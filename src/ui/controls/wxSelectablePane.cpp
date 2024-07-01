//
// Created by mito on 01.07.2024.
//

#include "../../../include/ui/controls/wxSelectablePane.h"

#include "../../../cmake-build-release/_deps/wx_widgets-src/include/wx/graphics.h"


wxSelectablePane::wxSelectablePane(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size)
    : wxWindow(parent, id, pos, size, wxFULL_REPAINT_ON_RESIZE){
    this->SetBackgroundStyle(wxBG_STYLE_PAINT);

    Bind(wxEVT_PAINT, &wxSelectablePane::OnPaint, this);
}

wxSize wxSelectablePane::DoGetBestSize() const {
    return FromDIP(wxSize(42, 42));
}

void wxSelectablePane::DrawContent(wxGraphicsContext *gc, const wxRect &rect, int roundress) const {
}

void wxSelectablePane::OnPaint(wxPaintEvent &event) {
    wxAutoBufferedPaintDC dc(this);
    //dc.SetBackground(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    dc.SetBackground(wxBrush(this->GetParent()->GetBackgroundColour()));
    dc.Clear();

    auto gc = wxGraphicsContext::Create(dc);
    if (gc) {
        wxRect selectionRect(0, 0, this->GetSize().GetWidth(), this->GetSize().GetHeight());
        selectionRect.Deflate(FromDIP(1));

        wxRect contentRect = selectionRect;
        contentRect.Deflate(FromDIP(2));

        const auto roundness = FromDIP(2);

        DrawContent(gc, contentRect, roundness);

        if (selected) {
            gc->SetPen(wxSystemSettings::GetAppearance().IsDark() ? *wxWHITE_PEN : *wxBLACK_PEN);
            gc->SetBrush(*wxTRANSPARENT_BRUSH);

            gc->DrawRoundedRectangle(selectionRect.GetX(), selectionRect.GetY(), selectionRect.GetWidth(), selectionRect.GetHeight(), roundness);
        }

        delete gc;
    }

}

