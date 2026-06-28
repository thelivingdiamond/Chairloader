// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_AnimatedBase.h>
#include <_unknown/ArkNpcCollisionObserver.h>

class ArkNpc;
class ArkNpcAnimAction;
struct ArkNpcBodyStateEnterParams_Lifted;
struct ArkNpcBodyStateExitParams;
struct ArkNpcBodyStateForceAnimFinishExitParams;
enum class EActionFailure;
struct EventPhysCollision;

// ArkNpcBodyState_Lifted
// Header:  Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Lifted.h
class ArkNpcBodyState_Lifted : public ArkNpcBodyState_AnimatedBase, public ArkNpcCollisionObserver
{ // Size=352 (0x160)
public:
	int m_liftedFragmentId;
	int m_bumpFragmentId;
	ArkNpcMovementDesire m_movementDesire;
	bool m_bBumpedHead;

	ArkNpcBodyState_Lifted();
	void Enter(const ArkNpcBodyStateEnterParams_Lifted& _params) { FEnter(this, _params); }
	void Exit(const ArkNpcBodyStateExitParams& _params) { FExitOv1(this, _params); }
	virtual void OnNpcAnimActionExit(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionFail(ArkNpcAnimAction& _animAction, EActionFailure _actionFailure);
	virtual void OnNpcCollision(ArkNpc& _npc, const EventPhysCollision& _collisionEvent);
	void OnAnimActionDone() { FOnAnimActionDone(this); }

#if 0
	void Exit(const ArkNpcBodyStateForceAnimFinishExitParams& _arg0_);
#endif

	static inline auto FArkNpcBodyState_Lifted = PreyFunction<void(ArkNpcBodyState_Lifted* const _this)>(0x12A38C0);
	static inline auto FEnter = PreyFunction<void(ArkNpcBodyState_Lifted* const _this, const ArkNpcBodyStateEnterParams_Lifted& _params)>(0x12A3930);
	static inline auto FExitOv1 = PreyFunction<void(ArkNpcBodyState_Lifted* const _this, const ArkNpcBodyStateExitParams& _params)>(0x12A39F0);
	static inline auto FOnNpcAnimActionExit = PreyFunction<void(ArkNpcBodyState_Lifted* const _this, ArkNpcAnimAction& _animAction)>(0x12A3B90);
	static inline auto FOnNpcAnimActionFail = PreyFunction<void(ArkNpcBodyState_Lifted* const _this, ArkNpcAnimAction& _animAction, EActionFailure _actionFailure)>(0x12A3B90);
	static inline auto FOnNpcCollision = PreyFunction<void(ArkNpcCollisionObserver* const _this, ArkNpc& _npc, const EventPhysCollision& _collisionEvent)>(0x12A3BA0);
	static inline auto FOnAnimActionDone = PreyFunction<void(ArkNpcBodyState_Lifted* const _this)>(0x12A3A90);
};
#endif // MOONCRASH
