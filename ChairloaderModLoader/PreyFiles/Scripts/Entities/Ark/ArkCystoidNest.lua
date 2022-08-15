Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkCystoidNest = {
  Properties = {
    object_Model = "",
    signalGroup_Damage = "3149325216937655803",
    signalmodifier_InboundModifier = "3149325216976359587",
    signalGroup_Trigger = "",
    nPrimedDuration = 750,
    nCystoidsToSpawn = 5,
    archetype_CystoidArchetype = "",
    material_PrimedMaterial = "",
    fHealth = 100,
    metaTags_TagsToIgnore = "9469288860498988665",
    metaTags_ArkMetaTags = "",
    signal_NullWave = "3149325216915549045",
    fNullWaveDeaccumulation = 0.5,
    faction_ArkFaction = "17591291352619661944",
    scanningDisplayName = "@npc_cystoidnest",
    anim_IdleAnim = "",
    fHazardRadius = 10,
    nHazardPulseDelay = 250,
    signalpackage_HazardPackage = "10641886185795235206",
    OneG = {
      fMonitorRadius = 6,
      fTargetSpeedThreshold = 1.5,
      fPlayerSpeedThreshold = 2,
      fSpawnImpulse = 0.3
    },
    ZeroG = {
      fMonitorRadius = 6,
      fTargetSpeedThreshold = 1.5,
      fPlayerSpeedThreshold = 2,
      fSpawnImpulse = 0.3
    },
    Effects = {
      sParticleAttachmentName = "fx_attachMainBody",
      particleeffect_Spawn = "Characters.Aliens.Cystoid.Nest.CystoidSpawn",
      particleeffect_Destroyed = "Characters.Aliens.Cystoid.Nest.DeathExplosion"
    },
    AI = {bUsedAsDynamicObstacle = 1},
    Physics = {
      bPhysicalize = 1,
      bRigidBody = 1,
      bPushableByPlayers = 1,
      bPushableByAI = 1,
      bResting = 1,
      bRigidBodyActive = 1,
      Density = 1,
      Mass = -1
    },
    RecycleData = {
      organic = 0,
      mineral = 0,
      synthetic = 0,
      exotic = 0
    },
    Sound = {
      audioTrigger_Explode = "",
      audioTrigger_Triggered = "",
      audioTrigger_ExistStart = ""
    }
  },
  Editor = {
    Icon = "animobject.bmp",
    IconOnTop = 1,
    IsScalable = false,
    ArchetypeEntityObjectClassName = "Entity::ArkNpcSpawnCystoidNest"
  },
  PropertiesInstance = {bAutoDisable = 1, bUsedAsDynamicObstacle = 1}
}
GetArkEntityUtils(ArkCystoidNest)
SetupCollisionFiltering(ArkCystoidNest)
function ArkCystoidNest.Init(A0_3628, A1_3629)
end
function ArkCystoidNest.SetFromProperties(A0_3630)
  local L1_3631
end
function ArkCystoidNest.OnReset(A0_3632, A1_3633)
  A0_3632:Log("OnReset")
  A0_3632.m_bInit = false
  A0_3632:SetFromProperties()
end
function ArkCystoidNest.OnSpawn(A0_3634)
  Ark.RemoveInboundSignalModifier(A0_3634.id, A0_3634.Properties.signalmodifier_InboundModifier)
  Ark.AttachInboundSignalModifier(A0_3634.id, A0_3634.Properties.signalmodifier_InboundModifier)
end
function ArkCystoidNest.Event_Trigger(A0_3635, A1_3636, A2_3637)
  Ark.TriggerCystoidNest(A0_3635.id, A2_3637.id)
end
ArkCystoidNest.FlowEvents = {
  Inputs = {
    Trigger = {
      ArkCystoidNest.Event_Trigger,
      "entity"
    }
  },
  Outputs = {
    Triggered = "entity",
    Spawned = "entity",
    Exploded = "bool"
  }
}
