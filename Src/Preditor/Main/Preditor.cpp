#include <boost/json.hpp>
#include <Prey/CryAction/flowsystem/Nodes/FlowBaseNode.h>
#include <Prey/CryAction/flowsystem/flowsystem.h>
#include <Preditor/Assets/IAssetSystem.h>
#include <Preditor/IChairloaderToolsPreditor.h>
#include <Preditor/Engine/IPreditorEngine.h>
#include <Preditor/Input/IPreditorInput.h>
#include <Preditor/Viewport/IViewportWindow.h>
#include "Project/Project.h"
#include "Project/UserProjectSettings.h"
#include "UI/PreditorUI.h"
#include "Preditor.h"
#include "SceneEditorManager.h"

class CNullFlowGraph2 : public IFlowGraph
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

static void DumpFlowNodesCommand(IConsoleCmdArgs*)
{
    namespace json = boost::json;

    auto flowSystem = static_cast<CFlowSystem*>(gEnv->pFlowSystem);
    json::object jRoot;

    for (auto& typeEntry : flowSystem->m_typeNameToIdMap)
    {
        IFlowNode::SActivationInfo info;
        CNullFlowGraph2 nullGraph;
        info.pGraph = &nullGraph;

        IFlowNode_AutoPtr node = flowSystem->CreateNodeOfType(&info, typeEntry.second);
        if (!node)
        {
            CryError("Failed to create node {}", typeEntry.first);
            continue;
        }

        json::object jObj;
        SFlowNodeConfig nodeConfig{};
        node->GetConfiguration(nodeConfig);
        jObj["nFlags"] = nodeConfig.nFlags;
        jObj["sDescription"] = nodeConfig.sDescription ? json::value(nodeConfig.sDescription) : nullptr;
        jObj["sUIClassName"] = nodeConfig.sUIClassName ? json::value(nodeConfig.sUIClassName) : nullptr;

        if (nodeConfig.pInputPorts)
        {
            json::array jInputPorts;
            for (const SInputPortConfig* inputPort = nodeConfig.pInputPorts; inputPort->name != nullptr; inputPort++)
            {
                json::object jPort;
                jPort["name"] = inputPort->name ? json::value(inputPort->name) : nullptr;
                jPort["humanName"] = inputPort->humanName ? json::value(inputPort->humanName) : nullptr;
                jPort["description"] = inputPort->description ? json::value(inputPort->description) : nullptr;
                jPort["sUIConfig"] = inputPort->sUIConfig ? json::value(inputPort->sUIConfig) : nullptr;
                jInputPorts.push_back(jPort);
            }
            jObj["inputPorts"] = jInputPorts;
        }

        if (nodeConfig.pOutputPorts)
        {
            json::array jOnputPorts;
            for (const SOutputPortConfig* outputPort = nodeConfig.pOutputPorts; outputPort->name != nullptr; outputPort++)
            {
                json::object jPort;
                jPort["name"] = outputPort->name ? json::value(outputPort->name) : nullptr;
                jPort["humanName"] = outputPort->humanName ? json::value(outputPort->humanName) : nullptr;
                jPort["description"] = outputPort->description ? json::value(outputPort->description) : nullptr;
                jPort["type"] = outputPort->type;
                jOnputPorts.push_back(jPort);
            }
            jObj["outputPorts"] = jOnputPorts;
        }

        jRoot[json::string(typeEntry.first)] = jObj;
    }

    std::ofstream outFile(gPreditor->pPaths->GetUserPath() / "flownodes.json");
    outFile << jRoot;
}

std::unique_ptr<IPreditor> IPreditor::CreateInstance()
{
    return std::make_unique<Main::Preditor>();
}

Main::Preditor::Preditor()
{
    m_pProject = std::make_unique<Project>(gPreditor->pPaths->GetProjectDirPath());
    m_pUserSettings = std::make_unique<UserProjectSettings>(gPreditor->pPaths->GetUserPath() / IUserProjectSettings::FILE_NAME);
    gPreditor->pTime = &m_Time;
    gPreditor->pProject = m_pProject.get();
    gPreditor->pUserSettings = m_pUserSettings.get();
}

Main::Preditor::~Preditor()
{
    gPreditor->pProject = nullptr;
    gPreditor->pUserSettings = nullptr;
}

void Main::Preditor::AddLevelToRecent(const std::string& path)
{
    std::string_view pathView = path;
    std::string_view prefix = "Levels/";

    if (path.size() >= prefix.size() && pathView.substr(0, prefix.size()) == prefix)
        pathView = pathView.substr(prefix.size());

    m_pUI->AddLevelToRecent(std::string(pathView));
}

void Main::Preditor::InitSystem()
{
    CRY_ASSERT(!gCL->pSceneEditor);
    gCL->pSceneEditor = this;
    m_pAssetSystem = IAssetSystem::CreateInstance();
    gPreditor->pAssetSystem = m_pAssetSystem.get();
    m_pAssetSystem->InitSystem();
}

void Main::Preditor::InitGame()
{
    m_pInput = IPreditorInput::CreateInstance();
    gPreditor->pInput = m_pInput.get();

    m_pSceneEditorManager = std::make_unique<SceneEditorManager>();
    gPreditor->pSceneEditorManager = m_pSceneEditorManager.get();

    m_pChairTools = IChairloaderToolsPreditor::CreateInstance(gPreditor->pEngine->GetIChairToPreditor());
    m_pUI = std::make_unique<PreditorUI>();

    REGISTER_COMMAND("pr_DumpFlowNodes", &DumpFlowNodesCommand, 0, "");
}

void Main::Preditor::ShutdownGame()
{
    m_pUI = nullptr;
    m_pChairTools = nullptr;

    m_pSceneEditorManager = nullptr;

    gPreditor->pInput = nullptr;
    m_pInput = nullptr;
}

void Main::Preditor::ShutdownSystem()
{
    CRY_ASSERT(gCL->pSceneEditor == this);
    gCL->pSceneEditor = nullptr;
    gPreditor->pAssetSystem = nullptr;
}

void Main::Preditor::Update()
{
    UpdateTime();
    gPreditor->pAssetSystem->Update();
    gPreditor->pInput->Update();
    m_pUserSettings->Update();
}

void Main::Preditor::ShowUI()
{
    m_pUI->ShowUI();
}

bool Main::Preditor::IsInSceneView() const
{
    return gPreditor->pViewportWindow->IsInSceneViewport();
}

void Main::Preditor::UpdateTime()
{
    CTimeValue nCurrentTime = gEnv->pTimer->GetAsyncTime();
    m_Time.nTimeDelta = nCurrentTime - m_Time.nTime;
    m_Time.nTime = nCurrentTime;

    m_Time.flTime = m_Time.nTime.GetSeconds();
    m_Time.flTimeDelta = m_Time.nTimeDelta.GetSeconds();
}
