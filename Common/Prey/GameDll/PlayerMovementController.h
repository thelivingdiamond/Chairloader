// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/IMovementController.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/MovementTransitionsController.h>
#include <Prey/GameDll/ark/ArkCornerSmoother3D.h>
#include <Prey/GameDll/cornersmoother.h>
#include <_unknown/IActorMovementController.h>

class CExactPositioning;
class CPlayer;
class ICrySizer;
struct IExactPositioningListener;
struct SActorFrameMovementParams;
struct SExactPositioningTarget;
struct SGameObjectEvent;
struct SStanceState;
struct SStanceStateQuery;

// CPlayerMovementController
// Header:  Prey/GameDll/PlayerMovementController.h
class CPlayerMovementController : public IActorMovementController
{ // Size=4984 (0x1378)
public:
	CPlayer* m_pPlayer;
	CMovementRequest m_state;
	float m_desiredSpeed;
	float m_lastRotX;
	float m_lastRotZ;
	float m_timeTurningInSameDirZ;
	float m_timeTurningInSameDirX;
	bool m_atTarget;
	bool m_usingLookIK;
	bool m_usingAimIK;
	bool m_aimClamped;
	Vec3 m_lookTarget;
	Vec3 m_aimTarget;
	float m_animTargetSpeed;
	int m_animTargetSpeedCounter;
	Vec3 m_fireTarget;
	EStance m_targetStance;
	float m_lastReqTurnSpeed;
	bool m_wasTurning;
	SMovementState m_currentMovementState;
	CMovementTransitionsController m_movementTransitionsController;
	CCornerSmoother m_cornerSmoother;
	CornerSmoothing::CCornerSmoother2 m_cornerSmoother2;
	CArkCornerSmoother3D m_cornerSmoother3D;
	float m_zRotationRate;
	std::unique_ptr<CExactPositioning> m_pExactPositioning;

	CPlayerMovementController(CPlayer* pPlayer);
	virtual ~CPlayerMovementController();
	virtual void Reset();
	virtual void Update(float frameTime, SActorFrameMovementParams& params);
	virtual void PostUpdate(float frameTime);
	bool HandleEvent(const SGameObjectEvent& event) { return FHandleEvent(this, event); }
	virtual void Release();
	virtual void ApplyControllerAcceleration(float& xRot, float& zRot, float dt);
	virtual bool RequestMovement(CMovementRequest& request);
	virtual void GetMovementState(SMovementState& state);
	virtual bool GetStanceState(const SStanceStateQuery& query, SStanceState& state);
	virtual void Serialize(TSerialize& ser);
	virtual void GetMemoryUsage(ICrySizer* pSizer) const;
	virtual void SetExactPositioningListener(IExactPositioningListener* pExactPositioningListener);
	virtual const SExactPositioningTarget* GetExactPositioningTarget();
	virtual void CancelMovementTransition();
	virtual void BlockMovementTransitions();
	virtual void UnblockMovementTransitions();
	virtual void UpdateMovementState(SMovementState& state);

#if 0
	void UpdateSafeLine(const Vec3& _arg0_, const Vec3& _arg1_);
#endif

	static inline auto FCPlayerMovementController = PreyFunction<void(CPlayerMovementController* const _this, CPlayer* pPlayer)>(0x18D2C00);
	static inline auto FReset = PreyFunction<void(CPlayerMovementController* const _this)>(0x18D4E10);
	static inline auto FUpdate = PreyFunction<void(CPlayerMovementController* const _this, float frameTime, SActorFrameMovementParams& params)>(0x18D5480);
	static inline auto FPostUpdate = PreyFunction<void(CPlayerMovementController* const _this, float frameTime)>(0x18D4150);
	static inline auto FHandleEvent = PreyFunction<bool(CPlayerMovementController* const _this, const SGameObjectEvent& event)>(0x18D4130);
	static inline auto FRelease = PreyFunction<void(CPlayerMovementController* const _this)>(0x3E3960);
	static inline auto FApplyControllerAcceleration = PreyFunction<void(CPlayerMovementController* const _this, float& xRot, float& zRot, float dt)>(0x18D2F30);
	static inline auto FRequestMovement = PreyFunction<bool(CPlayerMovementController* const _this, CMovementRequest& request)>(0x18D4170);
	static inline auto FGetMovementState = PreyFunction<void(CPlayerMovementController* const _this, SMovementState& state)>(0x18D3570);
	static inline auto FGetStanceState = PreyFunction<bool(CPlayerMovementController* const _this, const SStanceStateQuery& query, SStanceState& state)>(0x18D3600);
	static inline auto FSerialize = PreyFunction<void(CPlayerMovementController* const _this, TSerialize& ser)>(0x18D4F40);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CPlayerMovementController* const _this, ICrySizer* pSizer)>(0x18D3550);
	static inline auto FSetExactPositioningListener = PreyFunction<void(CPlayerMovementController* const _this, IExactPositioningListener* pExactPositioningListener)>(0x18D53C0);
	static inline auto FGetExactPositioningTarget = PreyFunction<const SExactPositioningTarget* (CPlayerMovementController* const _this)>(0x18D3530);
	static inline auto FCancelMovementTransition = PreyFunction<void(CPlayerMovementController* const _this)>(0x18D3090);
	static inline auto FBlockMovementTransitions = PreyFunction<void(CPlayerMovementController* const _this)>(0x18D3080);
	static inline auto FUnblockMovementTransitions = PreyFunction<void(CPlayerMovementController* const _this)>(0x18D5470);
	static inline auto FUpdateMovementState = PreyFunction<void(CPlayerMovementController* const _this, SMovementState& state)>(0x18D9260);
};
#endif // MOONCRASH
