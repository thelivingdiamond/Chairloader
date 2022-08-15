local L0_7818, L1_7819, L2_7820, L3_7821
L0_7818 = {}
L1_7819 = {}
L1_7819.object_Model = "engine/engineassets/objects/default.cgf"
L2_7820 = {}
L2_7820.mass = 50
L2_7820.radius = 1
L2_7820.air_resistance = 0
L3_7821 = {}
L3_7821.x = 0
L3_7821.y = 0
L3_7821.z = -9.81
L2_7820.gravity = L3_7821
L2_7820.water_resistance = 0.5
L3_7821 = {}
L3_7821.x = 0
L3_7821.y = 0
L3_7821.z = -7.8480005
L2_7820.water_gravity = L3_7821
L2_7820.min_bounce_vel = 1.5
L2_7820.accel_thrust = 0
L2_7820.accel_lift = 0
L3_7821 = {}
L3_7821.x = 0
L3_7821.y = 0
L3_7821.z = 0
L2_7820.velocity = L3_7821
L2_7820.thickness = 1
L3_7821 = {}
L3_7821.x = 0
L3_7821.y = 0
L3_7821.z = 0
L2_7820.wspin = L3_7821
L3_7821 = {}
L3_7821.x = 0
L3_7821.y = 0
L3_7821.z = 1
L2_7820.normal = L3_7821
L2_7820.pierceability = 15
L2_7820.constant_orientation = false
L2_7820.single_contact = true
L2_7820.no_roll = false
L2_7820.no_spin = true
L2_7820.no_path_alignment = false
L2_7820.collider_to_ignore = 0
L2_7820.material = ""
L1_7819.Particle = L2_7820
L0_7818.Properties = L1_7819
L1_7819 = {}
L1_7819.Icon = "physicsobject.bmp"
L1_7819.IconOnTop = 1
L0_7818.Editor = L1_7819
ParticlePhysics = L0_7818
L0_7818 = ParticlePhysics
function L1_7819(A0_7822)
  local L1_7823
  L1_7823 = A0_7822.Properties
  A0_7822:FreeSlot(0)
  if L1_7823.object_Model ~= "" then
    A0_7822:LoadObject(0, L1_7823.object_Model)
  end
  NormalizeVector(L1_7823.Particle.normal)
  A0_7822:Physicalize(0, PE_PARTICLE, L1_7823)
  A0_7822:SetSlotPos(0, {
    0,
    0,
    -L1_7823.Particle.thickness * 0.5
  })
end
L0_7818.SetFromProperties = L1_7819
L0_7818 = ParticlePhysics
function L1_7819(A0_7824)
  A0_7824:OnReset()
end
L0_7818.OnSpawn = L1_7819
L0_7818 = ParticlePhysics
function L1_7819(A0_7825)
  A0_7825:OnReset()
end
L0_7818.OnPropertyChange = L1_7819
L0_7818 = ParticlePhysics
function L1_7819(A0_7826)
  A0_7826:SetFromProperties()
end
L0_7818.OnReset = L1_7819
