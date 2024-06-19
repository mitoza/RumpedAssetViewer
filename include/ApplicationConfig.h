//
// Created by mito on 19.06.2024.
//

#ifndef APPLICATION_CONFIG_H
#define APPLICATION_CONFIG_H
#include <string>

#include "SFML/Window/VideoMode.hpp"
#include "SFML/Graphics.hpp"
#include "TGUI/TGUI.hpp"


namespace rumpedav {
    class ApplicationConfig {

        unsigned int w_width = 800;
        unsigned int w_height = 600;

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

        static tgui::Theme getLightTheme();
        static tgui::Theme getDarkTheme();


        // Default theme renderers
        // BaseThemeLoader, DefaultThemeLoader
        // BackendRenderer -> BackendText, BackendTexture

    };
}

#endif //APPLICATION_CONFIG_H
