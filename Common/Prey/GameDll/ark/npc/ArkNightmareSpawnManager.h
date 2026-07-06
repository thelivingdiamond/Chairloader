// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/ArkNightmareSpawnerFsm.h>
#include <_unknown/ArkNpcBodyStateObserver_Dissipate.h>
#include <_unknown/IArkDoomClockListener.h>
#include <_unknown/INightmareSpawnObserver.h>

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
#endif // MOONCRASH
