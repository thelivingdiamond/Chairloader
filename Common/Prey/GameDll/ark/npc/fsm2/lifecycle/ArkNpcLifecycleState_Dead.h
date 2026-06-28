// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/ArkNpcLifecycleState.h>

class ArkNpc;
struct ArkNpcLifecycleStateEnterParams_Dead;
struct ArkNpcLifecycleStateExitParams;
struct ArkNpcLifecycleStateSerializeParams;

// ArkNpcLifecycleState_Dead
// Header:  Prey/GameDll/ark/npc/fsm2/lifecycle/ArkNpcLifecycleState_Dead.h
class ArkNpcLifecycleState_Dead : public ArkNpcLifecycleState
{ // Size=1 (0x1)
public:
	void Enter(const ArkNpcLifecycleStateEnterParams_Dead& _params) { FEnterOv1(this, _params); }
	void Enter(const ArkNpcLifecycleStateSerializeParams& _params) { FEnterOv0(this, _params); }
	void Exit(const ArkNpcLifecycleStateExitParams& _params) { FExit(this, _params); }
	void PostSerialize(ArkNpc& _npc) { FPostSerialize(this, _npc); }

	static inline auto FEnterOv1 = PreyFunction<void(ArkNpcLifecycleState_Dead* const _this, const ArkNpcLifecycleStateEnterParams_Dead& _params)>(0x1333E90);
	static inline auto FEnterOv0 = PreyFunction<void(ArkNpcLifecycleState_Dead* const _this, const ArkNpcLifecycleStateSerializeParams& _params)>(0x1333E90);
	static inline auto FExit = PreyFunction<void(ArkNpcLifecycleState_Dead* const _this, const ArkNpcLifecycleStateExitParams& _params)>(0x1333E90);
	static inline auto FPostSerialize = PreyFunction<void(ArkNpcLifecycleState_Dead* const _this, ArkNpc& _npc)>(0x12A7840);
};
#endif // MOONCRASH
