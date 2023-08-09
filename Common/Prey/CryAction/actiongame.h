// Header file automatically created from a PDB.

#pragma once
#include <Prey/cryaction/ark/ArkActionGame.h>
#include <Prey/CryCore/StdAfx.h>
#include <Prey/CryAction/ActionGame.h>
#include <Prey/CryAction/IGameRulesSystem.h>
#include <Prey/CryAction/IMaterialEffects.h>
#include <Prey/CryCore/smartptr.h>
#include <Prey/CryGame/IGameFramework.h>
#include <Prey/CryMemory/CrySizer.h>
#include <Prey/CryNetwork/INetwork.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryNetwork/IHostMigrationEventListener.h>
#include <Prey/CryAction/IHitListener.h>
#include <Prey/CryAction/SGameStartParams.h>
#include <Prey/CryAction/SGameContextParams.h>

class CGameClientChannel;
class CGameClientNub;
class CGameContext;
class CGameServerNub;
class CGameStats;
class CScriptRMI;
struct EventPhys;
struct EventPhysCollision;
struct ExplosionInfo;
struct HitInfo;
struct IActor;
struct IEntity;
struct IEntitySystem;
struct IGameObject;
struct IGameTokenSystem;
struct IGeometry;
struct IMaterialEffects;
struct INetContext;
struct INetNub;
struct INetwork;
struct IPhysicalEntity;
struct IPhysicalWorld;
struct IRenderNode;
struct IResourceCollector;
struct IStatObj;
struct ISurfaceType;
struct SBrokenMeshSize;
struct SEntityCollHist;
struct SEntityHits;
struct SHostMigrationInfo;
class SBreakEvent;
struct IRenderNode;
struct IStatObj;
struct IPhysicalEntity;
struct IStatObj;
struct STreePieceThunk;

struct SBrokenEntPart // Id=8004A89 Size=8
{
    unsigned idSrcEnt;
    unsigned idNewEnt;

#if 0
    void Serialize(TSerialize arg0);
	void GetMemoryUsage(ICrySizer *arg0) const;
#endif
};
struct SBrokenVegPart // Id=8004A97 Size=20
{
    Vec3 pos;
    float volume;
    unsigned idNewEnt;

#if 0
    void Serialize(TSerialize arg0);
	void GetMemoryUsage(ICrySizer *arg0) const;
#endif
};
struct SProcBrokenObjRec // Id=8004A6E Size=32
{
    IRenderNode *pBrush;
    IStatObj *pStatObjOrg;
    unsigned idEnt;
    int itype;
    int islot;
    float mass;

#if 0
    void GetMemoryUsage(ICrySizer *arg0) const;
#endif
};


// Header: MadeUp
// _unknown/STreeBreakInst.h
struct STreeBreakInst // Id=8004AC6 Size=56
{
    IPhysicalEntity *pPhysEntSrc;
    IPhysicalEntity *pPhysEntNew0;
    STreePieceThunk *pNextPiece;
    STreeBreakInst *pThis;
    STreeBreakInst *pNext;
    IStatObj *pStatObj;
    float cutHeight;
    float cutSize;
};


struct STreePieceThunk // Id=8004AC7 Size=24
{
    IPhysicalEntity *pPhysEntNew;
    STreePieceThunk *pNext;
    STreeBreakInst *pParent;
};


// Header: FromCpp
// CryEngine/cryaction/actiongame.h
class CActionGame : public IHitListener, public CMultiThreadRefCount, public IHostMigrationEventListener // Id=8004A06 Size=2576
{
public:
	using BlockingConditionFunction = bool (*)(CGameClientChannel *);
	
	enum eInitTaskState
	{
		eITS_InProgress = 0,
		eITS_Done = 1,
		eITS_Error = 2,
	};

	enum EProceduralBreakType
	{
		ePBT_Normal = 16,
		ePBT_Glass = 1,
	};

	enum EProceduralBreakFlags
	{
		ePBF_ObeyCVar = 1,
		ePBF_AllowGlass = 2,
		ePBF_DefaultAllow = 8,
	};

	uint8_t m_proceduralBreakFlags;
	static inline auto s_this = PreyGlobal<CActionGame *>(0x249EFF0);
	IEntitySystem *m_pEntitySystem;
	INetwork *m_pNetwork;
	INetNub *m_pClientNub;
	INetNub *m_pServerNub;
	CGameClientNub *m_pGameClientNub;
	CGameServerNub *m_pGameServerNub;
	CGameContext *m_pGameContext;
	INetContext *m_pNetContext;
	IGameTokenSystem *m_pGameTokenSystem;
	IPhysicalWorld *m_pPhysicalWorld;
	IMaterialEffects *m_pMaterialEffects;
	
	using TGlobalPhysicsCallback = std::pair<void (__cdecl*)(EventPhys const *,void *),void *>;
	using TGlobalPhysicsCallbackSet = std::set<std::pair<void (__cdecl*)(EventPhys const *,void *),void *>,std::less<std::pair<void (__cdecl*)(EventPhys const *,void *),void *>>>;
	
	struct SPhysCallbacks // Id=8004A6A Size=160
	{
		std::set<std::pair<void (__cdecl*)(EventPhys const *,void *),void *>,std::less<std::pair<void (__cdecl*)(EventPhys const *,void *),void *>>> collision[2];
		std::set<std::pair<void (__cdecl*)(EventPhys const *,void *),void *>,std::less<std::pair<void (__cdecl*)(EventPhys const *,void *),void *>>> postStep[2];
		std::set<std::pair<void (__cdecl*)(EventPhys const *,void *),void *>,std::less<std::pair<void (__cdecl*)(EventPhys const *,void *),void *>>> stateChange[2];
		std::set<std::pair<void (__cdecl*)(EventPhys const *,void *),void *>,std::less<std::pair<void (__cdecl*)(EventPhys const *,void *),void *>>> createEntityPart[2];
		std::set<std::pair<void (__cdecl*)(EventPhys const *,void *),void *>,std::less<std::pair<void (__cdecl*)(EventPhys const *,void *),void *>>> updateMesh[2];
	};

	CActionGame::SPhysCallbacks m_globalPhysicsCallbacks;
	std::vector<SProcBrokenObjRec> m_brokenObjs;
	std::vector<SBreakEvent> m_breakEvents;
	std::vector<SBrokenEntPart> m_brokenEntParts;
	std::vector<SBrokenVegPart> m_brokenVegParts;
	std::vector<unsigned int> m_broken2dChunkIds;
	std::map<unsigned int,int,std::less<unsigned int>> m_entPieceIdx;
	std::map<IPhysicalEntity *,STreeBreakInst *,std::less<IPhysicalEntity *>> m_mapBrokenTreesByPhysEnt;
	std::map<IStatObj *,STreeBreakInst *,std::less<IStatObj *>> m_mapBrokenTreesByCGF;
	std::map<IPhysicalEntity *,STreePieceThunk *,std::less<IPhysicalEntity *>> m_mapBrokenTreesChunks;
	std::map<int,SBrokenMeshSize,std::less<int>> m_mapBrokenMeshes;
	std::vector<int> m_brokenMeshRemovals;
	bool m_bLoading;
	int m_iCurBreakEvent;
	int m_totBreakageSize;
	int m_inDeleteEntityCallback;
	CGameStats *m_pGameStats;
	SEntityCollHist *m_pCHSlotPool;
	SEntityCollHist *m_pFreeCHSlot0;
	std::map<int,SEntityCollHist *,std::less<int>> m_mapECH;
	SEntityHits *m_pEntHits0;
	std::map<int,SEntityHits *,std::less<int>> m_mapEntHits;
	
	struct SVegCollisionStatus // Id=8004C61 Size=24
	{
		IRenderNode *rn;
		IStatObj *pStat;
		int branchNum;
		
#if 0
		void GetMemoryUsage(ICrySizer *arg0) const;
#endif
	};

	std::map<unsigned int,Vec3,std::less<unsigned int>> m_vegStatus;
	std::map<unsigned int,CActionGame::SVegCollisionStatus *,std::less<unsigned int>> m_treeStatus;
	std::map<unsigned int,CActionGame::SVegCollisionStatus *,std::less<unsigned int>> m_treeBreakStatus;
	int m_nEffectCounter;
	SMFXRunTimeEffectParams m_lstCachedEffects[8];
	static inline auto g_procedural_breaking = PreyGlobal<int>(0x249EFF8);
	static inline auto g_joint_breaking = PreyGlobal<int>(0x224A3E8);
	static inline auto g_tree_cut_reuse_dist = PreyGlobal<float>(0x249EFFC);
	static inline auto g_no_secondary_breaking = PreyGlobal<int>(0x249F000);
	static inline auto g_no_breaking_by_objects = PreyGlobal<int>(0x249F004);
	static inline auto g_breakage_mem_limit = PreyGlobal<int>(0x249F008);
	static inline auto g_breakage_debug = PreyGlobal<int>(0x249F00C);
	static inline auto s_waterMaterialId = PreyGlobal<int>(0x224A3EC);
	
	enum eDisconnectState
	{
		eDS_Disconnect = 0,
		eDS_Disconnecting = 1,
		eDS_Disconnected = 2,
	};

	enum eReconnectState
	{
		eRS_Reconnect = 0,
		eRS_Reconnecting = 1,
		eRS_Terminated = 2,
		eRS_Reconnected = 3,
	};

	enum eInitState
	{
		eIS_Uninited = 0,
		eIS_Initing = 1,
		eIS_WaitForConnection = 2,
		eIS_WaitForPlayer = 3,
		eIS_WaitForInGame = 4,
		eIS_InitDone = 5,
		eIS_InitError = 6,
	};

	CActionGame::eInitState m_initState;
	
	struct SEntityFadeState // Id=8004C81 Size=12
	{
		unsigned entId;
		float time;
		int bCollisions;
	};

	DynArray<CActionGame::SEntityFadeState,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > m_fadeEntities;
	SGameContextParams m_gameContextParams;
	SGameStartParams m_startGameParams;
	string m_levelName;
	string m_gameRules;
	string m_demoRecorderFilename;
	string m_demoPlaybackFilename;
	string m_hostname;
	string m_connectionString;
	unsigned m_lastDynPoolSize;
	uint8_t *m_clientReserveForMigrate;
	
	struct SBreakageThrottling // Id=8004C8F Size=2
	{
		int16_t m_brokenTreeCounter;
	};

	CActionGame::SBreakageThrottling m_throttling;
	unsigned m_clientActorID;
	IActor *m_pClientActor;
	ArkActionGame m_arkActionGame;
	
	CActionGame(CScriptRMI *pScriptRMI);
	virtual ~CActionGame();
	bool Init(SGameStartParams const *pGameStartParams) { return FInit(this,pGameStartParams); }
	void ClientInit(SGameStartParams const *pGameStartParams, bool *io_ok, bool *io_hasPbSvStarted, bool *io_requireBlockingConnection) { FClientInit(this,pGameStartParams,io_ok,io_hasPbSvStarted,io_requireBlockingConnection); }
	bool ChangeGameContext(SGameContextParams const *pGameContextParams) { return FChangeGameContext(this,pGameContextParams); }
	bool BlockingSpawnPlayer() { return FBlockingSpawnPlayer(this); }
	void FixBrokenObjects(bool bRestoreBroken) { FFixBrokenObjects(this,bRestoreBroken); }
	IActor *GetClientActor() { return FGetClientActor(this); }
	bool Update() { return FUpdate(this); }
	void AddGlobalPhysicsCallback(int event, void (*proc)(EventPhys const *, void *), void *userdata) { FAddGlobalPhysicsCallback(this,event,proc,userdata); }
	void RemoveGlobalPhysicsCallback(int event, void (*proc)(EventPhys const *, void *), void *userdata) { FRemoveGlobalPhysicsCallback(this,event,proc,userdata); }
	void SerializeBreakableObjects(TSerialize ser) { FSerializeBreakableObjects(this,ser); }
	void FlushBreakableObjects() { FFlushBreakableObjects(this); }
	void ClearBreakHistory() { FClearBreakHistory(this); }
	void OnBreakageSpawnedEntity(IEntity *pEntity, IPhysicalEntity *pPhysEntity, IPhysicalEntity *pSrcPhysEntity) { FOnBreakageSpawnedEntity(this,pEntity,pPhysEntity,pSrcPhysEntity); }
	void InitImmersiveness() { FInitImmersiveness(this); }
	void UpdateImmersiveness() { FUpdateImmersiveness(this); }
	void OnEditorSetGameMode(bool bGameMode) { FOnEditorSetGameMode(this,bGameMode); }
	void DumpStats() { FDumpStats(this); }
	void GetMemoryUsage(ICrySizer *s) const { FGetMemoryUsage(this,s); }
	void ReleaseGameStats() { FReleaseGameStats(this); }
	void FreeBrokenMeshesForEntity(IPhysicalEntity *pent) { FFreeBrokenMeshesForEntity(this,pent); }
	void OnEntitySystemReset() { FOnEntitySystemReset(this); }
	static void RegisterCVars() { FRegisterCVars(); }
	static bool ImpactBreaksGlass(EventPhysCollision const &_epc, ISurfaceType const *_pSurfType) { return FImpactBreaksGlass(_epc,_pSurfType); }
	void EnablePhysicsEvents(bool enable) { FEnablePhysicsEvents(this,enable); }
	static int OnBBoxOverlap(EventPhys const *pEvent) { return FOnBBoxOverlap(pEvent); }
	static int OnCollisionLogged(EventPhys const *pEvent) { return FOnCollisionLogged(pEvent); }
	static int OnPostStepLogged(EventPhys const *pEvent) { return FOnPostStepLogged(pEvent); }
	static int OnStateChangeLogged(EventPhys const *pEvent) { return FOnStateChangeLogged(pEvent); }
	static int OnCreatePhysicalEntityLogged(EventPhys const *pEvent) { return FOnCreatePhysicalEntityLogged(pEvent); }
	static int OnUpdateMeshLogged(EventPhys const *pEvent) { return FOnUpdateMeshLogged(pEvent); }
	static int OnRemovePhysicalEntityPartsLogged(EventPhys const *pEvent) { return FOnRemovePhysicalEntityPartsLogged(pEvent); }
	static int OnPhysEntityDeleted(EventPhys const *pEvent) { return FOnPhysEntityDeleted(pEvent); }
	static int OnCollisionImmediate(EventPhys const *pEvent) { return FOnCollisionImmediate(pEvent); }
	static int OnPostStepImmediate(EventPhys const *pEvent) { return FOnPostStepImmediate(pEvent); }
	static int OnStateChangeImmediate(EventPhys const *pEvent) { return FOnStateChangeImmediate(pEvent); }
	static int OnCreatePhysicalEntityImmediate(EventPhys const *pEvent) { return FOnCreatePhysicalEntityImmediate(pEvent); }
	static int OnUpdateMeshImmediate(EventPhys const *pEvent) { return FOnUpdateMeshImmediate(pEvent); }
	virtual void OnHit(HitInfo const &__formal);
	virtual void OnExplosion(ExplosionInfo const &ei);
	virtual void OnServerExplosion(ExplosionInfo const &__formal);
	static void OnCollisionLogged_MaterialFX(EventPhys const *pEvent) { FOnCollisionLogged_MaterialFX(pEvent); }
	static void OnCollisionLogged_Breakable(EventPhys const *pEvent) { FOnCollisionLogged_Breakable(pEvent); }
	static void OnPostStepLogged_MaterialFX(EventPhys const *pEvent) { FOnPostStepLogged_MaterialFX(pEvent); }
	virtual IHostMigrationEventListener::EHostMigrationReturn OnInitiate(SHostMigrationInfo &hostMigrationInfo, unsigned &state);
	virtual IHostMigrationEventListener::EHostMigrationReturn OnDisconnectClient(SHostMigrationInfo &hostMigrationInfo, unsigned &state);
	virtual IHostMigrationEventListener::EHostMigrationReturn OnDemoteToClient(SHostMigrationInfo &hostMigrationInfo, unsigned &state);
	virtual IHostMigrationEventListener::EHostMigrationReturn OnPromoteToServer(SHostMigrationInfo &hostMigrationInfo, unsigned &state);
	virtual IHostMigrationEventListener::EHostMigrationReturn OnReconnectClient(SHostMigrationInfo &hostMigrationInfo, unsigned &state);
	virtual IHostMigrationEventListener::EHostMigrationReturn OnFinalise(SHostMigrationInfo &hostMigrationInfo, unsigned &state);
	virtual void OnComplete(SHostMigrationInfo &hostMigrationInfo);
	virtual IHostMigrationEventListener::EHostMigrationReturn OnTerminate(SHostMigrationInfo &hostMigrationInfo, unsigned &state);
	virtual IHostMigrationEventListener::EHostMigrationReturn OnReset(SHostMigrationInfo &hostMigrationInfo, unsigned &state);
	SBreakEvent &RegisterBreakEvent(EventPhysCollision const *pColl, float energy) { return FRegisterBreakEvent(this,pColl,energy); }
	unsigned UpdateEntityIdForBrokenPart(unsigned idSrc) { return FUpdateEntityIdForBrokenPart(this,idSrc); }
	unsigned UpdateEntityIdForVegetationBreak(IRenderNode *pVeg) { return FUpdateEntityIdForVegetationBreak(this,pVeg); }
	void RegisterEntsForBreakageReuse(IPhysicalEntity *pPhysEnt, int partid, IPhysicalEntity *pPhysEntNew, float h, float size) { FRegisterEntsForBreakageReuse(this,pPhysEnt,partid,pPhysEntNew,h,size); }
	void RemoveEntFromBreakageReuse(IPhysicalEntity *pEntity, int bRemoveOnlyIfSecondary) { FRemoveEntFromBreakageReuse(this,pEntity,bRemoveOnlyIfSecondary); }
	void ClearTreeBreakageReuseLog() { FClearTreeBreakageReuseLog(this); }
	int FreeBrokenMesh(IPhysicalEntity *pent, SBrokenMeshSize &bm) { return FFreeBrokenMesh(this,pent,bm); }
	void RegisterBrokenMesh(IPhysicalEntity *pPhysEnt, IGeometry *pPhysGeom, int partid, IStatObj *pStatObj, IGeometry *pSkel, float timeout, const char *fractureFX) { FRegisterBrokenMesh(this,pPhysEnt,pPhysGeom,partid,pStatObj,pSkel,timeout,fractureFX); }
	void DrawBrokenMeshes() { FDrawBrokenMeshes(this); }
	bool ConditionHavePlayer(CGameClientChannel *pChannel) { return FConditionHavePlayer(this,pChannel); }
	bool ConditionHaveConnection(CGameClientChannel *pChannel) { return FConditionHaveConnection(this,pChannel); }
	bool ConditionInGame(CGameClientChannel *pChannel) { return FConditionInGame(this,pChannel); }
	bool BlockingConnect(bool (*condition)(CGameClientChannel *), bool requireClientChannel, const char *conditionText) { return FBlockingConnect(this,condition,requireClientChannel,conditionText); }
	void BackupGameStartParams(SGameStartParams const *pGameStartParams) { FBackupGameStartParams(this,pGameStartParams); }
	
#if 0
	void ServerInit(SGameStartParams const *arg0, bool *arg1, bool *arg2);
	void PostInit(SGameStartParams const *arg0, bool *arg1, bool *arg2);
	bool IsInited();
	bool IsIniting();
	string const &GetLevelName() const;
	void UnloadLevel();
	void UnloadPhysicsData();
	SBreakEvent &StoreBreakEvent(SBreakEvent const &arg0);
	void CryLobbyServerInit(SGameStartParams const *arg0);
	bool IsServer() const;
	bool IsClient() const;
	CGameServerNub *GetGameServerNub();
	CGameClientNub *GetGameClientNub();
	CGameContext *GetGameContext();
	bool ControlsEntity(unsigned arg0);
	void Serialize(TSerialize arg0);
	INetNub *GetServerNetNub();
	INetNub *GetClientNetNub();
	static CActionGame *Get();
	ArkActionGame const &GetArkActionGame() const;
	static IGameObject *GetEntityGameObject(IEntity *arg0);
	static IGameObject *GetPhysicalEntityGameObject(IPhysicalEntity *arg0);
	static void ArkPerformPlaneBreak(EventPhysCollision const &arg0);
	static IEntity *GetEntity(int arg0, void *arg1);
	void CreateGameStats();
	void LogModeInformation(const bool arg0, const char *arg1) const;
	static void OnStateChangeLogged_MaterialFX(EventPhys const *arg0);
	bool ProcessHitpoints(Vec3 const &arg0, IPhysicalEntity *arg1, int arg2, ISurfaceType *arg3, int arg4);
	int ReuseBrokenTrees(EventPhysCollision const *arg0, float arg1, int arg2);
	static void AddBroken2DChunkId(int arg0);
	void UpdateBrokenMeshes(float arg0);
	void UpdateFadeEntities(float arg0);
	CActionGame::eInitTaskState NonBlockingConnect(bool (*arg0)(CGameClientChannel *), bool arg1, const char *arg2);
	void CallOnEditorSetGameMode(IEntity *arg0, bool arg1);
	bool IsStale();
	void AddProtectedPath(const char *arg0);
	bool AllowProceduralBreaking(uint8_t arg0);
#endif
	
	static inline auto FBitNotCActionGame = PreyFunction<void(CActionGame *const _this)>(0x5A7D20);
	static inline auto FInit = PreyFunction<bool(CActionGame *const _this, SGameStartParams const *pGameStartParams)>(0x5AB470);
	static inline auto FClientInit = PreyFunction<void(CActionGame *const _this, SGameStartParams const *pGameStartParams, bool *io_ok, bool *io_hasPbSvStarted, bool *io_requireBlockingConnection)>(0x5A9100);
	static inline auto FChangeGameContext = PreyFunction<bool(CActionGame *const _this, SGameContextParams const *pGameContextParams)>(0x5A8D70);
	static inline auto FBlockingSpawnPlayer = PreyFunction<bool(CActionGame *const _this)>(0x5A8CB0);
	static inline auto FFixBrokenObjects = PreyFunction<void(CActionGame *const _this, bool bRestoreBroken)>(0x5A9CF0);
	static inline auto FGetClientActor = PreyFunction<IActor *(CActionGame *const _this)>(0x5AADD0);
	static inline auto FUpdate = PreyFunction<bool(CActionGame *const _this)>(0x5B34F0);
	static inline auto FAddGlobalPhysicsCallback = PreyFunction<void(CActionGame *const _this, int event, void (*proc)(EventPhys const *, void *), void *userdata)>(0x5A8720);
	static inline auto FRemoveGlobalPhysicsCallback = PreyFunction<void(CActionGame *const _this, int event, void (*proc)(EventPhys const *, void *), void *userdata)>(0x5B28E0);
	static inline auto FSerializeBreakableObjects = PreyFunction<void(CActionGame *const _this, TSerialize ser)>(0x5B2D00);
	static inline auto FFlushBreakableObjects = PreyFunction<void(CActionGame *const _this)>(0x5A9F90);
	static inline auto FClearBreakHistory = PreyFunction<void(CActionGame *const _this)>(0x5A8DA0);
	static inline auto FOnBreakageSpawnedEntity = PreyFunction<void(CActionGame *const _this, IEntity *pEntity, IPhysicalEntity *pPhysEntity, IPhysicalEntity *pSrcPhysEntity)>(0x5ACBE0);
	static inline auto FInitImmersiveness = PreyFunction<void(CActionGame *const _this)>(0x5AC470);
	static inline auto FUpdateImmersiveness = PreyFunction<void(CActionGame *const _this)>(0x5B3F70);
	static inline auto FOnEditorSetGameMode = PreyFunction<void(CActionGame *const _this, bool bGameMode)>(0x5AF010);
	static inline auto FDumpStats = PreyFunction<void(CActionGame *const _this)>(0x5A9960);
	static inline auto FGetMemoryUsage = PreyFunction<void(CActionGame const *const _this, ICrySizer *s)>(0x5AAE90);
	static inline auto FReleaseGameStats = PreyFunction<void(CActionGame *const _this)>(0x5B26D0);
	static inline auto FFreeBrokenMeshesForEntity = PreyFunction<void(CActionGame *const _this, IPhysicalEntity *pent)>(0x5AAC80);
	static inline auto FOnEntitySystemReset = PreyFunction<void(CActionGame *const _this)>(0x5AF380);
	static inline auto FRegisterCVars = PreyFunction<void()>(0x5B1D30);
	static inline auto FImpactBreaksGlass = PreyFunction<bool(EventPhysCollision const &_epc, ISurfaceType const *_pSurfType)>(0x5AB370);
	static inline auto FEnablePhysicsEvents = PreyFunction<void(CActionGame *const _this, bool enable)>(0x5A9980);
	static inline auto FOnBBoxOverlap = PreyFunction<int(EventPhys const *pEvent)>(0x5AC7C0);
	static inline auto FOnCollisionLogged = PreyFunction<int(EventPhys const *pEvent)>(0x5ACF70);
	static inline auto FOnPostStepLogged = PreyFunction<int(EventPhys const *pEvent)>(0x5AFD20);
	static inline auto FOnStateChangeLogged = PreyFunction<int(EventPhys const *pEvent)>(0x5B0AC0);
	static inline auto FOnCreatePhysicalEntityLogged = PreyFunction<int(EventPhys const *pEvent)>(0x5AECB0);
	static inline auto FOnUpdateMeshLogged = PreyFunction<int(EventPhys const *pEvent)>(0x5B0DD0);
	static inline auto FOnRemovePhysicalEntityPartsLogged = PreyFunction<int(EventPhys const *pEvent)>(0x5B07E0);
	static inline auto FOnPhysEntityDeleted = PreyFunction<int(EventPhys const *pEvent)>(0x5AFBA0);
	static inline auto FOnCollisionImmediate = PreyFunction<int(EventPhys const *pEvent)>(0x5ACC50);
	static inline auto FOnPostStepImmediate = PreyFunction<int(EventPhys const *pEvent)>(0x5AFBE0);
	static inline auto FOnStateChangeImmediate = PreyFunction<int(EventPhys const *pEvent)>(0x5B09A0);
	static inline auto FOnCreatePhysicalEntityImmediate = PreyFunction<int(EventPhys const *pEvent)>(0x5AEB20);
	static inline auto FOnUpdateMeshImmediate = PreyFunction<int(EventPhys const *pEvent)>(0x5B0CD0);
	static inline auto FOnHit = PreyFunction<void(CActionGame *const _this, HitInfo const &__formal)>(0xA13080);
	static inline auto FOnExplosion = PreyFunction<void(CActionGame *const _this, ExplosionInfo const &ei)>(0x5AF390);
	static inline auto FOnServerExplosion = PreyFunction<void(CActionGame *const _this, ExplosionInfo const &__formal)>(0xA13080);
	static inline auto FOnCollisionLogged_MaterialFX = PreyFunction<void(EventPhys const *pEvent)>(0x5AD420);
	static inline auto FOnCollisionLogged_Breakable = PreyFunction<void(EventPhys const *pEvent)>(0x5AD1A0);
	static inline auto FOnPostStepLogged_MaterialFX = PreyFunction<void(EventPhys const *pEvent)>(0x5AFE40);
	static inline auto FOnInitiate = PreyFunction<IHostMigrationEventListener::EHostMigrationReturn(CActionGame *const _this, SHostMigrationInfo &hostMigrationInfo, unsigned &state)>(0x5AF920);
	static inline auto FOnDisconnectClient = PreyFunction<IHostMigrationEventListener::EHostMigrationReturn(CActionGame *const _this, SHostMigrationInfo &hostMigrationInfo, unsigned &state)>(0x5AEF00);
	static inline auto FOnDemoteToClient = PreyFunction<IHostMigrationEventListener::EHostMigrationReturn(CActionGame *const _this, SHostMigrationInfo &hostMigrationInfo, unsigned &state)>(0x5AEEA0);
	static inline auto FOnPromoteToServer = PreyFunction<IHostMigrationEventListener::EHostMigrationReturn(CActionGame *const _this, SHostMigrationInfo &hostMigrationInfo, unsigned &state)>(0x5B00D0);
	static inline auto FOnReconnectClient = PreyFunction<IHostMigrationEventListener::EHostMigrationReturn(CActionGame *const _this, SHostMigrationInfo &hostMigrationInfo, unsigned &state)>(0x5B0590);
	static inline auto FOnFinalise = PreyFunction<IHostMigrationEventListener::EHostMigrationReturn(CActionGame *const _this, SHostMigrationInfo &hostMigrationInfo, unsigned &state)>(0x5AF8C0);
	static inline auto FOnComplete = PreyFunction<void(CActionGame *const _this, SHostMigrationInfo &hostMigrationInfo)>(0xA13080);
	static inline auto FOnTerminate = PreyFunction<IHostMigrationEventListener::EHostMigrationReturn(CActionGame *const _this, SHostMigrationInfo &hostMigrationInfo, unsigned &state)>(0x158AEF0);
	static inline auto FOnReset = PreyFunction<IHostMigrationEventListener::EHostMigrationReturn(CActionGame *const _this, SHostMigrationInfo &hostMigrationInfo, unsigned &state)>(0x158AEF0);
	static inline auto FRegisterBreakEvent = PreyFunction<SBreakEvent &(CActionGame *const _this, EventPhysCollision const *pColl, float energy)>(0x5B1170);
	static inline auto FUpdateEntityIdForBrokenPart = PreyFunction<unsigned(CActionGame *const _this, unsigned idSrc)>(0x5B3C60);
	static inline auto FUpdateEntityIdForVegetationBreak = PreyFunction<unsigned(CActionGame *const _this, IRenderNode *pVeg)>(0x5B3DB0);
	static inline auto FRegisterEntsForBreakageReuse = PreyFunction<void(CActionGame *const _this, IPhysicalEntity *pPhysEnt, int partid, IPhysicalEntity *pPhysEntNew, float h, float size)>(0x5B2320);
	static inline auto FRemoveEntFromBreakageReuse = PreyFunction<void(CActionGame *const _this, IPhysicalEntity *pEntity, int bRemoveOnlyIfSecondary)>(0x5B2700);
	static inline auto FClearTreeBreakageReuseLog = PreyFunction<void(CActionGame *const _this)>(0x5A8FA0);
	static inline auto FFreeBrokenMesh = PreyFunction<int(CActionGame *const _this, IPhysicalEntity *pent, SBrokenMeshSize &bm)>(0x5AA1A0);
	static inline auto FRegisterBrokenMesh = PreyFunction<void(CActionGame *const _this, IPhysicalEntity *pPhysEnt, IGeometry *pPhysGeom, int partid, IStatObj *pStatObj, IGeometry *pSkel, float timeout, const char *fractureFX)>(0x5B13F0);
	static inline auto FDrawBrokenMeshes = PreyFunction<void(CActionGame *const _this)>(0x5A93B0);
	static inline auto FConditionHavePlayer = PreyFunction<bool(CActionGame *const _this, CGameClientChannel *pChannel)>(0x5A9360);
	static inline auto FConditionHaveConnection = PreyFunction<bool(CActionGame *const _this, CGameClientChannel *pChannel)>(0x5A9350);
	static inline auto FConditionInGame = PreyFunction<bool(CActionGame *const _this, CGameClientChannel *pChannel)>(0x5A9370);
	static inline auto FBlockingConnect = PreyFunction<bool(CActionGame *const _this, bool (*condition)(CGameClientChannel *), bool requireClientChannel, const char *conditionText)>(0x5A8A80);
	static inline auto FBackupGameStartParams = PreyFunction<void(CActionGame *const _this, SGameStartParams const *pGameStartParams)>(0x5A88A0);
};

// Header: Exact
// CryEngine/cryaction/actiongame.h
struct SBreakEvent // Id=8004A07 Size=164
{
	int16_t itype;
	int16_t bFirstBreak;
	unsigned idEnt;
	Vec3 eventPos;
	unsigned hash;
	Vec3 pos;
	Quat rot;
	Vec3 scale;
	Vec3 pt;
	Vec3 n;
	Vec3 vloc[2];
	float mass[2];
	int partid[2];
	int idmat[2];
	float penetration;
	float energy;
	float radius;
	float time;
	int16_t iPrim[2];
	int16_t iBrokenObjectIndex;
	int16_t iState;
	int seed;
	
	void Serialize(TSerialize ser) { FSerialize(this,ser); }
	
#if 0
	void GetMemoryUsage(ICrySizer *arg0) const;
#endif
	
	static inline auto FSerialize = PreyFunction<void(SBreakEvent *const _this, TSerialize ser)>(0x5B2A70);
};

// Header: FromCpp
// CryEngine/cryaction/actiongame.h
class CAdjustLocalConnectionPacketRate // Id=80072E4 Size=12
{
public:
	float m_old;
	float m_oldInactivityTimeout;
	float m_oldInactivityTimeoutDev;

	CAdjustLocalConnectionPacketRate(float rate, float inactivityTimeout);
	~CAdjustLocalConnectionPacketRate();

	static inline auto FBitNotCAdjustLocalConnectionPacketRate = PreyFunction<void(CAdjustLocalConnectionPacketRate *const _this)>(0x5A8360);
};

// Header: FromCpp
// CryEngine/cryaction/actiongame.h
struct CrySizerNaive : public ICrySizer // Id=80072EE Size=32
{
	uint64_t m_count;
	uint64_t m_size;
	
	virtual void Release();
	virtual uint64_t GetTotalSize();
	virtual uint64_t GetObjectCount();
	virtual IResourceCollector *GetResourceCollector();
	virtual void Push(const char *__formal);
	virtual void PushSubcomponent(const char *__formal);
	virtual void Pop();
	virtual bool AddObject(const void *id, uint64_t size, int count);
	virtual void Reset();
	virtual void End();
	virtual void SetResourceCollector(IResourceCollector *pColl);
	virtual ~CrySizerNaive();
	
	static inline auto FRelease = PreyFunction<void(CrySizerNaive *const _this)>(0xA13080);
	static inline auto FGetTotalSize = PreyFunction<uint64_t(CrySizerNaive *const _this)>(0xD87500);
	static inline auto FGetObjectCount = PreyFunction<uint64_t(CrySizerNaive *const _this)>(0x5BFB50);
	static inline auto FGetResourceCollector = PreyFunction<IResourceCollector *(CrySizerNaive *const _this)>(0x158AEF0);
	static inline auto FPush = PreyFunction<void(CrySizerNaive *const _this, const char *__formal)>(0xA13080);
	static inline auto FPushSubcomponent = PreyFunction<void(CrySizerNaive *const _this, const char *__formal)>(0xA13080);
	static inline auto FPop = PreyFunction<void(CrySizerNaive *const _this)>(0xA13080);
	static inline auto FAddObject = PreyFunction<bool(CrySizerNaive *const _this, const void *id, uint64_t size, int count)>(0x5A8880);
	static inline auto FReset = PreyFunction<void(CrySizerNaive *const _this)>(0x1800CA0);
	static inline auto FEnd = PreyFunction<void(CrySizerNaive *const _this)>(0xA13080);
	static inline auto FSetResourceCollector = PreyFunction<void(CrySizerNaive *const _this, IResourceCollector *pColl)>(0xA13080);
};

