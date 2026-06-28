// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/GameDll/ark/spatial/arkspatiallysorted.h>
#include <_unknown/ArkSpatialManagerEntry.h>
#include <_unknown/ArkSpatialManagerKey.h>
#include <_unknown/ArkSpatiallySorted.h>

class ArkApexTentacle;
class ArkNpc;
namespace ArkSignalSystem
{
class Manager;
} // namespace ArkSignalSystem
class ArkTurret;
class ArkTyphonNest;
class CArkNpcSpawner;
struct IEntity;
struct SEntityEvent;
struct SEntitySpawnParams;

// ArkSpatialManager
// Header:  Prey/GameDll/ark/spatial/ArkSpatialManager.h
class ArkSpatialManager : public IEntitySystemSink
{ // Size=896 (0x380)
public:
	using EnergizableEntryMap = std::unordered_map<const IEntity*, ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_Energizable>>;
	using InterferableEntryMap = std::unordered_map<const IEntity*, ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_Interferable>>;
	using InterferableAndEnergizableEntryMap = std::unordered_map<const IEntity*, ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_InterferableAndEnergizable>>;
	using SignalIdVector = std::vector<uint64_t>;
	using SpatiallySortedApexTentacles = ArkSpatiallySorted<ArkSpatiallySortedApexTentacle>;
	using SpatiallySortedTyphonNests = ArkSpatiallySorted<ArkSpatiallySortedTyphonNest>;
	using SpatiallySortedEntities = ArkSpatiallySorted<ArkSpatiallySortedEntity>;
	using SpatiallySortedNpcs = ArkSpatiallySorted<ArkSpatiallySortedNpc>;
	using SpatiallySortedTurrets = ArkSpatiallySorted<ArkSpatiallySortedTurret>;
	using SpatiallySortedNpcSpawners = ArkSpatiallySorted<ArkSpatiallySortedNpcSpawner>;

	std::vector<uint64_t> m_energizeAuraSignalIds;
	std::unordered_map<const IEntity*, ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_Energizable>> m_energizableEntries;
	ArkSpatiallySorted<ArkSpatiallySortedEntity> m_energizables;
	std::vector<uint64_t> m_interferenceSignalIds;
	std::unordered_map<const IEntity*, ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_Interferable>> m_interferableEntries;
	ArkSpatiallySorted<ArkSpatiallySortedEntity> m_interferables;
	std::unordered_map<const IEntity*, ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_InterferableAndEnergizable>> m_interferableAndEnergizableEntries;
	ArkSpatiallySorted<ArkSpatiallySortedEntity> m_interferableAndEnergizables;
	ArkSpatiallySorted<ArkSpatiallySortedApexTentacle> m_apexTentacles;
	ArkSpatiallySorted<ArkSpatiallySortedTyphonNest> m_typhonNests;
	ArkSpatiallySorted<ArkSpatiallySortedNpc> m_npcs;
	ArkSpatiallySorted<ArkSpatiallySortedNpcSpawner> m_npcSpawners;
	ArkSpatiallySorted<ArkSpatiallySortedTurret> m_turrets;
	std::unordered_set<unsigned int> m_entitiesForDistanceToPlayerUpdating;
	float m_nextRefreshEntityToPlayerDistTime;

	ArkSpatialManager();
	virtual ~ArkSpatialManager();
	void Initialize() { FInitialize(this); }
	void OnLevelLoadStart() { FOnLevelLoadStart(this); }
	void OnLoadSaveStart() { FOnLoadSaveStart(this); }
	void OnLevelLoadEnd() { FOnLevelLoadEnd(this); }
	void Reset(bool _bEnteringGameMode) { FReset(this, _bEnteringGameMode); }
	void Refresh() { FRefresh(this); }
	ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle> AddApexTentacle(ArkApexTentacle& _tentacle) { alignas(ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle>) std::byte _return_buf_[sizeof(ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle>)]; return *FAddApexTentacle(this, reinterpret_cast<ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle>*>(_return_buf_), _tentacle); }
	void RemoveApexTentacle(ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle>& _tentacleKey) { FRemoveApexTentacle(this, _tentacleKey); }
	ArkSpatialManagerKey<ArkSpatialManagerKeyType_TyphonNest> AddTyphonNest(ArkTyphonNest& _nest) { alignas(ArkSpatialManagerKey<ArkSpatialManagerKeyType_TyphonNest>) std::byte _return_buf_[sizeof(ArkSpatialManagerKey<ArkSpatialManagerKeyType_TyphonNest>)]; return *FAddTyphonNest(this, reinterpret_cast<ArkSpatialManagerKey<ArkSpatialManagerKeyType_TyphonNest>*>(_return_buf_), _nest); }
	void RemoveTyphonNest(ArkSpatialManagerKey<ArkSpatialManagerKeyType_TyphonNest>& _nestKey) { FRemoveTyphonNest(this, _nestKey); }
	ArkSpatialManagerKey<ArkSpatialManagerKeyType_Npc> AddNpc(const ArkNpc& _npc) { alignas(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Npc>) std::byte _return_buf_[sizeof(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Npc>)]; return *FAddNpc(this, reinterpret_cast<ArkSpatialManagerKey<ArkSpatialManagerKeyType_Npc>*>(_return_buf_), _npc); }
	void RemoveNpc(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Npc>& _npcKey) { FRemoveNpc(this, _npcKey); }
	ArkSpatialManagerKey<ArkSpatialManagerKeyType_NpcSpawner> AddNpcSpawner(const CArkNpcSpawner& _npcSpawner) { alignas(ArkSpatialManagerKey<ArkSpatialManagerKeyType_NpcSpawner>) std::byte _return_buf_[sizeof(ArkSpatialManagerKey<ArkSpatialManagerKeyType_NpcSpawner>)]; return *FAddNpcSpawner(this, reinterpret_cast<ArkSpatialManagerKey<ArkSpatialManagerKeyType_NpcSpawner>*>(_return_buf_), _npcSpawner); }
	void RemoveNpcSpawner(ArkSpatialManagerKey<ArkSpatialManagerKeyType_NpcSpawner>& _npcSpawnerKey) { FRemoveNpcSpawner(this, _npcSpawnerKey); }
	ArkSpatialManagerKey<ArkSpatialManagerKeyType_Turret> AddTurret(const ArkTurret& _turret) { alignas(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Turret>) std::byte _return_buf_[sizeof(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Turret>)]; return *FAddTurret(this, reinterpret_cast<ArkSpatialManagerKey<ArkSpatialManagerKeyType_Turret>*>(_return_buf_), _turret); }
	void RemoveTurret(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Turret>& _turretKey) { FRemoveTurret(this, _turretKey); }
	void AddEntityForDistanceChecks(const IEntity& _entity) { FAddEntityForDistanceChecks(this, _entity); }
	virtual bool OnBeforeSpawn(SEntitySpawnParams& _params);
	virtual void OnSpawn(IEntity* _pEntity, SEntitySpawnParams& _params);
	virtual bool OnRemove(IEntity* _pEntity);
	virtual void OnReused(IEntity* _pEntity, SEntitySpawnParams& _params);
	virtual void OnEvent(IEntity* _pEntity, SEntityEvent& _event);
	void SetupReceivers() { FSetupReceivers(this); }
	void AddEntity(const ArkSignalSystem::Manager& _signalManager, const IEntity& _entity) { FAddEntity(this, _signalManager, _entity); }
	ArkSpatialManagerKey<ArkSpatialManagerKeyType_Energizable> AddEnergizable(const IEntity& _energizableEntity) { alignas(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Energizable>) std::byte _return_buf_[sizeof(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Energizable>)]; return *FAddEnergizable(this, reinterpret_cast<ArkSpatialManagerKey<ArkSpatialManagerKeyType_Energizable>*>(_return_buf_), _energizableEntity); }
	void RemoveEnergizable(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Energizable>& _energizableKey) { FRemoveEnergizable(this, _energizableKey); }
	ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable> AddInterferable(const IEntity& _interferableEntity) { alignas(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable>) std::byte _return_buf_[sizeof(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable>)]; return *FAddInterferable(this, reinterpret_cast<ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable>*>(_return_buf_), _interferableEntity); }
	void RemoveInterferable(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable>& _interferableKey) { FRemoveInterferable(this, _interferableKey); }
	ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable> AddInterferableAndEnergizable(const IEntity& _interferableAndEnergizableEntity) { alignas(ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable>) std::byte _return_buf_[sizeof(ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable>)]; return *FAddInterferableAndEnergizableOv0(this, reinterpret_cast<ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable>*>(_return_buf_), _interferableAndEnergizableEntity); }
	void RemoveInterferableAndEnergizable(ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable>& _interferableAndEnergizableKey) { FRemoveInterferableAndEnergizable(this, _interferableAndEnergizableKey); }

#if 0
	ArkSpatialManager(const ArkSpatialManager& _arg0_);
	void RemoveEntityForDistanceChecks(const IEntity& _arg0_);
	ArkSpatialManager& operator=(const ArkSpatialManager& _arg0_);
	bool IsEnergizable(const ArkSignalSystem::Manager& _arg0_, const IEntity& _arg1_);
	bool IsInterferable(const ArkSignalSystem::Manager& _arg0_, const IEntity& _arg1_);
	bool AddInterferableAndEnergizable(const ArkSignalSystem::Manager& _arg0_, const IEntity& _arg1_);
	void RefreshEntityToPlayerDistances();
#endif

	static inline auto FArkSpatialManagerOv1 = PreyFunction<void(ArkSpatialManager* const _this)>(0x14155F0);
	static inline auto FBitNotArkSpatialManager = PreyFunction<void(ArkSpatialManager* const _this)>(0x1415940);
	static inline auto FInitialize = PreyFunction<void(ArkSpatialManager* const _this)>(0x1416570);
	static inline auto FOnLevelLoadStart = PreyFunction<void(ArkSpatialManager* const _this)>(0x1416670);
	static inline auto FOnLoadSaveStart = PreyFunction<void(ArkSpatialManager* const _this)>(0x1416880);
	static inline auto FOnLevelLoadEnd = PreyFunction<void(ArkSpatialManager* const _this)>(0x1416660);
	static inline auto FReset = PreyFunction<void(ArkSpatialManager* const _this, bool _bEnteringGameMode)>(0x1417C20);
	static inline auto FRefresh = PreyFunction<void(ArkSpatialManager* const _this)>(0x14174B0);
	static inline auto FAddApexTentacle = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle>*(ArkSpatialManager* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle>* _return_value_, ArkApexTentacle& _tentacle)>(0x1415C50);
	static inline auto FRemoveApexTentacle = PreyFunction<void(ArkSpatialManager* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle>& _tentacleKey)>(0x14176C0);
	static inline auto FAddTyphonNest = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_TyphonNest>*(ArkSpatialManager* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_TyphonNest>* _return_value_, ArkTyphonNest& _nest)>(0x1416520);
	static inline auto FRemoveTyphonNest = PreyFunction<void(ArkSpatialManager* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_TyphonNest>& _nestKey)>(0x1417B40);
	static inline auto FAddNpc = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_Npc>*(ArkSpatialManager* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_Npc>* _return_value_, const ArkNpc& _npc)>(0x1416430);
	static inline auto FRemoveNpc = PreyFunction<void(ArkSpatialManager* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_Npc>& _npcKey)>(0x14177D0);
	static inline auto FAddNpcSpawner = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_NpcSpawner>*(ArkSpatialManager* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_NpcSpawner>* _return_value_, const CArkNpcSpawner& _npcSpawner)>(0x1416480);
	static inline auto FRemoveNpcSpawner = PreyFunction<void(ArkSpatialManager* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_NpcSpawner>& _npcSpawnerKey)>(0x14178B0);
	static inline auto FAddTurret = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_Turret>*(ArkSpatialManager* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_Turret>* _return_value_, const ArkTurret& _turret)>(0x14164D0);
	static inline auto FRemoveTurret = PreyFunction<void(ArkSpatialManager* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_Turret>& _turretKey)>(0x1417A60);
	static inline auto FAddEntityForDistanceChecks = PreyFunction<void(ArkSpatialManager* const _this, const IEntity& _entity)>(0x1416240);
	static inline auto FOnBeforeSpawn = PreyFunction<bool(ArkSpatialManager* const _this, SEntitySpawnParams& _params)>(0x1A302A0);
	static inline auto FOnSpawn = PreyFunction<void(ArkSpatialManager* const _this, IEntity* _pEntity, SEntitySpawnParams& _params)>(0x14169B0);
	static inline auto FOnRemove = PreyFunction<bool(ArkSpatialManager* const _this, IEntity* _pEntity)>(0x1416890);
	static inline auto FOnReused = PreyFunction<void(ArkSpatialManager* const _this, IEntity* _pEntity, SEntitySpawnParams& _params)>(0x1333E90);
	static inline auto FOnEvent = PreyFunction<void(ArkSpatialManager* const _this, IEntity* _pEntity, SEntityEvent& _event)>(0x1416590);
	static inline auto FSetupReceivers = PreyFunction<void(ArkSpatialManager* const _this)>(0x1417E60);
	static inline auto FAddEntity = PreyFunction<void(ArkSpatialManager* const _this, const ArkSignalSystem::Manager& _signalManager, const IEntity& _entity)>(0x1415CF0);
	static inline auto FAddEnergizable = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_Energizable>*(ArkSpatialManager* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_Energizable>* _return_value_, const IEntity& _energizableEntity)>(0x1415CA0);
	static inline auto FRemoveEnergizable = PreyFunction<void(ArkSpatialManager* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_Energizable>& _energizableKey)>(0x14177A0);
	static inline auto FAddInterferable = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable>*(ArkSpatialManager* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable>* _return_value_, const IEntity& _interferableEntity)>(0x1416390);
	static inline auto FRemoveInterferable = PreyFunction<void(ArkSpatialManager* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable>& _interferableKey)>(0x14177B0);
	static inline auto FAddInterferableAndEnergizableOv0 = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable>*(ArkSpatialManager* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable>* _return_value_, const IEntity& _interferableAndEnergizableEntity)>(0x14163E0);
	static inline auto FRemoveInterferableAndEnergizable = PreyFunction<void(ArkSpatialManager* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable>& _interferableAndEnergizableKey)>(0x14177C0);
};
#endif // !MOONCRASH
