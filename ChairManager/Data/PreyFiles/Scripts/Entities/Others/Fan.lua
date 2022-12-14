local L0_6713, L1_6714
L0_6713 = {}
L1_6714 = {}
L0_6713.Client = L1_6714
L1_6714 = {}
L0_6713.Server = L1_6714
L1_6714 = {}
L1_6714.fileModel = "engine/engineassets/objects/default.cgf"
L1_6714.ModelSubObject = ""
L1_6714.fileModelDestroyed = ""
L1_6714.DestroyedSubObject = ""
L1_6714.MaxSpeed = 0.1
L1_6714.fHealth = 100
L1_6714.bTurnedOn = 1
L1_6714.Physics = {
  bRigidBody = 0,
  bRigidBodyActive = 0,
  bRigidBodyAfterDeath = 1,
  bResting = 1,
  Density = -1,
  Mass = 150
}
L1_6714.Breakage = {
  fLifeTime = 10,
  fExplodeImpulse = 0,
  bSurfaceEffects = 1
}
L1_6714.Destruction = {
  bExplode = 1,
  ParticleEffect = "explosions.barrel.wood_explode",
  EffectScale = 1,
  Radius = 1,
  Pressure = 1,
  Damage = 0,
  Decal = "",
  Direction = {
    x = 0,
    y = 0,
    z = 1
  }
}
L0_6713.Properties = L1_6714
L1_6714 = {}
L1_6714.Icon = "animobject.bmp"
L1_6714.IconOnTop = 1
L0_6713.Editor = L1_6714
L1_6714 = {
  "TurnedOn",
  "TurnedOff",
  "Accelerating",
  "Decelerating",
  "Destroyed"
}
L0_6713.States = L1_6714
L0_6713.fCurrentSpeed = 0
L0_6713.fDesiredSpeed = 0
L1_6714 = {}
L1_6714.impulse = {
  x = 0,
  y = 0,
  z = 0
}
L1_6714.pos = {
  x = 0,
  y = 0,
  z = 0
}
L0_6713.LastHit = L1_6714
L0_6713.shooterId = 0
Fan = L0_6713
L0_6713 = Fan
function L1_6714(A0_6715)
  A0_6715:OnReset()
end
L0_6713.OnPropertyChange = L1_6714
L0_6713 = Fan
function L1_6714(A0_6716, A1_6717)
  local L2_6718
  L2_6718 = A0_6716.fCurrentSpeed
  A1_6717.fCurrentSpeed = L2_6718
  L2_6718 = A0_6716.fDesiredSpeed
  A1_6717.fDesiredSpeed = L2_6718
end
L0_6713.OnSave = L1_6714
L0_6713 = Fan
function L1_6714(A0_6719, A1_6720)
  local L2_6721
  L2_6721 = A1_6720.fCurrentSpeed
  A0_6719.fCurrentSpeed = L2_6721
  L2_6721 = A1_6720.fDesiredSpeed
  A0_6719.fDesiredSpeed = L2_6721
end
L0_6713.OnLoad = L1_6714
L0_6713 = Fan
function L1_6714(A0_6722)
  local L1_6723
  L1_6723 = A0_6722.Properties
  A0_6722.health = L1_6723.fHealth
  if not EmptyString(L1_6723.fileModel) then
    A0_6722:LoadSubObject(0, L1_6723.fileModel, L1_6723.ModelSubObject)
  end
  if not EmptyString(L1_6723.fileModelDestroyed) then
    A0_6722:LoadSubObject(1, L1_6723.fileModelDestroyed, L1_6723.DestroyedSubObject)
  elseif not EmptyString(L1_6723.DestroyedSubObject) then
    A0_6722:LoadSubObject(1, L1_6723.fileModel, L1_6723.DestroyedSubObject)
  end
  A0_6722:SetCurrentSlot(0)
  A0_6722:PhysicalizeThis(0)
  if L1_6723.bTurnedOn == 1 then
    A0_6722.fCurrentSpeed = A0_6722.Properties.MaxSpeed
    A0_6722:GotoState("TurnedOn")
  else
    A0_6722.fCurrentSpeed = 0
    A0_6722:GotoState("TurnedOff")
  end
  A0_6722.fDesiredSpeed = A0_6722.Properties.MaxSpeed
end
L0_6713.OnReset = L1_6714
L0_6713 = Fan
function L1_6714(A0_6724, A1_6725)
  local L2_6726
  L2_6726 = A0_6724.Properties
  L2_6726 = L2_6726.Physics
  EntityCommon.PhysicalizeRigid(A0_6724, A1_6725, L2_6726, 1)
end
L0_6713.PhysicalizeThis = L1_6714
L0_6713 = Fan
L0_6713 = L0_6713.Client
function L1_6714(A0_6727, A1_6728, A2_6729)
  CopyVector(A0_6727.LastHit.pos, A1_6728.pos)
  CopyVector(A0_6727.LastHit.impulse, A1_6728.dir)
  A0_6727.LastHit.impulse.x = A0_6727.LastHit.impulse.x * A1_6728.damage
  A0_6727.LastHit.impulse.y = A0_6727.LastHit.impulse.y * A1_6728.damage
  A0_6727.LastHit.impulse.z = A0_6727.LastHit.impulse.z * A1_6728.damage
end
L0_6713.OnHit = L1_6714
L0_6713 = Fan
L0_6713 = L0_6713.Server
function L1_6714(A0_6730, A1_6731)
  A0_6730.shooterId = A1_6731.shooterId
  A0_6730.health = A0_6730.health - A1_6731.damage
  BroadcastEvent(A0_6730, "Hit")
  if A0_6730.health <= 0 then
    A0_6730:GotoState("Destroyed")
  end
end
L0_6713.OnHit = L1_6714
L0_6713 = Fan
function L1_6714(A0_6732)
  local L1_6733, L2_6734, L3_6735
  L1_6733 = A0_6732.Properties
  L2_6734 = A0_6732.LastHit
  L2_6734 = L2_6734.pos
  L3_6735 = A0_6732.LastHit
  L3_6735 = L3_6735.impulse
  A0_6732:BreakToPieces(0, 0, L1_6733.Breakage.fExplodeImpulse, L2_6734, L3_6735, L1_6733.Breakage.fLifeTime, L1_6733.Breakage.bSurfaceEffects)
  if NumberToBool(A0_6732.Properties.Destruction.bExplode) then
    g_gameRules:CreateExplosion(A0_6732.shooterId, A0_6732.id, A0_6732.Properties.Destruction.Damage, A0_6732:GetWorldPos(), A0_6732.Properties.Destruction.Direction, A0_6732.Properties.Destruction.Radius, nil, A0_6732.Properties.Destruction.Pressure, A0_6732.Properties.Destruction.HoleSize, A0_6732.Properties.Destruction.ParticleEffect, A0_6732.Properties.Destruction.EffectScale)
  end
  A0_6732:SetCurrentSlot(1)
  if L1_6733.Physics.bRigidBodyAfterDeath == 1 then
    L1_6733.Physics.bRigidBody = 1
    A0_6732:PhysicalizeThis(1)
    L1_6733.Physics.bRigidBody = L1_6733.Physics.bRigidBody
  else
    A0_6732:PhysicalizeThis(1)
  end
  A0_6732:RemoveDecals()
  A0_6732:AwakePhysics(1)
end
L0_6713.Explode = L1_6714
L0_6713 = Fan
function L1_6714(A0_6736, A1_6737)
  if A1_6737 == 0 then
    A0_6736:DrawSlot(0, 1)
    A0_6736:DrawSlot(1, 0)
  else
    A0_6736:DrawSlot(0, 0)
    A0_6736:DrawSlot(1, 1)
  end
  A0_6736.currentSlot = A1_6737
end
L0_6713.SetCurrentSlot = L1_6714
L0_6713 = Fan
L0_6713 = L0_6713.Server
function L1_6714(A0_6738)
  if not A0_6738.bInitialized then
    A0_6738:OnReset()
    A0_6738.bInitialized = 1
  end
end
L0_6713.OnInit = L1_6714
L0_6713 = Fan
L0_6713 = L0_6713.Client
function L1_6714(A0_6739)
  if not A0_6739.bInitialized then
    A0_6739:OnReset()
    A0_6739.bInitialized = 1
  end
end
L0_6713.OnInit = L1_6714
L0_6713 = Fan
function L1_6714(A0_6740)
  BroadcastEvent(A0_6740, "Destroyed")
end
L0_6713.Event_Destroyed = L1_6714
L0_6713 = Fan
function L1_6714(A0_6741)
  if A0_6741:GetState() ~= "Destroyed" then
    A0_6741:GotoState("Accelerating")
  end
end
L0_6713.Event_TurnOn = L1_6714
L0_6713 = Fan
function L1_6714(A0_6742)
  if A0_6742:GetState() ~= "Destroyed" then
    A0_6742:GotoState("Decelerating")
  end
end
L0_6713.Event_TurnOff = L1_6714
L0_6713 = Fan
function L1_6714(A0_6743)
  if A0_6743:GetState() ~= "Destroyed" then
    if A0_6743:GetState() == "Accelerating" or A0_6743:GetState() == "TurnedOn" then
      A0_6743:GotoState("Decelerating")
    elseif A0_6743:GetState() == "Decelerating" or A0_6743:GetState() == "TurnedOff" then
      A0_6743:GotoState("Accelerating")
    end
  end
end
L0_6713.Event_Switch = L1_6714
L0_6713 = Fan
function L1_6714(A0_6744, A1_6745)
  BroadcastEvent(A0_6744, "Hit")
end
L0_6713.Event_Hit = L1_6714
L0_6713 = Fan
L0_6713 = L0_6713.Server
L1_6714 = {}
function L1_6714.OnBeginState(A0_6746)
  BroadcastEvent(A0_6746, "TurnOn")
  A0_6746:SetTimer(0, 25)
end
function L1_6714.OnTimer(A0_6747, A1_6748, A2_6749)
  A0_6747:GetAngles(g_Vectors.temp_v1)
  g_Vectors.temp_v1.z = g_Vectors.temp_v1.z + A0_6747.fCurrentSpeed
  A0_6747:SetAngles(g_Vectors.temp_v1)
  A0_6747:SetTimer(0, 25)
end
function L1_6714.OnEndState(A0_6750)
  local L1_6751
end
L0_6713.TurnedOn = L1_6714
L0_6713 = Fan
L0_6713 = L0_6713.Server
L1_6714 = {}
function L1_6714.OnBeginState(A0_6752)
  BroadcastEvent(A0_6752, "TurnOff")
end
function L1_6714.OnEndState(A0_6753)
  local L1_6754
end
L0_6713.TurnedOff = L1_6714
L0_6713 = Fan
L0_6713 = L0_6713.Server
L1_6714 = {}
function L1_6714.OnBeginState(A0_6755)
  A0_6755:SetTimer(0, 25)
end
function L1_6714.OnTimer(A0_6756, A1_6757, A2_6758)
  A0_6756:GetAngles(g_Vectors.temp_v1)
  g_Vectors.temp_v1.z = g_Vectors.temp_v1.z + A0_6756.fCurrentSpeed
  A0_6756:SetAngles(g_Vectors.temp_v1)
  if A0_6756.fCurrentSpeed <= A0_6756.fDesiredSpeed then
    A0_6756.fCurrentSpeed = A0_6756.fCurrentSpeed + A0_6756.fDesiredSpeed / 100
    A0_6756:SetTimer(0, 25)
  else
    A0_6756:GotoState("TurnedOn")
  end
end
function L1_6714.OnEndState(A0_6759)
  local L1_6760
end
L0_6713.Accelerating = L1_6714
L0_6713 = Fan
L0_6713 = L0_6713.Server
L1_6714 = {}
function L1_6714.OnBeginState(A0_6761)
  A0_6761:SetTimer(0, 25)
end
function L1_6714.OnTimer(A0_6762, A1_6763, A2_6764)
  A0_6762:GetAngles(g_Vectors.temp_v1)
  g_Vectors.temp_v1.z = g_Vectors.temp_v1.z + A0_6762.fCurrentSpeed
  A0_6762:SetAngles(g_Vectors.temp_v1)
  if A0_6762.fCurrentSpeed > 0.01 then
    A0_6762.fCurrentSpeed = A0_6762.fCurrentSpeed - A0_6762.fDesiredSpeed / 100
    A0_6762:SetTimer(0, 25)
  else
    A0_6762:GotoState("TurnedOff")
  end
end
function L1_6714.OnEndState(A0_6765)
  local L1_6766
end
L0_6713.Decelerating = L1_6714
L0_6713 = Fan
L0_6713 = L0_6713.Server
L1_6714 = {}
function L1_6714.OnBeginState(A0_6767)
  A0_6767:Explode()
  BroadcastEvent(A0_6767, "Destroyed")
  A0_6767:SetTimer(0, 25)
end
function L1_6714.OnTimer(A0_6768, A1_6769, A2_6770)
  A0_6768:GetAngles(g_Vectors.temp_v1)
  g_Vectors.temp_v1.z = g_Vectors.temp_v1.z + A0_6768.fCurrentSpeed
  A0_6768:SetAngles(g_Vectors.temp_v1)
  if A0_6768.fCurrentSpeed > 0.01 then
    A0_6768.fCurrentSpeed = A0_6768.fCurrentSpeed - A0_6768.fDesiredSpeed / 100 * 2
    A0_6768:SetTimer(0, 25)
  end
end
function L1_6714.OnEndState(A0_6771)
  local L1_6772
end
L0_6713.Destroyed = L1_6714
L0_6713 = Fan
L1_6714 = {}
L1_6714.Inputs = {
  Switch = {
    Fan.Event_Switch,
    "bool"
  },
  TurnOn = {
    Fan.Event_TurnOn,
    "bool"
  },
  TurnOff = {
    Fan.Event_TurnOff,
    "bool"
  },
  Hit = {
    Fan.Event_hit,
    "bool"
  },
  Destroyed = {
    Fan.Event_Destroyed,
    "bool"
  }
}
L1_6714.Outputs = {
  TurnOn = "bool",
  TurnOff = "bool",
  Hit = "bool",
  Destroyed = "bool"
}
L0_6713.FlowEvents = L1_6714
