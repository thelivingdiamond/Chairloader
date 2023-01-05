Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkWorldUI_WarmVessels_LiveExam = {
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
    liveExam = {
      id = 1,
      defaultLabel = "Sample Required",
      readyLabel = "Release to Live Exam",
      isEnabled = false
    },
    purge = {
      id = 2,
      defaultLabel = "Purge",
      readyLabel = "Purging",
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
  m_usable = 0
}
GetArkEntityUtils(ArkWorldUI_WarmVessels_LiveExam)
function ArkWorldUI_WarmVessels_LiveExam.Init(A0_9061)
  if not A0_9061.m_bInit then
    A0_9061:Log("Initializing...")
    A0_9061.m_bInit = true
    A0_9061:SetFromProperties()
    A0_9061:SetupScreen()
    A0_9061:SetupButtons()
  end
end
function ArkWorldUI_WarmVessels_LiveExam.SetupScreen(A0_9062)
  A0_9062:Log("SetupScreen")
  A0_9062.m_instanceId = A0_9062:GetRawId()
  Ark.SetWorldUIEntity(A0_9062.id, A0_9062.m_instanceId, A0_9062:GetMaterial(0), A0_9062.m_uiElementName, A0_9062.m_subMatIndex)
  Ark.SetWorldUIDistances(A0_9062.m_instanceId, A0_9062.m_uiElementName, A0_9062.m_fInteractDist, 20, 80)
  UIAction.UnregisterElementListener(A0_9062, "")
  UIAction.RegisterElementListener(A0_9062, A0_9062.m_uiElementName, A0_9062.m_instanceId, "KioskBtnPress", "OnButtonPress")
end
function ArkWorldUI_WarmVessels_LiveExam.SetupButtons(A0_9063)
  for _FORV_4_, _FORV_5_ in pairs(A0_9063.m_buttons) do
    UIAction.CallFunction(A0_9063.m_uiElementName, A0_9063.m_instanceId, "setButton", _FORV_5_.id, _FORV_5_.defaultLabel, _FORV_5_.isEnabled)
  end
end
function ArkWorldUI_WarmVessels_LiveExam.IsUsable(A0_9064, A1_9065)
  local L2_9066
  L2_9066 = A0_9064.m_usable
  return L2_9066
end
function ArkWorldUI_WarmVessels_LiveExam.GetUsableMessage(A0_9067, A1_9068)
  local L2_9069
  L2_9069 = "use"
  return L2_9069
end
function ArkWorldUI_WarmVessels_LiveExam.OnUsed(A0_9070, A1_9071, A2_9072)
  UIAction.CallFunction(A0_9070.m_uiElementName, A0_9070.m_instanceId, "kioskInteract")
end
function ArkWorldUI_WarmVessels_LiveExam.OnButtonPress(A0_9073, A1_9074, A2_9075, A3_9076, A4_9077)
  local L5_9078
  L5_9078 = A4_9077[0]
  A0_9073:Log("Button pressed:" .. L5_9078)
  if L5_9078 == A0_9073.m_buttons.liveExam.id then
    UIAction.CallFunction(A0_9073.m_uiElementName, A0_9073.m_instanceId, "setButton", L5_9078, "Releasing Sample", false)
    BroadcastEvent(A0_9073, "LiveExamPressed")
  elseif L5_9078 == A0_9073.m_buttons.purge.id then
    UIAction.CallFunction(A0_9073.m_uiElementName, A0_9073.m_instanceId, "setButton", L5_9078, A0_9073.m_buttons.purge.readyLabel, false)
    BroadcastEvent(A0_9073, "PurgePressed")
  end
end
function ArkWorldUI_WarmVessels_LiveExam.Event_EnablePurge(A0_9079)
  A0_9079:Log("Event_EnablePurge")
  UIAction.CallFunction(A0_9079.m_uiElementName, A0_9079.m_instanceId, "setButton", A0_9079.m_buttons.purge.id, A0_9079.m_buttons.purge.defaultLabel, true)
  A0_9079.m_usable = 1
end
function ArkWorldUI_WarmVessels_LiveExam.Event_DisablePurge(A0_9080)
  A0_9080:Log("Event_DisablePurge")
  UIAction.CallFunction(A0_9080.m_uiElementName, A0_9080.m_instanceId, "setButton", A0_9080.m_buttons.purge.id, A0_9080.m_buttons.purge.defaultLabel, false)
  A0_9080.m_usable = 0
end
function ArkWorldUI_WarmVessels_LiveExam.Event_EnableLiveExam(A0_9081)
  A0_9081:Log("Event_EnableLiveExam")
  UIAction.CallFunction(A0_9081.m_uiElementName, A0_9081.m_instanceId, "setButton", A0_9081.m_buttons.liveExam.id, A0_9081.m_buttons.liveExam.readyLabel, true)
  A0_9081.m_usable = 1
end
function ArkWorldUI_WarmVessels_LiveExam.Event_DisableLiveExam(A0_9082)
  A0_9082:Log("Event_DisableLiveExam")
  UIAction.CallFunction(A0_9082.m_uiElementName, A0_9082.m_instanceId, "setButton", A0_9082.m_buttons.liveExam.id, A0_9082.m_buttons.liveExam.defaultLabel, false)
  A0_9082.m_usable = 0
end
function ArkWorldUI_WarmVessels_LiveExam.Event_Reset(A0_9083)
  A0_9083:Log("Event_Reset")
  A0_9083:SetupButtons()
end
function ArkWorldUI_WarmVessels_LiveExam.OnStartGame(A0_9084)
  A0_9084:Log("OnStartGame")
  A0_9084:Init()
end
function ArkWorldUI_WarmVessels_LiveExam.OnReset(A0_9085)
  A0_9085:Log("OnReset ")
  if A0_9085.Properties.Physics.bPhysicalize == 1 then
    A0_9085:PhysicalizeThis()
    A0_9085:AwakePhysics(0)
  end
  A0_9085.m_bInit = false
  A0_9085.m_usable = 0
end
ArkWorldUI_WarmVessels_LiveExam.FlowEvents = {
  Inputs = {
    EnableLiveExam = {
      ArkWorldUI_WarmVessels_LiveExam.Event_EnableLiveExam,
      "bool"
    },
    EnablePurge = {
      ArkWorldUI_WarmVessels_LiveExam.Event_EnablePurge,
      "bool"
    },
    DisableLiveExam = {
      ArkWorldUI_WarmVessels_LiveExam.Event_DisableLiveExam,
      "bool"
    },
    DisablePurge = {
      ArkWorldUI_WarmVessels_LiveExam.Event_DisablePurge,
      "bool"
    },
    Reset = {
      ArkWorldUI_WarmVessels_LiveExam.Event_Reset,
      "bool"
    }
  },
  Outputs = {LiveExamPressed = "bool", PurgePressed = "bool"}
}
