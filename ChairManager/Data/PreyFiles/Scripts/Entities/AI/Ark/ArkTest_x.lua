Script.ReloadScript("SCRIPTS/Entities/AI/Shared/AIBase.lua")
ArkTest_x = {
  ActionController = "Animations/Mannequin/ADB/Ai_Human_ControllerDefs.xml",
  AnimDatabase3P = "Animations/Mannequin/ADB/Ai_Human_Database.adb",
  SoundDatabase = "",
  UseMannequinAGState = true,
  UseLegacyCoverLocator = false,
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
      BONE_CALF_L = "l_lowerLeg_jnt"
    },
    meeleHitRagdollImpulseScale = 1,
    lookFOV = 200,
    lookInVehicleFOV = 110,
    aimFOV = 200,
    maxLookAimAngle = 120,
    aimIKFadeDuration = 0.5,
    aimIKLayer = 14,
    proceduralLeaningFactor = 0,
    canUseComplexLookIK = true,
    lookAtSimpleHeadBone = "head_jnt",
    cornerSmoother = 2,
    stepThresholdTime = 0.5,
    stepThresholdDistance = 0.1,
    turnThresholdTime = 0.5,
    turnThresholdAngle = 5,
    maxDeltaAngleRateNormal = 360,
    nearbyRange = 10,
    middleRange = 30,
    defaultStance = STANCE_RELAXED,
    stance = {
      {
        stanceId = STANCE_STAND,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 1.2,
        heightPivot = 0,
        size = {
          x = 0.5,
          y = 0.5,
          z = 0.2
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 1.625
        },
        weaponOffset = {
          x = 0.2,
          y = 0,
          z = 1.35
        },
        leanLeftViewOffset = {
          x = -0.5,
          y = 0.1,
          z = 1.525
        },
        leanRightViewOffset = {
          x = 0.5,
          y = 0.1,
          z = 1.525
        },
        leanLeftWeaponOffset = {
          x = -0.45,
          y = 0,
          z = 1.3
        },
        leanRightWeaponOffset = {
          x = 0.65,
          y = 0,
          z = 1.3
        },
        peekOverViewOffset = {
          x = 0.1,
          y = 0,
          z = 1.5
        },
        peekOverWeaponOffset = {
          x = 0.1,
          y = 0,
          z = 1.4
        },
        name = "stand",
        useCapsule = 1
      },
      {
        stanceId = STANCE_ALERTED,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 1.2,
        heightPivot = 0,
        size = {
          x = 0.5,
          y = 0.5,
          z = 0.2
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 1.625
        },
        weaponOffset = {
          x = 0.2,
          y = 0,
          z = 1.35
        },
        leanLeftViewOffset = {
          x = -0.5,
          y = 0.1,
          z = 1.525
        },
        leanRightViewOffset = {
          x = 0.5,
          y = 0.1,
          z = 1.525
        },
        leanLeftWeaponOffset = {
          x = -0.45,
          y = 0,
          z = 1.3
        },
        leanRightWeaponOffset = {
          x = 0.65,
          y = 0,
          z = 1.3
        },
        peekOverViewOffset = {
          x = 0.1,
          y = 0,
          z = 1.5
        },
        peekOverWeaponOffset = {
          x = 0.1,
          y = 0,
          z = 1.4
        },
        name = "alerted",
        useCapsule = 1
      },
      {
        stanceId = STANCE_CROUCH,
        normalSpeed = 0.5,
        maxSpeed = 50,
        heightCollider = 0.8,
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
          y = 0,
          z = 0.9
        },
        weaponOffset = {
          x = 0.2,
          y = 0,
          z = 0.85
        },
        leanLeftViewOffset = {
          x = -0.55,
          y = 0,
          z = 1.1
        },
        leanRightViewOffset = {
          x = 0.65,
          y = 0,
          z = 0.9
        },
        leanLeftWeaponOffset = {
          x = -0.5,
          y = 0,
          z = 0.85
        },
        leanRightWeaponOffset = {
          x = 0.5,
          y = 0,
          z = 0.75
        },
        peekOverViewOffset = {
          x = 0.1,
          y = 0,
          z = 1.5
        },
        peekOverWeaponOffset = {
          x = 0.1,
          y = 0,
          z = 1.4
        },
        name = "crouch",
        useCapsule = 1
      },
      {
        stanceId = STANCE_LOW_COVER,
        normalSpeed = 0.5,
        maxSpeed = 50,
        heightCollider = 0.8,
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
          y = 0,
          z = 0.9
        },
        weaponOffset = {
          x = 0.2,
          y = 0,
          z = 0.85
        },
        leanLeftViewOffset = {
          x = -0.75,
          y = 0,
          z = 0.9
        },
        leanRightViewOffset = {
          x = 0.75,
          y = 0,
          z = 0.95
        },
        leanLeftWeaponOffset = {
          x = -0.75,
          y = 0,
          z = 0.6
        },
        leanRightWeaponOffset = {
          x = 0.8,
          y = 0,
          z = 0.8
        },
        whileLeanedLeftViewOffset = {
          x = 0.2,
          y = 0.4,
          z = 0.85
        },
        whileLeanedRightViewOffset = {
          x = 0.2,
          y = 0.3,
          z = 1
        },
        whileLeanedLeftWeaponOffset = {
          x = 0.25,
          y = 0.4,
          z = 0.8
        },
        whileLeanedRightWeaponOffset = {
          x = 0.25,
          y = 0.1,
          z = 0.8
        },
        peekOverViewOffset = {
          x = 0.1,
          y = 0,
          z = 1.5
        },
        peekOverWeaponOffset = {
          x = 0.1,
          y = 0,
          z = 1.4
        },
        name = "coverLow",
        useCapsule = 1
      },
      {
        stanceId = STANCE_HIGH_COVER,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 1.2,
        heightPivot = 0,
        size = {
          x = 0.5,
          y = 0.5,
          z = 0.2
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 1.625
        },
        weaponOffset = {
          x = 0.2,
          y = 0,
          z = 1.35
        },
        leanLeftViewOffset = {
          x = -0.7,
          y = 0.1,
          z = 1.525
        },
        leanRightViewOffset = {
          x = 0.95,
          y = 0.1,
          z = 1.525
        },
        leanLeftWeaponOffset = {
          x = -0.6,
          y = 0.1,
          z = 1.3
        },
        leanRightWeaponOffset = {
          x = 1,
          y = 0.1,
          z = 1.3
        },
        whileLeanedLeftViewOffset = {
          x = 0.1,
          y = 0.1,
          z = 1.5
        },
        whileLeanedRightViewOffset = {
          x = 0.25,
          y = 0.2,
          z = 1.55
        },
        whileLeanedLeftWeaponOffset = {
          x = 0.15,
          y = 0.1,
          z = 1.35
        },
        whileLeanedRightWeaponOffset = {
          x = 0.3,
          y = 0.2,
          z = 1.45
        },
        peekOverViewOffset = {
          x = 0.1,
          y = 0,
          z = 1.5
        },
        peekOverWeaponOffset = {
          x = 0.1,
          y = 0,
          z = 1.4
        },
        name = "coverHigh",
        useCapsule = 1
      },
      {
        stanceId = STANCE_SWIM,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 0.9,
        heightPivot = 0.5,
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
          z = 0.5
        },
        weaponOffset = {
          x = 0.2,
          y = 0,
          z = 0.3
        },
        peekOverViewOffset = {
          x = 0.1,
          y = 0,
          z = 1.5
        },
        peekOverWeaponOffset = {
          x = 0.1,
          y = 0,
          z = 1.4
        },
        name = "swim",
        useCapsule = 1
      },
      {
        stanceId = STANCE_ZEROG,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 0.9,
        heightPivot = 0.5,
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
          z = 0.5
        },
        weaponOffset = {
          x = 0.2,
          y = 0,
          z = 0.3
        },
        name = "zerog",
        useCapsule = 1
      },
      {
        stanceId = STANCE_RELAXED,
        normalSpeed = 1,
        maxSpeed = 50,
        heightCollider = 1.2,
        heightPivot = 0,
        size = {
          x = 0.5,
          y = 0.5,
          z = 0.2
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 1.625
        },
        weaponOffset = {
          x = 0.2,
          y = 0,
          z = 1.3
        },
        peekOverViewOffset = {
          x = 0.1,
          y = 0,
          z = 1.5
        },
        peekOverWeaponOffset = {
          x = 0.1,
          y = 0,
          z = 1.4
        },
        name = "relaxed",
        useCapsule = 1
      }
    }
  },
  Properties = {
    fileAiTree = "Ark/AI/AiTrees/HumanAiTree.xml",
    TagList = "",
    soclasses_SmartObjectClass = "Human, Actor",
    esNavigationType = "MediumSizedCharacters",
    fileHitDeathReactionsParamsDataFile = "Libs/HitDeathReactionsData/ArkHitDeathReactions_Human.xml",
    Damage = {
      fileBodyDamage = "Libs/BodyDamage/BodyDamage_Default.xml",
      fileBodyDamageParts = "Libs/BodyDamage/BodyParts_Default.xml",
      fileBodyDestructibility = "Libs/BodyDamage/BodyDestructibility_Default.xml",
      CanFall = 1,
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
      FOVPrimary = 180,
      FOVSecondary = 180
    },
    useSpecialMovementTransitions = 1,
    bOverrideAllowLookAimStrafing = 1,
    fileModel = "Objects/characters/human/NPC/Russian/Russian_01.cdf",
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
    ArkCharacter = {characterCharacter = ""},
    ArkDialog = {
      voiceName = "Human",
      fNearbyDistance = 2,
      fPlayerApproachCD = 30,
      fPlayerLoiterCD = 5
    },
    ArkMoveInfo = {moveMultiDir = true, moveHover = false}
  },
  AIMovementAbility = {
    allowEntityClampingByAnimation = 1,
    usePredictiveFollowing = 1,
    pathLookAhead = 1,
    walkSpeed = 1.25,
    runSpeed = 3.5,
    sprintSpeed = 5,
    maneuverSpeed = 1.25,
    b3DMove = 0,
    minTurnRadius = 0,
    maxTurnRadius = 3,
    pathSpeedLookAheadPerSpeed = -1.5,
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
    avoidanceRadius = 2,
    collisionAvoidanceRadiusIncrement = 0.01,
    pushableObstacleMassMin = 0,
    pushableObstacleMassMax = 80,
    lookIdleTurnSpeed = 30,
    lookCombatTurnSpeed = 50,
    aimTurnSpeed = -1,
    fireTurnSpeed = -1,
    directionalScaleRefSpeedMin = 1,
    directionalScaleRefSpeedMax = 5,
    directionalScaleTurn = 0.4,
    directionalScaleStrafe = 0.8,
    directionalScaleSlope = 0.083333,
    AIMovementSpeeds = {
      Relaxed = {
        Slow = {
          0.5,
          0,
          0.5
        },
        Walk = {
          1.25,
          0,
          1.25
        },
        Run = {
          3.5,
          0,
          3.5
        },
        Sprint = {
          5,
          0,
          5
        }
      },
      Alerted = {
        Slow = {
          0.5,
          0,
          0.5
        },
        Walk = {
          1.5,
          0,
          1.5
        },
        Run = {
          3.5,
          0,
          3.5
        },
        Sprint = {
          5,
          0,
          5
        }
      },
      Combat = {
        Slow = {
          0.5,
          0,
          0.5
        },
        Walk = {
          1.5,
          0,
          1.5
        },
        Run = {
          3.5,
          0,
          3.5
        },
        Sprint = {
          5,
          0,
          5
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
  PropertiesInstance = {bIsInvulnerable = false, bStartDead = false},
  SearchModule = {sightRange = 12},
  aiSequenceUser = true,
  bIsDeathGoo = false,
  bIsMimicking = false,
  bIsMimickingUseableItem = false,
  fakeUseableName = "This is bad if you see this"
}
mergef(ArkTest_x, AIBase, 1)
function ArkTest_x.OnResetCustom(A0_2006, A1_2007, A2_2008)
  if A1_2007 then
    A0_2006:SpawnLootInside("ArkIngredientScrap", "exotic", 0, 2)
  end
end
function ArkTest_x.SpawnLootInside(A0_2009, A1_2010, A2_2011, A3_2012, A4_2013)
  local L5_2014, L6_2015
  L5_2014 = math
  L5_2014 = L5_2014.random
  L6_2015 = A3_2012
  L5_2014 = L5_2014(L6_2015, A4_2013)
  while L5_2014 > 0 do
    L6_2015 = {}
    L6_2015.class = A1_2010
    L6_2015.position = A0_2009:GetWorldPos()
    System.SpawnEntity(L6_2015):SetType(tostring(A2_2011))
    if System.SpawnEntity(L6_2015).arkitem:PickUp(A0_2009.id) then
      A0_2009:Log("ArkMimic_x:SpawnLootInside(): item added>>" .. A1_2010)
    else
      A0_2009:Log("ArkMimic_x:SpawnLootInside(): inventory full" .. A1_2010 .. " not added.")
    end
    System.SpawnEntity(L6_2015):Hide(1)
    L5_2014 = L5_2014 - 1
  end
end
function ArkMimic_x.IsUsable(A0_2016, A1_2017)
  local L2_2018
  L2_2018 = 1
  return L2_2018
end
function ArkTest_x.GetUsableMessage(A0_2019, A1_2020)
  if A0_2019.bIsDeathGoo == 1 then
    return A0_2019.Properties.ArkCorpseInfo.Container.deathGooContainerName .. " Corpse"
  elseif A0_2019.bIsMimickingUseableItem == 1 then
    return A0_2019.fakeUseableName
  end
  return ""
end
function ArkTest_x.OnUsed(A0_2021, A1_2022)
  if A0_2021.bIsDeathGoo == 1 then
    Ark.OpenExternalInventory(A0_2021.id)
    BroadcastEvent(A0_2021, "OnOpen")
  else
    BroadcastEvent(A0_2021, "PlayerUsed")
  end
end
function ArkTest_x.IsInvulnerable(A0_2023)
  local L1_2024
  L1_2024 = A0_2023.PropertiesInstance
  L1_2024 = L1_2024.bIsInvulnerable
  L1_2024 = L1_2024 == true or L1_2024 == 1
  return L1_2024
end
