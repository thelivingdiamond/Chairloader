// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicOperatorCamera.h>

class ArkPlayerMimicScienceOperatorController;
class CCryName;
struct IEntity;

// ArkPlayerMimicScienceOperatorCamera
// Header:  Prey/GameDll/ark/player/psipower/ArkPlayerMimicScienceOperatorCamera.h
class ArkPlayerMimicScienceOperatorCamera : public ArkPlayerMimicOperatorCamera
{ // Size=144 (0x90)
public:
	enum class OperatorAttackState
	{
		Idle = 0,
		Attacking = 1,
	};

	Quat m_rotation;
	Quat m_initialRotation;
	Quat m_mimicWorldRotation;
	Ang3 m_inputAngles;
	Vec3 m_position;
	Vec3 m_desiredPosition;
	Vec3 m_initialPositionOffset;
	Vec3 m_attackTargetPositionZeroG;
	ArkSimpleTimer m_lerpTimer;
	unsigned m_targetEntityId;
	const ArkPlayerMimicScienceOperatorController* m_pController;
	bool m_bZeroG;
	bool m_bInGravShaft;
	ArkPlayerMimicScienceOperatorCamera::OperatorAttackState m_attackState;

	ArkPlayerMimicScienceOperatorCamera();
	void Initialize(const ArkPlayerMimicScienceOperatorController& _controller) { FInitialize(this, _controller); }
	void Update(const float _frameTime, const IEntity& _mimicEntity) { FUpdate(this, _frameTime, _mimicEntity); }
	void SetPosition(const Vec3& _position) { FSetPosition(this, _position); }
	void SetRotation(const Quat& _rotation) { FSetRotation(this, _rotation); }
	void SetInGravShaft(const bool _bInGravShaft) { FSetInGravShaft(this, _bInGravShaft); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void RefreshInitialLerpValues(const float _lerpTimerDuration) { FRefreshInitialLerpValues(this, _lerpTimerDuration); }

#if 0
	Vec3 GetPosition() const;
	Quat GetRotation() const;
	void ProcessInput(const CCryName& _arg0_, const bool _arg1_);
#endif

	static inline auto FArkPlayerMimicScienceOperatorCameraOv2 = PreyFunction<void(ArkPlayerMimicScienceOperatorCamera* const _this)>(0x12EE0B0);
	static inline auto FInitialize = PreyFunction<void(ArkPlayerMimicScienceOperatorCamera* const _this, const ArkPlayerMimicScienceOperatorController& _controller)>(0x12EE300);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMimicScienceOperatorCamera* const _this, const float _frameTime, const IEntity& _mimicEntity)>(0x12EE580);
	static inline auto FSetPosition = PreyFunction<void(ArkPlayerMimicScienceOperatorCamera* const _this, const Vec3& _position)>(0x12EE560);
	static inline auto FSetRotation = PreyFunction<void(ArkPlayerMimicScienceOperatorCamera* const _this, const Quat& _rotation)>(0x1314460);
	static inline auto FSetInGravShaft = PreyFunction<void(ArkPlayerMimicScienceOperatorCamera* const _this, const bool _bInGravShaft)>(0x12EE540);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerMimicScienceOperatorCamera* const _this, TSerialize _ser)>(0x12EE440);
	static inline auto FRefreshInitialLerpValues = PreyFunction<void(ArkPlayerMimicScienceOperatorCamera* const _this, const float _lerpTimerDuration)>(0x12EE3C0);
};

