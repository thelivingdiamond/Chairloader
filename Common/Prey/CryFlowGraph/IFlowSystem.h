// Header file automatically created from a PDB.

#pragma once
#include <boost/variant.hpp>
#include <Prey/CryCore/StdAfx.h>
#include <Prey/CryCore/functor.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryFlowGraph/SFlowSystemVoid.h>
#include <Chairloader/PreyFunction.h>

typedef uint8  TFlowPortId;
typedef uint16 TFlowNodeId;
typedef uint16 TFlowNodeTypeId;
typedef uint32 TFlowGraphId;
typedef int    TFlowSystemContainerId;

static const TFlowNodeId InvalidFlowNodeId = ~TFlowNodeId(0);
static const TFlowPortId InvalidFlowPortId = ~TFlowPortId(0);
static const TFlowNodeTypeId InvalidFlowNodeTypeId = 0; //!< Must be 0 - FlowSystem.cpp relies on it.
static const TFlowGraphId InvalidFlowGraphId = ~TFlowGraphId(0);
static const TFlowSystemContainerId InvalidContainerId = ~TFlowSystemContainerId(0);


struct SInputPortConfig;
struct SOutputPortConfig;

enum EHyperNodeFlags
{
    EHYPER_NODE_ENTITY        = 0x0001,
    EHYPER_NODE_ENTITY_VALID  = 0x0002,
    EHYPER_NODE_GRAPH_ENTITY  = 0x0004,    // This node targets graph default entity.
    EHYPER_NODE_GRAPH_ENTITY2 = 0x0008,    // Second graph default entity.
    EHYPER_NODE_INSPECTED     = 0x0010,    // Node is being inspected [dynamic, visual-only hint]
    EHYPER_NODE_HIDE_UI       = 0x0100,    // Not visible in components tree.
    EHYPER_NODE_CUSTOM_COLOR1 = 0x0200,    // Custom Color1
    EHYPER_NODE_UNREMOVEABLE  = 0x0400,    // Node cannot be deleted by user
};


// Header: MadeUp
// _unknown/SFlowNodeConfig.h
struct SFlowNodeConfig // Id=8001C3F Size=40
{
    SInputPortConfig const *pInputPorts;
    SOutputPortConfig const *pOutputPorts;
    unsigned nFlags;
    const char *sDescription;
    const char *sUIClassName;

#if 0
    void SetCategory(unsigned arg0);
	unsigned GetCategory() const;
	unsigned GetCoreFlags() const;
	unsigned GetUsageFlags() const;
	unsigned GetTypeFlags() const;
#endif
};

class ICrySizer;
struct IFlowNode;
TYPEDEF_AUTOPTR(IFlowNode);
typedef IFlowNode_AutoPtr IFlowNodePtr;

class TFlowInputData;
struct IFlowNode
{
    struct SActivationInfo // Id=8000F62 Size=48
    {
        IFlowGraph *pGraph = nullptr;
        uint16_t myID = 0;
        IEntity *pEntity = nullptr;
        uint8_t connectPort = 0;
        TFlowInputData *pInputPorts = nullptr;
        void *m_pUserData = nullptr;

#if 0
        void __dflt_ctor_closure();
#endif
    };

    enum EFlowEvent
    {
        eFE_Update,
        eFE_Activate,               //!< Sent if one or more input ports have been activated.
        eFE_FinalActivate,          //!< Must be eFE_Activate+1 (same as activate, but at the end of FlowSystem:Update).
        eFE_PrecacheResources,      //!< Called after flow graph loading to precache resources inside flow nodes.
        eFE_Initialize,             //!< Sent once after level has been loaded. it is NOT called on Serialization!.
        eFE_FinalInitialize,        //!< Must be eFE_Initialize+1.
        eFE_SetEntityId,            //!< This event is send to set the entity of the FlowNode. Might also be sent in conjunction (pre) other events (like eFE_Initialize).
        eFE_Suspend,
        eFE_Resume,
        eFE_EditorInputPortDataSet,
        eFE_ConnectInputPort,
        eFE_DisconnectInputPort,
        eFE_ConnectOutputPort,
        eFE_DisconnectOutputPort,
        eFE_DontDoAnythingWithThisPlease
    };

    IFlowNode() = default;


    // <interfuscator:shuffle>
    virtual ~IFlowNode(){}

    //! Provides base copy and move semantic without copying ref count in _i_reference_target_t
    IFlowNode(IFlowNode const&) { }

    //! Provides base copy and move semantic without copying ref count in _i_reference_target_t
    IFlowNode& operator= (IFlowNode const&) { return *this; }

    //! notification to be overridden in C# flow node
//    virtual void OnDelete() const {}


    virtual void AddRef() = 0;
    //! override to kick off a notification for C# flow node.
    //! to be removed when we get rid of C# flow node completely
    virtual void Release() = 0;

    virtual _smart_ptr<IFlowNode> Clone(SActivationInfo*) = 0;

    virtual void         GetConfiguration(SFlowNodeConfig&) = 0;
    virtual bool         SerializeXML(SActivationInfo*, const XmlNodeRef& root, bool reading) = 0;
    virtual void         Serialize(SActivationInfo*, TSerialize ser) = 0;
    virtual void         PostSerialize(SActivationInfo*) = 0;
    virtual void         ProcessEvent(EFlowEvent event, SActivationInfo*) = 0;

    virtual void         GetMemoryUsage(ICrySizer* s) const = 0;

    //! Used to return the global UI enum name to use for the given input port, if the port defines a UI enum of type 'enum_global_def'.
    //! \param[in] portId The input port Id for which to determine the global enum name.
    //! \param[in] pNodeEntity Current entity attached to the node.
    //! \param[in] szName The common name defined with the port (enum_global_def:commonName).
    //! \param[out] outGlobalEnum The global enum name to use for this port.
    //! \param[in] globalEnumMaxSize Maximum size of the possible resulting outGlobalEnum name (including null-terminated character).
    //! \returns true if a global enum name was determined and should be used. Otherwise the common name is used.
    virtual bool GetPortGlobalEnum(uint32 portId, IEntity* pNodeEntity, const char* szName, char* outGlobalEnum, size_t globalEnumMaxSize) const { return false; }

    // </interfuscator:shuffle>
};

struct IFlowNodeFactory // Id=8001C5D Size=8
{
    virtual ~IFlowNodeFactory();
    virtual void AddRef() = 0;
    virtual void Release() = 0;
    virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo *arg0) = 0;
    virtual void GetMemoryUsage(ICrySizer *arg0) const = 0;
    virtual void Reset() = 0;
    virtual bool AllowOverride() const { return FAllowOverride(this); }

    static inline auto FAllowOverride = PreyFunction<bool(IFlowNodeFactory const *const _this)>(0xDD23F0);
};


// Header: Exact
// CryEngine/crycommon/iflowsystem.h
class TFlowInputData // Id=8001C01 Size=32
{
public:
    class IsSameType // Id=8001C02 Size=1
    {
    public:
        class StrictlyEqual : public boost::static_visitor<bool> // Id=8001C03 Size=1
        {
        public:
        };

#if 0
        bool operator()(TFlowInputData const &arg0, TFlowInputData const &arg1) const;
#endif
    };

    class IsEqual // Id=8001C05 Size=1
    {
    public:
        class StrictlyEqual : public boost::static_visitor<bool> // Id=8001C06 Size=1
        {
        public:
        };

#if 0
        bool operator()(TFlowInputData const &arg0, TFlowInputData const &arg1) const;
#endif
    };

    class ExtractType : public boost::static_visitor<EFlowDataTypes> // Id=8001C07 Size=1
    {
    public:
    };

    class ConvertType_SetFlexi : public boost::static_visitor<bool> // Id=8001C09 Size=8
    {
    public:
        TFlowInputData &to;
    };

    class WriteType : public boost::static_visitor<void> // Id=8001C0A Size=24
    {
    public:
        TSerialize m_ser;
        bool m_userFlag;
    };

    class LoadType : public boost::static_visitor<void> // Id=8001C0B Size=16
    {
    public:
        TSerialize m_ser;
    };

    class MemStatistics : public boost::static_visitor<void> // Id=8001C0C Size=8
    {
    public:
        ICrySizer *m_pSizer;
    };

    boost::variant<boost::detail::variant::over_sequence<boost::mpl::l_item<boost::mpl::long_<7>,SFlowSystemVoid,boost::mpl::l_item<boost::mpl::long_<6>,int,boost::mpl::l_item<boost::mpl::long_<5>,float,boost::mpl::l_item<boost::mpl::long_<4>,unsigned int,boost::mpl::l_item<boost::mpl::long_<3>,Vec3,boost::mpl::l_item<boost::mpl::long_<2>,string,boost::mpl::l_item<boost::mpl::long_<1>,bool,boost::mpl::l_end>>>>>>>>> m_variant;
    bool m_userFlag : 1;
    bool m_locked : 1;

    TFlowInputData(TFlowInputData const &rhs);
    TFlowInputData &operator=(TFlowInputData const &rhs) { return FoperatorEq(this,rhs); }
    bool SetValueWithConversion(TFlowInputData const &value) { return FSetValueWithConversion(this,value); }
    void Serialize(TSerialize ser) { FSerialize(this,ser); }

#if 0
    static TFlowInputData CreateDefaultInitializedForTag(int arg0, bool arg1);
	bool operator==(TFlowInputData const &arg0) const;
	bool operator!=(TFlowInputData const &arg0) const;
	bool SetDefaultForTag(int arg0);
	EFlowDataTypes GetType() const;
	bool IsUserFlagSet() const;
	void SetUserFlag(bool arg0);
	void ClearUserFlag();
	bool IsLocked() const;
	void SetLocked();
	void SetUnlocked();
	void GetMemoryStatistics(ICrySizer *arg0) const;
	void GetMemoryUsage(ICrySizer *arg0) const;
#endif

    static inline auto FoperatorEq = PreyFunction<TFlowInputData &(TFlowInputData *const _this, TFlowInputData const &rhs)>(0x34A240);
    static inline auto FSetValueWithConversion = PreyFunction<bool(TFlowInputData *const _this, TFlowInputData const &value)>(0x415180);
    static inline auto FSerialize = PreyFunction<void(TFlowInputData *const _this, TSerialize ser)>(0x2AF660);
};

// Header: MadeUp
// _unknown/SInputPortConfig.h
struct SInputPortConfig // Id=8001C40 Size=64
{
    const char *name;
    const char *humanName;
    const char *description;
    const char *sUIConfig;
    TFlowInputData defaultData;

#if 0
    void GetMemoryUsage(ICrySizer *arg0) const;
#endif
};


struct SOutputPortConfig // Id=8001C41 Size=32
{
    const char *name;
    const char *humanName;
    const char *description;
    int type;

#if 0
    void GetMemoryUsage(ICrySizer *arg0) const;
#endif
};


// Header: Exact
// CryEngine/crycommon/iflowsystem.h
template <typename T> struct DefaultInitializedForTag/*<boost::mpl::v_iter<boost::mpl::vector7<SFlowSystemVoid,int,float,unsigned int,Vec3,string,bool>,2>>*/ // Id=80036A5 Size=1
{
#if 0
    bool operator()(int tag, boost::variant<boost::detail::variant::over_sequence<boost::mpl::l_item<boost::mpl::long_<7>,SFlowSystemVoid,boost::mpl::l_item<boost::mpl::long_<6>,int,boost::mpl::l_item<boost::mpl::long_<5>,float,boost::mpl::l_item<boost::mpl::long_<4>,unsigned int,boost::mpl::l_item<boost::mpl::long_<3>,Vec3,boost::mpl::l_item<boost::mpl::long_<2>,string,boost::mpl::l_item<boost::mpl::long_<1>,bool,boost::mpl::l_end>>>>>>>>> &v) const;
#endif
};

#if 0
// Header: Exact
// CryEngine/crycommon/iflowsystem.h
template <typename T> struct DefaultInitializedForTag/*<boost::mpl::v_iter<boost::mpl::vector7<SFlowSystemVoid,int,float,unsigned int,Vec3,string,bool>,5>>*/ // Id=80036AB Size=1
{
#if 0
    bool operator()(int tag, boost::variant<boost::detail::variant::over_sequence<boost::mpl::l_item<boost::mpl::long_<7>,SFlowSystemVoid,boost::mpl::l_item<boost::mpl::long_<6>,int,boost::mpl::l_item<boost::mpl::long_<5>,float,boost::mpl::l_item<boost::mpl::long_<4>,unsigned int,boost::mpl::l_item<boost::mpl::long_<3>,Vec3,boost::mpl::l_item<boost::mpl::long_<2>,string,boost::mpl::l_item<boost::mpl::long_<1>,bool,boost::mpl::l_end>>>>>>>>> &v) const;
#endif
};
#endif

struct IFlowNodeTypeIterator // Id=8001C5F Size=8
{
    struct SNodeType // Id=8001C60 Size=16
    {
        uint16_t typeId;
        const char *typeName;
    };

    virtual ~IFlowNodeTypeIterator();
    virtual void AddRef() = 0;
    virtual void Release() = 0;
    virtual bool Next(IFlowNodeTypeIterator::SNodeType &arg0) = 0;
};


struct SFlowAddress // Id=8000F55 Size=4
{
    uint16_t node;
    uint8_t port;
    bool isOutput;

#if 0
    bool operator==(SFlowAddress const &arg0) const;
	bool operator!=(SFlowAddress const &arg0) const;
#endif
};

// Header: MadeUp
// _unknown/IFlowGraphInspector.h
struct IFlowGraphInspector // Id=8001C62 Size=8
{
    struct IFilter // Id=8001C63 Size=8
    {
        enum EFilterResult
        {
            eFR_DontCare = 0,
            eFR_Block = 1,
            eFR_Pass = 2,
        };

        virtual ~IFilter();
        virtual void AddRef() = 0;
        virtual void Release() = 0;
        virtual void AddFilter(_smart_ptr<IFlowGraphInspector::IFilter> arg0) = 0;
        virtual void RemoveFilter(_smart_ptr<IFlowGraphInspector::IFilter> arg0) = 0;
        virtual IFlowGraphInspector::IFilter::EFilterResult Apply(IFlowGraph *arg0, SFlowAddress arg1, SFlowAddress arg2) = 0;
    };

    using IFilter_AutoPtr = _smart_ptr<IFlowGraphInspector::IFilter>;
    using IFilter_AutoArray = std::vector<_smart_ptr<IFlowGraphInspector::IFilter>>;
    using IFilterPtr = _smart_ptr<IFlowGraphInspector::IFilter>;

    virtual ~IFlowGraphInspector();
    virtual void AddRef() = 0;
    virtual void Release() = 0;
    virtual void PreUpdate(IFlowGraph *arg0) = 0;
    virtual void PostUpdate(IFlowGraph *arg0) = 0;
    virtual void NotifyFlow(IFlowGraph *arg0, SFlowAddress arg1, SFlowAddress arg2) = 0;
    virtual void NotifyProcessEvent(IFlowNode::EFlowEvent arg0, IFlowNode::SActivationInfo *arg1, IFlowNode *arg2) = 0;
    virtual void AddFilter(_smart_ptr<IFlowGraphInspector::IFilter> arg0) = 0;
    virtual void RemoveFilter(_smart_ptr<IFlowGraphInspector::IFilter> arg0) = 0;
    virtual void GetMemoryUsage(ICrySizer *arg0) const = 0;
};
struct IFlowGraphModuleListener;
struct IFlowGraphModule;
struct IFlowGraphModuleIterator;

struct IFlowGraphModuleManager // Id=8001C72 Size=8
{
    virtual ~IFlowGraphModuleManager();
    virtual bool RegisterListener(IFlowGraphModuleListener *arg0, const char *arg1) = 0;
    virtual void UnregisterListener(IFlowGraphModuleListener *arg0) = 0;
    virtual bool DeleteModuleXML(const char *arg0) = 0;
    virtual bool RenameModuleXML(const char *arg0, const char *arg1) = 0;
    virtual _smart_ptr<IFlowGraphModuleIterator> CreateModuleIterator() = 0;
    virtual const char *GetStartNodeName(const char *arg0) const = 0;
    virtual const char *GetReturnNodeName(const char *arg0) const = 0;
    virtual const char *GetCallerNodeName(const char *arg0) const = 0;
    virtual void ScanForModules() = 0;
    virtual const char *GetModulePath(const char *arg0) = 0;
    virtual bool SaveModule(const char *arg0, XmlNodeRef arg1) = 0;
    virtual IFlowGraphModule *LoadModuleFile(const char *arg0, const char *arg1, bool arg2) = 0;
    virtual IFlowGraphModule *GetModule(_smart_ptr<IFlowGraph> arg0) const = 0;
    virtual IFlowGraphModule *GetModule(const char *arg0) const = 0;
    virtual IFlowGraphModule *GetModule(unsigned arg0) const = 0;
    virtual unsigned CreateModuleInstance(unsigned arg0, DynArray<TFlowInputData,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > const &arg1,  Functor2<bool,DynArray<TFlowInputData,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > const &> const &arg2) = 0;
    virtual unsigned CreateModuleInstance(unsigned arg0, unsigned arg1, uint16_t arg2, DynArray<TFlowInputData,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > const &arg3, Functor2<bool,DynArray<TFlowInputData,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > const &> const &arg4) = 0;
    virtual bool CreateModuleNodes(const char *arg0, unsigned arg1) = 0;
};

class IArkGlobalAction;
class IArkGlobalActionManager;

struct IFlowSystemContainer // Id=8001C87 Size=8
{
    virtual ~IFlowSystemContainer();
    virtual void AddItem(TFlowInputData arg0) = 0;
    virtual void AddItemUnique(TFlowInputData arg0) = 0;
    virtual void RemoveItem(TFlowInputData arg0) = 0;
    virtual TFlowInputData GetItem(int arg0) = 0;
    virtual void Clear() = 0;
    virtual void RemoveItemAt(int arg0) = 0;
    virtual int GetItemCount() const = 0;
    virtual void GetMemoryUsage(ICrySizer *arg0) const = 0;
    virtual void Serialize(TSerialize arg0) = 0;
};

struct IFlowSystem // Id=8000F51 Size=8
{
    virtual ~IFlowSystem();
    virtual void Release() = 0;
    virtual void Update() = 0;
    virtual void Reset(bool arg0) = 0;
    virtual void Enable(bool arg0) = 0;
    virtual void ReloadAllNodeTypes() = 0;
    virtual _smart_ptr<IFlowGraph> CreateFlowGraph() = 0;
    virtual uint16_t RegisterType(const char *arg0, _smart_ptr<IFlowNodeFactory> arg1) = 0;
    virtual bool UnregisterType(const char *arg0) = 0;
    virtual const char *GetTypeName(uint16_t arg0) = 0;
    virtual uint16_t GetTypeId(const char *arg0) = 0;
    virtual _smart_ptr<IFlowNodeTypeIterator> CreateNodeTypeIterator() = 0;
    virtual void RegisterInspector(_smart_ptr<IFlowGraphInspector> arg0, _smart_ptr<IFlowGraph> arg1) = 0;
    virtual void UnregisterInspector(_smart_ptr<IFlowGraphInspector> arg0, _smart_ptr<IFlowGraph> arg1) = 0;
    virtual _smart_ptr<IFlowGraphInspector> GetDefaultInspector() const = 0;
    virtual void EnableInspecting(bool arg0) = 0;
    virtual bool IsInspectingEnabled() const = 0;
    virtual bool IsConsoleFlowNodesEnabled() const = 0;
    virtual IFlowGraph *GetGraphById(unsigned arg0) = 0;
    virtual void OnEntityIdChanged(unsigned arg0, unsigned arg1) = 0;
    virtual void GetMemoryUsage(ICrySizer *arg0) const = 0;
    virtual IFlowGraphModuleManager *GetIModuleManager() = 0;
    virtual IArkGlobalActionManager &GetIArkGlobalActionManager() = 0;
    virtual bool CreateContainer(int arg0) = 0;
    virtual void DeleteContainer(int arg0) = 0;
    virtual std::shared_ptr<IFlowSystemContainer> GetContainer(int arg0) = 0;
    virtual void Serialize(TSerialize arg0) = 0;
};

