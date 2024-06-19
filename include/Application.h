//
// Created by mito on 19.06.2024.
//

#ifndef APPLICATION_H
#define APPLICATION_H

#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include "ApplicationConfig.h"

class Application {

    ApplicationConfig appConfig;
    sf::RenderWindow window;
    tgui::Gui gui;

public:
    explicit Application(ApplicationConfig &config);
    ~Application() = default;

    void run();

private:
    void handleEvents();

};



#endif //APPLICATION_H
