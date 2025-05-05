//
// Created by theli on 5/3/2025.
//

#include "ChairloaderCryRender.h"
#include "ChairRender.h"
#include "Chairloader/ServiceEnvironments/IChairloaderCryRenderServiceEnvironment.h"
#include "Chairloader/IChairServiceCollection.h"

void Internal::IChairloaderCryRenderServiceEnvironment::ConfigureServices(IChairServiceCollection &serviceCollection) {
    serviceCollection.AddService("IChairRender", "ChairRender",[](IChairServiceProvider& provider) {
        return std::make_shared<RenderDll::ChairRender>();
    });

    serviceCollection.AddService("IChairloaderCryRender", "ChairloaderCryRender", [](IChairServiceProvider& provider) {
        return std::make_shared<RenderDll::ChairloaderCryRender>();
    });
}
