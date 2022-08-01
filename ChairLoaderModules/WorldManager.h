//
// Created by theli on 7/31/2022.
//
#include <ChairLoader/ChairloaderEnv.h>
#include "../Common/ChairLoader/pch.h"
class WorldManager {
public:
    WorldManager(ChairloaderGlobalEnvironment* env);
    void Draw();

    void Update();

    std::string GetModuleName();
private:
    bool showLevelManagerWindow = false;
    ChairloaderGlobalEnvironment* gCLEnv;
    const std::string ModuleName = "WorldManager";

    void DrawLevelManagerWindow();

    void DrawMenuBar();

};
