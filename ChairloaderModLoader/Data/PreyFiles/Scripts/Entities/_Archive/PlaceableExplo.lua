local L0_1031, L1_1032, L2_1033, L3_1034
L0_1031 = {}
L0_1031.type = "Trigger"
L1_1032 = {}
L1_1032.DimX = 5
L1_1032.DimY = 5
L1_1032.DimZ = 5
L1_1032.ScriptCommand = ""
L1_1032.PlaySequence = ""
L1_1032.dummyModel = "Objects/Pickups/explosive/explosive_dummy.cgf"
L1_1032.fileModel = "objects/pickups/explosive/explosive.cgf"
L1_1032.object_ModelDestroyed = ""
L1_1032.ExplosionEffect = ""
L1_1032.ExplosionScale = 1
L1_1032.countdown = 10
L1_1032.explDamage = 100
L1_1032.explRmin = 2
L1_1032.explRmax = 20.5
L1_1032.explRadius = 3
L1_1032.explImpulsive_pressure = 200
L1_1032.bInitiallyVisible = 1
L1_1032.bAutomaticPlaceable = 1
L1_1032.TextInstruction = ""
L1_1032.bActive = 1
L0_1031.Properties = L1_1032
L1_1032 = {}
L1_1032.pos = nil
L1_1032.damage = 100
L1_1032.rmin = 2
L1_1032.rmax = 20.5
L1_1032.radius = 3
L1_1032.impulsive_pressure = 200
L1_1032.shooter = nil
L1_1032.weapon = nil
L0_1031.explosion_params = L1_1032
L0_1031.countdown_step = 0
L1_1032 = {}
L1_1032.Model = "Objects/Editor/T.cgf"
L1_1032.ShowBounds = 1
L0_1031.Editor = L1_1032
L0_1031.timing_soundfile = "SOUNDS/items/bombcount.wav"
L0_1031.timing_sound = nil
PlaceableExplo = L0_1031
L0_1031 = PlaceableExplo
function L1_1032(A0_1035)
  if A0_1035.Properties.dummyModel ~= "" then
    A0_1035:LoadObject(A0_1035.Properties.dummyModel, 0, 1)
  end
  if A0_1035.Properties.fileModel ~= "" then
    A0_1035:LoadObject(A0_1035.Properties.fileModel, 1, 1)
  end
  if A0_1035.Properties.object_ModelDestroyed ~= "" then
    A0_1035:LoadObject(A0_1035.Properties.object_ModelDestroyed, 2, 1)
  end
end
L0_1031.LoadGeometry = L1_1032
L0_1031 = PlaceableExplo
function L1_1032(A0_1036)
  A0_1036:RegisterState("placeable")
  A0_1036:RegisterState("notarmed")
  A0_1036:RegisterState("armed")
  A0_1036:RegisterState("detonated")
end
L0_1031.RegisterStates = L1_1032
L0_1031 = PlaceableExplo
function L1_1032(A0_1037)
  local L1_1038, L2_1039
  L2_1039 = A0_1037
  L1_1038 = A0_1037.Activate
  L1_1038(L2_1039, 0)
  L2_1039 = A0_1037
  L1_1038 = A0_1037.TrackColliders
  L1_1038(L2_1039, 1)
  L2_1039 = A0_1037
  L1_1038 = A0_1037.GotoState
  L1_1038(L2_1039, "placeable")
  L1_1038 = {}
  L2_1039 = A0_1037.Properties
  L2_1039 = L2_1039.DimX
  L2_1039 = -L2_1039
  L2_1039 = L2_1039 / 2
  L1_1038.x = L2_1039
  L2_1039 = A0_1037.Properties
  L2_1039 = L2_1039.DimY
  L2_1039 = -L2_1039
  L2_1039 = L2_1039 / 2
  L1_1038.y = L2_1039
  L2_1039 = A0_1037.Properties
  L2_1039 = L2_1039.DimZ
  L2_1039 = -L2_1039
  L2_1039 = L2_1039 / 2
  L1_1038.z = L2_1039
  L2_1039 = {}
  L2_1039.x = A0_1037.Properties.DimX / 2
  L2_1039.y = A0_1037.Properties.DimY / 2
  L2_1039.z = A0_1037.Properties.DimZ / 2
  A0_1037:SetBBox(L1_1038, L2_1039)
  if A0_1037.Properties.ExplosionEffect ~= "" then
    A0_1037.explosion_effect = A0_1037.Properties.ExplosionEffect
  else
    A0_1037.explosion_effect = "explosions.grenade_air.explosion"
  end
  if A0_1037.Properties.bInitiallyVisible == 1 then
    A0_1037:DrawObject(0, 1)
  else
    A0_1037:DrawObject(0, 0)
  end
  A0_1037.bActive = A0_1037.Properties.bActive
end
L0_1031.OnReset = L1_1032
L0_1031 = PlaceableExplo
function L1_1032(A0_1040)
  A0_1040:OnReset()
end
L0_1031.OnMultiplayerReset = L1_1032
L0_1031 = PlaceableExplo
function L1_1032(A0_1041)
  A0_1041:OnReset()
end
L0_1031.OnPropertyChange = L1_1032
L0_1031 = PlaceableExplo
function L1_1032(A0_1042, A1_1043, A2_1044)
  if A1_1043 then
    if A1_1043 == 0 then
      A1_1043 = _localplayer.id
    end
    if Server:GetServerSlotByEntityId(A1_1043) then
      Server:GetServerSlotByEntityId(A1_1043):SendText(A2_1044, 0.9)
    end
  end
end
L0_1031.PrintMessage = L1_1032
L0_1031 = PlaceableExplo
function L1_1032(A0_1045, A1_1046)
  A1_1046:WriteInt(A0_1045.countdown_step)
  if A0_1045.target then
    if A0_1045.target == _localplayer.id then
      A1_1046:WriteInt(0)
    else
      A1_1046:WriteInt(A0_1045.target)
    end
  else
    A1_1046:WriteInt(-1)
  end
end
L0_1031.OnSave = L1_1032
L0_1031 = PlaceableExplo
function L1_1032(A0_1047, A1_1048)
  A0_1047.countdown_step = A1_1048:ReadInt()
  A0_1047.target = A1_1048:ReadInt()
  if A0_1047.target < 0 then
    A0_1047.target = nil
  end
end
L0_1031.OnLoad = L1_1032
L0_1031 = PlaceableExplo
function L1_1032(A0_1049, A1_1050)
end
L0_1031.OnLoadRELEASE = L1_1032
L0_1031 = PlaceableExplo
L1_1032 = {}
function L2_1033(A0_1051)
  A0_1051:LoadGeometry()
  A0_1051:RegisterStates()
  A0_1051:OnReset()
  A0_1051:NetPresent(nil)
end
L1_1032.OnInit = L2_1033
L2_1033 = {}
function L3_1034(A0_1052)
  A0_1052:DestroyPhysics()
end
L2_1033.OnBeginState = L3_1034
function L3_1034(A0_1053, A1_1054)
  if GameRules:IsInteractionPossible(A1_1054, A0_1053) and A1_1054.type == "Player" and not A1_1054:IsDead() then
    A0_1053.Who = A1_1054
    A0_1053:SetTimer(1)
  end
end
L2_1033.OnEnterArea = L3_1034
function L3_1034(A0_1055, A1_1056)
  if A1_1056 == A0_1055.Who then
    A0_1055.Who = nil
  end
end
L2_1033.OnLeaveArea = L3_1034
function L3_1034(A0_1057, A1_1058)
  if A0_1057.Who then
    A0_1057:Collide(A0_1057.Who)
    A0_1057:SetTimer(1)
  end
end
L2_1033.OnTimer = L3_1034
L1_1032.placeable = L2_1033
L2_1033 = {}
function L3_1034(A0_1059)
  A0_1059:DestroyPhysics()
end
L2_1033.OnBeginState = L3_1034
L1_1032.notarmed = L2_1033
L2_1033 = {}
function L3_1034(A0_1060)
  A0_1060:DestroyPhysics()
  if A0_1060.Properties.countdown >= 0 then
    A0_1060:SetTimer(1000)
  end
end
L2_1033.OnBeginState = L3_1034
function L3_1034(A0_1061)
  if A0_1061.Properties.countdown >= 0 then
    if A0_1061.countdown_step == 0 then
      A0_1061:GotoState("detonated")
      A0_1061:Event_Explode()
    else
      A0_1061:PrintMessage(A0_1061.target, A0_1061.countdown_step .. " @secondsleft")
      A0_1061.countdown_step = A0_1061.countdown_step - 1
      A0_1061:SetTimer(1000)
      A0_1061:PlaySound(A0_1061.timing_sound)
    end
  end
end
L2_1033.OnTimer = L3_1034
L1_1032.armed = L2_1033
L2_1033 = {}
function L3_1034(A0_1062)
  if A0_1062.Properties.object_ModelDestroyed ~= "" then
    A0_1062:CreateStaticEntity(10, 100)
  end
  A0_1062.target = nil
end
L2_1033.OnBeginState = L3_1034
L1_1032.detonated = L2_1033
L0_1031.Server = L1_1032
L0_1031 = PlaceableExplo
L1_1032 = {}
function L2_1033(A0_1063)
  A0_1063:LoadGeometry()
  A0_1063:RegisterStates()
  A0_1063.timing_sound = Sound.Load3DSound(A0_1063.timing_soundfile, 0, 0, 255, 10, 250)
  A0_1063:OnReset()
end
L1_1032.OnInit = L2_1033
L2_1033 = {}
function L3_1034(A0_1064)
  A0_1064:DrawObject(0, 1)
  A0_1064:DrawObject(1, 0)
  A0_1064:DrawObject(2, 0)
  A0_1064:DestroyPhysics()
  Sound.StopSound(A0_1064.timing_sound)
end
L2_1033.OnBeginState = L3_1034
L1_1032.placeable = L2_1033
L2_1033 = {}
function L3_1034(A0_1065)
  A0_1065:DrawObject(0, 0)
  A0_1065:DrawObject(1, 1)
  A0_1065:DrawObject(2, 0)
  A0_1065:DestroyPhysics()
  Sound.StopSound(A0_1065.timing_sound)
end
L2_1033.OnBeginState = L3_1034
L1_1032.notarmed = L2_1033
L2_1033 = {}
function L3_1034(A0_1066)
  A0_1066:DrawObject(0, 0)
  A0_1066:DrawObject(1, 1)
  A0_1066:DrawObject(2, 0)
  A0_1066:DestroyPhysics()
  A0_1066:PlaySound(A0_1066.timing_sound)
end
L2_1033.OnBeginState = L3_1034
L1_1032.armed = L2_1033
L2_1033 = {}
function L3_1034(A0_1067)
  A0_1067:DrawObject(0, 0)
  A0_1067:DrawObject(1, 0)
  A0_1067:DrawObject(2, 1)
  Sound.StopSound(A0_1067.timing_sound)
  if A0_1067.Properties.object_ModelDestroyed ~= "" then
    A0_1067:CreateStaticEntity(10, 100)
  end
end
L2_1033.OnBeginState = L3_1034
L1_1032.detonated = L2_1033
L0_1031.Client = L1_1032
L0_1031 = PlaceableExplo
function L1_1032(A0_1068, A1_1069)
  if A1_1069.type ~= "Player" or A1_1069.theVehicle then
    return
  end
  if A0_1068.bActive == 0 then
    return
  end
  for _FORV_5_, _FORV_6_ in pairs(A1_1069.explosives) do
    if _FORV_6_ == 1 then
      if A0_1068.Properties.bAutomaticPlaceable ~= 1 and not A1_1069.cnt.use_pressed then
        Hud.label = A0_1068.Properties.TextInstruction
        return
      end
      A1_1069.explosives[_FORV_5_] = 0
      A0_1068.target = A1_1069.id
      A0_1068:GotoState("armed")
      A0_1068.countdown_step = A0_1068.Properties.countdown
      A0_1068:Event_ExplosivePlaced()
      break
    end
  end
end
L0_1031.Collide = L1_1032
L0_1031 = PlaceableExplo
function L1_1032(A0_1070, A1_1071)
  A0_1070.bActive = 1
  BroadcastEvent(A0_1070, "Activate")
end
L0_1031.Event_Activate = L1_1032
L0_1031 = PlaceableExplo
function L1_1032(A0_1072, A1_1073)
  A0_1072.bActive = 0
  BroadcastEvent(A0_1072, "DeActivateAndHide")
  A0_1072:Event_Hide()
end
L0_1031.Event_DeActivateAndHide = L1_1032
L0_1031 = PlaceableExplo
function L1_1032(A0_1074, A1_1075)
  BroadcastEvent(A0_1074, "ExplosivePlaced")
end
L0_1031.Event_ExplosivePlaced = L1_1032
L0_1031 = PlaceableExplo
function L1_1032(A0_1076, A1_1077)
  BroadcastEvent(A0_1076, "Explode")
  A0_1076:Explode()
end
L0_1031.Event_Explode = L1_1032
L0_1031 = PlaceableExplo
function L1_1032(A0_1078, A1_1079)
  A0_1078:Hide(1)
end
L0_1031.Event_Hide = L1_1032
L0_1031 = PlaceableExplo
function L1_1032(A0_1080, A1_1081)
  A0_1080:Hide(0)
end
L0_1031.Event_Show = L1_1032
L0_1031 = PlaceableExplo
function L1_1032(A0_1082)
  local L1_1083, L2_1084
  L1_1083 = {}
  L1_1083.x = 0
  L1_1083.y = 0
  L1_1083.z = 0.7
  L2_1084 = A0_1082.GetPos
  L2_1084 = L2_1084(A0_1082)
  Particle.SpawnEffect(A0_1082.explosion_effect, L2_1084, L1_1083, A0_1082.Properties.ExplosionScale)
  CreateEntityLight(A0_1082, 7, 1, 1, 0.7, 0.5)
  A0_1082.explosion_params.pos = L2_1084
  A0_1082.explosion_params.shooter = A0_1082
  A0_1082.explosion_params.damage = A0_1082.Properties.explDamage
  A0_1082.explosion_params.rmin = A0_1082.Properties.explRmin
  A0_1082.explosion_params.rmax = A0_1082.Properties.explRmax
  A0_1082.explosion_params.radius = A0_1082.Properties.explRadius
  A0_1082.explosion_params.impulsive_pressure = A0_1082.Properties.explImpulsive_pressure
  Game:CreateExplosion(A0_1082.explosion_params)
  if A0_1082.Properties.ScriptCommand and A0_1082.Properties.ScriptCommand ~= "" then
    dostring(A0_1082.Properties.ScriptCommand)
  end
  if A0_1082.Properties.PlaySequence ~= "" then
    Movie.PlaySequence(A0_1082.Properties.PlaySequence)
  end
end
L0_1031.Explode = L1_1032
L0_1031 = PlaceableExplo
L1_1032 = {}
L2_1033 = {}
L3_1034 = {
  PlaceableExplo.Event_Activate,
  "bool"
}
L2_1033.Activate = L3_1034
L3_1034 = {
  PlaceableExplo.Event_DeActivate,
  "bool"
}
L2_1033.DeActivate = L3_1034
L3_1034 = {
  PlaceableExplo.Event_Explode,
  "bool"
}
L2_1033.Explode = L3_1034
L3_1034 = {
  PlaceableExplo.Event_ExplosivePlaced,
  "bool"
}
L2_1033.ExplosivePlaced = L3_1034
L3_1034 = {
  PlaceableExplo.Event_Hide,
  "bool"
}
L2_1033.Hide = L3_1034
L3_1034 = {
  PlaceableExplo.Event_Show,
  "bool"
}
L2_1033.Show = L3_1034
L1_1032.Inputs = L2_1033
L2_1033 = {}
L2_1033.Activate = "bool"
L2_1033.DeActivate = "bool"
L2_1033.Explode = "bool"
L2_1033.ExplosivePlaced = "bool"
L2_1033.Hide = "bool"
L2_1033.Show = "bool"
L1_1032.Outputs = L2_1033
L0_1031.FlowEvents = L1_1032
