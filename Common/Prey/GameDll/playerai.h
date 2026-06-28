// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ICryMannequinUserParams.h>
#include <Prey/GameDll/AnimActionAIDetail.h>
#include <_unknown/TMannequinAutoInit.h>

class CAnimActionAIDetail;
class CAnimActionAIMovement;
class CArkAnimActionAIBlink;
class CPlayer;
class CTagDefinition;
class IActionController;
struct IScriptTable;
struct ISkeletonPose;
struct SActorFrameMovementParams;
struct SAnimActionAIMovementSettings;
struct SAnimationContext;
struct SControllerDef;
struct SMannequinAIStateParams;

// CAIAnimationState
// Header:  Prey/GameDll/playerai.h
class CAIAnimationState
{ // Size=32 (0x20)
public:
	SAnimationContext* m_pContext;
	const SMannequinAIStateParams* m_pAiUserParams;
	EStance m_requestedStance;
	EStance m_stance;
	float m_pseudoSpeed;

	void SetRequestedStance(const EStance stance) { FSetRequestedStance(this, stance); }
	EStance GetRequestedStance() const { return FGetRequestedStance(this); }
	void SetStance(const EStance stance) { FSetStance(this, stance); }
	EStance GetStance() const { return FGetStance(this); }

#if 0
	CAIAnimationState();
	~CAIAnimationState();
	void Init(SAnimationContext* _arg0_);
	void Reset();
	void SetPseudoSpeed(float _arg0_);
	float GetPseudoSpeed() const;
#endif

	static inline auto FSetRequestedStance = PreyFunction<void(CAIAnimationState* const _this, const EStance stance)>(0x7CA210);
	static inline auto FGetRequestedStance = PreyFunction<EStance(const CAIAnimationState* const _this)>(0x387590);
	static inline auto FSetStance = PreyFunction<void(CAIAnimationState* const _this, const EStance stance)>(0x18CFE20);
	static inline auto FGetStance = PreyFunction<EStance(const CAIAnimationState* const _this)>(0x11883D0);
};

// CAIAnimationComponent
// Header:  Prey/GameDll/playerai.h
class CAIAnimationComponent
{ // Size=136 (0x88)
public:
	_smart_ptr<CAnimActionAIMovement> m_pAnimActionAiMovement;
	_smart_ptr<CAnimActionAIDetail> m_pAnimActionAiDetail;
	CAIAnimationState m_animationState;
	std::weak_ptr<CProceduralContextAim> m_pProceduralContextAim;
	std::weak_ptr<CProceduralContextLook> m_pProceduralContextLook;
	std::weak_ptr<CProceduralContextLook> m_pProceduralContextLookHead;
	std::weak_ptr<CProceduralContextLook> m_pProceduralContextLookEyes;
	_smart_ptr<CArkAnimActionAIBlink> m_pBlinkAction;
	bool m_useLegacyCoverLocator;
	string m_forcedTagList;

	CAIAnimationComponent(IScriptTable* pScriptTable);
	~CAIAnimationComponent();
	bool InitMannequin(IActionController& actionController, const SAnimActionAIMovementSettings& animActionAIMovementSettings) { return FInitMannequin(this, actionController, animActionAIMovementSettings); }
	void ResetMannequin() { FResetMannequin(this); }
	void RequestAIMovementDetail(CAnimActionAIDetail::EMovementDetail movementDetail) { FRequestAIMovementDetail(this, movementDetail); }
	void UpdateAimingState(ISkeletonPose* pSkeletonPose, const bool aimEnabled, const Vec3& aimTarget, const unsigned aimIkLayer, const float aimIkFadeoutTime) { FUpdateAimingState(this, pSkeletonPose, aimEnabled, aimTarget, aimIkLayer, aimIkFadeoutTime); }
	bool UpdateLookingState(const bool lookEnabled, const Vec3& lookTarget) { return FUpdateLookingState(this, lookEnabled, lookTarget); }
	void EnableBlink(bool _bEnable) { FEnableBlink(this, _bEnable); }
	void ForceStanceTo(CPlayer& player, const EStance targetStance) { FForceStanceTo(this, player, targetStance); }
	void ForceStanceInAIActorTo(CPlayer& player, const EStance targetStance) { FForceStanceInAIActorTo(this, player, targetStance); }
	void ForceReevaluateMovementAnimAction() { FForceReevaluateMovementAnimAction(this); }

#if 0
	CAIAnimationState& GetAnimationState();
	const CAIAnimationState& GetAnimationState() const;
	void UpdateAnimationStateRequests(CPlayer& _arg0_, const SActorFrameMovementParams& _arg1_);
	void UpdateStanceAndCover(CPlayer& _arg0_, IActionController* _arg1_);
	bool GetUseLegacyCoverLocator() const;
#endif

	static inline auto FCAIAnimationComponentOv1 = PreyFunction<void(CAIAnimationComponent* const _this, IScriptTable* pScriptTable)>(0x18CDC70);
	static inline auto FBitNotCAIAnimationComponent = PreyFunction<void(CAIAnimationComponent* const _this)>(0x18CDEA0);
	static inline auto FInitMannequin = PreyFunction<bool(CAIAnimationComponent* const _this, IActionController& actionController, const SAnimActionAIMovementSettings& animActionAIMovementSettings)>(0x18CEF90);
	static inline auto FResetMannequin = PreyFunction<void(CAIAnimationComponent* const _this)>(0x18CFC60);
	static inline auto FRequestAIMovementDetail = PreyFunction<void(CAIAnimationComponent* const _this, CAnimActionAIDetail::EMovementDetail movementDetail)>(0x18CFC50);
	static inline auto FUpdateAimingState = PreyFunction<void(CAIAnimationComponent* const _this, ISkeletonPose* pSkeletonPose, const bool aimEnabled, const Vec3& aimTarget, const unsigned aimIkLayer, const float aimIkFadeoutTime)>(0x18D0380);
	static inline auto FUpdateLookingState = PreyFunction<bool(CAIAnimationComponent* const _this, const bool lookEnabled, const Vec3& lookTarget)>(0x18D0490);
	static inline auto FEnableBlink = PreyFunction<void(CAIAnimationComponent* const _this, bool _bEnable)>(0x18CDFD0);
	static inline auto FForceStanceTo = PreyFunction<void(CAIAnimationComponent* const _this, CPlayer& player, const EStance targetStance)>(0x18CE040);
	static inline auto FForceStanceInAIActorTo = PreyFunction<void(CAIAnimationComponent* const _this, CPlayer& player, const EStance targetStance)>(0x18CDFF0);
	static inline auto FForceReevaluateMovementAnimAction = PreyFunction<void(CAIAnimationComponent* const _this)>(0x18CDFE0);
};

// SMannequinAIStateParams
// Header:  Prey/GameDll/playerai.h
struct SMannequinAIStateParams : public IMannequinUserParams
{ // Size=208 (0xD0)
	// SMannequinAIStateParams::TagIDs
	// Header:  Prey/GameDll/playerai.h
	struct TagIDs
	{ // Size=156 (0x9C)
		TMannequinAutoInit<int,-1> Dead;
		TMannequinAutoInit<int,-1> Alive;
		TMannequinAutoInit<int,-1> Aiming;
		TMannequinAutoInit<int,-1> NotAiming;
		TMannequinAutoInit<int,-1> Firing;
		TMannequinAutoInit<int,-1> NotFiring;
		TMannequinAutoInit<int,-1> Nw;
		TMannequinAutoInit<int,-1> NoItem;
		TMannequinAutoInit<int,-1> Relaxed;
		TMannequinAutoInit<int,-1> Alerted;
		TMannequinAutoInit<int,-1> Crouch;
		TMannequinAutoInit<int,-1> Swim;
		TMannequinAutoInit<int,-1> Stand;
		TMannequinAutoInit<int,-1> CoverHigh;
		TMannequinAutoInit<int,-1> CoverLow;
		TMannequinAutoInit<int,-1> NoGait;
		TMannequinAutoInit<int,-1> Walk;
		TMannequinAutoInit<int,-1> Run;
		TMannequinAutoInit<int,-1> Sprint;
		TMannequinAutoInit<int,-1> CoverLeft;
		TMannequinAutoInit<int,-1> CoverRight;
		TMannequinAutoInit<int,-1> AlertedOrStand;
		TMannequinAutoInit<int,-1> CoverAlignForward;
		TMannequinAutoInit<int,-1> CoverAlignRight;
		TMannequinAutoInit<int,-1> CoverAlignBack;
		TMannequinAutoInit<int,-1> CoverAlignLeft;
		TMannequinAutoInit<int,-1> Back;
		TMannequinAutoInit<int,-1> Combat;
		TMannequinAutoInit<int,-1> Front;
		TMannequinAutoInit<int,-1> Left;
		TMannequinAutoInit<int,-1> Right;
		TMannequinAutoInit<int,-1> Hover;
		TMannequinAutoInit<int,-1> Corrupted;
		TMannequinAutoInit<int,-1> InvestigateAnomaly;
		TMannequinAutoInit<int,-1> InvestigateDanger;
		TMannequinAutoInit<int,-1> InvestigateVision;
		TMannequinAutoInit<int,-1> Hunt;
		TMannequinAutoInit<int,-1> GunUp;
		TMannequinAutoInit<int,-1> Charge;

		void Init(const CTagDefinition& tagDefs) { FInit(this, tagDefs); }

		static inline auto FInit = PreyFunction<void(SMannequinAIStateParams::TagIDs* const _this, const CTagDefinition& tagDefs)>(0x18CE4B0);
	};

	// SMannequinAIStateParams::TagGroupIDs
	// Header:  Prey/GameDll/playerai.h
	struct TagGroupIDs
	{ // Size=40 (0x28)
		TMannequinAutoInit<int,-1> Health;
		TMannequinAutoInit<int,-1> Aim;
		TMannequinAutoInit<int,-1> Fire;
		TMannequinAutoInit<int,-1> Item;
		TMannequinAutoInit<int,-1> WeaponType;
		TMannequinAutoInit<int,-1> Stance;
		TMannequinAutoInit<int,-1> Gait;
		TMannequinAutoInit<int,-1> MergedStance;
		TMannequinAutoInit<int,-1> AlignmentToCover;
		TMannequinAutoInit<int,-1> Direction;

	#if 0
		void Init(const CTagDefinition& _arg0_);
	#endif
	};

	SMannequinAIStateParams::TagIDs tagIDs;
	SMannequinAIStateParams::TagGroupIDs tagGroupIDs;

	virtual void Init(const SControllerDef& controllerDef);

	static inline auto FInit = PreyFunction<void(SMannequinAIStateParams* const _this, const SControllerDef& controllerDef)>(0x18CE3B0);
};
#endif // MOONCRASH
