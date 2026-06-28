// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_AnimatedBase.h>

struct ArkNpcBodyStateEnterParams_GravShaft;
struct ArkNpcBodyStateExitParams;
struct ArkNpcBodyStateForceAnimFinishExitParams;

// ArkNpcBodyState_GravShaft
// Header:  Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_GravShaft.h
class ArkNpcBodyState_GravShaft : public ArkNpcBodyState_AnimatedBase
{ // Size=56 (0x38)
public:
	void Enter(const ArkNpcBodyStateEnterParams_GravShaft& _params) { FEnter(this, _params); }
	void Exit(const ArkNpcBodyStateExitParams& _params) { FExitOv1(this, _params); }

#if 0
	void Exit(const ArkNpcBodyStateForceAnimFinishExitParams& _arg0_);
#endif

	static inline auto FEnter = PreyFunction<void(ArkNpcBodyState_GravShaft* const _this, const ArkNpcBodyStateEnterParams_GravShaft& _params)>(0x12A36C0);
	static inline auto FExitOv1 = PreyFunction<void(ArkNpcBodyState_GravShaft* const _this, const ArkNpcBodyStateExitParams& _params)>(0x12A3720);
};
#endif // MOONCRASH
