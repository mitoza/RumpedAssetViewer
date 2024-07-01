//
// Created by mito on 01.07.2024.
//

#include "../../../include/ui/controls/FormatXPMPanel.h"

#include "../../../include/data/Color.h"

FormatXPMPanel::FormatXPMPanel(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size)
    : wxWindow(parent, id, pos, size) {
    auto *rootSizer = new wxBoxSizer(wxHORIZONTAL);
    auto *vSplitter = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
                                           wxSP_BORDER | wxSP_LIVE_UPDATE | wxSP_3DSASH);
    vSplitter->SetMinimumPaneSize(64);
    vSplitter->SetSashInvisible(false);
    vSplitter->SetSashGravity(0.0f);

    auto *settingsPanel = new wxPanel(vSplitter, wxID_ANY);
    settingsPanel->SetBackgroundColour(
        rumpedav::Color::Material(rumpedav::MaterialColor::Green, rumpedav::Variant::_500));

    auto *otherPanel = new wxPanel(vSplitter, wxID_ANY);
    otherPanel->SetBackgroundColour(rumpedav::Color::Material(rumpedav::MaterialColor::Blue, rumpedav::Variant::_500));
    vSplitter->SplitHorizontally(settingsPanel, otherPanel);

    auto *vSizer = new wxBoxSizer(wxVERTICAL);

    // lvSettings = new wxListView(settingsPanel);
    // lvSettings->Arrange(wxLIST_ALIGN_SNAP_TO_GRID);
    // lvSettings->AppendColumn("Name");
    // lvSettings->SetColumnWidth(0, 128);
    // lvSettings->AppendColumn("Value");
    // lvSettings->SetColumnWidth(1, 128);
    //
    // lvSettings->InsertItem(0, "Width");
    // lvSettings->InsertItem(1, "Height");
    // lvSettings->InsertItem(2, "\".\"");
    //
    // lvSettings->SetItem(0, 1, "32");
    // lvSettings->SetItem(1, 1, "32");
    // lvSettings->SetItem(2, 1, "#000000");
    //
    // vSizer->Add(lvSettings, 0, wxALL, 0);

    propertyGrid = new wxPropertyGridManager(settingsPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize,
                                             //wxPG_BOLD_MODIFIED |
                                             //wxPG_SPLITTER_AUTO_CENTER |
                                             //wxPG_TOOLBAR |
                                             // wxPG_DESCRIPTION |
                                             wxPGMAN_DEFAULT_STYLE
    );

    auto *page = propertyGrid->AddPage();
    propertyGrid->SetColumnCount(3);
    propertyGrid->SetColumnTitle(2, "Prop");
    page->Append(new wxUIntProperty("Width", wxPG_LABEL, 32));
    page->Append(new wxUIntProperty("Height", wxPG_LABEL, 32));
    auto *colorProperty = new wxColourProperty("\".\"", wxPG_LABEL, wxColor(100, 100, 200));

    page->Append(colorProperty);

    propertyGrid->ShowHeader();

    vSizer->Add(propertyGrid, 0, wxEXPAND | wxALL, 0);

    settingsPanel->SetSizerAndFit(vSizer);

    rootSizer->Add(vSplitter, 1, wxEXPAND | wxALL, 0);
    SetSizer(rootSizer);
}

FormatXPMPanel::~FormatXPMPanel() {
    //delete lvSettings;
    delete propertyGrid;
}


void FormatXPMPanel::AddColor() {
}
