//
// Created by theli on 5/3/2025.
//

#include "ChairloaderConfigManager.h"
#include "ChairloaderCore.h"
#include "ChairVarManager.h"
#include "ChairloaderGui.h"
#include "ChairLogger.h"
#include "Lua/LuaModManager.h"
#include "LogManager.h"
#include "ModDllManager.h"
#include "Chairloader/ServiceEnvironments/IChairloaderCoreServiceEnvironment.h"
#include "Chairloader/IChairServiceCollection.h"
#include "Chairloader/IChairServiceProvider.h"

void Internal::IChairloaderCoreServiceEnvironment::ConfigureServices(IChairServiceCollection &serviceCollection) {
    AddSingleton<ILogManager, LogManager>(serviceCollection);
    AddTransient<IChairLogger, ChairLogger>(serviceCollection);
    AddSingleton<IModDllManager, ModDllManager>(serviceCollection);
    AddSingleton<IChairVarManager, ChairVarManager>(serviceCollection);
    AddSingleton<IChairloaderGui, ChairloaderGui>(serviceCollection);
    AddSingleton<IChairloaderConfigManager, ChairloaderConfigManager>(serviceCollection);
    AddSingleton<IChairloaderCore, ChairloaderCore, IChairloaderConfigManager, IModDllManager, IChairVarManager,IChairloaderGui>(serviceCollection);
}
