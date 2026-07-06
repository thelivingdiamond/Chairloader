// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <_unknown/ArkNightmareSpawnerFsmBase_template_.h>
#include <_unknown/ArkNightmareSpawnerFsmConfig.h>
#include <_unknown/ArkNightmareSpawnerState_Base.h>

class ArkNpc;
struct IEntity;
struct INightmareSpawnObserver;

// ArkNightmareSpawnerFsm
// Header:  Prey/GameDll/ark/npc/ArkNightmareSpawnerFsm.h
class ArkNightmareSpawnerFsm : public ArkNightmareSpawnerFsmBase_template_<void>
{ // Size=240 (0xF0)
public:
	ArkNightmareSpawnerFsmConfig m_config;
	std::vector<unsigned int> m_nightmareSpawners;
	std::unordered_set<INightmareSpawnObserver*> m_spawnObservers;
	string m_spawnedNightmareLevelName;
	unsigned m_spawnedNightmareEntityId;

	ArkNightmareSpawnerFsm();
	~ArkNightmareSpawnerFsm();
	void Initialize() { FInitialize(this); }
	void Terminate() { FTerminate(this); }
	void StartNightmareSpawning() { FStartNightmareSpawningOv1(this); }
	void StartNightmareSpawning(float _delay) { FStartNightmareSpawningOv0(this, _delay); }
	void Reset() { FReset(this); }
	void Update(float _frameTime) { FUpdate(this, _frameTime); }
	void FullSerialize(TSerialize _serializer) { FFullSerialize(this, _serializer); }
	void PostSerialize() { FPostSerialize(this); }
	void OnNewLevel() { FOnNewLevel(this); }
	void OnKilled() { FOnKilled(this); }
	void OnDissipated() { FOnDissipated(this); }
	bool IsNightmareSpawned() const { return FIsNightmareSpawned(this); }
	ArkNpc* GetNightmareNpc() const { return FGetNightmareNpc(this); }
	unsigned GetNightmareEntityId() const { return FGetNightmareEntityId(this); }
	const string& GetNightmareLevelName() const { return FGetNightmareLevelName(this); }
	void RegisterObserver(INightmareSpawnObserver& _observer) { FRegisterObserver(this, _observer); }
	void UnregisterObserver(INightmareSpawnObserver& _observer) { FUnregisterObserver(this, _observer); }
	void LoadConfig() { FLoadConfig(this); }
	void CacheCurrentLevelSpawners() { FCacheCurrentLevelSpawners(this); }

#if 0
	bool IsNightmareSpawning() const;
	IEntity* GetNightmareEntity() const;
	const ArkNightmareSpawnerFsmConfig& GetConfig() const;
	const std::vector<unsigned int>& GetNightmareSpawners() const;
	void OnNightmareSpawned(unsigned _arg0_);
	void ValidateSpawners();
#endif

	static inline auto FArkNightmareSpawnerFsmOv1 = PreyFunction<void(ArkNightmareSpawnerFsm* const _this)>(0x1282E90);
	static inline auto FBitNotArkNightmareSpawnerFsm = PreyFunction<void(ArkNightmareSpawnerFsm* const _this)>(0x1282F80);
	static inline auto FInitialize = PreyFunction<void(ArkNightmareSpawnerFsm* const _this)>(0x1283230);
	static inline auto FTerminate = PreyFunction<void(ArkNightmareSpawnerFsm* const _this)>(0x1283CB0);
	static inline auto FStartNightmareSpawningOv1 = PreyFunction<void(ArkNightmareSpawnerFsm* const _this)>(0x1283CA0);
	static inline auto FStartNightmareSpawningOv0 = PreyFunction<void(ArkNightmareSpawnerFsm* const _this, float _delay)>(0x1283C90);
	static inline auto FReset = PreyFunction<void(ArkNightmareSpawnerFsm* const _this)>(0x1283760);
	static inline auto FUpdate = PreyFunction<void(ArkNightmareSpawnerFsm* const _this, float _frameTime)>(0x1283E00);
	static inline auto FFullSerialize = PreyFunction<void(ArkNightmareSpawnerFsm* const _this, TSerialize _serializer)>(0x12830E0);
	static inline auto FPostSerialize = PreyFunction<void(ArkNightmareSpawnerFsm* const _this)>(0x1283720);
	static inline auto FOnNewLevel = PreyFunction<void(ArkNightmareSpawnerFsm* const _this)>(0x1283700);
	static inline auto FOnKilled = PreyFunction<void(ArkNightmareSpawnerFsm* const _this)>(0x1283690);
	static inline auto FOnDissipated = PreyFunction<void(ArkNightmareSpawnerFsm* const _this)>(0x1283620);
	static inline auto FIsNightmareSpawned = PreyFunction<bool(const ArkNightmareSpawnerFsm* const _this)>(0x12832A0);
	static inline auto FGetNightmareNpc = PreyFunction<ArkNpc* (const ArkNightmareSpawnerFsm* const _this)>(0x1283220);
	static inline auto FGetNightmareEntityId = PreyFunction<unsigned(const ArkNightmareSpawnerFsm* const _this)>(0x1283210);
	static inline auto FGetNightmareLevelName = PreyFunction<const string& (const ArkNightmareSpawnerFsm* const _this)>(0xE93620);
	static inline auto FRegisterObserver = PreyFunction<void(ArkNightmareSpawnerFsm* const _this, INightmareSpawnObserver& _observer)>(0x1283730);
	static inline auto FUnregisterObserver = PreyFunction<void(ArkNightmareSpawnerFsm* const _this, INightmareSpawnObserver& _observer)>(0x1283CC0);
	static inline auto FLoadConfig = PreyFunction<void(ArkNightmareSpawnerFsm* const _this)>(0x12832B0);
	static inline auto FCacheCurrentLevelSpawners = PreyFunction<void(ArkNightmareSpawnerFsm* const _this)>(0x1283020);
};

// ArkNightmareSpawnerState_SpawnNightmare
// Header:  Prey/GameDll/ark/npc/ArkNightmareSpawnerFsm.h
class ArkNightmareSpawnerState_SpawnNightmare : public ArkNightmareSpawnerState_Base
{ // Size=8 (0x8)
public:
	ArkAudioTrigger m_attentionAudioTrigger;
	float m_delay;

	bool SpawnNightmare(ArkNightmareSpawnerFsm& _fsm) { return FSpawnNightmare(this, _fsm); }

#if 0
	ArkNightmareSpawnerState_SpawnNightmare();
	~ArkNightmareSpawnerState_SpawnNightmare();
	void Enter(ArkNightmareSpawnerFsm& _arg0_);
	void Enter(float _arg0_);
	void Update(ArkNightmareSpawnerFsm& _arg0_, float _arg1_);
	void Serialize(ArkNightmareSpawnerFsm& _arg0_, TSerialize _arg1_);
#endif

	static inline auto FSpawnNightmare = PreyFunction<bool(ArkNightmareSpawnerState_SpawnNightmare* const _this, ArkNightmareSpawnerFsm& _fsm)>(0x12837B0);
};
#endif // MOONCRASH
