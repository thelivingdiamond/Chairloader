// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

enum EEntityAspects;
struct HitInfo;
struct IActor;
class XmlNodeRef;

// IGameRulesSpawningModule
// Header:  _unknown/IGameRulesSpawningModule.h
class IGameRulesSpawningModule
{ // Size=8 (0x8)
public:
	// IGameRulesSpawningModule::SPlayerData
	// Header:  _unknown/IGameRulesSpawningModule.h
	struct SPlayerData
	{ // Size=32 (0x20)
		float deathTime;
		Vec3 deathPos;
		float lastRevivedTime;
		unsigned lastSpawnLocationId;
		unsigned lastKillerId;
		bool triedAutoRevive;

	#if 0
		SPlayerData();
	#endif
	};

	using TPlayerDataMap = std::map<unsigned int, IGameRulesSpawningModule::SPlayerData>;

	virtual ~IGameRulesSpawningModule();
	virtual void Init(XmlNodeRef xml) = 0;
	virtual void PostInit() = 0;
	virtual void Update(float frameTime) = 0;
	virtual void OnStartGame();
	virtual void SetLastSpawn(unsigned playerId, unsigned spawnId) = 0;
	virtual bool NetSerialize(TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags) = 0;
	virtual void AddSpawnLocation(unsigned location, bool isInitialSpawn, bool doVisTest, const char* pGroupName) = 0;
	virtual void RemoveSpawnLocation(unsigned id, bool isInitialSpawn) = 0;
	virtual void EnableSpawnLocation(unsigned location, bool isInitialSpawn, const char* pGroupName) = 0;
	virtual void DisableSpawnLocation(unsigned id, bool isInitialSpawn) = 0;
	virtual unsigned GetSpawnLocation(unsigned playerId) = 0;
	virtual unsigned GetFirstSpawnLocation(int teamId) const = 0;
	virtual int GetSpawnLocationCount() const = 0;
	virtual unsigned GetNthSpawnLocation(int idx) const = 0;
	virtual int GetSpawnIndexForEntityId(unsigned spawnId) const = 0;
	virtual void SetInitialSpawnGroup(const char* groupName) = 0;
	virtual void AddAvoidPOI(unsigned entityId, float avoidDistance, bool enabled, bool bStaticPOI) = 0;
	virtual void RemovePOI(unsigned entityId) = 0;
	virtual void EnablePOI(unsigned entityId) = 0;
	virtual void DisablePOI(unsigned entityId) = 0;
	virtual void PlayerJoined(unsigned playerId) = 0;
	virtual void PlayerLeft(unsigned playerId) = 0;
	virtual void OnPlayerKilled(const HitInfo& hitInfo) = 0;
	virtual void ClRequestRevive(unsigned playerId) = 0;
	virtual bool SvRequestRevive(unsigned playerId, unsigned preferredSpawnId) = 0;
	virtual void PerformRevive(unsigned playerId, int teamId, unsigned preferredSpawnId) = 0;
	virtual void OnSetTeam(unsigned playerId, int teamId) = 0;
	virtual const std::map<unsigned int, IGameRulesSpawningModule::SPlayerData>* GetPlayerValuesMap() const = 0;
	virtual void ReviveAllPlayers(bool isReset, bool bOnlyIfDead) = 0;
	virtual void ReviveAllPlayersOnTeam(int teamId);
	virtual int GetRemainingLives(unsigned playerId) = 0;
	virtual int GetNumLives() = 0;
	virtual float GetTimeFromDeathTillAutoReviveForTeam(int teamId) const = 0;
	virtual float GetPlayerAutoReviveAdditionalTime(IActor* pActor) const = 0;
	virtual float GetAutoReviveTimeScaleForTeam(int teamId) const = 0;
	virtual void SetAutoReviveTimeScaleForTeam(int teamId, float newScale) = 0;
	virtual void HostMigrationInsertIntoReviveQueue(unsigned playerId, float timeTillRevive) = 0;
	virtual void OnInGameBegin() = 0;
	virtual void OnInitialEquipmentScreenShown() = 0;
	virtual void OnNewRoundEquipmentScreenShown() = 0;
	virtual float GetRemainingInitialAutoSpawnTimer() = 0;
	virtual bool SvIsMidRoundJoiningAllowed() const = 0;
	virtual bool CanPlayerSpawnThisRound(const unsigned playerId) const = 0;
	virtual bool IsInInitialChannelsList(unsigned channelId) const = 0;
	virtual void HostMigrationStopAddingPlayers() = 0;
	virtual void HostMigrationResumeAddingPlayers() = 0;

#ifndef MOONCRASH
	static inline auto FOnStartGame = PreyFunction<void(IGameRulesSpawningModule* const _this)>(0xA13080);
	static inline auto FReviveAllPlayersOnTeam = PreyFunction<void(IGameRulesSpawningModule* const _this, int teamId)>(0xA13080);
#else
	static inline auto FOnStartGame = PreyFunction<void(IGameRulesSpawningModule* const _this)>(0x1333E90);
	static inline auto FReviveAllPlayersOnTeam = PreyFunction<void(IGameRulesSpawningModule* const _this, int teamId)>(0x1333E90);
#endif
};

