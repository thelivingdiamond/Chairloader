Script.ReloadScript("scripts/Utils/EntityUtils.lua")
BreakableObject = {
  Properties = {
    objModel = "engine/engineassets/objects/default.cgf",
    fDensity = 5000,
    fMass = -1,
    bResting = 0,
    bRigidBody = 0,
    bPickable = 0,
    bUsable = 0,
    nBreakableType = 0,
    PhysicsBuoyancy = {
      water_density = 1,
      water_damping = 1.5,
      water_resistance = 0
    },
    PhysicsSimulation = {
      max_time_step = 0.01,
      sleep_speed = 0.04,
      damping = 0
    },
    PhysicsBreakable = {
      max_push_force = 0.01,
      max_pull_force = 0.01,
      max_shift_force = 0.01,
      max_twist_torque = 0.01,
      max_bend_torque = 0.01,
      crack_weaken = 0.5,
      GroundPlanes = {
        positiveX = 0,
        negativeX = 0,
        positiveY = 0,
        negativeY = 0,
        positiveZ = 0.05,
        negativeZ = 0
      }
    }
  },
  Editor = {
    Icon = "physicsobject.bmp",
    IconOnTop = 1
  }
}
function BreakableObject.OnSave(A0_7492, A1_7493)
  A1_7493.first_break = A0_7492.first_break
end
function BreakableObject.OnLoad(A0_7494, A1_7495)
  A0_7494.first_break = A1_7495.first_break
end
function BreakableObject.OnSpawn(A0_7496)
  A0_7496:OnReset()
end
function BreakableObject.OnReset(A0_7497)
  local L1_7498, L2_7499, L3_7500, L4_7501
  L2_7499 = A0_7497
  L1_7498 = A0_7497.ResetOnUsed
  L1_7498(L2_7499)
  L2_7499 = A0_7497
  L1_7498 = A0_7497.LoadObject
  L3_7500 = 0
  L4_7501 = A0_7497.Properties
  L4_7501 = L4_7501.objModel
  L1_7498(L2_7499, L3_7500, L4_7501)
  L2_7499 = A0_7497
  L1_7498 = A0_7497.DrawSlot
  L3_7500 = 0
  L4_7501 = 1
  L1_7498(L2_7499, L3_7500, L4_7501)
  L1_7498 = nil
  L2_7499 = tonumber
  L3_7500 = A0_7497.Properties
  L3_7500 = L3_7500.bRigidBody
  L2_7499 = L2_7499(L3_7500)
  if L2_7499 ~= 0 then
    L1_7498 = PE_RIGID
  else
    L1_7498 = PE_STATIC
  end
  L2_7499 = A0_7497.Properties
  L4_7501 = A0_7497
  L3_7500 = A0_7497.Physicalize
  L3_7500(L4_7501, 0, L1_7498, {
    mass = L2_7499.fMass,
    density = L2_7499.fDensity
  })
  L4_7501 = A0_7497
  L3_7500 = A0_7497.LoadObjectLattice
  L3_7500(L4_7501, 0)
  L4_7501 = A0_7497
  L3_7500 = A0_7497.SetPhysicParams
  L3_7500(L4_7501, PHYSICPARAM_SUPPORT_LATTICE, L2_7499.PhysicsBreakable)
  L4_7501 = A0_7497
  L3_7500 = A0_7497.SetPhysicParams
  L3_7500(L4_7501, PHYSICPARAM_SIMULATION, L2_7499.PhysicsSimulation)
  L4_7501 = A0_7497
  L3_7500 = A0_7497.SetPhysicParams
  L3_7500(L4_7501, PHYSICPARAM_BUOYANCY, L2_7499.PhysicsBuoyancy)
  L4_7501 = A0_7497
  L3_7500 = A0_7497.SetPhysicParams
  L3_7500(L4_7501, PHYSICPARAM_PART_FLAGS, {
    partId = 0,
    mat_breakable = L2_7499.nBreakableType
  })
  L3_7500 = L2_7499.PhysicsBreakable
  L3_7500 = L3_7500.GroundPlanes
  L4_7501 = 0
  if L3_7500.positiveX ~= 0 then
    A0_7497:SetGroundPlane(L4_7501, 1, {
      x = 1,
      y = 0,
      z = 0
    }, L3_7500.positiveX)
    L4_7501 = L4_7501 + 1
  end
  if L3_7500.negativeX ~= 0 then
    A0_7497:SetGroundPlane(L4_7501, 1, {
      x = -1,
      y = 0,
      z = 0
    }, L3_7500.negativeX)
    L4_7501 = L4_7501 + 1
  end
  if L3_7500.positiveY ~= 0 then
    A0_7497:SetGroundPlane(L4_7501, 2, {
      x = 0,
      y = 1,
      z = 0
    }, L3_7500.positiveY)
    L4_7501 = L4_7501 + 1
  end
  if L3_7500.negativeY ~= 0 then
    A0_7497:SetGroundPlane(L4_7501, 2, {
      x = 0,
      y = -1,
      z = 0
    }, L3_7500.negativeY)
    L4_7501 = L4_7501 + 1
  end
  if L3_7500.positiveZ ~= 0 then
    A0_7497:SetGroundPlane(L4_7501, 3, {
      x = 0,
      y = 0,
      z = 1
    }, L3_7500.positiveZ)
    L4_7501 = L4_7501 + 1
  end
  if L3_7500.negativeZ ~= 0 then
    A0_7497:SetGroundPlane(L4_7501, 3, {
      x = 0,
      y = 0,
      z = -1
    }, L3_7500.negativeZ)
    L4_7501 = L4_7501 + 1
  end
  if tonumber(A0_7497.Properties.bResting) ~= 0 then
    A0_7497:AwakePhysics(0)
  else
    A0_7497:AwakePhysics(1)
  end
  A0_7497.radius = 0.15 + math.max(A0_7497:GetWorldBBox(g_Vectors.temp_v1, g_Vectors.temp_v2).x - A0_7497:GetWorldBBox(g_Vectors.temp_v1, g_Vectors.temp_v2).x, math.max(A0_7497:GetWorldBBox(g_Vectors.temp_v1, g_Vectors.temp_v2).y - A0_7497:GetWorldBBox(g_Vectors.temp_v1, g_Vectors.temp_v2).y, A0_7497:GetWorldBBox(g_Vectors.temp_v1, g_Vectors.temp_v2).z - A0_7497:GetWorldBBox(g_Vectors.temp_v1, g_Vectors.temp_v2).z))
  A0_7497.center = {
    x = (A0_7497:GetWorldBBox(g_Vectors.temp_v1, g_Vectors.temp_v2).x + A0_7497:GetWorldBBox(g_Vectors.temp_v1, g_Vectors.temp_v2).x) * 0.5,
    y = (A0_7497:GetWorldBBox(g_Vectors.temp_v1, g_Vectors.temp_v2).y + A0_7497:GetWorldBBox(g_Vectors.temp_v1, g_Vectors.temp_v2).y) * 0.5,
    z = (A0_7497:GetWorldBBox(g_Vectors.temp_v1, g_Vectors.temp_v2).z + A0_7497:GetWorldBBox(g_Vectors.temp_v1, g_Vectors.temp_v2).z) * 0.5
  }
  A0_7497.first_break = true
end
function BreakableObject.SetGroundPlane(A0_7502, A1_7503, A2_7504, A3_7505, A4_7506)
  A0_7502:SetPhysicParams(PHYSICPARAM_GROUND_PLANE, {
    origin = {
      x = ({
        x = (A0_7502:GetLocalBBox().x + A0_7502:GetLocalBBox().x) * 0.5,
        y = (A0_7502:GetLocalBBox().y + A0_7502:GetLocalBBox().y) * 0.5,
        z = (A0_7502:GetLocalBBox().z + A0_7502:GetLocalBBox().z) * 0.5
      }).x + A3_7505.x * ({
        x = A0_7502:GetLocalBBox().x - A0_7502:GetLocalBBox().x,
        y = A0_7502:GetLocalBBox().y - A0_7502:GetLocalBBox().y,
        z = A0_7502:GetLocalBBox().z - A0_7502:GetLocalBBox().z
      }).x * (A4_7506 - 0.5),
      y = ({
        x = (A0_7502:GetLocalBBox().x + A0_7502:GetLocalBBox().x) * 0.5,
        y = (A0_7502:GetLocalBBox().y + A0_7502:GetLocalBBox().y) * 0.5,
        z = (A0_7502:GetLocalBBox().z + A0_7502:GetLocalBBox().z) * 0.5
      }).y + A3_7505.y * ({
        x = A0_7502:GetLocalBBox().x - A0_7502:GetLocalBBox().x,
        y = A0_7502:GetLocalBBox().y - A0_7502:GetLocalBBox().y,
        z = A0_7502:GetLocalBBox().z - A0_7502:GetLocalBBox().z
      }).y * (A4_7506 - 0.5),
      z = ({
        x = (A0_7502:GetLocalBBox().x + A0_7502:GetLocalBBox().x) * 0.5,
        y = (A0_7502:GetLocalBBox().y + A0_7502:GetLocalBBox().y) * 0.5,
        z = (A0_7502:GetLocalBBox().z + A0_7502:GetLocalBBox().z) * 0.5
      }).z + A3_7505.z * ({
        x = A0_7502:GetLocalBBox().x - A0_7502:GetLocalBBox().x,
        y = A0_7502:GetLocalBBox().y - A0_7502:GetLocalBBox().y,
        z = A0_7502:GetLocalBBox().z - A0_7502:GetLocalBBox().z
      }).z * (A4_7506 - 0.5)
    },
    normal = A3_7505,
    plane_index = A1_7503
  })
end
function BreakableObject.OnPropertyChange(A0_7507)
  A0_7507:OnReset()
end
function BreakableObject.OnShutDown(A0_7508)
  local L1_7509
end
function BreakableObject.OnPhysicsBreak(A0_7510)
  A0_7510:Event_OnBreak()
end
function BreakableObject.OnPhysicsBreak(A0_7511)
  AI.BreakEvent(A0_7511.id, A0_7511.center, A0_7511.radis)
  A0_7511:Event_OnBreak()
  if A0_7511.first_break then
    A0_7511:Event_OnFirstBreak()
    A0_7511.first_break = false
  end
end
function BreakableObject.Event_OnBreak(A0_7512)
  AI.BreakEvent(A0_7512.id, A0_7512.center, A0_7512.radis)
  BroadcastEvent(A0_7512, "OnBreak")
end
function BreakableObject.Event_OnFirstBreak(A0_7513)
  BroadcastEvent(A0_7513, "OnFirstBreak")
end
BreakableObject.FlowEvents = {
  Inputs = {
    OnBreak = {
      BreakableObject.Event_OnBreak,
      "bool"
    },
    OnFirstBreak = {
      BreakableObject.Event_OnFirstBreak,
      "bool"
    }
  },
  Outputs = {OnBreak = "bool", OnFirstBreak = "bool"}
}
MakeUsable(BreakableObject)
MakePickable(BreakableObject)
MakeTargetableByAI(BreakableObject)
MakeKillable(BreakableObject)
