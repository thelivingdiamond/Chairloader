// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <_unknown/IGameRulesSpawningModule.h>

class CGameRules;
enum EEntityAspects;
struct HitInfo;
struct IActor;
class XmlNodeRef;

// CGameRulesSpawningBase
// Header:  Prey/GameDll/gamerulesmodules/GameRulesSpawningBase.h
class CGameRulesSpawningBase : public IGameRulesSpawningModule
{ // Size=120 (0x78)
public:
	// CGameRulesSpawningBase::SSpawnGroup
	// Header:  Prey/GameDll/gamerulesmodules/GameRulesSpawningBase.h
	struct SSpawnGroup
	{ // Size=32 (0x20)
		std::vector<unsigned int> m_locations;
		unsigned m_id;
		uint8_t m_useCount;
	};

	using inherited = IGameRulesSpawningModule;
	using TSpawnLocations = std::vector<unsigned int>;
	using TSpawnGroups = std::vector<CGameRulesSpawningBase::SSpawnGroup>;

	static constexpr const unsigned kInvalidInitialSpawnIndex = 4294967295;
	std::vector<unsigned int> m_allSpawnLocations;
	std::vector<unsigned int> m_spawnLocations;
	std::vector<CGameRulesSpawningBase::SSpawnGroup> m_initialSpawnLocations;
	std::map<unsigned int, IGameRulesSpawningModule::SPlayerData> m_playerValues;
	CGameRules* m_pGameRules;
	unsigned m_activeInitialSpawnGroupIndex;
	bool m_bTeamAlwaysUsesInitialSpawns[2];
	int m_spawnGroupOverride;

	CGameRulesSpawningBase();
	virtual ~CGameRulesSpawningBase();
	virtual void SetLastSpawn(unsigned playerId, unsigned spawnId);
	virtual void Init(XmlNodeRef xml);
	virtual void PostInit();
	virtual void Update(float frameTime);
	virtual bool NetSerialize(TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags);
	virtual void AddSpawnLocation(unsigned location, bool isInitialSpawn, bool doVisTest, const char* pGroupName);
	virtual void RemoveSpawnLocation(unsigned id, bool isInitialSpawn);
	virtual void EnableSpawnLocation(unsigned location, bool isInitialSpawn, const char* pGroupName);
	virtual void DisableSpawnLocation(unsigned id, bool isInitialSpawn);
	virtual void SetInitialSpawnGroup(const char* groupName);
	virtual unsigned GetSpawnLocation(unsigned playerId);
	virtual unsigned GetFirstSpawnLocation(int teamId) const;
	virtual int GetSpawnLocationCount() const;
	virtual unsigned GetNthSpawnLocation(int idx) const;
	virtual int GetSpawnIndexForEntityId(unsigned spawnId) const;
	virtual void AddAvoidPOI(unsigned entityId, float avoidDistance, bool enabled, bool bStaticPOI);
	virtual void RemovePOI(unsigned entityId);
	virtual void EnablePOI(unsigned entityId);
	virtual void DisablePOI(unsigned entityId);
	virtual void PlayerJoined(unsigned playerId);
	virtual void PlayerLeft(unsigned playerId);
	virtual void OnPlayerKilled(const HitInfo& hitInfo);
	virtual void ClRequestRevive(unsigned playerId);
	virtual bool SvRequestRevive(unsigned playerId, unsigned preferredSpawnId);
	virtual void PerformRevive(unsigned playerId, int teamId, unsigned preferredSpawnId);
	virtual void OnSetTeam(unsigned playerId, int teamId);
	virtual const std::map<unsigned int, IGameRulesSpawningModule::SPlayerData>* GetPlayerValuesMap() const;
	virtual void ReviveAllPlayers(bool isReset, bool bOnlyIfDead);
	virtual int GetRemainingLives(unsigned playerId);
	virtual int GetNumLives();
	virtual float GetTimeFromDeathTillAutoReviveForTeam(int teamId) const;
	virtual float GetPlayerAutoReviveAdditionalTime(IActor* pActor) const;
	virtual float GetAutoReviveTimeScaleForTeam(int teamId) const;
	virtual void SetAutoReviveTimeScaleForTeam(int teamId, float newScale);
	virtual void HostMigrationInsertIntoReviveQueue(unsigned playerId, float timeTillRevive);
	virtual void OnInGameBegin();
	virtual void OnInitialEquipmentScreenShown();
	virtual void OnNewRoundEquipmentScreenShown();
	virtual float GetRemainingInitialAutoSpawnTimer();
	virtual bool SvIsMidRoundJoiningAllowed() const;
	virtual bool CanPlayerSpawnThisRound(const unsigned playerId) const;
	virtual bool IsInInitialChannelsList(unsigned channelId) const;
	virtual void HostMigrationStopAddingPlayers();
	virtual void HostMigrationResumeAddingPlayers();
	static std::vector<unsigned int>* GetSpawnLocationsFromGroup(std::vector<CGameRulesSpawningBase::SSpawnGroup>& groups, const char* pGroupName) { return FGetSpawnLocationsFromGroup(groups, pGroupName); }

#if 0
	bool HasInitialSpawns() const;
	const std::vector<unsigned int>& GetInitialSpawns() const;
	float GetTime() const;
	bool IsPlayerInitialSpawning(const unsigned _arg0_) const;
	std::vector<unsigned int>& GetSpawnLocations(const unsigned _arg0_);
	void SelectNewInitialSpawnGroup();
#endif

	static inline auto FCGameRulesSpawningBaseOv1 = PreyFunction<void(CGameRulesSpawningBase* const _this)>(0x185B100);
	static inline auto FSetLastSpawn = PreyFunction<void(CGameRulesSpawningBase* const _this, unsigned playerId, unsigned spawnId)>(0x185BE50);
	static inline auto FInit = PreyFunction<void(CGameRulesSpawningBase* const _this, XmlNodeRef xml)>(0x185B900);
	static inline auto FPostInit = PreyFunction<void(CGameRulesSpawningBase* const _this)>(0x1333E90);
	static inline auto FUpdate = PreyFunction<void(CGameRulesSpawningBase* const _this, float frameTime)>(0x1333E90);
	static inline auto FNetSerialize = PreyFunction<bool(CGameRulesSpawningBase* const _this, TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags)>(0x185B990);
	static inline auto FAddSpawnLocation = PreyFunction<void(CGameRulesSpawningBase* const _this, unsigned location, bool isInitialSpawn, bool doVisTest, const char* pGroupName)>(0x185B340);
	static inline auto FRemoveSpawnLocation = PreyFunction<void(CGameRulesSpawningBase* const _this, unsigned id, bool isInitialSpawn)>(0x185BC20);
	static inline auto FEnableSpawnLocation = PreyFunction<void(CGameRulesSpawningBase* const _this, unsigned location, bool isInitialSpawn, const char* pGroupName)>(0x185B5D0);
	static inline auto FDisableSpawnLocation = PreyFunction<void(CGameRulesSpawningBase* const _this, unsigned id, bool isInitialSpawn)>(0x185B490);
	static inline auto FSetInitialSpawnGroup = PreyFunction<void(CGameRulesSpawningBase* const _this, const char* groupName)>(0x185BDA0);
	static inline auto FGetSpawnLocation = PreyFunction<unsigned(CGameRulesSpawningBase* const _this, unsigned playerId)>(0x1CBB0B0);
	static inline auto FGetFirstSpawnLocation = PreyFunction<unsigned(const CGameRulesSpawningBase* const _this, int teamId)>(0x185B6B0);
	static inline auto FGetSpawnLocationCount = PreyFunction<int(const CGameRulesSpawningBase* const _this)>(0x185B7C0);
	static inline auto FGetNthSpawnLocation = PreyFunction<unsigned(const CGameRulesSpawningBase* const _this, int idx)>(0x185B750);
	static inline auto FGetSpawnIndexForEntityId = PreyFunction<int(const CGameRulesSpawningBase* const _this, unsigned spawnId)>(0x185B780);
	static inline auto FAddAvoidPOI = PreyFunction<void(CGameRulesSpawningBase* const _this, unsigned entityId, float avoidDistance, bool enabled, bool bStaticPOI)>(0x1333E90);
	static inline auto FRemovePOI = PreyFunction<void(CGameRulesSpawningBase* const _this, unsigned entityId)>(0x1333E90);
	static inline auto FEnablePOI = PreyFunction<void(CGameRulesSpawningBase* const _this, unsigned entityId)>(0x1333E90);
	static inline auto FDisablePOI = PreyFunction<void(CGameRulesSpawningBase* const _this, unsigned entityId)>(0x1333E90);
	static inline auto FPlayerJoined = PreyFunction<void(CGameRulesSpawningBase* const _this, unsigned playerId)>(0x185BB60);
	static inline auto FPlayerLeft = PreyFunction<void(CGameRulesSpawningBase* const _this, unsigned playerId)>(0x185BBC0);
	static inline auto FOnPlayerKilled = PreyFunction<void(CGameRulesSpawningBase* const _this, const HitInfo& hitInfo)>(0x185BA80);
	static inline auto FClRequestRevive = PreyFunction<void(CGameRulesSpawningBase* const _this, unsigned playerId)>(0x1333E90);
	static inline auto FSvRequestRevive = PreyFunction<bool(CGameRulesSpawningBase* const _this, unsigned playerId, unsigned preferredSpawnId)>(0x13B0900);
	static inline auto FPerformRevive = PreyFunction<void(CGameRulesSpawningBase* const _this, unsigned playerId, int teamId, unsigned preferredSpawnId)>(0x1333E90);
	static inline auto FOnSetTeam = PreyFunction<void(CGameRulesSpawningBase* const _this, unsigned playerId, int teamId)>(0x1333E90);
	static inline auto FGetPlayerValuesMap = PreyFunction<const std::map<unsigned int, IGameRulesSpawningModule::SPlayerData>* (const CGameRulesSpawningBase* const _this)>(0x10ED4B0);
	static inline auto FReviveAllPlayers = PreyFunction<void(CGameRulesSpawningBase* const _this, bool isReset, bool bOnlyIfDead)>(0x1333E90);
	static inline auto FGetRemainingLives = PreyFunction<int(CGameRulesSpawningBase* const _this, unsigned playerId)>(0x1CBB0B0);
	static inline auto FGetNumLives = PreyFunction<int(CGameRulesSpawningBase* const _this)>(0x1CBB0B0);
	static inline auto FGetTimeFromDeathTillAutoReviveForTeam = PreyFunction<float(const CGameRulesSpawningBase* const _this, int teamId)>(0x13C1A80);
	static inline auto FGetPlayerAutoReviveAdditionalTime = PreyFunction<float(const CGameRulesSpawningBase* const _this, IActor* pActor)>(0x714650);
	static inline auto FGetAutoReviveTimeScaleForTeam = PreyFunction<float(const CGameRulesSpawningBase* const _this, int teamId)>(0x1AE7A80);
	static inline auto FSetAutoReviveTimeScaleForTeam = PreyFunction<void(CGameRulesSpawningBase* const _this, int teamId, float newScale)>(0x1333E90);
	static inline auto FHostMigrationInsertIntoReviveQueue = PreyFunction<void(CGameRulesSpawningBase* const _this, unsigned playerId, float timeTillRevive)>(0x1333E90);
	static inline auto FOnInGameBegin = PreyFunction<void(CGameRulesSpawningBase* const _this)>(0x1333E90);
	static inline auto FOnInitialEquipmentScreenShown = PreyFunction<void(CGameRulesSpawningBase* const _this)>(0x1333E90);
	static inline auto FOnNewRoundEquipmentScreenShown = PreyFunction<void(CGameRulesSpawningBase* const _this)>(0x1333E90);
	static inline auto FGetRemainingInitialAutoSpawnTimer = PreyFunction<float(CGameRulesSpawningBase* const _this)>(0x13C1A80);
	static inline auto FSvIsMidRoundJoiningAllowed = PreyFunction<bool(const CGameRulesSpawningBase* const _this)>(0x1A302A0);
	static inline auto FCanPlayerSpawnThisRound = PreyFunction<bool(const CGameRulesSpawningBase* const _this, const unsigned playerId)>(0x1A302A0);
	static inline auto FIsInInitialChannelsList = PreyFunction<bool(const CGameRulesSpawningBase* const _this, unsigned channelId)>(0x1A302A0);
	static inline auto FHostMigrationStopAddingPlayers = PreyFunction<void(CGameRulesSpawningBase* const _this)>(0x1333E90);
	static inline auto FHostMigrationResumeAddingPlayers = PreyFunction<void(CGameRulesSpawningBase* const _this)>(0x1333E90);
	static inline auto FGetSpawnLocationsFromGroup = PreyFunction<std::vector<unsigned int>* (std::vector<CGameRulesSpawningBase::SSpawnGroup>& groups, const char* pGroupName)>(0x185B7D0);
};

// compare_spawns_name_only
// Header:  Prey/GameDll/gamerulesmodules/GameRulesSpawningBase.h
struct compare_spawns_name_only
{ // Size=1 (0x1)
	bool operator()(unsigned lhs, unsigned rhs) const { return FoperatorRBLRBR(this, lhs, rhs); }

	static inline auto FoperatorRBLRBR = PreyFunction<bool(const compare_spawns_name_only* const _this, unsigned lhs, unsigned rhs)>(0x185B230);
};
#endif // MOONCRASH
