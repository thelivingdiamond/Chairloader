// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/ArkNpcBodyState.h>

struct ArkNpcBodyStateEnterParams_Busy;
struct ArkNpcBodyStateExitParams;
class ArkNpcBodyStateObserver_Busy;

// ArkNpcBodyState_Busy
// Header:  Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Busy.h
class ArkNpcBodyState_Busy : public ArkNpcBodyState
{ // Size=8 (0x8)
public:
	ArkNpcBodyStateObserver_Busy* m_pObserver;

	ArkNpcBodyState_Busy();
	void Enter(const ArkNpcBodyStateEnterParams_Busy& _params) { FEnter(this, _params); }
	void Exit(const ArkNpcBodyStateExitParams& _params) { FExit(this, _params); }

	static inline auto FArkNpcBodyState_Busy = PreyFunction<void(ArkNpcBodyState_Busy* const _this)>(0x12A2F50);
	static inline auto FEnter = PreyFunction<void(ArkNpcBodyState_Busy* const _this, const ArkNpcBodyStateEnterParams_Busy& _params)>(0x12A2F60);
	static inline auto FExit = PreyFunction<void(ArkNpcBodyState_Busy* const _this, const ArkNpcBodyStateExitParams& _params)>(0x12A2F70);
};
#endif // MOONCRASH
