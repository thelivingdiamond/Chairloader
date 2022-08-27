Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkElectricalBox = {
  Properties = {
    object_Model = "",
    object_ModelBroken = "",
    signalpackage_Hazard = "",
    archetype_LightningArc = "ArkGameplayObjects.LightningArc.LightningArc_ElectricalBox",
    nElectricArcs = 1,
    nSparkInterval = 1000,
    nSparkVariation = 100,
    nGooSparkWarningTime = 2000,
    nGooBreakWarningTime = 1000,
    fHazardRadius = 1,
    nMaxTargets = 1,
    fHealth = 100,
    signal_GooSignal = "3149325216915549017",
    fMaxGooAccumulation = 128,
    fGooDrainRate = 20,
    fGooDecalSize = 2,
    material_GooDecal = "Materials/ArkEffects/Weapons/Gloogun/Gloogun_Decal_Hard_00",
    vector_GooDecalOffset = {
      x = -0.85,
      y = 0,
      z = 0.75
    },
    vector_ElectricalArcOffset = {
      x = 0,
      y = 0,
      z = 0
    },
    vector_ElectricalArcOffset2 = {
      x = 0,
      y = 0,
      z = 0
    },
    vector_ElectricalArcOffset3 = {
      x = 0,
      y = 0,
      z = 0
    },
    signalGroup_Damage = "3149325216937655803",
    signalmodifier_SignalModifier = "5310807215636213104",
    textCorpseName = "@npc_broken",
    fInstigationDecayTime = 5,
    bInteractIgnoresGloo = 1,
    fPlayerZeroGImpulseScale = 10,
    Repair = {
      textPromptItemRequired = "",
      textDisplayName = "",
      textDisplayNameBroken = "",
      nSparePartsRequired = 1,
      nHoldToUseDuration = 1000,
      ability_RepairRequirement = "",
      archetype_RepairItem = "",
      bRepairable = 1,
      fRepairIconRange = 10
    },
    Fortify = {
      nHoldToUseDuration = 1000,
      archetype_FortifyItem = "",
      ability_FortifyRequirement = "3149325216929347161",
      nSparePartsRequired = 0,
      bFortifiable = 1,
      textFortifyVerb = ""
    },
    Disrupt = {
      disruptionProfile_Profile = "10739735956140212131",
      particleeffect_SparkVFX = "",
      audioTrigger_SparkSFX = ""
    },
    Effects = {
      material_electricalArc = "",
      particleeffect_FlashVFX = "",
      particleeffect_IdleVFX = "",
      particleeffect_WarningVFX = ""
    },
    Sound = {
      audioTrigger_IntactLoop = "",
      audioTrigger_HazardLoop = "",
      audioTrigger_PowerOff = "",
      audioTrigger_Zap = "",
      audioTrigger_RepairLoop = "",
      audioTrigger_RepairStop = "",
      audioTrigger_WarningLoop = "",
      audioTrigger_WarningStop = ""
    },
    Physics = {
      bPhysicalize = 1,
      bRigidBody = 0,
      bPushableByPlayers = 0,
      bPushableByAI = 0,
      bResting = 1,
      bRigidBodyActive = 1,
      Density = -1,
      Mass = -1
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
  TargetClassBlackList = {
    LightningArc = true,
    EnvironmentLight = true,
    GeomEntity = true,
    ArkElectricalBox = true,
    SinglePlayer = true,
    ExtendedClip = true,
    NoWeapon = true,
    SoundListener = true,
    ArkProjectileEMPGrenade = true,
    ArkProjectileGoo = true,
    ArkProjectileGooBall = true,
    ArkProjectileHomingPsiBlast = true,
    ArkProjectileLureGrenade = true,
    ArkProjectileNullwaveTransmitter = true,
    ArkProjectilePistolBullet = true,
    ArkProjectileRecyclerGrenade = true,
    ArkProjectileShotgunBlast = true,
    ArkProjectileShotgunShell = true,
    ArkProjectileStunGun = true,
    ArkProjectileTracer = true,
    ArkProjectileTurretBullet = true,
    ArkTechnopathEMPHazard = true
  },
  Editor = {
    Icon = "Lightning.bmp",
    IconOnTop = 1,
    IsScalable = false
  },
  PropertiesInstance = {
    bStartsBroken = 0,
    bStartsPowered = 1,
    bVerbose = 0
  }
}
GetArkEntityUtils(ArkElectricalBox)
SetupCollisionFiltering(ArkElectricalBox)
ArkMakeSaveable(ArkElectricalBox)
ArkElectricalBoxInstanceVars = {
  m_bVerbose = false,
  m_bInit = false,
  m_referenceTable = false,
  m_activatorId = NULL_ENTITY
}
function CreateElectricalBox(A0_3703)
  mergef(A0_3703, ArkElectricalBoxInstanceVars, 1)
  A0_3703.m_referenceTable = ArkElectricalBoxInstanceVars
end
function ArkElectricalBox.Init(A0_3704, A1_3705)
  local L2_3706
  L2_3706 = A0_3704.Properties
  if not A0_3704.m_bInit then
    A0_3704:Log("Initializing...")
    A0_3704.m_bInit = true
    if A1_3705 then
      A0_3704:Activate(1)
    end
  end
end
function ArkElectricalBox.SetFromProperties(A0_3707)
  local L1_3708
  L1_3708 = A0_3707.Properties
  A0_3707.m_bVerbose = A0_3707.PropertiesInstance.bVerbose == 1
  A0_3707:SetDisplayName(L1_3708.Repair.textDisplayName)
  Ark.RemoveInboundSignalModifier(A0_3707.id, L1_3708.signalmodifier_SignalModifier)
  Ark.AttachInboundSignalModifier(A0_3707.id, L1_3708.signalmodifier_SignalModifier)
end
function ArkElectricalBox.OnPropertyChange(A0_3709)
  if A0_3709.PropertiesInstance.bStartsBroken == 1 then
    A0_3709:LoadObject(0, A0_3709.Properties.object_ModelBroken)
  else
    A0_3709:SetupModelAndPhysics()
  end
end
function ArkElectricalBox.Event_Repair(A0_3710)
  BroadcastEvent(A0_3710, "Repair")
end
function ArkElectricalBox.Event_Break(A0_3711)
  BroadcastEvent(A0_3711, "Break")
end
function ArkElectricalBox.OnReset(A0_3712, A1_3713)
  A0_3712:Log("OnReset")
  A0_3712.m_bInit = false
  A0_3712.m_activatorId = A0_3712.id
  A0_3712:Activate(0)
  A0_3712:SetFromProperties()
end
function ArkElectricalBox.OnSpawn(A0_3714)
  CreateElectricalBox(A0_3714)
  A0_3714:Log("OnSpawn")
  A0_3714:SetFromProperties()
end
function ArkElectricalBox.OnPostLoad(A0_3715)
  A0_3715:Activate(1)
end
function ArkElectricalBox.OnSetBroken(A0_3716, A1_3717)
  if A1_3717 then
    A0_3716:LoadObject(0, A0_3716.Properties.object_ModelBroken)
    A0_3716:PhysicalizeThis()
  else
    A0_3716:SetupModelAndPhysics()
  end
end
function ArkElectricalBox.Event_PowerOn(A0_3718)
  Ark.SetElectricalBoxPowered(A0_3718.id, true, A0_3718.m_activatorId)
  BroadcastEvent(A0_3718, "PoweredOn")
end
function ArkElectricalBox.Event_PowerOff(A0_3719)
  Ark.SetElectricalBoxPowered(A0_3719.id, false, A0_3719.m_activatorId)
  BroadcastEvent(A0_3719, "PoweredOff")
end
function ArkElectricalBox.Event_Activator(A0_3720, A1_3721, A2_3722)
  A0_3720.m_activatorId = A2_3722.id
end
ArkElectricalBox.FlowEvents = {
  Inputs = {
    PowerOn = {
      ArkElectricalBox.Event_PowerOn,
      "bool"
    },
    PowerOff = {
      ArkElectricalBox.Event_PowerOff,
      "bool"
    },
    Repair = {
      ArkElectricalBox.Event_Repair,
      "bool"
    },
    Break = {
      ArkElectricalBox.Event_Break,
      "bool"
    },
    Activator = {
      ArkElectricalBox.Event_Activator,
      "entity"
    }
  },
  Outputs = {
    PreExplode = "bool",
    Explode = "bool",
    Hazard = "bool",
    Destroyed = "bool",
    StrikeTime = "float",
    PoweredOn = "bool",
    Spark = "bool",
    PoweredOff = "bool",
    Repaired = "bool",
    EntityId = "entity"
  }
}
