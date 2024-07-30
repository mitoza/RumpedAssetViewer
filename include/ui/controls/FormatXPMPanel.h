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
#include "PaintPane.h"
#include "../Config.h"

class FormatXPMPanel : public wxWindow {
public:
    wxListView *lvSettings;
    wxPropertyGridManager *propertyGrid;
    PaintPane *paintPane;
    wxStaticBitmap *bmpPreview;
    wxTextCtrl *textPanel;

    explicit FormatXPMPanel(wxWindow *parent, wxWindowID id = wxID_ANY, const wxPoint &pos = wxDefaultPosition,
                            const wxSize &size = wxDefaultSize);
    ~FormatXPMPanel() override;

    void OnRightDown(wxMouseEvent &event);
    void OnPropertyRightDown(wxPropertyGridEvent &event);
    void OnPropertyChanged(wxPropertyGridEvent &event);
    void OnPropertySelected(wxPropertyGridEvent &event);

    void OnPaintChanged(PaintChangedEvent &event);

    void RefreshProperties() const;

    void AddColor();

};


#endif //FORMATXPMPANEL_H
