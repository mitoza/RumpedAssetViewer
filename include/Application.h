//
// Created by mito on 19.06.2024.
//

#ifndef APPLICATION_H
#define APPLICATION_H

#include "ApplicationConfig.h"
#include "Context.h"

namespace rumpedav {
    class Context;

    class Application {
        Context context;
    public:
        explicit Application(ApplicationConfig &_config);

        ~Application();

        void run();

    };
}

#endif //APPLICATION_H
