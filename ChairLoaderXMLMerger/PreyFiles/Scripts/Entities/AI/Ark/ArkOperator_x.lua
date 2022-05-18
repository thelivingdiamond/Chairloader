Script.ReloadScript("SCRIPTS/Entities/AI/Shared/AIBase.lua")
ArkOperator_x = {
  ActionController = "Animations/Mannequin/ADB/Ai_Operator_ControllerDefs.xml",
  AnimDatabase3P = "Animations/Mannequin/ADB/Ai_Operator_Database.adb",
  UseMannequinAGState = true,
  UseLegacyCoverLocator = false,
  physicsParams = {
    flags = 0,
    mass = 20,
    Living = {
      gravity = 9.81,
      mass = 20,
      air_resistance = 0,
      k_air_control = 0,
      inertia = 2,
      inertiaAccel = 2,
      timeImpulseRecover = 1.5,
      height = 0.43,
      size = {
        x = 0.6,
        y = 0.6,
        z = 0.1
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
    lookFOV = 200,
    lookInVehicleFOV = 110,
    aimFOV = 200,
    leanAngle = 60,
    maxLookAimAngle = 120,
    aimIKFadeDuration = 0.5,
    aimIKLayer = 14,
    proceduralLeaningFactor = 0,
    canUseComplexLookIK = true,
    lookAtSimpleHeadBone = "root_jnt",
    cornerSmoother = 3,
    stepThresholdTime = 0.5,
    stepThresholdDistance = 0.1,
    turnThresholdTime = 0.1,
    turnThresholdAngle = 2,
    minimumAngleForTurnWithoutDelay = 2,
    maxDeltaAngleRateNormal = 90,
    maxDeltaAngleRateFast = 360,
    maxDeltaAngleRateFastest = 360,
    nearbyRange = 10,
    middleRange = 30,
    defaultStance = 12,
    stance = {
      {
        stanceId = STANCE_STAND,
        normalSpeed = 1,
        maxSpeed = 50,
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 0
        },
        heightCollider = 0.43,
        heightPivot = 0,
        size = {
          x = 0.6,
          y = 0.6,
          z = 0.1
        },
        name = "stand",
        useCapsule = 1
      },
      {
        stanceId = STANCE_HOVER,
        normalSpeed = 1,
        maxSpeed = 50,
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 0
        },
        heightCollider = 0.43,
        heightPivot = 0,
        size = {
          x = 0.6,
          y = 0.6,
          z = 0.1
        },
        name = "hover",
        useCapsule = 1
      },
      {
        stanceId = STANCE_CORRUPTED,
        normalSpeed = 1,
        maxSpeed = 50,
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 0
        },
        heightCollider = 0.43,
        heightPivot = 0,
        size = {
          x = 0.6,
          y = 0.6,
          z = 0.1
        },
        name = "corrupted",
        useCapsule = 1
      },
      {
        stanceId = STANCE_ALERTED,
        normalSpeed = 1,
        maxSpeed = 50,
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 0
        },
        heightCollider = 0.43,
        heightPivot = 0,
        size = {
          x = 0.6,
          y = 0.6,
          z = 0.1
        },
        name = "alerted",
        useCapsule = 1
      },
      {
        stanceId = STANCE_RELAXED,
        normalSpeed = 1,
        maxSpeed = 50,
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewOffset = {
          x = 0,
          y = 0.1,
          z = 0
        },
        heightCollider = 0.43,
        heightPivot = 0,
        size = {
          x = 0.6,
          y = 0.6,
          z = 0.1
        },
        heightPivot = 0,
        name = "relaxed",
        useCapsule = 1
      }
    }
  },
  Properties = {
    fileAiTree = "Ark/AI/AiTrees/OperatorAiTree.xml",
    fileAccumulatorConfig = "",
    soundUnmorphSound = "",
    ei_ObjectMapIcon = "",
    TagList = "",
    soclasses_SmartObjectClass = "Human, Actor",
    esNavigationType = "ArkOperator",
    fileHitDeathReactionsParamsDataFile = "Libs/HitDeathReactionsData/ArkHitDeathReactions_Operator.xml",
    signalPackage_ElectricShock = "",
    ability_HackRequirement = "",
    loottable_ContainerLootTable = "",
    operatorMineClassName = "ArkProjectileOperatorGrenade",
    operatorMineSpawnAttachment = "MineSpawnLocation",
    attachmenteffects_operatorLevitator = "17591291352653888042",
    bCanFall = false,
    Laser = {
      object_LaserGeometryName = "Objects/ArkEffects/Weapons/HeavyLaser/heavylaser_initialbeam_green.cgf",
      object_ReflectionGeometryName = "Objects/ArkEffects/Weapons/HeavyLaser/heavylaser_beam_green.cgf",
      particleeffect_LensFlareEffectName = "Characters.Robots.OperatorGeneric.Weapon.LaserMaintainFire_00",
      particleeffect_BeamEndEffectName = "Characters.Robots.OperatorMilitary.LaserBeamImpact_00",
      fMinLaserThickness = 0.005,
      fMaxLaserThickness = 0.055,
      fMaxLaserLength = 100,
      ShootBoneAttachment = "",
      signalpackage_laserPackageId = "3149325216914689683",
      surfaceTypeName = "ArkOperatorLaserWeaponHit",
      friendlyHitDamageScale = 0.1,
      sHitType = "ArkInstalaserBeam",
      LaserMatName = "ArkOperatorLaser",
      itemarchetype_LootAmmoLaser = "",
      itemarchetype_LootAmmoStun = "",
      fBeamEndJumpDistSq = 1,
      attachmenteffects_operatorLaserCharge = "2428940965289302982",
      attachmenteffects_operatorLaserFlare = "2428940965289303111"
    },
    Light = {
      archetype_lightFriendly = "",
      archetype_lightHostile = "",
      archetype_lightHacked = "",
      ArkLightAttachmentName = "LightAttachment",
      fFlickerToggleMaxDuration = 0.15,
      fTalkMinBrightness = 0.6,
      fTalkMaxBrightness = 0.9
    },
    Dispenser = {object_FakeOperatorModel = "", materialanimations_FakeOperatorMaterialAnim = ""},
    OnStunned = {attachmenteffects_OnStunEffects = ""},
    OnPsychoShocked = {attachmenteffects_OnPsychoShockedEffects = ""},
    Damage = {
      fileBodyDamage = "Libs/BodyDamage/BodyDamage_Default.xml",
      fileBodyDamageParts = "Libs/BodyDamage/BodyParts_Default.xml",
      fileBodyDestructibility = "Libs/BodyDamage/BodyDestructibility_Default.xml",
      CanFall = 0,
      FallSleepTime = 1,
      heatAbsobsion = 0.5,
      heatDissipation = 200,
      minHeatDamage = 100,
      arkWeaponImpulseScale = 10,
      arkWeaponImpulseApplyTimeImpulseMin = 5,
      arkWeaponImpulseApplyTimeImpulseMax = 50,
      arkWeaponImpulseApplyTimeMin = 0.05,
      arkWeaponImpulseApplyTimeMax = 0.1
    },
    DamageStates = {
      HealthThresholdDamaged = 600,
      HealthThresholdDisabled = 300,
      AttachmentNameUndamaged = "",
      AttachmentNameDamaged = "",
      AttachmentNameDisabled = "",
      modelChassisModel = "Objects/characters/Robots/Operator/Operator.cdf",
      AttachmentNameChassisUndamaged = "body",
      AttachmentNameChassisDestroyed = "destroyed_skin",
      attachmenteffects_OnDamagedEffects = "",
      attachmenteffects_OnDisabledEffects = "",
      attachmenteffects_OnDestroyedEffects = "17591291352650596140",
      attachmenteffects_operatorPreDestruction = "17591291352656579532",
      signalPackage_explosionPackage = "9469288860551345417",
      cameraShake_explosionCameraShake = "",
      fExplosionRadius = 3,
      fExplosionImpulse = 100,
      fExplosionDelay = 2,
      fDestroyedHeightOffset = -0.5
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
    bSupportsLookAt = false,
    AttentionFacing = {bUsesAttentionLook = 0, bUsesAttentionFacing = 0},
    useSpecialMovementTransitions = 0,
    bOverrideAllowLookAimStrafing = 1,
    fileModel = "Objects/characters/Robots/OperatorScience/OperatorScience.cdf",
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
      bodyFallEffect = "",
      hoverMotorStartEffect = "",
      hoverMotorTurnEffect = "",
      hoverMotorStopEffect = "",
      hoverMotorTravelSpeedEffect = "",
      hoverMotorTravelSpeedPercentEffect = "",
      corruptGravityEffect = ""
    },
    ArkCharacter = {character_Character = ""},
    ArkCorruption = {
      bStartCorrupted = 0,
      attachmenteffects_CorruptionEffects = "17591291352644294320",
      particleeffect_MovementGlitch = "Characters.Robots.OperatorGeneric.CorruptedSparks_00",
      movementGlitchAttachmentName1 = "FX_CorruptSparks_00",
      movementGlitchAttachmentName2 = "FX_CorruptSparks_01",
      audioTrigger_BecomeCorruptedTrigger = "",
      gameEffect_Corrupted = "",
      metatag_UnCorrupted = "3149325216957280890"
    },
    ArkDormant = {signalModifier_dormantSignalModifierId = "", attentionModifier_dormantHearingGainMult = 2.5},
    ArkHack = {gameEffect_Hacked = "100", bStartHacked = 0},
    OperatorEffects = {
      particleeffect_levitationEffectName = "Characters.Robots.OperatorGeneric.Levitators_00",
      levitatorAttachmentName1 = "FX_Levitator_00",
      levitatorAttachmentName2 = "FX_Levitator_01",
      particleeffect_boosterEffectName = "Characters.Robots.OperatorGeneric.Boosters_00",
      boosterAttachmentName1 = "FX_Booster_00",
      boosterAttachmentName2 = "FX_Booster_01",
      particleeffect_airJetName = "Characters.Robots.OperatorGeneric.AirJetBooster_00",
      minAirJetToggleOnTime = 0.5,
      maxAirJetToggleOnTime = 1,
      airJetToggleOffTime = 0.25,
      gameEffect_OperatorArmRetractedGameEffectId = "1100"
    },
    OperatorDeath = {damageRadius = 0, signalpackage_DamagePackageId = ""},
    ArkDialog = {
      fPlayerApproachDistanceNear = 20,
      fPlayerApproachDistanceMedium = 20,
      fPlayerApproachDistanceFar = 20,
      fPlayerApproachCDNear = 30,
      fPlayerApproachCDMedium = 30,
      fPlayerApproachCDFar = 30,
      fPlayerLoiterDistance = 10,
      fPlayerLoiterCD = 5,
      audioProxyJointName = "cog_jnt",
      fAttenuationScale = 0.7
    },
    faction_ArkFaction = "0",
    ArkMoveInfo = {
      moveMultiDir = false,
      moveHover = true,
      hoverRoll = 0.3,
      hoverPitchSpeedMult = 0.4,
      hoverPitchIdleMaxDegrees = 7,
      hoverPitchMoveMaxDegrees = 10,
      hoverBob = true,
      hoverBobTimeMin = 0.5,
      hoverBobTimeMax = 1,
      hoverBobSpeedMin = 0.02,
      hoverBobSpeedMax = 0.035,
      hoverBobAccelStartMult = 1,
      hoverBobDecelEndMult = 0.95,
      hoverBobAdjustFastHeightDelta = 0.25,
      hoverBobAdjustFastSpeed = 0.5,
      hoverPivotHeight = 0.4,
      hoverClearanceHeight = 0.45,
      hoverClearanceLedge = 1.5,
      hoverPsiLiftSpeedMult = 0.25,
      pushLeverageMax = 2,
      matchTargetHeightDistance = 10
    },
    Repair = {
      nHoldToUseDuration = 1000,
      archetype_RepairItem = "",
      ability_RepairRequirement = "3149325216929347161",
      nSparePartsRequired = 0,
      textDisplayNameBroken = "@i_brokenoperator",
      bRepairable = 1
    },
    ArkUnreachableTargeting = {
      defaultCombatReachabilityCheckUp = 1,
      defaultCombatReachabilityCheckDown = 5,
      defaultCombatReachabilityCheckHorizontal = 1
    },
    ArkStunned = {gameEffect_StunnedGameEffectId = "2001"},
    Sound = {
      DamageStates = {
        audioTrigger_BecomeUndamagedTrigger = "",
        audioTrigger_BecomeDamagedTrigger = "",
        audioTrigger_BecomeDisabledTrigger = ""
      },
      OperatorMineLaying = {audioTrigger_Orient = "", audioTrigger_DropMine = ""},
      audioTrigger_RepairLoop = "",
      audioTrigger_RepairStop = "",
      audioTrigger_FortifyLoop = "",
      audioTrigger_FortifyStop = ""
    }
  },
  AIMovementAbility = {
    allowEntityClampingByAnimation = 0,
    usePredictiveFollowing = 1,
    pathLookAhead = 1.5,
    walkSpeed = 2,
    runSpeed = 5,
    sprintSpeed = 8,
    maneuverSpeed = 1,
    b3DMove = 1,
    minTurnRadius = 0,
    maxTurnRadius = 3,
    pathSpeedLookAheadPerSpeed = -1.5,
    optimalFlightHeight = 1.15,
    minFlightHeight = 0.375,
    maxFlightHeight = 50,
    cornerSlowDown = 0.5,
    pathType = "AIPATH_OPERATOR",
    pathRadius = 0.35,
    passRadius = 0.63,
    separationRadius = 0.59,
    distanceToCover = 0.5,
    inCoverRadius = 0.075,
    effectiveCoverHeight = 0.55,
    effectiveHighCoverHeight = 1.75,
    pathFindPrediction = 0.5,
    maxAccel = 1,
    maxDecel = 1.5,
    velDecay = 0.1,
    maneuverTrh = 2,
    resolveStickingInTrace = 1,
    pathRegenIntervalDuringTrace = -1,
    lightAffectsSpeed = 1,
    avoidanceAbilities = AVOIDANCE_ALL,
    pushableObstacleWeakAvoidance = true,
    pushableObstacleAvoidanceRadiusMin = 0.6,
    pushableObstacleAvoidanceRadiusMax = 0.6,
    avoidanceRadius = 2,
    collisionAvoidanceRadiusIncrement = 0.01,
    pushableObstacleMassMin = 5,
    pushableObstacleMassMax = 20,
    pushableObstacleHeightMin = 0.5,
    pushableObstacleHeightMax = 2,
    lookIdleTurnSpeed = 30,
    lookCombatTurnSpeed = 50,
    aimTurnSpeed = -1,
    fireTurnSpeed = -1,
    directionalScaleRefSpeedMin = 1,
    directionalScaleRefSpeedMax = 5,
    directionalScaleTurn = 0.1,
    directionalScaleStrafe = 0.2,
    directionalScaleSlope = 0,
    harshStopSpeed = 8.5,
    harshStopMinAngle = 135,
    harshStopMaxAngle = 180,
    AIMovementSpeeds = {
      Relaxed = {
        Slow = {
          0.8,
          0,
          0.8
        },
        Walk = {
          1.5,
          0,
          1.5
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
          0,
          0.8
        },
        Walk = {
          1.5,
          0,
          1.5
        },
        Run = {
          5,
          0,
          5
        },
        Sprint = {
          12,
          0,
          12,
          15,
          15
        }
      },
      Hover = {
        Slow = {
          0.8,
          0,
          0.8
        },
        Walk = {
          1.5,
          0,
          1.5
        },
        Run = {
          5,
          0,
          5
        },
        Sprint = {
          12,
          0,
          12,
          15,
          15
        }
      },
      Corrupted = {
        Slow = {
          0.8,
          0,
          0.8
        },
        Walk = {
          1,
          0,
          1
        },
        Run = {
          3,
          0,
          3
        },
        Sprint = {
          8,
          0,
          8,
          6,
          7
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
    voiceName = "Operator",
    ability_HackRequirementOverride = "",
    bAutoDisable = 1
  },
  SearchModule = {sightRange = 12},
  aiSequenceUser = true
}
mergef(ArkOperator_x, AIBase, 1)
function ArkOperator_x.OnMeleeSignal(A0_1941, A1_1942, A2_1943, A3_1944)
  local L4_1945
  L4_1945 = A0_1941.Properties
  L4_1945 = L4_1945.signalPackage_ElectricShock
  if L4_1945 ~= "" then
    Ark.SendSignalPackage(g_localActor.id, A0_1941.id, A0_1941.id, L4_1945)
  end
end
function ArkOperator_x.OnSignalReceivedCustom(A0_1946, A1_1947, A2_1948)
  local L3_1949
  if A1_1947 == "3149325216914689654" then
    L3_1949 = A0_1946.Properties
    L3_1949 = L3_1949.signalPackage_ElectricShock
    if L3_1949 ~= "" then
      Ark.SendSignalPackage(g_localActor.id, A0_1946.id, A0_1946.id, L3_1949)
    end
  end
end
function ArkOperator_x.OnNpcKilled(A0_1950)
  Ark.SpawnLootFromTable(A0_1950.Properties.loottable_ContainerLootTable, A0_1950.id)
end
function ArkOperator_x.IsInvulnerable(A0_1951)
  local L1_1952
  L1_1952 = A0_1951.PropertiesInstance
  L1_1952 = L1_1952.bIsInvulnerable
  L1_1952 = L1_1952 == true
  return L1_1952
end
function ArkOperator_x.OnResetCustom(A0_1953, A1_1954, A2_1955)
  if A1_1954 then
    A0_1953:ResetContainer()
    A0_1953:InitInventory()
  end
  characterName = nil
  if A0_1953.Properties.ArkCharacter.character_Character ~= "" then
    characterName = ArkRoster.GetCharacterName(A0_1953.Properties.ArkCharacter.character_Character)
  end
  if characterName ~= nil then
    A0_1953:SetDisplayName(characterName)
  end
end
function ArkOperator_x.GetUsable(A0_1956)
  local L1_1957
  L1_1957 = {}
  if A0_1956.arknpc:IsDead() then
    if A0_1956.arknpc:IsDestroyed() then
      L1_1957["Hold Use"], ({}).ActionType = {}, "Carry"
      ;({}).ActionType = "ScriptDefined"
      L1_1957.Loot, ({}).DisplayText = {}, A0_1956.Properties.ArkInteractMessages.textDeadInteractText
      return L1_1957
    end
  else
    if A0_1956.alternateDisplayText then
      ({}).ActionType = "ScriptDefined"
      L1_1957.Use, ({}).DisplayText = {}, A0_1956.alternateDisplayText
    elseif A0_1956.arknpc:HasUseDialog() and not A0_1956.arknpc:IsBroken() then
      ({}).ActionType = "ScriptDefined"
      L1_1957.Use, ({}).DisplayText = {}, A0_1956.Properties.ArkInteractMessages.textAliveInteractText
    end
    if not A0_1956.arknpc:IsHacked() and not ArkFaction:IsEntityFriendlyToEntity(A0_1956:GetRawId(), g_localActor:GetRawId()) and (not ArkFaction:IsEntityHostileToEntity(A0_1956:GetRawId(), g_localActor:GetRawId()) or not (A0_1956.arknpc:GetAttentionLevelOnPlayer() == ATTENTIONLEVEL_KNOWN) or A0_1956.arknpc:IsGlooed() or bIsDisabled or not not A0_1956.arknpc:IsStunned()) then
      L1_1957["Hold Use"], ({}).ActionType = {}, "Hack"
    end
    return L1_1957
  end
  return L1_1957
end
function ArkOperator_x.GetRemoteManipulationInteraction(A0_1958)
  if A0_1958:GetUsable().Use and A0_1958:GetUsable().Use.ActionType or A0_1958:GetUsable()["Hold Use"] and A0_1958:GetUsable()["Hold Use"].ActionType or A0_1958:GetUsable().Special and A0_1958:GetUsable().Special.ActionType or A0_1958:GetUsable().Loot and A0_1958:GetUsable().Loot.ActionType then
    ({}).ActionType = "Examine"
  end
  return {}
end
function ArkOperator_x.OnLureSignal(A0_1959, A1_1960, A2_1961, A3_1962)
  if A0_1959.arknpc:IsCorrupted() then
    A0_1959.arknpc:OnLured(A1_1960)
  end
end
function ArkOperator_x.HackSuccess(A0_1963)
  A0_1963.arknpc:Hack()
end
function ArkOperator_x.HackFail(A0_1964)
  local L1_1965
end
function ArkOperator_x.Event_WakeFromDormant(A0_1966)
  A0_1966.arknpc:WakeFromDormant()
end
ArkOperator_x.FlowEvents = {
  Inputs = {
    WakeFromDormant = {
      ArkOperator_x.Event_WakeFromDormant,
      "bool"
    }
  },
  Outputs = {
    Broken = "bool",
    Repaired = "bool",
    Hacked = "bool"
  }
}
