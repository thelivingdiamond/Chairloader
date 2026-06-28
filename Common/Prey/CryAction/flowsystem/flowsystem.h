// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/ark/ArkGlobalActionManager.h>
#include <Prey/CryCore/Containers/CryArray.h>
//#include <Prey/CryAction/FlowSystem/FlowSystem.cpp>
#include <Prey/CryAction/flowsystem/flowsystemcvars.h>
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
#else // MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <CryEngine/cryaction/ark/ArkGlobalActionManager.h>
#include <CryEngine/crycommon/cryarray.h>
#include <Prey/CryAction/FlowSystem/FlowSystem.cpp>
#include <Prey/CryAction/FlowSystem/FlowSystemCVars.h>
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <_unknown/CListenerSet.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>
#include <_unknown/IFlowNodeTypeIterator.h>

class CFlowGraphBase;
class CFlowGraphModuleManager;
class IArkGlobalActionManager;
class ICrySizer;
struct IEntity;
struct IFlowGraph;
struct IFlowGraphInspector;
struct IFlowGraphModuleManager;
struct IFlowNode;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SFlowAddress;
class TFlowInputData;
class XmlNodeRef;

// CAutoFlowFactory<CFlowStartNode>
// Header:  CryEngine/cryaction/flowsystem/FlowSystem.h
class CAutoFlowFactory<CFlowStartNode> : public IFlowNodeFactory
{ // Size=16 (0x10)
public:
	int m_refs;

	virtual void AddRef();
	virtual void Release();
	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual void Reset();

#if 0
	CAutoFlowFactory<CFlowStartNode>();
#endif

	static inline auto FAddRef = PreyFunction<void(CAutoFlowFactory<CFlowStartNode>* const _this)>(0x4678B0);
	static inline auto FRelease = PreyFunction<void(CAutoFlowFactory<CFlowStartNode>* const _this)>(0x552600);
	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoFlowFactory<CFlowStartNode>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x432800);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CAutoFlowFactory<CFlowStartNode>* const _this, ICrySizer* s)>(0x432E30);
	static inline auto FReset = PreyFunction<void(CAutoFlowFactory<CFlowStartNode>* const _this)>(0x1333E90);
};

// CAutoFlowFactory<CFlowTrackEventNode>
// Header:  CryEngine/cryaction/flowsystem/FlowSystem.h
class CAutoFlowFactory<CFlowTrackEventNode> : public IFlowNodeFactory
{ // Size=16 (0x10)
public:
	int m_refs;

	virtual void AddRef();
	virtual void Release();
	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual void Reset();

#if 0
	CAutoFlowFactory<CFlowTrackEventNode>();
#endif

	static inline auto FAddRef = PreyFunction<void(CAutoFlowFactory<CFlowTrackEventNode>* const _this)>(0x4678B0);
	static inline auto FRelease = PreyFunction<void(CAutoFlowFactory<CFlowTrackEventNode>* const _this)>(0x552600);
	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CAutoFlowFactory<CFlowTrackEventNode>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x432850);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CAutoFlowFactory<CFlowTrackEventNode>* const _this, ICrySizer* s)>(0x432E30);
	static inline auto FReset = PreyFunction<void(CAutoFlowFactory<CFlowTrackEventNode>* const _this)>(0x1333E90);
};

// CFlowSystem
// Header:  CryEngine/cryaction/flowsystem/FlowSystem.h
class CFlowSystem : public IFlowSystem, public IEntitySystemSink
{ // Size=264 (0x108)
public:
	// CFlowSystem::STypeInfo
	// Header:  CryEngine/cryaction/flowsystem/FlowSystem.h
	struct STypeInfo
	{ // Size=16 (0x10)
		string name;
		_smart_ptr<IFlowNodeFactory> factory;

	#if 0
		STypeInfo();
		STypeInfo(const string& _arg0_, _smart_ptr<IFlowNodeFactory> _arg1_);
		void GetMemoryUsage(ICrySizer* _arg0_) const;
	#endif
	};

	// CFlowSystem::CNodeTypeIterator
	// Header:  CryEngine/cryaction/flowsystem/FlowSystem.h
	// Include: Prey/CryAction/FlowSystem/FlowSystem.cpp
	class CNodeTypeIterator : public IFlowNodeTypeIterator
	{ // Size=32 (0x20)
	public:
		int m_nRefs;
		uint16_t m_id;
		CFlowSystem* m_pImpl;
		std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CFlowSystem::STypeInfo> > > m_iter;

		virtual void AddRef();
		virtual void Release();
		virtual bool Next(IFlowNodeTypeIterator::SNodeType& nodeType);

	#if 0
		CNodeTypeIterator(CFlowSystem* _arg0_);
	#endif

		static inline auto FAddRef = PreyFunction<void(CFlowSystem::CNodeTypeIterator* const _this)>(0x4678B0);
		static inline auto FRelease = PreyFunction<void(CFlowSystem::CNodeTypeIterator* const _this)>(0x552600);
		static inline auto FNext = PreyFunction<bool(CFlowSystem::CNodeTypeIterator* const _this, IFlowNodeTypeIterator::SNodeType& nodeType)>(0x433A80);
	};

	using TTypeNameToIdMap = std::map<string, unsigned short>;
	using TGraphs = CListenerSet<CFlowGraphBase *>;
	using TFlowSystemContainerMap = std::map<int, std::shared_ptr<IFlowSystemContainer>>;

	bool m_bInspectingEnabled;
	bool m_needToUpdateForwardings;
	bool m_criticalLoadingErrorHappened;
	std::map<string, unsigned short> m_typeNameToIdMap;
	std::vector<CFlowSystem::STypeInfo> m_typeRegistryVec;
	CListenerSet<CFlowGraphBase *> m_graphs;
	std::vector<_smart_ptr<IFlowGraphInspector>> m_systemInspectors;
	std::vector<unsigned short> m_freeNodeTypeIDs;
	uint16_t m_nextNodeTypeID;
	_smart_ptr<IFlowGraphInspector> m_pDefaultInspector;
	CFlowSystemCVars m_cVars;
	unsigned m_nextFlowGraphId;
	CFlowGraphModuleManager* m_pModuleManager;
	ArkGlobalActionManager m_arkGlobalActionManager;
	std::map<int, std::shared_ptr<IFlowSystemContainer>> m_FlowSystemContainers;

	CFlowSystem();
	virtual ~CFlowSystem();
	virtual void Release();
	virtual void Update();
	virtual void Reset(bool unload);
	virtual void ReloadAllNodeTypes();
	virtual _smart_ptr<IFlowGraph> CreateFlowGraph();
	virtual uint16_t RegisterType(const char* type, _smart_ptr<IFlowNodeFactory> factory);
	virtual bool UnregisterType(const char* typeName);
	virtual const char* GetTypeName(uint16_t typeId);
	virtual uint16_t GetTypeId(const char* typeName);
	virtual _smart_ptr<IFlowNodeTypeIterator> CreateNodeTypeIterator();
	virtual void RegisterInspector(_smart_ptr<IFlowGraphInspector> pInspector, _smart_ptr<IFlowGraph> pGraph);
	virtual void UnregisterInspector(_smart_ptr<IFlowGraphInspector> pInspector, _smart_ptr<IFlowGraph> pGraph);
	virtual void EnableInspecting(bool bEnable);
	virtual bool IsInspectingEnabled() const;
	virtual _smart_ptr<IFlowGraphInspector> GetDefaultInspector() const;
	virtual IFlowGraph* GetGraphById(unsigned graphId);
	virtual void OnEntityIdChanged(unsigned oldId, unsigned newId);
	virtual void GetMemoryUsage(ICrySizer* pSizer) const;
	virtual bool IsConsoleFlowNodesEnabled() const;
	virtual bool CreateContainer(int id);
	virtual void DeleteContainer(int id);
	virtual std::shared_ptr<IFlowSystemContainer> GetContainer(int id);
	virtual void Serialize(TSerialize ser);
	virtual bool OnBeforeSpawn(SEntitySpawnParams& params);
	virtual void OnSpawn(IEntity* pEntity, SEntitySpawnParams& params);
	virtual bool OnRemove(IEntity* pEntity);
	virtual void OnReused(IEntity* pEntity, SEntitySpawnParams& params);
	virtual void OnEvent(IEntity* pEntity, SEntityEvent& event);
	_smart_ptr<IFlowNode> CreateNodeOfType(IFlowNode::SActivationInfo* pActInfo, uint16_t typeId) { alignas(_smart_ptr<IFlowNode>) std::byte _return_buf_[sizeof(_smart_ptr<IFlowNode>)]; return *FCreateNodeOfType(this, reinterpret_cast<_smart_ptr<IFlowNode>*>(_return_buf_), pActInfo, typeId); }
	void PreInit() { FPreInit(this); }
	void Init() { FInit(this); }
	void Shutdown() { FShutdown(this); }
	virtual void Enable(bool enable);
	unsigned RegisterGraph(CFlowGraphBase* pGraph, const char* debugName) { return FRegisterGraph(this, pGraph, debugName); }
	void UnregisterGraph(CFlowGraphBase* pGraph) { FUnregisterGraph(this, pGraph); }
	virtual IFlowGraphModuleManager* GetIModuleManager();
	virtual IArkGlobalActionManager& GetIArkGlobalActionManager();
	void NotifyFlow(CFlowGraphBase* pGraph, const SFlowAddress from, const SFlowAddress to) { FNotifyFlow(this, pGraph, from, to); }
	const CFlowSystem::STypeInfo& GetTypeInfo(uint16_t typeId) const { return FGetTypeInfo(this, typeId); }
	void LoadExtensions(string path) { FLoadExtensions(this, path); }
	void LoadExtensionFromXml(XmlNodeRef nodeParent) { FLoadExtensionFromXml(this, nodeParent); }
	void RegisterAllNodeTypes() { FRegisterAllNodeTypes(this); }
	void RegisterEntityTypes() { FRegisterEntityTypes(this); }
	bool BlacklistedFlownode(const char* * nodeName) { return FBlacklistedFlownode(this, nodeName); }
	void UpdateGraphs() { FUpdateGraphs(this); }

#if 0
	void ShowCriticalLoadingErrorWarning(const bool _arg0_);
	void GlobalActionsPostSerialize() const;
	CFlowGraphModuleManager* GetModuleManager();
	const CFlowGraphModuleManager* GetModuleManager() const;
	void NotifyProcessEvent(CFlowGraphBase* _arg0_, IFlowNode::EFlowEvent _arg1_, IFlowNode::SActivationInfo* _arg2_, IFlowNode* _arg3_);
	void RegisterAutoTypes();
	uint16_t GenerateNodeTypeID();
#endif

	static inline auto FCFlowSystemOv1 = PreyFunction<void(CFlowSystem* const _this)>(0x431E50);
	static inline auto FBitNotCFlowSystem = PreyFunction<void(CFlowSystem* const _this)>(0x432150);
	static inline auto FRelease = PreyFunction<void(CFlowSystem* const _this)>(0x4349A0);
	static inline auto FUpdate = PreyFunction<void(CFlowSystem* const _this)>(0x435600);
	static inline auto FReset = PreyFunction<void(CFlowSystem* const _this, bool unload)>(0x434B90);
	static inline auto FReloadAllNodeTypes = PreyFunction<void(CFlowSystem* const _this)>(0x1333E90);
	static inline auto FCreateFlowGraph = PreyFunction<_smart_ptr<IFlowGraph>*(CFlowSystem* const _this, _smart_ptr<IFlowGraph>* _return_value_)>(0x432A60);
	static inline auto FRegisterType = PreyFunction<uint16_t(CFlowSystem* const _this, const char* type, _smart_ptr<IFlowNodeFactory> factory)>(0x434540);
	static inline auto FUnregisterType = PreyFunction<bool(CFlowSystem* const _this, const char* typeName)>(0x435400);
	static inline auto FGetTypeName = PreyFunction<const char* (CFlowSystem* const _this, uint16_t typeId)>(0x4333F0);
	static inline auto FGetTypeId = PreyFunction<uint16_t(CFlowSystem* const _this, const char* typeName)>(0x4332F0);
	static inline auto FCreateNodeTypeIterator = PreyFunction<_smart_ptr<IFlowNodeTypeIterator>*(CFlowSystem* const _this, _smart_ptr<IFlowNodeTypeIterator>* _return_value_)>(0x432B30);
	static inline auto FRegisterInspector = PreyFunction<void(CFlowSystem* const _this, _smart_ptr<IFlowGraphInspector> pInspector, _smart_ptr<IFlowGraph> pGraph)>(0x434470);
	static inline auto FUnregisterInspector = PreyFunction<void(CFlowSystem* const _this, _smart_ptr<IFlowGraphInspector> pInspector, _smart_ptr<IFlowGraph> pGraph)>(0x4352A0);
	static inline auto FEnableInspecting = PreyFunction<void(CFlowSystem* const _this, bool bEnable)>(0xEAF650);
	static inline auto FIsInspectingEnabled = PreyFunction<bool(const CFlowSystem* const _this)>(0x720C90);
	static inline auto FGetDefaultInspector = PreyFunction<_smart_ptr<IFlowGraphInspector>*(const CFlowSystem* const _this, _smart_ptr<IFlowGraphInspector>* _return_value_)>(0x432CD0);
	static inline auto FGetGraphById = PreyFunction<IFlowGraph* (CFlowSystem* const _this, unsigned graphId)>(0x432D00);
	static inline auto FOnEntityIdChanged = PreyFunction<void(CFlowSystem* const _this, unsigned oldId, unsigned newId)>(0x433BD0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowSystem* const _this, ICrySizer* pSizer)>(0x432EE0);
	static inline auto FIsConsoleFlowNodesEnabled = PreyFunction<bool(const CFlowSystem* const _this)>(0x433450);
	static inline auto FCreateContainer = PreyFunction<bool(CFlowSystem* const _this, int id)>(0x4328D0);
	static inline auto FDeleteContainer = PreyFunction<void(CFlowSystem* const _this, int id)>(0x432BA0);
	static inline auto FGetContainer = PreyFunction<std::shared_ptr<IFlowSystemContainer>*(CFlowSystem* const _this, std::shared_ptr<IFlowSystemContainer>* _return_value_, int id)>(0x432C10);
	static inline auto FSerialize = PreyFunction<void(CFlowSystem* const _this, TSerialize ser)>(0x434D80);
	static inline auto FOnBeforeSpawn = PreyFunction<bool(IEntitySystemSink* const _this, SEntitySpawnParams& params)>(0x1A302A0);
	static inline auto FOnSpawn = PreyFunction<void(IEntitySystemSink* const _this, IEntity* pEntity, SEntitySpawnParams& params)>(0x433D90);
	static inline auto FOnRemove = PreyFunction<bool(IEntitySystemSink* const _this, IEntity* pEntity)>(0x1A302A0);
	static inline auto FOnReused = PreyFunction<void(IEntitySystemSink* const _this, IEntity* pEntity, SEntitySpawnParams& params)>(0x433CB0);
	static inline auto FOnEvent = PreyFunction<void(IEntitySystemSink* const _this, IEntity* pEntity, SEntityEvent& event)>(0x1333E90);
	static inline auto FCreateNodeOfType = PreyFunction<_smart_ptr<IFlowNode>*(CFlowSystem* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo, uint16_t typeId)>(0x432AD0);
	static inline auto FPreInit = PreyFunction<void(CFlowSystem* const _this)>(0x433DC0);
	static inline auto FInit = PreyFunction<void(CFlowSystem* const _this)>(0x433420);
	static inline auto FShutdown = PreyFunction<void(CFlowSystem* const _this)>(0x435200);
	static inline auto FEnable = PreyFunction<void(CFlowSystem* const _this, bool enable)>(0x432C00);
	static inline auto FRegisterGraph = PreyFunction<unsigned(CFlowSystem* const _this, CFlowGraphBase* pGraph, const char* debugName)>(0x434410);
	static inline auto FUnregisterGraph = PreyFunction<void(CFlowSystem* const _this, CFlowGraphBase* pGraph)>(0x435230);
	static inline auto FGetIModuleManager = PreyFunction<IFlowGraphModuleManager* (CFlowSystem* const _this)>(0x84FDC0);
	static inline auto FGetIArkGlobalActionManager = PreyFunction<IArkGlobalActionManager& (CFlowSystem* const _this)>(0x432DF0);
	static inline auto FNotifyFlow = PreyFunction<void(CFlowSystem* const _this, CFlowGraphBase* pGraph, const SFlowAddress from, const SFlowAddress to)>(0x433B20);
	static inline auto FGetTypeInfo = PreyFunction<const CFlowSystem::STypeInfo& (const CFlowSystem* const _this, uint16_t typeId)>(0x4333C0);
	static inline auto FLoadExtensions = PreyFunction<void(CFlowSystem* const _this, string path)>(0x433700);
	static inline auto FLoadExtensionFromXml = PreyFunction<void(CFlowSystem* const _this, XmlNodeRef nodeParent)>(0x433460);
	static inline auto FRegisterAllNodeTypes = PreyFunction<void(CFlowSystem* const _this)>(0x433E80);
	static inline auto FRegisterEntityTypes = PreyFunction<void(CFlowSystem* const _this)>(0x434130);
	static inline auto FBlacklistedFlownode = PreyFunction<bool(CFlowSystem* const _this, const char* * nodeName)>(0x432560);
	static inline auto FUpdateGraphs = PreyFunction<void(CFlowSystem* const _this)>(0x435880);
};

// CFlowSystemContainer
// Header:  CryEngine/cryaction/flowsystem/FlowSystem.h
// Include: Prey/CryAction/FlowSystem/FlowSystem.h
struct CFlowSystemContainer : public IFlowSystemContainer
{ // Size=16 (0x10)
	DynArray<TFlowInputData,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > m_container;

	virtual void AddItem(TFlowInputData item);
	virtual void AddItemUnique(TFlowInputData item);
	virtual void RemoveItem(TFlowInputData item);
	virtual TFlowInputData GetItem(int i);
	virtual void RemoveItemAt(int i);
	virtual int GetItemCount() const;
	virtual void Clear();
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual void Serialize(TSerialize ser);

	static inline auto FAddItem = PreyFunction<void(CFlowSystemContainer* const _this, TFlowInputData item)>(0x432460);
	static inline auto FAddItemUnique = PreyFunction<void(CFlowSystemContainer* const _this, TFlowInputData item)>(0x4324C0);
	static inline auto FRemoveItem = PreyFunction<void(CFlowSystemContainer* const _this, TFlowInputData item)>(0x434A00);
	static inline auto FGetItem = PreyFunction<TFlowInputData*(CFlowSystemContainer* const _this, TFlowInputData* _return_value_, int i)>(0x432E00);
	static inline auto FRemoveItemAt = PreyFunction<void(CFlowSystemContainer* const _this, int i)>(0x434B70);
	static inline auto FGetItemCount = PreyFunction<int(const CFlowSystemContainer* const _this)>(0x7BD660);
	static inline auto FClear = PreyFunction<void(CFlowSystemContainer* const _this)>(0x4327D0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowSystemContainer* const _this, ICrySizer* s)>(0x433270);
	static inline auto FSerialize = PreyFunction<void(CFlowSystemContainer* const _this, TSerialize ser)>(0x435070);
};

// CSingletonFlowFactory<CFlowLogNode>
// Header:  CryEngine/cryaction/flowsystem/FlowSystem.h
class CSingletonFlowFactory<CFlowLogNode> : public IFlowNodeFactory
{ // Size=24 (0x18)
public:
	_smart_ptr<IFlowNode> m_pInstance;
	int m_refs;

	virtual void AddRef();
	virtual void Release();
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual _smart_ptr<IFlowNode> Create(IFlowNode::SActivationInfo* pActInfo);
	virtual void Reset();

#if 0
	CSingletonFlowFactory<CFlowLogNode>();
#endif

	static inline auto FAddRef = PreyFunction<void(CSingletonFlowFactory<CFlowLogNode>* const _this)>(0x4E57E0);
	static inline auto FRelease = PreyFunction<void(CSingletonFlowFactory<CFlowLogNode>* const _this)>(0x434980);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CSingletonFlowFactory<CFlowLogNode>* const _this, ICrySizer* s)>(0x432E80);
	static inline auto FCreate = PreyFunction<_smart_ptr<IFlowNode>*(CSingletonFlowFactory<CFlowLogNode>* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x4328A0);
	static inline auto FReset = PreyFunction<void(CSingletonFlowFactory<CFlowLogNode>* const _this)>(0x1333E90);
};
#endif // !MOONCRASH
