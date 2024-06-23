//
// Created by Dmitry Velychko on 23.06.2024.
//

#ifndef ASSETVIEWER_LISTVIEWCOMBOPOPUP_H
#define ASSETVIEWER_LISTVIEWCOMBOPOPUP_H


#include "wx/wxprec.h"
#include "wx/wx.h"
#include "wx/image.h"
#include "wx/combo.h"
#include "wx/odcombo.h"
#include "wx/listctrl.h"

class ListViewComboPopup : public wxListView, public wxComboPopup {
public:

    virtual void Init() override {
        m_value = -1;
        m_itemHere = -1; // hot item in list
    }

    virtual bool Create(wxWindow *parent) override {
        return wxListView::Create(parent, 1,
                                  wxPoint(0, 0), wxDefaultSize,
                                  wxLC_LIST | wxLC_SINGLE_SEL |
                                  wxLC_SORT_ASCENDING | wxSIMPLE_BORDER);
    }

    virtual wxWindow *GetControl() override { return this; }

    virtual void SetStringValue(const wxString &s) override {
        int n = wxListView::FindItem(-1, s);
        if (n >= 0 && n < GetItemCount())
            wxListView::Select(n);
    }

    virtual wxString GetStringValue() const override {
        if (m_value >= 0)
            return wxListView::GetItemText(m_value);
        return wxEmptyString;
    }

    //
    // Popup event handlers
    //

    // Mouse hot-tracking
    void OnMouseMove(wxMouseEvent &event) {
        // Move selection to cursor if it is inside the popup

        int resFlags;
        int itemHere = HitTest(event.GetPosition(), resFlags);
        if (itemHere >= 0) {
            wxListView::Select(itemHere, true);
            m_itemHere = itemHere;
        }
        event.Skip();
    }

    // On mouse left, set the value and close the popup
    void OnMouseClick(wxMouseEvent & WXUNUSED(event)) {
        m_value = m_itemHere;
        // TODO: Send event
        //Dismiss();
    }

    //
    // Utilities for item manipulation
    //

    void AddSelection(const wxString &selstr) {
        wxListView::InsertItem(GetItemCount(), selstr);
    }

protected:

    int m_value; // current item index
    int m_itemHere; // hot item in popup

private:
wxDECLARE_EVENT_TABLE();
};


#endif //ASSETVIEWER_LISTVIEWCOMBOPOPUP_H
