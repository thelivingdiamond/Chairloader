Script.ReloadScript("Scripts/Entities/AI/AIWave.lua")
ActiveTerritories = {}
ActiveWaves = {}
AITerritory = {
  type = "AITerritory",
  Editor = {
    Icon = "territory.bmp"
  },
  liveAIs = {},
  deadAIs = {},
  activeWaves = {},
  historyWaves = {},
  nActiveCount = 0,
  nBodyCount = 0
}
function AddToTerritoryAndWave(A0_2650)
  if GetAIWave(A0_2650) then
    GetAIWave(A0_2650):Add(A0_2650)
  end
  if GetAITerritory(A0_2650) then
    GetAITerritory(A0_2650):Add(A0_2650)
  end
end
function NotifyDeathToTerritoryAndWave(A0_2651)
  Script.SetTimerForFunction(3000, "DeferredNotifyDeathToTerritoryAndWave", A0_2651)
end
function DeferredNotifyDeathToTerritoryAndWave(A0_2652)
  if A0_2652 and type(A0_2652) == "table" then
    if GetAIWave(A0_2652) then
      GetAIWave(A0_2652):NotifyDeath(A0_2652)
    end
    if GetAITerritory(A0_2652) then
      GetAITerritory(A0_2652):NotifyDeath(A0_2652)
    end
  end
end
function GetAITerritory(A0_2653)
  local L1_2654
  L1_2654 = A0_2653.AI
  L1_2654 = L1_2654.TerritoryShape
  return GetAITerritoryFromName(L1_2654)
end
function GetAITerritoryFromName(A0_2655)
  if A0_2655 then
    return System.GetEntityByName(A0_2655)
  end
  return nil
end
function UpdateTerritoriesActiveCounts(A0_2656)
  local L1_2657, L2_2658, L3_2659, L4_2660
  for L4_2660, _FORV_5_ in L1_2657(L2_2658) do
    if System.GetEntityByName(L4_2660) then
      System.GetEntityByName(L4_2660):UpdateActiveCount()
    end
  end
end
function AITerritory.IsWaveEnabling(A0_2661)
  local L1_2662, L2_2663, L3_2664, L4_2665
  for L4_2665, _FORV_5_ in L1_2662(L2_2663) do
    if System.GetEntity(L4_2665) and System.GetEntity(L4_2665):IsEnabling() then
      return true
    end
  end
  return L1_2662
end
function AITerritory.UpdateWavesActiveCounts(A0_2666, A1_2667)
  local L2_2668, L3_2669, L4_2670, L5_2671, L6_2672, L7_2673
  L2_2668 = Set
  L2_2668 = L2_2668.New
  L2_2668 = L2_2668()
  L3_2669 = 0
  for L7_2673, _FORV_8_ in L4_2670(L5_2671) do
    if System.GetEntity(L7_2673) then
      System.GetEntity(L7_2673):UpdateActiveCount(A1_2667)
      L3_2669 = L3_2669 + System.GetEntity(L7_2673):GetPoolQueueCount()
      if 0 >= System.GetEntity(L7_2673):GetActiveCount() then
        Set.Add(L2_2668, L7_2673)
      end
    end
  end
  for L7_2673, _FORV_8_ in L4_2670(L5_2671) do
    Set.Remove(A0_2666.activeWaves, L7_2673)
  end
  return L3_2669
end
function AITerritory.ReturnWavesBookmarkedAI(A0_2674, A1_2675)
  local L2_2676, L3_2677, L4_2678, L5_2679
  for L5_2679, _FORV_6_ in L2_2676(L3_2677) do
    if System.GetEntity(L5_2679) and System.GetEntity(L5_2679).ReturnBookmarkedAI then
      System.GetEntity(L5_2679):ReturnBookmarkedAI()
    end
  end
end
function AITerritory.ResetWavesBookmarkedAI(A0_2680, A1_2681)
  local L2_2682, L3_2683, L4_2684, L5_2685
  for L5_2685, _FORV_6_ in L2_2682(L3_2683) do
    if System.GetEntity(L5_2685) and System.GetEntity(L5_2685).ResetBookmarkedAI then
      System.GetEntity(L5_2685):ResetBookmarkedAI()
    end
  end
end
function AITerritory.PrepareWavesBookmarkedAI(A0_2686)
  local L1_2687, L2_2688, L3_2689, L4_2690
  for L4_2690, _FORV_5_ in L1_2687(L2_2688) do
    if System.GetEntity(L4_2690) and System.GetEntity(L4_2690).PrepareBookmarkedAI and ActiveWaves[System.GetEntity(L4_2690).GetName()] then
      System.GetEntity(L4_2690):PrepareBookmarkedAI()
    end
  end
end
function AITerritory.Event_Disable(A0_2691)
  local L1_2692, L2_2693, L3_2694, L4_2695, L5_2696, L6_2697, L7_2698
  L1_2692 = A0_2691.GetName
  L1_2692 = L1_2692(L2_2693)
  if L2_2693 then
    for L5_2696, L6_2697 in L2_2693(L3_2694) do
      L7_2698 = System
      L7_2698 = L7_2698.GetEntity
      L7_2698 = L7_2698(L5_2696)
      if L7_2698 and A0_2691:CheckAlive(L7_2698) and L7_2698:IsActive() then
        L7_2698:Event_Disable()
      end
    end
    L2_2693(L3_2694)
    L2_2693[L1_2692] = false
    L2_2693(L3_2694, L4_2695)
    L2_2693(L3_2694)
  end
end
function AITerritory.Event_Enable(A0_2699)
  if not ActiveTerritories[A0_2699:GetName()] then
    ActiveTerritories[A0_2699:GetName()] = true
    A0_2699:PrepareWavesBookmarkedAI()
    Script.SetTimerForFunction(500, "DelayedEvent_Enable", A0_2699)
    A0_2699:UpdateActiveCount()
  end
end
function DelayedEvent_Enable(A0_2700)
  local L1_2701, L2_2702, L3_2703, L4_2704, L5_2705, L6_2706
  if A0_2700 then
    if L1_2701 == "table" then
      L1_2701(L2_2702, L3_2703)
      for L4_2704, L5_2705 in L1_2701(L2_2702) do
        L6_2706 = System
        L6_2706 = L6_2706.GetEntity
        L6_2706 = L6_2706(L4_2704)
        if L6_2706 and A0_2700:CheckAlive(L6_2706) and (not L6_2706.AI.Wave or ActiveWaves[L6_2706.AI.Wave]) and not L6_2706:IsActive() then
          L6_2706:Event_Enable()
        end
      end
    end
  end
end
function AITerritory.Event_Kill(A0_2707)
  local L1_2708, L2_2709, L3_2710, L4_2711, L5_2712, L6_2713, L7_2714
  L1_2708 = A0_2707.GetName
  L1_2708 = L1_2708(L2_2709)
  if L2_2709 then
    for L5_2712, L6_2713 in L2_2709(L3_2710) do
      L7_2714 = System
      L7_2714 = L7_2714.GetEntity
      L7_2714 = L7_2714(L5_2712)
      if L7_2714 and A0_2707:CheckAlive(L7_2714) and L7_2714:IsActive() then
        L7_2714:Event_Kill()
      end
    end
  end
end
function AITerritory.Event_Spawn(A0_2715)
  local L1_2716, L2_2717, L3_2718, L4_2719, L5_2720, L6_2721, L7_2722, L8_2723, L9_2724
  L1_2716 = false
  L2_2717 = false
  L3_2718 = A0_2715.GetName
  L3_2718 = L3_2718(L4_2719)
  if not L4_2719 then
    L4_2719[L3_2718] = true
    L4_2719(L5_2720, L6_2721)
    for L7_2722, L8_2723 in L4_2719(L5_2720) do
      L9_2724 = System
      L9_2724 = L9_2724.GetEntity
      L9_2724 = L9_2724(L7_2722)
      if L9_2724 and A0_2715:CheckAlive(L9_2724) and (not L9_2724.AI.Wave or ActiveWaves[L9_2724.AI.Wave]) and not L9_2724:IsActive() then
        L9_2724:Event_Enable()
        L1_2716 = true
      end
    end
  end
  for L7_2722, L8_2723 in L4_2719(L5_2720) do
    L9_2724 = System
    L9_2724 = L9_2724.GetEntity
    L9_2724 = L9_2724(L7_2722)
    if L9_2724 and not L9_2724.AI.Wave and (not L9_2724.whoSpawnedMe or not L9_2724.whoSpawnedMe.spawnedEntity) then
      L9_2724:Event_Spawn()
      L2_2717 = true
      Set.Remove(A0_2715.deadAIs, L9_2724.id)
    end
  end
  if L1_2716 or L2_2717 then
    L4_2719(L5_2720)
    L7_2722 = A0_2715
    L4_2719(L5_2720, L6_2721, L7_2722)
  end
end
function DelayedBroadcastEventSpawned(A0_2725)
  if A0_2725 and type(A0_2725) == "table" then
    BroadcastEvent(A0_2725, "Spawned")
  end
end
function AITerritory.Event_DisableAndClear(A0_2726)
  local L1_2727, L2_2728, L3_2729, L4_2730, L5_2731
  L1_2727 = A0_2726.GetName
  L1_2727 = L1_2727(L2_2728)
  for L5_2731, _FORV_6_ in L2_2728(L3_2729) do
    if System.GetEntity(L5_2731) then
      System.GetEntity(L5_2731):Event_DisableAndClear()
    end
  end
  L2_2728[L1_2727] = false
  L2_2728(L3_2729, L4_2730)
  L2_2728(L3_2729)
end
function AITerritory.OnInit(A0_2732)
  A0_2732:OnReset()
end
function AITerritory.OnLoad(A0_2733, A1_2734)
  ActiveTerritories[A0_2733:GetName()] = A1_2734.bIsActive
  A0_2733.liveAIs = Set.DeserializeEntities(A1_2734.liveAIs)
  A0_2733.deadAIs = Set.DeserializeEntities(A1_2734.deadAIs)
  A0_2733.activeWaves = Set.DeserializeEntities(A1_2734.activeWaves)
  A0_2733.historyWaves = Set.DeserializeEntities(A1_2734.historyWaves)
  A0_2733.nActiveCount = A1_2734.nActiveCount
  A0_2733.nBodyCount = A1_2734.nBodyCount
end
function AITerritory.OnReset(A0_2735)
  ActiveTerritories[A0_2735:GetName()] = false
  A0_2735.liveAIs = Set.New()
  A0_2735.deadAIs = Set.New()
  A0_2735.activeWaves = Set.New()
  A0_2735.historyWaves = Set.New()
  A0_2735.nActiveCount = 0
  A0_2735.nBodyCount = 0
end
function AITerritory.OnSave(A0_2736, A1_2737)
  A1_2737.bIsActive = ActiveTerritories[A0_2736:GetName()]
  A1_2737.liveAIs = Set.SerializeEntities(A0_2736.liveAIs)
  A1_2737.deadAIs = Set.SerializeEntities(A0_2736.deadAIs)
  A1_2737.activeWaves = Set.SerializeEntities(A0_2736.activeWaves)
  A1_2737.historyWaves = Set.SerializeEntities(A0_2736.historyWaves)
  A1_2737.nActiveCount = A0_2736.nActiveCount
  A1_2737.nBodyCount = A0_2736.nBodyCount
end
function AITerritory.Add(A0_2738, A1_2739)
  local L2_2740, L3_2741
  L3_2741 = A0_2738
  L2_2740 = A0_2738.GetName
  L2_2740 = L2_2740(L3_2741)
  L3_2741 = A1_2739.AI
  L3_2741 = L3_2741.TerritoryShape
  if L2_2740 == L3_2741 then
    L3_2741 = A1_2739.AI
    L3_2741 = L3_2741.Wave
    if L3_2741 and System.GetEntityByName(L3_2741) then
      Set.Add(A0_2738.activeWaves, System.GetEntityByName(L3_2741).id)
      Set.Add(A0_2738.historyWaves, System.GetEntityByName(L3_2741).id)
    end
    if A1_2739:IsDead() then
      Set.Add(A0_2738.deadAIs, A1_2739.id)
    elseif not Set.Get(A0_2738.deadAIs, A1_2739.id) then
      Set.Add(A0_2738.liveAIs, A1_2739.id)
      if A1_2739:IsActive() and ActiveTerritories[L2_2740] then
        A0_2738:UpdateActiveCount()
      else
        A1_2739:Event_Disable()
      end
    end
  end
end
function AITerritory.NotifyDeath(A0_2742, A1_2743)
  if Set.Get(A0_2742.liveAIs, A1_2743.id) then
    Set.Remove(A0_2742.liveAIs, A1_2743.id)
    Set.Add(A0_2742.deadAIs, A1_2743.id)
    A0_2742:UpdateActiveCount(true)
    A0_2742.nBodyCount = A0_2742.nBodyCount + 1
    A0_2742:ActivateOutput("BodyCount", A0_2742.nBodyCount)
  end
end
function WaveAllowActorRemoval(A0_2744)
  if GetAIWave(A0_2744) then
    return GetAIWave(A0_2744):AllowActorRemoval(A0_2744)
  else
    return true
  end
end
function AITerritory.UpdateActiveCount(A0_2745, A1_2746)
  local L2_2747, L3_2748, L4_2749, L5_2750, L6_2751, L7_2752, L8_2753, L9_2754
  L3_2748 = A0_2745
  L2_2747 = A0_2745.IsWaveEnabling
  L2_2747 = L2_2747(L3_2748)
  if L2_2747 then
    return
  end
  L3_2748 = A0_2745
  L2_2747 = A0_2745.GetName
  L2_2747 = L2_2747(L3_2748)
  L3_2748 = A0_2745.UpdateWavesActiveCounts
  L3_2748 = L3_2748(L4_2749, L5_2750)
  if L4_2749 then
    for L7_2752, L8_2753 in L4_2749(L5_2750) do
      L9_2754 = System
      L9_2754 = L9_2754.GetEntity
      L9_2754 = L9_2754(L7_2752)
      if L9_2754 and A0_2745:CheckAlive(L9_2754) and L9_2754:IsActive() then
        L3_2748 = L3_2748 + 1
      end
    end
  end
  if L3_2748 ~= L4_2749 then
    A0_2745.nActiveCount = L3_2748
    L7_2752 = A0_2745.nActiveCount
    L4_2749(L5_2750, L6_2751, L7_2752)
    if A1_2746 then
      if L4_2749 == 0 then
        L4_2749(L5_2750, L6_2751)
      end
    end
  end
end
function AITerritory.CheckAlive(A0_2755, A1_2756)
  if A1_2756:IsDead() then
    A0_2755:NotifyDeath(A1_2756)
    return false
  end
  return true
end
function AITerritory.OnHidden(A0_2757)
  A0_2757:ResetWavesBookmarkedAI()
end
AITerritory.FlowEvents = {
  Inputs = {
    Disable = {
      AITerritory.Event_Disable,
      "bool"
    },
    Enable = {
      AITerritory.Event_Enable,
      "bool"
    },
    Kill = {
      AITerritory.Event_Kill,
      "bool"
    },
    Spawn = {
      AITerritory.Event_Spawn,
      "bool"
    },
    DisableAndClear = {
      AITerritory.Event_DisableAndClear,
      "bool"
    }
  },
  Outputs = {
    ActiveCount = "int",
    BodyCount = "int",
    Dead = "bool",
    Disabled = "bool",
    Enabled = "bool",
    Spawned = "bool"
  }
}
