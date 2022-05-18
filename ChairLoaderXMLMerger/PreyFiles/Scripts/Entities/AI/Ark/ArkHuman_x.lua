Script.ReloadScript("SCRIPTS/Entities/AI/Shared/AIBase.lua")
ArkHuman_x = {
  ActionController = "Animations/Mannequin/ADB/Ai_Human_ControllerDefs.xml",
  AnimDatabase3P = "Animations/Mannequin/ADB/Ai_Human_Database.adb",
  UseMannequinAGState = true,
  UseLegacyCoverLocator = false,
  physicsParams = {
    Living = {
      mass = 90,
      air_resistance = 0,
      height = 1.125,
      size = {
        x = 0.5,
        y = 0.5,
        z = 0.375
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
    lookFOV = 200,
    lookInVehicleFOV = 110,
    aimFOV = 200,
    maxLookAimAngle = 120,
    aimIKFadeDuration = 0.5,
    aimIKLayer = 9,
    lookIKLayer = 10,
    proceduralLeaningFactor = 0,
    canUseComplexLookIK = true,
    lookAtSimpleHeadBone = "head_jnt",
    cornerSmoother = 2,
    stepThresholdTime = 0.5,
    stepThresholdDistance = 0.1,
    turnThresholdTime = 0.5,
    turnThresholdAngle = 5,
    maxDeltaAngleRateNormal = 125,
    maxDeltaAngleRateFast = 150,
    maxDeltaAngleRateFastest = 175,
    slopeUpSlowdownMult = 0,
    slopeDownSlowdownMult = 0,
    nearbyRange = 10,
    middleRange = 30,
    defaultStance = STANCE_RELAXED,
    stance = {
      {
        stanceId = STANCE_STAND,
        normalSpeed = 1.48,
        maxSpeed = 4.45,
        heightPivot = 0,
        CollisionHeight = 2,
        CollisionDiameter = 1,
        CapsuleOffset = 0.25,
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
        name = "stand",
        useCapsule = 1,
        slopeUpSlowdownMin = 0,
        slopeUpSlowdownMax = 0,
        slopeDownSlowdownMin = 0,
        slopeDownSlowdownMax = 0
      },
      {
        stanceId = STANCE_ALERTED,
        normalSpeed = 1.49,
        maxSpeed = 3.9,
        heightPivot = 0,
        CollisionHeight = 2,
        CollisionDiameter = 1,
        CapsuleOffset = 0.25,
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
        name = "alerted",
        useCapsule = 1,
        slopeUpSlowdownMin = 0,
        slopeUpSlowdownMax = 1,
        slopeDownSlowdownMin = 0,
        slopeDownSlowdownMax = 0.25
      },
      {
        stanceId = STANCE_ZEROG,
        normalSpeed = 1.58,
        maxSpeed = 4.65,
        heightPivot = 0,
        CollisionHeight = 2,
        CollisionDiameter = 1,
        CapsuleOffset = 0.25,
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
        useCapsule = 1
      },
      {
        stanceId = STANCE_RELAXED,
        normalSpeed = 1.48,
        maxSpeed = 4.45,
        heightPivot = 0,
        CollisionHeight = 2,
        CollisionDiameter = 1,
        CapsuleOffset = 0.25,
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
        name = "relaxed",
        useCapsule = 1,
        slopeUpSlowdownMin = 0,
        slopeUpSlowdownMax = 0,
        slopeDownSlowdownMin = 0,
        slopeDownSlowdownMax = 0
      },
      {
        stanceId = STANCE_CORRUPTED,
        normalSpeed = 0.8,
        maxSpeed = 0.8,
        heightPivot = 0,
        CollisionHeight = 2,
        CollisionDiameter = 1,
        CapsuleOffset = 0.25,
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
        name = "corrupted",
        useCapsule = 1,
        slopeUpSlowdownMin = 0,
        slopeUpSlowdownMax = 0,
        slopeDownSlowdownMin = 0,
        slopeDownSlowdownMax = 0
      },
      {
        stanceId = STANCE_CHARGE,
        normalSpeed = 4.36,
        maxSpeed = 4.36,
        heightPivot = 0,
        CollisionHeight = 2,
        CollisionDiameter = 1,
        CapsuleOffset = 0.25,
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
        name = "charge",
        useCapsule = 1,
        slopeUpSlowdownMin = 0,
        slopeUpSlowdownMax = 0,
        slopeDownSlowdownMin = 0,
        slopeDownSlowdownMax = 0
      },
      {
        stanceId = STANCE_GUNUP,
        normalSpeed = 1.9,
        maxSpeed = 2.57,
        heightPivot = 0,
        CollisionHeight = 2,
        CollisionDiameter = 1,
        CapsuleOffset = 0.25,
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
        name = "gunup",
        useCapsule = 1,
        slopeUpSlowdownMin = 0,
        slopeUpSlowdownMax = 0,
        slopeDownSlowdownMin = 0,
        slopeDownSlowdownMax = 0
      }
    }
  },
  Properties = {
    fileAiTree = "Ark/AI/AiTrees/HumanAiTree.xml",
    fileAccumulatorConfig = "",
    bCanTriggerAreas = 1,
    TagList = "",
    soclasses_SmartObjectClass = "Human, Actor",
    esNavigationType = "MediumSizedCharacters",
    fileHitDeathReactionsParamsDataFile = "Libs/HitDeathReactionsData/ArkHitDeathReactions_Human.xml",
    LipSync = {
      TransitionQueueSettings = {
        nCharacterSlot = 0,
        nAnimLayer = 12,
        sDefaultAnimName = "MissingLipSyncAnim"
      }
    },
    ArkHumanArmed = {
      bIsArmed = 0,
      magSize = 8,
      gunAttachmentName = "weapon",
      itemarchetype_LootWeapon = ""
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
      FOVPrimary = 180,
      FOVSecondary = 180
    },
    useSpecialMovementTransitions = 1,
    specialMovementTransitionsLibOverride = "",
    bOverrideAllowLookAimStrafing = 1,
    bSupportsLookAt = true,
    fileModel = "Objects/characters/Humans/GenMale/GenMale.cdf",
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
      foleyEffect = "",
      bodyFallEffect = ""
    },
    Damage = {arkHitImpulseScale = 1},
    ArkCorruption = {
      bStartCorrupted = 0,
      attachmenteffects_CorruptionEffects = "17591291352644294392",
      attachmenteffects_headExplode = "17591291352656479113",
      bShouldGoUnconsciousOnUncorruption = true,
      bDeletedOnLevelLoadAndUncorrupted = true,
      gameEffect_Corrupted = "200",
      metatag_UnCorrupted = "3149325216957280890"
    },
    RaisePhantom = {bCanBeRaisedPhantom = true},
    ArkUnreachableTargeting = {
      startingTraceRadius = 0.5,
      startingMinSearchRadius = 4,
      chanceToSearchInReverseOrder = 0,
      horizontalOffsetStanding = 0.24,
      standardCombatHeight = 1.51
    },
    ArkCharacter = {character_Character = "", voice_VoiceOverride = ""},
    ArkFear = {gameEffect_Feared = "18"},
    ArkMoveInfo = {pushLeverageMax = 2},
    OnStunned = {attachmenteffects_OnStunEffects = ""},
    OnPsychoShocked = {attachmenteffects_OnPsychoShockedEffects = ""},
    ArkDialog = {
      fPlayerApproachDistanceNear = 20,
      fPlayerApproachDistanceMedium = 20,
      fPlayerApproachDistanceFar = 20,
      fPlayerApproachCDNear = 30,
      fPlayerApproachCDMedium = 30,
      fPlayerApproachCDFar = 30,
      fPlayerLoiterDistance = 10,
      fPlayerLoiterCD = 5,
      audioProxyJointName = "head_jnt"
    },
    AttentionFacing = {bUsesAttentionLook = false, bUsesAttentionFacing = false},
    faction_ArkFaction = "0",
    ArkStunned = {gameEffect_StunnedGameEffectId = "2002"},
    Unconscious = {
      unconsciousDisplayText = "@ui_unconscious"
    }
  },
  AIMovementAbility = {
    allowEntityClampingByAnimation = 1,
    usePredictiveFollowing = 1,
    pathLookAhead = 1,
    walkSpeed = 1.58,
    runSpeed = 4.65,
    sprintSpeed = 4.65,
    maneuverSpeed = 1.58,
    b3DMove = 0,
    minTurnRadius = 0,
    maxTurnRadius = 3,
    pathSpeedLookAheadPerSpeed = -1.5,
    cornerSlowDown = 0.75,
    pathType = AIPATH_HUMAN,
    pathRadius = 0.5,
    passRadius = 0.65,
    separationRadius = 0.45,
    distanceToCover = 0.5,
    inCoverRadius = 0.075,
    effectiveCoverHeight = 0.55,
    effectiveHighCoverHeight = 1.75,
    pathFindPrediction = 0.5,
    maxAccel = 18,
    maxDecel = 18,
    velDecay = 0.5,
    maneuverTrh = 2,
    resolveStickingInTrace = 1,
    pathRegenIntervalDuringTrace = -1,
    lightAffectsSpeed = 1,
    avoidanceAbilities = AVOIDANCE_ALL,
    pushableObstacleWeakAvoidance = true,
    pushableObstacleAvoidanceRadiusMin = 0.5,
    pushableObstacleAvoidanceRadiusMax = 0.6,
    collisionAvoidanceRadiusIncrement = 0.02,
    pushableObstacleMassMin = 0,
    pushableObstacleMassMax = 80,
    pushableObstacleHeightMin = 0.25,
    pushableObstacleHeightMax = 2,
    lookIdleTurnSpeed = 30,
    lookCombatTurnSpeed = 50,
    aimTurnSpeed = -1,
    fireTurnSpeed = -1,
    directionalScaleRefSpeedMin = 1,
    directionalScaleRefSpeedMax = 5,
    directionalScaleTurn = 0.6,
    directionalScaleStrafe = 0.8,
    directionalScaleSlope = 0,
    harshStopSpeed = 1,
    harshStopMinAngle = 105,
    harshStopMaxAngle = 170,
    harshStopBelowDist = 1.69,
    AIMovementSpeeds = {
      Relaxed = {
        Slow = {
          0.5,
          0,
          0.5
        },
        Walk = {
          1.48,
          0,
          1.48
        },
        Run = {
          4.45,
          0,
          4.45
        },
        Sprint = {
          4.45,
          0,
          4.45
        }
      },
      Alerted = {
        Slow = {
          0.5,
          0,
          0.5
        },
        Walk = {
          1.49,
          0,
          1.49
        },
        Run = {
          3.9,
          0,
          3.9
        },
        Sprint = {
          3.9,
          0,
          3.9
        }
      },
      Combat = {
        Slow = {
          0.5,
          0,
          0.5
        },
        Walk = {
          1.49,
          0,
          1.49
        },
        Run = {
          3.9,
          0,
          3.9
        },
        Sprint = {
          3.9,
          0,
          3.9
        }
      },
      Corrupted = {
        Slow = {
          0.5,
          0,
          0.5
        },
        Walk = {
          0.8,
          0,
          0.8
        },
        Run = {
          0.8,
          0,
          0.8
        },
        Sprint = {
          0.8,
          0,
          0.8
        }
      },
      GunUp = {
        Slow = {
          0.5,
          0,
          0.5
        },
        Walk = {
          1.9,
          0,
          1.9
        },
        Run = {
          2.57,
          0,
          2.57
        },
        Sprint = {
          2.57,
          0,
          2.57
        }
      },
      Charge = {
        Slow = {
          0.5,
          0,
          0.5
        },
        Walk = {
          4.36,
          0,
          4.36
        },
        Run = {
          4.36,
          0,
          4.36
        },
        Sprint = {
          4.36,
          0,
          4.36
        }
      }
    }
  },
  ProceduralContextAim = {
    polarCoordinatesSmoothTimeSeconds = 0.25,
    polarCoordinatesMaxYawDegreesPerSecond = 180,
    polarCoordinatesMaxPitchDegreesPerSecond = 180,
    fadeInSeconds = 0.25,
    fadeOutSeconds = 0.25,
    fadeOutMinDistance = 0,
    fadeOutAngleDegrees = 180,
    maxAngleDegreesXY = 180,
    maxAngleDegreesZ = 180
  },
  ProceduralContextLook = {
    polarCoordinatesSmoothTimeSeconds = 0.5,
    polarCoordinatesMaxYawDegreesPerSecond = 360,
    polarCoordinatesMaxPitchDegreesPerSecond = 360,
    fadeInSeconds = 0.5,
    fadeOutSeconds = 0.5,
    fadeOutMinDistance = 0,
    fadeOutAngleDegrees = 180,
    maxAngleDegreesXY = 45,
    maxAngleDegreesZ = 45,
    speedMultiplierFast = 0.85,
    speedMultiplierFastest = 0.7
  },
  ProceduralContextLookHead = {
    polarCoordinatesSmoothTimeSeconds = 0.2,
    polarCoordinatesMaxYawDegreesPerSecond = 180,
    polarCoordinatesMaxPitchDegreesPerSecond = 180,
    fadeInSeconds = 0.3,
    fadeOutSeconds = 0.3,
    fadeOutMinDistance = 0,
    fadeOutMaxDistance = 20,
    fadeOutAngleDegrees = 135,
    maxAngleDegreesXY = 37,
    maxAngleDegreesZ = 37,
    speedMultiplierFast = 0.85,
    speedMultiplierFastest = 0.7
  },
  ProceduralContextLookEyes = {
    polarCoordinatesSmoothTimeSeconds = 0,
    polarCoordinatesMaxYawDegreesPerSecond = 360,
    polarCoordinatesMaxPitchDegreesPerSecond = 360,
    fadeInSeconds = 0,
    fadeOutSeconds = 0,
    fadeOutMinDistance = 0,
    fadeOutMaxDistance = 10,
    fadeOutAngleDegrees = 135,
    maxAngleDegreesXY = 30,
    maxAngleDegreesZ = 30
  },
  PropertiesInstance = {
    bStartDead = false,
    bAutoDisable = 1,
    ArkCorruption = {bIsCorrupted = 0}
  },
  ArkEmotionExtension = {nAnimLayer = 7},
  SearchModule = {sightRange = 12},
  aiSequenceUser = true,
  bHasSpawnedLoot = false,
  signalListened = "3149325216985116127",
  playerFaction = "17591291352618367183"
}
mergef(ArkHuman_x, AIBase, 1)
function ArkHuman_x.GetUsable(A0_1889)
  local L1_1890
  L1_1890 = {}
  if A0_1889:IsLootable() and not A0_1889.arknpc:IsGlooed() then
    L1_1890["Hold Use"], ({}).ActionType = {}, "Carry"
    if not A0_1889.arknpc:IsRaisedCorpse() then
      ({}).ActionType = "ScriptDefined"
      L1_1890.Loot, ({}).DisplayText = {}, A0_1889.Properties.ArkInteractMessages.textDeadInteractText
    end
    return L1_1890
  elseif A0_1889.alternateDisplayText then
    ({}).ActionType = "ScriptDefined"
    L1_1890.Use, ({}).DisplayText = {}, A0_1889.alternateDisplayText
  elseif A0_1889.arknpc:HasUseDialog() then
    ({}).ActionType = "ScriptDefined"
    L1_1890.Use, ({}).DisplayText = {}, A0_1889.Properties.ArkInteractMessages.textAliveInteractText
  end
  return L1_1890
end
function ArkHuman_x.OnHoldUsed(A0_1891, A1_1892)
  BroadcastEvent(A0_1891, "OnCarry")
end
function ArkHuman_x.IsLootable(A0_1893)
  return A0_1893.arknpc:IsDead() or A0_1893.arknpc:IsStunned() or A0_1893.arknpc:IsAsleep()
end
function ArkHuman_x.GetRemoteManipulationInteraction(A0_1894)
  local L1_1895
  L1_1895 = {}
  if A0_1894.arknpc:IsDead() or A0_1894.arknpc:IsStunned() or A0_1894.arknpc:IsAsleep() then
    L1_1895.ActionType = "Carry"
  else
    L1_1895.ActionType = "ScriptDefined"
  end
  return L1_1895
end
function ArkHuman_x.OnResetCustom(A0_1896, A1_1897, A2_1898)
  if A1_1897 then
    A0_1896:ResetContainer()
    A0_1896:InitInventory()
    CryAction.ActivateExtensionForGameObject(A0_1896.id, "ArkEmotionExtension", true)
  end
  characterName = nil
  if A0_1896.Properties.ArkCharacter.character_Character ~= "" then
    characterName = ArkRoster.GetCharacterName(A0_1896.Properties.ArkCharacter.character_Character)
  end
  if characterName ~= nil then
    A0_1896:SetDisplayName(characterName)
  end
  A0_1896.PropertiesInstance.ArkCorruption.bIsCorrupted = A0_1896.Properties.ArkCorruption.bIsCorrupted
  A0_1896.bHasSpawnedLoot = false
  A0_1896.bHostileToPlayer = nil
  if A0_1896.Properties.bCanTriggerAreas == 1 then
    A0_1896:SetFlags(ENTITY_FLAG_TRIGGER_AREAS, 0)
  else
    A0_1896:SetFlags(ENTITY_FLAG_TRIGGER_AREAS, 2)
  end
end
function ArkHuman_x.OnNpcStunned(A0_1899)
  BroadcastEvent(A0_1899, "Stunned")
  if not A0_1899.bHasSpawnedLoot then
    Ark.SpawnLootFromTable(A0_1899.Properties.loottable_ContainerLootTable, A0_1899.id)
    A0_1899.bHasSpawnedLoot = true
  end
end
function ArkHuman_x.OnNpcKilled(A0_1900)
  if not A0_1900.bHasSpawnedLoot then
    Ark.SpawnLootFromTable(A0_1900.Properties.loottable_ContainerLootTable, A0_1900.id)
    A0_1900.bHasSpawnedLoot = true
  end
end
function ArkHuman_x.OnNpcUnconscious(A0_1901)
  if not A0_1901.bHasSpawnedLoot then
    Ark.SpawnLootFromTable(A0_1901.Properties.loottable_ContainerLootTable, A0_1901.id)
    A0_1901.bHasSpawnedLoot = true
  end
  BroadcastEvent(A0_1901, "Sleep")
end
function ArkHuman_x.IsInvulnerable(A0_1902)
  local L1_1903
  L1_1903 = A0_1902.PropertiesInstance
  L1_1903 = L1_1903.bIsInvulnerable
  L1_1903 = L1_1903 == true
  return L1_1903
end
function ArkHuman_x.OnLureSignal(A0_1904, A1_1905, A2_1906, A3_1907)
  if A0_1904.arknpc:IsCorrupted() then
    A0_1904.arknpc:OnLured(A1_1905)
  end
end
function ArkHuman_x.OnFireThresholdExceeded(A0_1908)
  A0_1908.arknpc:LightOnFire()
end
function ArkHuman_x.OnFireThesholdFellBelow(A0_1909)
  A0_1909.arknpc:OnFireExpired()
end
function ArkHuman_x.OnFireAboveThresholdRefresh(A0_1910)
  A0_1910.arknpc:OnFireAboveThresholdRefresh()
end
function ArkHuman_x.OnSignalReceived(A0_1911)
  if not A0_1911.bHostileToPlayer then
    A0_1911.bHostileToPlayer = true
    ArkFaction:SetFactionDispositionTowardFaction(A0_1911.Properties.faction_ArkFaction, A0_1911.playerFaction, RELATIONSHIP_HOSTILE, true)
  end
end
