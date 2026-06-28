// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_AnimatedBase.h>

struct ArkNpcBodyStateEnterParams_Landing;
struct ArkNpcBodyStateExitParams;
struct ArkNpcBodyStateForceAnimFinishExitParams;

// ArkNpcBodyState_Landing
// Header:  Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Landing.h
class ArkNpcBodyState_Landing : public ArkNpcBodyState_AnimatedBase
{ // Size=56 (0x38)
public:
	void Enter(const ArkNpcBodyStateEnterParams_Landing& _params) { FEnter(this, _params); }
	void Exit(const ArkNpcBodyStateExitParams& _params) { FExitOv1(this, _params); }

#if 0
	void Exit(const ArkNpcBodyStateForceAnimFinishExitParams& _arg0_);
#endif

	static inline auto FEnter = PreyFunction<void(ArkNpcBodyState_Landing* const _this, const ArkNpcBodyStateEnterParams_Landing& _params)>(0x12A3870);
	static inline auto FExitOv1 = PreyFunction<void(ArkNpcBodyState_Landing* const _this, const ArkNpcBodyStateExitParams& _params)>(0x12A3890);
};
#endif // MOONCRASH
