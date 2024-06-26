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
#include "../../include/ui/samples/DndFrame.h"
#include "wxSFMLCanvas.h"


namespace rumpedav {


    class MainFrame : public wxFrame {

        enum {
            ID_MENU_Hello = wxID_HIGHEST,
            ID_MENU_QuickHello,
            ID_MENU_SAMPLE_ComboBox,
            ID_MENU_SAMPLE_AUI,
            ID_MENU_SAMPLE_DND,


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

    private:

        wxSFMLCanvas *CreateSFMLControl(const wxSize &size = wxWindow::FromDIP(wxSize(320, 240), nullptr));

        wxSizeReportCtrl *CreateSizeReportCtrl(const wxSize &size = wxWindow::FromDIP(wxSize(80, 80), nullptr));

    };

}

#endif //ASSETVIEWER_MAINFRAME_H
