//
// Created by Dmitry Velychko on 23.06.2024.
//

#include "../../../include/ui/samples/SampleComboFrame.h"
#include "../../../include/ui/samples/ListViewComboPopup.h"
#include "../../../include/ui/samples/TreeCtrlComboPopup.h"


wxBEGIN_EVENT_TABLE(SampleComboFrame, wxFrame)
                EVT_TEXT(wxID_ANY, SampleComboFrame::OnComboBoxUpdate)
                EVT_TEXT_ENTER(wxID_ANY, SampleComboFrame::OnComboBoxUpdate)
                EVT_COMBOBOX(wxID_ANY, SampleComboFrame::OnComboBoxUpdate)

                EVT_MENU(ComboCtrl_Compare, SampleComboFrame::OnShowComparison)
                EVT_MENU(ComboCtrl_Quit, SampleComboFrame::OnQuit)
                EVT_MENU(ComboCtrl_About, SampleComboFrame::OnAbout)

                EVT_IDLE(SampleComboFrame::OnIdle)
wxEND_EVENT_TABLE()

// ----------------------------------------------------------------------------
// main frame
// ----------------------------------------------------------------------------

// frame constructor
SampleComboFrame::SampleComboFrame(wxWindow *parent, const wxString &title)
        : wxFrame(parent, wxID_ANY, title) {
    wxBoxSizer *topSizer;
    wxBoxSizer *topRowSizer;
    wxBoxSizer *colSizer;
    wxBoxSizer *rowSizer;

    // set the frame icon
    //SetIcon(wxIcon(sample));

#if wxUSE_MENUS
    // create a menu bar
    wxMenu *fileMenu = new wxMenu;

    // the "About" item should be in the help menu
    wxMenu *helpMenu = new wxMenu;
    helpMenu->Append(ComboCtrl_About, "&About\tF1", "Show about dialog");

    fileMenu->Append(ComboCtrl_Compare, "&Compare against wxComboBox...",
                     "Show some wxOwnerDrawnComboBoxes side-by-side with native wxComboBoxes.");
    fileMenu->AppendSeparator();
    fileMenu->Append(ComboCtrl_Quit, "E&xit\tAlt-X", "Quit this program");

    // now append the freshly created menu to the menu bar...
    wxMenuBar *menuBar = new wxMenuBar();
    menuBar->Append(fileMenu, "&File");
    menuBar->Append(helpMenu, "&Help");

    // ... and attach this menu bar to the frame
    SetMenuBar(menuBar);
#endif // wxUSE_MENUS

    wxPanel *panel = new wxPanel(this);

    // Prepare log window right away since it shows EVT_TEXTs
    m_logWin = new wxTextCtrl(panel, 105, wxEmptyString,
                              wxDefaultPosition,
                              wxSize(-1, 125),
                              wxTE_MULTILINE);
    wxLogTextCtrl *logger = new wxLogTextCtrl(m_logWin);
    m_logOld = logger->SetActiveTarget(logger);
    logger->DisableTimestamp();


    topSizer = new wxBoxSizer(wxVERTICAL);

    topRowSizer = new wxBoxSizer(wxHORIZONTAL);

    colSizer = new wxBoxSizer(wxVERTICAL);


    wxComboCtrl *cc;
    wxGenericComboCtrl *gcc;
    wxOwnerDrawnComboBox *odc;

    // Create common strings array
    m_arrItems.Add("Solid");
    m_arrItems.Add("Transparent");
    m_arrItems.Add("Dot");
    m_arrItems.Add("Long Dash");
    m_arrItems.Add("Short Dash");
    m_arrItems.Add("Dot Dash");
    m_arrItems.Add("Backward Diagonal Hatch");
    m_arrItems.Add("Cross-diagonal Hatch");
    m_arrItems.Add("Forward Diagonal Hatch");
    m_arrItems.Add("Cross Hatch");
    m_arrItems.Add("Horizontal Hatch");
    m_arrItems.Add("Vertical Hatch");


    //
    // Create pen selector ODComboBox with owner-drawn items
    //
    rowSizer = new wxBoxSizer(wxHORIZONTAL);
    rowSizer->Add(new wxStaticText(panel, wxID_ANY,
                                   "OwnerDrawnComboBox with owner-drawn items:"), 1,
                  wxALIGN_CENTER_VERTICAL | wxRIGHT, 4);
    colSizer->Add(rowSizer, 0, wxEXPAND | wxALL, 5);

    rowSizer = new wxBoxSizer(wxHORIZONTAL);


    // When defining derivative class for callbacks, we need
    // to use two-stage creation (or redefine the common wx
    // constructor).
    odc = new wxPenStyleComboBox();
    odc->Create(panel, wxID_ANY, wxEmptyString,
                wxDefaultPosition, wxDefaultSize,
                m_arrItems,
                wxCB_READONLY //wxNO_BORDER | wxCB_READONLY
    );


    odc->SetSelection(0);

    rowSizer->Add(odc, 1, wxALIGN_CENTER_VERTICAL | wxALL, 4);
    rowSizer->AddStretchSpacer(1);
    colSizer->Add(rowSizer, 0, wxEXPAND | wxALL, 5);



    //
    // Same but with changed button position
    //
    rowSizer = new wxBoxSizer(wxHORIZONTAL);
    rowSizer->Add(new wxStaticText(panel, wxID_ANY,
                                   "OwnerDrawnComboBox with owner-drawn items and button on the left:"), 1,
                  wxALIGN_CENTER_VERTICAL | wxRIGHT, 4);
    colSizer->Add(rowSizer, 0, wxEXPAND | wxALL, 5);

    rowSizer = new wxBoxSizer(wxHORIZONTAL);


    // When defining derivative class for callbacks, we need
    // to use two-stage creation (or redefine the common wx
    // constructor).
    odc = new wxPenStyleComboBox();
    odc->Create(panel, wxID_ANY, wxEmptyString,
                wxDefaultPosition, wxDefaultSize,
                m_arrItems,
                wxCB_READONLY //wxNO_BORDER | wxCB_READONLY
    );


    odc->SetSelection(0);

    // Use button size that is slightly smaller than the default.
    wxSize butSize = odc->GetButtonSize();
    odc->SetButtonPosition(butSize.x - 2, // button width
                           butSize.y - 6, // button height
                           wxLEFT, // side
                           2 // horizontal spacing
    );

    rowSizer->Add(odc, 1, wxALIGN_CENTER_VERTICAL | wxALL, 4);
    rowSizer->AddStretchSpacer(1);
    colSizer->Add(rowSizer, 0, wxEXPAND | wxALL, 5);


    //
    // List View wxComboCtrl
    //

    rowSizer = new wxBoxSizer(wxHORIZONTAL);
    rowSizer->Add(new wxStaticText(panel,
                                   wxID_ANY,
                                   "List View wxComboCtrl (custom animation):"),
                  1, wxALIGN_CENTER_VERTICAL | wxRIGHT, 4);
    rowSizer->Add(new wxStaticText(panel, wxID_ANY, "Tree Ctrl wxComboCtrl:"), 1,
                  wxALIGN_CENTER_VERTICAL | wxRIGHT, 4);
    colSizer->Add(rowSizer, 0, wxEXPAND | wxALL, 5);

    rowSizer = new wxBoxSizer(wxHORIZONTAL);
    cc = new wxComboCtrlWithCustomPopupAnim();

    // Let's set a custom style for the contained wxTextCtrl. We need to
    // use two-step creation for it to work properly.
    cc->SetTextCtrlStyle(wxTE_RIGHT);

    cc->Create(panel, wxID_ANY, wxEmptyString);

    // Make sure we use popup that allows focusing the listview.
    cc->UseAltPopupWindow();

    cc->SetPopupMinWidth(300);

    ListViewComboPopup *iface = new ListViewComboPopup();
    cc->SetPopupControl(iface);

    int i;
    for (i = 0; i < 100; i++)
        iface->AddSelection(wxString::Format("Item %02i", i));

    rowSizer->Add(cc, 1, wxALIGN_CENTER_VERTICAL | wxALL, 5);


    //
    // Tree Ctrl wxComboCtrl
    //

    // Note that we test that wxGenericComboCtrl works
    gcc = new wxGenericComboCtrl(panel, wxID_ANY, wxEmptyString,
                                 wxDefaultPosition, wxDefaultSize);

    // Make sure we use popup that allows focusing the treectrl.
    gcc->UseAltPopupWindow();

    // Set popup interface right away, otherwise some of the calls
    // below may fail
    TreeCtrlComboPopup *tcPopup = new TreeCtrlComboPopup();
    gcc->SetPopupControl(tcPopup);

    // Add items using wxTreeCtrl methods directly
    wxTreeItemId rootId = tcPopup->AddRoot("<hidden_root>");

    wxTreeItemId groupId;

    for (i = 0; i < 4; i++) {
        groupId = tcPopup->AppendItem(rootId,
                                      wxString::Format("Branch %02i", i));

        int n;
        for (n = 0; n < 25; n++)
            tcPopup->AppendItem(groupId,
                                wxString::Format("Subitem %02i", (i * 25) + n));
    }

    gcc->SetValue("Subitem 05");

    // Move button to left - it makes more sense for a tree ctrl
    gcc->SetButtonPosition(-1, // button width
                           -1, // button height
                           wxLEFT, // side
                           0 // horizontal spacing
    );

    rowSizer->Add(gcc, 1, wxALIGN_CENTER_VERTICAL | wxALL, 5);

    colSizer->Add(rowSizer, 0, wxEXPAND | wxALL, 5);

#if wxUSE_IMAGE
    wxInitAllImageHandlers();

    //
    // Custom Dropbutton Bitmaps
    // (second one uses blank button background)
    //
    rowSizer = new wxBoxSizer(wxHORIZONTAL);
    rowSizer->Add(new wxStaticText(panel, wxID_ANY,
                                   "OwnerDrawnComboBox with simple dropbutton graphics:"), 1,
                  wxALIGN_CENTER_VERTICAL | wxRIGHT, 4);

    colSizer->Add(rowSizer, 0, wxEXPAND | wxALL, 5);

    rowSizer = new wxBoxSizer(wxHORIZONTAL);

    odc = new wxOwnerDrawnComboBox(panel, wxID_ANY, wxEmptyString,
                                   wxDefaultPosition, wxDefaultSize,
                                   m_arrItems,
                                   (long) 0 // wxCB_SORT // wxNO_BORDER | wxCB_READONLY
    );

    wxOwnerDrawnComboBox *odc2;
    odc2 = new wxOwnerDrawnComboBox(panel, wxID_ANY, wxEmptyString,
                                    wxDefaultPosition, wxDefaultSize,
                                    m_arrItems,
                                    (long) 0 // wxCB_SORT // wxNO_BORDER | wxCB_READONLY
    );

    // Load images from disk
#ifdef wxHAS_SVG
    wxBitmapBundle bmpNormal = wxBitmapBundle::FromSVGFile("dropbutn.svg", wxSize(16, 16));
    wxBitmapBundle bmpPressed = wxBitmapBundle::FromSVGFile("dropbutp.svg", wxSize(16, 16));
    wxBitmapBundle bmpHover = wxBitmapBundle::FromSVGFile("dropbuth.svg", wxSize(16, 16));

    if (bmpNormal.IsOk() && bmpPressed.IsOk() && bmpHover.IsOk()) {
        odc->SetButtonBitmaps(bmpNormal, false, bmpPressed, bmpHover);
        odc2->SetButtonBitmaps(bmpNormal, true, bmpPressed, bmpHover);
    } else
        wxLogError("Dropbutton images not found");
#endif

    //odc2->SetButtonPosition(0, // width adjustment
    //                        0, // height adjustment
    //                        wxLEFT, // side
    //                        0 // horizontal spacing
    //                       );

    rowSizer->Add(odc, 1, wxALIGN_CENTER_VERTICAL | wxALL, 4);
    rowSizer->Add(odc2, 1, wxALIGN_CENTER_VERTICAL | wxALL, 4);
    colSizer->Add(rowSizer, 0, wxEXPAND | wxALL, 5);
#endif


    //
    // wxComboCtrl with totally custom button action (open file dialog)
    //
    rowSizer = new wxBoxSizer(wxHORIZONTAL);
    rowSizer->Add(new wxStaticText(panel, wxID_ANY,
                                   "wxComboCtrl with custom button and custom main control:"), 1,
                  wxALIGN_CENTER_VERTICAL | wxRIGHT, 4);


    colSizer->Add(rowSizer, 0, wxEXPAND | wxALL, 5);

    rowSizer = new wxBoxSizer(wxHORIZONTAL);
    wxFileSelectorCombo *fsc;

    fsc = new wxFileSelectorCombo(panel, wxID_ANY, wxEmptyString,
                                  wxDefaultPosition, wxDefaultSize,
                                  (long) 0
    );

    // This is a perfectly useless control, as the popup and main control
    // don't interact with each other, but it shows that we can use something
    // other than wxTextCtrl for the main part of wxComboCtrl too.
    //
    // In a real program, custom popup and main control would work together,
    // i.e. changing selection in one of them would update the other one.
    //
    // Also note the complicated dance we need to go through to create the
    // controls in the right order: we want to create the custom main control
    // before actually creating the wxComboCtrl window, as otherwise it would
    // unnecessarily create a wxTextCtrl by default, forcing us to use its
    // default ctor and Create() later, but this, in turn, also requires using
    // default ctor for the main control and creating it later too, as it can't
    // be created before its parent window is.
    wxComboCtrl *comboCustom = new wxComboCtrl();
    wxCheckBox *cbox = new wxCheckBox();
    comboCustom->SetMainControl(cbox);
    comboCustom->Create(panel, wxID_ANY, wxEmptyString);
    cbox->Create(comboCustom, wxID_ANY, "Checkbox as main control");
    cbox->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));

    comboCustom->SetPopupControl(new ListViewComboPopup());

    rowSizer->Add(fsc, 1, wxALIGN_CENTER_VERTICAL | wxALL, 4);
    rowSizer->Add(comboCustom, 1, wxALIGN_CENTER_VERTICAL | wxALL, 4);
    colSizer->Add(rowSizer, 0, wxEXPAND | wxALL, 5);


    // Make sure GetFeatures is implemented
    wxComboCtrl::GetFeatures();


    topRowSizer->Add(colSizer, 1, wxALL, 2);

    colSizer = new wxBoxSizer(wxVERTICAL);

    colSizer->AddSpacer(8);
    colSizer->Add(new wxStaticText(panel, wxID_ANY, "Log Messages:"), 0, wxTOP | wxLEFT, 3);
    colSizer->Add(m_logWin, 1, wxEXPAND | wxALL, 3);

    topRowSizer->Add(colSizer, 1, wxEXPAND | wxALL, 2);
    topSizer->Add(topRowSizer, 1, wxEXPAND);

    panel->SetSizer(topSizer);
    topSizer->SetSizeHints(panel);

    Fit();
    Centre();
}

// event handlers

void SampleComboFrame::OnComboBoxUpdate(wxCommandEvent &event) {
    // Don't show messages for the log output window (it'll crash)
    if (!event.GetEventObject()->IsKindOf(CLASSINFO(wxComboCtrl)))
        return;

    if (event.GetEventType() == wxEVT_COMBOBOX) {
        wxLogMessage("EVT_COMBOBOX(id=%i,selection=%i)", event.GetId(), event.GetSelection());
    } else if (event.GetEventType() == wxEVT_TEXT) {
        wxLogMessage("EVT_TEXT(id=%i,string=\"%s\")", event.GetId(), event.GetString());
    } else if (event.GetEventType() == wxEVT_TEXT_ENTER) {
        wxLogMessage("EVT_TEXT_ENTER(id=%i,string=\"%s\")",
                     event.GetId(), event.GetString());
    }
}

void SampleComboFrame::OnShowComparison(wxCommandEvent & WXUNUSED(event)) {
    //
    // Show some wxOwnerDrawComboBoxes for comparison
    //

    wxBoxSizer *colSizer;
    wxBoxSizer *rowSizer;
    wxStaticBoxSizer *groupSizer;

    wxComboBox *cb;
    wxOwnerDrawnComboBox *odc;

    const int border = 4;

    wxDialog *dlg = new wxDialog(this, wxID_ANY,
                                 "Compare against wxComboBox",
                                 wxDefaultPosition, wxDefaultSize,
                                 wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);

    colSizer = new wxBoxSizer(wxVERTICAL);

    rowSizer = new wxBoxSizer(wxHORIZONTAL);

    groupSizer = new wxStaticBoxSizer(new wxStaticBox(dlg, wxID_ANY, " wxOwnerDrawnComboBox "),
                                      wxVERTICAL);

    groupSizer->Add(new wxStaticText(groupSizer->GetStaticBox(), wxID_ANY,
                                     "Writable, with margins, sorted:"),
                    wxSizerFlags().Expand().Border(wxRIGHT, border));

    odc = new wxOwnerDrawnComboBox(groupSizer->GetStaticBox(), wxID_ANY, wxEmptyString,
                                   wxDefaultPosition, wxDefaultSize,
                                   m_arrItems,
                                   wxCB_SORT // wxNO_BORDER|wxCB_READONLY
    );

    odc->Append("H - Appended Item"); // test sorting in append

    odc->SetValue("Dot Dash");
    odc->SetMargins(15, 10);
    groupSizer->Add(odc, wxSizerFlags().Border(wxALL, border));
    groupSizer->AddStretchSpacer();

    //
    // Readonly ODComboBox
    groupSizer->Add(new wxStaticText(groupSizer->GetStaticBox(), wxID_ANY,
                                     "Read-only, big font:"),
                    wxSizerFlags().Border(wxRIGHT, border));

    odc = new wxOwnerDrawnComboBox(groupSizer->GetStaticBox(), wxID_ANY, wxEmptyString,
                                   wxDefaultPosition, wxDefaultSize,
                                   m_arrItems,
                                   wxCB_SORT | wxCB_READONLY // wxNO_BORDER|wxCB_READONLY
    );

    odc->SetFont(odc->GetFont().Scale(1.5));
    odc->SetValue("Dot Dash");
    odc->SetText("Dot Dash (Testing SetText)");

    groupSizer->Add(odc, 0, wxALL, border);
    groupSizer->AddStretchSpacer();

    //
    // Disabled read-only ODComboBox
    groupSizer->Add(new wxStaticText(groupSizer->GetStaticBox(), wxID_ANY, "Read-only disabled:"),
                    wxSizerFlags().Border(wxRIGHT, border));

    odc = new wxOwnerDrawnComboBox(groupSizer->GetStaticBox(), wxID_ANY, wxEmptyString,
                                   wxDefaultPosition, wxDefaultSize,
                                   m_arrItems,
                                   wxCB_READONLY // wxNO_BORDER|wxCB_READONLY
    );

    odc->SetValue("Dot Dash");
    odc->Enable(false);

    groupSizer->Add(odc, wxSizerFlags(3).Expand().Border(wxALL, border));

    // Disabled ODComboBox
    groupSizer->Add(new wxStaticText(groupSizer->GetStaticBox(), wxID_ANY, "Disabled:"),
                    wxSizerFlags().Border(wxRIGHT, border));

    odc = new wxOwnerDrawnComboBox(groupSizer->GetStaticBox(), wxID_ANY, wxEmptyString,
                                   wxDefaultPosition, wxDefaultSize, m_arrItems);

    odc->SetValue("Dot Dash");
    odc->Enable(false);

    groupSizer->Add(odc, wxSizerFlags(3).Expand().Border(wxALL, border));

    rowSizer->Add(groupSizer, 1, wxEXPAND | wxALL, border);


    groupSizer = new wxStaticBoxSizer(new wxStaticBox(dlg, wxID_ANY, " wxComboBox "),
                                      wxVERTICAL);

    //
    // wxComboBox
    //
    groupSizer->Add(new wxStaticText(groupSizer->GetStaticBox(), wxID_ANY,
                                     "Writable, with margins, sorted:"),
                    wxSizerFlags().Expand().Border(wxRIGHT, border));

    cb = new wxComboBox(groupSizer->GetStaticBox(), wxID_ANY, wxEmptyString,
                        wxDefaultPosition, wxDefaultSize,
                        m_arrItems,
                        wxCB_SORT // wxNO_BORDER|wxCB_READONLY
    );

    cb->Append("H - Appended Item"); // test sorting in append

    cb->SetValue("Dot Dash");
    cb->SetMargins(15, 10);
    groupSizer->Add(cb, wxSizerFlags().Border(wxALL, border));
    groupSizer->AddStretchSpacer();

    //
    // Readonly wxComboBox
    groupSizer->Add(new wxStaticText(groupSizer->GetStaticBox(), wxID_ANY,
                                     "Read-only, big font:"),
                    wxSizerFlags().Border(wxRIGHT, border));

    cb = new wxComboBox(groupSizer->GetStaticBox(), wxID_ANY, wxEmptyString,
                        wxDefaultPosition, wxDefaultSize,
                        m_arrItems,
                        wxCB_SORT | wxCB_READONLY // wxNO_BORDER|wxCB_READONLY
    );

    cb->SetFont(cb->GetFont().Scale(1.5));
    cb->SetValue("Dot Dash");

    groupSizer->Add(cb, 0, wxALL, border);
    groupSizer->AddStretchSpacer();

    //
    // Disabled read-only wxComboBox
    groupSizer->Add(new wxStaticText(groupSizer->GetStaticBox(), wxID_ANY, "Read-only disabled:"),
                    wxSizerFlags().Border(wxRIGHT, border));

    cb = new wxComboBox(groupSizer->GetStaticBox(), wxID_ANY, wxEmptyString,
                        wxDefaultPosition, wxDefaultSize,
                        m_arrItems,
                        wxCB_READONLY // wxNO_BORDER|wxCB_READONLY
    );

    cb->SetValue("Dot Dash");
    cb->Enable(false);

    groupSizer->Add(cb, wxSizerFlags(3).Expand().Border(wxALL, border));

    //
    // Disabled wxComboBox
    groupSizer->Add(new wxStaticText(groupSizer->GetStaticBox(), wxID_ANY, "Disabled:"),
                    wxSizerFlags().Border(wxRIGHT, border));

    cb = new wxComboBox(groupSizer->GetStaticBox(), wxID_ANY, wxEmptyString,
                        wxDefaultPosition, wxDefaultSize, m_arrItems);

    cb->SetValue("Dot Dash");
    cb->Enable(false);

    groupSizer->Add(cb, wxSizerFlags(3).Expand().Border(wxALL, border));

    rowSizer->Add(groupSizer, 1, wxEXPAND | wxALL, border);

    colSizer->Add(rowSizer, 1, wxEXPAND | wxALL, border);

    dlg->SetSizer(colSizer);
    colSizer->SetSizeHints(dlg);

    dlg->SetSize(60, 240);
    dlg->Centre();
    dlg->ShowModal();
}

SampleComboFrame::~SampleComboFrame() {
    delete wxLog::SetActiveTarget(m_logOld);
}

void SampleComboFrame::OnQuit(wxCommandEvent & WXUNUSED(event)) {
    // true is to force the frame to close
    Close(true);
}

void SampleComboFrame::OnAbout(wxCommandEvent & WXUNUSED(event)) {
    wxMessageBox(wxString::Format(
                         "Welcome to %s!\n"
                         "\n"
                         "This is the wxWidgets wxComboCtrl and wxOwnerDrawnComboBox sample\n"
                         "running under %s.",
                         wxVERSION_STRING,
                         wxGetOsDescription()
                 ),
                 "About wxComboCtrl sample",
                 wxOK | wxICON_INFORMATION,
                 this);
}

void SampleComboFrame::OnIdle(wxIdleEvent &event) {
    // This code is useful for debugging focus problems
    // (which are plentiful when dealing with popup windows).
#if 0
    static wxWindow* lastFocus = nullptr;

    wxWindow* curFocus = ::wxWindow::FindFocus();

    if ( curFocus != lastFocus )
    {
        const wxChar* className = "<none>";
        if ( curFocus )
            className = curFocus->GetClassInfo()->GetClassName();
        lastFocus = curFocus;
        wxLogDebug( "FOCUSED: %s %X",
            className,
            (unsigned int)curFocus);
    }
#endif

    event.Skip();
}