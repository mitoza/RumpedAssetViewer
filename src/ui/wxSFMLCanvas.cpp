//
// Created by Dmitry Velychko on 22.06.2024.
//

#include "../../include/ui/wxSFMLCanvas.h"

wxSFMLCanvas::wxSFMLCanvas(
        wxWindow *Parent,
        wxWindowID Id,
        const wxPoint &Position,
        const wxSize &Size,
        long Style) {
#ifdef __WXGTK__

    // GTK implementation requires to go deeper to find the
    // low-level X11 identifier of the widget
    gtk_widget_realize(m_wxwindow);
    gtk_widget_set_double_buffered(m_wxwindow, false);
    GdkWindow* Win = GTK_PIZZA(m_wxwindow)->bin_window;
    XFlush(GDK_WINDOW_XDISPLAY(Win));
    sf::RenderWindow::Create(GDK_WINDOW_XWINDOW(Win));

#else
    // Tested under Windows XP only (should work with X11
    // and other Windows versions - no idea about MacOS)
    sf::RenderWindow::create(GetHandle());
#endif
    //Bind(wxEVT_SIZE, &wxSFMLCanvas::OnSize, this, wxID_RESIZE_FRAME);
}

wxSFMLCanvas::~wxSFMLCanvas() {

}

void wxSFMLCanvas::OnUpdate() {

}

void wxSFMLCanvas::OnIdle(wxIdleEvent &idleEvent) {
    // Send a paint message when the control is idle, to ensure maximum framerate
    Refresh();
}

void wxSFMLCanvas::OnPaint(wxPaintEvent &paintEvent) {
    // Prepare the control to be repainted
    wxPaintDC Dc(this);

    // Let the derived class do its specific stuff
    OnUpdate();

    // Display on screen
    //Display(); // !!!
}

void wxSFMLCanvas::OnEraseBackground(wxEraseEvent &eraseEvent) {

}

void wxSFMLCanvas::OnSize(wxSizeEvent &sizeEvent) {

}

