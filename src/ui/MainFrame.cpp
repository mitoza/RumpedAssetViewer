//
// Created by Dmitry Velychko on 21.06.2024.
//

#include "../../include/ui/MainFrame.h"

namespace rumpedav {
    MainFrame::MainFrame()
            : wxFrame(nullptr, wxID_ANY, "Hello World", wxDefaultPosition,
                      wxWindow::FromDIP(wxSize(800, 600), nullptr),
                      wxDEFAULT_FRAME_STYLE | wxRESIZE_BORDER // | wxFRAME_TOOL_WINDOW | wxNO_BORDER
                      ) {
        // https://stackoverflow.com/questions/68088652/create-a-titleless-borderless-draggable-wxframe-in-wxwidgets
        initMenuBar();
        initUI();

    }

    MainFrame::~MainFrame() = default;

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

        // Menu - Samples - DragFrame
        menuSamples->Append(ID_MENU_SAMPLE_AUI, "&DragAndDrop");
        Bind(wxEVT_MENU, [&](wxCommandEvent &) {
            auto *dndFrame = new DnDFrame(this);
            dndFrame->Show();
        }, ID_MENU_SAMPLE_DND);

        // Menu - Help / About
        auto *menuHelp = new wxMenu;
        menuBar->Append(menuHelp, "&Help");
        menuHelp->Append(wxID_ABOUT);
        Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);

        // Menu Creation
        SetMenuBar(menuBar);
    }

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
        auto *tbLeft = new wxAuiToolBar(this, ID_TB_LEFT, wxDefaultPosition,
                                        FromDIP(wxSize(120, 500)),
                                        //wxGetDisplaySize(),
                                        wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_OVERFLOW | wxAUI_TB_VERTICAL |
                                        wxAUI_TB_PLAIN_BACKGROUND);
        wxBitmapBundle bmFolder = wxArtProvider::GetBitmapBundle(wxART_FOLDER_OPEN, wxART_OTHER, wxSize(24, 24));
        tbLeft->AddTool(ID_TB_PROJECT_BTN, _("Project"), bmFolder, _("Open Project"));
        tbLeft->AddSeparator();
        tbLeft->AddTool(ID_TB_PROJECT_OPTIONS, _("Options"), wxArtProvider::GetBitmapBundle(wxART_FOLDER),
                        _("Options"));
        //tbLeft->SetToolDropDown(ID_TB_PROJECT_OPTIONS, true);
        tbLeft->ToggleTool(ID_TB_PROJECT_OPTIONS, false);
        tbLeft->SetOverflowVisible(false);
        tbLeft->Realize();

        m_auiManager.AddPane(tbLeft, wxAuiPaneInfo().
                Name("tbProject").Caption("Sample Vertical Toolbar").
                ToolbarPane()
                .Maximize()
                .Gripper(false)
                .Left()
                .BestSize(wxSize(32, INT_FAST16_MAX))

                );

        // Add SFML Canvas Panel
        m_auiManager.AddPane(CreateSFMLControl(), wxAuiPaneInfo().
                        Name("sfml_content").Caption("SFML Content").
                        DefaultPane().Row(1));

        m_auiManager.AddPane(CreateSizeReportCtrl(), wxAuiPaneInfo().
                Name("size_report_content").Caption("Size Report").
                DefaultPane().Row(0));

        m_auiManager.Update();
    }

    void MainFrame::OnHello(wxCommandEvent &event) {
        std::cout << "Hello Click" << std::endl;
    }

    void MainFrame::OnExit(wxCommandEvent &event) {
        Close();
    }

    void MainFrame::OnAbout(wxCommandEvent &event) {
    }

    wxSFMLCanvas *MainFrame::CreateSFMLControl(const wxSize &size) {
        auto *control = new wxSFMLCanvas(this, wxID_ANY, wxDefaultPosition, size,
                                         wxNO_BORDER, &m_auiManager);
        return control;
    }

    wxSizeReportCtrl *MainFrame::CreateSizeReportCtrl(const wxSize &size) {
        auto *ctrl = new wxSizeReportCtrl(this, wxID_ANY,
                                                      wxDefaultPosition,
                                                      size, &m_auiManager);
        return ctrl;
    }

}
