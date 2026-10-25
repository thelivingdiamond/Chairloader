// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/iface/IGameRulesKillListener.h>
#include <Prey/GameDll/ark/npc/ArkEncounterProfile.h>
#include <Prey/GameDll/ark/npc/IArkEncounterManager.h>

struct ArkEncounter;
class ArkNpc;
struct HitInfo;
struct IEntity;
class XmlNodeRef;

// ArkEncounterManager
// Header:  Prey/GameDll/ark/npc/ArkEncounterManager.h
class ArkEncounterManager : public IArkEncounterManager, public IGameRulesKillListener
{ // Size=152 (0x98)
public:
	enum class EncounterProfileState
	{
		uninitialized = 0,
		inactive = 1,
		populated = 2,
#ifndef MOONCRASH
		repopulated = 3,
#endif
	};

	ArkEncounterManager::EncounterProfileState m_State;
	ArkEncounterProfile* m_pCurrentProfile;
	std::vector<ArkEncounterProfile> m_EncounterProfiles;
	std::map<unsigned int, unsigned int> m_SpawnedToSpawnerMap;
	std::map<unsigned int, ArkEncounter*> m_SpawnedToEncounterMap;
	std::vector<unsigned int> m_ManagedLivingEntities;
	std::vector<unsigned int> m_LivingHostileEntities;
	string m_PendingProfileName;
	bool m_bNeedsEntityHostilityCheck;
#ifndef MOONCRASH
	bool m_bCheckForRepopulationOnNextUpdate;
#endif

	ArkEncounterManager();
	virtual void Load(const XmlNodeRef& _node);
	void Serialize(TSerialize& _serialize) { FSerialize(this, _serialize); }
	void Update(float deltaTime) { FUpdate(this, deltaTime); }
	void Reset(bool _bEnteringGameMode) { FReset(this, _bEnteringGameMode); }
	void OnLevelLoadEnd() { FOnLevelLoadEnd(this); }
	void OnLevelToLevelTransition() { FOnLevelToLevelTransition(this); }
#ifndef MOONCRASH
	void SetCurrentEncounterProfile(const string& encounter_profile_name) { FSetCurrentEncounterProfileOv1(this, encounter_profile_name); }
	void SetCurrentEncounterProfile(ArkEncounterProfile* pProfile) { FSetCurrentEncounterProfileOv0(this, pProfile); }
#else
	void SetCurrentEncounterProfile(const string& encounter_profile_name, bool bAllowResetCurrent) { FSetCurrentEncounterProfileOv1(this, encounter_profile_name, bAllowResetCurrent); }
	void SetCurrentEncounterProfile(ArkEncounterProfile* pProfile, bool bAllowResetCurrent) { FSetCurrentEncounterProfileOv0(this, pProfile, bAllowResetCurrent); }
#endif
	ArkEncounterProfile* AddNewEncounterProfile(const string& encounter_profile_name) { return FAddNewEncounterProfile(this, encounter_profile_name); }
#ifndef MOONCRASH
	ArkEncounterProfile* GetEncounterProfile(const string& encounter_profile_name) { return FGetEncounterProfile(this, encounter_profile_name); }
	ArkEncounter* GetEncounter(const string& encounter_name) { return FGetEncounter(this, encounter_name); }
#else
	ArkEncounter* GetEncounter(const string& profile_name, const string& encounter_name) { return FGetEncounter(this, profile_name, encounter_name); }
#endif
	void AddNewEncounter(const string& encounter_profile_name, const string& encounter_name) { FAddNewEncounter(this, encounter_profile_name, encounter_name); }
#ifndef MOONCRASH
	void AddEncounterInfo(const string& encounter_name, unsigned spawner_id, bool bSpawnFirst, int SpawnChanceWeight, bool bCanRespawn) { FAddEncounterInfo(this, encounter_name, spawner_id, bSpawnFirst, SpawnChanceWeight, bCanRespawn); }
#else
	void AddEncounterInfo(const string& profile_name, const string& encounter_name, unsigned spawner_id, int spawn_track, int doomclock_level, int SpawnChanceWeight) { FAddEncounterInfo(this, profile_name, encounter_name, spawner_id, spawn_track, doomclock_level, SpawnChanceWeight); }
#endif
	void RefreshCurrentEncounterProfile() { FRefreshCurrentEncounterProfile(this); }
	void EliminateCurrentEncounterProfile() { FEliminateCurrentEncounterProfile(this); }
	void SetSpawnerActive(unsigned spawner_id, bool bActive) { FSetSpawnerActive(this, spawner_id, bActive); }
#ifndef MOONCRASH
	bool DoesEncounterHaveLivingEntities(ArkEncounter* pEncounter) { return FDoesEncounterHaveLivingEntities(this, pEncounter); }
#endif
	void NotifyEntitySpawned(IEntity* pEntity, IEntity* pSpawnerEntity) { FNotifyEntitySpawned(this, pEntity, pSpawnerEntity); }
	void NotifyCystoidSpawned(IEntity* pCystoid, IEntity* pSpawnerEntity) { FNotifyCystoidSpawned(this, pCystoid, pSpawnerEntity); }
#ifndef MOONCRASH
	void NotifyCystoidNestSpawned(IEntity* pCystoidNestEntity, IEntity* pSpawnerEntity) { FNotifyCystoidNestSpawned(this, pCystoidNestEntity, pSpawnerEntity); }
	void NotifySpawnCountRequested(const char* pEncounterName, int spawn_count) { FNotifySpawnCountRequested(this, pEncounterName, spawn_count); }
#endif
	void NotifyNPCDone(ArkNpc* pNPC) { FNotifyNPCDone(this, pNPC); }
	void NotifyCystoidDone(unsigned cystoid_id) { FNotifyCystoidDone(this, cystoid_id); }
#ifndef MOONCRASH
	void NotifyCystoidNestDone(unsigned cystoid_nest_id) { FNotifyCystoidNestDone(this, cystoid_nest_id); }
#endif
	bool AddNpcToEncounter(const ArkNpc& _npc, ArkEncounter& _encounter) { return FAddNpcToEncounter(this, _npc, _encounter); }
	virtual void OnEntityKilledEarly(const HitInfo& _hitInfo);
	virtual void OnEntityKilled(const HitInfo& _hitInfo);
	virtual void OnEntityBroken(const unsigned _brokenEntityId);
	void OnCystoidKilled(unsigned cystoid_id) { FOnCystoidKilled(this, cystoid_id); }
#ifndef MOONCRASH
	void OnCystoidNestDepleted(unsigned cystoid_nest_id) { FOnCystoidNestDepleted(this, cystoid_nest_id); }
#endif
	void SetDebugLoggingEnabled(bool bEnabled) { FSetDebugLoggingEnabled(this, bEnabled); }
#ifndef MOONCRASH
	int GetManagedLivingPopulationCount() { return FGetManagedLivingPopulationCount(this); }
	int GetHostileLivingPopulationCount() const { return FGetHostileLivingPopulationCount(this); }
	void CheckForRepopulation(bool bIgnoreTime) { FCheckForRepopulation(this, bIgnoreTime); }
#endif
	bool IsEntityAlive(unsigned entity_id) const { return FIsEntityAlive(this, entity_id); }
	void NotifyDeadEntity(unsigned killed_entity_id) { FNotifyDeadEntity(this, killed_entity_id); }
	void RemoveEntityReferences(unsigned entity_id) { FRemoveEntityReferences(this, entity_id); }
	void CheckEntityForPlayerHostility(unsigned entity_id, unsigned player_id) { FCheckEntityForPlayerHostility(this, entity_id, player_id); }

#if 0
	ArkEncounterManager(const ArkEncounterManager& _arg0_);
	void Init();
	void DebugPrintState(bool _arg0_);
	void Log(const string& _arg0_);
	int GetManagedTotalPopulationCount();
	int GetTotalPopulationCount() const;
	ArkEncounterManager& operator=(const ArkEncounterManager& _arg0_);
	void DestroyManagedNPCs();
#endif

#ifdef MOONCRASH
	void NotifyTyphonNestSpawned(IEntity* _pTyphonNestEntity, IEntity* _pSpawnerEntity) { FNotifyTyphonNestSpawned(this, _pTyphonNestEntity, _pSpawnerEntity); }
	void NotifyTurretSpawned(IEntity* _pTurretEntity, IEntity* _pSpawnerEntity) { FNotifyTurretSpawned(this, _pTurretEntity, _pSpawnerEntity); }
	void NotifyTyphonNestDone(unsigned typhon_nest_id) { FNotifyTyphonNestDone(this, typhon_nest_id); }
	void GetEncounterEntities(const ArkEncounter* _pEncounter, std::vector<unsigned int>& _result) { FGetEncounterEntities(this, _pEncounter, _result); }
	void OnTyphonNestDepleted(unsigned typhon_nest_id) { FOnTyphonNestDepleted(this, typhon_nest_id); }
#endif
#ifndef MOONCRASH
	static inline auto FArkEncounterManagerOv1 = PreyFunction<void(ArkEncounterManager* const _this)>(0x1384290);
	static inline auto FLoad = PreyFunction<void(ArkEncounterManager* const _this, const XmlNodeRef& _node)>(0x1384CC0);
	static inline auto FSerialize = PreyFunction<void(ArkEncounterManager* const _this, TSerialize& _serialize)>(0x1385860);
	static inline auto FUpdate = PreyFunction<void(ArkEncounterManager* const _this, float deltaTime)>(0x1386440);
	static inline auto FReset = PreyFunction<void(ArkEncounterManager* const _this, bool _bEnteringGameMode)>(0x13857C0);
	static inline auto FOnLevelLoadEnd = PreyFunction<void(ArkEncounterManager* const _this)>(0x13855D0);
	static inline auto FOnLevelToLevelTransition = PreyFunction<void(ArkEncounterManager* const _this)>(0x1385610);
	static inline auto FSetCurrentEncounterProfileOv1 = PreyFunction<void(ArkEncounterManager* const _this, const string& encounter_profile_name)>(0x1386130);
	static inline auto FSetCurrentEncounterProfileOv0 = PreyFunction<void(ArkEncounterManager* const _this, ArkEncounterProfile* pProfile)>(0x13861E0);
	static inline auto FAddNewEncounterProfile = PreyFunction<ArkEncounterProfile* (ArkEncounterManager* const _this, const string& encounter_profile_name)>(0x13846F0);
	static inline auto FGetEncounterProfile = PreyFunction<ArkEncounterProfile* (ArkEncounterManager* const _this, const string& encounter_profile_name)>(0x1384A40);
	static inline auto FGetEncounter = PreyFunction<ArkEncounter* (ArkEncounterManager* const _this, const string& encounter_name)>(0x13849F0);
	static inline auto FAddNewEncounter = PreyFunction<void(ArkEncounterManager* const _this, const string& encounter_profile_name, const string& encounter_name)>(0x1384670);
	static inline auto FAddEncounterInfo = PreyFunction<void(ArkEncounterManager* const _this, const string& encounter_name, unsigned spawner_id, bool bSpawnFirst, int SpawnChanceWeight, bool bCanRespawn)>(0x13845E0);
	static inline auto FRefreshCurrentEncounterProfile = PreyFunction<void(ArkEncounterManager* const _this)>(0x1385650);
	static inline auto FEliminateCurrentEncounterProfile = PreyFunction<void(ArkEncounterManager* const _this)>(0x13849E0);
	static inline auto FSetSpawnerActive = PreyFunction<void(ArkEncounterManager* const _this, unsigned spawner_id, bool bActive)>(0x13863E0);
	static inline auto FDoesEncounterHaveLivingEntities = PreyFunction<bool(ArkEncounterManager* const _this, ArkEncounter* pEncounter)>(0x1384930);
	static inline auto FNotifyEntitySpawned = PreyFunction<void(ArkEncounterManager* const _this, IEntity* pEntity, IEntity* pSpawnerEntity)>(0x13852D0);
	static inline auto FNotifyCystoidSpawned = PreyFunction<void(ArkEncounterManager* const _this, IEntity* pCystoid, IEntity* pSpawnerEntity)>(0x1385000);
	static inline auto FNotifyCystoidNestSpawned = PreyFunction<void(ArkEncounterManager* const _this, IEntity* pCystoidNestEntity, IEntity* pSpawnerEntity)>(0x1384E10);
	static inline auto FNotifySpawnCountRequested = PreyFunction<void(ArkEncounterManager* const _this, const char* pEncounterName, int spawn_count)>(0x13854B0);
	static inline auto FNotifyNPCDone = PreyFunction<void(ArkEncounterManager* const _this, ArkNpc* pNPC)>(0x1385480);
	static inline auto FNotifyCystoidDone = PreyFunction<void(ArkEncounterManager* const _this, unsigned cystoid_id)>(0x1384E00);
	static inline auto FNotifyCystoidNestDone = PreyFunction<void(ArkEncounterManager* const _this, unsigned cystoid_nest_id)>(0x1384E00);
	static inline auto FAddNpcToEncounter = PreyFunction<bool(ArkEncounterManager* const _this, const ArkNpc& _npc, ArkEncounter& _encounter)>(0x1384750);
	static inline auto FOnEntityKilledEarly = PreyFunction<void(IGameRulesKillListener* const _this, const HitInfo& _hitInfo)>(0xA13080);
	static inline auto FOnEntityKilled = PreyFunction<void(IGameRulesKillListener* const _this, const HitInfo& _hitInfo)>(0x13855C0);
	static inline auto FOnEntityBroken = PreyFunction<void(IGameRulesKillListener* const _this, const unsigned _brokenEntityId)>(0xA13080);
	static inline auto FOnCystoidKilled = PreyFunction<void(ArkEncounterManager* const _this, unsigned cystoid_id)>(0x13855B0);
	static inline auto FOnCystoidNestDepleted = PreyFunction<void(ArkEncounterManager* const _this, unsigned cystoid_nest_id)>(0x13855B0);
	static inline auto FSetDebugLoggingEnabled = PreyFunction<void(ArkEncounterManager* const _this, bool bEnabled)>(0xA13080);
	static inline auto FGetManagedLivingPopulationCount = PreyFunction<int(ArkEncounterManager* const _this)>(0x1384AA0);
	static inline auto FGetHostileLivingPopulationCount = PreyFunction<int(const ArkEncounterManager* const _this)>(0x1384A90);
	static inline auto FCheckForRepopulation = PreyFunction<void(ArkEncounterManager* const _this, bool bIgnoreTime)>(0x13848F0);
	static inline auto FIsEntityAlive = PreyFunction<bool(const ArkEncounterManager* const _this, unsigned entity_id)>(0x1384AB0);
	static inline auto FNotifyDeadEntity = PreyFunction<void(ArkEncounterManager* const _this, unsigned killed_entity_id)>(0x13851F0);
	static inline auto FRemoveEntityReferences = PreyFunction<void(ArkEncounterManager* const _this, unsigned entity_id)>(0x13856A0);
	static inline auto FCheckEntityForPlayerHostility = PreyFunction<void(ArkEncounterManager* const _this, unsigned entity_id, unsigned player_id)>(0x1384860);
#else
	static inline auto FArkEncounterManagerOv1 = PreyFunction<void(ArkEncounterManager* const _this)>(0x1482310);
	static inline auto FLoad = PreyFunction<void(ArkEncounterManager* const _this, const XmlNodeRef& _node)>(0x1482D30);
	static inline auto FSerialize = PreyFunction<void(ArkEncounterManager* const _this, TSerialize& _serialize)>(0x1483A10);
	static inline auto FUpdate = PreyFunction<void(ArkEncounterManager* const _this, float deltaTime)>(0x1484600);
	static inline auto FReset = PreyFunction<void(ArkEncounterManager* const _this, bool _bEnteringGameMode)>(0x1483970);
	static inline auto FOnLevelLoadEnd = PreyFunction<void(ArkEncounterManager* const _this)>(0x1483760);
	static inline auto FOnLevelToLevelTransition = PreyFunction<void(ArkEncounterManager* const _this)>(0x14837A0);
	static inline auto FSetCurrentEncounterProfileOv1 = PreyFunction<void(ArkEncounterManager* const _this, const string& encounter_profile_name, bool bAllowResetCurrent)>(0x14842D0);
	static inline auto FSetCurrentEncounterProfileOv0 = PreyFunction<void(ArkEncounterManager* const _this, ArkEncounterProfile* pProfile, bool bAllowResetCurrent)>(0x14843A0);
	static inline auto FAddNewEncounterProfile = PreyFunction<ArkEncounterProfile* (ArkEncounterManager* const _this, const string& encounter_profile_name)>(0x1482720);
	static inline auto FGetEncounter = PreyFunction<ArkEncounter* (ArkEncounterManager* const _this, const string& profile_name, const string& encounter_name)>(0x1482930);
	static inline auto FAddNewEncounter = PreyFunction<void(ArkEncounterManager* const _this, const string& encounter_profile_name, const string& encounter_name)>(0x14826A0);
	static inline auto FAddEncounterInfo = PreyFunction<void(ArkEncounterManager* const _this, const string& profile_name, const string& encounter_name, unsigned spawner_id, int spawn_track, int doomclock_level, int SpawnChanceWeight)>(0x1482660);
	static inline auto FRefreshCurrentEncounterProfile = PreyFunction<void(ArkEncounterManager* const _this)>(0x14837F0);
	static inline auto FEliminateCurrentEncounterProfile = PreyFunction<void(ArkEncounterManager* const _this)>(0x1482920);
	static inline auto FSetSpawnerActive = PreyFunction<void(ArkEncounterManager* const _this, unsigned spawner_id, bool bActive)>(0x14845A0);
	static inline auto FNotifyEntitySpawned = PreyFunction<void(ArkEncounterManager* const _this, IEntity* pEntity, IEntity* pSpawnerEntity)>(0x1483050);
	static inline auto FNotifyCystoidSpawned = PreyFunction<void(ArkEncounterManager* const _this, IEntity* pCystoid, IEntity* pSpawnerEntity)>(0x1482E70);
	static inline auto FNotifyTyphonNestSpawned = PreyFunction<void(ArkEncounterManager* const _this, IEntity* _pTyphonNestEntity, IEntity* _pSpawnerEntity)>(0x1483520);
	static inline auto FNotifyTurretSpawned = PreyFunction<void(ArkEncounterManager* const _this, IEntity* _pTurretEntity, IEntity* _pSpawnerEntity)>(0x14832D0);
	static inline auto FNotifyNPCDone = PreyFunction<void(ArkEncounterManager* const _this, ArkNpc* pNPC)>(0x14832A0);
	static inline auto FNotifyCystoidDone = PreyFunction<void(ArkEncounterManager* const _this, unsigned cystoid_id)>(0x1483510);
	static inline auto FNotifyTyphonNestDone = PreyFunction<void(ArkEncounterManager* const _this, unsigned typhon_nest_id)>(0x1483510);
	static inline auto FAddNpcToEncounter = PreyFunction<bool(ArkEncounterManager* const _this, const ArkNpc& _npc, ArkEncounter& _encounter)>(0x1482780);
	static inline auto FGetEncounterEntities = PreyFunction<void(ArkEncounterManager* const _this, const ArkEncounter* _pEncounter, std::vector<unsigned int>& _result)>(0x14829A0);
	static inline auto FOnEntityKilledEarly = PreyFunction<void(IGameRulesKillListener* const _this, const HitInfo& _hitInfo)>(0x1333E90);
	static inline auto FOnEntityKilled = PreyFunction<void(IGameRulesKillListener* const _this, const HitInfo& _hitInfo)>(0x1483750);
	static inline auto FOnEntityBroken = PreyFunction<void(IGameRulesKillListener* const _this, const unsigned _brokenEntityId)>(0x1333E90);
	static inline auto FOnCystoidKilled = PreyFunction<void(ArkEncounterManager* const _this, unsigned cystoid_id)>(0x14837E0);
	static inline auto FOnTyphonNestDepleted = PreyFunction<void(ArkEncounterManager* const _this, unsigned typhon_nest_id)>(0x14837E0);
	static inline auto FSetDebugLoggingEnabled = PreyFunction<void(ArkEncounterManager* const _this, bool bEnabled)>(0x1333E90);
	static inline auto FIsEntityAlive = PreyFunction<bool(const ArkEncounterManager* const _this, unsigned entity_id)>(0x1482A60);
	static inline auto FNotifyDeadEntity = PreyFunction<void(ArkEncounterManager* const _this, unsigned killed_entity_id)>(0x1482FD0);
	static inline auto FRemoveEntityReferences = PreyFunction<void(ArkEncounterManager* const _this, unsigned entity_id)>(0x1483850);
	static inline auto FCheckEntityForPlayerHostility = PreyFunction<void(ArkEncounterManager* const _this, unsigned entity_id, unsigned player_id)>(0x1482890);
#endif
};

