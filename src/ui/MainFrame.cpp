//
// Created by Dmitry Velychko on 21.06.2024.
//

#include "../../include/ui/MainFrame.h"

namespace rumpedav {
    MainFrame::MainFrame()
        : wxFrame(nullptr, wxID_ANY, "Hello World", wxDefaultPosition,
                  wxWindow::FromDIP(wxSize(800, 600), nullptr)) {
        initMenuBar();
        initUI();

    }

    MainFrame::~MainFrame() = default;

    void MainFrame::initUI() {
        // Window
        SetMinSize(FromDIP(wxSize(400, 300)));
        SetThemeEnabled(true);

        // StatusBar
        CreateStatusBar(2);
        SetStatusText("Welcome to wxWidgets!", 0);
        SetStatusText("Ready", 1);

        // AUI
        m_auiManager.SetManagedWindow(this);
        //m_auiManager.GetArtProvider()->SetColor(wxAuiPaneDockArtSetting)

        // Create Project Toolbar
        auto *tbLeft = new wxAuiToolBar(this, ID_TB_LEFT, wxDefaultPosition, wxDefaultSize,
                                           wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_OVERFLOW | wxAUI_TB_VERTICAL | wxAUI_TB_PLAIN_BACKGROUND);
        wxBitmapBundle bmFolder = wxArtProvider::GetBitmapBundle(wxART_FOLDER_OPEN, wxART_OTHER, wxSize(24, 24));
        tbLeft->AddTool(ID_TB_PROJECT_BTN, _("Project"), bmFolder, _("Open Project"));
        tbLeft->AddSeparator();
        tbLeft->AddTool(ID_TB_PROJECT_OPTIONS, _("Options"), wxArtProvider::GetBitmapBundle(wxART_FOLDER), _("Options"));
        //tbLeft->SetToolDropDown(ID_TB_PROJECT_OPTIONS, true);
        tbLeft->ToggleTool(ID_TB_PROJECT_OPTIONS, false);
        tbLeft->SetOverflowVisible(false);
        tbLeft->Realize();

        // m_auiManager.AddPane(tbProject, wxAuiPaneInfo().
        //     Name("tbProject").Caption("Sample Vertical Toolbar").Gripper(false).
        //     ToolbarPane().Right().RightDockable(true).GripperTop(false)
        //     );

        m_auiManager.Update();
    }

    void MainFrame::initMenuBar() {
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
            wxMessageBox(_("wxAUI Demo 1"), _("About wxAUI Demo 1"), wxICON_QUESTION | wxOK, this);
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
