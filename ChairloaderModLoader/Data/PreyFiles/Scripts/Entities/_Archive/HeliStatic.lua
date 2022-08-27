local L0_904, L1_905
L0_904 = {}
L0_904.temp_ModelName = "none"
L0_904.pathStep = 0
L0_904.dropState = 0
L1_905 = {}
L1_905.mass = 900
L1_905.height = 0.1
L1_905.eyeheight = 0.1
L1_905.sphereheight = 0.1
L1_905.radius = 0.5
L1_905.gravity = 0
L1_905.aircontrol = 1
L0_904.V22PhysParams = L1_905
L0_904.damage = 0
L0_904.bExploded = 0
L1_905 = {}
L0_904.pieces = L1_905
L0_904.explosionImpulse = 10
L1_905 = {}
L1_905.fDmgScaleBullet = 0.1
L1_905.fDmgScaleExplosion = 1.7
L1_905.max_health = 100
L1_905.bRigidBodyActive = 0
L1_905.Mass = 5000
L1_905.fileModel = "objects/vehicles/troopgunship/troopgunship_inflight.cgf"
L1_905.ExplosionParams = {
  nDamage = 100,
  fRadiusMin = 20,
  fRadiusMax = 20.5,
  fRadius = 20,
  fImpulsivePressure = 100600
}
L1_905.sound_engine_file = "SOUNDS/Ambient/E3/hele/heleLP1.wav"
L0_904.Properties = L1_905
L1_905 = {}
L1_905.focus = 1.8
L1_905.speed = 1.55
L1_905.count = 1
L1_905.size = 0.04
L1_905.size_speed = 0.1
L1_905.gravity = {
  x = 0,
  y = 0,
  z = 0.3
}
L1_905.rotation = {
  x = 0,
  y = 0,
  z = 1.75
}
L1_905.lifetime = 2
L1_905.tid = System.LoadTexture("textures/clouda.dds")
L1_905.frames = 0
L1_905.color_based_blending = 0
L0_904.DamageParticles1 = L1_905
L1_905 = {}
L1_905.focus = 1.8
L1_905.speed = 0.6
L1_905.count = 1
L1_905.size = 0.3
L1_905.size_speed = 0.5
L1_905.gravity = {
  x = 0.3,
  y = 0,
  z = 0.3
}
L1_905.rotation = {
  x = 1.75,
  y = 1,
  z = 1.75
}
L1_905.lifetime = 4
L1_905.tid = System.LoadTexture("textures\\cloud_black1.dds")
L1_905.frames = 0
L1_905.color_based_blending = 0
L0_904.DamageParticles2 = L1_905
L0_904.sound_engine = nil
HeliStatic = L0_904
L0_904 = HeliStatic
L1_905 = {}
function L1_905.OnInit(A0_906)
  System.Log("Client HeliStatic onInit")
  A0_906:InitClient()
end
function L1_905.OnContact(A0_907, A1_908)
  A0_907:OnContactClient(A1_908)
end
function L1_905.OnUpdate(A0_909, A1_910)
  A0_909:UpdateClient(A1_910)
end
L0_904.Client = L1_905
L0_904 = HeliStatic
L1_905 = {}
function L1_905.OnInit(A0_911)
  System.Log("Server HeliStatic onInit")
  A0_911:InitServer()
end
function L1_905.OnContact(A0_912, A1_913)
  A0_912:OnContactServer(A1_913)
end
function L1_905.OnEvent(A0_914, A1_915, A2_916)
  A0_914:OnEventServer(A1_915, A2_916)
end
function L1_905.OnShutDown(A0_917)
  A0_917:OnShutDownServer(A0_917)
end
function L1_905.OnUpdate(A0_918, A1_919)
  A0_918:UpdateServer(A1_919)
end
function L1_905.OnDamage(A0_920, A1_921)
  A0_920:OnDamageServer(A1_921)
end
L0_904.Server = L1_905
L0_904 = HeliStatic
function L1_905(A0_922)
  A0_922.damage = 0
  A0_922.sound_engine = Sound.Load3DSound(A0_922.Properties.sound_engine_file, bor(SOUND_OUTDOOR, SOUND_UNSCALABLE), 0, 255, 1, 100)
end
L0_904.OnReset = L1_905
L0_904 = HeliStatic
function L1_905(A0_923)
  A0_923:OnReset()
  A0_923:LoadModel()
  Sound.SetSoundLoop(A0_923.sound_engine, 1)
end
L0_904.OnPropertyChange = L1_905
L0_904 = HeliStatic
function L1_905(A0_924)
  local L1_925, L2_926
  L1_925 = A0_924.temp_ModelName
  L2_926 = A0_924.Properties
  L2_926 = L2_926.fileModel
  if L1_925 ~= L2_926 then
    L2_926 = A0_924
    L1_925 = A0_924.LoadObject
    L1_925(L2_926, A0_924.Properties.fileModel, 0, 1)
    L1_925 = A0_924.Properties
    L1_925 = L1_925.bRigidBodyActive
    if L1_925 == 1 then
      L2_926 = A0_924
      L1_925 = A0_924.CreateRigidBody
      L1_925(L2_926, 1000, 5000, 0)
    else
      L2_926 = A0_924
      L1_925 = A0_924.CreateStaticEntity
      L1_925(L2_926, 5000, 0)
      L2_926 = A0_924
      L1_925 = A0_924.EnablePhysics
      L1_925(L2_926, 1)
      L2_926 = A0_924
      L1_925 = A0_924.DrawObject
      L1_925(L2_926, 0, 1)
    end
    L1_925 = A0_924.Properties
    L1_925 = L1_925.fileModel
    A0_924.temp_ModelName = L1_925
    L1_925 = 1
    L2_926 = 1
    while true do
      if L2_926 == 1 and Server:SpawnEntity("Piece") then
        System.Log("loading Piece #" .. L1_925)
        A0_924.pieces[L1_925] = Server:SpawnEntity("Piece")
        L2_926 = A0_924.pieces[L1_925].Load(A0_924.pieces[L1_925], A0_924.Properties.fileModel, L1_925)
        L1_925 = L1_925 + 1
        break
      end
    end
    A0_924.pieces[L1_925 - 1] = nil
  end
  L1_925 = A0_924.Properties
  L1_925 = L1_925.fileModel
  A0_924.temp_ModelName = L1_925
end
L0_904.LoadModel = L1_905
L0_904 = HeliStatic
function L1_905(A0_927)
  A0_927:LoadModel()
  A0_927:OnReset()
  Sound.SetSoundLoop(A0_927.sound_engine, 1)
  A0_927.ExplosionSound = Sound.Load3DSound("sounds\\weapons\\explosions\\mbarrel.wav", 0, 0, 0, 7, 100)
end
L0_904.InitClient = L1_905
L0_904 = HeliStatic
function L1_905(A0_928)
  A0_928:OnReset()
  A0_928:Activate(1)
  A0_928:LoadModel()
end
L0_904.InitServer = L1_905
L0_904 = HeliStatic
function L1_905(A0_929, A1_930)
  if A1_930.type ~= "Player" then
    return
  end
end
L0_904.OnContactServer = L1_905
L0_904 = HeliStatic
function L1_905(A0_931, A1_932)
  if A1_932.type ~= "Player" then
    return
  end
end
L0_904.OnContactClient = L1_905
L0_904 = HeliStatic
function L1_905(A0_933, A1_934)
end
L0_904.UpdateServer = L1_905
L0_904 = HeliStatic
function L1_905(A0_935, A1_936)
  local L2_937
  L2_937 = A0_935.GetPos
  L2_937 = L2_937(A0_935)
  L2_937.z = L2_937.z - 5
  System.ApplyForceToEnvironment(L2_937, 50, 1)
  if _localplayer and _localplayer.id and A0_935.sound_engine ~= nil then
    if System.IsPointIndoors(_localplayer:GetPos()) then
      if Sound.IsPlaying(A0_935.sound_engine) then
        Sound.StopSound(A0_935.sound_engine)
      end
    else
      Sound.SetSoundPosition(A0_935.sound_engine, L2_937)
      if Sound.IsPlaying(A0_935.sound_engine) == nil then
        Sound.PlaySound(A0_935.sound_engine)
      end
    end
  end
  A0_935:ExecuteDamageModel()
end
L0_904.UpdateClient = L1_905
L0_904 = HeliStatic
function L1_905(A0_938, A1_939)
  System.LogToConsole("Damage  " .. A1_939.damage .. " total " .. A0_938.damage)
  if A0_938.damage < 0 then
    return
  end
  if A1_939.explosion then
    A0_938.damage = A0_938.damage + A1_939.damage * A0_938.Properties.fDmgScaleExplosion
  else
    A0_938.damage = A0_938.damage + A1_939.damage * A0_938.Properties.fDmgScaleBullet
  end
end
L0_904.OnDamageServer = L1_905
L0_904 = HeliStatic
function L1_905(A0_940)
  System.LogToConsole("HeliStatic OnShutDOWN ---------------------------")
  for _FORV_4_, _FORV_5_ in pairs(A0_940.pieces) do
    Server:RemoveEntity(_FORV_5_.id)
  end
end
L0_904.OnShutDownServer = L1_905
L0_904 = HeliStatic
function L1_905(A0_941, A1_942)
end
L0_904.OnSave = L1_905
L0_904 = HeliStatic
function L1_905(A0_943, A1_944)
end
L0_904.OnLoad = L1_905
L0_904 = HeliStatic
function L1_905(A0_945, A1_946, A2_947)
end
L0_904.OnEventServer = L1_905
L0_904 = HeliStatic
function L1_905(A0_948, A1_949)
end
L0_904.OnWrite = L1_905
L0_904 = HeliStatic
function L1_905(A0_950, A1_951)
end
L0_904.OnRead = L1_905
L0_904 = HeliStatic
function L1_905(A0_952)
  local L1_953
  L1_953 = A0_952.damage
  if L1_953 > A0_952.Properties.max_health * 0.2 then
    L1_953 = A0_952.GetHelperPos
    L1_953 = L1_953(A0_952, "vehicle_damage1", 0)
    Particle.CreateParticle(L1_953, {
      x = 0,
      y = 0,
      z = 1
    }, A0_952.DamageParticles1)
    if A0_952.damage > A0_952.Properties.max_health then
      L1_953 = A0_952:GetHelperPos("vehicle_damage2", 0)
      Particle.CreateParticle(L1_953, {
        x = 0,
        y = 0,
        z = 1
      }, A0_952.DamageParticles2)
      HeliStatic.BlowUp(A0_952)
    end
  end
end
L0_904.ExecuteDamageModel = L1_905
L0_904 = HeliStatic
function L1_905(A0_954)
  local L1_955, L2_956
  L1_955 = A0_954.bExploded
  if L1_955 == 1 then
    return
  end
  L1_955 = {}
  L1_955.x = 0
  L1_955.y = 0
  L1_955.z = 1
  L2_956 = ExecuteMaterial
  L2_956(A0_954:GetPos(), L1_955, HeliExplosion, 1)
  L2_956 = {}
  L2_956.pos = A0_954:GetPos()
  L2_956.damage = A0_954.Properties.ExplosionParams.nDamage
  L2_956.rmin = A0_954.Properties.ExplosionParams.fRadiusMin
  L2_956.rmax = A0_954.Properties.ExplosionParams.fRadiusMax
  L2_956.radius = A0_954.Properties.ExplosionParams.fRadius
  L2_956.impulsive_pressure = A0_954.Properties.ExplosionParams.fImpulsivePressure
  L2_956.shooter = A0_954
  L2_956.weapon = A0_954
  Game:CreateExplosion(L2_956)
  L2_956.pos = A0_954:GetHelperPos("vehicle_damage2", 0)
  Game:CreateExplosion(L2_956)
  if A0_954.ExplosionSound ~= nil then
    Sound.SetSoundPosition(A0_954.ExplosionSound, A0_954:GetPos())
    Sound.PlaySound(A0_954.ExplosionSound)
  end
  A0_954:BreakOnPieces()
  A0_954.bExploded = 1
end
L0_904.BlowUp = L1_905
L0_904 = HeliStatic
function L1_905(A0_957)
  local L1_958, L2_959, L3_960, L4_961, L5_962, L6_963, L7_964, L8_965
  L2_959 = A0_957
  L1_958 = A0_957.GetPos
  L1_958 = L1_958(L2_959)
  L3_960 = A0_957
  L2_959 = A0_957.GetAngles
  L2_959 = L2_959(L3_960)
  L3_960 = A0_957.DrawObject
  L3_960(L4_961, L5_962, L6_963)
  L3_960 = System
  L3_960 = L3_960.Log
  L3_960(L4_961)
  L3_960 = {}
  L3_960.x = 0
  L3_960.y = 0
  L3_960.z = 1
  for L7_964, L8_965 in L4_961(L5_962) do
    System.Log(" Piece #" .. L7_964)
    L8_965:DrawObject(0, 1)
    L8_965:EnablePhysics(1)
    L8_965:SetPos(L1_958)
    L8_965:SetAngles(L2_959)
    L3_960.x = 2 - random(0, 4)
    L3_960.y = 2 - random(0, 4)
    L3_960.z = 2
    L8_965:Activate(L8_965)
  end
  if L4_961 then
    L4_961(L5_962)
  end
  L4_961(L5_962, L6_963)
end
L0_904.BreakOnPieces = L1_905
