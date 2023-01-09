Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkRotator = {
  Properties = {
    object_Model = "",
    bDisallowGrenades = true,
    signalpackage_Hazard = "",
    Physics = {
      bPhysicalize = 1,
      Density = -1,
      Mass = -1
    },
    Disrupt = {
      disruptionProfile_Profile = "10739735956140218188",
      particleeffect_SparkVFX = "",
      audioTrigger_SparkSFX = ""
    }
  },
  bHasGoo = false,
  PropertiesInstance = {
    vSpeed = {
      x = 0,
      y = 0,
      z = 100
    },
    bUseWorldCoordSys = false,
    bStartsOn = 1,
    bVerbose = 0,
    GooHandler = {bBreaksGoo = 0, bTurnOnWhenNoGoo = true}
  },
  Editor = {
    IconOnTop = true,
    Icon = "animobject.bmp",
    ShowBounds = 0,
    IsScalable = false
  }
}
GetArkEntityUtils(ArkRotator)
SetupCollisionFiltering(ArkRotator)
function ArkRotator.Init(A0_4493)
  local L1_4494
end
function ArkRotator.SetFromProperties(A0_4495)
  A0_4495:SetupModelAndPhysics()
  A0_4495.m_bVerbose = A0_4495.PropertiesInstance.bVerbose == 1
end
function ArkRotator.OnPropertyChange(A0_4496)
  A0_4496:Log("OnPropertyChange")
  A0_4496:SetFromProperties()
end
function ArkRotator.OnReset(A0_4497)
  A0_4497.bHasGoo = 0
  A0_4497:SetFromProperties()
  A0_4497:Log("OnReset")
end
function ArkRotator.OnSpawn(A0_4498)
  A0_4498:SetFromProperties()
  A0_4498:Log("OnSpawn")
end
function ArkRotator.OnInit(A0_4499)
  A0_4499:Log("OnInit")
end
function ArkRotator.Event_On(A0_4500)
  A0_4500:Log("Event_On")
  Ark.SetArkRotatorActive(A0_4500.id, 1)
end
function ArkRotator.Event_Off(A0_4501)
  A0_4501:Log("Event_Off")
  Ark.SetArkRotatorActive(A0_4501.id, 0)
end
ArkRotator.FlowEvents = {
  Inputs = {
    Off = {
      ArkRotator.Event_Off,
      "bool"
    },
    On = {
      ArkRotator.Event_On,
      "bool"
    }
  },
  Outputs = {Off = "bool", On = "bool"}
}
