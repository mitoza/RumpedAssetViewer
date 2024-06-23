//
// Created by Dmitry Velychko on 23.06.2024.
//

#include "../../../include/ui/samples/TreeCtrlComboPopup.h"

wxBEGIN_EVENT_TABLE(TreeCtrlComboPopup, wxTreeCtrl)
                EVT_MOTION(TreeCtrlComboPopup::OnMouseMove)
// NOTE: Left down event is used instead of left up right now
//       since MSW wxTreeCtrl doesn't seem to emit left ups
//       consistently.
                EVT_LEFT_DOWN(TreeCtrlComboPopup::OnMouseClick)
wxEND_EVENT_TABLE()