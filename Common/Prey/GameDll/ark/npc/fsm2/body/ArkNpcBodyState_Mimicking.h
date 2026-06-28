// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <_unknown/ArkNpcBodyState.h>
#include <_unknown/ArkNpcBodyStateEnterParams.h>

class ArkNpc;
class ArkNpcBodyFsm;
struct ArkNpcBodyStateExitParams;
enum class EArkNpcMovementDesireCallbackEvent;
struct IEntity;

// ArkNpcBodyStateEnterParams_Mimicking
// Header:  Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Mimicking.h
struct ArkNpcBodyStateEnterParams_Mimicking : public ArkNpcBodyStateEnterParams
{ // Size=32 (0x20)
	ArkNpcBodyFsm& m_fsm;
	const IEntity& m_mimickedEntity;
	const EArkNpcMimicryReason m_reason;

	ArkNpcBodyStateEnterParams_Mimicking(ArkNpc& _npc, ArkNpcBodyFsm& _fsm, const IEntity& _mimickedEntity, EArkNpcMimicryReason _reason);

	static inline auto FArkNpcBodyStateEnterParams_Mimicking = PreyFunction<void(ArkNpcBodyStateEnterParams_Mimicking* const _this, ArkNpc& _npc, ArkNpcBodyFsm& _fsm, const IEntity& _mimickedEntity, EArkNpcMimicryReason _reason)>(0x12A3E80);
};

// ArkNpcBodyState_Mimicking
// Header:  Prey/GameDll/ark/npc/fsm2/body/ArkNpcBodyState_Mimicking.h
class ArkNpcBodyState_Mimicking : public ArkNpcBodyState
{ // Size=296 (0x128)
public:
	ArkNpc* m_pNpc;
	ArkNpcBodyFsm* m_pFsm;
	unsigned m_mimickedEntityId;
	EArkNpcMimicryReason m_reason;
	ArkNpcMovementDesire m_movementDesire;
	bool m_bFrozen;
	boost::optional<Vec3_tpl<float> > m_optUnmimicPosition;

	ArkNpcBodyState_Mimicking();
	void Enter(const ArkNpcBodyStateEnterParams_Mimicking& _params) { FEnter(this, _params); }
	void Exit(const ArkNpcBodyStateExitParams& _params) { FExit(this, _params); }
	bool CanExit() const { return FCanExit(this); }
	EArkNpcMimicryReason GetReason() const { return FGetReason(this); }
	unsigned GetMimickedEntityId() const { return FGetMimickedEntityId(this); }
	void SetFrozen(bool _bFrozen) { FSetFrozen(this, _bFrozen); }
	void MovementDesireCallback(EArkNpcMovementDesireCallbackEvent _event) { FMovementDesireCallback(this, _event); }

	static inline auto FArkNpcBodyState_MimickingOv1 = PreyFunction<void(ArkNpcBodyState_Mimicking* const _this)>(0x12A3EA0);
	static inline auto FEnter = PreyFunction<void(ArkNpcBodyState_Mimicking* const _this, const ArkNpcBodyStateEnterParams_Mimicking& _params)>(0x12A3F40);
	static inline auto FExit = PreyFunction<void(ArkNpcBodyState_Mimicking* const _this, const ArkNpcBodyStateExitParams& _params)>(0x12A3FC0);
	static inline auto FCanExit = PreyFunction<bool(const ArkNpcBodyState_Mimicking* const _this)>(0x12A3F10);
	static inline auto FGetReason = PreyFunction<EArkNpcMimicryReason(const ArkNpcBodyState_Mimicking* const _this)>(0x11883D0);
	static inline auto FGetMimickedEntityId = PreyFunction<unsigned(const ArkNpcBodyState_Mimicking* const _this)>(0x387590);
	static inline auto FSetFrozen = PreyFunction<void(ArkNpcBodyState_Mimicking* const _this, bool _bFrozen)>(0x12A40F0);
	static inline auto FMovementDesireCallback = PreyFunction<void(ArkNpcBodyState_Mimicking* const _this, EArkNpcMovementDesireCallbackEvent _event)>(0x12A4060);
};
#endif // MOONCRASH
