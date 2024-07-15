//
// Created by theli on 9/25/2022.
//
#include <Prey/CryCore/Platform/CryWindows.h>
#include <Prey/CrySystem/System.h>
#include "FlowgraphEditor.h"
#include <Prey/CryAction/Ark/IArkGlobalActionManager.h>
#include <Prey/CryAction/flowsystem/Nodes/FlowBaseNode.h>
#include <Prey/CryAction/flowsystem/flowsystem.h>
#include "ImGui/imgui_stdlib.h"
#include "ImGui/imgui_internal.h"
#include "App/AppImGui.h"
#include "PreditorFlowgraph.h"

FlowgraphEditor::FlowgraphEditor(FGE::PreditorFlowgraph* pMainFG)
{
    m_pMainFG = pMainFG;
    SetFlags(ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking);
    ImNodes::CreateContext();
}

FlowgraphEditor::~FlowgraphEditor()
{
    ImNodes::DestroyContext();
}

void FlowgraphEditor::ShowContents()
{
    ImGui::SetNextWindowSize(ImVec2(800, 500), ImGuiCond_FirstUseEver);
    ImGuiID dockspaceID = ImGui::GetID(m_DockspaceName.c_str());

    constexpr ImGuiDockNodeFlags dockspace_flags =
        /*ImGuiDockNodeFlags_PassthruCentralNode |*/ ImGuiDockNodeFlags_NoWindowMenuButton;

    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Load File"))
            {
            }
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }
    ImGui::DockSpace(dockspaceID, ImVec2(0.0f, 0.0f), dockspace_flags);
    if (m_IsFirstShow)
    {
        m_IsFirstShow = false;

        ImGui::DockBuilderRemoveNode(dockspaceID); // clear any previous layout
        ImGui::DockBuilderAddNode(dockspaceID, dockspace_flags | ImGuiDockNodeFlags_DockSpace);
        m_DockNode = ImGui::DockBuilderGetNode(dockspaceID);
        ImGui::DockBuilderSetNodeSize(dockspaceID, ImGui::GetWindowSize());

        // split the dockspace into 2 nodes -- DockBuilderSplitNode takes in the following args in the
        // following order
        //   window ID to split, direction, fraction (between 0 and 1), the final two setting let's us
        //   choose which id we want (which ever one we DON'T set as NULL, will be returned by the function)
        //                                                              out_id_at_dir is the id of the node
        //                                                              in the direction we specified
        //                                                              earlier, out_id_at_opposite_dir is
        //                                                              in the opposite direction
        auto dock_id_right =
            ImGui::DockBuilderSplitNode(dockspaceID, ImGuiDir_Right, 0.2f, nullptr, &dockspaceID);
        auto dock_id_up =
            ImGui::DockBuilderSplitNode(dock_id_right, ImGuiDir_Up, 0.3f, nullptr, &dock_id_right);

        // we now dock our windows into the docking node we made above
        ImGui::DockBuilderDockWindow("Node Properties", dock_id_up);
        ImGui::DockBuilderDockWindow("Nodes", dock_id_right);
        ImGui::DockBuilderDockWindow("Graphs", dock_id_right);
        ImGui::DockBuilderFinish(dockspaceID);
    }

    // UGLY HACK
    // End the window - begin called in ManagedWindow::UpdateWindow
    ImGui::End();

    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 2.0f);
    ImGui::PushID(GetFullTitle().c_str());
    DrawNodeGraphList();
    DrawNodeProperties();
    DrawNodeEditorTabs();
    ImGui::PopID();
    ImGui::PopStyleVar();

    // UGLY HACK: Begin a dummy window, ManagedWindow::UpdateWindow will End it
    // TODO 2023-07-23: Fix this shit
    ImGui::Begin("UGLY!!");
}

void FlowgraphEditor::DrawNodeEditorTabs()
{
    for (auto& graph : m_FlowGraphs)
    {
        graph->drawTab();
    }
    if (m_bShowNodePopup)
    {
        ImGui::OpenPopup("NodeInfo");
        m_bShowNodePopup = false;
    }
    if (ImGui::BeginPopup("NodeInfo"))
    {
        if (ImGui::MenuItem("Reset Pan"))
        {
            p_CurrentFlowGraph->resetPanning({ 0, 0 });
        }
        if (ImGui::BeginMenu("Add Nodes"))
        {
            for (auto& category : Node::CategoryNames)
            {
                if (ImGui::BeginMenu(category.second))
                {
                    for (auto& prototypeNode : m_pMainFG->GetPrototypes())
                    {
                        if (prototypeNode.second->Category == category.first)
                        {
                            if (ImGui::MenuItem(("Add " + prototypeNode.second->Class).c_str()))
                            {
                                p_CurrentFlowGraph->addNode(prototypeNode.first, prototypeNode.second);
                            }
                        }
                    }
                    ImGui::EndMenu();
                }
            }
            ImGui::EndMenu();
        }
        ImGui::EndPopup();
    }
}

void FlowgraphEditor::DrawNodeGraphList()
{
    if (ImGui::Begin("Nodes"))
    {
        static ImGuiTextFilter filter;
        filter.Draw("Filter");

        if (ImGui::BeginTable("Nodes Table", 1, ImGuiTableFlags_ScrollY,
                              ImVec2(0, ImGui::GetContentRegionAvail().y * 0.95f)))
        {
            // TODO 2023-07-23: Cache those so they are not refreshed every frame
            std::list<std::shared_ptr<PrototypeNode>> filteredNodes;
            std::list<PrototypeNode::nodeCategory> categories;

            for (auto& node : m_pMainFG->GetPrototypes())
            {
                if (filter.PassFilter(node.second->Class.c_str()))
                {
                    filteredNodes.emplace_back(node.second);
                    if (std::find(categories.begin(), categories.end(), node.second->Category) == categories.end())
                    {
                        categories.emplace_back(node.second->Category);
                    }
                }
            }

            for (auto& Category : Node::CategoryNames)
            {
                if (std::find(categories.begin(), categories.end(), Category.first) == categories.end())
                {
                    continue;
                }
                ImGui::TableNextRow();
                ImGui::TableNextColumn();
                ImGui::PushStyleColor(ImGuiCol_HeaderHovered, Node::GetCategoryColor(Category.first).operator ImU32());
                ImGuiTreeNodeFlags treeNodeFlags = ImGuiTreeNodeFlags_CollapsingHeader;
                if (categories.size() < (int)PrototypeNode::nodeCategory::COUNT - 4)
                {
                    treeNodeFlags |= ImGuiTreeNodeFlags_DefaultOpen;
                }
                if (ImGui::TreeNodeEx(Category.second, treeNodeFlags) ||
                    categories.size() < (int)PrototypeNode::nodeCategory::COUNT - 4)
                {
                    for (auto& ProtoNode : filteredNodes)
                    {
                        if (ProtoNode->Category == Category.first)
                        {
                            if (ImGui::Selectable(ProtoNode->Class.c_str()))
                            {
                                if (p_CurrentFlowGraph != nullptr)
                                {
                                    p_CurrentFlowGraph->addNode(ProtoNode->Class, ProtoNode);
                                }
                            }
                            if (ImGui::IsItemHovered() && GImGui->HoveredIdTimer > 0.5f)
                            {
                                ImGui::BeginTooltip();
                                ImGui::Text("%s", ProtoNode->Class.c_str());
                                ImGui::EndTooltip();
                            }
                        }
                    }
                    ImGui::PopStyleColor();
                }
                else
                {
                    ImGui::PopStyleColor();
                }
            }

            ImGui::EndTable();
        }
    }

    ImGui::End();
}

void FlowgraphEditor::DrawNodeProperties()
{
    if (ImGui::Begin("Node Properties"))
    {
        if (p_CurrentFlowGraph != nullptr)
        {
            p_CurrentFlowGraph->drawSelectedNodeProperties();
        }
    }
    ImGui::End();
}
