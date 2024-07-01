//
// Created by mito on 19.06.2024.
//

#ifndef APPLICATION_H
#define APPLICATION_H

#include "wx/wx.h"
#include "ApplicationConfig.h"
#include "Context.h"
#include "./ui/MainFrame.h"
#include "wx/cmdline.h"

namespace rumpedav {
    // class MainFrame;

    class Application : public wxApp {
        Context context;

    public:
        Application();

        explicit Application(const ApplicationConfig &_config);

        ~Application() override;

        bool OnInit() override;

        int OnExit() override;

        int OnRun() override;

        bool ProcessIdle() override;

        void CleanUp() override;

        bool OnInitGui() override;

        void OnInitCmdLine(wxCmdLineParser &parser) override;

        bool OnCmdLineParsed(wxCmdLineParser &parser) override;
    };
}

#endif //APPLICATION_H
