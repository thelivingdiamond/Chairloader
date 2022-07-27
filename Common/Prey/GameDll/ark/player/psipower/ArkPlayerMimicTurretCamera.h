// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflect/arkreflectionaccessors.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicTurretController.h>

class CCryName;
struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/ArkPlayerMimicTurretCamera.h
class ArkPlayerMimicTurretCamera // Id=801B844 Size=72
{
public:
	using Controller = ArkPlayerMimicTurretController;
	
	enum class TurretState
	{
		Undeployed = 0,
		Deployed = 1,
		ZeroG = 2,
	};

	ArkSimpleTimer m_lerpTimer;
	Vec3 m_position;
	Ang3 m_inputAngles;
	Quat m_rotation;
	float m_reticlePitchDelta;
	ArkPlayerMimicTurretController const *m_pController;
	ArkPlayerMimicTurretCamera::TurretState m_turretState;
	
	ArkPlayerMimicTurretCamera();
	void Initialize(ArkPlayerMimicTurretController const &_controller) { FInitialize(this,_controller); }
	void Update(const float _frameTime, IEntity const &_mimicEntity) { FUpdate(this,_frameTime,_mimicEntity); }
	Quat GetRotation() const { return FGetRotation(this); }
	void SetRotation(Quat const &_rotation) { FSetRotation(this,_rotation); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	
#if 0
	Vec3 GetPosition() const;
	void SetPosition(Vec3 const &arg0);
	void SetInGravShaft(const bool arg0);
	void ProcessInput(CCryName const &arg0, const bool arg1);
#endif
	
	static inline auto FInitialize = PreyFunction<void(ArkPlayerMimicTurretCamera *const _this, ArkPlayerMimicTurretController const &_controller)>(0x17CD570);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMimicTurretCamera *const _this, const float _frameTime, IEntity const &_mimicEntity)>(0x1322230);
	static inline auto FGetRotation = PreyFunction<Quat(ArkPlayerMimicTurretCamera const *const _this)>(0x1322040);
	static inline auto FSetRotation = PreyFunction<void(ArkPlayerMimicTurretCamera *const _this, Quat const &_rotation)>(0x13221B0);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerMimicTurretCamera *const _this, TSerialize _ser)>(0x1322110);
};

