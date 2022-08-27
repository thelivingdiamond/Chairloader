local L0_755, L1_756, L2_757
L0_755 = {}
L1_756 = {}
L0_755.Client = L1_756
L1_756 = {}
L0_755.Server = L1_756
L1_756 = {}
L1_756.fileModel = "objects/library/props/electronic_devices/fans/ceiling_fan_local.cgf"
L1_756.fileDestroyedModel = "objects/library/props/electronic_devices/fans/ceiling_fan_local.cgf"
L1_756.MaxSpeed = 0.25
L1_756.fHealth = 25
L2_757 = {}
L2_757.bRigidBody = 1
L2_757.bRigidBodyActive = 1
L2_757.bResting = 1
L2_757.Density = -1
L2_757.Mass = 150
L1_756.Physics = L2_757
L2_757 = {}
L2_757.bExplode = 1
L2_757.Effect = "explosions.large_Vehicle.a"
L2_757.EffectScale = 0.05
L2_757.Radius = 10
L2_757.Pressure = 12
L2_757.Damage = 25
L2_757.Decal = ""
L1_756.Destruction = L2_757
L2_757 = {}
L2_757.Icon = "Item.bmp"
L2_757.IconOnTop = 1
L1_756.Editor = L2_757
L2_757 = {
  "TurnedOn",
  "TurnedOff",
  "Accelerating",
  "Decelerating",
  "Destroyed"
}
L1_756.States = L2_757
L1_756.fCurrentSpeed = 0
L1_756.fDesiredSpeed = 0
L0_755.Properties = L1_756
Fan = L0_755
L0_755 = Fan
function L1_756(A0_758)
  A0_758:OnReset()
end
L0_755.OnPropertyChange = L1_756
L0_755 = Fan
function L1_756(A0_759, A1_760)
end
L0_755.OnSave = L1_756
L0_755 = Fan
function L1_756(A0_761, A1_762)
end
L0_755.OnLoad = L1_756
L0_755 = Fan
function L1_756(A0_763)
  A0_763.health = A0_763.Properties.fHealth
  A0_763:PhysicalizeThis(0)
  A0_763:GotoState("TurnedOff")
  A0_763.fCurrentSpeed = 0
  A0_763.fDesiredSpeed = A0_763.Properties.MaxSpeed
end
L0_755.OnReset = L1_756
L0_755 = Fan
function L1_756(A0_764)
  local L1_765, L2_766
  L1_765 = A0_764.Properties
  L1_765 = L1_765.fileModel
  if L1_765 ~= "" then
    L2_766 = A0_764.LoadObject
    L2_766(A0_764, 0, L1_765)
  end
  L2_766 = A0_764.Properties
  L2_766 = L2_766.Physics
  EntityCommon.PhysicalizeRigid(A0_764, 0, L2_766, 1)
end
L0_755.PhysicalizeThis = L1_756
L0_755 = Fan
L0_755 = L0_755.Server
function L1_756(A0_767, A1_768, A2_769, A3_770, A4_771)
  A0_767.health = A0_767.health - A4_771
  BroadcastEvent(A0_767, "Hit")
  if A0_767.health <= 0 then
    A0_767:GotoState("Destroyed")
  end
end
L0_755.OnHit = L1_756
L0_755 = Fan
function L1_756(A0_772)
  local L1_773
  L1_773 = NumberToBool
  L1_773 = L1_773(A0_772.Properties.Destruction.bExplode)
  if L1_773 then
    L1_773 = A0_772.Properties
    L1_773 = L1_773.Destruction
    g_gameRules.server:RequestExplosion(NULL_ENTITY, A0_772.id, A0_772:GetWorldPos(), L1_773.Direction, L1_773.Radius, L1_773.Pressure, L1_773.Damage, 0, 0, L1_773.Decal, L1_773.Effect, L1_773.EffectScale)
  end
  L1_773 = A0_772.Properties
  L1_773 = L1_773.fileDestroyedModel
  if L1_773 ~= "" then
    A0_772:LoadObject(0, L1_773)
  end
end
L0_755.Explode = L1_756
L0_755 = Fan
L0_755 = L0_755.Server
function L1_756(A0_774)
  if not A0_774.bInitialized then
    A0_774:OnReset()
    A0_774.bInitialized = 1
  end
end
L0_755.OnInit = L1_756
L0_755 = Fan
L0_755 = L0_755.Client
function L1_756(A0_775)
  if not A0_775.bInitialized then
    A0_775:OnReset()
    A0_775.bInitialized = 1
  end
end
L0_755.OnInit = L1_756
L0_755 = Fan
function L1_756(A0_776)
  BroadcastEvent(A0_776, "Destroyed")
end
L0_755.Event_Destroyed = L1_756
L0_755 = Fan
function L1_756(A0_777)
  if A0_777:GetState() ~= "Destroyed" then
    A0_777:GotoState("Accelerating")
  end
end
L0_755.Event_TurnOn = L1_756
L0_755 = Fan
function L1_756(A0_778)
  if A0_778:GetState() ~= "Destroyed" then
    A0_778:GotoState("Decelerating")
  end
end
L0_755.Event_TurnOff = L1_756
L0_755 = Fan
function L1_756(A0_779)
  if A0_779:GetState() ~= "Destroyed" then
    if A0_779:GetState() == "Accelerating" or A0_779:GetState() == "TurnedOn" then
      A0_779:GotoState("Decelerating")
    elseif A0_779:GetState() == "Decelerating" or A0_779:GetState() == "TurnedOff" then
      A0_779:GotoState("Accelerating")
    end
  end
end
L0_755.Event_Switch = L1_756
L0_755 = Fan
function L1_756(A0_780, A1_781)
  BroadcastEvent(A0_780, "Hit")
end
L0_755.Event_Hit = L1_756
L0_755 = Fan
L0_755 = L0_755.Server
L1_756 = {}
function L2_757(A0_782)
  BroadcastEvent(A0_782, "TurnOn")
  A0_782:SetTimer(0, 25)
end
L1_756.OnBeginState = L2_757
function L2_757(A0_783, A1_784, A2_785)
  A0_783:GetAngles(g_Vectors.temp_v1)
  g_Vectors.temp_v1.z = g_Vectors.temp_v1.z + A0_783.fCurrentSpeed
  A0_783:SetAngles(g_Vectors.temp_v1)
  A0_783:SetTimer(0, 25)
end
L1_756.OnTimer = L2_757
function L2_757(A0_786)
  local L1_787
end
L1_756.OnEndState = L2_757
L0_755.TurnedOn = L1_756
L0_755 = Fan
L0_755 = L0_755.Server
L1_756 = {}
function L2_757(A0_788)
  BroadcastEvent(A0_788, "TurnOff")
end
L1_756.OnBeginState = L2_757
function L2_757(A0_789)
  local L1_790
end
L1_756.OnEndState = L2_757
L0_755.TurnedOff = L1_756
L0_755 = Fan
L0_755 = L0_755.Server
L1_756 = {}
function L2_757(A0_791)
  A0_791:SetTimer(0, 25)
end
L1_756.OnBeginState = L2_757
function L2_757(A0_792, A1_793, A2_794)
  A0_792:GetAngles(g_Vectors.temp_v1)
  g_Vectors.temp_v1.z = g_Vectors.temp_v1.z + A0_792.fCurrentSpeed
  A0_792:SetAngles(g_Vectors.temp_v1)
  if A0_792.fCurrentSpeed <= A0_792.fDesiredSpeed then
    A0_792.fCurrentSpeed = A0_792.fCurrentSpeed + A0_792.fDesiredSpeed / 100
    A0_792:SetTimer(0, 25)
  else
    A0_792:GotoState("TurnedOn")
  end
end
L1_756.OnTimer = L2_757
function L2_757(A0_795)
  local L1_796
end
L1_756.OnEndState = L2_757
L0_755.Accelerating = L1_756
L0_755 = Fan
L0_755 = L0_755.Server
L1_756 = {}
function L2_757(A0_797)
  A0_797:SetTimer(0, 25)
end
L1_756.OnBeginState = L2_757
function L2_757(A0_798, A1_799, A2_800)
  A0_798:GetAngles(g_Vectors.temp_v1)
  g_Vectors.temp_v1.z = g_Vectors.temp_v1.z + A0_798.fCurrentSpeed
  A0_798:SetAngles(g_Vectors.temp_v1)
  if A0_798.fCurrentSpeed > 0.01 then
    A0_798.fCurrentSpeed = A0_798.fCurrentSpeed - A0_798.fDesiredSpeed / 100
    A0_798:SetTimer(0, 25)
  else
    A0_798:GotoState("TurnedOff")
  end
end
L1_756.OnTimer = L2_757
function L2_757(A0_801)
  local L1_802
end
L1_756.OnEndState = L2_757
L0_755.Decelerating = L1_756
L0_755 = Fan
L0_755 = L0_755.Server
L1_756 = {}
function L2_757(A0_803)
  A0_803:Explode()
  BroadcastEvent(A0_803, "Destroyed")
  A0_803:SetTimer(0, 25)
end
L1_756.OnBeginState = L2_757
function L2_757(A0_804, A1_805, A2_806)
  A0_804:GetAngles(g_Vectors.temp_v1)
  g_Vectors.temp_v1.z = g_Vectors.temp_v1.z + A0_804.fCurrentSpeed
  A0_804:SetAngles(g_Vectors.temp_v1)
  if A0_804.fCurrentSpeed > 0.01 then
    A0_804.fCurrentSpeed = A0_804.fCurrentSpeed - A0_804.fDesiredSpeed / 100 * 2
    A0_804:SetTimer(0, 25)
  end
end
L1_756.OnTimer = L2_757
function L2_757(A0_807)
  local L1_808
end
L1_756.OnEndState = L2_757
L0_755.Destroyed = L1_756
L0_755 = Fan
L1_756 = {}
L2_757 = {}
L2_757.Switch = {
  Fan.Event_Switch,
  "bool"
}
L2_757.TurnOn = {
  Fan.Event_TurnOn,
  "bool"
}
L2_757.TurnOff = {
  Fan.Event_TurnOff,
  "bool"
}
L2_757.Hit = {
  Fan.Event_hit,
  "bool"
}
L2_757.Destroyed = {
  Fan.Event_Destroyed,
  "bool"
}
L1_756.Inputs = L2_757
L2_757 = {}
L2_757.TurnOn = "bool"
L2_757.TurnOff = "bool"
L2_757.Hit = "bool"
L2_757.Destroyed = "bool"
L1_756.Outputs = L2_757
L0_755.FlowEvents = L1_756
