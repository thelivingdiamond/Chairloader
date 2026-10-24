// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/IGameObject.h>

class CAnimationPlayerProxy;
enum EAnimatedCharacterArms;
enum ECharacterMoveType   // CryEngine 5.2 IAnimatedCharacter.h
{
	eCMT_None = 0,
	eCMT_Normal,
	eCMT_Fly,
	eCMT_Swim,
	eCMT_ZeroG,
	eCMT_Impulse,
	eCMT_JumpInstant,
	eCMT_JumpAccumulate
};
enum EColliderMode;
enum EColliderModeLayer;
enum EMCMSlot;
enum EMovementControlMethod;
enum EWeaponRaisedPose;
class IActionController;
class IAnimationDatabase;
struct IAnimationGraphState;
struct SAnimatedCharacterParams;
struct SCharacterMoveRequest;
struct SGroundAlignmentParams;
struct SLandBobParams;
struct SPredictedCharacterStates;
struct SViewParams;

// IAnimatedCharacter
// Header:  _unknown/IAnimatedCharacter.h
// Include: Prey/CryAction/IAnimatedCharacter.h
struct IAnimatedCharacter : public IGameObjectExtension
{ // Size=64 (0x40)
	virtual IAnimationGraphState* GetAnimationGraphState() = 0;
	virtual void PushForcedState(const char* state) = 0;
	virtual void ClearForcedStates() = 0;
	virtual void ChangeGraph(const char* graph, int layer) = 0;
	virtual void ResetState() = 0;
	virtual void ResetInertiaCache() = 0;
	virtual IActionController* GetActionController() = 0;
	virtual const IActionController* GetActionController() const = 0;
	virtual void SetShadowCharacterSlot(int id) = 0;
	virtual void SetAnimationPlayerProxy(CAnimationPlayerProxy* proxy, int layer) = 0;
	virtual CAnimationPlayerProxy* GetAnimationPlayerProxy(int layer) = 0;
	virtual void UpdateCharacterPtrs() = 0;
	virtual void AddMovement(const SCharacterMoveRequest& request) = 0;
	virtual void SetEntityRotation(const Quat& rot) = 0;
	virtual const SPredictedCharacterStates& GetOverriddenMotionParameters() const = 0;
	virtual void SetOverriddenMotionParameters(const SPredictedCharacterStates& motionParameters) = 0;
	virtual void UseAnimationMovementForEntity(bool xyMove, bool zMove, bool rotation) = 0;
	virtual void EntityAnimMovementBlend(const Vec3& _blendAnimRootMotionXYZ, float _blendAnimRootRotation) = 0;
	virtual void EntityAnimMovementAdd(const Vec3& _blendAnimRootMotionXYZ, float _blendAnimRootRotation) = 0;
	virtual void EntityAnimPositionBlend(const Vec3& _blendAnimRootMotionXYZ) = 0;
	virtual void EntityAnimPositionAdd(const Vec3& _blendAnimRootMotionXYZ) = 0;
	virtual void EntityAnimRotationBlend(float _blendAnimRootRotation) = 0;
	virtual void EntityAnimRotationAdd(float _blendAnimRootRotation) = 0;
	virtual void EntityAnimMovementClear(bool _bPosClear, bool _bRotClear) = 0;
	virtual void SetDisableGravityOverride(bool _bDisableGravity) = 0;
	virtual void SetMoveRequestTypeOverride(ECharacterMoveType _mt) = 0;
	virtual void ClearMoveRequestTypeOverride() = 0;
	virtual void SetImmediateParamUpdate(bool _m_bImmediate) = 0;
	virtual void EnableSlopeSlowdown(bool _bEnable) = 0;
	virtual void SetHeightMotionParam(float _heightParam) = 0;
	virtual float GetHeightMotionParam() const = 0;
	virtual void EnableLegIK(bool _bEnable) = 0;
	virtual void EnableLegIKOnSlope(bool _bEnable) = 0;
	virtual const QuatT& GetAnimLocation() const = 0;
	virtual const float GetEntitySpeedHorizontal() const = 0;
	virtual const float GetEntitySpeed() const = 0;
	virtual const Vec2& GetEntityMovementDirHorizontal() const = 0;
	virtual const Vec2& GetEntityVelocityHorizontal() const = 0;
	virtual const Vec2& GetEntityAccelerationHorizontal() const = 0;
	virtual const float GetEntityTangentialAcceleration() const = 0;
	virtual const Vec3& GetExpectedEntMovement() const = 0;
	virtual float GetAngularSpeedHorizontal() const = 0;
	virtual const SAnimatedCharacterParams& GetParams() = 0;
	virtual void SetParams(const SAnimatedCharacterParams& params) = 0;
	virtual SGroundAlignmentParams& GetGroundAlignmentParams() = 0;
	virtual void SetDoMotionParams(bool doMotionParams) = 0;
	virtual int GetCurrentStance() = 0;
	virtual bool InStanceTransition() = 0;
	virtual void RequestStance(int stanceID, const char* name) = 0;
	virtual float FilterView(SViewParams& viewParams) const = 0;
	virtual EColliderMode GetPhysicalColliderMode() const = 0;
	virtual void ForceRefreshPhysicalColliderMode() = 0;
	virtual void RequestPhysicalColliderMode(EColliderMode mode, EColliderModeLayer layer, const char* tag) = 0;
	virtual void SetCharacterCollisionFlags(unsigned flags) = 0;
	virtual void SetMovementControlMethods(EMovementControlMethod horizontal, EMovementControlMethod vertical) = 0;
	virtual void SetMovementControlMethods(EMCMSlot slot, EMovementControlMethod horizontal, EMovementControlMethod vertical, const char* tag) = 0;
	virtual void EnableRigidCollider(float radius) = 0;
	virtual void DisableRigidCollider() = 0;
	virtual EMovementControlMethod GetMCMH() const = 0;
	virtual EMovementControlMethod GetMCMV() const = 0;
	virtual void EnableLandBob(const SLandBobParams& landBobParams) = 0;
	virtual void DisableLandBob() = 0;
	virtual void SetFacialAlertnessLevel(int alertness) = 0;
	virtual int GetFacialAlertnessLevel() = 0;
	virtual void AllowLookIk(bool allow, int layer) = 0;
	virtual bool IsLookIkAllowed() const = 0;
	virtual void AllowAimIk(bool allow) = 0;
	virtual bool IsAimIkAllowed() const = 0;
	virtual void AllowAnimationUpdates(bool _bAllow) = 0;
	virtual bool AreAnimationUpdatesAllowed() const = 0;
	virtual void TriggerRecoil(float duration, float kinematicImpact, float kickIn, EAnimatedCharacterArms arms) = 0;
	virtual void SetWeaponRaisedPose(EWeaponRaisedPose pose) = 0;
	virtual void SetNoMovementOverride(bool external) = 0;
	virtual float GetSlopeDegreeMoveDir() const = 0;
	virtual float GetSlopeDegree() const = 0;
	virtual void SetInGrabbedState(bool bEnable) = 0;
	virtual void ForceMovement(const QuatT& relativeMovement) = 0;
	virtual void ForceOverrideRotation(const Quat& qWorldRotation) = 0;
	virtual void SetEnableCharacterUpdate(bool _bEnable) = 0;
	virtual const IAnimationDatabase* GetAnimationDatabase1P() const = 0;
	virtual const IAnimationDatabase* GetAnimationDatabase3P() const = 0;
};

