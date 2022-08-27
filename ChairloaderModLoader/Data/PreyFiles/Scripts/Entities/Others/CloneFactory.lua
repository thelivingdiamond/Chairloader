local L0_6621, L1_6622, L2_6623, L3_6624, L4_6625, L5_6626
L0_6621 = {
  L1_6622,
  L2_6623,
  L3_6624
}
L2_6623.Radius = 1
L2_6623.strSourceEntity = ""
L2_6623.strDestEntity = ""
L2_6623.bSafetyLock = 1
L2_6623.groupid = -1
L2_6623.bConnectOnDeath = 1
L2_6623.bMaterial = 0
L1_6622.Properties = L2_6623
L2_6623.Icon = "territory.bmp"
L1_6622.Editor = L2_6623
L2_6623.x = 0
L2_6623.y = 0
L2_6623.z = 0
L1_6622.myLocation = L2_6623
L2_6623.x = 0
L2_6623.y = 0
L2_6623.z = 0
L1_6622.spawnLocation = L2_6623
L2_6623.x = 1
L2_6623.y = 0
L2_6623.z = 0
L1_6622.spawnOrientation = L2_6623
CloneFactory = L1_6622
for L4_6625, L5_6626 in L1_6622(L2_6623) do
  CloneFactory.Properties["bClone" .. L5_6626] = 1
end
L1_6622.OnSpawn = L2_6623
L1_6622.OnReset = L2_6623
L1_6622.Clone = L2_6623
L1_6622.Event_Clone = L2_6623
L1_6622.Event_CloneDied = L2_6623
L4_6625 = {L5_6626, "bool"}
L5_6626 = CloneFactory
L5_6626 = L5_6626.Event_Clone
L3_6624.Clone = L4_6625
L4_6625 = {L5_6626, "bool"}
L5_6626 = CloneFactory
L5_6626 = L5_6626.Event_CloneDied
L3_6624.CloneDied = L4_6625
L2_6623.Inputs = L3_6624
L4_6625 = {L5_6626, "bool"}
L5_6626 = CloneFactory
L5_6626 = L5_6626.Event_Clone
L3_6624.Clone = L4_6625
L4_6625 = {L5_6626, "bool"}
L5_6626 = CloneFactory
L5_6626 = L5_6626.Event_CloneDied
L3_6624.CloneDied = L4_6625
L2_6623.Outputs = L3_6624
L1_6622.FlowEvents = L2_6623
