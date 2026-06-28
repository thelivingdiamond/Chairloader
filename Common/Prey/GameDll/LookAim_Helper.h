// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class CPlayer;
struct ICharacterInstance;
struct SActorParams;
struct SMovementState;

// CLookAim_Helper
// Header:  Prey/GameDll/LookAim_Helper.h
class CLookAim_Helper
{ // Size=104 (0x68)
public:
	bool m_initialized;
	bool m_canUseLookAtComplex;
	bool m_canUseLookAtSimple;
	std::shared_ptr<AnimPoseModifier::CLookAtSimple> m_lookAtSimple;
	float m_lookAtWeight;
	float m_lookAtFadeInSpeed;
	float m_lookAtFadeOutSpeed;
	Vec3 m_lookAtInterpolatedTargetGlobal;
	Vec3 m_lookAtTargetRate;
	Vec3 m_lookAtTargetGlobal;
	float m_lookAtTargetSmoothTime;
	int m_availableHandsForFiring;
	int m_lastAimPoseAnimID;
	float m_lastAimYaw;
	bool m_aimIsSwitchingArms;
	Vec3 m_vLastAimTarget;

	CLookAim_Helper();
	void UpdateLook(CPlayer* pPlayer, ICharacterInstance* pCharacter, bool bEnabled, float FOV, const Vec3& targetGlobal, const unsigned lookIKLayer) { FUpdateLook(this, pPlayer, pCharacter, bEnabled, FOV, targetGlobal, lookIKLayer); }
	void UpdateDynamicAimPoses(CPlayer* pPlayer, ICharacterInstance* pCharacter, const SActorParams& params, const bool aimEnabled, const int aimIKLayer, const Vec3& vAimTarget, const SMovementState& curMovementState) { FUpdateDynamicAimPoses(this, pPlayer, pCharacter, params, aimEnabled, aimIKLayer, vAimTarget, curMovementState); }
	void Init(CPlayer* pPlayer, ICharacterInstance* pCharacter) { FInit(this, pPlayer, pCharacter); }

#if 0
	void Reset();
	bool CanHandFire(int _arg0_) const;
#endif

	static inline auto FCLookAim_HelperOv2 = PreyFunction<void(CLookAim_Helper* const _this)>(0x1891130);
	static inline auto FUpdateLook = PreyFunction<void(CLookAim_Helper* const _this, CPlayer* pPlayer, ICharacterInstance* pCharacter, bool bEnabled, float FOV, const Vec3& targetGlobal, const unsigned lookIKLayer)>(0x18916E0);
	static inline auto FUpdateDynamicAimPoses = PreyFunction<void(CLookAim_Helper* const _this, CPlayer* pPlayer, ICharacterInstance* pCharacter, const SActorParams& params, const bool aimEnabled, const int aimIKLayer, const Vec3& vAimTarget, const SMovementState& curMovementState)>(0x1891230);
	static inline auto FInit = PreyFunction<void(CLookAim_Helper* const _this, CPlayer* pPlayer, ICharacterInstance* pCharacter)>(0x1891150);
};
#endif // MOONCRASH
