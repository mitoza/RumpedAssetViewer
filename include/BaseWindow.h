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


#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include <TGUI/Widgets/Button.hpp>
#include <TGUI/Widgets/CheckBox.hpp>
#include "Context.h"


namespace rumpedav {

    class BaseWindow {
        //static std::vector<std::shared_ptr<BaseWindow>> m_windows;
        //static size_t currentWindowIndex;

        //static void addWindow(std::unique_ptr<BaseWindow> &window);

    protected:
        ApplicationConfig config;
        sf::Thread thread;
        sf::RenderWindow window;
        tgui::Gui gui;

        void run();

    public:
        BaseWindow(Context &_context);
        ~BaseWindow();

        [[nodiscard]] sf::RenderWindow &Window();

        [[nodiscard]] tgui::Gui &Gui();

        virtual void create();

        virtual void resize(sf::Vector2u size);

        virtual void destroy();

        size_t show(bool runThread);

        void close(size_t index);

    };

    //std::vector<std::shared_ptr<BaseWindow>> BaseWindow::m_windows;
    //size_t BaseWindow::currentWindowIndex = -1;

}

#endif //BASEWINDOW_H
