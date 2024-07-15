#include "PreditorFlowgraph.h"
#include "Node.h"

namespace
{

//! Null IFlowGraph implementation so the engine doesn't crash.
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

} // namespace

std::shared_ptr<PrototypeNode> FGE::PreditorFlowgraph::AddUnknownPrototype(const PrototypeNodeClass& nodeClass)
{
    auto node = std::make_shared<PrototypeNode>();
    node->Class = nodeClass;
    node->Category = PrototypeNode::nodeCategory::UNKNOWN;
    m_PrototypeNodes.insert(std::pair(node->Class, node));
    return node;
}

void FGE::PreditorFlowgraph::AddPinToPrototype(const PrototypeNodeClass& nodeClass, const PrototypePin& pin)
{
    auto node = m_PrototypeNodes.find(nodeClass);
    if (node != m_PrototypeNodes.end())
    {
        if (pin.Kind == PinKind::Input)
            node->second->ProtoInputs.push_back(pin);
        else
            node->second->ProtoOutputs.push_back(pin);
    }

    // TODO 2023-07-23: What this do?
    /*
    for (auto& file : m_BaseGameFlowgaphs)
    {
        for (auto& graph : file->m_FlowGraphs)
        {
            graph->refreshNodesOfClass(nodeClass);
        }
    }
    */
}

void FGE::PreditorFlowgraph::InitForEditor()
{
    if (m_IsInitialized)
        return;
    
    m_IsInitialized = true;
    LoadPrototypes();
}

void FGE::PreditorFlowgraph::LoadPrototypes()
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
