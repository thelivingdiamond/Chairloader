//
// Created by theli on 5/3/2025.
//

#include "ChairloaderTools.h"
#include "Chairloader/ServiceEnvironments/IChairloaderToolsServiceEnvironment.h"
#include "Chairloader/IChairServiceCollection.h"
#include "LocalizationUtil.h"
#include "Editor/Editor.h"
#include "Trainer/SignalSystemManager.h"
#include "Trainer/EntityManager.h"
#include "Trainer/EntitySpawnList.h"
#include "Trainer/PlayerManager.h"
#include "Trainer/WorldManager.h"
#include "DebugMenu.h"
#include "PerfOverlay.h"
#include "FileBrowser.h"
#include "DevConsoleDialog.h"

void Internal::IChairloaderToolsServiceEnvironment::ConfigureServices(IChairServiceCollection &serviceCollection) {
    AddSingleton<IChairloaderTools, ChairloaderTools, IChairloaderConfigManager>(serviceCollection);
}
