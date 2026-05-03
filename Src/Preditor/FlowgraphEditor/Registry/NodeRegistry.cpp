#include <algorithm>
#include <Prey/CryAction/flowsystem/flowsystem.h>
#include <Prey/CryAction/flowsystem/nodes/flowbasenode.h>
#include "NodeRegistry.h"

namespace FlowgraphEditor
{

namespace
{

//! Minimal IFlowGraph stub used as the parent during prototype scraping.
//! Some node ctors dereference SActivationInfo::pGraph — this gives them
//! a no-op target so we can read SFlowNodeConfig without a real graph.
class StubFlowGraph : public IFlowGraph
{
public:
    virtual void DoActivatePort(SFlowAddress, NFlowSystemUtils::Wrapper<SFlowSystemVoid> const&) {}
    virtual void DoActivatePort(SFlowAddress, NFlowSystemUtils::Wrapper<int> const&) {}
    virtual void DoActivatePort(SFlowAddress, NFlowSystemUtils::Wrapper<float> const&) {}
    virtual void DoActivatePort(SFlowAddress, NFlowSystemUtils::Wrapper<unsigned int> const&) {}
    virtual void DoActivatePort(SFlowAddress, NFlowSystemUtils::Wrapper<Vec3> const&) {}
    virtual void DoActivatePort(SFlowAddress, NFlowSystemUtils::Wrapper<string> const&) {}
    virtual void DoActivatePort(SFlowAddress, NFlowSystemUtils::Wrapper<bool> const&) {}

    virtual void AddRef() {}
    virtual void Release() {}
    virtual _smart_ptr<IFlowGraph> Clone() { return nullptr; }
    virtual void Clear() {}
    virtual _smart_ptr<IFlowNodeIterator> CreateNodeIterator() { return nullptr; }
    virtual _smart_ptr<IFlowEdgeIterator> CreateEdgeIterator() { return nullptr; }
    virtual void SetGraphEntity(unsigned, int) {}
    virtual unsigned GetGraphEntity(int) const { return 0; }
    virtual void SetEnabled(bool) {}
    virtual bool IsEnabled() const { return false; }
    virtual void SetActive(bool) {}
    virtual bool IsActive() const { return false; }
    virtual void UnregisterFromFlowSystem() {}
    virtual void SetType(IFlowGraph::EFlowGraphType) {}
    virtual IFlowGraph::EFlowGraphType GetType() const { return eFGT_Default; }
    virtual void Update() {}
    virtual bool SerializeXML(XmlNodeRef const&, bool) { return false; }
    virtual void Serialize(TSerialize) {}
    virtual void PostSerialize() {}
    virtual void InitializeValues() {}
    virtual void PrecacheResources() {}
    virtual void EnsureSortedEdges() {}
    virtual SFlowAddress ResolveAddress(const char*, bool)
    {
        SFlowAddress a;
        memset(&a, 0, sizeof(a));
        return a;
    }
    virtual uint16_t ResolveNode(const char*) { return 0; }
    virtual uint16_t CreateNode(uint16_t, const char*, void*) { return 0; }
    virtual uint16_t CreateNode(const char*, const char*, void*) { return 0; }
    virtual IFlowNodeData* GetNodeData(uint16_t) { return nullptr; }
    virtual bool SetNodeName(uint16_t, const char*) { return false; }
    virtual const char* GetNodeName(uint16_t) { return nullptr; }
    virtual uint16_t GetNodeTypeId(uint16_t) { return 0; }
    virtual const char* GetNodeTypeName(uint16_t) { return nullptr; }
    virtual void RemoveNode(const char*) {}
    virtual void RemoveNode(uint16_t) {}
    virtual void SetUserData(uint16_t, XmlNodeRef const&) {}
    virtual XmlNodeRef GetUserData(uint16_t) { return nullptr; }
    virtual bool LinkNodes(SFlowAddress, SFlowAddress) { return false; }
    virtual void UnlinkNodes(SFlowAddress, SFlowAddress) {}
    virtual void RegisterFlowNodeActivationListener(SFlowNodeActivationListener*) {}
    virtual void RemoveFlowNodeActivationListener(SFlowNodeActivationListener*) {}
    virtual bool NotifyFlowNodeActivationListeners(uint16_t, uint8_t, uint16_t, uint8_t, const char*) { return false; }
    virtual void SetEntityId(uint16_t, unsigned) {}
    virtual unsigned GetEntityId(uint16_t) { return 0; }
    virtual _smart_ptr<IFlowGraph> GetClonedFlowGraph() const { return nullptr; }
    virtual void GetNodeConfiguration(uint16_t, SFlowNodeConfig&) {}
    virtual void SetRegularlyUpdated(uint16_t, bool) {}
    virtual void RequestFinalActivation(uint16_t) {}
    virtual void ActivateNode(uint16_t) {}
    virtual void ActivatePortAny(SFlowAddress, TFlowInputData const&) {}
    virtual void ActivatePortCString(SFlowAddress, const char*) {}
    virtual bool SetInputValue(uint16_t, uint8_t, TFlowInputData const&) { return false; }
    virtual bool IsOutputConnected(SFlowAddress) { return false; }
    virtual TFlowInputData const* GetInputValue(uint16_t, uint8_t) { return nullptr; }
    virtual bool GetActivationInfo(const char*, IFlowNode::SActivationInfo&) { return false; }
    virtual void SetSuspended(bool) {}
    virtual bool IsSuspended() const { return false; }
    virtual void SetCustomAction(ICustomAction*) {}
    virtual ICustomAction* GetCustomAction() const { return nullptr; }
    virtual void GetMemoryUsage(ICrySizer*) const {}
    virtual void RemoveGraphTokens(bool) {}
    virtual bool UpdateGraphToken(int, const char*, EFlowDataTypes) { return false; }
    virtual bool LoadGraphToken(int, const char*, EFlowDataTypes) { return false; }
    virtual int CloneGraphToken(IFlowGraph::SGraphToken const&) { return 0; }
    virtual uint64_t GetGraphTokenCount() const { return 0; }
    virtual IFlowGraph::SGraphToken const* GetGraphToken(uint64_t) const { return nullptr; }
    virtual unsigned GetGraphId() const { return 0; }
    virtual void OnNodeConfigReload(IFlowNodeData&) {}
    virtual void SetOwningModule(IFlowGraphModule*) {}
    virtual IFlowGraphModule* GetOwningModule() const { return nullptr; }
    virtual void FixCreatePhantomRequestEntityIdOutput(SFlowAddress, unsigned) {}
};

void ExtractInputPort(const SInputPortConfig& src, PrototypePort& dst)
{
    dst.name        = src.name        ? src.name        : "";
    dst.humanName   = src.humanName   ? src.humanName   : "";
    dst.description = src.description ? src.description : "";
    dst.uiConfig    = src.sUIConfig   ? src.sUIConfig   : "";
    dst.type = FlowDataTypeFromEngine(static_cast<int>(src.defaultData.GetType()));
}

void ExtractOutputPort(const SOutputPortConfig& src, PrototypePort& dst)
{
    dst.name        = src.name        ? src.name        : "";
    dst.humanName   = src.humanName   ? src.humanName   : "";
    dst.description = src.description ? src.description : "";
    dst.type = FlowDataTypeFromEngine(src.type);
}

template <typename PortConfig, typename Extractor>
void ExtractPortArray(const PortConfig* portArray,
                      std::vector<PrototypePort>& dst,
                      Extractor extract)
{
    if (!portArray)
        return;
    for (const PortConfig* p = portArray; p->name != nullptr; ++p)
    {
        PrototypePort port;
        extract(*p, port);
        dst.push_back(std::move(port));
    }
}

std::unique_ptr<PrototypeNode> ScrapeOne(CFlowSystem& flowSystem,
                                         std::string className,
                                         uint16_t typeId,
                                         StubFlowGraph& stubGraph)
{
    IFlowNode::SActivationInfo info{};
    info.pGraph = &stubGraph;

    auto pNode = flowSystem.CreateNodeOfType(&info, typeId);
    if (!pNode)
        return nullptr;

    SFlowNodeConfig cfg{};
    pNode->GetConfiguration(cfg);

    auto proto = std::make_unique<PrototypeNode>();
    proto->className = std::move(className);
    proto->description = cfg.sDescription ? cfg.sDescription : "";
    proto->engineFlags = cfg.nFlags;
    proto->categoryKey = CategoryKeyFromClassName(proto->className);
    ExtractPortArray(cfg.pInputPorts,  proto->inputs,  ExtractInputPort);
    ExtractPortArray(cfg.pOutputPorts, proto->outputs, ExtractOutputPort);

    // Let the _smart_ptr destruct: refcount drops to zero, the node is
    // destroyed, and it unhooks from any engine update lists it joined.
    // Do NOT call ReleaseOwnership() here — Cry's smart_ptr leaks the ref.
    return proto;
}

} // anonymous namespace

NodeRegistry& NodeRegistry::Get()
{
    static NodeRegistry s_instance;
    return s_instance;
}

bool NodeRegistry::EnsureLoaded()
{
    if (m_bLoaded)
        return true;
    if (!gEnv || !gEnv->pFlowSystem)
        return false;
    LoadFromEngine();
    EnsureEditorPrototypes();
    m_bLoaded = true;
    return true;
}

void NodeRegistry::EnsureEditorPrototypes()
{
    // Commentbox is editor-only decoration. The engine may or may not register
    // it depending on build; ensure the palette always has one regardless.
    if (!Find("_commentbox"))
    {
        auto proto = std::make_unique<PrototypeNode>();
        proto->className   = "_commentbox";
        proto->description = "Commentbox — decorative group rectangle for organizing nearby nodes.";
        proto->categoryKey = "comment";

        auto addInput = [&](const char* name, FlowDataType type, const char* desc) {
            PrototypePort port;
            port.name        = name;
            port.type        = type;
            port.description = desc;
            proto->inputs.push_back(std::move(port));
        };
        addInput("TextSize",      FlowDataType::Float, "Label font size multiplier");
        addInput("Color",         FlowDataType::Vec3,  "Tint color (RGB 0..1)");
        addInput("DisplayFilled", FlowDataType::Bool,  "Fill the rectangle");
        addInput("DisplayBox",    FlowDataType::Bool,  "Draw the rectangle border");
        addInput("SortPriority",  FlowDataType::Int,   "Z-order among commentboxes");

        AddSynthetic(std::move(proto));
    }
}

void NodeRegistry::LoadFromEngine()
{
    auto* flowSystem = static_cast<CFlowSystem*>(gEnv->pFlowSystem);

    // Static so it outlives the scrape — defense in depth in case a node holds
    // onto its parent-graph pointer past its own destructor.
    static StubFlowGraph s_stubGraph;
    size_t failed = 0;

    for (const auto& [name, typeId] : flowSystem->m_typeNameToIdMap)
    {
        // typeId 0 (InvalidFlowNodeTypeId) is a reserved sentinel registered as
        // "InvalidType"; CreateNodeOfType will correctly refuse it. Skip silently.
        if (typeId == InvalidFlowNodeTypeId)
            continue;

        std::string className = name.c_str();
        auto proto = ScrapeOne(*flowSystem, className, typeId, s_stubGraph);
        if (!proto)
        {
            ++failed;
            CryLog("FlowgraphEditor: failed to scrape prototype '{}'", className);
            continue;
        }
        m_All.push_back(std::move(proto));
    }

    RebuildIndices();
    CryLog("FlowgraphEditor: loaded {} prototypes from engine ({} failed)",
           m_All.size(), failed);
}

void NodeRegistry::RebuildIndices()
{
    m_ByClass.clear();
    m_ByCategory.clear();

    for (auto& proto : m_All)
    {
        m_ByClass[proto->className] = proto.get();
        m_ByCategory[proto->categoryKey].push_back(proto.get());
    }

    for (auto& [key, vec] : m_ByCategory)
    {
        std::sort(vec.begin(), vec.end(),
                  [](const PrototypeNode* a, const PrototypeNode* b) {
                      return a->className < b->className;
                  });
    }
}

const PrototypeNode* NodeRegistry::Find(std::string_view className) const
{
    auto it = m_ByClass.find(std::string(className));
    return it != m_ByClass.end() ? it->second : nullptr;
}

const std::vector<const PrototypeNode*>& NodeRegistry::InCategory(std::string_view categoryKey) const
{
    static const std::vector<const PrototypeNode*> kEmpty;
    auto it = m_ByCategory.find(categoryKey);
    return it != m_ByCategory.end() ? it->second : kEmpty;
}

void NodeRegistry::AddSynthetic(std::unique_ptr<PrototypeNode> proto)
{
    if (!proto)
        return;
    m_All.push_back(std::move(proto));
    RebuildIndices();
}

} // namespace FlowgraphEditor
