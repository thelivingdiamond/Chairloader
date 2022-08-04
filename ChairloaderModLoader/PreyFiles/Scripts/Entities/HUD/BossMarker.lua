local L0_5428, L1_5429, L2_5430, L3_5431
L0_5428 = {}
L1_5429 = {}
L1_5429.Icon = "Comment.bmp"
L0_5428.Editor = L1_5429
L1_5429 = {}
L1_5429.fileModel = ""
L1_5429.ModelSubObject = ""
L1_5429.bEnabled = 1
L0_5428.Properties = L1_5429
BossMarker = L0_5428
L0_5428 = BossMarker
function L1_5429(A0_5432)
  A0_5432:OnReset()
end
L0_5428.OnInit = L1_5429
L0_5428 = BossMarker
function L1_5429(A0_5433)
  A0_5433:OnReset()
end
L0_5428.OnPropertyChange = L1_5429
L0_5428 = BossMarker
function L1_5429(A0_5434)
  if A0_5434.Properties.bEnabled == 1 then
    Game.AddTacticalEntity(A0_5434.id, eTacticalEntity_Unit)
  else
    Game.RemoveTacticalEntity(A0_5434.id, eTacticalEntity_Unit)
  end
end
L0_5428.OnReset = L1_5429
L0_5428 = BossMarker
function L1_5429(A0_5435, A1_5436)
  A0_5435.Properties.bEnabled = A1_5436.enabled
end
L0_5428.OnLoad = L1_5429
L0_5428 = BossMarker
function L1_5429(A0_5437, A1_5438)
  local L2_5439
  L2_5439 = A0_5437.Properties
  L2_5439 = L2_5439.bEnabled
  A1_5438.enabled = L2_5439
end
L0_5428.OnSave = L1_5429
L0_5428 = BossMarker
function L1_5429(A0_5440)
  A0_5440.Properties.bEnabled = 1
  BroadcastEvent(A0_5440, "Unhide")
  Game.AddTacticalEntity(A0_5440.id, eTacticalEntity_Unit)
end
L0_5428.Event_Enable = L1_5429
L0_5428 = BossMarker
function L1_5429(A0_5441)
  A0_5441.Properties.bEnabled = 0
  BroadcastEvent(A0_5441, "Hide")
  Game.RemoveTacticalEntity(A0_5441.id, eTacticalEntity_Unit)
end
L0_5428.Event_Disable = L1_5429
L0_5428 = BossMarker
L1_5429 = {}
L2_5430 = {}
L3_5431 = {
  BossMarker.Event_Enable,
  "bool"
}
L2_5430.Enable = L3_5431
L3_5431 = {
  BossMarker.Event_Disable,
  "bool"
}
L2_5430.Disable = L3_5431
L1_5429.Inputs = L2_5430
L0_5428.FlowEvents = L1_5429
