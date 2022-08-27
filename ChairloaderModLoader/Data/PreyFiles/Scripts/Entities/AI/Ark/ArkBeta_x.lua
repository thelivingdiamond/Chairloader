Script.ReloadScript("SCRIPTS/Entities/AI/Shared/AIBase.lua")
ArkBeta_x = {
  ActionController = "Animations/Mannequin/ADB/Ai_Phantom_ControllerDefs.xml",
  AnimDatabase3P = "Animations/Mannequin/ADB/Ai_Phantom_Database.adb",
  UseMannequinAGState = true,
  UseLegacyCoverLocator = false,
  physicsParams = {
    Living = {
      mass = 160,
      air_resistance = 0,
      height = 1.275,
      size = {
        x = 0.6,
        y = 0.6,
        z = 0.475
      },
      use_capsule = 1
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
      BONE_FOOT_R = "r_foot_jnt",
      BONE_FOOT_L = "l_foot_jnt",
      BONE_ARM_R = "r_upperArm_jnt",
      BONE_ARM_L = "l_upperArm_jnt",
      BONE_CALF_R = "r_lowerLeg_jnt",
      BONE_CALF_L = "l_lowerLeg_jnt",
      BONE_CAMERA = "look_jnt"
    },
    meeleHitRagdollImpulseScale = 1,
    lookFOV = 180,
    lookInVehicleFOV = 110,
    aimFOV = 160,
    maxLookAimAngle = 90,
    aimIKFadeDuration = 0.5,
    aimIKLayer = 13,
    lookIKLayer = 14,
    proceduralLeaningFactor = 0,
    canUseComplexLookIK = true,
    lookAtSimpleHeadBone = "head_jnt",
    cornerSmoother = 2,
    stepThresholdTime = 0.5,
    stepThresholdDistance = 0.1,
    turnThresholdTime = 1,
    turnThresholdAngle = 5,
    maxDeltaAngleRateNormal = 105,
    maxDeltaAngleRateFast = 120,
    maxDeltaAngleRateFastest = 135,
    slopeUpSlowdownMult = 0.15,
    slopeDownSlowdownMult = 0,
    nearbyRange = 10,
    middleRange = 30,
    defaultStance = STANCE_RELAXED,
    stance = {
      {
        stanceId = STANCE_STAND,
        normalSpeed = 1,
        maxSpeed = 50,
        heightPivot = 0,
        CollisionHeight = 2.35,
        CollisionDiameter = 1.2,
        CapsuleOffset = 0.2,
        modelOffset = {
          x = -1,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 0.5
        },
        name = "stand",
        useCapsule = 1
      },
      {
        stanceId = STANCE_ALERTED,
        normalSpeed = 1,
        maxSpeed = 50,
        heightPivot = 0,
        CollisionHeight = 2.35,
        CollisionDiameter = 1.2,
        CapsuleOffset = 0.2,
        modelOffset = {
          x = -1,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 0.5
        },
        name = "alerted",
        useCapsule = 1
      },
      {
        stanceId = STANCE_INVESTIGATE_ANOMALY,
        normalSpeed = 1,
        maxSpeed = 50,
        heightPivot = 0,
        CollisionHeight = 2.35,
        CollisionDiameter = 1.2,
        CapsuleOffset = 0.2,
        modelOffset = {
          x = -1,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 0.5
        },
        name = "anomaly",
        useCapsule = 1
      },
      {
        stanceId = STANCE_INVESTIGATE_DANGER,
        normalSpeed = 1,
        maxSpeed = 50,
        heightPivot = 0,
        CollisionHeight = 2.35,
        CollisionDiameter = 1.2,
        CapsuleOffset = 0.2,
        modelOffset = {
          x = -1,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 0.5
        },
        name = "danger",
        useCapsule = 1
      },
      {
        stanceId = STANCE_INVESTIGATE_VISION,
        normalSpeed = 1,
        maxSpeed = 50,
        heightPivot = 0,
        CollisionHeight = 2.35,
        CollisionDiameter = 1.2,
        CapsuleOffset = 0.2,
        modelOffset = {
          x = -1,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 0.5
        },
        name = "vision",
        useCapsule = 1
      },
      {
        stanceId = STANCE_HUNT,
        normalSpeed = 1,
        maxSpeed = 50,
        heightPivot = 0,
        CollisionHeight = 2.35,
        CollisionDiameter = 1.2,
        CapsuleOffset = 0.2,
        modelOffset = {
          x = -1,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 0.5
        },
        name = "hunt",
        useCapsule = 1
      },
      {
        stanceId = STANCE_ZEROG,
        normalSpeed = 1,
        maxSpeed = 50,
        heightPivot = 0,
        CollisionHeight = 2.35,
        CollisionDiameter = 1.2,
        CapsuleOffset = 0.2,
        modelOffset = {
          x = -1,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 0.5
        },
        name = "zerog",
        useCapsule = 1
      },
      {
        stanceId = STANCE_RELAXED,
        normalSpeed = 1,
        maxSpeed = 50,
        heightPivot = 0,
        CollisionHeight = 2.35,
        CollisionDiameter = 1.2,
        CapsuleOffset = 0.2,
        modelOffset = {
          x = -1,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 0.5
        },
        name = "relaxed",
        useCapsule = 1
      }
    }
  },
  Properties = {
    fileAiTree = "Ark/AI/AiTrees/BetaAiTree.xml",
    fileAccumulatorConfig = "",
    esElitePhantomType = "BASE",
    loottables_HumanLootTable = "",
    AttentionFacing = {bUsesAttentionLook = 0, bUsesAttentionFacing = 1},
    PsiBlast = {
      nMaterialSlot = 0,
      nSubMaterialSlot = 0,
      sMaterialParamName = "",
      fMaterialParamMaxValue = 0,
      fMaterialParamRampInTime = 0,
      fMaterialParamRampOutTime = 0
    },
    PsiAttackEffects = {
      attachmenteffects_phantomAttackGlow = "14610450286760874655"
    },
    ArkPsiBlast = {
      attachmenteffects_CastEffect = "17591291352656540600"
    },
    Shift = {
      attachmenteffects_shiftTelegraph = "14610450286761482000",
      attachmenteffects_shiftMove = "",
      attachmenteffects_shiftOut = "",
      attachmenteffects_lurkShiftTelegraph = "",
      attachmenteffects_lurkShiftMove = "",
      attachmenteffects_lurkShiftOut = "",
      signalmodifier_shiftingSignalModifier = "",
      fShiftDistMin = 1.5,
      fShiftSpeed = 100,
      fShiftDeltaAngleRate = 1080,
      fTelegraphTime = 0.2
    },
    OnElectrocuted = {attachmenteffects_OnElectrocutedEffects = ""},
    OnStunned = {attachmenteffects_OnStunEffects = ""},
    OnDeath = {
      signalpackage_FearAOESignal = "",
      fFearScale = 1,
      fFearRadius = 10,
      particleeffect_FearAOEParticle = ""
    },
    OnPsychoShocked = {attachmenteffects_OnPsychoShockedEffects = ""},
    MeleeAttack = {
      fShortMaxDistance = 6,
      fMediumMaxDistance = 6,
      fLongMaxDistance = 6,
      fMaxForwardAngle = 30,
      fMinSideAngle = 30,
      fMaxSideAngle = 135
    },
    Thermogenesis = {attachmenteffects_ThermogenesisCast = ""},
    ThermalAura = {attachmentEffects_ThermalAuraCastWarmup = ""},
    TagList = "",
    soclasses_SmartObjectClass = "Human, Actor",
    esNavigationType = "ArkAlien_Medium",
    fileHitDeathReactionsParamsDataFile = "Libs/HitDeathReactionsData/ArkHitDeathReactions_Beta.xml",
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
    useSpecialMovementTransitions = 1,
    bOverrideAllowLookAimStrafing = 1,
    bSupportsLookAt = true,
    fileModel = "Objects/characters/Aliens/Phantom/Phantom.cdf",
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
      footstepEffect = "footstep_phantom",
      remoteFootstepEffect = "footstep_phantom",
      footstepIndGearAudioSignal_Walk = "",
      footstepIndGearAudioSignal_Run = "",
      bFootstepGearEffect = 0,
      foleyEffect = "foley_player",
      bodyFallEffect = ""
    },
    RaiseFromCorpse = {attachmenteffects_RaiseStartEffect = "", gameEffect_RaiseFromCorpse = "987"},
    ArkCharacter = {
      character_Character = "",
      voice_VoiceOverride = "13680621263400262208"
    },
    ArkDialog = {
      fPlayerApproachDistanceNear = 20,
      fPlayerApproachDistanceMedium = 20,
      fPlayerApproachDistanceFar = 20,
      fPlayerApproachCDNear = 30,
      fPlayerApproachCDMedium = 30,
      fPlayerApproachCDFar = 30,
      fPlayerLoiterDistance = 10,
      fPlayerLoiterCD = 5,
      fAttenuationScale = 0.7,
      bUseResearchNameForSubtitles = true
    },
    faction_ArkFaction = "0",
    ArkMoveInfo = {moveShift = true, pushLeverageMax = 2},
    MaterialAnimations = {materialanimations_PhantomRaisedFromCorpse = ""},
    Stun = {
      bStunLastsForever = false,
      bRagdollStun = false,
      ragdollRootJointName = "",
      signalModifier_stunnedSignalModifierId = ""
    },
    OnPsiSuppressed = {attachmenteffects_OnPsiSuppressed = ""},
    ArkUnreachableTargeting = {
      startingTraceRadius = 0.5,
      startingMinSearchRadius = 4,
      chanceToSearchInReverseOrder = 0.5,
      horizontalOffsetStanding = 0.73,
      standardCombatHeight = 1.62
    },
    Sound = {
      audioTrigger_AmbientLivingStart = "Play_Phantom_Exist_LP",
      audioTrigger_AmbientLivingStop = "Stop_Phantom_Exist_LP",
      ThermalAura = {
        audioTrigger_BurnLoop = "",
        audioTrigger_Explode = "",
        audioTrigger_Cooldown = ""
      }
    },
    Unconscious = {
      unconsciousDisplayText = "@ui_unconscious"
    }
  },
  AIMovementAbility = {
    allowEntityClampingByAnimation = 1,
    usePredictiveFollowing = 1,
    pathLookAhead = 1,
    walkSpeed = 1.9,
    runSpeed = 2.6,
    sprintSpeed = 2.6,
    maneuverSpeed = 1.9,
    b3DMove = 0,
    minTurnRadius = 0,
    maxTurnRadius = 3,
    pathSpeedLookAheadPerSpeed = -1.5,
    cornerSlowDown = 0.75,
    pathType = "AIPATH_PHANTOM",
    pathRadius = 0.625,
    passRadius = 0.8,
    separationRadius = 0.55,
    distanceToCover = 0.82,
    inCoverRadius = 0.075,
    effectiveCoverHeight = 0.55,
    effectiveHighCoverHeight = 1.75,
    pathFindPrediction = 1.2,
    maxAccel = 2.6,
    maxDecel = 1.3,
    velDecay = 0.5,
    maneuverTrh = 2,
    resolveStickingInTrace = 1,
    pathRegenIntervalDuringTrace = -1,
    lightAffectsSpeed = 1,
    avoidanceAbilities = AVOIDANCE_ALL,
    pushableObstacleWeakAvoidance = true,
    pushableObstacleAvoidanceRadiusMin = 0.5,
    pushableObstacleAvoidanceRadiusMax = 0.75,
    pushableObstacleMassMin = 10,
    pushableObstacleMassMax = 200,
    pushableObstacleHeightMin = 0.25,
    pushableObstacleHeightMax = 2.5,
    collisionAvoidanceRadiusIncrement = 0.02,
    lookIdleTurnSpeed = 30,
    lookCombatTurnSpeed = 50,
    aimTurnSpeed = -1,
    fireTurnSpeed = -1,
    directionalScaleRefSpeedMin = 1.3,
    directionalScaleRefSpeedMax = 2.6,
    directionalScaleTurn = 0.5,
    directionalScaleStrafe = 0.5,
    directionalScaleSlope = 0,
    harshStopSpeed = 1.3,
    harshStopMinAngle = 105,
    harshStopMaxAngle = 170,
    harshStopBelowDist = 1.3,
    AIMovementSpeeds = {
      Relaxed = {
        Slow = {
          1.3,
          0,
          1.3
        },
        Walk = {
          2,
          0,
          2
        },
        Run = {
          2,
          1.4,
          2
        },
        Sprint = {
          2.6,
          1.4,
          2.6
        }
      },
      Alerted = {
        Slow = {
          1.3,
          0,
          1.3
        },
        Walk = {
          2,
          0,
          2
        },
        Run = {
          2,
          1.4,
          2
        },
        Sprint = {
          2.6,
          1.4,
          2.6
        }
      },
      Combat = {
        Slow = {
          1.3,
          0,
          1.3
        },
        Walk = {
          2,
          0,
          2
        },
        Run = {
          2.6,
          1.4,
          2.6
        },
        Sprint = {
          2.6,
          1.4,
          2.6
        }
      }
    }
  },
  ProceduralContextAim = {
    polarCoordinatesSmoothTimeSeconds = 0.2,
    polarCoordinatesMaxYawDegreesPerSecond = 360,
    polarCoordinatesMaxPitchDegreesPerSecond = 360,
    fadeInSeconds = 0.25,
    fadeOutSeconds = 0.25,
    fadeOutMinDistance = 0,
    fadeOutAngleDegrees = 180,
    maxAngleDegreesXY = 75,
    maxAngleDegreesZ = 90
  },
  ProceduralContextLook = {
    polarCoordinatesSmoothTimeSeconds = 0.4,
    polarCoordinatesMaxYawDegreesPerSecond = 360,
    polarCoordinatesMaxPitchDegreesPerSecond = 360,
    fadeInSeconds = 0.4,
    fadeOutSeconds = 0.4,
    fadeOutMinDistance = 0,
    fadeOutAngleDegrees = 180,
    maxAngleDegreesXY = 60,
    maxAngleDegreesZ = 70,
    speedMultiplierFast = 0.85,
    speedMultiplierFastest = 0.7
  },
  ProceduralContextLookHead = {
    polarCoordinatesSmoothTimeSeconds = 0.2,
    polarCoordinatesMaxYawDegreesPerSecond = 360,
    polarCoordinatesMaxPitchDegreesPerSecond = 360,
    fadeInSeconds = 0.2,
    fadeOutSeconds = 0.2,
    fadeOutMinDistance = 0,
    fadeOutMaxDistance = 75,
    fadeOutAngleDegrees = 180,
    maxAngleDegreesXY = 37,
    maxAngleDegreesZ = 70,
    speedMultiplierFast = 0.85,
    speedMultiplierFastest = 0.7
  },
  PropertiesInstance = {bStartDead = false, bAutoDisable = 1},
  SearchModule = {sightRange = 12},
  aiSequenceUser = true,
  bIsDeathGoo = false
}
mergef(ArkBeta_x, AIBase, 1)
function ArkBeta_x.IsInvulnerable(A0_1873)
  local L1_1874
  L1_1874 = A0_1873.PropertiesInstance
  L1_1874 = L1_1874.bIsInvulnerable
  L1_1874 = L1_1874 == true
  return L1_1874
end
function ArkBeta_x.OnDeathCustom(A0_1875, A1_1876)
  if A0_1875.UpdateDisplayName then
    A0_1875:UpdateDisplayName()
  end
  ArkNpc.OnDeathCustom(A0_1875, A1_1876)
end
function ArkBeta_x.OnLureSignal(A0_1877, A1_1878, A2_1879, A3_1880)
  A0_1877.arknpc:OnLured(A1_1878)
end
function ArkBeta_x.OnSpawn(A0_1881, A1_1882)
  BasicActor.OnSpawn(A0_1881, A1_1882)
  A0_1881:Activate(1)
end
function ArkBeta_x.OnUpdate(A0_1883, A1_1884)
end
function ArkBeta_x.Server.OnStartGame(A0_1885)
  if not A0_1885.arknpc:IsDead() then
    A0_1885.arknpc:AttachGameEffect(15)
    if A0_1885.arknpc:HasArkMetaTag("9469288860501638642") then
      A0_1885.arknpc:AttachGameEffect(9)
    end
  end
end
function ArkBeta_x.OnNpcKilled(A0_1886)
  A0_1886.arknpc:DetachGameEffect(15)
  if A0_1886.arknpc:HasArkMetaTag("9469288860501638642") then
    A0_1886.arknpc:DetachGameEffect(9)
  end
  A0_1886:SetupInventoryOnDeath()
  A0_1886.Properties.loottables_HumanLootTable:gsub("([^,]+)", function(A0_1887)
    local L2_1888
    L2_1888 = _UPVALUE0_
    L2_1888[#_UPVALUE0_ + 1] = A0_1887
  end)
  if #{} > 0 then
    Ark.SpawnLootFromTable(({})[math.random(#{})], A0_1886.id)
  end
end
ArkBeta_x.Server.OnUpdate = ArkBeta_x.OnUpdate
