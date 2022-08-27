local L0_2591, L1_2592, L2_2593, L3_2594
L0_2591 = {}
L1_2592 = {}
L0_2591.Client = L1_2592
L1_2592 = {}
L0_2591.Server = L1_2592
L1_2592 = {}
L1_2592.Model = "Editor/Objects/Particles.cgf"
L1_2592.Icon = "SpawnPoint.bmp"
L1_2592.DisplayArrow = 1
L0_2591.Editor = L1_2592
L1_2592 = {}
L1_2592.NumUnits = 2
L1_2592.Limit = 4
L1_2592.bLimitStop = 1
L1_2592.bDoVisCheck = 0
L0_2591.Properties = L1_2592
L0_2591.unitsCounter = 0
L0_2591.totalUnitsCounter = 0
L0_2591.isEnabled = 0
L1_2592 = {}
L0_2591.visDummys = L1_2592
L1_2592 = {}
L0_2591.spawnedIds = L1_2592
L0_2591.spawnedIdsSize = 0
AISpawner = L0_2591
L0_2591 = AISpawner
L0_2591 = L0_2591.Server
function L1_2592(A0_2595)
  AI.LogEvent("AISpawner.Server:OnInit >>>")
  A0_2595:OnReset()
  A0_2595:CreateDummy()
end
L0_2591.OnInit = L1_2592
L0_2591 = AISpawner
L0_2591 = L0_2591.Server
function L1_2592(A0_2596)
  A0_2596:RemoveDummy()
end
L0_2591.OnShutDown = L1_2592
L0_2591 = AISpawner
function L1_2592(A0_2597)
  A0_2597:CreateDummy()
end
L0_2591.OnPropertyChange = L1_2592
L0_2591 = AISpawner
function L1_2592(A0_2598)
  A0_2598.unitsCounter = 0
  A0_2598.totalUnitsCounter = 0
  A0_2598.isEnabled = 0
  A0_2598.spawnedIds = {}
  A0_2598.spawnedIdsSize = 0
end
L0_2591.OnReset = L1_2592
L0_2591 = AISpawner
function L1_2592(A0_2599, A1_2600)
  local L2_2601
  L2_2601 = A0_2599.unitsCounter
  A1_2600.unitsCounter = L2_2601
  L2_2601 = A0_2599.totalUnitsCounter
  A1_2600.totalUnitsCounter = L2_2601
  L2_2601 = A0_2599.isEnabled
  A1_2600.isEnabled = L2_2601
  L2_2601 = A0_2599.spawnedIds
  A1_2600.spawnedIds = L2_2601
  L2_2601 = A0_2599.spawnedIdsSize
  A1_2600.spawnedIdsSize = L2_2601
end
L0_2591.OnSave = L1_2592
L0_2591 = AISpawner
function L1_2592(A0_2602, A1_2603)
  local L2_2604
  L2_2604 = A1_2603.unitsCounter
  A0_2602.unitsCounter = L2_2604
  L2_2604 = A1_2603.totalUnitsCounter
  A0_2602.totalUnitsCounter = L2_2604
  L2_2604 = A1_2603.isEnabled
  A0_2602.isEnabled = L2_2604
  L2_2604 = A1_2603.spawnedIds
  A0_2602.spawnedIds = L2_2604
  L2_2604 = A1_2603.spawnedIdsSize
  A0_2602.spawnedIdsSize = L2_2604
end
L0_2591.OnLoad = L1_2592
L0_2591 = AISpawner
function L1_2592(A0_2605)
  A0_2605.unitsCounter = A0_2605.unitsCounter - 1
  if A0_2605.isEnabled == 0 then
    return
  end
  if A0_2605.unitsCounter < A0_2605.Properties.NumUnits then
    A0_2605:SpawnInitially()
  end
end
L0_2591.UnitDown = L1_2592
L0_2591 = AISpawner
function L1_2592(A0_2606, A1_2607)
  if System.GetEntity(A1_2607) == nil then
    return
  end
  System.GetEntity(A1_2607).spawnedEntity = nil
  if System.GetEntity(A1_2607).Event_SpawnKeep then
    System.GetEntity(A1_2607):Event_SpawnKeep()
  elseif System.GetEntity(A1_2607).SpawnCopyAndLoad then
    System.GetEntity(A1_2607):SpawnCopyAndLoad()
  end
  if System.GetEntity(A1_2607).spawnedEntity and System.GetEntity(System.GetEntity(A1_2607).spawnedEntity) then
    if System.GetEntity(A1_2607).PropertiesInstance.bAutoDisable ~= 1 then
      AI.AutoDisable(System.GetEntity(System.GetEntity(A1_2607).spawnedEntity).id, 0)
    end
    if System.GetEntity(System.GetEntity(A1_2607).spawnedEntity).class == "Scout" then
      AI.AutoDisable(System.GetEntity(System.GetEntity(A1_2607).spawnedEntity).id, 0)
    end
    System.GetEntity(System.GetEntity(A1_2607).spawnedEntity).AI.spawnerListenerId = A0_2606.id
    A0_2606.unitsCounter = A0_2606.unitsCounter + 1
    A0_2606.totalUnitsCounter = A0_2606.totalUnitsCounter + 1
    A0_2606:FindSpawnReinfPoint()
    System.GetEntity(System.GetEntity(A1_2607).spawnedEntity).AI.reinfPoint = g_SignalData.ObjectName
    System.GetEntity(System.GetEntity(A1_2607).spawnedEntity):SetName(System.GetEntity(System.GetEntity(A1_2607).spawnedEntity):GetName() .. "_spawned")
    AI.Signal(SIGNALFILTER_SENDER, 0, "NEW_SPAWN", System.GetEntity(System.GetEntity(A1_2607).spawnedEntity).id, g_SignalData)
    A0_2606.spawnedIds[A0_2606.spawnedIdsSize] = System.GetEntity(System.GetEntity(A1_2607).spawnedEntity).id
    A0_2606.spawnedIdsSize = A0_2606.spawnedIdsSize + 1
  end
end
L0_2591.SpawnUnit = L1_2592
L0_2591 = AISpawner
function L1_2592(A0_2608)
  local L1_2609, L2_2610
  L1_2609 = A0_2608.CountLinks
  L1_2609 = L1_2609(L2_2610)
  if L1_2609 < 1 then
    return L2_2610
  end
  if L2_2610 == 0 then
    while true do
      if A0_2608:GetLink(L2_2610) then
        AI.LogEvent(" >>>FindSpawnProtoUnitIdx checking " .. L2_2610)
        if AI.GetTypeOf(A0_2608:GetLink(L2_2610).id) ~= AIOBJECT_WAYPOINT then
          return A0_2608:GetLink(L2_2610).id
        end
      end
      if L1_2609 == 1 then
        return
      end
    end
  else
    for _FORV_5_, _FORV_6_ in L2_2610(A0_2608.visDummys) do
      if _FORV_6_:UnSeenFrames() > 100 then
        return _FORV_5_
      end
    end
  end
  return L2_2610
end
L0_2591.FindSpawnProtoUnitId = L1_2592
L0_2591 = AISpawner
function L1_2592(A0_2611)
  local L1_2612, L2_2613, L3_2614, L4_2615, L5_2616
  L1_2612 = Log
  L2_2613 = "FindSpawnReinfPoint"
  L1_2612(L2_2613)
  L2_2613 = A0_2611
  L1_2612 = A0_2611.GetPos
  L1_2612 = L1_2612(L2_2613)
  L2_2613 = g_localActor
  if L2_2613 then
    L2_2613 = g_localActor
    L3_2614 = L2_2613
    L2_2613 = L2_2613.GetPos
    L2_2613 = L2_2613(L3_2614)
    L1_2612 = L2_2613
  end
  L2_2613 = 100000000
  L3_2614 = 0
  L4_2615 = 0
  L5_2616 = A0_2611.GetLink
  L5_2616 = L5_2616(A0_2611, L4_2615)
  while L5_2616 do
    if AI.GetTypeOf(L5_2616.id) == AIOBJECT_WAYPOINT and L2_2613 > DistanceSqVectors(L1_2612, L5_2616:GetPos()) then
      L2_2613 = DistanceSqVectors(L1_2612, L5_2616:GetPos())
      L3_2614 = L4_2615
    end
    L4_2615 = L4_2615 + 1
    L5_2616 = A0_2611:GetLink(L4_2615)
  end
  L5_2616 = A0_2611:GetLink(L3_2614)
  g_SignalData.ObjectName = L5_2616:GetName()
  Log("FindSpawnReinfPoint end")
end
L0_2591.FindSpawnReinfPoint = L1_2592
L0_2591 = AISpawner
function L1_2592(A0_2617)
  local L1_2618
  L1_2618 = Log
  L1_2618("SpawnInitially")
  while true do
    L1_2618 = A0_2617.unitsCounter
    if L1_2618 < A0_2617.Properties.NumUnits then
      L1_2618 = A0_2617.totalUnitsCounter
      if L1_2618 == A0_2617.Properties.Limit then
        L1_2618 = A0_2617.Event_Limit
        L1_2618(A0_2617)
        L1_2618 = A0_2617.isEnabled
        if L1_2618 == 0 then
          return
        end
      end
      L1_2618 = A0_2617.FindSpawnProtoUnitId
      L1_2618 = L1_2618(A0_2617)
      if L1_2618 == 0 then
        AI.LogEvent(" >>>Spawning initially : Can't find valid spawn proto/point")
        return
      end
      A0_2617:SpawnUnit(L1_2618)
    end
  end
  L1_2618 = Log
  L1_2618("SpawnInitially end")
end
L0_2591.SpawnInitially = L1_2592
L0_2591 = AISpawner
function L1_2592(A0_2619)
  for _FORV_4_, _FORV_5_ in pairs(A0_2619.visDummys) do
    System.RemoveEntity(_FORV_5_.id)
  end
  A0_2619.visDummys = {}
end
L0_2591.RemoveDummy = L1_2592
L0_2591 = AISpawner
function L1_2592(A0_2620)
  local L1_2621, L2_2622, L3_2623, L4_2624, L5_2625, L6_2626, L7_2627, L8_2628, L9_2629
  L1_2621 = Log
  L2_2622 = "createdummy start"
  L1_2621(L2_2622)
  L2_2622 = A0_2620
  L1_2621 = A0_2620.RemoveDummy
  L1_2621(L2_2622)
  L1_2621 = A0_2620.Properties
  L1_2621 = L1_2621.bDoVisCheck
  if L1_2621 == 0 then
    return
  end
  L1_2621 = 0
  L3_2623 = A0_2620
  L2_2622 = A0_2620.GetLink
  L4_2624 = L1_2621
  L2_2622 = L2_2622(L3_2623, L4_2624)
  while L2_2622 do
    L3_2623 = AI
    L3_2623 = L3_2623.GetTypeOf
    L4_2624 = L2_2622.id
    L3_2623 = L3_2623(L4_2624)
    L4_2624 = AIOBJECT_WAYPOINT
    if L3_2623 ~= L4_2624 then
      L3_2623 = A0_2620
      L4_2624 = {}
      L4_2624.class = "Dummy"
      L6_2626 = L2_2622
      L5_2625 = L2_2622.GetPos
      L5_2625 = L5_2625(L6_2626)
      L4_2624.position = L5_2625
      L6_2626 = L2_2622
      L5_2625 = L2_2622.GetName
      L5_2625 = L5_2625(L6_2626)
      L6_2626 = "_VisDummy"
      L5_2625 = L5_2625 .. L6_2626
      L4_2624.name = L5_2625
      L5_2625 = System
      L5_2625 = L5_2625.SpawnEntity
      L6_2626 = L4_2624
      L5_2625 = L5_2625(L6_2626)
      L3_2623 = L5_2625
      L6_2626 = L3_2623
      L5_2625 = L3_2623.LoadObject
      L7_2627 = 0
      L8_2628 = "objects/box_nodraw.cgf"
      L5_2625(L6_2626, L7_2627, L8_2628)
      L6_2626 = L2_2622
      L5_2625 = L2_2622.GetLocalBBox
      L6_2626 = L5_2625(L6_2626)
      L8_2628 = L3_2623
      L7_2627 = L3_2623.SetLocalBBox
      L9_2629 = L5_2625
      L7_2627(L8_2628, L9_2629, L6_2626)
      L7_2627 = A0_2620.visDummys
      L8_2628 = L2_2622.id
      L7_2627[L8_2628] = L3_2623
    end
    L1_2621 = L1_2621 + 1
    L4_2624 = A0_2620
    L3_2623 = A0_2620.GetLink
    L5_2625 = L1_2621
    L3_2623 = L3_2623(L4_2624, L5_2625)
    L2_2622 = L3_2623
  end
  L3_2623 = Log
  L4_2624 = "createdummy end"
  L3_2623(L4_2624)
end
L0_2591.CreateDummy = L1_2592
L0_2591 = AISpawner
function L1_2592(A0_2630, A1_2631)
  A0_2630.isEnabled = 1
  A0_2630:SpawnInitially()
  BroadcastEvent(A0_2630, "Enable")
end
L0_2591.Event_Enable = L1_2592
L0_2591 = AISpawner
function L1_2592(A0_2632, A1_2633)
  A0_2632.isEnabled = 0
  BroadcastEvent(A0_2632, "Disable")
end
L0_2591.Event_Disable = L1_2592
L0_2591 = AISpawner
function L1_2592(A0_2634, A1_2635)
  if A0_2634.Properties.bLimitStop ~= 0 then
    A0_2634:Event_Disable()
  end
  BroadcastEvent(A0_2634, "Limit")
end
L0_2591.Event_Limit = L1_2592
L0_2591 = AISpawner
function L1_2592(A0_2636, A1_2637)
  local L2_2638, L3_2639, L4_2640, L5_2641, L6_2642
  for L5_2641, L6_2642 in L2_2638(L3_2639) do
    if System.GetEntity(L6_2642) then
      AI.AutoDisable(System.GetEntity(L6_2642).id, 1)
      if System.GetEntity(L6_2642).AutoDisablePassangers then
        System.GetEntity(L6_2642):AutoDisablePassangers(1)
      end
    end
  end
  L2_2638(L3_2639, L4_2640)
end
L0_2591.Event_AutoDisableOn = L1_2592
L0_2591 = AISpawner
function L1_2592(A0_2643, A1_2644)
  local L2_2645, L3_2646, L4_2647, L5_2648, L6_2649
  for L5_2648, L6_2649 in L2_2645(L3_2646) do
    if System.GetEntity(L6_2649) then
      AI.AutoDisable(System.GetEntity(L6_2649).id, 0)
      if System.GetEntity(L6_2649).AutoDisablePassangers then
        System.GetEntity(L6_2649):AutoDisablePassangers(0)
      end
    end
  end
  L2_2645(L3_2646, L4_2647)
end
L0_2591.Event_AutoDisableOff = L1_2592
L0_2591 = AISpawner
L1_2592 = {}
L2_2593 = {}
L3_2594 = {
  AISpawner.Event_Enable,
  "bool"
}
L2_2593.Enable = L3_2594
L3_2594 = {
  AISpawner.Event_Disable,
  "bool"
}
L2_2593.Disable = L3_2594
L3_2594 = {
  AISpawner.Event_AutoDisableOn,
  "bool"
}
L2_2593.AutoDisableOn = L3_2594
L3_2594 = {
  AISpawner.Event_AutoDisableOff,
  "bool"
}
L2_2593.AutoDisableOff = L3_2594
L1_2592.Inputs = L2_2593
L2_2593 = {}
L2_2593.Limit = "bool"
L1_2592.Outputs = L2_2593
L0_2591.FlowEvents = L1_2592
