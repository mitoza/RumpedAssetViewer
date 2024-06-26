//
// Created by mito on 19.06.2024.
//

#include "../include/Application.h"

namespace rumpedav {

    Application::Application() = default;

    Application::Application(const ApplicationConfig &_config) {
        context.config = _config;
    }

    Application::~Application() = default;

    bool Application::OnInit() {
        if (!wxApp::OnInit()) return false;

#if wxUSE_LIBPNG
        //wxImage::AddHandler(new wxPNGHandler);
#endif

        auto *mainFrame = new MainFrame();
        mainFrame->Show();
        return true;
    }


}
