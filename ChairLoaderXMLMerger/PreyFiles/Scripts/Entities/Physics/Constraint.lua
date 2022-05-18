local L0_7543, L1_7544, L2_7545
L0_7543 = {}
L1_7544 = {}
L1_7544.radius = 0.03
L1_7544.damping = 0
L1_7544.bNoSelfCollisions = 1
L1_7544.bUseEntityFrame = 1
L1_7544.max_pull_force = 0
L1_7544.max_bend_torque = 0
L1_7544.bConstrainToLine = 0
L1_7544.bConstrainToPlane = 0
L1_7544.bConstrainFully = 1
L1_7544.bNoRotation = 0
L2_7545 = {}
L2_7545.x_min = 0
L2_7545.x_max = 0
L2_7545.yz_min = 0
L2_7545.yz_max = 0
L1_7544.Limits = L2_7545
L0_7543.Properties = L1_7544
L0_7543.numUpdates = 0
L1_7544 = {}
L1_7544.Icon = "Magnet.bmp"
L1_7544.ShowBounds = 1
L0_7543.Editor = L1_7544
Constraint = L0_7543
L0_7543 = Constraint
function L1_7544(A0_7546)
  A0_7546.idEnt = nil
  A0_7546.idConstr = nil
  A0_7546.broken = nil
  A0_7546.numUpdates = 0
  A0_7546:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
end
L0_7543.OnReset = L1_7544
L0_7543 = Constraint
function L1_7544(A0_7547)
  local L1_7548
  L1_7548 = {}
  L1_7548.pivot = {}
  L1_7548.frame0 = {}
  L1_7548.frame1 = {}
  if A0_7547.idEnt then
  elseif not A0_7547.broken then
    if Physics.SamplePhysEnvironment(A0_7547:GetPos(), A0_7547.Properties.radius)[1] and Physics.SamplePhysEnvironment(A0_7547:GetPos(), A0_7547.Properties.radius)[6] then
      CopyVector(L1_7548.pivot, A0_7547:GetPos())
      if A0_7547.Properties.bUseEntityFrame == 1 then
        CopyVector(L1_7548.frame1, Physics.SamplePhysEnvironment(A0_7547:GetPos(), A0_7547.Properties.radius)[1]:GetAngles())
      else
        CopyVector(L1_7548.frame1, A0_7547:GetAngles())
      end
      CopyVector(L1_7548.frame0, L1_7548.frame1)
      L1_7548.entity_part_id_1 = Physics.SamplePhysEnvironment(A0_7547:GetPos(), A0_7547.Properties.radius)[2]
      L1_7548.phys_entity_id = Physics.SamplePhysEnvironment(A0_7547:GetPos(), A0_7547.Properties.radius)[6]
      L1_7548.entity_part_id_2 = Physics.SamplePhysEnvironment(A0_7547:GetPos(), A0_7547.Properties.radius)[5]
      L1_7548.xmin = A0_7547.Properties.Limits.x_min
      L1_7548.xmax = A0_7547.Properties.Limits.x_max
      L1_7548.yzmin = A0_7547.Properties.Limits.yz_min
      L1_7548.yzmax = A0_7547.Properties.Limits.yz_max
      L1_7548.ignore_buddy = A0_7547.Properties.bNoSelfCollisions
      L1_7548.damping = A0_7547.Properties.damping
      L1_7548.sensor_size = A0_7547.Properties.radius
      L1_7548.max_pull_force = A0_7547.Properties.max_pull_force
      L1_7548.max_bend_torque = A0_7547.Properties.max_bend_torque
      L1_7548.line = A0_7547.Properties.bConstrainToLine
      L1_7548.plane = A0_7547.Properties.bConstrainToPlane
      L1_7548.no_rotation = A0_7547.Properties.bNoRotation
      L1_7548.full = A0_7547.Properties.bConstrainFully
      A0_7547.idConstr = Physics.SamplePhysEnvironment(A0_7547:GetPos(), A0_7547.Properties.radius)[1]:SetPhysicParams(PHYSICPARAM_CONSTRAINT, L1_7548)
      A0_7547.idEnt = Physics.SamplePhysEnvironment(A0_7547:GetPos(), A0_7547.Properties.radius)[1].id
    else
      A0_7547:SetTimer(1, 1)
    end
  end
end
L0_7543.Apply = L1_7544
L0_7543 = Constraint
function L1_7544(A0_7549)
  if A0_7549.numUpdates < 10 then
    A0_7549:Apply()
    A0_7549.numUpdates = A0_7549.numUpdates + 1
  end
end
L0_7543.OnTimer = L1_7544
L0_7543 = Constraint
function L1_7544(A0_7550)
  if not A0_7550.broken and not A0_7550.idConstr then
    A0_7550.numUpdates = 0
    A0_7550.idEnt = nil
    A0_7550.idConstr = nil
    A0_7550:Apply()
  end
end
L0_7543.OnLevelLoaded = L1_7544
L0_7543 = Constraint
function L1_7544(A0_7551)
  A0_7551:OnReset()
end
L0_7543.OnPropertyChange = L1_7544
L0_7543 = Constraint
function L1_7544(A0_7552)
  A0_7552:OnReset()
end
L0_7543.OnSpawn = L1_7544
L0_7543 = Constraint
function L1_7544(A0_7553, A1_7554)
  if A0_7553.idEnt then
    System.GetEntity(A0_7553.idEnt):SetPhysicParams(PHYSICPARAM_REMOVE_CONSTRAINT, {
      id = A0_7553.idConstr
    })
    A0_7553.idEnt = nil
    A0_7553.idConstr = nil
  end
  A0_7553.broken = true
  A0_7553:KillTimer(1)
  BroadcastEvent(A0_7553, "ConstraintBroken")
end
L0_7543.Event_ConstraintBroken = L1_7544
L0_7543 = Constraint
function L1_7544(A0_7555, A1_7556)
  local L2_7557
  L2_7557 = A0_7555.broken
  A1_7556.broken = L2_7557
  L2_7557 = A0_7555.idEnt
  A1_7556.idEnt = L2_7557
  L2_7557 = A0_7555.idConstr
  A1_7556.idConstr = L2_7557
end
L0_7543.OnSave = L1_7544
L0_7543 = Constraint
function L1_7544(A0_7558, A1_7559)
  local L2_7560
  L2_7560 = A1_7559.broken
  A0_7558.broken = L2_7560
  L2_7560 = A1_7559.idEnt
  A0_7558.idEnt = L2_7560
  L2_7560 = A1_7559.idConstr
  A0_7558.idConstr = L2_7560
end
L0_7543.OnLoad = L1_7544
L0_7543 = Constraint
function L1_7544(A0_7561)
  local L1_7562
end
L0_7543.OnDestroy = L1_7544
L0_7543 = Constraint
L1_7544 = {}
L2_7545 = {}
L2_7545.ConstraintBroken = {
  Constraint.Event_ConstraintBroken,
  "bool"
}
L1_7544.Inputs = L2_7545
L2_7545 = {}
L2_7545.ConstraintBroken = "bool"
L1_7544.Outputs = L2_7545
L0_7543.FlowEvents = L1_7544
