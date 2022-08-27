local L0_4339, L1_4340
L0_4339 = {}
L1_4340 = {}
L1_4340.object_Model = ""
L1_4340.NavAgentTypes = "ArkAlien_Small"
L0_4339.Properties = L1_4340
L1_4340 = {}
L1_4340.IconOnTop = true
L1_4340.Icon = "Door.bmp"
L1_4340.ShowBounds = 0
L0_4339.Editor = L1_4340
ArkNavIslandJumpLink = L0_4339
L0_4339 = ArkNavIslandJumpLink
function L1_4340(A0_4341)
  local L1_4342
end
L0_4339.Init = L1_4340
L0_4339 = ArkNavIslandJumpLink
function L1_4340(A0_4343)
  local L1_4344
end
L0_4339.Reset = L1_4340
L0_4339 = ArkNavIslandJumpLink
function L1_4340(A0_4345)
  local L1_4346
end
L0_4339.OnPostLoad = L1_4340
L0_4339 = ArkNavIslandJumpLink
function L1_4340(A0_4347)
  local L1_4348
end
L0_4339.UpdateForEditorDisplay = L1_4340
L0_4339 = ArkNavIslandJumpLink
function L1_4340(A0_4349)
  if System.IsEditor() then
    A0_4349:Init()
    A0_4349:UpdateForEditorDisplay()
  end
end
L0_4339.OnInit = L1_4340
L0_4339 = ArkNavIslandJumpLink
function L1_4340(A0_4350)
  A0_4350:Reset()
  A0_4350:UpdateForEditorDisplay()
end
L0_4339.OnPropertyChange = L1_4340
L0_4339 = ArkNavIslandJumpLink
function L1_4340(A0_4351)
  A0_4351:Reset()
end
L0_4339.OnReset = L1_4340
L0_4339 = ArkNavIslandJumpLink
function L1_4340(A0_4352)
  A0_4352:Reset()
end
L0_4339.OnSpawn = L1_4340
