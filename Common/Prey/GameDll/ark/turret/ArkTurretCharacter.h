// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/ArkUnanimous.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <_unknown/ArkTurretAngle.h>

class ArkTurret;
class ArkTurretAnimAction;
class IAction;
class IActionController;
class IAnimationDatabase;
struct SAnimationContext;

// ArkTurretCharacter
// Header:  Prey/GameDll/ark/turret/ArkTurretCharacter.h
class ArkTurretCharacter
{ // Size=128 (0x80)
public:
	ArkTurret& m_turret;
	IActionController* m_pActionController;
	SAnimationContext* m_pAnimContex;
	const IAnimationDatabase* m_pAnimationDB;
	std::shared_ptr<IAnimationOperatorQueue> m_pAimRotationModifier;
	_smart_ptr<IAction> m_pCurrentAction;
	_smart_ptr<IAction> m_pRecoilAction;
	ArkTurretAngle m_currentAngle;
	ArkTurretAngle m_goalAngle;
	ArkTurretAngle m_angularVelocity;
	int16_t m_gimbalYawJointID;
	int16_t m_gimbalPitchJointID;
	int16_t m_barrelEndJointID;
	int16_t m_barrelStockJointID;
	EArkTurretAnimState m_currentState;
	ArkUnanimous m_enabled;
	bool m_bEnabled;
	bool m_bAimEnabled;

	ArkTurretCharacter(ArkTurret& _turret);
	~ArkTurretCharacter();
	void Initialize() { FInitialize(this); }
	void Update(float _frameTime) { FUpdate(this, _frameTime); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	void Release() { FRelease(this); }
	void SetGlobalTag(const char* _pTag, bool _bSet) { FSetGlobalTag(this, _pTag, _bSet); }
	void PushEnable() { FPushEnable(this); }
	void PushDisable() { FPushDisable(this); }
	void PopDisable() { FPopDisable(this); }
	void EnableAiming() { FEnableAiming(this); }
	void DisableAiming() { FDisableAiming(this); }
	bool IsUndeployed() const { return FIsUndeployed(this); }
	bool IsDeployed() const { return FIsDeployed(this); }
	bool IsSearching() const { return FIsSearching(this); }
	void PlayUndeployed() { FPlayUndeployed(this); }
	void PlayDeployed() { FPlayDeployed(this); }
	void PlayBroken() { FPlayBroken(this); }
	void PlaySearching() { FPlaySearching(this); }
	void PlayRecoil(float _recoilLength) { FPlayRecoil(this, _recoilLength); }
	void StopRecoil() { FStopRecoil(this); }
	void SetGoalOrientation(const Vec3& _lookPosition) { FSetGoalOrientationOv1(this, _lookPosition); }
	void SetGoalOrientation(float _yaw, float _pitch) { FSetGoalOrientationOv0(this, _yaw, _pitch); }
	void ClearGoalOrientation() { FClearGoalOrientation(this); }
	const ArkTurretAngle& GetCurrentOrientation() const { return FGetCurrentOrientation(this); }
	void UpdateCurrentOrientation() { FUpdateCurrentOrientation(this); }
	bool HasArrivedAtGoalOrientation(float _withinRadians) const { return FHasArrivedAtGoalOrientation(this, _withinRadians); }
	ArkTurretAngle CalculateOrientationFromLookAtPos(const Vec3& _lookPosition) const { alignas(ArkTurretAngle) std::byte _return_buf_[sizeof(ArkTurretAngle)]; return *FCalculateOrientationFromLookAtPos(this, reinterpret_cast<ArkTurretAngle*>(_return_buf_), _lookPosition); }
	QuatT GetViewTm(float _viewConeHorizontalSemiangle, float _viewConeUpSemiangle, float _viewConeDownSemiangle) const { alignas(QuatT) std::byte _return_buf_[sizeof(QuatT)]; return *FGetViewTm(this, reinterpret_cast<QuatT*>(_return_buf_), _viewConeHorizontalSemiangle, _viewConeUpSemiangle, _viewConeDownSemiangle); }
	QuatT GetGimbalYawJointTM() const { alignas(QuatT) std::byte _return_buf_[sizeof(QuatT)]; return *FGetGimbalYawJointTM(this, reinterpret_cast<QuatT*>(_return_buf_)); }
	QuatT GetBarrelEndJointTM() const { alignas(QuatT) std::byte _return_buf_[sizeof(QuatT)]; return *FGetBarrelEndJointTM(this, reinterpret_cast<QuatT*>(_return_buf_)); }
	void OnActionEnter(const ArkTurretAnimAction& _action) { FOnActionEnter(this, _action); }
	void OnActionExit(const ArkTurretAnimAction& _action) { FOnActionExit(this, _action); }
	void UpdateAiming(float _frameTime) { FUpdateAiming(this, _frameTime); }
	void LoadModel(const char* _pModelPath) { FLoadModel(this, _pModelPath); }
	void OnModelChanged() { FOnModelChanged(this); }
	void StartFragment(const char* _pFragmentName, EArkTurretAnimState _state, bool _bAutoBlendout) { FStartFragment(this, _pFragmentName, _state, _bAutoBlendout); }
	QuatT GetJointTM(int16_t _id) const { alignas(QuatT) std::byte _return_buf_[sizeof(QuatT)]; return *FGetJointTM(this, reinterpret_cast<QuatT*>(_return_buf_), _id); }

#if 0
	void LoadAliveModel();
	void LoadDestroyedModel();
	void PopEnable();
	bool IsAiming() const;
	bool IsValid() const;
	bool IsEnabled() const;
	void SetGoalOrientationToCurrentOrientation();
	void MakeGoalOrientationCurrent();
	const ArkTurretAngle& GetGoalOrientation() const;
	bool CanReachOrientation(const Vec3& _arg0_) const;
	bool CanReachOrientation(float _arg0_, float _arg1_) const;
	int16_t GetGimbalYawJointId() const;
	int16_t GetGimbalPitchJointId() const;
	int16_t GetBarrelEndJointId() const;
	int16_t GetBarrelStockJointId() const;
	QuatT GetGimbalPitchJointTM() const;
	QuatT GetBarrelStockJointTM() const;
	void OnEnabled();
	void OnDisabled();
	bool IsCurrentFragmentPlaying() const;
	void PlayAction(const char* _arg0_, EArkTurretAnimState _arg1_, bool _arg2_);
	IAction* StartAdditiveFragment(const char* _arg0_) const;
#endif

	static inline auto FArkTurretCharacterOv1 = PreyFunction<void(ArkTurretCharacter* const _this, ArkTurret& _turret)>(0x13CA380);
	static inline auto FBitNotArkTurretCharacter = PreyFunction<void(ArkTurretCharacter* const _this)>(0x13CA3F0);
	static inline auto FInitialize = PreyFunction<void(ArkTurretCharacter* const _this)>(0x13CB470);
	static inline auto FUpdate = PreyFunction<void(ArkTurretCharacter* const _this, float _frameTime)>(0x13CC440);
	static inline auto FSerialize = PreyFunction<void(ArkTurretCharacter* const _this, TSerialize _ser)>(0x13CBF10);
	static inline auto FPostSerialize = PreyFunction<void(ArkTurretCharacter* const _this)>(0x13CBD90);
	static inline auto FRelease = PreyFunction<void(ArkTurretCharacter* const _this)>(0x13CBEB0);
	static inline auto FSetGlobalTag = PreyFunction<void(ArkTurretCharacter* const _this, const char* _pTag, bool _bSet)>(0x13CC060);
	static inline auto FPushEnable = PreyFunction<void(ArkTurretCharacter* const _this)>(0x13CBE50);
	static inline auto FPushDisable = PreyFunction<void(ArkTurretCharacter* const _this)>(0x13CBE00);
	static inline auto FPopDisable = PreyFunction<void(ArkTurretCharacter* const _this)>(0x13CBD30);
	static inline auto FEnableAiming = PreyFunction<void(ArkTurretCharacter* const _this)>(0x13CA940);
	static inline auto FDisableAiming = PreyFunction<void(ArkTurretCharacter* const _this)>(0x13CA930);
	static inline auto FIsUndeployed = PreyFunction<bool(const ArkTurretCharacter* const _this)>(0x13CB6B0);
	static inline auto FIsDeployed = PreyFunction<bool(const ArkTurretCharacter* const _this)>(0x13CB670);
	static inline auto FIsSearching = PreyFunction<bool(const ArkTurretCharacter* const _this)>(0x13CB690);
	static inline auto FPlayUndeployed = PreyFunction<void(ArkTurretCharacter* const _this)>(0x13CBD10);
	static inline auto FPlayDeployed = PreyFunction<void(ArkTurretCharacter* const _this)>(0x13CBB30);
	static inline auto FPlayBroken = PreyFunction<void(ArkTurretCharacter* const _this)>(0x13CBB10);
	static inline auto FPlaySearching = PreyFunction<void(ArkTurretCharacter* const _this)>(0x13CBCF0);
	static inline auto FPlayRecoil = PreyFunction<void(ArkTurretCharacter* const _this, float _recoilLength)>(0x13CBB50);
	static inline auto FStopRecoil = PreyFunction<void(ArkTurretCharacter* const _this)>(0x13CC3D0);
	static inline auto FSetGoalOrientationOv1 = PreyFunction<void(ArkTurretCharacter* const _this, const Vec3& _lookPosition)>(0x13CC1B0);
	static inline auto FSetGoalOrientationOv0 = PreyFunction<void(ArkTurretCharacter* const _this, float _yaw, float _pitch)>(0xA18E10);
	static inline auto FClearGoalOrientation = PreyFunction<void(ArkTurretCharacter* const _this)>(0x13CA920);
	static inline auto FGetCurrentOrientation = PreyFunction<const ArkTurretAngle& (const ArkTurretCharacter* const _this)>(0x1368F30);
	static inline auto FUpdateCurrentOrientation = PreyFunction<void(ArkTurretCharacter* const _this)>(0x13CC8E0);
	static inline auto FHasArrivedAtGoalOrientation = PreyFunction<bool(const ArkTurretCharacter* const _this, float _withinRadians)>(0x13CB430);
	static inline auto FCalculateOrientationFromLookAtPos = PreyFunction<ArkTurretAngle*(const ArkTurretCharacter* const _this, ArkTurretAngle* _return_value_, const Vec3& _lookPosition)>(0x13CA480);
	static inline auto FGetViewTm = PreyFunction<QuatT*(const ArkTurretCharacter* const _this, QuatT* _return_value_, float _viewConeHorizontalSemiangle, float _viewConeUpSemiangle, float _viewConeDownSemiangle)>(0x13CAE40);
	static inline auto FGetGimbalYawJointTM = PreyFunction<QuatT*(const ArkTurretCharacter* const _this, QuatT* _return_value_)>(0x13CA970);
	static inline auto FGetBarrelEndJointTM = PreyFunction<QuatT*(const ArkTurretCharacter* const _this, QuatT* _return_value_)>(0x13CA950);
	static inline auto FOnActionEnter = PreyFunction<void(ArkTurretCharacter* const _this, const ArkTurretAnimAction& _action)>(0x13CB7D0);
	static inline auto FOnActionExit = PreyFunction<void(ArkTurretCharacter* const _this, const ArkTurretAnimAction& _action)>(0x13CB800);
	static inline auto FUpdateAiming = PreyFunction<void(ArkTurretCharacter* const _this, float _frameTime)>(0x13CC6F0);
	static inline auto FLoadModel = PreyFunction<void(ArkTurretCharacter* const _this, const char* _pModelPath)>(0x13CB6D0);
	static inline auto FOnModelChanged = PreyFunction<void(ArkTurretCharacter* const _this)>(0x13CB840);
	static inline auto FStartFragment = PreyFunction<void(ArkTurretCharacter* const _this, const char* _pFragmentName, EArkTurretAnimState _state, bool _bAutoBlendout)>(0x13CC1E0);
	static inline auto FGetJointTM = PreyFunction<QuatT*(const ArkTurretCharacter* const _this, QuatT* _return_value_, int16_t _id)>(0x13CA990);
};
#endif // MOONCRASH
