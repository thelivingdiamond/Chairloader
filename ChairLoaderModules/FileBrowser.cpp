//
// Created by theli on 9/4/2022.
//



#include "FileBrowser.h"
#include <Prey/CrySystem/File/CryFile.h>
//#include <Prey/CrySystem/CryPak.h>
#include <Prey/CrySystem/XML/IXml.h>

FileBrowser::FileBrowser(ChairloaderGlobalEnvironment *env) {
    gCLEnv = env;
    xmlDepthSpacing = 20.0f;
}

void FileBrowser::Draw() {
    drawMenuBar();
    drawFileBrowser();
    drawFileViewer();
    for(int i = 0; i < openFiles.size(); i++) {
        if(!openFiles.at(i).open) {
            openFiles.erase(openFiles.begin() + i);
        }
    }
}

void FileBrowser::Update() {

}

FileBrowser::~FileBrowser() {

}

void FileBrowser::drawFileBrowser() {
#ifdef DEBUG_BUILD
    if(showFileBrowserDebug) {
        if (ImGui::Begin("File Browser Debug", &showFileBrowserDebug, ImGuiWindowFlags_MenuBar)) {
            static std::vector<string> files;
            static std::string directoryToSearch = "";
            static std::string fileToSearch;
            static std::string fileFilterString = "*";
            static bool _recursive, _bAllowUseFileSystem;
            static bool bExists;
            if (ImGui::Button("Get Game Directory")) {
                directoryToSearch = gEnv->pCryPak->GetGameFolder();
            }
            ImGui::InputText("Directory", &directoryToSearch);
            ImGui::InputText("File Filter", &fileFilterString);
            ImGui::Checkbox("Recursive", &_recursive);
            ImGui::Checkbox("Allow Use File System", &_bAllowUseFileSystem);
            if (ImGui::Button("Scan Files")) {
                files.clear();
                gEnv->pCryPak->ScanDirectory(directoryToSearch.c_str(), fileFilterString.c_str(), files, _recursive,
                                             _bAllowUseFileSystem);
            }
            SDirectoryEnumeratorHelper dirEnumHelper;
            _finddata64i32_t fd;
            if (ImGui::Button("Scan Files 2")) {
                string root = "";
                string path = directoryToSearch.c_str();
                string fileSpec = fileFilterString.c_str();
                files.clear();
            }
            ImGui::InputText("File To Search", &fileToSearch);
            if (ImGui::Button("File Exists")) {
                bExists = gEnv->pCryPak->IsFileExist(fileToSearch.c_str(), ICryPak::eFileLocation_Any);
            }
            ImGui::BeginDisabled();
            ImGui::Checkbox("File Exists", &bExists);
            ImGui::EndDisabled();
            if (ImGui::CollapsingHeader("Files")) {
                for (auto &file: files) {
                    ImGui::Text("%s", file.c_str());
                }
            }
            auto pakInfo = gEnv->pCryPak->GetPakInfo();
            ImGui::Text("Pak Open Flags");
            // ICryArchive::EPakFlags::
//            FLAGS_ABSOLUTE_PATHS  FLAGS_RELATIVE_PATHS_ONLY  FLAGS_READ_ONLY  FLAGS_OPTIMIZED_READ_ONLY  FLAGS_CREATE_NEW  FLAGS_DONT_COMPACT  FLAGS_IN_MEMORY       FLAGS_IN_MEMORY_CPU   FLAGS_FILENAMES_AS_CRC32  FLAGS_ON_HDD  FLAGS_OVERRIDE_PAK  FLAGS_DISABLE_PAK = BIT(11),
            static bool FLAGS_ABSOLUTE_PATHS= false, FLAGS_RELATIVE_PATHS_ONLY= false, FLAGS_READ_ONLY= false, FLAGS_OPTIMIZED_READ_ONLY= false, FLAGS_CREATE_NEW= false, FLAGS_DONT_COMPACT= false, FLAGS_IN_MEMORY= false, FLAGS_IN_MEMORY_CPU= false, FLAGS_FILENAMES_AS_CRC32= false, FLAGS_ON_HDD= false, FLAGS_OVERRIDE_PAK= false, FLAGS_DISABLE_PAK;
            ImGui::Checkbox("FLAGS_ABSOLUTE_PATHS", &FLAGS_ABSOLUTE_PATHS);
            ImGui::Checkbox("FLAGS_RELATIVE_PATHS_ONLY", &FLAGS_RELATIVE_PATHS_ONLY);
            ImGui::Checkbox("FLAGS_READ_ONLY", &FLAGS_READ_ONLY);
            ImGui::Checkbox("FLAGS_OPTIMIZED_READ_ONLY", &FLAGS_OPTIMIZED_READ_ONLY);
            ImGui::Checkbox("FLAGS_CREATE_NEW", &FLAGS_CREATE_NEW);
            ImGui::Checkbox("FLAGS_DONT_COMPACT", &FLAGS_DONT_COMPACT);
            ImGui::Checkbox("FLAGS_IN_MEMORY", &FLAGS_IN_MEMORY);
            ImGui::Checkbox("FLAGS_IN_MEMORY_CPU", &FLAGS_IN_MEMORY_CPU);
            ImGui::Checkbox("FLAGS_FILENAMES_AS_CRC32", &FLAGS_FILENAMES_AS_CRC32);
            ImGui::Checkbox("FLAGS_ON_HDD", &FLAGS_ON_HDD);
            ImGui::Checkbox("FLAGS_OVERRIDE_PAK", &FLAGS_OVERRIDE_PAK);
            ImGui::Checkbox("FLAGS_DISABLE_PAK", &FLAGS_DISABLE_PAK);
            auto archiveFlags =
                      (FLAGS_ABSOLUTE_PATHS ? ICryArchive::EPakFlags::FLAGS_ABSOLUTE_PATHS : (ICryArchive::EPakFlags)0)
                    | (FLAGS_RELATIVE_PATHS_ONLY ? ICryArchive::EPakFlags::FLAGS_RELATIVE_PATHS_ONLY : (ICryArchive::EPakFlags)0)
                    | (FLAGS_READ_ONLY ? ICryArchive::EPakFlags::FLAGS_READ_ONLY : (ICryArchive::EPakFlags)0)
                    | (FLAGS_OPTIMIZED_READ_ONLY ? ICryArchive::EPakFlags::FLAGS_OPTIMIZED_READ_ONLY : (ICryArchive::EPakFlags)0)
                    | (FLAGS_CREATE_NEW ? ICryArchive::EPakFlags::FLAGS_CREATE_NEW : (ICryArchive::EPakFlags)0)
                    | (FLAGS_DONT_COMPACT ? ICryArchive::EPakFlags::FLAGS_DONT_COMPACT : (ICryArchive::EPakFlags)0)
                    | (FLAGS_IN_MEMORY ? ICryArchive::EPakFlags::FLAGS_IN_MEMORY : (ICryArchive::EPakFlags)0)
                    | (FLAGS_IN_MEMORY_CPU ? ICryArchive::EPakFlags::FLAGS_IN_MEMORY_CPU : (ICryArchive::EPakFlags)0)
                    | (FLAGS_FILENAMES_AS_CRC32 ? ICryArchive::EPakFlags::FLAGS_FILENAMES_AS_CRC32 : (ICryArchive::EPakFlags)0)
                    | (FLAGS_ON_HDD ? ICryArchive::EPakFlags::FLAGS_ON_HDD : (ICryArchive::EPakFlags)0)
                    | (FLAGS_OVERRIDE_PAK ? ICryArchive::EPakFlags::FLAGS_OVERRIDE_PAK : (ICryArchive::EPakFlags)0)
                    | (FLAGS_DISABLE_PAK ? ICryArchive::EPakFlags::FLAGS_DISABLE_PAK : (ICryArchive::EPakFlags)0);
            if (ImGui::CollapsingHeader("Paks")) {
                for (int i = 0; i < pakInfo->numOpenPaks; i++) {
                    auto archive = gEnv->pCryPak->OpenArchive(pakInfo->arrPaks[i].szFilePath, archiveFlags);
                    if( archive){
                        ImGui::Text("%s: %d", pakInfo->arrPaks[i].szFilePath, archive->IsReadOnly());
                    } else {
                        ImGui::Text("%s: NOT OPENED", pakInfo->arrPaks[i].szFilePath);
                    }

//                    ImGui::Text("%s", pakInfo->arrPaks[i].szBindRoot);
                }
                gEnv->pSystem->GetPerfHUD();
            }
        }
        ImGui::End();
    }
#endif
    if(showFileBrowser){
        if(ImGui::Begin("File Browser", &showFileBrowser, ImGuiWindowFlags_MenuBar)){
            using filePath = std::string;
            using fileName = std::string;
            static std::vector<fileName> files;
            static std::vector<filePath> filePaths;
            static std::vector<std::pair<fileName, filePath>> filePairs;
            static std::string selectedFile;
            if(ImGui::BeginMenuBar()){
                if(ImGui::BeginMenu("File")){
                    if(ImGui::MenuItem("Refresh")){
                        RefreshFileList = true;
                    }
                    ImGui::EndMenu();
                }
                // settings
                if(ImGui::BeginMenu("Settings")){
                    ImGui::InputText("File Filter", &fileFilter);
                    // show side bar
                    ImGui::MenuItem("Show Side Bar", nullptr, &showSideBar);
                    ImGui::EndMenu();
                }
                ImGui::EndMenuBar();
            }
            if(ImGui::InputText("Current Path", &currentPath, ImGuiInputTextFlags_EnterReturnsTrue)){
                RefreshFileList = true;
            }
            if(ImGui::InputText("File Filter", &fileFilter, ImGuiInputTextFlags_EnterReturnsTrue)){
                RefreshFileList = true;
            }
            if(RefreshFileList){
                files.clear();
                filePaths.clear();
                ScanDirectory(currentPath, fileFilter, files, filePaths);
                for(int i = 0; i < files.size(); i++){
                    filePairs.emplace_back(std::make_pair(files[i], filePaths[i]));
                }
                RefreshFileList = false;
            }
            static float DEFAULT_SIDELIST_WIDTH = 250.0f;
            static float sideListWidth = DEFAULT_SIDELIST_WIDTH;
            if(ImGui::GetContentRegionAvail().x * 0.3f >= DEFAULT_SIDELIST_WIDTH){
                sideListWidth = DEFAULT_SIDELIST_WIDTH;
            } else {
                sideListWidth = ImGui::GetContentRegionAvail().x * 0.3f;
            }
            if(ImGui::BeginChild("File List", ImVec2(0, 0), true)){
                if(ImGui::BeginChild("Side List", ImVec2(sideListWidth, 0), true, ImGuiWindowFlags_HorizontalScrollbar)){
                    recursiveNodeDisplay("");

                }
                ImGui::EndChild();
                if(ImGui::IsItemHovered() && ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(0)){
                    currentPath = "";
                }
                ImGui::SameLine();
                if(ImGui::BeginChild("Main List", ImVec2(0,0), true)){
                    if(ImGui::BeginTable("File Table", 3, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_SizingFixedFit | ImGuiTableFlags_Resizable | ImGuiTableFlags_ScrollY)){
                        // File name, type, size, date modified
                        ImGui::TableSetupColumn("File Name", ImGuiTableColumnFlags_WidthStretch);
                        ImGui::TableSetupColumn("File Type", ImGuiTableColumnFlags_WidthFixed, 100.0f);
                        ImGui::TableSetupColumn("File Size", ImGuiTableColumnFlags_WidthFixed, 100.0f);
                        ImGui::TableSetupScrollFreeze(1, 1);
                        ImGui::TableHeadersRow();
                        ImGui::TableNextRow();
                        ImGui::TableNextColumn();
                        ImGui::Selectable("..", false, ImGuiSelectableFlags_SpanAllColumns | ImGuiSelectableFlags_AllowDoubleClick);
                        if(ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(0)){
                            goUpDirectory();
                        }
                        static string root = "";
                        string dir = PathUtil::AddSlash(root + currentPath.c_str());

                        string findFilter = PathUtil::Make(dir, "*");
                        ICryPak *pIPak = gEnv->pCryPak;

                        _finddata_t fd;
                        intptr_t fhandle;

                        fhandle = pIPak->FindFirst(findFilter, &fd, 0, false);

                        if (fhandle != -1) {
                            do {
                                if (fd.name[0] == '.')
                                    continue;
                                if (fd.attrib & _A_SUBDIR) { // recurse on sub directories.
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    if(ImGui::Selectable((fd.name + std::string("/")).c_str(), selectedFile == fd.name, ImGuiSelectableFlags_SpanAllColumns)){
                                        selectedFile = fd.name;
                                       selectedFile = fd.name;
                                    }
                                    if(ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(0)){
                                        currentPath = PathUtil::AddSlash(string(currentPath.c_str()) + fd.name);
                                    }
                                    ImGui::TableNextColumn();
                                    ImGui::Text("DIR");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("");
                                } else {
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    if(ImGui::Selectable(fd.name, selectedFile == fd.name), ImGuiSelectableFlags_SpanAllColumns){
                                        selectedFile = fd.name;
                                    }
                                    if(ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(0)){
                                        // check if extension is xml
                                        if(PathUtil::GetExt(fd.name) == std::string("xml")){
                                            // load file
                                            std::string filePath = PathUtil::Make(dir, fd.name).c_str();
                                            openFile(filePath);
                                        }
                                    }
                                    ImGui::TableNextColumn();
                                    ImGui::Text(".%s", PathUtil::GetExt(fd.name));
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%.2fkb", fd.size/1024.0f);
                                }
                            } while (pIPak->FindNext(fhandle, &fd) == 0);
                            pIPak->FindClose(fhandle);
                        }
                        ImGui::EndTable();
                    }
                }
                ImGui::EndChild();
            }
            ImGui::EndChild();
        }
        ImGui::End();
    }
}

void FileBrowser::drawMenuBar() {
    if(ImGui::BeginMainMenuBar()){
        if(ImGui::BeginMenu("File Browser")) {
            ImGui::MenuItem("Show File Browser", NULL, &showFileBrowser);
            ImGui::MenuItem("Show File Viewer", NULL, &showFileViewer);
#ifdef DEBUG_BUILD
    ImGui::MenuItem("Debug", NULL, &showFileBrowserDebug);
#endif
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}

void FileBrowser::ScanDirectory(std::string &directory, std::string &filter, std::vector<std::string> &files, std::vector<std::string> &filePaths) {
    static string root = "";
    string dir = PathUtil::AddSlash(root + directory.c_str());

    string findFilter = PathUtil::Make(dir, filter.c_str());
    ICryPak *pIPak = gEnv->pCryPak;

    _finddata_t fd;
    intptr_t fhandle;

    fhandle = pIPak->FindFirst(findFilter, &fd, 0, false);
    if (fhandle != -1) {
        do {
            //  Skip back folders.
            files.emplace_back(fd.name);
            filePaths.emplace_back(directory + fd.name + "\\");
//            if (fd.name[0] == '.')
//                continue;
//            if (fd.attrib & _A_SUBDIR) // skip sub directories.
//                continue;
        } while (pIPak->FindNext(fhandle, &fd) == 0);
        pIPak->FindClose(fhandle);
    }

}

bool FileBrowser::recursiveNodeDisplay(std::string parentPath) {
    static string root = "";
    string dir = PathUtil::AddSlash(root + parentPath.c_str());

    string findFilter = PathUtil::Make(dir, "*");
    ICryPak *pIPak = gEnv->pCryPak;

    _finddata_t fd;
    intptr_t fhandle;

    fhandle = pIPak->FindFirst(findFilter, &fd, 0, false);
    if (fhandle != -1) {
        do {
//            if (fd.name[0] == '.')
//                continue;
            if (fd.attrib & _A_SUBDIR) { // recurse on sub directories.
                auto node_flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick;
                if(!CheckForSubDirectories(parentPath + fd.name + "\\")){
                    node_flags |= ImGuiTreeNodeFlags_Leaf;
                }
                if(currentPath == parentPath + fd.name + "\\"){
                    node_flags |= ImGuiTreeNodeFlags_Selected;
                }
                bool nodeOpen = ImGui::TreeNodeEx((parentPath + fd.name + "\\").c_str(), node_flags, "%s", fd.name);
//                if(ImGui::IsItemToggledOpen()){
//
//                }
                if (ImGui::IsItemClicked()) {
                    currentPath = parentPath + fd.name + "\\";
                    RefreshFileList = true;
                }
                if(nodeOpen){
                    recursiveNodeDisplay(parentPath + fd.name + "\\");
                    ImGui::TreePop();
                }
                // check for double click to set current path

            }
        } while (pIPak->FindNext(fhandle, &fd) == 0);
        pIPak->FindClose(fhandle);
    }
    return false;
}

bool FileBrowser::CheckForSubDirectories(std::string directory) {
    static string root = "";
    string dir = PathUtil::AddSlash(root + directory.c_str());

    string findFilter = PathUtil::Make(dir, "*");
    ICryPak *pIPak = gEnv->pCryPak;

    _finddata_t fd;
    intptr_t fhandle;

    fhandle = pIPak->FindFirst(findFilter, &fd, 0, false);

    if (fhandle != -1) {
        do {
            if (fd.name[0] == '.')
                continue;
            if (fd.attrib & _A_SUBDIR) { // recurse on sub directories.
                return true;
            }
        } while (pIPak->FindNext(fhandle, &fd) == 0);
        pIPak->FindClose(fhandle);
    }
    return false;
}

void FileBrowser::goUpDirectory() {
    if(currentPath == "/"){
        return;
    }
    currentPath = PathUtil::GetParentDirectory(currentPath.c_str());
    RefreshFileList = true;
}

void FileBrowser::drawFileViewer() {
    if(showFileViewer){
        ImGui::SetNextWindowBgAlpha(1.0f);
        if(ImGui::Begin("File Viewer", &showFileViewer, ImGuiWindowFlags_MenuBar)){
            if(ImGui::BeginMenuBar()){
                if(ImGui::BeginMenu("File")){

                    ImGui::EndMenu();
                }
                ImGui::EndMenuBar();
            }
            auto barFlags = ImGuiTabBarFlags_Reorderable | ImGuiTabBarFlags_FittingPolicyScroll /*| ImGuiTabBarFlags_AutoSelectNewTabs*/ | ImGuiTabBarFlags_TabListPopupButton;
//            if(openFiles.size() > 1)
//                barFlags |= ImGuiTabBarFlags_AutoSelectNewTabs;
            if(ImGui::BeginTabBar("File Viewer Tabs", barFlags )){
                for(auto &file : openFiles){
                    displayXmlFile(file);
                }
                ImGui::EndTabBar();
            }
        }
        ImGui::End();
    }
}

void FileBrowser::openFile(std::string path) {
    if (std::find(openFiles.begin(), openFiles.end(), path) == openFiles.end()) {
        if (PathUtil::GetExt(path.c_str()) == std::string("xml")) {
            auto xmlFile = gEnv->pSystem->LoadXmlFromFile(path.c_str());
            openFiles.emplace_back(openXmlFile{path, xmlFile});
        }
    }
    if (!showFileViewer) {
        showFileViewer = true;
    }
}

void FileBrowser::displayXmlFile(openXmlFile& file) {
    bool open = true;
    if(ImGui::BeginTabItem(file.path.c_str(), &open)){
        currentViewingFile = file;
        if(ImGui::BeginChild("File Viewer Child", ImVec2(0, 0), true, ImGuiWindowFlags_HorizontalScrollbar)) {
            if (file.xml) {
                displayXmlNode(file.xml, 0);
            }
        }
        ImGui::EndChild();
        ImGui::EndTabItem();
    }
    if(!open){
        for(auto it = openFiles.begin(); it != openFiles.end(); it++){
            if(it->path == file.path){
                openFiles.erase(it);
                break;
            }
        }
    }
}

void FileBrowser::displayXmlNode(XmlNodeRef node, int depth) {
    if(node){
        //TODO: add way to edit style colors
        ImGui::SetCursorPosX((depth * xmlDepthSpacing) + 10.0f);
//        ImGui::PushStyleColor(ImGuiCol_Text, ImColor(107, 119, 255).operator ImVec4());
        bool nodeOpen = false;
        if(!std::string(node->getAttr("Name")).empty()){
            nodeOpen = ImGui::TreeNode((std::string(node->getTag()) + node->getAttr("Name") + node->getAttr("id")).c_str(), "<%s - %s>", node->getTag(), node->getAttr("Name"));
        }
        else {
            nodeOpen = ImGui::TreeNode((std::string(node->getTag()) + node->getAttr("Name") + node->getAttr("id")).c_str(), "<%s>", node->getTag());
        }
//        ImGui::PopStyleColor();
        if(nodeOpen) {
            for (int i = 0; i < node->getNumAttributes(); i++) {
                std::string attributeName, attributeValue;
                attributeName.resize(1024);
                attributeValue.resize(1024);
                auto attributeNamePtr = attributeName.c_str();
                auto attributeValuePtr = attributeValue.c_str();
                node->getAttributeByIndex(i, &attributeNamePtr, &attributeValuePtr);
                ImGui::TextColored(ImColor(47, 239, 95), "%s", attributeNamePtr);
                ImGui::SameLine();
                ImGui::TextColored(ImColor(255, 255, 255), "=");
                ImGui::SameLine();
                ImGui::TextColored(ImColor(221, 146, 33), "%s", attributeValuePtr);
                if(ImGui::IsItemClicked()){
                    ImGui::SetClipboardText(attributeValuePtr);
                    gCLEnv->gui->overlayLog(GetModuleName(), "Copied to Clipboard");
                }
            }
            if(strlen(node->getContent()) != 0) {
                ImGui::Text("%s", node->getContent());
                for (int i = 0; i < node->getChildCount(); i++) {
                    displayXmlNode(node->getChild(i), depth + 1);
                }
                ImGui::SetCursorPosX((depth * xmlDepthSpacing));
            } else {
                for (int i = 0; i < node->getChildCount(); i++) {
                    displayXmlNode(node->getChild(i), depth + 1);
                }
            }
            ImGui::TreePop();
        }
    }

}

