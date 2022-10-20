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

static std::vector<std::shared_ptr<FlowGraphXMLFile>> filesWithgraphNodes;

bool findGraphNodes(pugi::xml_node &node){
    // recrusively find all nodes with the tag "Graph" in the xml file
    // when they are found CryLog the path to the node
    bool graphNodesPresent = false;
    if(node.name() == std::string("Graph") || node.name() == std::string("FlowGraph")){
//        CryLog("Found Graph Node: %s", node.path().c_str());
        graphNodesPresent = true;
        return graphNodesPresent;
    }
    for (auto &child : node.children()){
        if (std::string(child.name()) == "Graph" || std::string(child.name()) == "FlowGraph" ){
//            CryLog("Found Graph Node: %s", child.path().c_str());
            graphNodesPresent = true;
            continue;
        }

        graphNodesPresent = graphNodesPresent | findGraphNodes(child);
    }
    return graphNodesPresent;
}

void searchXmlDocuments(fs::path path){
    // iterate through every file in the directory, if it's a directory, recurse
    // if it's a .xml file, load it and recursively find all nodes named "Graph
    if(fs::is_directory(path)){
        for(auto &p: fs::directory_iterator(path)){
            searchXmlDocuments(p);
        }
    }else if(path.extension() == ".xml"){
        pugi::xml_document doc;
        pugi::xml_parse_result result = doc.load_file(path.string().c_str());
        if(result){
            pugi::xml_node node = doc.first_child();
            if(node){
                if(findGraphNodes(node)){
//                    CryLog("Found Graph Nodes in %s", path.string().c_str());
                    filesWithgraphNodes.emplace_back(std::make_shared<FlowGraphXMLFile>(path));
//                    filesWithgraphNodes.back().m_Path = path;
//                    filesWithgraphNodes.back().m_FilePlace = filesWithgraphNodes.back().parseFilePlace(filesWithgraphNodes.back().m_Path);
                }
            }
        }
    }
}


FlowgraphEditor::FlowgraphEditor() {
    m_pFlowgraphEditorInstance = this;
    ImNodes::CreateContext();
    auto flowSystem = static_cast<CFlowSystem*>(gEnv->pFlowSystem);
    for(auto & typeEntry: flowSystem->m_typeNameToIdMap) {
        auto info = new IFlowNode::SActivationInfo();
        //TODO: Fix timer nodes
        if(std::string(typeEntry.first.c_str()) == ("Entity:TacticalScan") ||
        std::string(typeEntry.first.c_str()) == ("Ark:PlayerMimicEvent") ||
        std::string(typeEntry.first.c_str()) == ("Time:Timer")) {
            continue;
        }
        PrototypeNode newNode;
        newNode.Class = typeEntry.first.c_str();
        auto node = flowSystem->CreateNodeOfType(info, typeEntry.second);
        SFlowNodeConfig nodeConfig{};
        if(node.get() == nullptr) {
            continue;
        }
        node->GetConfiguration(nodeConfig);
        if(nodeConfig.sDescription != nullptr)
            newNode.Description = nodeConfig.sDescription;
        int i = 0;
        auto inputPort = &nodeConfig.pInputPorts[i];
        if(inputPort != nullptr) {
            while (inputPort->name != nullptr) {
                PrototypePin newPin;
                if(inputPort->name != nullptr)
                    newPin.Name = inputPort->name;
                if(inputPort->humanName != nullptr)
                    newPin.HumanName = inputPort->humanName;
                if(inputPort->description != nullptr)
                    newPin.Description = inputPort->description;
                newPin.Kind = PinKind::Input;
                if(inputPort->sUIConfig != nullptr)
                    newPin.sUIConfig = inputPort->sUIConfig;
                newNode.ProtoInputs.emplace_back(newPin);
                inputPort = &nodeConfig.pInputPorts[++i];
            }
        }
        i = 0;
        auto outputPort = &nodeConfig.pOutputPorts[i];
        if(outputPort != nullptr) {
            while (outputPort->name != nullptr) {
                PrototypePin newPin;
                if(outputPort->name != nullptr)
                    newPin.Name = outputPort->name;
                if(outputPort->humanName != nullptr)
                    newPin.HumanName = outputPort->humanName;
                if(outputPort->description != nullptr)
                    newPin.Description = outputPort->description;
                newPin.Kind = PinKind::Output;
                newPin.Type = outputPort->type;
                newNode.ProtoOutputs.emplace_back(newPin);
                outputPort = &nodeConfig.pOutputPorts[++i];
            }
        }
        newNode.mFlags = nodeConfig.nFlags;
        newNode.m_bEntity_Node = nodeConfig.nFlags & EHYPER_NODE_ENTITY;
//        newNode.m_bDefault_Entity_node = nodeConfig.nFlags & 0x0004;
        newNode.setCategory();
        m_PrototypeNodes.insert(std::pair(newNode.Class, newNode));
        node.ReleaseOwnership();
        delete info;
    }
    // add comment box classes
    PrototypeNode commentNode;
    commentNode.Class = "_commentbox";
    commentNode.Description = "Comment Box";
    commentNode.Category = PrototypeNode::nodeCategory::COMMENT;

    m_PrototypeNodes.insert(std::pair(commentNode.Class, commentNode));
    commentNode.Class = "_comment";
    m_PrototypeNodes.insert(std::pair(commentNode.Class, commentNode));
    static FlowGraph testGraph;
    testGraph.m_Name = "TestGraph";
    m_FlowGraphs.emplace_back(&testGraph);
}

void FlowgraphEditor::Draw(bool *bDraw) {
    ImGui::ShowDemoWindow(bDraw);
    gEnv->pFlowSystem;
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 2.0f);
    ImGui::PushFont(AppImGui::getPrettyFont());
    ImGui::SetNextWindowSize(ImVec2(800,500), ImGuiCond_FirstUseEver);
    if(ImGui::Begin("Flowgraph Editor", bDraw, ImGuiWindowFlags_MenuBar)) {
        if (ImGui::BeginMenuBar()) {
            if (ImGui::BeginMenu("File")) {
                if (ImGui::MenuItem("Load File")) {

                }
                ImGui::EndMenu();
            }
            ImGui::EndMenuBar();
        }
        ImGui::GetStyle().ScaleAllSizes(STYLE_SCALE);

        DrawNodeEditorTabs();
        ImGui::SameLine();
        DrawNodeGraphList();

        ImGui::GetStyle().ScaleAllSizes(1.0f / STYLE_SCALE);
        ImGui::End();
    }
    ImGui::PopFont();
    ImGui::PopStyleVar();
}

void FlowgraphEditor::Update() {
}

FlowgraphEditor::~FlowgraphEditor() {
    ImNodes::DestroyContext();
}

void FlowgraphEditor::DrawNodeEditorTabs() {
    ImGui::BeginGroup();
    static ImVec2 itemSize = {30, 30};
    if(ImGui::BeginChild("Toolbar", ImVec2(ImGui::GetContentRegionAvail().x * 0.8f, itemSize.y))){
//        ImGui::Text("This is a toolbar bitch");
        static std::string path = R"(C:\Users\theli\Documents\Modding\Prey Modding\Learning2Hack\ChairLoader\ChairloaderModLoader\Data\PreyFiles)";
        ImGui::InputText("Path", &path);
        ImGui::SameLine();
        if(ImGui::Button(ICON_MD_SEARCH "##Search Button Toolbar", itemSize)){
            searchXmlDocuments(path);
        }
    }
    ImGui::EndChild();
    if(ImGui::BeginChild("Flow Graph Canvas", ImVec2(ImGui::GetContentRegionAvail().x * 0.8f,0))) {
        if(ImGui::BeginTabBar("Flowgraphs", ImGuiTabBarFlags_Reorderable | ImGuiTabBarFlags_TabListPopupButton | ImGuiTabBarFlags_AutoSelectNewTabs)) {
            for (auto &flowgraph: m_FlowGraphs) {
                flowgraph->drawTab();
            }
            ImGui::EndTabBar();
        }
        if(m_bShowNodePopup){
            ImGui::OpenPopup("NodeInfo");
            m_bShowNodePopup = false;
        }
        if(ImGui::BeginPopup("NodeInfo")){
            if(ImGui::MenuItem("Reset Pan")){
                p_CurrentFlowGraph->resetPanning({0,0});
            }
            if(ImGui::BeginMenu("Add Nodes")){
                for(auto & category : Node::CategoryNames){
                    if(ImGui::BeginMenu(category.second)){
                        for(auto& prototypeNode: m_PrototypeNodes){
                            if(prototypeNode.second.Category == category.first){
                                if(ImGui::MenuItem(("Add " + prototypeNode.second.Class).c_str())){
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
    ImGui::EndChild();
    ImGui::EndGroup();
}

void FlowgraphEditor::DrawNodeGraphList(){
    ImGui::BeginGroup();
    if(p_CurrentFlowGraph != nullptr){
        if(ImGui::BeginChild("Node Properties", ImVec2(0,ImGui::GetContentRegionAvail().y * p_CurrentFlowGraph->m_nodePropertiesHeight), true)){
            p_CurrentFlowGraph->drawSelectedNodeProperties();
        }
        ImGui::EndChild();
    }
    if(ImGui::BeginChild("Prototype Node Selection List", ImVec2(0,0), true)) {
//        static std::string path;
//        ImGui::InputText("Path", &path);
//        if (ImGui::Button("Load XML File")) {
//            if (p_CurrentFlowGraph) {
//                auto success = p_CurrentFlowGraph->loadXML(path);
//                CRY_ASSERT(success);
//            }
//        }
        if (ImGui::BeginTabBar("Node and Graph List")) {
            if(ImGui::BeginTabItem("Nodes")) {
                static ImGuiTextFilter filter;
                filter.Draw("Filter");
                if (ImGui::BeginTable("Nodes", 1, ImGuiTableFlags_ScrollY,
                                      ImVec2(0, ImGui::GetContentRegionAvail().y * 0.95f))) {
                    std::list<PrototypeNode *> filteredNodes;
                    std::list<Node::nodeCategory> categories;
                    for (auto &node: m_PrototypeNodes) {
                        if (filter.PassFilter(node.second.Class.c_str())) {
                            filteredNodes.emplace_back(&node.second);
                            if (std::find(categories.begin(), categories.end(), node.second.Category) ==
                                categories.end()) {
                                categories.emplace_back(node.second.Category);
                            }
                        }
                    }
                    /*for (auto &ProtoNode: m_PrototypeNodes) {
                                if (filter.PassFilter(ProtoNode.first.c_str()) && ProtoNode.second.Category == Category.first) {
                                    if (ImGui::Selectable(ProtoNode.second.Class.c_str())) {
                                        if (p_CurrentFlowGraph != nullptr) {
                                            p_CurrentFlowGraph->addNode(ProtoNode.second.Class, ProtoNode.second);
                                        }
                                    }
                                }
                            }*/
                    for (auto &Category: Node::CategoryNames) {
                        if (std::find(categories.begin(), categories.end(), Category.first) == categories.end()) {
                            continue;
                        }
                        ImGui::TableNextRow();
                        ImGui::TableNextColumn();
                        ImGui::PushStyleColor(ImGuiCol_HeaderHovered,
                                              Node::GetCategoryColor(Category.first).operator ImU32());
                        ImGuiTreeNodeFlags treeNodeFlags = ImGuiTreeNodeFlags_CollapsingHeader;
                        if (categories.size() < (int) Node::nodeCategory::COUNT - 4) {
                            treeNodeFlags |= ImGuiTreeNodeFlags_DefaultOpen;
                        }
                        if (ImGui::TreeNodeEx(Category.second, treeNodeFlags) ||
                            categories.size() < (int) Node::nodeCategory::COUNT - 4) {
                            for (auto &ProtoNode: filteredNodes) {
                                if (ProtoNode->Category == Category.first) {
                                    if (ImGui::Selectable(ProtoNode->Class.c_str())) {
                                        if (p_CurrentFlowGraph != nullptr) {
                                            p_CurrentFlowGraph->addNode(ProtoNode->Class, *ProtoNode);
                                        }
                                    }
                                    if (ImGui::IsItemHovered() && GImGui->HoveredIdTimer > 0.5f) {
                                        ImGui::BeginTooltip();
                                        ImGui::Text("%s", ProtoNode->Class.c_str());
                                        ImGui::EndTooltip();
                                    }
                                }
                            }
                            ImGui::PopStyleColor();
                        } else {
                            ImGui::PopStyleColor();
                        }
                    }
                    ImGui::EndTable();
                }
                if (ImGui::Button("Clear Nodes")) {
                }
                ImGui::EndTabItem();
            }
            if(ImGui::BeginTabItem("Graphs")) {
                if(ImGui::BeginChild("Graphs", ImVec2(0,0), true, ImGuiWindowFlags_HorizontalScrollbar)){
                    std::vector<std::shared_ptr<FlowGraphXMLFile>> LevelFlowGraphs, LibsFlowGraphs, PrefabFlowGraphs;
                    for(auto & file: filesWithgraphNodes){
                        switch(file->m_FilePlace){
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
                    if(ImGui::TreeNode("Level")){
                        std::vector<std::pair<std::string, std::vector<FlowGraphXMLFile*>>> filesSortedByLevelName;
                        for(auto & file: LevelFlowGraphs){
                            bool found = false;
                            for(auto & fileSorted: filesSortedByLevelName){
                                if(fileSorted.first == file->m_LevelName){
                                    fileSorted.second.push_back(file.get());
                                    found = true;
                                    break;
                                }
                            }
                            if(!found){
                                std::vector<FlowGraphXMLFile*> files;
                                files.push_back(file.get());
                                filesSortedByLevelName.emplace_back(std::pair(file->m_LevelName.u8string(), files));
//                                    filesSortedByLevelName.emplace_back((std::pair(file->m_LevelName, std::vector<FlowGraphXMLFile*>{file.get()})));
                            }
                        }
                        for(auto & fileSorted: filesSortedByLevelName){
                            if(ImGui::TreeNode(fileSorted.first.c_str())){
                                for(auto & file: fileSorted.second) {
                                    if(ImGui::TreeNode(file->m_RelativeLevelPath.u8string().c_str())){
                                        for(auto &graph : file->m_FlowGraphs){
                                            std::string graphIDStr = graph->m_Name + "##";
                                            if(graph->m_FlowGraphType == FlowGraphFromXML::FlowGraphType::Entity){
                                                auto entityInfo = std::get<FlowGraphFromXML::EntityFileInfo>(graph->m_FileInfo);
                                                graphIDStr = graph->m_Name
                                                        + "##" + entityInfo.entityName + std::to_string(entityInfo.entityID);
                                            }
                                            if(ImGui::Selectable(graphIDStr.c_str())){
                                                m_FlowGraphs.emplace_back(graph.get());
                                            }
                                        }
                                        ImGui::TreePop();
                                    }
                                }
                                ImGui::TreePop();
                            }
                        }
//                            }
//                            if(ImGui::TreeNode(file->m_Path.u8string().c_str(), "%s %s", file->m_LevelName.u8string().c_str(), file->m_RelativePath.u8string().c_str())){
//
//                                ImGui::TreePop();
//                            }

                        ImGui::TreePop();
                    }
                    if(ImGui::TreeNode("Libs")){
                        for(auto & file: LibsFlowGraphs){
                            ImGui::Text("%s", file->m_RelativePath.u8string().c_str());
                        }
                        ImGui::TreePop();
                    }
                    if(ImGui::TreeNode("Prefabs")){
                        for(auto & file: PrefabFlowGraphs){
                            ImGui::Text("%s", file->m_RelativePath.u8string().c_str());
                        }
                        ImGui::TreePop();
                    }
                }
                ImGui::EndChild();
                ImGui::EndTabItem();
            }
            ImGui::EndTabBar();
        }
    }
    ImGui::EndChild();
    ImGui::EndGroup();
}