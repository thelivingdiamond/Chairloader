// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryScriptSystem/ScriptHelpers.h>

class ICrySizer;
struct IFunctionHandler;
struct IGameFramework;
struct ISystem;
union ScriptHandle;

// CScriptBind_Game
// Header:  Prey/GameDll/ScriptBind_Game.h
class CScriptBind_Game : public CScriptableBase
{ // Size=112 (0x70)
public:
	enum EGameCacheResourceType
	{
		eGCRT_Texture = 0,
		eGCRT_TextureDeferredCubemap = 1,
		eGCRT_StaticObject = 2,
		eGCRT_Material = 3,
	};

	ISystem* m_pSystem;
	IGameFramework* m_pGameFW;

	CScriptBind_Game(ISystem* pSystem, IGameFramework* pGameFramework);
	virtual ~CScriptBind_Game();
	virtual void GetMemoryUsage(ICrySizer* pSizer) const;
	int ShowMainMenu(IFunctionHandler* pH) { return FShowMainMenu(this, pH); }
	int PauseGame(IFunctionHandler* pH, bool pause) { return FPauseGame(this, pH, pause); }
	int IsMountedWeaponUsableWithTarget(IFunctionHandler* pH) { return FIsMountedWeaponUsableWithTarget(this, pH); }
	int IsPlayer(IFunctionHandler* pH, ScriptHandle entityId) { return FIsPlayer(this, pH, entityId); }
	int AddTacticalEntity(IFunctionHandler* pH, ScriptHandle id, int type) { return FAddTacticalEntity(this, pH, id, type); }
	int RemoveTacticalEntity(IFunctionHandler* pH, ScriptHandle id, int type) { return FRemoveTacticalEntity(this, pH, id, type); }
	int OnAmmoCrateSpawned(IFunctionHandler* pH, bool providesFragGrenades) { return FOnAmmoCrateSpawned(this, pH, providesFragGrenades); }
	int CacheResource(IFunctionHandler* pH, const char* whoIsRequesting, const char* resourceName, int resourceType, int resourceFlags) { return FCacheResource(this, pH, whoIsRequesting, resourceName, resourceType, resourceFlags); }
	int CacheActorClassResources(IFunctionHandler* pH, const char* actorEntityClassName) { return FCacheActorClassResources(this, pH, actorEntityClassName); }
	int CacheEntityArchetype(IFunctionHandler* pH, const char* archetypeName) { return FCacheEntityArchetype(this, pH, archetypeName); }
	int CacheArkItem(IFunctionHandler* pH, const char* _szArkItemArchetype) { return FCacheArkItem(this, pH, _szArkItemArchetype); }
	int CacheArkLootTable(IFunctionHandler* pH, const char* _szLootTableId) { return FCacheArkLootTable(this, pH, _szLootTableId); }
	int SaveCheckpoint(IFunctionHandler* pH, ScriptHandle checkpointId, const char* fileName) { return FSaveCheckpoint(this, pH, checkpointId, fileName); }
	int LoadCheckpoint(IFunctionHandler* pH, const char* fileName) { return FLoadCheckpoint(this, pH, fileName); }
	int QueueDeferredKill(IFunctionHandler* pH, ScriptHandle entityId) { return FQueueDeferredKill(this, pH, entityId); }
	int OnEnvironmentalWeaponHealthChanged(IFunctionHandler* pH, ScriptHandle entityId) { return FOnEnvironmentalWeaponHealthChanged(this, pH, entityId); }
	int ReturnToProjectilePool(IFunctionHandler* pH, ScriptHandle entityId) { return FReturnToProjectilePool(this, pH, entityId); }
	int ImpulseEnvironment(IFunctionHandler* pH, ScriptHandle entityId, Vec3 _impulse) { return FImpulseEnvironment(this, pH, entityId, _impulse); }
	int ResetEntity(IFunctionHandler* pH, ScriptHandle entityId) { return FResetEntity(this, pH, entityId); }
	int SendEventToGameObject(IFunctionHandler* pH, ScriptHandle entityId, char* event) { return FSendEventToGameObject(this, pH, entityId, event); }
	int LoadPrefabLibrary(IFunctionHandler* pH, const char* filename) { return FLoadPrefabLibrary(this, pH, filename); }
	int SpawnPrefab(IFunctionHandler* pH, ScriptHandle entityId, const char* libname, const char* prefabname, unsigned seed, unsigned nMaxSpawn) { return FSpawnPrefab(this, pH, entityId, libname, prefabname, seed, nMaxSpawn); }
	int MovePrefab(IFunctionHandler* pH, ScriptHandle entityId) { return FMovePrefab(this, pH, entityId); }
	int DeletePrefab(IFunctionHandler* pH, ScriptHandle entityId) { return FDeletePrefab(this, pH, entityId); }
	int HidePrefab(IFunctionHandler* pH, ScriptHandle entityId, bool bHide) { return FHidePrefab(this, pH, entityId, bHide); }
	int CacheEquipmentPack(IFunctionHandler* pH, const char* equipmentPackName) { return FCacheEquipmentPack(this, pH, equipmentPackName); }
	void RegisterGlobals() { FRegisterGlobals(this); }
	void RegisterMethods() { FRegisterMethods(this); }

	static inline auto FCScriptBind_GameOv1 = PreyFunction<void(CScriptBind_Game* const _this, ISystem* pSystem, IGameFramework* pGameFramework)>(0x1909F70);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CScriptBind_Game* const _this, ICrySizer* pSizer)>(0x578280);
	static inline auto FShowMainMenu = PreyFunction<int(CScriptBind_Game* const _this, IFunctionHandler* pH)>(0x77DB10);
	static inline auto FPauseGame = PreyFunction<int(CScriptBind_Game* const _this, IFunctionHandler* pH, bool pause)>(0x190BEC0);
	static inline auto FIsMountedWeaponUsableWithTarget = PreyFunction<int(CScriptBind_Game* const _this, IFunctionHandler* pH)>(0x190B380);
	static inline auto FIsPlayer = PreyFunction<int(CScriptBind_Game* const _this, IFunctionHandler* pH, ScriptHandle entityId)>(0x190BBB0);
	static inline auto FAddTacticalEntity = PreyFunction<int(CScriptBind_Game* const _this, IFunctionHandler* pH, ScriptHandle id, int type)>(0x77DB10);
	static inline auto FRemoveTacticalEntity = PreyFunction<int(CScriptBind_Game* const _this, IFunctionHandler* pH, ScriptHandle id, int type)>(0x77DB10);
	static inline auto FOnAmmoCrateSpawned = PreyFunction<int(CScriptBind_Game* const _this, IFunctionHandler* pH, bool providesFragGrenades)>(0x190BE70);
	static inline auto FCacheResource = PreyFunction<int(CScriptBind_Game* const _this, IFunctionHandler* pH, const char* whoIsRequesting, const char* resourceName, int resourceType, int resourceFlags)>(0x190A2B0);
	static inline auto FCacheActorClassResources = PreyFunction<int(CScriptBind_Game* const _this, IFunctionHandler* pH, const char* actorEntityClassName)>(0x190A0B0);
	static inline auto FCacheEntityArchetype = PreyFunction<int(CScriptBind_Game* const _this, IFunctionHandler* pH, const char* archetypeName)>(0x190A240);
	static inline auto FCacheArkItem = PreyFunction<int(CScriptBind_Game* const _this, IFunctionHandler* pH, const char* _szArkItemArchetype)>(0x190A170);
	static inline auto FCacheArkLootTable = PreyFunction<int(CScriptBind_Game* const _this, IFunctionHandler* pH, const char* _szLootTableId)>(0x190A1B0);
	static inline auto FSaveCheckpoint = PreyFunction<int(CScriptBind_Game* const _this, IFunctionHandler* pH, ScriptHandle checkpointId, const char* fileName)>(0x190D390);
	static inline auto FLoadCheckpoint = PreyFunction<int(CScriptBind_Game* const _this, IFunctionHandler* pH, const char* fileName)>(0x190BC90);
	static inline auto FQueueDeferredKill = PreyFunction<int(CScriptBind_Game* const _this, IFunctionHandler* pH, ScriptHandle entityId)>(0x190BF90);
	static inline auto FOnEnvironmentalWeaponHealthChanged = PreyFunction<int(CScriptBind_Game* const _this, IFunctionHandler* pH, ScriptHandle entityId)>(0x77DB10);
	static inline auto FReturnToProjectilePool = PreyFunction<int(CScriptBind_Game* const _this, IFunctionHandler* pH, ScriptHandle entityId)>(0x190D350);
	static inline auto FImpulseEnvironment = PreyFunction<int(CScriptBind_Game* const _this, IFunctionHandler* pH, ScriptHandle entityId, Vec3 _impulse)>(0x190AFF0);
	static inline auto FResetEntity = PreyFunction<int(CScriptBind_Game* const _this, IFunctionHandler* pH, ScriptHandle entityId)>(0x190D2E0);
	static inline auto FSendEventToGameObject = PreyFunction<int(CScriptBind_Game* const _this, IFunctionHandler* pH, ScriptHandle entityId, char* event)>(0x190D440);
	static inline auto FLoadPrefabLibrary = PreyFunction<int(CScriptBind_Game* const _this, IFunctionHandler* pH, const char* filename)>(0x190BD30);
	static inline auto FSpawnPrefab = PreyFunction<int(CScriptBind_Game* const _this, IFunctionHandler* pH, ScriptHandle entityId, const char* libname, const char* prefabname, unsigned seed, unsigned nMaxSpawn)>(0x190D4C0);
	static inline auto FMovePrefab = PreyFunction<int(CScriptBind_Game* const _this, IFunctionHandler* pH, ScriptHandle entityId)>(0x190BE10);
	static inline auto FDeletePrefab = PreyFunction<int(CScriptBind_Game* const _this, IFunctionHandler* pH, ScriptHandle entityId)>(0x190ACF0);
	static inline auto FHidePrefab = PreyFunction<int(CScriptBind_Game* const _this, IFunctionHandler* pH, ScriptHandle entityId, bool bHide)>(0x190AF80);
	static inline auto FCacheEquipmentPack = PreyFunction<int(CScriptBind_Game* const _this, IFunctionHandler* pH, const char* equipmentPackName)>(0x190A270);
	static inline auto FRegisterGlobals = PreyFunction<void(CScriptBind_Game* const _this)>(0x190BFC0);
	static inline auto FRegisterMethods = PreyFunction<void(CScriptBind_Game* const _this)>(0x190C840);
};
#endif // MOONCRASH
