Script.ReloadScript("SCRIPTS/Entities/AI/Shared/AIBase.lua")
ArkHumanTest_x = {
  ActionController = "Animations/Mannequin/ADB/ArkHumanTestControllerDef.xml",
  AnimDatabase3P = "Animations/Mannequin/ADB/ArkHumanTest.adb",
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
    stopFollowingDist = 2,
    followAtWalkSpeedDist = 5,
    followAtRunSpeedDist = 15,
    followAtSprintSpeedDist = 100,
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
        name = "stand",
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
      sightEnvScaleNormal = 0.2,
      sightEnvScaleAlarmed = 1,
      cloakMaxDistCrouchedAndMoving = 1.5,
      cloakMaxDistCrouchedAndStill = 1.3,
      cloakMaxDistMoving = 3,
      cloakMaxDistStill = 2,
      config = "Human"
    },
    useSpecialMovementTransitions = 1,
    bOverrideAllowLookAimStrafing = 1,
    fileModel = "Objects/Characters/Test_Biped/Biped.cdf",
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
    }
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
  OnCustomKill = function(A0_2035)
    if AIBase.OnCustomKill then
      AIBase.OnCustomKill(A0_2035)
    end
    if not A0_2035.Properties.AI.bPlayDeathSound or A0_2035.Properties.AI.sndDeathSound ~= "" then
    end
  end,
  OnGrenadeDanger = function(A0_2036, A1_2037, A2_2038)
    A0_2036.lastImmediateThreatPos = A2_2038.point
  end,
  OnExposedToExplosion = function(A0_2039, A1_2040, A2_2041)
    A0_2039.lastImmediateThreatPos = A2_2041.point
  end,
  OnScorcherExplosionDanger = function(A0_2042, A1_2043, A2_2044)
    A0_2042.lastImmediateThreatPos = A2_2044.point
  end,
  OnWaterRippleSeen = function(A0_2045, A1_2046, A2_2047)
    local L3_2048
    L3_2048 = A0_2045.AI
    L3_2048.lastWaterRipplePosition = A2_2047.point
    L3_2048 = g_Vectors
    L3_2048 = L3_2048.temp_v1
    A0_2045:GetWorldPos(L3_2048)
    if DistanceVectors(L3_2048, A0_2045.AI.lastWaterRipplePosition) < 15 then
      AI.Signal(SIGNALFILTER_SENDER, 1, "OnNearbyWaterRippleSeen", A0_2045.id)
    end
  end,
  OnEMPGrenadeThrown = function(A0_2049, A1_2050, A2_2051)
    AI.Signal(SIGNALFILTER_GROUPONLY, 1, "EMPGrenadeThrownInGroup", A0_2049.id)
    if A0_2049:HasGroupMembersNearby() then
      AI.PlayCommunication(A0_2049.id, "ThrowEMP", "Group", 2)
    end
  end,
  OnSmokeGrenadeThrown = function(A0_2052, A1_2053, A2_2054)
    AI.Signal(SIGNALFILTER_GROUPONLY, 1, "SmokeGrenadeThrownInGroup", A0_2052.id)
    if A0_2052:HasGroupMembersNearby() then
      AI.PlayCommunication(A0_2052.id, "ThrowSmoke", "Group", 2)
    end
  end,
  OnFragGrenadeThrown = function(A0_2055, A1_2056, A2_2057)
    AI.Signal(SIGNALFILTER_GROUPONLY, 1, "FragGrenadeThrownInGroup", A0_2055.id)
    if A0_2055:HasGroupMembersNearby() then
      AI.PlayCommunication(A0_2055.id, "ThrowFrag", "Group", 2)
    end
  end,
  OccupyAdvantagePoint = function(A0_2058)
    local L1_2059
    L1_2059 = A0_2058.ReleaseAdvantagePoint
    L1_2059(A0_2058)
    L1_2059 = AI
    L1_2059 = L1_2059.GetRefPointPosition
    L1_2059 = L1_2059(A0_2058.id)
    if not L1_2059 then
      return
    end
    A0_2058.occupiedAdvantagePointPosition = L1_2059
    GameAI.OccupyAdvantagePoint(A0_2058.id, L1_2059)
  end,
  ReleaseAdvantagePoint = function(A0_2060)
    if not A0_2060.occupiedAdvantagePointPosition then
      return
    end
    GameAI.ReleaseAdvantagePointFor(A0_2060.id, A0_2060.occupiedAdvantagePointPosition)
    A0_2060.occupiedAdvantagePointPosition = nil
  end,
  GroupMemberDied = function(A0_2061)
    local L1_2062
    L1_2062 = A0_2061.deadGroupMemberCount
    if L1_2062 == nil then
      A0_2061.deadGroupMemberCount = 1
    else
      L1_2062 = A0_2061.deadGroupMemberCount
      L1_2062 = L1_2062 + 1
      A0_2061.deadGroupMemberCount = L1_2062
    end
  end,
  GetDeadGroupMemberCount = function(A0_2063)
    return A0_2063.deadGroupMemberCount or 0
  end,
  IsAlone = function(A0_2064)
    return AI.GetDistanceToClosestGroupMember(A0_2064.id) > 50
  end,
  HasGroupMembersNearby = function(A0_2065)
    return not A0_2065:IsAlone()
  end,
  WatchedMateDie = function(A0_2066)
    local L1_2067, L2_2068
    L1_2067 = System
    L1_2067 = L1_2067.GetEntity
    L2_2068 = A0_2066.deadGroupMemberData
    L2_2068 = L2_2068.victimID
    L1_2067 = L1_2067(L2_2068)
    L2_2068 = ""
    if L1_2067 and L1_2067.deathProjectileClassId then
      L2_2068 = CryAction.GetClassName(L1_2067.deathProjectileClassId)
    end
    if L2_2068 == "LTagGrenade" then
      AI.PlayCommunication(A0_2066.id, "NoticePlayerUsingLtag", "EnemyWeaponComment", 3)
    elseif L2_2068 == "SniperBullet" or L2_2068 == "GaussBullet" then
      AI.PlayCommunication(A0_2066.id, "NoticePlayerUsingDSG1", "EnemyWeaponComment", 3)
    elseif L2_2068 == "rocket" then
      AI.PlayCommunication(A0_2066.id, "NoticePlayerUsingJaw", "EnemyWeaponComment", 3)
    elseif AI.GetAlertness(A0_2066.id) >= 2 then
      AI.PlayCommunication(A0_2066.id, "AwareOfTargetAndWitnessedMateDie", "DeadGroupMemberComment", 3)
    end
  end,
  OnGroupMemberDiedOnHMG = function(A0_2069)
    AI.PlayCommunication(A0_2069.id, "NoticeMateDiedOnMountedGun", "Group", 2)
  end
}
mergef(ArkHumanTest_x, AIBase, 1)
function ArkHumanTest_x.OnResetCustom(A0_2070)
  GameAI.UnregisterWithAllModules(A0_2070.id)
  A0_2070.AI.mountedWeaponCheck = true
  if A0_2070.Properties.AI.bUseRadioChatter == 1 then
    GameAI.RegisterWithModule("RadioChatter", A0_2070.id)
  end
  GameAI.RegisterWithModule("BattleFront", A0_2070.id)
  GameAI.RegisterWithModule("StalkerModule", A0_2070.id)
  GameAI.RegisterWithModule("RangeModule", A0_2070.id)
  GameAI.AddRange(A0_2070.id, 2.5, "OnTargetEnteredMeleeRange", "")
  GameAI.AddRange(A0_2070.id, 3, "", "OnTargetLeftMeleeRange")
  GameAI.AddRange(A0_2070.id, A0_2070.gameParams.nearbyRange, "OnTargetEnteredNearbyRange", "OnTargetLeftNearbyRange")
  GameAI.AddRange(A0_2070.id, A0_2070.gameParams.middleRange, "OnTargetEnteredMiddleRange", "OnTargetEnteredMiddleRange")
  GameAI.AddRange(A0_2070.id, A0_2070.gameParams.stopFollowDist, "OnTargetEnteredFollowStopRange", "OnTargetExitedFollowStopRange")
  GameAI.AddRange(A0_2070.id, A0_2070.gameParams.followAtWalkSpeedDist, "OnTargetEnteredFollowWalkRange", "OnTargetExitedFollowWalkRange")
  GameAI.AddRange(A0_2070.id, A0_2070.gameParams.followAtRunSpeedDist, "OnTargetEnteredFollowRunRange", "OnTargetExitedFollowRunRange")
  GameAI.AddRange(A0_2070.id, A0_2070.gameParams.followAtSprintSpeedDist, "OnTargetEnteredFollowSprintRange", "OnTargetExitedFollowSprintRange")
  GameAI.AddRange(A0_2070.id, 8, "EnteredTooCloseForComfortRange", "LeftTooCloseForComfortRange")
  if A0_2070.Properties.AIBehaviorFlags.bSniper == 1 then
    GameAI.AddRange(A0_2070.id, 10, "OnTargetEnteredCloseRange", "")
    GameAI.AddRange(A0_2070.id, 12, "", "OnTargetLeftCloseRange")
  end
  if A0_2070.Properties.AIBehaviorFlags.bGrenadier == 1 then
    GameAI.AddRange(A0_2070.id, 20, "OnTargetEnteredCloseRange", "")
    GameAI.AddRange(A0_2070.id, 22, "", "OnTargetLeftCloseRange")
  end
  A0_2070.lastImmediateThreatPos = {
    x = 0,
    y = 0,
    z = 0
  }
  A0_2070.deadGroupMemberCount = 0
  A0_2070.suspiciousSoundInvestigationCount = 0
end
function ArkHumanTest_x.EnableSearchModule(A0_2071)
  local L1_2072, L2_2073, L3_2074
  L1_2072 = AI
  L1_2072 = L1_2072.GetGroupOf
  L2_2073 = A0_2071.id
  L1_2072 = L1_2072(L2_2073)
  L2_2073 = g_Vectors
  L2_2073 = L2_2073.temp_v1
  L3_2074 = AI
  L3_2074 = L3_2074.GetAttentionTargetPosition
  L3_2074 = L3_2074(A0_2071.id, L2_2073)
  if L3_2074 then
    L3_2074 = NULL_ENTITY
    if AI.GetAttentionTargetEntity(A0_2071.id) then
      L3_2074 = AI.GetAttentionTargetEntity(A0_2071.id).id
    end
    GameAI.StartSearchModuleFor(L1_2072, L2_2073, L3_2074, 45)
    GameAI.RegisterWithModule("SearchModule", A0_2071.id)
    A0_2071:Log("Started search module for my group.")
  else
    L3_2074 = A0_2071.Error
    L3_2074(A0_2071, "No attention target to search for")
  end
end
function ArkHumanTest_x.SetNextSearchSpotToRefPoint(A0_2075)
  local L1_2076
  L1_2076 = GameAI
  L1_2076 = L1_2076.GetNextSearchSpot
  L1_2076 = L1_2076(A0_2075.id, 0.6, 0.3, 15, 0.1)
  if L1_2076 then
    AI.SetRefPointPosition(A0_2075.id, L1_2076)
  else
    AI.Signal(SIGNALFILTER_SENDER, 1, "NoSearchSpotsAvailable", A0_2075.id)
  end
end
function ArkHumanTest_x.DisableSearchModule(A0_2077)
  GameAI.UnregisterWithModule("SearchModule", A0_2077.id)
end
function ArkHumanTest_x.OnPostLoad(A0_2078)
  A0_2078:OnResetCustom()
  BasicActor.OnPostLoad(A0_2078)
end
function ArkHumanTest_x.SetHoldGroundMoveSpeed(A0_2079)
  local L1_2080
  L1_2080 = g_Vectors
  L1_2080 = L1_2080.temp_v1
  A0_2079:GetWorldPos(L1_2080)
  if DistanceVectors(L1_2080, A0_2079.AI.HoldGround.pos) > 10 or math.abs(L1_2080.z - A0_2079.AI.HoldGround.pos.z) > 1 then
    AI.SetSpeed(A0_2079.id, SPEED_RUN)
  else
    AI.SetSpeed(A0_2079.id, SPEED_WALK)
  end
end
function ArkHumanTest_x.DoPainSounds(A0_2081, A1_2082, A2_2083, A3_2084)
  if g_gameRules:IsStealthHealthHit(A2_2083) then
    return
  end
  if A1_2082 then
    if A0_2081.doHeadShotReadability then
      AI.PlayCommunication(A0_2081.id, "comm_headshot_death", "Injury", 0.5)
      A0_2081.doHeadShotReadability = false
    elseif A2_2083 == "stickyArrow" then
      AI.PlayCommunication(A0_2081.id, "comm_headshot_death", "Injury", 0.5)
    elseif A2_2083 == "meleeLeft" or A2_2083 == "meleeRight" then
      if AI.GetAlertness(A0_2081.id) > 0 == false then
        AI.PlayCommunication(A0_2081.id, "comm_headshot_death", "Injury", 0.5)
      else
        AI.PlayCommunication(A0_2081.id, "comm_death_melee", "Injury", 0.5)
      end
    elseif A2_2083 == "silentMelee" then
      AI.PlayCommunication(A0_2081.id, "comm_headshot_death", "Injury", 0.5)
    elseif A3_2084 == true then
      AI.PlayCommunication(A0_2081.id, "comm_headshot_death", "Injury", 0.5)
    else
      AI.PlayCommunication(A0_2081.id, "comm_death", "Injury", 0.5)
    end
  elseif A2_2083 == "silentMelee" then
    return
  else
    AI.PlayCommunication(A0_2081.id, "comm_pain", "InjuryPain", 0.5)
  end
end
function ArkHumanTest_x.EnableBlindFire(A0_2085, A1_2086)
  if A1_2086 then
    AI.SetPosturePriority(A0_2085.id, "BlindLowCoverAim", 10)
    AI.SetPosturePriority(A0_2085.id, "BlindHighCoverAim", 10)
  else
    AI.SetPosturePriority(A0_2085.id, "BlindLowCoverAim", 0)
    AI.SetPosturePriority(A0_2085.id, "BlindHighCoverAim", 0)
  end
end
function ArkHumanTest_x.CheckForMountedWeapons(A0_2087)
  if A0_2087:FindValidMountedWeapon() then
    A0_2087.AI.targetMountedWeapon = A0_2087:FindValidMountedWeapon()
    AI.SetBehaviorVariable(A0_2087.id, "GoToMountedWeapon", true)
    return true
  else
    return false
  end
end
function ArkHumanTest_x.FindValidMountedWeapon(A0_2088)
  local L1_2089
  L1_2089 = AI
  L1_2089 = L1_2089.FindObjectOfType
  L1_2089 = L1_2089(A0_2088:GetPos(), 10, AIOBJECT_MOUNTEDWEAPON)
  if L1_2089 and System.GetEntityByName(L1_2089) and not System.GetEntityByName(L1_2089).inUse and Game.IsMountedWeaponUsableWithTarget(A0_2088.id, System.GetEntityByName(L1_2089).id) then
    return (System.GetEntityByName(L1_2089))
  end
end
function ArkHumanTest_x.OnUseMountedWeaponRequest(A0_2090, A1_2091)
  A0_2090:PrepareForMountedWeaponUse(A1_2091)
end
function ArkHumanTest_x.PrepareForMountedWeaponUse(A0_2092, A1_2093, A2_2094)
  local L3_2095, L4_2096, L5_2097, L6_2098, L7_2099
  if A1_2093 then
    L4_2096 = System
    L4_2096 = L4_2096.GetEntity
    L5_2097 = A1_2093
    L4_2096 = L4_2096(L5_2097)
    L3_2095 = L4_2096
  else
  end
  if not L3_2095 then
    L4_2096 = false
    return L4_2096
  end
  L4_2096 = L3_2095.item
  L5_2097 = L4_2096
  L4_2096 = L4_2096.IsUsed
  L4_2096 = L4_2096(L5_2097)
  if L4_2096 then
    L4_2096 = L3_2095.item
    L5_2097 = L4_2096
    L4_2096 = L4_2096.GetOwnerId
    L4_2096 = L4_2096(L5_2097)
    L5_2097 = A0_2092.id
    if L4_2096 ~= L5_2097 then
      L4_2096 = false
      return L4_2096
    end
  end
  L4_2096 = g_Vectors
  L4_2096 = L4_2096.temp_v1
  L5_2097 = L3_2095.item
  L6_2098 = L5_2097
  L5_2097 = L5_2097.GetMountedDir
  L7_2099 = g_Vectors
  L7_2099 = L7_2099.temp_v2
  L5_2097 = L5_2097(L6_2098, L7_2099)
  L7_2099 = L3_2095
  L6_2098 = L3_2095.GetWorldPos
  L6_2098 = L6_2098(L7_2099, g_Vectors.temp_v3)
  L7_2099 = FastDifferenceVectors
  L7_2099(L4_2096, L6_2098, L5_2097)
  L7_2099 = g_Vectors
  L7_2099 = L7_2099.temp_v4
  L7_2099.x = 0
  L7_2099.y = 0
  L7_2099.z = -2
  if 0 < Physics.RayWorldIntersection(L4_2096, L7_2099, 2, ent_terrain + ent_static + ent_rigid + ent_sleeping_rigid, A0_2092.id, nil, g_HitTable) then
    L4_2096.z = g_HitTable[1].pos.z
  end
  AI.SetRefPointPosition(A0_2092.id, L4_2096)
  AI.SetRefPointDirection(A0_2092.id, L5_2097)
  A0_2092.AI.currentMountedWeaponId = A1_2093
  A0_2092.AI.currentMountedWeaponInitialDir = L5_2097
  A0_2092.AI.currentMountedWeaponPivot = L6_2098
  L3_2095.inUse = true
  if not A0_2092.AI.theVehicle and not A0_2092.AI.usingMountedWeapon then
    AI.SetBehaviorVariable(A0_2092.id, "MovingToMountedWeapon", true)
  else
    return false
  end
  return true
end
function ArkHumanTest_x.ForceReleaseOfMountedGun(A0_2100)
  A0_2100:LeaveMountedWeapon()
end
function ArkHumanTest_x.SetMachineGunInitialDirInRefPoint(A0_2101)
  if A0_2101.AI.currentMountedWeaponInitialDir ~= nil and A0_2101.AI.currentMountedWeaponPivot ~= nil then
    AI.SetRefPointPosition(A0_2101.id, A0_2101.AI.currentMountedWeaponPivot)
    AI.SetRefPointDirection(A0_2101.id, A0_2101.AI.currentMountedWeaponInitialDir)
  end
end
function ArkHumanTest_x.UseMountedWeapon(A0_2102)
  local L1_2103, L2_2104, L3_2105, L4_2106, L5_2107, L6_2108, L7_2109
  L1_2103 = A0_2102.AI
  L1_2103 = L1_2103.targetMountedWeapon
  if L1_2103 then
    L1_2103 = A0_2102.AI
    L1_2103 = L1_2103.targetMountedWeapon
    L1_2103.inUse = true
  end
  L1_2103 = A0_2102.AI
  L1_2103 = L1_2103.currentMountedWeaponId
  if not L1_2103 then
    return
  end
  L2_2104 = A0_2102.AI
  L3_2105 = AI
  L3_2105 = L3_2105.GetParameter
  L4_2106 = A0_2102.id
  L5_2107 = AIPARAM_FIRE_TURNSPEED
  L3_2105 = L3_2105(L4_2106, L5_2107)
  L2_2104.oldFireTurnSpeed = L3_2105
  L2_2104 = AI
  L2_2104 = L2_2104.ChangeParameter
  L3_2105 = A0_2102.id
  L4_2106 = AIPARAM_FIRE_TURNSPEED
  L5_2107 = 35
  L2_2104(L3_2105, L4_2106, L5_2107)
  L2_2104 = A0_2102.Properties
  L2_2104 = L2_2104.Perception
  L3_2105 = L2_2104.sightrange
  L4_2106 = AI
  L4_2106 = L4_2106.ChangeParameter
  L5_2107 = A0_2102.id
  L6_2108 = AIPARAM_ACCURACY
  L7_2109 = 1
  L4_2106(L5_2107, L6_2108, L7_2109)
  L4_2106 = AI
  L4_2106 = L4_2106.ChangeParameter
  L5_2107 = A0_2102.id
  L6_2108 = AIPARAM_SIGHTRANGE
  L7_2109 = L3_2105
  L4_2106(L5_2107, L6_2108, L7_2109)
  L4_2106 = AI
  L4_2106 = L4_2106.ChangeParameter
  L5_2107 = A0_2102.id
  L6_2108 = AIPARAM_ATTACKRANGE
  L7_2109 = L3_2105
  L4_2106(L5_2107, L6_2108, L7_2109)
  L4_2106 = AI
  L4_2106 = L4_2106.ChangeParameter
  L5_2107 = A0_2102.id
  L6_2108 = AIPARAM_FOVPRIMARY
  L7_2109 = 320
  L4_2106(L5_2107, L6_2108, L7_2109)
  L4_2106 = AI
  L4_2106 = L4_2106.ChangeParameter
  L5_2107 = A0_2102.id
  L6_2108 = AIPARAM_FOVSECONDARY
  L7_2109 = 330
  L4_2106(L5_2107, L6_2108, L7_2109)
  L4_2106 = System
  L4_2106 = L4_2106.GetEntity
  L5_2107 = L1_2103
  L4_2106 = L4_2106(L5_2107)
  if L4_2106 then
    L6_2108 = A0_2102
    L5_2107 = A0_2102.GetDistance
    L7_2109 = L4_2106.id
    L5_2107 = L5_2107(L6_2108, L7_2109)
    if L5_2107 < 3 then
      L5_2107 = A0_2102.actor
      L6_2108 = L5_2107
      L5_2107 = L5_2107.HolsterItem
      L7_2109 = true
      L5_2107(L6_2108, L7_2109)
      L5_2107 = L4_2106.item
      L6_2108 = L5_2107
      L5_2107 = L5_2107.IsUsed
      L5_2107 = L5_2107(L6_2108)
      if not L5_2107 then
        L5_2107 = L4_2106.item
        L6_2108 = L5_2107
        L5_2107 = L5_2107.StartUse
        L7_2109 = A0_2102.id
        L5_2107(L6_2108, L7_2109)
        L5_2107 = g_Vectors
        L5_2107 = L5_2107.temp_v1
        L6_2108 = L4_2106.item
        L7_2109 = L6_2108
        L6_2108 = L6_2108.GetMountedDir
        L6_2108 = L6_2108(L7_2109, g_Vectors.temp_v2)
        L7_2109 = L4_2106.GetWorldPos
        L7_2109 = L7_2109(L4_2106, g_Vectors.temp_v3)
        FastSumVectors(L5_2107, L7_2109, L6_2108)
        FastSumVectors(L5_2107, L5_2107, L6_2108)
        AI.SetRefPointPosition(A0_2102.id, L5_2107)
        AI.SetRefPointDirection(A0_2102.id, L6_2108)
        A0_2102.AI.usingMountedWeapon = true
        if L4_2106.class == "HMG" then
          AI.PlayCommunication(A0_2102.id, "AIUsesMountedGun", "Group", 3)
        elseif L4_2106.class == "AGL" then
          AI.PlayCommunication(A0_2102.id, "AIUsesAGL", "Group", 3)
        end
      end
    else
      L6_2108 = A0_2102
      L5_2107 = A0_2102.DrawWeaponNow
      L5_2107(L6_2108)
    end
  end
end
function ArkHumanTest_x.LeaveMountedWeapon(A0_2110)
  local L1_2111
  L1_2111 = A0_2110.AI
  L1_2111 = L1_2111.targetMountedWeapon
  if L1_2111 then
    L1_2111 = A0_2110.AI
    L1_2111 = L1_2111.targetMountedWeapon
    L1_2111.inUse = false
  end
  L1_2111 = A0_2110.AI
  L1_2111 = L1_2111.currentMountedWeaponId
  if not L1_2111 then
    return
  end
  A0_2110.AI.currentMountedWeaponId = nil
  A0_2110.AI.currentMountedWeaponInitialDir = nil
  A0_2110.AI.currentMountedWeaponPivot = nil
  if System.GetEntity(L1_2111) then
    System.GetEntity(L1_2111).inUse = false
  else
    A0_2110:OnError("(LeaveMountedWeapon) No weapon entity?")
    return
  end
  A0_2110.AI.usingMountedWeapon = nil
  AI.ChangeParameter(A0_2110.id, AIPARAM_FIRE_TURNSPEED, A0_2110.AI.oldFireTurnSpeed)
  AI.ChangeParameter(A0_2110.id, AIPARAM_ACCURACY, 1)
  AI.ChangeParameter(A0_2110.id, AIPARAM_SIGHTRANGE, A0_2110.Properties.Perception.sightrange)
  AI.ChangeParameter(A0_2110.id, AIPARAM_ATTACKRANGE, A0_2110.Properties.Perception.attackrange)
  AI.ChangeParameter(A0_2110.id, AIPARAM_FOVPRIMARY, A0_2110.Properties.Perception.FOVPrimary)
  AI.ChangeParameter(A0_2110.id, AIPARAM_FOVSECONDARY, A0_2110.Properties.Perception.FOVSecondary)
  if System.GetEntity(L1_2111) then
    System.GetEntity(L1_2111).item:StopUse(A0_2110.id)
    A0_2110.actor:HolsterItem(false)
  end
end
function ArkHumanTest_x.CanShootMountedWeapon(A0_2112)
  if AI.GetTargetType(A0_2112.id) ~= AITARGET_ENEMY and AI.GetTargetType(A0_2112.id) ~= AITARGET_MEMORY and AI.GetTargetType(A0_2112.id) ~= AITARGET_SOUND then
    return false
  end
  if not A0_2112.AI.currentMountedWeaponId then
    return false
  end
  if not System.GetEntity(A0_2112.AI.currentMountedWeaponId) or not Game.IsMountedWeaponUsableWithTarget(A0_2112.id, System.GetEntity(A0_2112.AI.currentMountedWeaponId).id, 0) then
    return false
  end
  return true
end
function ArkHumanTest_x.CheckMountedWeaponTarget(A0_2113)
  if A0_2113.AI.mountedWeaponCheck == false then
    return
  end
  if A0_2113.actor:GetLinkedVehicleId() then
    return
  end
  if AI.GetTargetType(A0_2113.id) == AITARGET_MEMORY or AI.GetTargetType(A0_2113.id) == AITARGET_SOUND then
    if 10 > AI.GetAttentionTargetDistance(A0_2113.id) then
      A0_2113:Log("CheckMountedWeaponTarget - dist < cutoff... leaving")
      AI.Signal(SIGNALFILTER_SENDER, 1, "LeaveMountedWeapon", A0_2113.id)
    end
  elseif AI.GetTargetType(A0_2113.id) == AITARGET_ENEMY and not A0_2113:CanShootMountedWeapon() then
    A0_2113:Log("CheckMountedWeaponTarget - CanShootMountedWeapon is false... leaving")
    AI.Signal(SIGNALFILTER_SENDER, 1, "LeaveMountedWeapon", A0_2113.id)
  end
end
function ArkHumanTest_x.IsTargetAnEnemy(A0_2114)
  return AI.GetTargetType(A0_2114.id) == AITARGET_ENEMY
end
function ArkHumanTest_x.MountedWeaponTargetChange(A0_2115)
  if AI.GetTargetType(A0_2115.id) == AITARGET_ENEMY then
    A0_2115:SelectPipe(0, "FireMountedWeapon")
  else
    A0_2115:SelectPipe(0, "LookAroundInMountedWeapon")
    if A0_2115.AI.theVehicle then
      A0_2115:InsertSubpipe(AIGOALPIPE_NOTDUPLICATE, "FireSecondaryMountedWeapon")
    end
  end
end
function ArkHumanTest_x.GetUsable(A0_2116)
  if not A0_2116:IsDead() then
    ({}).ActionType = "ScriptDefined"
    ;({}).Use, ({}).DisplayText = {}, "@use_object"
  end
  return {}
end
function ArkHumanTest_x.AnimationEvent(A0_2117, A1_2118, A2_2119)
  if A1_2118 == "StealthMeleeDeath" then
    AI.PlayCommunication(A0_2117.id, "comm_death_melee_stealth", "Injury", 0.5)
  elseif BasicAI.AnimationEvent then
    BasicAI.AnimationEvent(A0_2117, A1_2118, A2_2119)
  end
end
function ArkHumanTest_x.IsFurthestAwayFromTargetInSquad(A0_2120)
  local L1_2121, L2_2122, L3_2123, L4_2124
  L1_2121 = GameAI
  L1_2121 = L1_2121.GetSquadId
  L2_2122 = A0_2120.id
  L1_2121 = L1_2121(L2_2122)
  if L1_2121 == nil then
    L3_2123 = A0_2120
    L2_2122 = A0_2120.Error
    L4_2124 = "IsFurthestAwayFromTargetInSquad: Squad ID is nil"
    L2_2122(L3_2123, L4_2124)
    L2_2122 = true
    return L2_2122
  end
  L2_2122 = GameAI
  L2_2122 = L2_2122.GetSquadMembers
  L3_2123 = L1_2121
  L2_2122 = L2_2122(L3_2123)
  if L2_2122 == nil then
    L4_2124 = A0_2120
    L3_2123 = A0_2120.Error
    L3_2123(L4_2124, "IsFurthestAwayFromTargetInSquad: Squad doesn't have any members (members is nil)")
    L3_2123 = true
    return L3_2123
  end
  L3_2123 = A0_2120.id
  L4_2124 = 0
  for _FORV_8_, _FORV_9_ in pairs(L2_2122) do
    if L4_2124 < (AI.GetAttentionTargetDistance(_FORV_9_.id) or 500) then
      L4_2124, L3_2123 = AI.GetAttentionTargetDistance(_FORV_9_.id) or 500, _FORV_9_.id
    end
  end
  if L3_2123 == A0_2120.id then
    return true
  else
    return false
  end
end
function ArkHumanTest_x.IsFurtherAwayFromTargetThanAveragePositionOfSquadScopeUsers(A0_2125, A1_2126)
  local L2_2127, L3_2128, L4_2129
  L2_2127 = g_Vectors
  L2_2127 = L2_2127.temp_v1
  L3_2128 = AI
  L3_2128 = L3_2128.GetAttentionTargetPosition
  L4_2129 = A0_2125.id
  L3_2128 = L3_2128(L4_2129, L2_2127)
  if not L3_2128 then
    L3_2128 = true
    return L3_2128
  end
  L3_2128 = GameAI
  L3_2128 = L3_2128.GetSquadScopeUserCount
  L4_2129 = A0_2125.id
  L3_2128 = L3_2128(L4_2129, A1_2126)
  if L3_2128 < 2 then
    L3_2128 = true
    return L3_2128
  end
  L3_2128 = GameAI
  L3_2128 = L3_2128.GetAveragePositionOfSquadScopeUsers
  L4_2129 = A0_2125.id
  L3_2128 = L3_2128(L4_2129, A1_2126)
  L4_2129 = IsNullVector
  L4_2129 = L4_2129(L3_2128)
  if L4_2129 then
    L4_2129 = true
    return L4_2129
  end
  L4_2129 = A0_2125.GetWorldPos
  L4_2129 = L4_2129(A0_2125, g_Vectors.temp_v2)
  if DistanceSqVectors(L3_2128, L2_2127) < DistanceSqVectors(L4_2129, L2_2127) then
    return true
  else
    return false
  end
end
function ArkHumanTest_x.IsClosestToTargetInSquad(A0_2130)
  local L1_2131, L2_2132, L3_2133, L4_2134
  L1_2131 = GameAI
  L1_2131 = L1_2131.GetSquadId
  L2_2132 = A0_2130.id
  L1_2131 = L1_2131(L2_2132)
  if L1_2131 == nil then
    L3_2133 = A0_2130
    L2_2132 = A0_2130.Error
    L4_2134 = "IsCloserFromTargetInSquad: Squad ID is nil"
    L2_2132(L3_2133, L4_2134)
    L2_2132 = true
    return L2_2132
  end
  L2_2132 = GameAI
  L2_2132 = L2_2132.GetSquadMembers
  L3_2133 = L1_2131
  L2_2132 = L2_2132(L3_2133)
  if L2_2132 == nil then
    L4_2134 = A0_2130
    L3_2133 = A0_2130.Error
    L3_2133(L4_2134, "IsCloserFromTargetInSquad: Squad doesn't have any members (members is nil)")
    L3_2133 = true
    return L3_2133
  end
  L3_2133 = A0_2130.id
  L4_2134 = 1000
  for _FORV_8_, _FORV_9_ in pairs(L2_2132) do
    if _FORV_9_ ~= nil and _FORV_9_:IsActive() and not _FORV_9_:IsDead() then
      if L4_2134 >= (AI.GetAttentionTargetDistance(_FORV_9_.id) or 500) then
        L4_2134, L3_2133 = AI.GetAttentionTargetDistance(_FORV_9_.id) or 500, _FORV_9_.id
      end
    end
  end
  if L3_2133 == A0_2130.id then
    return true
  else
    return false
  end
end
function ArkHumanTest_x.IsClosestToTargetInGroup(A0_2135)
  local L1_2136, L2_2137, L3_2138, L4_2139, L5_2140, L6_2141, L7_2142
  L1_2136 = A0_2135.id
  L2_2137 = 1000
  L3_2138 = AI
  L3_2138 = L3_2138.GetGroupCount
  L3_2138 = L3_2138(L4_2139)
  for L7_2142 = 1, L3_2138 do
    if AI.GetGroupMember(A0_2135.id, L7_2142) ~= nil and AI.GetGroupMember(A0_2135.id, L7_2142):IsActive() and not AI.GetGroupMember(A0_2135.id, L7_2142):IsDead() then
      if L2_2137 >= (AI.GetAttentionTargetDistance(AI.GetGroupMember(A0_2135.id, L7_2142).id) or 500) then
        L2_2137, L1_2136 = AI.GetAttentionTargetDistance(AI.GetGroupMember(A0_2135.id, L7_2142).id) or 500, AI.GetGroupMember(A0_2135.id, L7_2142).id
      end
    end
  end
  if L1_2136 == L4_2139 then
    return L4_2139
  else
    return L4_2139
  end
end
function ArkHumanTest_x.IsInRangeFromTarget(A0_2143, A1_2144)
  if A1_2144 and A1_2144 >= (AI.GetAttentionTargetDistance(A0_2143.id) or 500) then
    return true
  end
  return false
end
function ArkHumanTest_x.GetTargetDistance(A0_2145)
  return AI.GetAttentionTargetDistance(A0_2145.id) or 500
end
function ArkHumanTest_x.SetLastExplosiveTypeAsGrenade(A0_2146)
  local L1_2147
  A0_2146.lastExplosiveType = "grenade"
  L1_2147 = true
  return L1_2147
end
function ArkHumanTest_x.SetLastExplosiveTypeAsExplosive(A0_2148)
  local L1_2149
  A0_2148.lastExplosiveType = "explosive"
  L1_2149 = true
  return L1_2149
end
function ArkHumanTest_x.ClearCombatMoveAssignmentIfCloseToTheDestination(A0_2150)
  if DistanceSqVectors(A0_2150:GetWorldPos(), A0_2150.AI.combatMove.position) < 25 then
    A0_2150:ClearAssignment()
  end
end
function ArkHumanTest_x.ShouldUseGrenade(A0_2151)
  local L1_2152, L2_2153
  L1_2152 = AI
  L1_2152 = L1_2152.GetAttentionTargetEntity
  L2_2153 = A0_2151.id
  L1_2152 = L1_2152(L2_2153)
  L2_2153 = A0_2151.ValidateAttentionTarget
  L2_2153 = L2_2153(A0_2151, L1_2152)
  if not L2_2153 then
    L2_2153 = false
    return L2_2153
  end
  L2_2153 = g_Vectors
  L2_2153 = L2_2153.temp_v3
  SubVectors(L2_2153, L1_2152:GetWorldPos(), A0_2151:GetWorldPos())
  NormalizeVector(L2_2153)
  if dotproduct2d(A0_2151:GetDirectionVector(), L2_2153) > math.cos(math.rad(A0_2151.gameParams.grenadeThrowMaxAngle)) then
    if A0_2151.gameParams.grenadeLaunchProbability and random(0, 1) <= A0_2151.gameParams.grenadeLaunchProbability then
      return true
    else
      return false
    end
  end
end
function ArkHumanTest_x.RefreshCurrentDeadGroupMemberBodyPosition(A0_2154)
  if A0_2154.deadGroupMemberData == nil then
    A0_2154:Error("RefreshCurrentDeadGroupMemberBodyPosition expected the 'dead group member data' to exist but it didn't.")
    return
  end
  if System.GetEntity(A0_2154.deadGroupMemberData.victimID) then
    CopyVector(A0_2154.deadGroupMemberData.currentBodyPosition, System.GetEntity(A0_2154.deadGroupMemberData.victimID):GetWorldPos())
  end
end
function ArkHumanTest_x.SetDeadGroupMemberBodyPositionAsRefPoint(A0_2155)
  if A0_2155.deadGroupMemberData == nil then
    A0_2155:Error("SetDeadGroupMemberPositionAsRefPoint expected the 'dead group member data' to exist but it didn't.")
    return false
  end
  AI.SetRefPointPosition(A0_2155.id, A0_2155.deadGroupMemberData.currentBodyPosition)
  return true
end
function ArkHumanTest_x.SetDeadGroupMemberDeathPositionAsRefPoint(A0_2156)
  if A0_2156.deadGroupMemberData == nil then
    A0_2156:Error("SetDeadGroupMemberDeathPositionAsRefPoint expected the 'dead group member data' to exist but it didn't.")
    return false
  end
  AI.SetRefPointPosition(A0_2156.id, A0_2156.deadGroupMemberData.deathPosition)
  return true
end
function ArkHumanTest_x.GrabDeadGroupMemberDataFromGroupScriptTable(A0_2157)
  local L1_2158
  L1_2158 = AI
  L1_2158 = L1_2158.GetGroupOf
  L1_2158 = L1_2158(A0_2157.id)
  assert(AI.GetGroupScriptTable(L1_2158) ~= nil)
  if AI.GetGroupScriptTable(L1_2158) == nil then
    A0_2157:Error("group == nil in GrabDeadGroupMemberDataFromGroupScriptTable")
    return
  end
  if AI.GetGroupScriptTable(L1_2158).deadGroupMemberData == nil then
    A0_2157:Error("group.deadGroupMemberData == nil in GrabDeadGroupMemberDataFromGroupScriptTable")
    return
  end
  A0_2157.deadGroupMemberData = {}
  mergef(A0_2157.deadGroupMemberData, AI.GetGroupScriptTable(L1_2158).deadGroupMemberData, 1)
end
function ArkHumanTest_x.GetDistanceToDeadBody(A0_2159)
  local L1_2160
  L1_2160 = DistanceVectors
  return L1_2160(A0_2159.deadGroupMemberData.currentBodyPosition, A0_2159:GetWorldPos())
end
function ArkHumanTest_x.IsTargetInNearbyRange(A0_2161)
  if AI.GetAttentionTargetDistance(A0_2161.id) <= A0_2161.gameParams.nearbyRange then
    return true
  end
  return false
end
function ArkHumanTest_x.IsTargetInMiddleRange(A0_2162)
  if AI.GetAttentionTargetDistance(A0_2162.id) <= A0_2162.gameParams.middleRange then
    return true
  end
  return false
end
