//
// Created by theli on 5/3/2025.
//

#include "ChairImGui.h"
#include "ChairloaderConfigManager.h"
#include "ChairloaderCore.h"
#include "ChairVarManager.h"
#include "ChairloaderGui.h"
#include "ChairLogger.h"
#include "Lua/LuaModManager.h"
#include "Lua/ScriptBind_Chairloader.h"
#include "LogManager.h"
#include "ModDllManager.h"
#include "Chairloader/ChairXmlUtils.h"
#include "Chairloader/ServiceEnvironments/IChairloaderCoreServiceEnvironment.h"
#include "Chairloader/IChairServiceCollection.h"
#include "Chairloader/IChairServiceProvider.h"

void Internal::IChairloaderCoreServiceEnvironment::ConfigureServices(IChairServiceCollection &serviceCollection) {
    AddSingleton<IChairXmlUtils, ChairXmlUtils>(serviceCollection);
    AddSingleton<LogManager, LogManager>(serviceCollection);
    AddSingleton<ILogManager, LogManager>(serviceCollection, [](IChairServiceProvider & sp) { return sp.GetRequiredService<LogManager>();  });
    AddTransient<IChairLogger, ChairLogger, LogManager>(serviceCollection);
    AddSingleton<IChairloaderConfigManager, ChairloaderConfigManager>(serviceCollection);
    AddSingleton<IChairloaderImGui, ChairImGui, IChairRender>(serviceCollection);
    AddSingleton<IChairVarManager, ChairVarManager>(serviceCollection);
    AddSingleton<IChairloaderGui, ChairloaderGui, LogManager>(serviceCollection);
    AddSingleton<IModDllManager, ModDllManager, IChairloaderConfigManager>(serviceCollection);
    AddSingleton<LuaModManager, LuaModManager>(serviceCollection);
    AddSingleton<ScriptBind_Chairloader, ScriptBind_Chairloader, LuaModManager, IChairLogger>(serviceCollection);
    AddSingleton<IChairloaderCore, ChairloaderCore, IChairloaderConfigManager, IModDllManager, IChairVarManager,
        IChairloaderGui, LuaModManager, IChairloaderImGui, LogManager>(serviceCollection);
}
