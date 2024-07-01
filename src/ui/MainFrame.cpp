//
// Created by Dmitry Velychko on 21.06.2024.
//

#include "../../include/ui/MainFrame.h"

#include "../../cmake-build-release/_deps/wx_widgets-src/include/wx/wrapsizer.h"
#include "../../cmake-build-release/_deps/wx_widgets-src/include/wx/msw/tglbtn.h"
#include "../../include/ui/controls/wxColorPane.h"

namespace rumpedav {
    MainFrame::MainFrame()
        : wxFrame(nullptr, wxID_ANY, "Hello World", wxDefaultPosition,
                  wxWindow::FromDIP(wxSize(800, 600), nullptr),
                  wxDEFAULT_FRAME_STYLE // | wxRESIZE_BORDER // | wxFRAME_TOOL_WINDOW | wxNO_BORDER
        ) {
        // Styling
        // https://stackoverflow.com/questions/68088652/create-a-titleless-borderless-draggable-wxframe-in-wxwidgets
        // https://forums.wxwidgets.org/viewtopic.php?t=44241
        OnInit();
    }

    void MainFrame::OnInit() {
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
        Bind(wxEVT_MENU, [&](wxCommandEvent &event) {
            auto *auiFrame = new SampleAuiFrame(this, wxID_ANY, "AUI", wxDefaultPosition,
                                                wxWindow::FromDIP(wxSize(800, 600), nullptr));
            auiFrame->Show();
        }, ID_MENU_SAMPLE_AUI);

        // Menu - Samples - DragFrame
        menuSamples->Append(ID_MENU_SAMPLE_DND, "&DragAndDrop");
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

        // Window
        SetMinSize(FromDIP(wxSize(400, 300)));
        SetThemeEnabled(true);

        // StatusBar
        CreateStatusBar(2);
        SetStatusText("Welcome to wxWidgets!", 0);
        SetStatusText("Ready", 1);

        // AUI
        m_auiManager.SetManagedWindow(this);

        CreateToolbarLeft();
        CreatePanelContent();
        CreatePanelProject();

        m_auiManager.AddPane(
            CreateSizeReportCtrl(), wxAuiPaneInfo().
            Name("size_report_content").Caption("Size Report").
            Right().
            CloseButton(true)
        );

        // Set AUI Flags
        unsigned int flags = m_auiManager.GetFlags();
        flags |= wxAUI_MGR_LIVE_RESIZE; // Allow Live Update of Resize
        m_auiManager.SetFlags(flags);

        //m_auiManager.GetArtProvider()->SetColor(wxAuiPaneDockArtSetting)

        Bind(wxEVT_AUI_PANE_CLOSE, &MainFrame::OnPaneClose, this);

        m_auiManager.Update();
    }

    void MainFrame::OnPaneClose(wxAuiManagerEvent &evt) {
        if (evt.pane->name == PANE_PROJECT) {
            m_tbLeft->SetToolSticky(ID_TB_LEFT_BTN_PROJECT, false);
        }
    }


    void MainFrame::OnHello(wxCommandEvent &event) {
        std::cout << "Hello Click" << std::endl;
    }

    void MainFrame::OnExit(wxCommandEvent &event) {
        Close();
    }

    void MainFrame::OnAbout(wxCommandEvent &event) {
    }

    void MainFrame::CreateToolbarLeft() {
        if (m_tbLeft != nullptr) return;
        const wxBitmapBundle bmFolder = wxArtProvider::GetBitmapBundle(wxART_FOLDER_OPEN, wxART_OTHER, wxSize(24, 24));

        m_tbLeft = std::make_unique<wxAuiToolBar>(
            this, ID_TB_LEFT, wxDefaultPosition, wxDefaultSize,
            wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_OVERFLOW | wxAUI_TB_VERTICAL |
            wxAUI_TB_PLAIN_BACKGROUND
        );

        m_tbLeft->AddTool(ID_TB_LEFT_BTN_PROJECT, _("Project"), bmFolder, _("Open Project"));
        m_tbLeft->SetToolSticky(ID_TB_LEFT_BTN_PROJECT, true);
        Bind(wxEVT_MENU, [&](wxCommandEvent &event) {
            m_tbLeft->SetToolSticky(ID_TB_LEFT_BTN_PROJECT, !m_tbLeft->GetToolSticky(ID_TB_LEFT_BTN_PROJECT));
            m_auiManager.GetPane(PANE_PROJECT).Show(m_tbLeft->GetToolSticky(ID_TB_LEFT_BTN_PROJECT));
            m_auiManager.Update();
        }, ID_TB_LEFT_BTN_PROJECT);

        m_tbLeft->AddSeparator();

        m_tbLeft->AddTool(ID_TB_LEFT_BTN_OPTIONS, _("Options"), wxArtProvider::GetBitmapBundle(wxART_FOLDER),
                          _("Options"));
        //tbLeft->SetToolDropDown(ID_TB_PROJECT_OPTIONS, true);
        m_tbLeft->ToggleTool(ID_TB_LEFT_BTN_OPTIONS, false);

        m_tbLeft->SetOverflowVisible(false);
        m_tbLeft->Realize();

        m_auiManager.AddPane(
            m_tbLeft.get(), wxAuiPaneInfo().
            Name(PANE_TOOLBAR_LEFT).Caption("Sample Vertical Toolbar").
            ToolbarPane().Left().
            Gripper(false).BestSize(wxSize(42, INT_FAST16_MAX))
        );
    }

    void MainFrame::CreatePanelContent(const wxSize &paneSize) {
        auto *controlsPanel = BuildControlsPanel(this);

        m_auiManager.AddPane(controlsPanel, wxAuiPaneInfo().
                             Name(PANE_CONTENT).Caption("SFML Content").
                             CenterPane()
        );
    }

    wxSizeReportCtrl *MainFrame::CreateSizeReportCtrl(const wxSize &paneSize) {
        auto *ctrl = new wxSizeReportCtrl(this, wxID_ANY, wxDefaultPosition, paneSize, &m_auiManager);
        return ctrl;
    }

    void MainFrame::CreatePanelProject(const wxSize &paneSize) {
        m_pProject = std::make_unique<wxTreeCtrl>(
            this, wxID_ANY,
            wxPoint(0, 0), paneSize,
            wxTR_DEFAULT_STYLE | wxNO_BORDER
        );

        wxSize size(16, 16);
        wxVector<wxBitmapBundle> images;
        images.push_back(wxArtProvider::GetBitmapBundle(wxART_FOLDER, wxART_OTHER, size));
        images.push_back(wxArtProvider::GetBitmapBundle(wxART_NORMAL_FILE, wxART_OTHER, size));
        m_pProject->SetImages(images);

        wxTreeItemId root = m_pProject->AddRoot("Asset Viewer", 0);
        wxArrayTreeItemIds items;

        items.Add(m_pProject->AppendItem(root, "Item 1", 0));
        items.Add(m_pProject->AppendItem(root, "Item 2", 0));
        items.Add(m_pProject->AppendItem(root, "Item 3", 0));
        items.Add(m_pProject->AppendItem(root, "Item 4", 0));
        items.Add(m_pProject->AppendItem(root, "Item 5", 0));

        int i, count;
        for (i = 0, count = items.Count(); i < count; ++i) {
            wxTreeItemId id = items.Item(i);
            m_pProject->AppendItem(id, "Subitem 1", 1);
            m_pProject->AppendItem(id, "Subitem 2", 1);
            m_pProject->AppendItem(id, "Subitem 3", 1);
            m_pProject->AppendItem(id, "Subitem 4", 1);
            m_pProject->AppendItem(id, "Subitem 5", 1);
        }

        m_pProject->Expand(root);

        m_auiManager.AddPane(
            m_pProject.get(), wxAuiPaneInfo().
            Name(PANE_PROJECT).Caption("Project").
            DefaultPane().
            Left()
            //.Layer(1).Position(1).
            //CloseButton(true).
            //MaximizeButton(true)
        );
    }

    wxPanel *MainFrame::BuildControlsPanel(wxWindow *parent) {
        // https://www.youtube.com/watch?v=QhQ7aeKjYG4&list=PL0qQTroQZs5sxKZDdJrn8fEjNXCPT7f5T&index=3
        const std::string lightBackground = "#f3f3f3";
        const std::string darkBackground = "#2c2c2c";

        const auto controlsPanel = new wxPanel(parent, wxID_ANY);
        const bool isDark = wxSystemSettings::GetAppearance().IsDark();
        controlsPanel->SetBackgroundColour(wxColor(isDark ? darkBackground : lightBackground));

        const auto vSizer = new wxBoxSizer(wxVERTICAL);
        const auto text = new wxStaticText(controlsPanel, wxID_ANY, "Colors");
        text->SetForegroundColour(wxColor(isDark ? lightBackground : darkBackground));
        vSizer->Add(text, 0, wxALL, FromDIP(4));

        const auto hwSizer = new wxWrapSizer(wxHORIZONTAL);

        const auto singleColorPane = new wxColorPane(controlsPanel, wxID_ANY, wxColor(100, 100, 200));
        singleColorPane->selected = true;
        hwSizer->Add(singleColorPane, 0, wxALL, FromDIP(4));

        const auto btnOk = new wxButton(controlsPanel, wxID_ANY, "OK");
        hwSizer->Add(btnOk, 0, wxALL, FromDIP(4));

        vSizer->Add(hwSizer, 0, wxALL, FromDIP(4));

        controlsPanel->SetSizer(vSizer);
        return controlsPanel;

    }
}
