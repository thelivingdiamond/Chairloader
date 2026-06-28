// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/fsm2/lifecycle/alive/ArkNpcAliveFsm.h>
#include <_unknown/ArkNpcLifecycleState.h>

class ArkNpc;
class ArkNpcLifecycleFsm;
struct ArkNpcLifecycleStateEnterParams_Alert;
struct ArkNpcLifecycleStateEnterParams_Alive;
struct ArkNpcLifecycleStateEnterParams_Broken;
struct ArkNpcLifecycleStateEnterParams_Dormant;
struct ArkNpcLifecycleStateEnterParams_Unconscious;
struct ArkNpcLifecycleStateExitParams;
struct ArkNpcLifecycleStateSerializeParams;

// ArkNpcLifecycleState_Alive
// Header:  Prey/GameDll/ark/npc/fsm2/lifecycle/ArkNpcLifecycleState_Alive.h
class ArkNpcLifecycleState_Alive : public ArkNpcLifecycleState
{ // Size=704 (0x2C0)
public:
	ArkNpcAliveFsm m_fsm;

	void Enter(const ArkNpcLifecycleStateEnterParams_Alert& _params) { FEnterOv4(this, _params); }
	void Enter(const ArkNpcLifecycleStateEnterParams_Broken& _params) { FEnterOv3(this, _params); }
	void Enter(const ArkNpcLifecycleStateEnterParams_Dormant& _params) { FEnterOv2(this, _params); }
	void Enter(const ArkNpcLifecycleStateEnterParams_Unconscious& _params) { FEnterOv1(this, _params); }
	void Enter(const ArkNpcLifecycleStateSerializeParams& _params) { FEnterOv0(this, _params); }
	void Exit(const ArkNpcLifecycleStateExitParams& _params) { FExit(this, _params); }
	void Update(ArkNpc& _npc, const ArkNpcLifecycleFsm& _fsm, const float _elapsedTime) { FUpdate(this, _npc, _fsm, _elapsedTime); }
	bool BecomeAlert(ArkNpc& _npc) { return FBecomeAlert(this, _npc); }
	bool BecomeBroken(ArkNpc& _npc) { return FBecomeBroken(this, _npc); }
	bool BecomeUnconscious(ArkNpc& _npc) { return FBecomeUnconscious(this, _npc); }
	bool IsAlert() const { return FIsAlert(this); }
	bool IsBroken() const { return FIsBroken(this); }
	bool IsConscious() const { return FIsConscious(this); }
	bool IsDormant() const { return FIsDormant(this); }
	bool IsUnconscious() const { return FIsUnconscious(this); }
	void Serialize(ArkNpc& _npc, TSerialize _serializer) { FSerialize(this, _npc, _serializer); }
	void PostSerialize(ArkNpc& _npc) { FPostSerialize(this, _npc); }

#if 0
	bool BecomeDormant(ArkNpc& _arg0_, const Vec3& _arg1_, const Quat& _arg2_);
	void EnterAlive(const ArkNpcLifecycleStateEnterParams_Alive& _arg0_);
#endif

	static inline auto FEnterOv4 = PreyFunction<void(ArkNpcLifecycleState_Alive* const _this, const ArkNpcLifecycleStateEnterParams_Alert& _params)>(0x12A7140);
	static inline auto FEnterOv3 = PreyFunction<void(ArkNpcLifecycleState_Alive* const _this, const ArkNpcLifecycleStateEnterParams_Broken& _params)>(0x12A7200);
	static inline auto FEnterOv2 = PreyFunction<void(ArkNpcLifecycleState_Alive* const _this, const ArkNpcLifecycleStateEnterParams_Dormant& _params)>(0x12A72C0);
	static inline auto FEnterOv1 = PreyFunction<void(ArkNpcLifecycleState_Alive* const _this, const ArkNpcLifecycleStateEnterParams_Unconscious& _params)>(0x12A73A0);
	static inline auto FEnterOv0 = PreyFunction<void(ArkNpcLifecycleState_Alive* const _this, const ArkNpcLifecycleStateSerializeParams& _params)>(0x12A7470);
	static inline auto FExit = PreyFunction<void(ArkNpcLifecycleState_Alive* const _this, const ArkNpcLifecycleStateExitParams& _params)>(0x12A75C0);
	static inline auto FUpdate = PreyFunction<void(ArkNpcLifecycleState_Alive* const _this, ArkNpc& _npc, const ArkNpcLifecycleFsm& _fsm, const float _elapsedTime)>(0x12A7830);
	static inline auto FBecomeAlert = PreyFunction<bool(ArkNpcLifecycleState_Alive* const _this, ArkNpc& _npc)>(0x12A6E40);
	static inline auto FBecomeBroken = PreyFunction<bool(ArkNpcLifecycleState_Alive* const _this, ArkNpc& _npc)>(0x12A6F50);
	static inline auto FBecomeUnconscious = PreyFunction<bool(ArkNpcLifecycleState_Alive* const _this, ArkNpc& _npc)>(0x12A7040);
	static inline auto FIsAlert = PreyFunction<bool(const ArkNpcLifecycleState_Alive* const _this)>(0x12A7680);
	static inline auto FIsBroken = PreyFunction<bool(const ArkNpcLifecycleState_Alive* const _this)>(0x12A76C0);
	static inline auto FIsConscious = PreyFunction<bool(const ArkNpcLifecycleState_Alive* const _this)>(0x12A76D0);
	static inline auto FIsDormant = PreyFunction<bool(const ArkNpcLifecycleState_Alive* const _this)>(0x12A76E0);
	static inline auto FIsUnconscious = PreyFunction<bool(const ArkNpcLifecycleState_Alive* const _this)>(0x143DFE0);
	static inline auto FSerialize = PreyFunction<void(ArkNpcLifecycleState_Alive* const _this, ArkNpc& _npc, TSerialize _serializer)>(0x12A7730);
	static inline auto FPostSerialize = PreyFunction<void(ArkNpcLifecycleState_Alive* const _this, ArkNpc& _npc)>(0x12A7720);
};
#endif // MOONCRASH
