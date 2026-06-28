// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/ArkCommon/ArkInterval.h>
#include <_unknown/ArkTurretAngle.h>

struct IEntityArchetype;

// ArkTurretProperties
// Header:  Prey/GameDll/ark/turret/ArkTurretProperties.h
struct ArkTurretProperties
{ // Size=416 (0x1A0)
	// ArkTurretProperties::ArkBehavior
	// Header:  Prey/GameDll/ark/turret/ArkTurretProperties.h
	struct ArkBehavior
	{ // Size=24 (0x18)
		float m_fallenToUprightDelay;
		float m_fallenActivePhysicsTime;
		float m_attackingLostLosDelay;
		float m_attackingCallForHelpPulseTime;
		ArkInterval<float> m_searchingAnimDelay;

	#if 0
		ArkBehavior();
	#endif
	};

	// ArkTurretProperties::ArkDamageFsmConfig
	// Header:  Prey/GameDll/ark/turret/ArkTurretProperties.h
	struct ArkDamageFsmConfig
	{ // Size=40 (0x28)
		const char* m_pUndamagedAttachmentName;
		const char* m_pDamagedAttachmentName;
		const char* m_pDisabledAttachmentName;
		uint64_t m_repairableDistractionId;
		float m_healthThresholdDamage;
		float m_healthThresholdDisabled;

	#if 0
		ArkDamageFsmConfig();
	#endif
	};

	// ArkTurretProperties::ArkDialog
	// Header:  Prey/GameDll/ark/turret/ArkTurretProperties.h
	struct ArkDialog
	{ // Size=4 (0x4)
		float m_playerBumpCD;

	#if 0
		ArkDialog();
	#endif
	};

	// ArkTurretProperties::ArkFaction
	// Header:  Prey/GameDll/ark/turret/ArkTurretProperties.h
	struct ArkFaction
	{ // Size=24 (0x18)
		uint64_t m_defaultFactionId;
		uint64_t m_playerControlledFactionId;
		uint64_t m_hackedFactionId;

	#if 0
		ArkFaction();
	#endif
	};

	// ArkTurretProperties::ArkFalling
	// Header:  Prey/GameDll/ark/turret/ArkTurretProperties.h
	struct ArkFalling
	{ // Size=24 (0x18)
		uint64_t m_fallDamagePackageId;
		float m_fallMinSpeedForFalling;
		float m_fallDistanceForDamage;
		float m_fallDamagePerMeter;

	#if 0
		ArkFalling();
	#endif
	};

	// ArkTurretProperties::ArkInteractMessages
	// Header:  Prey/GameDll/ark/turret/ArkTurretProperties.h
	struct ArkInteractMessages
	{ // Size=24 (0x18)
		const char* m_pLootInteractionText;
		const char* m_pDeployInteractionText;
		const char* m_pCantDeployInteractionText;

	#if 0
		ArkInteractMessages();
	#endif
	};

	// ArkTurretProperties::ArkMannequin
	// Header:  Prey/GameDll/ark/turret/ArkTurretProperties.h
	struct ArkMannequin
	{ // Size=48 (0x30)
		const char* m_pControllerDefFilePath;
		const char* m_pAnimationDatabaseFilePath;
		const char* m_pDefaultTurretModel;
		const char* m_pDestroyedTurretModel;
		const char* m_pRecoilFragmentName;
		float m_recoilAnimationLength;

	#if 0
		ArkMannequin();
	#endif
	};

	// ArkTurretProperties::ArkWeapon
	// Header:  Prey/GameDll/ark/turret/ArkTurretProperties.h
	struct ArkWeapon
	{ // Size=32 (0x20)
		const char* m_pShootAttachmentName;
		float m_validFiringAngleToTargetRadians;
		float m_windupDuration;
		float m_shootingDuration;
		float m_cooldownDuration;
		bool m_bIgnoreShootAngleWhileShooting;

	#if 0
		ArkWeapon();
	#endif
	};

	// ArkTurretProperties::Physics
	// Header:  Prey/GameDll/ark/turret/ArkTurretProperties.h
	struct Physics
	{ // Size=4 (0x4)
		float m_mass;

	#if 0
		Physics();
	#endif
	};

	// ArkTurretProperties::Sound
	// Header:  Prey/GameDll/ark/turret/ArkTurretProperties.h
	struct Sound
	{ // Size=60 (0x3C)
		ArkAudioTrigger m_audioTriggers[15];

	#if 0
		Sound();
	#endif
	};

	ArkTurretProperties::ArkBehavior m_behavior;
	ArkTurretProperties::ArkDamageFsmConfig m_damage;
	ArkTurretProperties::ArkDialog m_dialog;
	ArkTurretProperties::ArkFaction m_faction;
	ArkTurretProperties::ArkFalling m_falling;
	ArkTurretProperties::ArkInteractMessages m_interactiveMessages;
	ArkTurretProperties::ArkMannequin m_arkMannequin;
	ArkTurretProperties::ArkWeapon m_weapon;
	ArkTurretProperties::Physics m_physics;
	ArkTurretProperties::Sound m_sound;
	IEntityArchetype* m_pWeaponArchetype;
	const char* m_pWeaponExtensionName;
	float m_angularVelDamp;
	float m_yawLimit;
	float m_pitchLowerLimit;
	float m_pitchUpperLimit;
	ArkTurretAngle m_angularAcceleration;
	ArkTurretAngle m_maxVelocity;
	float m_acquiredLineOfSightDuration;
	float m_lostLineOfSightDuration;
	float m_deadCarryHoldUseDuration;
	float m_deployHoldUseDuration;
	uint64_t m_callForHelpLoudness;
	uint64_t m_callForHelpNoiseType;
	uint64_t m_technoControlledSignalModifier;
	uint64_t m_defaultSignalModifier;
	Vec3 m_deployedBoundingBoxSize;
	float m_closeThresholdAutoDisable;
	float m_nonHostileApproachDistanceSqrd;
	float m_playerLoiterDistanceSqrd;
	float m_playerLoiterCooldown;
	float m_uprightToFallenDelay;

	ArkTurretProperties();

#if 0
	ArkTurretProperties(const ArkTurretProperties& _arg0_);
	ArkTurretProperties& operator=(const ArkTurretProperties& _arg0_);
#endif

	static inline auto FArkTurretPropertiesOv1 = PreyFunction<void(ArkTurretProperties* const _this)>(0x13CCC30);
};
#endif // MOONCRASH
