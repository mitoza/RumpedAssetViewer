//
// Created by mito on 19.06.2024.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "BaseWindow.h"

namespace rumpedav {
    class MainWindow: public BaseWindow {

        void addToolbar();

    public:
        explicit MainWindow(tgui::Gui &gui) : BaseWindow(gui) {

        }

        ~MainWindow();

    };
}

#endif //MAINWINDOW_H
