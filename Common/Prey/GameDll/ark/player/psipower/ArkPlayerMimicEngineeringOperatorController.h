// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicEngineeringOperatorRotationController.h>
#include <Prey/GameDll/ark/player/psipower/arkplayermimicoperatorcontroller.h>
#include <Prey/GameDll/ark/player/psipower/arkplayermimicoperatormovementcontroller.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipowermimicproperties.h>

class ArkInputLegend;
class CCryName;
struct IAnimatedCharacter;
struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/ArkPlayerMimicEngineeringOperatorController.h
class ArkPlayerMimicEngineeringOperatorController : public ArkPlayerMimicOperatorController<ArkPlayerMimicEngineeringOperatorController> // Id=801B68A Size=184
{
public:
	using Properties = ArkPsiMimicEngineeringOperatorProperties;
	using MovementController = ArkPlayerMimicOperatorMovementController<ArkPlayerMimicEngineeringOperatorController>;
	using RotationController = ArkPlayerMimicEngineeringOperatorRotationController;
	
	ArkPlayerMimicOperatorMovementController<ArkPlayerMimicEngineeringOperatorController> m_movementController;
	ArkPlayerMimicEngineeringOperatorRotationController m_rotationController;
	_smart_ptr<ArkNpcAnimAction> m_pAnimAction;
	IAnimatedCharacter *m_pAnimatedCharacter;
	ArkPsiMimicEngineeringOperatorProperties const &m_properties;
	bool m_bAttacking;
	
	ArkPlayerMimicEngineeringOperatorController();
	void Initialize_Derived(IEntity &_mimicEntity) { FInitialize_Derived(this,_mimicEntity); }
	void Update_Derived(const float _frameTime, IEntity &_mimicEntity) { FUpdate_Derived(this,_frameTime,_mimicEntity); }
	void ResetModalLegend_Derived(ArkInputLegend &_inputLegend) const { FResetModalLegend_Derived(this,_inputLegend); }
	void ProcessInput(CCryName const &_actionId, const bool _bPressed) { FProcessInput(this,_actionId,_bPressed); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	bool IsAttacking() const { return FIsAttacking(this); }
	float GetMovementSpeed() const { return FGetMovementSpeed(this); }
	Quat GetMimicTargetRotation() const { return FGetMimicTargetRotation(this); }
	ArkPsiMimicEngineeringOperatorProperties const &GetProperties() const { return FGetProperties(this); }
	
#if 0
	void PostSerialize() const;
#endif
	
	static inline auto FInitialize_Derived = PreyFunction<void(ArkPlayerMimicEngineeringOperatorController *const _this, IEntity &_mimicEntity)>(0x1315380);
	static inline auto FUpdate_Derived = PreyFunction<void(ArkPlayerMimicEngineeringOperatorController *const _this, const float _frameTime, IEntity &_mimicEntity)>(0x13156C0);
	static inline auto FResetModalLegend_Derived = PreyFunction<void(ArkPlayerMimicEngineeringOperatorController const *const _this, ArkInputLegend &_inputLegend)>(0x1315640);
	static inline auto FProcessInput = PreyFunction<void(ArkPlayerMimicEngineeringOperatorController *const _this, CCryName const &_actionId, const bool _bPressed)>(0x13154D0);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerMimicEngineeringOperatorController *const _this, TSerialize _ser)>(0x1315670);
	static inline auto FIsAttacking = PreyFunction<bool(ArkPlayerMimicEngineeringOperatorController const *const _this)>(0x9DFD20);
	static inline auto FGetMovementSpeed = PreyFunction<float(ArkPlayerMimicEngineeringOperatorController const *const _this)>(0x1315330);
	static inline auto FGetMimicTargetRotation = PreyFunction<Quat(ArkPlayerMimicEngineeringOperatorController const *const _this)>(0x1315310);
	static inline auto FGetProperties = PreyFunction<ArkPsiMimicEngineeringOperatorProperties const &(ArkPlayerMimicEngineeringOperatorController const *const _this)>(0x1315370);
};

