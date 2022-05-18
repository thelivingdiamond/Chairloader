local L0_620, L1_621, L2_622, L3_623
L0_620 = {}
L0_620.type = "CameraFocus"
L1_621 = {}
L1_621.Model = "Objects/Editor/T.cgf"
L0_620.Editor = L1_621
CameraFocus = L0_620
L0_620 = CameraFocus
function L1_621(A0_624)
  A0_624:Activate(0)
end
L0_620.OnInit = L1_621
L0_620 = CameraFocus
function L1_621(A0_625)
  A0_625:GotoState("Inactive")
end
L0_620.OnReset = L1_621
L0_620 = CameraFocus
function L1_621(A0_626, A1_627)
end
L0_620.OnContact = L1_621
L0_620 = CameraFocus
function L1_621(A0_628, A1_629)
end
L0_620.OnDamage = L1_621
L0_620 = CameraFocus
function L1_621(A0_630)
  local L1_631
end
L0_620.OnShutDown = L1_621
L0_620 = CameraFocus
function L1_621(A0_632, A1_633, A2_634)
end
L0_620.OnEvent = L1_621
L0_620 = CameraFocus
function L1_621(A0_635, A1_636)
end
L0_620.OnSave = L1_621
L0_620 = CameraFocus
function L1_621(A0_637, A1_638)
end
L0_620.OnLoad = L1_621
L0_620 = CameraFocus
function L1_621(A0_639, A1_640)
end
L0_620.OnWrite = L1_621
L0_620 = CameraFocus
function L1_621(A0_641, A1_642)
end
L0_620.OnRead = L1_621
L0_620 = CameraFocus
function L1_621(A0_643)
  A0_643:GotoState("Active")
end
L0_620.Event_Enable = L1_621
L0_620 = CameraFocus
function L1_621(A0_644)
  A0_644:GotoState("Inactive")
end
L0_620.Event_Disable = L1_621
L0_620 = CameraFocus
L1_621 = {}
function L2_622(A0_645)
  A0_645:Activate(1)
end
L1_621.OnBeginState = L2_622
function L2_622(A0_646)
  A0_646:Activate(0)
end
L1_621.OnEndState = L2_622
function L2_622(A0_647)
  local L1_648
end
L1_621.OnUpdate = L2_622
L0_620.Active = L1_621
L0_620 = CameraFocus
L1_621 = {}
function L2_622(A0_649)
  A0_649:Activate(0)
end
L1_621.OnBeginState = L2_622
L0_620.Inactive = L1_621
L0_620 = CameraFocus
L1_621 = {}
L2_622 = {}
L3_623 = {
  CameraFocus.Event_Disable,
  "bool"
}
L2_622.Disable = L3_623
L3_623 = {
  CameraFocus.Event_Enable,
  "bool"
}
L2_622.Enable = L3_623
L1_621.Inputs = L2_622
L2_622 = {}
L2_622.Disable = "bool"
L2_622.Enable = "bool"
L1_621.Outputs = L2_622
L0_620.FlowEvents = L1_621
