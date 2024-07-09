//
// Created by mito on 09.07.2024.
//

#include "../../../include/ui/controls/PaintPane.h"

#include "../../../cmake-build-release/_deps/wx_widgets-src/include/wx/dcbuffer.h"
#include "../../../cmake-build-release/_deps/wx_widgets-src/include/wx/graphics.h"

PaintPane::PaintPane(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size)
    : wxWindow(parent, id, pos, size) {
    Reset();
    this->SetBackgroundStyle(wxBG_STYLE_PAINT);
    Bind(wxEVT_PAINT, &PaintPane::OnPaint, this);
    Bind(wxEVT_SIZE, &PaintPane::OnSize, this);
    Bind(wxEVT_LEFT_DOWN, &PaintPane::OnMouse, this);
    Bind(wxEVT_LEFT_UP, &PaintPane::OnMouse, this);
    Bind(wxEVT_MOTION, &PaintPane::OnMouse, this);
}

void PaintPane::OnPaint(wxPaintEvent &event) {
    //wxWindow::OnPaint(event);
    wxBufferedPaintDC dc(this);
    dc.SetBackground(wxBrush(wxColor(255, 255, 255)));
    dc.Clear();

    auto gc = wxGraphicsContext::Create(dc);
    if (!gc) return;
    const auto rect = wxRect(0, 0, GetSize().GetWidth(), GetSize().GetHeight());
    DrawGrid(gc, rect, GetCellSize());
}

void PaintPane::OnSize(wxSizeEvent &event) {
    Refresh();
    event.Skip();
}

wxSize PaintPane::GetMinSize() const {
    const auto minSize = std::min(_width * FromDIP(5), _height * FromDIP(5));
    return wxSize(minSize, minSize);
}

void PaintPane::OnMouse(wxMouseEvent &mouseEvent) {
    if (mouseEvent.LeftDown()) {
        std::cout << "x: " << (mouseEvent.GetX() / GetCellSize()) << std::endl;
    } else if (mouseEvent.LeftUp()) {
        std::cout << "y: " << (mouseEvent.GetY() / GetCellSize()) << std::endl;
    } else if (mouseEvent.Moving()) {
        //std::cout << "move" << std::endl;
    }
}

void PaintPane::Reset() {
    _width = 32;
    _height = 32;
    colors.clear();
    colors['.'] = wxColor(0, 120, 0);
    data.clear();
    data = std::vector(_width * _height, '.');
    data[5] = ' ';
    data[50] = ' ';
    data[500] = ' ';

}

void PaintPane::DrawGrid(wxGraphicsContext *gc, const wxRect &rect, const float cellSize) const {
    const auto start = GetStartPoint();
    for (int i = 0; i < _height; i++) {
        for (int j = 0; j < _width; j++) {
            char colorName = data.at(i * _width + j);
            if (colors.count(colorName) > 0) {
                wxColor color = colors.at(colorName);
                gc->SetBrush(wxBrush(colors.at(colorName)));
                gc->DrawRectangle(start.x + cellSize * j, start.y + cellSize * i, cellSize + 1, cellSize + 1);
            } else {
                gc->SetBrush(wxBrush(wxColor(255, 255, 255)));
                gc->DrawRectangle(start.x + cellSize * j, start.y + cellSize * i, cellSize + 1, cellSize + 1);
                gc->SetBrush(wxBrush(wxColor(0, 0, 0)));
                const auto *points = new wxPoint2DDouble[5]{
                    {start.x + cellSize * j, start.y + cellSize * i},
                    {start.x + cellSize * j + cellSize, start.y + cellSize * i + cellSize},
                    {start.x + cellSize * j, start.y + cellSize * i + cellSize},
                    {start.x + cellSize * j + cellSize, start.y + cellSize * i},
                    {start.x + cellSize * j, start.y + cellSize * i}
                };
                gc->DrawLines(5, points, wxWINDING_RULE);
                delete points;
            }
        }
    }
}

float PaintPane::GetCellSize() const {
    return std::min((float) GetSize().GetWidth() / (float) _width, (float) GetSize().GetHeight() / (float) _height);
}

wxPoint PaintPane::GetStartPoint() const {
    const auto cellSize = GetCellSize();
    return {
        static_cast<int>(GetSize().GetWidth() / 2 - (cellSize * _width) / 2),
        static_cast<int>(GetSize().GetHeight() / 2 - (cellSize * _height) / 2)
    };
}
