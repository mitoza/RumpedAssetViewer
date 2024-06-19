//
// Created by mito on 19.06.2024.
//

#ifndef CONTEXT_H
#define CONTEXT_H

#include "ApplicationConfig.h"

namespace rumpedav {

    class Context {

    protected:
        ApplicationConfig config;

    public:

        Context();
        explicit Context(ApplicationConfig &_config);

        virtual ~Context();

        [[nodiscard]] ApplicationConfig &getConfig();
    };

}

#endif //CONTEXT_H
