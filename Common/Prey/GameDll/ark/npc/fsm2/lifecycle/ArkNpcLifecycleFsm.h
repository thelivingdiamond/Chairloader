#ifndef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/fsm2/lifecycle/ArkNpcLifecycleFsmBase.h>

class ArkNpc;

// ArkNpcLifecycleFsm
// Header:  Prey/GameDll/ark/npc/fsm2/lifecycle/ArkNpcLifecycleFsm.h
class ArkNpcLifecycleFsm : public ArkNpcLifecycleFsmBase_template_<void>
{ // Size=712 (0x2C8)
public:
	void Update(ArkNpc& _npc, float _elapsedTime) { FUpdate(this, _npc, _elapsedTime); }
	void Serialize(ArkNpc& _npc, TSerialize _serializer) { FSerialize(this, _npc, _serializer); }
	void PostSerialize(ArkNpc& _npc) { FPostSerialize(this, _npc); }

	static inline auto FUpdate = PreyFunction<void(ArkNpcLifecycleFsm* const _this, ArkNpc& _npc, float _elapsedTime)>(0x1217680);
	static inline auto FSerialize = PreyFunction<void(ArkNpcLifecycleFsm* const _this, ArkNpc& _npc, TSerialize _serializer)>(0x1217650);
	static inline auto FPostSerialize = PreyFunction<void(ArkNpcLifecycleFsm* const _this, ArkNpc& _npc)>(0x1217620);
};

#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/fsm2/lifecycle/ArkNpcLifecycleFsmBase.h>

class ArkNpc;

// ArkNpcLifecycleFsm
// Header:  Prey/GameDll/ark/npc/fsm2/lifecycle/ArkNpcLifecycleFsm.h
class ArkNpcLifecycleFsm : public ArkNpcLifecycleFsmBase_template_<void>
{ // Size=720 (0x2D0)
public:
	void Update(ArkNpc& _npc, float _elapsedTime) { FUpdate(this, _npc, _elapsedTime); }
	void Serialize(ArkNpc& _npc, TSerialize _serializer) { FSerialize(this, _npc, _serializer); }
	void PostSerialize(ArkNpc& _npc) { FPostSerialize(this, _npc); }

	static inline auto FUpdate = PreyFunction<void(ArkNpcLifecycleFsm* const _this, ArkNpc& _npc, float _elapsedTime)>(0x12A6CD0);
	static inline auto FSerialize = PreyFunction<void(ArkNpcLifecycleFsm* const _this, ArkNpc& _npc, TSerialize _serializer)>(0x12A6CA0);
	static inline auto FPostSerialize = PreyFunction<void(ArkNpcLifecycleFsm* const _this, ArkNpc& _npc)>(0x12A6C70);
};

#endif // !MOONCRASH
