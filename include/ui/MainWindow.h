//
// Created by mito on 19.06.2024.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "SFML/Graphics.hpp"
#include "BaseWindow.h"
#include "DialogWindow.h"
#include "../data/Icons.h"

namespace rumpedav {
#define WNAME_MAIN_WINDOW "w_main_window"
#define WNAME_MAIN_MENU_BAR "w_main_menubar"
#define WNAME_MAIN_TOP_PANEL "w_main_top_panel"
#define WNAME_MAIN_BTN_CLOSE "w_main_btn_close"
#define WNAME_MAIN_BTN_OPEN "w_main_btn_open"

    class MainWindow : public BaseWindow {
    public:
        explicit MainWindow(Context &_context, BaseWindow *parent = nullptr);

        void create() override;

        void resize(unsigned int width, unsigned int height) override;

        void handleEvent(sf::Event &event) override;

        void destroy() override;

    };
}

#endif //MAINWINDOW_H
