#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/ArkNightmareSpawnerState_Base.h>

class ArkNightmareSpawnerFsm;

// ArkNightmareSpawnerState_SpawnEffects
// Header:  _unknown/ArkNightmareSpawnerState_SpawnEffects.h
class ArkNightmareSpawnerState_SpawnEffects : public ArkNightmareSpawnerState_Base
{ // Size=12 (0xC)
public:
	ArkAudioTrigger m_nightmareAudioTrigger;
	ArkAudioTrigger m_cameraShakeAudioTrigger;
	float m_delay;

#if 0
	ArkNightmareSpawnerState_SpawnEffects();
	~ArkNightmareSpawnerState_SpawnEffects();
	void Enter(ArkNightmareSpawnerFsm& _arg0_);
	void Update(ArkNightmareSpawnerFsm& _arg0_, float _arg1_);
	void Serialize(ArkNightmareSpawnerFsm& _arg0_, TSerialize _arg1_);
	void PostSpawnEffects(ArkNightmareSpawnerFsm& _arg0_);
#endif
};
#endif // MOONCRASH
