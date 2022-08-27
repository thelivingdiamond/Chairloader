local L0_2959, L1_2960, L2_2961, L3_2962
L0_2959 = {}
L1_2960 = {}
L0_2959.Client = L1_2960
L1_2960 = {}
L0_2959.Server = L1_2960
L1_2960 = {}
L0_2959.PropertiesInstance = L1_2960
L1_2960 = {}
L1_2960.bUseEntity = 1
L2_2961 = {}
L2_2961.name = ""
L3_2962 = {}
L3_2962.x = 0
L3_2962.y = 0
L3_2962.z = 0
L2_2961.vOffset = L3_2962
L3_2962 = {}
L3_2962.x = 0
L3_2962.y = 0
L3_2962.z = 0
L2_2961.vRotation = L3_2962
L1_2960.ParticleFX = L2_2961
L0_2959.Properties = L1_2960
L1_2960 = {}
L1_2960.Icon = "TagPoint.bmp"
L0_2959.Editor = L1_2960
L1_2960 = {}
function L2_2961(A0_2963)
  GameAI.RegisterScanSpot(A0_2963.id)
end
L1_2960.OnStartGame = L2_2961
L0_2959.Server = L1_2960
function L1_2960(A0_2964)
  local L1_2965, L2_2966, L3_2967, L4_2968, L5_2969
  L1_2965 = A0_2964.CountLinks
  L1_2965 = L1_2965(L2_2966)
  for L5_2969 = 0, L1_2965 - 1 do
    if A0_2964.Properties.bUseEntity then
      A0_2964:GetLink(L5_2969):OnUsed()
    end
    if A0_2964.Properties.ParticleFX.name ~= "" then
      Particle.SpawnEffect(A0_2964.Properties.ParticleFX.name, SumVectors(A0_2964:GetLink(L5_2969):GetWorldPos(), A0_2964.Properties.ParticleFX.vOffset), A0_2964.Properties.ParticleFX.vRotation, 1)
    end
  end
  L5_2969 = true
  L2_2966(L3_2967, L4_2968, L5_2969)
end
L0_2959.OnScannedByDrone = L1_2960
ScanSpot = L0_2959
L0_2959 = ScanSpot
function L1_2960(A0_2970, A1_2971)
  GameAI.RegisterScanSpot(A0_2970.id)
end
L0_2959.Event_Enable = L1_2960
L0_2959 = ScanSpot
function L1_2960(A0_2972, A1_2973)
  GameAI.UnregisterScanSpot(A0_2972.id)
end
L0_2959.Event_Disable = L1_2960
L0_2959 = ScanSpot
L1_2960 = {}
L2_2961 = {}
L3_2962 = {
  ScanSpot.Event_Enable,
  "bool"
}
L2_2961.Enable = L3_2962
L3_2962 = {
  ScanSpot.Event_Disable,
  "bool"
}
L2_2961.Disable = L3_2962
L1_2960.Inputs = L2_2961
L2_2961 = {}
L2_2961.Scanned = "bool"
L1_2960.Outputs = L2_2961
L0_2959.FlowEvents = L1_2960
