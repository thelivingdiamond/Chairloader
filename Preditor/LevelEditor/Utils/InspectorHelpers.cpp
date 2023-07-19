#include "Utils/InspectorHelpers.h"

bool LevelEditor::Inspector::Begin(const char* name, ImGuiTreeNodeFlags flags)
{
    if (ImGui::CollapsingHeader(name, ImGuiTreeNodeFlags_DefaultOpen | flags))
    {
        ImGui::PushID(name);
        return true;
    }

    return false;
}

void LevelEditor::Inspector::End()
{
    ImGui::PopID();
}
