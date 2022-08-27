local L0_7047, L1_7048, L2_7049, L3_7050
L0_7047 = {}
L1_7048 = {}
L1_7048.objPlayerModel = ""
L1_7048.objArmsModel = ""
L1_7048.bPreCacheModels = 0
L0_7047.Properties = L1_7048
L1_7048 = {}
L1_7048.Model = "editor/objects/box.cgf"
L0_7047.Editor = L1_7048
PlayerModelChanger = L0_7047
L0_7047 = PlayerModelChanger
function L1_7048(A0_7051, A1_7052)
  A0_7051.changePlayerModel = A1_7052.changePlayerModel
end
L0_7047.OnLoad = L1_7048
L0_7047 = PlayerModelChanger
function L1_7048(A0_7053, A1_7054)
  A1_7054.changePlayerModel = A0_7053.changePlayerModel
end
L0_7047.OnSave = L1_7048
L0_7047 = PlayerModelChanger
function L1_7048(A0_7055)
  A0_7055:Reset()
end
L0_7047.OnPropertyChange = L1_7048
L0_7047 = PlayerModelChanger
function L1_7048(A0_7056)
  A0_7056:Reset()
end
L0_7047.OnReset = L1_7048
L0_7047 = PlayerModelChanger
function L1_7048(A0_7057)
  A0_7057:Reset()
end
L0_7047.OnSpawn = L1_7048
L0_7047 = PlayerModelChanger
function L1_7048(A0_7058)
  local L1_7059
end
L0_7047.OnDestroy = L1_7048
L0_7047 = PlayerModelChanger
function L1_7048(A0_7060)
  local L1_7061, L2_7062
  L2_7062 = A0_7060
  L1_7061 = A0_7060.Activate
  L1_7061(L2_7062, 0)
  L1_7061 = A0_7060.Properties
  L1_7061 = L1_7061.bPreCacheModels
  if L1_7061 then
    L1_7061 = A0_7060.Properties
    L1_7061 = L1_7061.objPlayerModel
    L2_7062 = A0_7060.Properties
    L2_7062 = L2_7062.objArmsModel
    if L1_7061 and 0 < string.len(L1_7061) then
      A0_7060:LoadCharacter(0, A0_7060.Properties.objPlayerModel)
      A0_7060:DrawSlot(0, 0)
      A0_7060.changePlayerModel = true
    end
    if L2_7062 and 0 < string.len(L2_7062) then
      A0_7060:LoadCharacter(1, A0_7060.Properties.objArmsModel)
      A0_7060:DrawSlot(1, 0)
      A0_7060.changeArmsModel = true
    end
  end
end
L0_7047.Reset = L1_7048
L0_7047 = PlayerModelChanger
function L1_7048(A0_7063)
  local L1_7064, L2_7065
  L1_7064 = g_localActor
  if L1_7064 then
    L1_7064, L2_7065 = nil, nil
    if A0_7063.changePlayerModel then
      L1_7064 = A0_7063.Properties.objPlayerModel
    end
    if A0_7063.changeArmsModel then
      L2_7065 = A0_7063.Properties.objArmsModel
    end
    g_localActor:SetModel(L1_7064, L2_7065)
  end
end
L0_7047.ChangeModel = L1_7048
L0_7047 = PlayerModelChanger
function L1_7048(A0_7066, A1_7067)
  A0_7066:ChangeModel()
  BroadcastEvent(A0_7066, "ChangeModel")
end
L0_7047.Event_ChangePlayerModel = L1_7048
L0_7047 = PlayerModelChanger
function L1_7048(A0_7068, A1_7069)
  A0_7068:Reset()
  BroadcastEvent(A0_7068, "Reset")
end
L0_7047.Event_Reset = L1_7048
L0_7047 = PlayerModelChanger
L1_7048 = {}
L2_7049 = {}
L3_7050 = {
  PlayerModelChanger.Event_ChangePlayerModel,
  "bool"
}
L2_7049.ChangePlayerModel = L3_7050
L3_7050 = {
  PlayerModelChanger.Event_Reset,
  "bool"
}
L2_7049.Reset = L3_7050
L1_7048.Inputs = L2_7049
L2_7049 = {}
L2_7049.ChangePlayerModel = "bool"
L2_7049.Reset = "bool"
L1_7048.Outputs = L2_7049
L0_7047.FlowEvents = L1_7048
