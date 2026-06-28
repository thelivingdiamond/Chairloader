// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/fsm2/lifecycle/alive/conscious/ArkNpcConsciousFsm.h>
#include <_unknown/ArkNpcAliveState.h>

class ArkNpc;
class ArkNpcAliveFsm;
struct ArkNpcAliveStateEnterParams_Alert;
struct ArkNpcAliveStateEnterParams_Conscious;
struct ArkNpcAliveStateEnterParams_Dormant;
struct ArkNpcAliveStateExitParams;
struct ArkNpcAliveStateSerializeParams;

// ArkNpcAliveState_Conscious
// Header:  Prey/GameDll/ark/npc/fsm2/lifecycle/alive/ArkNpcAliveState_Conscious.h
class ArkNpcAliveState_Conscious : public ArkNpcAliveState
{ // Size=496 (0x1F0)
public:
	ArkNpcConsciousFsm m_fsm;

	void Enter(const ArkNpcAliveStateEnterParams_Alert& _params) { FEnterOv2(this, _params); }
	void Enter(const ArkNpcAliveStateSerializeParams& _params) { FEnterOv1(this, _params); }
	void Enter(const ArkNpcAliveStateEnterParams_Dormant& _params) { FEnterOv0(this, _params); }
	void Update(ArkNpc& _npc, ArkNpcAliveFsm& _fsm, float _elapsedTime) { FUpdate(this, _npc, _fsm, _elapsedTime); }
	void Exit(const ArkNpcAliveStateExitParams& _params) { FExit(this, _params); }
	bool BecomeAlert(ArkNpc& _npc) { return FBecomeAlert(this, _npc); }
	bool IsAlert() const { return FIsAlert(this); }
	bool IsDormant() const { return FIsDormant(this); }
	void Serialize(ArkNpc& _npc, TSerialize _serializer) { FSerialize(this, _npc, _serializer); }

#if 0
	bool BecomeDormant(ArkNpc& _arg0_, const Vec3& _arg1_, const Quat& _arg2_);
	void EnterConscious(const ArkNpcAliveStateEnterParams_Conscious& _arg0_);
#endif

	static inline auto FEnterOv2 = PreyFunction<void(ArkNpcAliveState_Conscious* const _this, const ArkNpcAliveStateEnterParams_Alert& _params)>(0x12A5DC0);
	static inline auto FEnterOv1 = PreyFunction<void(ArkNpcAliveState_Conscious* const _this, const ArkNpcAliveStateSerializeParams& _params)>(0x12A5F10);
	static inline auto FEnterOv0 = PreyFunction<void(ArkNpcAliveState_Conscious* const _this, const ArkNpcAliveStateEnterParams_Dormant& _params)>(0x12A5E50);
	static inline auto FUpdate = PreyFunction<void(ArkNpcAliveState_Conscious* const _this, ArkNpc& _npc, ArkNpcAliveFsm& _fsm, float _elapsedTime)>(0x12A61E0);
	static inline auto FExit = PreyFunction<void(ArkNpcAliveState_Conscious* const _this, const ArkNpcAliveStateExitParams& _params)>(0x12A6050);
	static inline auto FBecomeAlert = PreyFunction<bool(ArkNpcAliveState_Conscious* const _this, ArkNpc& _npc)>(0x12A5D60);
	static inline auto FIsAlert = PreyFunction<bool(const ArkNpcAliveState_Conscious* const _this)>(0x12A76C0);
	static inline auto FIsDormant = PreyFunction<bool(const ArkNpcAliveState_Conscious* const _this)>(0x12A76D0);
	static inline auto FSerialize = PreyFunction<void(ArkNpcAliveState_Conscious* const _this, ArkNpc& _npc, TSerialize _serializer)>(0x12A6100);
};
#endif // MOONCRASH
