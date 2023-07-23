//
// Created by theli on 9/25/2022.
//

#ifndef CHAIRLOADER_FLOWGRAPHEDITOR_H
#define CHAIRLOADER_FLOWGRAPHEDITOR_H

struct Node;
#include <pugixml.hpp>
#include <Prey/CryFlowGraph/IFlowSystem.h>
#include <filesystem>
#include "ImGui/imgui.h"
#include "ImNodes/imnodes.h"

#include "Flowgraph.h"
#include "App/AppModule.h"
#include <future>

class ImGuiDockNode;
class IFlowNode;

class FlowgraphEditor : public AppModule{
public:
    FlowgraphEditor();
    ~FlowgraphEditor() override;

    void Init() override;
    void ShowUI() override;
    void Update() override;

    static FlowgraphEditor* getInstance(){ return m_pFlowgraphEditorInstance;}
    ImGuiDockNode* getDockNode(){ return m_DockNode; }

    void setCurrentFlowgraph(FlowGraph* flowgraph){ p_CurrentFlowGraph = flowgraph;}
    void removeFlowgraph(FlowGraph* flowgraph);


    std::map<PrototypeNode::NodeClass,  std::shared_ptr<PrototypeNode>>& getPrototypes(){ return m_PrototypeNodes; }
    void addUnknownPrototype(PrototypeNode::NodeClass nodeClass);
    void addPinToPrototype(PrototypeNode::NodeClass nodeClass, PrototypePin pin);

    static void setShowNodePopup(bool bShow){ m_bShowNodePopup = bShow;}

private:
    enum class UIState {
        Initialization,
        Editor,
    };
    UIState m_UIState = UIState::Initialization;
    enum class InitializationState{
        None,
        LoadingPrototypes,
        SearchingDocuments,
        LoadingFlowgraphs,
        Done,
        COUNT,
    };

    bool m_bDraw = true;
    std::map<PrototypeNode::NodeClass,  std::shared_ptr<PrototypeNode>> m_PrototypeNodes;
    std::vector<fs::path> m_BaseGameFlowgraphPaths;
    std::vector<std::shared_ptr<FlowGraphXMLFile>> m_BaseGameFlowgaphs;
    std::vector<FlowGraph*> m_FlowGraphs;
    FlowGraph* p_CurrentFlowGraph = nullptr;

    void loadPrototypes();
    void searchXmlDocuments(fs::path path);
    bool findGraphNodes(pugi::xml_node &node);
    void loadXmlDocuments();

    std::mutex m_InitStatusMutex;
    std::string m_InitStatus;
    InitializationState m_InitState = InitializationState::None;
    void initAsync();
    std::future<void> m_InitFuture;
    float m_LoadingProgress = 1;
    fs::path m_CurrentLoadingFile;

    // XML Load and save
    static inline FlowgraphEditor* m_pFlowgraphEditorInstance = nullptr;
    static inline bool m_bShowNodePopup = false;
    void DrawNodeEditorTabs();
    void DrawNodeGraphList();
    void DrawNodeProperties();
    static const inline std::string m_DockspaceName = "FlowgraphEditorDockspace";
    ImGuiDockNode* m_DockNode;
};


#endif //CHAIRLOADER_FLOWGRAPHEDITOR_H
