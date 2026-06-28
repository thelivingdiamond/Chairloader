// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/ArkNpcConsciousState.h>

struct ArkNpcConsciousStateEnterParams_Alert;
struct ArkNpcConsciousStateExitParams;
struct ArkNpcConsciousStateSerializeParams;

// ArkNpcConsciousState_Alert
// Header:  Prey/GameDll/ark/npc/fsm2/lifecycle/alive/conscious/ArkNpcConsciousState_Alert.h
class ArkNpcConsciousState_Alert : public ArkNpcConsciousState
{ // Size=1 (0x1)
public:
	void Enter(const ArkNpcConsciousStateEnterParams_Alert& _params) { FEnterOv1(this, _params); }
	void Enter(const ArkNpcConsciousStateSerializeParams& _params) { FEnterOv0(this, _params); }
	void Exit(const ArkNpcConsciousStateExitParams& _params) { FExit(this, _params); }

	static inline auto FEnterOv1 = PreyFunction<void(ArkNpcConsciousState_Alert* const _this, const ArkNpcConsciousStateEnterParams_Alert& _params)>(0x12A6530);
	static inline auto FEnterOv0 = PreyFunction<void(ArkNpcConsciousState_Alert* const _this, const ArkNpcConsciousStateSerializeParams& _params)>(0x12A6530);
	static inline auto FExit = PreyFunction<void(ArkNpcConsciousState_Alert* const _this, const ArkNpcConsciousStateExitParams& _params)>(0x12A6540);
};
#endif // MOONCRASH
