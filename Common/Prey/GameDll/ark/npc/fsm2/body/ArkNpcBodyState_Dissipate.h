// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_AnimatedBase.h>

struct ArkNpcBodyStateEnterParams_Dissipate;
struct ArkNpcBodyStateExitParams;
struct ArkNpcBodyStateForceAnimFinishExitParams;
class ArkNpcBodyStateObserver_Dissipate;

// ArkNpcBodyState_Dissipate
// Header:  Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Dissipate.h
class ArkNpcBodyState_Dissipate : public ArkNpcBodyState_AnimatedBase
{ // Size=64 (0x40)
public:
	ArkNpcBodyStateObserver_Dissipate* m_pObserver;

	ArkNpcBodyState_Dissipate();
	void Enter(const ArkNpcBodyStateEnterParams_Dissipate& _params) { FEnter(this, _params); }
	void Exit(const ArkNpcBodyStateExitParams& _params) { FExitOv1(this, _params); }

#if 0
	void Exit(const ArkNpcBodyStateForceAnimFinishExitParams& _arg0_);
#endif

	static inline auto FArkNpcBodyState_Dissipate = PreyFunction<void(ArkNpcBodyState_Dissipate* const _this)>(0x12A2FA0);
	static inline auto FEnter = PreyFunction<void(ArkNpcBodyState_Dissipate* const _this, const ArkNpcBodyStateEnterParams_Dissipate& _params)>(0x12A2FD0);
	static inline auto FExitOv1 = PreyFunction<void(ArkNpcBodyState_Dissipate* const _this, const ArkNpcBodyStateExitParams& _params)>(0x12A3010);
};
#endif // MOONCRASH
