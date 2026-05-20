//
// Created by theli on 5/3/2025.
//

#ifndef ICHAIRLOADERPATCHESSERVICEENVIRONMENT_H
#define ICHAIRLOADERPATCHESSERVICEENVIRONMENT_H

struct IChairServiceCollection;

namespace Internal {
    struct IChairloaderPatchesServiceEnvironment {
        static void ConfigureServices(IChairServiceCollection &serviceCollection);
    };
}

#endif //ICHAIRLOADERPATCHESSERVICEENVIRONMENT_H
