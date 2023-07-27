// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/ArkCommon/ArkInterval.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/ui/ArkInputLegend.h>
#include <Prey/GameDll/ark/ui/ArkInputLegendHandler.h>

class ArkPlayer;
class ArkPlayerMovementFSM;
enum class EStance;
struct EventPhysCollision;
struct IEntity;
struct IParticleEffect;
class XmlNodeRef;

namespace ArkPlayerMovementStates
{

// ArkPlayerMovementStates::Base
// Header:  Prey/GameDll/ark/player/ArkPlayerMovementStates.h
class Base
{ // Size=1 (0x1)
public:
	static void ProcessRotation(const ArkPlayerMovementFSM& _fsm, Quat& _rotation, const Ang3 _inputRotation) { FProcessRotation(_fsm, _rotation, _inputRotation); }
	static void LimitRotation(const ArkPlayerMovementFSM& _fsm, Quat& _rotation) { FLimitRotation(_fsm, _rotation); }
	static void ApplyBleedingMovementDamage(ArkPlayer& _player, const float _damage) { FApplyBleedingMovementDamage(_player, _damage); }
	static Vec2 GetMovementInput(const ArkPlayer& _player) { return FGetMovementInput(_player); }
	static float GetViewHeightInterpolationSpeed(const ArkPlayer& _player) { return FGetViewHeightInterpolationSpeed(_player); }

#if 0
	static void OnStepStop();
	static void Enter();
	static void Exit();
	static bool QueuesJump(const ArkPlayerMovementFSM& _arg0_);
	static bool AllowsJump(const ArkPlayerMovementFSM& _arg0_);
	static bool IsSprinting(const ArkPlayerMovementFSM& _arg0_);
	static void OnSneakButtonPressed(ArkPlayerMovementFSM& _arg0_);
	static Ang3 GetCameraRotationInfluence(const ArkPlayerMovementFSM& _arg0_, const float _arg1_);
	static void Update(ArkPlayerMovementFSM& _arg0_, const float _arg1_);
	static float GetFPIKPitchWeight(const ArkPlayerMovementFSM& _arg0_);
	static float GetLeanInput(const ArkPlayerMovementFSM& _arg0_);
#endif

	static inline auto FProcessRotation = PreyFunction<void(const ArkPlayerMovementFSM& _fsm, Quat& _rotation, const Ang3 _inputRotation)>(0x1571460);
	static inline auto FLimitRotation = PreyFunction<void(const ArkPlayerMovementFSM& _fsm, Quat& _rotation)>(0x123BC50);
	static inline auto FApplyBleedingMovementDamage = PreyFunction<void(ArkPlayer& _player, const float _damage)>(0x12399C0);
	static inline auto FGetMovementInput = PreyFunction<Vec2(const ArkPlayer& _player)>(0x123BBE0);
	static inline auto FGetViewHeightInterpolationSpeed = PreyFunction<float(const ArkPlayer& _player)>(0x123BC30);
};

// ArkPlayerMovementStates::GravShaft
// Header:  Prey/GameDll/ark/player/ArkPlayerMovementStates.h
class GravShaft : public ArkPlayerMovementStates::Base
{ // Size=16 (0x10)
public:
	Quat m_desiredViewRotation;

#if 0
	GravShaft();
	void ProcessRotation(const ArkPlayerMovementFSM& _arg0_, Quat& _arg1_, const Ang3 _arg2_);
	static void LimitRotation(const ArkPlayerMovementFSM& _arg0_, Quat& _arg1_);
#endif
};

// ArkPlayerMovementStates::Cinematic
// Header:  Prey/GameDll/ark/player/ArkPlayerMovementStates.h
class Cinematic : public ArkPlayerMovementStates::Base
{ // Size=12 (0xC)
public:
	Ang3 m_cameraAdditive;

	void Enter() { FEnter(this); }
	void Exit() { FExit(this); }
	void Update(ArkPlayerMovementFSM& _fsm, const float _frameTime) { FUpdate(this, _fsm, _frameTime); }
	void ProcessRotation(const ArkPlayerMovementFSM& _fsm, Quat& _rotation, const Ang3 _inputRotation) { FProcessRotation(this, _fsm, _rotation, _inputRotation); }

#if 0
	Cinematic();
	Ang3 GetCameraRotationInfluence(const ArkPlayerMovementFSM& _arg0_, const float _arg1_);
#endif

	static inline auto FEnter = PreyFunction<void(ArkPlayerMovementStates::Cinematic* const _this)>(0x1239A40);
	static inline auto FExit = PreyFunction<void(ArkPlayerMovementStates::Cinematic* const _this)>(0x123AFF0);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMovementStates::Cinematic* const _this, ArkPlayerMovementFSM& _fsm, const float _frameTime)>(0x1240560);
	static inline auto FProcessRotation = PreyFunction<void(ArkPlayerMovementStates::Cinematic* const _this, const ArkPlayerMovementFSM& _fsm, Quat& _rotation, const Ang3 _inputRotation)>(0x123D280);
};

// ArkPlayerMovementStates::Climb
// Header:  Prey/GameDll/ark/player/ArkPlayerMovementStates.h
class Climb : public ArkPlayerMovementStates::Base
{ // Size=40 (0x28)
public:
	_smart_ptr<TAction<SAnimationContext> > m_pClimbAction;
	Vec3 m_targetPos;
	Vec3 m_cachedVelocity;
	float m_mediumToHighThreshold;
	bool m_bHighClimb;

	void Enter(Vec3 _targetPos) { FEnter(this, _targetPos); }
	void Update(ArkPlayerMovementFSM& _fsm, const float _frameTime) { FUpdate(this, _fsm, _frameTime); }
	void Exit() { FExit(this); }
	void LoadConfig(const XmlNodeRef& _root) { FLoadConfig(this, _root); }

#if 0
	Climb();
	Vec2 GetInputMovement(const ArkPlayer& _arg0_) const;
	bool IsAHighClimb() const;
	static bool QueuesJump(const ArkPlayerMovementFSM& _arg0_);
#endif

	static inline auto FEnter = PreyFunction<void(ArkPlayerMovementStates::Climb* const _this, Vec3 _targetPos)>(0x1239A80);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMovementStates::Climb* const _this, ArkPlayerMovementFSM& _fsm, const float _frameTime)>(0x1240620);
	static inline auto FExit = PreyFunction<void(ArkPlayerMovementStates::Climb* const _this)>(0x123B010);
	static inline auto FLoadConfig = PreyFunction<void(ArkPlayerMovementStates::Climb* const _this, const XmlNodeRef& _root)>(0x123C7F0);
};

// ArkPlayerMovementStates::Death
// Header:  Prey/GameDll/ark/player/ArkPlayerMovementStates.h
class Death : public ArkPlayerMovementStates::Base
{ // Size=48 (0x30)
public:
	ArkSimpleTimer m_deathCamDelay;
	ArkSimpleTimer m_fullSlowTimer;
	ArkSimpleTimer m_rampUpSpeedTimer;
	float m_deathCamProbability;
	float m_idealDeathCamDistance;
	float m_idealDeathCamAngle;
	float m_deathCamGravityMinAngle;
	float m_timeScaleAmount;
	int m_timeScaleHandle;

	void Enter(const float _verticalSpeed) { FEnter(this, _verticalSpeed); }
	void Exit() { FExit(this); }
	void Update(ArkPlayerMovementFSM& _fsm, const float _frameTime) { FUpdate(this, _fsm, _frameTime); }

#if 0
	Death();
	void LoadConfig(const XmlNodeRef& _arg0_);
#endif

	static inline auto FEnter = PreyFunction<void(ArkPlayerMovementStates::Death* const _this, const float _verticalSpeed)>(0x1239E00);
	static inline auto FExit = PreyFunction<void(ArkPlayerMovementStates::Death* const _this)>(0x123B380);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMovementStates::Death* const _this, ArkPlayerMovementFSM& _fsm, const float _frameTime)>(0x12407F0);
};

// ArkPlayerMovementStates::DeathByRecyclerGrenade
// Header:  Prey/GameDll/ark/player/ArkPlayerMovementStates.h
class DeathByRecyclerGrenade : public ArkPlayerMovementStates::Base
{ // Size=96 (0x60)
public:
	ArkSimpleTimer m_deathTimer;
	uint64_t m_postProcessEffectId;
	uint64_t m_gammaParamId;
	ArkInterval<float> m_gammaValues;
	uint64_t m_brightnessParamId;
	ArkInterval<float> m_brightnessValues;
	uint64_t m_saturationParamId;
	ArkInterval<float> m_saturationValues;
	_smart_ptr<IParticleEmitter> m_emitter;
	string m_effectName;
	string m_scaleName;
	ArkInterval<float> m_scaleValues;

	void Enter() { FEnter(this); }
	void Exit() { FExit(this); }
	void Update(ArkPlayerMovementFSM& _fsm, const float _frameTime) { FUpdate(this, _fsm, _frameTime); }
	void LoadConfig(const XmlNodeRef& _root) { FLoadConfig(this, _root); }
	void UpdatePostEffectParam(const uint64_t _paramId, const ArkInterval<float> _values, const float _timeFactor) { FUpdatePostEffectParam(this, _paramId, _values, _timeFactor); }

#if 0
	DeathByRecyclerGrenade();
#endif

	static inline auto FEnter = PreyFunction<void(ArkPlayerMovementStates::DeathByRecyclerGrenade* const _this)>(0x123A000);
	static inline auto FExit = PreyFunction<void(ArkPlayerMovementStates::DeathByRecyclerGrenade* const _this)>(0x123B460);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMovementStates::DeathByRecyclerGrenade* const _this, ArkPlayerMovementFSM& _fsm, const float _frameTime)>(0x1240C20);
	static inline auto FLoadConfig = PreyFunction<void(ArkPlayerMovementStates::DeathByRecyclerGrenade* const _this, const XmlNodeRef& _root)>(0x1570DF0);
	static inline auto FUpdatePostEffectParam = PreyFunction<void(ArkPlayerMovementStates::DeathByRecyclerGrenade* const _this, const uint64_t _paramId, const ArkInterval<float> _values, const float _timeFactor)>(0x1244BA0);
};

// ArkPlayerMovementStates::Fall
// Header:  Prey/GameDll/ark/player/ArkPlayerMovementStates.h
class Fall : public ArkPlayerMovementStates::Base
{ // Size=40 (0x28)
public:
	uint64_t m_package;
	ArkTimeRemaining m_propulsionForceDuration;
	ArkAudioTrigger m_audioTrigger;
	float m_fatalSpeed;
	float m_safeSpeed;
	float m_traumaDmgSpeed;
	float m_BigBumpSpeed;
	bool m_bSneakOnExit;
	bool m_bAirControlEnabled;

	void Enter() { FEnter(this); }
	void Exit() { FExit(this); }
	void Update(ArkPlayerMovementFSM& _fsm, const float _frameTime) { FUpdate(this, _fsm, _frameTime); }
	void OnCollision(const EventPhysCollision& _event) { FOnCollision(this, _event); }

#if 0
	Fall();
	void LoadConfig(const XmlNodeRef& _arg0_);
	void OnSneakButtonPressed(ArkPlayerMovementFSM& _arg0_);
	static bool QueuesJump(const ArkPlayerMovementFSM& _arg0_);
#endif

	static inline auto FEnter = PreyFunction<void(ArkPlayerMovementStates::Fall* const _this)>(0x123A340);
	static inline auto FExit = PreyFunction<void(ArkPlayerMovementStates::Fall* const _this)>(0x123B4C0);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMovementStates::Fall* const _this, ArkPlayerMovementFSM& _fsm, const float _frameTime)>(0x1240D30);
	static inline auto FOnCollision = PreyFunction<void(ArkPlayerMovementStates::Fall* const _this, const EventPhysCollision& _event)>(0x123D160);
};

// ArkPlayerMovementStates::Fly
// Header:  Prey/GameDll/ark/player/ArkPlayerMovementStates.h
class Fly : public ArkPlayerMovementStates::Base
{ // Size=1 (0x1)
public:
	static void Update(ArkPlayerMovementFSM& _fsm, const float _frameTime) { FUpdate(_fsm, _frameTime); }
	static void Exit() { FExit(); }

	static inline auto FUpdate = PreyFunction<void(ArkPlayerMovementFSM& _fsm, const float _frameTime)>(0xA13080);
	static inline auto FExit = PreyFunction<void()>(0x123B560);
};

// ArkPlayerMovementStates::GravShaftG
// Header:  Prey/GameDll/ark/player/ArkPlayerMovementStates.h
class GravShaftG : public ArkPlayerMovementStates::GravShaft
{ // Size=16 (0x10)
public:
	void Enter() { FEnter(this); }
	void SetDesiredViewDirection(const Vec3& _direction) { FSetDesiredViewDirection(this, _direction); }
	void Update(ArkPlayerMovementFSM& _fsm, const float _frameTime) const { FUpdate(this, _fsm, _frameTime); }

#if 0
	static float GetFPIKPitchWeight(const ArkPlayerMovementFSM& _arg0_);
#endif

	static inline auto FEnter = PreyFunction<void(ArkPlayerMovementStates::GravShaftG* const _this)>(0x123A380);
	static inline auto FSetDesiredViewDirection = PreyFunction<void(ArkPlayerMovementStates::GravShaftG* const _this, const Vec3& _direction)>(0x123F590);
	static inline auto FUpdate = PreyFunction<void(const ArkPlayerMovementStates::GravShaftG* const _this, ArkPlayerMovementFSM& _fsm, const float _frameTime)>(0x1241590);
};

// ArkPlayerMovementStates::GravShaftToG
// Header:  Prey/GameDll/ark/player/ArkPlayerMovementStates.h
class GravShaftToG : public ArkPlayerMovementStates::GravShaft
{ // Size=32 (0x20)
public:
	Quat m_desiredEntityRotation;

	void SetDesiredViewDirection(const Vec3& _direction) { FSetDesiredViewDirection(this, _direction); }
	void Enter() { FEnter(this); }
	void Exit() { FExit(this); }
	float GetViewHeightInterpolationSpeed(const ArkPlayer& _player) const { return FGetViewHeightInterpolationSpeed(this, _player); }
	void Update(ArkPlayerMovementFSM& _fsm, const float _frameTime) const { FUpdate(this, _fsm, _frameTime); }
	static float GetFPIKPitchWeight(const ArkPlayerMovementFSM& _fsm) { return FGetFPIKPitchWeight(_fsm); }

#if 0
	GravShaftToG();
#endif

	static inline auto FSetDesiredViewDirection = PreyFunction<void(ArkPlayerMovementStates::GravShaftToG* const _this, const Vec3& _direction)>(0x123F750);
	static inline auto FEnter = PreyFunction<void(ArkPlayerMovementStates::GravShaftToG* const _this)>(0x123A410);
	static inline auto FExit = PreyFunction<void(ArkPlayerMovementStates::GravShaftToG* const _this)>(0x123B580);
	static inline auto FGetViewHeightInterpolationSpeed = PreyFunction<float(const ArkPlayerMovementStates::GravShaftToG* const _this, const ArkPlayer& _player)>(0x123BC40);
	static inline auto FUpdate = PreyFunction<void(const ArkPlayerMovementStates::GravShaftToG* const _this, ArkPlayerMovementFSM& _fsm, const float _frameTime)>(0x12419A0);
	static inline auto FGetFPIKPitchWeight = PreyFunction<float(const ArkPlayerMovementFSM& _fsm)>(0x123BA90);
};

// ArkPlayerMovementStates::GravShaftZeroG
// Header:  Prey/GameDll/ark/player/ArkPlayerMovementStates.h
class GravShaftZeroG : public ArkPlayerMovementStates::GravShaft
{ // Size=16 (0x10)
public:
	void SetDesiredViewDirection(const Vec3& _direction) { FSetDesiredViewDirection(this, _direction); }
	void Enter() { FEnter(this); }
	float GetViewHeightInterpolationSpeed(const ArkPlayer& _player) const { return FGetViewHeightInterpolationSpeed(this, _player); }
	void Update(ArkPlayerMovementFSM& _fsm, const float _frameTime) const { FUpdate(this, _fsm, _frameTime); }
	void ProcessRotation(const ArkPlayerMovementFSM& _fsm, Quat& _rotation, const Ang3 _inputRotation) { FProcessRotation(this, _fsm, _rotation, _inputRotation); }

#if 0
	static float GetFPIKPitchWeight(const ArkPlayerMovementFSM& _arg0_);
#endif

	static inline auto FSetDesiredViewDirection = PreyFunction<void(ArkPlayerMovementStates::GravShaftZeroG* const _this, const Vec3& _direction)>(0x123FC10);
	static inline auto FEnter = PreyFunction<void(ArkPlayerMovementStates::GravShaftZeroG* const _this)>(0x123A4A0);
	static inline auto FGetViewHeightInterpolationSpeed = PreyFunction<float(const ArkPlayerMovementStates::GravShaftZeroG* const _this, const ArkPlayer& _player)>(0x123BC40);
	static inline auto FUpdate = PreyFunction<void(const ArkPlayerMovementStates::GravShaftZeroG* const _this, ArkPlayerMovementFSM& _fsm, const float _frameTime)>(0x1242030);
	static inline auto FProcessRotation = PreyFunction<void(ArkPlayerMovementStates::GravShaftZeroG* const _this, const ArkPlayerMovementFSM& _fsm, Quat& _rotation, const Ang3 _inputRotation)>(0x123D610);
};

// ArkPlayerMovementStates::Jump
// Header:  Prey/GameDll/ark/player/ArkPlayerMovementStates.h
class Jump : public ArkPlayerMovementStates::Base
{ // Size=44 (0x2C)
public:
	ArkAudioTrigger m_audioTrigger;
	ArkAudioTrigger m_audioTriggerPlay;
	ArkAudioSwitch m_mobilityAbilitySwitch;
	std::array<ArkAudioSwitchState,3> m_mobilityAbilityStates;
	float m_minJumpHeight;
	float m_bonusVelocity;
	float m_startHeight;
	ArkSimpleTimer m_maxJumpTimer;

	void Update(ArkPlayerMovementFSM& _fsm, const float _frameTime) { FUpdate(this, _fsm, _frameTime); }
	void Enter() { FEnter(this); }

#if 0
	Jump();
	void LoadConfig(const XmlNodeRef& _arg0_);
	float GetStartHeight() const;
#endif

	static inline auto FUpdate = PreyFunction<void(ArkPlayerMovementStates::Jump* const _this, ArkPlayerMovementFSM& _fsm, const float _frameTime)>(0x1242080);
	static inline auto FEnter = PreyFunction<void(ArkPlayerMovementStates::Jump* const _this)>(0x123A4C0);
};

// ArkPlayerMovementStates::Lift
// Header:  Prey/GameDll/ark/player/ArkPlayerMovementStates.h
class Lift : public ArkPlayerMovementStates::Base
{ // Size=144 (0x90)
public:
	ArkLooseEffect m_particleEffect;
	string m_particleEffectPath;
	float m_inputMovementSpeed;
	float m_propulsionMovementSpeed;
	float m_upwardDamageSpeed;
	uint64_t m_upwardDamagePackageId;

	Lift();
	void Enter() { FEnter(this); }
	void Exit() { FExit(this); }
	void LoadConfig(const XmlNodeRef& _root) { FLoadConfig(this, _root); }
	void Update(ArkPlayerMovementFSM& _fsm, const float _frameTime) { FUpdate(this, _fsm, _frameTime); }
	void OnCollision(ArkPlayerMovementFSM& _fsm, const EventPhysCollision& _event) { FOnCollision(this, _fsm, _event); }

	static inline auto FLiftOv2 = PreyFunction<void(ArkPlayerMovementStates::Lift* const _this)>(0x12390B0);
	static inline auto FEnter = PreyFunction<void(ArkPlayerMovementStates::Lift* const _this)>(0x123A8F0);
	static inline auto FExit = PreyFunction<void(ArkPlayerMovementStates::Lift* const _this)>(0x123B620);
	static inline auto FLoadConfig = PreyFunction<void(ArkPlayerMovementStates::Lift* const _this, const XmlNodeRef& _root)>(0x123C810);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMovementStates::Lift* const _this, ArkPlayerMovementFSM& _fsm, const float _frameTime)>(0x1242300);
	static inline auto FOnCollision = PreyFunction<void(ArkPlayerMovementStates::Lift* const _this, ArkPlayerMovementFSM& _fsm, const EventPhysCollision& _event)>(0x123D180);
};

// ArkPlayerMovementStates::Mimic
// Header:  Prey/GameDll/ark/player/ArkPlayerMovementStates.h
class Mimic : public ArkPlayerMovementStates::Base
{ // Size=1 (0x1)
public:
	void Enter() { FEnter(this); }
	void Exit() { FExit(this); }

#if 0
	static void LimitRotation(const ArkPlayerMovementFSM& _arg0_, Quat& _arg1_);
	static float GetFPIKPitchWeight(const ArkPlayerMovementFSM& _arg0_);
#endif

	static inline auto FEnter = PreyFunction<void(ArkPlayerMovementStates::Mimic* const _this)>(0x123A920);
	static inline auto FExit = PreyFunction<void(ArkPlayerMovementStates::Mimic* const _this)>(0x123B630);
};

// ArkPlayerMovementStates::Shift
// Header:  Prey/GameDll/ark/player/ArkPlayerMovementStates.h
class Shift : public ArkPlayerMovementStates::Base
{ // Size=56 (0x38)
public:
	ArkSimpleTimer m_shiftTimer;
	Vec3 m_targetPosition;
	Quat m_targetRotation;
	float m_speed;
	float m_shiftForwardFov;
	float m_shiftBackwardFov;
	int m_zoomHandle;
	bool m_bZeroG;

	Shift();
	void Stop() { FStop(this); }
	void SetTargetPosition(const Vec3& _position) { FSetTargetPosition(this, _position); }
	void SetTargetRotation(const Quat& _rotation) { FSetTargetRotation(this, _rotation); }
	void Enter() { FEnter(this); }
	void Exit() { FExit(this); }
	void Update(ArkPlayerMovementFSM& _fsm, const float _frameTime) { FUpdate(this, _fsm, _frameTime); }
	void LoadConfig(const XmlNodeRef& _root) { FLoadConfig(this, _root); }
	void LimitRotation(const ArkPlayerMovementFSM& _fsm, Quat& _rotation) const { FLimitRotation(this, _fsm, _rotation); }
	float GetFPIKPitchWeight(const ArkPlayerMovementFSM& _fsm) const { return FGetFPIKPitchWeight(this, _fsm); }

	static inline auto FShiftOv2 = PreyFunction<void(ArkPlayerMovementStates::Shift* const _this)>(0x12390E0);
	static inline auto FStop = PreyFunction<void(ArkPlayerMovementStates::Shift* const _this)>(0x1240490);
	static inline auto FSetTargetPosition = PreyFunction<void(ArkPlayerMovementStates::Shift* const _this, const Vec3& _position)>(0x12401A0);
	static inline auto FSetTargetRotation = PreyFunction<void(ArkPlayerMovementStates::Shift* const _this, const Quat& _rotation)>(0x1240290);
	static inline auto FEnter = PreyFunction<void(ArkPlayerMovementStates::Shift* const _this)>(0x123A970);
	static inline auto FExit = PreyFunction<void(ArkPlayerMovementStates::Shift* const _this)>(0x123B6B0);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMovementStates::Shift* const _this, ArkPlayerMovementFSM& _fsm, const float _frameTime)>(0x1242560);
	static inline auto FLoadConfig = PreyFunction<void(ArkPlayerMovementStates::Shift* const _this, const XmlNodeRef& _root)>(0x123C8E0);
	static inline auto FLimitRotation = PreyFunction<void(const ArkPlayerMovementStates::Shift* const _this, const ArkPlayerMovementFSM& _fsm, Quat& _rotation)>(0x123C320);
	static inline auto FGetFPIKPitchWeight = PreyFunction<float(const ArkPlayerMovementStates::Shift* const _this, const ArkPlayerMovementFSM& _fsm)>(0x123BB00);
};

// ArkPlayerMovementStates::Slide
// Header:  Prey/GameDll/ark/player/ArkPlayerMovementStates.h
class Slide : public ArkPlayerMovementStates::Base
{ // Size=8 (0x8)
public:
	_smart_ptr<TAction<SAnimationContext> > m_pAction;

	void Update(ArkPlayerMovementFSM& _fsm, const float _frameTime) { FUpdate(this, _fsm, _frameTime); }
	void Enter() { FEnter(this); }
	void Exit() const { FExit(this); }
	static void LimitRotation(const ArkPlayerMovementFSM& _fsm, Quat& _rotation) { FLimitRotation(_fsm, _rotation); }
	static void Stand(ArkPlayerMovementFSM& _fsm) { FStand(_fsm); }

#if 0
	Slide();
	void OnSneakButtonPressed(ArkPlayerMovementFSM& _arg0_) const;
	static bool AllowsJump(const ArkPlayerMovementFSM& _arg0_);
#endif

	static inline auto FUpdate = PreyFunction<void(ArkPlayerMovementStates::Slide* const _this, ArkPlayerMovementFSM& _fsm, const float _frameTime)>(0x1242840);
	static inline auto FEnter = PreyFunction<void(ArkPlayerMovementStates::Slide* const _this)>(0x123ABA0);
	static inline auto FExit = PreyFunction<void(const ArkPlayerMovementStates::Slide* const _this)>(0x123B700);
	static inline auto FLimitRotation = PreyFunction<void(const ArkPlayerMovementFSM& _fsm, Quat& _rotation)>(0x123C340);
	static inline auto FStand = PreyFunction<void(ArkPlayerMovementFSM& _fsm)>(0x1240430);
};

// ArkPlayerMovementStates::Smoke
// Header:  Prey/GameDll/ark/player/ArkPlayerMovementStates.h
class Smoke : public ArkPlayerMovementStates::Base
{ // Size=12 (0xC)
public:
	float m_speed;
	float m_inertia;
	float m_maxHeight;

	void LoadConfig(const XmlNodeRef& _root) { FLoadConfig(this, _root); }
	void Update(ArkPlayerMovementFSM& _fsm, const float _frameTime) const { FUpdate(this, _fsm, _frameTime); }
	void ProcessRotation(const ArkPlayerMovementFSM& _fsm, Quat& _rotation, const Ang3 _inputRotation) { FProcessRotation(this, _fsm, _rotation, _inputRotation); }
	void Enter() { FEnter(this); }
	static void Exit() { FExit(); }

#if 0
	Smoke();
	static void LimitRotation(const ArkPlayerMovementFSM& _arg0_, Quat& _arg1_);
#endif

	static inline auto FLoadConfig = PreyFunction<void(ArkPlayerMovementStates::Smoke* const _this, const XmlNodeRef& _root)>(0x123C940);
	static inline auto FUpdate = PreyFunction<void(const ArkPlayerMovementStates::Smoke* const _this, ArkPlayerMovementFSM& _fsm, const float _frameTime)>(0x1242ED0);
	static inline auto FProcessRotation = PreyFunction<void(ArkPlayerMovementStates::Smoke* const _this, const ArkPlayerMovementFSM& _fsm, Quat& _rotation, const Ang3 _inputRotation)>(0x123D980);
	static inline auto FEnter = PreyFunction<void(ArkPlayerMovementStates::Smoke* const _this)>(0x123ACA0);
	static inline auto FExit = PreyFunction<void()>(0x123B790);
};

// ArkPlayerMovementStates::ZeroG
// Header:  Prey/GameDll/ark/player/ArkPlayerMovementStates.h
class ZeroG : public ArkPlayerMovementStates::Base
{ // Size=392 (0x188)
public:
	enum class ArkZeroGState
	{
		normal = 0,
		cruise = 1,
		sprint = 2,
		max = 3,
	};

	// ArkPlayerMovementStates::ZeroG::ZeroGParams
	// Header:  Prey/GameDll/ark/player/ArkPlayerMovementStates.h
	class ZeroGParams
	{ // Size=56 (0x38)
	public:
		string m_maxSpeedStat;
		Vec3 m_baseAccel;
		float m_minDragSpeed;
		float m_maxDragSpeed;
		float m_drag;
		float m_baseDecel;
		float m_velocityLerp;
		float m_counterThrustAngle;
		float m_counterThrustSpeed;
		float m_brakingRatio;
		float m_yawPitchFactor;

		ZeroGParams(const XmlNodeRef& _root);
		float GetMaxSpeed() const { return FGetMaxSpeed(this); }

	#if 0
		ZeroGParams();
		Vec3 GetBaseAccel() const;
		float GetMinDragSpeed() const;
		float GetMaxDragSpeed() const;
		float GetDrag() const;
		float GetBaseDecel() const;
		float GetVelocityLerp() const;
		float GetCounterThrustAngle() const;
		float GetCounterThrustSpeed() const;
		float GetBrakingRatio() const;
		float GetYawPitchFactor() const;
	#endif

		static inline auto FZeroGParamsOv2 = PreyFunction<void(ArkPlayerMovementStates::ZeroG::ZeroGParams* const _this, const XmlNodeRef& _root)>(0x1239120);
		static inline auto FGetMaxSpeed = PreyFunction<float(const ArkPlayerMovementStates::ZeroG::ZeroGParams* const _this)>(0x123BB10);
	};

	// ArkPlayerMovementStates::ZeroG::RollParams
	// Header:  Prey/GameDll/ark/player/ArkPlayerMovementStates.h
	class RollParams
	{ // Size=16 (0x10)
	public:
		float m_velocity;
		float m_acceleration;
		float m_deceleration;
		float m_yInputDeadzone;

	#if 0
		RollParams();
		RollParams(const XmlNodeRef& _arg0_);
		float GetVelocity() const;
		float GetAcceleration() const;
		float GetDeceleration() const;
		float GetYInputDeadzone() const;
	#endif
	};

	// ArkPlayerMovementStates::ZeroG::AlignParams
	// Header:  Prey/GameDll/ark/player/ArkPlayerMovementStates.h
	class AlignParams
	{ // Size=8 (0x8)
	public:
		float m_distance;
		float m_rate;

	#if 0
		AlignParams();
		AlignParams(const XmlNodeRef& _arg0_);
		float GetDistance() const;
		float GetRate() const;
	#endif
	};

	std::array<ArkPlayerMovementStates::ZeroG::ZeroGParams,3> m_params;
	Vec3 m_normalToAlignGround;
	ArkPlayerMovementStates::ZeroG::RollParams m_rollParams;
	ArkPlayerMovementStates::ZeroG::AlignParams m_alignParams;
	_smart_ptr<TAction<SAnimationContext> > m_pOutAction;
	IParticleEffect* m_pEffect;
	float m_speed;
	float m_rollSpeed;
	float m_maxCollisionAngle;
	bool m_bOnGround;
	bool m_bSprinting;
	bool m_bAscending;
	bool m_bDescending;
	bool m_bBraking;
	bool m_bRolling;
	uint64_t m_gameNoiseTypeId;
	uint64_t m_gameNoiseLoudness;
	int m_movementGameNoiseId;
	_smart_ptr<IParticleEmitter> m_pEffectEmitter;
	ArkAudioTrigger m_triggerControl;
	ArkAudioTrigger m_triggerBoost;
	ArkAudioTrigger m_triggerLand;
	ArkAudioTrigger m_triggerBoostStop;
	ArkAudioTrigger m_triggerAscend;
	ArkAudioTrigger m_triggerAscendStop;
	ArkAudioTrigger m_triggerDescend;
	ArkAudioTrigger m_triggerDescendStop;
	ArkAudioTrigger m_triggerBrake;
	ArkAudioRtpc m_rtpcThrustLR;
	ArkAudioRtpc m_rtpcThrustFB;
	ArkAudioRtpc m_rtpcRoll;
	ArkAudioRtpc m_rtpcPitch;
	ArkAudioRtpc m_rtpcYaw;
	uint64_t m_bodyCollisionPackage;
	uint64_t m_headCollisionPackage;
	ArkInputLegend m_ongoingInputLegend;
	ArkInputLegendHandler m_ongoingInputLegendHandler;

	ZeroG();
	void Enter() { FEnter(this); }
	void Exit() { FExit(this); }
	void LoadConfig(const XmlNodeRef& _root) { FLoadConfig(this, _root); }
	void PostSerialize() { FPostSerialize(this); }
	void Update(ArkPlayerMovementFSM& _fsm, const float _frameTime) { FUpdate(this, _fsm, _frameTime); }
	void ProcessRotation(const ArkPlayerMovementFSM& _fsm, Quat& _rotation, const Ang3 _inputRotation) { FProcessRotation(this, _fsm, _rotation, _inputRotation); }
	Vec2 GetMovementInput(const ArkPlayer& _player) const { alignas(Vec2) std::byte _return_buf_[sizeof(Vec2)]; return *FGetMovementInput(this, reinterpret_cast<Vec2*>(_return_buf_), _player); }
	void SetGameNoise(IEntity& _playerEntity, bool _bActive) { FSetGameNoise(this, _playerEntity, _bActive); }
	static void TrySetStance(const EStance _newStance) { FTrySetStance(_newStance); }

#if 0
	static void RegisterCVars();
	static bool AllowsJump(const ArkPlayerMovementFSM& _arg0_);
	bool IsSprinting(const ArkPlayerMovementFSM& _arg0_) const;
	static void LimitRotation(const ArkPlayerMovementFSM& _arg0_, Quat& _arg1_);
	static float GetFPIKPitchWeight(const ArkPlayerMovementFSM& _arg0_);
	const ArkAudioRtpc& GetYawRTPC() const;
	const ArkAudioRtpc& GetPitchRTPC() const;
	uint64_t GetBodyCollisionPackage() const;
	uint64_t GetHeadCollisionPackage() const;
	float GetMaxCollisionAngle() const;
	float GetMaxSpeed(ArkPlayerMovementStates::ZeroG::ArkZeroGState _arg0_) const;
	float GetCurrentSpeed() const;
#endif

	static inline auto FZeroGOv2 = PreyFunction<void(ArkPlayerMovementStates::ZeroG* const _this)>(0x156E5B0);
	static inline auto FEnter = PreyFunction<void(ArkPlayerMovementStates::ZeroG* const _this)>(0x123AD30);
	static inline auto FExit = PreyFunction<void(ArkPlayerMovementStates::ZeroG* const _this)>(0x123B7B0);
	static inline auto FLoadConfig = PreyFunction<void(ArkPlayerMovementStates::ZeroG* const _this, const XmlNodeRef& _root)>(0x123C990);
	static inline auto FPostSerialize = PreyFunction<void(ArkPlayerMovementStates::ZeroG* const _this)>(0x123D250);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMovementStates::ZeroG* const _this, ArkPlayerMovementFSM& _fsm, const float _frameTime)>(0x1243540);
	static inline auto FProcessRotation = PreyFunction<void(ArkPlayerMovementStates::ZeroG* const _this, const ArkPlayerMovementFSM& _fsm, Quat& _rotation, const Ang3 _inputRotation)>(0x123E7D0);
	static inline auto FGetMovementInput = PreyFunction<Vec2*(const ArkPlayerMovementStates::ZeroG* const _this, Vec2* _return_value_, const ArkPlayer& _player)>(0x123BC10);
	static inline auto FSetGameNoise = PreyFunction<void(ArkPlayerMovementStates::ZeroG* const _this, IEntity& _playerEntity, bool _bActive)>(0x1240060);
	static inline auto FTrySetStance = PreyFunction<void(const EStance _newStance)>(0x1240510);
};


} // namespace ArkPlayerMovementStates

// PlayerCrawlRagdollAction
// Header:  Prey/GameDll/ark/player/ArkPlayerMovementStates.h
class PlayerCrawlRagdollAction : public TAction<SAnimationContext>
{ // Size=128 (0x80)
public:
	virtual void OnActionEvent(const unsigned _eventCRC);

#if 0
	PlayerCrawlRagdollAction(int _arg0_);
#endif

	static inline auto FOnActionEvent = PreyFunction<void(PlayerCrawlRagdollAction* const _this, const unsigned _eventCRC)>(0x123D080);
};

