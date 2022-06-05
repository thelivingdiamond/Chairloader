Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkLeakable = {
  Properties = {
    object_Model = "",
    material_Material = "",
    signalpackage_LeakHazard = "",
    bRecycleLeaks = 1,
    nRecycleDuration = 0,
    fLeakAngle = 10,
    fMinLeakLength = 0.5,
    fMaxLeakLength = 1,
    nMaxLeaks = 1,
    fChanceOfLeak = 0.25,
    fMinDistanceBetweenLeaks = 0.1,
    fMaxHostileAdjustmentAngle = 25,
    nHostileAdjustmentFreqency = 500,
    nHazardInterval = 100,
    nLeakDuration = -1,
    nCameraVFXInterval = 1000,
    fSelfLeakImpulse = 0,
    fAttachedGooScaleFactor = 0.5,
    signalGroup_Piercing = "3149325216937655803",
    Signals = {signal_Goo = ""},
    Effects = {
      particleeffect_Leak = "",
      fMinLeakLength = 1,
      fMaxLeakLength = 4
    },
    Sound = {audioTrigger_LeakStart = "", audioTrigger_LeakStop = ""},
    Physics = {
      bPhysicalize = 1,
      bRigidBody = 0,
      bPushableByPlayers = 0,
      bPushableByAI = 0,
      bResting = 1,
      bRigidBodyActive = 0,
      Density = -1,
      Mass = -1
    }
  },
  States = {"Intact", "Hazard"},
  TargetClassBlackList = {
    LightningArc = true,
    ArkElectricalBox = true,
    SinglePlayer = true,
    ExtendedClip = true,
    NoWeapon = true,
    ArkLeakable = true,
    ArkProjectileGoo = true
  },
  Editor = {
    Icon = "Hazard.bmp",
    IconOnTop = 1,
    IsScalable = false
  },
  PropertiesInstance = {
    bValveStartsOpen = 1,
    bVerbose = 0,
    bDrawTargetPoints = 0,
    bForceEffectVAClip = 0,
    fMinLeakLengthOverride = -1,
    fMaxLeakLengthOverride = -1,
    fAllowedAngle = -1,
    fAllowedAngleOffset = 0
  }
}
GetArkEntityUtils(ArkLeakable)
SetupCollisionFiltering(ArkLeakable)
function ArkLeakable.Init(A0_4209, A1_4210)
  A0_4209:Activate(1)
end
function ArkLeakable.SetFromProperties(A0_4211)
  A0_4211:SetMaterial(A0_4211.Properties.material_Material)
end
function ArkLeakable.OnReset(A0_4212, A1_4213)
  A0_4212:Activate(1)
  A0_4212:SetFromProperties()
end
function ArkLeakable.OnSpawn(A0_4214)
  A0_4214:SetFromProperties()
end
function ArkLeakable.Event_ValveOpen(A0_4215)
  Ark.SetLeakableValveState(A0_4215.id, true)
  BroadcastEvent(A0_4215, "ValveOpened")
end
function ArkLeakable.Event_ValveClose(A0_4216)
  Ark.SetLeakableValveState(A0_4216.id, false)
  BroadcastEvent(A0_4216, "ValveClosed")
end
function ArkLeakable.Event_Repair(A0_4217)
  BroadcastEvent(A0_4217, "Repaired")
end
ArkLeakable.FlowEvents = {
  Inputs = {
    ValveOpen = {
      ArkLeakable.Event_ValveOpen,
      "bool"
    },
    ValveClose = {
      ArkLeakable.Event_ValveClose,
      "bool"
    },
    Repair = {
      ArkLeakable.Event_Repair,
      "bool"
    }
  },
  Outputs = {
    ValveOpened = "bool",
    ValveClosed = "bool",
    Repaired = "bool",
    OnHit = "bool",
    Leaking = "bool",
    EntityId = "entity"
  }
}
