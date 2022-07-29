// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcLookDesire.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicMilitaryOperatorController.h>

class CCryName;
struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/ArkPlayerMimicMilitaryOperatorRotationController.h
class ArkPlayerMimicMilitaryOperatorRotationController // Id=801B688 Size=296
{
public:
	using Controller = ArkPlayerMimicMilitaryOperatorController;
	
	ArkNpcLookDesire m_lookDesire;
	Quat m_targetEntityRotation;
	Quat m_prevLocalLaserRotation;
	Ang3 m_laserInputAngles;
	Ang3 m_entityInputAngles;
	ArkPlayerMimicMilitaryOperatorController const &m_controller;
	float m_turnSpeed;
	
	ArkPlayerMimicMilitaryOperatorRotationController(ArkPlayerMimicMilitaryOperatorController const &_controller);
	~ArkPlayerMimicMilitaryOperatorRotationController();
	void Initialize(IEntity &_mimicEntity) { FInitialize(this,_mimicEntity); }
	void Update(const float _frameTime, IEntity &_mimicEntity) { FUpdate(this,_frameTime,_mimicEntity); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	
#if 0
	void ProcessInput(CCryName const &arg0, const bool arg1);
	Quat const &GetTargetRotation() const;
#endif
	
	static inline auto FBitNotArkPlayerMimicMilitaryOperatorRotationController = PreyFunction<void(ArkPlayerMimicMilitaryOperatorRotationController *const _this)>(0x1311360);
	static inline auto FInitialize = PreyFunction<void(ArkPlayerMimicMilitaryOperatorRotationController *const _this, IEntity &_mimicEntity)>(0x1311390);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMimicMilitaryOperatorRotationController *const _this, const float _frameTime, IEntity &_mimicEntity)>(0x13116A0);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerMimicMilitaryOperatorRotationController *const _this, TSerialize _ser)>(0x1311620);
};

