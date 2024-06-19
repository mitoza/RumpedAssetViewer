//
// Created by mito on 19.06.2024.
//

#include "../include/ApplicationConfig.h"

namespace rumpedav {
    ApplicationConfig::ApplicationConfig(int argc, char *argv[]) {
        tgui::Theme theme();


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
}
