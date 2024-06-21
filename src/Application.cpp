//
// Created by mito on 19.06.2024.
//

#include "../include/Application.h"

namespace rumpedav {
    Application::Application(ApplicationConfig &_config) {
        context.config = _config;
    }

    Application::~Application() = default;

    void Application::run() {

    }

}
