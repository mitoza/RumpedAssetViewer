//
// Created by Dmitry Velychko on 23.06.2024.
//

#ifndef ASSETVIEWER_AUIFRAME_H
#define ASSETVIEWER_AUIFRAME_H

#include "wx/wx.h"

class AuiFrame : public wxFrame {

    // event handlers (these functions should _not_ be virtual)
    void OnQuit(wxCommandEvent &event);

    void OnIdle(wxIdleEvent &event);

public:

    AuiFrame(wxWindow *parent, const wxString& title);

    ~AuiFrame() override;


};


#endif //ASSETVIEWER_AUIFRAME_H
