local L0_483, L1_484, L2_485
L0_483 = {}
L0_483.type = "Mine"
L0_483.MapVisMask = 0
L1_484 = {}
L1_484.bEnabled = 1
L0_483.Properties = L1_484
L1_484 = {}
L1_484.Model = "Objects/Editor/T.cgf"
L0_483.Editor = L1_484
L1_484 = {}
L1_484.pos = nil
L1_484.damage = 1000
L1_484.rmin = 2
L1_484.rmax = 20.5
L1_484.radius = 3
L1_484.impulsive_pressure = 200
L1_484.shooter = nil
L1_484.weapon = nil
L0_483.ExplosionParams = L1_484
L0_483.mine_triggered = nil
L0_483.Enabled = 1
AreaMine = L0_483
L0_483 = AreaMine
function L1_484(A0_486)
  A0_486:OnReset()
end
L0_483.OnPropertyChange = L1_484
L0_483 = AreaMine
function L1_484(A0_487)
  A0_487:Activate(0)
  A0_487:OnReset()
end
L0_483.OnInit = L1_484
L0_483 = AreaMine
function L1_484(A0_488)
  local L1_489
end
L0_483.OnShutDown = L1_484
L0_483 = AreaMine
function L1_484(A0_490)
  A0_490.Enabled = A0_490.Properties.bEnabled
  A0_490:RegisterState("Waiting")
  A0_490:RegisterState("Dead")
  A0_490:GotoState("Waiting")
end
L0_483.OnReset = L1_484
L0_483 = AreaMine
function L1_484(A0_491, A1_492)
  if A0_491.Enabled then
    A0_491:Explode()
    A0_491:GotoState("Dead")
  end
  BroadcastEvent(A0_491, "Trigger")
end
L0_483.Event_Explode = L1_484
L0_483 = AreaMine
L1_484 = {}
function L2_485(A0_493)
  local L1_494
end
L1_484.OnBeginState = L2_485
L0_483.Dead = L1_484
L0_483 = AreaMine
L1_484 = {}
function L2_485(A0_495)
  local L1_496
end
L1_484.OnBeginState = L2_485
function L2_485(A0_497, A1_498, A2_499)
  A0_497:SetPos(A1_498:GetPos())
  A0_497:Explode(A0_497)
end
L1_484.OnEnterArea = L2_485
L0_483.Waiting = L1_484
L0_483 = AreaMine
function L1_484(A0_500)
  local L1_501, L2_502
  L1_501 = {}
  L1_501.x = 0
  L1_501.y = 0
  L1_501.z = -0.1
  L2_502 = A0_500.GetPos
  L2_502 = L2_502(A0_500)
  ExecuteMaterial(L2_502, L1_501, Materials.mat_default.projectile_hit, 1)
  A0_500.ExplosionParams.pos = L2_502
  A0_500.ExplosionParams.shooter = A0_500
  A0_500:GotoState("Dead")
  Server:RemoveEntity(A0_500.id)
  Game:CreateExplosion(A0_500.ExplosionParams)
end
L0_483.Explode = L1_484
L0_483 = AreaMine
L1_484 = {}
L2_485 = {}
L2_485.Explode = {
  AreaMine.Event_Explode,
  "bool"
}
L1_484.Inputs = L2_485
L2_485 = {}
L2_485.Explode = "bool"
L1_484.Outputs = L2_485
L0_483.FlowEvents = L1_484
