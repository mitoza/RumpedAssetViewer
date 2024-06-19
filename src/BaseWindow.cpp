//
// Created by mito on 19.06.2024.
//

#include <iostream>
#include "../include/BaseWindow.h"

namespace rumpedav {

    BaseWindow::BaseWindow(Context &_context)
            : context(_context),
              config(_context.getConfig()),
              thread(&BaseWindow::run, this) {
//        window.create({320, 240}, "New Window");
//        gui.setWindow(window);

    }


    sf::RenderWindow &BaseWindow::Window() {
        return window;
    }

    tgui::Gui &BaseWindow::Gui() {
        return gui;
    }

    void BaseWindow::run() {
        std::cout << "Run! Thread:" << ++threadCounter << std::endl;
        create();
        sf::Event event;

        //sf::RenderWindow window2(config.getVideoMode(), config.getTitle(), config.getStyle());

        while (window.isOpen()) {
            if (this->mainThread) {
                while (window.pollEvent(event)) {
                    this->handleEvent(event);
                    gui.handleEvent(event);
                }
            }
            window.clear();
            if (this->mainThread) gui.draw();
            window.display();
        }
        std::cout << "EndRun!" << std::endl;
    }

    void BaseWindow::create() {
    }

    void BaseWindow::destroy() {
    }

    void BaseWindow::resize(sf::Vector2u size) {
    }

    void BaseWindow::handleEvent(sf::Event &event) {

    }

    void BaseWindow::show(const bool _mainThread) {
        this->mainThread = _mainThread;
        std::cout << "Main: " << ++threadCounter << std::endl;
        if (mainThread) {
            run();
        } else {
            thread.launch();
        }
    }

//    void BaseWindow::addWindow(std::unique_ptr<BaseWindow> &window) {
//        //m_windows.push_back(std::unique_ptr<BaseWindow>(window));
//    }

}

