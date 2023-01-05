// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/IGameObject.h>
#include <Prey/CryNetwork/ISerialize.h>

struct SViewParams;
class XmlNodeRef;

// ArkPlayerCamera
// Header:  Prey/GameDll/ark/player/ArkPlayerCamera.h
class ArkPlayerCamera : public IGameObjectView
{ // Size=456 (0x1C8)
public:
	enum class Mode
	{
		playerControl = 0,
		animation = 1,
		custom = 2,
		animationToPlayerControl = 3,
		death = 4,
		deathByRecycerGrenade = 5,
		last = 6,
	};

	enum class EArkBoneList
	{
		BONE_BIP01 = 0,
		BONE_SPINE = 1,
		BONE_SPINE2 = 2,
		BONE_SPINE3 = 3,
		BONE_HEAD = 4,
		BONE_EYE_R = 5,
		BONE_EYE_L = 6,
		BONE_WEAPON = 7,
		BONE_WEAPON2 = 8,
		BONE_FOOT_R = 9,
		BONE_FOOT_L = 10,
		BONE_ARM_R = 11,
		BONE_ARM_L = 12,
		BONE_CALF_R = 13,
		BONE_CALF_L = 14,
		BONE_CAMERA = 15,
		BONE_HUD = 16,
		BONE_ID_NUM = 17,
	};

	std::array<CryStringT<char>,17> m_boneNames;
	std::function<Quat_tpl<float> __cdecl(float)> m_customUpdateFunction;
	std::function<Vec3_tpl<float> __cdecl(float)> m_customOffsetFunction;
	std::function<void __cdecl(SViewParams &)> m_customViewFunction;
	Quat m_rotation;
	Vec2 m_recoilStep;
	float m_recoilTimeRemaining;
	float m_recoilDelayRemaining;
	float m_leanAmount;
	float m_leanAngle;
	float m_leanOffset;
	float m_eyeOffset;
	float m_transitionTime;
	float m_transitionTimeRemain;
	Quat m_transitionStartRot;
	Vec3 m_deathPos;
	ArkPlayerCamera::Mode m_mode;
	float m_bRecycleGrenadeDeathSpeed;
	Vec3 m_nonLeaningTargetPosition;
	float m_FPIKWeight;
	float m_FPIKWeightTarget;
	float m_stanceChangeInterSpeed;

	void Init() { FInit(this); }
	void Reset() { FReset(this); }
	static QuatT GetCameraBoneLocalQuatT() { return FGetCameraBoneLocalQuatT(); }
	void LoadConfig(const XmlNodeRef& _node) { FLoadConfig(this, _node); }
	void PrePhysicsUpdate(const float _frameTime) { FPrePhysicsUpdate(this, _frameTime); }
	void SyncEyeOffsetToStanceViewHeight() { FSyncEyeOffsetToStanceViewHeight(this); }
	void SetCustomUpdateFunction(std::function<Quat_tpl<float> __cdecl(float)> _function) { FSetCustomUpdateFunction(this, _function); }
	void RemoveCustomUpdateFunction(float _interpolateToUnlockTime) { FRemoveCustomUpdateFunction(this, _interpolateToUnlockTime); }
	void SetCustomViewFunction(std::function<void __cdecl(SViewParams &)> _function) { FSetCustomViewFunction(this, _function); }
	void RemoveCustomFunctions() { FRemoveCustomFunctions(this); }
	std::pair<Vec3, Quat> GetDesiredPositionAndRotation(float _frameTime) { alignas(std::pair<Vec3, Quat>) std::byte _return_buf_[sizeof(std::pair<Vec3, Quat>)]; return *FGetDesiredPositionAndRotation(this, reinterpret_cast<std::pair<Vec3, Quat>*>(_return_buf_), _frameTime); }
	bool IsLeaning() const { return FIsLeaning(this); }
	float GetLeanAmount() const { return FGetLeanAmount(this); }
	int GetJointId(const int _boneId) const { return FGetJointId(this, _boneId); }
	float GetDefaultViewHeightInterpolationSpeed() const { return FGetDefaultViewHeightInterpolationSpeed(this); }
	void UpdateFPIK(const float _frameTime, const float _pitchWeight) { FUpdateFPIK(this, _frameTime, _pitchWeight); }
	virtual void UpdateView(SViewParams& _params);
	virtual void PostUpdateView(SViewParams& _params);
	static boost::optional<Quat_tpl<float> > UpdateIronsightsView(const float _frameTime, const Vec3& _initialRotation) { return FUpdateIronsightsView(_frameTime, _initialRotation); }

#if 0
	ArkPlayerCamera();
	ArkPlayerCamera::Mode GetMode() const;
	void RemoveCustomViewFunction();
	void SetRotation(const Quat& _arg0_);
	Quat GetRotation() const;
	void Serialize(TSerialize _arg0_);
	void SetCustomOffsetFunction(std::function<Vec3_tpl<float> __cdecl(float)> _arg0_);
	void RemoveCustomOffsetFunction();
	void SetAnimationControlled();
	void SetDeathMode(const Vec3 _arg0_);
	void SetRecyclerGrenadeDeathMode(const Vec3 _arg0_);
	void ClearDeathMode();
	void AddRecoil(const Vec2 _arg0_, const float _arg1_, const float _arg2_);
	const Vec3& GetNonLeaningTargetPosition() const;
	void SetFPIKWeight(const float _arg0_);
#endif

	static inline auto FInit = PreyFunction<void(ArkPlayerCamera* const _this)>(0x145D310);
	static inline auto FReset = PreyFunction<void(ArkPlayerCamera* const _this)>(0x145DC80);
	static inline auto FGetCameraBoneLocalQuatT = PreyFunction<QuatT()>(0x145C480);
	static inline auto FLoadConfig = PreyFunction<void(ArkPlayerCamera* const _this, const XmlNodeRef& _node)>(0x145D680);
	static inline auto FPrePhysicsUpdate = PreyFunction<void(ArkPlayerCamera* const _this, const float _frameTime)>(0x145D780);
	static inline auto FSyncEyeOffsetToStanceViewHeight = PreyFunction<void(ArkPlayerCamera* const _this)>(0x145DD00);
	static inline auto FSetCustomUpdateFunction = PreyFunction<void(ArkPlayerCamera* const _this, std::function<Quat_tpl<float> __cdecl(float)> _function)>(0x123F3E0);
	static inline auto FRemoveCustomUpdateFunction = PreyFunction<void(ArkPlayerCamera* const _this, float _interpolateToUnlockTime)>(0x145DC00);
	static inline auto FSetCustomViewFunction = PreyFunction<void(ArkPlayerCamera* const _this, std::function<void __cdecl(SViewParams &)> _function)>(0x14298B0);
	static inline auto FRemoveCustomFunctions = PreyFunction<void(ArkPlayerCamera* const _this)>(0x145DC80);
	static inline auto FGetDesiredPositionAndRotation = PreyFunction<std::pair<Vec3, Quat>*(ArkPlayerCamera* const _this, std::pair<Vec3, Quat>* _return_value_, float _frameTime)>(0x145C530);
	static inline auto FIsLeaning = PreyFunction<bool(const ArkPlayerCamera* const _this)>(0x145D660);
	static inline auto FGetLeanAmount = PreyFunction<float(const ArkPlayerCamera* const _this)>(0x145D300);
	static inline auto FGetJointId = PreyFunction<int(const ArkPlayerCamera* const _this, const int _boneId)>(0x145D2A0);
	static inline auto FGetDefaultViewHeightInterpolationSpeed = PreyFunction<float(const ArkPlayerCamera* const _this)>(0x145C520);
	static inline auto FUpdateFPIK = PreyFunction<void(ArkPlayerCamera* const _this, const float _frameTime, const float _pitchWeight)>(0x145DD50);
	static inline auto FUpdateView = PreyFunction<void(ArkPlayerCamera* const _this, SViewParams& _params)>(0x145ED50);
	static inline auto FPostUpdateView = PreyFunction<void(ArkPlayerCamera* const _this, SViewParams& _params)>(0xA13080);
	static inline auto FUpdateIronsightsView = PreyFunction<boost::optional<Quat_tpl<float> >(const float _frameTime, const Vec3& _initialRotation)>(0x145E8E0);
};

