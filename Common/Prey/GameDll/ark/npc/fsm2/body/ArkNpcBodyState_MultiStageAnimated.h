// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_AnimatedBase.h>

struct ArkNpcBodyStateEnterParams_MultiStageAnimated;
struct ArkNpcBodyStateExitParams;
struct ArkNpcBodyStateForceAnimFinishExitParams;
class ArkNpcBodyStateObserver_MultiStageAnimated;

// ArkNpcBodyState_MultiStageAnimated
// Header:  Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_MultiStageAnimated.h
class ArkNpcBodyState_MultiStageAnimated : public ArkNpcBodyState_AnimatedBase
{ // Size=64 (0x40)
public:
	ArkNpcBodyStateObserver_MultiStageAnimated* m_pObserver;

	ArkNpcBodyState_MultiStageAnimated();
	void Enter(const ArkNpcBodyStateEnterParams_MultiStageAnimated& _params) { FEnter(this, _params); }
	void Exit(const ArkNpcBodyStateExitParams& _params) { FExitOv1(this, _params); }

#if 0
	void Exit(const ArkNpcBodyStateForceAnimFinishExitParams& _arg0_);
	void ExitAnimated();
#endif

#ifndef MOONCRASH
	static inline auto FArkNpcBodyState_MultiStageAnimated = PreyFunction<void(ArkNpcBodyState_MultiStageAnimated* const _this)>(0x1213640);
	static inline auto FEnter = PreyFunction<void(ArkNpcBodyState_MultiStageAnimated* const _this, const ArkNpcBodyStateEnterParams_MultiStageAnimated& _params)>(0x1213670);
	static inline auto FExitOv1 = PreyFunction<void(ArkNpcBodyState_MultiStageAnimated* const _this, const ArkNpcBodyStateExitParams& _params)>(0x1214B40);
#else
	static inline auto FArkNpcBodyState_MultiStageAnimated = PreyFunction<void(ArkNpcBodyState_MultiStageAnimated* const _this)>(0x12A2FA0);
	static inline auto FEnter = PreyFunction<void(ArkNpcBodyState_MultiStageAnimated* const _this, const ArkNpcBodyStateEnterParams_MultiStageAnimated& _params)>(0x12A2B30);
	static inline auto FExitOv1 = PreyFunction<void(ArkNpcBodyState_MultiStageAnimated* const _this, const ArkNpcBodyStateExitParams& _params)>(0x12A4120);
#endif
};

