Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkMedbay = {
  Properties = {
    object_Model = "",
    sEnabledMessage = "",
    sDisabledMessage = "",
    ei_ObjectMapIcon = "",
    Physics = {
      bPhysicalize = 1,
      bRigidBody = 0,
      bPushableByPlayers = 0,
      bPushableByAI = 0,
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
  States = {"Enabled", "Disabled"},
  PropertiesInstance = {
    bUsable = 1,
    bStartsEnabled = 1,
    bVerbose = 0
  },
  Editor = {Icon = "health.bmp", IconOnTop = 1}
}
MedbayInstanceVars = {
  m_bVerbose = false,
  m_bEnabled = false,
  m_bUsable = false,
  m_referenceTable = false,
  m_usableMessage = ""
}
GetArkEntityUtils(ArkMedbay)
function CreateMedbay(A0_4296)
  mergef(A0_4296, MedbayInstanceVars, 1)
  A0_4296.m_referenceTable = MedbayInstanceVars
end
function ArkMedbay.Init(A0_4297)
  A0_4297:SetFromProperties()
  if A0_4297.m_bEnabled then
    A0_4297:GotoState("Enabled")
  else
    A0_4297:GotoState("Disabled")
  end
end
function ArkMedbay.SetFromProperties(A0_4298)
  A0_4298:Log("Setting from properties")
  A0_4298.m_bVerbose = A0_4298.PropertiesInstance.bVerbose == 1
  A0_4298.m_bEnabled = A0_4298.PropertiesInstance.bStartsEnabled == 1
  A0_4298.m_bUsable = A0_4298.PropertiesInstance.bUsable == 1
  A0_4298:SetupModelAndPhysics()
end
function ArkMedbay.GetUsable(A0_4299)
  local L2_4300
  L2_4300 = {}
  if A0_4299.m_bUsable then
    ({}).ActionType = "ScriptDefined"
    L2_4300.Use, ({}).DisplayText = {}, "@use_object"
  end
  return L2_4300
end
function ArkMedbay.GetRemoteManipulationInteraction(A0_4301)
  local L1_4302
  L1_4302 = {}
  L1_4302.ActionType = "ScriptDefined"
  L1_4302.DisplayText = "@use_object"
  L1_4302.CouldChange = false
  return L1_4302
end
function ArkMedbay.Event_Enable(A0_4303)
  A0_4303:GotoState("Enabled")
end
function ArkMedbay.Event_Disable(A0_4304)
  A0_4304:GotoState("Disabled")
end
function ArkMedbay.OnUsed(A0_4305, A1_4306)
  A0_4305:Log("OnUsed")
  BroadcastEvent(A0_4305, "Used")
end
function ArkMedbay.OnRemoteManipulation(A0_4307, A1_4308)
  A0_4307:Log("OnUsed")
  BroadcastEvent(A0_4307, "Used")
end
function ArkMedbay.OnReset(A0_4309)
  A0_4309:Log("OnReset")
  A0_4309:SetFromProperties()
end
function ArkMedbay.OnSpawn(A0_4310)
  CreateMedbay(A0_4310)
  A0_4310:Log("OnSpawn")
end
ArkMedbay.Enabled = {
  OnStartLevel = function(A0_4311)
    A0_4311:OnStartLevel()
  end,
  OnBeginState = function(A0_4312)
    A0_4312:Log("Enabled state begin")
    A0_4312.m_bEnabled = true
    A0_4312.m_bUsable = A0_4312.PropertiesInstance.bUsable == 1
    A0_4312.m_usableMessage = A0_4312.Properties.sEnabledMessage
    A0_4312:SetDisplayName(A0_4312.m_usableMessage)
    BroadcastEvent(A0_4312, "Enabled")
  end,
  OnEndState = function(A0_4313)
    A0_4313:Log("Enabled state end")
  end
}
ArkMedbay.Disabled = {
  OnStartLevel = function(A0_4314)
    A0_4314:OnStartLevel()
  end,
  OnBeginState = function(A0_4315)
    A0_4315:Log("Disabled state begin")
    A0_4315.m_bEnabled = false
    A0_4315.m_bUsable = A0_4315.PropertiesInstance.bUsable == 1
    A0_4315.m_usableMessage = A0_4315.Properties.sDisabledMessage
    A0_4315:SetDisplayName(A0_4315.m_usableMessage)
    BroadcastEvent(A0_4315, "Disabled")
  end,
  OnEndState = function(A0_4316)
    A0_4316:Log("Disabled state end")
  end
}
ArkMedbay.FlowEvents = {
  Inputs = {
    Enable = {
      ArkMedbay.Event_Enable,
      "bool"
    },
    Disable = {
      ArkMedbay.Event_Disable,
      "bool"
    }
  },
  Outputs = {
    Used = "bool",
    Enabled = "bool",
    Disabled = "bool"
  }
}
