//
// Created by Dmitry Velychko on 22.06.2024.
//

#ifndef ASSETVIEWER_WXSFMLCANVAS_H
#define ASSETVIEWER_WXSFMLCANVAS_H

#include <SFML/Graphics.hpp>
#include <wx/wx.h>

#ifdef __WXGTK__
#include <gdk/gdkx.h>
#include <gtk/gtk.h>
#include <wx/gtk/win_gtk.h>
#endif


class wxSFMLCanvas : public wxControl, public sf::RenderWindow {

    virtual void OnUpdate();

    void OnIdle(wxIdleEvent &idleEvent);

    void OnPaint(wxPaintEvent &paintEvent);

    void OnEraseBackground(wxEraseEvent &eraseEvent);

    void OnSize(wxSizeEvent &sizeEvent);

public:
    explicit wxSFMLCanvas(
            wxWindow *Parent = nullptr,
            wxWindowID Id = -1,
            const wxPoint &Position = wxDefaultPosition,
            const wxSize &Size = wxDefaultSize,
            long Style = 0);

    ~wxSFMLCanvas() override;
};


#endif //ASSETVIEWER_WXSFMLCANVAS_H
