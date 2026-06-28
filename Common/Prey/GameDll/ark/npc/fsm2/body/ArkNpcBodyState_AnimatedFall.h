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

// ArkNpcBodyStateEnterParams_AnimatedFall
// Header:  Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_AnimatedFall.h
struct ArkNpcBodyStateEnterParams_AnimatedFall : public ArkNpcBodyStateEnterParams_AnimatedBase
{ // Size=40 (0x28)
	const _smart_ptr<ArkNpcAnimAction>& m_pLandAnimAction;
	const float m_startZ;
	const float m_distanceForLandingAnim;

	ArkNpcBodyStateEnterParams_AnimatedFall(ArkNpc& _npc, ArkNpcBodyFsm& _fsm, const _smart_ptr<ArkNpcAnimAction>& _pFallAnimAction, const _smart_ptr<ArkNpcAnimAction>& _pLandAnimAction, float _startZ, float _distanceForLandingAnim);

	static inline auto FArkNpcBodyStateEnterParams_AnimatedFall = PreyFunction<void(ArkNpcBodyStateEnterParams_AnimatedFall* const _this, ArkNpc& _npc, ArkNpcBodyFsm& _fsm, const _smart_ptr<ArkNpcAnimAction>& _pFallAnimAction, const _smart_ptr<ArkNpcAnimAction>& _pLandAnimAction, float _startZ, float _distanceForLandingAnim)>(0x12A3120);
};

// ArkNpcBodyState_AnimatedFall
// Header:  Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_AnimatedFall.h
class ArkNpcBodyState_AnimatedFall : public ArkNpcBodyState_AnimatedBase
{ // Size=336 (0x150)
public:
	_smart_ptr<ArkNpcAnimAction> m_pLandAnimAction;
	float m_startZ;
	float m_distanceForLandingAnim;
	ArkNpcMovementDesire m_movementDesire;
	Vec3 m_prevPosition;
	float m_stuckTimer;

	ArkNpcBodyState_AnimatedFall();
	~ArkNpcBodyState_AnimatedFall();
	void Enter(const ArkNpcBodyStateEnterParams_AnimatedFall& _params) { FEnter(this, _params); }
	void Exit(const ArkNpcBodyStateExitParams& _params) { FExitOv1(this, _params); }
	void Update(ArkNpc& _npc, ArkNpcBodyFsm& _fsm, float _elapsedTime) { FUpdate(this, _npc, _fsm, _elapsedTime); }

#if 0
	void Exit(const ArkNpcBodyStateForceAnimFinishExitParams& _arg0_);
	void ExitToLanding(ArkNpc& _arg0_, ArkNpcBodyFsm& _arg1_) const;
	void UpdateFalling(ArkNpc& _arg0_, float _arg1_);
	void OnLanded(ArkNpc& _arg0_, ArkNpcBodyFsm& _arg1_);
#endif

	static inline auto FArkNpcBodyState_AnimatedFall = PreyFunction<void(ArkNpcBodyState_AnimatedFall* const _this)>(0x12A3160);
	static inline auto FBitNotArkNpcBodyState_AnimatedFall = PreyFunction<void(ArkNpcBodyState_AnimatedFall* const _this)>(0x12A31C0);
	static inline auto FEnter = PreyFunction<void(ArkNpcBodyState_AnimatedFall* const _this, const ArkNpcBodyStateEnterParams_AnimatedFall& _params)>(0x12A3210);
	static inline auto FExitOv1 = PreyFunction<void(ArkNpcBodyState_AnimatedFall* const _this, const ArkNpcBodyStateExitParams& _params)>(0x12A32D0);
	static inline auto FUpdate = PreyFunction<void(ArkNpcBodyState_AnimatedFall* const _this, ArkNpc& _npc, ArkNpcBodyFsm& _fsm, float _elapsedTime)>(0x12A3370);
};
#endif // MOONCRASH
