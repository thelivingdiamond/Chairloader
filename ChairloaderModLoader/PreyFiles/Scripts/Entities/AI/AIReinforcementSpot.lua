local L0_2578, L1_2579, L2_2580, L3_2581
L0_2578 = {}
L0_2578.type = "AIReinforcementSpot"
L1_2579 = {}
L1_2579.bEnabled = 1
L1_2579.groupid = 173
L1_2579.radius = 30
L1_2579.AvoidWhenTargetInRadius = 15
L1_2579.bWhenAllAlerted = 1
L1_2579.bWhenInCombat = 1
L1_2579.iGroupBodyCount = 2
L1_2579.eiReinforcementType = 0
L0_2578.Properties = L1_2579
AIReinforcementSpot = L0_2578
L0_2578 = AIReinforcementSpot
function L1_2579(A0_2582)
  A0_2582:Register()
end
L0_2578.OnInit = L1_2579
L0_2578 = AIReinforcementSpot
function L1_2579(A0_2583)
  A0_2583:Register()
end
L0_2578.OnPropertyChange = L1_2579
L0_2578 = AIReinforcementSpot
function L1_2579(A0_2584)
  A0_2584.bNowEnabled = A0_2584.Properties.bEnabled
  if A0_2584.Properties.bEnabled == 0 then
    A0_2584:TriggerEvent(AIEVENT_DISABLE)
  else
    A0_2584:TriggerEvent(AIEVENT_ENABLE)
  end
  A0_2584:ActivateOutput("GroupID", A0_2584.Properties.groupid)
end
L0_2578.OnReset = L1_2579
L0_2578 = AIReinforcementSpot
function L1_2579(A0_2585)
  if A0_2585.Properties.aianchor_AnchorType ~= "" then
    CryAction.RegisterWithAI(A0_2585.id, AIAnchorTable.REINFORCEMENT_SPOT, A0_2585.Properties)
    AI.ChangeParameter(A0_2585.id, AIPARAM_GROUPID, A0_2585.Properties.groupid)
  end
  A0_2585:OnReset()
end
L0_2578.Register = L1_2579
L0_2578 = AIReinforcementSpot
function L1_2579(A0_2586, A1_2587)
  A0_2586:TriggerEvent(AIEVENT_ENABLE)
  A0_2586.bNowEnabled = 1
  A0_2586:ActivateOutput("GroupID", A0_2586.Properties.groupid)
end
L0_2578.Event_Enable = L1_2579
L0_2578 = AIReinforcementSpot
function L1_2579(A0_2588, A1_2589)
  A0_2588:TriggerEvent(AIEVENT_DISABLE)
  A0_2588.bNowEnabled = 0
end
L0_2578.Event_Disable = L1_2579
L0_2578 = AIReinforcementSpot
function L1_2579(A0_2590)
  A0_2590:TriggerEvent(AIEVENT_DISABLE)
  A0_2590.bNowEnabled = 0
  A0_2590:ActivateOutput("GroupID", A0_2590.Properties.groupid)
  A0_2590:ActivateOutput("Called", true)
end
L0_2578.Alarm = L1_2579
L0_2578 = AIReinforcementSpot
L1_2579 = {}
L2_2580 = {}
L3_2581 = {
  AIReinforcementSpot.Event_Enable,
  "bool"
}
L2_2580.Enable = L3_2581
L3_2581 = {
  AIReinforcementSpot.Event_Disable,
  "bool"
}
L2_2580.Disable = L3_2581
L1_2579.Inputs = L2_2580
L2_2580 = {}
L2_2580.Called = "bool"
L2_2580.GroupID = "int"
L1_2579.Outputs = L2_2580
L0_2578.FlowEvents = L1_2579
