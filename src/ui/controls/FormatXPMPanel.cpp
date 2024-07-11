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
    propertyGrid->SetColumnCount(2);
    //propertyGrid->SetColumnTitle(2, "Prop");
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

    RefreshProperties();

    Bind(wxEVT_RIGHT_UP, &FormatXPMPanel::OnRightDown, this);
}

void FormatXPMPanel::OnPropertyRightDown(wxPropertyGridEvent &event) {
    wxPGProperty* property = event.GetProperty();
    //wxVariant pendingValue = event.GetValue();

    wxMenu *menu = new wxMenu(property->GetName());

    //menu.Append(ID_MENU_PROPERTIES_ADD_COLOR, "&Add color");
    auto *addItem = new wxMenuItem(nullptr, wxID_ANY, _("&Add color"));
    menu->Append(addItem);

    menu->Bind(wxEVT_MENU, [&](wxCommandEvent &event) {
        if (event.GetId() == addItem->GetId()) {
            AddColor();
        }
    });

    const wxPoint pt = wxGetMousePosition();
    const int mouseX = pt.x - this->GetScreenPosition().x;
    const int mouseY = pt.y - this->GetScreenPosition().y;
    PopupMenu(menu, mouseX, mouseY);
    event.Skip();
}

void FormatXPMPanel::OnPropertyChanged(wxPropertyGridEvent &event) {
    if (event.GetProperty()->GetName().StartsWith("color_")) {
        const wxPGProperty* property =  event.GetProperty();
        //auto color = wxColor(property->GetValueAsString());
        wxAny value = property->GetValue();
        auto color = value.As<wxColor>();
        auto colorKey = event.GetProperty()->GetName().Right(1).GetChar(0);
        paintPane->UpdateColor(colorKey, color);
    }

}

void FormatXPMPanel::OnPropertySelected(wxPropertyGridEvent &event) {
    if (event.GetProperty()->GetName().StartsWith("color_")) {
        auto colorKey = event.GetProperty()->GetName().Right(1).GetChar(0);
        paintPane->SetColor(colorKey);
    } else {
        paintPane->SetColor(' ');
    }
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
    RefreshProperties();
}

void FormatXPMPanel::RefreshProperties() const {
    propertyGrid->Clear();
    propertyGrid->Refresh();
    auto *page = propertyGrid->AddPage("XMP Propetries");
    propertyGrid->SetColumnCount(2);
    //propertyGrid->SetColumnTitle(2, "Prop");
    page->Append(new wxUIntProperty("Width", "width", paintPane->GetWidth()));
    page->Append(new wxUIntProperty("Height", "height", paintPane->GetHeight()));

    auto *colorNoneProperty = new wxStringProperty("\" \"", "none", "NONE");
    colorNoneProperty->Enable(false);
    page->Append(colorNoneProperty);

    std::vector<char> colorKeys;
    paintPane->GetColorKeys(colorKeys);
    for(auto const& colorKey : colorKeys) {
        wxString label = wxString("\"").append(colorKey).append("\"");
        wxString name = wxString("color_").append(colorKey);
        auto *colorProperty = new wxColourProperty(label, name, paintPane->GetColor(colorKey));
        page->Append(colorProperty);
    }

}
