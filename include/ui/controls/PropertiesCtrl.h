//
// Created by mito on 13.08.2024.
//

#ifndef PROPERTIESPANE_H
#define PROPERTIESPANE_H

#include "wx/wx.h"
#include "wx/aui/framemanager.h"

#include "wx/propgrid/propgrid.h"
#include "wx/propgrid/property.h"
#include "wx/propgrid/props.h"
#include "wx/propgrid/editors.h"
#include "wx/propgrid/advprops.h"
#include "wx/propgrid/manager.h"


class PropertiesCtrl: public wxControl {

    wxAuiManager *m_mgr;
    wxPropertyGridManager *propertyGrid{};

public:
    PropertiesCtrl(wxWindow *parent, wxWindowID id = wxID_ANY,
                            const wxPoint &position = wxDefaultPosition,
                            const wxSize &size = wxDefaultSize,
                            long style = wxNO_BORDER,
                            wxAuiManager *mgr = nullptr);

    void OnSize(wxSizeEvent &evt);

};



#endif //PROPERTIESPANE_H
