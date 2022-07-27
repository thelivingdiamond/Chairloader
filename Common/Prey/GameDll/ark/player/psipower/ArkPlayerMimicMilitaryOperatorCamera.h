// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflect/arkreflectionaccessors.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicMilitaryOperatorController.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicOperatorCamera.h>

class CCryName;
struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/ArkPlayerMimicMilitaryOperatorCamera.h
class ArkPlayerMimicMilitaryOperatorCamera : public ArkPlayerMimicOperatorCamera // Id=801B7EC Size=104
{
public:
	using Controller = ArkPlayerMimicMilitaryOperatorController;
	
	Quat m_rotation;
	Quat m_mimicWorldRotation;
	Quat m_reticleRotationDelta;
	Vec3 m_position;
	Ang3 m_inputAngles;
	ArkSimpleTimer m_lerpTimer;
	ArkPlayerMimicMilitaryOperatorController const *m_pController;
	float m_attackPositionXDir;
	bool m_bWasAttacking;
	bool m_bZeroG;
	bool m_bInGravShaft;
	
	ArkPlayerMimicMilitaryOperatorCamera();
	void Initialize(ArkPlayerMimicMilitaryOperatorController const &_controller) { FInitialize(this,_controller); }
	void Update(const float _frameTime, IEntity const &_mimicEntity) { FUpdate(this,_frameTime,_mimicEntity); }
	Quat GetRotation() const { return FGetRotation(this); }
	void SetInGravShaft(const bool _bInGravShaft) { FSetInGravShaft(this,_bInGravShaft); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	
#if 0
	Vec3 GetPosition() const;
	void SetPosition(Vec3 const &arg0);
	void SetRotation(Quat const &arg0);
	void ProcessInput(CCryName const &arg0, const bool arg1) const;
#endif
	
	static inline auto FInitialize = PreyFunction<void(ArkPlayerMimicMilitaryOperatorCamera *const _this, ArkPlayerMimicMilitaryOperatorController const &_controller)>(0x130F540);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMimicMilitaryOperatorCamera *const _this, const float _frameTime, IEntity const &_mimicEntity)>(0x130F6F0);
	static inline auto FGetRotation = PreyFunction<Quat(ArkPlayerMimicMilitaryOperatorCamera const *const _this)>(0x130F400);
	static inline auto FSetInGravShaft = PreyFunction<void(ArkPlayerMimicMilitaryOperatorCamera *const _this, const bool _bInGravShaft)>(0x130F6B0);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerMimicMilitaryOperatorCamera *const _this, TSerialize _ser)>(0x130F5E0);
};

