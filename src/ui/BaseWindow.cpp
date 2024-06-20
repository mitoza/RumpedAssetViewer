//
// Created by mito on 19.06.2024.
//

#include <iostream>
#include "../../include/ui/BaseWindow.h"

namespace rumpedav {

    BaseWindow::BaseWindow(Context &_context, BaseWindow *parent)
            : context(_context),
              parent(parent),
              config(_context.getConfig()) {
    }


    sf::RenderWindow &BaseWindow::Window() {
        return window;
    }

    sf::WindowHandle BaseWindow::Handle() {
        return window.getSystemHandle();
    }

    tgui::Gui &BaseWindow::Gui() {
        return gui;
    }

    void BaseWindow::run() {
        create();
        sf::Event event;
        std::cout << "Run!" << std::endl;

        while (window.isOpen()) {
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Resized) {
                    resize(event.size.width, event.size.height);
                }
                gui.handleEvent(event);
                this->handleEvent(event);

            }
            window.clear();
            gui.draw();
            window.display();
        }
        std::cout << "EndRun!" << std::endl;
    }

    void BaseWindow::create() {
    }

    void BaseWindow::destroy() {
    }

    void BaseWindow::resize(unsigned int width, unsigned int height) {
    }

    void BaseWindow::handleEvent(sf::Event &event) {

    }

    void BaseWindow::show() {
            run();
    }

//    void BaseWindow::addWindow(std::unique_ptr<BaseWindow> &window) {
//        //m_windows.push_back(std::unique_ptr<BaseWindow>(window));
//    }

}

