local L0_1217, L1_1218, L2_1219, L3_1220
L0_1217 = {}
L0_1217.type = "Mine"
L0_1217.MapVisMask = 0
L1_1218 = {}
L1_1218.Radius = 4
L1_1218.bEnabled = 1
L1_1218.Delay = 2
L1_1218.bOnlyPlayer = 1
L1_1218.fileActivationSound = "SOUNDS/items/nvisionactivate.wav"
L1_1218.fileModel = "Objects/Pickups/Health/Medikit.cgf"
L1_1218.nExplosionDamage = 300
L0_1217.Properties = L1_1218
L1_1218 = {}
L1_1218.pos = nil
L1_1218.damage = 100
L1_1218.rmin = 2
L1_1218.rmax = 20.5
L1_1218.radius = 3
L1_1218.impulsive_pressure = 200
L1_1218.shooter = nil
L1_1218.weapon = nil
L0_1217.ExplosionParams = L1_1218
L0_1217.mine_triggered = nil
L0_1217.activation_sound = nil
L0_1217.Who = nil
L0_1217.Enabled = 1
ProximityMine = L0_1217
L0_1217 = ProximityMine
function L1_1218(A0_1221)
  A0_1221:OnReset()
end
L0_1217.OnPropertyChange = L1_1218
L0_1217 = ProximityMine
function L1_1218(A0_1222)
  A0_1222:Activate(0)
  A0_1222:TrackColliders(1)
  A0_1222:LoadObject(A0_1222.Properties.fileModel, 0, 1)
  A0_1222:CreateStaticEntity(10, 100)
  A0_1222:OnReset()
end
L0_1217.OnInit = L1_1218
L0_1217 = ProximityMine
function L1_1218(A0_1223)
  local L1_1224
end
L0_1217.OnShutDown = L1_1218
L0_1217 = ProximityMine
function L1_1218(A0_1225)
  local L1_1226, L2_1227
  L1_1226 = {}
  L2_1227 = A0_1225.Properties
  L2_1227 = L2_1227.Radius
  L2_1227 = -L2_1227
  L2_1227 = L2_1227 / 2
  L1_1226.x = L2_1227
  L2_1227 = A0_1225.Properties
  L2_1227 = L2_1227.Radius
  L2_1227 = -L2_1227
  L2_1227 = L2_1227 / 2
  L1_1226.y = L2_1227
  L2_1227 = A0_1225.Properties
  L2_1227 = L2_1227.Radius
  L2_1227 = -L2_1227
  L2_1227 = L2_1227 / 2
  L1_1226.z = L2_1227
  L2_1227 = {}
  L2_1227.x = A0_1225.Properties.Radius / 2
  L2_1227.y = A0_1225.Properties.Radius / 2
  L2_1227.z = A0_1225.Properties.Radius / 2
  A0_1225:SetBBox(L1_1226, L2_1227)
  A0_1225:DrawObject(0, 1)
  A0_1225.Enabled = A0_1225.Properties.bEnabled
  A0_1225.activation_sound = Sound.Load3DSound(A0_1225.Properties.fileActivationSound)
  A0_1225.Who = nil
  A0_1225.Died = 0
  A0_1225:GotoState("Waiting")
end
L0_1217.OnReset = L1_1218
L0_1217 = ProximityMine
function L1_1218(A0_1228, A1_1229)
  A0_1228.Enabled = 1
  BroadcastEvent(A0_1228, "Enable")
end
L0_1217.Event_Enable = L1_1218
L0_1217 = ProximityMine
function L1_1218(A0_1230, A1_1231)
  A0_1230.Enabled = 0
  BroadcastEvent(A0_1230, "Disable")
end
L0_1217.Event_Disable = L1_1218
L0_1217 = ProximityMine
function L1_1218(A0_1232, A1_1233)
  if A0_1232.Enabled then
    A0_1232:Explode()
    A0_1232:GotoState("Dead")
  end
  BroadcastEvent(A0_1232, "Trigger")
end
L0_1217.Event_Explode = L1_1218
L0_1217 = ProximityMine
function L1_1218(A0_1234, A1_1235)
  local L2_1236
  L2_1236 = A0_1234.Properties
  L2_1236 = L2_1236.bOnlyPlayer
  if L2_1236 ~= 0 then
    L2_1236 = A1_1235.type
    if L2_1236 ~= "Player" then
      L2_1236 = 0
      return L2_1236
    end
  end
  L2_1236 = 1
  return L2_1236
end
L0_1217.IsValid = L1_1218
L0_1217 = ProximityMine
L1_1218 = {}
function L2_1219(A0_1237)
  A0_1237.Died = 1
  A0_1237:DrawObject(0, 0)
end
L1_1218.OnBeginState = L2_1219
L0_1217.Dead = L1_1218
L0_1217 = ProximityMine
L1_1218 = {}
function L2_1219(A0_1238)
  local L1_1239
  A0_1238.Who = nil
  A0_1238.sound_played = nil
end
L1_1218.OnBeginState = L2_1219
function L2_1219(A0_1240, A1_1241, A2_1242)
  A0_1240:SetPos(A1_1241:GetPos())
  A0_1240:Explode(A0_1240)
end
L1_1218.OnEnterArea = L2_1219
function L2_1219(A0_1243, A1_1244)
  if A0_1243.Enabled ~= 1 then
    return
  end
  if A0_1243:IsValid(A1_1244) == 0 then
    return
  end
  A0_1243.Who = A1_1244
  if A0_1243.mine_triggered == nil then
    if A0_1243.activation_sound == nil then
      System.LogToConsole("Activation sound is nil")
    end
    Sound.SetSoundPosition(A0_1243.activation_sound, A0_1243:GetPos())
    Sound.PlaySound(A0_1243.activation_sound)
    A0_1243.mine_triggered = 1
    A0_1243:SetTimer(A0_1243.Properties.Delay * 1000 + 1)
  end
end
L1_1218.OnEnterArea = L2_1219
function L2_1219(A0_1245)
  A0_1245:Event_Explode(A0_1245)
end
L1_1218.OnTimer = L2_1219
function L2_1219(A0_1246, A1_1247)
  A0_1246:Event_Explode(A1_1247.shooter)
end
L1_1218.OnDamage = L2_1219
L0_1217.Waiting = L1_1218
L0_1217 = ProximityMine
function L1_1218(A0_1248)
  local L1_1249, L2_1250
  L1_1249 = {}
  L1_1249.x = 0
  L1_1249.y = 0
  L1_1249.z = -0.1
  L2_1250 = A0_1248.GetPos
  L2_1250 = L2_1250(A0_1248)
  ExecuteMaterial(L2_1250, L1_1249, Materials.mat_default.projectile_hit, 1)
  A0_1248.ExplosionParams.pos = L2_1250
  A0_1248.ExplosionParams.shooter = A0_1248
  A0_1248:GotoState("Dead")
  A0_1248.ExplosionParams.damage = A0_1248.Properties.nExplosionDamage
  Game:CreateExplosion(A0_1248.ExplosionParams)
end
L0_1217.Explode = L1_1218
L0_1217 = ProximityMine
L1_1218 = {}
L2_1219 = {}
L3_1220 = {
  ProximityMine.Event_Disable,
  "bool"
}
L2_1219.Disable = L3_1220
L3_1220 = {
  ProximityMine.Event_Enable,
  "bool"
}
L2_1219.Enable = L3_1220
L3_1220 = {
  ProximityMine.Event_Explode,
  "bool"
}
L2_1219.Explode = L3_1220
L1_1218.Inputs = L2_1219
L2_1219 = {}
L2_1219.Disable = "bool"
L2_1219.Enable = "bool"
L2_1219.Explode = "bool"
L1_1218.Outputs = L2_1219
L0_1217.FlowEvents = L1_1218
