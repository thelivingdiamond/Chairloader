local L0_5415, L1_5416, L2_5417, L3_5418
L0_5415 = {}
L0_5415.type = "WaterVolume"
L1_5416 = {}
L1_5416.StreamSpeed = 0
L1_5416.FogDensity = 0.5
L2_5417 = {}
L2_5417.x = 0.005
L2_5417.y = 0.01
L2_5417.z = 0.02
L1_5416.color_FogColor = L2_5417
L1_5416.FogColorMultiplier = 0.5
L1_5416.bFogColorAffectedBySun = 1
L1_5416.FogShadowing = 0.5
L1_5416.bCapFogAtVolumeDepth = 0
L1_5416.bCaustics = 1
L1_5416.CausticIntensity = 1
L1_5416.CausticTiling = 1
L1_5416.CausticHeight = 0.5
L1_5416.UScale = 1
L1_5416.VScale = 1
L1_5416.Depth = 5
L1_5416.ViewDistanceRatio = 100
L1_5416.MinSpec = 0
L1_5416.MaterialLayerMask = 0
L1_5416.bAwakeAreaWhenMoving = 0
L1_5416.bIsRiver = 0
L2_5417 = {}
L2_5417.bNetworked = 0
L1_5416.MultiplayerOptions = L2_5417
L0_5415.Properties = L1_5416
L1_5416 = {}
L1_5416.Model = "Editor/Objects/T.cgf"
L1_5416.Icon = "Water.bmp"
L1_5416.ShowBounds = 1
L1_5416.IsScalable = false
L1_5416.IsRotatable = true
L0_5415.Editor = L1_5416
WaterVolume = L0_5415
L0_5415 = WaterVolume
function L1_5416(A0_5419)
  if A0_5419.Properties.MultiplayerOptions.bNetworked == 0 then
    A0_5419:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
  end
end
L0_5415.OnSpawn = L1_5416
L0_5415 = WaterVolume
function L1_5416(A0_5420)
  local L1_5421
end
L0_5415.OnPropertyChange = L1_5416
L0_5415 = WaterVolume
function L1_5416(A0_5422)
  local L1_5423
  L1_5423 = 1
  return L1_5423
end
L0_5415.IsShapeOnly = L1_5416
L0_5415 = WaterVolume
function L1_5416(A0_5424)
  A0_5424:Hide(1)
  A0_5424:ActivateOutput("Hidden", true)
end
L0_5415.Event_Hide = L1_5416
L0_5415 = WaterVolume
function L1_5416(A0_5425)
  A0_5425:Hide(0)
  A0_5425:ActivateOutput("UnHidden", true)
end
L0_5415.Event_UnHide = L1_5416
L0_5415 = WaterVolume
function L1_5416(A0_5426)
  Game.SendEventToGameObject(A0_5426.id, "PhysicsEnable")
end
L0_5415.Event_PhysicsEnable = L1_5416
L0_5415 = WaterVolume
function L1_5416(A0_5427)
  Game.SendEventToGameObject(A0_5427.id, "PhysicsDisable")
end
L0_5415.Event_PhysicsDisable = L1_5416
L0_5415 = WaterVolume
L1_5416 = {}
L2_5417 = {}
L3_5418 = {
  WaterVolume.Event_Hide,
  "bool"
}
L2_5417.Hide = L3_5418
L3_5418 = {
  WaterVolume.Event_UnHide,
  "bool"
}
L2_5417.UnHide = L3_5418
L3_5418 = {
  WaterVolume.Event_PhysicsEnable,
  "bool"
}
L2_5417.PhysicsEnable = L3_5418
L3_5418 = {
  WaterVolume.Event_PhysicsDisable,
  "bool"
}
L2_5417.PhysicsDisable = L3_5418
L1_5416.Inputs = L2_5417
L2_5417 = {}
L2_5417.Hidden = "bool"
L2_5417.UnHidden = "bool"
L1_5416.Outputs = L2_5417
L0_5415.FlowEvents = L1_5416
