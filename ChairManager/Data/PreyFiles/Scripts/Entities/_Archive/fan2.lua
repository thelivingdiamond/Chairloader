local L0_809, L1_810
L0_809 = {}
L1_810 = {}
L0_809.Properties = L1_810
Fan = L0_809
L0_809 = Fan
function L1_810(A0_811)
  A0_811:SetName("Fan")
  A0_811:LoadCharacter("Objects/Fan/Fan.cid", 0)
  A0_811:DrawCharacter(0, 1)
  A0_811:StartAnimation(0, "FanLoop")
end
L0_809.OnInit = L1_810
L0_809 = Fan
function L1_810(A0_812, A1_813)
end
L0_809.OnContact = L1_810
L0_809 = Fan
function L1_810(A0_814, A1_815)
end
L0_809.OnUpdate = L1_810
L0_809 = Fan
function L1_810(A0_816)
  local L1_817
end
L0_809.OnShutDown = L1_810
L0_809 = Fan
function L1_810(A0_818)
  local L1_819
end
L0_809.OnActivate = L1_810
