//
// Created by Dmitry Velychko on 21.06.2024.
//

#ifndef ASSETVIEWER_MAINFRAME_H
#define ASSETVIEWER_MAINFRAME_H

#include "wx/wx.h"

namespace rumpedav {

    enum {
        ID_Hello = 1
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
