// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcLookDesire.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicScienceOperatorController.h>

class CCryName;
struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/ArkPlayerMimicScienceOperatorRotationController.h
class ArkPlayerMimicScienceOperatorRotationController // Id=801B690 Size=264
{
public:
	using Controller = ArkPlayerMimicScienceOperatorController;
	
	ArkNpcLookDesire m_lookDesire;
	Quat m_targetRotation;
	Ang3 m_inputAngles;
	float m_turnSpeed;
	ArkPlayerMimicScienceOperatorController const &m_controller;
	
	ArkPlayerMimicScienceOperatorRotationController(ArkPlayerMimicScienceOperatorController const &_controller);
	void Initialize(IEntity &_mimicEntity) { FInitialize(this,_mimicEntity); }
	void Update(const float _frameTime, IEntity &_mimicEntity) { FUpdate(this,_frameTime,_mimicEntity); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	
#if 0
	void ProcessInput(CCryName const &arg0, const bool arg1);
	Quat const &GetTargetRotation() const;
#endif
	
	static inline auto FInitialize = PreyFunction<void(ArkPlayerMimicScienceOperatorRotationController *const _this, IEntity &_mimicEntity)>(0x12F2110);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMimicScienceOperatorRotationController *const _this, const float _frameTime, IEntity &_mimicEntity)>(0x12F21E0);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerMimicScienceOperatorRotationController *const _this, TSerialize _ser)>(0x12F2180);
};

