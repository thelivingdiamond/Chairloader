#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <TlHelp32.h>
#include <vector>
#include <tuple>
#include <Windows.h>
#include "Drawing.h"
#include <zip.h>

#include <pugixml.hpp>
#include <boost/variant.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;

namespace chairloader {
    class chairloaderMod {
    public:
        std::string modName;
        pugi::xml_document* config = nullptr;
        int loadOrder = -1;
        std::string displayName;
        bool xmlLoad = true;
        bool dllLoad = true;


        chairloaderMod(const std::string modNameIn, pugi::xml_document* configIn, int loadOrderIn = -1, std::string displayNameIn = "", bool xmlLoadIn = true, bool dllLoadIn = true) :modName(modNameIn), config(configIn), loadOrder(loadOrderIn), displayName(displayNameIn), xmlLoad(xmlLoadIn), dllLoad(dllLoadIn) {}

        bool operator()(chairloaderMod a, chairloaderMod b) {
            if (a.loadOrder == -1 || b.loadOrder == -1) {
                return a.modName < b.modName;
            }
            else {
                return a.loadOrder < b.loadOrder;
            }
        }
        bool operator<(chairloaderMod b) {
            if (this->loadOrder == -1 || b.loadOrder == -1) {
                return this->modName < b.modName;
            }
            else {
                return this->loadOrder < b.loadOrder;
            }
        }
        void operator=(const chairloaderMod& rhs) {
            this->modName = rhs.modName;
            this->loadOrder = rhs.loadOrder;
            this->config = rhs.config;
            this->displayName = rhs.displayName;
            this->dllLoad = rhs.dllLoad;
            this->xmlLoad = rhs.xmlLoad;
        }
        bool operator==(const std::string& rhs) const { return this->modName == rhs; }
        bool operator==(const chairloaderMod& rhs) const { return this->modName == rhs.modName; }
        void setLoadOrder(int i) {
            this->loadOrder = i;
        }
    };
    typedef std::vector<chairloaderMod> modList;

    bool mergeXmlNodes(pugi::xml_node* destination, pugi::xml_node* source, std::string modName, bool overwrite = false) {
        if (destination == nullptr || source == nullptr) {
            return false;
        }
        destination->append_child(pugi::node_comment).set_value(modName.c_str());
        for (auto itr = source->begin(); itr != source->end(); ++itr) {
            pugi::xml_node node = *itr;
            if (destination->find_child_by_attribute("Name", itr->attribute("Name").as_string()) == nullptr) {
                destination->append_copy(node);
            }
            else {
                if (overwrite) {
                    destination->remove_child(destination->find_child_by_attribute("Name", itr->attribute("Name").as_string()));
                    destination->append_copy(node);
                }
                else {
                    printf("conflict found\n");
                }
            }
        }
        return true;
    }




    bool DirectoryExists(const char* dirName) {
        DWORD attribs = ::GetFileAttributesA(dirName);
        if (attribs == INVALID_FILE_ATTRIBUTES) {
            return false;
        }
        return (attribs & FILE_ATTRIBUTE_DIRECTORY);
    }

    bool mergeFile(std::string pathSoFar, std::vector<std::string> modNames, std::string fileName, std::vector<std::string>* outputPaths, std::string preyPath, modList* modConfigs = nullptr) {
        pugi::xml_document destination, source;
        pugi::xml_parse_result destinationResult, sourceResult;
        pugi::xml_node destinationParent, sourceParent;
        destinationResult = destination.load_file(("PreyFiles\\" + pathSoFar + "\\" + fileName).c_str());
        if (_strcmpi(destinationResult.description(), "No error") != 0)
            return false;
        //TODO: do this for every modName in the input vector and adjust accordingly
        bool successfulMerge = false;
        for (auto& mod : *modConfigs) {
            if (mod.xmlLoad) {
                sourceResult = source.load_file((preyPath + "\\Mods\\" + mod.modName + "\\" + pathSoFar + "\\" + fileName).c_str());
                if (_strcmpi(sourceResult.description(), "No error") == 0) {
                    destinationParent = destination.root().first_child();
                    sourceParent = source.root().first_child();
                    bool configFound = false;
                    if (modConfigs != nullptr) {
                        auto modConfig = std::find(modConfigs->begin(), modConfigs->end(), mod.modName);
                        if (modConfig != modConfigs->end()) {
                            pugi::xml_node fileNode = modConfig->config->root().first_child().child("XMLConfig").find_child_by_attribute("Name", fileName.c_str());
                            if (fileNode != nullptr) {
                                configFound = true;
                                bool overwrite = fileNode.attribute("Overwrite").as_bool();
                                if (mergeXmlNodes(&destinationParent, &sourceParent, mod.modName, overwrite))
                                    successfulMerge = true;
                            }
                        }
                    }
                    if (!configFound) {
                        if (mergeXmlNodes(&destinationParent, &sourceParent, mod.modName, false)) {
                            successfulMerge = true;
                        }
                    }
                }
            }
        }
        if (successfulMerge) {
            std::wstring wpath;
            std::string path;
            path = ".\\Output\\" + pathSoFar;
            wpath = std::wstring(path.begin(), path.end());
            fs::create_directories(wpath);
            // CreateDirectory(wpath.c_str(), NULL);
            if (destination.save_file((".\\Output" + pathSoFar + "\\" + fileName).c_str(), "\t", pugi::format_no_declaration)) {
                outputPaths->emplace_back(".\\Output" + pathSoFar + "\\" + fileName);
                return true;
            }
        }
        return false;
    }


    std::vector<std::string>* treeWalkAndMerge(pugi::xml_node parent, std::string pathSoFar, std::vector<std::string> modNames, std::string preyPath, std::vector<std::string>* outputPaths = nullptr, modList* modConfigs = nullptr) {
        if (outputPaths == nullptr) {
            outputPaths = new std::vector<std::string >;
        }
        for (auto itr = parent.begin(); itr != parent.end(); ++itr) {
            if (_strcmpi(itr->name(), "Folder") == 0 || _strcmpi(itr->name(), "Library") == 0) {
                treeWalkAndMerge(*itr, pathSoFar + "\\" + itr->attribute("Name").as_string(), modNames, preyPath, outputPaths, modConfigs);
            }
            else if (_strcmpi(itr->name(), "File") == 0) {
                if (mergeFile(pathSoFar, modNames, itr->attribute("Name").as_string(), outputPaths, preyPath, modConfigs)) {
                    // printf("Merged: %s\n", (modName + "\\" + pathSoFar + "\\" + itr->attribute("Name").as_string()).c_str());
                }
                else {
                    // printf("Merge Failed: %s\n", (modName + "\\" + pathSoFar + "\\" + itr->attribute("Name").as_string()).c_str());
                }
            }
        }
        return outputPaths;
    }

    std::vector<fs::path> get_all(fs::path const& root, std::string const& ext)
    {
        std::vector<fs::path> paths;

        if (fs::exists(root) && fs::is_directory(root))
        {
            for (auto const& entry : fs::directory_iterator(root))
            {
                if (fs::is_regular_file(entry) && entry.path().extension() == ext)
                    paths.emplace_back(entry.path().filename());
            }
        }

        return paths;
    }

    bool mergeXmlDocs(pugi::xml_document* destination, pugi::xml_document* source, std::string rootNode, std::string modName, bool overwrite = false) {
        pugi::xml_node destinationNode = destination->child(rootNode.c_str());
        pugi::xml_node sourceNode = source->child(rootNode.c_str());
        if (destinationNode == nullptr || sourceNode == nullptr) {
            return false;
        }
        return mergeXmlNodes(&destinationNode, &sourceNode, modName, overwrite);
    }

    modList* loadModConfigs(std::string preyPath, modList* modConfigs = nullptr) {
        if (modConfigs == nullptr) {
            modConfigs = new modList;
        }
        std::vector<fs::path> xmlFiles = get_all(preyPath + "\\Mods", ".xml");
        std::vector<fs::path> configFiles;
        pugi::xml_document loadOrderConfig;
        if (loadOrderConfig.load_file("chairloaderConfig.xml").status == pugi::status_ok) {
            for (auto& file : xmlFiles) {
                std::wstring fileName = file.filename().c_str();
                std::wstring wPreyPath = std::wstring(preyPath.begin(), preyPath.end());
                if (fileName.find(L"config_") != std::wstring::npos) {
                    printf("Config Found: %ls\n", fileName.c_str());
                    configFiles.emplace_back(file);
                    pugi::xml_document* doc = new pugi::xml_document;
                    pugi::xml_parse_result result = doc->load_file((wPreyPath + L"\\Mods\\" + fileName).c_str());
                    if (result.status == pugi::status_ok) {
                        std::string modName = doc->root().first_child().attribute("ModName").as_string();
                        std::string displayName = doc->root().first_child().attribute("DisplayName").as_string();
                        if (!modName.empty()) {
                            int loadOrder = -1;
                            bool xmlLoad = true, dllLoad = true;
                            pugi::xml_node node = loadOrderConfig.root().first_child().child("LoadOrder").find_child_by_attribute("Name", modName.c_str());
                            if (node) {
                                loadOrder = node.attribute("LoadOrder").as_int();
                                xmlLoad = node.attribute("XmlLoad").as_bool();
                                dllLoad = node.attribute("DllLoad").as_bool();
                            }
                            else {
                                pugi::xml_node mod = loadOrderConfig.root().first_child().child("LoadOrder").append_child("Mod");
                                mod.append_attribute("Name").set_value(modName.c_str());
                                mod.append_attribute("LoadOrder").set_value(loadOrder);
                                mod.append_attribute("XmlLoad").set_value(xmlLoad);
                                mod.append_attribute("DllLoad").set_value(dllLoad);
                                loadOrderConfig.save_file("chairloaderConfig.xml");
                            }
                            // if (doc->root().first_child().attribute("LoadOrder")) {
                            //     loadOrder = doc->root().first_child().attribute("LoadOrder").as_int();
                            // }
                            // else {
                            //     doc->root().first_child().append_attribute("LoadOrder").set_value("-1");
                            //     doc->save_file((L"Mods\\" + fileName).c_str(), "\t", pugi::format_no_declaration);
                            // }

                            modConfigs->emplace_back(chairloaderMod{ modName, doc, loadOrder, displayName, xmlLoad, dllLoad });
                        }
                    }
                }
            }
        }
        return modConfigs;
    }
    bool saveLoadOrderConfig(modList* modConfigs) {
        pugi::xml_document loadOrderConfig;
        if (loadOrderConfig.load_file("chairloaderConfig.xml").status == pugi::status_ok) {
            for (auto& mod : *modConfigs) {
                pugi::xml_node node = loadOrderConfig.root().first_child().child("LoadOrder").find_child_by_attribute("Name", mod.modName.c_str());
                if (node) {
                    node.attribute("LoadOrder").set_value(mod.loadOrder);
                    node.attribute("XmlLoad").set_value(mod.xmlLoad);
                    node.attribute("DllLoad").set_value(mod.dllLoad);
                }
                else {
                    pugi::xml_node modNode = loadOrderConfig.root().first_child().child("LoadOrder").append_child("Mod");
                    modNode.append_attribute("Name").set_value(mod.modName.c_str());
                    modNode.append_attribute("LoadOrder").set_value(mod.loadOrder);
                    modNode.append_attribute("XmlLoad").set_value(mod.xmlLoad);
                    modNode.append_attribute("DllLoad").set_value(mod.dllLoad);
                }
            }
            return loadOrderConfig.save_file("chairloaderConfig.xml");
        }
        return false;
    }


    void replace_all(
        std::string& s,
        std::string const& toReplace,
        std::string const& replaceWith
    ) {
        std::ostringstream oss;
        std::size_t pos = 0;
        std::size_t prevPos = pos;

        while (true) {
            prevPos = pos;
            pos = s.find(toReplace, pos);
            if (pos == std::string::npos)
                break;
            oss << s.substr(prevPos, pos - prevPos);
            oss << replaceWith;
            pos += toReplace.size();
        }

        oss << s.substr(prevPos);
        s = oss.str();
    }

    void packFiles(std::string outputFile, std::vector<std::string> inputPaths, bool autoRemove = true) {
        if (autoRemove) {
            try {
                fs::remove(outputFile);
            } catch(const boost::filesystem::filesystem_error& e) {
                Drawing::Log(e.what());
            }
        }
        // DeleteFile(L"patch_chairloader.pak");
        // std::ofstream file(outputFile.c_str());

        zip_t* patchFile = zip_open(outputFile.c_str(), ZIP_CREATE, nullptr);
        for (auto& file : inputPaths) {
            zip_source* source = zip_source_file_create(file.c_str(), 0, 0, nullptr);
            std::string zipPath = file;
            zipPath.erase(zipPath.find(".\\Output\\"), strlen(".\\Output\\"));
            replace_all(zipPath, "\\", "/");
            printf("Zip Path: %s\n", zipPath.c_str());
            zip_file_add(patchFile, zipPath.c_str(), source, 0);
        }
        zip_close(patchFile);
    }

    void deployPatch(std::string patchFile, std::string preyPath) {
        try {
            if (!fs::is_directory(preyPath + "\\GameSDK\\Precache\\")) {
                fs::create_directories(preyPath + "\\GameSDK\\Precache\\");
            }
            if (fs::exists(".\\" + patchFile)) {
                fs::copy_file(".\\" + patchFile, (preyPath + "\\GameSDK\\Precache\\" + patchFile), fs::copy_option::overwrite_if_exists);
            }
        } catch(const boost::filesystem::filesystem_error& e) {
            Drawing::Log(e.what());
        }
    }

    std::vector<chairloader::chairloaderMod>* sortModLoadOrder(chairloader::modList* modConfigs) {
        std::sort(modConfigs->begin(), modConfigs->end());
        return modConfigs;
    }

    DWORD GetProcId(const wchar_t* procName) {
        DWORD procId = 0;
        HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

        if (hSnap != INVALID_HANDLE_VALUE) {
            PROCESSENTRY32W procEntry;
            procEntry.dwSize = sizeof(procEntry);

            if (Process32FirstW(hSnap, &procEntry)) {
                do {
                    if (!_wcsicmp(procEntry.szExeFile, procName)) {
                        procId = procEntry.th32ProcessID; 
                        break;
                    }
                } while (Process32NextW(hSnap, &procEntry));
            }
        }
        CloseHandle(hSnap);
        return procId;
    }
    std::vector<fs::path>* getDllPaths(std::string preyPath, std::vector<fs::path>* dllPaths) {
        if(dllPaths = nullptr) {
            dllPaths = new std::vector<fs::path>;
        }
        std::vector<fs::path> paths;
        paths = get_all(preyPath + "\\Mods", ".dll");
        for(auto &itr:paths) {
            printf("%ls\n", itr.c_str());
            dllPaths->emplace_back();
        }
        return dllPaths;
    }


    void InjectMods(std::vector<fs::path> dllPaths, std::string preyPath) {
        // const wchar_t* dllPath = L"C:********CHANGE THIS******";

        const wchar_t* procName = L"Prey.exe";
        DWORD procId = 0;

        while (!procId) {
            procId = GetProcId(procName);
            Sleep(30);
        }
        // std::cout << "Process Found...\n";
        HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, 0, procId);
        for (auto& path : dllPaths) {
            std::wstring wPreyPath = std::wstring(preyPath.begin(), preyPath.end());
            std::wstring dllPath = wPreyPath + L"\\" + path.c_str();
            if (hProc && hProc != INVALID_HANDLE_VALUE) {

                void* loc = VirtualAllocEx(hProc, 0, MAX_PATH, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

                if (loc) {
                    WriteProcessMemory(hProc, loc, (dllPath.c_str()), dllPath.size() + 1, 0);
                    // std::cout << "Memory Patched...\n";
                }

                HANDLE hThread = CreateRemoteThread(hProc, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibraryA, loc, 0, 0);
                // std::cout << "DLL Injected...\n";
                if (hThread) {
                    CloseHandle(hThread);
                }
            }
        }

        if (hProc) {
            CloseHandle(hProc);
        }
    }
};