// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyStateEnterParams.h>

class ArkNpc;
class ArkNpcAnimAction;
class ArkNpcBodyFsm;

// ArkNpcBodyStateEnterParams_AnimatedBase
// Header:  _unknown/ArkNpcBodyStateEnterParams_AnimatedBase.h
struct ArkNpcBodyStateEnterParams_AnimatedBase : public ArkNpcBodyStateEnterParams
{ // Size=24 (0x18)
	ArkNpcBodyFsm& m_fsm;
	const _smart_ptr<ArkNpcAnimAction>& m_pAnimAction;

	ArkNpcBodyStateEnterParams_AnimatedBase(ArkNpc& _npc, ArkNpcBodyFsm& _fsm, const _smart_ptr<ArkNpcAnimAction>& _pAnimAction);

#ifndef MOONCRASH
	static inline auto FArkNpcBodyStateEnterParams_AnimatedBase = PreyFunction<void(ArkNpcBodyStateEnterParams_AnimatedBase* const _this, ArkNpc& _npc, ArkNpcBodyFsm& _fsm, const _smart_ptr<ArkNpcAnimAction>& _pAnimAction)>(0x11445D0);
#else
	static inline auto FArkNpcBodyStateEnterParams_AnimatedBase = PreyFunction<void(ArkNpcBodyStateEnterParams_AnimatedBase* const _this, ArkNpc& _npc, ArkNpcBodyFsm& _fsm, const _smart_ptr<ArkNpcAnimAction>& _pAnimAction)>(0x118B360);
#endif
};

