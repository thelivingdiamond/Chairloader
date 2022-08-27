local L0_845, L1_846
L0_845 = {}
L0_845.type = "Mine"
L0_845.MapVisMask = 0
L1_846 = {}
L1_846.Radius = 4
L1_846.bEnabled = 1
L1_846.Delay = 0.2
L1_846.bOnlyPlayer = 1
L0_845.Properties = L1_846
L1_846 = {}
L1_846.mass = 10
L1_846.size = 0.1
L1_846.heading = {
  x = 0,
  y = 0,
  z = 1
}
L1_846.initial_velocity = 18
L1_846.k_air_resistance = 0
L1_846.acc_thrust = 0
L1_846.acc_lift = 0
L1_846.surface_idx = 0
L1_846.gravity = {
  x = 0,
  y = 0,
  z = -19.62
}
L0_845.JumpParams = L1_846
L1_846 = {}
L1_846.pos = {}
L1_846.damage = 100
L1_846.rmin = 2
L1_846.rmax = 20.5
L1_846.radius = 20
L1_846.impulsive_pressure = 200
L1_846.shooter = nil
L1_846.weapon = nil
L0_845.ExplosionParams = L1_846
L1_846 = {}
L1_846.focus = 1
L1_846.color = {
  1,
  1,
  1
}
L1_846.speed = 1
L1_846.count = 2
L1_846.size = 0.2
L1_846.size_speed = 1
L1_846.gravity = -9.8
L1_846.lifetime = 1
L1_846.frames = 1
L1_846.blend_type = 0
L1_846.color_based_blending = 0
L1_846.tid = System.LoadTexture("textures/WeaponMuzzleFlash/smoke.dds")
L0_845.Smoke = L1_846
L1_846 = {}
L0_845.Editor = L1_846
L0_845.Who = nil
L0_845.Enabled = 1
FrogMine = L0_845
L0_845 = FrogMine
function L1_846(A0_847)
  A0_847:OnReset()
end
L0_845.OnPropertyChange = L1_846
L0_845 = FrogMine
function L1_846(A0_848)
  A0_848:Activate(0)
  A0_848:TrackColliders(1)
  A0_848:LoadObject("Objects/Pickups/Health/Medikit.cgf", 0, 1)
  A0_848:OnReset()
end
L0_845.OnInit = L1_846
L0_845 = FrogMine
function L1_846(A0_849)
  local L1_850
end
L0_845.OnShutDown = L1_846
L0_845 = FrogMine
function L1_846(A0_851)
  local L1_852, L2_853
  L1_852 = {}
  L2_853 = A0_851.Properties
  L2_853 = L2_853.Radius
  L2_853 = -L2_853
  L2_853 = L2_853 / 2
  L1_852.x = L2_853
  L2_853 = A0_851.Properties
  L2_853 = L2_853.Radius
  L2_853 = -L2_853
  L2_853 = L2_853 / 2
  L1_852.y = L2_853
  L2_853 = A0_851.Properties
  L2_853 = L2_853.Radius
  L2_853 = -L2_853
  L2_853 = L2_853 / 2
  L1_852.z = L2_853
  L2_853 = {}
  L2_853.x = A0_851.Properties.Radius / 2
  L2_853.y = A0_851.Properties.Radius / 2
  L2_853.z = A0_851.Properties.Radius / 2
  A0_851:SetBBox(L1_852, L2_853)
  A0_851:DrawObject(0, 1)
  A0_851.Enabled = A0_851.Properties.bEnabled
  A0_851.Who = nil
  A0_851.Died = 0
  A0_851:GotoState("Waiting")
end
L0_845.OnReset = L1_846
L0_845 = FrogMine
function L1_846(A0_854, A1_855)
  A0_854.Enabled = 1
  BroadcastEvent(A0_854, "Enable")
end
L0_845.Event_Enable = L1_846
L0_845 = FrogMine
function L1_846(A0_856, A1_857)
  A0_856.Enabled = 0
  BroadcastEvent(A0_856, "Disable")
end
L0_845.Event_Disable = L1_846
L0_845 = FrogMine
function L1_846(A0_858, A1_859)
  System.LogToConsole("Trigered")
  if A0_858.Enabled ~= 0 and A0_858.Died == 0 then
    A0_858:GotoState("Triggered")
  end
  BroadcastEvent(A0_858, "Trigger")
end
L0_845.Event_Trigger = L1_846
L0_845 = FrogMine
function L1_846(A0_860, A1_861)
  local L2_862
  L2_862 = A0_860.Properties
  L2_862 = L2_862.bOnlyPlayer
  if L2_862 ~= 0 then
    L2_862 = A1_861.type
    if L2_862 ~= "Player" then
      L2_862 = 0
      return L2_862
    end
  end
  L2_862 = 1
  return L2_862
end
L0_845.IsValid = L1_846
L0_845 = FrogMine
L1_846 = {}
function L1_846.OnBeginState(A0_863)
  A0_863.Died = 1
  A0_863:DrawObject(0, 0)
end
L0_845.Dead = L1_846
L0_845 = FrogMine
L1_846 = {}
function L1_846.OnBeginState(A0_864)
  local L1_865
  A0_864.Who = nil
end
function L1_846.OnEnterArea(A0_866, A1_867)
  if A0_866.Enabled ~= 1 then
    return
  end
  if A0_866:IsValid(A1_867) == 0 then
    return
  end
  A0_866.Who = A1_867
  A0_866:Event_Trigger(A0_866)
end
L0_845.Waiting = L1_846
L0_845 = FrogMine
L1_846 = {}
function L1_846.OnBeginState(A0_868)
  A0_868.part_time = 10
  A0_868.speed = 20
  A0_868.curr_time = 0
  A0_868.startZ = A0_868:GetPos().z
  if 0 < A0_868.Properties.Delay then
    A0_868:SetTimer(A0_868.Properties.Delay * 1000)
  else
    A0_868:SetTimer(1)
  end
end
function L1_846.OnEndState(A0_869)
  local L1_870
  L1_870 = A0_869.GetPos
  L1_870 = L1_870(A0_869)
  L1_870.z = A0_869.startZ
  A0_869:SetPos(L1_870)
end
function L1_846.OnTimer(A0_871)
  A0_871:Explode()
  A0_871:GotoState("Dead")
  A0_871:GotoState("Waiting")
end
function L1_846.OnUpdate(A0_872, A1_873)
  local L2_874, L3_875
  L2_874 = A0_872.curr_time
  L2_874 = L2_874 + A1_873
  A0_872.curr_time = L2_874
  L2_874 = A0_872.curr_time
  L3_875 = A0_872.GetPos
  L3_875 = L3_875(A0_872)
  L3_875.z = A0_872.startZ + A0_872.speed * L2_874 - 19.62 * (L2_874 * L2_874)
  A0_872:SetPos(L3_875)
  A0_872.part_time = A0_872.part_time + A1_873 * 2
  if A0_872.part_time > 0.06 then
    Particle.CreateParticle(A0_872:GetPos(), {
      x = 0,
      y = 0,
      z = 0
    }, A0_872.Smoke)
    A0_872.part_time = 0
  end
end
L0_845.Triggered = L1_846
L0_845 = FrogMine
function L1_846(A0_876)
  local L1_877, L2_878
  L1_877 = {}
  L1_877.x = 0
  L1_877.y = 0
  L1_877.z = 0.5
  L2_878 = A0_876.GetPos
  L2_878 = L2_878(A0_876)
  ExecuteMaterial(L2_878, L1_877, Materials.mat_default.projectile_hit, 1)
  A0_876.ExplosionParams.pos = L2_878
  Game:CreateExplosion(A0_876.ExplosionParams)
  System.DeformTerrain(L2_878, 8, Grenade.decal_tid)
  A0_876:AddDynamicLight(L2_878, 20, 1, 1, 0.3, 1, 1, 1, 0.3, 1, 1)
end
L0_845.Explode = L1_846
L0_845 = FrogMine
L1_846 = {}
L1_846.Inputs = {
  Disable = {
    FrogMine.Event_Disable,
    "bool"
  },
  Enable = {
    FrogMine.Event_Enable,
    "bool"
  },
  Trigger = {
    FrogMine.Event_Trigger,
    "bool"
  }
}
L1_846.Outputs = {
  Disable = "bool",
  Enable = "bool",
  Trigger = "bool"
}
L0_845.FlowEvents = L1_846
