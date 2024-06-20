//
// Created by mito on 20.06.2024.
//

#ifndef THEMES_H
#define THEMES_H
#include <TGUI/Loading/Theme.hpp>
#include "Color.h"
#include <TGUI/Renderers/MenuBarRenderer.hpp>

namespace rumpedav {

    // https://tgui.eu/tutorials/latest-stable/using-themes/
    // https://tgui.eu/tutorials/latest-stable/renderers/

    class Themes {

    public:
        static tgui::Theme Light() {
            const tgui::Color backgroundColor = tgui::Color();
            tgui::Theme lightTheme;
            auto menuBarRenderer = std::make_shared<tgui::MenuBarRenderer>();
            //menuBarRenderer->setBackgroundColor(tgui::Color(175, 175, 175));
            //menuBarRenderer->setBackgroundColor(Color::Material(MaterialColor::Blue, Variant::_700));
            menuBarRenderer->setBackgroundColor(Color::HTML(HtmlColor::azure));


            lightTheme.addRenderer("MenuBar", menuBarRenderer->getData());
            //lightTheme.getRenderer("MenuBar")->propertyValuePairs["BackgroundColor"] = tgui::Color(175, 175, 175);

            return lightTheme;
        }

        static tgui::Theme Dark() {
            tgui::Theme darkTheme;
            return darkTheme;
        }

    };
}

#endif //THEMES_H
