//
// Created by Dmitry Velychko on 21.06.2024.
//

#include "../../include/ui/MainFrame.h"

namespace rumpedav {

    MainFrame::MainFrame()
        : wxFrame(nullptr, wxID_ANY, "Hello World") {

        auto *menuFile = new wxMenu;
        menuFile->Append(ID_Hello, "&Hello...\tCtrl+H",
                         "Help string shown in status bar for this menu item");
        menuFile->AppendSeparator();
        menuFile->Append(wxID_EXIT);

        auto *menuHelp = new wxMenu;
        menuHelp->Append(wxID_ABOUT);

        auto *menuBar = new wxMenuBar;
        menuBar->Append(menuFile, "&File");
        menuBar->Append(menuHelp, "&Help");

        SetMenuBar(menuBar);

        CreateStatusBar();
        SetStatusText("Welcome to wxWidgets!");


        Bind(wxEVT_MENU, &MainFrame::OnHello, this, ID_Hello);
        Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
        Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
    }

    MainFrame::~MainFrame() {

    }

    void MainFrame::OnHello(wxCommandEvent &event) {

    }

    void MainFrame::OnExit(wxCommandEvent &event) {

    }

    void MainFrame::OnAbout(wxCommandEvent &event) {

    }
}