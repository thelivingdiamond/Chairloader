// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>

class ArkPlayerMimicTurretController;
class CCryName;
struct IEntity;

// ArkPlayerMimicTurretCamera
// Header:  Prey/GameDll/ark/player/psipower/ArkPlayerMimicTurretCamera.h
class ArkPlayerMimicTurretCamera
{ // Size=72 (0x48)
public:
	enum class TurretState
	{
		Undeployed = 0,
		Deployed = 1,
		ZeroG = 2,
	};

	using Controller = ArkPlayerMimicTurretController;

	ArkSimpleTimer m_lerpTimer;
	Vec3 m_position;
	Ang3 m_inputAngles;
	Quat m_rotation;
	float m_reticlePitchDelta;
	const ArkPlayerMimicTurretController* m_pController;
	ArkPlayerMimicTurretCamera::TurretState m_turretState;

	ArkPlayerMimicTurretCamera();
	void Initialize(const ArkPlayerMimicTurretController& _controller) { FInitialize(this, _controller); }
	void Update(const float _frameTime, const IEntity& _mimicEntity) { FUpdate(this, _frameTime, _mimicEntity); }
	Quat GetRotation() const { alignas(Quat) std::byte _return_buf_[sizeof(Quat)]; return *FGetRotation(this, reinterpret_cast<Quat*>(_return_buf_)); }
	void SetRotation(const Quat& _rotation) { FSetRotation(this, _rotation); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }

#if 0
	Vec3 GetPosition() const;
	void SetPosition(const Vec3& _arg0_);
	void SetInGravShaft(const bool _arg0_);
	void ProcessInput(const CCryName& _arg0_, const bool _arg1_);
#endif

	static inline auto FArkPlayerMimicTurretCameraOv2 = PreyFunction<void(ArkPlayerMimicTurretCamera* const _this)>(0x1322000);
	static inline auto FInitialize = PreyFunction<void(ArkPlayerMimicTurretCamera* const _this, const ArkPlayerMimicTurretController& _controller)>(0x17CD570);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMimicTurretCamera* const _this, const float _frameTime, const IEntity& _mimicEntity)>(0x1322230);
	static inline auto FGetRotation = PreyFunction<Quat*(const ArkPlayerMimicTurretCamera* const _this, Quat* _return_value_)>(0x1322040);
	static inline auto FSetRotation = PreyFunction<void(ArkPlayerMimicTurretCamera* const _this, const Quat& _rotation)>(0x13221B0);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerMimicTurretCamera* const _this, TSerialize _ser)>(0x1322110);
};

