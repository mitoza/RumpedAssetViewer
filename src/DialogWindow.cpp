//
// Created by Dmitry Velychko on 20.06.2024.
//

#include "../include/DialogWindow.h"

namespace rumpedav {

    DialogWindow::DialogWindow(Context &_context) : BaseWindow(_context) {
        window.create({320, 240}, "New Window");
        gui.setWindow(window);
    }

    void DialogWindow::create() {
        BaseWindow::create();
    }

    void DialogWindow::destroy() {
        BaseWindow::destroy();
    }

    void DialogWindow::resize(sf::Vector2u size) {
        BaseWindow::resize(size);
    }

    void DialogWindow::handleEvent(sf::Event &event) {
        BaseWindow::handleEvent(event);
    }

}