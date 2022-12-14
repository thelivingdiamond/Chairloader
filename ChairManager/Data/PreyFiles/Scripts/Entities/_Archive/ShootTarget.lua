local L0_1269, L1_1270, L2_1271, L3_1272
L0_1269 = {}
L1_1270 = {}
L1_1270.objectModel = "Objects/Natural/Bushes/cliff_bush_a1.cgf"
L1_1270.bPhysicalize = 1
L1_1270.sName = "shootTarget"
L1_1270.fDensity = -1
L1_1270.fMass = -1
L0_1269.Properties = L1_1270
L0_1269.nShootCount = 0
L0_1269.nContactCount = 0
L0_1269.nLog = 0
L0_1269.fDamage = 0
L0_1269.fCollisionDamage = 0
L0_1269.nDamageQueueSize = 100
ShootTarget = L0_1269
L0_1269 = ShootTarget
function L1_1270(A0_1273, A1_1274)
  A0_1273:StartAnimation(0, A0_1273.Properties.Animation)
end
L0_1269.Event_StartAnimation = L1_1270
L0_1269 = ShootTarget
function L1_1270(A0_1275, A1_1276)
  A0_1275:ResetAnimation(0, -1)
end
L0_1269.Event_StopAnimtion = L1_1270
L0_1269 = ShootTarget
function L1_1270(A0_1277)
  if A0_1277.Properties.objectModel ~= "" then
    A0_1277:LoadObject(A0_1277.Properties.objectModel, 0, 1)
    A0_1277:DrawObject(0, 1)
  end
  if A0_1277.Properties.bPhysicalize then
    A0_1277:CreateStaticEntity(A0_1277.Properties.fMass, -1)
  end
  A0_1277.nShootCount = 0
  A0_1277.nContactCount = 0
  A0_1277.fDamage = 0
  A0_1277.fCollisionDamage = 0
end
L0_1269.OnReset = L1_1270
L0_1269 = ShootTarget
function L1_1270(A0_1278, A1_1279)
  local L2_1280, L3_1281, L4_1282, L5_1283, L6_1284, L7_1285
  L2_1280 = A0_1278.nContactCount
  L2_1280 = L2_1280 + 1
  A0_1278.nContactCount = L2_1280
  L2_1280 = A1_1279.CollisionDmg
  if L2_1280 then
    L3_1281 = A0_1278.fCollisionDamage
    L3_1281 = L3_1281 + L2_1280
    A0_1278.fCollisionDamage = L3_1281
  end
  L3_1281 = format
  L3_1281 = L3_1281(L4_1282, L5_1283)
  if L4_1282 then
    L7_1285 = A0_1278.Properties
    L7_1285 = L7_1285.sName
    L4_1282(L5_1283, L6_1284)
  end
  if L4_1282 == 1 then
    L4_1282(L5_1283)
    for L7_1285, _FORV_8_ in L4_1282(L5_1283) do
      System.Log(" " .. L7_1285)
    end
    A0_1278.nLog = 0
  end
end
L0_1269.OnContact = L1_1270
L0_1269 = ShootTarget
function L1_1270(A0_1286, A1_1287)
  local L2_1288, L3_1289, L4_1290, L5_1291, L6_1292, L7_1293
  L2_1288 = A0_1286.nShootCount
  L2_1288 = L2_1288 + 1
  A0_1286.nShootCount = L2_1288
  L2_1288 = A0_1286.fDamage
  L3_1289 = A1_1287.damage
  L2_1288 = L2_1288 + L3_1289
  A0_1286.fDamage = L2_1288
  L2_1288 = format
  L3_1289 = "%.2f"
  L2_1288 = L2_1288(L3_1289, L4_1290)
  L3_1289 = format
  L3_1289 = L3_1289(L4_1290, L5_1291)
  if L4_1290 then
    L7_1293 = A0_1286.nShootCount
    L4_1290(L5_1291, L6_1292)
  end
  if L4_1290 == 1 then
    L4_1290(L5_1291)
    for L7_1293, _FORV_8_ in L4_1290(L5_1291) do
      System.Log(" " .. L7_1293 .. " = ")
    end
    A0_1286.nLog = 0
  end
end
L0_1269.OnDamage = L1_1270
L0_1269 = ShootTarget
function L1_1270(A0_1294)
  A0_1294:OnReset()
end
L0_1269.OnPropertyChange = L1_1270
L0_1269 = ShootTarget
function L1_1270(A0_1295)
  A0_1295:OnReset()
end
L0_1269.OnInit = L1_1270
L0_1269 = ShootTarget
function L1_1270(A0_1296)
  local L1_1297
end
L0_1269.OnShutDown = L1_1270
L0_1269 = ShootTarget
function L1_1270(A0_1298, A1_1299)
end
L0_1269.OnSave = L1_1270
L0_1269 = ShootTarget
function L1_1270(A0_1300, A1_1301)
end
L0_1269.OnLoad = L1_1270
L0_1269 = ShootTarget
L1_1270 = {}
L2_1271 = {}
L3_1272 = {
  ShootTarget.Event_StartAnimation,
  "bool"
}
L2_1271.StartAnimation = L3_1272
L3_1272 = {
  ShootTarget.Event_StopAnimation,
  "bool"
}
L2_1271.StopAnimation = L3_1272
L1_1270.Inputs = L2_1271
L2_1271 = {}
L2_1271.StartAnimation = "bool"
L2_1271.StopAnimation = "bool"
L1_1270.Outputs = L2_1271
L0_1269.FlowEvents = L1_1270
