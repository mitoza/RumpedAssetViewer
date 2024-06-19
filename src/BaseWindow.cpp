//
// Created by mito on 19.06.2024.
//

#include <iostream>
#include "../include/BaseWindow.h"

namespace rumpedav {

    BaseWindow::BaseWindow(Context &_context)
        : config(_context.getConfig()), thread(&BaseWindow::run, this) {
        window.create({320, 240}, "New Window");
        gui.setWindow(window);

    }

    BaseWindow::~BaseWindow() {

    };

    sf::RenderWindow &BaseWindow::Window() {
        return window;
    }

    tgui::Gui &BaseWindow::Gui() {
        return gui;
    }

    void BaseWindow::run() {
        std::cout << "Run!" << std::endl;
        create();
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                gui.handleEvent(event);

                switch (event.type) {
                    case sf::Event::Closed:
                        window.close();
                    break;

                    default:
                        break;
                }
            }

            window.clear();
            gui.draw();
            window.display();
        }
        std::cout << "EndRun!" << std::endl;
    }

    void BaseWindow::create() {
    }

    void BaseWindow::resize(sf::Vector2u size) {
    }

    void BaseWindow::destroy() {
    }

    size_t BaseWindow::show(const bool runThread  = true) {
        if (runThread) {
            thread.launch();
        } else {
            run();
        }
        //currentWindowIndex = m_windows.size() - 1;
        return 0;
    }

    void BaseWindow::close(size_t index) {
        // TODO implmentation
        // Close window
        // Stop thread
        // Remove window
        // Remove thread

    }

//    void BaseWindow::addWindow(std::unique_ptr<BaseWindow> &window) {
//        //m_windows.push_back(std::unique_ptr<BaseWindow>(window));
//    }

}

