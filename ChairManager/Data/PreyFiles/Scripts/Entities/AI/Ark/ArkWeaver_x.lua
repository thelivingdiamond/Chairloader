Script.ReloadScript("SCRIPTS/Entities/AI/Shared/AIBase.lua")
ArkWeaver_x = {
  ActionController = "Animations/Mannequin/ADB/Ai_Weaver_ControllerDefs.xml",
  AnimDatabase3P = "Animations/Mannequin/ADB/Ai_Weaver_Database.adb",
  UseMannequinAGState = true,
  UseLegacyCoverLocator = false,
  physicsParams = {
    Living = {
      gravity = 9.81,
      mass = 150,
      air_resistance = 0,
      k_air_control = 0,
      inertia = 2,
      inertiaAccel = 2,
      timeImpulseRecover = 1.5,
      height = 1.4,
      size = {
        x = 0.75,
        y = 0.75,
        z = 0.2
      },
      use_capsule = 1
    }
  },
  gameParams = {
    boneIDs = {
      BONE_BIP01 = "root_jnt",
      BONE_SPINE = "cog_jnt",
      BONE_SPINE2 = "",
      BONE_SPINE3 = "",
      BONE_HEAD = "cog_jnt",
      BONE_WEAPON = "",
      BONE_WEAPON2 = "",
      BONE_FOOT_R = "",
      BONE_FOOT_L = "",
      BONE_ARM_R = "",
      BONE_ARM_L = "",
      BONE_CALF_R = "",
      BONE_CALF_L = "",
      BONE_CAMERA = "look_jnt"
    },
    meeleHitRagdollImpulseScale = 1,
    lookFOV = 180,
    lookInVehicleFOV = 110,
    aimFOV = 160,
    maxLookAimAngle = 90,
    aimIKFadeDuration = 0.5,
    aimIKLayer = 14,
    lookIKLayer = 15,
    proceduralLeaningFactor = 0,
    canUseComplexLookIK = true,
    lookAtSimpleHeadBone = "",
    cornerSmoother = 3,
    stepThresholdTime = 0.5,
    stepThresholdDistance = 0.1,
    turnThresholdTime = 0.2,
    turnThresholdAngle = 2,
    minimumAngleForTurnWithoutDelay = 2,
    maxDeltaAngleRateNormal = 45,
    maxDeltaAngleRateFast = 60,
    maxDeltaAngleRateFastest = 75,
    nearbyRange = 10,
    middleRange = 30,
    defaultStance = 12,
    stance = {
      {
        stanceId = STANCE_STAND,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 1.4,
        heightPivot = 0,
        size = {
          x = 0.75,
          y = 0.75,
          z = 0.2
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        weaponOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        name = "stand",
        useCapsule = 1
      },
      {
        stanceId = STANCE_ALERTED,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 1.4,
        heightPivot = 0,
        size = {
          x = 0.74,
          y = 0.74,
          z = 0.2
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        weaponOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        name = "alerted",
        useCapsule = 1
      },
      {
        stanceId = STANCE_CRAWL,
        normalSpeed = 0.5,
        maxSpeed = 50,
        heightCollider = 0.9,
        heightPivot = 0,
        size = {
          x = 0.6,
          y = 0.6,
          z = 0.1
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        weaponOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        name = "crouch",
        useCapsule = 1
      },
      {
        stanceId = STANCE_ZEROG,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 1.4,
        heightPivot = 0,
        size = {
          x = 0.74,
          y = 0.74,
          z = 0.2
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        weaponOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        name = "zerog",
        useCapsule = 1
      },
      {
        stanceId = STANCE_HOVER,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 1.4,
        heightPivot = 0,
        size = {
          x = 0.74,
          y = 0.74,
          z = 0.2
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        weaponOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        name = "hover",
        useCapsule = 1
      },
      {
        stanceId = STANCE_RELAXED,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 1.4,
        heightPivot = 0,
        size = {
          x = 0.74,
          y = 0.74,
          z = 0.2
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        weaponOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        name = "relaxed",
        useCapsule = 1
      }
    }
  },
  Properties = {
    fileAiTree = "Ark/AI/AiTrees/TelepathAiTree.xml",
    fileAccumulatorConfig = "",
    TagList = "",
    soclasses_SmartObjectClass = "Human, Actor",
    esNavigationType = "ArkWeaver",
    bCanFall = false,
    TelepathMindBlast = {
      signalpackage_SignalPackageId = "3149325216914175803"
    },
    Damage = {
      fileBodyDamage = "Libs/BodyDamage/BodyDamage_Default.xml",
      fileBodyDamageParts = "Libs/BodyDamage/BodyParts_Default.xml",
      fileBodyDestructibility = "Libs/BodyDamage/BodyDestructibility_Default.xml",
      CanFall = 0,
      FallSleepTime = 1,
      heatAbsobsion = 0.5,
      heatDissipation = 200,
      minHeatDamage = 100,
      arkWeaponImpulseScale = 300,
      arkWeaponImpulseApplyTimeImpulseMin = 300,
      arkWeaponImpulseApplyTimeImpulseMax = 1500,
      arkWeaponImpulseApplyTimeMin = 0.1,
      arkWeaponImpulseApplyTimeMax = 0.25
    },
    Perception = {
      minAlarmLevel = 0,
      cloakMaxDistCrouchedAndMoving = 1.5,
      cloakMaxDistCrouchedAndStill = 1.3,
      cloakMaxDistMoving = 3,
      cloakMaxDistStill = 2,
      config = "Human",
      FOVPrimary = 120,
      FOVSecondary = 120
    },
    AttentionFacing = {bUsesAttentionLook = 0, bUsesAttentionFacing = 0},
    EMPBlast = {
      particleeffect_Cast = "Characters.Aliens.Phantom.Thermal.Thermogenesis.Cast_01",
      effectAttachmentName = "Rope_bellyLowerA01"
    },
    OnFire = {
      particleeffect_OnFireEffect = "Characters.Aliens.Phantom.Thermal.FlamingMimic.BurnLoop_01",
      effectAttachmentName = "attach_fx_chest",
      fFearDuration = 5,
      signalpackage_fireDoTSignalPackageId = "9469288860495533935",
      fDotTickRate = 1,
      fDotDuration = 10,
      bFleesWhenLitOnFire = 0
    },
    OnStunned = {attachmenteffects_OnStunEffects = ""},
    OnDeath = {
      signalpackage_FearAOESignal = "",
      fFearScale = 1,
      fFearRadius = 10,
      particleeffect_FearAOEParticle = ""
    },
    WeaverShield = {
      attachmenteffects_ShieldIn = "",
      attachmenteffects_ShieldDissolve = "",
      attachmenteffects_ShieldBurst = ""
    },
    MaterialAnimations = {
      materialanimations_WeaverShieldIn = "0",
      materialanimations_WeaverShieldDissolve = "0",
      materialanimations_WeaverShieldBurst = "0"
    },
    RaisePhantom = {attachmenteffects_raisePhantomFromCorpseCast = "", maxAllowedRaisedPhantoms = 1},
    OnPsychoShocked = {attachmenteffects_OnPsychoShockedEffects = ""},
    useSpecialMovementTransitions = 0,
    bOverrideAllowLookAimStrafing = 1,
    fileModel = "Objects/characters/Aliens/Telepath/Telepath.cdf",
    bUseFacialFrameRateLimiting = 1,
    AIBehaviorFlags = {bSniper = 0, bGrenadier = 0},
    AI = {
      bUseRadioChatter = 0,
      bPlayDeathSound = 0,
      sndDeathSound = ""
    },
    PlayerInteractions = {
      bStealthKill = 0,
      bCanBeGrabbed = 0,
      esGrabType = ""
    },
    CharacterSounds = {
      footstepEffect = "footstep_grunt",
      remoteFootstepEffect = "footstep_grunt",
      footstepIndGearAudioSignal_Walk = "",
      footstepIndGearAudioSignal_Run = "",
      bFootstepGearEffect = 0,
      foleyEffect = "foley_player",
      bodyFallEffect = ""
    },
    ArkEffects = {},
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
      doorCrouch = true,
      moveHover = true,
      hoverRoll = 0.25,
      hoverPitchSpeedMult = 0.4,
      hoverPitchIdleMaxDegrees = 60,
      hoverPitchMoveMaxDegrees = 35,
      hoverBob = true,
      hoverBobTimeMin = 2.8,
      hoverBobTimeMax = 3.3,
      hoverBobSpeedMin = 0.09,
      hoverBobSpeedMax = 0.12,
      hoverBobAccelStartMult = 0.5,
      hoverBobDecelEndMult = 0.6,
      hoverBobAdjustFastHeightDelta = 0.5,
      hoverBobAdjustFastSpeed = 0.5,
      hoverPivotHeight = 2.5,
      hoverClearanceHeight = 0.9,
      hoverClearanceLedge = 1.6,
      hoverPsiLiftSpeedMult = 1,
      hoverZeroGIgnoreObstacles = true,
      pushLeverageMax = 2,
      matchTargetHeightDistance = 10
    },
    Stun = {
      bStunLastsForever = false,
      bRagdollStun = true,
      ragdollRootJointName = "cog_jnt",
      signalModifier_stunnedSignalModifierId = ""
    },
    OnPsiSuppressed = {attachmenteffects_OnPsiSuppressed = ""}
  },
  AIMovementAbility = {
    allowEntityClampingByAnimation = 0,
    usePredictiveFollowing = 1,
    pathLookAhead = 3,
    walkSpeed = 2,
    runSpeed = 5,
    sprintSpeed = 10,
    maneuverSpeed = 2,
    b3DMove = 1,
    minTurnRadius = 0,
    maxTurnRadius = 3,
    pathSpeedLookAheadPerSpeed = -1.5,
    optimalFlightHeight = 0.65,
    minFlightHeight = 0.4,
    maxFlightHeight = 50,
    cornerSlowDown = 0.75,
    pathType = "AIPATH_OVERSEER",
    pathRadius = 1,
    passRadius = 1.3,
    separationRadius = 0.95,
    distanceToCover = 0.5,
    inCoverRadius = 0.075,
    effectiveCoverHeight = 0.55,
    effectiveHighCoverHeight = 1.75,
    pathFindPrediction = 1.5,
    maxAccel = 5,
    maxDecel = 5,
    velDecay = 0.5,
    maneuverTrh = 2,
    resolveStickingInTrace = 1,
    pathRegenIntervalDuringTrace = -1,
    lightAffectsSpeed = 1,
    avoidanceAbilities = AVOIDANCE_ALL,
    pushableObstacleWeakAvoidance = true,
    pushableObstacleAvoidanceRadiusMin = 0.8,
    pushableObstacleAvoidanceRadiusMax = 0.8,
    pushableObstacleMassMin = 0,
    pushableObstacleMassMax = 80,
    pushableObstacleHeightMin = 0.7,
    pushableObstacleHeightMax = 1.5,
    lookIdleTurnSpeed = 10,
    lookCombatTurnSpeed = 10,
    aimTurnSpeed = -1,
    fireTurnSpeed = -1,
    directionalScaleRefSpeedMin = 3,
    directionalScaleRefSpeedMax = 5,
    directionalScaleTurn = 0.7,
    directionalScaleStrafe = 0.8,
    directionalScaleSlope = 0,
    harshStopSpeed = 3,
    harshStopMinAngle = 120,
    harshStopMaxAngle = 180,
    AIMovementSpeeds = {
      Relaxed = {
        Slow = {
          1,
          1,
          1
        },
        Walk = {
          3,
          3,
          3
        },
        Run = {
          5,
          5,
          5
        },
        Sprint = {
          100,
          100,
          100
        }
      },
      Alerted = {
        Slow = {
          1,
          1,
          1
        },
        Walk = {
          3,
          3,
          3
        },
        Run = {
          5,
          5,
          5
        },
        Sprint = {
          100,
          100,
          100
        }
      },
      Combat = {
        Slow = {
          1,
          1,
          1
        },
        Walk = {
          3,
          3,
          3
        },
        Run = {
          5,
          5,
          5
        },
        Sprint = {
          100,
          100,
          100
        }
      }
    }
  },
  melee = {
    damage = 400,
    damageOffset = {
      x = 0,
      y = 2,
      z = 0
    },
    damageRadius = 1.8,
    damageRadiusShort = 1.5,
    hitRange = 1.8,
    knockdownChance = 0.1,
    impulse = 600,
    angleThreshold = 180
  },
  PropertiesInstance = {
    bStartDead = false,
    bAutoDisable = 1,
    ArkDialog = {jobName = ""}
  },
  SearchModule = {sightRange = 12},
  aiSequenceUser = true,
  bIsDeathGoo = false
}
mergef(ArkWeaver_x, AIBase, 1)
function ArkWeaver_x.IsInvulnerable(A0_2027)
  local L1_2028
  L1_2028 = A0_2027.PropertiesInstance
  L1_2028 = L1_2028.bIsInvulnerable
  L1_2028 = L1_2028 == true
  return L1_2028
end
function ArkWeaver_x.OnLureSignal(A0_2029, A1_2030, A2_2031, A3_2032)
  A0_2029.arknpc:OnLured(A1_2030)
end
function ArkWeaver_x.Server.OnStartGame(A0_2033)
  if not A0_2033.arknpc:IsDead() then
    A0_2033.arknpc:AttachGameEffect(1)
  end
end
function ArkWeaver_x.OnNpcKilled(A0_2034)
  A0_2034.arknpc:DetachGameEffect(1)
  A0_2034:SetupInventoryOnDeath()
end
