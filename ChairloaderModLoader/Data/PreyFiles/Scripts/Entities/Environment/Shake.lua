local L0_5233, L1_5234, L2_5235, L3_5236
L0_5233 = {}
L0_5233.type = "Shake"
L1_5234 = {}
L1_5234.Radius = 30
L1_5234.Shake = 0.05
L0_5233.Properties = L1_5234
L1_5234 = {}
L1_5234.Icon = "shake.bmp"
L0_5233.Editor = L1_5234
Shake = L0_5233
L0_5233 = Shake
function L1_5234(A0_5237)
  A0_5237:OnReset()
end
L0_5233.OnInit = L1_5234
L0_5233 = Shake
function L1_5234(A0_5238)
  A0_5238:OnReset()
end
L0_5233.OnPropertyChange = L1_5234
L0_5233 = Shake
function L1_5234(A0_5239)
  local L1_5240
end
L0_5233.OnReset = L1_5234
L0_5233 = Shake
function L1_5234(A0_5241)
  local L1_5242
end
L0_5233.OnShutDown = L1_5234
L0_5233 = Shake
function L1_5234(A0_5243, A1_5244)
end
L0_5233.Event_Enable = L1_5234
L0_5233 = Shake
function L1_5234(A0_5245, A1_5246)
end
L0_5233.Event_Disable = L1_5234
L0_5233 = Shake
L1_5234 = {}
L2_5235 = {}
L3_5236 = {
  Shake.Event_Disable,
  "bool"
}
L2_5235.Disable = L3_5236
L3_5236 = {
  Shake.Event_Enable,
  "bool"
}
L2_5235.Enable = L3_5236
L1_5234.Inputs = L2_5235
L2_5235 = {}
L2_5235.Disable = "bool"
L2_5235.Enable = "bool"
L1_5234.Outputs = L2_5235
L0_5233.FlowEvents = L1_5234
