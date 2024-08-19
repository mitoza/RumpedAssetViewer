//
// Created by mito on 09.07.2024.
//

#ifndef CONFIG_H
#define CONFIG_H

#include "wx/wx.h"

#define PANE_TOOLBAR_TOP "pane_toolbar_top"
#define PANE_TOOLBAR_LEFT "pane_toolbar_left"
#define PANE_PROJECT "pane_project"
#define PANE_CONTENT "pane_content"
#define PANE_PROPERTIES "pane_properties"
#define PANE_METADATA "pane_metadata"
#define CTRL_PROPERTIES "ctrl_properties"

enum {
    ID_MENU_Hello = wxID_HIGHEST,
    ID_MENU_QuickHello,
    ID_MENU_SAMPLE_ComboBox,
    ID_MENU_SAMPLE_AUI,
    ID_MENU_SAMPLE_DND,
    ID_MENU_PROPERTIES_ADD_COLOR,

    ID_TB_LEFT,
    ID_TB_LEFT_BTN_PROJECT,
    ID_TB_LEFT_BTN_OPTIONS,

    ID_PROPERTIES_CONTROL

};

#endif //CONFIG_H
