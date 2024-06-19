//
// Created by mito on 19.06.2024.
//

#include "../include/Context.h"

namespace rumpedav {

    Context::Context() = default;

    Context::Context(ApplicationConfig &_config) {
        config = _config;
    }

    Context::~Context() = default;

    ApplicationConfig &Context::getConfig() {
        return config;
    }

}
