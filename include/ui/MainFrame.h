//
// Created by Dmitry Velychko on 21.06.2024.
//

#ifndef ASSETVIEWER_MAINFRAME_H
#define ASSETVIEWER_MAINFRAME_H

#include <iostream>
#include "wx/wx.h"
#include "wx/aui/aui.h"
#include "../../include/ui/samples/SampleComboFrame.h"

#include "../../include/ui/samples/SampleAuiFrame.h"


namespace rumpedav {


    class MainFrame : public wxFrame {

        enum {
            ID_MENU_Hello = wxID_HIGHEST,
            ID_MENU_QuickHello,
            ID_MENU_SAMPLE_ComboBox,
            ID_MENU_SAMPLE_AUI,

            ID_TB_LEFT,
            ID_TB_PROJECT_BTN,
            ID_TB_PROJECT_OPTIONS,

        };

        wxAuiManager m_auiManager;

    public:
        MainFrame();
        ~MainFrame();

    private:
        void initMenuBar();

        void initUI();

        void OnHello(wxCommandEvent &event);

        void OnExit(wxCommandEvent &event);

        void OnAbout(wxCommandEvent &event);

    };

}

#endif //ASSETVIEWER_MAINFRAME_H
