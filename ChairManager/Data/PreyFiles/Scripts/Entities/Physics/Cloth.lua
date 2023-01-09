local L0_7517, L1_7518, L2_7519, L3_7520
L0_7517 = {}
L1_7518 = {}
L0_7517.Server = L1_7518
L1_7518 = {}
L0_7517.Client = L1_7518
L1_7518 = {}
L1_7518.mass = 5
L1_7518.density = 200
L1_7518.fileModel = "engine/engineassets/objects/default.cgf"
L2_7519 = {}
L2_7519.x = 0
L2_7519.y = 0
L2_7519.z = -9.8
L1_7518.gravity = L2_7519
L1_7518.damping = 0.3
L1_7518.max_time_step = 0.02
L1_7518.sleep_speed = 0.01
L1_7518.thickness = 0.06
L1_7518.friction = 0
L1_7518.hardness = 20
L1_7518.air_resistance = 1
L2_7519 = {}
L2_7519.x = 0
L2_7519.y = 0
L2_7519.z = 0
L1_7518.wind = L2_7519
L2_7519 = {}
L2_7519.x = 0
L2_7519.y = 10
L2_7519.z = 0
L1_7518.wind_event = L2_7519
L1_7518.wind_variance = 0.2
L1_7518.max_iters = 20
L1_7518.accuracy = 0.05
L1_7518.water_resistance = 600
L1_7518.impulse_scale = 0.02
L1_7518.explosion_scale = 0.003
L1_7518.collision_impulse_scale = 1
L1_7518.max_collision_impulse = 160
L1_7518.mass_decay = 0
L1_7518.attach_radius = 0
L1_7518.bCollideWithTerrain = 0
L1_7518.bCollideWithStatics = 1
L1_7518.bCollideWithPhysical = 1
L1_7518.bCollideWithPlayers = 1
L1_7518.bRigidCore = 0
L1_7518.max_safe_step = 0.2
L2_7519 = {}
L2_7519.bNetworked = 0
L1_7518.MultiplayerOptions = L2_7519
L0_7517.Properties = L1_7518
L0_7517.id_attach_to = -1
L0_7517.id_part_attach_to = -1
L1_7518 = {}
L1_7518.Icon = "physicsobject.bmp"
L0_7517.Editor = L1_7518
Cloth = L0_7517
L0_7517 = Cloth
L0_7517 = L0_7517.Server
function L1_7518(A0_7521)
  A0_7521:ReattachSoftEntityVtx(A0_7521:LookForEntityToAttachTo().entityId, A0_7521:LookForEntityToAttachTo().partId)
end
L0_7517.OnUnHidden = L1_7518
L0_7517 = Cloth
function L1_7518(A0_7522)
  local L1_7523, L2_7524, L3_7525, L4_7526
  L1_7523 = {}
  L2_7524 = A0_7522.Properties
  L2_7524 = L2_7524.density
  L1_7523.density = L2_7524
  L2_7524 = A0_7522.Properties
  L2_7524 = L2_7524.mass
  L1_7523.mass = L2_7524
  L2_7524 = A0_7522.Properties
  L2_7524 = L2_7524.bRigidCore
  L1_7523.bRigidCore = L2_7524
  L2_7524 = 0
  L4_7526 = A0_7522
  L3_7525 = A0_7522.GetLinkTarget
  L3_7525 = L3_7525(L4_7526, "AttachedTo", L2_7524)
  if L3_7525 then
    L4_7526 = L3_7525.id
    L1_7523.AttachmentIdEnt = L4_7526
    L1_7523.AttachmentPartId = -1
  else
    L4_7526 = A0_7522.LookForEntityToAttachTo
    L4_7526 = L4_7526(A0_7522)
    L1_7523.AttachmentId = L4_7526.entityId
    L1_7523.AttachmentPartId = L4_7526.partId
  end
  L4_7526 = A0_7522.Physicalize
  L4_7526(A0_7522, 0, PE_SOFT, L1_7523)
  L4_7526 = A0_7522.SetPhysicParams
  L4_7526(A0_7522, PHYSICPARAM_SIMULATION, A0_7522.Properties)
  L4_7526 = A0_7522.SetPhysicParams
  L4_7526(A0_7522, PHYSICPARAM_BUOYANCY, A0_7522.Properties)
  L4_7526 = A0_7522.SetPhysicParams
  L4_7526(A0_7522, PHYSICPARAM_SOFTBODY, A0_7522.Properties)
  L4_7526 = {}
  L4_7526.collision_mask = 0
  if A0_7522.Properties.bCollideWithTerrain == 1 then
    L4_7526.collision_mask = L4_7526.collision_mask + ent_terrain
  end
  if A0_7522.Properties.bCollideWithStatics == 1 then
    L4_7526.collision_mask = L4_7526.collision_mask + ent_static
  end
  if A0_7522.Properties.bCollideWithPhysical == 1 then
    L4_7526.collision_mask = L4_7526.collision_mask + ent_rigid + ent_sleeping_rigid
  end
  if A0_7522.Properties.bCollideWithPlayers == 1 then
    L4_7526.collision_mask = L4_7526.collision_mask + ent_living
  end
  A0_7522:SetPhysicParams(PHYSICPARAM_SOFTBODY, L4_7526)
  if 0 < A0_7522.Properties.air_resistance then
    A0_7522:AwakePhysics(1)
  else
    A0_7522:AwakePhysics(0)
  end
end
L0_7517.OnReset = L1_7518
L0_7517 = Cloth
function L1_7518(A0_7527)
  local L1_7528
  L1_7528 = {}
  L1_7528.entityId = NULL_ENTITY
  L1_7528.partId = -1
  if A0_7527.Properties.attach_radius > 0 and Physics.SamplePhysEnvironment(A0_7527:GetPos(), A0_7527.Properties.attach_radius, ent_terrain + ent_static + ent_rigid + ent_sleeping_rigid + ent_independent)[3] then
    L1_7528.entityId = Physics.SamplePhysEnvironment(A0_7527:GetPos(), A0_7527.Properties.attach_radius, ent_terrain + ent_static + ent_rigid + ent_sleeping_rigid + ent_independent)[3]
    L1_7528.partId = Physics.SamplePhysEnvironment(A0_7527:GetPos(), A0_7527.Properties.attach_radius, ent_terrain + ent_static + ent_rigid + ent_sleeping_rigid + ent_independent)[2]
  end
  return L1_7528
end
L0_7517.LookForEntityToAttachTo = L1_7518
L0_7517 = Cloth
function L1_7518(A0_7529)
  if A0_7529.Properties.MultiplayerOptions.bNetworked == 0 then
    A0_7529:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
  end
  A0_7529:LoadSubObject(0, A0_7529.Properties.fileModel, "cloth")
  A0_7529:OnReset()
end
L0_7517.OnSpawn = L1_7518
L0_7517 = Cloth
L0_7517 = L0_7517.Server
function L1_7518(A0_7530)
  A0_7530:OnReset()
end
L0_7517.OnStartGame = L1_7518
L0_7517 = Cloth
function L1_7518(A0_7531)
  A0_7531:LoadSubObject(0, A0_7531.Properties.fileModel, "cloth")
  A0_7531:OnReset()
end
L0_7517.OnPropertyChange = L1_7518
L0_7517 = Cloth
function L1_7518(A0_7532, A1_7533)
  if A1_7533.ipart then
    A0_7532:AddImpulse(A1_7533.ipart, A1_7533.pos, A1_7533.dir, A1_7533.impact_force_mul)
  else
    A0_7532:AddImpulse(-1, A1_7533.pos, A1_7533.dir, A1_7533.impact_force_mul)
  end
end
L0_7517.OnDamage = L1_7518
L0_7517 = Cloth
function L1_7518(A0_7534)
  A0_7534:OnReset()
end
L0_7517.OnInit = L1_7518
L0_7517 = Cloth
function L1_7518(A0_7535)
  local L1_7536
end
L0_7517.OnShutDown = L1_7518
L0_7517 = Cloth
function L1_7518(A0_7537, A1_7538)
  local L2_7539
  L2_7539 = {}
  L2_7539.wind = {
    x = 0,
    y = 0,
    z = 0
  }
  CopyVector(L2_7539.wind, A0_7537.Properties.wind_event)
  A0_7537:SetPhysicParams(PHYSICPARAM_SOFTBODY, L2_7539)
end
L0_7517.Event_WindOn = L1_7518
L0_7517 = Cloth
function L1_7518(A0_7540, A1_7541)
  local L2_7542
  L2_7542 = {}
  L2_7542.wind = {
    x = 0,
    y = 0,
    z = 0
  }
  CopyVector(L2_7542.wind, A0_7540.Properties.wind)
  A0_7540:SetPhysicParams(PHYSICPARAM_SOFTBODY, L2_7542)
end
L0_7517.Event_WindOff = L1_7518
L0_7517 = Cloth
L1_7518 = {}
L2_7519 = {}
L3_7520 = {
  Cloth.Event_WindOn,
  "bool"
}
L2_7519.WindOn = L3_7520
L3_7520 = {
  Cloth.Event_WindOff,
  "bool"
}
L2_7519.WindOff = L3_7520
L1_7518.Inputs = L2_7519
L2_7519 = {}
L2_7519.WindOn = "bool"
L2_7519.WindOff = "bool"
L1_7518.Outputs = L2_7519
L0_7517.FlowEvents = L1_7518
