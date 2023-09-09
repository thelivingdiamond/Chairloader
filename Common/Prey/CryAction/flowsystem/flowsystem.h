// Header file automatically created from a PDB.

#pragma once
#include <Prey/cryaction/ark/ArkGlobalActionManager.h>
#include <Prey/CryCore/Containers/CryArray.h>
//#include <Prey/CryAction/FlowSystem/FlowSystem.cpp>
#include <Prey/CryAction/FlowSystem/FlowSystemCVars.h>
#include <Prey/CryCore/Containers/CryListenerSet.h>
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CrySystem/XML/IXml.h>

class ArkAiTreeInstanceNode;
class ArkAiTreeNode;
class CFlowGraphBase;
class CFlowGraphModuleManager;
class IArkGlobalActionManager;
class ICrySizer;
struct IEntity;
struct IFlowGraph;
struct IFlowGraphModuleManager;
struct IFlowNode;
struct SEntityEvent;
struct SEntitySpawnParams;

// Header: Exact
// CryEngine/cryaction/flowsystem/flowsystem.h
class CFlowSystem : public IFlowSystem, public IEntitySystemSink // Id=800467D Size=264
{
public:
	struct STypeInfo // Id=80047D0 Size=16
	{
		string name;
		_smart_ptr<IFlowNodeFactory> factory;
		
#if 0
		void GetMemoryUsage(ICrySizer *arg0) const;
#endif
	};

	bool m_bInspectingEnabled;
	bool m_needToUpdateForwardings;
	bool m_criticalLoadingErrorHappened;
	
	class CNodeTypeIterator : public IFlowNodeTypeIterator // Id=80047D1 Size=32
	{
	public:
		int m_nRefs;
		uint16_t m_id;
		CFlowSystem *m_pImpl;
		std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CFlowSystem::STypeInfo> > > m_iter;
		
		virtual void AddRef();
		virtual void Release();
		virtual bool Next(IFlowNodeTypeIterator::SNodeType &nodeType);
		virtual ~CNodeTypeIterator();
		
		static inline auto FAddRef = PreyFunction<void(CFlowSystem::CNodeTypeIterator *const _this)>(0x49B5B0);
		static inline auto FRelease = PreyFunction<void(CFlowSystem::CNodeTypeIterator *const _this)>(0x468370);
		static inline auto FNext = PreyFunction<bool(CFlowSystem::CNodeTypeIterator *const _this, IFlowNodeTypeIterator::SNodeType &nodeType)>(0x41AA90);
	};

	using TTypeNameToIdMap = std::map<string,unsigned short,std::less<string>,std::allocator<std::pair<CryStringT<char> const,unsigned short>>>;
	
	std::map<string,unsigned short,std::less<string>,std::allocator<std::pair<CryStringT<char> const,unsigned short>>> m_typeNameToIdMap;
	std::vector<CFlowSystem::STypeInfo> m_typeRegistryVec;
	
	using TGraphs = CListenerSet<CFlowGraphBase *>;
	
	CListenerSet<CFlowGraphBase *> m_graphs;
	std::vector<_smart_ptr<IFlowGraphInspector>> m_systemInspectors;
	std::vector<unsigned short> m_freeNodeTypeIDs;
	uint16_t m_nextNodeTypeID;
	_smart_ptr<IFlowGraphInspector> m_pDefaultInspector;
	CFlowSystemCVars m_cVars;
	unsigned m_nextFlowGraphId;
	CFlowGraphModuleManager *m_pModuleManager;
	ArkGlobalActionManager m_arkGlobalActionManager;
	
	using TFlowSystemContainerMap = std::map<int,std::shared_ptr<IFlowSystemContainer>,std::less<int>>;
	
	std::map<int,std::shared_ptr<IFlowSystemContainer>,std::less<int>> m_FlowSystemContainers;
	
	CFlowSystem();
	virtual ~CFlowSystem();
	virtual void Release();
	virtual void Update();
	virtual void Reset(bool unload);
	virtual void ReloadAllNodeTypes();
	virtual _smart_ptr<IFlowGraph> CreateFlowGraph();
	virtual uint16_t RegisterType(const char *type, _smart_ptr<IFlowNodeFactory> factory);
	virtual bool UnregisterType(const char *typeName);
	virtual const char *GetTypeName(uint16_t typeId);
	virtual uint16_t GetTypeId(const char *typeName);
	virtual _smart_ptr<IFlowNodeTypeIterator> CreateNodeTypeIterator();
	virtual void RegisterInspector(_smart_ptr<IFlowGraphInspector> pInspector, _smart_ptr<IFlowGraph> pGraph);
	virtual void UnregisterInspector(_smart_ptr<IFlowGraphInspector> pInspector, _smart_ptr<IFlowGraph> pGraph);
	virtual void EnableInspecting(bool bEnable);
	virtual bool IsInspectingEnabled() const;
	virtual _smart_ptr<IFlowGraphInspector> GetDefaultInspector() const;
	virtual IFlowGraph *GetGraphById(unsigned graphId);
	virtual void OnEntityIdChanged(unsigned oldId, unsigned newId);
	virtual void GetMemoryUsage(ICrySizer *pSizer) const;
	virtual bool IsConsoleFlowNodesEnabled() const;
	virtual bool CreateContainer(int id);
	virtual void DeleteContainer(int id);
	virtual std::shared_ptr<IFlowSystemContainer> GetContainer(int id);
	virtual void Serialize(TSerialize ser);
	virtual bool OnBeforeSpawn(SEntitySpawnParams &params);
	virtual void OnSpawn(IEntity *pEntity, SEntitySpawnParams &params);
	virtual bool OnRemove(IEntity *pEntity);
	virtual void OnReused(IEntity *pEntity, SEntitySpawnParams &params);
	virtual void OnEvent(IEntity *pEntity, SEntityEvent &event);
    _smart_ptr<IFlowNode> CreateNodeOfType(IFlowNode::SActivationInfo *pActInfo, uint16_t typeId)
    {
        _smart_ptr<IFlowNode> result;
        FCreateNodeOfType(this,&result,pActInfo,typeId);
        return result;
    }
	void PreInit() { FPreInit(this); }
	void Init() { FInit(this); }
	void Shutdown() { FShutdown(this); }
	virtual void Enable(bool enable);
	unsigned RegisterGraph(CFlowGraphBase *pGraph, const char *debugName) { return FRegisterGraph(this,pGraph,debugName); }
	void UnregisterGraph(CFlowGraphBase *pGraph) { FUnregisterGraph(this,pGraph); }
	virtual IFlowGraphModuleManager *GetIModuleManager();
	virtual IArkGlobalActionManager &GetIArkGlobalActionManager();
	void NotifyFlow(CFlowGraphBase *pGraph, SFlowAddress from, SFlowAddress to) { FNotifyFlow(this,pGraph,from,to); }
	CFlowSystem::STypeInfo const &GetTypeInfo(uint16_t typeId) const { return FGetTypeInfo(this,typeId); }
	void LoadExtensions(string path) { FLoadExtensions(this,path); }
	void LoadExtensionFromXml(XmlNodeRef nodeParent) { FLoadExtensionFromXml(this,nodeParent); }
	void RegisterAllNodeTypes() { FRegisterAllNodeTypes(this); }
	void RegisterEntityTypes() { FRegisterEntityTypes(this); }
	bool BlacklistedFlownode(const char **nodeName) { return FBlacklistedFlownode(this,nodeName); }
	void UpdateGraphs() { FUpdateGraphs(this); }
	
#if 0
	void ShowCriticalLoadingErrorWarning(const bool arg0);
	void GlobalActionsPostSerialize() const;
	CFlowGraphModuleManager *GetModuleManager();
	CFlowGraphModuleManager const *GetModuleManager() const;
	void NotifyProcessEvent(CFlowGraphBase *arg0, IFlowNode::EFlowEvent arg1, IFlowNode::SActivationInfo *arg2, IFlowNode *arg3);
	void RegisterAutoTypes();
	uint16_t GenerateNodeTypeID();
#endif
	
	static inline auto FBitNotCFlowSystem = PreyFunction<void(CFlowSystem *const _this)>(0x419120);
	static inline auto FRelease = PreyFunction<void(CFlowSystem *const _this)>(0x41B9B0);
	static inline auto FUpdate = PreyFunction<void(CFlowSystem *const _this)>(0x41C610);
	static inline auto FReset = PreyFunction<void(CFlowSystem *const _this, bool unload)>(0x41BBA0);
	static inline auto FReloadAllNodeTypes = PreyFunction<void(CFlowSystem *const _this)>(0xA13080);
	static inline auto FCreateFlowGraph = PreyFunction<_smart_ptr<IFlowGraph>(CFlowSystem *const _this)>(0x419A40);
	static inline auto FRegisterType = PreyFunction<uint16_t(CFlowSystem *const _this, const char *type, _smart_ptr<IFlowNodeFactory> factory)>(0x41B550);
	static inline auto FUnregisterType = PreyFunction<bool(CFlowSystem *const _this, const char *typeName)>(0x41C410);
	static inline auto FGetTypeName = PreyFunction<const char *(CFlowSystem *const _this, uint16_t typeId)>(0x41A3F0);
	static inline auto FGetTypeId = PreyFunction<uint16_t(CFlowSystem *const _this, const char *typeName)>(0x41A2F0);
	static inline auto FCreateNodeTypeIterator = PreyFunction<_smart_ptr<IFlowNodeTypeIterator>(CFlowSystem *const _this)>(0x419B10);
	static inline auto FRegisterInspector = PreyFunction<void(CFlowSystem *const _this, _smart_ptr<IFlowGraphInspector> pInspector, _smart_ptr<IFlowGraph> pGraph)>(0x41B480);
	static inline auto FUnregisterInspector = PreyFunction<void(CFlowSystem *const _this, _smart_ptr<IFlowGraphInspector> pInspector, _smart_ptr<IFlowGraph> pGraph)>(0x41C2B0);
	static inline auto FEnableInspecting = PreyFunction<void(CFlowSystem *const _this, bool bEnable)>(0x419BF0);
	static inline auto FIsInspectingEnabled = PreyFunction<bool(CFlowSystem const *const _this)>(0x10DE2E0);
	static inline auto FGetDefaultInspector = PreyFunction<_smart_ptr<IFlowGraphInspector>(CFlowSystem const *const _this)>(0x419CC0);
	static inline auto FGetGraphById = PreyFunction<IFlowGraph *(CFlowSystem *const _this, unsigned graphId)>(0x419CF0);
	static inline auto FOnEntityIdChanged = PreyFunction<void(CFlowSystem *const _this, unsigned oldId, unsigned newId)>(0x41ABE0);
	static inline auto FGetMemoryUsage = PreyFunction<void(CFlowSystem const *const _this, ICrySizer *pSizer)>(0x419EE0);
	static inline auto FIsConsoleFlowNodesEnabled = PreyFunction<bool(CFlowSystem const *const _this)>(0x41A450);
	static inline auto FCreateContainer = PreyFunction<bool(CFlowSystem *const _this, int id)>(0x4198B0);
	static inline auto FDeleteContainer = PreyFunction<void(CFlowSystem *const _this, int id)>(0x419B80);
	static inline auto FGetContainer = PreyFunction<std::shared_ptr<IFlowSystemContainer>(CFlowSystem *const _this, int id)>(0x419C00);
	static inline auto FSerialize = PreyFunction<void(CFlowSystem *const _this, TSerialize ser)>(0x41BD90);
	static inline auto FOnBeforeSpawn = PreyFunction<bool(CFlowSystem *const _this, SEntitySpawnParams &params)>(0x1B933B0);
	static inline auto FOnSpawn = PreyFunction<void(CFlowSystem *const _this, IEntity *pEntity, SEntitySpawnParams &params)>(0x41ADA0);
	static inline auto FOnRemove = PreyFunction<bool(CFlowSystem *const _this, IEntity *pEntity)>(0x1B933B0);
	static inline auto FOnReused = PreyFunction<void(CFlowSystem *const _this, IEntity *pEntity, SEntitySpawnParams &params)>(0x41ACC0);
	static inline auto FOnEvent = PreyFunction<void(CFlowSystem *const _this, IEntity *pEntity, SEntityEvent &event)>(0xA13080);
    static inline auto FCreateNodeOfType = PreyFunction<_smart_ptr<IFlowNode>* (CFlowSystem *const _this, _smart_ptr<IFlowNode> *result, IFlowNode::SActivationInfo *pActInfo, uint16_t typeId)>(0x419AB0);
	static inline auto FPreInit = PreyFunction<void(CFlowSystem *const _this)>(0x41ADD0);
	static inline auto FInit = PreyFunction<void(CFlowSystem *const _this)>(0x41A420);
	static inline auto FShutdown = PreyFunction<void(CFlowSystem *const _this)>(0x41C210);
	static inline auto FEnable = PreyFunction<void(CFlowSystem *const _this, bool enable)>(0x419BE0);
	static inline auto FRegisterGraph = PreyFunction<unsigned(CFlowSystem *const _this, CFlowGraphBase *pGraph, const char *debugName)>(0x41B420);
	static inline auto FUnregisterGraph = PreyFunction<void(CFlowSystem *const _this, CFlowGraphBase *pGraph)>(0x41C240);
	static inline auto FGetIModuleManager = PreyFunction<IFlowGraphModuleManager *(CFlowSystem *const _this)>(0x419DE0);
	static inline auto FGetIArkGlobalActionManager = PreyFunction<IArkGlobalActionManager &(CFlowSystem *const _this)>(0x10BD4D0);
	static inline auto FNotifyFlow = PreyFunction<void(CFlowSystem *const _this, CFlowGraphBase *pGraph, SFlowAddress from, SFlowAddress to)>(0x41AB30);
	static inline auto FGetTypeInfo = PreyFunction<CFlowSystem::STypeInfo const &(CFlowSystem const *const _this, uint16_t typeId)>(0x41A3C0);
	static inline auto FLoadExtensions = PreyFunction<void(CFlowSystem *const _this, string path)>(0x41A700);
	static inline auto FLoadExtensionFromXml = PreyFunction<void(CFlowSystem *const _this, XmlNodeRef nodeParent)>(0x41A460);
	static inline auto FRegisterAllNodeTypes = PreyFunction<void(CFlowSystem *const _this)>(0x41AE90);
	static inline auto FRegisterEntityTypes = PreyFunction<void(CFlowSystem *const _this)>(0x41B140);
	static inline auto FBlacklistedFlownode = PreyFunction<bool(CFlowSystem *const _this, const char **nodeName)>(0x419540);
	static inline auto FUpdateGraphs = PreyFunction<void(CFlowSystem *const _this)>(0x41C890);
};

// Header: FromCpp
// CryEngine/cryaction/flowsystem/flowsystem.h
struct CFlowSystemContainer : public IFlowSystemContainer // Id=8006922 Size=16
{
	DynArray<TFlowInputData,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > m_container;
	
	virtual void AddItem(TFlowInputData item);
	virtual void AddItemUnique(TFlowInputData item);
	virtual void RemoveItem(TFlowInputData item);
	virtual TFlowInputData GetItem(int i);
	virtual void RemoveItemAt(int i);
	virtual int GetItemCount() const;
	virtual void Clear();
	virtual void GetMemoryUsage(ICrySizer *s) const;
	virtual void Serialize(TSerialize ser);
	virtual ~CFlowSystemContainer();
	
	static inline auto FAddItem = PreyFunction<void(CFlowSystemContainer *const _this, TFlowInputData item)>(0x419430);
	static inline auto FAddItemUnique = PreyFunction<void(CFlowSystemContainer *const _this, TFlowInputData item)>(0x419490);
	static inline auto FRemoveItem = PreyFunction<void(CFlowSystemContainer *const _this, TFlowInputData item)>(0x41BA10);
	static inline auto FGetItem = PreyFunction<TFlowInputData(CFlowSystemContainer *const _this, int i)>(0x419DF0);
	static inline auto FRemoveItemAt = PreyFunction<void(CFlowSystemContainer *const _this, int i)>(0x41BB80);
	static inline auto FGetItemCount = PreyFunction<int(CFlowSystemContainer const *const _this)>(0x419E20);
	static inline auto FClear = PreyFunction<void(CFlowSystemContainer *const _this)>(0x4197B0);
	static inline auto FGetMemoryUsage = PreyFunction<void(CFlowSystemContainer const *const _this, ICrySizer *s)>(0x41A270);
	static inline auto FSerialize = PreyFunction<void(CFlowSystemContainer *const _this, TSerialize ser)>(0x41C080);
};

// Header: FromCpp
// CryEngine/cryaction/flowsystem/flowsystem.h
//class CSingletonFlowFactory<CFlowLogNode> : public IFlowNodeFactory // Id=8006923 Size=24
//{
//public:
//	_smart_ptr<IFlowNode> m_pInstance;
//	int m_refs;
//
//#if 0
//	virtual void AddRef();
//	virtual void Release();
//	virtual void GetMemoryUsage(ICrySizer *s) const;
//	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo *pActInfo);
//	virtual void Reset();
//	virtual ~CSingletonFlowFactory<CFlowLogNode>();
//#endif
//};

//// Header: FromCpp
//// CryEngine/cryaction/flowsystem/flowsystem.h
//class CAutoFlowFactory<CFlowStartNode> : public IFlowNodeFactory // Id=8006924 Size=16
//{
//public:
//	int m_refs;
//
//#if 0
//	virtual void AddRef();
//	virtual void Release();
//	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo *pActInfo);
//	virtual void GetMemoryUsage(ICrySizer *s) const;
//	virtual void Reset();
//	virtual ~CAutoFlowFactory<CFlowStartNode>();
//#endif
//};
//
//// Header: FromCpp
//// CryEngine/cryaction/flowsystem/flowsystem.h
//class CAutoFlowFactory<CFlowTrackEventNode> : public IFlowNodeFactory // Id=8006925 Size=16
//{
//public:
//	int m_refs;
//
//#if 0
//	virtual void AddRef();
//	virtual void Release();
//	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo *pActInfo);
//	virtual void GetMemoryUsage(ICrySizer *s) const;
//	virtual void Reset();
//	virtual ~CAutoFlowFactory<CFlowTrackEventNode>();
//#endif
//};

// Header: Exact
// CryEngine/cryaction/flowsystem/flowsystem.h
class ArkAiTreeInstanceNodeQueueElement // Id=8014370 Size=24
{
public:
	class Contains // Id=8014371 Size=8
	{
	public:
		ArkAiTreeNode const &m_node;
		
		Contains(ArkAiTreeNode const &_node);
		bool operator()(ArkAiTreeInstanceNodeQueueElement const &_elem) const { return FoperatorRBLRBR(this,_elem); }
		
		static inline auto FoperatorRBLRBR = PreyFunction<bool(ArkAiTreeInstanceNodeQueueElement::Contains const *const _this, ArkAiTreeInstanceNodeQueueElement const &_elem)>(0x10DE260);
	};

	class Empty // Id=8014372 Size=1
	{
	public:
		bool operator()(ArkAiTreeInstanceNodeQueueElement const &_elem) const { return FoperatorRBLRBR(this,_elem); }
		
		static inline auto FoperatorRBLRBR = PreyFunction<bool(ArkAiTreeInstanceNodeQueueElement::Empty const *const _this, ArkAiTreeInstanceNodeQueueElement const &_elem)>(0x10DE270);
	};

	class EmptyOrDoesNotSortBefore // Id=8014373 Size=8
	{
	public:
		const uint64_t m_traversalIndex;
		
		EmptyOrDoesNotSortBefore(ArkAiTreeNode const &_node);
		bool operator()(ArkAiTreeInstanceNodeQueueElement const &_elem) const { return FoperatorRBLRBR(this,_elem); }
		
		static inline auto FoperatorRBLRBR = PreyFunction<bool(ArkAiTreeInstanceNodeQueueElement::EmptyOrDoesNotSortBefore const *const _this, ArkAiTreeInstanceNodeQueueElement const &_elem)>(0x10DE280);
	};

	class SortsBefore // Id=8014374 Size=8
	{
	public:
		const uint64_t m_traversalIndex;
		
		SortsBefore(ArkAiTreeNode const &_node);
		bool operator()(ArkAiTreeInstanceNodeQueueElement const &_elem) const { return FoperatorRBLRBR(this,_elem); }
		
		static inline auto FoperatorRBLRBR = PreyFunction<bool(ArkAiTreeInstanceNodeQueueElement::SortsBefore const *const _this, ArkAiTreeInstanceNodeQueueElement const &_elem)>(0x10DE2B0);
	};

	ArkAiTreeNode const *m_pNode;
	ArkAiTreeInstanceNode *m_pInstanceNode;
	bool m_bWantsUpdate;
	
	ArkAiTreeInstanceNodeQueueElement(void *);
	ArkAiTreeInstanceNodeQueueElement(ArkAiTreeNode const &_node, ArkAiTreeInstanceNode &_instanceNode, bool _bWantsUpdate);
	ArkAiTreeNode const &GetNode() const { return FGetNode(this); }
	ArkAiTreeInstanceNode &GetInstanceNode() const { return FGetInstanceNode(this); }
	bool WantsUpdate() const { return FWantsUpdate(this); }
	void SetWantsUpdate(bool _bWantsUpdate) { FSetWantsUpdate(this,_bWantsUpdate); }
	
#if 0
	int *operator int ArkSafeBool<class ArkAiTreeInstanceNodeQueueElement>::*() const;
#endif
	
	static inline auto FGetNode = PreyFunction<ArkAiTreeNode const &(ArkAiTreeInstanceNodeQueueElement const *const _this)>(0x12E5E70);
	static inline auto FGetInstanceNode = PreyFunction<ArkAiTreeInstanceNode &(ArkAiTreeInstanceNodeQueueElement const *const _this)>(0x12AAC70);
	static inline auto FWantsUpdate = PreyFunction<bool(ArkAiTreeInstanceNodeQueueElement const *const _this)>(0x10DE2E0);
	static inline auto FSetWantsUpdate = PreyFunction<void(ArkAiTreeInstanceNodeQueueElement *const _this, bool _bWantsUpdate)>(0x419BF0);
};

