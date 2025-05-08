//
// Created by theli on 5/3/2025.
//

#include "ChairloaderCryRender.h"
#include "ChairRender.h"
#include "Chairloader/ServiceEnvironments/IChairloaderCryRenderServiceEnvironment.h"
#include "Chairloader/IChairServiceCollection.h"

void Internal::IChairloaderCryRenderServiceEnvironment::ConfigureServices(IChairServiceCollection &serviceCollection) {
    AddSingleton<IChairRender, RenderDll::ChairRender>(serviceCollection);
    AddSingleton<IChairloaderCryRender, RenderDll::ChairloaderCryRender>(serviceCollection);
}
