//
// Created by mito on 01.07.2024.
//

#ifndef FORMATXPMPANEL_H
#define FORMATXPMPANEL_H
#include "wx/wx.h"
#include <wx/spinctrl.h>
#include <wx/listctrl.h>
#include <wx/splitter.h>
#include "wx/propgrid/propgrid.h"
#include "wx/propgrid/property.h"
#include "wx/propgrid/props.h"
#include "wx/propgrid/editors.h"
#include "wx/propgrid/advprops.h"
#include "wx/propgrid/manager.h"

class FormatXPMPanel : public wxWindow {
public:
    int width = 32;
    int height = 32;
    int colors = 1;
    int chars_per_pixel = 1;

    wxListView *lvSettings;
    wxPropertyGridManager *propertyGrid;

    explicit FormatXPMPanel(wxWindow *parent, wxWindowID id = wxID_ANY, const wxPoint &pos = wxDefaultPosition,
                            const wxSize &size = wxDefaultSize);

    ~FormatXPMPanel() override;

    void AddColor();
};


#endif //FORMATXPMPANEL_H
