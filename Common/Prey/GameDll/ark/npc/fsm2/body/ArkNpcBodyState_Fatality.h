// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_AnimatedBase.h>

struct ArkNpcBodyStateEnterParams_Fatality;
struct ArkNpcBodyStateExitParams;
struct ArkNpcBodyStateForceAnimFinishExitParams;

// ArkNpcBodyState_Fatality
// Header:  Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Fatality.h
class ArkNpcBodyState_Fatality : public ArkNpcBodyState_AnimatedBase
{ // Size=304 (0x130)
public:
	ArkNpcMovementDesire m_movementDesire;

	ArkNpcBodyState_Fatality();
	void Enter(const ArkNpcBodyStateEnterParams_Fatality& _params) { FEnter(this, _params); }
	void Exit(const ArkNpcBodyStateExitParams& _params) { FExitOv1(this, _params); }

#if 0
	void Exit(const ArkNpcBodyStateForceAnimFinishExitParams& _arg0_);
#endif

	static inline auto FArkNpcBodyState_Fatality = PreyFunction<void(ArkNpcBodyState_Fatality* const _this)>(0x12A35B0);
	static inline auto FEnter = PreyFunction<void(ArkNpcBodyState_Fatality* const _this, const ArkNpcBodyStateEnterParams_Fatality& _params)>(0x12A35F0);
	static inline auto FExitOv1 = PreyFunction<void(ArkNpcBodyState_Fatality* const _this, const ArkNpcBodyStateExitParams& _params)>(0x12A3650);
};
#endif // MOONCRASH
