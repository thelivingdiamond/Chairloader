// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_AnimatedBase.h>

struct ArkNpcBodyStateEnterParams_Resist;
struct ArkNpcBodyStateExitParams;
struct ArkNpcBodyStateForceAnimFinishExitParams;

// ArkNpcBodyState_Resist
// Header:  Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Resist.h
class ArkNpcBodyState_Resist : public ArkNpcBodyState_AnimatedBase
{ // Size=472 (0x1D8)
public:
	ArkNpcFacingDesire m_facingDesire;
	ArkNpcMovementDesire m_movementDesire;

	ArkNpcBodyState_Resist();
	void Enter(const ArkNpcBodyStateEnterParams_Resist& _params) { FEnter(this, _params); }
	void Exit(const ArkNpcBodyStateExitParams& _params) { FExitOv1(this, _params); }

#if 0
	void Exit(const ArkNpcBodyStateForceAnimFinishExitParams& _arg0_);
#endif

	static inline auto FArkNpcBodyState_Resist = PreyFunction<void(ArkNpcBodyState_Resist* const _this)>(0x12A4E80);
	static inline auto FEnter = PreyFunction<void(ArkNpcBodyState_Resist* const _this, const ArkNpcBodyStateEnterParams_Resist& _params)>(0x12A4F60);
	static inline auto FExitOv1 = PreyFunction<void(ArkNpcBodyState_Resist* const _this, const ArkNpcBodyStateExitParams& _params)>(0x12A4ED0);
};
#endif // MOONCRASH
