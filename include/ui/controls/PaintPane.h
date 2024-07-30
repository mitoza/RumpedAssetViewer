//
// Created by mito on 09.07.2024.
//

#ifndef PAINTPANE_H
#define PAINTPANE_H

#include "wx/wx.h"
#include "wx/event.h"
#include "vector"
#include "map"
#include "../Config.h"

class PaintPane : public wxWindow {
    const char colorKeys[63] = "._-$&()*+!abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int _width = 32;
    int _height = 32;
    float cellSize = 5;
    wxPoint startPoint = {0, 0};
    wxPoint mousePrevPoint = {-1, -1};
    std::map<char, wxColor> colors;
    std::vector<char> data;
    char currentColor = '.';

public:
    PaintPane(wxWindow *parent, wxWindowID id, const wxPoint &pos = wxDefaultPosition,
              const wxSize &size = wxDefaultSize);

    void OnPaint(wxPaintEvent &event);

    void OnSize(wxSizeEvent &event);

    wxSize GetMinSize() const override;

    unsigned int GetWidth() const;

    unsigned int GetHeight() const;

    void GetColorKeys(std::vector<char> &colorKeys) const;

    wxColor GetColor(char colorKey);

    unsigned int GetColorsSize();


    void OnMouse(wxMouseEvent &mouseEvent);

    void Reset();

    void AddColor();

    void UpdateColor(char colorKey, wxColor &color);

    void SetColor(char colorKey);

    char GetCurrentColor();

    unsigned char *GetData();
    wxImage *GetImage();

    //void SetBitmap(wxBitmap &bitmap);

protected:
    virtual void DrawGrid(wxGraphicsContext *gc, const wxRect &rect) const;

private:
    float GetCellSize() const;

    wxPoint GetStartPoint() const;

};

class PaintChangedEvent : public wxEvent {
    wxPoint position;
    char colorKey;
public:
    PaintChangedEvent(wxEventType eventType, int winId, wxPoint pos, char ckey)
            : wxEvent(winId, eventType), position(pos), colorKey(ckey) {}

    [[nodiscard]] wxEvent *Clone() const override {
        return new PaintChangedEvent(*this);
    }

    [[nodiscard]] wxPoint GetPosition() const { return position; }

    [[nodiscard]] char GetColorKey() const { return colorKey; }

};

wxDECLARE_EVENT(EVT_PAINT_CHANGED, PaintChangedEvent);


#endif //PAINTPANE_H
