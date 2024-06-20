//
// Created by mito on 19.06.2024.
//

#include "../../include/ui/MainWindow.h"

#include <iostream>


namespace rumpedav {
    MainWindow::MainWindow(Context &_context, BaseWindow *parent)
        : BaseWindow(_context, parent) {
    }

    void MainWindow::create() {
        window.create(config.getVideoMode(), config.getTitle(), config.getStyle());
        window.setVerticalSyncEnabled(config.isVSync());
        window.setFramerateLimit(config.getFramerateLimit());
        //if(!sf::WindowIcon.loadFromFile("texture/cherry_leaf1.png"))
        //    std::cout << "cant load texture from file " << std::endl;
        //    window.setIcon(60,60,WindowIcon.getPixelsPtr());
        gui.setWindow(window);
        window.setIcon(24, 24, Icons::cross().getData()->backendTexture->getPixels());

        try {
            // MenuBar
            const tgui::MenuBar::Ptr menuBar = tgui::MenuBar::create();
            menuBar->setRenderer(config.getTheme().getRenderer("MenuBar"));
            menuBar->addMenuItem({"File", "New", "Picture"});
            menuBar->addMenuItem({"File", "Open"});
            menuBar->addMenuItem({"File", "-"});
            menuBar->addMenuItem({"File", "Exit"});
            menuBar->addMenuItem({"Tools", "Converter"});
            menuBar->addMenuItem({"Window", "About"});

            gui.add(menuBar, WNAME_MAIN_MENU_BAR);

            // TopPanel
            const tgui::Panel::Ptr mainTopPanel = tgui::Panel::create();
            gui.add(mainTopPanel, WNAME_MAIN_TOP_PANEL);

            const tgui::BitmapButton::Ptr btnClose = tgui::BitmapButton::create();
            //btnClose->setText("Exit");
            btnClose->setImage(Icons::cross());
            btnClose->setImageScaling(0.5f);
            btnClose->onClick([&] { window.close(); });
            mainTopPanel->add(btnClose, WNAME_MAIN_BTN_CLOSE);

            const tgui::Button::Ptr btnOpen = tgui::Button::create();
            btnOpen->setText("Open");
            btnOpen->onClick([&] {
                MainWindow mainWindow(context, this);
                mainWindow.show();
            });
            mainTopPanel->add(btnOpen, WNAME_MAIN_BTN_OPEN);

            resize(window.getSize().x, window.getSize().y);
        } catch (const tgui::Exception &e) {
            std::cerr << "Failed to load TGUI widgets: " << e.what() << std::endl;
        }
    }

    void MainWindow::resize(unsigned int width, unsigned int height) {
        const tgui::MenuBar::Ptr mainMenuBar = gui.get<tgui::MenuBar>(WNAME_MAIN_MENU_BAR);
        mainMenuBar->setSize({width, 24});
        mainMenuBar->setPosition(24, 0);

        const tgui::Panel::Ptr mainTopPanel = gui.get<tgui::Panel>(WNAME_MAIN_TOP_PANEL);
        mainTopPanel->setSize({width, 48});
        mainTopPanel->setPosition({0, 24});

        const tgui::BitmapButton::Ptr btnClose = gui.get<tgui::BitmapButton>(WNAME_MAIN_BTN_CLOSE);
        btnClose->setSize({"48", "48"});
        btnClose->setPosition(mainTopPanel->getSize().x - btnClose->getSize().x, 0);

        const tgui::Button::Ptr btnOpen = gui.get<tgui::Button>(WNAME_MAIN_BTN_OPEN);
        btnOpen->setSize("48", "48");
        btnOpen->setPosition(btnClose->getPosition().x - btnOpen->getSize().x, 0);

    }

    void MainWindow::destroy() {
        gui.removeAllWidgets();
    }

    void MainWindow::handleEvent(sf::Event &event) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                switch(event.key.code) {
                    case sf::Keyboard::Key::Space:

                        break;
                }
                break;

            default:
                break;
        }
    }

}
