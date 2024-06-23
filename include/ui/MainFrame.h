//
// Created by Dmitry Velychko on 21.06.2024.
//

#ifndef ASSETVIEWER_MAINFRAME_H
#define ASSETVIEWER_MAINFRAME_H

#include <iostream>
//#include "wx/wx.h"
#include "../../include/ui/samples/SampleComboFrame.h"
#include "../../include/ui/AuiFrame.h"
#include "../../include/ui/samples/SampleAuiFrame.h"


namespace rumpedav {


    class MainFrame : public wxFrame {

        enum {
            ID_MENU_Hello = 1,
            ID_MENU_QuickHello,
            ID_MENU_SAMPLE_ComboBox,
            ID_MENU_SAMPLE_AUI
        };

    public:
        MainFrame();

    private:
        void OnHello(wxCommandEvent &event);

        void OnExit(wxCommandEvent &event);

        void OnAbout(wxCommandEvent &event);

    };

}

#endif //ASSETVIEWER_MAINFRAME_H
