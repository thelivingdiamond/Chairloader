// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_AnimatedBase.h>
#include <_unknown/ArkNpcCollisionObserver.h>

class ArkNpc;
struct ArkNpcBodyStateEnterParams_Rebound;
struct ArkNpcBodyStateExitParams;
struct ArkNpcBodyStateForceAnimFinishExitParams;
struct EventPhysCollision;

// ArkNpcBodyState_Rebound
// Header:  Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Rebound.h
class ArkNpcBodyState_Rebound : public ArkNpcBodyState_AnimatedBase, public ArkNpcCollisionObserver
{ // Size=344 (0x158)
public:
	ArkNpcMovementDesire m_movementDesire;
	bool m_bCollided;

	ArkNpcBodyState_Rebound();
	void Enter(const ArkNpcBodyStateEnterParams_Rebound& _params) { FEnter(this, _params); }
	void Exit(const ArkNpcBodyStateExitParams& _params) { FExitOv1(this, _params); }
	bool CanExitToFalling() const { return FCanExitToFalling(this); }
	virtual void OnNpcCollision(ArkNpc& _npc, const EventPhysCollision& _collisionEvent);

#if 0
	void Exit(const ArkNpcBodyStateForceAnimFinishExitParams& _arg0_);
#endif

	static inline auto FArkNpcBodyState_Rebound = PreyFunction<void(ArkNpcBodyState_Rebound* const _this)>(0x12A4D00);
	static inline auto FEnter = PreyFunction<void(ArkNpcBodyState_Rebound* const _this, const ArkNpcBodyStateEnterParams_Rebound& _params)>(0x12A4D60);
	static inline auto FExitOv1 = PreyFunction<void(ArkNpcBodyState_Rebound* const _this, const ArkNpcBodyStateExitParams& _params)>(0x12A4DA0);
	static inline auto FCanExitToFalling = PreyFunction<bool(const ArkNpcBodyState_Rebound* const _this)>(0x10E2580);
	static inline auto FOnNpcCollision = PreyFunction<void(ArkNpcCollisionObserver* const _this, ArkNpc& _npc, const EventPhysCollision& _collisionEvent)>(0x12A4E00);
};
#endif // MOONCRASH
