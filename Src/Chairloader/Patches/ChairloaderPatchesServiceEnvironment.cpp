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

    serviceCollection.AddService("IChairStreamApi", "ChairSteamAPI", [](IChairServiceProvider &provider) {
        return ChairSteamAPI::CreateInstance();
    });

    serviceCollection.AddService("IChairloaderPatches", "ChairloaderPatches", [](IChairServiceProvider& provider) {
        return std::make_shared<ChairloaderPatches>(
            provider.GetService<IChairSteamAPI>("IChairStreamApi")
        );
    });
}
