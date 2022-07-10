#pragma once
#include "pch.h"
namespace ImGuiUtils {
    inline void RightAlignText(const char* text) {
        auto posX = (ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - ImGui::CalcTextSize(text).x
            - ImGui::GetScrollX());
        if (posX > ImGui::GetCursorPosX())
            ImGui::SetCursorPosX(posX);
    }
    inline void HelpMarker(const char* desc) {
        ImGui::TextDisabled("(?)");
        if (ImGui::IsItemHovered())
        {
            ImGui::BeginTooltip();
            ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
            ImGui::TextUnformatted(desc);
            ImGui::PopTextWrapPos();
            ImGui::EndTooltip();
        }
    }
    inline bool selectableRectangle(std::string text, float x_size, float y_size, ImColor color) {
        ImDrawList* draw_list = ImGui::GetWindowDrawList();
        ImVec2 screenPos = ImGui::GetCursorScreenPos();
        draw_list->AddRect(screenPos, ImVec2(screenPos.x + x_size, screenPos.y + y_size), color);
        ImVec2 textSize = ImGui::CalcTextSize(text.c_str());
        ImVec2 textPos = ImVec2(ImGui::GetCursorPos().x + x_size / 2 - textSize.x / 2, ImGui::GetCursorPos().y + y_size / 2 - textSize.y / 2);
        ImGui::SetCursorPos(textPos);
        return ImGui::Selectable(text.c_str(), false, ImGuiSelectableFlags_None, ImVec2(textSize.x + 5, textSize.y + 5));
    }
};