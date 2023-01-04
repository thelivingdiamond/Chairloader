// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/player/ArkPlayerMovementStates.h>
#include <Prey/GameDll/ark/player/arkplayergroundstate.h>

namespace ArkPlayerMovementStates
{
class Base;
} // namespace ArkPlayerMovementStates
enum class EStance;
class XmlNodeRef;

template<typename T>
class ArkPlayerMovementFsmBase_template_;

// ArkPlayerMovementFsmBase_template_<void>
// Header:  Prey/GameDll/ark/player/ArkPlayerMovementFSM.h
template<>
class ArkPlayerMovementFsmBase_template_<void>
{ // Size=1472 (0x5C0)
public:
#if 0
	// ArkPlayerMovementFsmBase_template_<void>::StateSelector<1>
	// Header:  Prey/GameDll/ark/player/ArkPlayerMovementFSM.h
	struct StateSelector<1>
	{ // Size=1 (0x1)
		using StateType = ArkPlayerMovementStates::Ground;

	#if 0
		static ArkPlayerMovementStates::Ground& Get(ArkPlayerMovementFsmBase_template_<void>& _arg0_);
		static const ArkPlayerMovementStates::Ground& Get(const ArkPlayerMovementFsmBase_template_<void>& _arg0_);
	#endif
	};
#endif

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

	ArkPlayerMovementStates::Base& GetCurrentState() { return FGetCurrentStateOv1(this); }
	ArkPlayerMovementFsmBase_template_<void>();
	~ArkPlayerMovementFsmBase_template_<void>();
	void ExitCurrentState() { FExitCurrentState(this); }

#if 0
	ArkPlayerMovementStates::Base& GetState(const EArkPlayerMovementStateId _arg0_);
	const ArkPlayerMovementStates::Base& GetState(const EArkPlayerMovementStateId _arg0_) const;
	bool CanTransitionTo(const EArkPlayerMovementStateId _arg0_) const;
	bool Initiate(const EArkPlayerMovementStateId _arg0_);
	bool Terminate();
	bool SetCurrentState(const EArkPlayerMovementStateId _arg0_);
	bool SetCurrentStateIfNot(const EArkPlayerMovementStateId _arg0_);
	EArkPlayerMovementStateId GetCurrentStateId() const;
	const ArkPlayerMovementStates::Base& GetCurrentState() const;
	bool CurrentStateIs(const EArkPlayerMovementStateId _arg0_) const;
	bool CurrentStateIsNot(const EArkPlayerMovementStateId _arg0_) const;
	void RestoreCurrentState(const EArkPlayerMovementStateId _arg0_);
	void EnterState(const EArkPlayerMovementStateId _arg0_);
#endif

	static inline auto FGetCurrentStateOv1 = PreyFunction<ArkPlayerMovementStates::Base& (ArkPlayerMovementFsmBase_template_<void>* const _this)>(0x14399D0);
	static inline auto FArkPlayerMovementFsmBase_template_LessvoidGreaterOv1 = PreyFunction<void(ArkPlayerMovementFsmBase_template_<void>* const _this)>(0x156E130);
	static inline auto FBitNotArkPlayerMovementFsmBase_template_LessvoidGreater = PreyFunction<void(ArkPlayerMovementFsmBase_template_<void>* const _this)>(0x154DAB0);
	static inline auto FExitCurrentState = PreyFunction<void(ArkPlayerMovementFsmBase_template_<void>* const _this)>(0x1235330);
};

// ArkPlayerMovementFSM
// Header:  Prey/GameDll/ark/player/ArkPlayerMovementFSM.h
class ArkPlayerMovementFSM : public ArkPlayerMovementFsmBase_template_<void>
{ // Size=1568 (0x620)
public:
	enum class EArkFlyMode
	{
		off = 0,
		on = 1,
		onNoCollision = 2,
	};

	// ArkPlayerMovementFSM::StagingInfo
	// Header:  Prey/GameDll/ark/player/ArkPlayerMovementFSM.h
	class StagingInfo
	{ // Size=20 (0x14)
	public:
		Ang3 m_rotation;
		float m_yaw;
		float m_pitch;

	#if 0
		StagingInfo();
		StagingInfo(const Ang3 _arg0_, const float _arg1_, const float _arg2_);
		void LimitRotation(Quat& _arg0_) const;
		void Serialize(TSerialize _arg0_);
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
	void LoadConfig(const XmlNodeRef& _root) { FLoadConfig(this, _root); }
	void Update(const float _frameTime) { FUpdate(this, _frameTime); }
	Vec2 GetMovementInput() const { alignas(Vec2) std::byte _return_buf_[sizeof(Vec2)]; return *FGetMovementInput(this, reinterpret_cast<Vec2*>(_return_buf_)); }
	void SetInputJumpPressed(bool _bPressed) { FSetInputJumpPressed(this, _bPressed); }
	bool IsInputJumpPressed() const { return FIsInputJumpPressed(this); }
	bool IsJumpRequested() const { return FIsJumpRequested(this); }
	float GetTimeOfJumpRequest() const { return FGetTimeOfJumpRequest(this); }
	void SetJumpRequested(bool _requested) { FSetJumpRequested(this, _requested); }
	void SetInputSneak(bool _bPressed) { FSetInputSneak(this, _bPressed); }
	bool IsInputSneakPressed() const { return FIsInputSneakPressed(this); }
	Ang3 GetCameraRotationInfluence(float _frameTime) { alignas(Ang3) std::byte _return_buf_[sizeof(Ang3)]; return *FGetCameraRotationInfluence(this, reinterpret_cast<Ang3*>(_return_buf_), _frameTime); }
	Vec2 GetWorldMovement() const { alignas(Vec2) std::byte _return_buf_[sizeof(Vec2)]; return *FGetWorldMovement(this, reinterpret_cast<Vec2*>(_return_buf_)); }
	void OnFlyModePressed() { FOnFlyModePressed(this); }
	void LimitRotation(Quat& _rotation) const { FLimitRotation(this, _rotation); }
	bool IsInZeroG() const { return FIsInZeroG(this); }
	bool CheckZeroG() { return FCheckZeroG(this); }
	bool IsSprinting() const { return FIsSprinting(this); }
	float GetViewHeightInterpolationSpeed() const { return FGetViewHeightInterpolationSpeed(this); }
	void ProcessRotation(Quat& _rotation, Ang3 _inputRotation) { FProcessRotation(this, _rotation, _inputRotation); }
	void RestrictMovement(bool _bRestrict) { FRestrictMovement(this, _bRestrict); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	void SetStagingInfo(Ang3 _rotation, float _viewLimitYaw, float _viewLimitPitch, bool _bLockPlayer, int _stance) { FSetStagingInfo(this, _rotation, _viewLimitYaw, _viewLimitPitch, _bLockPlayer, _stance); }
	float GetMaxMovementSpeed(const EStance _stance) const { return FGetMaxMovementSpeed(this, _stance); }
	float GetCarrySpeedScale() const { return FGetCarrySpeedScale(this); }
	void SetCarrySpeedScale(const float _scale) { FSetCarrySpeedScale(this, _scale); }
	bool ProcessClimb() { return FProcessClimb(this); }
	static bool CanFit(const Vec3& _pos, const EStance _stance, const Vec3& _sweepDir, const unsigned _ignore) { return FCanFit(_pos, _stance, _sweepDir, _ignore); }
	void SetMovementParameters(ArkPlayerMovementStates::Ground::ArkGroundColliderParameters _groundColliderParams, ArkPlayerMovementStates::Ground::ArkGroundColliderParameters _gooProjectileColliderParams) { FSetMovementParameters(this, _groundColliderParams, _gooProjectileColliderParams); }
	void SetRequestedStance(EStance _stance) { FSetRequestedStance(this, _stance); }
	float GetLeanInput() const { return FGetLeanInput(this); }
	static int GetNumPointsInZeroG() { return FGetNumPointsInZeroG(); }
	static Vec3 GetWindVelocity() { return FGetWindVelocity(); }
	static bool TrySetStance(EStance _stance) { return FTrySetStance(_stance); }
	boost::optional<ClimbPosInfo> GetClimbPosInfo_Internal() const { alignas(boost::optional<ClimbPosInfo>) std::byte _return_buf_[sizeof(boost::optional<ClimbPosInfo>)]; return *FGetClimbPosInfo_Internal(this, reinterpret_cast<boost::optional<ClimbPosInfo>*>(_return_buf_)); }

#if 0
	bool AllowsJump() const;
	bool QueuesJump() const;
	void OnStepStop();
	void SetFlyMode(const int _arg0_);
	void SetFlyMode(const ArkPlayerMovementFSM::EArkFlyMode _arg0_);
	float GetFPIKPitchWeight() const;
	boost::optional<ClimbPosInfo> GetClimbPosInfo() const;
	float GetVerticalSpeed() const;
	float GetAirControl() const;
	Ang3 GetCameraRotationInfluenceFromState(float _arg0_);
#endif

	static inline auto FArkPlayerMovementFSMOv2 = PreyFunction<void(ArkPlayerMovementFSM* const _this)>(0x156E510);
	static inline auto FLoadConfig = PreyFunction<void(ArkPlayerMovementFSM* const _this, const XmlNodeRef& _root)>(0x1570870);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMovementFSM* const _this, const float _frameTime)>(0x1571AF0);
	static inline auto FGetMovementInput = PreyFunction<Vec2*(const ArkPlayerMovementFSM* const _this, Vec2* _return_value_)>(0x156FC40);
	static inline auto FSetInputJumpPressed = PreyFunction<void(ArkPlayerMovementFSM* const _this, bool _bPressed)>(0x1571700);
	static inline auto FIsInputJumpPressed = PreyFunction<bool(const ArkPlayerMovementFSM* const _this)>(0x1570550);
	static inline auto FIsJumpRequested = PreyFunction<bool(const ArkPlayerMovementFSM* const _this)>(0x1570570);
	static inline auto FGetTimeOfJumpRequest = PreyFunction<float(const ArkPlayerMovementFSM* const _this)>(0x156FF40);
	static inline auto FSetJumpRequested = PreyFunction<void(ArkPlayerMovementFSM* const _this, bool _requested)>(0x15717A0);
	static inline auto FSetInputSneak = PreyFunction<void(ArkPlayerMovementFSM* const _this, bool _bPressed)>(0x1571710);
	static inline auto FIsInputSneakPressed = PreyFunction<bool(const ArkPlayerMovementFSM* const _this)>(0x1570560);
	static inline auto FGetCameraRotationInfluence = PreyFunction<Ang3*(ArkPlayerMovementFSM* const _this, Ang3* _return_value_, float _frameTime)>(0x156F5E0);
	static inline auto FGetWorldMovement = PreyFunction<Vec2*(const ArkPlayerMovementFSM* const _this, Vec2* _return_value_)>(0x1570260);
	static inline auto FOnFlyModePressed = PreyFunction<void(ArkPlayerMovementFSM* const _this)>(0x15710E0);
	static inline auto FLimitRotation = PreyFunction<void(const ArkPlayerMovementFSM* const _this, Quat& _rotation)>(0x1570600);
	static inline auto FIsInZeroG = PreyFunction<bool(const ArkPlayerMovementFSM* const _this)>(0x1570370);
	static inline auto FCheckZeroG = PreyFunction<bool(ArkPlayerMovementFSM* const _this)>(0x156F3A0);
	static inline auto FIsSprinting = PreyFunction<bool(const ArkPlayerMovementFSM* const _this)>(0x1570580);
	static inline auto FGetViewHeightInterpolationSpeed = PreyFunction<float(const ArkPlayerMovementFSM* const _this)>(0x156FF50);
	static inline auto FProcessRotation = PreyFunction<void(ArkPlayerMovementFSM* const _this, Quat& _rotation, Ang3 _inputRotation)>(0x1571310);
	static inline auto FRestrictMovement = PreyFunction<void(ArkPlayerMovementFSM* const _this, bool _bRestrict)>(0x15715D0);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerMovementFSM* const _this, TSerialize _ser)>(0x15715E0);
	static inline auto FPostSerialize = PreyFunction<void(ArkPlayerMovementFSM* const _this)>(0x15711D0);
	static inline auto FSetStagingInfo = PreyFunction<void(ArkPlayerMovementFSM* const _this, Ang3 _rotation, float _viewLimitYaw, float _viewLimitPitch, bool _bLockPlayer, int _stance)>(0x15718D0);
	static inline auto FGetMaxMovementSpeed = PreyFunction<float(const ArkPlayerMovementFSM* const _this, const EStance _stance)>(0x156FBA0);
	static inline auto FGetCarrySpeedScale = PreyFunction<float(const ArkPlayerMovementFSM* const _this)>(0x156F870);
	static inline auto FSetCarrySpeedScale = PreyFunction<void(ArkPlayerMovementFSM* const _this, const float _scale)>(0x15716F0);
	static inline auto FProcessClimb = PreyFunction<bool(ArkPlayerMovementFSM* const _this)>(0x15711F0);
	static inline auto FCanFit = PreyFunction<bool(const Vec3& _pos, const EStance _stance, const Vec3& _sweepDir, const unsigned _ignore)>(0x156F150);
	static inline auto FSetMovementParameters = PreyFunction<void(ArkPlayerMovementFSM* const _this, ArkPlayerMovementStates::Ground::ArkGroundColliderParameters _groundColliderParams, ArkPlayerMovementStates::Ground::ArkGroundColliderParameters _gooProjectileColliderParams)>(0x1571880);
	static inline auto FSetRequestedStance = PreyFunction<void(ArkPlayerMovementFSM* const _this, EStance _stance)>(0x15718B0);
	static inline auto FGetLeanInput = PreyFunction<float(const ArkPlayerMovementFSM* const _this)>(0x156FB20);
	static inline auto FGetNumPointsInZeroG = PreyFunction<int()>(0x156FD60);
	static inline auto FGetWindVelocity = PreyFunction<Vec3()>(0x1570010);
	static inline auto FTrySetStance = PreyFunction<bool(EStance _stance)>(0x1571980);
	static inline auto FGetClimbPosInfo_Internal = PreyFunction<boost::optional<ClimbPosInfo>*(const ArkPlayerMovementFSM* const _this, boost::optional<ClimbPosInfo>* _return_value_)>(0x156F880);
};

