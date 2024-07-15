#include <ImGui/imgui_internal.h>
#include "FlowgraphTab.h"
#include "FlowgraphWindow.h"
#include "Flowgraph.h"

void FGE::FlowgraphTab::ShowTab(ImGuiDockNode* pDockNode)
{
    bool drawTab = true;

    if (ImGui::Begin(m_TabName.c_str(), &drawTab))
    {
        if (m_bFirstDraw)
        {
            // Dock the window to the node editor
            ImGui::DockContextQueueDock(ImGui::GetCurrentContext(), pDockNode->HostWindow,
                pDockNode->CentralNode, ImGui::GetCurrentWindow(), ImGuiDir_None, 1.0f, false);
        }

        m_pWindow->SetCurrentTab(this);
        ShowContents();
    }

    ImGui::End();

    if (!drawTab)
    {
        // TODO 2023-08-13: Show a pop-up to ask if the user wants to close the tab
    }
}

void FGE::FlowgraphTab::ShowContents()
{
    if (!m_bShowNodeList)
    {
        ShowNodeList();
        ImGui::SameLine();
    }

    ImGui::BeginGroup();
    ShowToolbar();
    ShowGraph();
    ImGui::EndGroup();

    m_pFG->update();
}

void FGE::FlowgraphTab::ShowNodeList()
{
    if (ImGui::BeginChild("Node List", ImVec2(ImGui::GetContentRegionAvail().x * 0.2f, 0), false))
    {
        ImGui::Text("Node List");
        ImGui::Separator();

        if (ImGui::BeginTable("Node List", 2, 0, ImGui::GetContentRegionAvail()))
        {
            ImGui::TableSetupColumn("ID", ImGuiTableColumnFlags_WidthFixed);
            ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthFixed);

            for (auto& node : m_pFG->m_Nodes)
            {
                ImGui::TableNextRow();
                ImGui::TableSetColumnIndex(0);
                if (ImGui::Selectable(std::to_string(node.second.ID).c_str(),
                    ImNodes::IsNodeSelected(node.second.ID), ImGuiSelectableFlags_SpanAllColumns))
                {
                    if ((ImGui::IsKeyDown(ImGui::GetKeyIndex(ImGuiKey_LeftShift)) ||
                        ImGui::IsKeyDown(ImGui::GetKeyIndex(ImGuiKey_RightShift))))
                    {
                        if (ImNodes::IsNodeSelected(node.second.ID))
                        {
                            const int num_selected = ImNodes::NumSelectedNodes();
                            if (num_selected > 0)
                            {
                                static std::vector<int> selected_nodes;
                                selected_nodes.resize(static_cast<size_t>(num_selected));
                                ImNodes::GetSelectedNodes(selected_nodes.data());
                                ImNodes::ClearNodeSelection();
                                for (int i = 0; i < num_selected; ++i)
                                {
                                    if (selected_nodes[i] != node.second.ID)
                                    {
                                        ImNodes::SelectNode(selected_nodes[i]);
                                    }
                                }
                            }
                        }
                        else
                        {
                            ImNodes::SelectNode(node.second.ID);
                        }
                    }
                    else
                    {
                        if (ImNodes::NumSelectedNodes() >= 1)
                        {
                            ImNodes::ClearNodeSelection();
                            ImNodes::SelectNode(node.second.ID);
                        }
                        else
                        {
                            if (ImNodes::IsNodeSelected(node.second.ID))
                            {
                                ImNodes::ClearNodeSelection();
                            }
                            else
                            {
                                ImNodes::SelectNode(node.second.ID);
                            }
                        }
                    }
                }
                if (ImGui::IsItemClicked(ImGuiMouseButton_Left) &&
                    ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
                {
                    ImNodes::EditorContextMoveToNode(node.second.ID);
                }
                ImGui::TableSetColumnIndex(1);
                ImGui::Text("%s", node.second.Name.c_str());
            }
            ImGui::EndTable();
        }

        //if(ImGui::BeginTable("Command History", 2, 0, {0, 200})) {
        //    ImGui::TableSetupColumn("Command", ImGuiTableColumnFlags_WidthFixed);
        //    ImGui::TableSetupColumn("Time", ImGuiTableColumnFlags_WidthFixed);
        //    ImGui::TableHeadersRow();
        //    /*for (auto& command : m_CommandHistory) {
        //        ImGui::TableNextRow();
        //        ImGui::TableSetColumnIndex(0);
        //        ImGui::Text("%lld", std::get<Node>(command.m_StoredObject).ID);
        //        ImGui::TableSetColumnIndex(1);
        //        ImGui::Text("%d", command.m_Operation);
        //    }*/
        //    ImGui::EndTable();
        //}
    }
    ImGui::EndChild();
    ImGui::SameLine();
}

void FGE::FlowgraphTab::ShowToolbar()
{
    const ImVec2 toolbarItemSize{ 30, 30 };

    if (ImGui::BeginChild("Toolbar", ImVec2(ImGui::GetContentRegionAvail().x, toolbarItemSize.y),
        false, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse))
    {
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0));

        if (ImGui::Button(ICON_MD_MENU "##Menu", toolbarItemSize))
            ImGui::OpenPopup("Toolbar Menu");

        if (ImGui::IsItemHovered())
            ImGui::SetTooltip("Menu");

        ImGui::SameLine();

        if (!m_bShowNodeList)
        {
            if (ImGui::Button(ICON_MD_ARROW_FORWARD "##NodeList", toolbarItemSize))
                m_bShowNodeList = true;

            if (ImGui::IsItemHovered())
                ImGui::SetTooltip("Show Node List");
        }
        else
        {
            if (ImGui::Button(ICON_MD_ARROW_BACK "##NodeList", toolbarItemSize))
                m_bShowNodeList = false;

            if (ImGui::IsItemHovered())
                ImGui::SetTooltip("Hide Node List");
        }

        ImGui::SameLine();

        if (ImGui::Button(ICON_MD_UNDO "##Undo", toolbarItemSize))
        {
            //            undo();
        }

        if (ImGui::IsItemHovered())
            ImGui::SetTooltip("Undo");

        ImGui::SameLine();

        if (ImGui::Button(ICON_MD_REDO "##Redo", toolbarItemSize))
        {
            //            redo();
        }

        if (ImGui::IsItemHovered())
            ImGui::SetTooltip("Undo");

        ImGui::SameLine();

        if (ImGui::Button(ICON_MD_SAVE "##SaveXml", toolbarItemSize))
            saveXML();

        if (ImGui::IsItemHovered())
            ImGui::SetTooltip("Save");

        ImGui::SameLine();

        if (ImGui::Button(ICON_MD_CENTER_FOCUS_WEAK "##ResetPan", toolbarItemSize))
        {
            m_bResetPan = true;
            m_ResetPos = { 0, 0 };
        }

        if (ImGui::IsItemHovered())
            ImGui::SetTooltip("Reset Pan");

        ImGui::PopStyleColor();

        if (ImGui::BeginPopup("Toolbar Menu"))
        {
            if (ImGui::MenuItem("Save"))
                saveXML();

            if (ImGui::MenuItem("Save As"))
            {
                //            saveAs();
            }

            if (ImGui::MenuItem("Load"))
            {
                //            load();
            }

            ImGui::Separator();

            ImGui::MenuItem("Show Node List", nullptr, &m_bShowNodeList);
            ImGui::Separator();

            if (ImGui::BeginMenu("Graph Tokens", !m_pFG->m_Tokens.empty()))
            {
                for (auto& token : m_pFG->m_Tokens)
                    ImGui::MenuItem(token.second.m_Name.c_str());

                ImGui::EndMenu();
            }

            ImGui::EndPopup();
        }
    }
}

void FGE::FlowgraphTab::ShowGraph()
{
    ImNodes::EditorContextSet(m_pFG->m_Context);
    ImNodes::BeginNodeEditor();
    ImNodes::MiniMap(0.25f, ImNodesMiniMapLocation_TopRight);

    if (m_bResetPan)
    {
        ImNodes::EditorContextResetPanning({ 0, 0 });
        m_bResetPan = false;
    }

    for (auto& node : m_pFG->m_Nodes)
    {
        node.second.draw();
    }

    for (auto& edge : m_pFG->m_Edges)
    {
        edge.second.draw();
    }

    if (ImNodes::IsEditorHovered() && ImGui::IsMouseClicked(ImGuiMouseButton_Right))
    {
        m_pWindow->OpenNodeInfoPopup();
    }

    ImNodes::EndNodeEditor();
}
