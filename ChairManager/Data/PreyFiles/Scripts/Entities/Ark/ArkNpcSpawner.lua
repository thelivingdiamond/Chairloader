local L0_4401, L1_4402, L2_4403
L0_4401 = {}
L1_4402 = {}
L1_4402.sNpcArchetype = ""
L1_4402.bSpawnOnGameStart = 0
L1_4402.bSpawnCorpse = 0
L1_4402.bSpawnDormant = 0
L1_4402.bSpawnBroken = 0
L1_4402.bRigorMortis = 0
L1_4402.bSpawnAlwaysUpdate = 0
L1_4402.pose_PoseAnim = ""
L0_4401.Properties = L1_4402
L1_4402 = {}
L1_4402.roomContainer_wanderRoomsContainer = ""
L2_4403 = {}
L2_4403.fPlayerApproachDistanceNear = -1
L2_4403.fPlayerApproachDistanceMedium = -1
L2_4403.fPlayerApproachDistanceFar = -1
L2_4403.fPlayerApproachCDNear = -1
L2_4403.fPlayerApproachCDMedium = -1
L2_4403.fPlayerApproachCDFar = -1
L2_4403.fPlayerLoiterDistance = -1
L2_4403.fPlayerLoiterCD = -1
L1_4402.ArkDialogOverride = L2_4403
L0_4401.PropertiesInstance = L1_4402
L1_4402 = {}
L1_4402.Icon = "User.bmp"
L1_4402.IconOnTop = 1
L0_4401.Editor = L1_4402
ArkNpcSpawner = L0_4401
L0_4401 = ArkNpcSpawner
function L1_4402(A0_4404)
  BroadcastEvent(A0_4404, "Spawn")
end
L0_4401.Event_Spawn = L1_4402
L0_4401 = ArkNpcSpawner
L1_4402 = {}
L2_4403 = {}
L2_4403.Spawn = {
  ArkNpcSpawner.Event_Spawn,
  "void"
}
L1_4402.Inputs = L2_4403
L2_4403 = {}
L2_4403.Succeeded = "bool"
L2_4403.SpawnedEntityId = "int"
L2_4403.Failed = "bool"
L1_4402.Outputs = L2_4403
L0_4401.FlowEvents = L1_4402
