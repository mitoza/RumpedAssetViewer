//
// Created by Dmitry Velychko on 21.06.2024.
//

#include "../../include/ui/MainFrame.h"

namespace rumpedav {

    MainFrame::MainFrame()
            : wxFrame(nullptr, wxID_ANY, "Hello World", wxDefaultPosition,
                      wxWindow::FromDIP(wxSize(800, 600), nullptr)) {

        // MenuBar
        auto *menuBar = new wxMenuBar;

        // Menu - File
        auto *menuFile = new wxMenu;
        menuBar->Append(menuFile, "&File");

        // Menu - File - Help
        menuFile->Append(ID_MENU_Hello, "&Hello...\tCtrl+H",
                         "Help string shown in status bar for this menu item");
        Bind(wxEVT_MENU, &MainFrame::OnHello, this, ID_MENU_Hello);

        // Menu - File - QuickHelp
        menuFile->Append(ID_MENU_QuickHello, "&QuickHello\tCtrl+Q");
        Bind(wxEVT_MENU, [&](wxCommandEvent &) {
            SetStatusText("Quick Help");
        }, ID_MENU_QuickHello);

        // Menu - File - Separator
        menuFile->AppendSeparator();

        // Menu - File - Exit
        menuFile->Append(wxID_EXIT);
        Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);

        // Menu - Samples
        auto *menuSamples = new wxMenu;
        menuBar->Append(menuSamples, "&Samples");

        // Menu - Samples - ComboBox
        menuSamples->Append(ID_MENU_SAMPLE_ComboBox, "&Combobox");
        Bind(wxEVT_MENU, [&](wxCommandEvent &) {
            auto *comboBoxFrame = new SampleComboFrame(this, "ComboBox");
            comboBoxFrame->Show();
        }, ID_MENU_SAMPLE_ComboBox);

        // Menu - Samples - AuiFrame
        menuSamples->Append(ID_MENU_SAMPLE_AUI, "&AUI");
        Bind(wxEVT_MENU, [&](wxCommandEvent &) {
//            auto *auiFrame = new AuiFrame(this, "AUI");
            auto *auiFrame = new SampleAuiFrame(this, wxID_ANY, "AUI", wxDefaultPosition,
            wxWindow::FromDIP(wxSize(800, 600), nullptr));
            auiFrame->Show();
        }, ID_MENU_SAMPLE_AUI);

        // Menu - Help / About
        auto *menuHelp = new wxMenu;
        menuBar->Append(menuHelp, "&Help");
        menuHelp->Append(wxID_ABOUT);
        Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);

        // Menu Creation
        SetMenuBar(menuBar);

        // StatusBar Creation
        CreateStatusBar(2);
        SetStatusText("Welcome to wxWidgets!", 0);
        //auto *trackerNode = new wxTrackerNode();

        SetStatusText("Ready", 1);
        SetMinSize(FromDIP(wxSize(400, 300)));

    }

    void MainFrame::OnHello(wxCommandEvent &event) {
        std::cout << "Hello Click" << std::endl;
    }

    void MainFrame::OnExit(wxCommandEvent &event) {
        Close();
    }

    void MainFrame::OnAbout(wxCommandEvent &event) {

    }
}