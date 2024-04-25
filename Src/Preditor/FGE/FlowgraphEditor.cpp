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
#include <filesystem>

class CNullFlowGraph : public IFlowGraph
{
  public:
    virtual void DoActivatePort(SFlowAddress arg0, NFlowSystemUtils::Wrapper<SFlowSystemVoid> const& arg1) {}
    virtual void DoActivatePort(SFlowAddress arg0, NFlowSystemUtils::Wrapper<int> const& arg1) {}
    virtual void DoActivatePort(SFlowAddress arg0, NFlowSystemUtils::Wrapper<float> const& arg1) {}
    virtual void DoActivatePort(SFlowAddress arg0, NFlowSystemUtils::Wrapper<unsigned int> const& arg1) {}
    virtual void DoActivatePort(SFlowAddress arg0, NFlowSystemUtils::Wrapper<Vec3> const& arg1) {}
    virtual void DoActivatePort(SFlowAddress arg0, NFlowSystemUtils::Wrapper<string> const& arg1) {}
    virtual void DoActivatePort(SFlowAddress arg0, NFlowSystemUtils::Wrapper<bool> const& arg1) {}

    virtual void AddRef() {}
    virtual void Release() {}
    virtual _smart_ptr<IFlowGraph> Clone() { return nullptr; }
    virtual void Clear() {}
    virtual _smart_ptr<IFlowNodeIterator> CreateNodeIterator() { return nullptr; }
    virtual _smart_ptr<IFlowEdgeIterator> CreateEdgeIterator() { return nullptr; }
    virtual void SetGraphEntity(unsigned arg0, int arg1) {}
    virtual unsigned GetGraphEntity(int arg0) const { return 0; }
    virtual void SetEnabled(bool arg0) {}
    virtual bool IsEnabled() const { return false; }
    virtual void SetActive(bool arg0) {}
    virtual bool IsActive() const { return false; }
    virtual void UnregisterFromFlowSystem() {}
    virtual void SetType(IFlowGraph::EFlowGraphType arg0) {}
    virtual IFlowGraph::EFlowGraphType GetType() const { return eFGT_Default; }
    virtual void Update() {}
    virtual bool SerializeXML(XmlNodeRef const& arg0, bool arg1) { return false; }
    virtual void Serialize(TSerialize arg0) {}
    virtual void PostSerialize() {}
    virtual void InitializeValues() {}
    virtual void PrecacheResources() {}
    virtual void EnsureSortedEdges() {}
    virtual SFlowAddress ResolveAddress(const char* arg0, bool arg1)
    {
        SFlowAddress a;
        memset(&a, 0, sizeof(a));
        return a;
    }
    virtual uint16_t ResolveNode(const char* arg0) { return 0; }
    virtual uint16_t CreateNode(uint16_t arg0, const char* arg1, void* arg2) { return 0; }
    virtual uint16_t CreateNode(const char* arg0, const char* arg1, void* arg2) { return 0; }
    virtual IFlowNodeData* GetNodeData(uint16_t arg0) { return nullptr; }
    virtual bool SetNodeName(uint16_t arg0, const char* arg1) { return false; }
    virtual const char* GetNodeName(uint16_t arg0) { return 0; }
    virtual uint16_t GetNodeTypeId(uint16_t arg0) { return 0; }
    virtual const char* GetNodeTypeName(uint16_t arg0) { return 0; }
    virtual void RemoveNode(const char* arg0) {}
    virtual void RemoveNode(uint16_t arg0) {}
    virtual void SetUserData(uint16_t arg0, XmlNodeRef const& arg1) {}
    virtual XmlNodeRef GetUserData(uint16_t arg0) { return 0; }
    virtual bool LinkNodes(SFlowAddress arg0, SFlowAddress arg1) { return 0; }
    virtual void UnlinkNodes(SFlowAddress arg0, SFlowAddress arg1) {}
    virtual void RegisterFlowNodeActivationListener(SFlowNodeActivationListener* arg0) {}
    virtual void RemoveFlowNodeActivationListener(SFlowNodeActivationListener* arg0) {}
    virtual bool NotifyFlowNodeActivationListeners(uint16_t arg0, uint8_t arg1, uint16_t arg2, uint8_t arg3,
                                                   const char* arg4)
    {
        return 0;
    }
    virtual void SetEntityId(uint16_t arg0, unsigned arg1) {}
    virtual unsigned GetEntityId(uint16_t arg0) { return 0; }
    virtual _smart_ptr<IFlowGraph> GetClonedFlowGraph() const { return 0; }
    virtual void GetNodeConfiguration(uint16_t arg0, SFlowNodeConfig& arg1) {}
    virtual void SetRegularlyUpdated(uint16_t arg0, bool arg1) {}
    virtual void RequestFinalActivation(uint16_t arg0) {}
    virtual void ActivateNode(uint16_t arg0) {}
    virtual void ActivatePortAny(SFlowAddress arg0, TFlowInputData const& arg1) {}
    virtual void ActivatePortCString(SFlowAddress arg0, const char* arg1) {}
    virtual bool SetInputValue(uint16_t arg0, uint8_t arg1, TFlowInputData const& arg2) { return 0; }
    virtual bool IsOutputConnected(SFlowAddress arg0) { return 0; }
    virtual TFlowInputData const* GetInputValue(uint16_t arg0, uint8_t arg1) { return 0; }
    virtual bool GetActivationInfo(const char* arg0, IFlowNode::SActivationInfo& arg1) { return 0; }
    virtual void SetSuspended(bool arg0) {}
    virtual bool IsSuspended() const { return 0; }
    virtual void SetCustomAction(ICustomAction* arg0) {}
    virtual ICustomAction* GetCustomAction() const { return 0; }
    virtual void GetMemoryUsage(ICrySizer* arg0) const {}
    virtual void RemoveGraphTokens(bool arg0) {}
    virtual bool UpdateGraphToken(int arg0, const char* arg1, EFlowDataTypes arg2) { return 0; }
    virtual bool LoadGraphToken(int arg0, const char* arg1, EFlowDataTypes arg2) { return 0; }
    virtual int CloneGraphToken(IFlowGraph::SGraphToken const& arg0) { return 0; }
    virtual uint64_t GetGraphTokenCount() const { return 0; }
    virtual IFlowGraph::SGraphToken const* GetGraphToken(uint64_t arg0) const { return 0; }
    virtual unsigned GetGraphId() const { return 0; }
    virtual void OnNodeConfigReload(IFlowNodeData& arg0) {}
    virtual void SetOwningModule(IFlowGraphModule* arg0) {}
    virtual IFlowGraphModule* GetOwningModule() const { return 0; }
    virtual void FixCreatePhantomRequestEntityIdOutput(SFlowAddress arg0, unsigned arg1) {}
};

bool FlowgraphEditor::findGraphNodes(pugi::xml_node& node)
{
    // recrusively find all nodes with the tag "Graph" in the xml file
    // when they are found CryLog the path to the node
    bool graphNodesPresent = false;
    if (node.name() == std::string("Graph") || node.name() == std::string("FlowGraph"))
    {
        graphNodesPresent = true;
        return graphNodesPresent;
    }
    for (auto& child : node.children())
    {
        if (std::string(child.name()) == "Graph" || std::string(child.name()) == "FlowGraph")
        {
            graphNodesPresent = true;
            continue;
        }

        graphNodesPresent = graphNodesPresent | findGraphNodes(child);
    }
    return graphNodesPresent;
}

void FlowgraphEditor::searchXmlDocuments(fs::path path)
{
    // iterate through every file in the directory, if it's a directory, recurse
    // if it's a .xml file, load it and recursively find all nodes named "Graph
    if (fs::is_directory(path))
    {
        for (auto& p : fs::directory_iterator(path))
        {
            searchXmlDocuments(p);
        }
    }
    else if (path.extension() == ".xml")
    {
        pugi::xml_document doc;
        pugi::xml_parse_result result = doc.load_file(path.string().c_str());
        if (result)
        {
            pugi::xml_node node = doc.first_child();
            if (node)
            {
                if (findGraphNodes(node))
                {
                    m_BaseGameFlowgraphPaths.emplace_back(path);
                }
            }
        }
    }
}

void FlowgraphEditor::loadXmlDocuments()
{
    for (auto& path : m_BaseGameFlowgraphPaths)
    {
        {
            std::scoped_lock lock(m_InitStatusMutex);
            m_LoadingProgress++;
            m_CurrentLoadingFile = path.wstring().substr(gPreditor->pConfig->GetPreyFiles().wstring().length());
        }
        m_BaseGameFlowgaphs.emplace_back(std::make_shared<FlowGraphXMLFile>(path));
    }
}

FlowgraphEditor::FlowgraphEditor()
{
    m_pFlowgraphEditorInstance = this;
    ImNodes::CreateContext();
}

void FlowgraphEditor::ShowUI()
{
    std::scoped_lock lock(m_InitStatusMutex);
    static ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
    static ImGuiDockNodeFlags dockspace_flags =
        /*ImGuiDockNodeFlags_PassthruCentralNode |*/ ImGuiDockNodeFlags_NoWindowMenuButton;
    if (isShown())
    {
        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 2.0f);
        ImGui::SetNextWindowSize(ImVec2(800, 500), ImGuiCond_FirstUseEver);
        static auto first_time = true;
        static ImVec2 itemSize = { 30, 30 };
        if (m_UIState == UIState::Editor)
        {
            m_bDraw = true;
            auto m_DockspaceID = ImGui::GetID(m_DockspaceName.c_str());
            if (ImGui::Begin("Flowgraph Editor", &m_bDraw, window_flags))
            {
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
                ImGui::DockSpace(m_DockspaceID, ImVec2(0.0f, 0.0f), dockspace_flags);
                if (first_time)
                {
                    first_time = false;

                    ImGui::DockBuilderRemoveNode(m_DockspaceID); // clear any previous layout
                    ImGui::DockBuilderAddNode(m_DockspaceID, dockspace_flags | ImGuiDockNodeFlags_DockSpace);
                    m_DockNode = ImGui::DockBuilderGetNode(m_DockspaceID);
                    ImGui::DockBuilderSetNodeSize(m_DockspaceID, ImGui::GetWindowSize());

                    // split the dockspace into 2 nodes -- DockBuilderSplitNode takes in the following args in the
                    // following order
                    //   window ID to split, direction, fraction (between 0 and 1), the final two setting let's us
                    //   choose which id we want (which ever one we DON'T set as NULL, will be returned by the function)
                    //                                                              out_id_at_dir is the id of the node
                    //                                                              in the direction we specified
                    //                                                              earlier, out_id_at_opposite_dir is
                    //                                                              in the opposite direction
                    auto dock_id_right =
                        ImGui::DockBuilderSplitNode(m_DockspaceID, ImGuiDir_Right, 0.2f, nullptr, &m_DockspaceID);
                    auto dock_id_up =
                        ImGui::DockBuilderSplitNode(dock_id_right, ImGuiDir_Up, 0.3f, nullptr, &dock_id_right);

                    // we now dock our windows into the docking node we made above
                    ImGui::DockBuilderDockWindow("Node Properties", dock_id_up);
                    ImGui::DockBuilderDockWindow("Nodes", dock_id_right);
                    ImGui::DockBuilderDockWindow("Graphs", dock_id_right);
                    ImGui::DockBuilderFinish(m_DockspaceID);
                }
            }
            ImGui::End();
            DrawNodeGraphList();
            DrawNodeProperties();
            DrawNodeEditorTabs();
        }
        else if (m_UIState == UIState::Initialization)
        {
            //            ImGui::SetNextWindowSize(ImVec2(400, 200), ImGuiCond_Once);
            if (ImGui::Begin("Loading Flowgraph Editor", nullptr,
                             ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize |
                                 ImGuiWindowFlags_NoDocking))
            {
                ImGui::Text("Initializing Flowgraph Editor...");
                // TODO: add status text
                float m_progress = (float)m_InitState / ((float)InitializationState::COUNT - 1);
                ImGui::ProgressBar(m_progress, ImVec2(0.0f, 0.0f));
                ImGui::Text("%s", m_InitStatus.c_str());
                if (m_InitState == InitializationState::LoadingFlowgraphs)
                {
                    ImGui::ProgressBar((float)m_LoadingProgress / (float)m_BaseGameFlowgraphPaths.size(),
                                       ImVec2(0.0f, 0.0f));
                    ImGui::PushTextWrapPos();
                    ImGui::Text("Loading: %s", m_CurrentLoadingFile.u8string().c_str());
                    ImGui::PopTextWrapPos();
                }
            }
            ImGui::End();
            if (IsFutureReady(m_InitFuture))
            {
                m_InitFuture.get();
                m_UIState = UIState::Editor;
                m_InitState = InitializationState::COUNT;
            }
        }
        else
        {
            // panic
        }
        ImGui::PopStyleVar();
        if (!m_bDraw)
        {
            setShown(false);
        }
    }
}

void FlowgraphEditor::Update() {}

FlowgraphEditor::~FlowgraphEditor()
{
    ImNodes::DestroyContext();
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
                    for (auto& prototypeNode : m_PrototypeNodes)
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
            std::list<std::shared_ptr<PrototypeNode>> filteredNodes;
            std::list<PrototypeNode::nodeCategory> categories;
            for (auto& node : m_PrototypeNodes)
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
    if (ImGui::Begin("Graphs"))
    {
        std::vector<std::shared_ptr<FlowGraphXMLFile>> LevelFlowGraphs, LibsFlowGraphs, PrefabFlowGraphs;
        for (auto& file : m_BaseGameFlowgaphs)
        {
            switch (file->m_FilePlace)
            {
            case FilePlace::Ark:
                break;
            case FilePlace::Level:
                LevelFlowGraphs.push_back(file);
                break;
            case FilePlace::Mod:
                break;
            case FilePlace::Libs:
                LibsFlowGraphs.push_back(file);
                break;
            case FilePlace::Prefabs:
                PrefabFlowGraphs.push_back(file);
                break;
            default:
                break;
            }
        }
        if (ImGui::TreeNode("Level"))
        {
            std::vector<std::pair<std::string, std::vector<FlowGraphXMLFile*>>> filesSortedByLevelName;
            for (auto& file : LevelFlowGraphs)
            {
                bool found = false;
                for (auto& fileSorted : filesSortedByLevelName)
                {
                    if (fileSorted.first == file->m_LevelName)
                    {
                        fileSorted.second.push_back(file.get());
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    std::vector<FlowGraphXMLFile*> files;
                    files.push_back(file.get());
                    filesSortedByLevelName.emplace_back(std::pair(file->m_LevelName.u8string(), files));
                }
            }
            for (auto& fileSorted : filesSortedByLevelName)
            {
                if (ImGui::TreeNode(fileSorted.first.c_str()))
                {
                    for (auto& file : fileSorted.second)
                    {
                        if (ImGui::TreeNode(file->m_RelativeLevelPath.u8string().c_str()))
                        {
                            for (auto& graph : file->m_FlowGraphs)
                            {
                                std::string graphIDStr = graph->m_Name + "##";
                                if (graph->m_FlowGraphType == FlowGraphFromXML::FlowGraphType::Entity)
                                {
                                    auto entityInfo = std::get<FlowGraphFromXML::EntityFileInfo>(graph->m_FileInfo);
                                    graphIDStr = graph->m_Name + "##" + entityInfo.entityName +
                                                 std::to_string(entityInfo.entityID);
                                }
                                if (graph->m_bContainsUnknownNodes)
                                {
                                    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1, 0, 0, 1));
                                }
                                if (ImGui::Selectable(graphIDStr.c_str()))
                                {
                                    bool alreadyOpen = false;
                                    for (auto& openGraph : m_FlowGraphs)
                                    {
                                        if (openGraph->m_Path == graph->m_Path)
                                        {
                                            if (openGraph->m_Name == graph->m_Name)
                                            {
                                                alreadyOpen = true;
                                                break;
                                            }
                                        }
                                    }
                                    if (!alreadyOpen)
                                        m_FlowGraphs.emplace_back(graph.get());
                                }
                                if (graph->m_bContainsUnknownNodes)
                                {
                                    ImGui::PopStyleColor();
                                }
                                ImGui::SameLine();
                                ImGui::Text("%d", graph->m_Nodes.size());
                            }
                            ImGui::TreePop();
                        }
                    }
                    ImGui::TreePop();
                }
            }
            ImGui::TreePop();
        }
        if (ImGui::TreeNode("Libs"))
        {
            static const std::map<FlowGraphFromXML::FlowGraphType, std::string> typeNames = {
                { FlowGraphFromXML::FlowGraphType::GlobalAction, "Global Action" },
                { FlowGraphFromXML::FlowGraphType::UIAction, "UI Action" },
                { FlowGraphFromXML::FlowGraphType::FlowgraphModule, "Flowgraph Module" },
                { FlowGraphFromXML::FlowGraphType::Unknown, "Unknown" },
            };
            //            for (auto &file: LibsFlowGraphs) {
            std::vector<std::pair<FlowGraphFromXML::FlowGraphType, std::vector<FlowGraphXMLFile*>>> filesSortedByType;
            for (auto& file : LibsFlowGraphs)
            {
                bool found = false;
                for (auto& fileSorted : filesSortedByType)
                {
                    if (fileSorted.first == file->m_FlowGraphs[0]->m_FlowGraphType)
                    {
                        fileSorted.second.push_back(file.get());
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    std::vector<FlowGraphXMLFile*> files;
                    files.push_back(file.get());
                    filesSortedByType.emplace_back(std::pair(file->m_FlowGraphs[0]->m_FlowGraphType, files));
                }
            }
            for (auto& fileSorted : filesSortedByType)
            {
                if (ImGui::TreeNode(typeNames.at(fileSorted.first).c_str()))
                {
                    for (auto& XmlFile : fileSorted.second)
                    {
                        if (XmlFile->m_FlowGraphs[0]->m_bContainsUnknownNodes)
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1, 0, 0, 1));
                        }
                        if (ImGui::Selectable(XmlFile->m_Path.filename().u8string().c_str()))
                        {
                            auto graph = XmlFile->m_FlowGraphs[0];
                            bool alreadyOpen = false;
                            for (auto& openGraph : m_FlowGraphs)
                            {
                                if (openGraph->m_Path == graph->m_Path)
                                {
                                    if (openGraph->m_Name == graph->m_Name)
                                    {
                                        alreadyOpen = true;
                                        break;
                                    }
                                }
                            }
                            if (!alreadyOpen)
                                m_FlowGraphs.emplace_back(graph.get());
                        }
                        if (XmlFile->m_FlowGraphs[0]->m_bContainsUnknownNodes)
                        {
                            ImGui::PopStyleColor();
                        }
                    }
                    ImGui::TreePop();
                }
            }

            //                // remove libs/ from the string before displaying it
            //                std::string selectableName =
            //                file->m_RelativePath.u8string().substr(file->m_RelativePath.u8string().find('\\') + 1);
            //                if(ImGui::Selectable(selectableName.c_str())){
            //                    bool alreadyOpen = false;
            //                    for(auto &openGraph: m_FlowGraphs) {
            //                        if(openGraph->m_Path == file->m_Path) {
            //                            if(openGraph->m_Name == file->m_Name) {
            //                                alreadyOpen = true;
            //                                break;
            //                            }
            //                        }
            //                    }
            //                    if(!alreadyOpen)
            //                        m_FlowGraphs.emplace_back(file->m_FlowGraphs[0].get());
            //                }
            //            }
            ImGui::TreePop();
        }
        if (ImGui::TreeNode("Prefabs"))
        {
            for (auto& file : PrefabFlowGraphs)
            {
                if (ImGui::TreeNode(file->m_Path.u8string().c_str(), "%s", file->m_Path.filename().u8string().c_str()))
                {
                    for (auto& graph : file->m_FlowGraphs)
                    {
                        if (graph->m_bContainsUnknownNodes)
                        {
                            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1, 0, 0, 1));
                        }
                        if (ImGui::Selectable(graph->m_Name.c_str()))
                        {
                            bool alreadyOpen = false;
                            for (auto& openGraph : m_FlowGraphs)
                            {
                                if (openGraph->m_Path == graph->m_Path)
                                {
                                    if (openGraph->m_Name == graph->m_Name)
                                    {
                                        alreadyOpen = true;
                                        break;
                                    }
                                }
                            }
                            if (!alreadyOpen)
                                m_FlowGraphs.emplace_back(graph.get());
                        }
                        if (graph->m_bContainsUnknownNodes)
                        {
                            ImGui::PopStyleColor();
                        }
                    }
                    ImGui::TreePop();
                }
            }
            ImGui::TreePop();
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

void FlowgraphEditor::removeFlowgraph(FlowGraph* flowgraph)
{
    auto it = std::find(m_FlowGraphs.begin(), m_FlowGraphs.end(), flowgraph);
    if (it != m_FlowGraphs.end())
    {
        m_FlowGraphs.erase(it);
    }
}

void FlowgraphEditor::addUnknownPrototype(PrototypeNode::NodeClass nodeClass)
{
    auto node = std::make_shared<PrototypeNode>();
    node->Class = nodeClass;
    node->Category = PrototypeNode::nodeCategory::UNKNOWN;
    m_PrototypeNodes.insert(std::pair(node->Class, node));
}

void FlowgraphEditor::addPinToPrototype(PrototypeNode::NodeClass nodeClass, PrototypePin pin)
{
    auto node = m_PrototypeNodes.find(nodeClass);
    if (node != m_PrototypeNodes.end())
    {
        if (pin.Kind == PinKind::Input)
            node->second->ProtoInputs.push_back(pin);
        else
            node->second->ProtoOutputs.push_back(pin);
    }
    for (auto& file : m_BaseGameFlowgaphs)
    {
        for (auto& graph : file->m_FlowGraphs)
        {
            graph->refreshNodesOfClass(nodeClass);
        }
    }
}

void FlowgraphEditor::Init()
{
    // Can no longer run everything in async - the engine runs fully now
    // m_InitFuture = std::async(std::launch::async, [&]() {initAsync();});

    AppModule::Init();
    initAsync();
    m_UIState = UIState::Editor;
    m_InitState = InitializationState::COUNT;
}

void FlowgraphEditor::initAsync()
{
    {
        std::scoped_lock lock(m_InitStatusMutex);
        m_InitStatus = "Loading Prototype Flowgraph Nodes";
        m_InitState = InitializationState::LoadingPrototypes;
    }
    loadPrototypes();
    {
        std::scoped_lock lock(m_InitStatusMutex);
        m_InitStatus = "Finding Flowgraphs";
        m_InitState = InitializationState::SearchingDocuments;
    }
    searchXmlDocuments(gPreditor->pConfig->GetPreyFiles());
    {
        std::scoped_lock lock(m_InitStatusMutex);
        m_InitStatus = "Loading Flowgraphs";
        m_InitState = InitializationState::LoadingFlowgraphs;
    }
    loadXmlDocuments();
    {
        std::scoped_lock lock(m_InitStatusMutex);
        m_InitStatus = "Initialization Complete";
        m_InitState = InitializationState::Done;
    }
}

void FlowgraphEditor::loadPrototypes()
{
    auto flowSystem = static_cast<CFlowSystem*>(gEnv->pFlowSystem);
    for (auto& typeEntry : flowSystem->m_typeNameToIdMap)
    {
        IFlowNode::SActivationInfo info;
        CNullFlowGraph nullGraph;
        info.pGraph = &nullGraph;
        // TODO: Fix timer nodes
        if (/*std::string(typeEntry.first.c_str()) == ("Entity:TacticalScan") ||*/
            /*std::string(typeEntry.first.c_str()) == ("Ark:PlayerMimicEvent") ||*/
            std::string(typeEntry.first.c_str()) == ("Time:Timer"))
        {
            continue;
        }
        auto newNode = std::make_shared<PrototypeNode>();
        newNode->Class = typeEntry.first.c_str();
        auto node = flowSystem->CreateNodeOfType(&info, typeEntry.second);
        SFlowNodeConfig nodeConfig{};
        if (node.get() == nullptr)
        {
            continue;
        }
        node->GetConfiguration(nodeConfig);
        if (nodeConfig.sDescription != nullptr)
            newNode->Description = nodeConfig.sDescription;
        int i = 0;
        auto inputPort = &nodeConfig.pInputPorts[i];
        if (inputPort != nullptr)
        {
            while (inputPort->name != nullptr)
            {
                PrototypePin newPin;
                if (inputPort->name != nullptr)
                    newPin.Name = inputPort->name;
                if (inputPort->humanName != nullptr)
                    newPin.HumanName = inputPort->humanName;
                if (inputPort->description != nullptr)
                    newPin.Description = inputPort->description;
                newPin.Kind = PinKind::Input;
                if (inputPort->sUIConfig != nullptr)
                    newPin.sUIConfig = inputPort->sUIConfig;
                newNode->ProtoInputs.emplace_back(newPin);
                inputPort = &nodeConfig.pInputPorts[++i];
            }
        }
        i = 0;
        auto outputPort = &nodeConfig.pOutputPorts[i];
        if (outputPort != nullptr)
        {
            while (outputPort->name != nullptr)
            {
                PrototypePin newPin;
                if (outputPort->name != nullptr)
                    newPin.Name = outputPort->name;
                if (outputPort->humanName != nullptr)
                    newPin.HumanName = outputPort->humanName;
                if (outputPort->description != nullptr)
                    newPin.Description = outputPort->description;
                newPin.Kind = PinKind::Output;
                newPin.Type = outputPort->type;
                newNode->ProtoOutputs.emplace_back(newPin);
                outputPort = &nodeConfig.pOutputPorts[++i];
            }
        }
        newNode->mFlags = nodeConfig.nFlags;
        newNode->m_bEntity_Node = nodeConfig.nFlags & EHYPER_NODE_ENTITY;
        //        newNode->m_bDefault_Entity_node = nodeConfig.nFlags & 0x0004;
        newNode->setCategory();
        m_PrototypeNodes.insert(std::pair(newNode->Class, newNode));
        node.ReleaseOwnership();
    }
    // add comment box classes
    auto commentNode = std::make_shared<PrototypeNode>();
    commentNode->Class = "_commentbox";
    commentNode->Description = "Comment Box";
    commentNode->Category = PrototypeNode::nodeCategory::COMMENT;

    m_PrototypeNodes.insert(std::pair(commentNode->Class, commentNode));
    commentNode = std::make_shared<PrototypeNode>();
    commentNode->Class = "_comment";
    commentNode->Description = "Comment Box";
    commentNode->Category = PrototypeNode::nodeCategory::COMMENT;
    m_PrototypeNodes.insert(std::pair(commentNode->Class, commentNode));

    // Add nodes that cannot be constructed

    // TIME:TIMER
    auto TimerNode = std::make_shared<PrototypeNode>();
    TimerNode->Class = "Time:Timer";
    TimerNode->Description = "Timer";
    TimerNode->Category = PrototypeNode::nodeCategory::TIME;
    // add the inputs period, min, max, paused, timer
    PrototypePin newPin;
    newPin.Name = "period";
    newPin.Kind = PinKind::Input;
    TimerNode->ProtoInputs.emplace_back(newPin);
    newPin.Name = "min";
    newPin.Kind = PinKind::Input;
    TimerNode->ProtoInputs.emplace_back(newPin);
    newPin.Name = "max";
    newPin.Kind = PinKind::Input;
    TimerNode->ProtoInputs.emplace_back(newPin);
    newPin.Name = "paused";
    newPin.Kind = PinKind::Input;
    TimerNode->ProtoInputs.emplace_back(newPin);
    newPin.Name = "Timer";
    newPin.Kind = PinKind::Input;
    TimerNode->ProtoInputs.emplace_back(newPin);
    // add the one output out
    newPin.Name = "out";
    newPin.Kind = PinKind::Output;
    TimerNode->ProtoOutputs.emplace_back(newPin);
    m_PrototypeNodes.insert(std::pair(TimerNode->Class, TimerNode));
}
