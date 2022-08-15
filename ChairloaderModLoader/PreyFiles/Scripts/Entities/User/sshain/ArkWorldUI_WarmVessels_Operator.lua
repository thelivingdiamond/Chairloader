Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkWorldUI_WarmVessels_Operator = {
  Properties = {
    object_Model = "objects/user/ebeyhl/monitor_operator_a/monitor_operator_a_screen.cga",
    Physics = {
      bPhysicalize = 1,
      bRigidBody = 1,
      bPushableByPlayers = 1,
      Density = -1,
      Mass = -1
    }
  },
  Editor = {Icon = "Prefab.bmp", IconOnTop = 1},
  m_buttons = {
    extraction = {
      id = 1,
      defaultLabel = "Load Extraction Device",
      readyLabel = "Going to Extraction",
      isEnabled = true
    },
    liveExam = {
      id = 3,
      defaultLabel = "Send to Live Exam",
      readyLabel = "Going to Live Exam",
      isEnabled = true
    }
  },
  m_uiElementName = "DanielleKiosk",
  m_screenBone = 1,
  m_subMatIndex = 0,
  m_instanceId = -1,
  m_fInteractDist = 2,
  m_bVerbose = false,
  m_bInit = false,
  m_usable = 1
}
GetArkEntityUtils(ArkWorldUI_WarmVessels_Operator)
function ArkWorldUI_WarmVessels_Operator.Init(A0_9086)
  if not A0_9086.m_bInit then
    A0_9086:Log("Initializing...")
    A0_9086.m_bInit = true
    A0_9086:SetFromProperties()
    A0_9086:SetupScreen()
    A0_9086:SetupButtons()
  end
end
function ArkWorldUI_WarmVessels_Operator.SetupScreen(A0_9087)
  A0_9087:Log("SetupScreen")
  A0_9087.m_instanceId = A0_9087:GetRawId()
  Ark.SetWorldUIEntity(A0_9087.id, A0_9087.m_instanceId, A0_9087:GetMaterial(0), A0_9087.m_uiElementName, A0_9087.m_subMatIndex)
  Ark.SetWorldUIDistances(A0_9087.m_instanceId, A0_9087.m_uiElementName, A0_9087.m_fInteractDist, 20, 80)
  UIAction.UnregisterElementListener(A0_9087, "")
  UIAction.RegisterElementListener(A0_9087, A0_9087.m_uiElementName, A0_9087.m_instanceId, "KioskBtnPress", "OnButtonPress")
end
function ArkWorldUI_WarmVessels_Operator.SetupButtons(A0_9088)
  for _FORV_4_, _FORV_5_ in pairs(A0_9088.m_buttons) do
    UIAction.CallFunction(A0_9088.m_uiElementName, A0_9088.m_instanceId, "setButton", _FORV_5_.id, _FORV_5_.defaultLabel, _FORV_5_.isEnabled)
  end
end
function ArkWorldUI_WarmVessels_Operator.IsUsable(A0_9089, A1_9090)
  local L2_9091
  L2_9091 = A0_9089.m_usable
  return L2_9091
end
function ArkWorldUI_WarmVessels_Operator.GetUsableMessage(A0_9092, A1_9093)
  local L2_9094
  L2_9094 = "use"
  return L2_9094
end
function ArkWorldUI_WarmVessels_Operator.OnUsed(A0_9095, A1_9096, A2_9097)
  UIAction.CallFunction(A0_9095.m_uiElementName, A0_9095.m_instanceId, "kioskInteract")
end
function ArkWorldUI_WarmVessels_Operator.OnButtonPress(A0_9098, A1_9099, A2_9100, A3_9101, A4_9102)
  local L5_9103
  L5_9103 = A4_9102[0]
  A0_9098:Log("Button pressed:" .. L5_9103)
  if L5_9103 == A0_9098.m_buttons.liveExam.id then
    BroadcastEvent(A0_9098, "GotoLiveExamPressed")
  elseif L5_9103 == A0_9098.m_buttons.extraction.id then
    BroadcastEvent(A0_9098, "GotoExtractionPressed")
  else
    LogWarning(A0_9098:GetName() .. " got into a weird state and registered a button press for a button id that doesn't exist.")
    return
  end
  UIAction.CallFunction(A0_9098.m_uiElementName, A0_9098.m_instanceId, "setButton", A0_9098.m_buttons.extraction.id, A0_9098.m_buttons.extraction.readyLabel, false)
  A0_9098.m_usable = 0
end
function ArkWorldUI_WarmVessels_Operator.Event_Reset(A0_9104)
  A0_9104:Hide(0)
  A0_9104.m_usable = 1
  A0_9104:SetupButtons()
end
function ArkWorldUI_WarmVessels_Operator.Event_Hide(A0_9105)
  A0_9105:Hide(1)
  BroadcastEvent(A0_9105, "Hidden")
end
function ArkWorldUI_WarmVessels_Operator.Event_Unhide(A0_9106)
  A0_9106:Hide(0)
  BroadcastEvent(A0_9106, "Unhidden")
end
function ArkWorldUI_WarmVessels_Operator.Event_EnableGotoExtraction(A0_9107)
  A0_9107:Log("Event_EnableGotoExtraction")
  UIAction.CallFunction(A0_9107.m_uiElementName, A0_9107.m_instanceId, "setButton", A0_9107.m_buttons.extraction.id, A0_9107.m_buttons.extraction.defaultLabel, true)
  A0_9107.m_usable = 1
end
function ArkWorldUI_WarmVessels_Operator.Event_DisableGotoExtraction(A0_9108)
  A0_9108:Log("Event_DisableGotoExtraction")
  UIAction.CallFunction(A0_9108.m_uiElementName, A0_9108.m_instanceId, "setButton", A0_9108.m_buttons.extraction.id, A0_9108.m_buttons.extraction.defaultLabel, false)
end
function ArkWorldUI_WarmVessels_Operator.Event_EnableGotoLiveExam(A0_9109)
  A0_9109:Log("Event_EnableGotoLiveExam")
  UIAction.CallFunction(A0_9109.m_uiElementName, A0_9109.m_instanceId, "setButton", A0_9109.m_buttons.liveExam.id, A0_9109.m_buttons.liveExam.defaultLabel, true)
  A0_9109.m_usable = 1
end
function ArkWorldUI_WarmVessels_Operator.Event_DisableGotoLiveExam(A0_9110)
  A0_9110:Log("Event_DisableGotoLiveExam")
  UIAction.CallFunction(A0_9110.m_uiElementName, A0_9110.m_instanceId, "setButton", A0_9110.m_buttons.liveExam.id, A0_9110.m_buttons.liveExam.defaultLabel, false)
end
function ArkWorldUI_WarmVessels_Operator.OnStartGame(A0_9111)
  A0_9111:Log("OnStartGame")
  A0_9111:Init()
end
function ArkWorldUI_WarmVessels_Operator.OnReset(A0_9112)
  A0_9112:Log("OnReset ")
  if A0_9112.Properties.Physics.bPhysicalize == 1 then
    A0_9112:PhysicalizeThis()
    A0_9112:AwakePhysics(0)
  end
  A0_9112.m_bInit = false
  A0_9112.m_usable = 1
end
ArkWorldUI_WarmVessels_Operator.FlowEvents = {
  Inputs = {
    Hide = {
      ArkWorldUI_WarmVessels_Operator.Event_Hide,
      "bool"
    },
    Unhide = {
      ArkWorldUI_WarmVessels_Operator.Event_Unhide,
      "bool"
    },
    Reset = {
      ArkWorldUI_WarmVessels_Operator.Event_Reset,
      "bool"
    },
    EnableGotoExtraction = {
      ArkWorldUI_WarmVessels_Operator.Event_EnableGotoExtraction,
      "bool"
    },
    DisableGotoExtraction = {
      ArkWorldUI_WarmVessels_Operator.Event_DisableGotoExtraction,
      "bool"
    },
    EnableGotoLiveExam = {
      ArkWorldUI_WarmVessels_Operator.Event_EnableGotoLiveExam,
      "bool"
    },
    DisableGotoLiveExam = {
      ArkWorldUI_WarmVessels_Operator.Event_DisableGotoLiveExam,
      "bool"
    }
  },
  Outputs = {
    GotoExtractionPressed = "bool",
    GotoLiveExamPressed = "bool",
    Hidden = "bool",
    Unhidden = "bool"
  }
}
