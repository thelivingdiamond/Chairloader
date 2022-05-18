Turret = {
  Properties = {
    objModel = "objects/weapons/turret/turret.cdf",
    esTurretState = "Deployed",
    PrimaryWeapon = "TurretGun",
    PrimaryWeaponJointName = "weaponjoint",
    PrimaryWeaponFovDegrees = 15,
    PrimaryWeaponRangeCheckOffset = 2,
    bUsableOnlyOnce = 1,
    Sound = {
      GameHintName = "HumanTurret_Gun",
      HorizontalJointName = "arcjoint",
      VerticalJointName = "Def_Gun_JNT",
      soundVerticalMovementStart = "sounds/w_turret:turret_functionality:turn_loop",
      soundVerticalMovementStop = "sounds/w_turret:turret_functionality:vertical_stop",
      soundVerticalMovementLoop = "sounds/w_turret:turret_functionality:vertical_loop",
      soundHorizontalMovementStart = "sounds/w_turret:turret_functionality:turn_start",
      soundHorizontalMovementStop = "sounds/w_turret:turret_functionality:turn_stop",
      soundHorizontalMovementLoop = "sounds/w_turret:turret_functionality:turn_loop",
      soundAlerted = "sounds/w_turret:turret_functionality:alerted",
      soundLockedOnTarget = "",
      fMovementStartSoundThresholdDegreesSecond = 4,
      fMovementStopSoundThresholdDegreesSecond = 0.2,
      fHorizontalLoopingSoundDelaySeconds = 0.3,
      fVerticalLoopingSoundDelaySeconds = 0.3,
      fAlertedTimeoutSeconds = 60,
      fLockOnTargetSeconds = 0.2
    },
    Laser = {
      bEnabled = 0,
      objGeometry = "engine/engineassets/objects/default.cgf",
      DotEffect = "",
      SourceEffect = "",
      JointName = "weaponjoint",
      fOffsetX = 0.45,
      fOffsetY = -0.87,
      fOffsetZ = -0.025,
      fThickness = 0.8,
      fRange = 150,
      fShowDot = 1
    },
    Vision = {
      fRadarRange = 20,
      fRadarFov = 180,
      fRadarVerticalOffset = 2,
      fEyeRange = 40,
      fEyeFov = 25,
      EyeJointName = "weaponjoint",
      fCloakDetectionDistance = 4
    },
    Mannequin = {
      fileControllerDef = "Animations/Mannequin/ADB/turretControllerDefs.xml",
      fileAnimationDatabase = "Animations/Mannequin/ADB/turret.adb"
    },
    Behavior = {
      SearchSweep = {
        fYawDegreesHalfLimit = 45,
        fYawDegreesPerSecond = 90,
        fDistance = 100,
        fHeight = 1,
        fRandomOffsetSeconds = 1,
        fRandomOffsetRange = 3
      },
      SearchSweepPause = {
        fLimitPauseSeconds = 1,
        fRandomOffsetSeconds = 0.4,
        fRandomOffsetRange = 5
      },
      FollowTarget = {
        fReevaluateTargetSeconds = 0.5,
        fMinStartFireDelaySeconds = 0.1,
        fMaxStartFireDelaySeconds = 0.15,
        fAimVerticalOffset = -0.3,
        fPredictionDelaySeconds = 0.1
      },
      FireTarget = {fMinStopFireSeconds = 0.5, fMaxStopFireSeconds = 0.75},
      LostTarget = {
        fBackToSearchSeconds = 5,
        fDampenVelocityTimeSeconds = 10,
        fLastVelocityValueWeight = 0.9
      },
      Undeployed = {bIsThreat = 0}
    },
    Damage = {
      health = 1000,
      fileBodyDamage = "Libs/BodyDamage/BodyDamage_HumanTurret.xml",
      fileBodyDamageParts = "Libs/BodyDamage/BodyParts_HumanTurret.xml",
      fileBodyDestructibility = "Libs/BodyDamage/BodyDestructibility_HumanTurret.xml"
    },
    AutoAimTargetParams = {
      primaryTargetBone = "weaponjoint_ref",
      physicsTargetBone = "weaponjoint_ref",
      secondaryTargetBone = "arcjoint",
      fallbackOffset = 1.2,
      innerRadius = 0.5,
      outerRadius = 0.6,
      snapRadius = 1.5,
      snapRadiusTagged = 3
    }
  },
  PropertiesInstance = {groupId = -1, fCloakDetectionDistanceMultiplier = 1},
  Editor = {Icon = "user.bmp", IconOnTop = 1},
  Server = {},
  Client = {}
}
MakeUsable(Turret)
function Turret.Client.OnInit(A0_8704)
  A0_8704:CacheResources()
end
function Turret.CacheResources(A0_8705)
  local L1_8706
  L1_8706 = A0_8705.PreLoadParticleEffect
  L1_8706(A0_8705, A0_8705.Properties.Laser.DotEffect)
  L1_8706 = A0_8705.PreLoadParticleEffect
  L1_8706(A0_8705, A0_8705.Properties.Laser.SourceEffect)
  L1_8706 = "Turret.lua"
  Game.CacheResource(L1_8706, A0_8705.Properties.Laser.objGeometry, eGameCacheResourceType_StaticObject, 0)
end
function Turret.OnPropertyChange(A0_8707)
  A0_8707.turret:OnPropertyChange()
end
function Turret.Server.OnHit(A0_8708, A1_8709)
  A0_8708.turret:OnHit(A1_8709)
end
function Turret.OnUsed(A0_8710, A1_8711, A2_8712)
  A0_8710.turret:SetStateById(eTurretBehaviorState_PartiallyDeployed)
  A0_8710.turret:SetFactionToPlayerFaction()
  if A0_8710.Properties.bUsableOnlyOnce == 1 then
    A0_8710.bUsable = 0
  end
end
function Turret.IsUsable(A0_8713, A1_8714)
  if A0_8713.bUsable == 1 then
    return 1
  end
  return 0
end
function Turret.Event_SetStateDeployed(A0_8715)
  A0_8715.turret:SetStateById(eTurretBehaviorState_Deployed)
end
function Turret.Event_SetStatePartiallyDeployed(A0_8716)
  A0_8716.turret:SetStateById(eTurretBehaviorState_PartiallyDeployed)
end
function Turret.Event_SetStateUndeployed(A0_8717)
  A0_8717.turret:SetStateById(eTurretBehaviorState_Undeployed)
end
function Turret.Event_Enable(A0_8718, A1_8719)
  A0_8718.turret:Enable()
end
function Turret.Event_Disable(A0_8720, A1_8721)
  A0_8720.turret:Disable()
end
function Turret.OnReset(A0_8722)
  local L1_8723
  L1_8723 = A0_8722.Properties
  L1_8723 = L1_8723.bUsable
  A0_8722.bUsable = L1_8723
end
function Turret.OnSave(A0_8724, A1_8725)
  A1_8725.bUsable = A0_8724.bUsable
end
function Turret.OnLoad(A0_8726, A1_8727)
  A0_8726.bUsable = A1_8727.bUsable
end
Turret.FlowEvents = {
  Inputs = {
    Enable = {
      Turret.Event_Enable,
      "bool"
    },
    Disable = {
      Turret.Event_Disable,
      "bool"
    },
    SetDeployed = {
      Turret.Event_SetStateDeployed,
      "bool"
    },
    SetPartiallyDeployed = {
      Turret.Event_SetStatePartiallyDeployed,
      "bool"
    },
    SetUndeployed = {
      Turret.Event_SetStateUndeployed,
      "bool"
    }
  },
  Outputs = {Destroyed = "bool"}
}
