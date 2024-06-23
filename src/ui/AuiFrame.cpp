//
// Created by Dmitry Velychko on 23.06.2024.
//

#include "../../include/ui/AuiFrame.h"

AuiFrame::AuiFrame(wxWindow *parent, const wxString &title)
    : wxFrame(parent, wxID_ANY, title, wxDefaultPosition,
              wxWindow::FromDIP(wxSize(800, 600), nullptr)) {

}

void AuiFrame::OnQuit(wxCommandEvent &event) {
    Close(true);
}

void AuiFrame::OnIdle(wxIdleEvent &event) {
    event.Skip();
}

AuiFrame::~AuiFrame() = default;
