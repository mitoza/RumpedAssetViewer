//
// Created by Dmitry Velychko on 23.06.2024.
//

#ifndef ASSETVIEWER_TREECTRLCOMBOPOPUP_H
#define ASSETVIEWER_TREECTRLCOMBOPOPUP_H


#include "wx/wxprec.h"
#include "wx/wx.h"
#include "wx/image.h"
#include "wx/combo.h"
#include "wx/odcombo.h"
#include "wx/treectrl.h"

class TreeCtrlComboPopup : public wxTreeCtrl, public wxComboPopup {
public:

    virtual void Init() override {
    }

    virtual ~TreeCtrlComboPopup() {
        if (!m_isBeingDeleted) {
            wxMessageBox("error wxTreeCtrl::Destroy() was not called");
        }
        SendDestroyEvent();
    }

    virtual bool Create(wxWindow *parent) override {
        return wxTreeCtrl::Create(parent, 1,
                                  wxPoint(0, 0), wxDefaultSize,
                                  wxTR_DEFAULT_STYLE | wxTR_HIDE_ROOT | wxSIMPLE_BORDER);
    }

    virtual void OnShow() {
        // make sure selected item is visible
        if (m_value.IsOk())
            EnsureVisible(m_value);
    }

    virtual wxSize GetAdjustedSize(int minWidth,
                                   int WXUNUSED(prefHeight),
                                   int maxHeight) override {
        return wxSize(wxMax(300, minWidth), wxMin(250, maxHeight));
    }

    virtual wxWindow *GetControl() override { return this; }

    // Needed by SetStringValue
    wxTreeItemId FindItemByText(wxTreeItemId parent, const wxString &text) {
        wxTreeItemIdValue cookie;
        wxTreeItemId child = GetFirstChild(parent, cookie);
        while (child.IsOk()) {
            if (GetItemText(child) == text) {
                return child;
            }
            if (ItemHasChildren(child)) {
                wxTreeItemId found = FindItemByText(child, text);
                if (found.IsOk())
                    return found;
            }
            child = GetNextChild(parent, cookie);
        }
        return wxTreeItemId();
    }

    virtual void SetStringValue(const wxString &s) override {
        wxTreeItemId root = GetRootItem();
        if (!root.IsOk())
            return;

        wxTreeItemId found = FindItemByText(root, s);
        if (found.IsOk()) {
            m_value = m_itemHere = found;
            wxTreeCtrl::SelectItem(found);
        }
    }

    virtual wxString GetStringValue() const override {
        if (m_value.IsOk())
            return wxTreeCtrl::GetItemText(m_value);
        return wxEmptyString;
    }

    //
    // Popup event handlers
    //

    // Mouse hot-tracking
    void OnMouseMove(wxMouseEvent &event) {
        int resFlags;
        wxTreeItemId itemHere = HitTest(event.GetPosition(), resFlags);
        if (itemHere.IsOk() && (resFlags & wxTREE_HITTEST_ONITEMLABEL)) {
            wxTreeCtrl::SelectItem(itemHere, true);
            m_itemHere = itemHere;
        }
        event.Skip();
    }

    // On mouse left, set the value and close the popup
    void OnMouseClick(wxMouseEvent &event) {
        int resFlags;
        wxTreeItemId itemHere = HitTest(event.GetPosition(), resFlags);
        if (itemHere.IsOk() && (resFlags & wxTREE_HITTEST_ONITEMLABEL)) {
            m_itemHere = itemHere;
            m_value = itemHere;
            Dismiss();
            // TODO: Send event
        }
        event.Skip();
    }

protected:

    wxTreeItemId m_value; // current item index
    wxTreeItemId m_itemHere; // hot item in popup

private:
wxDECLARE_EVENT_TABLE();
};


#endif //ASSETVIEWER_TREECTRLCOMBOPOPUP_H
