local L0_6121, L1_6122
L0_6121 = {}
L1_6122 = {}
L0_6121.Client = L1_6122
L1_6122 = {}
L0_6121.Server = L1_6122
L1_6122 = {}
L1_6122.objModel = "objects/weapons/us/av_mine/avmine.cgf"
L1_6122.Health = 200
L1_6122.MainExplosion = {
  Effect = "explosions.rocket.soil",
  EffectScale = 0.4,
  Radius = 25,
  Pressure = 500,
  Damage = 250,
  Decal = "textures/decal/explo_decal.dds",
  DecalScale = 1,
  Direction = {
    x = 0,
    y = 0,
    z = -1
  },
  SoundEffect = "Sounds/physics:explosions:explo_big_01"
}
L1_6122.HugeExplosion = {
  Effect = "explosions.TAC.mushroom",
  EffectScale = 0.4,
  Radius = 500,
  Pressure = 800,
  Damage = 800,
  Decal = "textures/decal/explo_decal.dds",
  DecalScale = 1,
  Direction = {
    x = 0,
    y = 0,
    z = -1
  },
  SoundEffect = "Sounds/physics:explosions:explo_big_01"
}
L0_6121.Properties = L1_6122
L1_6122 = {}
L1_6122.Icon = "Item.bmp"
L1_6122.IconOnTop = 1
L0_6121.Editor = L1_6122
L0_6121.AttachedEntity = nil
L0_6121.ModelSlot = 0
L0_6121.SmokeSlot = -1
L1_6122 = {
  "Idle",
  "Carried",
  "Active",
  "Armed",
  "Destroyed"
}
L0_6121.States = L1_6122
L0_6121.ArmedBeepSound = "Sounds/crysiswars2:interface:multiplayer/mp_match_timer_beep"
L0_6121.ARMED_BEEP_TIME = 1000
L0_6121.ARMED_BEEP = 1
BTBBomb = L0_6121
L0_6121 = BTBBomb
L0_6121 = L0_6121.Server
function L1_6122(A0_6123)
  Log("BTBBomb.Server.OnInit")
  if not A0_6123.bInitialized then
    A0_6123:OnReset()
    A0_6123.bInitialized = 1
  end
end
L0_6121.OnInit = L1_6122
L0_6121 = BTBBomb
L0_6121 = L0_6121.Client
function L1_6122(A0_6124)
  Log("BTBBomb.Client.OnInit")
  if not A0_6124.bInitialized then
    A0_6124:OnReset()
    A0_6124.bInitialized = 1
  end
  A0_6124:CacheResources()
end
L0_6121.OnInit = L1_6122
L0_6121 = BTBBomb
function L1_6122(A0_6125)
  A0_6125:PreLoadParticleEffect("smoke_and_fire.Jeep.hull_smoke")
end
L0_6121.CacheResources = L1_6122
L0_6121 = BTBBomb
function L1_6122(A0_6126)
  local L1_6127, L2_6128, L3_6129
  L1_6127 = Log
  L2_6128 = "BTBBomb.OnReset"
  L1_6127(L2_6128)
  L2_6128 = A0_6126
  L1_6127 = A0_6126.LoadCorrectGeometry
  L1_6127(L2_6128)
  L1_6127 = 1
  L2_6128 = {}
  L3_6129 = -L1_6127
  L2_6128.x = L3_6129
  L3_6129 = -L1_6127
  L2_6128.y = L3_6129
  L3_6129 = -L1_6127
  L2_6128.z = L3_6129
  L3_6129 = {}
  L3_6129.x = L1_6127
  L3_6129.y = L1_6127
  L3_6129.z = L1_6127
  A0_6126:SetTriggerBBox(L2_6128, L3_6129)
  A0_6126:Physicalize(A0_6126.ModelSlot, PE_RIGID, {mass = 0})
  A0_6126:SetScale(3)
  A0_6126.health = A0_6126.Properties.Health
  A0_6126.inside = {}
  if A0_6126.SmokeSlot ~= -1 then
    A0_6126:FreeSlot(A0_6126.SmokeSlot)
    A0_6126.SmokeSlot = -1
  end
  A0_6126:DrawSlot(A0_6126.ModelSlot, 1)
  A0_6126:GotoState("Idle")
end
L0_6121.OnReset = L1_6122
L0_6121 = BTBBomb
function L1_6122(A0_6130)
  Log("BTBBomb:Reset()")
  A0_6130:OnReset()
end
L0_6121.Reset = L1_6122
L0_6121 = BTBBomb
function L1_6122(A0_6131)
  CryAction.CreateGameObjectForEntity(A0_6131.id)
  CryAction.BindGameObjectToNetwork(A0_6131.id)
  CryAction.ForceGameObjectUpdate(A0_6131.id, true)
  A0_6131:Activate(1)
  A0_6131:OnReset()
end
L0_6121.OnSpawn = L1_6122
L0_6121 = BTBBomb
function L1_6122(A0_6132, A1_6133, A2_6134)
  Log("BTBBomb:LoadGeometry() model = \"" .. A2_6134 .. "\"")
  if string.len(A2_6134) > 0 then
    if string.lower(string.sub(A2_6134, -4)) == ".chr" or string.lower(string.sub(A2_6134, -4)) == ".cdf" or string.lower(string.sub(A2_6134, -4)) == ".cga" then
      A0_6132:LoadCharacter(A1_6133, A2_6134)
    else
      A0_6132:LoadObject(A1_6133, A2_6134)
    end
  end
end
L0_6121.LoadGeometry = L1_6122
L0_6121 = BTBBomb
function L1_6122(A0_6135)
  Log("BTBBomb.LoadCorrectGeometry()")
  A0_6135:LoadGeometry(A0_6135.ModelSlot, A0_6135.Properties.objModel)
end
L0_6121.LoadCorrectGeometry = L1_6122
L0_6121 = BTBBomb
L0_6121 = L0_6121.Server
function L1_6122(A0_6136, A1_6137)
  A0_6136:OnHit(A1_6137, true)
end
L0_6121.OnHit = L1_6122
L0_6121 = BTBBomb
L0_6121 = L0_6121.Client
function L1_6122(A0_6138, A1_6139)
  A0_6138:OnHit(A1_6139, false)
end
L0_6121.OnHit = L1_6122
L0_6121 = BTBBomb
function L1_6122(A0_6140, A1_6141, A2_6142)
  if A0_6140:GetState() ~= "Active" then
    Log("BTBBomb:OnHit Can only be shot when active")
  end
  if A1_6141.shooter == A0_6140 then
    Log("BTBBomb:OnHit Can't damage self!")
    return
  end
  A0_6140.health = A0_6140.health - A1_6141.damage
  if A0_6140.health < A0_6140.Properties.Health * 0.25 and A0_6140.SmokeSlot == -1 then
    A0_6140.SmokeSlot = A0_6140:LoadParticleEffect(-1, "smoke_and_fire.Jeep.hull_smoke", {})
  end
  if A0_6140.health <= 0 and A2_6142 == true and g_gameRules.Server.BombZeroHealth ~= nil then
    g_gameRules.Server.BombZeroHealth(g_gameRules)
  end
  Log("HIT BOMB! health :%d", A0_6140.health)
end
L0_6121.OnHit = L1_6122
L0_6121 = BTBBomb
function L1_6122(A0_6143)
  A0_6143:GotoState("Armed")
end
L0_6121.Armed = L1_6122
L0_6121 = BTBBomb
function L1_6122(A0_6144)
  A0_6144:GotoState("Carried")
end
L0_6121.Carried = L1_6122
L0_6121 = BTBBomb
function L1_6122(A0_6145)
  A0_6145:GotoState("Active")
end
L0_6121.Active = L1_6122
L0_6121 = BTBBomb
function L1_6122(A0_6146)
  A0_6146:GotoState("Destroyed")
end
L0_6121.Destroyed = L1_6122
L0_6121 = BTBBomb
function L1_6122(A0_6147)
  A0_6147:OnReset()
end
L0_6121.OnPropertyChange = L1_6122
L0_6121 = BTBBomb
function L1_6122(A0_6148, A1_6149, A2_6150)
  Log("BTBBomb.OnEnterArea")
  if A1_6149 and A1_6149.actor and A1_6149.actor:IsPlayer() then
    InsertIntoTable(A0_6148.inside, A1_6149.id)
    if g_gameRules.Server.EntityEnterBombArea ~= nil then
      g_gameRules.Server.EntityEnterBombArea(g_gameRules, A1_6149, A0_6148)
    end
  end
end
L0_6121.OnEnterArea = L1_6122
L0_6121 = BTBBomb
function L1_6122(A0_6151, A1_6152, A2_6153)
  Log("BTBBomb.OnLeaveArea")
  if A1_6152 and A1_6152.actor and A1_6152.actor:IsPlayer() then
    RemoveFromTable(A0_6151.inside, A1_6152.id)
  end
end
L0_6121.OnLeaveArea = L1_6122
L0_6121 = BTBBomb
function L1_6122(A0_6154, A1_6155)
  if A0_6154.AttachedEntity ~= nil then
    A0_6154:DetachThis(1, 0)
    A0_6154:SetAngles({
      x = 0,
      y = 0,
      z = 0
    })
    A0_6154:EnablePhysics(true)
  end
  A0_6154.AttachedEntity = A1_6155
  if A1_6155 ~= nil then
    A0_6154:EnablePhysics(false)
    A0_6154:SetPos(A1_6155:GetPos())
    A1_6155:AttachChild(A0_6154.id, 1)
  end
end
L0_6121.AttachTo = L1_6122
L0_6121 = BTBBomb
function L1_6122(A0_6156, A1_6157)
  A0_6156:Explode(A0_6156.Properties.MainExplosion, A1_6157)
end
L0_6121.ExplodeMain = L1_6122
L0_6121 = BTBBomb
function L1_6122(A0_6158, A1_6159)
  A0_6158:Explode(A0_6158.Properties.HugeExplosion, A1_6159)
end
L0_6121.ExplodeHuge = L1_6122
L0_6121 = BTBBomb
function L1_6122(A0_6160, A1_6161, A2_6162)
  local L3_6163
  L3_6163 = Log
  L3_6163("BTBBomb:Explode %s", tostring(A2_6162))
  if A2_6162 then
    L3_6163 = A1_6161.Radius
    g_gameRules:CreateExplosion(A0_6160.id, A0_6160.id, A1_6161.Damage, A0_6160:GetPos(), A1_6161.Direction, L3_6163, nil, A1_6161.Pressure, A1_6161.HoleSize, A1_6161.Effect, A1_6161.EffectScale)
  end
  L3_6163 = Sound
  L3_6163 = L3_6163.Play
  L3_6163(A1_6161.SoundEffect, A0_6160:GetPos(), SOUND_DEFAULT_3D, SOUND_SEMANTIC_MECHANIC_ENTITY)
  L3_6163 = A0_6160.GotoState
  L3_6163(A0_6160, "Destroyed")
end
L0_6121.Explode = L1_6122
L0_6121 = BTBBomb
L0_6121 = L0_6121.Server
L1_6122 = {}
function L1_6122.OnBeginState(A0_6164)
  A0_6164:EnablePhysics(false)
end
function L1_6122.OnEnterArea(A0_6165, A1_6166, A2_6167)
  A0_6165:OnEnterArea(A1_6166, A2_6167)
end
function L1_6122.OnLeaveArea(A0_6168, A1_6169, A2_6170)
  A0_6168:OnLeaveArea(A1_6169, A2_6170)
end
L0_6121.Idle = L1_6122
L0_6121 = BTBBomb
L0_6121 = L0_6121.Client
L1_6122 = {}
function L1_6122.OnBeginState(A0_6171)
  A0_6171:EnablePhysics(false)
end
L0_6121.Idle = L1_6122
L0_6121 = BTBBomb
L0_6121 = L0_6121.Server
L1_6122 = {}
function L1_6122.OnBeginState(A0_6172)
  A0_6172:EnablePhysics(false)
end
function L1_6122.OnEnterArea(A0_6173, A1_6174, A2_6175)
  A0_6173:OnEnterArea(A1_6174, A2_6175)
end
function L1_6122.OnLeaveArea(A0_6176, A1_6177, A2_6178)
  A0_6176:OnLeaveArea(A1_6177, A2_6178)
end
L0_6121.Carried = L1_6122
L0_6121 = BTBBomb
L0_6121 = L0_6121.Client
L1_6122 = {}
function L1_6122.OnBeginState(A0_6179)
  A0_6179:EnablePhysics(false)
end
L0_6121.Carried = L1_6122
L0_6121 = BTBBomb
L0_6121 = L0_6121.Server
L1_6122 = {}
function L1_6122.OnBeginState(A0_6180)
  A0_6180:EnablePhysics(true)
  if A0_6180.health < 100 and A0_6180.SmokeSlot == -1 then
    A0_6180.SmokeSlot = A0_6180:LoadParticleEffect(-1, "smoke_and_fire.Jeep.hull_smoke", {})
  end
end
function L1_6122.OnEnterArea(A0_6181, A1_6182, A2_6183)
  A0_6181:OnEnterArea(A1_6182, A2_6183)
end
function L1_6122.OnLeaveArea(A0_6184, A1_6185, A2_6186)
  A0_6184:OnLeaveArea(A1_6185, A2_6186)
end
function L1_6122.OnEndState(A0_6187)
  if A0_6187.SmokeSlot ~= -1 then
    A0_6187:FreeSlot(A0_6187.SmokeSlot)
    A0_6187.SmokeSlot = -1
  end
end
L0_6121.Active = L1_6122
L0_6121 = BTBBomb
L0_6121 = L0_6121.Client
L1_6122 = {}
function L1_6122.OnBeginState(A0_6188)
  A0_6188:EnablePhysics(true)
  if A0_6188.health < 100 and A0_6188.SmokeSlot == -1 then
    A0_6188.SmokeSlot = A0_6188:LoadParticleEffect(-1, "smoke_and_fire.Jeep.hull_smoke", {})
  end
end
function L1_6122.OnEndState(A0_6189)
  if A0_6189.SmokeSlot ~= -1 then
    A0_6189:FreeSlot(A0_6189.SmokeSlot)
    A0_6189.SmokeSlot = -1
  end
end
L0_6121.Active = L1_6122
L0_6121 = BTBBomb
L0_6121 = L0_6121.Server
L1_6122 = {}
function L1_6122.OnBeginState(A0_6190)
  A0_6190:EnablePhysics(false)
  A0_6190:DrawSlot(A0_6190.ModelSlot, 0)
end
L0_6121.Destroyed = L1_6122
L0_6121 = BTBBomb
L0_6121 = L0_6121.Client
L1_6122 = {}
function L1_6122.OnBeginState(A0_6191)
  A0_6191:EnablePhysics(false)
  A0_6191:DrawSlot(A0_6191.ModelSlot, 0)
end
L0_6121.Destroyed = L1_6122
L0_6121 = BTBBomb
L0_6121 = L0_6121.Server
L1_6122 = {}
function L1_6122.OnBeginState(A0_6192)
  A0_6192:EnablePhysics(false)
end
function L1_6122.OnTimer(A0_6193, A1_6194)
end
function L1_6122.OnEndState(A0_6195)
  local L1_6196
end
L0_6121.Armed = L1_6122
L0_6121 = BTBBomb
L0_6121 = L0_6121.Client
L1_6122 = {}
function L1_6122.OnBeginState(A0_6197)
  A0_6197:SetTimer(A0_6197.ARMED_BEEP, A0_6197.ARMED_BEEP_TIME)
  Sound.Play(A0_6197.ArmedBeepSound, A0_6197:GetPos(), SOUND_DEFAULT_3D, SOUND_SEMANTIC_MECHANIC_ENTITY)
  A0_6197:EnablePhysics(false)
end
function L1_6122.OnTimer(A0_6198, A1_6199)
  if A1_6199 == A0_6198.ARMED_BEEP then
    Sound.Play(A0_6198.ArmedBeepSound, A0_6198:GetPos(), SOUND_DEFAULT_3D, SOUND_SEMANTIC_MECHANIC_ENTITY)
    A0_6198:SetTimer(A0_6198.ARMED_BEEP, A0_6198.ARMED_BEEP_TIME)
  end
end
function L1_6122.OnEndState(A0_6200)
  A0_6200:KillTimer(A0_6200.ARMED_BEEP)
end
L0_6121.Armed = L1_6122
