//
// Created by Dmitry Velychko on 23.06.2024.
//

#include "../../../include/ui/samples/wxSizeReportCtrl.h"

wxBEGIN_EVENT_TABLE(wxSizeReportCtrl, wxControl)
                EVT_PAINT(wxSizeReportCtrl::OnPaint)
                EVT_SIZE(wxSizeReportCtrl::OnSize)
                EVT_ERASE_BACKGROUND(wxSizeReportCtrl::OnEraseBackground)
wxEND_EVENT_TABLE()