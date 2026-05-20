//
// Created by theli on 5/3/2025.
//

#ifndef ICHAIRLOADERTOOLSSERVICEENVIRONMENT_H
#define ICHAIRLOADERTOOLSSERVICEENVIRONMENT_H

struct IChairServiceCollection;

namespace Internal {
    struct IChairloaderToolsServiceEnvironment {
        static void ConfigureServices(IChairServiceCollection &serviceCollection);
    };
}


#endif //ICHAIRLOADERTOOLSSERVICEENVIRONMENT_H
