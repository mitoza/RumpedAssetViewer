//
// Created by Dmitry Velychko on 21.06.2024.
//

#ifndef ASSETVIEWER_MAINFRAME_H
#define ASSETVIEWER_MAINFRAME_H

#include "wx/wx.h"
#include "../../include/ui/samples/SampleComboFrame.h"

namespace rumpedav {

    enum {
        ID_MENU_Hello = 1,
        ID_MENU_QuickHello,
        ID_MENU_ComboBox,

    };

    class MainFrame : public wxFrame {
        void OnHello(wxCommandEvent& event);
        void OnExit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);

    public:
        MainFrame();
        ~MainFrame() override;
    };

}

#endif //ASSETVIEWER_MAINFRAME_H
