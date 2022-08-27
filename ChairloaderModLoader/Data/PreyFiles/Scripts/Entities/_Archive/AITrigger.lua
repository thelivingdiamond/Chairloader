local L0_451, L1_452, L2_453, L3_454
L0_451 = {}
L0_451.type = "AITrigger"
L1_452 = {}
L1_452.modifyerName = "bridge"
L1_452.fAlarmRadius = 50
L0_451.Properties = L1_452
L1_452 = {}
L1_452.Model = "Editor/Objects/box.cgf"
L0_451.Editor = L1_452
AITrigger = L0_451
L0_451 = AITrigger
function L1_452(A0_455)
  A0_455:OnReset()
end
L0_451.OnInit = L1_452
L0_451 = AITrigger
function L1_452(A0_456)
  local L1_457
end
L0_451.OnReset = L1_452
L0_451 = AITrigger
function L1_452(A0_458, A1_459)
  AI.Event(1, A0_458.Properties.modifyerName)
  BroadcastEvent(A0_458, "Event")
  AI.Commander:OnBridgeDestroyed()
end
L0_451.Event_Event = L1_452
L0_451 = AITrigger
function L1_452(A0_460, A1_461)
  System.Log("Alarm!")
  AI.SoundEvent(A0_460:GetWorldPos(), A0_460.Properties.fAlarmRadius, AISOUND_GENERIC, g_localActor.id)
  BroadcastEvent(A0_460, "Alarm")
end
L0_451.Event_Alarm = L1_452
L0_451 = AITrigger
L1_452 = {}
L2_453 = {}
L3_454 = {
  AITrigger.Event_Alarm,
  "bool"
}
L2_453.Alarm = L3_454
L3_454 = {
  AITrigger.Event_Event,
  "bool"
}
L2_453.Event = L3_454
L1_452.Inputs = L2_453
L2_453 = {}
L2_453.Alarm = "bool"
L2_453.Event = "bool"
L1_452.Outputs = L2_453
L0_451.Events = L1_452
