//
// Created by Dmitry Velychko on 21.06.2024.
//

#ifndef ASSETVIEWER_MAINFRAME_H
#define ASSETVIEWER_MAINFRAME_H

#include <iostream>
#include <memory>

#include "wx/wx.h"
#include "wx/aui/aui.h"
#include "wx/wrapsizer.h"
#include "../../include/ui/samples/SampleComboFrame.h"
#include "../../include/ui/samples/SampleAuiFrame.h"
#include "../../include/ui/samples/DndFrame.h"
#include "controls/ColorPane.h"
#include "controls/FormatXPMPanel.h"
#include "controls/PropertiesCtrl.h"
#include "Config.h"


namespace rumpedav {

    // class PropertiesCtrl;

    class MainFrame : public wxFrame {
        wxAuiManager m_auiManager;
        std::unique_ptr<wxAuiToolBar> m_tbLeft;
        //std::unique_ptr<wxSFMLCanvas> m_pContent;
        std::unique_ptr<wxColorPane> m_pContent;
        std::unique_ptr<PropertiesCtrl> m_propCtrl;
        std::unique_ptr<wxTreeCtrl> m_pProject;

    public:
        MainFrame();

    private:
        void OnInit();

        void OnPaneClose(wxAuiManagerEvent &evt);

        void OnHello(wxCommandEvent &event);

        void OnExit(wxCommandEvent &event);

        void OnAbout(wxCommandEvent &event);

    private:
        void CreateToolbarLeft();

        void CreatePanelContent(const wxSize &paneSize = wxWindow::FromDIP(wxSize(800, 600), nullptr));

        wxSizeReportCtrl *CreateSizeReportCtrl(const wxSize &paneSize = wxWindow::FromDIP(wxSize(320, 240), nullptr));

        void CreatePropertiesCtrl(const wxSize &paneSize = wxWindow::FromDIP(wxSize(320, 240), nullptr));

        void CreatePanelProject(const wxSize &paneSize = wxWindow::FromDIP(wxSize(320, 240), nullptr));

        wxPanel *BuildControlsPanel(wxWindow *parent);

    };
}

#endif //ASSETVIEWER_MAINFRAME_H
