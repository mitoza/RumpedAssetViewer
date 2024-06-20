//
// Created by mito on 19.06.2024.
//

#include "../include/ApplicationConfig.h"

namespace rumpedav {
    ApplicationConfig::ApplicationConfig(int argc, char *argv[]) {
        theme = getLightTheme();
    }

    ApplicationConfig &ApplicationConfig::load() {
        return *this;
    }

    sf::VideoMode ApplicationConfig::getVideoMode() const {
        return sf::VideoMode({w_width, w_height, 32});
    }

    std::string ApplicationConfig::getTitle() {
        return "Rumped Asset viewer";
    }

    bool ApplicationConfig::isVSync() {
        return false;
    }

    unsigned int ApplicationConfig::getStyle() {
        return sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close;
        //return sf::Style::Fullscreen;
        //return sf::Style::None;
    }

    unsigned int ApplicationConfig::getFramerateLimit() {
        return 60;
    }

    tgui::Theme &ApplicationConfig::getTheme() {
        return theme;
    }

    tgui::Theme ApplicationConfig::getLightTheme() {
        tgui::Theme lightTheme;
        auto menuBarRenderer = std::make_shared<tgui::MenuBarRenderer>();
        menuBarRenderer->setBackgroundColor(tgui::Color(175, 175, 175));
        lightTheme.addRenderer("MenuBar", menuBarRenderer->getData());
        //lightTheme.getRenderer("MenuBar")->propertyValuePairs["BackgroundColor"] = tgui::Color(175, 175, 175);

        return lightTheme;
    }

    tgui::Theme ApplicationConfig::getDarkTheme() {
        tgui::Theme darkTheme;
        return darkTheme;
    }


}
