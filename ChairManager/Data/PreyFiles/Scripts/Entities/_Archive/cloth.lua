local L0_707, L1_708, L2_709
L0_707 = {}
L1_708 = {}
L1_708.mass = 5
L1_708.density = 200
L1_708.fileModel = "Objects/testcloth.cgf"
L2_709 = {}
L2_709.x = 0
L2_709.y = 0
L2_709.z = -9.81
L1_708.gravity = L2_709
L1_708.damping = 0
L1_708.max_time_step = 0.025
L1_708.sleep_speed = 0.1
L1_708.thickness = 0.06
L1_708.friction = 0
L1_708.max_safe_step = 0.4
L1_708.stiffness = 500
L1_708.damping_ratio = 0.9
L1_708.air_resistance = 0
L2_709 = {}
L2_709.x = 0
L2_709.y = 0
L2_709.z = 0
L1_708.wind = L2_709
L1_708.max_iters = 40
L1_708.accuracy = 0.01
L1_708.water_resistance = 600
L1_708.impulse_scale = 0.02
L1_708.explosion_scale = 0.002
L1_708.collision_impulse_scale = 1
L1_708.max_collision_impulse = 160
L1_708.bCollideWithTerrain = 0
L1_708.bCollideWithStatics = 1
L1_708.bCollideWithPhysical = 1
L1_708.bCollideWithPlayers = 1
L0_707.Properties = L1_708
L0_707.id_attach_to = -1
L0_707.id_part_attach_to = -1
L1_708 = {}
L1_708.Model = "Objects/Editor/LightSphear.cgf"
L0_707.Editor = L1_708
TestCloth = L0_707
L0_707 = TestCloth
function L1_708(A0_710)
  local L1_711
  A0_710.lightId = nil
  L1_711 = A0_710.NetPresent
  L1_711(A0_710, nil)
  L1_711 = A0_710.Activate
  L1_711(A0_710, 1)
  L1_711 = A0_710.LoadObject
  L1_711(A0_710, A0_710.Properties.fileModel, 0, 1, "cloth")
  L1_711 = A0_710.CreateSoftEntity
  L1_711(A0_710, A0_710.Properties.mass, A0_710.Properties.density, 1, A0_710.id_attach_to, A0_710.id_part_attach_to)
  L1_711 = A0_710.SetPhysicParams
  L1_711(A0_710, PHYSICPARAM_SIMULATION, A0_710.Properties)
  L1_711 = A0_710.SetPhysicParams
  L1_711(A0_710, PHYSICPARAM_BUOYANCY, A0_710.Properties)
  L1_711 = A0_710.SetPhysicParams
  L1_711(A0_710, PHYSICPARAM_SOFTBODY, A0_710.Properties)
  L1_711 = {}
  L1_711.collision_mask = 0
  if A0_710.Properties.bCollideWithTerrain == 1 then
    L1_711.collision_mask = L1_711.collision_mask + ent_terrain
  end
  if A0_710.Properties.bCollideWithStatics == 1 then
    L1_711.collision_mask = L1_711.collision_mask + ent_static
  end
  if A0_710.Properties.bCollideWithPhysical == 1 then
    L1_711.collision_mask = L1_711.collision_mask + ent_rigid + ent_sleeping_rigid
  end
  if A0_710.Properties.bCollideWithPlayers == 1 then
    L1_711.collision_mask = L1_711.collision_mask + ent_living
  end
  A0_710:SetPhysicParams(PHYSICPARAM_SOFTBODY, L1_711)
  A0_710:DrawObject(0, 1)
  A0_710:AwakePhysics(0)
end
L0_707.OnReset = L1_708
L0_707 = TestCloth
function L1_708(A0_712)
  A0_712:OnReset()
end
L0_707.OnPropertyChange = L1_708
L0_707 = TestCloth
function L1_708(A0_713, A1_714)
  if A1_714.ipart then
    A0_713:AddImpulse(A1_714.ipart, A1_714.pos, A1_714.dir, A1_714.impact_force_mul)
  else
    A0_713:AddImpulse(-1, A1_714.pos, A1_714.dir, A1_714.impact_force_mul)
  end
end
L0_707.OnDamage = L1_708
L0_707 = TestCloth
function L1_708(A0_715)
  A0_715:SetUpdateType(eUT_Visible)
  A0_715:OnReset()
end
L0_707.OnInit = L1_708
L0_707 = TestCloth
function L1_708(A0_716)
  local L1_717
end
L0_707.OnShutDown = L1_708
