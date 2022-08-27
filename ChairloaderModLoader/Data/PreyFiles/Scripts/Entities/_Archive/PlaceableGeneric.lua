local L0_1085, L1_1086, L2_1087, L3_1088
L0_1085 = {}
L0_1085.type = "Trigger"
L1_1086 = {}
L1_1086.DimX = 5
L1_1086.DimY = 5
L1_1086.DimZ = 5
L1_1086.ScriptCommand = ""
L1_1086.PlaySequence = ""
L1_1086.dummyModel = "Objects/Pickups/explosive/explosive_dummy.cgf"
L1_1086.fileModel = "objects/pickups/explosive/explosive.cgf"
L1_1086.object_ModelDestroyed = ""
L1_1086.bInitiallyVisible = 1
L1_1086.bAutomaticPlaceable = 1
L2_1087 = noinstruction
L1_1086.TextInstruction = L2_1087
L1_1086.PlaceableObject = ""
L1_1086.bActive = 1
L0_1085.Properties = L1_1086
L1_1086 = {}
L1_1086.Model = "Objects/Editor/T.cgf"
L1_1086.ShowBounds = 1
L0_1085.Editor = L1_1086
PlaceableGeneric = L0_1085
L0_1085 = PlaceableGeneric
function L1_1086(A0_1089)
  if A0_1089.Properties.dummyModel ~= "" then
    A0_1089:LoadObject(A0_1089.Properties.dummyModel, 0, 1)
  end
  if A0_1089.Properties.fileModel ~= "" then
    A0_1089:LoadObject(A0_1089.Properties.fileModel, 1, 1)
  end
  if A0_1089.Properties.object_ModelDestroyed ~= "" then
    A0_1089:LoadObject(A0_1089.Properties.object_ModelDestroyed, 2, 1)
  end
end
L0_1085.LoadGeometry = L1_1086
L0_1085 = PlaceableGeneric
function L1_1086(A0_1090)
  A0_1090:RegisterState("placeable")
  A0_1090:RegisterState("notarmed")
  A0_1090:RegisterState("armed")
  A0_1090:RegisterState("detonated")
end
L0_1085.RegisterStates = L1_1086
L0_1085 = PlaceableGeneric
function L1_1086(A0_1091)
  local L1_1092, L2_1093
  L2_1093 = A0_1091
  L1_1092 = A0_1091.Activate
  L1_1092(L2_1093, 0)
  L2_1093 = A0_1091
  L1_1092 = A0_1091.TrackColliders
  L1_1092(L2_1093, 1)
  L1_1092 = {}
  L2_1093 = A0_1091.Properties
  L2_1093 = L2_1093.DimX
  L2_1093 = -L2_1093
  L2_1093 = L2_1093 / 2
  L1_1092.x = L2_1093
  L2_1093 = A0_1091.Properties
  L2_1093 = L2_1093.DimY
  L2_1093 = -L2_1093
  L2_1093 = L2_1093 / 2
  L1_1092.y = L2_1093
  L2_1093 = A0_1091.Properties
  L2_1093 = L2_1093.DimZ
  L2_1093 = -L2_1093
  L2_1093 = L2_1093 / 2
  L1_1092.z = L2_1093
  L2_1093 = {}
  L2_1093.x = A0_1091.Properties.DimX / 2
  L2_1093.y = A0_1091.Properties.DimY / 2
  L2_1093.z = A0_1091.Properties.DimZ / 2
  A0_1091:SetBBox(L1_1092, L2_1093)
  if A0_1091.Properties.bInitiallyVisible == 1 then
    A0_1091:DrawObject(0, 1)
  else
    A0_1091:DrawObject(0, 0)
  end
  A0_1091:GotoState("placeable")
  A0_1091.bActive = A0_1091.Properties.bActive
end
L0_1085.OnReset = L1_1086
L0_1085 = PlaceableGeneric
function L1_1086(A0_1094)
  A0_1094:OnReset()
end
L0_1085.OnMultiplayerReset = L1_1086
L0_1085 = PlaceableGeneric
function L1_1086(A0_1095)
  A0_1095:OnReset()
end
L0_1085.OnPropertyChange = L1_1086
L0_1085 = PlaceableGeneric
function L1_1086(A0_1096, A1_1097, A2_1098)
  if A1_1097 and Server:GetServerSlotByEntityId(A1_1097) then
    Server:GetServerSlotByEntityId(A1_1097):SendText(A2_1098, 0.9)
  end
end
L0_1085.PrintMessage = L1_1086
L0_1085 = PlaceableGeneric
L1_1086 = {}
function L2_1087(A0_1099)
  A0_1099:LoadGeometry()
  A0_1099:RegisterStates()
  A0_1099:OnReset()
  A0_1099:NetPresent(nil)
end
L1_1086.OnInit = L2_1087
L2_1087 = {}
function L3_1088(A0_1100)
  A0_1100:DestroyPhysics()
end
L2_1087.OnBeginState = L3_1088
function L3_1088(A0_1101, A1_1102)
  if GameRules:IsInteractionPossible(A1_1102, A0_1101) and A1_1102.type == "Player" and not A1_1102:IsDead() then
    A0_1101.Who = A1_1102
    A0_1101:SetTimer(1)
  end
end
L2_1087.OnEnterArea = L3_1088
function L3_1088(A0_1103, A1_1104)
  if A1_1104 == A0_1103.Who then
    A0_1103.Who = nil
  end
end
L2_1087.OnLeaveArea = L3_1088
function L3_1088(A0_1105, A1_1106)
  if A0_1105.Who then
    A0_1105:Collide(A0_1105.Who)
    A0_1105:SetTimer(1)
  end
end
L2_1087.OnTimer = L3_1088
L1_1086.placeable = L2_1087
L2_1087 = {}
function L3_1088(A0_1107)
  A0_1107:DestroyPhysics()
end
L2_1087.OnBeginState = L3_1088
L1_1086.notarmed = L2_1087
L2_1087 = {}
function L3_1088(A0_1108)
  A0_1108:DestroyPhysics()
end
L2_1087.OnBeginState = L3_1088
function L3_1088(A0_1109)
  A0_1109:GotoState("detonated")
  BroadcastEvent(A0_1109, "Explode")
end
L2_1087.OnTimer = L3_1088
L1_1086.armed = L2_1087
L2_1087 = {}
function L3_1088(A0_1110)
  A0_1110:CreateStaticEntity(10, 100)
end
L2_1087.OnBeginState = L3_1088
L1_1086.detonated = L2_1087
L0_1085.Server = L1_1086
L0_1085 = PlaceableGeneric
L1_1086 = {}
function L2_1087(A0_1111)
  A0_1111:LoadGeometry()
  A0_1111:RegisterStates()
  A0_1111:OnReset()
end
L1_1086.OnInit = L2_1087
L2_1087 = {}
function L3_1088(A0_1112)
  A0_1112:DrawObject(0, 1)
  A0_1112:DrawObject(1, 0)
  A0_1112:DrawObject(2, 0)
  A0_1112:DestroyPhysics()
end
L2_1087.OnBeginState = L3_1088
L1_1086.placeable = L2_1087
L2_1087 = {}
function L3_1088(A0_1113)
  A0_1113:DrawObject(0, 0)
  A0_1113:DrawObject(1, 1)
  A0_1113:DrawObject(2, 0)
  A0_1113:DestroyPhysics()
end
L2_1087.OnBeginState = L3_1088
L1_1086.notarmed = L2_1087
L2_1087 = {}
function L3_1088(A0_1114)
  A0_1114:DrawObject(0, 0)
  A0_1114:DrawObject(1, 1)
  A0_1114:DrawObject(2, 0)
  A0_1114:DestroyPhysics()
end
L2_1087.OnBeginState = L3_1088
L1_1086.armed = L2_1087
L2_1087 = {}
function L3_1088(A0_1115)
  A0_1115:Explode()
  A0_1115:DrawObject(0, 0)
  A0_1115:DrawObject(1, 0)
  A0_1115:DrawObject(2, 1)
  A0_1115:CreateStaticEntity(10, 100)
end
L2_1087.OnBeginState = L3_1088
L1_1086.detonated = L2_1087
L0_1085.Client = L1_1086
L0_1085 = PlaceableGeneric
function L1_1086(A0_1116, A1_1117)
  if A0_1116.bActive == 0 then
    return
  end
  if A1_1117.type ~= "Player" then
    return
  end
  if A1_1117.objects[A0_1116.Properties.PlaceableObject] == 1 then
    System.LogToConsole("object found:" .. A0_1116.Properties.PlaceableObject)
    if A0_1116.Properties.bAutomaticPlaceable ~= 1 and not A1_1117.cnt.use_pressed then
      Hud.label = A0_1116.Properties.TextInstruction
      return
    end
    A1_1117.objects[A0_1116.Properties.PlaceableObject] = 0
    A0_1116.target = A1_1117.id
    A0_1116:GotoState("armed")
    A0_1116:Event_ExplosivePlaced()
  end
end
L0_1085.Collide = L1_1086
L0_1085 = PlaceableGeneric
function L1_1086(A0_1118, A1_1119)
  BroadcastEvent(A0_1118, "Activate")
  A0_1118.bActive = 1
end
L0_1085.Event_Activate = L1_1086
L0_1085 = PlaceableGeneric
function L1_1086(A0_1120, A1_1121)
  BroadcastEvent(A0_1120, "ExplosivePlaced")
end
L0_1085.Event_ExplosivePlaced = L1_1086
L0_1085 = PlaceableGeneric
function L1_1086(A0_1122, A1_1123)
  BroadcastEvent(A0_1122, "Explode")
  A0_1122:Explode()
end
L0_1085.Event_Explode = L1_1086
L0_1085 = PlaceableGeneric
function L1_1086(A0_1124, A1_1125)
  A0_1124:DrawObject(0, 0)
end
L0_1085.Event_Hide = L1_1086
L0_1085 = PlaceableGeneric
function L1_1086(A0_1126, A1_1127)
  A0_1126:DrawObject(0, 1)
end
L0_1085.Event_Show = L1_1086
L0_1085 = PlaceableGeneric
function L1_1086(A0_1128)
  if A0_1128.Properties.ScriptCommand and A0_1128.Properties.ScriptCommand ~= "" then
    dostring(A0_1128.Properties.ScriptCommand)
  end
  if A0_1128.Properties.PlaySequence ~= "" then
    Movie.PlaySequence(A0_1128.Properties.PlaySequence)
  end
end
L0_1085.Explode = L1_1086
L0_1085 = PlaceableGeneric
L1_1086 = {}
L2_1087 = {}
L3_1088 = {
  PlaceableGeneric.Event_Activate,
  "bool"
}
L2_1087.Activate = L3_1088
L3_1088 = {
  PlaceableGeneric.Event_Explode,
  "bool"
}
L2_1087.Explode = L3_1088
L3_1088 = {
  PlaceableGeneric.Event_ExplosivePlaced,
  "bool"
}
L2_1087.ExplosivePlaced = L3_1088
L3_1088 = {
  PlaceableGeneric.Event_Hide,
  "bool"
}
L2_1087.Hide = L3_1088
L3_1088 = {
  PlaceableGeneric.Event_Show,
  "bool"
}
L2_1087.Show = L3_1088
L1_1086.Inputs = L2_1087
L2_1087 = {}
L2_1087.Activate = "bool"
L2_1087.Explode = "bool"
L2_1087.ExplosivePlaced = "bool"
L2_1087.Hide = "bool"
L2_1087.Show = "bool"
L1_1086.Outputs = L2_1087
L0_1085.FlowEvents = L1_1086
