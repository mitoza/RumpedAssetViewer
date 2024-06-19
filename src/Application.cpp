//
// Created by mito on 19.06.2024.
//

#include "../include/Application.h"

#include "../include/MainWindow.h"

namespace rumpedav {
    Application::Application(ApplicationConfig &_config) {
        Context::config = ApplicationConfig(_config);
        //window.setIcon()
    }

    Application::~Application() = default;

    void Application::run() {
        MainWindow mainWindow;
        mainWindow.show(false);
    }
}
