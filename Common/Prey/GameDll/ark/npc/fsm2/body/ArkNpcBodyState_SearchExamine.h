// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Animated.h>

struct ArkNpcBodyStateEnterParams_Animated;
struct ArkNpcBodyStateExitParams;
struct ArkNpcBodyStateForceAnimFinishExitParams;

// ArkNpcBodyState_SearchExamine
// Header:  Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_SearchExamine.h
class ArkNpcBodyState_SearchExamine : public ArkNpcBodyState_Animated
{ // Size=64 (0x40)
public:
	ArkNpcBodyState_SearchExamine();
	void Enter(const ArkNpcBodyStateEnterParams_Animated& _params) { FEnter(this, _params); }
	void Exit(const ArkNpcBodyStateExitParams& _params) { FExitOv1(this, _params); }

#if 0
	void Exit(const ArkNpcBodyStateForceAnimFinishExitParams& _arg0_);
#endif

	static inline auto FArkNpcBodyState_SearchExamine = PreyFunction<void(ArkNpcBodyState_SearchExamine* const _this)>(0x12A2EE0);
	static inline auto FEnter = PreyFunction<void(ArkNpcBodyState_SearchExamine* const _this, const ArkNpcBodyStateEnterParams_Animated& _params)>(0x12A50E0);
	static inline auto FExitOv1 = PreyFunction<void(ArkNpcBodyState_SearchExamine* const _this, const ArkNpcBodyStateExitParams& _params)>(0x12A50F0);
};
#endif // MOONCRASH
