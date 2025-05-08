//
// Created by theli on 5/3/2025.
//

#include <memory>

#include "ChairloaderPatches.h"
#include "SteamAPI/ChairSteamAPI.h"
#include "Chairloader/IChairServiceCollection.h"
#include "Chairloader/IChairServiceProvider.h"
#include "Chairloader/ServiceEnvironments/IChairloaderPatchesServiceEnvironment.h"

void Internal::IChairloaderPatchesServiceEnvironment::ConfigureServices(IChairServiceCollection &serviceCollection) {

    serviceCollection.AddService(IChairSteamAPI::Name(), EChairServiceLifetime::Singleton,
        [](IChairServiceProvider& serviceProvider) {
            return std::static_pointer_cast<void>(ChairSteamAPI::CreateInstance());
        });
    AddSingleton<IChairloaderPatches, ChairloaderPatches, IChairSteamAPI>(serviceCollection);
}
