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
    DrawGrid(gc, rect);
}

void PaintPane::OnSize(wxSizeEvent &event) {
    cellSize = std::min((float) GetSize().GetWidth() / (float) _width, (float) GetSize().GetHeight() / (float) _height);
    startPoint = {
            static_cast<int>(GetSize().GetWidth() / 2 - (cellSize * _width) / 2),
            static_cast<int>(GetSize().GetHeight() / 2 - (cellSize * _height) / 2)
    };
    Refresh();
    event.Skip();
}

wxSize PaintPane::GetMinSize() const {
    const auto minSize = std::min(_width * FromDIP(5), _height * FromDIP(5));
    return wxSize(minSize, minSize);
}

void PaintPane::OnMouse(wxMouseEvent &mouseEvent) {
    int x = std::floor((static_cast<float>(mouseEvent.GetX() - startPoint.x) / cellSize));
    int y = std::floor((static_cast<float>(mouseEvent.GetY() - startPoint.y) / cellSize));
    if (x < 0 || x >= _width || y < 0 || y >= _height) {
        mouseEvent.Skip();
        return;
    }

    if (mouseEvent.LeftDown()) {
        mousePrevPoint = {x, y};
        data[y * _width + x] = currentColor;
        Refresh();
    } else if (mouseEvent.LeftUp()) {
        mousePrevPoint = {-1, -1};
    } else if (mouseEvent.Dragging()) {
        if (mousePrevPoint.x != -1 && mousePrevPoint.y != -1 && data[y * _width + x] != currentColor) {
            mousePrevPoint = {x, y};
            data[y * _width + x] = currentColor;
            Refresh();
        }
    }

}

void PaintPane::Reset() {
    _width = 32;
    _height = 32;
    colors.clear();
    colors['.'] = wxColor(0, 120, 0);
    data.clear();
    data = std::vector(_width * _height, ' ');
    data[5] = '.';
    data[50] = '.';
    data[500] = '.';
}

void PaintPane::DrawGrid(wxGraphicsContext *gc, const wxRect &rect) const {
    for (int i = 0; i < _height; i++) {
        for (int j = 0; j < _width; j++) {
            char colorName = data.at(i * _width + j);
            float cx = static_cast<float>(startPoint.x) + cellSize * static_cast<float>(j);
            float cy = static_cast<float>(startPoint.y) + cellSize * static_cast<float>(i);
            if (colors.count(colorName) > 0) {
                wxColor color = colors.at(colorName);
                gc->SetBrush(wxBrush(colors.at(colorName)));
                gc->DrawRectangle(cx, cy, cellSize + 1, cellSize + 1);
            } else {
                gc->SetBrush(wxBrush(wxColor(232, 232, 232)));
                gc->DrawRectangle(cx, cy, cellSize + 1, cellSize + 1);
                gc->SetBrush(wxBrush(wxColor(212, 212, 212)));
                const auto *points = new wxPoint2DDouble[7]{
                        {cx,                cy},
                        {cx + cellSize / 2, cy},
                        {cx + cellSize / 2, cy + cellSize},
                        {cx + cellSize,     cy + cellSize},
                        {cx + cellSize,     cy + cellSize / 2},
                        {cx,                cy + cellSize / 2},
                        {cx,                cy}
                };
                gc->DrawLines(7, points, wxWINDING_RULE);
                delete[] points;
            }
        }
    }
}

float PaintPane::GetCellSize() const {
    return cellSize;
}

wxPoint PaintPane::GetStartPoint() const {
    return startPoint;
}

void PaintPane::AddColor(const char colorKey, wxColour &color) {
    this->colors[colorKey] = color;
}

void PaintPane::UpdateColor(char colorKey, wxColour &color) {
    colors[colorKey] = color;
    Refresh();
}

void PaintPane::SetColor(const char colorKey) {
    if (colors.count(colorKey) > 0) {
        this->currentColor = colorKey;
    } else {
        this->currentColor = ' ';
    }
}

char PaintPane::GetCurrentColor() {
    return this->currentColor;
}

unsigned int PaintPane::GetWidth() const {
    return _width;
}

unsigned int PaintPane::GetHeight() const {
    return _height;
}

void PaintPane::GetColorKeys(std::vector<char> &colorKeys) const {
    for(auto & [colorKey, color] : colors) {
        colorKeys.push_back(colorKey);
    }
}

wxColor PaintPane::GetColor(char colorKey) {
    if (colors.count(colorKey) > 0) {
        return colors[colorKey];
    } else {
        return wxColor(0, 0, 0);
    }
}

unsigned int PaintPane::GetColorsSize() {
    return colors.size();
}

