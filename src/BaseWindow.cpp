//
// Created by mito on 19.06.2024.
//

#include "../include/BaseWindow.h"

namespace rumpedav {

    BaseWindow::BaseWindow()
        : config, thread(&BaseWindow::run, this) {
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
    }

    void BaseWindow::resize(sf::Vector2u size) {
    }

    size_t BaseWindow::show(const bool runThread  = true) {
        if (runThread) {
            m_windows.push_back(std::unique_ptr<BaseWindow>(this));
            thread.launch();
        } else {
            run();
        }
        currentWindowIndex = m_windows.size() - 1;
        return currentWindowIndex;
    }

    void BaseWindow::close(size_t index) {
        // TODO implmentation
        // Close window
        // Stop thread
        // Remove window
        // Remove thread

    }

    void BaseWindow::closeAll() {
        for(const auto & window : m_windows) {
            window->window.close();
        }
        m_windows.clear();
    }

}

