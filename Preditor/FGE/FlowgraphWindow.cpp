#include <ImGui/imgui_internal.h> // For Dockspace
#include "FlowgraphWindow.h"
#include "Node.h"
#include "PreditorFlowgraph.h"
#include "FlowgraphTab.h"

constexpr char DOCKSPACE[] = "Dockspace";
constexpr char WINDOW_MAIN[] = "Flowgraph Editor";
constexpr char WINDOW_PROPERTIES[] = "Node Properties";
constexpr char WINDOW_NODES[] = "Nodes";

FGE::FlowgraphWindow::FlowgraphWindow(PreditorFlowgraph* pFGE)
{
    m_pFGE = pFGE;
}

FGE::FlowgraphWindow::~FlowgraphWindow()
{
}

void FGE::FlowgraphWindow::SetVisible(bool state)
{
}

bool FGE::FlowgraphWindow::UpdateWindow()
{
    if (!m_bVisible)
        return true;

    ImGui::PushID("FGE");
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 2.0f);

    ShowMainWindow();
    ShowNodeList();
    ShowNodeProperties();
    ShowEditorTabs();

    ImGui::PopStyleVar();
    ImGui::PopID();

    return true;
}

void FGE::FlowgraphWindow::ShowMainWindow()
{
    constexpr ImGuiWindowFlags window_flags =
        ImGuiWindowFlags_MenuBar |
        ImGuiWindowFlags_NoDocking;

    constexpr ImGuiDockNodeFlags dockspace_flags =
        // ImGuiDockNodeFlags_PassthruCentralNode |
        ImGuiDockNodeFlags_NoWindowMenuButton;

    ImGui::SetNextWindowSize(ImVec2(800, 500), ImGuiCond_FirstUseEver);

    if (ImGui::Begin(WINDOW_MAIN, &m_bVisible, window_flags))
    {
        ImGuiID dockspaceId = m_DockSpaceId = ImGui::GetID(DOCKSPACE);
        ImGui::DockSpace(dockspaceId, ImVec2(0.0f, 0.0f), dockspace_flags);

        ShowMenuBar();

        // TODO 2023-08-13: Check if appearing first time ever, in session or after disappearing
        if (ImGui::IsWindowAppearing())
        {
            ImGui::DockBuilderRemoveNode(dockspaceId); // clear any previous layout
            ImGui::DockBuilderAddNode(dockspaceId, dockspace_flags | ImGuiDockNodeFlags_DockSpace);
            ImGui::DockBuilderSetNodeSize(dockspaceId, ImGui::GetWindowSize());

            // split the dockspace into 2 nodes -- DockBuilderSplitNode takes in the following args in the
            // following order
            //   window ID to split, direction, fraction (between 0 and 1)
            // 
            // the final two setting let's us choose which id we want
            // (which ever one we DON'T set as NULL, will be returned by the function)
            // 
            // out_id_at_dir is the id of the node in the direction we specified earlier,
            // out_id_at_opposite_dir is in the opposite direction
            ImGuiID dockIdRight = ImGui::DockBuilderSplitNode(dockspaceId, ImGuiDir_Right, 0.2f, nullptr, &dockspaceId);
            ImGuiID dockIdUp = ImGui::DockBuilderSplitNode(dockIdRight, ImGuiDir_Up, 0.3f, nullptr, &dockIdRight);

            // we now dock our windows into the docking node we made above
            ImGui::DockBuilderDockWindow(WINDOW_PROPERTIES, dockIdUp);
            ImGui::DockBuilderDockWindow(WINDOW_NODES, dockIdRight);
            ImGui::DockBuilderFinish(dockspaceId);
        }
    }

    ImGui::End();
}

void FGE::FlowgraphWindow::ShowMenuBar()
{
    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Load File"))
            {
                // TODO 2023-08-13
            }

            ImGui::EndMenu();
        }

        ImGui::EndMenuBar();
    }
}

void FGE::FlowgraphWindow::ShowNodeList()
{
    if (ImGui::Begin(WINDOW_NODES))
    {
        static ImGuiTextFilter filter;
        filter.Draw("Filter");

        if (ImGui::BeginTable("Nodes Table", 1, ImGuiTableFlags_ScrollY, ImVec2(0, ImGui::GetContentRegionAvail().y * 0.95f)))
        {
            // TODO 2023-08-13: Need to optimize thise
            std::list<std::shared_ptr<PrototypeNode>> filteredNodes;
            std::list<PrototypeNode::nodeCategory> categories;

            for (auto& node : m_pFGE->GetPrototypes())
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

            for (auto& category : Node::CategoryNames)
            {
                if (std::find(categories.begin(), categories.end(), category.first) == categories.end())
                    continue;

                ImGui::TableNextRow();
                ImGui::TableNextColumn();
                ImGui::PushStyleColor(ImGuiCol_HeaderHovered, Node::GetCategoryColor(category.first).operator ImU32());
                ImGuiTreeNodeFlags treeNodeFlags = ImGuiTreeNodeFlags_CollapsingHeader;
                if (categories.size() < (int)PrototypeNode::nodeCategory::COUNT - 4)
                    treeNodeFlags |= ImGuiTreeNodeFlags_DefaultOpen;

                if (ImGui::TreeNodeEx(category.second, treeNodeFlags) ||
                    categories.size() < (int)PrototypeNode::nodeCategory::COUNT - 4)
                {
                    for (auto& ProtoNode : filteredNodes)
                    {
                        if (ProtoNode->Category == category.first)
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
                }

                ImGui::PopStyleColor();
            }

            ImGui::EndTable();
        }
    }

    ImGui::End();
}

void FGE::FlowgraphWindow::ShowNodeProperties()
{
    if (ImGui::Begin(WINDOW_PROPERTIES))
    {
        if (p_CurrentFlowGraph != nullptr)
        {
            p_CurrentFlowGraph->drawSelectedNodeProperties();
        }
    }

    ImGui::End();
}

void FGE::FlowgraphWindow::ShowEditorTabs()
{
    ImGuiDockNode* pDockNode = ImGui::DockBuilderGetNode(m_DockSpaceId);

    for (auto& pTab : m_Tabs)
    {
        pTab->ShowTab(pDockNode);
    }

    if (m_bOpenNodeInfoPopup)
    {
        ImGui::OpenPopup("NodeInfo");
        m_bOpenNodeInfoPopup = false;
    }

    if (ImGui::BeginPopup("NodeInfo"))
    {
        if (ImGui::MenuItem("Reset Pan"))
            p_CurrentFlowGraph->resetPanning({ 0, 0 });

        if (ImGui::BeginMenu("Add Nodes"))
        {
            for (auto& category : Node::CategoryNames)
            {
                if (ImGui::BeginMenu(category.second))
                {
                    for (auto& prototypeNode : m_PrototypeNodes)
                    {
                        if (prototypeNode.second->Category == category.first)
                        {
                            if (ImGui::MenuItem(("Add " + prototypeNode.second->Class).c_str()))
                                p_CurrentFlowGraph->addNode(prototypeNode.first, prototypeNode.second);
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
