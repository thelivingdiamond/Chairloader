local L0_442, L1_443
L0_442 = {}
L0_442.Name = "AICrate"
L1_443 = {}
L1_443.objModel = "Objects/Indoor/boxes/crates/crateCarry.cgf"
L1_443.Density = 20
L1_443.Mass = 1
L0_442.Properties = L1_443
L1_443 = {}
L1_443.max_time_step = 0.01
L1_443.sleep_speed = 0.04
L1_443.damping = 0
L1_443.water_damping = 0
L1_443.water_resistance = 1000
L1_443.water_density = 1000
L1_443.mass = 1
L1_443.density = 20
L0_442.PhysParams = L1_443
AICrate = L0_442
L0_442 = AICrate
function L1_443(A0_444)
  if A0_444.ModelName ~= A0_444.Properties.objModel then
    A0_444.ModelName = A0_444.Properties.objModel
    A0_444:LoadObject(A0_444.ModelName, 0, 1)
  end
  A0_444:CreateRigidBody(A0_444.Properties.Density, A0_444.Properties.Mass, 0)
  A0_444:EnablePhysics(1)
  A0_444.PhysParams.mass = A0_444.Properties.Mass
  A0_444.PhysParams.density = A0_444.Properties.Density
  A0_444:SetPhysicParams(PHYSICPARAM_SIMULATION, A0_444.PhysParams)
  A0_444:SetPhysicParams(PHYSICPARAM_BUOYANCY, A0_444.PhysParams)
  A0_444:AwakePhysics(0)
  A0_444:DrawObject(0, 1)
end
L0_442.OnPropertyChange = L1_443
L0_442 = AICrate
function L1_443(A0_445)
  A0_445:Activate(0)
  A0_445:SetUpdateType(eUT_Physics)
  A0_445:OnPropertyChange()
  AI:RegisterWithAI(A0_445.id, AIAnchor.AIOBJECT_CARRY_CRATE)
end
L0_442.OnInit = L1_443
L0_442 = AICrate
function L1_443(A0_446, A1_447, A2_448)
end
L0_442.OnEvent = L1_443
L0_442 = AICrate
function L1_443(A0_449)
  local L1_450
end
L0_442.OnShutDown = L1_443
