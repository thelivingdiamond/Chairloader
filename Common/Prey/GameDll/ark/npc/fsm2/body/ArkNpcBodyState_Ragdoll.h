// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/ArkInterval.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcLookDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_AnimatedBase.h>
#include <_unknown/ArkNpcBodyStateEnterParams_AnimatedBase.h>
#include <_unknown/ArkNpcCollisionObserver.h>

class ArkNpc;
class ArkNpcAnimAction;
class ArkNpcBodyFsm;
struct ArkNpcBodyStateExitParams;
struct ArkNpcBodyStateForceAnimFinishExitParams;
enum class EActionFailure;
struct EventPhysCollision;

// ArkNpcBodyStateEnterParams_Ragdoll
// Header:  Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Ragdoll.h
struct ArkNpcBodyStateEnterParams_Ragdoll : public ArkNpcBodyStateEnterParams_AnimatedBase
{ // Size=40 (0x28)
	const _smart_ptr<ArkNpcAnimAction> m_pStandupAnimAction;
	const ArkInterval<float>* const m_pRagdollInterval;

	ArkNpcBodyStateEnterParams_Ragdoll(ArkNpc& _npc, ArkNpcBodyFsm& _fsm, const _smart_ptr<ArkNpcAnimAction>& _pRagdollAnimAction, const _smart_ptr<ArkNpcAnimAction>& _pStandupAnimAction);
	ArkNpcBodyStateEnterParams_Ragdoll(ArkNpc& _npc, ArkNpcBodyFsm& _fsm, const _smart_ptr<ArkNpcAnimAction>& _pRagdollAnimAction, const _smart_ptr<ArkNpcAnimAction>& _pStandupAnimAction, const ArkInterval<float>& _ragdollInterval);

	static inline auto FArkNpcBodyStateEnterParams_RagdollOv3 = PreyFunction<void(ArkNpcBodyStateEnterParams_Ragdoll* const _this, ArkNpc& _npc, ArkNpcBodyFsm& _fsm, const _smart_ptr<ArkNpcAnimAction>& _pRagdollAnimAction, const _smart_ptr<ArkNpcAnimAction>& _pStandupAnimAction)>(0x12A44B0);
	static inline auto FArkNpcBodyStateEnterParams_RagdollOv2 = PreyFunction<void(ArkNpcBodyStateEnterParams_Ragdoll* const _this, ArkNpc& _npc, ArkNpcBodyFsm& _fsm, const _smart_ptr<ArkNpcAnimAction>& _pRagdollAnimAction, const _smart_ptr<ArkNpcAnimAction>& _pStandupAnimAction, const ArkInterval<float>& _ragdollInterval)>(0x12A44F0);
};

// ArkNpcBodyStateSerializeParams_Ragdoll
// Header:  Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Ragdoll.h
struct ArkNpcBodyStateSerializeParams_Ragdoll : public ArkNpcBodyStateEnterParams_Ragdoll
{ // Size=48 (0x30)
	TSerialize& m_serializer;

	ArkNpcBodyStateSerializeParams_Ragdoll(ArkNpc& _npc, ArkNpcBodyFsm& _fsm, const _smart_ptr<ArkNpcAnimAction>& _pRagdollAnimAction, const _smart_ptr<ArkNpcAnimAction>& _pStandupAnimAction, TSerialize& _serializer);

	static inline auto FArkNpcBodyStateSerializeParams_RagdollOv2 = PreyFunction<void(ArkNpcBodyStateSerializeParams_Ragdoll* const _this, ArkNpc& _npc, ArkNpcBodyFsm& _fsm, const _smart_ptr<ArkNpcAnimAction>& _pRagdollAnimAction, const _smart_ptr<ArkNpcAnimAction>& _pStandupAnimAction, TSerialize& _serializer)>(0x12A4530);
};

// ArkNpcBodyState_Ragdoll
// Header:  Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Ragdoll.h
class ArkNpcBodyState_Ragdoll : public ArkNpcBodyState_AnimatedBase, public ArkNpcCollisionObserver
{ // Size=784 (0x310)
public:
	_smart_ptr<ArkNpcAnimAction> m_pStandupAnimAction;
	std::shared_ptr<CFragmentCache> m_pRequestedFragment;
	ArkInterval<float> m_ragdollInterval;
	ArkNpcMovementDesire m_ragdollMovementDesire;
	ArkNpcFacingDesire m_ragdollFacingDesire;
	ArkNpcLookDesire m_ragdollLookDesire;
	uint64_t m_indefiniteCount;
	bool m_bFrozen;
	float m_timer;
	float m_startZ;

	ArkNpcBodyState_Ragdoll();
	void Enter(const ArkNpcBodyStateEnterParams_Ragdoll& _params) { FEnterOv1(this, _params); }
	void Enter(const ArkNpcBodyStateSerializeParams_Ragdoll& _params) { FEnterOv0(this, _params); }
	void Exit(const ArkNpcBodyStateExitParams& _params) { FExitOv1(this, _params); }
	bool CanExit() const { return FCanExit(this); }
	void Update(ArkNpc& _npc, ArkNpcBodyFsm& _fsm, float _elaspedTime) { FUpdate(this, _npc, _fsm, _elaspedTime); }
	void PopIndefiniteRagdoll() { FPopIndefiniteRagdoll(this); }
	void ClearFrozen() { FClearFrozen(this); }
	bool IsStandingUp() const { return FIsStandingUp(this); }
	bool ShouldSerialize() const { return FShouldSerialize(this); }
	void Serialize(ArkNpc& _npc, TSerialize _serializer) { FSerialize(this, _npc, _serializer); }
	void PostSerialize(ArkNpc& _npc) { FPostSerialize(this, _npc); }
	virtual void OnNpcAnimActionExit(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionFail(ArkNpcAnimAction& _animAction, EActionFailure _actionFailure);
	virtual void OnNpcCollision(ArkNpc& _npc, const EventPhysCollision& _collisionEvent);
	void Restart(const ArkNpcBodyStateEnterParams_Ragdoll& _params) { FRestart(this, _params); }
	void OnAnimActionDone(ArkNpcAnimAction& _animAction) { FOnAnimActionDone(this, _animAction); }

#if 0
	void Exit(const ArkNpcBodyStateForceAnimFinishExitParams& _arg0_);
#endif

	static inline auto FArkNpcBodyState_Ragdoll = PreyFunction<void(ArkNpcBodyState_Ragdoll* const _this)>(0x12A4570);
	static inline auto FEnterOv1 = PreyFunction<void(ArkNpcBodyState_Ragdoll* const _this, const ArkNpcBodyStateEnterParams_Ragdoll& _params)>(0x12A4640);
	static inline auto FEnterOv0 = PreyFunction<void(ArkNpcBodyState_Ragdoll* const _this, const ArkNpcBodyStateSerializeParams_Ragdoll& _params)>(0x12A4700);
	static inline auto FExitOv1 = PreyFunction<void(ArkNpcBodyState_Ragdoll* const _this, const ArkNpcBodyStateExitParams& _params)>(0x12A4820);
	static inline auto FCanExit = PreyFunction<bool(const ArkNpcBodyState_Ragdoll* const _this)>(0x12A4620);
	static inline auto FUpdate = PreyFunction<void(ArkNpcBodyState_Ragdoll* const _this, ArkNpc& _npc, ArkNpcBodyFsm& _fsm, float _elaspedTime)>(0x12A4C10);
	static inline auto FPopIndefiniteRagdoll = PreyFunction<void(ArkNpcBodyState_Ragdoll* const _this)>(0x12A4AA0);
	static inline auto FClearFrozen = PreyFunction<void(ArkNpcBodyState_Ragdoll* const _this)>(0x12A4630);
	static inline auto FIsStandingUp = PreyFunction<bool(const ArkNpcBodyState_Ragdoll* const _this)>(0x12A4980);
	static inline auto FShouldSerialize = PreyFunction<bool(const ArkNpcBodyState_Ragdoll* const _this)>(0x12A4BF0);
	static inline auto FSerialize = PreyFunction<void(ArkNpcBodyState_Ragdoll* const _this, ArkNpc& _npc, TSerialize _serializer)>(0x12A4B10);
	static inline auto FPostSerialize = PreyFunction<void(ArkNpcBodyState_Ragdoll* const _this, ArkNpc& _npc)>(0x1333E90);
	static inline auto FOnNpcAnimActionExit = PreyFunction<void(ArkNpcBodyState_Ragdoll* const _this, ArkNpcAnimAction& _animAction)>(0x12A4A10);
	static inline auto FOnNpcAnimActionFail = PreyFunction<void(ArkNpcBodyState_Ragdoll* const _this, ArkNpcAnimAction& _animAction, EActionFailure _actionFailure)>(0x12A4A10);
	static inline auto FOnNpcCollision = PreyFunction<void(ArkNpcCollisionObserver* const _this, ArkNpc& _npc, const EventPhysCollision& _collisionEvent)>(0x12A4A20);
	static inline auto FRestart = PreyFunction<void(ArkNpcBodyState_Ragdoll* const _this, const ArkNpcBodyStateEnterParams_Ragdoll& _params)>(0x12A4AB0);
	static inline auto FOnAnimActionDone = PreyFunction<void(ArkNpcBodyState_Ragdoll* const _this, ArkNpcAnimAction& _animAction)>(0x12A49A0);
};
#endif // MOONCRASH
