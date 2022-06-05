Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkAlienJelly = {
  ai = 1,
  Properties = {
    object_Model = "",
    metaTags_ArkMetaTags = "",
    signalpackage_DamagePackage = "",
    signalpackage_EnergizedDamagePackage = "",
    signalmodifier_InboundModifier = "",
    fHealth = 100,
    nExplodeDelay = 1000,
    nEnergizeDuration = 100,
    nLureDelay = 500,
    nTargetRefreshDelay = 1500,
    nInvalidTargetDelay = 5000,
    nStunDuration = 500,
    fEnergizedAttackProximity = 0.85,
    fMinMovementPeriod = 2,
    fMaxMovementPeriod = 4,
    metaTags_TagsToIgnore = "9469288860498988665",
    scanningDisplayName = "@loc_15373294129887561160",
    ZeroG = {
      fExplosionImpulseScale = 200,
      fMinSpeed = 2,
      fMaxSpeed = 5,
      fDeceleration = 3.5,
      fHomingProximity = 10,
      fDeactivationProximity = 15,
      fAttackProximity = 1,
      fDamageRange = 3,
      fDamageRangeOuter = 3,
      fInnerImpulseRange = 3,
      fOuterImpulseRange = 6,
      cameraShake_CameraShake = "10739735956147043737",
      fFlockingTetherRange = 10,
      fTargetSpeedThreshold = 2.5,
      fPlayerSpeedThreshold = 1,
      fCystoidSpeedThreshold = 0.3,
      nRandomImpulseMinDelay = -1,
      nRandomImpulseMaxDelay = -1,
      fRandomImpulseMagnitude = 0
    },
    OneG = {
      fExplosionImpulseScale = 350,
      fMinSpeed = 2,
      fMaxSpeed = 5,
      fDeceleration = 3.5,
      fHomingProximity = 12,
      fDeactivationProximity = 15,
      fAttackProximity = 1,
      fDamageRange = 4,
      fDamageRangeOuter = 4,
      fInnerImpulseRange = 4,
      fOuterImpulseRange = 6,
      cameraShake_CameraShake = "10739735956147043737",
      nMaxTimeOffGround = 100,
      fFlockingTetherRange = 10,
      fTargetSpeedThreshold = 2.5,
      fPlayerSpeedThreshold = 2,
      fCystoidSpeedThreshold = 1.5,
      nRandomImpulseMinDelay = 2000,
      nRandomImpulseMaxDelay = 5000,
      fRandomImpulseMagnitude = 2
    },
    faction_ArkFaction = "17591291352619661944",
    signalGroup_Damage = "3149325216937655803",
    signalGroup_Trigger = "",
    signal_NullWave = "3149325216915549045",
    signal_LureSignal = "10641886185830929654",
    fNullWaveDeaccumulation = 0.5,
    EnergizeSignals = {signal_Laser = ""},
    StunSignals = {
      signal_Impact = "",
      signal_RecycleGrenade = "",
      signal_Explosion = "3149325216913726733"
    },
    Effects = {
      particleeffect_Active = "",
      particleeffect_Dormant = "",
      particleeffect_Proximity = "",
      particleeffect_Explode = "",
      particleeffect_SpawnedByWeaver = "",
      particleeffect_Energized = ""
    },
    Sound = {
      audioTrigger_FollowStart = "",
      audioTrigger_FollowStop = "",
      audioTrigger_AttackStart = "",
      audioTrigger_AttackStop = "",
      audioTrigger_Explode = "",
      audioTrigger_DamagePlayer = "",
      audioTrigger_ExistStart = "",
      audioTrigger_ExistStop = ""
    },
    Physics = {
      signalpackage_collisionDamagePackage = "",
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
    }
  },
  Editor = {
    Icon = "animobject.bmp",
    IconOnTop = 1,
    ArchetypeEntityObjectClassName = "Entity::ArkNpcSpawnCystoid"
  },
  PropertiesInstance = {bAutoDisable = 1}
}
GetArkEntityUtils(ArkAlienJelly)
SetupCollisionFiltering(ArkAlienJelly)
function ArkAlienJelly.OnSpawn(A0_3429)
  Ark.AttachInboundSignalModifier(A0_3429.id, A0_3429.Properties.signalmodifier_InboundModifier)
end
function ArkAlienJelly.Event_Dead(A0_3430)
  BroadcastEvent(A0_3430, "Dead")
end
function ArkAlienJelly.Event_Rest(A0_3431)
  BroadcastEvent(A0_3431, "Rest")
end
function ArkAlienJelly.Event_Follow(A0_3432, A1_3433, A2_3434)
  Ark.ForceCystoidToFollow(A0_3432.id, A2_3434.id)
end
function ArkAlienJelly.Event_Attack(A0_3435)
  BroadcastEvent(A0_3435, "Attack")
end
function ArkAlienJelly.Event_ResumeAI(A0_3436)
  BroadcastEvent(A0_3436, "ResumeAI")
end
ArkAlienJelly.FlowEvents = {
  Inputs = {
    Rest = {
      ArkAlienJelly.Event_Rest,
      "bool"
    },
    Follow = {
      ArkAlienJelly.Event_Follow,
      "entity"
    },
    Attack = {
      ArkAlienJelly.Event_Attack,
      "bool"
    },
    ResumeAI = {
      ArkAlienJelly.Event_ResumeAI,
      "bool"
    }
  },
  Outputs = {
    Rest = "bool",
    Follow = "bool",
    Attack = "bool",
    Explode = "bool"
  }
}
