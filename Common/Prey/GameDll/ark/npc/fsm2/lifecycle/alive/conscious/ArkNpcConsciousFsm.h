#ifndef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/fsm2/lifecycle/alive/conscious/ArkNpcConsciousFsmBase.h>

class ArkNpc;

// ArkNpcConsciousFsm
// Header:  Prey/GameDll/ark/npc/fsm2/lifecycle/alive/conscious/ArkNpcConsciousFsm.h
class ArkNpcConsciousFsm : public ArkNpcConsciousFsmBase_template_<void>
{ // Size=488 (0x1E8)
public:
	void Update(ArkNpc& _npc, float _elapsedTime) { FUpdate(this, _npc, _elapsedTime); }
	void Serialize(ArkNpc& _npc, TSerialize _serializer) { FSerialize(this, _npc, _serializer); }

	static inline auto FUpdate = PreyFunction<void(ArkNpcConsciousFsm* const _this, ArkNpc& _npc, float _elapsedTime)>(0x1216EB0);
	static inline auto FSerialize = PreyFunction<void(ArkNpcConsciousFsm* const _this, ArkNpc& _npc, TSerialize _serializer)>(0x1216E80);
};

#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/fsm2/lifecycle/alive/conscious/ArkNpcConsciousFsmBase.h>

class ArkNpc;

// ArkNpcConsciousFsm
// Header:  Prey/GameDll/ark/npc/fsm2/lifecycle/alive/conscious/ArkNpcConsciousFsm.h
class ArkNpcConsciousFsm : public ArkNpcConsciousFsmBase_template_<void>
{ // Size=496 (0x1F0)
public:
	void Update(ArkNpc& _npc, float _elapsedTime) { FUpdate(this, _npc, _elapsedTime); }
	void Serialize(ArkNpc& _npc, TSerialize _serializer) { FSerialize(this, _npc, _serializer); }

	static inline auto FUpdate = PreyFunction<void(ArkNpcConsciousFsm* const _this, ArkNpc& _npc, float _elapsedTime)>(0x12A6500);
	static inline auto FSerialize = PreyFunction<void(ArkNpcConsciousFsm* const _this, ArkNpc& _npc, TSerialize _serializer)>(0x12A64D0);
};

#endif // !MOONCRASH
