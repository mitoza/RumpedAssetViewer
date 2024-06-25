//
// Created by Dmitry Velychko on 22.06.2024.
//

#ifndef ASSETVIEWER_WXSFMLCANVAS_H
#define ASSETVIEWER_WXSFMLCANVAS_H

#include <SFML/Graphics.hpp>
#include <wx/wx.h>
#include "wx/aui/framemanager.h"
#include "wx/dcbuffer.h"

#ifdef __WXGTK__
#include <gdk/gdkx.h>
#include <gtk/gtk.h>
#include <wx/gtk/win_gtk.h>
#endif


class wxSFMLCanvas : public wxControl, public sf::RenderWindow {
//wxDECLARE_EVENT_TABLE();

    wxAuiManager *m_mgr;

public:
    explicit wxSFMLCanvas(wxWindow *Parent = nullptr, wxWindowID id = wxID_ANY,
            const wxPoint &position = wxDefaultPosition,
            const wxSize &Size = wxDefaultSize,
            long Style = wxNO_BORDER, wxAuiManager *mgr = nullptr);

    ~wxSFMLCanvas() override;

private :
    virtual void OnUpdate();

    void OnIdle(wxIdleEvent &idleEvent);

    void OnPaint(wxPaintEvent &WXUNUSED(paintEvent));

    void OnEraseBackground(wxEraseEvent &WXUNUSED(eraseEvent));

    void OnSize(wxSizeEvent &WXUNUSED(sizeEvent));

};


#endif //ASSETVIEWER_WXSFMLCANVAS_H
