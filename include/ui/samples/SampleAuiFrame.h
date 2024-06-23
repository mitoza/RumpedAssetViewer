//
// Created by Dmitry Velychko on 23.06.2024.
//

#ifndef ASSETVIEWER_SAMPLEAUIFRAME_H
#define ASSETVIEWER_SAMPLEAUIFRAME_H

#include "wx/wxprec.h"

#include "wx/app.h"
#include "wx/grid.h"
#include "wx/treectrl.h"
#include "wx/spinctrl.h"
#include "wx/artprov.h"
#include "wx/clipbrd.h"
#include "wx/image.h"
#include "wx/choice.h"
#include "wx/colordlg.h"
#include "wx/wxhtml.h"
#include "wx/imaglist.h"
#include "wx/dataobj.h"
#include "wx/dcclient.h"
#include "wx/bmpbuttn.h"
#include "wx/log.h"
#include "wx/menu.h"
#include "wx/toolbar.h"
#include "wx/statusbr.h"
#include "wx/msgdlg.h"
#include "wx/textdlg.h"
#include "wx/stattext.h"

#include "wx/aui/aui.h"
//#include "../sample.xpm"

#include "wxSizeReportCtrl.h"
//#include "SettingsPanel.h"

//class wxSizeReportCtrl;
//class SettingsPanel;

class SampleAuiFrame : public wxFrame {
    enum {
        ID_CreateTree = wxID_HIGHEST,
        ID_CreateGrid,
        ID_CreateText,
        ID_CreateHTML,
        ID_CreateNotebook,
        ID_CreateSizeReport,
        ID_GridContent,
        ID_TextContent,
        ID_TreeContent,
        ID_HTMLContent,
        ID_NotebookContent,
        ID_SizeReportContent,
        ID_CreatePerspective,
        ID_CopyPerspectiveCode,
        ID_AllowFloating,
        ID_AllowActivePane,
        ID_TransparentHint,
        ID_VenetianBlindsHint,
        ID_RectangleHint,
        ID_NoHint,
        ID_HintFade,
        ID_NoVenetianFade,
        ID_TransparentDrag,
        ID_NoGradient,
        ID_VerticalGradient,
        ID_HorizontalGradient,
        ID_LiveUpdate,
        ID_AllowToolbarResizing,
        ID_Settings,
        ID_CustomizeToolbar,
        ID_DropDownToolbarItem,
        ID_NotebookNoCloseButton,
        ID_NotebookCloseButton,
        ID_NotebookCloseButtonAll,
        ID_NotebookCloseButtonActive,
        ID_NotebookAllowTabMove,
        ID_NotebookAllowTabExternalMove,
        ID_NotebookAllowTabSplit,
        ID_NotebookWindowList,
        ID_NotebookScrollButtons,
        ID_NotebookTabFixedWidth,
        ID_NotebookArtGloss,
        ID_NotebookArtSimple,
        ID_NotebookAlignTop,
        ID_NotebookAlignBottom,
        ID_NotebookNewTab,
        ID_NotebookDeleteTab,

        ID_SampleItem,

        ID_FirstPerspective = ID_CreatePerspective + 1000
    };

wxDECLARE_EVENT_TABLE();

    wxAuiManager m_mgr;
    wxArrayString m_perspectives;
    wxMenu *m_perspectives_menu;
    long m_notebook_style;
    long m_notebook_theme;

public:
    SampleAuiFrame(wxWindow *parent,
                   wxWindowID id,
                   const wxString &title,
                   const wxPoint &pos = wxDefaultPosition,
                   const wxSize &size = wxDefaultSize,
                   long style = wxDEFAULT_FRAME_STYLE | wxSUNKEN_BORDER);

    wxAuiDockArt *GetDockArt();

    void DoUpdate();

private:

    void OnEraseBackground(wxEraseEvent &evt);

    void OnSize(wxSizeEvent &evt);

    void OnCreateTree(wxCommandEvent &evt);

    void OnCreateGrid(wxCommandEvent &evt);

    void OnCreateHTML(wxCommandEvent &evt);

    void OnCreateNotebook(wxCommandEvent &evt);

    void OnCreateText(wxCommandEvent &evt);

    void OnCreateSizeReport(wxCommandEvent &evt);

    void OnChangeContentPane(wxCommandEvent &evt);

    void OnDropDownToolbarItem(wxAuiToolBarEvent &evt);

    void OnCreatePerspective(wxCommandEvent &evt);

    void OnCopyPerspectiveCode(wxCommandEvent &evt);

    void OnRestorePerspective(wxCommandEvent &evt);

    void OnSettings(wxCommandEvent &evt);

    void OnCustomizeToolbar(wxCommandEvent &evt);

    void OnAllowNotebookDnD(wxAuiNotebookEvent &evt);

    void OnNotebookPageClose(wxAuiNotebookEvent &evt);

    void OnNotebookPageClosed(wxAuiNotebookEvent &evt);

    void OnNotebookPageChanging(wxAuiNotebookEvent &evt);

    void OnExit(wxCommandEvent &evt);


    void OnAbout(wxCommandEvent &evt);

    void OnTabAlignment(wxCommandEvent &evt);

    void OnGradient(wxCommandEvent &evt);

    void OnToolbarResizing(wxCommandEvent &evt);

    void OnManagerFlag(wxCommandEvent &evt);

    void OnNotebookFlag(wxCommandEvent &evt);

    void OnUpdateUI(wxUpdateUIEvent &evt);

    void OnNotebookNewTab(wxCommandEvent &evt);

    void OnNotebookDeleteTab(wxCommandEvent &evt);

    void OnPaneClose(wxAuiManagerEvent &evt);

private:
    wxTextCtrl *CreateTextCtrl(const wxString &text = wxEmptyString);

    wxGrid *CreateGrid();

    wxTreeCtrl *CreateTreeCtrl();

    wxSizeReportCtrl *CreateSizeReportCtrl(const wxSize &size = wxWindow::FromDIP(wxSize(80, 80), nullptr));

    wxPoint GetStartPosition();

    wxHtmlWindow *CreateHTMLCtrl(wxWindow *parent = nullptr);

    wxAuiNotebook *CreateNotebook();

    wxString GetIntroText();

};


#endif //ASSETVIEWER_SAMPLEAUIFRAME_H
