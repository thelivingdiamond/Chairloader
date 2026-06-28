// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/SAITurnParams.h>
#include <_unknown/SViewLimitParams.h>

struct AABB;

// SActorParams
// Header:  Prey/GameDll/actordefinitions.h
struct SActorParams
{ // Size=352 (0x160)
	enum ESpeedMultiplierReason
	{
		eSMR_Internal = 0,
		eSMR_GameRules = 1,
		eSMR_Item = 2,
		eSMR_SuitDisruptor = 3,
		eSMR_COUNT = 4,
	};

	// SActorParams::SDynamicAimPose
	// Header:  Prey/GameDll/actordefinitions.h
	struct SDynamicAimPose
	{ // Size=24 (0x18)
		string leftArmAimPose;
		string rightArmAimPose;
		string bothArmsAimPose;
	};

	SViewLimitParams viewLimits;
	Vec3 mountedWeaponCameraTarget;
	float viewFoVScale;
	float internalSpeedMult;
	float speedMultiplier[4];
	float meeleHitRagdollImpulseScale;
	float lookFOVRadians;
	float aimFOVRadians;
	float maxLookAimAngleRadians;
	bool allowLookAimStrafing;
	int cornerSmoother;
	float fallNPlayStiffness_scale;
	float sprintMultiplier;
	float sneakMultiplier;
	float strafeMultiplier;
	float backwardMultiplier;
	float jumpHeight;
	float leanShift;
	float leanAngle;
	float aimIKFadeDuration;
	float proceduralLeaningFactor;
	char animationAppendix[32];
	string footstepEffectName;
	string remoteFootstepEffectName;
	string foleyEffectName;
	string bodyFallEffectName;
	string footstepIndGearAudioSignal_Walk;
	string footstepIndGearAudioSignal_Run;
	bool footstepGearEffect;
	bool canUseComplexLookIK;
	string lookAtSimpleHeadBoneName;
	unsigned aimIKLayer;
	unsigned lookIKLayer;
	SActorParams::SDynamicAimPose idleDynamicAimPose;
	SActorParams::SDynamicAimPose runDynamicAimPose;
	float bothArmsAimHalfFOV;
	float bothArmsAimPitchFactor;
	bool useDynamicAimPoses;
	SAITurnParams AITurnParams;
	float stepThresholdDistance;
	float stepThresholdTime;
	float maxDeltaAngleRateNormal;
	float maxDeltaAngleRateAnimTarget;
	float maxDeltaAngleMultiplayer;
	float maxDeltaAngleRateJukeTurn;
	EStance defaultStance;
	bool smoothedZTurning;
	float slopeUpSlowdownMult;
	float slopeDownSlowdownMult;

	SActorParams();

	static inline auto FSActorParamsOv2 = PreyFunction<void(SActorParams* const _this)>(0x17BF550);
};

// SStanceInfo
// Header:  Prey/GameDll/actordefinitions.h
struct SStanceInfo
{ // Size=248 (0xF8)
	int physicalizeSlot;
	float heightCollider;
	float heightPivot;
	float groundContactEps;
	bool useCapsule;
	Vec3 size;
	Vec3 viewOffset;
	Vec3 leanLeftViewOffset;
	Vec3 leanRightViewOffset;
	Vec3 whileLeanedLeftViewOffset;
	Vec3 whileLeanedRightViewOffset;
	float viewDownYMod;
	Vec3 peekOverViewOffset;
	Vec3 peekOverWeaponOffset;
	Vec3 weaponOffset;
	Vec3 leanLeftWeaponOffset;
	Vec3 leanRightWeaponOffset;
	Vec3 whileLeanedLeftWeaponOffset;
	Vec3 whileLeanedRightWeaponOffset;
	float normalSpeed;
	float maxSpeed;
	float slopeUpSlowdownMin;
	float slopeUpSlowdownMax;
	float slopeDownSlowdownMin;
	float slopeDownSlowdownMax;
	char name[32];
	Vec3 modelOffset;

	Vec3 GetViewOffsetWithLean(float lean, float peekOver, bool useWhileLeanedOffsets) const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetViewOffsetWithLean(this, reinterpret_cast<Vec3*>(_return_buf_), lean, peekOver, useWhileLeanedOffsets); }

#if 0
	Vec3 GetWeaponOffsetWithLean(float _arg0_, float _arg1_, bool _arg2_) const;
	static Vec3 GetOffsetWithLean(float _arg0_, float _arg1_, const Vec3& _arg2_, const Vec3& _arg3_, const Vec3& _arg4_, const Vec3& _arg5_);
	AABB GetStanceBounds() const;
	AABB GetColliderBounds() const;
	SStanceInfo();
#endif

	static inline auto FGetViewOffsetWithLean = PreyFunction<Vec3*(const SStanceInfo* const _this, Vec3* _return_value_, float lean, float peekOver, bool useWhileLeanedOffsets)>(0x18C1D20);
};
#endif // MOONCRASH
