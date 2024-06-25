//
// Created by Dmitry Velychko on 23.06.2024.
//

#ifndef ASSETVIEWER_WXSIZEREPORTCTRL_H
#define ASSETVIEWER_WXSIZEREPORTCTRL_H

#include "wx/wx.h"
#include "wx/aui/framemanager.h"

// -- wxSizeReportCtrl --
// (a utility control that always reports it's client size)

class wxSizeReportCtrl : public wxControl {
wxDECLARE_EVENT_TABLE();

    wxAuiManager *m_mgr;

public:

    explicit wxSizeReportCtrl(wxWindow *parent, wxWindowID id = wxID_ANY,
                     const wxPoint &position = wxDefaultPosition,
                     const wxSize &size = wxDefaultSize,
                     wxAuiManager *mgr = nullptr)
            : wxControl(parent, id, position, size, wxNO_BORDER) {
        m_mgr = mgr;
    }

private:

    void OnPaint(wxPaintEvent & WXUNUSED(evt)) {
        wxPaintDC dc(this);
        wxSize size = GetClientSize();
        wxString s;
        int h, w, height;

        s.Printf("Size: %d x %d", size.x, size.y);

        dc.SetFont(*wxNORMAL_FONT);
        dc.GetTextExtent(s, &w, &height);
        height += FromDIP(3);
        dc.SetBrush(*wxWHITE_BRUSH);
        dc.SetPen(*wxWHITE_PEN);
        dc.DrawRectangle(0, 0, size.x, size.y);
        dc.SetPen(*wxLIGHT_GREY_PEN);
        dc.DrawLine(0, 0, size.x, size.y);
        dc.DrawLine(0, size.y, size.x, 0);
        dc.DrawText(s, (size.x - w) / 2, ((size.y - (height * 5)) / 2));

        if (m_mgr) {
            wxAuiPaneInfo pi = m_mgr->GetPane(this);

            s.Printf("Layer: %d", pi.dock_layer);
            dc.GetTextExtent(s, &w, &h);
            dc.DrawText(s, (size.x - w) / 2, ((size.y - (height * 5)) / 2) + (height * 1));

            s.Printf("Dock: %d Row: %d", pi.dock_direction, pi.dock_row);
            dc.GetTextExtent(s, &w, &h);
            dc.DrawText(s, (size.x - w) / 2, ((size.y - (height * 5)) / 2) + (height * 2));

            s.Printf("Position: %d", pi.dock_pos);
            dc.GetTextExtent(s, &w, &h);
            dc.DrawText(s, (size.x - w) / 2, ((size.y - (height * 5)) / 2) + (height * 3));

            s.Printf("Proportion: %d", pi.dock_proportion);
            dc.GetTextExtent(s, &w, &h);
            dc.DrawText(s, (size.x - w) / 2, ((size.y - (height * 5)) / 2) + (height * 4));
        }
    }

    void OnEraseBackground(wxEraseEvent & WXUNUSED(evt)) {
        // intentionally empty
    }

    void OnSize(wxSizeEvent & WXUNUSED(evt)) {
        Refresh();
    }

};


#endif //ASSETVIEWER_WXSIZEREPORTCTRL_H
