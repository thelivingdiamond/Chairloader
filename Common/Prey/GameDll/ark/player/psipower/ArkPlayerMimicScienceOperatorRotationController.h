// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcLookDesire.h>

class ArkPlayerMimicScienceOperatorController;
class CCryName;
struct IEntity;

// ArkPlayerMimicScienceOperatorRotationController
// Header:  Prey/GameDll/ark/player/psipower/ArkPlayerMimicScienceOperatorRotationController.h
class ArkPlayerMimicScienceOperatorRotationController
{ // Size=264 (0x108)
public:
	using Controller = ArkPlayerMimicScienceOperatorController;

	ArkNpcLookDesire m_lookDesire;
	Quat m_targetRotation;
	Ang3 m_inputAngles;
	float m_turnSpeed;
	const ArkPlayerMimicScienceOperatorController& m_controller;

	ArkPlayerMimicScienceOperatorRotationController(const ArkPlayerMimicScienceOperatorController& _controller);
	void Initialize(IEntity& _mimicEntity) { FInitialize(this, _mimicEntity); }
	void Update(const float _frameTime, IEntity& _mimicEntity) { FUpdate(this, _frameTime, _mimicEntity); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }

#if 0
	void ProcessInput(const CCryName& _arg0_, const bool _arg1_);
	const Quat& GetTargetRotation() const;
#endif

	static inline auto FArkPlayerMimicScienceOperatorRotationControllerOv1 = PreyFunction<void(ArkPlayerMimicScienceOperatorRotationController* const _this, const ArkPlayerMimicScienceOperatorController& _controller)>(0x12F1FA0);
	static inline auto FInitialize = PreyFunction<void(ArkPlayerMimicScienceOperatorRotationController* const _this, IEntity& _mimicEntity)>(0x12F2110);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMimicScienceOperatorRotationController* const _this, const float _frameTime, IEntity& _mimicEntity)>(0x12F21E0);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerMimicScienceOperatorRotationController* const _this, TSerialize _ser)>(0x12F2180);
};

