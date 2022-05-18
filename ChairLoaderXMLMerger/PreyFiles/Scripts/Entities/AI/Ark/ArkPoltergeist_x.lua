Script.ReloadScript("SCRIPTS/Entities/AI/Shared/AIBase.lua")
ArkPoltergeist_x = {
  ActionController = "Animations/Mannequin/ADB/Ai_Poltergeist_ControllerDefs.xml",
  AnimDatabase3P = "Animations/Mannequin/ADB/Ai_Poltergeist_Database.adb",
  UseMannequinAGState = true,
  UseLegacyCoverLocator = false,
  physicsParams = {
    Living = {
      gravity = 9.81,
      mass = 130,
      air_resistance = 0,
      k_air_control = 0,
      inertia = 2,
      inertiaAccel = 2,
      timeImpulseRecover = 1.5,
      height = 0.8,
      size = {
        x = 0.5,
        y = 0.5,
        z = 0.4
      },
      use_capsule = 0
    }
  },
  gameParams = {
    boneIDs = {
      BONE_BIP01 = "root_jnt",
      BONE_SPINE = "spine1_jnt",
      BONE_SPINE2 = "spine2_jnt",
      BONE_SPINE3 = "spine3_jnt",
      BONE_HEAD = "head_jnt",
      BONE_WEAPON = "r_handProp_jnt",
      BONE_WEAPON2 = "l_handProp_jnt",
      BONE_FOOT_R = "Rope_r_legRope Seg07",
      BONE_FOOT_L = "Rope_l_legRope Seg07",
      BONE_ARM_R = "r_upperArm_jnt",
      BONE_ARM_L = "l_upperArm_jnt",
      BONE_CALF_R = "Rope_r_legRope Seg01",
      BONE_CALF_L = "Rope_l_legRope Seg01",
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
    turnThresholdTime = 0.5,
    turnThresholdAngle = 5,
    maxDeltaAngleRateNormal = 90,
    maxDeltaAngleRateFast = 105,
    maxDeltaAngleRateFastest = 120,
    nearbyRange = 10,
    middleRange = 30,
    defaultStance = 11,
    stance = {
      {
        stanceId = STANCE_STAND,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 0.8,
        heightPivot = 0,
        size = {
          x = 0.5,
          y = 0.5,
          z = 0.4
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 1
        },
        name = "stand",
        useCapsule = 0
      },
      {
        stanceId = STANCE_ALERTED,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 0.8,
        heightPivot = 0,
        size = {
          x = 0.5,
          y = 0.5,
          z = 0.4
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 1
        },
        name = "alerted",
        useCapsule = 0
      },
      {
        stanceId = STANCE_INVESTIGATE_ANOMALY,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 0.8,
        heightPivot = 0,
        size = {
          x = 0.5,
          y = 0.5,
          z = 0.4
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 1
        },
        name = "anomaly",
        useCapsule = 0
      },
      {
        stanceId = STANCE_INVESTIGATE_DANGER,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 0.8,
        heightPivot = 0,
        size = {
          x = 0.5,
          y = 0.5,
          z = 0.4
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 1
        },
        name = "danger",
        useCapsule = 0
      },
      {
        stanceId = STANCE_INVESTIGATE_VISION,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 0.8,
        heightPivot = 0,
        size = {
          x = 0.5,
          y = 0.5,
          z = 0.4
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 1
        },
        name = "vision",
        useCapsule = 0
      },
      {
        stanceId = STANCE_HUNT,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 0.8,
        heightPivot = 0,
        size = {
          x = 0.5,
          y = 0.5,
          z = 0.4
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 1
        },
        name = "hunt",
        useCapsule = 0
      },
      {
        stanceId = STANCE_ZEROG,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 0.8,
        heightPivot = 0,
        size = {
          x = 0.5,
          y = 0.5,
          z = 0.4
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 1
        },
        name = "zerog",
        useCapsule = 0
      },
      {
        stanceId = STANCE_RELAXED,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 0.8,
        heightPivot = 0,
        size = {
          x = 0.5,
          y = 0.5,
          z = 0.4
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 1
        },
        name = "relaxed",
        useCapsule = 0
      }
    }
  },
  Properties = {
    fileAiTree = "Ark/AI/AiTrees/PoltergeistAiTree.xml",
    fileAccumulatorConfig = "",
    roomPerceptionModel_RoomPerceptionModel = "1",
    TagList = "",
    soclasses_SmartObjectClass = "Human, Actor",
    esNavigationType = "MediumSizedCharacters",
    fileHitDeathReactionsParamsDataFile = "Libs/HitDeathReactionsData/ArkHitDeathReactions_Poltergeist.xml",
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
      minHeatDamage = 100
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
    OnStunned = {attachmenteffects_OnStunEffects = ""},
    OnDeath = {
      signalpackage_FearAOESignal = "",
      fFearScale = 1,
      fFearRadius = 10,
      particleeffect_FearAOEParticle = ""
    },
    OnPsychoShocked = {attachmenteffects_OnPsychoShockedEffects = ""},
    useSpecialMovementTransitions = 0,
    bOverrideAllowLookAimStrafing = 1,
    fileModel = "objects/characters/aliens/poltergeist/poltergeist.cdf",
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
    ArkUnreachableTargeting = {
      startingTraceRadius = 0.5,
      startingMinSearchRadius = 4,
      chanceToSearchInReverseOrder = 0.2,
      horizontalOffsetStanding = 0.35,
      standardCombatHeight = 0.8
    },
    ArkCorpseInfo = {
      deadModel = "Objects/characters/Aliens/AlienGuts/AlienGuts_Phantom.cdf",
      fCorpseMass = 15,
      fCorpseStiffness = 73,
      fTimeTilMorphStart = 0.5,
      fMorphInTime = 1,
      fMorphOutTime = 2,
      fTimeTilDeathGutsRagdoll = 0.7
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
    MaterialAnimations = {
      materialanimations_PoltergeistAppear = "12635110349637740383",
      materialanimations_PoltergeistDisappear = "12635110349637740724",
      materialanimations_PoltergeistPsychoscopeOn = "12635110349638353850",
      materialanimations_PoltergeistPsychoscopeOff = "12635110349638420382"
    },
    PoltergeistEffects = {
      attachmenteffects_PsychoscopeBlurEffect = "243995946806214050",
      attachmenteffects_AppearEffect = "243995946806213845",
      attachmenteffects_DisappearEffect = "243995946806213895",
      attachmenteffects_CastEffect = "243995946806304698",
      attachmenteffects_GlitchEffect = "",
      gameeffect_InvisibilityGameEffect = "3"
    },
    faction_ArkFaction = "0",
    ArkMoveInfo = {pushLeverageMax = 2},
    disappearAfterDamageTime = 2,
    OnPsiSuppressed = {attachmenteffects_OnPsiSuppressed = ""},
    Sound = {
      PoltergeistEffects = {
        audioTrigger_ThrowLift = "",
        audioTrigger_ThrowImpulse = "Play_Poltergeist_Throw"
      }
    }
  },
  AIMovementAbility = {
    allowEntityClampingByAnimation = 0,
    usePredictiveFollowing = 1,
    pathLookAhead = 1,
    walkSpeed = 1,
    runSpeed = 3,
    sprintSpeed = 3,
    maneuverSpeed = 1,
    b3DMove = 1,
    minTurnRadius = 0,
    maxTurnRadius = 3,
    pathSpeedLookAheadPerSpeed = -1.5,
    optimalFlightHeight = 1.75,
    minFlightHeight = 0.35,
    maxFlightHeight = 50,
    cornerSlowDown = 0.75,
    pathType = AIPATH_HUMAN,
    pathRadius = 0.5,
    passRadius = 0.5,
    separationRadius = 0.45,
    distanceToCover = 0.5,
    inCoverRadius = 0.075,
    effectiveCoverHeight = 0.55,
    effectiveHighCoverHeight = 1.75,
    pathFindPrediction = 0.5,
    maxAccel = 2,
    maxDecel = 4,
    velDecay = 0.5,
    maneuverTrh = 2,
    resolveStickingInTrace = 1,
    pathRegenIntervalDuringTrace = -1,
    lightAffectsSpeed = 1,
    avoidanceAbilities = AVOIDANCE_ALL,
    pushableObstacleWeakAvoidance = true,
    pushableObstacleAvoidanceRadiusMin = 0.4,
    pushableObstacleAvoidanceRadiusMax = 0.4,
    pushableObstacleMassMin = 0,
    pushableObstacleMassMax = 80,
    lookIdleTurnSpeed = 10,
    lookCombatTurnSpeed = 10,
    aimTurnSpeed = -1,
    fireTurnSpeed = -1,
    directionalScaleRefSpeedMin = 1,
    directionalScaleRefSpeedMax = 2,
    directionalScaleTurn = 0.6,
    directionalScaleStrafe = 0.6,
    directionalScaleSlope = 0.083333,
    harshStopSpeed = 0.75,
    harshStopMinAngle = 60,
    harshStopMaxAngle = 180,
    AIMovementSpeeds = {
      Relaxed = {
        Slow = {
          0.5,
          0.5,
          0.5
        },
        Walk = {
          1,
          1,
          1
        },
        Run = {
          2,
          2,
          2
        },
        Sprint = {
          2,
          2,
          2
        }
      },
      Alerted = {
        Slow = {
          0.5,
          0.5,
          0.5
        },
        Walk = {
          1,
          1,
          1
        },
        Run = {
          2,
          2,
          2
        },
        Sprint = {
          2,
          2,
          2
        }
      },
      Combat = {
        Slow = {
          0.5,
          0.5,
          0.5
        },
        Walk = {
          1,
          1,
          1
        },
        Run = {
          2,
          2,
          2
        },
        Sprint = {
          2,
          2,
          2
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
    damageDisappearTimerId = nil,
    ArkDialog = {jobName = ""}
  },
  SearchModule = {sightRange = 12},
  aiSequenceUser = true,
  bIsDeathGoo = false
}
mergef(ArkPoltergeist_x, AIBase, 1)
function ArkPoltergeist_x.IsInvulnerable(A0_1983)
  local L1_1984
  L1_1984 = A0_1983.PropertiesInstance
  L1_1984 = L1_1984.bIsInvulnerable
  L1_1984 = L1_1984 == true
  return L1_1984
end
function ArkPoltergeist_x.Server.OnStartGame(A0_1985)
  if not A0_1985.arknpc:IsDead() then
    A0_1985.arknpc:AttachGameEffect(2)
    A0_1985.arknpc:AttachGameEffect(3)
  end
end
function ArkPoltergeist_x.OnNpcKilled(A0_1986)
  A0_1986.arknpc:DetachGameEffect(2)
  A0_1986.arknpc:DetachGameEffect(3)
  A0_1986:SetupInventoryOnDeath()
end
function ArkPoltergeist_x.OnLureSignal(A0_1987, A1_1988, A2_1989, A3_1990)
  A0_1987.arknpc:OnLured(A1_1988)
end
