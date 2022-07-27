// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/GameDll/ark/spatial/ArkSpatialManagerKey.h>
#include <Prey/GameDll/ark/spatial/arkspatiallysorted.h>
#include <Prey/GameDll/ark/spatial/arkspatialmanagerentry.h>
#include <Prey/GameDll/ark/spatial/arkspatialmanagerentry_apextentacle.h>
#include <Prey/GameDll/ark/spatial/arkspatialmanagerentry_cystoidnest.h>
#include <Prey/GameDll/ark/spatial/arkspatialmanagerentry_energizable.h>
#include <Prey/GameDll/ark/spatial/arkspatialmanagerentry_interferable.h>
#include <Prey/GameDll/ark/spatial/arkspatialmanagerentry_interferableandenergizable.h>
#include <Prey/GameDll/ark/spatial/arkspatialmanagerentry_npc.h>
#include <Prey/GameDll/ark/spatial/arkspatialmanagerentry_turret.h>

class ArkApexTentacle;
class ArkCystoidNest;
class ArkNpc;
namespace ArkSignalSystem
{
class Manager;
} // namespace ArkSignalSystem
class ArkTurret;
struct IEntity;
struct SEntityEvent;
struct SEntitySpawnParams;

// Header: FromCpp
// Prey/GameDll/ark/spatial/ArkSpatialManager.h
class ArkSpatialManager : public IEntitySystemSink // Id=8016089 Size=824
{
public:
	using EnergizableEntryMap = std::unordered_map<IEntity const *,ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_Energizable>>;
	using InterferableEntryMap = std::unordered_map<IEntity const *,ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_Interferable>>;
	using InterferableAndEnergizableEntryMap = std::unordered_map<IEntity const *,ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_InterferableAndEnergizable>>;
	using SignalIdVector = std::vector<unsigned __int64>;
	using SpatiallySortedApexTentacles = ArkSpatiallySorted<ArkSpatiallySortedApexTentacle>;
	using SpatiallySortedCystoidNests = ArkSpatiallySorted<ArkSpatiallySortedCystoidNest>;
	using SpatiallySortedEntities = ArkSpatiallySorted<ArkSpatiallySortedEntity>;
	using SpatiallySortedNpcs = ArkSpatiallySorted<ArkSpatiallySortedNpc>;
	using SpatiallySortedTurrets = ArkSpatiallySorted<ArkSpatiallySortedTurret>;
	
	std::vector<unsigned __int64> m_energizeAuraSignalIds;
	std::unordered_map<IEntity const *,ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_Energizable>> m_energizableEntries;
	ArkSpatiallySorted<ArkSpatiallySortedEntity> m_energizables;
	std::vector<unsigned __int64> m_interferenceSignalIds;
	std::unordered_map<IEntity const *,ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_Interferable>> m_interferableEntries;
	ArkSpatiallySorted<ArkSpatiallySortedEntity> m_interferables;
	std::unordered_map<IEntity const *,ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_InterferableAndEnergizable>> m_interferableAndEnergizableEntries;
	ArkSpatiallySorted<ArkSpatiallySortedEntity> m_interferableAndEnergizables;
	ArkSpatiallySorted<ArkSpatiallySortedApexTentacle> m_apexTentacles;
	ArkSpatiallySorted<ArkSpatiallySortedCystoidNest> m_cystoidNests;
	ArkSpatiallySorted<ArkSpatiallySortedNpc> m_npcs;
	ArkSpatiallySorted<ArkSpatiallySortedTurret> m_turrets;
	std::unordered_set<unsigned int> m_entitiesForDistanceToPlayerUpdating;
	float m_nextRefreshEntityToPlayerDistTime;
	
	ArkSpatialManager();
	virtual ~ArkSpatialManager();
	void Initialize() { FInitialize(this); }
	void OnLevelLoadStart() { FOnLevelLoadStart(this); }
	void OnLoadSaveStart() { FOnLoadSaveStart(this); }
	void Reset(bool _bEnteringGameMode) { FReset(this,_bEnteringGameMode); }
	void Refresh() { FRefresh(this); }
	ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle> AddApexTentacle(ArkApexTentacle &_tentacle) { return FAddApexTentacle(this,_tentacle); }
	void RemoveApexTentacle(ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle> &_tentacleKey) { FRemoveApexTentacle(this,_tentacleKey); }
	ArkSpatialManagerKey<ArkSpatialManagerKeyType_CystoidNest> AddCystoidNest(ArkCystoidNest &_nest) { return FAddCystoidNest(this,_nest); }
	void RemoveCystoidNest(ArkSpatialManagerKey<ArkSpatialManagerKeyType_CystoidNest> &_nestKey) { FRemoveCystoidNest(this,_nestKey); }
	ArkSpatialManagerKey<ArkSpatialManagerKeyType_Npc> AddNpc(ArkNpc const &_npc) { return FAddNpc(this,_npc); }
	void RemoveNpc(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Npc> &_npcKey) { FRemoveNpc(this,_npcKey); }
	ArkSpatialManagerKey<ArkSpatialManagerKeyType_Turret> AddTurret(ArkTurret const &_turret) { return FAddTurret(this,_turret); }
	void RemoveTurret(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Turret> &_turretKey) { FRemoveTurret(this,_turretKey); }
	void AddEntityForDistanceChecks(IEntity const &_entity) { FAddEntityForDistanceChecks(this,_entity); }
	virtual bool OnBeforeSpawn(SEntitySpawnParams &_params);
	virtual void OnSpawn(IEntity *_pEntity, SEntitySpawnParams &_params);
	virtual bool OnRemove(IEntity *_pEntity);
	virtual void OnReused(IEntity *_pEntity, SEntitySpawnParams &_params);
	virtual void OnEvent(IEntity *_pEntity, SEntityEvent &_event);
	void SetupReceivers() { FSetupReceivers(this); }
	void AddEntity(ArkSignalSystem::Manager const &_signalManager, IEntity const &_entity) { FAddEntity(this,_signalManager,_entity); }
	ArkSpatialManagerKey<ArkSpatialManagerKeyType_Energizable> AddEnergizable(IEntity const &_energizableEntity) { return FAddEnergizable(this,_energizableEntity); }
	void RemoveEnergizable(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Energizable> &_energizableKey) { FRemoveEnergizable(this,_energizableKey); }
	ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable> AddInterferable(IEntity const &_interferableEntity) { return FAddInterferable(this,_interferableEntity); }
	void RemoveInterferable(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable> &_interferableKey) { FRemoveInterferable(this,_interferableKey); }
	ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable> AddInterferableAndEnergizable(IEntity const &_interferableAndEnergizableEntity) { return FAddInterferableAndEnergizableOv0(this,_interferableAndEnergizableEntity); }
	void RemoveInterferableAndEnergizable(ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable> &_interferableAndEnergizableKey) { FRemoveInterferableAndEnergizable(this,_interferableAndEnergizableKey); }
	
#if 0
	void RemoveEntityForDistanceChecks(IEntity const &arg0);
	bool IsEnergizable(ArkSignalSystem::Manager const &arg0, IEntity const &arg1);
	bool IsInterferable(ArkSignalSystem::Manager const &arg0, IEntity const &arg1);
	bool AddInterferableAndEnergizable(ArkSignalSystem::Manager const &arg0, IEntity const &arg1);
	void RefreshEntityToPlayerDistances();
#endif
	
	static inline auto FBitNotArkSpatialManager = PreyFunction<void(ArkSpatialManager *const _this)>(0x13396E0);
	static inline auto FInitialize = PreyFunction<void(ArkSpatialManager *const _this)>(0x133A2A0);
	static inline auto FOnLevelLoadStart = PreyFunction<void(ArkSpatialManager *const _this)>(0x133A3B0);
	static inline auto FOnLoadSaveStart = PreyFunction<void(ArkSpatialManager *const _this)>(0x133A590);
	static inline auto FReset = PreyFunction<void(ArkSpatialManager *const _this, bool _bEnteringGameMode)>(0x133B860);
	static inline auto FRefresh = PreyFunction<void(ArkSpatialManager *const _this)>(0x133B1C0);
	static inline auto FAddApexTentacle = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle>(ArkSpatialManager *const _this, ArkApexTentacle &_tentacle)>(0x13399D0);
	static inline auto FRemoveApexTentacle = PreyFunction<void(ArkSpatialManager *const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle> &_tentacleKey)>(0x133B3E0);
	static inline auto FAddCystoidNest = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_CystoidNest>(ArkSpatialManager *const _this, ArkCystoidNest &_nest)>(0x1339A20);
	static inline auto FRemoveCystoidNest = PreyFunction<void(ArkSpatialManager *const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_CystoidNest> &_nestKey)>(0x133B4C0);
	static inline auto FAddNpc = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_Npc>(ArkSpatialManager *const _this, ArkNpc const &_npc)>(0x133A200);
	static inline auto FRemoveNpc = PreyFunction<void(ArkSpatialManager *const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_Npc> &_npcKey)>(0x133B5D0);
	static inline auto FAddTurret = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_Turret>(ArkSpatialManager *const _this, ArkTurret const &_turret)>(0x133A250);
	static inline auto FRemoveTurret = PreyFunction<void(ArkSpatialManager *const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_Turret> &_turretKey)>(0x133B780);
	static inline auto FAddEntityForDistanceChecks = PreyFunction<void(ArkSpatialManager *const _this, IEntity const &_entity)>(0x133A010);
	static inline auto FOnBeforeSpawn = PreyFunction<bool(ArkSpatialManager *const _this, SEntitySpawnParams &_params)>(0x1B933B0);
	static inline auto FOnSpawn = PreyFunction<void(ArkSpatialManager *const _this, IEntity *_pEntity, SEntitySpawnParams &_params)>(0x133A6C0);
	static inline auto FOnRemove = PreyFunction<bool(ArkSpatialManager *const _this, IEntity *_pEntity)>(0x133A5A0);
	static inline auto FOnReused = PreyFunction<void(ArkSpatialManager *const _this, IEntity *_pEntity, SEntitySpawnParams &_params)>(0xA13080);
	static inline auto FOnEvent = PreyFunction<void(ArkSpatialManager *const _this, IEntity *_pEntity, SEntityEvent &_event)>(0x133A2E0);
	static inline auto FSetupReceivers = PreyFunction<void(ArkSpatialManager *const _this)>(0x133BA70);
	static inline auto FAddEntity = PreyFunction<void(ArkSpatialManager *const _this, ArkSignalSystem::Manager const &_signalManager, IEntity const &_entity)>(0x1339AC0);
	static inline auto FAddEnergizable = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_Energizable>(ArkSpatialManager *const _this, IEntity const &_energizableEntity)>(0x1339A70);
	static inline auto FRemoveEnergizable = PreyFunction<void(ArkSpatialManager *const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_Energizable> &_energizableKey)>(0x133B5A0);
	static inline auto FAddInterferable = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable>(ArkSpatialManager *const _this, IEntity const &_interferableEntity)>(0x133A160);
	static inline auto FRemoveInterferable = PreyFunction<void(ArkSpatialManager *const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable> &_interferableKey)>(0x133B5B0);
	static inline auto FAddInterferableAndEnergizableOv0 = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable>(ArkSpatialManager *const _this, IEntity const &_interferableAndEnergizableEntity)>(0x133A1B0);
	static inline auto FRemoveInterferableAndEnergizable = PreyFunction<void(ArkSpatialManager *const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable> &_interferableAndEnergizableKey)>(0x133B5C0);
};

