//
// Created by mito on 19.06.2024.
//

#ifndef CONTEXT_H
#define CONTEXT_H

#include "ApplicationConfig.h"

namespace rumpedav {
    class Application;

    class Context {
        friend class Application;

    protected:
        static ApplicationConfig config;

    public:
        Context();

        virtual ~Context();

        [[nodiscard]] static ApplicationConfig &Config();
    };
}

#endif //CONTEXT_H
