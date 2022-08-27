local L0_7685, L1_7686, L2_7687, L3_7688
L0_7685 = {}
L1_7686 = {}
L1_7686.bActive = 1
L1_7686.soclasses_SmartObjectClass = ""
L2_7687 = {}
L2_7687.ParticleEffect = "explosions.grenade_air.explosion"
L2_7687.EffectScale = 1
L2_7687.MinRadius = 5
L2_7687.Radius = 10
L2_7687.MinPhysRadius = 2.5
L2_7687.PhysRadius = 5
L2_7687.Pressure = 1000
L2_7687.Damage = 1000
L3_7688 = {}
L3_7688.x = 0
L3_7688.y = 0
L3_7688.z = 1
L2_7687.Direction = L3_7688
L1_7686.Explosion = L2_7687
L0_7685.Properties = L1_7686
L1_7686 = {}
L1_7686.Icon = "explosion.bmp"
L1_7686.IconOnTop = 1
L0_7685.Editor = L1_7686
Explosion = L0_7685
L0_7685 = Explosion
function L1_7686(A0_7689)
  A0_7689:OnReset()
end
L0_7685.OnPropertyChange = L1_7686
L0_7685 = Explosion
function L1_7686(A0_7690)
  A0_7690:OnReset()
  A0_7690:PreLoadParticleEffect(A0_7690.Properties.Explosion.ParticleEffect)
end
L0_7685.OnInit = L1_7686
L0_7685 = Explosion
function L1_7686(A0_7691)
  A0_7691:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
  A0_7691.bActive = A0_7691.Properties.bActive
end
L0_7685.OnReset = L1_7686
L0_7685 = Explosion
function L1_7686(A0_7692, A1_7693)
  A1_7693.bActive = A0_7692.bActive
end
L0_7685.OnSave = L1_7686
L0_7685 = Explosion
function L1_7686(A0_7694, A1_7695)
  A0_7694.bActive = A1_7695.bActive
end
L0_7685.OnLoad = L1_7686
L0_7685 = Explosion
function L1_7686(A0_7696, A1_7697)
  local L2_7698
  L2_7698 = A0_7696.Properties
  L2_7698 = L2_7698.Explosion
  g_gameRules:CreateExplosion(A0_7696.id, A0_7696.id, L2_7698.Damage, A0_7696:GetWorldPos(), L2_7698.Direction, L2_7698.Radius, nil, L2_7698.Pressure, L2_7698.HoleSize, L2_7698.ParticleEffect, L2_7698.EffectScale, L2_7698.MinRadius, L2_7698.MinPhysRadius, L2_7698.PhysRadius, 4)
  BroadcastEvent(A0_7696, "Explode")
end
L0_7685.Explode = L1_7686
L0_7685 = Explosion
function L1_7686(A0_7699, A1_7700)
  if tonumber(A0_7699.bActive) ~= 0 then
    A0_7699:Explode(NULL_ENTITY)
  end
end
L0_7685.Event_Explode = L1_7686
L0_7685 = Explosion
function L1_7686(A0_7701, A1_7702)
  A0_7701.bActive = 1
  BroadcastEvent(A0_7701, "Activate")
end
L0_7685.Event_Activate = L1_7686
L0_7685 = Explosion
function L1_7686(A0_7703, A1_7704)
  A0_7703.bActive = 0
  BroadcastEvent(A0_7703, "Deactivate")
end
L0_7685.Event_Deactivate = L1_7686
L0_7685 = Explosion
L1_7686 = {}
L2_7687 = {}
L3_7688 = {
  Explosion.Event_Activate,
  "bool"
}
L2_7687.Activate = L3_7688
L3_7688 = {
  Explosion.Event_Deactivate,
  "bool"
}
L2_7687.Deactivate = L3_7688
L3_7688 = {
  Explosion.Event_Explode,
  "bool"
}
L2_7687.Explode = L3_7688
L1_7686.Inputs = L2_7687
L2_7687 = {}
L2_7687.Activate = "bool"
L2_7687.Deactivate = "bool"
L2_7687.Explode = "bool"
L1_7686.Outputs = L2_7687
L0_7685.FlowEvents = L1_7686
