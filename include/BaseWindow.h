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

#include <vector>
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include <TGUI/Widgets/Button.hpp>
#include <TGUI/Widgets/CheckBox.hpp>

namespace rumpedav {

#define WNAME_MAIN_WINDOW "w_main_window"
#define WNAME_MAIN_TOOLBAR "w_main_toolbar"


    class BaseWindow {
        std::vector<tgui::Widget::Ptr> m_widgets;
        tgui::Gui &m_gui;

    public:
        explicit BaseWindow(tgui::Gui &gui);

        ~BaseWindow();

        [[nodiscard]] tgui::Gui &getGui() const;
    };
}

#endif //BASEWINDOW_H
