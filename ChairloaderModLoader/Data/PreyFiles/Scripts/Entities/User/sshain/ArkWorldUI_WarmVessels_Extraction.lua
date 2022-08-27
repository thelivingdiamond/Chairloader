Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkWorldUI_WarmVessels_Extraction = {
  Properties = {
    object_Model = "Objects/User/ebeyhl/Monitor_Extraction_A/monitor_extraction_a_screen.cga",
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
      defaultLabel = "Extract Sample",
      readyLabel = "Extraction Complete",
      isEnabled = false
    },
    container = {
      id = 2,
      defaultLabel = "Container Required",
      readyLabel = "Container Ready",
      isEnabled = false
    }
  },
  m_uiElementName = "DanielleKiosk",
  m_screenBone = 1,
  m_subMatIndex = 0,
  m_instanceId = -1,
  m_fInteractDist = 2,
  m_bVerbose = false,
  m_bInit = false,
  m_bIsContainerReady = false
}
GetArkEntityUtils(ArkWorldUI_WarmVessels_Extraction)
function ArkWorldUI_WarmVessels_Extraction.Init(A0_9026)
  if not A0_9026.m_bInit then
    A0_9026:Log("Initializing...")
    A0_9026.m_bInit = true
    A0_9026:SetFromProperties()
    A0_9026:SetupScreen()
    A0_9026:SetupButtons()
  end
end
function ArkWorldUI_WarmVessels_Extraction.SetupScreen(A0_9027)
  A0_9027:Log("SetupScreen")
  A0_9027.m_instanceId = A0_9027:GetRawId()
  Ark.SetWorldUIEntity(A0_9027.id, A0_9027.m_instanceId, A0_9027:GetMaterial(0), A0_9027.m_uiElementName, A0_9027.m_subMatIndex)
  Ark.SetWorldUIDistances(A0_9027.m_instanceId, A0_9027.m_uiElementName, A0_9027.m_fInteractDist, 20, 80)
  UIAction.UnregisterElementListener(A0_9027, "")
  UIAction.RegisterElementListener(A0_9027, A0_9027.m_uiElementName, A0_9027.m_instanceId, "KioskBtnPress", "OnButtonPress")
end
function ArkWorldUI_WarmVessels_Extraction.SetupButtons(A0_9028)
  for _FORV_4_, _FORV_5_ in pairs(A0_9028.m_buttons) do
    UIAction.CallFunction(A0_9028.m_uiElementName, A0_9028.m_instanceId, "setButton", _FORV_5_.id, _FORV_5_.defaultLabel, _FORV_5_.isEnabled)
  end
end
function ArkWorldUI_WarmVessels_Extraction.EnableExtractionButton(A0_9029)
  local L1_9030
  L1_9030 = A0_9029.m_bIsContainerReady
  if L1_9030 then
    L1_9030 = A0_9029.m_buttons
    L1_9030 = L1_9030.extraction
    UIAction.CallFunction(A0_9029.m_uiElementName, A0_9029.m_instanceId, "setButton", L1_9030.id, L1_9030.defaultLabel, true)
  end
end
function ArkWorldUI_WarmVessels_Extraction.IsUsable(A0_9031, A1_9032)
  local L2_9033
  L2_9033 = 0
  if A0_9031.m_bIsContainerReady then
    L2_9033 = 1
  end
  return L2_9033
end
function ArkWorldUI_WarmVessels_Extraction.GetUsableMessage(A0_9034, A1_9035)
  local L2_9036
  L2_9036 = "use"
  return L2_9036
end
function ArkWorldUI_WarmVessels_Extraction.OnUsed(A0_9037, A1_9038, A2_9039)
  UIAction.CallFunction(A0_9037.m_uiElementName, A0_9037.m_instanceId, "kioskInteract")
end
function ArkWorldUI_WarmVessels_Extraction.OnButtonPress(A0_9040, A1_9041, A2_9042, A3_9043, A4_9044)
  local L5_9045
  L5_9045 = A4_9044[0]
  A0_9040:Log("Button pressed:" .. L5_9045)
  if L5_9045 == A0_9040.m_buttons.extraction.id then
    BroadcastEvent(A0_9040, "StartExtraction")
    UIAction.CallFunction(A0_9040.m_uiElementName, A0_9040.m_instanceId, "setButton", A0_9040.m_buttons.extraction.id, "Extraction In Progress", false)
    A0_9040.m_bIsContainerReady = false
  end
end
function ArkWorldUI_WarmVessels_Extraction.Event_IsContainerPresent(A0_9046)
  A0_9046:Log("Is Container Present")
  UIAction.CallFunction(A0_9046.m_uiElementName, A0_9046.m_instanceId, "setButton", A0_9046.m_buttons.container.id, A0_9046.m_buttons.container.readyLabel, false)
  A0_9046.m_bIsContainerReady = true
  A0_9046:EnableExtractionButton()
end
function ArkWorldUI_WarmVessels_Extraction.Event_ExtractionComplete(A0_9047)
  A0_9047:Log("EXTRACTION COMPLETE!")
  UIAction.CallFunction(A0_9047.m_uiElementName, A0_9047.m_instanceId, "setButton", A0_9047.m_buttons.extraction.id, A0_9047.m_buttons.extraction.readyLabel, false)
end
function ArkWorldUI_WarmVessels_Extraction.Event_Reset(A0_9048)
  A0_9048.m_bIsContainerReady = false
  A0_9048.m_bInit = false
  A0_9048:SetupButtons()
end
function ArkWorldUI_WarmVessels_Extraction.OnStartGame(A0_9049)
  A0_9049:Log("OnStartGame")
  A0_9049:Init()
end
function ArkWorldUI_WarmVessels_Extraction.OnReset(A0_9050)
  A0_9050:Log("OnReset ")
  if A0_9050.Properties.Physics.bPhysicalize == 1 then
    A0_9050:PhysicalizeThis()
    A0_9050:AwakePhysics(0)
  end
  A0_9050.m_bIsContainerReady = false
  A0_9050.m_bInit = false
end
ArkWorldUI_WarmVessels_Extraction.FlowEvents = {
  Inputs = {
    IsContainerPresent = {
      ArkWorldUI_WarmVessels_Extraction.Event_IsContainerPresent,
      "bool"
    },
    ExtractionComplete = {
      ArkWorldUI_WarmVessels_Extraction.Event_ExtractionComplete,
      "bool"
    },
    Reset = {
      ArkWorldUI_WarmVessels_Extraction.Event_Reset,
      "bool"
    }
  },
  Outputs = {StartExtraction = "bool"}
}
