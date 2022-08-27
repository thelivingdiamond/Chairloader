local L0_559, L1_560
L0_559 = {}
L0_559.type = "BFlyController"
L1_560 = {}
L1_560.BFlyNumber = 23
L0_559.Properties = L1_560
L1_560 = {}
L1_560.Model = "Objects/Editor/T.cgf"
L0_559.Editor = L1_560
L0_559.outsideBFlyNumber = 0
BFly = L0_559
L0_559 = BFly
function L1_560(A0_561)
  local L1_562
end
L0_559.OnInit = L1_560
L0_559 = BFly
function L1_560(A0_563, A1_564, A2_565, A3_566)
  System.SetBFCount(Lerp(A0_563.outsideBFlyNumber, A0_563.Properties.BFlyNumber, A3_566))
end
L0_559.OnProceedFadeArea = L1_560
L0_559 = BFly
function L1_560(A0_567, A1_568, A2_569)
  A0_567.outsideBFlyNumber = System.GetBFCount()
end
L0_559.OnEnterArea = L1_560
L0_559 = BFly
function L1_560(A0_570, A1_571, A2_572)
  System.SetBFCount(A0_570.outsideBFlyNumber)
end
L0_559.OnLeaveArea = L1_560
L0_559 = BFly
function L1_560(A0_573)
  local L1_574
end
L0_559.OnShutDown = L1_560
