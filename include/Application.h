//
// Created by mito on 19.06.2024.
//

#ifndef APPLICATION_H
#define APPLICATION_H

#include "wx/wx.h"
#include "ApplicationConfig.h"
#include "Context.h"
#include "./ui/MainFrame.h"

namespace rumpedav {
    class MainFrame;

    class Application : public wxApp {
        Context context;
    public:
        Application();

        explicit Application(ApplicationConfig &_config);

        ~Application() override;

        bool OnInit() override;

    };

}

#endif //APPLICATION_H
