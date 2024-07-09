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

    auto *bottomPanel = new wxPanel(vSplitter, wxID_ANY);
    bottomPanel->SetBackgroundColour(rumpedav::Color::Material(rumpedav::MaterialColor::Blue, rumpedav::Variant::_500));
    vSplitter->SplitHorizontally(settingsPanel, bottomPanel);

    auto *vSizer = new wxBoxSizer(wxVERTICAL);

    propertyGrid = new wxPropertyGridManager(settingsPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize,
        wxPGMAN_DEFAULT_STYLE | wxPG_NO_INTERNAL_BORDER | wxPG_SPLITTER_AUTO_CENTER
        );
    auto *page = propertyGrid->AddPage("XMP Propetries");
    propertyGrid->SetColumnCount(3);
    propertyGrid->SetColumnTitle(2, "Prop");
    page->Append(new wxUIntProperty("Width", wxPG_LABEL, 32));
    page->Append(new wxUIntProperty("Height", wxPG_LABEL, 32));
    auto *colorProperty = new wxColourProperty("\".\"", wxPG_LABEL, wxColor(100, 100, 200));
    page->Append(colorProperty);
    //propertyGrid->ShowHeader();
    vSizer->Add(propertyGrid, 0, wxEXPAND | wxALL, 0);

    paintPane = new PaintPane(settingsPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    vSizer->Add(paintPane, 1, wxEXPAND | wxALL, 0);

    settingsPanel->SetSizerAndFit(vSizer);

    rootSizer->Add(vSplitter, 1, wxEXPAND | wxALL, 0);
    SetSizer(rootSizer);

    propertyGrid->Bind(wxEVT_PG_RIGHT_CLICK, &FormatXPMPanel::OnPropertyRightDown, this);
    propertyGrid->Bind(wxEVT_PG_CHANGED, &FormatXPMPanel::OnPropertyChanged, this);
    propertyGrid->Bind(wxEVT_PG_SELECTED, &FormatXPMPanel::OnPropertySelected, this);
    propertyGrid->Bind(wxEVT_CONTEXT_MENU, [&](wxContextMenuEvent &event){
        //AddColor();
        event.Skip();
    });

    Bind(wxEVT_RIGHT_UP, &FormatXPMPanel::OnRightDown, this);


    // Bind(wxEVT_RIGHT_DOWN, [&](wxPropertyGridEvent &event) {
    //     std::cout << "123" << std::endl;
    //     wxMenu menu("XMP Settings");
    //     menu.Append(wxID_ANY, "&About");
    //     PopupMenu(&menu, 50, event.GetProperty()->GetY());
    // }, propertyGrid->GetId());

}

void FormatXPMPanel::OnPropertyRightDown(wxPropertyGridEvent &event) {
    wxPGProperty* property = event.GetProperty();
    //wxVariant pendingValue = event.GetValue();

    wxMenu *menu = new wxMenu(property->GetName());

    //menu.Append(ID_MENU_PROPERTIES_ADD_COLOR, "&Add color");
    auto *addItem = new wxMenuItem(nullptr, wxID_ANY, _("&Add color"));
    menu->Append(addItem);

    menu->Bind(wxEVT_MENU, [&](wxCommandEvent &event) {
        AddColor();
    });

    const wxPoint pt = wxGetMousePosition();
    const int mouseX = pt.x - this->GetScreenPosition().x;
    const int mouseY = pt.y - this->GetScreenPosition().y;
    PopupMenu(menu, mouseX, mouseY);
    event.Skip();
}

void FormatXPMPanel::OnPropertyChanged(wxPropertyGridEvent &event) {
}

void FormatXPMPanel::OnPropertySelected(wxPropertyGridEvent &event) {
}

FormatXPMPanel::~FormatXPMPanel() {
    //delete lvSettings;
    delete propertyGrid;
}

void FormatXPMPanel::OnRightDown(wxMouseEvent &event) {
    wxMenu menu;
    const auto *addColorItem = menu.Append(wxID_ANY, "&Add color");
    //Bind(wxEVT_MENU, &FormatXPMPanel::AddColor, addColorItem->GetId());
    PopupMenu(&menu, event.GetX(), event.GetY());
}


void FormatXPMPanel::AddColor() {
    std::cout << "Add Color" << std::endl;
}
