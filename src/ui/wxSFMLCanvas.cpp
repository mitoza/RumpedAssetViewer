//
// Created by Dmitry Velychko on 22.06.2024.
//

#include "../../include/ui/wxSFMLCanvas.h"

wxSFMLCanvas::wxSFMLCanvas(wxWindow *parent, wxWindowID id,
        const wxPoint &position, const wxSize &size,
        long style, wxAuiManager *mgr)
        : wxControl(parent, id, position, size, style) {
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
    create(GetHandle());

#endif
    m_mgr = mgr;
    Bind(wxEVT_PAINT, &wxSFMLCanvas::OnPaint, this, wxID_ANY);
    Bind(wxEVT_SIZE, &wxSFMLCanvas::OnSize, this, wxID_ANY);
    Bind(wxEVT_ERASE_BACKGROUND, &wxSFMLCanvas::OnEraseBackground, this, wxID_ANY);
}

wxSFMLCanvas::~wxSFMLCanvas() {

}

void wxSFMLCanvas::OnUpdate() {
    clear(sf::Color(rumpedav::Color::Material(rumpedav::MaterialColor::Grey, rumpedav::Variant::_300)));

    sf::CircleShape circle = sf::CircleShape(20, 6);
    circle.setPosition(50, 50);
    circle.setFillColor(sf::Color::Red);

    draw(circle);
}

void wxSFMLCanvas::OnIdle(wxIdleEvent &idleEvent) {
    // Send a paint message when the control is idle, to ensure maximum framerate
    Refresh();
}

void wxSFMLCanvas::OnPaint(wxPaintEvent &paintEvent) {
    // https://wiki.wxwidgets.org/Making_a_render_loop
#ifdef __WIN32__
    wxPaintDC dc(this);
#endif

    OnUpdate();

    display();

#ifdef __APPLE__
    sf::Vector2u windowSize = getSize();

    sf::Texture texture;
    texture.create(windowSize.x, windowSize.y);
    texture.update(*this);
    sf::Image image = texture.copyToImage();
    //Lock();
    wxBitmap bmp(wxImage(windowSize.x, windowSize.y,
                         (unsigned char *)image.getPixelsPtr(), true));
    //Unlock();
    wxBufferedPaintDC dc(this, bmp);
#endif
}

void wxSFMLCanvas::OnEraseBackground(wxEraseEvent &eraseEvent) {

}

void wxSFMLCanvas::OnSize(wxSizeEvent &sizeEvent) {
    std::cout << "Resize" << std::endl;
    Refresh();
    onResize();
}

