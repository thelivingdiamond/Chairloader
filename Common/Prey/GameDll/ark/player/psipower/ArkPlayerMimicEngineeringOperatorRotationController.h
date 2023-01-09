// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

class ArkPlayerMimicEngineeringOperatorController;
class CCryName;
struct IEntity;

// ArkPlayerMimicEngineeringOperatorRotationController
// Header:  Prey/GameDll/ark/player/psipower/ArkPlayerMimicEngineeringOperatorRotationController.h
class ArkPlayerMimicEngineeringOperatorRotationController
{ // Size=48 (0x30)
public:
	using Controller = ArkPlayerMimicEngineeringOperatorController;

	Quat m_targetRotation;
	Ang3 m_inputAngles;
	const ArkPlayerMimicEngineeringOperatorController& m_controller;
	float m_turnSpeed;

	ArkPlayerMimicEngineeringOperatorRotationController(const ArkPlayerMimicEngineeringOperatorController& _controller);
	void Update(const float _frameTime, IEntity& _mimicEntity) { FUpdate(this, _frameTime, _mimicEntity); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }

#if 0
	void Initialize(IEntity& _arg0_);
	void ProcessInput(const CCryName& _arg0_, const bool _arg1_);
	const Quat& GetTargetRotation() const;
#endif

	static inline auto FArkPlayerMimicEngineeringOperatorRotationControllerOv2 = PreyFunction<void(ArkPlayerMimicEngineeringOperatorRotationController* const _this, const ArkPlayerMimicEngineeringOperatorController& _controller)>(0x1315890);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMimicEngineeringOperatorRotationController* const _this, const float _frameTime, IEntity& _mimicEntity)>(0x1315910);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerMimicEngineeringOperatorRotationController* const _this, TSerialize _ser)>(0x13158C0);
};

