// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <_unknown/ArkNpcLifecycleFsmBase_template_.h>

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
#endif // MOONCRASH
