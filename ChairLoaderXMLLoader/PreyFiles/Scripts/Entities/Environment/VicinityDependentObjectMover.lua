local L0_5349, L1_5350, L2_5351, L3_5352
L0_5349 = {}
L0_5349.type = "VicinityDependentObjectMover"
L1_5350 = {}
L1_5350.objModel = "Objects/architecture/00_tutorial/columns/nanogon.cgf"
L1_5350.fMoveToDistance = 2
L1_5350.fMoveToSpeed = 30
L1_5350.fMoveBackSpeed = 30
L1_5350.fAreaTriggerRange = 10
L1_5350.fBackAreaTriggerRange = 10
L1_5350.fForceMoveCompleteDistance = 2
L1_5350.bUseAreaTrigger = 0
L1_5350.bDisableAreaTriggerOnMoveComplete = 0
L0_5349.Properties = L1_5350
L1_5350 = {}
L1_5350.Icon = "mine.bmp"
L0_5349.Editor = L1_5350
L1_5350 = {}
L0_5349.Client = L1_5350
L1_5350 = {}
L0_5349.Server = L1_5350
VicinityDependentObjectMover = L0_5349
L0_5349 = VicinityDependentObjectMover
function L1_5350(A0_5353)
  Game.SendEventToGameObject(A0_5353.id, "UpdateFromProperties")
end
L0_5349.OnPropertyChange = L1_5350
L0_5349 = VicinityDependentObjectMover
function L1_5350(A0_5354)
  Game.SendEventToGameObject(A0_5354.id, "EnableAreaTrigger")
end
L0_5349.Event_EnableAreaTrigger = L1_5350
L0_5349 = VicinityDependentObjectMover
function L1_5350(A0_5355)
  Game.SendEventToGameObject(A0_5355.id, "DisableAreaTrigger")
end
L0_5349.Event_DisableAreaTrigger = L1_5350
L0_5349 = VicinityDependentObjectMover
function L1_5350(A0_5356)
  Game.SendEventToGameObject(A0_5356.id, "MoveTo")
end
L0_5349.Event_MoveTo = L1_5350
L0_5349 = VicinityDependentObjectMover
function L1_5350(A0_5357)
  Game.SendEventToGameObject(A0_5357.id, "MoveBack")
end
L0_5349.Event_MoveBack = L1_5350
L0_5349 = VicinityDependentObjectMover
function L1_5350(A0_5358)
  Game.SendEventToGameObject(A0_5358.id, "Reset")
end
L0_5349.Event_Reset = L1_5350
L0_5349 = VicinityDependentObjectMover
function L1_5350(A0_5359)
  Game.SendEventToGameObject(A0_5359.id, "ForceToTargetPos")
end
L0_5349.Event_ForceToTargetPos = L1_5350
L0_5349 = VicinityDependentObjectMover
function L1_5350(A0_5360)
  Game.SendEventToGameObject(A0_5360.id, "ForceReverseMoveToStartPos")
end
L0_5349.Event_ForceReverseMoveToStartPos = L1_5350
L0_5349 = VicinityDependentObjectMover
function L1_5350(A0_5361)
  A0_5361:Hide(1)
end
L0_5349.Event_Hide = L1_5350
L0_5349 = VicinityDependentObjectMover
function L1_5350(A0_5362)
  A0_5362:Hide(0)
end
L0_5349.Event_Unhide = L1_5350
L0_5349 = VicinityDependentObjectMover
L1_5350 = {}
L2_5351 = {}
L3_5352 = {
  VicinityDependentObjectMover.Event_EnableAreaTrigger,
  "bool"
}
L2_5351.EnableAreaTrigger = L3_5352
L3_5352 = {
  VicinityDependentObjectMover.Event_DisableAreaTrigger,
  "bool"
}
L2_5351.DisableAreaTrigger = L3_5352
L3_5352 = {
  VicinityDependentObjectMover.Event_MoveTo,
  "bool"
}
L2_5351.MoveTo = L3_5352
L3_5352 = {
  VicinityDependentObjectMover.Event_MoveBack,
  "bool"
}
L2_5351.MoveBack = L3_5352
L3_5352 = {
  VicinityDependentObjectMover.Event_Reset,
  "bool"
}
L2_5351.Reset = L3_5352
L3_5352 = {
  VicinityDependentObjectMover.Event_ForceToTargetPos,
  "bool"
}
L2_5351.ForceToTargetPos = L3_5352
L3_5352 = {
  VicinityDependentObjectMover.Event_ForceReverseMoveToStartPos,
  "bool"
}
L2_5351.ForceReverseMoveToStartPos = L3_5352
L3_5352 = {
  VicinityDependentObjectMover.Event_Hide,
  "bool"
}
L2_5351.Hide = L3_5352
L3_5352 = {
  VicinityDependentObjectMover.Event_Unhide,
  "bool"
}
L2_5351.Unhide = L3_5352
L1_5350.Inputs = L2_5351
L2_5351 = {}
L2_5351.MoveToStart = "bool"
L2_5351.MoveToComplete = "bool"
L2_5351.MoveBackStart = "bool"
L2_5351.MoveBackComplete = "bool"
L2_5351.OnReset = "bool"
L2_5351.OnForceToTargetPos = "bool"
L2_5351.OnHide = "bool"
L2_5351.OnUnhide = "bool"
L1_5350.Outputs = L2_5351
L0_5349.FlowEvents = L1_5350
