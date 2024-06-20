//
// Created by mito on 19.06.2024.
//

#ifndef APPLICATION_CONFIG_H
#define APPLICATION_CONFIG_H
#include <string>

#include "SFML/Window/VideoMode.hpp"
#include "SFML/Graphics.hpp"
#include "TGUI/TGUI.hpp"
#include "./data/Themes.h"


namespace rumpedav {

#define SIZE_2 2
#define SIZE_4 4
#define SIZE_8 8
#define SIZE_12 12
#define SIZE_16 16
#define SIZE_20 20
#define SIZE_24 24
#define SIZE_28 28
#define SIZE_32 32
#define SIZE_36 38
#define SIZE_42 42
#define SIZE_48 48
#define SIZE_56 56
#define SIZE_64 64

    class Themes;

    class ApplicationConfig {

        unsigned int w_width = 1024;
        unsigned int w_height = 768;
        tgui::Theme theme;
        tgui::Font font;

    public:
        ApplicationConfig() = default;
        ApplicationConfig(int argc, char* argv[]);
        ~ApplicationConfig() = default;

        ApplicationConfig &load();

        [[nodiscard]] sf::VideoMode getVideoMode() const;


        static std::string getTitle();
        static bool isVSync();
        static unsigned int getStyle();
        static unsigned int getFramerateLimit();

        tgui::Theme &getTheme();

        tgui::Font &getFont();


        // Default theme renderers
        // BaseThemeLoader, DefaultThemeLoader
        // BackendRenderer -> BackendText, BackendTexture

    };
}

#endif //APPLICATION_CONFIG_H
