local L0_4397, L1_4398, L2_4399
L0_4397 = {}
L1_4398 = {}
L1_4398.sNpcArchetype = ""
L1_4398.bSpawnOnGameStart = 0
L1_4398.bSpawnAlwaysUpdate = 0
L0_4397.Properties = L1_4398
L1_4398 = {}
L1_4398.roomContainer_wanderRoomsContainer = ""
L2_4399 = {}
L2_4399.fPlayerApproachDistanceNear = -1
L2_4399.fPlayerApproachDistanceMedium = -1
L2_4399.fPlayerApproachDistanceFar = -1
L2_4399.fPlayerApproachCDNear = -1
L2_4399.fPlayerApproachCDMedium = -1
L2_4399.fPlayerApproachCDFar = -1
L2_4399.fPlayerLoiterDistance = -1
L2_4399.fPlayerLoiterCD = -1
L1_4398.ArkDialogOverride = L2_4399
L0_4397.PropertiesInstance = L1_4398
L1_4398 = {}
L1_4398.Icon = "Cystoid.bmp"
L1_4398.IconOnTop = 1
L0_4397.Editor = L1_4398
ArkNpcSpawnCystoidNest = L0_4397
L0_4397 = ArkNpcSpawnCystoidNest
function L1_4398(A0_4400)
  BroadcastEvent(A0_4400, "Spawn")
end
L0_4397.Event_Spawn = L1_4398
L0_4397 = ArkNpcSpawnCystoidNest
L1_4398 = {}
L2_4399 = {}
L2_4399.Spawn = {
  ArkNpcSpawnCystoidNest.Event_Spawn,
  "void"
}
L1_4398.Inputs = L2_4399
L2_4399 = {}
L2_4399.Succeeded = "bool"
L2_4399.SpawnedEntityId = "int"
L2_4399.Failed = "bool"
L1_4398.Outputs = L2_4399
L0_4397.FlowEvents = L1_4398
