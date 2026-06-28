// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkRepairable.h>
#include <Prey/GameDll/ark/iface/IArkRepairableListener.h>
#include <_unknown/ArkNpcAliveState.h>

class ArkNpc;
class ArkNpcAliveFsm;
struct ArkNpcAliveStateEnterParams_Broken;
struct ArkNpcAliveStateExitParams;
struct ArkNpcAliveStateSerializeParams;

// ArkNpcAliveState_Broken
// Header:  Prey/GameDll/ark/npc/fsm2/lifecycle/alive/ArkNpcAliveState_Broken.h
class ArkNpcAliveState_Broken : public ArkNpcAliveState, public IArkRepairableListener
{ // Size=184 (0xB8)
public:
	ArkNpc* m_pNpc;
	ArkRepairable m_repairable;
	bool m_bRepair;

	ArkNpcAliveState_Broken();
	void Enter(const ArkNpcAliveStateEnterParams_Broken& _params) { FEnterOv1(this, _params); }
	void Enter(const ArkNpcAliveStateSerializeParams& _params) { FEnterOv0(this, _params); }
	void Exit(const ArkNpcAliveStateExitParams& _params) { FExit(this, _params); }
	void Update(ArkNpc& _npc, const ArkNpcAliveFsm& _fsm, float _elapsedTime) { FUpdate(this, _npc, _fsm, _elapsedTime); }
	void Serialize(ArkNpc& _npc, TSerialize _serializer) { FSerialize(this, _npc, _serializer); }
	void PostSerialize() { FPostSerialize(this); }
	virtual void OnBrokenChanged(bool _bBroken, bool _bWasForced);

	static inline auto FArkNpcAliveState_BrokenOv2 = PreyFunction<void(ArkNpcAliveState_Broken* const _this)>(0x12A5AB0);
	static inline auto FEnterOv1 = PreyFunction<void(ArkNpcAliveState_Broken* const _this, const ArkNpcAliveStateEnterParams_Broken& _params)>(0x12A5AF0);
	static inline auto FEnterOv0 = PreyFunction<void(ArkNpcAliveState_Broken* const _this, const ArkNpcAliveStateSerializeParams& _params)>(0x12A5B70);
	static inline auto FExit = PreyFunction<void(ArkNpcAliveState_Broken* const _this, const ArkNpcAliveStateExitParams& _params)>(0x12A5C10);
	static inline auto FUpdate = PreyFunction<void(ArkNpcAliveState_Broken* const _this, ArkNpc& _npc, const ArkNpcAliveFsm& _fsm, float _elapsedTime)>(0x12A5D50);
	static inline auto FSerialize = PreyFunction<void(ArkNpcAliveState_Broken* const _this, ArkNpc& _npc, TSerialize _serializer)>(0x12A5D00);
	static inline auto FPostSerialize = PreyFunction<void(ArkNpcAliveState_Broken* const _this)>(0x12A5CF0);
	static inline auto FOnBrokenChanged = PreyFunction<void(ArkNpcAliveState_Broken* const _this, bool _bBroken, bool _bWasForced)>(0x12A5C80);
};
#endif // MOONCRASH
