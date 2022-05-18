Script.ReloadScript("SCRIPTS/Entities/AI/Shared/AIBase.lua")
Script.ReloadScript("SCRIPTS/Entities/Ark/ArkEtherForm.lua")
ArkNightmare_x = {
  ActionController = "Animations/Mannequin/ADB/Ai_Nightmare_ControllerDefs.xml",
  AnimDatabase3P = "Animations/Mannequin/ADB/Ai_Nightmare_Database.adb",
  SoundDatabase = "Animations/Mannequin/ADB/humanSounds.adb",
  UseMannequinAGState = true,
  UseLegacyCoverLocator = false,
  physicsParams = {
    Living = {
      mass = 500,
      height = 2.25,
      size = {
        x = 1.5,
        y = 1.5,
        z = 0
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
      BONE_WEAPON = "",
      BONE_WEAPON2 = "",
      BONE_FOOT_R = "r_foot_jnt",
      BONE_FOOT_L = "l_foot_jnt",
      BONE_ARM_R = "r_upperArm_jnt",
      BONE_ARM_L = "l_upperArm_jnt",
      BONE_CALF_R = "r_legKnee_jnt",
      BONE_CALF_L = "l_legKnee_jnt",
      BONE_CAMERA = "look_jnt"
    },
    meeleHitRagdollImpulseScale = 3,
    lookFOV = 180,
    lookInVehicleFOV = 110,
    aimFOV = 160,
    maxLookAimAngle = 90,
    aimIKFadeDuration = 0.5,
    aimIKLayer = 14,
    lookIKLayer = 15,
    proceduralLeaningFactor = 0,
    canUseComplexLookIK = true,
    lookAtSimpleHeadBone = "head_jnt",
    cornerSmoother = 2,
    stepThresholdTime = 0.5,
    stepThresholdDistance = 0.1,
    turnThresholdTime = 0.5,
    turnThresholdAngle = 5,
    maxDeltaAngleRateNormal = 90,
    maxDeltaAngleRateFast = 180,
    maxDeltaAngleRateFastest = 270,
    smoothedZTurning = true,
    slopeUpSlowdownMult = 0.15,
    slopeDownSlowdownMult = 0.15,
    nearbyRange = 10,
    middleRange = 30,
    defaultStance = STANCE_RELAXED,
    stance = {
      {
        stanceId = STANCE_STAND,
        normalSpeed = 250,
        maxSpeed = 250,
        heightPivot = 0,
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 7
        },
        CollisionHeight = 6.5,
        CollisionDiameter = 3,
        CapsuleOffset = 2,
        name = "stand",
        useCapsule = 1,
        physicalizedSlot = 0
      },
      {
        stanceId = STANCE_ALERTED,
        normalSpeed = 250,
        maxSpeed = 250,
        heightPivot = 0,
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 7
        },
        CollisionHeight = 6.5,
        CollisionDiameter = 3,
        CapsuleOffset = 2,
        name = "alerted",
        useCapsule = 1,
        physicalizedSlot = 0
      },
      {
        stanceId = STANCE_INVESTIGATE_ANOMALY,
        normalSpeed = 250,
        maxSpeed = 250,
        heightPivot = 0,
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 7
        },
        CollisionHeight = 6.5,
        CollisionDiameter = 3,
        CapsuleOffset = 2,
        name = "anomaly",
        useCapsule = 1,
        physicalizedSlot = 0
      },
      {
        stanceId = STANCE_INVESTIGATE_DANGER,
        normalSpeed = 250,
        maxSpeed = 250,
        heightPivot = 0,
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 7
        },
        CollisionHeight = 6.5,
        CollisionDiameter = 3,
        CapsuleOffset = 2,
        name = "danger",
        useCapsule = 1,
        physicalizedSlot = 0
      },
      {
        stanceId = STANCE_INVESTIGATE_VISION,
        normalSpeed = 250,
        maxSpeed = 250,
        heightPivot = 0,
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 7
        },
        CollisionHeight = 6.5,
        CollisionDiameter = 3,
        CapsuleOffset = 2,
        name = "vision",
        useCapsule = 1,
        physicalizedSlot = 0
      },
      {
        stanceId = STANCE_HUNT,
        normalSpeed = 250,
        maxSpeed = 250,
        heightPivot = 0,
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 7
        },
        CollisionHeight = 6.5,
        CollisionDiameter = 3,
        CapsuleOffset = 2,
        name = "hunt",
        useCapsule = 1,
        physicalizedSlot = 0
      },
      {
        stanceId = STANCE_CROUCH,
        normalSpeed = 0.5,
        maxSpeed = 50,
        heightPivot = 0,
        size = {
          x = 0.5,
          y = 0.5,
          z = 0.1
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 7
        },
        CollisionHeight = 3.5,
        CollisionDiameter = 3,
        CapsuleOffset = 1,
        name = "crouch",
        useCapsule = 1,
        physicalizedSlot = 0
      },
      {
        stanceId = STANCE_CRAWL,
        normalSpeed = 0.5,
        maxSpeed = 50,
        heightPivot = 0,
        size = {
          x = 0.5,
          y = 0.5,
          z = 0.1
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 7
        },
        CollisionHeight = 3.5,
        CollisionDiameter = 3,
        CapsuleOffset = 1,
        name = "crawl",
        useCapsule = 1,
        physicalizedSlot = 0
      },
      {
        stanceId = STANCE_ZEROG,
        normalSpeed = 3,
        maxSpeed = 50,
        heightPivot = 0.5,
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 7
        },
        CollisionHeight = 6.5,
        CollisionDiameter = 3,
        CapsuleOffset = 2,
        name = "zerog",
        useCapsule = 1,
        physicalizedSlot = 0
      },
      {
        stanceId = STANCE_HOVER,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 1,
        heightPivot = 0,
        size = {
          x = 0.3,
          y = 0.3,
          z = 0
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
        weaponOffset = {
          x = 0.2,
          y = 0,
          z = 0.3
        },
        name = "hover",
        useCapsule = 1,
        physicalizedSlot = 1
      },
      {
        stanceId = STANCE_RELAXED,
        normalSpeed = 250,
        maxSpeed = 250,
        heightCollider = 1.2,
        heightPivot = 0,
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 7
        },
        CollisionHeight = 6.5,
        CollisionDiameter = 3,
        CapsuleOffset = 2,
        name = "relaxed",
        useCapsule = 1,
        physicalizedSlot = 0
      }
    }
  },
  Properties = {
    soundAmbientLivingSound = "Sounds/Ark_Incubation:Beta:Beta_Exist_LP",
    fileAiTree = "Ark/AI/AiTrees/NightmareAiTree.xml",
    fileAccumulatorConfig = "",
    bCanRagdoll = false,
    PsiBlast = {
      nMaterialSlot = 0,
      nSubMaterialSlot = 0,
      sMaterialParamName = "",
      fMaterialParamMaxValue = 0,
      fMaterialParamRampInTime = 0,
      fMaterialParamRampOutTime = 0
    },
    TagList = "",
    soclasses_SmartObjectClass = "Human, Actor",
    esNavigationType = "ArkAlien_Large",
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
      cloakMaxDistMoving = 5,
      cloakMaxDistStill = 2,
      config = "Human",
      FOVPrimary = 120,
      FOVSecondary = 120
    },
    AttentionFacing = {bUsesAttentionLook = 1, bUsesAttentionFacing = 1},
    useSpecialMovementTransitions = 0,
    bOverrideAllowLookAimStrafing = 1,
    fileModel = "Objects/characters/Aliens/Nightmare/Nightmare.cdf",
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
      footstepEffect = "footstep_nightmare",
      remoteFootstepEffect = "footstep_nightmare",
      footstepIndGearAudioSignal_Walk = "",
      footstepIndGearAudioSignal_Run = "",
      bFootstepGearEffect = 0,
      foleyEffect = "foley_player",
      bodyFallEffect = ""
    },
    ArkFear = {
      attachmenteffects_BlastEffect = "17591291352656538235"
    },
    OnStunned = {attachmenteffects_OnStunEffects = ""},
    OnDeath = {
      signalpackage_FearAOESignal = "",
      fFearScale = 1,
      fFearRadius = 10,
      particleeffect_FearAOEParticle = ""
    },
    OnPsychoShocked = {attachmenteffects_OnPsychoShockedEffects = ""},
    ArkCharacter = {character_Character = ""},
    MeleeAttack = {
      fShortMaxDistance = 5,
      fMediumMaxDistance = 8,
      fLongMaxDistance = 10,
      fMaxForwardAngle = 30,
      fMinSideAngle = 65,
      fMaxSideAngle = 135
    },
    ArkEffects = {
      signalpackage_KineticBlastSignalPackageId = "3149325216914175777",
      particleeffect_KineticBlast = "Player.Powers.KineticBlast.KenticBlast_00",
      fKineticBlastEffectSize = 10
    },
    ArkUnreachableTargeting = {
      startingTraceRadius = 0.75,
      startingMinSearchRadius = 4,
      chanceToSearchInReverseOrder = 0.15,
      nightmareHeightDifferential = 1.5,
      horizontalOffsetStanding = 2.8,
      horizontalOffsetCrouching = 3.2,
      standardCombatHeight = 5.2
    },
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
    Physics = {scaleFallTriggers = 3},
    ArkEtherForm = {
      attachmenteffects_LargeFormOutEffect = "12635110349638536018",
      attachmenteffects_LargeFormInEffect = "12635110349638538565"
    },
    faction_ArkFaction = "0",
    ArkMoveInfo = {
      doorAnimate = true,
      moveLarge = true,
      largeCrouchCollisionHeight = 4,
      largeNavMeshTurnClearanceMin = 0.5,
      largeNavMeshTurnClearanceMax = 1.75,
      footStepImpulseMin = 40,
      footStepImpulseMax = 80,
      footStepAdjustMassMin = 3,
      footStepAdjustMassMax = 200,
      footStepRadius = 1.2,
      footStepFalloff = 0.9,
      footStepMassScale = true,
      particleeffect_footstepEffect = "Characters.Aliens.Nightmare.Footsteps.NightmareFootstep_00",
      cameraShake_footstepCameraShake = "NightmareFootfall",
      pushLeverageMax = 3,
      legIKIgnoreRigidBodies = true,
      bDestroyGloo = true,
      headCollisionHeight = 5.25,
      headCollisionLength = 2.25,
      headCollisionRadius = 1.25,
      matchTargetHeightDistance = 15
    },
    Stun = {
      bStunLastsForever = false,
      bRagdollStun = false,
      ragdollRootJointName = "",
      signalModifier_stunnedSignalModifierId = ""
    },
    OnPsiSuppressed = {attachmenteffects_OnPsiSuppressed = ""},
    MaterialAnimations = {
      materialanimations_LargeFormOut = "5897280292631830168",
      materialanimations_LargeFormIn = "243995946793615109",
      materialanimations_EtherFormOut = "",
      materialanimations_EtherFormIn = ""
    }
  },
  AIMovementAbility = {
    allowEntityClampingByAnimation = 1,
    usePredictiveFollowing = 1,
    pathLookAhead = 1,
    walkSpeed = 13,
    runSpeed = 13,
    sprintSpeed = 13,
    maneuverSpeed = 4.6,
    b3DMove = 0,
    minTurnRadius = 0,
    maxTurnRadius = 3,
    pathSpeedLookAheadPerSpeed = -1.5,
    optimalFlightHeight = 0.9,
    minFlightHeight = 0.31,
    maxFlightHeight = 50,
    cornerSlowDown = 0.75,
    pathType = "AIPATH_NIGHTMARE",
    pathRadius = 3,
    passRadius = 1.5,
    separationRadius = 1,
    collisionAvoidanceRadiusIncrement = 0.05,
    distanceToCover = 1.4,
    inCoverRadius = 0.075,
    effectiveCoverHeight = 0.55,
    effectiveHighCoverHeight = 1.75,
    pathFindPrediction = 0.5,
    maxAccel = 13,
    maxDecel = 13,
    velDecay = 0.5,
    maneuverTrh = 2,
    resolveStickingInTrace = 1,
    pathRegenIntervalDuringTrace = -1,
    lightAffectsSpeed = 1,
    avoidanceAbilities = AVOIDANCE_ALL,
    pushableObstacleWeakAvoidance = true,
    obstacleAvoidanceMaxPathDeviation = 10,
    ignoreMinimumMassObstaclesAtHighUrgency = 1,
    ignoreMinimumMassObstaclesAtLowUrgency = 0,
    pushableObstacleAvoidanceRadiusMin = 0,
    pushableObstacleAvoidanceRadiusMax = 3,
    pushableObstacleMassMin = 200,
    pushableObstacleMassMax = 10000,
    pushableObstacleHeightMin = 1.4,
    pushableObstacleHeightMax = 3,
    lookIdleTurnSpeed = 30,
    lookCombatTurnSpeed = 50,
    aimTurnSpeed = -1,
    fireTurnSpeed = -1,
    directionalScaleRefSpeedMin = 0.1,
    directionalScaleRefSpeedMax = 14,
    directionalScaleTurn = 0.7,
    directionalScaleStrafe = 0.9,
    directionalScaleSlope = 0,
    harshStopSpeed = 0.5,
    harshStopMinAngle = 105,
    harshStopMaxAngle = 170,
    harshStopBelowDist = 5.8,
    AIMovementSpeeds = {
      Relaxed = {
        Slow = {
          3,
          0.5,
          3
        },
        Walk = {
          13,
          0,
          13
        },
        Run = {
          13,
          0,
          13
        },
        Sprint = {
          13,
          0,
          13
        }
      },
      Alerted = {
        Slow = {
          3,
          0.5,
          3
        },
        Walk = {
          13,
          0,
          13
        },
        Run = {
          13,
          0,
          13
        },
        Sprint = {
          13,
          0,
          13
        }
      },
      Combat = {
        Slow = {
          3,
          0.5,
          3
        },
        Walk = {
          13,
          0,
          13
        },
        Run = {
          13,
          0,
          13
        },
        Sprint = {
          13,
          0,
          13
        }
      },
      Hover = {
        Slow = {
          0.5,
          0.25,
          1
        },
        Walk = {
          1.8,
          1.2,
          3.3
        },
        Run = {
          6.8,
          4.8,
          8.8
        },
        Sprint = {
          12,
          9,
          15
        }
      }
    }
  },
  ProceduralContextLook = {
    polarCoordinatesSmoothTimeSeconds = 0.4,
    polarCoordinatesMaxYawDegreesPerSecond = 360,
    polarCoordinatesMaxPitchDegreesPerSecond = 360,
    fadeInSeconds = 0.4,
    fadeOutSeconds = 0.4,
    fadeOutMinDistance = 0,
    fadeOutAngleDegrees = 180,
    maxAngleDegreesXY = 40,
    maxAngleDegreesZ = 90,
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
    fadeOutMaxDistance = 125,
    fadeOutAngleDegrees = 175,
    maxAngleDegreesXY = 20,
    maxAngleDegreesZ = 90,
    speedMultiplierFast = 0.85,
    speedMultiplierFastest = 0.7
  },
  PropertiesInstance = {bStartDead = false, voiceName = "Nightmare"},
  SearchModule = {sightRange = 6.5},
  aiSequenceUser = true,
  bIsDeathGoo = false,
  nRecycleTimerId = -1
}
mergef(ArkNightmare_x, AIBase, 1)
function ArkNightmare_x.OnResetCustom(A0_1918, A1_1919, A2_1920)
  A0_1918:Activate(0)
  A0_1918.arknpc:StopCharacterEffect(CHARACTEREFFECTTYPE_FROZENINGOO)
  if A1_1919 then
    A0_1918:ResetContainer()
    A0_1918:InitInventory()
  end
end
function ArkNightmare_x.IsInvulnerable(A0_1921)
  local L1_1922
  L1_1922 = A0_1921.PropertiesInstance
  L1_1922 = L1_1922.bIsInvulnerable
  L1_1922 = L1_1922 == true
  return L1_1922
end
function ArkNightmare_x.Server.OnStartGame(A0_1923)
  local L1_1924
end
function ArkNightmare_x.OnLureSignal(A0_1925, A1_1926, A2_1927, A3_1928)
  A0_1925.arknpc:OnLured(A1_1926)
end
function ArkNightmare_x.OnFireThresholdExceeded(A0_1929)
  A0_1929.arknpc:LightOnFire()
end
function ArkNightmare_x.OnFireThesholdFellBelow(A0_1930)
  A0_1930.arknpc:OnFireExpired()
end
function ArkNightmare_x.OnFireAboveThresholdRefresh(A0_1931)
  A0_1931.arknpc:OnFireAboveThresholdRefresh()
end
function ArkNightmare_x.OnDiscHitEtherFormSignal(A0_1932, A1_1933, A2_1934, A3_1935)
  Ark.SendSignalPackage(A0_1932.id, g_localActor.id, g_localActor.id, "243995946787474368")
end
function ArkNightmare_x.OnRecycleBeginCorporeal(A0_1936, A1_1937, A2_1938, A3_1939)
  if A1_1937 ~= nil then
    A0_1936.arknpc:RestrictToEtherForm()
    if A0_1936.nRecycleTimerId ~= -1 then
      Script.KillTimer(nRecycleTimerId)
      A0_1936.nRecycleTimerId = -1
    end
    A0_1936.nRecycleTimerId = Script.SetTimer(4000, A0_1936.OnRecycleTimerEnd, A0_1936)
  end
end
function ArkNightmare_x.OnRecycleTimerEnd(A0_1940)
  A0_1940.arknpc:ClearRestrictToEtherForm()
end
