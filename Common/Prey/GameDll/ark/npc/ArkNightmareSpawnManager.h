#ifndef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/npc/ArkNpcBodyStateObserver_Dissipate.h>
#include <Prey/CryAction/IViewSystem.h>

class ArkNpc;
class ArkNpcBodyState_Dissipate;
struct IEntityArchetype;
struct INightmareSpawnObserver;

// ArkNightmareSpawnManager
// Header:  Prey/GameDll/ark/npc/ArkNightmareSpawnManager.h
class ArkNightmareSpawnManager : public ArkNpcBodyStateObserver_Dissipate
{ // Size=312 (0x138)
public:
	enum class SpawnType
	{
		active = 0,
		passive = 1,
		set = 2,
	};

	// ArkNightmareSpawnManager::NightmareInfo
	// Header:  Prey/GameDll/ark/npc/ArkNightmareSpawnManager.h
	struct NightmareInfo
	{ // Size=16 (0x10)
		unsigned m_id;
		string m_levelName;

		NightmareInfo();

	#if 0
		void Serialize(TSerialize _arg0_);
		bool operator==(const ArkNightmareSpawnManager::NightmareInfo& _arg0_);
	#endif

		static inline auto FNightmareInfoOv2 = PreyFunction<void(ArkNightmareSpawnManager::NightmareInfo* const _this)>(0x11F42D0);
	};

	IEntityArchetype* m_pNightmareArchetype;
	ArkNightmareSpawnManager::NightmareInfo m_currentNightmare;
	std::vector<ArkNightmareSpawnManager::NightmareInfo> m_nightmaresToRemove;
	std::vector<string> m_noSpawningInLevels;
	std::vector<unsigned int> m_currentLevelNightmareSpawners;
	std::unordered_set<INightmareSpawnObserver*> m_spawnObservers;
	IView::SShakeParams m_cameraShakeParams;
	ArkAudioTrigger m_attentionAudioTrigger;
	ArkAudioTrigger m_nightmareAudioTrigger;
	ArkAudioTrigger m_cameraShakeAudioTrigger;
	ArkSimpleTimer m_spawnDelayTimer;
	ArkSimpleTimer m_postSpawnFxDelayTimer;
	float m_offscreenTimeRequiredToSpawn;
	float m_passiveSpawnTimer;
	float m_passiveInitialCooldownOnEnableInSeconds;
	float m_passiveCooldownOnCombatInSeconds;
	float m_passiveCooldownOnPassiveSpawnInSeconds;
	float m_respawnCooldownTimer;
	float m_respawnCooldownOnSpawnInSeconds;
	float m_respawnCooldownOnDeathInSeconds;
	float m_nightmareHeatSpawnThreshold;
	float m_currentNightmareHeat;
	float m_nightmareHeatLeakPerASecond;
	bool m_bEnabled;
	bool m_bTriedToSpawnNightmareOnCD;
	bool m_bShouldSpawnNightmare;
	bool m_bShouldPlayPostSpawnFx;
	bool m_bSpawningActively;
	bool m_bNeedsAttentionUpdate;
	bool m_bDelayedRemove;

	ArkNightmareSpawnManager();
	~ArkNightmareSpawnManager();
	virtual void OnNpcBodyStateStateExit_Dissipate(const ArkNpcBodyState_Dissipate& _state);
	void Initialize() { FInitialize(this); }
	void OnNewGame() { FOnNewGame(this); }
	void Reset(bool _bEnteringGameMode) { FReset(this, _bEnteringGameMode); }
	void Update(float _frameTime) { FUpdate(this, _frameTime); }
	void FullSerialize(TSerialize _serializer) { FFullSerialize(this, _serializer); }
	void PostSerialize() { FPostSerialize(this); }
	void OnLevelTransitionFinished() { FOnLevelTransitionFinished(this); }
	void Enable() { FEnable(this); }
	void Disable() { FDisable(this); }
	void OnNeuromodUsed(const uint64_t& _abilityId) { FOnNeuromodUsed(this, _abilityId); }
	void OnNightmareStartCombat(ArkNpc& _npc) { FOnNightmareStartCombat(this, _npc); }
	void OnNightmareStopCombat(ArkNpc& _npc) { FOnNightmareStopCombat(this, _npc); }
	void OnNpcDeath(ArkNpc& _npc) { FOnNpcDeath(this, _npc); }
	bool TrySpawnNightmare() { return FTrySpawnNightmare(this); }
	bool TryDespawnCurrentNightmare() { return FTryDespawnCurrentNightmare(this); }
	void TryIncreaseNightmareAttention() { FTryIncreaseNightmareAttention(this); }
	void SetCurrentNightmare(const unsigned _newNightmareId) { FSetCurrentNightmare(this, _newNightmareId); }
	bool TryDissipateCurrentNightmare() { return FTryDissipateCurrentNightmare(this); }
	bool TryDissipateNightmare(unsigned _nightmareEntityId) { return FTryDissipateNightmare(this, _nightmareEntityId); }
	unsigned GetCurrentNightmareId() const { return FGetCurrentNightmareId(this); }
	ArkNpc* GetCurrentNightmare() const { return FGetCurrentNightmare(this); }
	void IncreaseHeat(float _amount) { FIncreaseHeat(this, _amount); }
	void DecreaseHeat(float _amount) { FDecreaseHeat(this, _amount); }
	float GetHeat() const { return FGetHeat(this); }
	void ClearHeat() { FClearHeat(this); }
	void RegisterObserver(INightmareSpawnObserver& _observer) { FRegisterObserver(this, _observer); }
	void UnregisterObserver(INightmareSpawnObserver& _observer) { FUnregisterObserver(this, _observer); }
	void LoadXml() { FLoadXml(this); }
	void CacheCurrentLevelSpawners() { FCacheCurrentLevelSpawners(this); }
	void TryActiveSpawn() { FTryActiveSpawn(this); }
	bool IsNightmareAliveInCurrentLevel() const { return FIsNightmareAliveInCurrentLevel(this); }
	void SpawnNewNightmare() { FSpawnNewNightmare(this); }
	void UpdateNightmareAttention() { FUpdateNightmareAttention(this); }
	void CleanRemoveableNightmares() { FCleanRemoveableNightmares(this); }
	bool PlayerIsInBlacklistedLevel() const { return FPlayerIsInBlacklistedLevel(this); }
	void RemoveCurrentNightmare() { FRemoveCurrentNightmare(this); }

#if 0
	ArkNightmareSpawnManager(const ArkNightmareSpawnManager& _arg0_);
	bool IsEnabled() const;
	ArkNightmareSpawnManager& operator=(const ArkNightmareSpawnManager& _arg0_);
	void StartSpawning(bool _arg0_);
	void TryPassiveSpawn();
	void PlayPostSpawnEffects();
#endif

	static inline auto FArkNightmareSpawnManagerOv1 = PreyFunction<void(ArkNightmareSpawnManager* const _this)>(0x11F4170);
	static inline auto FBitNotArkNightmareSpawnManager = PreyFunction<void(ArkNightmareSpawnManager* const _this)>(0x11F4350);
	static inline auto FOnNpcBodyStateStateExit_Dissipate = PreyFunction<void(ArkNightmareSpawnManager* const _this, const ArkNpcBodyState_Dissipate& _state)>(0x11F5560);
	static inline auto FInitialize = PreyFunction<void(ArkNightmareSpawnManager* const _this)>(0x11F5500);
	static inline auto FOnNewGame = PreyFunction<void(ArkNightmareSpawnManager* const _this)>(0x11F5500);
	static inline auto FReset = PreyFunction<void(ArkNightmareSpawnManager* const _this, bool _bEnteringGameMode)>(0x11F57A0);
	static inline auto FUpdate = PreyFunction<void(ArkNightmareSpawnManager* const _this, float _frameTime)>(0x11F6170);
	static inline auto FFullSerialize = PreyFunction<void(ArkNightmareSpawnManager* const _this, TSerialize _serializer)>(0x11F47C0);
	static inline auto FPostSerialize = PreyFunction<void(ArkNightmareSpawnManager* const _this)>(0x11F5720);
	static inline auto FOnLevelTransitionFinished = PreyFunction<void(ArkNightmareSpawnManager* const _this)>(0x11F52B0);
	static inline auto FEnable = PreyFunction<void(ArkNightmareSpawnManager* const _this)>(0x11F47A0);
	static inline auto FDisable = PreyFunction<void(ArkNightmareSpawnManager* const _this)>(0x11F4750);
	static inline auto FOnNeuromodUsed = PreyFunction<void(ArkNightmareSpawnManager* const _this, const uint64_t& _abilityId)>(0x11F5360);
	static inline auto FOnNightmareStartCombat = PreyFunction<void(ArkNightmareSpawnManager* const _this, ArkNpc& _npc)>(0x11F5510);
	static inline auto FOnNightmareStopCombat = PreyFunction<void(ArkNightmareSpawnManager* const _this, ArkNpc& _npc)>(0x11F5510);
	static inline auto FOnNpcDeath = PreyFunction<void(ArkNightmareSpawnManager* const _this, ArkNpc& _npc)>(0x11F55A0);
	static inline auto FTrySpawnNightmare = PreyFunction<bool(ArkNightmareSpawnManager* const _this)>(0x11F6000);
	static inline auto FTryDespawnCurrentNightmare = PreyFunction<bool(ArkNightmareSpawnManager* const _this)>(0x11F5E60);
	static inline auto FTryIncreaseNightmareAttention = PreyFunction<void(ArkNightmareSpawnManager* const _this)>(0x11F5FD0);
	static inline auto FSetCurrentNightmare = PreyFunction<void(ArkNightmareSpawnManager* const _this, const unsigned _newNightmareId)>(0x11F5850);
	static inline auto FTryDissipateCurrentNightmare = PreyFunction<bool(ArkNightmareSpawnManager* const _this)>(0x11F5EB0);
	static inline auto FTryDissipateNightmare = PreyFunction<bool(ArkNightmareSpawnManager* const _this, unsigned _nightmareEntityId)>(0x11F5F60);
	static inline auto FGetCurrentNightmareId = PreyFunction<unsigned(const ArkNightmareSpawnManager* const _this)>(0x985E40);
	static inline auto FGetCurrentNightmare = PreyFunction<ArkNpc* (const ArkNightmareSpawnManager* const _this)>(0x11F4A70);
	static inline auto FIncreaseHeat = PreyFunction<void(ArkNightmareSpawnManager* const _this, float _amount)>(0x11F4AA0);
	static inline auto FDecreaseHeat = PreyFunction<void(ArkNightmareSpawnManager* const _this, float _amount)>(0x11F4730);
	static inline auto FGetHeat = PreyFunction<float(const ArkNightmareSpawnManager* const _this)>(0x11F4A90);
	static inline auto FClearHeat = PreyFunction<void(ArkNightmareSpawnManager* const _this)>(0x11F4720);
	static inline auto FRegisterObserver = PreyFunction<void(ArkNightmareSpawnManager* const _this, INightmareSpawnObserver& _observer)>(0x11F5740);
	static inline auto FUnregisterObserver = PreyFunction<void(ArkNightmareSpawnManager* const _this, INightmareSpawnObserver& _observer)>(0x11F6030);
	static inline auto FLoadXml = PreyFunction<void(ArkNightmareSpawnManager* const _this)>(0x11F4BA0);
	static inline auto FCacheCurrentLevelSpawners = PreyFunction<void(ArkNightmareSpawnManager* const _this)>(0x11F4510);
	static inline auto FTryActiveSpawn = PreyFunction<void(ArkNightmareSpawnManager* const _this)>(0x11F5D90);
	static inline auto FIsNightmareAliveInCurrentLevel = PreyFunction<bool(const ArkNightmareSpawnManager* const _this)>(0x11F4AD0);
	static inline auto FSpawnNewNightmare = PreyFunction<void(ArkNightmareSpawnManager* const _this)>(0x11F58D0);
	static inline auto FUpdateNightmareAttention = PreyFunction<void(ArkNightmareSpawnManager* const _this)>(0x11F63B0);
	static inline auto FCleanRemoveableNightmares = PreyFunction<void(ArkNightmareSpawnManager* const _this)>(0x11F45C0);
	static inline auto FPlayerIsInBlacklistedLevel = PreyFunction<bool(const ArkNightmareSpawnManager* const _this)>(0x11F5650);
	static inline auto FRemoveCurrentNightmare = PreyFunction<void(ArkNightmareSpawnManager* const _this)>(0x11F5770);
};

#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/ArkNightmareSpawnerFsm.h>
#include <Prey/GameDll/ark/npc/ArkNpcBodyStateObserver_Dissipate.h>
#include <Prey/GameDll/ark/IArkDoomClockListener.h>
#include <Prey/GameDll/ark/npc/INightmareSpawnObserver.h>

class ArkNpc;
class ArkNpcBodyState_Dissipate;

// ArkNightmareSpawnManager
// Header:  Prey/GameDll/ark/npc/ArkNightmareSpawnManager.h
class ArkNightmareSpawnManager
	: public IArkDoomClockListener
	, public INightmareSpawnObserver
	, public ArkNpcBodyStateObserver_Dissipate
{ // Size=312 (0x138)
public:
	// ArkNightmareSpawnManager::NightmareInfo
	// Header:  Prey/GameDll/ark/npc/ArkNightmareSpawnManager.h
	struct NightmareInfo
	{ // Size=16 (0x10)
		unsigned m_id;
		string m_levelName;

	#if 0
		NightmareInfo();
		NightmareInfo(unsigned _arg0_, const string& _arg1_);
		void Serialize(TSerialize _arg0_);
		bool operator==(const ArkNightmareSpawnManager::NightmareInfo& _arg0_);
	#endif
	};

	ArkNightmareSpawnerFsm m_fsm;
	std::vector<ArkNightmareSpawnManager::NightmareInfo> m_nightmaresToRemove;
	float m_onNewLevelSpawnDelay;
	float m_onDeathSpawnDelay;
	float m_onDissipatedSpawnDelay;
	int m_doomClockSpawnThreshold;
	float m_nightmareHealth;
	bool m_bNightmareAlive;
	bool m_bDoomclockThresholdTriggered;
	bool m_bDelayedRemoval;
	bool m_bEnabled;

	ArkNightmareSpawnManager();
	~ArkNightmareSpawnManager();
	void Initialize() { FInitialize(this); }
	void Reset(bool _bEnteringGameMode) { FReset(this, _bEnteringGameMode); }
	void Update(float _frameTime) { FUpdate(this, _frameTime); }
	void FullSerialize(TSerialize _serializer) { FFullSerialize(this, _serializer); }
	void PostSerialize() { FPostSerialize(this); }
	void OnNewGame() { FOnNewGame(this); }
	void OnLevelTransitionFinished() { FOnLevelTransitionFinished(this); }
	void OnSimulationReset() { FOnSimulationReset(this); }
	void Enable() { FEnable(this); }
	virtual void OnDoomClockIncrement(int _doomClockLevel);
	virtual void OnDoomClockPreIncrement(int _doomClockLevel);
	virtual void OnNightmareSpawned(ArkNpc& _nightmare);
	virtual void OnNightmareKilled(ArkNpc& _nightmare);
	virtual void OnNightmareDissipated(ArkNpc& _nightmare);
	virtual void OnNpcBodyStateStateExit_Dissipate(const ArkNpcBodyState_Dissipate& _state);
	void DissipateNightmare(ArkNpc& _nightmare) { FDissipateNightmare(this, _nightmare); }
	void DissipateCurrentNightmare() { FDissipateCurrentNightmare(this); }
	unsigned GetCurrentNightmareId() const { return FGetCurrentNightmareId(this); }
	ArkNpc* GetCurrentNightmare() const { return FGetCurrentNightmare(this); }
	void RegisterObserver(INightmareSpawnObserver& _observer) { FRegisterObserver(this, _observer); }
	void UnregisterObserver(INightmareSpawnObserver& _observer) { FUnregisterObserver(this, _observer); }
	void OnNpcDeath(ArkNpc& _npc) { FOnNpcDeath(this, _npc); }
	void CleanRemoveableNightmares() { FCleanRemoveableNightmares(this); }
	void OnNightmareDespawned() { FOnNightmareDespawned(this); }

#if 0
	bool IsEnabled() const;
	void RemoveCurrentNightmare();
	void TryStartSpawningNightmare();
	void TryStartSpawningNightmare(float _arg0_);
#endif

	static inline auto FArkNightmareSpawnManagerOv1 = PreyFunction<void(ArkNightmareSpawnManager* const _this)>(0x1281B30);
	static inline auto FBitNotArkNightmareSpawnManager = PreyFunction<void(ArkNightmareSpawnManager* const _this)>(0x1281BC0);
	static inline auto FInitialize = PreyFunction<void(ArkNightmareSpawnManager* const _this)>(0x1281EF0);
	static inline auto FReset = PreyFunction<void(ArkNightmareSpawnManager* const _this, bool _bEnteringGameMode)>(0x12823B0);
	static inline auto FUpdate = PreyFunction<void(ArkNightmareSpawnManager* const _this, float _frameTime)>(0x1282470);
	static inline auto FFullSerialize = PreyFunction<void(ArkNightmareSpawnManager* const _this, TSerialize _serializer)>(0x1281DF0);
	static inline auto FPostSerialize = PreyFunction<void(ArkNightmareSpawnManager* const _this)>(0x1282390);
	static inline auto FOnNewGame = PreyFunction<void(ArkNightmareSpawnManager* const _this)>(0x12821B0);
	static inline auto FOnLevelTransitionFinished = PreyFunction<void(ArkNightmareSpawnManager* const _this)>(0x1282120);
	static inline auto FOnSimulationReset = PreyFunction<void(ArkNightmareSpawnManager* const _this)>(0x1282380);
	static inline auto FEnable = PreyFunction<void(ArkNightmareSpawnManager* const _this)>(0x1281DE0);
	static inline auto FOnDoomClockIncrement = PreyFunction<void(ArkNightmareSpawnManager* const _this, int _doomClockLevel)>(0x12820E0);
	static inline auto FOnDoomClockPreIncrement = PreyFunction<void(ArkNightmareSpawnManager* const _this, int _doomClockLevel)>(0x1333E90);
	static inline auto FOnNightmareSpawned = PreyFunction<void(INightmareSpawnObserver* const _this, ArkNpc& _nightmare)>(0x1282240);
	static inline auto FOnNightmareKilled = PreyFunction<void(INightmareSpawnObserver* const _this, ArkNpc& _nightmare)>(0x1333E90);
	static inline auto FOnNightmareDissipated = PreyFunction<void(INightmareSpawnObserver* const _this, ArkNpc& _nightmare)>(0x1333E90);
	static inline auto FOnNpcBodyStateStateExit_Dissipate = PreyFunction<void(ArkNpcBodyStateObserver_Dissipate* const _this, const ArkNpcBodyState_Dissipate& _state)>(0x1282290);
	static inline auto FDissipateNightmare = PreyFunction<void(ArkNightmareSpawnManager* const _this, ArkNpc& _nightmare)>(0x1281DC0);
	static inline auto FDissipateCurrentNightmare = PreyFunction<void(ArkNightmareSpawnManager* const _this)>(0x1281D80);
	static inline auto FGetCurrentNightmareId = PreyFunction<unsigned(const ArkNightmareSpawnManager* const _this)>(0x1281EE0);
	static inline auto FGetCurrentNightmare = PreyFunction<ArkNpc* (const ArkNightmareSpawnManager* const _this)>(0x1281ED0);
	static inline auto FRegisterObserver = PreyFunction<void(ArkNightmareSpawnManager* const _this, INightmareSpawnObserver& _observer)>(0x12823A0);
	static inline auto FUnregisterObserver = PreyFunction<void(ArkNightmareSpawnManager* const _this, INightmareSpawnObserver& _observer)>(0x1282460);
	static inline auto FOnNpcDeath = PreyFunction<void(ArkNightmareSpawnManager* const _this, ArkNpc& _npc)>(0x1282310);
	static inline auto FCleanRemoveableNightmares = PreyFunction<void(ArkNightmareSpawnManager* const _this)>(0x1281C50);
	static inline auto FOnNightmareDespawned = PreyFunction<void(ArkNightmareSpawnManager* const _this)>(0x12821D0);
};

#endif // !MOONCRASH
