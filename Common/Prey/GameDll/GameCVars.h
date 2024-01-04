// Header file automatically created from a PDB.
#pragma once

struct ICVar;
struct IConsole;

// SGameReleaseConstantCVars
// Header:  Prey/GameDll/gameconstantcvars.h
struct SGameReleaseConstantCVars
{ // Size=1 (0x1)
	static inline auto m_pThis = PreyGlobal<SGameReleaseConstantCVars*>(0x2C09348);
	
	SGameReleaseConstantCVars();
	void Init(IConsole* pConsole) { FInit(this, pConsole); }
	
#if 0
	static const SGameReleaseConstantCVars& Get();
#endif
	
	static inline auto FSGameReleaseConstantCVars = PreyFunction<void(SGameReleaseConstantCVars* const _this)>(0x16E82E0);
	static inline auto FInit = PreyFunction<void(SGameReleaseConstantCVars* const _this, IConsole* pConsole)>(0xA13080);
};

// SAICollisions
// Header:  Prey/GameDll/GameCVars.h
struct SAICollisions
{ // Size=16 (0x10)
	float minSpeedForFallAndPlay;
	float minMassForFallAndPlay;
	float dmgFactorWhenCollidedByObject;
	int showInLog;
};

// SAIPerceptionCVars
// Header:  Prey/GameDll/GameCVars.h
struct SAIPerceptionCVars
{ // Size=32 (0x20)
	int movement_useSurfaceType;
	float movement_movingSurfaceDefault;
	float movement_standingRadiusDefault;
	float movement_crouchRadiusDefault;
	float movement_standingMovingMultiplier;
	float movement_crouchMovingMultiplier;
	float landed_baseRadius;
	float landed_speedMultiplier;
};

// SAIThreatModifierCVars
// Header:  Prey/GameDll/GameCVars.h
struct SAIThreatModifierCVars
{ // Size=72 (0x48)
	const char* DebugAgentName;
	float SOMIgnoreVisualRatio;
	float SOMDecayTime;
	float SOMMinimumRelaxed;
	float SOMMinimumCombat;
	float SOMCrouchModifierRelaxed;
	float SOMCrouchModifierCombat;
	float SOMMovementModifierRelaxed;
	float SOMMovementModifierCombat;
	float SOMWeaponFireModifierRelaxed;
	float SOMWeaponFireModifierCombat;
	float SOMCloakMaxTimeRelaxed;
	float SOMCloakMaxTimeCombat;
	float SOMUncloakMinTimeRelaxed;
	float SOMUncloakMinTimeCombat;
	float SOMUncloakMaxTimeRelaxed;
	float SOMUncloakMaxTimeCombat;
};

// SAltNormalization
// Header:  Prey/GameDll/GameCVars.h
struct SAltNormalization
{ // Size=12 (0xC)
	int enable;
	float hud_ctrl_Curve_Unified;
	float hud_ctrl_Coeff_Unified;
};

// SCaptureTheFlagParams
// Header:  Prey/GameDll/GameCVars.h
struct SCaptureTheFlagParams
{ // Size=4 (0x4)
	float carryingFlag_SpeedScale;
};

// SDeathCamSPParams
// Header:  Prey/GameDll/GameCVars.h
struct SDeathCamSPParams
{ // Size=28 (0x1C)
	int enable;
	int dof_enable;
	float updateFrequency;
	float dofRange;
	float dofRangeNoKiller;
	float dofRangeSpeed;
	float dofDistanceSpeed;
};

// SExtractionParams
// Header:  Prey/GameDll/GameCVars.h
struct SExtractionParams
{ // Size=12 (0xC)
	float carryingTick_SpeedScale;
	float carryingTick_EnergyCostPerHit;
	float carryingTick_DamageAbsorbDesperateEnergyCost;
};

// SJumpAirControl
// Header:  Prey/GameDll/GameCVars.h
struct SJumpAirControl
{ // Size=12 (0xC)
	float air_control_scale;
	float air_resistance_scale;
	float air_inertia_scale;
};

// SPlayerEnemyRamming
// Header:  Prey/GameDll/GameCVars.h
struct SPlayerEnemyRamming
{ // Size=28 (0x1C)
	float player_to_player;
	float ragdoll_to_player;
	float fall_damage_threashold;
	float safe_falling_speed;
	float fatal_falling_speed;
	float max_falling_damage;
	float min_momentum_to_fall;
};

// SPlayerHealth
// Header:  Prey/GameDll/GameCVars.h
struct SPlayerHealth
{ // Size=100 (0x64)
	float normal_regeneration_rateSP;
	float critical_health_thresholdSP;
	float critical_health_updateTimeSP;
	float normal_threshold_time_to_regenerateSP;
	float normal_regeneration_rateMP;
	float critical_health_thresholdMP;
	float fast_regeneration_rateMP;
	float slow_regeneration_rateMP;
	float normal_threshold_time_to_regenerateMP;
	int enable_FallandPlay;
	int collision_health_threshold;
	float fallDamage_SpeedSafe;
	float fallDamage_SpeedFatal;
	float fallSpeed_HeavyLand;
	float fallDamage_SpeedFatalArmor;
	float fallSpeed_HeavyLandArmor;
	float fallDamage_SpeedSafeArmorMP;
	float fallDamage_SpeedFatalArmorMP;
	float fallSpeed_HeavyLandArmorMP;
	float fallDamage_CurveAttackMP;
	float fallDamage_CurveAttack;
	int fallDamage_health_threshold;
	int debug_FallDamage;
	int enableNewHUDEffect;
	int minimalHudEffect;
};

// SPlayerLadder
// Header:  Prey/GameDll/GameCVars.h
struct SPlayerLadder
{ // Size=8 (0x8)
	int ladder_renderPlayerLast;
	int ladder_logVerbosity;
};

// SPlayerLedgeClamber
// Header:  Prey/GameDll/GameCVars.h
struct SPlayerLedgeClamber
{ // Size=12 (0xC)
	float cameraBlendWeight;
	int debugDraw;
	int enableVaultFromStanding;
};

// SPlayerMelee
// Header:  Prey/GameDll/GameCVars.h
struct SPlayerMelee
{ // Size=88 (0x58)
	enum EImpulsesState
	{
		ei_Disabled = 0,
		ei_OnlyToAlive = 1,
		ei_OnlyToDead = 2,
		ei_FullyEnabled = 3,
	};
	
	float melee_snap_angle_limit;
	float melee_snap_blend_speed;
	float melee_snap_target_select_range;
	float melee_snap_end_position_range;
	float melee_snap_move_speed_multiplier;
	float damage_multiplier_from_behind;
	float damage_multiplier_mp;
	float angle_limit_from_behind;
	float mp_victim_screenfx_intensity;
	float mp_victim_screenfx_duration;
	float mp_victim_screenfx_blendout_duration;
	float mp_victim_screenfx_dbg_force_test_duration;
	int impulses_enable;
	int debug_gfx;
	int mp_melee_system;
	int mp_melee_system_camera_lock_and_turn;
	int mp_knockback_enabled;
	float mp_melee_system_camera_lock_time;
	float mp_melee_system_camera_lock_crouch_height_offset;
	float mp_knockback_strength_vert;
	float mp_knockback_strength_hor;
	int mp_sliding_auto_melee_enabled;
};

// SPlayerMovement
// Header:  Prey/GameDll/GameCVars.h
struct SPlayerMovement
{ // Size=56 (0x38)
	float nonCombat_heavy_weapon_speed_scale;
	float nonCombat_heavy_weapon_sprint_scale;
	float nonCombat_heavy_weapon_strafe_speed_scale;
	float nonCombat_heavy_weapon_sneak_speed_scale;
	float power_sprint_targetFov;
	float ground_timeInAirToFall;
	float speedScale;
	float strafe_SpeedScale;
	float sprint_SpeedScale;
	float sneak_SpeedScale;
	int sprintStamina_debug;
	float mp_slope_speed_multiplier_uphill;
	float mp_slope_speed_multiplier_downhill;
	float mp_slope_speed_multiplier_minHill;
};

// SPlayerPickAndThrow
// Header:  Prey/GameDll/GameCVars.h
struct SPlayerPickAndThrow
{ // Size=180 (0xB4)
	int debugDraw;
	int useProxies;
	int cloakedEnvironmentalWeaponsAllowed;
	float maxOrientationCorrectionTime;
	float orientationCorrectionTimeMult;
	float environmentalWeaponObjectImpulseScale;
	float environmentalWeaponImpulseScale;
	float environmentalWeaponHitConeInDegrees;
	float minRequiredThrownEnvWeaponHitVelocity;
	float awayFromPlayerImpulseRatio;
	float environmentalWeaponDesiredRootedGrabAnimDuration;
	float environmentalWeaponDesiredGrabAnimDuration;
	float environmentalWeaponDesiredPrimaryAttackAnimDuration;
	float environmentalWeaponDesiredComboAttackAnimDuration;
	float environmentalWeaponUnrootedPickupTimeMult;
	float environmentalWeaponThrowAnimationSpeed;
	float environmentalWeaponFlippedImpulseOverrideMult;
	float environmentalWeaponFlipImpulseThreshold;
	float environmentalWeaponLivingToArticulatedImpulseRatio;
	int enviromentalWeaponUseThrowInitialFacingOveride;
	float environmentalWeaponMinViewClamp;
	float environmentalWeaponViewLerpZOffset;
	float environmentalWeaponViewLerpSmoothTime;
	float complexMelee_snap_angle_limit;
	float complexMelee_lerp_target_speed;
	float objectImpulseLowMassThreshold;
	float objectImpulseLowerScaleLimit;
	float comboInputWindowSize;
	float minComboInputWindowDurationInSecs;
	float impactNormalGroundClassificationAngle;
	float impactPtValidHeightDiffForImpactStick;
	float reboundAnimPlaybackSpeedMultiplier;
	int environmentalWeaponSweepTestsEnabled;
	float chargedThrowAutoAimDistance;
	float chargedThrowAutoAimConeSize;
	float chargedThrowAutoAimDistanceHeuristicWeighting;
	float chargedThrowAutoAimAngleHeuristicWeighting;
	float chargedThrowAimHeightOffset;
	int chargedthrowAutoAimEnabled;
	int intersectionAssistDebugEnabled;
	int intersectionAssistDeleteObjectOnEmbed;
	float intersectionAssistCollisionsPerSecond;
	float intersectionAssistTimePeriod;
	float intersectionAssistTranslationThreshold;
	float intersectionAssistPenetrationThreshold;
};

// SPlayerSlideControl
// Header:  Prey/GameDll/GameCVars.h
struct SPlayerSlideControl
{ // Size=24 (0x18)
	float min_speed_threshold;
	float min_speed;
	float deceleration_speed;
	float min_downhill_threshold;
	float max_downhill_threshold;
	float max_downhill_acceleration;
};

// SPostEffect
// Header:  Prey/GameDll/GameCVars.h
struct SPostEffect
{ // Size=52 (0x34)
	float FilterGrain_Amount;
	float FilterRadialBlurring_Amount;
	float FilterRadialBlurring_ScreenPosX;
	float FilterRadialBlurring_ScreenPosY;
	float FilterRadialBlurring_Radius;
	float Global_User_ColorC;
	float Global_User_ColorM;
	float Global_User_ColorY;
	float Global_User_ColorK;
	float Global_User_Brightness;
	float Global_User_Contrast;
	float Global_User_Saturation;
	float Global_User_ColorHue;
};

// SPowerSprintParams
// Header:  Prey/GameDll/GameCVars.h
struct SPowerSprintParams
{ // Size=4 (0x4)
	float foward_angle;
};

// SPredatorParams
// Header:  Prey/GameDll/GameCVars.h
struct SPredatorParams
{ // Size=8 (0x8)
	float hudTimerAlertWhenTimeRemaining;
	float hintMessagePauseTime;
};

// SSpectacularKillCVars
// Header:  Prey/GameDll/GameCVars.h
struct SSpectacularKillCVars
{ // Size=28 (0x1C)
	float maxDistanceError;
	float minTimeBetweenKills;
	float minTimeBetweenSameKills;
	float minKillerToTargetDotProduct;
	float maxHeightBetweenActors;
	float sqMaxDistanceFromPlayer;
	int debug;
};

// SCVars
// Header:  Prey/GameDll/GameCVars.h
struct SCVars
{ // Size=3688 (0xE68)
	enum EHitDeathReactionsLogReactionAnimsType
	{
		eHDRLRAT_DontLog = 0,
		eHDRLRAT_LogAnimNames = 1,
		eHDRLRAT_LogFilePaths = 2,
	};
	
	enum EHitDeathReactionsStreamingPolicy
	{
		eHDRSP_Disabled = 0,
		eHDRSP_ActorsAliveAndNotInPool = 1,
		eHDRSP_EntityLifespanBased = 2,
	};
	
	SGameReleaseConstantCVars m_releaseConstants;
	float cl_fov;
	float cl_hfov;
	float cl_mp_fov_scalar;
	float cl_tpvDist;
	float cl_tpvYaw;
	float cl_sensitivity;
	float cl_sensitivityController;
	float cl_sensitivityControllerMP;
	float cl_reticleSensitivityController;
	int cl_invertMouse;
	int cl_invertController;
	int cl_sneakToggle;
	int cl_worldUIExaminationToggle;
	int cl_sprintToggle;
	int cl_debugSwimming;
	int cl_logAsserts;
	int cl_zoomToggle;
	float cl_motionBlurVectorScale;
	float cl_motionBlurVectorScaleSprint;
	int g_enableMPDoubleTapGrenadeSwitch;
	ICVar* ca_GameControlledStrafingPtr;
	float cl_shallowWaterSpeedMulPlayer;
	float cl_shallowWaterSpeedMulAI;
	float cl_shallowWaterDepthLo;
	float cl_shallowWaterDepthHi;
	float cl_speedToBobFactor;
	float cl_bobAmount;
	float cl_rollAmount;
	float cl_bobWidth;
	float cl_bobHeight;
	float cl_bobSprintMultiplier;
	float cl_bobVerticalMultiplier;
	float cl_bobMaxHeight;
	float cl_strafeHorzScale;
	float g_highlightingMaxDistanceToHighlightSquared;
	float g_highlightingMovementDistanceToUpdateSquared;
	float g_highlightingTimeBetweenForcedRefresh;
	float g_ledgeGrabClearHeight;
	float g_ledgeGrabMovingledgeExitVelocityMult;
	float g_vaultMinHeightDiff;
	float g_vaultMinAnimationSpeed;
	int g_cloakFlickerOnRun;
	int kc_useAimAdjustment;
	float kc_aimAdjustmentMinAngle;
	float kc_precacheTimeStartPos;
	float kc_precacheTimeWeaponModels;
	int g_useQuickGrenadeThrow;
	int g_debugWeaponOffset;
	int g_MicrowaveBeamStaticObjectMaxChunkThreshold;
	float i_fastSelectMultiplier;
	float cl_idleBreaksDelayTime;
	int cl_postUpdateCamera;
	int p_collclassdebug;
	float pl_cameraTransitionTime;
	float pl_cameraTransitionTimeLedgeGrabIn;
	float pl_cameraTransitionTimeLedgeGrabOut;
	float pl_slideCameraFactor;
	float cl_slidingBlurRadius;
	float cl_slidingBlurAmount;
	float cl_slidingBlurBlendSpeed;
	int sv_votingTimeout;
	int sv_votingCooldown;
	int sv_votingEnable;
	int sv_votingMinVotes;
	float sv_votingRatio;
	float sv_votingTeamRatio;
	float sv_votingBanTime;
	int sv_input_timeout;
	ICVar* sv_aiTeamName;
	ICVar* performance_profile_logname;
	int g_infiniteAmmoTutorialMode;
	int i_lighteffects;
	int i_particleeffects;
	int i_rejecteffects;
	int i_grenade_showTrajectory;
	float i_grenade_trajectory_resolution;
	float i_grenade_trajectory_dashes;
	float i_grenade_trajectory_gaps;
	int i_grenade_trajectory_useGeometry;
	int i_ironsight_while_jumping_mp;
	int i_ironsight_while_falling_mp;
	float i_ironsight_falling_unzoom_minAirTime;
	float i_weapon_customisation_transition_time;
	int i_highlight_dropped_weapons;
	float i_laser_hitPosOffset;
	float pl_inputAccel;
	int pl_debug_energyConsumption;
	int pl_debug_pickable_items;
	float pl_useItemHoldTime;
	int pl_autoPickupItemsWhenUseHeld;
	float pl_autoPickupMinTimeBetweenPickups;
	int pl_debug_projectileAimHelper;
	float pl_nanovision_timeToRecharge;
	float pl_nanovision_timeToDrain;
	float pl_nanovision_minFractionToUse;
	float pl_refillAmmoDelay;
	int pl_spawnCorpseOnDeath;
	int pl_doLocalHitImpulsesMP;
	int kc_enable;
	int kc_debug;
	int kc_debugStressTest;
	int kc_debugVictimPos;
	int kc_debugWinningKill;
	int kc_debugSkillKill;
	int kc_memStats;
	int kc_maxFramesToPlayAtOnce;
	int kc_cameraCollision;
	int kc_showHighlightsAtEndOfGame;
	int kc_enableWinningKill;
	int kc_canSkip;
	float kc_length;
	float kc_skillKillLength;
	float kc_bulletSpeed;
	float kc_bulletHoverDist;
	float kc_bulletHoverTime;
	float kc_bulletHoverTimeScale;
	float kc_bulletPostHoverTimeScale;
	float kc_bulletTravelTimeScale;
	float kc_bulletCamOffsetX;
	float kc_bulletCamOffsetY;
	float kc_bulletCamOffsetZ;
	float kc_bulletRiflingSpeed;
	float kc_bulletZoomDist;
	float kc_bulletZoomTime;
	float kc_bulletZoomOutRatio;
	float kc_kickInTime;
	float kc_projectileDistance;
	float kc_projectileHeightOffset;
	float kc_largeProjectileDistance;
	float kc_largeProjectileHeightOffset;
	float kc_projectileVictimHeightOffset;
	float kc_projectileMinimumVictimDist;
	float kc_smoothing;
	float kc_grenadeSmoothingDist;
	float kc_cameraRaiseHeight;
	float kc_resendThreshold;
	float kc_chunkStreamTime;
	float g_multikillTimeBetweenKills;
	float g_flushed_timeBetweenGrenadeBounceAndSkillKill;
	float g_gotYourBackKill_targetDistFromFriendly;
	float g_gotYourBackKill_FOVRange;
	float g_guardian_maxTimeSinceLastDamage;
	float g_defiant_timeAtLowHealth;
	float g_defiant_lowHealthFraction;
	float g_intervention_timeBetweenZoomedAndKill;
	float g_blinding_timeBetweenFlashbangAndKill;
	float g_blinding_flashbangRecoveryDelayFrac;
	float g_neverFlagging_maxMatchTimeRemaining;
	float g_combinedFire_maxTimeBetweenWeapons;
	float g_fovToRotationSpeedInfluence;
	int dd_maxRMIsPerFrame;
	float dd_waitPeriodBetweenRMIBatches;
	int g_debugSpawnPointsRegistration;
	int g_debugSpawnPointValidity;
	float g_randomSpawnPointCacheTime;
	int g_detachCamera;
	int g_moveDetachedCamera;
	float g_detachedCameraMoveSpeed;
	float g_detachedCameraRotateSpeed;
	float g_detachedCameraTurboBoost;
	int g_detachedCameraDebug;
	int g_difficultyLevel;
	int g_difficultyLevelLowestPlayed;
	float g_flashBangMinSpeedMultiplier;
	float g_flashBangSpeedMultiplierFallOffEase;
	float g_flashBangNotInFOVRadiusFraction;
	float g_flashBangMinFOVMultiplier;
	int g_flashBangFriends;
	int g_flashBangSelf;
	float g_friendlyLowerItemMaxDistance;
	int g_holdObjectiveDebug;
	int g_gameRayCastQuota;
	int g_gameIntersectionTestQuota;
	int g_STAPCameraAnimation;
	float g_reticleYPercentage;
	float g_ExplosionImpulseScale;
	int g_debugaimlook;
	float g_playerLowHealthThreshold;
	float g_playerMidHealthThreshold;
	int g_SurvivorOneVictoryConditions_watchLvl;
	int g_SimpleEntityBasedObjective_watchLvl;
	int g_CTFScoreElement_watchLvl;
	int g_KingOfTheHillObjective_watchLvl;
	float g_HoldObjective_secondsBeforeStartForSpawn;
	int g_CombiCaptureObjective_watchLvl;
	int g_CombiCaptureObjective_watchTerminalSignalPlayers;
	int g_disable_OpponentsDisconnectedGameEnd;
	int g_victoryConditionsDebugDrawResolution;
	int g_restartWhenPrematchFinishes;
	float g_predator_marineRedCrosshairDelay;
	int sv_pacifist;
	int g_devDemo;
	int g_bulletPenetrationDebug;
	float g_bulletPenetrationDebugTimeout;
	int g_fpDbaManagementEnable;
	int g_fpDbaManagementDebug;
	int g_charactersDbaManagementEnable;
	int g_charactersDbaManagementDebug;
	int g_thermalVisionDebug;
	float g_droppedItemVanishTimer;
	float g_droppedHeavyWeaponVanishTimer;
	int g_corpseManager_maxNum;
	float g_corpseManager_timeoutInSeconds;
	float g_explosion_materialFX_raycastLength;
	int g_ec_enable;
	float g_ec_radiusScale;
	float g_ec_volume;
	float g_ec_extent;
	int g_ec_removeThreshold;
	float g_radialBlur;
	float g_timelimit;
	float g_timelimitextratime;
	float g_roundScoreboardTime;
	float g_roundStartTime;
	int g_roundlimit;
	float g_friendlyfireratio;
	int g_revivetime;
	int g_minplayerlimit;
	float g_hostMigrationResumeTime;
	int g_hostMigrationUseAutoLobbyMigrateInPrivateGames;
	int g_minPlayersForRankedGame;
	float g_gameStartingMessageTime;
	int g_mpRegenerationRate;
	int g_mpHeadshotsOnly;
	int g_mpNoVTOL;
	int g_mpNoEnvironmentalWeapons;
	int g_allowCustomLoadouts;
	int g_allowFatalityBonus;
	float g_spawnPrecacheTimeBeforeRevive;
	float g_autoReviveTime;
	float g_spawn_timeToRetrySpawnRequest;
	float g_spawn_recentSpawnTimer;
	float g_forcedReviveTime;
	int g_numLives;
	int g_autoAssignTeams;
	float g_maxHealthMultiplier;
	int g_mp_as_DefendersMaxHealth;
	float g_xpMultiplyer;
	int g_allowExplosives;
	int g_forceWeapon;
	int g_allowSpectators;
	int g_infiniteCloak;
	int g_allowWeaponCustomisation;
	ICVar* g_forceHeavyWeapon;
	ICVar* g_forceLoadoutPackage;
	int g_switchTeamAllowed;
	int g_switchTeamRequiredPlayerDifference;
	int g_switchTeamUnbalancedWarningDifference;
	float g_switchTeamUnbalancedWarningTimer;
	int g_tk_punish;
	int g_tk_punish_limit;
	int g_debugNetPlayerInput;
	int g_debugCollisionDamage;
	int g_debugHits;
	int g_suppressHitSanityCheckWarnings;
	int g_drawLeaks;
	int g_transcribeAutosaveFrequency;
	int g_enableLanguageSelectionMenu;
	int g_multiplayerDefault;
	int g_multiplayerModeOnly;
	int g_EPD;
	int g_frontEndRequiredEPD;
	int g_EnableDevMenuOptions;
	int g_frontEndUnicodeInput;
	int g_DisableMenuButtons;
	int g_EnablePersistantStatsDebugScreen;
	int g_craigNetworkDebugLevel;
	int g_presaleUnlock;
	int g_dlcPurchaseOverwrite;
	int g_MatchmakingVersion;
	int g_MatchmakingBlock;
	int g_enableInitialLoadoutScreen;
	int g_ProcessOnlineCallbacks;
	float g_gameRules_startTimerLength;
	float g_gameRules_postGame_HUDMessageTime;
	float g_gameRules_postGame_Top3Time;
	float g_gameRules_postGame_ScoreboardTime;
	int g_gameRules_startTimerMinPlayers;
	int g_gameRules_startTimerMinPlayersPerTeam;
	float g_gameRules_startTimerPlayersRatio;
	float g_gameRules_startTimerOverrideWait;
	int g_gameRules_preGame_StartSpawnedFrozen;
	int g_debug_fscommand;
	int g_skipIntro;
	int g_skipAfterLoadingScreen;
	int g_goToCampaignAfterTutorial;
	int g_aiCorpses_Enable;
	int g_aiCorpses_DebugDraw;
	int g_aiCorpses_MaxCorpses;
	float g_aiCorpses_DelayTimeToSwap;
	float g_aiCorpses_CullPhysicsDistance;
	float g_aiCorpses_ForceDeleteDistance;
	int g_scoreLimit;
	int g_scoreLimitOverride;
	float g_spawn_explosiveSafeDist;
	int g_logPrimaryRound;
	int g_server_region;
	int g_enableInitialLoginSilent;
	float g_dataRefreshFrequency;
	int g_maxGameBrowserResults;
	int g_inventoryNoLimits;
	int g_inventoryWeaponCapacity;
	int g_inventoryExplosivesCapacity;
	int g_inventoryGrenadesCapacity;
	int g_inventorySpecialCapacity;
	int g_loadoutServerControlled;
	ICVar* pl_debug_filter;
	int pl_debug_vistable;
	int pl_debug_movement;
	int pl_debug_jumping;
	int pl_debug_aiming;
	int pl_debug_aiming_input;
	int pl_debug_view;
	int pl_debug_hit_recoil;
	int pl_debug_look_poses;
	int pl_renderInNearest;
	int pl_aim_assistance_enabled;
	int pl_aim_assistance_disabled_atDifficultyLevel;
	int pl_aim_acceleration_enabled;
	float pl_aim_cloaked_multiplier;
	float pl_aim_near_lookat_target_distance;
	int pl_targeting_debug;
	int pl_switchTPOnKill;
	int pl_stealthKill_allowInMP;
	int pl_stealthKill_uncloakInMP;
	int pl_stealthKill_debug;
	float pl_stealthKill_aimVsSpineLerp;
	float pl_stealthKill_maxVelocitySquared;
	int pl_slealth_cloakinterference_onactionMP;
	int pl_stealthKill_usePhysicsCheck;
	int pl_stealthKill_useExtendedRange;
	float pl_stealth_shotgunDamageCap;
	float pl_shotgunDamageCap;
	float pl_freeFallDeath_cameraAngle;
	float pl_freeFallDeath_fadeTimer;
	float pl_fall_intensity_multiplier;
	float pl_fall_intensity_max;
	float pl_fall_time_multiplier;
	float pl_fall_time_max;
	float pl_fall_intensity_hit_multiplier;
	float pl_TacticalScanDuration;
	float pl_TacticalScanDurationMP;
	float pl_TacticalTaggingDuration;
	float pl_TacticalTaggingDurationMP;
	float controller_power_curve;
	float controller_multiplier_z;
	float controller_multiplier_x;
	float controller_full_turn_multiplier_x;
	float controller_full_turn_multiplier_z;
	int ctrlr_corner_smoother;
	int ctrlr_corner_smoother_debug;
	int ctrlr_OUTPUTDEBUGINFO;
	float pl_stampTimeout;
	int pl_stampTier;
	float pl_jump_maxTimerValue;
	float pl_jump_baseTimeAddedPerJump;
	float pl_jump_currentTimeMultiplierOnJump;
	float pl_jump_quickPressThresh;
	int pl_showClimbIndicator;
	int pl_boostedMelee_allowInMP;
	float pl_velocityInterpAirControlScale;
	int pl_velocityInterpSynchJump;
	int pl_debugInterpolation;
	float pl_velocityInterpAirDeltaFactor;
	float pl_velocityInterpPathCorrection;
	int pl_velocityInterpAlwaysSnap;
	int pl_adjustJumpAngleWithFloorNormal;
	float pl_netAimLerpFactor;
	float pl_netSerialiseMaxSpeed;
	int pl_serialisePhysVel;
	float pl_clientInertia;
	float pl_fallHeight;
	float pl_legs_colliders_dist;
	float pl_legs_colliders_scale;
	float g_manualFrameStepFrequency;
	SPowerSprintParams pl_power_sprint;
	SJumpAirControl pl_jump_control;
	SPlayerHealth pl_health;
	SPlayerMovement pl_movement;
	SPlayerLedgeClamber pl_ledgeClamber;
	SPlayerLadder pl_ladderControl;
	SPlayerPickAndThrow pl_pickAndThrow;
	SPlayerSlideControl pl_sliding_control;
	SPlayerSlideControl pl_sliding_control_mp;
	SPlayerEnemyRamming pl_enemy_ramming;
	SAICollisions AICollisions;
	SPlayerMelee pl_melee;
	SAltNormalization aim_altNormalization;
	SCaptureTheFlagParams mp_ctfParams;
	SExtractionParams mp_extractionParams;
	SPredatorParams mp_predatorParams;
	int g_FootstepSoundsFollowEntity;
	int g_FootstepSoundsDebug;
	float g_footstepSoundMaxDistanceSq;
	float pl_swimBackSpeedMul;
	float pl_swimSideSpeedMul;
	float pl_swimVertSpeedMul;
	float pl_swimNormalSprintSpeedMul;
	int pl_swimAlignArmsToSurface;
	int pl_drownDamage;
	float pl_drownTime;
	float pl_drownRecoveryTime;
	float pl_drownDamageInterval;
	int pl_mike_debug;
	int pl_mike_maxBurnPoints;
	int pl_impulseEnabled;
	float pl_impulseDuration;
	int pl_impulseLayer;
	float pl_impulseFullRecoilFactor;
	float pl_impulseMaxPitch;
	float pl_impulseMaxTwist;
	float pl_impulseCounterFactor;
	int pl_ZeroGRollFixInputMode;
	int pl_ZeroGRollMode;
	int pl_ZeroGRollPivotOffset;
	float pl_ExplosionUpImpulseScale;
	float pl_PsiTargetingDepthCamSpeed;
	float pl_fictionalTimeScale;
	int pl_unlimitedPsi;
	int pl_forceFlashlight;
	int pl_infiniteFlashlight;
	int pl_useFemaleModel;
	float pl_cameraNearZ;
	int pl_enableTraumas;
	int g_assertWhenVisTableNotUpdatedForNumFrames;
	float gl_time;
	float gl_waitForBalancedGameTime;
	int hud_ContextualHealthIndicator;
	float hud_objectiveIcons_flashTime;
	int hud_faderDebug;
	int hud_ctrlZoomMode;
	int hud_aspectCorrection;
	float hud_canvas_width_adjustment;
	int hud_colorLine;
	int hud_colorOver;
	int hud_colorText;
	float hud_defaultObjectiveTaskOpaqueDistance;
	float hud_objectiveTaskFadeDistance;
	float hud_objectiveTaskTextFadeDistance;
	float hud_logVisibleDuration;
	int hud_subtitles;
	int hud_tutorials;
	int hud_playstationContext;
	int hud_forceControllerGlyphs;
	int hud_startPaused;
	int hud_allowMouseInput;
	int hud_reticleSetting;
	int hud_showOptionalHud;
	int hud_showPlayerState;
	int hud_showHitFeedback;
	int hud_showObjectiveMarkers;
	int hud_showEnemyMarkers;
	int hud_showPsiScanPrompt;
	int hud_showHudLog;
	int hud_showLegends;
	int hud_showInteractPrompt;
	int hud_showEnemyHealthBar;
	int hud_psychoPsycho;
	int hud_hide;
	int menu3D_enabled;
	int g_flashrenderingduringloading;
	int g_levelfadein_levelload;
	int g_levelfadein_quickload;
	float aim_assistMinDistance;
	float aim_assistMaxDistance;
	float aim_assistMaxDistanceTagged;
	float aim_assistFalloffDistance;
	float aim_assistInputForFullFollow_Ironsight;
	float aim_assistMinTurnScale;
	float aim_assistSlowFalloffStartDistance;
	float aim_assistSlowDisableDistance;
	float aim_assistSlowThresholdOuter;
	float aim_assistSlowDistanceModifier;
	float aim_assistSlowStartFadeinDistance;
	float aim_assistSlowStopFadeinDistance;
	float aim_assistStrength;
	float aim_assistSnapRadiusScale;
	float aim_assistSnapRadiusTaggedScale;
	float aim_assistStrength_IronSight;
	float aim_assistMaxDistance_IronSight;
	float aim_assistMinTurnScale_IronSight;
	float aim_assistStrength_SniperScope;
	float aim_assistMaxDistance_SniperScope;
	float aim_assistMinTurnScale_SniperScope;
	ICVar* i_debuggun_1;
	ICVar* i_debuggun_2;
	float slide_spread;
	int i_debug_projectiles;
	int i_debug_weaponActions;
	int i_debug_spread;
	int i_debug_recoil;
	int i_auto_turret_target;
	int i_auto_turret_target_tacshells;
	int i_debug_zoom_mods;
	int i_debug_turrets;
	int i_debug_sounds;
	int i_debug_mp_flowgraph;
	int i_flashlight_has_shadows;
	int i_flashlight_has_fog_volume;
	int i_debug_itemparams_memusage;
	int i_debug_weaponparams_memusage;
	float i_failedDetonation_speedMultiplier;
	float i_failedDetonation_lifetime;
	float i_hmg_detachWeaponAnimFraction;
	float i_hmg_impulseLocalDirection_x;
	float i_hmg_impulseLocalDirection_y;
	float i_hmg_impulseLocalDirection_z;
	int g_displayIgnoreList;
	int g_buddyMessagesIngame;
	int g_enableFriendlyAIHits;
	int g_enableFriendlyPlayerHits;
	int g_mpAllSeeingRadar;
	int g_mpAllSeeingRadarSv;
	int g_mpDisableRadar;
	int g_mpNoEnemiesOnRadar;
	int g_mpHatsBootsOnRadar;
	int g_spectate_TeamOnly;
	int g_spectate_DisableManual;
	int g_spectate_DisableDead;
	int g_spectate_DisableFree;
	int g_spectate_DisableFollow;
	float g_spectate_skipInvalidTargetAfterTime;
	float g_spectate_follow_orbitYawSpeedDegrees;
	int g_spectate_follow_orbitAlsoRotateWithTarget;
	float g_spectate_follow_orbitMouseSpeedMultiplier;
	float g_spectate_follow_orbitMinPitchRadians;
	float g_spectate_follow_orbitMaxPitchRadians;
	int g_deathCam;
	int g_spectatorOnly;
	float g_spectatorOnlySwitchCooldown;
	int g_forceIntroSequence;
	int g_IntroSequencesEnabled;
	SDeathCamSPParams g_deathCamSP;
	float g_tpdeathcam_timeOutKilled;
	float g_tpdeathcam_timeOutSuicide;
	float g_tpdeathcam_lookDistWhenNoKiller;
	float g_tpdeathcam_camDistFromPlayerStart;
	float g_tpdeathcam_camDistFromPlayerEnd;
	float g_tpdeathcam_camDistFromPlayerMin;
	float g_tpdeathcam_camHeightTweak;
	float g_tpdeathcam_camCollisionRadius;
	float g_tpdeathcam_maxBumpCamUpOnCollide;
	float g_tpdeathcam_zVerticalLimit;
	float g_tpdeathcam_testLenIncreaseRestriction;
	float g_tpdeathcam_collisionEpsilon;
	float g_tpdeathcam_directionalFocusGroundTestLen;
	float g_tpdeathcam_camSmoothSpeed;
	float g_tpdeathcam_maxTurn;
	int g_killercam_disable;
	float g_killercam_displayDuration;
	float g_killercam_dofBlurAmount;
	float g_killercam_dofFocusRange;
	int g_killercam_canSkip;
	float g_postkill_minTimeForDeathCamAndKillerCam;
	float g_postkill_splitScaleDeathCam;
	int g_useHitSoundFeedback;
	int g_useSkillKillSoundEffects;
	int g_hasWindowFocus;
	int g_displayPlayerDamageTaken;
	int g_displayDbgText_hud;
	int g_displayDbgText_silhouettes;
	int g_displayDbgText_plugins;
	int g_displayDbgText_pmv;
	int g_displayDbgText_actorState;
	int g_spawn_vistable_numLineTestsPerFrame;
	int g_spawn_vistable_numAreaTestsPerFrame;
	int g_showShadowChar;
	int g_infiniteAmmo;
	float g_persistantStats_gamesCompletedFractionNeeded;
	int g_animatorDebug;
	int g_hideArms;
	int g_debugSmokeGrenades;
	float g_smokeGrenadeRadius;
	float g_empOverTimeGrenadeLife;
	int g_kickCarDetachesEntities;
	float g_kickCarDetachStartTime;
	float g_kickCarDetachEndTime;
	int g_playerUsesDedicatedInput;
	int watch_enabled;
	float watch_text_render_start_pos_x;
	float watch_text_render_start_pos_y;
	float watch_text_render_size;
	float watch_text_render_lineSpacing;
	float watch_text_render_fxscale;
	int autotest_enabled;
	ICVar* autotest_state_setup;
	int autotest_quit_when_done;
	int autotest_verbose;
	int designer_warning_enabled;
	int designer_warning_level_resources;
	int g_teamDifferentiation;
	SPostEffect g_postEffect;
	int g_gameFXSystemDebug;
	int g_gameFXLightningProfile;
	int g_DebugDrawPhysicsAccess;
	int ai_DebugVisualScriptErrors;
	int ai_EnablePressureSystem;
	int ai_DebugPressureSystem;
	int ai_DebugAggressionSystem;
	int ai_DebugBattleFront;
	int ai_DebugSearch;
	int ai_DebugDeferredDeath;
	float ai_CloakingDelay;
	float ai_CompleteCloakDelay;
	float ai_UnCloakingDelay;
	int ai_HazardsDebug;
	int ai_SquadManager_DebugDraw;
	float ai_SquadManager_MaxDistanceFromSquadCenter;
	float ai_SquadManager_UpdateTick;
	float ai_ProximityToHostileAlertnessIncrementThresholdDistance;
	int ai_invulnerable;
	int ai_cantdie;
	int ai_forceEnableNightmareManager;
	int g_actorViewDistRatio;
	int g_playerLodRatio;
	float g_itemsLodRatioScale;
	float g_itemsViewDistanceRatioScale;
	int g_hitDeathReactions_enable;
	int g_hitDeathReactions_useLuaDefaultFunctions;
	int g_hitDeathReactions_disable_ai;
	int g_hitDeathReactions_debug;
	int g_hitDeathReactions_disableRagdoll;
	int g_hitDeathReactions_usePrecaching;
	int g_hitDeathReactions_logReactionAnimsOnLoading;
	int g_hitDeathReactions_streaming;
	SSpectacularKillCVars g_spectacularKill;
	int g_movementTransitions_enable;
	int g_movementTransitions_log;
	int g_movementTransitions_debug;
	float g_maximumDamage;
	float g_instantKillDamageThreshold;
	int g_flyCamLoop;
	int g_dummyPlayersFire;
	int g_dummyPlayersMove;
	int g_dummyPlayersChangeWeapon;
	float g_dummyPlayersJump;
	int g_dummyPlayersRespawnAtDeathPosition;
	int g_dummyPlayersCommitSuicide;
	int g_dummyPlayersShowDebugText;
	float g_dummyPlayersMinInTime;
	float g_dummyPlayersMaxInTime;
	float g_dummyPlayersMinOutTime;
	float g_dummyPlayersMaxOutTime;
	ICVar* g_dummyPlayersGameRules;
	int g_dummyPlayersRanked;
	int g_muzzleFlashCull;
	float g_muzzleFlashCullDistance;
	int g_rejectEffectVisibilityCull;
	float g_rejectEffectCullDistance;
	int g_mpCullShootProbablyHits;
	float g_cloakRefractionScale;
	float g_cloakBlendSpeedScale;
	int g_telemetry_onlyInGame;
	int g_telemetry_drawcall_budget;
	int g_telemetry_memory_display;
	int g_telemetry_memory_size_sp;
	int g_telemetry_memory_size_mp;
	int g_telemetry_gameplay_enabled;
	int g_telemetry_gameplay_save_to_disk;
	int g_telemetry_gameplay_gzip;
	int g_telemetry_gameplay_copy_to_global_heap;
	int g_telemetryEnabledSP;
	float g_telemetrySampleRatePerformance;
	float g_telemetrySampleRateBandwidth;
	float g_telemetrySampleRateMemory;
	float g_telemetrySampleRateSound;
	float g_telemetry_xp_event_send_interval;
	float g_telemetry_mp_upload_delay;
	const char* g_telemetryTags;
	const char* g_telemetryConfig;
	int g_telemetry_serialize_method;
	int g_telemetryDisplaySessionId;
	const char* g_telemetryEntityClassesToExport;
	int g_modevarivar_proHud;
	int g_modevarivar_disableKillCam;
	int g_modevarivar_disableSpectatorCam;
	const char* g_dataCentreConfigStr;
	const char* g_downloadMgrDataCentreConfigStr;
	int g_ignoreDLCRequirements;
	float sv_netLimboTimeout;
	float g_idleKickTime;
	int g_useOnlineServiceForDedicated;
	int g_enablePoolCache;
	int g_setActorModelFromLua;
	int g_loadPlayerModelOnLoad;
	int g_enableActorLuaCache;
	int g_enableSlimCheckpoints;
	float g_mpLoaderScreenMaxTime;
	float g_mpLoaderScreenMaxTimeSoftLimit;
	int g_mpKickableCars;
	float g_forceItemRespawnTimer;
	float g_defaultItemRespawnTimer;
	float g_updateRichPresenceInterval;
	int g_useNetSyncToSpeedUpRMIs;
	ICVar* g_presaleURL;
	ICVar* g_messageOfTheDay;
	ICVar* g_serverImageUrl;
	SAIPerceptionCVars ai_perception;
	SAIThreatModifierCVars ai_threatModifiers;
	int pl_showInactiveTasks;
	float pl_maxRegen;
	float pl_taskLabelShowAngle;
	int pl_enableFPIK;
	float pl_incrementCameraYaw;
	int g_debugTimerEvents;
	int beta_debugShift;
	int pl_playerVoiceOn;
	int pl_playerVoiceFemale;
	int pl_danielleRobo;
	int s_DrawDialogAudioLatency;
	int pl_traumaDebug;
	int g_shownightmareheat;
	int g_debugdistraction;
	int g_debugDistractionCurrentAI;
	int wpn_firstTimePickup;
	float g_arkLightDisableDistance;
	static inline auto bInOnHudShowOptionalHud = PreyGlobal<bool>(0x2C09350);
	
	void InitCVars(IConsole* pConsole) { FInitCVars(this, pConsole); }
	void ReleaseCVars() { FReleaseCVars(this); }
	void InitAIPerceptionCVars(IConsole* pConsole) { FInitAIPerceptionCVars(this, pConsole); }
	void RefreshFOVCVars(const float _aspectRatio) { FRefreshFOVCVars(this, _aspectRatio); }
	static void UpdateShowOptionalHud(ICVar* const _pCvar) { FUpdateShowOptionalHud(_pCvar); }
	
#if 0
	SCVars();
	~SCVars();
	void ReleaseAIPerceptionCVars(IConsole* _arg0_);
#endif
	
	static inline auto FInitCVars = PreyFunction<void(SCVars* const _this, IConsole* pConsole)>(0x16EA6C0);
	static inline auto FReleaseCVars = PreyFunction<void(SCVars* const _this)>(0x16FA090);
	static inline auto FInitAIPerceptionCVars = PreyFunction<void(SCVars* const _this, IConsole* pConsole)>(0x16EA450);
	static inline auto FRefreshFOVCVars = PreyFunction<void(SCVars* const _this, const float _aspectRatio)>(0x16F95D0);
	static inline auto FUpdateShowOptionalHud = PreyFunction<void(ICVar* const _pCvar)>(0x16FCB30);
};

inline PreyGlobal<SCVars*> g_pGameCVars(0x2C09000);
