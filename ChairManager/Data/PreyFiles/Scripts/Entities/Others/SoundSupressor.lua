local L0_7165, L1_7166, L2_7167, L3_7168
L0_7165 = {}
L1_7166 = {}
L0_7165.Client = L1_7166
L1_7166 = {}
L0_7165.Server = L1_7166
L1_7166 = {}
L1_7166.radius = 10
L0_7165.Properties = L1_7166
L1_7166 = {}
L1_7166.Icon = "Item.bmp"
L1_7166.IconOnTop = 1
L0_7165.Editor = L1_7166
SoundSupressor = L0_7165
L0_7165 = SoundSupressor
function L1_7166(A0_7169)
  A0_7169:OnReset()
end
L0_7165.OnPropertyChange = L1_7166
L0_7165 = SoundSupressor
function L1_7166(A0_7170)
  A0_7170:OnReset()
end
L0_7165.OnInit = L1_7166
L0_7165 = SoundSupressor
function L1_7166(A0_7171)
  CryAction.RegisterWithAI(A0_7171.id, AIOBJECT_SNDSUPRESSOR, A0_7171.Properties)
end
L0_7165.OnReset = L1_7166
L0_7165 = SoundSupressor
function L1_7166(A0_7172)
  A0_7172:TriggerEvent(AIEVENT_DISABLE)
end
L0_7165.Event_TurnOn = L1_7166
L0_7165 = SoundSupressor
function L1_7166(A0_7173)
  A0_7173:TriggerEvent(AIEVENT_ENABLE)
end
L0_7165.Event_TurnOff = L1_7166
L0_7165 = SoundSupressor
L1_7166 = {}
L2_7167 = {}
L3_7168 = {
  SoundSupressor.Event_TurnOn,
  "bool"
}
L2_7167.TurnOn = L3_7168
L3_7168 = {
  SoundSupressor.Event_TurnOff,
  "bool"
}
L2_7167.TurnOff = L3_7168
L1_7166.Inputs = L2_7167
L2_7167 = {}
L1_7166.Outputs = L2_7167
L0_7165.FlowEvents = L1_7166
