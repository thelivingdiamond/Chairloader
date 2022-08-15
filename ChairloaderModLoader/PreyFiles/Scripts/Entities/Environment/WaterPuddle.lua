local L0_5363, L1_5364, L2_5365, L3_5366
L0_5363 = {}
L0_5363.type = "WaterPuddle"
L1_5364 = {}
L1_5364.bThisIsAPuddle = 0
L0_5363.Properties = L1_5364
L1_5364 = {}
L1_5364.Model = "Editor/Objects/T.cgf"
L1_5364.Icon = "Water.bmp"
L1_5364.ShowBounds = 1
L1_5364.IsScalable = false
L1_5364.IsRotatable = true
L0_5363.Editor = L1_5364
WaterPuddle = L0_5363
L0_5363 = WaterPuddle
function L1_5364(A0_5367)
  local L1_5368
end
L0_5363.OnPropertyChange = L1_5364
L0_5363 = WaterPuddle
function L1_5364(A0_5369)
  local L1_5370
  L1_5370 = 0
  return L1_5370
end
L0_5363.IsShapeOnly = L1_5364
L0_5363 = WaterPuddle
function L1_5364(A0_5371)
  A0_5371:Hide(1)
  A0_5371:ActivateOutput("Hidden", true)
end
L0_5363.Event_Hide = L1_5364
L0_5363 = WaterPuddle
function L1_5364(A0_5372)
  A0_5372:Hide(0)
  A0_5372:ActivateOutput("UnHidden", true)
end
L0_5363.Event_UnHide = L1_5364
L0_5363 = WaterPuddle
L1_5364 = {}
L2_5365 = {}
L3_5366 = {
  WaterPuddle.Event_Hide,
  "bool"
}
L2_5365.Hide = L3_5366
L3_5366 = {
  WaterPuddle.Event_UnHide,
  "bool"
}
L2_5365.UnHide = L3_5366
L1_5364.Inputs = L2_5365
L2_5365 = {}
L2_5365.Hidden = "bool"
L2_5365.UnHidden = "bool"
L1_5364.Outputs = L2_5365
L0_5363.FlowEvents = L1_5364
