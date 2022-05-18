Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkSceneWindow = {
  Properties = {
    object_Model = "",
    Physics = {
      bPhysicalize = 1,
      bRigidBody = 0,
      bResting = 1,
      bPushableByPlayers = 0,
      bPushableByAI = 0,
      Density = 100,
      Mass = -1
    }
  },
  Editor = {
    Icon = "physicsobject.bmp",
    IconOnTop = 1
  },
  PropertiesInstance = {bVerbose = 0}
}
ArkSceneWindowInstanceVars = {m_bVerbose = false}
GetArkEntityUtils(ArkSceneWindow)
function CreateArkSceneWindow(A0_4502)
  mergef(A0_4502, ArkSceneWindowInstanceVars, 1)
  A0_4502.m_referenceTable = ArkSceneWindowInstanceVars
end
function ArkSceneWindow.OnInit(A0_4503, A1_4504)
  A0_4503:Log("OnInit")
  A0_4503:SetFromProperties()
  Ark.RegisterForAllSignals(A0_4503.id)
end
function ArkSceneWindow.SetFromProperties(A0_4505)
  A0_4505:Log("SetFromProperties")
  A0_4505:SetupModelAndPhysics()
  if not A0_4505:IsHidden() then
    A0_4505:EnablePhysics(1)
  end
  A0_4505:SetAsSceneWindow(true)
  A0_4505.m_bVerbose = A0_4505.PropertiesInstance.bVerbose == 1
end
function ArkSceneWindow.OnReset(A0_4506)
  A0_4506:SetFromProperties()
end
function ArkSceneWindow.OnSpawn(A0_4507)
  CreateArkSceneWindow(A0_4507)
end
function ArkSceneWindow.OnPackageReceived(A0_4508, A1_4509, A2_4510)
  BroadcastEvent(A0_4508, "Hit")
end
function ArkSceneWindow.OnBreakable2d(A0_4511)
  BroadcastEvent(A0_4511, "Broken")
end
function ArkSceneWindow.Event_Hide(A0_4512)
  A0_4512:Hide(1)
  A0_4512:ActivateOutput("Hide", true)
end
function ArkSceneWindow.Event_UnHide(A0_4513)
  A0_4513:Hide(0)
  A0_4513:ActivateOutput("UnHide", true)
end
function ArkSceneWindow.Event_Enable(A0_4514)
  A0_4514:SetAsSceneWindow(true)
  A0_4514:ActivateOutput("Enabled", true)
end
function ArkSceneWindow.Event_Disable(A0_4515)
  A0_4515:SetAsSceneWindow(false)
  A0_4515:ActivateOutput("Disabled", true)
end
ArkSceneWindow.FlowEvents = {
  Inputs = {
    Hide = {
      ArkSceneWindow.Event_Hide,
      "bool"
    },
    UnHide = {
      ArkSceneWindow.Event_UnHide,
      "bool"
    },
    Enable = {
      ArkSceneWindow.Event_Enable,
      "bool"
    },
    Disable = {
      ArkSceneWindow.Event_Disable,
      "bool"
    }
  },
  Outputs = {
    Hide = "bool",
    UnHide = "bool",
    Enabled = "bool",
    Disabled = "bool",
    Hit = "bool",
    Broken = "bool"
  }
}
