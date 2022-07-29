// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicEngineeringOperatorController.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerMimicOperatorCamera.h>

class CCryName;
struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/ArkPlayerMimicEngineeringOperatorCamera.h
class ArkPlayerMimicEngineeringOperatorCamera : public ArkPlayerMimicOperatorCamera // Id=801B7ED Size=128
{
public:
	using Controller = ArkPlayerMimicEngineeringOperatorController;
	
	Quat m_rotation;
	Quat m_initialRotation;
	Quat m_mimicWorldRotation;
	Ang3 m_inputAngles;
	Vec3 m_position;
	Vec3 m_desiredPosition;
	Vec3 m_initialPositionOffset;
	ArkSimpleTimer m_lerpTimer;
	ArkPlayerMimicEngineeringOperatorController const *m_pController;
	float m_attackPositionXDir;
	bool m_bZeroG;
	bool m_bWasAttacking;
	bool m_bInGravShaft;
	
	ArkPlayerMimicEngineeringOperatorCamera();
	void Initialize(ArkPlayerMimicEngineeringOperatorController const &_controller) { FInitialize(this,_controller); }
	void Update(const float _frameTime, IEntity const &_mimicEntity) { FUpdate(this,_frameTime,_mimicEntity); }
	void SetRotation(Quat const &_rotation) { FSetRotation(this,_rotation); }
	void SetInGravShaft(const bool _bInGravShaft) { FSetInGravShaft(this,_bInGravShaft); }
	void ProcessInput(CCryName const &_actionId, const bool _bPressed) { FProcessInput(this,_actionId,_bPressed); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void RefreshInitialLerpValues(const float _lerpTimerDuration) { FRefreshInitialLerpValues(this,_lerpTimerDuration); }
	
#if 0
	Vec3 GetPosition() const;
	Quat GetRotation() const;
	void SetPosition(Vec3 const &arg0);
#endif
	
	static inline auto FInitialize = PreyFunction<void(ArkPlayerMimicEngineeringOperatorCamera *const _this, ArkPlayerMimicEngineeringOperatorController const &_controller)>(0x13141A0);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMimicEngineeringOperatorCamera *const _this, const float _frameTime, IEntity const &_mimicEntity)>(0x1314490);
	static inline auto FSetRotation = PreyFunction<void(ArkPlayerMimicEngineeringOperatorCamera *const _this, Quat const &_rotation)>(0x1314460);
	static inline auto FSetInGravShaft = PreyFunction<void(ArkPlayerMimicEngineeringOperatorCamera *const _this, const bool _bInGravShaft)>(0x1314440);
	static inline auto FProcessInput = PreyFunction<void(ArkPlayerMimicEngineeringOperatorCamera *const _this, CCryName const &_actionId, const bool _bPressed)>(0x1314260);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerMimicEngineeringOperatorCamera *const _this, TSerialize _ser)>(0x1314340);
	static inline auto FRefreshInitialLerpValues = PreyFunction<void(ArkPlayerMimicEngineeringOperatorCamera *const _this, const float _lerpTimerDuration)>(0x13142C0);
};

