// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcLookDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <_unknown/ArkNpcBodyState.h>
#include <_unknown/ArkNpcBodyStateEnterParams.h>

class ArkNpc;
struct ArkNpcBodyStateExitParams;
class ArkNpcBodyStateObserver_Trackview;

// ArkNpcBodyStateEnterParams_Trackview
// Header:  Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Trackview.h
struct ArkNpcBodyStateEnterParams_Trackview : public ArkNpcBodyStateEnterParams
{ // Size=24 (0x18)
	bool m_bDisableVision;
	bool m_bDisableHearing;
	bool m_bInterruptable;
	ArkNpcBodyStateObserver_Trackview* const m_pObserver;

	ArkNpcBodyStateEnterParams_Trackview(ArkNpc& _npc, bool _bDisableVision, bool _bDisableHearing, bool _bInterruptable, ArkNpcBodyStateObserver_Trackview& _observer);

	static inline auto FArkNpcBodyStateEnterParams_Trackview = PreyFunction<void(ArkNpcBodyStateEnterParams_Trackview* const _this, ArkNpc& _npc, bool _bDisableVision, bool _bDisableHearing, bool _bInterruptable, ArkNpcBodyStateObserver_Trackview& _observer)>(0x12A5510);
};

// ArkNpcBodyState_Trackview
// Header:  Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Trackview.h
class ArkNpcBodyState_Trackview : public ArkNpcBodyState
{ // Size=656 (0x290)
public:
	bool m_bDisableVision;
	bool m_bDisableHearing;
	bool m_bInterruptable;
	ArkNpcBodyStateObserver_Trackview* m_pObserver;
	ArkNpcFacingDesire m_facingDesire;
	ArkNpcLookDesire m_lookDesire;
	ArkNpcMovementDesire m_movementDesire;

	ArkNpcBodyState_Trackview();
	void Enter(const ArkNpcBodyStateEnterParams_Trackview& _params) { FEnter(this, _params); }
	void Exit(const ArkNpcBodyStateExitParams& _params) { FExit(this, _params); }
	bool CanExit() const { return FCanExit(this); }

	static inline auto FArkNpcBodyState_TrackviewOv1 = PreyFunction<void(ArkNpcBodyState_Trackview* const _this)>(0x12A5530);
	static inline auto FEnter = PreyFunction<void(ArkNpcBodyState_Trackview* const _this, const ArkNpcBodyStateEnterParams_Trackview& _params)>(0x12A55B0);
	static inline auto FExit = PreyFunction<void(ArkNpcBodyState_Trackview* const _this, const ArkNpcBodyStateExitParams& _params)>(0x12A5700);
	static inline auto FCanExit = PreyFunction<bool(const ArkNpcBodyState_Trackview* const _this)>(0x12A55A0);
};
#endif // MOONCRASH
