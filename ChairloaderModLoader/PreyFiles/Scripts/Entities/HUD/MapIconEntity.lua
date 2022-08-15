local L0_5488, L1_5489, L2_5490, L3_5491
L0_5488 = {}
L1_5489 = {}
L1_5489.Icon = "Comment.bmp"
L0_5488.Editor = L1_5489
L1_5489 = {}
L1_5489.fileModel = ""
L1_5489.ModelSubObject = ""
L1_5489.bEnabled = 1
L1_5489.sMapIcon = ""
L0_5488.Properties = L1_5489
MapIconEntity = L0_5488
L0_5488 = MapIconEntity
function L1_5489(A0_5492)
  A0_5492:OnReset()
end
L0_5488.OnInit = L1_5489
L0_5488 = MapIconEntity
function L1_5489(A0_5493)
  A0_5493:OnReset()
end
L0_5488.OnPropertyChange = L1_5489
L0_5488 = MapIconEntity
function L1_5489(A0_5494)
  if A0_5494.Properties.bEnabled == 1 then
    Game.AddTacticalEntity(A0_5494.id, eTacticalEntity_MapIcon)
  else
    Game.RemoveTacticalEntity(A0_5494.id, eTacticalEntity_MapIcon)
  end
end
L0_5488.OnReset = L1_5489
L0_5488 = MapIconEntity
function L1_5489(A0_5495, A1_5496)
  A0_5495.Properties.bEnabled = A1_5496.enabled
end
L0_5488.OnLoad = L1_5489
L0_5488 = MapIconEntity
function L1_5489(A0_5497, A1_5498)
  local L2_5499
  L2_5499 = A0_5497.Properties
  L2_5499 = L2_5499.bEnabled
  A1_5498.enabled = L2_5499
end
L0_5488.OnSave = L1_5489
L0_5488 = MapIconEntity
function L1_5489(A0_5500)
  A0_5500.Properties.bEnabled = 1
  Game.AddTacticalEntity(A0_5500.id, eTacticalEntity_MapIcon)
end
L0_5488.Event_Enable = L1_5489
L0_5488 = MapIconEntity
function L1_5489(A0_5501)
  A0_5501.Properties.bEnabled = 0
  Game.RemoveTacticalEntity(A0_5501.id, eTacticalEntity_MapIcon)
end
L0_5488.Event_Disable = L1_5489
L0_5488 = MapIconEntity
L1_5489 = {}
L2_5490 = {}
L3_5491 = {
  MapIconEntity.Event_Enable,
  "bool"
}
L2_5490.Enable = L3_5491
L3_5491 = {
  MapIconEntity.Event_Disable,
  "bool"
}
L2_5490.Disable = L3_5491
L1_5489.Inputs = L2_5490
L0_5488.FlowEvents = L1_5489
