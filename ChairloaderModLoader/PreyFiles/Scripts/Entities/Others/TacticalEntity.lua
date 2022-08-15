local L0_7308, L1_7309, L2_7310, L3_7311
L0_7308 = {}
L1_7309 = {}
L1_7309.Icon = "Comment.bmp"
L0_7308.Editor = L1_7309
L1_7309 = {}
L1_7309.fileModel = ""
L1_7309.ModelSubObject = ""
L1_7309.bEnabled = 1
L1_7309.bPhysicalize = 0
L1_7309.bAutoTarget = 0
L2_7310 = {}
L2_7310.bRigidBody = 1
L2_7310.bRigidBodyActive = 1
L2_7310.bResting = 1
L2_7310.Density = -1
L2_7310.Mass = 300
L3_7311 = {}
L3_7311.water_density = 1000
L3_7311.water_damping = 0
L3_7311.water_resistance = 1000
L2_7310.Buoyancy = L3_7311
L1_7309.Physics = L2_7310
L2_7310 = {}
L2_7310.LookupName = ""
L1_7309.TacticalInfo = L2_7310
L0_7308.Properties = L1_7309
L0_7308.registeredForAutoTarget = 0
TacticalEntity = L0_7308
L0_7308 = TacticalEntity
function L1_7309(A0_7312)
  A0_7312:OnReset()
  Game.AddTacticalEntity(A0_7312.id, eTacticalEntity_Story)
end
L0_7308.OnInit = L1_7309
L0_7308 = TacticalEntity
function L1_7309(A0_7313)
  A0_7313:OnReset()
end
L0_7308.OnPropertyChange = L1_7309
L0_7308 = TacticalEntity
function L1_7309(A0_7314)
  local L1_7315, L2_7316, L3_7317, L4_7318
  L1_7315 = A0_7314.Properties
  L2_7316 = L1_7315.bAutoTarget
  if L2_7316 ~= 0 then
    L2_7316 = A0_7314.registeredForAutoTarget
    if L2_7316 == 0 then
      L2_7316 = 0.35
      L3_7317 = 0.6
      L4_7318 = 1.25
      Game.RegisterWithAutoAimManager(A0_7314.id, L2_7316, L3_7317, L4_7318)
      A0_7314.registeredForAutoTarget = 1
    end
  end
  L2_7316 = L1_7315.bAutoTarget
  if L2_7316 == 0 then
    L2_7316 = A0_7314.registeredForAutoTarget
    if L2_7316 ~= 0 then
      L2_7316 = Game
      L2_7316 = L2_7316.UnregisterFromAutoAimManager
      L3_7317 = A0_7314.id
      L2_7316(L3_7317)
      A0_7314.registeredForAutoTarget = 0
    end
  end
end
L0_7308.EnableAutoTarget = L1_7309
L0_7308 = TacticalEntity
function L1_7309(A0_7319)
  if A0_7319.registeredForAutoTarget ~= 0 then
    Game.UnregisterFromAutoAimManager(A0_7319.id)
    A0_7319.registeredForAutoTarget = 0
  end
end
L0_7308.DisableAutoTarget = L1_7309
L0_7308 = TacticalEntity
function L1_7309(A0_7320)
  local L1_7321
  L1_7321 = A0_7320.Properties
  if not EmptyString(L1_7321.fileModel) then
    A0_7320:LoadSubObject(0, L1_7321.fileModel, L1_7321.ModelSubObject)
    if L1_7321.bPhysicalize == 1 then
      A0_7320:PhysicalizeThis(0)
    end
  end
  A0_7320:EnableAutoTarget()
end
L0_7308.OnReset = L1_7309
L0_7308 = TacticalEntity
function L1_7309(A0_7322, A1_7323)
  local L2_7324
  L2_7324 = A0_7322.Properties
  L2_7324 = L2_7324.Physics
  EntityCommon.PhysicalizeRigid(A0_7322, A1_7323, L2_7324, 1)
  if L2_7324.Buoyancy then
    A0_7322:SetPhysicParams(PHYSICPARAM_BUOYANCY, L2_7324.Buoyancy)
  end
end
L0_7308.PhysicalizeThis = L1_7309
L0_7308 = TacticalEntity
function L1_7309(A0_7325)
  A0_7325:DisableAutoTarget()
  Game.RemoveTacticalEntity(A0_7325.id, eTacticalEntity_Story)
end
L0_7308.OnDestroy = L1_7309
L0_7308 = TacticalEntity
function L1_7309(A0_7326)
  A0_7326.Properties.bEnabled = 1
  A0_7326:EnableAutoTarget()
  Game.AddTacticalEntity(A0_7326.id, eTacticalEntity_Story)
end
L0_7308.Event_Enable = L1_7309
L0_7308 = TacticalEntity
function L1_7309(A0_7327)
  A0_7327.Properties.bEnabled = 0
  A0_7327:DisableAutoTarget()
  Game.RemoveTacticalEntity(A0_7327.id, eTacticalEntity_Story)
end
L0_7308.Event_Disable = L1_7309
L0_7308 = TacticalEntity
function L1_7309(A0_7328)
  A0_7328:ActivateOutput("Scanned", true)
end
L0_7308.HasBeenScanned = L1_7309
L0_7308 = TacticalEntity
function L1_7309(A0_7329, A1_7330)
  A1_7330.registeredForAutoTarget = A0_7329.registeredForAutoTarget
end
L0_7308.OnSave = L1_7309
L0_7308 = TacticalEntity
function L1_7309(A0_7331, A1_7332)
  if A1_7332.registeredForAutoTarget == 1 then
    A0_7331:EnableAutoTarget()
  else
    A0_7331:DisableAutoTarget()
  end
end
L0_7308.OnLoad = L1_7309
L0_7308 = TacticalEntity
L1_7309 = {}
L2_7310 = {}
L3_7311 = {
  TacticalEntity.Event_Enable,
  "bool"
}
L2_7310.Enable = L3_7311
L3_7311 = {
  TacticalEntity.Event_Disable,
  "bool"
}
L2_7310.Disable = L3_7311
L1_7309.Inputs = L2_7310
L2_7310 = {}
L2_7310.Scanned = "bool"
L1_7309.Outputs = L2_7310
L0_7308.FlowEvents = L1_7309
