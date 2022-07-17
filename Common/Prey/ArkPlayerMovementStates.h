#pragma once
#include "ArkAudio.h"
#include "ArkInput.h"
#include "ArkProjectile.h"
#include "ArkTimer.h"
#include "Prey/CryAction/IAction.h"
#include "RayCast.h"
#include "Prey/ArkBasicTypes.h"

namespace ArkPlayerMovementStates {
	class Base
	{
		// a bunch of static functions
	};
	class Ground : Base
	{
	public:
		class ArkGroundColliderParameters
		{
			float m_minSlideAngle;
			float m_minFallAngle;
			float m_maxClimbAngle;
		};
		std::array<ArkLatentRaycast, 4> m_footPositioningRaycasts;
		std::array<bool, 4> m_groundProbeResults;
		ArkPlayerMovementStates::Ground::ArkGroundColliderParameters m_groundColliderParams;
		ArkPlayerMovementStates::Ground::ArkGroundColliderParameters m_gooProjectileColliderParams;
		ArkAudioTrigger m_triggerSprintStart;
		ArkAudioTrigger m_triggerSprintFullyAccelerated;
		_smart_ptr<TAction<SAnimationContext> > m_hobbleAnim;
		const CArkProjectileGoo* m_pProjectileGooGroundCollider;
		ArkAutoResetTimer m_sprintBleedTimer;
		ArkSimpleTimer m_sprintAccelerationTimer;
		ArkSimpleTimer m_jumpWindowTimer;
		ArkSimpleTimer m_stumbleSwitchTimer;
		ArkSimpleTimer m_stumbleTimer;
		EStance m_requestedStance;
		int m_sprintZoomHandle;
		float m_leanPitchLimit;
		float m_leanYawLimit;
		float m_leanCancelSpeedSq;
		float m_preLandJumpWindow;
		float m_turnTravelAngle;
		float m_turnTravelSpeed;
		float m_stumbleXAdd;
		float m_stumbleYScale;
		float m_stumbleMinListDuration;
		float m_stumbleMaxListDuration;
		float m_stumbleXMinAdd;
		float m_stumbleXMaxAdd;
		float m_stumbleYMinScale;
		float m_stumbleYMaxScale;
		float m_stumbleDurationMin;
		float m_stumbleDurationMax;
		float m_stumbleBreakDurationMin;
		float m_stumbleBreakDurationMax;
		float m_rotationCatchUpAngleThreshold;
		float m_travelAngle;
		float m_groundProbeDistance;
		bool m_bStumbleRight;
		bool m_bIsStumbling;
		bool m_bCatchUpRotation;
		bool m_bCanLean;
		bool m_bSprinting;
	};
	static_assert(sizeof(ArkPlayerMovementStates::Ground) == 0x1e8);
	class Death : ArkPlayerMovementStates::Base
	{
		ArkSimpleTimer m_deathCamDelay;
		ArkSimpleTimer m_fullSlowTimer;
		ArkSimpleTimer m_rampUpSpeedTimer;
		float m_deathCamProbability;
		float m_idealDeathCamDistance;
		float m_idealDeathCamAngle;
		float m_deathCamGravityMinAngle;
		float m_timeScaleAmount;
		int m_timeScaleHandle;
	};
	static_assert(sizeof(ArkPlayerMovementStates::Death) == 0x30);
	class DeathByRecyclerGrenade : ArkPlayerMovementStates::Base
	{
		ArkSimpleTimer m_deathTimer;
		unsigned __int64 m_postProcessEffectId;
		unsigned __int64 m_gammaParamId;
		ArkInterval<float> m_gammaValues;
		unsigned __int64 m_brightnessParamId;
		ArkInterval<float> m_brightnessValues;
		unsigned __int64 m_saturationParamId;
		ArkInterval<float> m_saturationValues;
		_smart_ptr<IParticleEmitter> m_emitter;
		CryStringT<char> m_effectName;
		CryStringT<char> m_scaleName;
		ArkInterval<float> m_scaleValues;
	};
	static_assert(sizeof(ArkPlayerMovementStates::DeathByRecyclerGrenade) == 0x60);
	class Jump : ArkPlayerMovementStates::Base
	{
		ArkAudioTrigger m_audioTrigger;
		ArkAudioTrigger m_audioTriggerPlay;
		ArkAudioSwitch m_mobilityAbilitySwitch;
		std::array<ArkAudioSwitchState, 3> m_mobilityAbilityStates;
		float m_minJumpHeight;
		float m_bonusVelocity;
		float m_startHeight;
		ArkSimpleTimer m_maxJumpTimer;
	};
	static_assert(sizeof(ArkPlayerMovementStates::Jump) == 0x2c);
	class Fall : ArkPlayerMovementStates::Base
	{
		unsigned __int64 m_package;
		ArkTimeRemaining m_propulsionForceDuration;
		ArkAudioTrigger m_audioTrigger;
		float m_fatalSpeed;
		float m_safeSpeed;
		float m_traumaDmgSpeed;
		float m_BigBumpSpeed;
		bool m_bSneakOnExit;
		bool m_bAirControlEnabled;
	};
	static_assert(sizeof(ArkPlayerMovementStates::Fall) == 0x28);
	class Climb : ArkPlayerMovementStates::Base
	{
		_smart_ptr<TAction<SAnimationContext> > m_pClimbAction;
		Vec3_tpl<float> m_targetPos;
		Vec3_tpl<float> m_cachedVelocity;
		float m_mediumToHighThreshold;
		bool m_bHighClimb;
	};
	static_assert(sizeof(ArkPlayerMovementStates::Climb) == 0x28);
	class Fly : ArkPlayerMovementStates::Base
	{
	};
	static_assert(sizeof(ArkPlayerMovementStates::Fly) == 0x1);
	class Smoke : ArkPlayerMovementStates::Base
	{
	public:
		static inline auto Enter = PreyFunction<void(Smoke* _this)>(0x123ACA0);
		static inline auto Exit = PreyFunction<void(void)>(0x123B790);
		float m_speed;
		float m_inertia;
		float m_maxHeight;
	};
	static_assert(sizeof(ArkPlayerMovementStates::Smoke) == 0xC);
	class ZeroG : ArkPlayerMovementStates::Base
	{
		class ZeroGParams
		{
			CryStringT<char> m_maxSpeedStat;
			Vec3_tpl<float> m_baseAccel;
			float m_minDragSpeed;
			float m_maxDragSpeed;
			float m_drag;
			float m_baseDecel;
			float m_velocityLerp;
			float m_counterThrustAngle;
			float m_counterThrustSpeed;
			float m_brakingRatio;
			float m_yawPitchFactor;
		};
		class RollParams
		{
			float m_velocity;
			float m_acceleration;
			float m_deceleration;
			float m_yInputDeadzone;
		};
		class AlignParams
		{
			float m_distance;
			float m_rate;
		};
		std::array<ArkPlayerMovementStates::ZeroG::ZeroGParams, 3> m_params;
		Vec3_tpl<float> m_normalToAlignGround;
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
		unsigned __int64 m_gameNoiseTypeId;
		unsigned __int64 m_gameNoiseLoudness;
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
		unsigned __int64 m_bodyCollisionPackage;
		unsigned __int64 m_headCollisionPackage;
		ArkInputLegend m_ongoingInputLegend;
		ArkInputLegendHandler m_ongoingInputLegendHandler;
	};
	static_assert(sizeof(ArkPlayerMovementStates::ZeroG) == 0x188);
	class Cinematic : ArkPlayerMovementStates::Base
	{
		Ang3_tpl<float> m_cameraAdditive;
	};
	static_assert(sizeof(ArkPlayerMovementStates::Cinematic) == 0xC);
	class Slide : ArkPlayerMovementStates::Base
	{
		_smart_ptr<TAction<SAnimationContext> > m_pAction;
	};
	static_assert(sizeof(ArkPlayerMovementStates::Slide) == 0x8);
	class Mimic : ArkPlayerMovementStates::Base
	{
	};
	static_assert(sizeof(ArkPlayerMovementStates::Mimic) == 0x1);
	class GravShaft : ArkPlayerMovementStates::Base
	{
		Quat_tpl<float> m_desiredViewRotation;
	};
	static_assert(sizeof(ArkPlayerMovementStates::GravShaft) == 0x10);
	class GravShaftG : ArkPlayerMovementStates::GravShaft
	{
	};
	static_assert(sizeof(ArkPlayerMovementStates::GravShaftG) == 0x10);
	class GravShaftToG : ArkPlayerMovementStates::GravShaft
	{
		Quat_tpl<float> m_desiredEntityRotation;
	};
	static_assert(sizeof(ArkPlayerMovementStates::GravShaftToG) == 0x20);
	class GravShaftZeroG : ArkPlayerMovementStates::GravShaft
	{
	};
	static_assert(sizeof(ArkPlayerMovementStates::GravShaftZeroG) == 0x10);
	class Lift : ArkPlayerMovementStates::Base
	{
		ArkLooseEffect m_particleEffect;
		CryStringT<char> m_particleEffectPath;
		float m_inputMovementSpeed;
		float m_propulsionMovementSpeed;
		float m_upwardDamageSpeed;
		unsigned __int64 m_upwardDamagePackageId;
	};
	static_assert(sizeof(ArkPlayerMovementStates::Lift) == 0x90);
	class Shift : ArkPlayerMovementStates::Base
	{
		ArkSimpleTimer m_shiftTimer;
		Vec3_tpl<float> m_targetPosition;
		Quat_tpl<float> m_targetRotation;
		float m_speed;
		float m_shiftForwardFov;
		float m_shiftBackwardFov;
		int m_zoomHandle;
		bool m_bZeroG;
	};
	static_assert(sizeof(ArkPlayerMovementStates::GravShaftG) == 0x10);
};