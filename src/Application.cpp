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
        SetTopWindow(mainFrame);
        return true;
    }

    int Application::OnExit() {
        return wxApp::OnExit();
    }

    int Application::OnRun() {
        int exitCode = wxApp::OnRun();
        //wxTheClipboard->Flush();
        if (exitCode != 0) {
            return exitCode;
        }
        return EXIT_SUCCESS;
    }

    bool Application::ProcessIdle() {
        return wxApp::ProcessIdle();
    }

    void Application::CleanUp() {
        wxApp::CleanUp();
    }

    bool Application::OnInitGui() {
        return wxApp::OnInitGui();
    }

    void Application::OnInitCmdLine(wxCmdLineParser &parser) {
        wxApp::OnInitCmdLine(parser);

        // const wxCmdLineEntryDesc g_cmdLineDesc[] = {
        //     {
        //         wxCMD_LINE_SWITCH, _("h"), _("help"), _("displays help on the command line parameters"),
        //         wxCMD_LINE_VAL_NONE, wxCMD_LINE_OPTION_HELP
        //     },
        //     {
        //         wxCMD_LINE_SWITCH, _("t"), _("test"), _("test switch"),
        //         wxCMD_LINE_VAL_NONE, wxCMD_LINE_OPTION_MANDATORY
        //     },
        //     {wxCMD_LINE_SWITCH, _("s"), _("silent"), _("disables the GUI")},
        //
        //     {wxCMD_LINE_NONE}
        // };
        //
        // parser.SetDesc(g_cmdLineDesc);
        // // must refuse '/' as parameter starter or cannot use "/path" style paths
        // parser.SetSwitchChars (_("-"));
    }

    bool Application::OnCmdLineParsed(wxCmdLineParser &parser) {
        // bool config_silent_mode = parser.Found(wxT("s"));
        //
        // // to get at your unnamed parameters use
        // wxArrayString files;
        // for (int i = 0; i < parser.GetParamCount(); i++) {
        //     files.Add(parser.GetParam(i));
        // }
        //
        // // and other command line parameters
        //
        // // then do what you need with them.
        //
        // return true;
        return wxApp::OnCmdLineParsed(parser);
    }
}
