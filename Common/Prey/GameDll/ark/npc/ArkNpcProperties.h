// Header file automatically created from a PDB.

#pragma once

#include <Prey/CryCore/StdAfx.h>
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/ArkStubs.h>

// Header: FromCpp
// Prey/GameDll/ark/npc/ArkNpcProperties.h
struct ArkNpcProperties // Id=8014069 Size=968
{
	struct Ability // Id=801406A Size=8
	{
		uint64_t m_abilityContextProfileId;
	};

	struct AttentionFacing // Id=801406B Size=2
	{
		bool m_bUsesAttentionFacing;
		bool m_bUsesAttentionLook;
	};

	struct Audio // Id=801406C Size=8
	{
		const char *m_pDistanceToPlayerParam;
	};

	struct CallForHelp // Id=801406D Size=32
	{
		uint64_t m_onAttackNoiseLoudness;
		uint64_t m_onAttackNoiseType;
		uint64_t m_onNewCombatAttentionNoiseLoudness;
		uint64_t m_onNewCombatAttentionNoiseType;
	};

	struct Character // Id=801406E Size=8
	{
		uint64_t m_characterId;
	};

	struct CombatRoleInfo // Id=801406F Size=20
	{
		bool m_bCanGetStaleInMeleeRole;
		bool m_bUsesCombatRoles;
		float m_meleeRoleCost;
		float m_meleeRolePreference;
		float m_meleeRoleScoreBias;
		float m_minDistanceToAllowRangeRoleSwitchSq;
	};

	struct ControlTurrets // Id=8014070 Size=8
	{
		uint64_t m_controlTurretsGameEffectId;
	};

	struct CorruptNpc // Id=8014071 Size=1
	{
		bool m_bReleaseCorruptionOnDeath;
	};

	struct Corruption // Id=8014072 Size=56
	{
		bool m_bDeletedOnLevelLoadAndUncorrupted;
		bool m_bShouldGoUnconsciousOnUncorruption;
		bool m_bStartCorrupted;
		const char *m_pMovementGlitchAttachmentName1;
		const char *m_pMovementGlitchAttachmentName2;
		ArkAudioTrigger m_becomeCorruptedAudioTrigger;
		uint64_t m_corruptedGameEffectId;
		uint64_t m_uncorruptedMetaTagId;
		_smart_ptr<IParticleEffect> m_pCorruptedMovementGlitchParticleEffect;
	};

	struct DamageStates // Id=8014073 Size=120
	{
		bool m_bHasDamageStates;
		float m_healthThresholdDamage;
		float m_healthThresholdDisabled;
		float m_destroyedExplosionRadius;
		float m_destroyedExplosionImpulse;
		float m_destroyedExplosionDelay;
		float m_destroyedHeightOffset;
		float m_disabledRepeatDialogCD;
		float m_disabledFlickerDuration;
		const char *m_pUndamagedAttachmentName;
		const char *m_pDamagedAttachmentName;
		const char *m_pDisabledAttachmentName;
		const char *m_pChassisModelName;
		const char *m_pChassisUndamagedAttachmentName;
		const char *m_pChassisDestroyedAttachmentName;
		ArkAudioTrigger m_becomeUndamagedAudioTrigger;
		ArkAudioTrigger m_becomeDamagedAudioTrigger;
		ArkAudioTrigger m_becomeDisabledAudioTrigger;
		uint64_t m_destroyedExplosionPackageId;
		uint64_t m_destroyedExplosionCameraShakeId;
	};

	struct Dodge // Id=8014074 Size=24
	{
		bool m_bEnabled;
		float m_chance;
		float m_cooldown;
		uint64_t m_damagePackageId;
	};

	struct Dormant // Id=8014075 Size=16
	{
		float m_hearingGainModifier;
		uint64_t m_signalModifierId;
	};

	struct Energized // Id=8014076 Size=8
	{
		uint64_t m_energizedGameEffectId;
	};

	struct EntityFactionModifier // Id=8014077 Size=8
	{
		uint64_t m_hositleToFactionId;
	};

	struct Fatality // Id=8014078 Size=4
	{
		float m_vulnerabilityHealthThreshold;
	};

	struct Fear // Id=8014079 Size=16
	{
		uint64_t m_fearedGameEffectId;
		uint64_t m_fearedSignalModifierId;
	};

	struct Glooed // Id=801407A Size=16
	{
		uint64_t m_glooGameEffectId;
		uint64_t m_onGlooedAbilityContextId;
	};

	struct Hack // Id=801407B Size=16
	{
		bool m_bStartHacked;
		uint64_t m_hackedGameEffectId;
	};

	struct HitReaction // Id=801407C Size=8
	{
		uint64_t m_hitReactionMaterialAnimationGameEffectId;
	};

	struct HumanArmed // Id=801407D Size=24
	{
		bool m_bIsArmed;
		int m_magSize;
		const char *m_pGunAttachmentName;
		IEntityArchetype *m_pLootWeaponEntityArchetype;
	};

	struct Hypnotize // Id=801407E Size=4
	{
		float m_timeBetweenHypnotize;
	};

	struct Laser // Id=801407F Size=88
	{
		int m_laserHitTypeId;
		float m_beamEndJumpDistanceSq;
		float m_materialEffectCooldown;
		float m_maxLaserLength;
		float m_maxThickness;
		float m_minThickness;
		uint64_t m_laserPackageId;
		int m_customSurfaceTypeId;
		const char *m_pBeamEndEffectName;
		const char *m_pLaserGeometryName;
		const char *m_pLaserMaterialEffectName;
		const char *m_pReflectionGeometryName;
		IEntityArchetype *m_pLootAmmoLaserArchetype;
		IEntityArchetype *m_pLootAmmoStunArchetype;
	};

	struct Mannequin // Id=8014080 Size=8
	{
		const char *m_pLifetimeTag;
	};

	struct MimicJumpAttack // Id=8014081 Size=16
	{
		uint64_t m_mimicJumpAttackPackageId;
		_smart_ptr<IParticleEffect> m_pMimicAttackEffect;
	};

	struct MimicReorient // Id=8014082 Size=12
	{
		bool m_bSupportsReorientation;
		float m_mimicGlitchRandTimeMax;
		float m_mimicGlitchRandTimeMin;
	};

	struct Mimicry // Id=8014083 Size=96
	{
		int m_morphInSlot;
		int m_morphOutSlot;
		float m_defaultMass;
		float m_impulseMultiplier;
		float m_impulsePointHorizontalRatio;
		float m_impulsePointVerticalRatio;
		float m_startCharacterMorphOutTime;
		float m_startGeometryMorphInTime;
		float m_stopCharacterMorphInTime;
		float m_stopGeometryMorphOutTime;
		string m_MorphOutBamfBoneName;
		uint64_t m_signalModifierId;
		_smart_ptr<IParticleEffect> m_pMorphInParticlefEffect;
		_smart_ptr<IParticleEffect> m_pMorphOutBamParticlefEffect;
		_smart_ptr<IParticleEffect> m_pMorphOutParticlefEffect;
		ArkAudioTrigger m_startTickingAudioTrigger;
		ArkAudioTrigger m_stopTickingAudioTrigger;
		ArkAudioTrigger m_unmorphAudioTrigger;
	};

	struct MindControl // Id=8014084 Size=8
	{
		uint64_t m_mindControlGameEffectId;
	};

	struct Nullwave // Id=8014085 Size=8
	{
		uint64_t m_nullwavedSignalModifierId;
	};

	struct OnDeath // Id=8014086 Size=24
	{
		float m_aoeDeathRadius;
		float m_aoeDeathSignalScale;
		uint64_t m_aoeDeathSignal;
		_smart_ptr<IParticleEffect> m_pFearAoeParticleEffect;
	};

	struct OnFire // Id=8014087 Size=8
	{
		uint64_t m_onFireGameEffectId;
	};

	struct OperatorEffects // Id=8014088 Size=32
	{
		float m_airJetToggleOffTime;
		float m_maxAirJetToggleOnTime;
		float m_minAirJetToggleOnTime;
		uint64_t m_operatorArmRetractedGameEffectId;
		_smart_ptr<IParticleEffect> m_pAirJetParticleEffect;
	};

	struct PlayerControlled // Id=8014089 Size=8
	{
		uint64_t m_playerControlledGameEffectId;
	};

	struct PoltergeistEffects // Id=801408A Size=8
	{
		uint64_t m_invisibilityGameEffectId;
	};

	struct RaiseFromCorpse // Id=801408B Size=8
	{
		uint64_t m_raiseFromCorpseGameEffectId;
	};

	struct RaisePhantom // Id=801408C Size=8
	{
		bool m_bCanBeRaisedPhantom;
		int m_maxAllowedRaisedPhantoms;
	};

	struct Shift // Id=801408D Size=8
	{
		uint64_t m_shiftingSignalModifierId;
	};

	struct Sound // Id=801408E Size=32
	{
		struct NoiseStates // Id=801408F Size=20
		{
			ArkAudioTrigger m_combatStateAudioTrigger;
			ArkAudioTrigger m_idleStateAudioTrigger;
			ArkAudioTrigger m_noticeStateAudioTrigger;
			ArkAudioTrigger m_searchStateAudioTrigger;
			ArkAudioTrigger m_stareStateAudioTrigger;
		};

		ArkNpcProperties::Sound::NoiseStates m_noiseStates;
		ArkAudioTrigger m_deathAudioTrigger;
		ArkAudioTrigger m_startAmbientLivingAudioTrigger;
		ArkAudioTrigger m_stopAmbientLivingAudioTrigger;
	};

	struct Stunned // Id=8014090 Size=8
	{
		uint64_t m_stunnedGameEffectId;
	};

	struct Surprise // Id=8014091 Size=16
	{
		uint64_t m_noiseLoudnessId;
		uint64_t m_noiseTypeId;
	};

	struct TurretWeapon // Id=8014092 Size=16
	{
		IEntityArchetype *m_pLootAmmoLaserArchetype;
		IEntityArchetype *m_pLootAmmoStunArchetype;
	};

	struct UnreachableTargeting // Id=8014093 Size=32
	{
		float m_defaultCombatReachabilityCheckUp;
		float m_defaultCombatReachabilityCheckDown;
		float m_defaultCombatReachabilityCheckHorizontal;
		float m_startingTraceRadius;
		float m_startingMinSearchRadius;
		float m_chanceToSearchInReverseOrder;
		float m_horizontalOffsetStanding;
		float m_standardCombatHeight;
	};

	ArkNpcProperties::Ability m_ability;
	ArkNpcProperties::AttentionFacing m_attentionFacing;
	ArkNpcProperties::Audio m_audio;
	ArkNpcProperties::CallForHelp m_callForHelp;
	ArkNpcProperties::Character m_character;
	ArkNpcProperties::CombatRoleInfo m_combatRoleInfo;
	ArkNpcProperties::ControlTurrets m_controlTurrets;
	ArkNpcProperties::CorruptNpc m_corruptNpc;
	ArkNpcProperties::Corruption m_corruption;
	ArkNpcProperties::DamageStates m_damageStates;
	ArkNpcProperties::Dodge m_dodge;
	ArkNpcProperties::Dormant m_dormant;
	ArkNpcProperties::Energized m_energized;
	ArkNpcProperties::EntityFactionModifier m_entityFactionModifier;
	ArkNpcProperties::Fatality m_fatality;
	ArkNpcProperties::Fear m_fear;
	ArkNpcProperties::Glooed m_glooed;
	ArkNpcProperties::Hack m_hack;
	ArkNpcProperties::HitReaction m_hitReaction;
	ArkNpcProperties::HumanArmed m_humanArmed;
	ArkNpcProperties::Hypnotize m_hypnotize;
	ArkNpcProperties::Laser m_laser;
	ArkNpcProperties::Mannequin m_mannequin;
	ArkNpcProperties::MimicJumpAttack m_mimicJumpAttack;
	ArkNpcProperties::MimicReorient m_mimicReorient;
	ArkNpcProperties::Mimicry m_mimicry;
	ArkNpcProperties::MindControl m_mindControl;
	ArkNpcProperties::Nullwave m_nullwave;
	ArkNpcProperties::OnDeath m_onDeath;
	ArkNpcProperties::OnFire m_onFire;
	ArkNpcProperties::OperatorEffects m_operatorEffects;
	ArkNpcProperties::PlayerControlled m_playerControlled;
	ArkNpcProperties::PoltergeistEffects m_poltergeistEffects;
	ArkNpcProperties::RaiseFromCorpse m_raiseFromCorpse;
	ArkNpcProperties::RaisePhantom m_raisePhantom;
	ArkNpcProperties::Shift m_shift;
	ArkNpcProperties::Sound m_sound;
	ArkNpcProperties::Stunned m_stunned;
	ArkNpcProperties::Surprise m_surprise;
	ArkNpcProperties::TurretWeapon m_turretWeapon;
	ArkNpcProperties::UnreachableTargeting m_unreachableTargeting;
	bool m_bCanFall;
	bool m_bCanRagdoll;
	bool m_bSupportsLookAt;
	int m_playerPowerTierTriggerThreshold;
	int m_npcManagerCombatPoints;
	float m_combatIntensityContribution;
	float m_combatIntensityRange;
	float m_fallDamagePerMeter;
	float m_fallDistanceForDamage;
	float m_fallDistanceForDialog;
	float m_fallDistanceForFallAnim;
	float m_fallDistanceForGlooBreak;
	float m_fallDistanceForLandAnim;
	float m_forceResistScrunchDistance;
	const char *m_pAiTreeFilePath;
	const char *m_pFaction;
	uint64_t m_fallDamagePackage;
	uint64_t m_ragdollSignalModifierId;
	EArkAttentionLevel m_abortTrackviewOnHostileAttention;
	EArkNpcVisionDirection m_visionDirection;
	
	ArkNpcProperties();
};

