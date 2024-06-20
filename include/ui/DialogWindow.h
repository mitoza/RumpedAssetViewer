//
// Created by Dmitry Velychko on 20.06.2024.
//

#ifndef ASSETVIEWER_DIALOGWINDOW_H
#define ASSETVIEWER_DIALOGWINDOW_H

#include "BaseWindow.h"
#include "../Context.h"

namespace rumpedav {

    class DialogWindow : public BaseWindow {

    public:
        explicit DialogWindow(Context &_context);

        void create() override;

        void destroy() override;

        void resize(unsigned int width, unsigned int height) override;

        void handleEvent(sf::Event &event) override;
    };

}

#endif //ASSETVIEWER_DIALOGWINDOW_H
