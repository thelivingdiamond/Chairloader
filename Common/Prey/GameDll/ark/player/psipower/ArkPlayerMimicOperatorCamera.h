// Header file automatically created from a PDB.
#pragma once

struct IEntity;

// ArkPlayerMimicOperatorCamera
// Header:  Prey/GameDll/ark/player/psipower/ArkPlayerMimicOperatorCamera.h
class ArkPlayerMimicOperatorCamera
{ // Size=4 (0x4)
public:
	float m_safePositionLerpCoeff;

	ArkPlayerMimicOperatorCamera();
	Vec3 CollideCamera(const float _frameTime, const IEntity& _mimicEntity, const Vec3& _basePosition, const Vec3& _desiredPositionOffset, const Vec3& _safePositionOffset) { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FCollideCamera(this, reinterpret_cast<Vec3*>(_return_buf_), _frameTime, _mimicEntity, _basePosition, _desiredPositionOffset, _safePositionOffset); }

#if 0
	float GetZeroGTransitionDuration() const;
	float GetAttackTransitionDuration() const;
	float GetInitialTransitionDuration() const;
	float GetRagdollTransitionDuration() const;
	float GetGravShaftTransitionDuration() const;
	float GetCollisionTransitionDuration() const;
#endif

	static inline auto FArkPlayerMimicOperatorCamera = PreyFunction<void(ArkPlayerMimicOperatorCamera* const _this)>(0x131EC40);
	static inline auto FCollideCamera = PreyFunction<Vec3*(ArkPlayerMimicOperatorCamera* const _this, Vec3* _return_value_, const float _frameTime, const IEntity& _mimicEntity, const Vec3& _basePosition, const Vec3& _desiredPositionOffset, const Vec3& _safePositionOffset)>(0x131EC50);
};

