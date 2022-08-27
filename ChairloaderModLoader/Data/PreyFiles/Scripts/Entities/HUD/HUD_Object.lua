local L0_5466, L1_5467, L2_5468
L0_5466 = {}
L0_5466.type = "HUD_Object"
L1_5467 = {}
L1_5467.fileModel = "objects/hud/hud_bg_center.cgf"
L0_5466.Properties = L1_5467
L1_5467 = {}
L1_5467.Icon = "Comment.bmp"
L1_5467.IconOnTop = 1
L0_5466.Editor = L1_5467
HUD_Object = L0_5466
L0_5466 = HUD_Object
function L1_5467(A0_5469)
  A0_5469:OnReset()
end
L0_5466.OnInit = L1_5467
L0_5466 = HUD_Object
function L1_5467(A0_5470)
  A0_5470:OnReset()
end
L0_5466.OnPropertyChange = L1_5467
L0_5466 = HUD_Object
function L1_5467(A0_5471)
  A0_5471:LoadObjectWithFlags(0, A0_5471.Properties.fileModel, 2)
end
L0_5466.OnReset = L1_5467
L0_5466 = HUD_Object
function L1_5467(A0_5472, A1_5473)
  A0_5472.Properties.fileModel = A1_5473
  A0_5472:LoadObjectWithFlags(0, A1_5473, 2)
end
L0_5466.SetObjectModel = L1_5467
L0_5466 = HUD_Object
function L1_5467(A0_5474, A1_5475)
  local L2_5476
  L2_5476 = A0_5474.Properties
  L2_5476 = L2_5476.fileModel
  A1_5475.fileModel = L2_5476
end
L0_5466.OnSave = L1_5467
L0_5466 = HUD_Object
function L1_5467(A0_5477, A1_5478)
  A0_5477:SetObjectModel(A1_5478.fileModel)
end
L0_5466.OnLoad = L1_5467
L0_5466 = HUD_Object
function L1_5467(A0_5479)
  A0_5479:Hide(0)
end
L0_5466.OnPostLoad = L1_5467
L0_5466 = HUD_Object
function L1_5467(A0_5480)
  local L1_5481
end
L0_5466.OnShutDown = L1_5467
L0_5466 = HUD_Object
function L1_5467(A0_5482, A1_5483)
end
L0_5466.Event_TargetReached = L1_5467
L0_5466 = HUD_Object
function L1_5467(A0_5484, A1_5485)
end
L0_5466.Event_Enable = L1_5467
L0_5466 = HUD_Object
function L1_5467(A0_5486, A1_5487)
end
L0_5466.Event_Disable = L1_5467
L0_5466 = HUD_Object
L1_5467 = {}
L2_5468 = {}
L1_5467.Inputs = L2_5468
L2_5468 = {}
L1_5467.Outputs = L2_5468
L0_5466.FlowEvents = L1_5467
