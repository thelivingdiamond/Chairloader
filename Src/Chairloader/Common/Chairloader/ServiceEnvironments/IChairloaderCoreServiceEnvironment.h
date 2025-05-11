//
// Created by theli on 5/3/2025.
//

#ifndef ICHAIRLOADERCORESERVICEENVIRONMENT_H
#define ICHAIRLOADERCORESERVICEENVIRONMENT_H

struct IChairServiceCollection;

namespace Internal {
    struct IChairloaderCoreServiceEnvironment {
        static void ConfigureServices(IChairServiceCollection &serviceCollection);
    };
}


#endif //ICHAIRLOADERCORESERVICEENVIRONMENT_H
