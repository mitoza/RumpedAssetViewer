//
// Created by mito on 01.07.2024.
//

#ifndef WXPROJECTPANE_H
#define WXPROJECTPANE_H

#include <wx/wx.h>
#include "wx/dcbuffer.h"


class wxSelectablePane : public wxWindow {
public:
    bool selected = false;

    wxSelectablePane(wxWindow *parent, wxWindowID id, const wxPoint &pos = wxDefaultPosition,
                     const wxSize &size = wxDefaultSize);

    [[nodiscard]] wxSize DoGetBestSize() const override;

protected:
    virtual void DrawContent(wxGraphicsContext *gc, const wxRect &rect, int roundress) const;

private:
    void OnPaint(wxPaintEvent &event);
};


#endif //WXPROJECTPANE_H
