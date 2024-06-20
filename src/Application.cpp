//
// Created by mito on 19.06.2024.
//

#include "../include/Application.h"

#include "../include/MainWindow.h"

namespace rumpedav {
    Application::Application(ApplicationConfig &_config) {
        context.config = _config;
    }

    Application::~Application() = default;

    void Application::run() {
        MainWindow mainWindow(context);
        mainWindow.show();
    }

}
