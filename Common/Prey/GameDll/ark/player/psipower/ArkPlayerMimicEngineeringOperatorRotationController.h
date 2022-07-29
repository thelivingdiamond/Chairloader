// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicEngineeringOperatorController.h>

class CCryName;
struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/ArkPlayerMimicEngineeringOperatorRotationController.h
class ArkPlayerMimicEngineeringOperatorRotationController // Id=801B68C Size=48
{
public:
	using Controller = ArkPlayerMimicEngineeringOperatorController;
	
	Quat m_targetRotation;
	Ang3 m_inputAngles;
	ArkPlayerMimicEngineeringOperatorController const &m_controller;
	float m_turnSpeed;
	
	ArkPlayerMimicEngineeringOperatorRotationController(ArkPlayerMimicEngineeringOperatorController const &_controller);
	void Update(const float _frameTime, IEntity &_mimicEntity) { FUpdate(this,_frameTime,_mimicEntity); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	
#if 0
	void Initialize(IEntity &arg0);
	void ProcessInput(CCryName const &arg0, const bool arg1);
	Quat const &GetTargetRotation() const;
#endif
	
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMimicEngineeringOperatorRotationController *const _this, const float _frameTime, IEntity &_mimicEntity)>(0x1315910);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerMimicEngineeringOperatorRotationController *const _this, TSerialize _ser)>(0x13158C0);
};

