//
// Created by mito on 19.06.2024.
//

#ifndef BASEWINDOW_H
#define BASEWINDOW_H

/*
 *  https://tgui.eu/documentation/latest-stable/annotated.html
 *  Standard TGUI Simple Widgets List:
 *      ButtonBase, Button, BitmapButton, EditBox, CheckBox, ChatBox(text, string),
 *      ColorPicker, CustomWidgetForBindings, EditBox, EditBoxSlider, FileDialog,
 *      Knob, Label, ListBox, ListView, MenuBar, MessageBox, Picture, ProgressBar
 *      RadioButton, RangeSlider, RichTextLabel, Scrollbar, ScrollbarChildWidget
 *      SeparatorLine, Slider, SpinButton, SpinControl, TextArea, ToggleButton,
 *      TreeView
 *
 *
 *  Other usefull classes:
 *      Sprite, Texture, SvgImage, ToolTip,
 *
 *  Containers:
 *      Container, BoxLayout, BoxLayoutRatios, ChildWindow, ClickableWidget, Group
 *      HorizontalLayout, HorizontalWrap, Panel, PanelListBox, ScrollablePanel,
 *      SubwidgetContainer, TabContainer, Tabs, VerticalLayout,
 *
 *
 *  Create widget example:
 *      auto editText = tgui::EditBox::create();
 *      gui.add(editBox, "MyWidgetName");
 *      childWindow->add(checkBox);
 *
 *  Retrieving widgets example:
 *      tgui::EditBox::Ptr editBox = gui.get<tgui::EditBox>("MyWidgetName");
 *      tgui::Widget::Ptr widget = gui.get("MyWidgetName");
 *
 *  Copying widgets example:
 *      tgui::Button::Ptr newButton = tgui::Button::copy(oldButton);
 *      gui.add(newButton);
 *
 *  Removing widgets example:
 *      gui.remove(button);
 *      gui.removeAllWidgets();
 */


#include "TGUI/TGUI.hpp"
#include "TGUI/Backend/SFML-Graphics.hpp"
#include "TGUI/Widgets/Button.hpp"
#include "TGUI/Widgets/CheckBox.hpp"
#include "../Context.h"


namespace rumpedav {

    class BaseWindow {
        std::vector<std::shared_ptr<BaseWindow>> childWindows;
    protected:
        Context context;
        ApplicationConfig config;
        sf::RenderWindow window;
        tgui::Gui gui;
        BaseWindow *parent = nullptr;

        void run();

    public:
        explicit BaseWindow(Context &_context, BaseWindow *parent = nullptr);

        [[nodiscard]] sf::RenderWindow &Window();

        sf::WindowHandle Handle();

        [[nodiscard]] tgui::Gui &Gui();

        virtual void create();

        virtual void destroy();

        virtual void resize(unsigned int width, unsigned int height);

        virtual void handleEvent(sf::Event &event);

        void show();

    };

}

#endif //BASEWINDOW_H
