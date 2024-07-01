//
// Created by mito on 01.07.2024.
//

#ifndef WXCOLORPANE_H
#define WXCOLORPANE_H
#include "wxSelectablePane.h"


class wxColorPane : public wxSelectablePane {

public:
    wxColor color;

    wxColorPane(wxWindow *parent, wxWindowID id, const wxColor &paneColor, const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize);

private:
    void DrawContent(wxGraphicsContext *gc, const wxRect &rect, int roundness) const override;
};



#endif //WXCOLORPANE_H
