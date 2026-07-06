// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_AnimatedBase.h>

struct ArkNpcBodyStateEnterParams_Animated;
struct ArkNpcBodyStateExitParams;
struct ArkNpcBodyStateForceAnimFinishExitParams;
class ArkNpcBodyStateObserver_Animated;

// ArkNpcBodyState_Animated
// Header:  Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Animated.h
class ArkNpcBodyState_Animated : public ArkNpcBodyState_AnimatedBase
{ // Size=64 (0x40)
public:
	ArkNpcBodyStateObserver_Animated* m_pObserver;

	ArkNpcBodyState_Animated();
	void Enter(const ArkNpcBodyStateEnterParams_Animated& _params) { FEnter(this, _params); }
	void Exit(const ArkNpcBodyStateExitParams& _params) { FExitOv1(this, _params); }
	void Exit(const ArkNpcBodyStateForceAnimFinishExitParams& _params) { FExitOv0(this, _params); }

#if 0
	void ExitAnimated();
#endif

	static inline auto FArkNpcBodyState_Animated = PreyFunction<void(ArkNpcBodyState_Animated* const _this)>(0x12A2FA0);
	static inline auto FEnter = PreyFunction<void(ArkNpcBodyState_Animated* const _this, const ArkNpcBodyStateEnterParams_Animated& _params)>(0x12A2B30);
	static inline auto FExitOv1 = PreyFunction<void(ArkNpcBodyState_Animated* const _this, const ArkNpcBodyStateExitParams& _params)>(0x12A2B60);
	static inline auto FExitOv0 = PreyFunction<void(ArkNpcBodyState_Animated* const _this, const ArkNpcBodyStateForceAnimFinishExitParams& _params)>(0x12A2BA0);
};
#endif // MOONCRASH
