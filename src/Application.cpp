//
// Created by mito on 19.06.2024.
//

#include "../include/Application.h"

namespace rumpedav {

    Application::Application() = default;

    Application::Application(ApplicationConfig &_config) {
        context.config = _config;
    }

    Application::~Application() = default;

    bool Application::OnInit() {
        auto *frame = new MainFrame();
        frame->Show();
        return true;
        //return wxAppConsoleBase::OnInit();
    }



}
