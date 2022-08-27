local L0_4393, L1_4394, L2_4395
L0_4393 = {}
L1_4394 = {}
L1_4394.sNpcArchetype = "ArkNpcs.Cystoids.Cystoid"
L1_4394.bSpawnOnGameStart = 0
L1_4394.bSpawnAlwaysUpdate = 0
L0_4393.Properties = L1_4394
L1_4394 = {}
L1_4394.roomContainer_wanderRoomsContainer = ""
L2_4395 = {}
L2_4395.fPlayerApproachDistanceNear = -1
L2_4395.fPlayerApproachDistanceMedium = -1
L2_4395.fPlayerApproachDistanceFar = -1
L2_4395.fPlayerApproachCDNear = -1
L2_4395.fPlayerApproachCDMedium = -1
L2_4395.fPlayerApproachCDFar = -1
L2_4395.fPlayerLoiterDistance = -1
L2_4395.fPlayerLoiterCD = -1
L1_4394.ArkDialogOverride = L2_4395
L0_4393.PropertiesInstance = L1_4394
L1_4394 = {}
L1_4394.Icon = "Cystoid.bmp"
L1_4394.IconOnTop = 1
L0_4393.Editor = L1_4394
ArkNpcSpawnCystoid = L0_4393
L0_4393 = ArkNpcSpawnCystoid
function L1_4394(A0_4396)
  BroadcastEvent(A0_4396, "Spawn")
end
L0_4393.Event_Spawn = L1_4394
L0_4393 = ArkNpcSpawnCystoid
L1_4394 = {}
L2_4395 = {}
L2_4395.Spawn = {
  ArkNpcSpawnCystoid.Event_Spawn,
  "void"
}
L1_4394.Inputs = L2_4395
L2_4395 = {}
L2_4395.Succeeded = "bool"
L2_4395.SpawnedEntityId = "int"
L2_4395.Failed = "bool"
L1_4394.Outputs = L2_4395
L0_4393.FlowEvents = L1_4394
