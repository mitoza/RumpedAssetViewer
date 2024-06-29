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
    sf::RenderWindow::setActive(true);
#endif
    m_mgr = mgr;
    m_view = getDefaultView();
    timer.Start(10);

    Bind(wxEVT_IDLE, &wxSFMLCanvas::OnIdle, this, wxID_ANY);
    Bind(wxEVT_PAINT, &wxSFMLCanvas::OnPaint, this, wxID_ANY);
    Bind(wxEVT_SIZE, &wxSFMLCanvas::OnSize, this, wxID_ANY);
    Bind(wxEVT_ERASE_BACKGROUND, &wxSFMLCanvas::OnEraseBackground, this, wxID_ANY);
    Bind(wxEVT_TIMER, &wxSFMLCanvas::OnTimer, this, wxID_ANY);
}

wxSFMLCanvas::~wxSFMLCanvas() {

}

void wxSFMLCanvas::OnUpdate() {

    clear(sf::Color(rumpedav::Color::Material(rumpedav::MaterialColor::BlueGrey,
                                              rumpedav::Variant::_50)));

    sf::CircleShape circle = sf::CircleShape(20, 6);
    circle.setOrigin(20, 20);

    circle.setPosition(getSize().x / 2, getSize().y / 2);

    circle.setFillColor(sf::Color::Red);

//    sf::Event event;
//    while(pollEvent(event)) {
//
//    }

    draw(circle);
}

void wxSFMLCanvas::OnIdle(wxIdleEvent &idleEvent) {
    // Send a paint message when the control is idle, to ensure maximum framerate
    Refresh();
}

void wxSFMLCanvas::OnPaint(wxPaintEvent &paintEvent) {
    // https://wiki.wxwidgets.org/Making_a_render_loop
//#ifdef __WIN32__
    wxPaintDC dc(this);
//#endif

    OnUpdate();

    display();

    wxSize size = GetClientSize();
    dc.SetPen(*wxLIGHT_GREY_PEN);
    dc.DrawRectangle(0, 0, size.x, size.y);
    dc.DrawLine(0, 0, size.x, size.y);
    dc.DrawLine(0, size.y, size.x, 0);

#ifdef __APPLE__
//    sf::Vector2u windowSize = getSize();
//
//    sf::Texture texture;
//    texture.create(windowSize.x, windowSize.y);
//    texture.update(*this);
//    sf::Image image = texture.copyToImage();
//    wxBitmap bmp(wxImage(windowSize.x, windowSize.y,
//                         (unsigned char *)image.getPixelsPtr(), true));
//    wxBufferedPaintDC bdc(this, bmp);
#endif
}

void wxSFMLCanvas::OnEraseBackground(wxEraseEvent &eraseEvent) {
    // do nothing
}

void wxSFMLCanvas::OnSize(wxSizeEvent &sizeEvent) {
    wxSize size = GetClientSize();
    std::cout << "Resize: " << size.x << "x" << size.y << std::endl;
    m_view.setSize({
        static_cast<float>(size.x),
        static_cast<float>(size.y)
    });
    setView(m_view);
    Refresh();

}

void wxSFMLCanvas::OnTimer(wxTimerEvent &) {
    //Refresh();
}
