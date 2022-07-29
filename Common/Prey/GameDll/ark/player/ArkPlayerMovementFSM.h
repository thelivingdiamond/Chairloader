// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/player/arkplayergroundstate.h>
#include <Prey/GameDll/ark/player/arkplayermovementfsm.h>
#include <Prey/GameDll/ark/player/arkplayermovementstates.h>
#include <Prey/GameDll/ark/player/arkplayercomponent.h>

class XmlNodeRef;

// Header: Exact
// Prey/GameDll/ark/player/arkplayermovementfsm.h
template <typename T>
class ArkPlayerMovementFsmBase_template_ // Id=80173E0 Size=1472
{
public:
	using EStateId = EArkPlayerMovementStateId;
	using BaseStateType = ArkPlayerMovementStates::Base;

	static constexpr const uint64_t k_stateCount = 18;
	EArkPlayerMovementStateId m_currentStateId;
	ArkPlayerMovementStates::Ground m_groundState;
	ArkPlayerMovementStates::Death m_deathState;
	ArkPlayerMovementStates::DeathByRecyclerGrenade m_deathByRecyclerGrenadeState;
	ArkPlayerMovementStates::Jump m_jumpState;
	ArkPlayerMovementStates::Fall m_fallState;
	ArkPlayerMovementStates::Climb m_climbState;
	ArkPlayerMovementStates::Fly m_flyState;
	ArkPlayerMovementStates::Smoke m_smokeState;
	ArkPlayerMovementStates::ZeroG m_zerogState;
	ArkPlayerMovementStates::Cinematic m_cinematicState;
	ArkPlayerMovementStates::Slide m_slideState;
	ArkPlayerMovementStates::Mimic m_mimicState;
	ArkPlayerMovementStates::GravShaftG m_gravShaftGState;
	ArkPlayerMovementStates::GravShaftToG m_gravShaftToGState;
	ArkPlayerMovementStates::GravShaftZeroG m_gravShaftZeroGState;
	ArkPlayerMovementStates::Lift m_liftState;
	ArkPlayerMovementStates::Shift m_shiftState;

	template <typename T>
	struct StateSelector // Id=8017411 Size=1
	{
		using StateType = T;

#if 0
		static StateType& Get(ArkPlayerMovementFsmBase_template_<void>& arg0);
		static StateType const& Get(ArkPlayerMovementFsmBase_template_<void> const& arg0);
#endif
	};

#if 0
	ArkPlayerMovementStates::Base& GetState(EArkPlayerMovementStateId arg0);
	ArkPlayerMovementStates::Base const& GetState(EArkPlayerMovementStateId arg0) const;
	bool CanTransitionTo(EArkPlayerMovementStateId arg0) const;
	bool Initiate(EArkPlayerMovementStateId arg0);
	bool Terminate();
	bool SetCurrentState(EArkPlayerMovementStateId arg0);
	bool SetCurrentStateIfNot(EArkPlayerMovementStateId arg0);
	EArkPlayerMovementStateId GetCurrentStateId() const;
	ArkPlayerMovementStates::Base& GetCurrentState();
	ArkPlayerMovementStates::Base const& GetCurrentState() const;
	bool CurrentStateIs(EArkPlayerMovementStateId arg0) const;
	bool CurrentStateIsNot(EArkPlayerMovementStateId arg0) const;
	void ArkPlayerMovementFsmBase_template_<void>();
	void ~ArkPlayerMovementFsmBase_template_<void>();
	void RestoreCurrentState(EArkPlayerMovementStateId arg0);
	void EnterState(EArkPlayerMovementStateId arg0);
	void ExitCurrentState();
#endif
};

// Header: FromCpp
// Prey/GameDll/ark/player/ArkPlayerMovementFSM.h
class ArkPlayerMovementFSM : public ArkPlayerMovementFsmBase_template_<void> // Id=80173DF Size=1568
{
public:
	enum class EArkFlyMode
	{
		off = 0,
		on = 1,
		onNoCollision = 2,
	};

	class StagingInfo // Id=80173E7 Size=20
	{
	public:
		Ang3 m_rotation;
		float m_yaw;
		float m_pitch;
		
#if 0
		void LimitRotation(Quat &arg0) const;
		void Serialize(TSerialize arg0);
#endif
	};

	boost::optional<ClimbPosInfo> m_climbPosInfo;
	ArkPlayerMovementFSM::StagingInfo m_stagingInfo;
	ArkPlayerMovementFSM::EArkFlyMode m_flyMode;
	float m_carrySpeedScale;
	float m_climbHorizontalFromEdgeProbeDistance;
	float m_climbVerticalReachDistance;
	float m_climbVerticalNormalMaxAngle;
	float m_cameraRoll;
	float m_cameraRollMaxAngle;
	float m_cameraRollIncreaseSpeed;
	float m_cameraRollRecoverySpeed;
	float m_airControl;
	bool m_bInputSneak;
	bool m_bInputJumpPressed;
	bool m_bJumpRequested;
	bool m_bMovementRestricted;
	float m_verticalSpeed;
	float m_jumpRequestedTime;
	
	ArkPlayerMovementFSM();
	void LoadConfig(XmlNodeRef const &_root) { FLoadConfig(this,_root); }
	void Update(const float _frameTime) { FUpdate(this,_frameTime); }
	Vec2 GetMovementInput() const { return FGetMovementInput(this); }
	void SetInputJumpPressed(bool _bPressed) { FSetInputJumpPressed(this,_bPressed); }
	bool IsInputJumpPressed() const { return FIsInputJumpPressed(this); }
	bool IsJumpRequested() const { return FIsJumpRequested(this); }
	float GetTimeOfJumpRequest() const { return FGetTimeOfJumpRequest(this); }
	void SetJumpRequested(bool _requested) { FSetJumpRequested(this,_requested); }
	void SetInputSneak(bool _bPressed) { FSetInputSneak(this,_bPressed); }
	bool IsInputSneakPressed() const { return FIsInputSneakPressed(this); }
	Ang3 GetCameraRotationInfluence(float _frameTime) { return FGetCameraRotationInfluence(this,_frameTime); }
	Vec2 GetWorldMovement() const { return FGetWorldMovement(this); }
	void OnFlyModePressed() { FOnFlyModePressed(this); }
	void LimitRotation(Quat &_rotation) const { FLimitRotation(this,_rotation); }
	bool IsInZeroG() const { return FIsInZeroG(this); }
	bool CheckZeroG() { return FCheckZeroG(this); }
	bool IsSprinting() const { return FIsSprinting(this); }
	float GetViewHeightInterpolationSpeed() const { return FGetViewHeightInterpolationSpeed(this); }
	void ProcessRotation(Quat &_rotation, Ang3 _inputRotation) { FProcessRotation(this,_rotation,_inputRotation); }
	void RestrictMovement(bool _bRestrict) { FRestrictMovement(this,_bRestrict); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void PostSerialize() { FPostSerialize(this); }
	void SetStagingInfo(Ang3 _rotation, float _viewLimitYaw, float _viewLimitPitch, bool _bLockPlayer, int _stance) { FSetStagingInfo(this,_rotation,_viewLimitYaw,_viewLimitPitch,_bLockPlayer,_stance); }
	float GetMaxMovementSpeed(EStance _stance) const { return FGetMaxMovementSpeed(this,_stance); }
	float GetCarrySpeedScale() const { return FGetCarrySpeedScale(this); }
	void SetCarrySpeedScale(const float _scale) { FSetCarrySpeedScale(this,_scale); }
	bool ProcessClimb() { return FProcessClimb(this); }
	static bool CanFit(Vec3 const &_pos, EStance _stance, Vec3 const &_sweepDir, const unsigned _ignore) { return FCanFit(_pos,_stance,_sweepDir,_ignore); }
	void SetMovementParameters(ArkPlayerMovementStates::Ground::ArkGroundColliderParameters _groundColliderParams, ArkPlayerMovementStates::Ground::ArkGroundColliderParameters _gooProjectileColliderParams) { FSetMovementParameters(this,_groundColliderParams,_gooProjectileColliderParams); }
	void SetRequestedStance(EStance _stance) { FSetRequestedStance(this,_stance); }
	float GetLeanInput() const { return FGetLeanInput(this); }
	static int GetNumPointsInZeroG() { return FGetNumPointsInZeroG(); }
	static Vec3 GetWindVelocity() { return FGetWindVelocity(); }
	static bool TrySetStance(EStance _stance) { return FTrySetStance(_stance); }
	boost::optional<ClimbPosInfo> GetClimbPosInfo_Internal() const { return FGetClimbPosInfo_Internal(this); }
	
#if 0
	bool AllowsJump() const;
	bool QueuesJump() const;
	void OnStepStop();
	void SetFlyMode(const int arg0);
	void SetFlyMode(ArkPlayerMovementFSM::EArkFlyMode arg0);
	float GetFPIKPitchWeight() const;
	boost::optional<ClimbPosInfo> GetClimbPosInfo() const;
	float GetVerticalSpeed() const;
	float GetAirControl() const;
	Ang3 GetCameraRotationInfluenceFromState(float arg0);
#endif
	
	static inline auto FLoadConfig = PreyFunction<void(ArkPlayerMovementFSM *const _this, XmlNodeRef const &_root)>(0x1570870);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMovementFSM *const _this, const float _frameTime)>(0x1571AF0);
	static inline auto FGetMovementInput = PreyFunction<Vec2(ArkPlayerMovementFSM const *const _this)>(0x156FC40);
	static inline auto FSetInputJumpPressed = PreyFunction<void(ArkPlayerMovementFSM *const _this, bool _bPressed)>(0x1571700);
	static inline auto FIsInputJumpPressed = PreyFunction<bool(ArkPlayerMovementFSM const *const _this)>(0x1570550);
	static inline auto FIsJumpRequested = PreyFunction<bool(ArkPlayerMovementFSM const *const _this)>(0x1570570);
	static inline auto FGetTimeOfJumpRequest = PreyFunction<float(ArkPlayerMovementFSM const *const _this)>(0x156FF40);
	static inline auto FSetJumpRequested = PreyFunction<void(ArkPlayerMovementFSM *const _this, bool _requested)>(0x15717A0);
	static inline auto FSetInputSneak = PreyFunction<void(ArkPlayerMovementFSM *const _this, bool _bPressed)>(0x1571710);
	static inline auto FIsInputSneakPressed = PreyFunction<bool(ArkPlayerMovementFSM const *const _this)>(0x1570560);
	static inline auto FGetCameraRotationInfluence = PreyFunction<Ang3(ArkPlayerMovementFSM *const _this, float _frameTime)>(0x156F5E0);
	static inline auto FGetWorldMovement = PreyFunction<Vec2(ArkPlayerMovementFSM const *const _this)>(0x1570260);
	static inline auto FOnFlyModePressed = PreyFunction<void(ArkPlayerMovementFSM *const _this)>(0x15710E0);
	static inline auto FLimitRotation = PreyFunction<void(ArkPlayerMovementFSM const *const _this, Quat &_rotation)>(0x1570600);
	static inline auto FIsInZeroG = PreyFunction<bool(ArkPlayerMovementFSM const *const _this)>(0x1570370);
	static inline auto FCheckZeroG = PreyFunction<bool(ArkPlayerMovementFSM *const _this)>(0x156F3A0);
	static inline auto FIsSprinting = PreyFunction<bool(ArkPlayerMovementFSM const *const _this)>(0x1570580);
	static inline auto FGetViewHeightInterpolationSpeed = PreyFunction<float(ArkPlayerMovementFSM const *const _this)>(0x156FF50);
	static inline auto FProcessRotation = PreyFunction<void(ArkPlayerMovementFSM *const _this, Quat &_rotation, Ang3 _inputRotation)>(0x1571310);
	static inline auto FRestrictMovement = PreyFunction<void(ArkPlayerMovementFSM *const _this, bool _bRestrict)>(0x15715D0);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerMovementFSM *const _this, TSerialize _ser)>(0x15715E0);
	static inline auto FPostSerialize = PreyFunction<void(ArkPlayerMovementFSM *const _this)>(0x15711D0);
	static inline auto FSetStagingInfo = PreyFunction<void(ArkPlayerMovementFSM *const _this, Ang3 _rotation, float _viewLimitYaw, float _viewLimitPitch, bool _bLockPlayer, int _stance)>(0x15718D0);
	static inline auto FGetMaxMovementSpeed = PreyFunction<float(ArkPlayerMovementFSM const *const _this, EStance _stance)>(0x156FBA0);
	static inline auto FGetCarrySpeedScale = PreyFunction<float(ArkPlayerMovementFSM const *const _this)>(0x156F870);
	static inline auto FSetCarrySpeedScale = PreyFunction<void(ArkPlayerMovementFSM *const _this, const float _scale)>(0x15716F0);
	static inline auto FProcessClimb = PreyFunction<bool(ArkPlayerMovementFSM *const _this)>(0x15711F0);
	static inline auto FCanFit = PreyFunction<bool(Vec3 const &_pos, EStance _stance, Vec3 const &_sweepDir, const unsigned _ignore)>(0x156F150);
	static inline auto FSetMovementParameters = PreyFunction<void(ArkPlayerMovementFSM *const _this, ArkPlayerMovementStates::Ground::ArkGroundColliderParameters _groundColliderParams, ArkPlayerMovementStates::Ground::ArkGroundColliderParameters _gooProjectileColliderParams)>(0x1571880);
	static inline auto FSetRequestedStance = PreyFunction<void(ArkPlayerMovementFSM *const _this, EStance _stance)>(0x15718B0);
	static inline auto FGetLeanInput = PreyFunction<float(ArkPlayerMovementFSM const *const _this)>(0x156FB20);
	static inline auto FGetNumPointsInZeroG = PreyFunction<int()>(0x156FD60);
	static inline auto FGetWindVelocity = PreyFunction<Vec3()>(0x1570010);
	static inline auto FTrySetStance = PreyFunction<bool(EStance _stance)>(0x1571980);
	static inline auto FGetClimbPosInfo_Internal = PreyFunction<boost::optional<ClimbPosInfo>(ArkPlayerMovementFSM const *const _this)>(0x156F880);
};

