Script.ReloadScript("scripts/Utils/EntityUtils.lua")
DeflectorShield = {
  Server = {},
  Client = {},
  Properties = {
    object_Model = "engine/engineassets/objects/default.cgf",
    ParticleEffect = "",
    MinDamage = 50,
    MaxDamage = 500,
    DropMinDistance = 10,
    DropPerMeter = 10,
    EnergyRadius = 0.4,
    EnergyDelay = 0.75,
    Spread = 0.1,
    HitType = "bullet",
    AmmoType = "deflectedblast",
    Physics = {Density = -1, Mass = -1}
  },
  Editor = {
    Icon = "Tornado.bmp"
  }
}
function DeflectorShield.CacheResources(A0_6686)
  if A0_6686.Properties.object_Model ~= "" then
    A0_6686:LoadObject(0, A0_6686.Properties.object_Model)
  end
  A0_6686:PreLoadParticleEffect(A0_6686.Properties.ParticleEffect)
end
function DeflectorShield.Server.OnInit(A0_6687)
  A0_6687:OnReset()
end
function DeflectorShield.Client.OnInit(A0_6688)
  if not CryAction.IsServer() then
    A0_6688:OnReset()
  end
end
function DeflectorShield.OnSpawn(A0_6689)
  A0_6689:SetFromProperties()
end
function DeflectorShield.OnReset(A0_6690)
  A0_6690:PhysicalizeThis()
  A0_6690:AwakePhysics(0)
  A0_6690:Recharged()
end
function DeflectorShield.OnPropertyChange(A0_6691)
  A0_6691:SetFromProperties()
end
function DeflectorShield.PhysicalizeThis(A0_6692)
  local L1_6693
  L1_6693 = A0_6692.Properties
  L1_6693 = L1_6693.Physics
  EntityCommon.PhysicalizeRigid(A0_6692, 0, L1_6693, 0)
end
function DeflectorShield.SetFromProperties(A0_6694)
  local L1_6695
  L1_6695 = A0_6694.Properties
  if L1_6695.object_Model == "" then
    return
  end
  A0_6694:LoadObject(0, L1_6695.object_Model)
  A0_6694:PhysicalizeThis()
end
function DeflectorShield.Die(A0_6696, A1_6697)
  A0_6696:Depleted()
end
function DeflectorShield.Server.OnHit(A0_6698, A1_6699)
  local L2_6700
  L2_6700 = A0_6698.dead
  if L2_6700 ~= nil then
    L2_6700 = A0_6698.dead
    if L2_6700 then
      L2_6700 = true
      return L2_6700
    end
  end
  L2_6700 = A1_6699.damage
  if A0_6698:IsInvulnerable() then
    return true
  end
  A0_6698.health = A0_6698.health - L2_6700
  if A0_6698.health <= 0 then
    A0_6698:Die(A1_6699)
  end
  return true
end
function DeflectorShield.OnLoad(A0_6701, A1_6702)
  A0_6701.health = A1_6702.health
end
function DeflectorShield.OnSave(A0_6703, A1_6704)
  A1_6704.health = A0_6703.health
end
function DeflectorShield.Recharged(A0_6705)
  A0_6705.health = A0_6705.Properties.Health.MaxHealth
  A0_6705.dead = false
  A0_6705:Hide(0)
end
function DeflectorShield.Depleted(A0_6706)
  A0_6706.health = 0
  A0_6706.dead = true
  A0_6706:Hide(1)
end
function DeflectorShield.Event_Hide(A0_6707)
  A0_6707:Depleted()
end
function DeflectorShield.Event_UnHide(A0_6708)
  A0_6708:Recharged()
end
DeflectorShield.FlowEvents = {
  Inputs = {
    Hide = {
      DeflectorShield.Event_Hide,
      "bool"
    },
    UnHide = {
      DeflectorShield.Event_UnHide,
      "bool"
    }
  }
}
MakeKillable(DeflectorShield)
