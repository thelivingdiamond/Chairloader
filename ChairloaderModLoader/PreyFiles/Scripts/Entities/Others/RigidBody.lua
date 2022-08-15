local L0_7106, L1_7107, L2_7108, L3_7109
L0_7106 = {}
L0_7106.type = "RigidBody"
L0_7106.MapVisMask = 0
L1_7107 = {}
L1_7107.soclasses_SmartObjectClass = ""
L1_7107.bAutoGenAIHidePts = 0
L1_7107.objModel = "Objects/box.cgf"
L1_7107.Density = 5000
L1_7107.Mass = 1
L1_7107.bResting = 1
L1_7107.bVisible = 1
L1_7107.bRigidBodyActive = 1
L1_7107.bActivateOnRocketDamage = 0
L2_7108 = {}
L2_7108.X = 0
L2_7108.Y = 0
L2_7108.Z = 0
L1_7107.Impulse = L2_7108
L1_7107.max_time_step = 0.01
L1_7107.sleep_speed = 0.04
L1_7107.damping = 0
L1_7107.water_damping = 1.5
L1_7107.water_resistance = 0
L0_7106.Properties = L1_7107
L1_7107 = {}
L1_7107.x = 0
L1_7107.y = 0
L1_7107.z = 0
L0_7106.temp_vec = L1_7107
L1_7107 = {}
L1_7107.mass = 0
L1_7107.density = 0
L0_7106.PhysParams = L1_7107
L0_7106.updateTime = 500
L0_7106.gravityUpdate = 0
L1_7107 = {}
L1_7107.Icon = "physicsobject.bmp"
L1_7107.IconOnTop = 1
L0_7106.Editor = L1_7107
RigidBody = L0_7106
L0_7106 = RigidBody
function L1_7107(A0_7110)
  A0_7110.ModelName = ""
  A0_7110.Mass = 0
  A0_7110:OnReset()
end
L0_7106.OnInit = L1_7107
L0_7106 = RigidBody
function L1_7107(A0_7111)
  local L1_7112, L2_7113
  L1_7112 = A0_7111.ModelName
  L2_7113 = A0_7111.Properties
  L2_7113 = L2_7113.objModel
  if L1_7112 == L2_7113 then
    L1_7112 = A0_7111.Mass
    L2_7113 = A0_7111.Properties
    L2_7113 = L2_7113.Mass
  elseif L1_7112 ~= L2_7113 then
    L1_7112 = A0_7111.Properties
    L1_7112 = L1_7112.Mass
    A0_7111.Mass = L1_7112
    L1_7112 = A0_7111.Properties
    L1_7112 = L1_7112.objModel
    A0_7111.ModelName = L1_7112
    L2_7113 = A0_7111
    L1_7112 = A0_7111.LoadObject
    L1_7112(L2_7113, 0, A0_7111.ModelName)
  end
  L1_7112 = A0_7111.Properties
  L2_7113 = L1_7112.bVisible
  if L2_7113 == 0 then
    L2_7113 = A0_7111.DrawSlot
    L2_7113(A0_7111, 0, 0)
  else
    L2_7113 = A0_7111.DrawSlot
    L2_7113(A0_7111, 0, 1)
  end
  L2_7113 = nil
  if A0_7111.Properties.bRigidBodyActive == 1 then
    L2_7113 = PE_RIGID
    A0_7111.PhysParams.density = L1_7112.Density
    A0_7111.PhysParams.mass = L1_7112.Mass
  else
    L2_7113 = PE_STATIC
  end
  A0_7111:Physicalize(0, L2_7113, A0_7111.PhysParams)
  A0_7111:SetPhysicParams(PHYSICPARAM_SIMULATION, A0_7111.Properties)
  A0_7111:SetPhysicParams(PHYSICPARAM_BUOYANCY, A0_7111.Properties)
  if A0_7111.Properties.bResting == 0 then
    A0_7111:AwakePhysics(1)
  else
    A0_7111:AwakePhysics(0)
  end
  if A0_7111.Properties.bAutoGenAIHidePts == 1 then
    A0_7111:SetFlags(ENTITY_FLAG_AI_HIDEABLE, 0)
  else
    A0_7111:SetFlags(ENTITY_FLAG_AI_HIDEABLE, 2)
  end
end
L0_7106.OnReset = L1_7107
L0_7106 = RigidBody
function L1_7107(A0_7114)
  A0_7114:OnReset()
end
L0_7106.OnPropertyChange = L1_7107
L0_7106 = RigidBody
function L1_7107(A0_7115, A1_7116)
  A0_7115:Event_OnTouch(A1_7116)
end
L0_7106.OnContact = L1_7107
L0_7106 = RigidBody
function L1_7107(A0_7117, A1_7118)
  if A1_7118.ipart then
    A0_7117:AddImpulse(A1_7118.ipart, A1_7118.pos, A1_7118.dir, A1_7118.impact_force_mul)
  end
  if A0_7117.Properties.bActivateOnRocketDamage and A1_7118.explosion then
    A0_7117:AwakePhysics(1)
  end
end
L0_7106.OnDamage = L1_7107
L0_7106 = RigidBody
function L1_7107(A0_7119)
  local L1_7120
end
L0_7106.OnShutDown = L1_7107
L0_7106 = RigidBody
function L1_7107(A0_7121)
  local L1_7122
end
L0_7106.OnTimer = L1_7107
L0_7106 = RigidBody
function L1_7107(A0_7123)
  A0_7123.gravityUpdate = A0_7123.gravityUpdate + _frametime
  if A0_7123.gravityUpdate < 0.5 then
    return
  end
  A0_7123.gravityUpdate = 0
  EntityUpdateGravity(A0_7123)
end
L0_7106.OnUpdate = L1_7107
L0_7106 = RigidBody
function L1_7107(A0_7124, A1_7125)
  A0_7124.temp_vec.x = A0_7124.Properties.Impulse.X
  A0_7124.temp_vec.y = A0_7124.Properties.Impulse.Y
  A0_7124.temp_vec.z = A0_7124.Properties.Impulse.Z
  A0_7124:AddImpulse(0, nil, A0_7124.temp_vec, 1)
end
L0_7106.Event_AddImpulse = L1_7107
L0_7106 = RigidBody
function L1_7107(A0_7126, A1_7127)
  A0_7126:CreateRigidBody(A0_7126.Properties.Density, A0_7126.Properties.Mass, 0)
  A0_7126:Activate(1)
  A0_7126:AwakePhysics(1)
end
L0_7106.Event_Activate = L1_7107
L0_7106 = RigidBody
function L1_7107(A0_7128, A1_7129)
  A0_7128:DrawSlot(0, 1)
end
L0_7106.Event_Show = L1_7107
L0_7106 = RigidBody
function L1_7107(A0_7130, A1_7131)
  A0_7130:DrawSlot(0, 0)
end
L0_7106.Event_Hide = L1_7107
L0_7106 = RigidBody
function L1_7107(A0_7132, A1_7133)
  BroadcastEvent(A0_7132, "OnTouch")
end
L0_7106.Event_OnTouch = L1_7107
L0_7106 = RigidBody
L1_7107 = {}
L2_7108 = {}
L3_7109 = {
  RigidBody.Event_Activate,
  "bool"
}
L2_7108.Activate = L3_7109
L3_7109 = {
  RigidBody.Event_AddImpulse,
  "bool"
}
L2_7108.AddImpulse = L3_7109
L3_7109 = {
  RigidBody.Event_Hide,
  "bool"
}
L2_7108.Hide = L3_7109
L3_7109 = {
  RigidBody.Event_Show,
  "bool"
}
L2_7108.Show = L3_7109
L3_7109 = {
  RigidBody.Event_OnTouch,
  "bool"
}
L2_7108.OnTouch = L3_7109
L1_7107.Inputs = L2_7108
L2_7108 = {}
L2_7108.Activate = "bool"
L2_7108.AddImpulse = "bool"
L2_7108.Hide = "bool"
L2_7108.Show = "bool"
L2_7108.OnTouch = "bool"
L1_7107.Outputs = L2_7108
L0_7106.FlowEvents = L1_7107
