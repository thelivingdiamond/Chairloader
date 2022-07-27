// Header file automatically created from a PDB.

#pragma once

struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/ArkPlayerMimicOperatorCamera.h
class ArkPlayerMimicOperatorCamera // Id=801B691 Size=4
{
public:
	float m_safePositionLerpCoeff;
	
	ArkPlayerMimicOperatorCamera();
	Vec3 CollideCamera(const float _frameTime, IEntity const &_mimicEntity, Vec3 const &_basePosition, Vec3 const &_desiredPositionOffset, Vec3 const &_safePositionOffset) { return FCollideCamera(this,_frameTime,_mimicEntity,_basePosition,_desiredPositionOffset,_safePositionOffset); }
	
#if 0
	float GetZeroGTransitionDuration() const;
	float GetAttackTransitionDuration() const;
	float GetInitialTransitionDuration() const;
	float GetRagdollTransitionDuration() const;
	float GetGravShaftTransitionDuration() const;
	float GetCollisionTransitionDuration() const;
#endif
	
	static inline auto FCollideCamera = PreyFunction<Vec3(ArkPlayerMimicOperatorCamera *const _this, const float _frameTime, IEntity const &_mimicEntity, Vec3 const &_basePosition, Vec3 const &_desiredPositionOffset, Vec3 const &_safePositionOffset)>(0x131EC50);
};

