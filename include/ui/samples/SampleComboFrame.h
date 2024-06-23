//
// Created by Dmitry Velychko on 23.06.2024.
//

#ifndef ASSETVIEWER_SAMPLECOMBOFRAME_H
#define ASSETVIEWER_SAMPLECOMBOFRAME_H

#include "wx/wxprec.h"
#include "wx/wx.h"
#include "wx/image.h"
#include "wx/combo.h"
#include "wx/odcombo.h"


class SampleComboFrame : public wxFrame {
    // any class wishing to process wxWidgets events must use this macro
wxDECLARE_EVENT_TABLE();
public:
    // ctor and dtor
    SampleComboFrame(wxWindow *parent, const wxString &title);

    ~SampleComboFrame();

    // event handlers (these functions should _not_ be virtual)
    void OnQuit(wxCommandEvent &event);

    void OnAbout(wxCommandEvent &event);

    void OnShowComparison(wxCommandEvent &event);

    // log wxComboCtrl events
    void OnComboBoxUpdate(wxCommandEvent &event);

    void OnIdle(wxIdleEvent &event);


protected:
    wxTextCtrl *m_logWin;
    wxLog *m_logOld;

    // Common list of items for all dialogs.
    wxArrayString m_arrItems;

};

enum {
    ComboCtrl_Compare = wxID_HIGHEST,
    // menu items
    ComboCtrl_Quit = wxID_EXIT,

    // it is important for the id corresponding to the "About" command to have
    // this standard value as otherwise it won't be handled properly under Mac
    // (where it is special and put into the "Apple" menu)
    ComboCtrl_About = wxID_ABOUT
};

class wxComboCtrlWithCustomPopupAnim : public wxComboCtrl {
protected:
    virtual bool AnimateShow(const wxRect &rect, int WXUNUSED(flags)) override {
        wxWindow *win = GetPopupWindow();
        win->SetSize(rect);
        win->Raise();  // This is needed
        win->ShowWithEffect(wxSHOW_EFFECT_BLEND);
        return true;
    }
};

// ----------------------------------------------------------------------------
// wxComboCtrl with entirely custom button action (opens file dialog)
// ----------------------------------------------------------------------------

class wxFileSelectorCombo : public wxComboCtrl {
public:
    wxFileSelectorCombo() : wxComboCtrl() { Init(); }

    wxFileSelectorCombo(wxWindow *parent,
                        wxWindowID id = wxID_ANY,
                        const wxString &value = wxEmptyString,
                        const wxPoint &pos = wxDefaultPosition,
                        const wxSize &size = wxDefaultSize,
                        long style = 0,
                        const wxValidator &validator = wxDefaultValidator,
                        const wxString &name = wxComboBoxNameStr)
            : wxComboCtrl() {
        Init();
        Create(parent, id, value,
               pos, size,
                // Style flag wxCC_STD_BUTTON makes the button
                // behave more like a standard push button.
               style | wxCC_STD_BUTTON,
               validator, name);

#ifdef wxHAS_SVG
        SetButtonBitmaps(wxBitmapBundle::FromSVGFile("three-dots.svg", wxSize(16, 16)), true);
#endif
    }

    virtual void OnButtonClick() override {
        // Show standard wxFileDialog on button click
        wxFileDialog dlg(this,
                         "Choose File",
                         wxEmptyString,
                         GetValue(),
                         "All files (*.*)|*.*",
                         wxFD_OPEN);

        if (dlg.ShowModal() == wxID_OK) {
            SetValue(dlg.GetPath());
        }
    }

    // Implement empty DoSetPopupControl to prevent assertion failure.
    virtual void DoSetPopupControl(wxComboPopup * WXUNUSED(popup)) override {
    }

private:
    void Init() {
        // Initialize member variables here
    }
};

// ----------------------------------------------------------------------------
// wxOwnerDrawnComboBox with custom paint list items
// ----------------------------------------------------------------------------

class wxPenStyleComboBox : public wxOwnerDrawnComboBox {
public:
    void OnDrawItem(wxDC &dc,
                            const wxRect &rect,
                            int item,
                            int flags) const override {
        if (item == wxNOT_FOUND)
            return;

        wxRect r(rect);
        r.Deflate(3);
        r.height -= 2;

        wxPenStyle penStyle = wxPENSTYLE_SOLID;
        if (item == 1)
            penStyle = wxPENSTYLE_TRANSPARENT;
        else if (item == 2)
            penStyle = wxPENSTYLE_DOT;
        else if (item == 3)
            penStyle = wxPENSTYLE_LONG_DASH;
        else if (item == 4)
            penStyle = wxPENSTYLE_SHORT_DASH;
        else if (item == 5)
            penStyle = wxPENSTYLE_DOT_DASH;
        else if (item == 6)
            penStyle = wxPENSTYLE_BDIAGONAL_HATCH;
        else if (item == 7)
            penStyle = wxPENSTYLE_CROSSDIAG_HATCH;
        else if (item == 8)
            penStyle = wxPENSTYLE_FDIAGONAL_HATCH;
        else if (item == 9)
            penStyle = wxPENSTYLE_CROSS_HATCH;
        else if (item == 10)
            penStyle = wxPENSTYLE_HORIZONTAL_HATCH;
        else if (item == 11)
            penStyle = wxPENSTYLE_VERTICAL_HATCH;

        wxPen pen(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWTEXT), 3, penStyle);

        // Get text colour as pen colour
        dc.SetPen(pen);

        if (!(flags & wxODCB_PAINTING_CONTROL)) {
            dc.DrawText(GetString(item),
                        r.x + 3,
                        (r.y + 0) + ((r.height / 2) - dc.GetCharHeight()) / 2
            );

            dc.DrawLine(r.x + 5, r.y + ((r.height / 4) * 3), r.x + r.width - 5, r.y + ((r.height / 4) * 3));
        } else {
            dc.DrawLine(r.x + 5, r.y + r.height / 2, r.x + r.width - 5, r.y + r.height / 2);
        }
    }

    void OnDrawBackground(wxDC &dc, const wxRect &rect,
                                  int item, int flags) const override {

        // If item is selected or even, or we are painting the
        // combo control itself, use the default rendering.
        if ((flags & (wxODCB_PAINTING_CONTROL | wxODCB_PAINTING_SELECTED)) ||
            (item & 1) == 0) {
            wxOwnerDrawnComboBox::OnDrawBackground(dc, rect, item, flags);
            return;
        }

        // Otherwise, draw every other background with different colour.
        //wxColour bgCol = wxSystemSettings::SelectLightDark(wxColour(240, 240, 250), wxColour(48, 48, 64));

        //dc.SetBrush(wxBrush(bgCol));
        //dc.SetPen(wxPen(bgCol));
        //dc.DrawRectangle(rect);
    }

    wxCoord OnMeasureItem(size_t item) const override {
        // Simply demonstrate the ability to have variable-height items
        return FromDIP(item & 1 ? 36 : 24);
    }

    wxCoord OnMeasureItemWidth(size_t WXUNUSED(item)) const override {
        return -1; // default - will be measured from text width
    }
};

#endif //ASSETVIEWER_SAMPLECOMBOFRAME_H
