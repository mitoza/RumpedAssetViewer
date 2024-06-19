//
// Created by mito on 19.06.2024.
//

#include "../include/MainWindow.h"
#include <iostream>

namespace rumpedav {
    MainWindow::MainWindow(Context &_context) : BaseWindow(_context) {

        window.create(config.getVideoMode(), config.getTitle(), config.getStyle());
        gui.setWindow(window);

        window.setVerticalSyncEnabled(config.isVSync());
        window.setFramerateLimit(config.getFramerateLimit());
    }

    void MainWindow::create() {
        try {
            const tgui::Panel::Ptr mainTopPanel = tgui::Panel::create();
            gui.add(mainTopPanel, WNAME_MAIN_TOP_PANEL);

            const tgui::Button::Ptr btnClose = tgui::Button::create();
            btnClose->setText("Exit");
            mainTopPanel->add(btnClose, WNAME_MAIN_BTN_CLOSE);

            resize(window.getSize());

        } catch(const tgui::Exception& e) {
            std::cerr << "Failed to load TGUI widgets: " << e.what() << std::endl;
        }
    }

    void MainWindow::resize(sf::Vector2u size) {
        const tgui::Panel::Ptr mainTopPanel = gui.get<tgui::Panel>(WNAME_MAIN_TOP_PANEL);
        mainTopPanel->setSize({"100%", "48"});
        mainTopPanel->setPosition({0, 0});

        const tgui::Button::Ptr btnClose = gui.get<tgui::Button>(WNAME_MAIN_BTN_CLOSE);
        btnClose->setSize({"48", "48"});
        btnClose->setPosition(mainTopPanel->getSize().x - btnClose->getSize().x, 0);
    }

    void MainWindow::destroy() {
        gui.removeAllWidgets();
    }

}
