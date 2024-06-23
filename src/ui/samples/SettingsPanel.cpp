//
// Created by Dmitry Velychko on 23.06.2024.
//

#include "../../../include/ui/samples/SettingsPanel.h"

wxBEGIN_EVENT_TABLE(SettingsPanel, wxPanel)
                EVT_SPINCTRL(ID_PaneBorderSize, SettingsPanel::OnPaneBorderSize)
                EVT_SPINCTRL(ID_SashSize, SettingsPanel::OnSashSize)
                EVT_SPINCTRL(ID_CaptionSize, SettingsPanel::OnCaptionSize)
                EVT_BUTTON(ID_BackgroundColor, SettingsPanel::OnSetColor)
                EVT_BUTTON(ID_SashColor, SettingsPanel::OnSetColor)
                EVT_BUTTON(ID_InactiveCaptionColor, SettingsPanel::OnSetColor)
                EVT_BUTTON(ID_InactiveCaptionGradientColor, SettingsPanel::OnSetColor)
                EVT_BUTTON(ID_InactiveCaptionTextColor, SettingsPanel::OnSetColor)
                EVT_BUTTON(ID_ActiveCaptionColor, SettingsPanel::OnSetColor)
                EVT_BUTTON(ID_ActiveCaptionGradientColor, SettingsPanel::OnSetColor)
                EVT_BUTTON(ID_ActiveCaptionTextColor, SettingsPanel::OnSetColor)
                EVT_BUTTON(ID_BorderColor, SettingsPanel::OnSetColor)
                EVT_BUTTON(ID_GripperColor, SettingsPanel::OnSetColor)
wxEND_EVENT_TABLE()