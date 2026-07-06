// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_AnimatedBase.h>
#include <_unknown/ArkNpcBodyStateEnterParams_AnimatedBase.h>

class ArkNpc;
class ArkNpcAnimAction;
class ArkNpcBodyFsm;
struct ArkNpcBodyStateExitParams;
struct ArkNpcBodyStateForceAnimFinishExitParams;

// ArkNpcBodyStateEnterParams_HitReact
// Header:  Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_HitReact.h
struct ArkNpcBodyStateEnterParams_HitReact : public ArkNpcBodyStateEnterParams_AnimatedBase
{ // Size=32 (0x20)
	const bool m_bBlockMovement;

	ArkNpcBodyStateEnterParams_HitReact(ArkNpc& _npc, ArkNpcBodyFsm& _fsm, const _smart_ptr<ArkNpcAnimAction>& _pAnimAction, bool _bBlockMovement);

	static inline auto FArkNpcBodyStateEnterParams_HitReact = PreyFunction<void(ArkNpcBodyStateEnterParams_HitReact* const _this, ArkNpc& _npc, ArkNpcBodyFsm& _fsm, const _smart_ptr<ArkNpcAnimAction>& _pAnimAction, bool _bBlockMovement)>(0x12A3790);
};

// ArkNpcBodyState_HitReact
// Header:  Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_HitReact.h
class ArkNpcBodyState_HitReact : public ArkNpcBodyState_AnimatedBase
{ // Size=312 (0x138)
public:
	bool m_bBlockMovement;
	ArkNpcMovementDesire m_movementDesire;

	ArkNpcBodyState_HitReact();
	void Enter(const ArkNpcBodyStateEnterParams_HitReact& _params) { FEnter(this, _params); }
	void Exit(const ArkNpcBodyStateExitParams& _params) { FExitOv1(this, _params); }

#if 0
	void Exit(const ArkNpcBodyStateForceAnimFinishExitParams& _arg0_);
#endif

	static inline auto FArkNpcBodyState_HitReact = PreyFunction<void(ArkNpcBodyState_HitReact* const _this)>(0x12A37B0);
	static inline auto FEnter = PreyFunction<void(ArkNpcBodyState_HitReact* const _this, const ArkNpcBodyStateEnterParams_HitReact& _params)>(0x12A37F0);
	static inline auto FExitOv1 = PreyFunction<void(ArkNpcBodyState_HitReact* const _this, const ArkNpcBodyStateExitParams& _params)>(0x12A3830);
};
#endif // MOONCRASH
