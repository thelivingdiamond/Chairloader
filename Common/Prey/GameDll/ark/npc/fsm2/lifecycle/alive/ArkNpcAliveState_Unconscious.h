// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <_unknown/ArkNpcAliveState.h>

class ArkNpc;
class ArkNpcAliveFsm;
struct ArkNpcAliveStateEnterParams_Unconscious;
struct ArkNpcAliveStateExitParams;
struct ArkNpcAliveStateSerializeParams;

// ArkNpcAliveState_Unconscious
// Header:  Prey/GameDll/ark/npc/fsm2/lifecycle/alive/ArkNpcAliveState_Unconscious.h
class ArkNpcAliveState_Unconscious : public ArkNpcAliveState
{ // Size=1 (0x1)
public:
	bool m_bNeedsZeroGBoost;

	ArkNpcAliveState_Unconscious();
	void Enter(const ArkNpcAliveStateEnterParams_Unconscious& _params) { FEnterOv1(this, _params); }
	void Enter(const ArkNpcAliveStateSerializeParams& _params) { FEnterOv0(this, _params); }
	void Exit(const ArkNpcAliveStateExitParams& _params) { FExit(this, _params); }
	void Update(ArkNpc& _npc, ArkNpcAliveFsm& _fsm, float _elapsedTime) { FUpdate(this, _npc, _fsm, _elapsedTime); }
	void Serialize(ArkNpc& _npc, TSerialize _serializer) { FSerialize(this, _npc, _serializer); }

	static inline auto FArkNpcAliveState_Unconscious = PreyFunction<void(ArkNpcAliveState_Unconscious* const _this)>(0x18E26C0);
	static inline auto FEnterOv1 = PreyFunction<void(ArkNpcAliveState_Unconscious* const _this, const ArkNpcAliveStateEnterParams_Unconscious& _params)>(0x12A61F0);
	static inline auto FEnterOv0 = PreyFunction<void(ArkNpcAliveState_Unconscious* const _this, const ArkNpcAliveStateSerializeParams& _params)>(0x12A6290);
	static inline auto FExit = PreyFunction<void(ArkNpcAliveState_Unconscious* const _this, const ArkNpcAliveStateExitParams& _params)>(0x12A62F0);
	static inline auto FUpdate = PreyFunction<void(ArkNpcAliveState_Unconscious* const _this, ArkNpc& _npc, ArkNpcAliveFsm& _fsm, float _elapsedTime)>(0x12A6360);
	static inline auto FSerialize = PreyFunction<void(ArkNpcAliveState_Unconscious* const _this, ArkNpc& _npc, TSerialize _serializer)>(0x12A6310);
};
#endif // MOONCRASH
