local L0_1383, L1_1384
L0_1383 = {}
L0_1383.name = "SwivilChair"
L1_1384 = {}
L1_1384.objModel = "Objects/Indoor/furniture/chairs/swivel.cgf"
L0_1383.Properties = L1_1384
SwivilChair = L0_1383
L0_1383 = SwivilChair
function L1_1384(A0_1385)
  A0_1385:Activate(0)
  if A0_1385.ModelName ~= A0_1385.Properties.objModel then
    A0_1385.ModelName = A0_1385.Properties.objModel
    A0_1385:LoadObject(A0_1385.ModelName, 0, 1)
  end
  A0_1385:CreateStaticEntity(200, 0)
  A0_1385:EnablePhysics(1)
  A0_1385:DrawObject(0, 1)
  AI:RegisterWithAI(A0_1385.id, AIAnchor.AIOBJECT_SWIVIL_CHAIR)
end
L0_1383.OnInit = L1_1384
L0_1383 = SwivilChair
function L1_1384(A0_1386, A1_1387, A2_1388)
end
L0_1383.OnEvent = L1_1384
L0_1383 = SwivilChair
function L1_1384(A0_1389)
  local L1_1390
end
L0_1383.OnShutDown = L1_1384
