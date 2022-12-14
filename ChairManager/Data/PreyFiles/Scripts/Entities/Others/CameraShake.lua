local L0_6599, L1_6600, L2_6601
L0_6599 = {}
L1_6600 = {}
L2_6601 = {}
L2_6601.x = 0
L2_6601.y = 0
L2_6601.z = 0
L1_6600.vector_Position = L2_6601
L1_6600.fRadius = 10
L1_6600.fStrength = 1
L1_6600.fDuration = 2
L1_6600.fFrequency = 0.5
L0_6599.Properties = L1_6600
L1_6600 = {}
L1_6600.Icon = "shake.bmp"
L0_6599.Editor = L1_6600
CameraShake = L0_6599
L0_6599 = CameraShake
function L1_6600(A0_6602)
  local L1_6603
end
L0_6599.OnPropertyChange = L1_6600
L0_6599 = CameraShake
function L1_6600(A0_6604, A1_6605)
  g_gameRules:ClientViewShake(A0_6604.Properties.vector_Position, nil, 0, A0_6604.Properties.fRadius, A0_6604.Properties.fStrength, A0_6604.Properties.fDuration, A0_6604.Properties.fFrequency)
end
L0_6599.Event_Shake = L1_6600
L0_6599 = CameraShake
L1_6600 = {}
L2_6601 = {}
L2_6601.Shake = {
  CameraShake.Event_Shake,
  "bool"
}
L1_6600.Inputs = L2_6601
L2_6601 = {}
L1_6600.Outputs = L2_6601
L0_6599.FlowEvents = L1_6600
