// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/iface/IGameRulesKillListener.h>
#include <Prey/GameDll/ark/npc/ArkEncounterProfile.h>
#include <_unknown/IArkEncounterManager.h>

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

	ArkEncounterManager();
	virtual void Load(const XmlNodeRef& _node);
	void Serialize(TSerialize& _serialize) { FSerialize(this, _serialize); }
	void Update(float deltaTime) { FUpdate(this, deltaTime); }
	void Reset(bool _bEnteringGameMode) { FReset(this, _bEnteringGameMode); }
	void OnLevelLoadEnd() { FOnLevelLoadEnd(this); }
	void OnLevelToLevelTransition() { FOnLevelToLevelTransition(this); }
	void SetCurrentEncounterProfile(const string& encounter_profile_name, bool bAllowResetCurrent) { FSetCurrentEncounterProfileOv1(this, encounter_profile_name, bAllowResetCurrent); }
	void SetCurrentEncounterProfile(ArkEncounterProfile* pProfile, bool bAllowResetCurrent) { FSetCurrentEncounterProfileOv0(this, pProfile, bAllowResetCurrent); }
	ArkEncounterProfile* AddNewEncounterProfile(const string& encounter_profile_name) { return FAddNewEncounterProfile(this, encounter_profile_name); }
	ArkEncounter* GetEncounter(const string& profile_name, const string& encounter_name) { return FGetEncounter(this, profile_name, encounter_name); }
	void AddNewEncounter(const string& encounter_profile_name, const string& encounter_name) { FAddNewEncounter(this, encounter_profile_name, encounter_name); }
	void AddEncounterInfo(const string& profile_name, const string& encounter_name, unsigned spawner_id, int spawn_track, int doomclock_level, int SpawnChanceWeight) { FAddEncounterInfo(this, profile_name, encounter_name, spawner_id, spawn_track, doomclock_level, SpawnChanceWeight); }
	void RefreshCurrentEncounterProfile() { FRefreshCurrentEncounterProfile(this); }
	void EliminateCurrentEncounterProfile() { FEliminateCurrentEncounterProfile(this); }
	void SetSpawnerActive(unsigned spawner_id, bool bActive) { FSetSpawnerActive(this, spawner_id, bActive); }
	void NotifyEntitySpawned(IEntity* pEntity, IEntity* pSpawnerEntity) { FNotifyEntitySpawned(this, pEntity, pSpawnerEntity); }
	void NotifyCystoidSpawned(IEntity* pCystoid, IEntity* pSpawnerEntity) { FNotifyCystoidSpawned(this, pCystoid, pSpawnerEntity); }
	void NotifyTyphonNestSpawned(IEntity* _pTyphonNestEntity, IEntity* _pSpawnerEntity) { FNotifyTyphonNestSpawned(this, _pTyphonNestEntity, _pSpawnerEntity); }
	void NotifyTurretSpawned(IEntity* _pTurretEntity, IEntity* _pSpawnerEntity) { FNotifyTurretSpawned(this, _pTurretEntity, _pSpawnerEntity); }
	void NotifyNPCDone(ArkNpc* pNPC) { FNotifyNPCDone(this, pNPC); }
	void NotifyCystoidDone(unsigned cystoid_id) { FNotifyCystoidDone(this, cystoid_id); }
	void NotifyTyphonNestDone(unsigned typhon_nest_id) { FNotifyTyphonNestDone(this, typhon_nest_id); }
	bool AddNpcToEncounter(const ArkNpc& _npc, ArkEncounter& _encounter) { return FAddNpcToEncounter(this, _npc, _encounter); }
	void GetEncounterEntities(const ArkEncounter* _pEncounter, std::vector<unsigned int>& _result) { FGetEncounterEntities(this, _pEncounter, _result); }
	virtual void OnEntityKilledEarly(const HitInfo& _hitInfo);
	virtual void OnEntityKilled(const HitInfo& _hitInfo);
	virtual void OnEntityBroken(const unsigned _brokenEntityId);
	void OnCystoidKilled(unsigned cystoid_id) { FOnCystoidKilled(this, cystoid_id); }
	void OnTyphonNestDepleted(unsigned typhon_nest_id) { FOnTyphonNestDepleted(this, typhon_nest_id); }
	void SetDebugLoggingEnabled(bool bEnabled) { FSetDebugLoggingEnabled(this, bEnabled); }
	bool IsEntityAlive(unsigned entity_id) const { return FIsEntityAlive(this, entity_id); }
	void NotifyDeadEntity(unsigned killed_entity_id) { FNotifyDeadEntity(this, killed_entity_id); }
	void RemoveEntityReferences(unsigned entity_id) { FRemoveEntityReferences(this, entity_id); }
	void CheckEntityForPlayerHostility(unsigned entity_id, unsigned player_id) { FCheckEntityForPlayerHostility(this, entity_id, player_id); }

#if 0
	ArkEncounterManager(const ArkEncounterManager& _arg0_);
	void Init();
	ArkEncounterProfile* GetCurrentEncounterProfile();
	ArkEncounterProfile* GetEncounterProfile(const string& _arg0_);
	bool DoesEncounterHaveLivingEntities(ArkEncounter* _arg0_);
	void NotifySpawnCountRequested(const char* _arg0_, const char* _arg1_, int _arg2_);
	void DebugPrintState(bool _arg0_);
	void Log(const string& _arg0_);
	int GetManagedLivingPopulationCount();
	int GetManagedTotalPopulationCount();
	int GetTotalPopulationCount() const;
	int GetHostileLivingPopulationCount() const;
	ArkEncounterManager& operator=(const ArkEncounterManager& _arg0_);
	void DestroyManagedNPCs();
#endif

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
};
#endif // MOONCRASH
