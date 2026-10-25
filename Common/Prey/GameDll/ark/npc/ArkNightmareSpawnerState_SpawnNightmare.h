// Moved out of ArkNightmareSpawnerFsm.h: ArkNightmareSpawnerFsmBase_template_ holds this state by value.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/ArkNightmareSpawnerState_Base.h>

class ArkNightmareSpawnerFsm;

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
