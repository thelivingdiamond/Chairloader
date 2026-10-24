// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ArkNpcAnimActionObserver.h>
#include <Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState.h>

class ArkNpc;
class ArkNpcAnimAction;
class ArkNpcBodyFsm;
struct ArkNpcBodyStateEnterParams_AnimatedBase;
struct ArkNpcBodyStateExitParams;
struct ArkNpcBodyStateForceAnimFinishExitParams;
enum class EActionFailure;

// ArkNpcBodyState_AnimatedBase
// Header:  Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_AnimatedBase.h
class ArkNpcBodyState_AnimatedBase : public ArkNpcBodyState, public ArkNpcAnimActionObserver
{ // Size=56 (0x38)
public:
	ArkNpc* m_pNpc;
	ArkNpcBodyFsm* m_pFsm;
	_smart_ptr<ArkNpcAnimAction> m_pAnimAction;

	void Enter(const ArkNpcBodyStateEnterParams_AnimatedBase& _params) { FEnter(this, _params); }
	void Exit(const ArkNpcBodyStateExitParams& _params) { FExitOv1(this, _params); }
	void Exit(const ArkNpcBodyStateForceAnimFinishExitParams& _params) { FExitOv0(this, _params); }
	const _smart_ptr<ArkNpcAnimAction>& GetAnimAction() const { return FGetAnimAction(this); }
	virtual void OnNpcAnimActionExit(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionFail(ArkNpcAnimAction& _animAction, EActionFailure _actionFailure);
	ArkNpcBodyState_AnimatedBase();
	~ArkNpcBodyState_AnimatedBase();
	void ExitToReady() { FExitToReady(this); }

#if 0
	ArkNpc& GetNpc() const;
	ArkNpcBodyFsm& GetFsm() const;
#endif

#ifdef MOONCRASH
	ArkNpc& GetNpc() const { return FGetNpc(this); }
#endif
#ifndef MOONCRASH
	static inline auto FEnter = PreyFunction<void(ArkNpcBodyState_AnimatedBase* const _this, const ArkNpcBodyStateEnterParams_AnimatedBase& _params)>(0x12137A0);
	static inline auto FExitOv1 = PreyFunction<void(ArkNpcBodyState_AnimatedBase* const _this, const ArkNpcBodyStateExitParams& _params)>(0x1213840);
	static inline auto FExitOv0 = PreyFunction<void(ArkNpcBodyState_AnimatedBase* const _this, const ArkNpcBodyStateForceAnimFinishExitParams& _params)>(0x12138F0);
	static inline auto FGetAnimAction = PreyFunction<const _smart_ptr<ArkNpcAnimAction>& (const ArkNpcBodyState_AnimatedBase* const _this)>(0x12BDA00);
	static inline auto FOnNpcAnimActionExit = PreyFunction<void(ArkNpcBodyState_AnimatedBase* const _this, ArkNpcAnimAction& _animAction)>(0x12139D0);
	static inline auto FOnNpcAnimActionFail = PreyFunction<void(ArkNpcBodyState_AnimatedBase* const _this, ArkNpcAnimAction& _animAction, EActionFailure _actionFailure)>(0x12139D0);
	static inline auto FArkNpcBodyState_AnimatedBase = PreyFunction<void(ArkNpcBodyState_AnimatedBase* const _this)>(0x12136E0);
	static inline auto FBitNotArkNpcBodyState_AnimatedBase = PreyFunction<void(ArkNpcBodyState_AnimatedBase* const _this)>(0x1213710);
	static inline auto FExitToReady = PreyFunction<void(ArkNpcBodyState_AnimatedBase* const _this)>(0x1213950);
#else
	static inline auto FEnter = PreyFunction<void(ArkNpcBodyState_AnimatedBase* const _this, const ArkNpcBodyStateEnterParams_AnimatedBase& _params)>(0x12A2CA0);
	static inline auto FExitOv1 = PreyFunction<void(ArkNpcBodyState_AnimatedBase* const _this, const ArkNpcBodyStateExitParams& _params)>(0x12A2D40);
	static inline auto FExitOv0 = PreyFunction<void(ArkNpcBodyState_AnimatedBase* const _this, const ArkNpcBodyStateForceAnimFinishExitParams& _params)>(0x12A2DF0);
	static inline auto FGetNpc = PreyFunction<ArkNpc& (const ArkNpcBodyState_AnimatedBase* const _this)>(0xD77240);
	static inline auto FGetAnimAction = PreyFunction<const _smart_ptr<ArkNpcAnimAction>& (const ArkNpcBodyState_AnimatedBase* const _this)>(0x1368F90);
	static inline auto FOnNpcAnimActionExit = PreyFunction<void(ArkNpcBodyState_AnimatedBase* const _this, ArkNpcAnimAction& _animAction)>(0x12A2ED0);
	static inline auto FOnNpcAnimActionFail = PreyFunction<void(ArkNpcBodyState_AnimatedBase* const _this, ArkNpcAnimAction& _animAction, EActionFailure _actionFailure)>(0x12A2ED0);
	static inline auto FArkNpcBodyState_AnimatedBase = PreyFunction<void(ArkNpcBodyState_AnimatedBase* const _this)>(0x12A2BE0);
	static inline auto FBitNotArkNpcBodyState_AnimatedBase = PreyFunction<void(ArkNpcBodyState_AnimatedBase* const _this)>(0x12A2C10);
	static inline auto FExitToReady = PreyFunction<void(ArkNpcBodyState_AnimatedBase* const _this)>(0x12A2E50);
#endif
};

