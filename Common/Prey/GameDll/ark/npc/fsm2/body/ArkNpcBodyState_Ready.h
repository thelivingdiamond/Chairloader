// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState.h>

struct ArkNpcBodyStateEnterParams_Ready;
struct ArkNpcBodyStateExitParams;

// ArkNpcBodyState_Ready
// Header:  _unknown/ArkNpcBodyState_Ready.h
class ArkNpcBodyState_Ready : public ArkNpcBodyState
{ // Size=1 (0x1)
public:
	void Enter(const ArkNpcBodyStateEnterParams_Ready& _params) { FEnter(this, _params); }
	void Exit(const ArkNpcBodyStateExitParams& _params) { FExit(this, _params); }

#ifndef MOONCRASH
	static inline auto FEnter = PreyFunction<void(ArkNpcBodyState_Ready* const _this, const ArkNpcBodyStateEnterParams_Ready& _params)>(0xA13080);
	static inline auto FExit = PreyFunction<void(ArkNpcBodyState_Ready* const _this, const ArkNpcBodyStateExitParams& _params)>(0xA13080);
#else
	static inline auto FEnter = PreyFunction<void(ArkNpcBodyState_Ready* const _this, const ArkNpcBodyStateEnterParams_Ready& _params)>(0x1333E90);
	static inline auto FExit = PreyFunction<void(ArkNpcBodyState_Ready* const _this, const ArkNpcBodyStateExitParams& _params)>(0x1333E90);
#endif
};

