Script.ReloadScript("SCRIPTS/Entities/AI/Shared/AIBase.lua")
Human_x = {
  ActionController = "Animations/Mannequin/ADB/humanControllerDefs.xml",
  AnimDatabase3P = "Animations/Mannequin/ADB/human.adb",
  SoundDatabase = "Animations/Mannequin/ADB/humanSounds.adb",
  UseMannequinAGState = true,
  UseLegacyCoverLocator = false,
  gameParams = {
    boneIDs = {
      BONE_BIP01 = "Bip01",
      BONE_SPINE = "Bip01 Spine1",
      BONE_SPINE2 = "Bip01 Spine2",
      BONE_SPINE3 = "Bip01 Spine3",
      BONE_HEAD = "Bip01 Head",
      BONE_WEAPON = "weapon_bone",
      BONE_WEAPON2 = "Lweapon_bone",
      BONE_FOOT_R = "Bip01 R Foot",
      BONE_FOOT_L = "Bip01 L Foot",
      BONE_ARM_R = "Bip01 R Forearm",
      BONE_ARM_L = "Bip01 L Forearm",
      BONE_CALF_R = "Bip01 R Calf",
      BONE_CALF_L = "Bip01 L Calf"
    },
    meeleHitRagdollImpulseScale = 1,
    grenadeLaunchProbability = 0.5,
    grenadeThrowMaxAngle = 45,
    lookFOV = 200,
    lookInVehicleFOV = 110,
    aimFOV = 200,
    maxLookAimAngle = 120,
    aimIKFadeDuration = 0.5,
    aimIKLayer = 14,
    proceduralLeaningFactor = 0,
    canUseComplexLookIK = true,
    lookAtSimpleHeadBone = "Bip01 Head",
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
    },
    characterDBAs = {
      "HumanAI",
      "HumanShared"
    }
  },
  Properties = {
    TagList = "",
    soclasses_SmartObjectClass = "Human, Actor",
    esNavigationType = "MediumSizedCharacters",
    fileHitDeathReactionsParamsDataFile = "Libs/HitDeathReactionsData/HitDeathReactions_SDKGrunt.xml",
    Damage = {
      fileBodyDamage = "Libs/BodyDamage/BodyDamage_Default.xml",
      fileBodyDamageParts = "Libs/BodyDamage/Bodyparts_HumanMaleShared.xml",
      fileBodyDestructibility = "Libs/BodyDamage/BodyDestructibility_HumanMaleShared.xml",
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
      config = "Human"
    },
    useSpecialMovementTransitions = 1,
    bOverrideAllowLookAimStrafing = 1,
    fileModel = "objects/characters/human/sdk_player/sdk_player_red.cdf",
    bUseFacialFrameRateLimiting = 1,
    AIBehaviorFlags = {bSniper = 0, bGrenadier = 0},
    AI = {
      bUseRadioChatter = 1,
      bPlayDeathSound = 0,
      sndDeathSound = ""
    },
    PlayerInteractions = {
      bStealthKill = 1,
      bCanBeGrabbed = 1,
      esGrabType = "Human"
    },
    CharacterSounds = {
      footstepEffect = "footstep_grunt",
      remoteFootstepEffect = "footstep_grunt",
      footstepIndGearAudioSignal_Walk = "",
      footstepIndGearAudioSignal_Run = "",
      bFootstepGearEffect = 0,
      foleyEffect = "foley_player",
      bodyFallEffect = "bodyfall"
    },
    LipSync = {
      esLipSyncType = "LipSync_TransitionQueue",
      bEnabled = true,
      TransitionQueueSettings = {
        nCharacterSlot = 0,
        nAnimLayer = 12,
        sDefaultAnimName = "facial_chewing_01"
      }
    }
  },
  AIMovementAbility = {
    allowEntityClampingByAnimation = 1,
    usePredictiveFollowing = 1,
    pathLookAhead = 1,
    walkSpeed = 2,
    runSpeed = 4,
    sprintSpeed = 6.4,
    maneuverSpeed = 1.5,
    b3DMove = 0,
    minTurnRadius = 0,
    maxTurnRadius = 3,
    pathSpeedLookAheadPerSpeed = -1.5,
    cornerSlowDown = 0.75,
    pathType = AIPATH_HUMAN,
    pathRadius = 0.25,
    passRadius = 0.25,
    separationRadius = 0.2,
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
    lookIdleTurnSpeed = 30,
    lookCombatTurnSpeed = 50,
    aimTurnSpeed = -1,
    fireTurnSpeed = -1,
    directionalScaleRefSpeedMin = 1,
    directionalScaleRefSpeedMax = 8,
    directionalScaleTurn = 0.2,
    directionalScaleStrafe = 0.6,
    directionalScaleSlope = 0.083333,
    AIMovementSpeeds = {
      Relaxed = {
        Slow = {
          0.6,
          0.6,
          0.6
        },
        Walk = {
          1.1,
          1.1,
          1.1
        },
        Run = {
          3.5,
          3.5,
          3.5
        },
        Sprint = {
          5,
          5,
          5
        }
      },
      Alerted = {
        Slow = {
          0.8,
          0.8,
          0.8
        },
        Walk = {
          1.4,
          1.4,
          1.4
        },
        Run = {
          3.5,
          3.5,
          3.5
        },
        Sprint = {
          5,
          5,
          5
        }
      },
      Combat = {
        Slow = {
          0.8,
          0.8,
          0.8
        },
        Walk = {
          1.7,
          1.7,
          1.7
        },
        Run = {
          4.5,
          4.5,
          4.5
        },
        Sprint = {
          6,
          6,
          6
        }
      },
      Crouch = {
        Slow = {
          0.8,
          0.8,
          0.8
        },
        Walk = {
          1.3,
          1.3,
          1.3
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
      LowCover = {
        Slow = {
          0.9,
          0.9,
          0.9
        },
        Walk = {
          0.9,
          0.9,
          0.9
        },
        Run = {
          1.8,
          1.8,
          1.8
        },
        Sprint = {
          1.8,
          1.8,
          1.8
        }
      },
      HighCover = {
        Slow = {
          1.3,
          1.3,
          1.3
        },
        Walk = {
          1.3,
          1.3,
          1.3
        },
        Run = {
          1.8,
          1.8,
          1.8
        },
        Sprint = {
          1.8,
          1.8,
          1.8
        }
      },
      Swim = {
        Slow = {
          1,
          1,
          1
        },
        Walk = {
          1,
          1,
          1
        },
        Run = {
          3.5,
          3.5,
          3.5
        },
        Sprint = {
          5,
          5,
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
  PropertiesInstance = {
    AI = {bGunner = 0}
  },
  SearchModule = {sightRange = 12},
  aiSequenceUser = true,
  OnCustomKill = function(A0_2163)
    if AIBase.OnCustomKill then
      AIBase.OnCustomKill(A0_2163)
    end
    if not A0_2163.Properties.AI.bPlayDeathSound or A0_2163.Properties.AI.sndDeathSound ~= "" then
    end
  end,
  OnGrenadeDanger = function(A0_2164, A1_2165, A2_2166)
    A0_2164.lastImmediateThreatPos = A2_2166.point
  end,
  OnExposedToExplosion = function(A0_2167, A1_2168, A2_2169)
    A0_2167.lastImmediateThreatPos = A2_2169.point
  end,
  OnScorcherExplosionDanger = function(A0_2170, A1_2171, A2_2172)
    A0_2170.lastImmediateThreatPos = A2_2172.point
  end,
  OnWaterRippleSeen = function(A0_2173, A1_2174, A2_2175)
    local L3_2176
    L3_2176 = A0_2173.AI
    L3_2176.lastWaterRipplePosition = A2_2175.point
    L3_2176 = g_Vectors
    L3_2176 = L3_2176.temp_v1
    A0_2173:GetWorldPos(L3_2176)
    if DistanceVectors(L3_2176, A0_2173.AI.lastWaterRipplePosition) < 15 then
      AI.Signal(SIGNALFILTER_SENDER, 1, "OnNearbyWaterRippleSeen", A0_2173.id)
    end
  end,
  OnEMPGrenadeThrown = function(A0_2177, A1_2178, A2_2179)
    AI.Signal(SIGNALFILTER_GROUPONLY, 1, "EMPGrenadeThrownInGroup", A0_2177.id)
    if A0_2177:HasGroupMembersNearby() then
      AI.PlayCommunication(A0_2177.id, "ThrowEMP", "Group", 2)
    end
  end,
  OnSmokeGrenadeThrown = function(A0_2180, A1_2181, A2_2182)
    AI.Signal(SIGNALFILTER_GROUPONLY, 1, "SmokeGrenadeThrownInGroup", A0_2180.id)
    if A0_2180:HasGroupMembersNearby() then
      AI.PlayCommunication(A0_2180.id, "ThrowSmoke", "Group", 2)
    end
  end,
  OnFragGrenadeThrown = function(A0_2183, A1_2184, A2_2185)
    AI.Signal(SIGNALFILTER_GROUPONLY, 1, "FragGrenadeThrownInGroup", A0_2183.id)
    if A0_2183:HasGroupMembersNearby() then
      AI.PlayCommunication(A0_2183.id, "ThrowFrag", "Group", 2)
    end
  end,
  OccupyAdvantagePoint = function(A0_2186)
    local L1_2187
    L1_2187 = A0_2186.ReleaseAdvantagePoint
    L1_2187(A0_2186)
    L1_2187 = AI
    L1_2187 = L1_2187.GetRefPointPosition
    L1_2187 = L1_2187(A0_2186.id)
    if not L1_2187 then
      return
    end
    A0_2186.occupiedAdvantagePointPosition = L1_2187
    GameAI.OccupyAdvantagePoint(A0_2186.id, L1_2187)
  end,
  ReleaseAdvantagePoint = function(A0_2188)
    if not A0_2188.occupiedAdvantagePointPosition then
      return
    end
    GameAI.ReleaseAdvantagePointFor(A0_2188.id, A0_2188.occupiedAdvantagePointPosition)
    A0_2188.occupiedAdvantagePointPosition = nil
  end,
  GroupMemberDied = function(A0_2189)
    local L1_2190
    L1_2190 = A0_2189.deadGroupMemberCount
    if L1_2190 == nil then
      A0_2189.deadGroupMemberCount = 1
    else
      L1_2190 = A0_2189.deadGroupMemberCount
      L1_2190 = L1_2190 + 1
      A0_2189.deadGroupMemberCount = L1_2190
    end
  end,
  GetDeadGroupMemberCount = function(A0_2191)
    return A0_2191.deadGroupMemberCount or 0
  end,
  IsAlone = function(A0_2192)
    return AI.GetDistanceToClosestGroupMember(A0_2192.id) > 50
  end,
  HasGroupMembersNearby = function(A0_2193)
    return not A0_2193:IsAlone()
  end,
  WatchedMateDie = function(A0_2194)
    local L1_2195, L2_2196
    L1_2195 = System
    L1_2195 = L1_2195.GetEntity
    L2_2196 = A0_2194.deadGroupMemberData
    L2_2196 = L2_2196.victimID
    L1_2195 = L1_2195(L2_2196)
    L2_2196 = ""
    if L1_2195 and L1_2195.deathProjectileClassId then
      L2_2196 = CryAction.GetClassName(L1_2195.deathProjectileClassId)
    end
    if L2_2196 == "LTagGrenade" then
      AI.PlayCommunication(A0_2194.id, "NoticePlayerUsingLtag", "EnemyWeaponComment", 3)
    elseif L2_2196 == "SniperBullet" or L2_2196 == "GaussBullet" then
      AI.PlayCommunication(A0_2194.id, "NoticePlayerUsingDSG1", "EnemyWeaponComment", 3)
    elseif L2_2196 == "rocket" then
      AI.PlayCommunication(A0_2194.id, "NoticePlayerUsingJaw", "EnemyWeaponComment", 3)
    elseif AI.GetAlertness(A0_2194.id) >= 2 then
      AI.PlayCommunication(A0_2194.id, "AwareOfTargetAndWitnessedMateDie", "DeadGroupMemberComment", 3)
    end
  end,
  OnGroupMemberDiedOnHMG = function(A0_2197)
    AI.PlayCommunication(A0_2197.id, "NoticeMateDiedOnMountedGun", "Group", 2)
  end
}
HumanPostures = {
  {
    name = "LowCoverPeek",
    templateOnly = true,
    type = POSTURE_PEEK,
    stance = STANCE_LOW_COVER,
    priority = 9,
    {
      name = "LowCoverPeekLeft",
      lean = -0.8,
      agInput = "coverLftPeek",
      priority = -0.25
    },
    {
      name = "LowCoverPeekRight",
      lean = 0.8,
      agInput = "coverRgtPeek",
      priority = -0.25
    },
    {
      name = "LowCoverPeekCenter",
      peekOver = 0.8,
      agInput = "coverMidPeek",
      priority = -0.5
    }
  },
  {
    name = "HighCoverPeek",
    templateOnly = true,
    type = POSTURE_PEEK,
    stance = STANCE_HIGH_COVER,
    priority = 9,
    {
      name = "HighCoverPeekLeft",
      lean = -0.8,
      agInput = "coverLftPeek",
      priority = -0.15
    },
    {
      name = "HighCoverPeekRight",
      lean = 0.8,
      agInput = "coverRgtPeek",
      priority = -0.15
    }
  },
  {
    name = "LowCoverAim",
    templateOnly = true,
    type = POSTURE_AIM,
    stance = STANCE_LOW_COVER,
    priority = 8,
    {
      name = "LowCoverAimOverCenter",
      peekOver = 0.8,
      agInput = "coverMidShoot"
    },
    {
      name = "LowCoverAimLeft",
      lean = -0.8,
      agInput = "coverLftShoot"
    },
    {
      name = "LowCoverAimRight",
      lean = 0.8,
      agInput = "coverRgtShoot"
    }
  },
  {
    name = "HighCoverAim",
    type = POSTURE_AIM,
    stance = STANCE_HIGH_COVER,
    priority = 9,
    {
      name = "HighCoverAimLeft",
      lean = -0.8,
      agInput = "coverLftShoot"
    },
    {
      name = "HighCoverAimRight",
      lean = 0.8,
      agInput = "coverRgtShoot"
    }
  },
  {
    name = "StandAim",
    type = POSTURE_AIM,
    stance = STANCE_STAND,
    priority = 10,
    {
      name = "StandAimCenter",
      lean = 0,
      priority = 0
    }
  },
  {
    name = "CrouchAim",
    type = POSTURE_AIM,
    stance = STANCE_CROUCH,
    priority = 8,
    {
      name = "CrouchAimCenter",
      lean = 0,
      priority = 0
    }
  },
  {
    name = "BlindLowCoverAim",
    templateOnly = true,
    type = POSTURE_AIM,
    stance = STANCE_LOW_COVER,
    priority = 0,
    {
      name = "BlindLowCoverAimLeft",
      lean = -0.8,
      agInput = "coverLftBlind",
      priority = -0.25
    },
    {
      name = "BlindLowCoverAimRight",
      lean = 0.8,
      peekOver = 0.2,
      agInput = "coverRgtBlind",
      priority = -0.25
    },
    {
      name = "BlindLowCoverAimCenter",
      peekOver = 0.8,
      agInput = "coverMidBlind",
      priority = -0.5
    }
  },
  {
    name = "BlindHighCoverAim",
    templateOnly = true,
    type = POSTURE_AIM,
    stance = STANCE_HIGH_COVER,
    priority = 0,
    {
      name = "BlindHighCoverAimLeft",
      lean = -0.8,
      agInput = "coverLftBlind",
      priority = -0.15
    },
    {
      name = "BlindHighCoverAimRight",
      lean = 0.8,
      agInput = "coverRgtBlind",
      priority = -0.15
    }
  }
}
mergef(Human_x, AIBase, 1)
function Human_x.OnResetCustom(A0_2198)
  GameAI.UnregisterWithAllModules(A0_2198.id)
  AI.SetPostures(A0_2198.id, HumanPostures)
  A0_2198.AI.mountedWeaponCheck = true
  if A0_2198.Properties.AI.bUseRadioChatter == 1 then
    GameAI.RegisterWithModule("RadioChatter", A0_2198.id)
  end
  GameAI.RegisterWithModule("BattleFront", A0_2198.id)
  GameAI.RegisterWithModule("StalkerModule", A0_2198.id)
  GameAI.RegisterWithModule("RangeModule", A0_2198.id)
  GameAI.AddRange(A0_2198.id, 2.5, "OnTargetEnteredMeleeRange", "")
  GameAI.AddRange(A0_2198.id, 3, "", "OnTargetLeftMeleeRange")
  GameAI.AddRange(A0_2198.id, A0_2198.gameParams.nearbyRange, "OnTargetEnteredNearbyRange", "OnTargetLeftNearbyRange")
  GameAI.AddRange(A0_2198.id, A0_2198.gameParams.middleRange, "OnTargetEnteredMiddleRange", "OnTargetEnteredMiddleRange")
  GameAI.AddRange(A0_2198.id, 8, "EnteredTooCloseForComfortRange", "LeftTooCloseForComfortRange")
  if A0_2198.Properties.AIBehaviorFlags.bSniper == 1 then
    GameAI.AddRange(A0_2198.id, 10, "OnTargetEnteredCloseRange", "")
    GameAI.AddRange(A0_2198.id, 12, "", "OnTargetLeftCloseRange")
  end
  if A0_2198.Properties.AIBehaviorFlags.bGrenadier == 1 then
    GameAI.AddRange(A0_2198.id, 20, "OnTargetEnteredCloseRange", "")
    GameAI.AddRange(A0_2198.id, 22, "", "OnTargetLeftCloseRange")
  end
  A0_2198.lastImmediateThreatPos = {
    x = 0,
    y = 0,
    z = 0
  }
  A0_2198.deadGroupMemberCount = 0
  A0_2198.suspiciousSoundInvestigationCount = 0
  A0_2198.actor:AcquireOrReleaseLipSyncExtension()
end
function Human_x.EnableSearchModule(A0_2199)
  local L1_2200, L2_2201, L3_2202
  L1_2200 = AI
  L1_2200 = L1_2200.GetGroupOf
  L2_2201 = A0_2199.id
  L1_2200 = L1_2200(L2_2201)
  L2_2201 = g_Vectors
  L2_2201 = L2_2201.temp_v1
  L3_2202 = AI
  L3_2202 = L3_2202.GetAttentionTargetPosition
  L3_2202 = L3_2202(A0_2199.id, L2_2201)
  if L3_2202 then
    L3_2202 = NULL_ENTITY
    if AI.GetAttentionTargetEntity(A0_2199.id) then
      L3_2202 = AI.GetAttentionTargetEntity(A0_2199.id).id
    end
    GameAI.StartSearchModuleFor(L1_2200, L2_2201, L3_2202, 45)
    GameAI.RegisterWithModule("SearchModule", A0_2199.id)
    A0_2199:Log("Started search module for my group.")
  else
    L3_2202 = A0_2199.Error
    L3_2202(A0_2199, "No attention target to search for")
  end
end
function Human_x.SetNextSearchSpotToRefPoint(A0_2203)
  local L1_2204
  L1_2204 = GameAI
  L1_2204 = L1_2204.GetNextSearchSpot
  L1_2204 = L1_2204(A0_2203.id, 0.6, 0.3, 15, 0.1)
  if L1_2204 then
    AI.SetRefPointPosition(A0_2203.id, L1_2204)
  else
    AI.Signal(SIGNALFILTER_SENDER, 1, "NoSearchSpotsAvailable", A0_2203.id)
  end
end
function Human_x.DisableSearchModule(A0_2205)
  GameAI.UnregisterWithModule("SearchModule", A0_2205.id)
end
function Human_x.OnPostLoad(A0_2206)
  A0_2206:OnResetCustom()
  BasicActor.OnPostLoad(A0_2206)
end
function Human_x.SetHoldGroundMoveSpeed(A0_2207)
  local L1_2208
  L1_2208 = g_Vectors
  L1_2208 = L1_2208.temp_v1
  A0_2207:GetWorldPos(L1_2208)
  if DistanceVectors(L1_2208, A0_2207.AI.HoldGround.pos) > 10 or math.abs(L1_2208.z - A0_2207.AI.HoldGround.pos.z) > 1 then
    AI.SetSpeed(A0_2207.id, SPEED_RUN)
  else
    AI.SetSpeed(A0_2207.id, SPEED_WALK)
  end
end
function Human_x.DoPainSounds(A0_2209, A1_2210, A2_2211, A3_2212)
  if g_gameRules:IsStealthHealthHit(A2_2211) then
    return
  end
  if A1_2210 then
    if A0_2209.doHeadShotReadability then
      AI.PlayCommunication(A0_2209.id, "comm_headshot_death", "Injury", 0.5)
      A0_2209.doHeadShotReadability = false
    elseif A2_2211 == "stickyArrow" then
      AI.PlayCommunication(A0_2209.id, "comm_headshot_death", "Injury", 0.5)
    elseif A2_2211 == "meleeLeft" or A2_2211 == "meleeRight" then
      if AI.GetAlertness(A0_2209.id) > 0 == false then
        AI.PlayCommunication(A0_2209.id, "comm_headshot_death", "Injury", 0.5)
      else
        AI.PlayCommunication(A0_2209.id, "comm_death_melee", "Injury", 0.5)
      end
    elseif A2_2211 == "silentMelee" then
      AI.PlayCommunication(A0_2209.id, "comm_headshot_death", "Injury", 0.5)
    elseif A3_2212 == true then
      AI.PlayCommunication(A0_2209.id, "comm_headshot_death", "Injury", 0.5)
    else
      AI.PlayCommunication(A0_2209.id, "comm_death", "Injury", 0.5)
    end
  elseif A2_2211 == "silentMelee" then
    return
  else
    AI.PlayCommunication(A0_2209.id, "comm_pain", "InjuryPain", 0.5)
  end
end
function Human_x.EnableBlindFire(A0_2213, A1_2214)
  if A1_2214 then
    AI.SetPosturePriority(A0_2213.id, "BlindLowCoverAim", 10)
    AI.SetPosturePriority(A0_2213.id, "BlindHighCoverAim", 10)
  else
    AI.SetPosturePriority(A0_2213.id, "BlindLowCoverAim", 0)
    AI.SetPosturePriority(A0_2213.id, "BlindHighCoverAim", 0)
  end
end
function Human_x.CheckForMountedWeapons(A0_2215)
  if A0_2215:FindValidMountedWeapon() then
    A0_2215.AI.targetMountedWeapon = A0_2215:FindValidMountedWeapon()
    AI.SetBehaviorVariable(A0_2215.id, "GoToMountedWeapon", true)
    return true
  else
    return false
  end
end
function Human_x.FindValidMountedWeapon(A0_2216)
  local L1_2217
  L1_2217 = AI
  L1_2217 = L1_2217.FindObjectOfType
  L1_2217 = L1_2217(A0_2216:GetPos(), 10, AIOBJECT_MOUNTEDWEAPON)
  if L1_2217 and System.GetEntityByName(L1_2217) and not System.GetEntityByName(L1_2217).inUse and Game.IsMountedWeaponUsableWithTarget(A0_2216.id, System.GetEntityByName(L1_2217).id) then
    return (System.GetEntityByName(L1_2217))
  end
end
function Human_x.OnUseMountedWeaponRequest(A0_2218, A1_2219)
  A0_2218:PrepareForMountedWeaponUse(A1_2219)
end
function Human_x.PrepareForMountedWeaponUse(A0_2220, A1_2221, A2_2222)
  local L3_2223, L4_2224, L5_2225, L6_2226, L7_2227
  if A1_2221 then
    L4_2224 = System
    L4_2224 = L4_2224.GetEntity
    L5_2225 = A1_2221
    L4_2224 = L4_2224(L5_2225)
    L3_2223 = L4_2224
  else
  end
  if not L3_2223 then
    L4_2224 = false
    return L4_2224
  end
  L4_2224 = L3_2223.item
  L5_2225 = L4_2224
  L4_2224 = L4_2224.IsUsed
  L4_2224 = L4_2224(L5_2225)
  if L4_2224 then
    L4_2224 = L3_2223.item
    L5_2225 = L4_2224
    L4_2224 = L4_2224.GetOwnerId
    L4_2224 = L4_2224(L5_2225)
    L5_2225 = A0_2220.id
    if L4_2224 ~= L5_2225 then
      L4_2224 = false
      return L4_2224
    end
  end
  L4_2224 = g_Vectors
  L4_2224 = L4_2224.temp_v1
  L5_2225 = L3_2223.item
  L6_2226 = L5_2225
  L5_2225 = L5_2225.GetMountedDir
  L7_2227 = g_Vectors
  L7_2227 = L7_2227.temp_v2
  L5_2225 = L5_2225(L6_2226, L7_2227)
  L7_2227 = L3_2223
  L6_2226 = L3_2223.GetWorldPos
  L6_2226 = L6_2226(L7_2227, g_Vectors.temp_v3)
  L7_2227 = FastDifferenceVectors
  L7_2227(L4_2224, L6_2226, L5_2225)
  L7_2227 = g_Vectors
  L7_2227 = L7_2227.temp_v4
  L7_2227.x = 0
  L7_2227.y = 0
  L7_2227.z = -2
  if 0 < Physics.RayWorldIntersection(L4_2224, L7_2227, 2, ent_terrain + ent_static + ent_rigid + ent_sleeping_rigid, A0_2220.id, nil, g_HitTable) then
    L4_2224.z = g_HitTable[1].pos.z
  end
  AI.SetRefPointPosition(A0_2220.id, L4_2224)
  AI.SetRefPointDirection(A0_2220.id, L5_2225)
  A0_2220.AI.currentMountedWeaponId = A1_2221
  A0_2220.AI.currentMountedWeaponInitialDir = L5_2225
  A0_2220.AI.currentMountedWeaponPivot = L6_2226
  L3_2223.inUse = true
  if not A0_2220.AI.theVehicle and not A0_2220.AI.usingMountedWeapon then
    AI.SetBehaviorVariable(A0_2220.id, "MovingToMountedWeapon", true)
  else
    return false
  end
  return true
end
function Human_x.ForceReleaseOfMountedGun(A0_2228)
  A0_2228:LeaveMountedWeapon()
end
function Human_x.SetMachineGunInitialDirInRefPoint(A0_2229)
  if A0_2229.AI.currentMountedWeaponInitialDir ~= nil and A0_2229.AI.currentMountedWeaponPivot ~= nil then
    AI.SetRefPointPosition(A0_2229.id, A0_2229.AI.currentMountedWeaponPivot)
    AI.SetRefPointDirection(A0_2229.id, A0_2229.AI.currentMountedWeaponInitialDir)
  end
end
function Human_x.UseMountedWeapon(A0_2230)
  local L1_2231, L2_2232, L3_2233, L4_2234, L5_2235, L6_2236, L7_2237
  L1_2231 = A0_2230.AI
  L1_2231 = L1_2231.targetMountedWeapon
  if L1_2231 then
    L1_2231 = A0_2230.AI
    L1_2231 = L1_2231.targetMountedWeapon
    L1_2231.inUse = true
  end
  L1_2231 = A0_2230.AI
  L1_2231 = L1_2231.currentMountedWeaponId
  if not L1_2231 then
    return
  end
  L2_2232 = A0_2230.AI
  L3_2233 = AI
  L3_2233 = L3_2233.GetParameter
  L4_2234 = A0_2230.id
  L5_2235 = AIPARAM_FIRE_TURNSPEED
  L3_2233 = L3_2233(L4_2234, L5_2235)
  L2_2232.oldFireTurnSpeed = L3_2233
  L2_2232 = AI
  L2_2232 = L2_2232.ChangeParameter
  L3_2233 = A0_2230.id
  L4_2234 = AIPARAM_FIRE_TURNSPEED
  L5_2235 = 35
  L2_2232(L3_2233, L4_2234, L5_2235)
  L2_2232 = A0_2230.Properties
  L2_2232 = L2_2232.Perception
  L3_2233 = L2_2232.sightrange
  L4_2234 = AI
  L4_2234 = L4_2234.ChangeParameter
  L5_2235 = A0_2230.id
  L6_2236 = AIPARAM_ACCURACY
  L7_2237 = 1
  L4_2234(L5_2235, L6_2236, L7_2237)
  L4_2234 = AI
  L4_2234 = L4_2234.ChangeParameter
  L5_2235 = A0_2230.id
  L6_2236 = AIPARAM_SIGHTRANGE
  L7_2237 = L3_2233
  L4_2234(L5_2235, L6_2236, L7_2237)
  L4_2234 = AI
  L4_2234 = L4_2234.ChangeParameter
  L5_2235 = A0_2230.id
  L6_2236 = AIPARAM_ATTACKRANGE
  L7_2237 = L3_2233
  L4_2234(L5_2235, L6_2236, L7_2237)
  L4_2234 = AI
  L4_2234 = L4_2234.ChangeParameter
  L5_2235 = A0_2230.id
  L6_2236 = AIPARAM_FOVPRIMARY
  L7_2237 = 320
  L4_2234(L5_2235, L6_2236, L7_2237)
  L4_2234 = AI
  L4_2234 = L4_2234.ChangeParameter
  L5_2235 = A0_2230.id
  L6_2236 = AIPARAM_FOVSECONDARY
  L7_2237 = 330
  L4_2234(L5_2235, L6_2236, L7_2237)
  L4_2234 = System
  L4_2234 = L4_2234.GetEntity
  L5_2235 = L1_2231
  L4_2234 = L4_2234(L5_2235)
  if L4_2234 then
    L6_2236 = A0_2230
    L5_2235 = A0_2230.GetDistance
    L7_2237 = L4_2234.id
    L5_2235 = L5_2235(L6_2236, L7_2237)
    if L5_2235 < 3 then
      L5_2235 = A0_2230.actor
      L6_2236 = L5_2235
      L5_2235 = L5_2235.HolsterItem
      L7_2237 = true
      L5_2235(L6_2236, L7_2237)
      L5_2235 = L4_2234.item
      L6_2236 = L5_2235
      L5_2235 = L5_2235.IsUsed
      L5_2235 = L5_2235(L6_2236)
      if not L5_2235 then
        L5_2235 = L4_2234.item
        L6_2236 = L5_2235
        L5_2235 = L5_2235.StartUse
        L7_2237 = A0_2230.id
        L5_2235(L6_2236, L7_2237)
        L5_2235 = g_Vectors
        L5_2235 = L5_2235.temp_v1
        L6_2236 = L4_2234.item
        L7_2237 = L6_2236
        L6_2236 = L6_2236.GetMountedDir
        L6_2236 = L6_2236(L7_2237, g_Vectors.temp_v2)
        L7_2237 = L4_2234.GetWorldPos
        L7_2237 = L7_2237(L4_2234, g_Vectors.temp_v3)
        FastSumVectors(L5_2235, L7_2237, L6_2236)
        FastSumVectors(L5_2235, L5_2235, L6_2236)
        AI.SetRefPointPosition(A0_2230.id, L5_2235)
        AI.SetRefPointDirection(A0_2230.id, L6_2236)
        A0_2230.AI.usingMountedWeapon = true
        if L4_2234.class == "HMG" then
          AI.PlayCommunication(A0_2230.id, "AIUsesMountedGun", "Group", 3)
        elseif L4_2234.class == "AGL" then
          AI.PlayCommunication(A0_2230.id, "AIUsesAGL", "Group", 3)
        end
      end
    else
      L6_2236 = A0_2230
      L5_2235 = A0_2230.DrawWeaponNow
      L5_2235(L6_2236)
    end
  end
end
function Human_x.LeaveMountedWeapon(A0_2238)
  local L1_2239
  L1_2239 = A0_2238.AI
  L1_2239 = L1_2239.targetMountedWeapon
  if L1_2239 then
    L1_2239 = A0_2238.AI
    L1_2239 = L1_2239.targetMountedWeapon
    L1_2239.inUse = false
  end
  L1_2239 = A0_2238.AI
  L1_2239 = L1_2239.currentMountedWeaponId
  if not L1_2239 then
    return
  end
  A0_2238.AI.currentMountedWeaponId = nil
  A0_2238.AI.currentMountedWeaponInitialDir = nil
  A0_2238.AI.currentMountedWeaponPivot = nil
  if System.GetEntity(L1_2239) then
    System.GetEntity(L1_2239).inUse = false
  else
    A0_2238:OnError("(LeaveMountedWeapon) No weapon entity?")
    return
  end
  A0_2238.AI.usingMountedWeapon = nil
  AI.ChangeParameter(A0_2238.id, AIPARAM_FIRE_TURNSPEED, A0_2238.AI.oldFireTurnSpeed)
  AI.ChangeParameter(A0_2238.id, AIPARAM_ACCURACY, 1)
  AI.ChangeParameter(A0_2238.id, AIPARAM_SIGHTRANGE, A0_2238.Properties.Perception.sightrange)
  AI.ChangeParameter(A0_2238.id, AIPARAM_ATTACKRANGE, A0_2238.Properties.Perception.attackrange)
  AI.ChangeParameter(A0_2238.id, AIPARAM_FOVPRIMARY, A0_2238.Properties.Perception.FOVPrimary)
  AI.ChangeParameter(A0_2238.id, AIPARAM_FOVSECONDARY, A0_2238.Properties.Perception.FOVSecondary)
  if System.GetEntity(L1_2239) then
    System.GetEntity(L1_2239).item:StopUse(A0_2238.id)
    A0_2238.actor:HolsterItem(false)
  end
end
function Human_x.CanShootMountedWeapon(A0_2240)
  if AI.GetTargetType(A0_2240.id) ~= AITARGET_ENEMY and AI.GetTargetType(A0_2240.id) ~= AITARGET_MEMORY and AI.GetTargetType(A0_2240.id) ~= AITARGET_SOUND then
    return false
  end
  if not A0_2240.AI.currentMountedWeaponId then
    return false
  end
  if not System.GetEntity(A0_2240.AI.currentMountedWeaponId) or not Game.IsMountedWeaponUsableWithTarget(A0_2240.id, System.GetEntity(A0_2240.AI.currentMountedWeaponId).id, 0) then
    return false
  end
  return true
end
function Human_x.CheckMountedWeaponTarget(A0_2241)
  if A0_2241.AI.mountedWeaponCheck == false then
    return
  end
  if A0_2241.actor:GetLinkedVehicleId() then
    return
  end
  if AI.GetTargetType(A0_2241.id) == AITARGET_MEMORY or AI.GetTargetType(A0_2241.id) == AITARGET_SOUND then
    if 10 > AI.GetAttentionTargetDistance(A0_2241.id) then
      A0_2241:Log("CheckMountedWeaponTarget - dist < cutoff... leaving")
      AI.Signal(SIGNALFILTER_SENDER, 1, "LeaveMountedWeapon", A0_2241.id)
    end
  elseif AI.GetTargetType(A0_2241.id) == AITARGET_ENEMY and not A0_2241:CanShootMountedWeapon() then
    A0_2241:Log("CheckMountedWeaponTarget - CanShootMountedWeapon is false... leaving")
    AI.Signal(SIGNALFILTER_SENDER, 1, "LeaveMountedWeapon", A0_2241.id)
  end
end
function Human_x.IsTargetAnEnemy(A0_2242)
  return AI.GetTargetType(A0_2242.id) == AITARGET_ENEMY
end
function Human_x.MountedWeaponTargetChange(A0_2243)
  if AI.GetTargetType(A0_2243.id) == AITARGET_ENEMY then
    A0_2243:SelectPipe(0, "FireMountedWeapon")
  else
    A0_2243:SelectPipe(0, "LookAroundInMountedWeapon")
    if A0_2243.AI.theVehicle then
      A0_2243:InsertSubpipe(AIGOALPIPE_NOTDUPLICATE, "FireSecondaryMountedWeapon")
    end
  end
end
function Human_x.IsUsable(A0_2244, A1_2245)
  if A0_2244:IsDead() then
    return 0
  else
    return 1
  end
end
function Human_x.GetUsable(A0_2246)
  if not A0_2246:IsDead() then
    ({}).ActionType = "ScriptDefined"
    ;({}).Use, ({}).DisplayText = {}, "@use_object"
  end
  return {}
end
function Human_x.AnimationEvent(A0_2247, A1_2248, A2_2249)
  if A1_2248 == "StealthMeleeDeath" then
    AI.PlayCommunication(A0_2247.id, "comm_death_melee_stealth", "Injury", 0.5)
  elseif BasicAI.AnimationEvent then
    BasicAI.AnimationEvent(A0_2247, A1_2248, A2_2249)
  end
end
function Human_x.IsFurthestAwayFromTargetInSquad(A0_2250)
  local L1_2251, L2_2252, L3_2253, L4_2254
  L1_2251 = GameAI
  L1_2251 = L1_2251.GetSquadId
  L2_2252 = A0_2250.id
  L1_2251 = L1_2251(L2_2252)
  if L1_2251 == nil then
    L3_2253 = A0_2250
    L2_2252 = A0_2250.Error
    L4_2254 = "IsFurthestAwayFromTargetInSquad: Squad ID is nil"
    L2_2252(L3_2253, L4_2254)
    L2_2252 = true
    return L2_2252
  end
  L2_2252 = GameAI
  L2_2252 = L2_2252.GetSquadMembers
  L3_2253 = L1_2251
  L2_2252 = L2_2252(L3_2253)
  if L2_2252 == nil then
    L4_2254 = A0_2250
    L3_2253 = A0_2250.Error
    L3_2253(L4_2254, "IsFurthestAwayFromTargetInSquad: Squad doesn't have any members (members is nil)")
    L3_2253 = true
    return L3_2253
  end
  L3_2253 = A0_2250.id
  L4_2254 = 0
  for _FORV_8_, _FORV_9_ in pairs(L2_2252) do
    if L4_2254 < (AI.GetAttentionTargetDistance(_FORV_9_.id) or 500) then
      L4_2254, L3_2253 = AI.GetAttentionTargetDistance(_FORV_9_.id) or 500, _FORV_9_.id
    end
  end
  if L3_2253 == A0_2250.id then
    return true
  else
    return false
  end
end
function Human_x.IsFurtherAwayFromTargetThanAveragePositionOfSquadScopeUsers(A0_2255, A1_2256)
  local L2_2257, L3_2258, L4_2259
  L2_2257 = g_Vectors
  L2_2257 = L2_2257.temp_v1
  L3_2258 = AI
  L3_2258 = L3_2258.GetAttentionTargetPosition
  L4_2259 = A0_2255.id
  L3_2258 = L3_2258(L4_2259, L2_2257)
  if not L3_2258 then
    L3_2258 = true
    return L3_2258
  end
  L3_2258 = GameAI
  L3_2258 = L3_2258.GetSquadScopeUserCount
  L4_2259 = A0_2255.id
  L3_2258 = L3_2258(L4_2259, A1_2256)
  if L3_2258 < 2 then
    L3_2258 = true
    return L3_2258
  end
  L3_2258 = GameAI
  L3_2258 = L3_2258.GetAveragePositionOfSquadScopeUsers
  L4_2259 = A0_2255.id
  L3_2258 = L3_2258(L4_2259, A1_2256)
  L4_2259 = IsNullVector
  L4_2259 = L4_2259(L3_2258)
  if L4_2259 then
    L4_2259 = true
    return L4_2259
  end
  L4_2259 = A0_2255.GetWorldPos
  L4_2259 = L4_2259(A0_2255, g_Vectors.temp_v2)
  if DistanceSqVectors(L3_2258, L2_2257) < DistanceSqVectors(L4_2259, L2_2257) then
    return true
  else
    return false
  end
end
function Human_x.IsClosestToTargetInSquad(A0_2260)
  local L1_2261, L2_2262, L3_2263, L4_2264
  L1_2261 = GameAI
  L1_2261 = L1_2261.GetSquadId
  L2_2262 = A0_2260.id
  L1_2261 = L1_2261(L2_2262)
  if L1_2261 == nil then
    L3_2263 = A0_2260
    L2_2262 = A0_2260.Error
    L4_2264 = "IsCloserFromTargetInSquad: Squad ID is nil"
    L2_2262(L3_2263, L4_2264)
    L2_2262 = true
    return L2_2262
  end
  L2_2262 = GameAI
  L2_2262 = L2_2262.GetSquadMembers
  L3_2263 = L1_2261
  L2_2262 = L2_2262(L3_2263)
  if L2_2262 == nil then
    L4_2264 = A0_2260
    L3_2263 = A0_2260.Error
    L3_2263(L4_2264, "IsCloserFromTargetInSquad: Squad doesn't have any members (members is nil)")
    L3_2263 = true
    return L3_2263
  end
  L3_2263 = A0_2260.id
  L4_2264 = 1000
  for _FORV_8_, _FORV_9_ in pairs(L2_2262) do
    if _FORV_9_ ~= nil and _FORV_9_:IsActive() and not _FORV_9_:IsDead() then
      if L4_2264 >= (AI.GetAttentionTargetDistance(_FORV_9_.id) or 500) then
        L4_2264, L3_2263 = AI.GetAttentionTargetDistance(_FORV_9_.id) or 500, _FORV_9_.id
      end
    end
  end
  if L3_2263 == A0_2260.id then
    return true
  else
    return false
  end
end
function Human_x.IsClosestToTargetInGroup(A0_2265)
  local L1_2266, L2_2267, L3_2268, L4_2269, L5_2270, L6_2271, L7_2272
  L1_2266 = A0_2265.id
  L2_2267 = 1000
  L3_2268 = AI
  L3_2268 = L3_2268.GetGroupCount
  L3_2268 = L3_2268(L4_2269)
  for L7_2272 = 1, L3_2268 do
    if AI.GetGroupMember(A0_2265.id, L7_2272) ~= nil and AI.GetGroupMember(A0_2265.id, L7_2272):IsActive() and not AI.GetGroupMember(A0_2265.id, L7_2272):IsDead() then
      if L2_2267 >= (AI.GetAttentionTargetDistance(AI.GetGroupMember(A0_2265.id, L7_2272).id) or 500) then
        L2_2267, L1_2266 = AI.GetAttentionTargetDistance(AI.GetGroupMember(A0_2265.id, L7_2272).id) or 500, AI.GetGroupMember(A0_2265.id, L7_2272).id
      end
    end
  end
  if L1_2266 == L4_2269 then
    return L4_2269
  else
    return L4_2269
  end
end
function Human_x.IsInRangeFromTarget(A0_2273, A1_2274)
  if A1_2274 and A1_2274 >= (AI.GetAttentionTargetDistance(A0_2273.id) or 500) then
    return true
  end
  return false
end
function Human_x.GetTargetDistance(A0_2275)
  return AI.GetAttentionTargetDistance(A0_2275.id) or 500
end
function Human_x.SetLastExplosiveTypeAsGrenade(A0_2276)
  local L1_2277
  A0_2276.lastExplosiveType = "grenade"
  L1_2277 = true
  return L1_2277
end
function Human_x.SetLastExplosiveTypeAsExplosive(A0_2278)
  local L1_2279
  A0_2278.lastExplosiveType = "explosive"
  L1_2279 = true
  return L1_2279
end
function Human_x.ClearCombatMoveAssignmentIfCloseToTheDestination(A0_2280)
  if DistanceSqVectors(A0_2280:GetWorldPos(), A0_2280.AI.combatMove.position) < 25 then
    A0_2280:ClearAssignment()
  end
end
function Human_x.ShouldUseGrenade(A0_2281)
  local L1_2282, L2_2283
  L1_2282 = AI
  L1_2282 = L1_2282.GetAttentionTargetEntity
  L2_2283 = A0_2281.id
  L1_2282 = L1_2282(L2_2283)
  L2_2283 = A0_2281.ValidateAttentionTarget
  L2_2283 = L2_2283(A0_2281, L1_2282)
  if not L2_2283 then
    L2_2283 = false
    return L2_2283
  end
  L2_2283 = g_Vectors
  L2_2283 = L2_2283.temp_v3
  SubVectors(L2_2283, L1_2282:GetWorldPos(), A0_2281:GetWorldPos())
  NormalizeVector(L2_2283)
  if dotproduct2d(A0_2281:GetDirectionVector(), L2_2283) > math.cos(math.rad(A0_2281.gameParams.grenadeThrowMaxAngle)) then
    if A0_2281.gameParams.grenadeLaunchProbability and random(0, 1) <= A0_2281.gameParams.grenadeLaunchProbability then
      return true
    else
      return false
    end
  end
end
function Human_x.RefreshCurrentDeadGroupMemberBodyPosition(A0_2284)
  if A0_2284.deadGroupMemberData == nil then
    A0_2284:Error("RefreshCurrentDeadGroupMemberBodyPosition expected the 'dead group member data' to exist but it didn't.")
    return
  end
  if System.GetEntity(A0_2284.deadGroupMemberData.victimID) then
    CopyVector(A0_2284.deadGroupMemberData.currentBodyPosition, System.GetEntity(A0_2284.deadGroupMemberData.victimID):GetWorldPos())
  end
end
function Human_x.SetDeadGroupMemberBodyPositionAsRefPoint(A0_2285)
  if A0_2285.deadGroupMemberData == nil then
    A0_2285:Error("SetDeadGroupMemberPositionAsRefPoint expected the 'dead group member data' to exist but it didn't.")
    return false
  end
  AI.SetRefPointPosition(A0_2285.id, A0_2285.deadGroupMemberData.currentBodyPosition)
  return true
end
function Human_x.SetDeadGroupMemberDeathPositionAsRefPoint(A0_2286)
  if A0_2286.deadGroupMemberData == nil then
    A0_2286:Error("SetDeadGroupMemberDeathPositionAsRefPoint expected the 'dead group member data' to exist but it didn't.")
    return false
  end
  AI.SetRefPointPosition(A0_2286.id, A0_2286.deadGroupMemberData.deathPosition)
  return true
end
function Human_x.GrabDeadGroupMemberDataFromGroupScriptTable(A0_2287)
  local L1_2288
  L1_2288 = AI
  L1_2288 = L1_2288.GetGroupOf
  L1_2288 = L1_2288(A0_2287.id)
  assert(AI.GetGroupScriptTable(L1_2288) ~= nil)
  if AI.GetGroupScriptTable(L1_2288) == nil then
    A0_2287:Error("group == nil in GrabDeadGroupMemberDataFromGroupScriptTable")
    return
  end
  if AI.GetGroupScriptTable(L1_2288).deadGroupMemberData == nil then
    A0_2287:Error("group.deadGroupMemberData == nil in GrabDeadGroupMemberDataFromGroupScriptTable")
    return
  end
  A0_2287.deadGroupMemberData = {}
  mergef(A0_2287.deadGroupMemberData, AI.GetGroupScriptTable(L1_2288).deadGroupMemberData, 1)
end
function Human_x.GetDistanceToDeadBody(A0_2289)
  local L1_2290
  L1_2290 = DistanceVectors
  return L1_2290(A0_2289.deadGroupMemberData.currentBodyPosition, A0_2289:GetWorldPos())
end
function Human_x.IsTargetInNearbyRange(A0_2291)
  if AI.GetAttentionTargetDistance(A0_2291.id) <= A0_2291.gameParams.nearbyRange then
    return true
  end
  return false
end
function Human_x.IsTargetInMiddleRange(A0_2292)
  if AI.GetAttentionTargetDistance(A0_2292.id) <= A0_2292.gameParams.middleRange then
    return true
  end
  return false
end
