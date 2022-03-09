
class Fatality {
    float m_vulnerabilityHealthThreshold;
};

class ArkAudioTrigger {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
};

class Corruption {
    bool m_bDeletedOnLevelLoadAndUncorrupted;
    bool m_bShouldGoUnconsciousOnUncorruption;
    bool m_bStartCorrupted;
    char * m_pMovementGlitchAttachmentName1;
    char * m_pMovementGlitchAttachmentName2;
    class ArkAudioTrigger m_becomeCorruptedAudioTrigger;
    __uint64 m_corruptedGameEffectId;
    __uint64 m_uncorruptedMetaTagId;
    class _smart_ptr<IParticleEffect> m_pCorruptedMovementGlitchParticleEffect;
};

class Dodge {
    bool m_bEnabled;
    float m_chance;
    float m_cooldown;
    __uint64 m_damagePackageId;
};

class PoltergeistEffects {
    __uint64 m_invisibilityGameEffectId;
};

class RaiseFromCorpse {
    __uint64 m_raiseFromCorpseGameEffectId;
};

class Stunned {
    __uint64 m_stunnedGameEffectId;
};

class Dormant {
    float m_hearingGainModifier;
    __uint64 m_signalModifierId;
};

class Glooed {
    __uint64 m_glooGameEffectId;
    __uint64 m_onGlooedAbilityContextId;
};

class UnreachableTargeting {
    float m_defaultCombatReachabilityCheckUp;
    float m_defaultCombatReachabilityCheckDown;
    float m_defaultCombatReachabilityCheckHorizontal;
    float m_startingTraceRadius;
    float m_startingMinSearchRadius;
    float m_chanceToSearchInReverseOrder;
    float m_horizontalOffsetStanding;
    float m_standardCombatHeight;
};

class OperatorEffects {
    float m_airJetToggleOffTime;
    float m_maxAirJetToggleOnTime;
    float m_minAirJetToggleOnTime;
    __uint64 m_operatorArmRetractedGameEffectId;
    class _smart_ptr<IParticleEffect> m_pAirJetParticleEffect;
};

class CorruptNpc {
    bool m_bReleaseCorruptionOnDeath;
};

class CryStringT<char> {
    char * m_str;
};

class Mimicry {
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
    class CryStringT<char> m_MorphOutBamfBoneName;
    __uint64 m_signalModifierId;
    class _smart_ptr<IParticleEffect> m_pMorphInParticlefEffect;
    class _smart_ptr<IParticleEffect> m_pMorphOutBamParticlefEffect;
    class _smart_ptr<IParticleEffect> m_pMorphOutParticlefEffect;
    class ArkAudioTrigger m_startTickingAudioTrigger;
    class ArkAudioTrigger m_stopTickingAudioTrigger;
    class ArkAudioTrigger m_unmorphAudioTrigger;
};

class TurretWeapon {
    class IEntityArchetype * m_pLootAmmoLaserArchetype;
    class IEntityArchetype * m_pLootAmmoStunArchetype;
};

class IEntityArchetype {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
};

class RaisePhantom {
    bool m_bCanBeRaisedPhantom;
    int m_maxAllowedRaisedPhantoms;
};

class IParticleEffect {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
};

class ControlTurrets {
    __uint64 m_controlTurretsGameEffectId;
};

class OnDeath {
    float m_aoeDeathRadius;
    float m_aoeDeathSignalScale;
    __uint64 m_aoeDeathSignal;
    class _smart_ptr<IParticleEffect> m_pFearAoeParticleEffect;
};

class NoiseStates {
    class ArkAudioTrigger m_combatStateAudioTrigger;
    class ArkAudioTrigger m_idleStateAudioTrigger;
    class ArkAudioTrigger m_noticeStateAudioTrigger;
    class ArkAudioTrigger m_searchStateAudioTrigger;
    class ArkAudioTrigger m_stareStateAudioTrigger;
};

class DamageStates {
    bool m_bHasDamageStates;
    float m_healthThresholdDamage;
    float m_healthThresholdDisabled;
    float m_destroyedExplosionRadius;
    float m_destroyedExplosionImpulse;
    float m_destroyedExplosionDelay;
    float m_destroyedHeightOffset;
    float m_disabledRepeatDialogCD;
    float m_disabledFlickerDuration;
    char * m_pUndamagedAttachmentName;
    char * m_pDamagedAttachmentName;
    char * m_pDisabledAttachmentName;
    char * m_pChassisModelName;
    char * m_pChassisUndamagedAttachmentName;
    char * m_pChassisDestroyedAttachmentName;
    class ArkAudioTrigger m_becomeUndamagedAudioTrigger;
    class ArkAudioTrigger m_becomeDamagedAudioTrigger;
    class ArkAudioTrigger m_becomeDisabledAudioTrigger;
    __uint64 m_destroyedExplosionPackageId;
    __uint64 m_destroyedExplosionCameraShakeId;
};

class CallForHelp {
    __uint64 m_onAttackNoiseLoudness;
    __uint64 m_onAttackNoiseType;
    __uint64 m_onNewCombatAttentionNoiseLoudness;
    __uint64 m_onNewCombatAttentionNoiseType;
};

class Ability {
    __uint64 m_abilityContextProfileId;
};

class Shift {
    __uint64 m_shiftingSignalModifierId;
};

class Hack {
    bool m_bStartHacked;
    __uint64 m_hackedGameEffectId;
};

class Character {
    __uint64 m_characterId;
};

class HitReaction {
    __uint64 m_hitReactionMaterialAnimationGameEffectId;
};

class HumanArmed {
    bool m_bIsArmed;
    int m_magSize;
    char * m_pGunAttachmentName;
    class IEntityArchetype * m_pLootWeaponEntityArchetype;
};

class AttentionFacing {
    bool m_bUsesAttentionFacing;
    bool m_bUsesAttentionLook;
};

class Nullwave {
    __uint64 m_nullwavedSignalModifierId;
};

class Sound {
    class NoiseStates m_noiseStates;
    class ArkAudioTrigger m_deathAudioTrigger;
    class ArkAudioTrigger m_startAmbientLivingAudioTrigger;
    class ArkAudioTrigger m_stopAmbientLivingAudioTrigger;
};

class CombatRoleInfo {
    bool m_bCanGetStaleInMeleeRole;
    bool m_bUsesCombatRoles;
    float m_meleeRoleCost;
    float m_meleeRolePreference;
    float m_meleeRoleScoreBias;
    float m_minDistanceToAllowRangeRoleSwitchSq;
};

class OnFire {
    __uint64 m_onFireGameEffectId;
};

class Surprise {
    __uint64 m_noiseLoudnessId;
    __uint64 m_noiseTypeId;
};

class MimicJumpAttack {
    __uint64 m_mimicJumpAttackPackageId;
    class _smart_ptr<IParticleEffect> m_pMimicAttackEffect;
};

class Hypnotize {
    float m_timeBetweenHypnotize;
};

class Energized {
    __uint64 m_energizedGameEffectId;
};

class MimicReorient {
    bool m_bSupportsReorientation;
    float m_mimicGlitchRandTimeMax;
    float m_mimicGlitchRandTimeMin;
};

class Fear {
    __uint64 m_fearedGameEffectId;
    __uint64 m_fearedSignalModifierId;
};

class EntityFactionModifier {
    __uint64 m_hositleToFactionId;
};

class Mannequin {
    char * m_pLifetimeTag;
};

class PlayerControlled {
    __uint64 m_playerControlledGameEffectId;
};

class Laser {
    int m_laserHitTypeId;
    float m_beamEndJumpDistanceSq;
    float m_materialEffectCooldown;
    float m_maxLaserLength;
    float m_maxThickness;
    float m_minThickness;
    __uint64 m_laserPackageId;
    int m_customSurfaceTypeId;
    char * m_pBeamEndEffectName;
    char * m_pLaserGeometryName;
    char * m_pLaserMaterialEffectName;
    char * m_pReflectionGeometryName;
    class IEntityArchetype * m_pLootAmmoLaserArchetype;
    class IEntityArchetype * m_pLootAmmoStunArchetype;
};

class MindControl {
    __uint64 m_mindControlGameEffectId;
};

class Audio {
    char * m_pDistanceToPlayerParam;
};

class ArkNpcProperties {
    Ability m_ability;
    AttentionFacing m_attentionFacing;
    Audio m_audio;
    CallForHelp m_callForHelp;
    Character m_character;
    CombatRoleInfo m_combatRoleInfo;
    ControlTurrets m_controlTurrets;
    CorruptNpc m_corruptNpc;
    Corruption m_corruption;
    DamageStates m_damageStates;
    Dodge m_dodge;
    Dormant m_dormant;
    Energized m_energized;
    EntityFactionModifier m_entityFactionModifier;
    Fatality m_fatality;
    Fear m_fear;
    Glooed m_glooed;
    Hack m_hack;
    HitReaction m_hitReaction;
    HumanArmed m_humanArmed;
    Hypnotize m_hypnotize;
    Laser m_laser;
    Mannequin m_mannequin;
    MimicJumpAttack m_mimicJumpAttack;
    MimicReorient m_mimicReorient;
    Mimicry m_mimicry;
    MindControl m_mindControl;
    Nullwave m_nullwave;
    OnDeath m_onDeath;
    OnFire m_onFire;
    OperatorEffects m_operatorEffects;
    PlayerControlled m_playerControlled;
    PoltergeistEffects m_poltergeistEffects;
    RaiseFromCorpse m_raiseFromCorpse;
    RaisePhantom m_raisePhantom;
    Shift m_shift;
    Sound m_sound;
    Stunned m_stunned;
    Surprise m_surprise;
    TurretWeapon m_turretWeapon;
    UnreachableTargeting m_unreachableTargeting;
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
    char * m_pAiTreeFilePath;
    char * m_pFaction;
    __uint64 m_fallDamagePackage;
    __uint64 m_ragdollSignalModifierId;
    enum EArkAttentionLevel m_abortTrackviewOnHostileAttention;
    enum EArkNpcVisionDirection m_visionDirection;
};

