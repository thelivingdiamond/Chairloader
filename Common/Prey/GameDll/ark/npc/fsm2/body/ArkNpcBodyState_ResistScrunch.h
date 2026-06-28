// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_AnimatedBase.h>

class ArkNpcAnimAction;
struct ArkNpcBodyStateEnterParams_ResistScrunch;
struct ArkNpcBodyStateExitParams;
struct ArkNpcBodyStateForceAnimFinishExitParams;
enum class EActionFailure;

// ArkNpcBodyState_ResistScrunch
// Header:  Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_ResistScrunch.h
class ArkNpcBodyState_ResistScrunch : public ArkNpcBodyState_AnimatedBase
{ // Size=472 (0x1D8)
public:
	ArkNpcFacingDesire m_facingDesire;
	ArkNpcMovementDesire m_movementDesire;

	ArkNpcBodyState_ResistScrunch();
	void Enter(const ArkNpcBodyStateEnterParams_ResistScrunch& _params) { FEnter(this, _params); }
	void Exit(const ArkNpcBodyStateExitParams& _params) { FExitOv1(this, _params); }
	virtual void OnNpcAnimActionExit(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionFail(ArkNpcAnimAction& _animAction, EActionFailure _actionFailure);
	void ExitToState() { FExitToState(this); }

#if 0
	void Exit(const ArkNpcBodyStateForceAnimFinishExitParams& _arg0_);
#endif

	static inline auto FArkNpcBodyState_ResistScrunch = PreyFunction<void(ArkNpcBodyState_ResistScrunch* const _this)>(0x12A4F10);
	static inline auto FEnter = PreyFunction<void(ArkNpcBodyState_ResistScrunch* const _this, const ArkNpcBodyStateEnterParams_ResistScrunch& _params)>(0x12A4F60);
	static inline auto FExitOv1 = PreyFunction<void(ArkNpcBodyState_ResistScrunch* const _this, const ArkNpcBodyStateExitParams& _params)>(0x12A4FA0);
	static inline auto FOnNpcAnimActionExit = PreyFunction<void(ArkNpcBodyState_ResistScrunch* const _this, ArkNpcAnimAction& _animAction)>(0x12A50D0);
	static inline auto FOnNpcAnimActionFail = PreyFunction<void(ArkNpcBodyState_ResistScrunch* const _this, ArkNpcAnimAction& _animAction, EActionFailure _actionFailure)>(0x12A50D0);
	static inline auto FExitToState = PreyFunction<void(ArkNpcBodyState_ResistScrunch* const _this)>(0x12A5040);
};
#endif // MOONCRASH
