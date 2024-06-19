//
// Created by mito on 19.06.2024.
//

#include "../include/Application.h"

namespace rumpedav {
    Application::Application(ApplicationConfig &config)
        : appConfig(config),
          window(config.getVideoMode(), config.getTitle()),
          gui(window) {
    }

    void Application::run() {
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
}