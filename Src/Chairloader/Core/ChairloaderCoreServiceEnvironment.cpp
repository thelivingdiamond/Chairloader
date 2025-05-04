//
// Created by theli on 5/3/2025.
//

#include "ChairloaderConfigManager.h"
#include "ChairloaderCore.h"
#include "ChairVarManager.h"
#include "ChairloaderGui.h"
#include "Lua/LuaModManager.h"
#include "LogManager.h"
#include "ModDllManager.h"
#include "Chairloader/ServiceEnvironments/IChairloaderCoreServiceEnvironment.h"
#include "Chairloader/IChairServiceCollection.h"
#include "Chairloader/IChairServiceProvider.h"

void Internal::IChairloaderCoreServiceEnvironment::ConfigureServices(IChairServiceCollection &serviceCollection) {

    //TODO: can we move log manager like this?
    serviceCollection.AddService("ILogManager", "LogManager", [](IChairServiceProvider &provider) {
        return std::make_shared<LogManager>();
    });

    serviceCollection.AddService("IModDllManager", "ModDllManager", [](IChairServiceProvider &provider) {
        return std::make_shared<ModDllManager>();
    });

    serviceCollection.AddService("IChairVarManager", "ChairVarManager", [](IChairServiceProvider &provider) {
        return std::make_shared<ChairVarManager>();
    });

    serviceCollection.AddService("IChairloaderGui", "ChairloaderGui", [](IChairServiceProvider &provider) {
        return std::make_shared<ChairloaderGui>();
    });

    serviceCollection.AddService("IChairloaderConfigManager", "ChairloaderConfigManager", [](IChairServiceProvider &provider) {
        return std::make_shared<ChairloaderConfigManager>();
    });

    serviceCollection.AddService("IChairloaderCore", "ChairloaderCore", [](IChairServiceProvider &provider) {
        return std::make_shared<ChairloaderCore>(provider.GetRequiredService<IChairloaderConfigManager>("IChairloaderConfigManager"),
                                              provider.GetRequiredService<IModDllManager>("IModDllManager"),
                                              provider.GetRequiredService<IChairVarManager>("IChairVarManager"),
                                              provider.GetRequiredService<IChairloaderGui>("IChairloaderGui"));
    });
}
