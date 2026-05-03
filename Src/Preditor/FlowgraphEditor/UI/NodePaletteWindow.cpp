#include <cstdio>
#include <imgui_stdlib.h>
#include "NodePaletteWindow.h"
#include "../Registry/NodeRegistry.h"

FlowgraphEditor::NodePaletteWindow::NodePaletteWindow()
{
    SetTitle("Flowgraph Palette");
    SetPersistentID("FlowgraphPalette");
    SetDestroyOnClose(false);
    SetVisible(false);
}

FlowgraphEditor::NodePaletteWindow::~NodePaletteWindow()
{
}

void FlowgraphEditor::NodePaletteWindow::ShowContents()
{
    NodeRegistry& registry = NodeRegistry::Get();

    if (!registry.IsLoaded())
    {
        ImGui::TextDisabled("Waiting for engine flow system...");
        return;
    }

    ImGui::Text("Prototypes: %zu", registry.Size());
    ImGui::InputTextWithHint("##paletteFilter", "Filter (substring of class name)",
                             &m_Filter);

    for (const auto& [key, protos] : registry.Categories())
    {
        char header[160];
        std::snprintf(header, sizeof(header), "%s (%zu)###cat-%s",
                      FormatCategoryDisplay(key).c_str(), protos.size(),
                      key.empty() ? "_misc" : key.c_str());

        if (!ImGui::TreeNode(header))
            continue;

        for (const PrototypeNode* proto : protos)
        {
            if (!m_Filter.empty() &&
                proto->className.find(m_Filter) == std::string::npos)
            {
                continue;
            }

            ImGui::Selectable(proto->className.c_str());
            if (ImGui::BeginDragDropSource(ImGuiDragDropFlags_None))
            {
                // Send the class name (null-terminated) as payload.
                ImGui::SetDragDropPayload("FLOWGRAPH_PROTOTYPE",
                    proto->className.c_str(),
                    proto->className.size() + 1);
                ImGui::Text("+ %s", proto->className.c_str());
                ImGui::EndDragDropSource();
            }
            if (ImGui::IsItemHovered() && !proto->description.empty())
                ImGui::SetTooltip("%s", proto->description.c_str());
        }
        ImGui::TreePop();
    }
}
