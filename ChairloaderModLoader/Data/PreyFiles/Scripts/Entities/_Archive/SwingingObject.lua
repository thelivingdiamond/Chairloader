local L0_1359, L1_1360, L2_1361, L3_1362
L0_1359 = {}
L1_1360 = {}
L1_1360.mass = 120
L1_1360.fileModel = "Objects/glm/shipwreck/stuff/chain_hook.cgf"
L1_1360.bShootable = 1
L1_1360.coll_dist = 0.025
L1_1360.material = "mat_default"
L2_1361 = {}
L2_1361.x = 0
L2_1361.y = 0
L2_1361.z = -9.81
L1_1360.gravity = L2_1361
L1_1360.damping = 0.5
L1_1360.sleep_speed = 0.01
L1_1360.max_time_step = 0.02
L1_1360.damage_players = 1
L1_1360.damage_scale = 10
L1_1360.bResting = 1
L2_1361 = {}
L2_1361.x = 1
L2_1361.y = 2
L2_1361.z = 3
L1_1360.vector_activation_impulse = L2_1361
L0_1359.Properties = L1_1360
L1_1360 = {}
L1_1360.Model = "Objects/Editor/LightSphear.cgf"
L0_1359.Editor = L1_1360
SwingingObject = L0_1359
L0_1359 = SwingingObject
function L1_1360(A0_1363)
  local L1_1364
  A0_1363.lightId = nil
  L1_1364 = A0_1363.NetPresent
  L1_1364(A0_1363, nil)
  L1_1364 = A0_1363.Activate
  L1_1364(A0_1363, 1)
  L1_1364 = {}
  L1_1364.entity_id_1 = -1
  L1_1364.entity_part_id_1 = 0
  L1_1364.surface_idx = Game:GetMaterialIDByName(A0_1363.Properties.material)
  L1_1364.shootable = A0_1363.Properties.bShootable
  A0_1363:CreateRigidBody(0, 1, 0)
  A0_1363:LoadCharacter(A0_1363.Properties.fileModel, 0)
  A0_1363:PhysicalizeCharacter(A0_1363.Properties.mass, 0, 0, 0)
  A0_1363:SetCharacterPhysicParams(0, "rope", PHYSICPARAM_ROPE, A0_1363.Properties)
  A0_1363:SetCharacterPhysicParams(0, "rope", PHYSICPARAM_ROPE, L1_1364)
  A0_1363:SetCharacterPhysicParams(0, "rope", PHYSICPARAM_SIMULATION, A0_1363.Properties)
  A0_1363:AwakePhysics(1 - A0_1363.Properties.bResting)
  A0_1363:DrawObject(0, 1)
end
L0_1359.OnReset = L1_1360
L0_1359 = SwingingObject
function L1_1360(A0_1365)
  A0_1365:OnReset()
end
L0_1359.OnPropertyChange = L1_1360
L0_1359 = SwingingObject
function L1_1360(A0_1366, A1_1367)
  if A1_1367.ipart then
    A0_1366:AddImpulse(A1_1367.ipart, A1_1367.pos, A1_1367.dir, A1_1367.impact_force_mul)
  else
    A0_1366:AddImpulse(-1, A1_1367.pos, A1_1367.dir, A1_1367.impact_force_mul)
  end
end
L0_1359.OnDamage = L1_1360
L0_1359 = SwingingObject
function L1_1360(A0_1368, A1_1369)
  A0_1368.temp_vec.x = A0_1368.Properties.vector_activation_impulse.x
  A0_1368.temp_vec.y = A0_1368.Properties.vector_activation_impulse.y
  A0_1368.temp_vec.z = A0_1368.Properties.vector_activation_impulse.z
  A0_1368:AddImpulse(0, nil, A0_1368.temp_vec, 1)
end
L0_1359.Event_AddImpulse = L1_1360
L0_1359 = SwingingObject
function L1_1360(A0_1370, A1_1371)
  A0_1370:AwakePhysics(1)
end
L0_1359.Event_Activate = L1_1360
L0_1359 = SwingingObject
function L1_1360(A0_1372)
  A0_1372:OnReset()
end
L0_1359.OnInit = L1_1360
L0_1359 = SwingingObject
function L1_1360(A0_1373, A1_1374)
end
L0_1359.OnWrite = L1_1360
L0_1359 = SwingingObject
function L1_1360(A0_1375, A1_1376)
end
L0_1359.OnRead = L1_1360
L0_1359 = SwingingObject
function L1_1360(A0_1377, A1_1378)
end
L0_1359.OnSave = L1_1360
L0_1359 = SwingingObject
function L1_1360(A0_1379, A1_1380)
end
L0_1359.OnLoad = L1_1360
L0_1359 = SwingingObject
function L1_1360(A0_1381)
  local L1_1382
end
L0_1359.OnShutDown = L1_1360
L0_1359 = SwingingObject
L1_1360 = {}
L2_1361 = {}
L3_1362 = {
  SwingingObject.Event_Activate,
  "bool"
}
L2_1361.Activate = L3_1362
L3_1362 = {
  SwingingObject.Event_AddImpulse,
  "bool"
}
L2_1361.AddImpulse = L3_1362
L1_1360.Inputs = L2_1361
L2_1361 = {}
L2_1361.Activate = "bool"
L2_1361.AddImpulse = "bool"
L1_1360.Outputs = L2_1361
L0_1359.FlowEvents = L1_1360
