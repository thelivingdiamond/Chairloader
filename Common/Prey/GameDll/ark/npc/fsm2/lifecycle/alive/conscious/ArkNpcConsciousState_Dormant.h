// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/ArkNpcAnimActionObserver.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <_unknown/ArkNpcConsciousState.h>

class ArkNpc;
class ArkNpcAnimAction;
class ArkNpcConsciousFsm;
struct ArkNpcConsciousStateEnterParams_Dormant;
struct ArkNpcConsciousStateExitParams;
struct ArkNpcConsciousStateSerializeParams;

// ArkNpcConsciousState_Dormant
// Header:  Prey/GameDll/ark/npc/fsm2/lifecycle/alive/conscious/ArkNpcConsciousState_Dormant.h
class ArkNpcConsciousState_Dormant : public ArkNpcConsciousState, public ArkNpcAnimActionObserver
{ // Size=488 (0x1E8)
public:
	ArkNpcMovementDesire m_movementDesire;
	ArkNpcFacingDesire m_facingDesire;
	Vec3 m_position;
	Quat m_rotation;
	float m_prevAttentionHearingGainModifier;
	float m_ragdollTimer;
	bool m_bRagdolled;

	ArkNpcConsciousState_Dormant();
	void Enter(const ArkNpcConsciousStateEnterParams_Dormant& _params) { FEnterOv1(this, _params); }
	void Enter(const ArkNpcConsciousStateSerializeParams& _params) { FEnterOv0(this, _params); }
	void Update(ArkNpc& _npc, ArkNpcConsciousFsm& _fsm, float _elapsedTime) { FUpdate(this, _npc, _fsm, _elapsedTime); }
	void Exit(const ArkNpcConsciousStateExitParams& _params) { FExit(this, _params); }
	void Serialize(ArkNpc& _npc, TSerialize _serializer) { FSerialize(this, _npc, _serializer); }
	virtual void OnNpcAnimFragmentStarted(ArkNpcAnimAction& _animAction);

	static inline auto FArkNpcConsciousState_Dormant = PreyFunction<void(ArkNpcConsciousState_Dormant* const _this)>(0x12A6550);
	static inline auto FEnterOv1 = PreyFunction<void(ArkNpcConsciousState_Dormant* const _this, const ArkNpcConsciousStateEnterParams_Dormant& _params)>(0x12A65C0);
	static inline auto FEnterOv0 = PreyFunction<void(ArkNpcConsciousState_Dormant* const _this, const ArkNpcConsciousStateSerializeParams& _params)>(0x12A67A0);
	static inline auto FUpdate = PreyFunction<void(ArkNpcConsciousState_Dormant* const _this, ArkNpc& _npc, ArkNpcConsciousFsm& _fsm, float _elapsedTime)>(0x12A6BD0);
	static inline auto FExit = PreyFunction<void(ArkNpcConsciousState_Dormant* const _this, const ArkNpcConsciousStateExitParams& _params)>(0x12A6900);
	static inline auto FSerialize = PreyFunction<void(ArkNpcConsciousState_Dormant* const _this, ArkNpc& _npc, TSerialize _serializer)>(0x12A6AD0);
	static inline auto FOnNpcAnimFragmentStarted = PreyFunction<void(ArkNpcConsciousState_Dormant* const _this, ArkNpcAnimAction& _animAction)>(0x12A6A60);
};
#endif // MOONCRASH
