//
// Created by mito on 19.06.2024.
//

#include "../include/Context.h"

namespace rumpedav {

    Context::Context() = default;

    Context::~Context() = default;

    ApplicationConfig &Context::Config() {
        return config;
    }

}
