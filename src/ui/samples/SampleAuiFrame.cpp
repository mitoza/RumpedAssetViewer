//
// Created by Dmitry Velychko on 23.06.2024.
//

#include "../../../include/ui/samples/SampleAuiFrame.h"
#include "../../../include/ui/samples/SettingsPanel.h"


wxBEGIN_EVENT_TABLE(SampleAuiFrame, wxFrame)
//                EVT_ERASE_BACKGROUND(SampleAuiFrame::OnEraseBackground)
//                EVT_SIZE(SampleAuiFrame::OnSize)
                EVT_MENU(SampleAuiFrame::ID_CreateTree, SampleAuiFrame::OnCreateTree)
                EVT_MENU(SampleAuiFrame::ID_CreateGrid, SampleAuiFrame::OnCreateGrid)
                EVT_MENU(SampleAuiFrame::ID_CreateText, SampleAuiFrame::OnCreateText)
                EVT_MENU(SampleAuiFrame::ID_CreateHTML, SampleAuiFrame::OnCreateHTML)
                EVT_MENU(SampleAuiFrame::ID_CreateSizeReport, SampleAuiFrame::OnCreateSizeReport)
                EVT_MENU(SampleAuiFrame::ID_CreateNotebook, SampleAuiFrame::OnCreateNotebook)
                EVT_MENU(SampleAuiFrame::ID_CreatePerspective, SampleAuiFrame::OnCreatePerspective)
                EVT_MENU(SampleAuiFrame::ID_CopyPerspectiveCode, SampleAuiFrame::OnCopyPerspectiveCode)
                EVT_MENU(ID_AllowFloating, SampleAuiFrame::OnManagerFlag)
                EVT_MENU(ID_TransparentHint, SampleAuiFrame::OnManagerFlag)
                EVT_MENU(ID_VenetianBlindsHint, SampleAuiFrame::OnManagerFlag)
                EVT_MENU(ID_RectangleHint, SampleAuiFrame::OnManagerFlag)
                EVT_MENU(ID_NoHint, SampleAuiFrame::OnManagerFlag)
                EVT_MENU(ID_HintFade, SampleAuiFrame::OnManagerFlag)
                EVT_MENU(ID_NoVenetianFade, SampleAuiFrame::OnManagerFlag)
                EVT_MENU(ID_TransparentDrag, SampleAuiFrame::OnManagerFlag)
                EVT_MENU(ID_LiveUpdate, SampleAuiFrame::OnManagerFlag)
                EVT_MENU(ID_AllowActivePane, SampleAuiFrame::OnManagerFlag)
                EVT_MENU(ID_NotebookTabFixedWidth, SampleAuiFrame::OnNotebookFlag)
                EVT_MENU(ID_NotebookNoCloseButton, SampleAuiFrame::OnNotebookFlag)
                EVT_MENU(ID_NotebookCloseButton, SampleAuiFrame::OnNotebookFlag)
                EVT_MENU(ID_NotebookCloseButtonAll, SampleAuiFrame::OnNotebookFlag)
                EVT_MENU(ID_NotebookCloseButtonActive, SampleAuiFrame::OnNotebookFlag)
                EVT_MENU(ID_NotebookAllowTabMove, SampleAuiFrame::OnNotebookFlag)
                EVT_MENU(ID_NotebookAllowTabExternalMove, SampleAuiFrame::OnNotebookFlag)
                EVT_MENU(ID_NotebookAllowTabSplit, SampleAuiFrame::OnNotebookFlag)
                EVT_MENU(ID_NotebookScrollButtons, SampleAuiFrame::OnNotebookFlag)
                EVT_MENU(ID_NotebookWindowList, SampleAuiFrame::OnNotebookFlag)
                EVT_MENU(ID_NotebookArtGloss, SampleAuiFrame::OnNotebookFlag)
                EVT_MENU(ID_NotebookArtSimple, SampleAuiFrame::OnNotebookFlag)
                EVT_MENU(ID_NotebookAlignTop, SampleAuiFrame::OnTabAlignment)
                EVT_MENU(ID_NotebookAlignBottom, SampleAuiFrame::OnTabAlignment)
                EVT_MENU(ID_NotebookNewTab, SampleAuiFrame::OnNotebookNewTab)
                EVT_MENU(ID_NotebookDeleteTab, SampleAuiFrame::OnNotebookDeleteTab)
                EVT_MENU(ID_NoGradient, SampleAuiFrame::OnGradient)
                EVT_MENU(ID_VerticalGradient, SampleAuiFrame::OnGradient)
                EVT_MENU(ID_HorizontalGradient, SampleAuiFrame::OnGradient)
                EVT_MENU(ID_AllowToolbarResizing, SampleAuiFrame::OnToolbarResizing)
                EVT_MENU(ID_Settings, SampleAuiFrame::OnSettings)
                EVT_MENU(ID_CustomizeToolbar, SampleAuiFrame::OnCustomizeToolbar)
                EVT_MENU(ID_GridContent, SampleAuiFrame::OnChangeContentPane)
                EVT_MENU(ID_TreeContent, SampleAuiFrame::OnChangeContentPane)
                EVT_MENU(ID_TextContent, SampleAuiFrame::OnChangeContentPane)
                EVT_MENU(ID_SizeReportContent, SampleAuiFrame::OnChangeContentPane)
                EVT_MENU(ID_HTMLContent, SampleAuiFrame::OnChangeContentPane)
                EVT_MENU(ID_NotebookContent, SampleAuiFrame::OnChangeContentPane)
                EVT_MENU(wxID_EXIT, SampleAuiFrame::OnExit)
                EVT_MENU(wxID_ABOUT, SampleAuiFrame::OnAbout)
                EVT_UPDATE_UI(ID_NotebookTabFixedWidth, SampleAuiFrame::OnUpdateUI)
                EVT_UPDATE_UI(ID_NotebookNoCloseButton, SampleAuiFrame::OnUpdateUI)
                EVT_UPDATE_UI(ID_NotebookCloseButton, SampleAuiFrame::OnUpdateUI)
                EVT_UPDATE_UI(ID_NotebookCloseButtonAll, SampleAuiFrame::OnUpdateUI)
                EVT_UPDATE_UI(ID_NotebookCloseButtonActive, SampleAuiFrame::OnUpdateUI)
                EVT_UPDATE_UI(ID_NotebookAllowTabMove, SampleAuiFrame::OnUpdateUI)
                EVT_UPDATE_UI(ID_NotebookAllowTabExternalMove, SampleAuiFrame::OnUpdateUI)
                EVT_UPDATE_UI(ID_NotebookAllowTabSplit, SampleAuiFrame::OnUpdateUI)
                EVT_UPDATE_UI(ID_NotebookScrollButtons, SampleAuiFrame::OnUpdateUI)
                EVT_UPDATE_UI(ID_NotebookWindowList, SampleAuiFrame::OnUpdateUI)
                EVT_UPDATE_UI(ID_AllowFloating, SampleAuiFrame::OnUpdateUI)
                EVT_UPDATE_UI(ID_TransparentHint, SampleAuiFrame::OnUpdateUI)
                EVT_UPDATE_UI(ID_VenetianBlindsHint, SampleAuiFrame::OnUpdateUI)
                EVT_UPDATE_UI(ID_RectangleHint, SampleAuiFrame::OnUpdateUI)
                EVT_UPDATE_UI(ID_NoHint, SampleAuiFrame::OnUpdateUI)
                EVT_UPDATE_UI(ID_HintFade, SampleAuiFrame::OnUpdateUI)
                EVT_UPDATE_UI(ID_NoVenetianFade, SampleAuiFrame::OnUpdateUI)
                EVT_UPDATE_UI(ID_TransparentDrag, SampleAuiFrame::OnUpdateUI)
                EVT_UPDATE_UI(ID_LiveUpdate, SampleAuiFrame::OnUpdateUI)
                EVT_UPDATE_UI(ID_NoGradient, SampleAuiFrame::OnUpdateUI)
                EVT_UPDATE_UI(ID_VerticalGradient, SampleAuiFrame::OnUpdateUI)
                EVT_UPDATE_UI(ID_HorizontalGradient, SampleAuiFrame::OnUpdateUI)
                EVT_UPDATE_UI(ID_AllowToolbarResizing, SampleAuiFrame::OnUpdateUI)
                EVT_MENU_RANGE(SampleAuiFrame::ID_FirstPerspective, SampleAuiFrame::ID_FirstPerspective + 1000,
                               SampleAuiFrame::OnRestorePerspective)
                EVT_AUITOOLBAR_TOOL_DROPDOWN(ID_DropDownToolbarItem, SampleAuiFrame::OnDropDownToolbarItem)
                EVT_AUI_PANE_CLOSE(SampleAuiFrame::OnPaneClose)
                EVT_AUINOTEBOOK_ALLOW_DND(wxID_ANY, SampleAuiFrame::OnAllowNotebookDnD)
                EVT_AUINOTEBOOK_PAGE_CLOSE(wxID_ANY, SampleAuiFrame::OnNotebookPageClose)
                EVT_AUINOTEBOOK_PAGE_CLOSED(wxID_ANY, SampleAuiFrame::OnNotebookPageClosed)
                EVT_AUINOTEBOOK_PAGE_CHANGING(wxID_ANY, SampleAuiFrame::OnNotebookPageChanging)
wxEND_EVENT_TABLE()


SampleAuiFrame::SampleAuiFrame(wxWindow *parent,
                               wxWindowID id,
                               const wxString &title,
                               const wxPoint &pos,
                               const wxSize &size,
                               long style)
        : wxFrame(parent, id, title, pos, size, style) {
    // tell wxAuiManager to manage this frame
    m_mgr.SetManagedWindow(this);

    // set frame icon
    //SetIcon(wxIcon(sample_xpm));

    // set up default notebook style
    m_notebook_style = wxAUI_NB_DEFAULT_STYLE | wxAUI_NB_TAB_EXTERNAL_MOVE | wxNO_BORDER;
    m_notebook_theme = 0;

    // create menu
    wxMenuBar *mb = new wxMenuBar;

    wxMenu *file_menu = new wxMenu;
    file_menu->Append(wxID_EXIT);

    wxMenu *view_menu = new wxMenu;
    view_menu->Append(ID_CreateText, _("Create Text Control"));
    view_menu->Append(ID_CreateHTML, _("Create HTML Control"));
    view_menu->Append(ID_CreateTree, _("Create Tree"));
    view_menu->Append(ID_CreateGrid, _("Create Grid"));
    view_menu->Append(ID_CreateNotebook, _("Create Notebook"));
    view_menu->Append(ID_CreateSizeReport, _("Create Size Reporter"));
    view_menu->AppendSeparator();
    view_menu->Append(ID_GridContent, _("Use a Grid for the Content Pane"));
    view_menu->Append(ID_TextContent, _("Use a Text Control for the Content Pane"));
    view_menu->Append(ID_HTMLContent, _("Use an HTML Control for the Content Pane"));
    view_menu->Append(ID_TreeContent, _("Use a Tree Control for the Content Pane"));
    view_menu->Append(ID_NotebookContent, _("Use a wxAuiNotebook control for the Content Pane"));
    view_menu->Append(ID_SizeReportContent, _("Use a Size Reporter for the Content Pane"));

    wxMenu *options_menu = new wxMenu;
    options_menu->AppendRadioItem(ID_TransparentHint, _("Transparent Hint"));
    options_menu->AppendRadioItem(ID_VenetianBlindsHint, _("Venetian Blinds Hint"));
    options_menu->AppendRadioItem(ID_RectangleHint, _("Rectangle Hint"));
    options_menu->AppendRadioItem(ID_NoHint, _("No Hint"));
    options_menu->AppendSeparator();
    options_menu->AppendCheckItem(ID_HintFade, _("Hint Fade-in"));
    options_menu->AppendCheckItem(ID_AllowFloating, _("Allow Floating"));
    options_menu->AppendCheckItem(ID_NoVenetianFade, _("Disable Venetian Blinds Hint Fade-in"));
    options_menu->AppendCheckItem(ID_TransparentDrag, _("Transparent Drag"));
    options_menu->AppendCheckItem(ID_AllowActivePane, _("Allow Active Pane"));
    // Only show "live resize" toggle if it's actually functional.
    if (!wxAuiManager::AlwaysUsesLiveResize())
        options_menu->AppendCheckItem(ID_LiveUpdate, _("Live Resize Update"));
    options_menu->AppendSeparator();
    options_menu->AppendRadioItem(ID_NoGradient, _("No Caption Gradient"));
    options_menu->AppendRadioItem(ID_VerticalGradient, _("Vertical Caption Gradient"));
    options_menu->AppendRadioItem(ID_HorizontalGradient, _("Horizontal Caption Gradient"));
    options_menu->AppendSeparator();
    options_menu->AppendCheckItem(ID_AllowToolbarResizing, _("Allow Toolbar Resizing"));
    options_menu->AppendSeparator();
    options_menu->Append(ID_Settings, _("Settings Pane"));

    wxMenu *notebook_menu = new wxMenu;
    notebook_menu->AppendRadioItem(ID_NotebookArtGloss, _("Glossy Theme (Default)"));
    notebook_menu->AppendRadioItem(ID_NotebookArtSimple, _("Simple Theme"));
    notebook_menu->AppendSeparator();
    notebook_menu->AppendRadioItem(ID_NotebookNoCloseButton, _("No Close Button"));
    notebook_menu->AppendRadioItem(ID_NotebookCloseButton, _("Close Button at Right"));
    notebook_menu->AppendRadioItem(ID_NotebookCloseButtonAll, _("Close Button on All Tabs"));
    notebook_menu->AppendRadioItem(ID_NotebookCloseButtonActive, _("Close Button on Active Tab"));
    notebook_menu->AppendSeparator();
    notebook_menu->AppendRadioItem(ID_NotebookAlignTop, _("Tab Top Alignment"));
    notebook_menu->AppendRadioItem(ID_NotebookAlignBottom, _("Tab Bottom Alignment"));
    notebook_menu->AppendSeparator();
    notebook_menu->AppendCheckItem(ID_NotebookAllowTabMove, _("Allow Tab Move"));
    notebook_menu->AppendCheckItem(ID_NotebookAllowTabExternalMove, _("Allow External Tab Move"));
    notebook_menu->AppendCheckItem(ID_NotebookAllowTabSplit, _("Allow Notebook Split"));
    notebook_menu->AppendCheckItem(ID_NotebookScrollButtons, _("Scroll Buttons Visible"));
    notebook_menu->AppendCheckItem(ID_NotebookWindowList, _("Window List Button Visible"));
    notebook_menu->AppendCheckItem(ID_NotebookTabFixedWidth, _("Fixed-width Tabs"));
    notebook_menu->AppendSeparator();
    notebook_menu->Append(ID_NotebookNewTab, _("Add a &New Tab"));
    notebook_menu->Append(ID_NotebookDeleteTab, _("&Delete Last Tab"));

    m_perspectives_menu = new wxMenu;
    m_perspectives_menu->Append(ID_CreatePerspective, _("Create Perspective"));
    m_perspectives_menu->Append(ID_CopyPerspectiveCode, _("Copy Perspective Data To Clipboard"));
    m_perspectives_menu->AppendSeparator();
    m_perspectives_menu->Append(ID_FirstPerspective + 0, _("Default Startup"));
    m_perspectives_menu->Append(ID_FirstPerspective + 1, _("All Panes"));

    wxMenu *help_menu = new wxMenu;
    help_menu->Append(wxID_ABOUT);

    mb->Append(file_menu, _("&File"));
    mb->Append(view_menu, _("&View"));
    mb->Append(m_perspectives_menu, _("&Perspectives"));
    mb->Append(options_menu, _("&Options"));
    mb->Append(notebook_menu, _("&Notebook"));
    mb->Append(help_menu, _("&Help"));

    SetMenuBar(mb);

    CreateStatusBar();
    GetStatusBar()->SetStatusText(_("Ready"));


    // min size for the frame itself isn't completely done.
    // see the end up wxAuiManager::Update() for the test
    // code. For now, just hard code a frame minimum size
    SetMinSize(FromDIP(wxSize(400, 300)));



    // prepare a few custom overflow elements for the toolbars' overflow buttons

    wxAuiToolBarItemArray prepend_items;
    wxAuiToolBarItemArray append_items;
    wxAuiToolBarItem item;
    item.SetKind(wxITEM_SEPARATOR);
    append_items.Add(item);
    item.SetKind(wxITEM_NORMAL);
    item.SetId(ID_CustomizeToolbar);
    item.SetLabel(_("Customize..."));
    append_items.Add(item);


    // create some toolbars
    wxAuiToolBar *tb1 = new wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
                                         wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_OVERFLOW);
    tb1->AddTool(ID_SampleItem + 1, "Test", wxArtProvider::GetBitmapBundle(wxART_ERROR));
    tb1->AddSeparator();
    tb1->AddTool(ID_SampleItem + 2, "Test", wxArtProvider::GetBitmapBundle(wxART_QUESTION));
    tb1->AddTool(ID_SampleItem + 3, "Test", wxArtProvider::GetBitmapBundle(wxART_INFORMATION));
    tb1->AddTool(ID_SampleItem + 4, "Test", wxArtProvider::GetBitmapBundle(wxART_WARNING));
    tb1->AddTool(ID_SampleItem + 5, "Test", wxArtProvider::GetBitmapBundle(wxART_MISSING_IMAGE));
    tb1->SetCustomOverflowItems(prepend_items, append_items);
    tb1->Realize();


    wxAuiToolBar *tb2 = new wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
                                         wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_OVERFLOW | wxAUI_TB_HORIZONTAL);

    wxBitmapBundle tb2_bmp1 = wxArtProvider::GetBitmapBundle(wxART_QUESTION, wxART_OTHER, wxSize(16, 16));
    tb2->AddTool(ID_SampleItem + 6, "Disabled", tb2_bmp1);
    tb2->AddTool(ID_SampleItem + 7, "Test", tb2_bmp1);
    tb2->AddTool(ID_SampleItem + 8, "Test", tb2_bmp1);
    tb2->AddTool(ID_SampleItem + 9, "Test", tb2_bmp1);
    tb2->AddSeparator();
    tb2->AddTool(ID_SampleItem + 10, "Test", tb2_bmp1);
    tb2->AddTool(ID_SampleItem + 11, "Test", tb2_bmp1);
    tb2->AddSeparator();
    tb2->AddTool(ID_SampleItem + 12, "Test", tb2_bmp1);
    tb2->AddTool(ID_SampleItem + 13, "Test", tb2_bmp1);
    tb2->AddTool(ID_SampleItem + 14, "Test", tb2_bmp1);
    tb2->AddTool(ID_SampleItem + 15, "Test", tb2_bmp1);
    tb2->SetCustomOverflowItems(prepend_items, append_items);
    tb2->EnableTool(ID_SampleItem + 6, false);
    tb2->Realize();


    wxAuiToolBar *tb3 = new wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
                                         wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_OVERFLOW);
    wxBitmapBundle tb3_bmp1 = wxArtProvider::GetBitmapBundle(wxART_FOLDER, wxART_OTHER, wxSize(16, 16));
    tb3->AddTool(ID_SampleItem + 16, "Check 1", tb3_bmp1, "Check 1", wxITEM_CHECK);
    tb3->AddTool(ID_SampleItem + 17, "Check 2", tb3_bmp1, "Check 2", wxITEM_CHECK);
    tb3->AddTool(ID_SampleItem + 18, "Check 3", tb3_bmp1, "Check 3", wxITEM_CHECK);
    tb3->AddTool(ID_SampleItem + 19, "Check 4", tb3_bmp1, "Check 4", wxITEM_CHECK);
    tb3->AddSeparator();
    tb3->AddTool(ID_SampleItem + 20, "Radio 1", tb3_bmp1, "Radio 1", wxITEM_RADIO);
    tb3->AddTool(ID_SampleItem + 21, "Radio 2", tb3_bmp1, "Radio 2", wxITEM_RADIO);
    tb3->AddTool(ID_SampleItem + 22, "Radio 3", tb3_bmp1, "Radio 3", wxITEM_RADIO);
    tb3->AddSeparator();
    tb3->AddTool(ID_SampleItem + 23, "Radio 1 (Group 2)", tb3_bmp1, "Radio 1 (Group 2)", wxITEM_RADIO);
    tb3->AddTool(ID_SampleItem + 24, "Radio 2 (Group 2)", tb3_bmp1, "Radio 2 (Group 2)", wxITEM_RADIO);
    tb3->AddTool(ID_SampleItem + 25, "Radio 3 (Group 2)", tb3_bmp1, "Radio 3 (Group 2)", wxITEM_RADIO);
    tb3->SetCustomOverflowItems(prepend_items, append_items);
    tb3->Realize();


    wxAuiToolBar *tb4 = new wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
                                         wxAUI_TB_DEFAULT_STYLE |
                                         wxAUI_TB_OVERFLOW |
                                         wxAUI_TB_TEXT |
                                         wxAUI_TB_HORZ_TEXT);
    wxBitmapBundle tb4_bmp1 = wxArtProvider::GetBitmapBundle(wxART_NORMAL_FILE, wxART_OTHER, wxSize(16, 16));
    tb4->AddTool(ID_DropDownToolbarItem, "Item 1", tb4_bmp1);
    tb4->AddTool(ID_SampleItem + 23, "Item 2", tb4_bmp1);
    tb4->SetToolSticky(ID_SampleItem + 23, true);
    tb4->AddTool(ID_SampleItem + 24, "Disabled", tb4_bmp1);
    tb4->EnableTool(ID_SampleItem + 24, false); // Just to show disabled items look
    tb4->AddTool(ID_SampleItem + 25, "Item 4", tb4_bmp1);
    tb4->AddSeparator();
    tb4->AddTool(ID_SampleItem + 26, "Item 5", tb4_bmp1);
    tb4->AddTool(ID_SampleItem + 27, "Item 6", tb4_bmp1);
    tb4->AddTool(ID_SampleItem + 28, "Item 7", tb4_bmp1);
    tb4->AddTool(ID_SampleItem + 29, "Item 8", tb4_bmp1);
    tb4->SetToolDropDown(ID_DropDownToolbarItem, true);
    tb4->SetCustomOverflowItems(prepend_items, append_items);
    wxChoice *choice = new wxChoice(tb4, ID_SampleItem + 35);
    choice->AppendString("One choice");
    choice->AppendString("Another choice");
    tb4->AddControl(choice);
    tb4->Realize();


    wxAuiToolBar *tb5 = new wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
                                         wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_OVERFLOW | wxAUI_TB_VERTICAL);
    tb5->AddTool(ID_SampleItem + 30, "Test", wxArtProvider::GetBitmapBundle(wxART_ERROR));
    tb5->AddSeparator();
    tb5->AddTool(ID_SampleItem + 31, "Test", wxArtProvider::GetBitmapBundle(wxART_QUESTION));
    tb5->AddTool(ID_SampleItem + 32, "Test", wxArtProvider::GetBitmapBundle(wxART_INFORMATION));
    tb5->AddTool(ID_SampleItem + 33, "Test", wxArtProvider::GetBitmapBundle(wxART_WARNING));
    tb5->AddTool(ID_SampleItem + 34, "Test", wxArtProvider::GetBitmapBundle(wxART_MISSING_IMAGE));
    tb5->SetCustomOverflowItems(prepend_items, append_items);
    tb5->Realize();

    // add a bunch of panes
    m_mgr.AddPane(CreateSizeReportCtrl(), wxAuiPaneInfo().
            Name("test1").Caption("Pane Caption").
            Top());

    m_mgr.AddPane(CreateSizeReportCtrl(), wxAuiPaneInfo().
            Name("test2").Caption("Client Size Reporter").
            Bottom().Position(1).
            CloseButton(true).MaximizeButton(true));

    m_mgr.AddPane(CreateSizeReportCtrl(), wxAuiPaneInfo().
            Name("test3").Caption("Client Size Reporter").
            Bottom().
            CloseButton(true).MaximizeButton(true));

    m_mgr.AddPane(CreateSizeReportCtrl(), wxAuiPaneInfo().
            Name("test4").Caption("Pane Caption").
            Left());

    m_mgr.AddPane(CreateSizeReportCtrl(), wxAuiPaneInfo().
            Name("test5").Caption("No Close Button").
            Right().CloseButton(false));

    m_mgr.AddPane(CreateSizeReportCtrl(), wxAuiPaneInfo().
            Name("test6").Caption("Client Size Reporter").
            Right().Row(1).
            CloseButton(true).MaximizeButton(true));

    m_mgr.AddPane(CreateSizeReportCtrl(), wxAuiPaneInfo().
            Name("test7").Caption("Client Size Reporter").
            Left().Layer(1).
            CloseButton(true).MaximizeButton(true));

    m_mgr.AddPane(CreateTreeCtrl(), wxAuiPaneInfo().
            Name("test8").Caption("Tree Pane").
            Left().Layer(1).Position(1).
            CloseButton(true).MaximizeButton(true));

    m_mgr.AddPane(CreateSizeReportCtrl(), wxAuiPaneInfo().
            Name("test9").Caption("Min Size 200x100").
            BestSize(FromDIP(wxSize(200, 100))).MinSize(FromDIP(wxSize(200, 100))).
            Bottom().Layer(1).
            CloseButton(true).MaximizeButton(true));

    wxWindow *wnd10 = CreateTextCtrl("This pane will prompt the user before hiding.");

    // Give this pane an icon, too, just for testing.
    int iconSize = m_mgr.GetArtProvider()->GetMetric(wxAUI_DOCKART_CAPTION_SIZE);

    // Make it even to use 16 pixel icons with default 17 caption height.
    iconSize &= ~1;

    m_mgr.AddPane(wnd10, wxAuiPaneInfo().
            Name("test10").Caption("Text Pane with Hide Prompt").
            Bottom().Layer(1).Position(1).
            Icon(wxArtProvider::GetBitmapBundle(wxART_WARNING,
                                                wxART_OTHER,
                                                wxSize(iconSize, iconSize))));

    m_mgr.AddPane(CreateSizeReportCtrl(), wxAuiPaneInfo().
            Name("test11").Caption("Fixed Pane").
            Bottom().Layer(1).Position(2).Fixed());

    auto *settingsPanel = new SettingsPanel(this, this);
    m_mgr.AddPane(settingsPanel, wxAuiPaneInfo().
            Name("settings").Caption("Dock Manager Settings").
            Dockable(false).Float().Hide());

    // create some center panes

    m_mgr.AddPane(CreateGrid(), wxAuiPaneInfo().Name("grid_content").
            CenterPane().Hide());

    m_mgr.AddPane(CreateTreeCtrl(), wxAuiPaneInfo().Name("tree_content").
            CenterPane().Hide());

    m_mgr.AddPane(CreateSizeReportCtrl(), wxAuiPaneInfo().Name("sizereport_content").
            CenterPane().Hide());

    m_mgr.AddPane(CreateTextCtrl(), wxAuiPaneInfo().Name("text_content").
            CenterPane().Hide());

    m_mgr.AddPane(CreateHTMLCtrl(), wxAuiPaneInfo().Name("html_content").
            CenterPane().Hide());

    m_mgr.AddPane(CreateNotebook(), wxAuiPaneInfo().Name("notebook_content").
            CenterPane().PaneBorder(false));

    // add the toolbars to the manager
    m_mgr.AddPane(tb1, wxAuiPaneInfo().
            Name("tb1").Caption("Big Toolbar").
            ToolbarPane().Top());

    m_mgr.AddPane(tb2, wxAuiPaneInfo().
            Name("tb2").Caption("Toolbar 2 (Horizontal)").
            ToolbarPane().Top().Row(1));

    m_mgr.AddPane(tb3, wxAuiPaneInfo().
            Name("tb3").Caption("Toolbar 3").
            ToolbarPane().Top().Row(1).Position(1));

    m_mgr.AddPane(tb4, wxAuiPaneInfo().
            Name("tb4").Caption("Sample Bookmark Toolbar").
            ToolbarPane().Top().Row(2));

    m_mgr.AddPane(tb5, wxAuiPaneInfo().
            Name("tb5").Caption("Sample Vertical Toolbar").
            ToolbarPane().Left().
            GripperTop());

    m_mgr.AddPane(new wxButton(this, wxID_ANY, _("Test Button")),
                  wxAuiPaneInfo().Name("tb6").
                          ToolbarPane().Top().Row(2).Position(1).
                          LeftDockable(false).RightDockable(false));

    // make some default perspectives

    wxString perspective_all = m_mgr.SavePerspective();

    int i, count;
    wxAuiPaneInfoArray &all_panes = m_mgr.GetAllPanes();
    for (i = 0, count = all_panes.GetCount(); i < count; ++i)
        if (!all_panes.Item(i).IsToolbar())
            all_panes.Item(i).Hide();
    m_mgr.GetPane("tb1").Hide();
    m_mgr.GetPane("tb6").Hide();
    m_mgr.GetPane("test8").Show().Left().Layer(0).Row(0).Position(0);
    m_mgr.GetPane("test10").Show().Bottom().Layer(0).Row(0).Position(0);
    m_mgr.GetPane("notebook_content").Show();
    wxString perspective_default = m_mgr.SavePerspective();

    m_perspectives.Add(perspective_default);
    m_perspectives.Add(perspective_all);

    // "commit" all changes made to wxAuiManager
    m_mgr.Update();
}

wxAuiDockArt *SampleAuiFrame::GetDockArt() {
    return m_mgr.GetArtProvider();
}

void SampleAuiFrame::DoUpdate() {
    m_mgr.Update();
}

void SampleAuiFrame::OnSettings(wxCommandEvent & WXUNUSED(evt)) {
    // show the settings pane, and float it
    wxAuiPaneInfo &floating_pane = m_mgr.GetPane("settings").Float().Show();

    if (floating_pane.floating_pos == wxDefaultPosition)
        floating_pane.FloatingPosition(GetStartPosition());

    m_mgr.Update();
}

void SampleAuiFrame::OnCustomizeToolbar(wxCommandEvent & WXUNUSED(evt)) {
    wxMessageBox(_("Customize Toolbar clicked"));
}

void SampleAuiFrame::OnGradient(wxCommandEvent &event) {
    int gradient = 0;

    switch (event.GetId()) {
        case ID_NoGradient:
            gradient = wxAUI_GRADIENT_NONE;
            break;
        case ID_VerticalGradient:
            gradient = wxAUI_GRADIENT_VERTICAL;
            break;
        case ID_HorizontalGradient:
            gradient = wxAUI_GRADIENT_HORIZONTAL;
            break;
    }

    m_mgr.GetArtProvider()->SetMetric(wxAUI_DOCKART_GRADIENT_TYPE, gradient);
    m_mgr.Update();
}

void SampleAuiFrame::OnToolbarResizing(wxCommandEvent & WXUNUSED(evt)) {
    wxAuiPaneInfoArray &all_panes = m_mgr.GetAllPanes();
    const size_t count = all_panes.GetCount();
    for (size_t i = 0; i < count; ++i) {
        wxAuiToolBar *toolbar = wxDynamicCast(all_panes[i].window, wxAuiToolBar);
        if (toolbar) {
            all_panes[i].Resizable(!all_panes[i].IsResizable());
        }
    }

    m_mgr.Update();
}

void SampleAuiFrame::OnManagerFlag(wxCommandEvent &event) {
    unsigned int flag = 0;

#if !defined(__WXMSW__) && !defined(__WXMAC__) && !defined(__WXGTK__)
    if (event.GetId() == ID_TransparentDrag ||
        event.GetId() == ID_TransparentHint ||
        event.GetId() == ID_HintFade)
    {
        wxMessageBox("This option is presently only available on wxGTK, wxMSW and wxMac");
        return;
    }
#endif

    int id = event.GetId();

    if (id == ID_TransparentHint ||
        id == ID_VenetianBlindsHint ||
        id == ID_RectangleHint ||
        id == ID_NoHint) {
        unsigned int flags = m_mgr.GetFlags();
        flags &= ~wxAUI_MGR_TRANSPARENT_HINT;
        flags &= ~wxAUI_MGR_VENETIAN_BLINDS_HINT;
        flags &= ~wxAUI_MGR_RECTANGLE_HINT;
        m_mgr.SetFlags(flags);
    }

    switch (id) {
        case ID_AllowFloating:
            flag = wxAUI_MGR_ALLOW_FLOATING;
            break;
        case ID_TransparentDrag:
            flag = wxAUI_MGR_TRANSPARENT_DRAG;
            break;
        case ID_HintFade:
            flag = wxAUI_MGR_HINT_FADE;
            break;
        case ID_NoVenetianFade:
            flag = wxAUI_MGR_NO_VENETIAN_BLINDS_FADE;
            break;
        case ID_AllowActivePane:
            flag = wxAUI_MGR_ALLOW_ACTIVE_PANE;
            break;
        case ID_TransparentHint:
            flag = wxAUI_MGR_TRANSPARENT_HINT;
            break;
        case ID_VenetianBlindsHint:
            flag = wxAUI_MGR_VENETIAN_BLINDS_HINT;
            break;
        case ID_RectangleHint:
            flag = wxAUI_MGR_RECTANGLE_HINT;
            break;
        case ID_LiveUpdate:
            flag = wxAUI_MGR_LIVE_RESIZE;
            break;
    }

    if (flag) {
        m_mgr.SetFlags(m_mgr.GetFlags() ^ flag);
    }

    m_mgr.Update();
}


void SampleAuiFrame::OnNotebookFlag(wxCommandEvent &event) {
    int id = event.GetId();

    if (id == ID_NotebookNoCloseButton ||
        id == ID_NotebookCloseButton ||
        id == ID_NotebookCloseButtonAll ||
        id == ID_NotebookCloseButtonActive) {
        m_notebook_style &= ~(wxAUI_NB_CLOSE_BUTTON |
                              wxAUI_NB_CLOSE_ON_ACTIVE_TAB |
                              wxAUI_NB_CLOSE_ON_ALL_TABS);

        switch (id) {
            case ID_NotebookNoCloseButton:
                break;
            case ID_NotebookCloseButton:
                m_notebook_style |= wxAUI_NB_CLOSE_BUTTON;
                break;
            case ID_NotebookCloseButtonAll:
                m_notebook_style |= wxAUI_NB_CLOSE_ON_ALL_TABS;
                break;
            case ID_NotebookCloseButtonActive:
                m_notebook_style |= wxAUI_NB_CLOSE_ON_ACTIVE_TAB;
                break;
        }
    }

    if (id == ID_NotebookAllowTabMove) {
        m_notebook_style ^= wxAUI_NB_TAB_MOVE;
    }
    if (id == ID_NotebookAllowTabExternalMove) {
        m_notebook_style ^= wxAUI_NB_TAB_EXTERNAL_MOVE;
    } else if (id == ID_NotebookAllowTabSplit) {
        m_notebook_style ^= wxAUI_NB_TAB_SPLIT;
    } else if (id == ID_NotebookWindowList) {
        m_notebook_style ^= wxAUI_NB_WINDOWLIST_BUTTON;
    } else if (id == ID_NotebookScrollButtons) {
        m_notebook_style ^= wxAUI_NB_SCROLL_BUTTONS;
    } else if (id == ID_NotebookTabFixedWidth) {
        m_notebook_style ^= wxAUI_NB_TAB_FIXED_WIDTH;
    }


    size_t i, count;
    wxAuiPaneInfoArray &all_panes = m_mgr.GetAllPanes();
    for (i = 0, count = all_panes.GetCount(); i < count; ++i) {
        wxAuiPaneInfo &pane = all_panes.Item(i);
        if (pane.window->IsKindOf(CLASSINFO(wxAuiNotebook))) {
            wxAuiNotebook *nb = (wxAuiNotebook *) pane.window;

            if (id == ID_NotebookArtGloss) {
                nb->SetArtProvider(new wxAuiDefaultTabArt);
                m_notebook_theme = 0;
            } else if (id == ID_NotebookArtSimple) {
                nb->SetArtProvider(new wxAuiSimpleTabArt);
                m_notebook_theme = 1;
            }


            nb->SetWindowStyleFlag(m_notebook_style);
            nb->Refresh();
        }
    }


}


void SampleAuiFrame::OnUpdateUI(wxUpdateUIEvent &event) {
    unsigned int flags = m_mgr.GetFlags();

    switch (event.GetId()) {
        case ID_NoGradient:
            event.Check(m_mgr.GetArtProvider()->GetMetric(wxAUI_DOCKART_GRADIENT_TYPE) == wxAUI_GRADIENT_NONE);
            break;
        case ID_VerticalGradient:
            event.Check(m_mgr.GetArtProvider()->GetMetric(wxAUI_DOCKART_GRADIENT_TYPE) == wxAUI_GRADIENT_VERTICAL);
            break;
        case ID_HorizontalGradient:
            event.Check(m_mgr.GetArtProvider()->GetMetric(wxAUI_DOCKART_GRADIENT_TYPE) == wxAUI_GRADIENT_HORIZONTAL);
            break;
        case ID_AllowToolbarResizing: {
            wxAuiPaneInfoArray &all_panes = m_mgr.GetAllPanes();
            const size_t count = all_panes.GetCount();
            for (size_t i = 0; i < count; ++i) {
                wxAuiToolBar *toolbar = wxDynamicCast(all_panes[i].window, wxAuiToolBar);
                if (toolbar) {
                    event.Check(all_panes[i].IsResizable());
                    break;
                }
            }
            break;
        }
        case ID_AllowFloating:
            event.Check((flags & wxAUI_MGR_ALLOW_FLOATING) != 0);
            break;
        case ID_TransparentDrag:
            event.Check((flags & wxAUI_MGR_TRANSPARENT_DRAG) != 0);
            break;
        case ID_TransparentHint:
            event.Check((flags & wxAUI_MGR_TRANSPARENT_HINT) != 0);
            break;
        case ID_LiveUpdate:
            event.Check((flags & wxAUI_MGR_LIVE_RESIZE) != 0);
            break;
        case ID_VenetianBlindsHint:
            event.Check((flags & wxAUI_MGR_VENETIAN_BLINDS_HINT) != 0);
            break;
        case ID_RectangleHint:
            event.Check((flags & wxAUI_MGR_RECTANGLE_HINT) != 0);
            break;
        case ID_NoHint:
            event.Check(((wxAUI_MGR_TRANSPARENT_HINT |
                          wxAUI_MGR_VENETIAN_BLINDS_HINT |
                          wxAUI_MGR_RECTANGLE_HINT) & flags) == 0);
            break;
        case ID_HintFade:
            event.Check((flags & wxAUI_MGR_HINT_FADE) != 0);
            break;
        case ID_NoVenetianFade:
            event.Check((flags & wxAUI_MGR_NO_VENETIAN_BLINDS_FADE) != 0);
            break;

        case ID_NotebookNoCloseButton:
            event.Check((m_notebook_style &
                         (wxAUI_NB_CLOSE_BUTTON | wxAUI_NB_CLOSE_ON_ALL_TABS | wxAUI_NB_CLOSE_ON_ACTIVE_TAB)) == 0);
            break;
        case ID_NotebookCloseButton:
            event.Check((m_notebook_style & wxAUI_NB_CLOSE_BUTTON) != 0);
            break;
        case ID_NotebookCloseButtonAll:
            event.Check((m_notebook_style & wxAUI_NB_CLOSE_ON_ALL_TABS) != 0);
            break;
        case ID_NotebookCloseButtonActive:
            event.Check((m_notebook_style & wxAUI_NB_CLOSE_ON_ACTIVE_TAB) != 0);
            break;
        case ID_NotebookAllowTabSplit:
            event.Check((m_notebook_style & wxAUI_NB_TAB_SPLIT) != 0);
            break;
        case ID_NotebookAllowTabMove:
            event.Check((m_notebook_style & wxAUI_NB_TAB_MOVE) != 0);
            break;
        case ID_NotebookAllowTabExternalMove:
            event.Check((m_notebook_style & wxAUI_NB_TAB_EXTERNAL_MOVE) != 0);
            break;
        case ID_NotebookScrollButtons:
            event.Check((m_notebook_style & wxAUI_NB_SCROLL_BUTTONS) != 0);
            break;
        case ID_NotebookWindowList:
            event.Check((m_notebook_style & wxAUI_NB_WINDOWLIST_BUTTON) != 0);
            break;
        case ID_NotebookTabFixedWidth:
            event.Check((m_notebook_style & wxAUI_NB_TAB_FIXED_WIDTH) != 0);
            break;
        case ID_NotebookArtGloss:
            event.Check(m_notebook_style == 0);
            break;
        case ID_NotebookArtSimple:
            event.Check(m_notebook_style == 1);
            break;

    }
}


void SampleAuiFrame::OnNotebookNewTab(wxCommandEvent & WXUNUSED(evt)) {
    auto *const book =
            wxCheckCast<wxAuiNotebook>(m_mgr.GetPane("notebook_content").window);

    book->AddPage(new wxTextCtrl(book, wxID_ANY, "New Tab",
                                 wxDefaultPosition, wxDefaultSize,
                                 wxTE_MULTILINE | wxNO_BORDER),
                  wxString::Format("Tab %zu", book->GetPageCount() + 1),
                  true /* select */);
}


void SampleAuiFrame::OnNotebookDeleteTab(wxCommandEvent & WXUNUSED(evt)) {
    auto *const book =
            wxCheckCast<wxAuiNotebook>(m_mgr.GetPane("notebook_content").window);

    auto numPages = book->GetPageCount();
    if (!numPages) {
        wxLogWarning("No pages to delete.");
        return;
    }

    book->DeletePage(numPages - 1);
}


void SampleAuiFrame::OnPaneClose(wxAuiManagerEvent &evt) {
    if (evt.pane->name == "test10") {
        int res = wxMessageBox("Are you sure you want to close/hide this pane?",
                               "wxAUI",
                               wxYES_NO,
                               this);
        if (res != wxYES)
            evt.Veto();
    }
}

void SampleAuiFrame::OnCreatePerspective(wxCommandEvent & WXUNUSED(event)) {
    wxTextEntryDialog dlg(this, "Enter a name for the new perspective:",
                          "wxAUI Test");

    dlg.SetValue(wxString::Format("Perspective %u", unsigned(m_perspectives.GetCount() + 1)));
    if (dlg.ShowModal() != wxID_OK)
        return;

    if (m_perspectives.GetCount() == 0) {
        m_perspectives_menu->AppendSeparator();
    }

    m_perspectives_menu->Append(ID_FirstPerspective + m_perspectives.GetCount(), dlg.GetValue());
    m_perspectives.Add(m_mgr.SavePerspective());
}

void SampleAuiFrame::OnCopyPerspectiveCode(wxCommandEvent & WXUNUSED(evt)) {
    wxString s = m_mgr.SavePerspective();

#if wxUSE_CLIPBOARD
    if (wxTheClipboard->Open()) {
        wxTheClipboard->SetData(new wxTextDataObject(s));
        wxTheClipboard->Close();
    }
#endif
}

void SampleAuiFrame::OnRestorePerspective(wxCommandEvent &evt) {
    m_mgr.LoadPerspective(m_perspectives.Item(evt.GetId() - ID_FirstPerspective));
}

void SampleAuiFrame::OnNotebookPageClose(wxAuiNotebookEvent &evt) {
    wxAuiNotebook *ctrl = (wxAuiNotebook *) evt.GetEventObject();
    if (ctrl->GetPage(evt.GetSelection())->IsKindOf(CLASSINFO(wxHtmlWindow))) {
        int res = wxMessageBox("Are you sure you want to close/hide this notebook page?",
                               "wxAUI",
                               wxYES_NO,
                               this);
        if (res != wxYES)
            evt.Veto();
    }
}

void SampleAuiFrame::OnNotebookPageClosed(wxAuiNotebookEvent &evt) {
    wxAuiNotebook *ctrl = (wxAuiNotebook *) evt.GetEventObject();
    wxUnusedVar(ctrl);

    // selection should always be a valid index
    wxASSERT_MSG(ctrl->GetSelection() < (int) ctrl->GetPageCount(),
                 wxString::Format("Invalid selection %d, only %d pages left",
                                  ctrl->GetSelection(),
                                  (int) ctrl->GetPageCount()));

    evt.Skip();
}

void SampleAuiFrame::OnNotebookPageChanging(wxAuiNotebookEvent &evt) {
    if (evt.GetOldSelection() == 3) {
        if (wxMessageBox("Are you sure you want to leave this page?\n"
                         "(This demonstrates veto-ing)",
                         "wxAUI",
                         wxICON_QUESTION | wxYES_NO,
                         this) != wxYES) {
            evt.Veto();
        }
    }
}

void SampleAuiFrame::OnAllowNotebookDnD(wxAuiNotebookEvent &evt) {
    // for the purpose of this test application, explicitly
    // allow all notebook drag and drop events
    evt.Allow();
}

void SampleAuiFrame::OnCreateTree(wxCommandEvent & WXUNUSED(event)) {
    m_mgr.AddPane(CreateTreeCtrl(), wxAuiPaneInfo().
            Caption("Tree Control").
            Float().FloatingPosition(GetStartPosition()).
            FloatingSize(FromDIP(wxSize(150, 300))));
    m_mgr.Update();
}

void SampleAuiFrame::OnCreateGrid(wxCommandEvent & WXUNUSED(event)) {
    m_mgr.AddPane(CreateGrid(), wxAuiPaneInfo().
            Caption("Grid").
            Float().FloatingPosition(GetStartPosition()).
            FloatingSize(FromDIP(wxSize(300, 200))));
    m_mgr.Update();
}

void SampleAuiFrame::OnCreateHTML(wxCommandEvent & WXUNUSED(event)) {
    m_mgr.AddPane(CreateHTMLCtrl(), wxAuiPaneInfo().
            Caption("HTML Control").
            Float().FloatingPosition(GetStartPosition()).
            FloatingSize(FromDIP(wxSize(300, 200))));
    m_mgr.Update();
}

void SampleAuiFrame::OnCreateNotebook(wxCommandEvent & WXUNUSED(event)) {
    m_mgr.AddPane(CreateNotebook(), wxAuiPaneInfo().
            Caption("Notebook").
            Float().FloatingPosition(GetStartPosition()).
            //FloatingSize(FromDIP(wxSize(300,200))).
            CloseButton(true).MaximizeButton(true));
    m_mgr.Update();
}

void SampleAuiFrame::OnCreateText(wxCommandEvent & WXUNUSED(event)) {
    m_mgr.AddPane(CreateTextCtrl(), wxAuiPaneInfo().
            Caption("Text Control").
            Float().FloatingPosition(GetStartPosition()));
    m_mgr.Update();
}

void SampleAuiFrame::OnCreateSizeReport(wxCommandEvent & WXUNUSED(event)) {
    m_mgr.AddPane(CreateSizeReportCtrl(), wxAuiPaneInfo().
            Caption("Client Size Reporter").
            Float().FloatingPosition(GetStartPosition()).
            CloseButton(true).MaximizeButton(true));
    m_mgr.Update();
}

void SampleAuiFrame::OnChangeContentPane(wxCommandEvent &evt) {
    m_mgr.GetPane("grid_content").Show(evt.GetId() == ID_GridContent);
    m_mgr.GetPane("text_content").Show(evt.GetId() == ID_TextContent);
    m_mgr.GetPane("tree_content").Show(evt.GetId() == ID_TreeContent);
    m_mgr.GetPane("sizereport_content").Show(evt.GetId() == ID_SizeReportContent);
    m_mgr.GetPane("html_content").Show(evt.GetId() == ID_HTMLContent);
    m_mgr.GetPane("notebook_content").Show(evt.GetId() == ID_NotebookContent);
    m_mgr.Update();
}

void SampleAuiFrame::OnDropDownToolbarItem(wxAuiToolBarEvent &evt) {
    if (evt.IsDropDownClicked()) {
        wxAuiToolBar *tb = static_cast<wxAuiToolBar *>(evt.GetEventObject());

        tb->SetToolSticky(evt.GetId(), true);

        // create the popup menu
        wxMenu menuPopup;

        // TODO: Use GetBitmapBundle() when wxMenuItem is updated to use it too.
        wxBitmap bmp = wxArtProvider::GetBitmap(wxART_QUESTION, wxART_OTHER, FromDIP(wxSize(16, 16)));

        wxMenuItem *m1 = new wxMenuItem(&menuPopup, 10001, _("Drop Down Item 1"));
        m1->SetBitmap(bmp);
        menuPopup.Append(m1);

        wxMenuItem *m2 = new wxMenuItem(&menuPopup, 10002, _("Drop Down Item 2"));
        m2->SetBitmap(bmp);
        menuPopup.Append(m2);

        wxMenuItem *m3 = new wxMenuItem(&menuPopup, 10003, _("Drop Down Item 3"));
        m3->SetBitmap(bmp);
        menuPopup.Append(m3);

        wxMenuItem *m4 = new wxMenuItem(&menuPopup, 10004, _("Drop Down Item 4"));
        m4->SetBitmap(bmp);
        menuPopup.Append(m4);

        // line up our menu with the button
        wxRect rect = tb->GetToolRect(evt.GetId());
        wxPoint pt = tb->ClientToScreen(rect.GetBottomLeft());
        pt = ScreenToClient(pt);


        PopupMenu(&menuPopup, pt);


        // make sure the button is "un-stuck"
        tb->SetToolSticky(evt.GetId(), false);
    }
}

void SampleAuiFrame::OnTabAlignment(wxCommandEvent &evt) {
    size_t i, count;
    wxAuiPaneInfoArray &all_panes = m_mgr.GetAllPanes();
    for (i = 0, count = all_panes.GetCount(); i < count; ++i) {
        wxAuiPaneInfo &pane = all_panes.Item(i);
        if (pane.window->IsKindOf(CLASSINFO(wxAuiNotebook))) {
            wxAuiNotebook *nb = (wxAuiNotebook *) pane.window;

            long style = nb->GetWindowStyleFlag();
            style &= ~(wxAUI_NB_TOP | wxAUI_NB_BOTTOM);
            if (evt.GetId() == ID_NotebookAlignTop)
                style |= wxAUI_NB_TOP;
            else if (evt.GetId() == ID_NotebookAlignBottom)
                style |= wxAUI_NB_BOTTOM;
            nb->SetWindowStyleFlag(style);

            nb->Refresh();
        }
    }
}

void SampleAuiFrame::OnExit(wxCommandEvent & WXUNUSED(event)) {
    Close(true);
}

void SampleAuiFrame::OnAbout(wxCommandEvent & WXUNUSED(event)) {
    wxMessageBox(
            _("wxAUI Demo\nAn advanced window management library for wxWidgets\n(c) Copyright 2005-2006, Kirix Corporation"),
            _("About wxAUI Demo"), wxOK, this);
}

wxPoint SampleAuiFrame::GetStartPosition() {
    static int x = 0;
    x += FromDIP(20);
    wxPoint pt = ClientToScreen(wxPoint(0, 0));
    return wxPoint(pt.x + x, pt.y + x);
}

wxTextCtrl *SampleAuiFrame::CreateTextCtrl(const wxString &ctrl_text) {
    static int n = 0;

    wxString text;
    if (!ctrl_text.empty())
        text = ctrl_text;
    else
        text.Printf("This is text box %d", ++n);

    return new wxTextCtrl(this, wxID_ANY, text,
                          wxPoint(0, 0), FromDIP(wxSize(150, 90)),
                          wxNO_BORDER | wxTE_MULTILINE);
}

wxGrid *SampleAuiFrame::CreateGrid() {
    wxGrid *grid = new wxGrid(this, wxID_ANY,
                              wxPoint(0, 0),
                              FromDIP(wxSize(150, 250)),
                              wxNO_BORDER | wxWANTS_CHARS);
    grid->CreateGrid(50, 20);
    return grid;
}

wxTreeCtrl *SampleAuiFrame::CreateTreeCtrl() {
    wxTreeCtrl *tree = new wxTreeCtrl(this, wxID_ANY,
                                      wxPoint(0, 0),
                                      FromDIP(wxSize(160, 250)),
                                      wxTR_DEFAULT_STYLE | wxNO_BORDER);

    wxSize size(16, 16);
    wxVector<wxBitmapBundle> images;
    images.push_back(wxArtProvider::GetBitmapBundle(wxART_FOLDER, wxART_OTHER, size));
    images.push_back(wxArtProvider::GetBitmapBundle(wxART_NORMAL_FILE, wxART_OTHER, size));
    tree->SetImages(images);

    wxTreeItemId root = tree->AddRoot("wxAUI Project", 0);
    wxArrayTreeItemIds items;


    items.Add(tree->AppendItem(root, "Item 1", 0));
    items.Add(tree->AppendItem(root, "Item 2", 0));
    items.Add(tree->AppendItem(root, "Item 3", 0));
    items.Add(tree->AppendItem(root, "Item 4", 0));
    items.Add(tree->AppendItem(root, "Item 5", 0));


    int i, count;
    for (i = 0, count = items.Count(); i < count; ++i) {
        wxTreeItemId id = items.Item(i);
        tree->AppendItem(id, "Subitem 1", 1);
        tree->AppendItem(id, "Subitem 2", 1);
        tree->AppendItem(id, "Subitem 3", 1);
        tree->AppendItem(id, "Subitem 4", 1);
        tree->AppendItem(id, "Subitem 5", 1);
    }


    tree->Expand(root);

    return tree;
}

wxSizeReportCtrl *SampleAuiFrame::CreateSizeReportCtrl(const wxSize &size) {
    wxSizeReportCtrl *ctrl = new wxSizeReportCtrl(this, wxID_ANY,
                                                  wxDefaultPosition,
                                                  size, &m_mgr);
    return ctrl;
}

wxHtmlWindow *SampleAuiFrame::CreateHTMLCtrl(wxWindow *parent) {
    if (!parent)
        parent = this;

    wxHtmlWindow *ctrl = new wxHtmlWindow(parent, wxID_ANY,
                                          wxDefaultPosition,
                                          FromDIP(wxSize(400, 300)));
    ctrl->SetPage(GetIntroText());
    return ctrl;
}

wxAuiNotebook *SampleAuiFrame::CreateNotebook() {
    // create the notebook off-window to avoid flicker
    wxSize client_size = GetClientSize();

    wxAuiNotebook *ctrl = new wxAuiNotebook(this, wxID_ANY,
                                            wxPoint(client_size.x, client_size.y),
                                            FromDIP(wxSize(430, 200)),
                                            m_notebook_style);
    ctrl->Freeze();

    wxBitmapBundle page_bmp = wxArtProvider::GetBitmapBundle(wxART_NORMAL_FILE, wxART_OTHER, wxSize(16, 16));

    ctrl->AddPage(CreateHTMLCtrl(ctrl), "Welcome to wxAUI", false, page_bmp);
    ctrl->SetPageToolTip(0, "Welcome to wxAUI (this is a page tooltip)");

    wxPanel *panel = new wxPanel(ctrl, wxID_ANY);
    wxFlexGridSizer *flex = new wxFlexGridSizer(4, 2, 0, 0);
    flex->AddGrowableRow(0);
    flex->AddGrowableRow(3);
    flex->AddGrowableCol(1);
    flex->Add(FromDIP(5), FromDIP(5));
    flex->Add(FromDIP(5), FromDIP(5));
    flex->Add(new wxStaticText(panel, -1, "wxTextCtrl:"), 0, wxALL | wxALIGN_CENTRE, FromDIP(5));
    flex->Add(new wxTextCtrl(panel, -1, "", wxDefaultPosition, FromDIP(wxSize(100, -1))),
              1, wxALL | wxALIGN_CENTRE, FromDIP(5));
    flex->Add(new wxStaticText(panel, -1, "wxSpinCtrl:"), 0, wxALL | wxALIGN_CENTRE, FromDIP(5));
    flex->Add(new wxSpinCtrl(panel, -1, "5", wxDefaultPosition, wxDefaultSize,
                             wxSP_ARROW_KEYS, 5, 50, 5), 0, wxALL | wxALIGN_CENTRE, FromDIP(5));
    flex->Add(FromDIP(5), FromDIP(5));
    flex->Add(FromDIP(5), FromDIP(5));
    panel->SetSizer(flex);
    ctrl->AddPage(panel, "wxPanel", false, page_bmp);


    ctrl->AddPage(new wxTextCtrl(ctrl, wxID_ANY, "Some text",
                                 wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxNO_BORDER), "wxTextCtrl 1", false,
                  page_bmp);

    ctrl->AddPage(new wxTextCtrl(ctrl, wxID_ANY, "Some more text",
                                 wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxNO_BORDER), "wxTextCtrl 2");

    ctrl->AddPage(new wxTextCtrl(ctrl, wxID_ANY, "Some more text",
                                 wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxNO_BORDER), "wxTextCtrl 3");

    ctrl->AddPage(new wxTextCtrl(ctrl, wxID_ANY, "Some more text",
                                 wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxNO_BORDER), "wxTextCtrl 4");

    ctrl->AddPage(new wxTextCtrl(ctrl, wxID_ANY, "Some more text",
                                 wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxNO_BORDER), "wxTextCtrl 5");

    ctrl->AddPage(new wxTextCtrl(ctrl, wxID_ANY, "Some more text",
                                 wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxNO_BORDER), "wxTextCtrl 6");

    ctrl->AddPage(new wxTextCtrl(ctrl, wxID_ANY, "Some more text",
                                 wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxNO_BORDER),
                  "wxTextCtrl 7 (longer title)");
    ctrl->SetPageToolTip(ctrl->GetPageCount() - 1,
                         "wxTextCtrl 7: and the tooltip message can be even longer!");

    ctrl->AddPage(new wxTextCtrl(ctrl, wxID_ANY, "Some more text",
                                 wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxNO_BORDER), "wxTextCtrl 8");

    ctrl->Thaw();
    return ctrl;
}

wxString SampleAuiFrame::GetIntroText() {
    const char *text =
            "<html><body>"
            "<h3>Welcome to wxAUI</h3>"
            "<br/><b>Overview</b><br/>"
            "<p>wxAUI is an Advanced User Interface library for the wxWidgets toolkit "
            "that allows developers to create high-quality, cross-platform user "
            "interfaces quickly and easily.</p>"
            "<p><b>Features</b></p>"
            "<p>With wxAUI, developers can create application frameworks with:</p>"
            "<ul>"
            "<li>Native, dockable floating frames</li>"
            "<li>Perspective saving and loading</li>"
            "<li>Native toolbars incorporating real-time, &quot;spring-loaded&quot; dragging</li>"
            "<li>Customizable floating/docking behaviour</li>"
            "<li>Completely customizable look-and-feel</li>"
            "<li>Optional transparent window effects (while dragging or docking)</li>"
            "<li>Splittable notebook control</li>"
            "</ul>"
            "<p><b>What's new in 0.9.4?</b></p>"
            "<p>wxAUI 0.9.4, which is bundled with wxWidgets, adds the following features:"
            "<ul>"
            "<li>New wxAuiToolBar class, a toolbar control which integrates more "
            "cleanly with wxAuiFrameManager.</li>"
            "<li>Lots of bug fixes</li>"
            "</ul>"
            "<p><b>What's new in 0.9.3?</b></p>"
            "<p>wxAUI 0.9.3, which is now bundled with wxWidgets, adds the following features:"
            "<ul>"
            "<li>New wxAuiNotebook class, a dynamic splittable notebook control</li>"
            "<li>New wxAuiMDI* classes, a tab-based MDI and drop-in replacement for classic MDI</li>"
            "<li>Maximize/Restore buttons implemented</li>"
            "<li>Better hinting with wxGTK</li>"
            "<li>Class rename.  'wxAui' is now the standard class prefix for all wxAUI classes</li>"
            "<li>Lots of bug fixes</li>"
            "</ul>"
            "<p><b>What's new in 0.9.2?</b></p>"
            "<p>The following features/fixes have been added since the last version of wxAUI:</p>"
            "<ul>"
            "<li>Support for wxMac</li>"
            "<li>Updates for wxWidgets 2.6.3</li>"
            "<li>Fix to pass more unused events through</li>"
            "<li>Fix to allow floating windows to receive idle events</li>"
            "<li>Fix for minimizing/maximizing problem with transparent hint pane</li>"
            "<li>Fix to not paint empty hint rectangles</li>"
            "<li>Fix for 64-bit compilation</li>"
            "</ul>"
            "<p><b>What changed in 0.9.1?</b></p>"
            "<p>The following features/fixes were added in wxAUI 0.9.1:</p>"
            "<ul>"
            "<li>Support for MDI frames</li>"
            "<li>Gradient captions option</li>"
            "<li>Active/Inactive panes option</li>"
            "<li>Fix for screen artifacts/paint problems</li>"
            "<li>Fix for hiding/showing floated window problem</li>"
            "<li>Fix for floating pane sizing problem</li>"
            "<li>Fix for drop position problem when dragging around center pane margins</li>"
            "<li>LF-only text file formatting for source code</li>"
            "</ul>"
            "<p>See README.txt for more information.</p>"
            "</body></html>";

    return wxString::FromAscii(text);
}
