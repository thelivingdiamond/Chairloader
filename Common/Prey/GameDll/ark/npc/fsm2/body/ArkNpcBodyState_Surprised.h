// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcLookDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_AnimatedBase.h>

struct ArkNpcBodyStateEnterParams_Surprised;
struct ArkNpcBodyStateExitParams;
struct ArkNpcBodyStateForceAnimFinishExitParams;

// ArkNpcBodyState_Surprised
// Header:  Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Surprised.h
class ArkNpcBodyState_Surprised : public ArkNpcBodyState_AnimatedBase
{ // Size=696 (0x2B8)
public:
	ArkNpcFacingDesire m_facingDesire;
	ArkNpcLookDesire m_lookDesire;
	ArkNpcMovementDesire m_movementDesire;

	ArkNpcBodyState_Surprised();
	void Enter(const ArkNpcBodyStateEnterParams_Surprised& _params) { FEnter(this, _params); }
	void Exit(const ArkNpcBodyStateExitParams& _params) { FExitOv1(this, _params); }

#if 0
	void Exit(const ArkNpcBodyStateForceAnimFinishExitParams& _arg0_);
#endif

	static inline auto FArkNpcBodyState_Surprised = PreyFunction<void(ArkNpcBodyState_Surprised* const _this)>(0x12A5110);
	static inline auto FEnter = PreyFunction<void(ArkNpcBodyState_Surprised* const _this, const ArkNpcBodyStateEnterParams_Surprised& _params)>(0x12A5180);
	static inline auto FExitOv1 = PreyFunction<void(ArkNpcBodyState_Surprised* const _this, const ArkNpcBodyStateExitParams& _params)>(0x12A5380);
};
#endif // MOONCRASH
