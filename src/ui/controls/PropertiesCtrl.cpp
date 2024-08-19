//
// Created by mito on 13.08.2024.
//

#include "../../../include/ui/controls/PropertiesCtrl.h"

PropertiesCtrl::PropertiesCtrl(wxWindow *parent, wxWindowID id, const wxPoint &position,
                               const wxSize &size, long style, wxAuiManager *mgr)
    : wxControl(parent, id, position, size, style), m_mgr(mgr) {
    auto *topPanel = new wxPanel(this, wxID_ANY);
    topPanel->SetBackgroundColour(wxColor(255, 200, 220));
    auto *vTopSizer = new wxBoxSizer(wxVERTICAL);

    propertyGrid = new wxPropertyGridManager(topPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize,
                                             wxPGMAN_DEFAULT_STYLE | wxPG_NO_INTERNAL_BORDER | wxPG_SPLITTER_AUTO_CENTER
    );
    propertyGrid->SetColumnCount(2);

    vTopSizer->Add(propertyGrid, 0, wxEXPAND | wxALL, 0);
    topPanel->SetSizerAndFit(vTopSizer);

// EVT_PAINT(wxSizeReportCtrl::OnPaint)
// EVT_SIZE(wxSizeReportCtrl::OnSize)
// EVT_ERASE_BACKGROUND(wxSizeReportCtrl::OnEraseBackground)

}

void PropertiesCtrl::OnSize(wxSizeEvent &evt) {
    Refresh();
}
