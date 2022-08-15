Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkLaserTripline = {
  type = "ArkLaserTripline",
  Properties = {
    object_Model = "",
    textDisplayName = "",
    bHideDisplayName = false,
    color_BeamColor = {
      x = 0,
      y = 1,
      z = 0
    },
    fVisibleBeamLengthStart = 0.3,
    fVisibleBeamLengthEnd = 0.2,
    ability_DisarmRequirement = "",
    signalgroup_Damage = "3149325216937655803",
    vector_InteractionOffset = {
      x = 0,
      y = 0,
      z = 0
    },
    Disrupt = {
      disruptionProfile_Profile = "10739735956140212131",
      particleeffect_SparkVFX = "",
      audioTrigger_SparkSFX = ""
    },
    Physics = {
      bPhysicalize = 1,
      bRigidBody = 0,
      bPushableByPlayers = 0,
      bPushableByAI = 0,
      bResting = 1,
      Density = -1,
      Mass = -1,
      bArticulated = 0,
      bBulletCollisionEnabled = 1
    }
  },
  PropertiesInstance = {bEnabledAtStartup = true},
  Editor = {
    Model = "Editor/Objects/T.cgf",
    Icon = "elevator.bmp",
    ShowBounds = 0,
    IsScalable = false,
    IsRotatable = true
  }
}
GetArkEntityUtils(ArkLaserTripline)
SetupCollisionFiltering(ArkLaserTripline)
function ArkLaserTripline.SetFromProperties(A0_4203)
  A0_4203:Log("OnPostLoad")
  A0_4203:SetupModelAndPhysics()
end
function ArkLaserTripline.OnReset(A0_4204, A1_4205)
  A0_4204:SetFromProperties()
end
function ArkLaserTripline.OnSpawn(A0_4206)
  A0_4206:SetFromProperties()
end
function ArkLaserTripline.Event_Enable(A0_4207)
  BroadcastEvent(A0_4207, "Enable")
end
function ArkLaserTripline.Event_Disable(A0_4208)
  BroadcastEvent(A0_4208, "Disable")
end
ArkLaserTripline.FlowEvents = {
  Inputs = {
    Disable = {
      ArkLaserTripline.Event_Disable,
      "bool"
    },
    Enable = {
      ArkLaserTripline.Event_Enable,
      "bool"
    }
  },
  Outputs = {
    Disabled = "bool",
    Enabled = "bool",
    Entered = "int",
    Disarmed = "bool",
    Damaged = "bool"
  }
}
