//
// Created by mito on 01.07.2024.
//

#include "../../../include/ui/controls/ColorPane.h"

#include "../../../cmake-build-release/_deps/wx_widgets-src/include/wx/graphics.h"


wxColorPane::wxColorPane(wxWindow *parent, wxWindowID id, const wxColor &paneColor, const wxPoint &pos, const wxSize &size)
    : wxSelectablePane(parent, id, pos, size), color(paneColor) {
}

void wxColorPane::DrawContent(wxGraphicsContext *gc, const wxRect &rect, const int roundness) const {
    //wxSelectablePane::DrawContent(gc, rect, roundress);
    gc->SetPen(wxPen(color));
    gc->SetBrush(wxBrush(color));

    gc->DrawRoundedRectangle(rect.GetX(), rect.GetY(), rect.GetWidth(), rect.GetHeight(), roundness);
}
