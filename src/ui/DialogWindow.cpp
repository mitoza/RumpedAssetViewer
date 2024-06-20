//
// Created by Dmitry Velychko on 20.06.2024.
//

#include "../../include/ui/DialogWindow.h"

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

    void DialogWindow::resize(unsigned int width, unsigned int height) {
        BaseWindow::resize(width, height);
    }

    void DialogWindow::handleEvent(sf::Event &event) {
        BaseWindow::handleEvent(event);
    }

}