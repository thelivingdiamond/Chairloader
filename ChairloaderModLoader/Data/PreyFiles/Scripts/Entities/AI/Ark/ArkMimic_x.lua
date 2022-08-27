Script.ReloadScript("SCRIPTS/Entities/AI/Shared/AIBase.lua")
ArkMimic_x = {
  ActionController = "Animations/Mannequin/ADB/Ai_Mimic_ControllerDefs.xml",
  AnimDatabase3P = "Animations/Mannequin/ADB/Ai_Mimic_Database.adb",
  UseMannequinAGState = true,
  UseLegacyCoverLocator = false,
  physicsParams = {
    Living = {
      mass = 30,
      air_resistance = 0,
      height = 0.51,
      size = {
        x = 0.5,
        y = 0.5,
        z = 0.18
      },
      use_capsule = 0
    }
  },
  gameParams = {
    boneIDs = {
      BONE_BIP01 = "root_jnt",
      BONE_SPINE = "cog_jnt",
      BONE_SPINE2 = "cog_jnt",
      BONE_SPINE3 = "cog_jnt",
      BONE_HEAD = "head_jnt",
      BONE_WEAPON = "tentacle13C_jnt",
      BONE_WEAPON2 = "tentacle13D_jnt",
      BONE_FOOT_R = "tentacle13A_jnt",
      BONE_FOOT_L = "tentacle13B_jnt",
      BONE_ARM_R = "tentacle13C_jnt",
      BONE_ARM_L = "tentacle13D_jnt",
      BONE_CALF_R = "tentacle12A_jnt",
      BONE_CALF_L = "tentacle12B_jnt",
      BONE_CAMERA = "neck_jnt"
    },
    meeleHitRagdollImpulseScale = 1,
    lookFOV = 360,
    lookInVehicleFOV = 110,
    aimFOV = 360,
    maxLookAimAngle = 120,
    aimIKFadeDuration = 0.5,
    aimIKLayer = 14,
    proceduralLeaningFactor = 0,
    canUseComplexLookIK = true,
    lookAtSimpleHeadBone = "head_jnt",
    cornerSmoother = 0,
    smoothedZTurning = true,
    stepThresholdTime = 0.5,
    stepThresholdDistance = 0.1,
    turnThresholdTime = 0.5,
    turnThresholdAngle = 5,
    maxDeltaAngleRateNormal = 135,
    maxDeltaAngleRateFast = 135,
    maxDeltaAngleRateFastest = 135,
    nearbyRange = 10,
    middleRange = 30,
    defaultStance = STANCE_RELAXED,
    stance = {
      {
        stanceId = STANCE_STAND,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 0.51,
        heightPivot = 0,
        size = {
          x = 0.5,
          y = 0.5,
          z = 0.18
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 0.5
        },
        name = "stand",
        useCapsule = 0
      },
      {
        stanceId = STANCE_ALERTED,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 0.51,
        heightPivot = 0,
        size = {
          x = 0.5,
          y = 0.5,
          z = 0.18
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 0.5
        },
        name = "alerted",
        useCapsule = 0
      },
      {
        stanceId = STANCE_INVESTIGATE_ANOMALY,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 0.51,
        heightPivot = 0,
        size = {
          x = 0.5,
          y = 0.5,
          z = 0.18
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 0.5
        },
        name = "anomaly",
        useCapsule = 0
      },
      {
        stanceId = STANCE_INVESTIGATE_DANGER,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 0.51,
        heightPivot = 0,
        size = {
          x = 0.5,
          y = 0.5,
          z = 0.18
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 0.5
        },
        name = "danger",
        useCapsule = 0
      },
      {
        stanceId = STANCE_INVESTIGATE_VISION,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 0.51,
        heightPivot = 0,
        size = {
          x = 0.5,
          y = 0.5,
          z = 0.18
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 0.5
        },
        name = "vision",
        useCapsule = 0
      },
      {
        stanceId = STANCE_HUNT,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 0.51,
        heightPivot = 0,
        size = {
          x = 0.5,
          y = 0.5,
          z = 0.18
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 0.5
        },
        name = "hunt",
        useCapsule = 0
      },
      {
        stanceId = STANCE_ZEROG,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 0.51,
        heightPivot = 0,
        size = {
          x = 0.5,
          y = 0.5,
          z = 0.18
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 0.5
        },
        name = "zerog",
        useCapsule = 0
      },
      {
        stanceId = STANCE_RELAXED,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 0.51,
        heightPivot = 0,
        size = {
          x = 0.5,
          y = 0.5,
          z = 0.18
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 0.5
        },
        name = "relaxed",
        useCapsule = 0
      }
    }
  },
  Properties = {
    fileAiTree = "Ark/AI/AiTrees/MimicAiTree.xml",
    fileAccumulatorConfig = "",
    TagList = "",
    soclasses_SmartObjectClass = "Human, Actor",
    esNavigationType = "ArkAlien_Small",
    fileHitDeathReactionsParamsDataFile = "Libs/HitDeathReactionsData/ArkHitDeathReactions_Mimic.xml",
    fStatusBarVerticalOffset = 0.4,
    bSupportsSmallAdditives = false,
    Damage = {
      fileBodyDamage = "Libs/BodyDamage/BodyDamage_Default.xml",
      fileBodyDamageParts = "Libs/BodyDamage/BodyParts_Default.xml",
      fileBodyDestructibility = "Libs/BodyDamage/BodyDestructibility_Default.xml",
      CanFall = 0,
      FallSleepTime = 1,
      heatAbsobsion = 0.5,
      heatDissipation = 200,
      minHeatDamage = 100
    },
    Perception = {
      minAlarmLevel = 0,
      cloakMaxDistCrouchedAndMoving = 1.5,
      cloakMaxDistCrouchedAndStill = 1.3,
      cloakMaxDistMoving = 3,
      cloakMaxDistStill = 2,
      config = "Human",
      FOVPrimary = 360,
      FOVSecondary = 180
    },
    useSpecialMovementTransitions = 0,
    bOverrideAllowLookAimStrafing = 1,
    fileModel = "Objects/characters/Aliens/Mimic/Mimic.cdf",
    bUseFacialFrameRateLimiting = 1,
    AIBehaviorFlags = {bSniper = 0, bGrenadier = 0},
    AI = {
      bUseRadioChatter = 0,
      bPlayDeathSound = 0,
      sndDeathSound = ""
    },
    AttentionFacing = {bUsesAttentionLook = 0, bUsesAttentionFacing = 0},
    PlayerInteractions = {
      bStealthKill = 0,
      bCanBeGrabbed = 0,
      esGrabType = ""
    },
    CharacterSounds = {
      footstepEffect = "footstep_mimic",
      remoteFootstepEffect = "footstep_mimic",
      footstepIndGearAudioSignal_Walk = "",
      footstepIndGearAudioSignal_Run = "",
      bFootstepGearEffect = 0,
      foleyEffect = "",
      bodyFallEffect = ""
    },
    Mimicry = {
      fCooldown = 3,
      fDefaultImpulseMass = 80,
      fImpulseMultiplier = 2.5,
      fMimicryImpulsePointXyRatio = 0.85,
      fMimicryImpulsePointZRatio = 0.75,
      fMimicEntityMimicModelMorphOutTime = 0.75,
      fMimicEntityObjectModelMorphInTime = 1,
      fUnmimicEntityMimicModelMorphInTime = 1,
      fUnmimicEntityObjectModelMorphOutTime = 0.75,
      signalmodifier_mimickedSignalModifierId = "3149325216939733383",
      particleeffect_MimicryMorphIn = "",
      mimicryMorphInSlot = 0,
      particleeffect_MimicryMorphOut = "",
      mimicryMorphOutSlot = 0,
      particleeffect_MimicryMorphOutBamf = "",
      mimicryMorphOutBamfBoneName = "",
      audioTrigger_StartTicking = "",
      audioTrigger_StopTicking = "",
      audioTrigger_Unmorph = ""
    },
    MimicReorient = {
      particleeffect_MimicReorient = "Characters.Aliens.Mimic.Body.BodyGlitch01",
      fGlitchRandTimeMin = 2,
      fGlitchRandTimeMax = 5,
      fMaxTurnDegrees = 20
    },
    MimicJumpAttack = {
      signalpackage_SignalPackageId = "3149325216914175803",
      particleeffect_onHitEffect = "Characters.Aliens.Mimic.AttackBase_01"
    },
    MeleeAttack = {
      fShortMaxDistance = 6,
      fMediumMaxDistance = 6,
      fLongMaxDistance = 6,
      fMaxForwardAngle = 30,
      fMinSideAngle = 30,
      fMaxSideAngle = 135
    },
    OnStunned = {attachmenteffects_OnStunEffects = ""},
    OnPsychoShocked = {attachmenteffects_OnPsychoShockedEffects = ""},
    OnDeath = {
      signalpackage_FearAOESignal = "",
      fFearScale = 1,
      fFearRadius = 10,
      particleeffect_FearAOEParticle = ""
    },
    ArkCharacter = {character_Character = ""},
    ArkDialog = {
      fPlayerApproachDistanceNear = 20,
      fPlayerApproachDistanceMedium = 20,
      fPlayerApproachDistanceFar = 20,
      fPlayerApproachCDNear = 30,
      fPlayerApproachCDMedium = 30,
      fPlayerApproachCDFar = 30,
      fPlayerLoiterDistance = 10,
      fPlayerLoiterCD = 5
    },
    faction_ArkFaction = "0",
    ArkMoveInfo = {
      moveMultiDir = true,
      moveHover = false,
      obstacleImpulseMin = 0.2,
      obstacleImpulseMax = 5,
      obstacleAdjustMassMin = 2,
      obstacleAdjustMassMax = 300,
      obstacleRadius = 0.6,
      obstacleFalloff = 1,
      pushLeverageMax = 1,
      footstepMinTime = 0
    },
    Stun = {
      bStunLastsForever = false,
      bRagdollStun = false,
      ragdollRootJointName = "",
      signalModifier_stunnedSignalModifierId = ""
    },
    OnPsiSuppressed = {attachmenteffects_OnPsiSuppressed = ""},
    Unconscious = {
      unconsciousDisplayText = "@ui_unconscious"
    }
  },
  AIMovementAbility = {
    allowEntityClampingByAnimation = 0,
    usePredictiveFollowing = 1,
    pathLookAhead = 1,
    walkSpeed = 2.4,
    runSpeed = 8.5,
    sprintSpeed = 12.5,
    maneuverSpeed = 8.5,
    b3DMove = 0,
    minTurnRadius = 0,
    maxTurnRadius = 3,
    pathSpeedLookAheadPerSpeed = -1.5,
    cornerSlowDown = 0.75,
    pathType = "AIPATH_MIMIC",
    pathRadius = 0.5,
    passRadius = 0.6,
    separationRadius = 0.35,
    distanceToCover = 0.5,
    inCoverRadius = 0.075,
    effectiveCoverHeight = 0.55,
    effectiveHighCoverHeight = 1.75,
    pathFindPrediction = 0.5,
    maxAccel = 23,
    maxDecel = 25,
    velDecay = 0.5,
    maneuverTrh = 2,
    resolveStickingInTrace = 1,
    pathRegenIntervalDuringTrace = -1,
    lightAffectsSpeed = 1,
    avoidanceAbilities = AVOIDANCE_ALL,
    pushableObstacleWeakAvoidance = true,
    obstacleAvoidanceMaxPathDeviation = 5,
    ignoreMinimumMassObstaclesAtHighUrgency = 0,
    ignoreMinimumMassObstaclesAtLowUrgency = 0,
    pushableObstacleAvoidanceRadiusMin = 0.5,
    pushableObstacleAvoidanceRadiusMax = 0.75,
    avoidanceRadius = 2,
    collisionAvoidanceRadiusIncrement = 0.01,
    pushableObstacleMassMin = 10,
    pushableObstacleMassMax = 100,
    pushableObstacleHeightMin = 0.25,
    pushableObstacleHeightMax = 1,
    lookIdleTurnSpeed = 30,
    lookCombatTurnSpeed = 50,
    aimTurnSpeed = -1,
    fireTurnSpeed = -1,
    directionalScaleRefSpeedMin = 2,
    directionalScaleRefSpeedMax = 5,
    directionalScaleTurn = 0.2,
    directionalScaleStrafe = 0,
    directionalScaleSlope = 0.083333,
    harshStopSpeed = 0,
    harshStopMinAngle = 0,
    harshStopMaxAngle = 0,
    AIMovementSpeeds = {
      Relaxed = {
        Slow = {
          1,
          0,
          1
        },
        Walk = {
          2.4,
          0,
          2.4
        },
        Run = {
          8.5,
          0,
          8.5
        },
        Sprint = {
          12.5,
          0,
          12.5
        }
      },
      Alerted = {
        Slow = {
          1,
          0,
          1
        },
        Walk = {
          2.4,
          0,
          2.4
        },
        Run = {
          8.5,
          0,
          8.5
        },
        Sprint = {
          12.5,
          0,
          12.5
        }
      },
      Combat = {
        Slow = {
          1,
          0,
          1
        },
        Walk = {
          2.4,
          0,
          2.4
        },
        Run = {
          8.4,
          0,
          8.4
        },
        Sprint = {
          12.5,
          0,
          12.5
        }
      }
    }
  },
  PropertiesInstance = {bStartDead = false, bAutoDisable = 1},
  SearchModule = {sightRange = 12},
  aiSequenceUser = true,
  bIsDeathGoo = false,
  bIsMimicking = false
}
mergef(ArkMimic_x, AIBase, 1)
function ArkMimic_x.DoBloodPool(A0_1912)
  local L1_1913
  return
end
function ArkMimic_x.OnLureSignal(A0_1914, A1_1915, A2_1916, A3_1917)
  A0_1914.arknpc:OnLured(A1_1915)
end
