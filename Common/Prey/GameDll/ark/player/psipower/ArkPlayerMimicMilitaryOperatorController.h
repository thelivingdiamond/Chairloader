// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflect/arkreflectionaccessors.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicMilitaryOperatorRotationController.h>
#include <Prey/GameDll/ark/player/psipower/arkplayermimicoperatorcontroller.h>
#include <Prey/GameDll/ark/player/psipower/arkplayermimicoperatormovementcontroller.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h>

class CCryName;
struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/ArkPlayerMimicMilitaryOperatorController.h
class ArkPlayerMimicMilitaryOperatorController : public ArkPlayerMimicOperatorController<ArkPlayerMimicMilitaryOperatorController> // Id=801B686 Size=1016
{
public:
	using Properties = ArkPsiMimicMilitaryOperatorProperties;
	using MovementController = ArkPlayerMimicOperatorMovementController<ArkPlayerMimicMilitaryOperatorController>;
	using RotationController = ArkPlayerMimicMilitaryOperatorRotationController;
	
	ArkPlayerMimicOperatorMovementController<ArkPlayerMimicMilitaryOperatorController> m_movementController;
	ArkPlayerMimicMilitaryOperatorRotationController m_rotationController;
	ArkOperatorLaserHelper m_laserHelper;
	ArkPsiMimicMilitaryOperatorProperties const &m_properties;
	
	ArkPlayerMimicMilitaryOperatorController();
	void Initialize_Derived(IEntity &_mimicEntity) { FInitialize_Derived(this,_mimicEntity); }
	void Update_Derived(const float _frameTime, IEntity &_mimicEntity) { FUpdate_Derived(this,_frameTime,_mimicEntity); }
	void ProcessInput(CCryName const &_actionId, const bool _bPressed) { FProcessInput(this,_actionId,_bPressed); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	bool IsAttacking() const { return FIsAttacking(this); }
	float GetMovementSpeed() const { return FGetMovementSpeed(this); }
	Vec3 GetLaserMuzzlePosition() const { return FGetLaserMuzzlePosition(this); }
	Quat GetLaserMuzzleRotation() const { return FGetLaserMuzzleRotation(this); }
	Vec3 GetLaserTargetPosition() const { return FGetLaserTargetPosition(this); }
	
#if 0
	void PostSerialize() const;
	Quat const &GetTargetEntityRotation() const;
	ArkPsiMimicMilitaryOperatorProperties const &GetProperties() const;
#endif
	
	static inline auto FInitialize_Derived = PreyFunction<void(ArkPlayerMimicMilitaryOperatorController *const _this, IEntity &_mimicEntity)>(0x1311000);
	static inline auto FUpdate_Derived = PreyFunction<void(ArkPlayerMimicMilitaryOperatorController *const _this, const float _frameTime, IEntity &_mimicEntity)>(0x1311150);
	static inline auto FProcessInput = PreyFunction<void(ArkPlayerMimicMilitaryOperatorController *const _this, CCryName const &_actionId, const bool _bPressed)>(0x1311080);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerMimicMilitaryOperatorController *const _this, TSerialize _ser)>(0x1311100);
	static inline auto FIsAttacking = PreyFunction<bool(ArkPlayerMimicMilitaryOperatorController const *const _this)>(0x1311060);
	static inline auto FGetMovementSpeed = PreyFunction<float(ArkPlayerMimicMilitaryOperatorController const *const _this)>(0x1310FC0);
	static inline auto FGetLaserMuzzlePosition = PreyFunction<Vec3(ArkPlayerMimicMilitaryOperatorController const *const _this)>(0x1310DE0);
	static inline auto FGetLaserMuzzleRotation = PreyFunction<Quat(ArkPlayerMimicMilitaryOperatorController const *const _this)>(0x1310E30);
	static inline auto FGetLaserTargetPosition = PreyFunction<Vec3(ArkPlayerMimicMilitaryOperatorController const *const _this)>(0x1310E80);
};

