typedef unsigned char   undefined;

typedef unsigned long long    GUID;
typedef unsigned int    ImageBaseOffset32;
typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned int    dword;
typedef long long    longlong;
typedef unsigned long long    qword;
typedef char    sbyte;
typedef signed char    schar;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined5;
typedef unsigned long long    undefined6;
typedef unsigned long long    undefined8;
typedef unsigned short    ushort;
typedef short    wchar_t;
typedef unsigned short    word;
typedef struct CEntitySystem CEntitySystem, *PCEntitySystem;

typedef struct unordered_map<unsignedint,float,std::hash<unsignedint>,std::equal_to<unsignedint>,std::allocator<std::pair<unsignedintconst,float>>> unordered_map<unsignedint,float,std::hash<unsignedint>,std::equal_to<unsignedint>,std::allocator<std::pair<unsignedintconst,float>>>, *Punordered_map<unsignedint,float,std::hash<unsignedint>,std::equal_to<unsignedint>,std::allocator<std::pair<unsignedintconst,float>>>;

typedef struct vector<IEntitySystemSink*,stl::STLGlobalAllocator<IEntitySystemSink*>> vector<IEntitySystemSink*,stl::STLGlobalAllocator<IEntitySystemSink*>>, *Pvector<IEntitySystemSink*,stl::STLGlobalAllocator<IEntitySystemSink*>>;

typedef struct vector<CEntitySystem::OnEventSink,stl::STLGlobalAllocator<CEntitySystem::OnEventSink>> vector<CEntitySystem::OnEventSink,stl::STLGlobalAllocator<CEntitySystem::OnEventSink>>, *Pvector<CEntitySystem::OnEventSink,stl::STLGlobalAllocator<CEntitySystem::OnEventSink>>;

typedef struct ISystem ISystem, *PISystem;

typedef struct vector<CEntity*,std::allocator<CEntity*>> vector<CEntity*,std::allocator<CEntity*>>, *Pvector<CEntity*,std::allocator<CEntity*>>;

typedef struct map<unsignedint,CEntity*,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,CEntity*>>> map<unsignedint,CEntity*,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,CEntity*>>>, *Pmap<unsignedint,CEntity*,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,CEntity*>>>;

typedef struct set<unsignedint,std::less<unsignedint>,std::allocator<unsignedint>> set<unsignedint,std::less<unsignedint>,std::allocator<unsignedint>>, *Pset<unsignedint,std::less<unsignedint>,std::allocator<unsignedint>>;

typedef struct multimap<charconst*,unsignedint,stl::less_stricmp<charconst*>,std::allocator<std::pair<charconst*const,unsignedint>>> multimap<charconst*,unsignedint,stl::less_stricmp<charconst*>,std::allocator<std::pair<charconst*const,unsignedint>>>, *Pmultimap<charconst*,unsignedint,stl::less_stricmp<charconst*>,std::allocator<std::pair<charconst*const,unsignedint>>>;

typedef struct CSaltBufferArray<unsignedshort,unsignedshort,65533> CSaltBufferArray<unsignedshort,unsignedshort,65533>, *PCSaltBufferArray<unsignedshort,unsignedshort,65533>;

typedef struct vector<unsignedint,std::allocator<unsignedint>> vector<unsignedint,std::allocator<unsignedint>>, *Pvector<unsignedint,std::allocator<unsignedint>>;

typedef struct CComponentEventDistributer CComponentEventDistributer, *PCComponentEventDistributer;

typedef struct multimap<CTimeValue,SEntityTimerEvent,std::less<CTimeValue>,stl::STLPoolAllocator<std::pair<CTimeValue,SEntityTimerEvent>,stl::PSyncNone,0,0>> multimap<CTimeValue,SEntityTimerEvent,std::less<CTimeValue>,stl::STLPoolAllocator<std::pair<CTimeValue,SEntityTimerEvent>,stl::PSyncNone,0,0>>, *Pmultimap<CTimeValue,SEntityTimerEvent,std::less<CTimeValue>,stl::STLPoolAllocator<std::pair<CTimeValue,SEntityTimerEvent>,stl::PSyncNone,0,0>>;

typedef struct vector<SEntityTimerEvent,std::allocator<SEntityTimerEvent>> vector<SEntityTimerEvent,std::allocator<SEntityTimerEvent>>, *Pvector<SEntityTimerEvent,std::allocator<SEntityTimerEvent>>;

typedef struct CTimeValue CTimeValue, *PCTimeValue;

typedef struct CScriptBind_Entity CScriptBind_Entity, *PCScriptBind_Entity;

typedef struct CEntityClassRegistry CEntityClassRegistry, *PCEntityClassRegistry;

typedef struct CPhysicsEventListener CPhysicsEventListener, *PCPhysicsEventListener;

typedef struct CAreaManager CAreaManager, *PCAreaManager;

typedef struct CEntityLoadManager CEntityLoadManager, *PCEntityLoadManager;

typedef struct CEntityPoolManager CEntityPoolManager, *PCEntityPoolManager;

typedef struct multimap<unsignedint,IEntityEventListener*,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,IEntityEventListener*>>> multimap<unsignedint,IEntityEventListener*,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,IEntityEventListener*>>>, *Pmultimap<unsignedint,IEntityEventListener*,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,IEntityEventListener*>>>;

typedef struct map<unsigned__int64,unsignedint,std::less<unsigned__int64>,std::allocator<std::pair<unsigned__int64const,unsignedint>>> map<unsigned__int64,unsignedint,std::less<unsigned__int64>,std::allocator<std::pair<unsigned__int64const,unsignedint>>>, *Pmap<unsigned__int64,unsignedint,std::less<unsigned__int64>,std::allocator<std::pair<unsigned__int64const,unsignedint>>>;

typedef struct IBreakableManager IBreakableManager, *PIBreakableManager;

typedef struct CEntityArchetypeManager CEntityArchetypeManager, *PCEntityArchetypeManager;

typedef struct CGeomCacheAttachmentManager CGeomCacheAttachmentManager, *PCGeomCacheAttachmentManager;

typedef struct CCharacterBoneAttachmentManager CCharacterBoneAttachmentManager, *PCCharacterBoneAttachmentManager;

typedef struct CPartitionGrid CPartitionGrid, *PCPartitionGrid;

typedef struct CProximityTriggerSystem CProximityTriggerSystem, *PCProximityTriggerSystem;

typedef struct CEntityTimeoutList CEntityTimeoutList, *PCEntityTimeoutList;

typedef struct map<CryStringT<char>,CEntityLayer*,std::less<CryStringT<char>>,std::allocator<std::pair<CryStringT<char>const,CEntityLayer*>>> map<CryStringT<char>,CEntityLayer*,std::less<CryStringT<char>>,std::allocator<std::pair<CryStringT<char>const,CEntityLayer*>>>, *Pmap<CryStringT<char>,CEntityLayer*,std::less<CryStringT<char>>,std::allocator<std::pair<CryStringT<char>const,CEntityLayer*>>>;

typedef struct vector<SEntityLayerGarbage,std::allocator<SEntityLayerGarbage>> vector<SEntityLayerGarbage,std::allocator<SEntityLayerGarbage>>, *Pvector<SEntityLayerGarbage,std::allocator<SEntityLayerGarbage>>;

typedef struct set<IEntityconst*,std::less<IEntityconst*>,std::allocator<IEntityconst*>> set<IEntityconst*,std::less<IEntityconst*>,std::allocator<IEntityconst*>>, *Pset<IEntityconst*,std::less<IEntityconst*>,std::allocator<IEntityconst*>>;

typedef struct vector<IEntityClassconst*,std::allocator<IEntityClassconst*>> vector<IEntityClassconst*,std::allocator<IEntityClassconst*>>, *Pvector<IEntityClassconst*,std::allocator<IEntityClassconst*>>;

typedef struct AABB AABB, *PAABB;

typedef struct SSaltBufferElement SSaltBufferElement, *PSSaltBufferElement;

typedef struct multimap<unsignedint,CComponentEventDistributer::SRegisteredComponentEvents,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,CComponentEventDistributer::SRegisteredComponentEvents>>> multimap<unsignedint,CComponentEventDistributer::SRegisteredComponentEvents,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,CComponentEventDistributer::SRegisteredComponentEvents>>>, *Pmultimap<unsignedint,CComponentEventDistributer::SRegisteredComponentEvents,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,CComponentEventDistributer::SRegisteredComponentEvents>>>;

typedef struct map<int,CComponentEventDistributer::SEventPtrs,std::less<int>,std::allocator<std::pair<intconst,CComponentEventDistributer::SEventPtrs>>> map<int,CComponentEventDistributer::SEventPtrs,std::less<int>,std::allocator<std::pair<intconst,CComponentEventDistributer::SEventPtrs>>>, *Pmap<int,CComponentEventDistributer::SEventPtrs,std::less<int>,std::allocator<std::pair<intconst,CComponentEventDistributer::SEventPtrs>>>;

typedef struct map<unsignedint,unsignedint,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,unsignedint>>> map<unsignedint,unsignedint,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,unsignedint>>>, *Pmap<unsignedint,unsignedint,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,unsignedint>>>;

typedef struct vector<CComponentEventDistributer::SEventPtr,std::allocator<CComponentEventDistributer::SEventPtr>> vector<CComponentEventDistributer::SEventPtr,std::allocator<CComponentEventDistributer::SEventPtr>>, *Pvector<CComponentEventDistributer::SEventPtr,std::allocator<CComponentEventDistributer::SEventPtr>>;

typedef struct CCryFlags<unsignedint> CCryFlags<unsignedint>, *PCCryFlags<unsignedint>;

typedef struct IEntitySystem IEntitySystem, *PIEntitySystem;

typedef struct pe_params_particle pe_params_particle, *Ppe_params_particle;

typedef struct pe_params_buoyancy pe_params_buoyancy, *Ppe_params_buoyancy;

typedef struct pe_player_dimensions pe_player_dimensions, *Ppe_player_dimensions;

typedef struct pe_player_dynamics pe_player_dynamics, *Ppe_player_dynamics;

typedef struct pe_params_area pe_params_area, *Ppe_params_area;

typedef struct AreaDefinition AreaDefinition, *PAreaDefinition;

typedef struct vector<Vec3_tpl<float>,std::allocator<Vec3_tpl<float>>> vector<Vec3_tpl<float>,std::allocator<Vec3_tpl<float>>>, *Pvector<Vec3_tpl<float>,std::allocator<Vec3_tpl<float>>>;

typedef struct pe_params_car pe_params_car, *Ppe_params_car;

typedef struct SmartScriptTable SmartScriptTable, *PSmartScriptTable;

typedef struct map<CryStringT<char>,IEntityClass*,std::less<CryStringT<char>>,std::allocator<std::pair<CryStringT<char>const,IEntityClass*>>> map<CryStringT<char>,IEntityClass*,std::less<CryStringT<char>>,std::allocator<std::pair<CryStringT<char>const,IEntityClass*>>>, *Pmap<CryStringT<char>,IEntityClass*,std::less<CryStringT<char>>,std::allocator<std::pair<CryStringT<char>const,IEntityClass*>>>;

typedef struct IEntityClass IEntityClass, *PIEntityClass;

typedef struct _Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CryStringT<char>const,IEntityClass*>>>> _Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CryStringT<char>const,IEntityClass*>>>>, *P_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CryStringT<char>const,IEntityClass*>>>>;

typedef struct CListenerSet<IEntityClassRegistryListener*> CListenerSet<IEntityClassRegistryListener*>, *PCListenerSet<IEntityClassRegistryListener*>;

typedef struct IPhysicalWorld IPhysicalWorld, *PIPhysicalWorld;

typedef struct vector<CArea*,std::allocator<CArea*>> vector<CArea*,std::allocator<CArea*>>, *Pvector<CArea*,std::allocator<CArea*>>;

typedef struct CAreaGrid CAreaGrid, *PCAreaGrid;

typedef struct IVisArea IVisArea, *PIVisArea;

typedef struct vector<IAreaManagerEventListener*,std::allocator<IAreaManagerEventListener*>> vector<IAreaManagerEventListener*,std::allocator<IAreaManagerEventListener*>>, *Pvector<IAreaManagerEventListener*,std::allocator<IAreaManagerEventListener*>>;

typedef struct VectorMap<unsignedint,CAreaManager::SAreasCache,std::less<unsignedint>,std::allocator<std::pair<unsignedint,CAreaManager::SAreasCache>>> VectorMap<unsignedint,CAreaManager::SAreasCache,std::less<unsignedint>,std::allocator<std::pair<unsignedint,CAreaManager::SAreasCache>>>, *PVectorMap<unsignedint,CAreaManager::SAreasCache,std::less<unsignedint>,std::allocator<std::pair<unsignedint,CAreaManager::SAreasCache>>>;

typedef struct VectorMap<unsignedint,unsigned__int64,std::less<unsignedint>,std::allocator<std::pair<unsignedint,unsigned__int64>>> VectorMap<unsignedint,unsigned__int64,std::less<unsignedint>,std::allocator<std::pair<unsignedint,unsigned__int64>>>, *PVectorMap<unsignedint,unsigned__int64,std::less<unsignedint>,std::allocator<std::pair<unsignedint,unsigned__int64>>>;

typedef struct vector<SEntityAttachment,std::allocator<SEntityAttachment>> vector<SEntityAttachment,std::allocator<SEntityAttachment>>, *Pvector<SEntityAttachment,std::allocator<SEntityAttachment>>;

typedef struct vector<CEntityLoadManager::SQueuedFlowGraph,std::allocator<CEntityLoadManager::SQueuedFlowGraph>> vector<CEntityLoadManager::SQueuedFlowGraph,std::allocator<CEntityLoadManager::SQueuedFlowGraph>>, *Pvector<CEntityLoadManager::SQueuedFlowGraph,std::allocator<CEntityLoadManager::SQueuedFlowGraph>>;

typedef struct vector<CEntityLoadManager::SHeldLayer,std::allocator<CEntityLoadManager::SHeldLayer>> vector<CEntityLoadManager::SHeldLayer,std::allocator<CEntityLoadManager::SHeldLayer>>, *Pvector<CEntityLoadManager::SHeldLayer,std::allocator<CEntityLoadManager::SHeldLayer>>;

typedef struct map<unsignedint,int,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,int>>> map<unsignedint,int,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,int>>>, *Pmap<unsignedint,int,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,int>>>;

typedef struct vector<std::map<unsignedint,unsignedint,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,unsignedint>>>,std::allocator<std::map<unsignedint,unsignedint,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,unsignedint>>>>> vector<std::map<unsignedint,unsignedint,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,unsignedint>>>,std::allocator<std::map<unsignedint,unsignedint,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,unsignedint>>>>>, *Pvector<std::map<unsignedint,unsignedint,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,unsignedint>>>,std::allocator<std::map<unsignedint,unsignedint,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,unsignedint>>>>>;

typedef struct XmlNodeRef XmlNodeRef, *PXmlNodeRef;

typedef struct _smart_ptr<ISerializeHelper> _smart_ptr<ISerializeHelper>, *P_smart_ptr<ISerializeHelper>;

typedef struct vector<CListenerSet<IEntityPoolListener*>,std::allocator<CListenerSet<IEntityPoolListener*>>> vector<CListenerSet<IEntityPoolListener*>,std::allocator<CListenerSet<IEntityPoolListener*>>>, *Pvector<CListenerSet<IEntityPoolListener*>,std::allocator<CListenerSet<IEntityPoolListener*>>>;

typedef struct map<unsignedint,CEntityPool*,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,CEntityPool*>>> map<unsignedint,CEntityPool*,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,CEntityPool*>>>, *Pmap<unsignedint,CEntityPool*,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,CEntityPool*>>>;

typedef struct map<unsignedint,CEntityPoolDefinition*,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,CEntityPoolDefinition*>>> map<unsignedint,CEntityPoolDefinition*,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,CEntityPoolDefinition*>>>, *Pmap<unsignedint,CEntityPoolDefinition*,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,CEntityPoolDefinition*>>>;

typedef struct map<unsignedint,CEntityPoolManager::SEntityBookmark,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,CEntityPoolManager::SEntityBookmark>>> map<unsignedint,CEntityPoolManager::SEntityBookmark,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,CEntityPoolManager::SEntityBookmark>>>, *Pmap<unsignedint,CEntityPoolManager::SEntityBookmark,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,CEntityPoolManager::SEntityBookmark>>>;

typedef struct queue<CEntityPoolManager::SEntityPrepareRequest,std::deque<CEntityPoolManager::SEntityPrepareRequest,std::allocator<CEntityPoolManager::SEntityPrepareRequest>>> queue<CEntityPoolManager::SEntityPrepareRequest,std::deque<CEntityPoolManager::SEntityPrepareRequest,std::allocator<CEntityPoolManager::SEntityPrepareRequest>>>, *Pqueue<CEntityPoolManager::SEntityPrepareRequest,std::deque<CEntityPoolManager::SEntityPrepareRequest,std::allocator<CEntityPoolManager::SEntityPrepareRequest>>>;

typedef struct SPreparingParams SPreparingParams, *PSPreparingParams;

typedef struct map<charconst*,_smart_ptr<CEntityArchetype>,stl::less_stricmp<charconst*>,std::allocator<std::pair<charconst*const,_smart_ptr<CEntityArchetype>>>> map<charconst*,_smart_ptr<CEntityArchetype>,stl::less_stricmp<charconst*>,std::allocator<std::pair<charconst*const,_smart_ptr<CEntityArchetype>>>>, *Pmap<charconst*,_smart_ptr<CEntityArchetype>,stl::less_stricmp<charconst*>,std::allocator<std::pair<charconst*const,_smart_ptr<CEntityArchetype>>>>;

typedef struct unordered_map<unsigned__int64,_smart_ptr<CEntityArchetype>,std::hash<unsigned__int64>,std::equal_to<unsigned__int64>,std::allocator<std::pair<unsigned__int64const,_smart_ptr<CEntityArchetype>>>> unordered_map<unsigned__int64,_smart_ptr<CEntityArchetype>,std::hash<unsigned__int64>,std::equal_to<unsigned__int64>,std::allocator<std::pair<unsigned__int64const,_smart_ptr<CEntityArchetype>>>>, *Punordered_map<unsigned__int64,_smart_ptr<CEntityArchetype>,std::hash<unsigned__int64>,std::equal_to<unsigned__int64>,std::allocator<std::pair<unsigned__int64const,_smart_ptr<CEntityArchetype>>>>;

typedef struct DynArray<CryStringT<char>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> DynArray<CryStringT<char>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>, *PDynArray<CryStringT<char>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>;

typedef struct vector<IEntityArchetypeListener*,std::allocator<IEntityArchetypeListener*>> vector<IEntityArchetypeListener*,std::allocator<IEntityArchetypeListener*>>, *Pvector<IEntityArchetypeListener*,std::allocator<IEntityArchetypeListener*>>;

typedef struct VectorMap<CGeomCacheAttachmentManager::SBinding,CGeomCacheAttachmentManager::SAttachmentData,std::less<CGeomCacheAttachmentManager::SBinding>,std::allocator<std::pair<CGeomCacheAttachmentManager::SBinding,CGeomCacheAttachmentManager::SAttachmentData>>> VectorMap<CGeomCacheAttachmentManager::SBinding,CGeomCacheAttachmentManager::SAttachmentData,std::less<CGeomCacheAttachmentManager::SBinding>,std::allocator<std::pair<CGeomCacheAttachmentManager::SBinding,CGeomCacheAttachmentManager::SAttachmentData>>>, *PVectorMap<CGeomCacheAttachmentManager::SBinding,CGeomCacheAttachmentManager::SAttachmentData,std::less<CGeomCacheAttachmentManager::SBinding>,std::allocator<std::pair<CGeomCacheAttachmentManager::SBinding,CGeomCacheAttachmentManager::SAttachmentData>>>;

typedef struct VectorMap<CCharacterBoneAttachmentManager::SBinding,CCharacterBoneAttachmentManager::SAttachmentData,std::less<CCharacterBoneAttachmentManager::SBinding>,std::allocator<std::pair<CCharacterBoneAttachmentManager::SBinding,CCharacterBoneAttachmentManager::SAttachmentData>>> VectorMap<CCharacterBoneAttachmentManager::SBinding,CCharacterBoneAttachmentManager::SAttachmentData,std::less<CCharacterBoneAttachmentManager::SBinding>,std::allocator<std::pair<CCharacterBoneAttachmentManager::SBinding,CCharacterBoneAttachmentManager::SAttachmentData>>>, *PVectorMap<CCharacterBoneAttachmentManager::SBinding,CCharacterBoneAttachmentManager::SAttachmentData,std::less<CCharacterBoneAttachmentManager::SBinding>,std::allocator<std::pair<CCharacterBoneAttachmentManager::SBinding,CCharacterBoneAttachmentManager::SAttachmentData>>>;

typedef struct SectorGroup SectorGroup, *PSectorGroup;

typedef struct vector<IEntity*,std::allocator<IEntity*>> vector<IEntity*,std::allocator<IEntity*>>, *Pvector<IEntity*,std::allocator<IEntity*>>;

typedef struct vector<SProximityElement*,std::allocator<SProximityElement*>> vector<SProximityElement*,std::allocator<SProximityElement*>>, *Pvector<SProximityElement*,std::allocator<SProximityElement*>>;

typedef struct vector<AABB,std::allocator<AABB>> vector<AABB,std::allocator<AABB>>, *Pvector<AABB,std::allocator<AABB>>;

typedef struct vector<SProximityEvent,std::allocator<SProximityEvent>> vector<SProximityEvent,std::allocator<SProximityEvent>>, *Pvector<SProximityEvent,std::allocator<SProximityEvent>>;

typedef struct RadixSort RadixSort, *PRadixSort;

typedef struct vector<float,std::allocator<float>> vector<float,std::allocator<float>>, *Pvector<float,std::allocator<float>>;

typedef struct unordered_map<unsignedint,std::vector<unsignedint,std::allocator<unsignedint>>,std::hash<unsignedint>,std::equal_to<unsignedint>,std::allocator<std::pair<unsignedintconst,std::vector<unsignedint,std::allocator<unsignedint>>>>> unordered_map<unsignedint,std::vector<unsignedint,std::allocator<unsignedint>>,std::hash<unsignedint>,std::equal_to<unsignedint>,std::allocator<std::pair<unsignedintconst,std::vector<unsignedint,std::allocator<unsignedint>>>>>, *Punordered_map<unsignedint,std::vector<unsignedint,std::allocator<unsignedint>>,std::hash<unsignedint>,std::equal_to<unsignedint>,std::allocator<std::pair<unsignedintconst,std::vector<unsignedint,std::allocator<unsignedint>>>>>;

typedef struct DynArray<CEntityTimeoutList::CEntry,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> DynArray<CEntityTimeoutList::CEntry,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>, *PDynArray<CEntityTimeoutList::CEntry,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>>;

typedef struct ITimer ITimer, *PITimer;

typedef struct Vec3_tpl<float> Vec3_tpl<float>, *PVec3_tpl<float>;

typedef struct Quat_tpl<float> Quat_tpl<float>, *PQuat_tpl<float>;

typedef struct IPhysicalEntity IPhysicalEntity, *PIPhysicalEntity;

typedef struct plane plane, *Pplane;

typedef struct IGeometry IGeometry, *PIGeometry;

typedef enum EAreaType {
    AREA_SPHERE=0,
    AREA_BOX=1,
    AREA_GEOMETRY=2,
    AREA_SHAPE=3,
    AREA_CYLINDER=4,
    AREA_SPLINE=5
} EAreaType;

typedef struct IScriptTable IScriptTable, *PIScriptTable;

typedef struct vector<CListenerSet<IEntityClassRegistryListener*>::ListenerRecord,std::allocator<CListenerSet<IEntityClassRegistryListener*>::ListenerRecord>> vector<CListenerSet<IEntityClassRegistryListener*>::ListenerRecord,std::allocator<CListenerSet<IEntityClassRegistryListener*>::ListenerRecord>>, *Pvector<CListenerSet<IEntityClassRegistryListener*>::ListenerRecord,std::allocator<CListenerSet<IEntityClassRegistryListener*>::ListenerRecord>>;

typedef ulonglong __uint64;

typedef struct Vec3_tpl<int> Vec3_tpl<int>, *PVec3_tpl<int>;

typedef struct vector<std::pair<unsignedint,CAreaManager::SAreasCache>,std::allocator<std::pair<unsignedint,CAreaManager::SAreasCache>>> vector<std::pair<unsignedint,CAreaManager::SAreasCache>,std::allocator<std::pair<unsignedint,CAreaManager::SAreasCache>>>, *Pvector<std::pair<unsignedint,CAreaManager::SAreasCache>,std::allocator<std::pair<unsignedint,CAreaManager::SAreasCache>>>;

typedef struct vector<std::pair<unsignedint,unsigned__int64>,std::allocator<std::pair<unsignedint,unsigned__int64>>> vector<std::pair<unsignedint,unsigned__int64>,std::allocator<std::pair<unsignedint,unsigned__int64>>>, *Pvector<std::pair<unsignedint,unsigned__int64>,std::allocator<std::pair<unsignedint,unsigned__int64>>>;

typedef struct IXmlNode IXmlNode, *PIXmlNode;

typedef struct ISerializeHelper ISerializeHelper, *PISerializeHelper;

typedef struct deque<CEntityPoolManager::SEntityPrepareRequest,std::allocator<CEntityPoolManager::SEntityPrepareRequest>> deque<CEntityPoolManager::SEntityPrepareRequest,std::allocator<CEntityPoolManager::SEntityPrepareRequest>>, *Pdeque<CEntityPoolManager::SEntityPrepareRequest,std::allocator<CEntityPoolManager::SEntityPrepareRequest>>;

typedef struct vector<std::pair<CGeomCacheAttachmentManager::SBinding,CGeomCacheAttachmentManager::SAttachmentData>,std::allocator<std::pair<CGeomCacheAttachmentManager::SBinding,CGeomCacheAttachmentManager::SAttachmentData>>> vector<std::pair<CGeomCacheAttachmentManager::SBinding,CGeomCacheAttachmentManager::SAttachmentData>,std::allocator<std::pair<CGeomCacheAttachmentManager::SBinding,CGeomCacheAttachmentManager::SAttachmentData>>>, *Pvector<std::pair<CGeomCacheAttachmentManager::SBinding,CGeomCacheAttachmentManager::SAttachmentData>,std::allocator<std::pair<CGeomCacheAttachmentManager::SBinding,CGeomCacheAttachmentManager::SAttachmentData>>>;

typedef struct vector<std::pair<CCharacterBoneAttachmentManager::SBinding,CCharacterBoneAttachmentManager::SAttachmentData>,std::allocator<std::pair<CCharacterBoneAttachmentManager::SBinding,CCharacterBoneAttachmentManager::SAttachmentData>>> vector<std::pair<CCharacterBoneAttachmentManager::SBinding,CCharacterBoneAttachmentManager::SAttachmentData>,std::allocator<std::pair<CCharacterBoneAttachmentManager::SBinding,CCharacterBoneAttachmentManager::SAttachmentData>>>, *Pvector<std::pair<CCharacterBoneAttachmentManager::SBinding,CCharacterBoneAttachmentManager::SAttachmentData>,std::allocator<std::pair<CCharacterBoneAttachmentManager::SBinding,CCharacterBoneAttachmentManager::SAttachmentData>>>;

typedef struct Sector Sector, *PSector;

typedef struct SGridLocation SGridLocation, *PSGridLocation;

typedef struct CEntity CEntity, *PCEntity;

typedef struct IEntityArchetype IEntityArchetype, *PIEntityArchetype;

typedef struct Matrix34_tpl<float> Matrix34_tpl<float>, *PMatrix34_tpl<float>;

typedef struct SBindings SBindings, *PSBindings;

typedef struct _smart_ptr<IMaterial> _smart_ptr<IMaterial>, *P_smart_ptr<IMaterial>;

typedef struct map<int,std::shared_ptr<IEntityProxy>,std::less<unsignedint>,stl::STLPoolAllocator<std::pair<int,std::shared_ptr<IEntityProxy>>,stl::PSyncMultiThread,0,0>> map<int,std::shared_ptr<IEntityProxy>,std::less<unsignedint>,stl::STLPoolAllocator<std::pair<int,std::shared_ptr<IEntityProxy>>,stl::PSyncMultiThread,0,0>>, *Pmap<int,std::shared_ptr<IEntityProxy>,std::less<unsignedint>,stl::STLPoolAllocator<std::pair<int,std::shared_ptr<IEntityProxy>>,stl::PSyncMultiThread,0,0>>;

typedef struct set<std::shared_ptr<IComponent>,std::less<std::shared_ptr<IComponent>>,std::allocator<std::shared_ptr<IComponent>>> set<std::shared_ptr<IComponent>,std::less<std::shared_ptr<IComponent>>,std::allocator<std::shared_ptr<IComponent>>>, *Pset<std::shared_ptr<IComponent>,std::less<std::shared_ptr<IComponent>>,std::allocator<std::shared_ptr<IComponent>>>;

typedef struct IEntityLink IEntityLink, *PIEntityLink;

typedef struct SProximityElement SProximityElement, *PSProximityElement;

typedef struct CryStringT<char> CryStringT<char>, *PCryStringT<char>;

typedef enum EBindingType {
    eBT_Pivot=0,
    eBT_GeomCacheNode=1,
    eBT_CharacterBone=2
} EBindingType;

typedef struct IMaterial IMaterial, *PIMaterial;

struct Vec3_tpl<float> {
    float x;
    float y;
    float z;
};

struct plane {
    struct Vec3_tpl<float> n;
    struct Vec3_tpl<float> origin;
};

struct vector<CEntityLoadManager::SQueuedFlowGraph,std::allocator<CEntityLoadManager::SQueuedFlowGraph>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct vector<unsignedint,std::allocator<unsignedint>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct map<unsignedint,unsignedint,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,unsignedint>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
};

struct vector<CEntityLoadManager::SHeldLayer,std::allocator<CEntityLoadManager::SHeldLayer>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct vector<std::map<unsignedint,unsignedint,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,unsignedint>>>,std::allocator<std::map<unsignedint,unsignedint,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,unsignedint>>>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct map<unsignedint,int,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,int>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
};

struct vector<SEntityAttachment,std::allocator<SEntityAttachment>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct CEntityLoadManager {
    struct vector<SEntityAttachment,std::allocator<SEntityAttachment>> m_queuedAttachments;
    struct vector<CEntityLoadManager::SQueuedFlowGraph,std::allocator<CEntityLoadManager::SQueuedFlowGraph>> m_queuedFlowgraphs;
    struct vector<CEntityLoadManager::SQueuedFlowGraph,std::allocator<CEntityLoadManager::SQueuedFlowGraph>> m_queuedEntityLinks;
    struct map<unsignedint,unsignedint,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,unsignedint>>> m_guidToId;
    struct CEntitySystem * m_pEntitySystem;
    struct vector<CEntityLoadManager::SHeldLayer,std::allocator<CEntityLoadManager::SHeldLayer>> m_heldLayers;
    struct map<unsignedint,int,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,int>>> m_layerNameMap;
    struct vector<std::map<unsignedint,unsignedint,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,unsignedint>>>,std::allocator<std::map<unsignedint,unsignedint,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,unsignedint>>>>> m_clonedLayerIds;
    struct vector<unsignedint,std::allocator<unsignedint>> m_clonedEntitiesTemp;
};

struct map<unsignedint,CEntityPoolManager::SEntityBookmark,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,CEntityPoolManager::SEntityBookmark>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
};

struct map<unsignedint,CEntityPoolDefinition*,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,CEntityPoolDefinition*>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
};

struct IEntityLink {
    char name[32];
    uint entityId;
    struct IEntityLink * next;
};

struct multimap<unsignedint,IEntityEventListener*,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,IEntityEventListener*>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
};

struct vector<CEntity*,std::allocator<CEntity*>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct SBindings {
    struct vector<CEntity*,std::allocator<CEntity*>> childs;
    struct CEntity * pParent;
    enum EBindingType parentBindingType;
};

struct pe_player_dynamics {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    float kInertia;
    float kInertiaAccel;
    float kAirControl;
    float kAirResistance;
    struct Vec3_tpl<float> gravity;
    float nodSpeed;
    int bSwimming;
    float mass;
    int surface_idx;
    float minSlideAngle;
    float maxClimbAngle;
    float maxJumpAngle;
    float minFallAngle;
    float maxVelGround;
    float timeImpulseRecover;
    int collTypes;
    undefined field20_0x4c;
    undefined field21_0x4d;
    undefined field22_0x4e;
    undefined field23_0x4f;
    struct IPhysicalEntity * pLivingEntToIgnore;
    int bNetwork;
    int bActive;
    int iRequestedTime;
    int bReleaseGroundColliderWhenNotActive;
    int bZeroG;
    int bForceVelocityOnSlope;
};

struct map<unsigned__int64,unsignedint,std::less<unsigned__int64>,std::allocator<std::pair<unsigned__int64const,unsignedint>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
};

struct ITimer {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct map<CryStringT<char>,CEntityLayer*,std::less<CryStringT<char>>,std::allocator<std::pair<CryStringT<char>const,CEntityLayer*>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
};

struct AreaDefinition {
    enum EAreaType areaType;
    float fRadius;
    struct Vec3_tpl<float> boxmin;
    struct Vec3_tpl<float> boxmax;
    struct Vec3_tpl<float> * pPoints;
    int nNumPoints;
    float zmin;
    float zmax;
    struct Vec3_tpl<float> center;
    struct Vec3_tpl<float> axis;
    struct pe_params_area * pGravityParams;
};

struct vector<IEntity*,std::allocator<IEntity*>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct unordered_map<unsigned__int64,_smart_ptr<CEntityArchetype>,std::hash<unsigned__int64>,std::equal_to<unsigned__int64>,std::allocator<std::pair<unsigned__int64const,_smart_ptr<CEntityArchetype>>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
    undefined field28_0x1c;
    undefined field29_0x1d;
    undefined field30_0x1e;
    undefined field31_0x1f;
    undefined field32_0x20;
    undefined field33_0x21;
    undefined field34_0x22;
    undefined field35_0x23;
    undefined field36_0x24;
    undefined field37_0x25;
    undefined field38_0x26;
    undefined field39_0x27;
    undefined field40_0x28;
    undefined field41_0x29;
    undefined field42_0x2a;
    undefined field43_0x2b;
    undefined field44_0x2c;
    undefined field45_0x2d;
    undefined field46_0x2e;
    undefined field47_0x2f;
    undefined field48_0x30;
    undefined field49_0x31;
    undefined field50_0x32;
    undefined field51_0x33;
    undefined field52_0x34;
    undefined field53_0x35;
    undefined field54_0x36;
    undefined field55_0x37;
    undefined field56_0x38;
    undefined field57_0x39;
    undefined field58_0x3a;
    undefined field59_0x3b;
    undefined field60_0x3c;
    undefined field61_0x3d;
    undefined field62_0x3e;
    undefined field63_0x3f;
};

struct SmartScriptTable {
    struct IScriptTable * p;
};

struct vector<IEntitySystemSink*,stl::STLGlobalAllocator<IEntitySystemSink*>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct vector<std::pair<unsignedint,unsigned__int64>,std::allocator<std::pair<unsignedint,unsigned__int64>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct AABB {
    struct Vec3_tpl<float> min;
    struct Vec3_tpl<float> max;
};

struct vector<SProximityElement*,std::allocator<SProximityElement*>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct SProximityElement {
    uint id;
    struct AABB aabb;
    uint bActivated:1;
    struct vector<SProximityElement*,std::allocator<SProximityElement*>> inside;
};

struct IPhysicalWorld {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct CPhysicsEventListener {
    struct CEntitySystem * m_pEntitySystem;
    struct IPhysicalWorld * m_pPhysics;
};

struct map<int,CComponentEventDistributer::SEventPtrs,std::less<int>,std::allocator<std::pair<intconst,CComponentEventDistributer::SEventPtrs>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
};

struct multimap<unsignedint,CComponentEventDistributer::SRegisteredComponentEvents,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,CComponentEventDistributer::SRegisteredComponentEvents>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
};

struct _Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CryStringT<char>const,IEntityClass*>>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct vector<CListenerSet<IEntityClassRegistryListener*>::ListenerRecord,std::allocator<CListenerSet<IEntityClassRegistryListener*>::ListenerRecord>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct CListenerSet<IEntityClassRegistryListener*> {
    struct vector<CListenerSet<IEntityClassRegistryListener*>::ListenerRecord,std::allocator<CListenerSet<IEntityClassRegistryListener*>::ListenerRecord>> m_listeners;
    __uint64 m_activeNotifications;
    bool m_cleanupRequired;
    bool m_freeMemOnCleanup;
};

struct map<CryStringT<char>,IEntityClass*,std::less<CryStringT<char>>,std::allocator<std::pair<CryStringT<char>const,IEntityClass*>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
};

struct CEntityClassRegistry {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    struct map<CryStringT<char>,IEntityClass*,std::less<CryStringT<char>>,std::allocator<std::pair<CryStringT<char>const,IEntityClass*>>> m_mapClassName;
    struct IEntityClass * m_pDefaultClass;
    struct ISystem * m_pSystem;
    struct _Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CryStringT<char>const,IEntityClass*>>>> m_currentMapIterator;
    struct CListenerSet<IEntityClassRegistryListener*> m_listeners;
};

struct IScriptTable {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct DynArray<CEntityTimeoutList::CEntry,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct CEntityTimeoutList {
    struct DynArray<CEntityTimeoutList::CEntry,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> m_entries;
    struct ITimer * m_pTimer;
};

struct vector<CArea*,std::allocator<CArea*>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct SPreparingParams {
    uint entityId;
    uint aiObjectId;
};

struct vector<float,std::allocator<float>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct map<int,std::shared_ptr<IEntityProxy>,std::less<unsignedint>,stl::STLPoolAllocator<std::pair<int,std::shared_ptr<IEntityProxy>>,stl::PSyncMultiThread,0,0>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
};

struct IXmlNode {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    int m_nRefCount;
    undefined field9_0xc;
    undefined field10_0xd;
    undefined field11_0xe;
    undefined field12_0xf;
};

struct Quat_tpl<float> {
    struct Vec3_tpl<float> v;
    float w;
};

struct Matrix34_tpl<float> {
    float m00;
    float m01;
    float m02;
    float m03;
    float m10;
    float m11;
    float m12;
    float m13;
    float m20;
    float m21;
    float m22;
    float m23;
};

struct set<std::shared_ptr<IComponent>,std::less<std::shared_ptr<IComponent>>,std::allocator<std::shared_ptr<IComponent>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
};

struct _smart_ptr<IMaterial> {
    struct IMaterial * p;
};

struct CryStringT<char> {
    char * m_str;
};

struct CEntity {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    uint m_bActive:1;
    uint m_bInActiveList:1;
    uint m_bBoundsValid:1;
    uint m_bInitialized:1;
    uint m_bHidden:1;
    uint m_bGarbage:1;
    uint m_bHaveEventListeners:1;
    uint m_bTrigger:1;
    uint m_bWasRellocated:1;
    uint m_nUpdateCounter:4;
    uint m_eUpdatePolicy:4;
    uint m_bInvisible:1;
    uint m_bNotInheritXform:1;
    uint m_bInShutDown:1;
    uint m_bIsFromPool:1;
    undefined field23_0xb;
    bool m_bDirtyForwardDir:1;
    undefined field25_0xd;
    undefined field26_0xe;
    undefined field27_0xf;
    uint m_bLoadedFromLevelFile:1;
    uint m_bHasPhysicsState:1;
    undefined field30_0x11;
    undefined field31_0x12;
    undefined field32_0x13;
    uint m_nID;
    __uint64 m_guid;
    uint m_flags;
    uint m_flagsExtended;
    struct IEntityClass * m_pClass;
    struct IEntityArchetype * m_pArchetype;
    struct Vec3_tpl<float> m_vPos;
    struct Quat_tpl<float> m_qRotation;
    struct Vec3_tpl<float> m_vScale;
    struct Matrix34_tpl<float> m_worldTM;
    struct Vec3_tpl<float> m_vForwardDir;
    undefined field44_0x9c;
    undefined field45_0x9d;
    undefined field46_0x9e;
    undefined field47_0x9f;
    struct SBindings * m_pBinds;
    uint m_aiObjectID;
    undefined field50_0xac;
    undefined field51_0xad;
    undefined field52_0xae;
    undefined field53_0xaf;
    struct _smart_ptr<IMaterial> m_pMaterial;
    struct map<int,std::shared_ptr<IEntityProxy>,std::less<unsignedint>,stl::STLPoolAllocator<std::pair<int,std::shared_ptr<IEntityProxy>>,stl::PSyncMultiThread,0,0>> m_proxy;
    struct set<std::shared_ptr<IComponent>,std::less<std::shared_ptr<IComponent>>,std::allocator<std::shared_ptr<IComponent>>> m_components;
    struct IEntityLink * m_pEntityLinks;
    struct SGridLocation * m_pGridLocation;
    struct SProximityElement * m_pProximityEntity;
    uint m_nKeepAliveCounter;
    undefined field61_0xf4;
    undefined field62_0xf5;
    undefined field63_0xf6;
    undefined field64_0xf7;
    struct CryStringT<char> m_szName;
    int m_cloneLayerId;
    uchar m_initialSceneMask;
    undefined field68_0x105;
    undefined field69_0x106;
    undefined field70_0x107;
    struct CryStringT<char> m_displayName;
};

struct CPartitionGrid {
    float m_worldToSector;
    int m_nWidth;
    int m_nHeight;
    int m_numSectorsX;
    int m_numSectorsY;
    undefined field5_0x14;
    undefined field6_0x15;
    undefined field7_0x16;
    undefined field8_0x17;
    struct SectorGroup * * m_pSectorGroups;
    bool m_bResetting;
    undefined field11_0x21;
    undefined field12_0x22;
    undefined field13_0x23;
    undefined field14_0x24;
    undefined field15_0x25;
    undefined field16_0x26;
    undefined field17_0x27;
    struct vector<IEntity*,std::allocator<IEntity*>> m_entityCache;
};

struct vector<std::pair<CCharacterBoneAttachmentManager::SBinding,CCharacterBoneAttachmentManager::SAttachmentData>,std::allocator<std::pair<CCharacterBoneAttachmentManager::SBinding,CCharacterBoneAttachmentManager::SAttachmentData>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct VectorMap<CCharacterBoneAttachmentManager::SBinding,CCharacterBoneAttachmentManager::SAttachmentData,std::less<CCharacterBoneAttachmentManager::SBinding>,std::allocator<std::pair<CCharacterBoneAttachmentManager::SBinding,CCharacterBoneAttachmentManager::SAttachmentData>>> {
    struct vector<std::pair<CCharacterBoneAttachmentManager::SBinding,CCharacterBoneAttachmentManager::SAttachmentData>,std::allocator<std::pair<CCharacterBoneAttachmentManager::SBinding,CCharacterBoneAttachmentManager::SAttachmentData>>> m_entries;
};

struct CCharacterBoneAttachmentManager {
    struct VectorMap<CCharacterBoneAttachmentManager::SBinding,CCharacterBoneAttachmentManager::SAttachmentData,std::less<CCharacterBoneAttachmentManager::SBinding>,std::allocator<std::pair<CCharacterBoneAttachmentManager::SBinding,CCharacterBoneAttachmentManager::SAttachmentData>>> m_attachments;
};

struct set<IEntityconst*,std::less<IEntityconst*>,std::allocator<IEntityconst*>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
};

struct _smart_ptr<ISerializeHelper> {
    struct ISerializeHelper * p;
};

struct vector<CListenerSet<IEntityPoolListener*>,std::allocator<CListenerSet<IEntityPoolListener*>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct XmlNodeRef {
    struct IXmlNode * p;
};

struct deque<CEntityPoolManager::SEntityPrepareRequest,std::allocator<CEntityPoolManager::SEntityPrepareRequest>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
    undefined field28_0x1c;
    undefined field29_0x1d;
    undefined field30_0x1e;
    undefined field31_0x1f;
    undefined field32_0x20;
    undefined field33_0x21;
    undefined field34_0x22;
    undefined field35_0x23;
    undefined field36_0x24;
    undefined field37_0x25;
    undefined field38_0x26;
    undefined field39_0x27;
};

struct queue<CEntityPoolManager::SEntityPrepareRequest,std::deque<CEntityPoolManager::SEntityPrepareRequest,std::allocator<CEntityPoolManager::SEntityPrepareRequest>>> {
    struct deque<CEntityPoolManager::SEntityPrepareRequest,std::allocator<CEntityPoolManager::SEntityPrepareRequest>> c;
};

struct map<unsignedint,CEntityPool*,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,CEntityPool*>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
};

struct CEntityPoolManager {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    bool m_bEnabled;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    struct XmlNodeRef m_pRootSID;
    struct CEntitySystem * m_pEntitySystem;
    struct _smart_ptr<ISerializeHelper> m_pSerializeHelper;
    struct vector<CListenerSet<IEntityPoolListener*>,std::allocator<CListenerSet<IEntityPoolListener*>>> m_Listeners;
    struct map<unsignedint,CEntityPool*,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,CEntityPool*>>> m_EntityPools;
    struct map<unsignedint,CEntityPoolDefinition*,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,CEntityPoolDefinition*>>> m_PoolDefinitions;
    struct map<unsignedint,CEntityPoolManager::SEntityBookmark,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,CEntityPoolManager::SEntityBookmark>>> m_PoolBookmarks;
    struct queue<CEntityPoolManager::SEntityPrepareRequest,std::deque<CEntityPoolManager::SEntityPrepareRequest,std::allocator<CEntityPoolManager::SEntityPrepareRequest>>> m_PrepareRequestQueue;
    uint m_uFramePrepareRequests;
    struct SPreparingParams m_currentParams;
    bool m_preparingFromPool;
    undefined field27_0xa5;
    undefined field28_0xa6;
    undefined field29_0xa7;
};

struct vector<IEntityArchetypeListener*,std::allocator<IEntityArchetypeListener*>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct map<charconst*,_smart_ptr<CEntityArchetype>,stl::less_stricmp<charconst*>,std::allocator<std::pair<charconst*const,_smart_ptr<CEntityArchetype>>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
};

struct DynArray<CryStringT<char>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct CEntityArchetypeManager {
    struct map<charconst*,_smart_ptr<CEntityArchetype>,stl::less_stricmp<charconst*>,std::allocator<std::pair<charconst*const,_smart_ptr<CEntityArchetype>>>> m_nameToArchetypeMap;
    struct unordered_map<unsigned__int64,_smart_ptr<CEntityArchetype>,std::hash<unsigned__int64>,std::equal_to<unsigned__int64>,std::allocator<std::pair<unsigned__int64const,_smart_ptr<CEntityArchetype>>>> m_idToArchetypeMap;
    struct DynArray<CryStringT<char>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> m_loadedLibs;
    struct vector<IEntityArchetypeListener*,std::allocator<IEntityArchetypeListener*>> m_listeners;
};

struct pe_params_area {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    struct Vec3_tpl<float> gravity;
    float falloff0;
    int bUniform;
    int bUseCallback;
    float damping;
    struct IGeometry * pGeom;
    float volume;
    float volumeAccuracy;
    float borderPad;
    int bConvexBorder;
    float objectVolumeThreshold;
    float cellSize;
    float waveSpeed;
    float waveDamping;
    float waveTimestep;
    float growthReserve;
    int affectsParticleEmitterPos;
    undefined field21_0x54;
    undefined field22_0x55;
    undefined field23_0x56;
    undefined field24_0x57;
};

struct IBreakableManager {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct vector<std::pair<CGeomCacheAttachmentManager::SBinding,CGeomCacheAttachmentManager::SAttachmentData>,std::allocator<std::pair<CGeomCacheAttachmentManager::SBinding,CGeomCacheAttachmentManager::SAttachmentData>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct VectorMap<CGeomCacheAttachmentManager::SBinding,CGeomCacheAttachmentManager::SAttachmentData,std::less<CGeomCacheAttachmentManager::SBinding>,std::allocator<std::pair<CGeomCacheAttachmentManager::SBinding,CGeomCacheAttachmentManager::SAttachmentData>>> {
    struct vector<std::pair<CGeomCacheAttachmentManager::SBinding,CGeomCacheAttachmentManager::SAttachmentData>,std::allocator<std::pair<CGeomCacheAttachmentManager::SBinding,CGeomCacheAttachmentManager::SAttachmentData>>> m_entries;
};

struct CGeomCacheAttachmentManager {
    struct VectorMap<CGeomCacheAttachmentManager::SBinding,CGeomCacheAttachmentManager::SAttachmentData,std::less<CGeomCacheAttachmentManager::SBinding>,std::allocator<std::pair<CGeomCacheAttachmentManager::SBinding,CGeomCacheAttachmentManager::SAttachmentData>>> m_attachments;
};

struct vector<Vec3_tpl<float>,std::allocator<Vec3_tpl<float>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct vector<std::pair<unsignedint,CAreaManager::SAreasCache>,std::allocator<std::pair<unsignedint,CAreaManager::SAreasCache>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct vector<SProximityEvent,std::allocator<SProximityEvent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct IVisArea {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct unordered_map<unsignedint,float,std::hash<unsignedint>,std::equal_to<unsignedint>,std::allocator<std::pair<unsignedintconst,float>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
    undefined field28_0x1c;
    undefined field29_0x1d;
    undefined field30_0x1e;
    undefined field31_0x1f;
    undefined field32_0x20;
    undefined field33_0x21;
    undefined field34_0x22;
    undefined field35_0x23;
    undefined field36_0x24;
    undefined field37_0x25;
    undefined field38_0x26;
    undefined field39_0x27;
    undefined field40_0x28;
    undefined field41_0x29;
    undefined field42_0x2a;
    undefined field43_0x2b;
    undefined field44_0x2c;
    undefined field45_0x2d;
    undefined field46_0x2e;
    undefined field47_0x2f;
    undefined field48_0x30;
    undefined field49_0x31;
    undefined field50_0x32;
    undefined field51_0x33;
    undefined field52_0x34;
    undefined field53_0x35;
    undefined field54_0x36;
    undefined field55_0x37;
    undefined field56_0x38;
    undefined field57_0x39;
    undefined field58_0x3a;
    undefined field59_0x3b;
    undefined field60_0x3c;
    undefined field61_0x3d;
    undefined field62_0x3e;
    undefined field63_0x3f;
};

struct pe_player_dimensions {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    float heightPivot;
    float heightEye;
    struct Vec3_tpl<float> sizeCollider;
    float heightCollider;
    float headRadius;
    float heightHead;
    struct Vec3_tpl<float> dirUnproj;
    float maxUnproj;
    int bUseCapsule;
    float groundContactEps;
    uint ignoreCollisionsWith;
};

struct pe_params_particle {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    uint flags;
    float mass;
    float size;
    float thickness;
    struct Vec3_tpl<float> heading;
    float velocity;
    float kAirResistance;
    float kWaterResistance;
    float accThrust;
    float accLift;
    int surface_idx;
    struct Vec3_tpl<float> wspin;
    struct Vec3_tpl<float> gravity;
    struct Vec3_tpl<float> waterGravity;
    struct Vec3_tpl<float> normal;
    struct Vec3_tpl<float> rollAxis;
    struct Quat_tpl<float> q0;
    float minBounceVel;
    float minVel;
    undefined field23_0x8c;
    undefined field24_0x8d;
    undefined field25_0x8e;
    undefined field26_0x8f;
    struct IPhysicalEntity * pColliderToIgnore;
    int iPierceability;
    int collTypes;
    int areaCheckPeriod;
    int dontPlayHitEffect;
    int ownerEntityId;
    undefined field33_0xac;
    undefined field34_0xad;
    undefined field35_0xae;
    undefined field36_0xaf;
};

struct pe_params_car {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    float axleFriction;
    float enginePower;
    float maxSteer;
    float engineMaxRPM;
    float brakeTorque;
    int iIntegrationType;
    float maxTimeStep;
    float minEnergy;
    float damping;
    float minBrakingFriction;
    float maxBrakingFriction;
    float kStabilizer;
    int nWheels;
    float engineMinRPM;
    float engineShiftUpRPM;
    float engineShiftDownRPM;
    float engineIdleRPM;
    float engineStartRPM;
    float clutchSpeed;
    int nGears;
    undefined field24_0x54;
    undefined field25_0x55;
    undefined field26_0x56;
    undefined field27_0x57;
    float * gearRatios;
    int maxGear;
    int minGear;
    float slipThreshold;
    float gearDirSwitchRPM;
    float kDynFriction;
    float steerTrackNeutralTurn;
    float pullTilt;
    float maxTilt;
    int bKeepTractionWhenTilted;
    undefined field38_0x84;
    undefined field39_0x85;
    undefined field40_0x86;
    undefined field41_0x87;
};

struct pe_params_buoyancy {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    float waterDensity;
    float kwaterDensity;
    float waterDamping;
    float waterResistance;
    float kwaterResistance;
    struct Vec3_tpl<float> waterFlow;
    float flowVariance;
    struct plane waterPlane;
    float waterEmin;
    int iMedium;
};

struct CScriptBind_Entity {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
    undefined field28_0x1c;
    undefined field29_0x1d;
    undefined field30_0x1e;
    undefined field31_0x1f;
    undefined field32_0x20;
    undefined field33_0x21;
    undefined field34_0x22;
    undefined field35_0x23;
    undefined field36_0x24;
    undefined field37_0x25;
    undefined field38_0x26;
    undefined field39_0x27;
    undefined field40_0x28;
    undefined field41_0x29;
    undefined field42_0x2a;
    undefined field43_0x2b;
    undefined field44_0x2c;
    undefined field45_0x2d;
    undefined field46_0x2e;
    undefined field47_0x2f;
    undefined field48_0x30;
    undefined field49_0x31;
    undefined field50_0x32;
    undefined field51_0x33;
    undefined field52_0x34;
    undefined field53_0x35;
    undefined field54_0x36;
    undefined field55_0x37;
    undefined field56_0x38;
    undefined field57_0x39;
    undefined field58_0x3a;
    undefined field59_0x3b;
    undefined field60_0x3c;
    undefined field61_0x3d;
    undefined field62_0x3e;
    undefined field63_0x3f;
    undefined field64_0x40;
    undefined field65_0x41;
    undefined field66_0x42;
    undefined field67_0x43;
    undefined field68_0x44;
    undefined field69_0x45;
    undefined field70_0x46;
    undefined field71_0x47;
    undefined field72_0x48;
    undefined field73_0x49;
    undefined field74_0x4a;
    undefined field75_0x4b;
    undefined field76_0x4c;
    undefined field77_0x4d;
    undefined field78_0x4e;
    undefined field79_0x4f;
    undefined field80_0x50;
    undefined field81_0x51;
    undefined field82_0x52;
    undefined field83_0x53;
    undefined field84_0x54;
    undefined field85_0x55;
    undefined field86_0x56;
    undefined field87_0x57;
    undefined field88_0x58;
    undefined field89_0x59;
    undefined field90_0x5a;
    undefined field91_0x5b;
    undefined field92_0x5c;
    undefined field93_0x5d;
    undefined field94_0x5e;
    undefined field95_0x5f;
    struct IEntitySystem * m_pEntitySystem;
    struct ISystem * m_pISystem;
    struct pe_params_particle m_particleParams;
    struct pe_params_buoyancy m_buoyancyParams;
    struct pe_player_dimensions m_playerDimensions;
    struct pe_player_dynamics m_playerDynamics;
    struct pe_params_area m_areaGravityParams;
    struct AreaDefinition m_areaDefinition;
    struct vector<Vec3_tpl<float>,std::allocator<Vec3_tpl<float>>> m_areaPoints;
    struct pe_params_car m_carParams;
    struct SmartScriptTable m_pStats;
    bool m_bIsAudioEventListener;
    undefined field108_0x371;
    undefined field109_0x372;
    undefined field110_0x373;
    undefined field111_0x374;
    undefined field112_0x375;
    undefined field113_0x376;
    undefined field114_0x377;
};

struct Sector {
    struct SGridLocation * first;
};

struct SectorGroup {
    int nLocationCount;
    struct Sector sectors[16][16];
};

struct map<unsignedint,CEntity*,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,CEntity*>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
};

struct CAreaGrid {
    struct CEntitySystem * m_pEntitySystem;
    uint m_nCells;
    uint m_nZCells;
    uint * m_pbitFieldX;
    uint * m_pbitFieldY;
    uint * m_pbitFieldZ;
    uint m_bitFieldSizeU32;
    uint m_maxNumAreas;
    struct Vec3_tpl<int>[2] * m_pAreaBounds;
    struct vector<CArea*,std::allocator<CArea*>> * m_papAreas;
    struct vector<CArea*,std::allocator<CArea*>> m_apAreasTmp;
};

struct VectorMap<unsignedint,CAreaManager::SAreasCache,std::less<unsignedint>,std::allocator<std::pair<unsignedint,CAreaManager::SAreasCache>>> {
    struct vector<std::pair<unsignedint,CAreaManager::SAreasCache>,std::allocator<std::pair<unsignedint,CAreaManager::SAreasCache>>> m_entries;
};

struct VectorMap<unsignedint,unsigned__int64,std::less<unsignedint>,std::allocator<std::pair<unsignedint,unsigned__int64>>> {
    struct vector<std::pair<unsignedint,unsigned__int64>,std::allocator<std::pair<unsignedint,unsigned__int64>>> m_entries;
};

struct vector<IAreaManagerEventListener*,std::allocator<IAreaManagerEventListener*>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct CAreaManager {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    struct vector<CArea*,std::allocator<CArea*>> m_apAreas;
    struct CEntitySystem * m_pEntitySystem;
    int m_nCurSoundStep;
    int m_nCurTailStep;
    bool m_bAreasDirty;
    undefined field21_0x39;
    undefined field22_0x3a;
    undefined field23_0x3b;
    undefined field24_0x3c;
    undefined field25_0x3d;
    undefined field26_0x3e;
    undefined field27_0x3f;
    struct CAreaGrid m_areaGrid;
    struct IVisArea * m_pPrevArea;
    struct IVisArea * m_pCurrArea;
    struct vector<IAreaManagerEventListener*,std::allocator<IAreaManagerEventListener*>> m_EventListeners;
    struct VectorMap<unsignedint,CAreaManager::SAreasCache,std::less<unsignedint>,std::allocator<std::pair<unsignedint,CAreaManager::SAreasCache>>> m_mapAreaCache;
    struct VectorMap<unsignedint,unsigned__int64,std::less<unsignedint>,std::allocator<std::pair<unsignedint,unsigned__int64>>> m_mapEntitiesToUpdate;
};

struct vector<CComponentEventDistributer::SEventPtr,std::allocator<CComponentEventDistributer::SEventPtr>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct SGridLocation {
    struct SGridLocation * next;
    struct SGridLocation * prev;
    int nSectorIndex;
    struct CEntity * pEntity;
    struct IEntityClass * pEntityClass;
    uint nEntityFlags;
};

struct CCryFlags<unsignedint> {
    uint m_bitStorage;
};

struct CComponentEventDistributer {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    struct multimap<unsignedint,CComponentEventDistributer::SRegisteredComponentEvents,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,CComponentEventDistributer::SRegisteredComponentEvents>>> m_componentRegistration;
    struct map<int,CComponentEventDistributer::SEventPtrs,std::less<int>,std::allocator<std::pair<intconst,CComponentEventDistributer::SEventPtrs>>> m_componentDistributer;
    struct map<unsignedint,unsignedint,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,unsignedint>>> m_mappedEntityIDs;
    struct vector<CComponentEventDistributer::SEventPtr,std::allocator<CComponentEventDistributer::SEventPtr>> m_eventPtrTemp;
    struct CCryFlags<unsignedint> m_flags;
    undefined field13_0x54;
    undefined field14_0x55;
    undefined field15_0x56;
    undefined field16_0x57;
};

struct IPhysicalEntity {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct set<unsignedint,std::less<unsignedint>,std::allocator<unsignedint>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
};

struct unordered_map<unsignedint,std::vector<unsignedint,std::allocator<unsignedint>>,std::hash<unsignedint>,std::equal_to<unsignedint>,std::allocator<std::pair<unsignedintconst,std::vector<unsignedint,std::allocator<unsignedint>>>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
    undefined field28_0x1c;
    undefined field29_0x1d;
    undefined field30_0x1e;
    undefined field31_0x1f;
    undefined field32_0x20;
    undefined field33_0x21;
    undefined field34_0x22;
    undefined field35_0x23;
    undefined field36_0x24;
    undefined field37_0x25;
    undefined field38_0x26;
    undefined field39_0x27;
    undefined field40_0x28;
    undefined field41_0x29;
    undefined field42_0x2a;
    undefined field43_0x2b;
    undefined field44_0x2c;
    undefined field45_0x2d;
    undefined field46_0x2e;
    undefined field47_0x2f;
    undefined field48_0x30;
    undefined field49_0x31;
    undefined field50_0x32;
    undefined field51_0x33;
    undefined field52_0x34;
    undefined field53_0x35;
    undefined field54_0x36;
    undefined field55_0x37;
    undefined field56_0x38;
    undefined field57_0x39;
    undefined field58_0x3a;
    undefined field59_0x3b;
    undefined field60_0x3c;
    undefined field61_0x3d;
    undefined field62_0x3e;
    undefined field63_0x3f;
};

struct IMaterial {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    uchar m_ucDefautMappingAxis;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    float m_fDefautMappingScale;
};

struct SSaltBufferElement {
    ushort m_Salt;
    ushort m_NextIndex;
};

struct IEntityClass {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct vector<IEntityClassconst*,std::allocator<IEntityClassconst*>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct RadixSort {
    uint mCurrentSize;
    uint mAllocatedSize;
    uint * mRanks;
    uint * mRanks2;
    uint mTotalCalls;
    uint mNbHits;
};

struct IGeometry {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct vector<SEntityLayerGarbage,std::allocator<SEntityLayerGarbage>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct ISerializeHelper {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct vector<CEntitySystem::OnEventSink,stl::STLGlobalAllocator<CEntitySystem::OnEventSink>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct IEntityArchetype {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct CSaltBufferArray<unsignedshort,unsignedshort,65533> {
    struct SSaltBufferElement m_Buffer[65533];
    ushort m_FreeListStartIndex;
    ushort m_maxUsed;
};

struct vector<SEntityTimerEvent,std::allocator<SEntityTimerEvent>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct multimap<CTimeValue,SEntityTimerEvent,std::less<CTimeValue>,stl::STLPoolAllocator<std::pair<CTimeValue,SEntityTimerEvent>,stl::PSyncNone,0,0>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
};

struct Vec3_tpl<int> {
    int x;
    int y;
    int z;
};

struct multimap<charconst*,unsignedint,stl::less_stricmp<charconst*>,std::allocator<std::pair<charconst*const,unsignedint>>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
};

struct IEntitySystem {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

struct vector<AABB,std::allocator<AABB>> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
};

struct CProximityTriggerSystem {
    struct vector<SProximityElement*,std::allocator<SProximityElement*>> m_triggers;
    struct vector<SProximityElement*,std::allocator<SProximityElement*>> m_triggersToRemove;
    struct vector<SProximityElement*,std::allocator<SProximityElement*>> m_entitiesToRemove;
    bool m_bTriggerMoved;
    bool m_bResetting;
    undefined field5_0x4a;
    undefined field6_0x4b;
    undefined field7_0x4c;
    undefined field8_0x4d;
    undefined field9_0x4e;
    undefined field10_0x4f;
    struct vector<SProximityElement*,std::allocator<SProximityElement*>> m_entities;
    struct vector<AABB,std::allocator<AABB>> m_triggersAABB;
    struct vector<SProximityEvent,std::allocator<SProximityEvent>> m_events;
    struct RadixSort * m_pTriggerSorter;
    struct RadixSort * m_pEntitySorter;
    struct vector<float,std::allocator<float>> m_minPosList0;
    struct vector<float,std::allocator<float>> m_minPosList1;
    struct unordered_map<unsignedint,std::vector<unsignedint,std::allocator<unsignedint>>,std::hash<unsignedint>,std::equal_to<unsignedint>,std::allocator<std::pair<unsignedintconst,std::vector<unsignedint,std::allocator<unsignedint>>>>> m_entitiesInTrigger;
    uint * m_Sorted0;
    uint * m_Sorted1;
};

struct CTimeValue {
    __int64 m_lValue;
};

struct CEntitySystem {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    struct unordered_map<unsignedint,float,std::hash<unsignedint>,std::equal_to<unsignedint>,std::allocator<std::pair<unsignedintconst,float>>> m_queuedEntityVisibilities;
    struct vector<IEntitySystemSink*,stl::STLGlobalAllocator<IEntitySystemSink*>> m_sinks[5];
    struct vector<CEntitySystem::OnEventSink,stl::STLGlobalAllocator<CEntitySystem::OnEventSink>> m_onEventSinks;
    struct ISystem * m_pISystem;
    struct vector<CEntity*,std::allocator<CEntity*>> m_EntityArray;
    struct vector<CEntity*,std::allocator<CEntity*>> m_deletedEntities;
    struct vector<CEntity*,std::allocator<CEntity*>> m_deferredUsedEntities;
    struct map<unsignedint,CEntity*,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,CEntity*>>> m_mapActiveEntities;
    bool m_tempActiveEntitiesValid;
    undefined field17_0x139;
    undefined field18_0x13a;
    undefined field19_0x13b;
    undefined field20_0x13c;
    undefined field21_0x13d;
    undefined field22_0x13e;
    undefined field23_0x13f;
    struct set<unsignedint,std::less<unsignedint>,std::allocator<unsignedint>> m_mapPrePhysicsEntities;
    struct multimap<charconst*,unsignedint,stl::less_stricmp<charconst*>,std::allocator<std::pair<charconst*const,unsignedint>>> m_mapEntityNames;
    struct CSaltBufferArray<unsignedshort,unsignedshort,65533> m_EntitySaltBuffer;
    struct vector<unsignedint,std::allocator<unsignedint>> m_tempActiveEntities;
    struct CComponentEventDistributer * m_pEventDistributer;
    struct multimap<CTimeValue,SEntityTimerEvent,std::less<CTimeValue>,stl::STLPoolAllocator<std::pair<CTimeValue,SEntityTimerEvent>,stl::PSyncNone,0,0>> m_timersMap;
    struct vector<SEntityTimerEvent,std::allocator<SEntityTimerEvent>> m_currentTimers;
    bool m_bTimersPause;
    undefined field32_0x401a1;
    undefined field33_0x401a2;
    undefined field34_0x401a3;
    undefined field35_0x401a4;
    undefined field36_0x401a5;
    undefined field37_0x401a6;
    undefined field38_0x401a7;
    struct CTimeValue m_nStartPause;
    struct CScriptBind_Entity * m_pEntityScriptBinding;
    struct CEntityClassRegistry * m_pClassRegistry;
    struct CPhysicsEventListener * m_pPhysicsEventListener;
    struct CAreaManager * m_pAreaManager;
    struct CEntityLoadManager * m_pEntityLoadManager;
    struct CEntityPoolManager * m_pEntityPoolManager;
    struct multimap<unsignedint,IEntityEventListener*,std::less<unsignedint>,std::allocator<std::pair<unsignedintconst,IEntityEventListener*>>> m_eventListeners[60];
    int m_eventListenerBeingProcessedRefCount;
    undefined field48_0x405a4;
    undefined field49_0x405a5;
    undefined field50_0x405a6;
    undefined field51_0x405a7;
    struct map<unsigned__int64,unsignedint,std::less<unsigned__int64>,std::allocator<std::pair<unsigned__int64const,unsignedint>>> m_guidMap;
    struct map<unsigned__int64,unsignedint,std::less<unsigned__int64>,std::allocator<std::pair<unsigned__int64const,unsignedint>>> m_genIdMap;
    struct IBreakableManager * m_pBreakableManager;
    struct CEntityArchetypeManager * m_pEntityArchetypeManager;
    struct CGeomCacheAttachmentManager * m_pGeomCacheAttachmentManager;
    struct CCharacterBoneAttachmentManager * m_pCharacterBoneAttachmentManager;
    struct CPartitionGrid * m_pPartitionGrid;
    struct CProximityTriggerSystem * m_pProximityTriggerSystem;
    uint m_idForced;
    bool m_bLocked;
    undefined field62_0x405fd;
    undefined field63_0x405fe;
    undefined field64_0x405ff;
    struct CEntityTimeoutList m_entityTimeoutList;
    struct map<CryStringT<char>,CEntityLayer*,std::less<CryStringT<char>>,std::allocator<std::pair<CryStringT<char>const,CEntityLayer*>>> m_layers;
    struct vector<SEntityLayerGarbage,std::allocator<SEntityLayerGarbage>> m_garbageLayerHeaps;
    struct set<IEntityconst*,std::less<IEntityconst*>,std::allocator<IEntityconst*>> m_EntitiesUsingPlayerTime;
    struct vector<IEntityClassconst*,std::allocator<IEntityClassconst*>> m_areaTriggeringClasses;
    struct AABB m_safeBounds;
    bool m_bReseting;
    undefined field72_0x40679;
    undefined field73_0x4067a;
    undefined field74_0x4067b;
    undefined field75_0x4067c;
    undefined field76_0x4067d;
    undefined field77_0x4067e;
    undefined field78_0x4067f;
};

struct ISystem {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

