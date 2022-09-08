//
// Created by theli on 9/4/2022.
//

#include "../Common/ChairLoader/pch.h"

#include "EntityUtils.h"
#include <Prey/ArkEntityArchetypeLibrary.h>
#include "../ChairLoader/GUIUtils.h"
#include "ChairLoader/IChairloader.h"
#include "ChairLoader/ChairloaderEnv.h"
#include "Prey/CryEntitySystem/EntitySystem.h"

class FileBrowser {
public:
    FileBrowser(ChairloaderGlobalEnvironment* env);
    ~FileBrowser();
    void Draw() ;
    void Update() ;
    std::string GetModuleName() { return moduleName; };
private:
    void drawFileBrowser();
    void drawFileEditor();
    void drawMenuBar();
    bool recursiveNodeDisplay(std::string parentPath);
    void goUpDirectory();
    bool RefreshFileList = true;
    bool showFileBrowserDebug = false;
    bool showFileBrowser = false;
    bool showFileEditor = false;
    bool showSideBar = true;
    std::string currentPath;
    std::string fileFilter = "*";

    // file editor
    struct openXmlFile {
        std::string path;
        XmlNodeRef xml;
        bool open = true;
        bool operator==(const std::string& other) const {
            return path == other;
        }
    };

    void openFile(std::string path);
    float xmlDepthSpacing = 0.0f;
    void displayXmlFile(openXmlFile& file);
    void displayXmlNode(XmlNodeRef node, int depth);
    std::vector<openXmlFile> openFiles;


    // environment *
    ChairloaderGlobalEnvironment* gCLEnv = nullptr;

    const std::string moduleName = "FileBrowser";
    static void ScanDirectory(std::string &directory, std::string &filter, std::vector<std::string> &files, std::vector<std::string> &filePaths);
    static bool CheckForSubDirectories(std::string directory);
};

