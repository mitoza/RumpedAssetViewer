//
// Created by mito on 19.06.2024.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "BaseWindow.h"

namespace rumpedav {
#define WNAME_MAIN_WINDOW "w_main_window"
#define WNAME_MAIN_TOP_PANEL "w_main_toolbar"
#define WNAME_MAIN_BTN_CLOSE "w_main_btn_close"

    class MainWindow : public BaseWindow {
    public:
        explicit MainWindow();

        void run() override;

        void resize(sf::Vector2u size) override;

    };
}

#endif //MAINWINDOW_H
