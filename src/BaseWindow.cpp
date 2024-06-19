//
// Created by mito on 19.06.2024.
//

#include "../include/BaseWindow.h"

namespace rumpedav {
    BaseWindow::BaseWindow(tgui::Gui &gui): m_gui(gui) {

    }

    BaseWindow::~BaseWindow() = default;

    tgui::Gui & BaseWindow::getGui() const {
        return m_gui;
    }
}

