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
    void drawMenuBar();
    bool showEntitySpawner = false, showEntityList = false;

    // environment *
    ChairloaderGlobalEnvironment* gCLEnv = nullptr;

    const std::string moduleName = "FileBrowser";

};

