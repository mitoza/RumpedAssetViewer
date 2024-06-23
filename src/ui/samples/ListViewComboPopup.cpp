//
// Created by Dmitry Velychko on 23.06.2024.
//

#include "../../../include/ui/samples/ListViewComboPopup.h"

wxBEGIN_EVENT_TABLE(ListViewComboPopup, wxListView)
                EVT_MOTION(ListViewComboPopup::OnMouseMove)
// NOTE: Left down event is used instead of left up right now
//       since MSW wxListCtrl doesn't seem to emit left ups
//       consistently.
                EVT_LEFT_DOWN(ListViewComboPopup::OnMouseClick)
wxEND_EVENT_TABLE()
