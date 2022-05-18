Script.ReloadScript("scripts/ArkEntityUtils.lua")
Script.ReloadScript("scripts/Entities/Ark/ArkLeakable.lua")
ArkExplosiveTank = {
  Properties = {
    bUseSafeCarry = false,
    bCanTriggerAreas = 1,
    object_Model = "",
    ability_CarryRequirement = "",
    signalpackage_Explosion = "",
    textDisplayName = "",
    nExplodeDelay = 1000,
    fMaxImpulse = 1000,
    fMinRadius = 0.5,
    fMaxRadius = 1,
    fExplosionVFXScale = 1,
    cameraShake_ExplosionCameraShake = "10739735956147043737",
    fHealth = 100,
    nInstantExplosionThreshold = 100,
    signalGroup_Damage = "3149325216937655803",
    signalmodifier_SignalModifier = "3149325216958565397",
    vector_ThrowAngularImpulse = {
      x = -10,
      y = 0,
      z = 0
    },
    Signals = {signal_Goo = ""},
    Effects = {particleeffect_Explode = "", particleeffect_Leak = ""},
    Sound = {audioTrigger_Explode = "", audioTrigger_Carry = ""},
    Physics = {
      bPhysicalize = 1,
      bRigidBody = 1,
      bPushableByPlayers = 1,
      bPushableByAI = 1,
      bResting = 1,
      bRigidBodyActive = 1,
      Density = -1,
      Mass = -1
    },
    RecycleData = {
      organic = 0,
      mineral = 0,
      synthetic = 0,
      exotic = 0
    },
    Silhouette = {
      color_RGB = {
        x = 1,
        y = 1,
        z = 1
      },
      fAlpha = 0.25
    }
  },
  States = {
    "Intact",
    "PreExplode",
    "Explode",
    "Hazard",
    "Destroyed"
  },
  Editor = {
    Icon = "explosion.bmp",
    IconOnTop = 1,
    IsScalable = false
  },
  PropertiesInstance = {bVerbose = 0}
}
ArkMakeDerivedEntityOverride(ArkExplosiveTank, ArkLeakable, false)
function ArkExplosiveTank.Init(A0_3855, A1_3856)
  A0_3855:Log("Initializing...")
  if A0_3855.Properties.bCanTriggerAreas == 1 then
    A0_3855:SetFlags(ENTITY_FLAG_TRIGGER_AREAS, 0)
  else
    A0_3855:SetFlags(ENTITY_FLAG_TRIGGER_AREAS, 2)
  end
end
function ArkExplosiveTank.SetFromProperties(A0_3857)
  local L1_3858
  L1_3858 = A0_3857.Properties
  A0_3857:SetDisplayName(L1_3858.textDisplayName)
  A0_3857.m_bVerbose = A0_3857.PropertiesInstance.bVerbose == 1
  Ark.RemoveInboundSignalModifier(A0_3857.id, L1_3858.signalmodifier_SignalModifier)
  Ark.AttachInboundSignalModifier(A0_3857.id, L1_3858.signalmodifier_SignalModifier)
end
function ArkExplosiveTank.OnSpawn(A0_3859)
  A0_3859:Log("OnSpawn")
  A0_3859:SetFromProperties()
end
function ArkExplosiveTank.OnPostLoad(A0_3860)
  A0_3860:SetFromProperties()
end
function ArkExplosiveTank.Event_Explode(A0_3861)
  Ark.ExplodeTank(A0_3861.id)
end
function ArkExplosiveTank.Event_Activator(A0_3862, A1_3863, A2_3864)
  Ark.SetEnvironmentalHazardActivator(A0_3862.id, A2_3864.id)
end
ArkExplosiveTank.FlowEvents = {
  Inputs = {
    Explode = {
      ArkExplosiveTank.Event_Explode,
      "bool"
    },
    Activator = {
      ArkExplosiveTank.Event_Activator,
      "entity"
    }
  },
  Outputs = {
    PreExplode = "bool",
    Explode = "bool",
    Hazard = "bool",
    Destroyed = "bool"
  }
}
