//
// Created by theli on 5/3/2025.
//

#ifndef ICHAIRLOADERCRYRENDERSERVICEENVIRONMENT_H
#define ICHAIRLOADERCRYRENDERSERVICEENVIRONMENT_H

struct IChairServiceCollection;

namespace Internal {
    struct IChairloaderCryRenderServiceEnvironment {
        static void ConfigureServices(IChairServiceCollection &serviceCollection);
    };
}


#endif //ICHAIRLOADERCRYRENDERSERVICEENVIRONMENT_H
