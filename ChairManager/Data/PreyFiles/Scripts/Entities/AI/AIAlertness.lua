System.Log("Loading AIAlertness.lua")
AIAlertness = {
  type = "AIAlertness",
  Properties = {bEnabled = 1},
  Editor = {
    Model = "Editor/Objects/box.cgf"
  }
}
function AIAlertness.OnPropertyChange(A0_2546)
  A0_2546:Register()
end
function AIAlertness.OnInit(A0_2547)
  A0_2547:Register()
end
function AIAlertness.OnReset(A0_2548)
  A0_2548.bNowEnabled = A0_2548.Properties.bEnabled
  if A0_2548.Properties.bEnabled == 0 then
    A0_2548:TriggerEvent(AIEVENT_DISABLE)
  else
    A0_2548:TriggerEvent(AIEVENT_ENABLE)
  end
end
function AIAlertness.Register(A0_2549)
  CryAction.RegisterWithAI(A0_2549.id, AIOBJECT_GLOBALALERTNESS)
  A0_2549:OnReset()
end
function AIAlertness.Event_Enable(A0_2550)
  A0_2550:TriggerEvent(AIEVENT_ENABLE)
  A0_2550.bNowEnabled = 1
  BroadcastEvent(A0_2550, "Enable")
end
function AIAlertness.Event_Disable(A0_2551)
  A0_2551:TriggerEvent(AIEVENT_DISABLE)
  A0_2551.bNowEnabled = 0
  BroadcastEvent(A0_2551, "Disable")
end
function AIAlertness.SetAlertness(A0_2552, A1_2553)
  if A0_2552.bNowEnabled then
    if A1_2553 == 0 then
      A0_2552:Event_Green()
    elseif A1_2553 == 1 then
      A0_2552:Event_Orange()
    elseif A1_2553 == 2 then
      A0_2552:Event_Red()
    end
  end
end
function AIAlertness.Event_Green(A0_2554, A1_2555)
  AI.LogEvent("GLOBAL ALERTNESS STATE:  GREEN")
  BroadcastEvent(A0_2554, "Green")
end
function AIAlertness.Event_Orange(A0_2556, A1_2557)
  AI.LogEvent("GLOBAL ALERTNESS STATE:  ORANGE")
  BroadcastEvent(A0_2556, "Orange")
end
function AIAlertness.Event_Red(A0_2558, A1_2559)
  AI.LogEvent("GLOBAL ALERTNESS STATE:  RED")
  BroadcastEvent(A0_2558, "Red")
end
AIAlertness.FlowEvents = {
  Inputs = {
    Disable = {
      AIAlertness.Event_Disable,
      "bool"
    },
    Enable = {
      AIAlertness.Event_Enable,
      "bool"
    },
    Green = {
      AIAlertness.Event_Green,
      "bool"
    },
    Orange = {
      AIAlertness.Event_Orange,
      "bool"
    },
    Red = {
      AIAlertness.Event_Red,
      "bool"
    }
  },
  Outputs = {
    Disable = "bool",
    Enable = "bool",
    Green = "bool",
    Orange = "bool",
    Red = "bool"
  }
}
