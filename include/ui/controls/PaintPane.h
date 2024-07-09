//
// Created by mito on 09.07.2024.
//

#ifndef PAINTPANE_H
#define PAINTPANE_H

#include "wx/wx.h"
#include "vector"
#include "map"

class PaintPane : public wxWindow {
    unsigned int _width = 32;
    unsigned int _height = 32;
    std::map<char, wxColor> colors;
    std::vector<char> data;
    char selectedColor = '.';

public:
    PaintPane(wxWindow *parent, wxWindowID id, const wxPoint &pos = wxDefaultPosition,
              const wxSize &size = wxDefaultSize);

    void OnPaint(wxPaintEvent &event) override;
    void OnSize(wxSizeEvent &event);
    wxSize GetMinSize() const override;

    void OnMouse(wxMouseEvent &mouseEvent);
    void Reset();


protected:
    virtual void DrawGrid(wxGraphicsContext *gc, const wxRect &rect, float cellSize) const;

private:
    float GetCellSize() const;
    wxPoint GetStartPoint() const;

};


#endif //PAINTPANE_H
