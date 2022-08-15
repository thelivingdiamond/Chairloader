local L0_2560, L1_2561, L2_2562, L3_2563
L0_2560 = {}
L0_2560.type = "AIAnchor"
L1_2561 = {}
L1_2561.aianchor_AnchorType = "_wrong_type_"
L1_2561.bEnabled = 1
L1_2561.soclasses_SmartObjectClass = ""
L1_2561.groupid = -1
L1_2561.radius = 0
L0_2560.Properties = L1_2561
AIAnchor = L0_2560
L0_2560 = AIAnchor
function L1_2561(A0_2564)
  A0_2564:Register()
end
L0_2560.OnPropertyChange = L1_2561
L0_2560 = AIAnchor
function L1_2561(A0_2565)
  A0_2565:Register()
end
L0_2560.OnInit = L1_2561
L0_2560 = AIAnchor
function L1_2561(A0_2566)
  A0_2566.bNowEnabled = A0_2566.Properties.bEnabled
  if A0_2566.Properties.bEnabled == 0 then
    A0_2566:TriggerEvent(AIEVENT_DISABLE)
  else
    A0_2566:TriggerEvent(AIEVENT_ENABLE)
  end
end
L0_2560.OnReset = L1_2561
L0_2560 = AIAnchor
function L1_2561(A0_2567)
  BroadcastEvent(A0_2567, "Use")
end
L0_2560.OnUsed = L1_2561
L0_2560 = AIAnchor
function L1_2561(A0_2568)
  A0_2568.registered = nil
  if A0_2568.Properties.aianchor_AnchorType ~= "" then
    if AIAnchorTable[A0_2568.Properties.aianchor_AnchorType] == nil then
      System.Log("AIAnchor[" .. A0_2568:GetName() .. "]:  undefined type [" .. A0_2568.Properties.aianchor_AnchorType .. "] Cant register with [AISYSTEM]")
    else
      CryAction.RegisterWithAI(A0_2568.id, AIAnchorTable[A0_2568.Properties.aianchor_AnchorType], A0_2568.Properties)
      AI.ChangeParameter(A0_2568.id, AIPARAM_GROUPID, A0_2568.Properties.groupid)
      A0_2568.registered = 1
    end
  end
  A0_2568:OnReset()
end
L0_2560.Register = L1_2561
L0_2560 = AIAnchor
function L1_2561(A0_2569, A1_2570)
  if A0_2569.bNowEnabled == 1 then
    BroadcastEvent(A0_2569, "Use")
  end
end
L0_2560.Event_Use = L1_2561
L0_2560 = AIAnchor
function L1_2561(A0_2571)
  A0_2571:TriggerEvent(AIEVENT_ENABLE)
  A0_2571.bNowEnabled = 1
  BroadcastEvent(A0_2571, "Enable")
end
L0_2560.Event_Enable = L1_2561
L0_2560 = AIAnchor
function L1_2561(A0_2572)
  A0_2572:TriggerEvent(AIEVENT_DISABLE)
  A0_2572.bNowEnabled = 0
  BroadcastEvent(A0_2572, "Disable")
end
L0_2560.Event_Disable = L1_2561
L0_2560 = AIAnchor
function L1_2561(A0_2573, A1_2574)
  local L2_2575
  L2_2575 = A0_2573.Properties
  L2_2575 = L2_2575.aianchor_AnchorType
  A1_2574.aianchor_AnchorType = L2_2575
end
L0_2560.OnSave = L1_2561
L0_2560 = AIAnchor
function L1_2561(A0_2576, A1_2577)
  A0_2576.Properties.aianchor_AnchorType = A1_2577.aianchor_AnchorType
  if not A0_2576.registered then
    A0_2576:Register()
  end
end
L0_2560.OnLoad = L1_2561
L0_2560 = AIAnchor
L1_2561 = {}
L2_2562 = {}
L3_2563 = {
  AIAnchor.Event_Disable,
  "bool"
}
L2_2562.Disable = L3_2563
L3_2563 = {
  AIAnchor.Event_Enable,
  "bool"
}
L2_2562.Enable = L3_2563
L3_2563 = {
  AIAnchor.Event_Use,
  "bool"
}
L2_2562.Use = L3_2563
L1_2561.Inputs = L2_2562
L2_2562 = {}
L2_2562.Disable = "bool"
L2_2562.Enable = "bool"
L2_2562.Use = "bool"
L1_2561.Outputs = L2_2562
L0_2560.FlowEvents = L1_2561
