Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkHoldToUse = {
  Properties = {
    object_Model = "",
    textInteractText = "",
    textDisplayName = "",
    Sound = {audioTrigger_Pressed = "", audioTrigger_Released = ""},
    Physics = {
      bPhysicalize = 1,
      bRigidBody = 0,
      bPushableByPlayers = 0,
      bPushableByAI = 0,
      Density = -1,
      Mass = -1
    }
  },
  PropertiesInstance = {bVerbose = 0},
  Editor = {
    Icon = "clock.bmp",
    IconOnTop = 0,
    IsScalable = false
  }
}
ArkHoldToUseInstanceVars = {
  m_bVerbose = false,
  m_referenceTable = false,
  m_bPressed = false,
  m_bInit = false,
  m_audioIds = {}
}
GetArkEntityUtils(ArkHoldToUse)
function CreateHoldToUse(A0_4065)
  mergef(A0_4065, ArkHoldToUseInstanceVars, 1)
  A0_4065.m_referenceTable = ArkHoldToUseInstanceVars
end
function ArkHoldToUse.Init(A0_4066, A1_4067)
  if not A0_4066.m_bInit then
    A0_4066.m_bInit = true
    A0_4066:SetFromProperties()
    A0_4066:SetDisplayName(A0_4066.Properties.textDisplayName)
    GetAudioIds(A0_4066.Properties.Sound, A0_4066.m_audioIds)
  end
end
function ArkHoldToUse.GetUsable(A0_4068)
  local L3_4069
  L3_4069 = A0_4068.Properties
  ;({}).ActionType = "ScriptDefined"
  ;({}).DisplayText = L3_4069.textInteractText
  ;({}).Use, ({}).HoldDuration = {}, 0
  return {}
end
function ArkHoldToUse.OnUpdate(A0_4070)
  local L1_4071
  if A0_4070.m_bPressed then
    L1_4071 = "Pressed"
  else
    L1_4071 = "Released"
    A0_4070:Activate(0)
  end
  BroadcastEvent(A0_4070, L1_4071)
end
function ArkHoldToUse.OnHoldToUseStarted(A0_4072)
  A0_4072.m_bPressed = true
  A0_4072:Activate(1)
end
function ArkHoldToUse.OnHoldToUseStopped(A0_4073)
  local L1_4074
  A0_4073.m_bPressed = false
end
function ArkHoldToUse.OnReset(A0_4075)
  A0_4075:Log("OnReset")
  A0_4075:SetFromProperties()
  A0_4075.m_bInit = false
  A0_4075.m_bPressed = false
end
function ArkHoldToUse.OnSpawn(A0_4076)
  CreateHoldToUse(A0_4076)
  A0_4076:Log("OnSpawn")
end
ArkHoldToUse.FlowEvents = {
  Inputs = {},
  Outputs = {Pressed = "bool", Released = "bool"}
}
