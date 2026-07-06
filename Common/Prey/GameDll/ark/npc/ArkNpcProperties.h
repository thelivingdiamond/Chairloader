// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>

struct IEntityArchetype;
struct IParticleEffect;

// ArkNpcProperties
// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
struct ArkNpcProperties
{ // Size=1120 (0x460)
	// ArkNpcProperties::Ability
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct Ability
	{ // Size=8 (0x8)
		uint64_t m_abilityContextProfileId;

	#if 0
		Ability();
	#endif
	};

	// ArkNpcProperties::AttentionFacing
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct AttentionFacing
	{ // Size=2 (0x2)
		bool m_bUsesAttentionFacing;
		bool m_bUsesAttentionLook;

	#if 0
		AttentionFacing();
	#endif
	};

	// ArkNpcProperties::Audio
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct Audio
	{ // Size=8 (0x8)
		const char* m_pDistanceToPlayerParam;

	#if 0
		Audio();
	#endif
	};

	// ArkNpcProperties::Blind
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct Blind
	{ // Size=8 (0x8)
		uint64_t m_blindGameEffectId;

	#if 0
		Blind();
	#endif
	};

	// ArkNpcProperties::CallForHelp
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct CallForHelp
	{ // Size=32 (0x20)
		uint64_t m_onAttackNoiseLoudness;
		uint64_t m_onAttackNoiseType;
		uint64_t m_onNewCombatAttentionNoiseLoudness;
		uint64_t m_onNewCombatAttentionNoiseType;

	#if 0
		CallForHelp();
	#endif
	};

	// ArkNpcProperties::Character
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct Character
	{ // Size=8 (0x8)
		uint64_t m_characterId;

	#if 0
		Character();
	#endif
	};

	// ArkNpcProperties::CombatRoleInfo
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct CombatRoleInfo
	{ // Size=20 (0x14)
		bool m_bCanGetStaleInMeleeRole;
		bool m_bUsesCombatRoles;
		float m_meleeRoleCost;
		float m_meleeRolePreference;
		float m_meleeRoleScoreBias;
		float m_minDistanceToAllowRangeRoleSwitchSq;

	#if 0
		CombatRoleInfo();
	#endif
	};

	// ArkNpcProperties::ControlTurrets
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct ControlTurrets
	{ // Size=8 (0x8)
		uint64_t m_controlTurretsGameEffectId;

	#if 0
		ControlTurrets();
	#endif
	};

	// ArkNpcProperties::CorruptNpc
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct CorruptNpc
	{ // Size=1 (0x1)
		bool m_bReleaseCorruptionOnDeath;

	#if 0
		CorruptNpc();
	#endif
	};

	// ArkNpcProperties::Corruption
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct Corruption
	{ // Size=56 (0x38)
		bool m_bDeletedOnLevelLoadAndUncorrupted;
		bool m_bShouldGoUnconsciousOnUncorruption;
		bool m_bStartCorrupted;
		const char* m_pMovementGlitchAttachmentName1;
		const char* m_pMovementGlitchAttachmentName2;
		ArkAudioTrigger m_becomeCorruptedAudioTrigger;
		uint64_t m_corruptedGameEffectId;
		uint64_t m_uncorruptedMetaTagId;
		_smart_ptr<IParticleEffect> m_pCorruptedMovementGlitchParticleEffect;

	#if 0
		Corruption();
	#endif
	};

	// ArkNpcProperties::DamageStates
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct DamageStates
	{ // Size=128 (0x80)
		bool m_bHasDamageStates;
		float m_healthThresholdDamage;
		float m_healthThresholdDisabled;
		float m_destroyedExplosionRadius;
		float m_destroyedExplosionImpulse;
		float m_destroyedExplosionDelay;
		float m_destroyedHeightOffset;
		float m_disabledRepeatDialogCD;
		float m_disabledFlickerDuration;
		const char* m_pUndamagedAttachmentName;
		const char* m_pDamagedAttachmentName;
		const char* m_pDisabledAttachmentName;
		const char* m_pChassisModelName;
		const char* m_pChassisUndamagedAttachmentName;
		const char* m_pChassisDestroyedAttachmentName;
		ArkAudioTrigger m_becomeUndamagedAudioTrigger;
		ArkAudioTrigger m_becomeDamagedAudioTrigger;
		ArkAudioTrigger m_becomeDisabledAudioTrigger;
		uint64_t m_destroyedExplosionPackageId;
		uint64_t m_destroyedExplosionCameraShakeId;
		uint64_t m_repairableDistractionId;

	#if 0
		DamageStates();
	#endif
	};

	// ArkNpcProperties::Dodge
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct Dodge
	{ // Size=24 (0x18)
		bool m_bEnabled;
		float m_chance;
		float m_cooldown;
		uint64_t m_damagePackageId;

	#if 0
		Dodge();
	#endif
	};

	// ArkNpcProperties::Dormant
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct Dormant
	{ // Size=16 (0x10)
		float m_hearingGainModifier;
		uint64_t m_signalModifierId;

	#if 0
		Dormant();
	#endif
	};

	// ArkNpcProperties::Energized
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct Energized
	{ // Size=8 (0x8)
		uint64_t m_energizedGameEffectId;

	#if 0
		Energized();
	#endif
	};

	// ArkNpcProperties::EntityFactionModifier
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct EntityFactionModifier
	{ // Size=8 (0x8)
		uint64_t m_hositleToFactionId;

	#if 0
		EntityFactionModifier();
	#endif
	};

	// ArkNpcProperties::Fatality
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct Fatality
	{ // Size=4 (0x4)
		float m_vulnerabilityHealthThreshold;

	#if 0
		Fatality();
	#endif
	};

	// ArkNpcProperties::Fear
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct Fear
	{ // Size=16 (0x10)
		uint64_t m_fearedGameEffectId;
		uint64_t m_fearedSignalModifierId;

	#if 0
		Fear();
	#endif
	};

	// ArkNpcProperties::Frenzied
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct Frenzied
	{ // Size=8 (0x8)
		uint64_t m_frenziedGameEffectId;

	#if 0
		Frenzied();
	#endif
	};

	// ArkNpcProperties::Glooed
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct Glooed
	{ // Size=24 (0x18)
		uint64_t m_glooGameEffectId;
		uint64_t m_onGlooedAbilityContextId;
		float m_glooedCooldown;

	#if 0
		Glooed();
	#endif
	};

	// ArkNpcProperties::Hack
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct Hack
	{ // Size=16 (0x10)
		bool m_bStartHacked;
		uint64_t m_hackedGameEffectId;

	#if 0
		Hack();
	#endif
	};

	// ArkNpcProperties::HitReaction
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct HitReaction
	{ // Size=8 (0x8)
		uint64_t m_hitReactionMaterialAnimationGameEffectId;

	#if 0
		HitReaction();
	#endif
	};

	// ArkNpcProperties::HumanArmed
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct HumanArmed
	{ // Size=24 (0x18)
		bool m_bIsArmed;
		int m_magSize;
		const char* m_pGunAttachmentName;
		IEntityArchetype* m_pLootWeaponEntityArchetype;

	#if 0
		HumanArmed();
	#endif
	};

	// ArkNpcProperties::Hypnotize
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct Hypnotize
	{ // Size=4 (0x4)
		float m_timeBetweenHypnotize;

	#if 0
		Hypnotize();
	#endif
	};

	// ArkNpcProperties::Laser
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct Laser
	{ // Size=88 (0x58)
		int m_laserHitTypeId;
		float m_beamEndJumpDistanceSq;
		float m_materialEffectCooldown;
		float m_maxLaserLength;
		float m_maxThickness;
		float m_minThickness;
		uint64_t m_laserPackageId;
		int m_customSurfaceTypeId;
		const char* m_pBeamEndEffectName;
		const char* m_pLaserGeometryName;
		const char* m_pLaserMaterialEffectName;
		const char* m_pReflectionGeometryName;
		IEntityArchetype* m_pLootAmmoLaserArchetype;
		IEntityArchetype* m_pLootAmmoStunArchetype;

	#if 0
		Laser();
	#endif
	};

	// ArkNpcProperties::Mannequin
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct Mannequin
	{ // Size=8 (0x8)
		const char* m_pLifetimeTag;

	#if 0
		Mannequin();
	#endif
	};

	// ArkNpcProperties::MimicJumpAttack
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct MimicJumpAttack
	{ // Size=16 (0x10)
		uint64_t m_mimicJumpAttackPackageId;
		_smart_ptr<IParticleEffect> m_pMimicAttackEffect;

	#if 0
		MimicJumpAttack();
	#endif
	};

	// ArkNpcProperties::MimicReorient
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct MimicReorient
	{ // Size=12 (0xC)
		bool m_bSupportsReorientation;
		float m_mimicGlitchRandTimeMax;
		float m_mimicGlitchRandTimeMin;

	#if 0
		MimicReorient();
	#endif
	};

	// ArkNpcProperties::Mimicry
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct Mimicry
	{ // Size=96 (0x60)
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

	#if 0
		Mimicry();
	#endif
	};

	// ArkNpcProperties::MindControl
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct MindControl
	{ // Size=8 (0x8)
		uint64_t m_mindControlGameEffectId;

	#if 0
		MindControl();
	#endif
	};

	// ArkNpcProperties::Nullwave
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct Nullwave
	{ // Size=8 (0x8)
		uint64_t m_nullwavedSignalModifierId;

	#if 0
		Nullwave();
	#endif
	};

	// ArkNpcProperties::OnDeath
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct OnDeath
	{ // Size=24 (0x18)
		float m_aoeDeathRadius;
		float m_aoeDeathSignalScale;
		uint64_t m_aoeDeathSignal;
		_smart_ptr<IParticleEffect> m_pFearAoeParticleEffect;

	#if 0
		OnDeath();
	#endif
	};

	// ArkNpcProperties::OnFire
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct OnFire
	{ // Size=8 (0x8)
		uint64_t m_onFireGameEffectId;

	#if 0
		OnFire();
	#endif
	};

	// ArkNpcProperties::OperatorEffects
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct OperatorEffects
	{ // Size=32 (0x20)
		float m_airJetToggleOffTime;
		float m_maxAirJetToggleOnTime;
		float m_minAirJetToggleOnTime;
		uint64_t m_operatorArmRetractedGameEffectId;
		_smart_ptr<IParticleEffect> m_pAirJetParticleEffect;

	#if 0
		OperatorEffects();
	#endif
	};

	// ArkNpcProperties::Pet
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct Pet
	{ // Size=16 (0x10)
		bool m_bPetInvulnerable;
		bool m_bPetAttentionDisabled;
		bool m_bPetUsesExternalInventory;
		bool m_bAlwaysLootable;
		float m_minMassScale;
		uint64_t m_petGameEffectId;

	#if 0
		Pet();
	#endif
	};

	// ArkNpcProperties::PlayerControlled
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct PlayerControlled
	{ // Size=8 (0x8)
		uint64_t m_playerControlledGameEffectId;

	#if 0
		PlayerControlled();
	#endif
	};

	// ArkNpcProperties::PoltergeistEffects
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct PoltergeistEffects
	{ // Size=8 (0x8)
		uint64_t m_invisibilityGameEffectId;

	#if 0
		PoltergeistEffects();
	#endif
	};

	// ArkNpcProperties::RaiseFromCorpse
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct RaiseFromCorpse
	{ // Size=8 (0x8)
		uint64_t m_raiseFromCorpseGameEffectId;

	#if 0
		RaiseFromCorpse();
	#endif
	};

	// ArkNpcProperties::RaisePhantom
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct RaisePhantom
	{ // Size=1 (0x1)
		bool m_bCanBeRaisedPhantom;

	#if 0
		RaisePhantom();
	#endif
	};

	// ArkNpcProperties::Shift
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct Shift
	{ // Size=8 (0x8)
		uint64_t m_shiftingSignalModifierId;

	#if 0
		Shift();
	#endif
	};

	// ArkNpcProperties::Size
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct Size
	{ // Size=8 (0x8)
		bool m_bUseCustomScale;
		float m_customScale;

	#if 0
		Size();
	#endif
	};

	// ArkNpcProperties::Sound
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct Sound
	{ // Size=36 (0x24)
		// ArkNpcProperties::Sound::NoiseStates
		// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
		struct NoiseStates
		{ // Size=24 (0x18)
			ArkAudioTrigger m_combatStateAudioTrigger;
			ArkAudioTrigger m_idleStateAudioTrigger;
			ArkAudioTrigger m_noticeStateAudioTrigger;
			ArkAudioTrigger m_searchStateAudioTrigger;
			ArkAudioTrigger m_stareStateAudioTrigger;
			ArkAudioTrigger m_undergroundStateAudioTrigger;

		#if 0
			NoiseStates();
		#endif
		};

		ArkNpcProperties::Sound::NoiseStates m_noiseStates;
		ArkAudioTrigger m_deathAudioTrigger;
		ArkAudioTrigger m_startAmbientLivingAudioTrigger;
		ArkAudioTrigger m_stopAmbientLivingAudioTrigger;

	#if 0
		Sound();
	#endif
	};

	// ArkNpcProperties::Stunned
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct Stunned
	{ // Size=8 (0x8)
		uint64_t m_stunnedGameEffectId;

	#if 0
		Stunned();
	#endif
	};

	// ArkNpcProperties::Surprise
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct Surprise
	{ // Size=16 (0x10)
		uint64_t m_noiseLoudnessId;
		uint64_t m_noiseTypeId;

	#if 0
		Surprise();
	#endif
	};

	// ArkNpcProperties::TurretWeapon
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct TurretWeapon
	{ // Size=16 (0x10)
		IEntityArchetype* m_pLootAmmoLaserArchetype;
		IEntityArchetype* m_pLootAmmoStunArchetype;

	#if 0
		TurretWeapon();
	#endif
	};

	// ArkNpcProperties::Underground
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct Underground
	{ // Size=16 (0x10)
		uint64_t m_undergroundGameEffectId;
		float m_undergroundAttackPosHeight;

	#if 0
		Underground();
	#endif
	};

	// ArkNpcProperties::UnreachableTargeting
	// Header:  Prey/GameDll/ark/npc/ArkNpcProperties.h
	struct UnreachableTargeting
	{ // Size=40 (0x28)
		float m_defaultCombatReachabilityCheckUp;
		float m_defaultCombatReachabilityCheckDown;
		float m_defaultCombatReachabilityCheckHorizontal;
		float m_startingTraceRadius;
		float m_startingMinSearchRadius;
		float m_chanceToSearchInReverseOrder;
		float m_horizontalOffsetStanding;
		float m_standardCombatHeight;
		float m_maxAllowedAngleToTarget;
		float m_maxSearchRadius;

	#if 0
		UnreachableTargeting();
	#endif
	};

	ArkNpcProperties::Ability m_ability;
	ArkNpcProperties::AttentionFacing m_attentionFacing;
	ArkNpcProperties::Audio m_audio;
	ArkNpcProperties::Blind m_blind;
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
	ArkNpcProperties::Frenzied m_frenzied;
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
	ArkNpcProperties::Pet m_pet;
	ArkNpcProperties::PlayerControlled m_playerControlled;
	ArkNpcProperties::PoltergeistEffects m_poltergeistEffects;
	ArkNpcProperties::RaiseFromCorpse m_raiseFromCorpse;
	ArkNpcProperties::RaisePhantom m_raisePhantom;
	ArkNpcProperties::Shift m_shift;
	ArkNpcProperties::Size m_size;
	ArkNpcProperties::Sound m_sound;
	ArkNpcProperties::Stunned m_stunned;
	ArkNpcProperties::Surprise m_surprise;
	ArkNpcProperties::TurretWeapon m_turretWeapon;
	ArkNpcProperties::Underground m_underground;
	ArkNpcProperties::UnreachableTargeting m_unreachableTargeting;
	bool m_bCanFall;
	bool m_bCanRagdoll;
	bool m_bSupportsLookAt;
	int m_playerPowerTierTriggerThreshold;
	int m_npcManagerCombatPoints;
	float m_combatIntensityContribution;
	float m_combatIntensityRange;
	float m_fallDamagePerMeter;
	float m_fallDamagePMPartialG;
	float m_fallDistanceForDamage;
	float m_fallDistanceForDialog;
	float m_fallDistanceForFallAnim;
	float m_fallDistanceForGlooBreak;
	float m_fallDistanceForLandAnim;
	float m_forceResistScrunchDistance;
	const char* m_pAiTreeFilePath;
	const char* m_pFaction;
	uint64_t m_fallDamagePackage;
	uint64_t m_ragdollSignalModifierId;
	uint64_t m_recycleAttackAbilityContextId;
	uint64_t m_armoredGameEffectId;
	uint64_t m_hostileToDamageGameEffectId;
	uint64_t m_telepathShieldGameEffectId;
	uint64_t m_fastTurnGameEffectId;
	EArkAttentionLevel m_abortTrackviewOnHostileAttention;
	EArkNpcVisionDirection m_visionDirection;
	const char* m_doomclockProfile;
	bool m_bSeismicPerceiver;

	ArkNpcProperties();

#if 0
	ArkNpcProperties(const ArkNpcProperties& _arg0_);
	ArkNpcProperties& operator=(const ArkNpcProperties& _arg0_);
#endif

	static inline auto FArkNpcPropertiesOv1 = PreyFunction<void(ArkNpcProperties* const _this)>(0x12970D0);
};
#endif // !MOONCRASH
