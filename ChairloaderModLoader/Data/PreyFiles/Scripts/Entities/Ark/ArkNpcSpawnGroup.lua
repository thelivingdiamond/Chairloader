local L0_4405, L1_4406, L2_4407
L0_4405 = {}
L1_4406 = {}
L1_4406.bSpawnOnGameStart = 0
L0_4405.Properties = L1_4406
L1_4406 = {}
L1_4406.Icon = "spawngroup.bmp"
L1_4406.IconOnTop = 1
L0_4405.Editor = L1_4406
ArkNpcSpawnGroup = L0_4405
L0_4405 = ArkNpcSpawnGroup
function L1_4406(A0_4408)
  BroadcastEvent(A0_4408, "OnInit")
end
L0_4405.OnInit = L1_4406
L0_4405 = ArkNpcSpawnGroup
function L1_4406(A0_4409)
  BroadcastEvent(A0_4409, "Spawn")
end
L0_4405.Event_Spawn = L1_4406
L0_4405 = ArkNpcSpawnGroup
L1_4406 = {}
L2_4407 = {}
L2_4407.Spawn = {
  ArkNpcSpawnGroup.Event_Spawn,
  "void"
}
L1_4406.Inputs = L2_4407
L2_4407 = {}
L2_4407.SpawnRequested = "bool"
L1_4406.Outputs = L2_4407
L0_4405.FlowEvents = L1_4406
