local L0_2758, L1_2759, L2_2760, L3_2761
L0_2758 = {}
L0_2758.type = "AIWave"
L1_2759 = {}
L1_2759.Icon = "wave.bmp"
L0_2758.Editor = L1_2759
L1_2759 = {}
L0_2758.liveAIs = L1_2759
L1_2759 = {}
L0_2758.deadAIs = L1_2759
L1_2759 = {}
L0_2758.bookmarkAIs = L1_2759
L1_2759 = {}
L0_2758.toSpawnFromDeadBookmarks = L1_2759
L0_2758.nActiveCount = 0
L0_2758.nBodyCount = 0
L0_2758.nPoolQueueCount = 0
L0_2758.bEnableOnAdd = false
L0_2758.bIsEnabling = false
L0_2758.bIsPreparingBookmarks = false
L0_2758.bBookmarsHaveBeenPrepared = false
L0_2758.bDisabledAndCleared = false
AIWave = L0_2758
L0_2758 = {}
AIWaveBookmarkCache = L0_2758
function L0_2758(A0_2762)
  local L1_2763, L2_2764, L3_2765, L4_2766, L5_2767
  for L4_2766, L5_2767 in L1_2763(L2_2764) do
    if GetAIWaveFromName(L5_2767) and GetAIWaveFromName(L5_2767):GetName() == A0_2762 then
      GetAIWaveFromName(L5_2767):AddBookmarked(L4_2766)
      AIWaveBookmarkCache[L4_2766] = nil
    end
  end
end
ExecuteAIWaveBookmarkCache = L0_2758
function L0_2758(A0_2768, A1_2769)
  if GetAIWaveFromName(A1_2769) then
    GetAIWaveFromName(A1_2769):AddBookmarked(A0_2768)
  else
    AIWaveBookmarkCache[A0_2768] = A1_2769
  end
end
AddBookmarkedToWave = L0_2758
function L0_2758(A0_2770)
  local L1_2771
  L1_2771 = A0_2770.AI
  L1_2771 = L1_2771.Wave
  return GetAIWaveFromName(L1_2771)
end
GetAIWave = L0_2758
function L0_2758(A0_2772)
  if A0_2772 then
    return System.GetEntityByName(A0_2772)
  end
  return nil
end
GetAIWaveFromName = L0_2758
L0_2758 = AIWave
function L1_2759(A0_2773)
  local L1_2774, L2_2775, L3_2776, L4_2777, L5_2778, L6_2779, L7_2780, L8_2781, L9_2782
  A0_2773.bIsPreparingBookmarks = true
  L1_2774 = A0_2773.bBookmarsHaveBeenPrepared
  L1_2774 = not L1_2774
  if L2_2775 <= 0 then
    for L5_2778, L6_2779 in L2_2775(L3_2776) do
      L7_2780 = System
      L7_2780 = L7_2780.GetEntity
      L8_2781 = L5_2778
      L7_2780 = L7_2780(L8_2781)
      L8_2781 = Set
      L8_2781 = L8_2781.Get
      L9_2782 = A0_2773.liveAIs
      L8_2781 = L8_2781(L9_2782, L5_2778)
      if not L7_2780 and (L8_2781 or L1_2774) then
        L9_2782 = System
        L9_2782 = L9_2782.PrepareEntityFromPool
        L9_2782 = L9_2782(L5_2778)
        if L9_2782 then
          L9_2782 = A0_2773.nPoolQueueCount
          L9_2782 = L9_2782 + 1
          A0_2773.nPoolQueueCount = L9_2782
        else
          L9_2782 = A0_2773.GetName
          L9_2782 = L9_2782(A0_2773)
          System.Warning("Input Enable of AI Wave " .. L9_2782 .. " failed to prepare pooled entity")
        end
      end
    end
  end
  A0_2773.bBookmarsHaveBeenPrepared = true
  A0_2773.bIsPreparingBookmarks = false
end
L0_2758.PrepareBookmarkedAI = L1_2759
L0_2758 = AIWave
function L1_2759(A0_2783)
  local L1_2784, L2_2785, L3_2786, L4_2787
  if L1_2784 > 0 then
    for L4_2787, _FORV_5_ in L1_2784(L2_2785) do
      System.ResetPoolEntity(L4_2787)
    end
  end
end
L0_2758.ResetBookmarkedAI = L1_2759
L0_2758 = AIWave
function L1_2759(A0_2788)
  local L1_2789, L2_2790, L3_2791, L4_2792, L5_2793, L6_2794, L7_2795, L8_2796, L9_2797
  L2_2790 = A0_2788
  L1_2789 = A0_2788.GetName
  L1_2789 = L1_2789(L2_2790)
  L2_2790 = A0_2788.bDisabledAndCleared
  if L2_2790 then
    L2_2790 = System
    L2_2790 = L2_2790.Warning
    L2_2790(L3_2791)
    return
  end
  L2_2790 = ActiveWaves
  L2_2790 = L2_2790[L1_2789]
  if L2_2790 then
    L2_2790 = Set
    L2_2790 = L2_2790.New
    L2_2790 = L2_2790()
    for L6_2794, L7_2795 in L3_2791(L4_2792) do
      L8_2796 = System
      L8_2796 = L8_2796.GetEntity
      L9_2797 = L6_2794
      L8_2796 = L8_2796(L9_2797)
      if L8_2796 then
        L9_2797 = A0_2788.CheckAlive
        L9_2797 = L9_2797(A0_2788, L8_2796)
        if L9_2797 then
          L9_2797 = L8_2796.IsActive
          L9_2797 = L9_2797(L8_2796)
          if L9_2797 then
            L9_2797 = Set
            L9_2797 = L9_2797.Get
            L9_2797 = L9_2797(A0_2788.bookmarkAIs, L6_2794)
            if not L9_2797 then
              L9_2797 = L8_2796.Event_Disable
              L9_2797(L8_2796)
            end
            L9_2797 = L8_2796.AI
            L9_2797 = L9_2797.TerritoryShape
            if L9_2797 then
              Set.Add(L2_2790, L9_2797)
            end
          end
        end
      end
    end
    L3_2791(L4_2792)
    L3_2791[L1_2789] = false
    L3_2791(L4_2792, L5_2793)
    L3_2791(L4_2792)
    L3_2791(L4_2792)
  end
end
L0_2758.Event_Disable = L1_2759
L0_2758 = AIWave
function L1_2759(A0_2798)
  local L1_2799, L2_2800, L3_2801, L4_2802
  for L4_2802, _FORV_5_ in L1_2799(L2_2800) do
    System.ReturnEntityToPool(L4_2802)
  end
end
L0_2758.ReturnBookmarkedAI = L1_2759
L0_2758 = AIWave
function L1_2759(A0_2803)
  local L1_2804, L2_2805, L3_2806, L4_2807, L5_2808, L6_2809, L7_2810, L8_2811, L9_2812
  L2_2805 = A0_2803
  L1_2804 = A0_2803.GetName
  L1_2804 = L1_2804(L2_2805)
  L2_2805 = A0_2803.bDisabledAndCleared
  if L2_2805 then
    L2_2805 = System
    L2_2805 = L2_2805.Warning
    L2_2805(L3_2806)
    return
  end
  A0_2803.bIsEnabling = true
  L2_2805 = ActiveWaves
  L2_2805 = L2_2805[L1_2804]
  if not L2_2805 then
    L2_2805 = A0_2803.PrepareBookmarkedAI
    L2_2805(L3_2806)
    L2_2805 = false
    for L6_2809, L7_2810 in L3_2806(L4_2807) do
      L2_2805 = true
      L8_2811 = System
      L8_2811 = L8_2811.GetEntity
      L9_2812 = L6_2809
      L8_2811 = L8_2811(L9_2812)
      if L8_2811 then
        L9_2812 = A0_2803.CheckAlive
        L9_2812 = L9_2812(A0_2803, L8_2811)
        if L9_2812 then
          L9_2812 = L8_2811.AI
          L9_2812 = L9_2812.TerritoryShape
          if not L9_2812 or ActiveTerritories[L9_2812] then
            A0_2803:TryBecomeActive(L1_2804)
            if not L8_2811:IsActive() then
              A0_2803:EnableEntity(L8_2811)
            end
          elseif not L9_2812 then
            System.Warning("Input Enable of AI Wave " .. L1_2804 .. " about to fail : nil territory!")
          else
            System.Warning("Input Enable of AI Wave " .. L1_2804 .. " about to fail : territory " .. L9_2812 .. " is not active!")
          end
        end
      end
    end
    A0_2803.bIsEnabling = false
    if L3_2806 then
      L3_2806(L4_2807)
    elseif not L2_2805 then
      L6_2809 = ". It will be enabled as soon as an AI is added to it."
      L3_2806(L4_2807)
      A0_2803.bEnableOnAdd = true
    end
  end
  A0_2803.bIsEnabling = false
end
L0_2758.Event_Enable = L1_2759
L0_2758 = AIWave
function L1_2759(A0_2813)
  local L1_2814, L2_2815, L3_2816, L4_2817, L5_2818, L6_2819, L7_2820, L8_2821, L9_2822, L10_2823
  L2_2815 = A0_2813
  L1_2814 = A0_2813.GetName
  L1_2814 = L1_2814(L2_2815)
  L2_2815 = A0_2813.bDisabledAndCleared
  if L2_2815 then
    L2_2815 = System
    L2_2815 = L2_2815.Warning
    L3_2816 = "Wave: "
    L3_2816 = L3_2816 .. L4_2817 .. L5_2818
    L2_2815(L3_2816)
    return
  end
  A0_2813.bIsEnabling = true
  L2_2815 = false
  L3_2816 = false
  if not L4_2817 then
    L4_2817(L5_2818)
    for L7_2820, L8_2821 in L4_2817(L5_2818) do
      L9_2822 = System
      L9_2822 = L9_2822.GetEntity
      L10_2823 = L7_2820
      L9_2822 = L9_2822(L10_2823)
      if L9_2822 then
        L10_2823 = L9_2822.AI
        L10_2823 = L10_2823.TerritoryShape
        if not L10_2823 or ActiveTerritories[L9_2822.AI.TerritoryShape] then
          A0_2813:TryBecomeActive(L1_2814)
          if A0_2813:CheckAlive(L9_2822) then
            L2_2815 = true
            if not L9_2822:IsActive() then
              A0_2813:EnableEntity(L9_2822)
            end
          end
        end
      end
    end
  end
  A0_2813.bIsPreparingBookmarks = true
  for L7_2820, L8_2821 in L4_2817(L5_2818) do
    L9_2822 = System
    L9_2822 = L9_2822.GetEntity
    L10_2823 = L8_2821
    L9_2822 = L9_2822(L10_2823)
    if not L9_2822 then
      L10_2823 = Set
      L10_2823 = L10_2823.Set
      L10_2823(A0_2813.toSpawnFromDeadBookmarks, L8_2821, L7_2820)
      L10_2823 = System
      L10_2823 = L10_2823.PrepareEntityFromPool
      L10_2823 = L10_2823(L8_2821)
      if not L10_2823 then
        L10_2823 = A0_2813.GetName
        L10_2823 = L10_2823(A0_2813)
        System.Warning("AIWave " .. L10_2823 .. " failed to prepare pooled entity: %s", tostring(L8_2821))
      end
      L10_2823 = Set
      L10_2823 = L10_2823.Get
      L10_2823 = L10_2823(A0_2813.toSpawnFromDeadBookmarks, L8_2821)
      if not L10_2823 then
        L3_2816 = true
      end
    end
  end
  A0_2813.bIsPreparingBookmarks = false
  for L7_2820, L8_2821 in L4_2817(L5_2818) do
    L9_2822 = System
    L9_2822 = L9_2822.GetEntity
    L10_2823 = L7_2820
    L9_2822 = L9_2822(L10_2823)
    L10_2823 = System
    L10_2823 = L10_2823.GetEntity
    L10_2823 = L10_2823(L8_2821)
    if L10_2823 and (not L9_2822.AI.TerritoryShape or ActiveTerritories[L9_2822.AI.TerritoryShape]) then
      A0_2813:TryBecomeActive(L1_2814)
      if L9_2822 then
        A0_2813:SpawnEntity(L9_2822)
      else
        L10_2823.spawnedEntity = nil
        L10_2823.lastSpawnedEntity = nil
        A0_2813:SpawnEntity(L10_2823)
      end
      L3_2816 = true
      Set.Remove(A0_2813.deadAIs, L7_2820)
    end
  end
  A0_2813.bIsEnabling = false
  if not L4_2817 then
    L7_2820 = " was activated but it was not enabled"
    L4_2817(L5_2818)
  end
  if L2_2815 or L3_2816 then
    L4_2817(L5_2818)
    L7_2820 = A0_2813
    L4_2817(L5_2818, L6_2819, L7_2820)
  end
end
L0_2758.Event_Spawn = L1_2759
function L0_2758(A0_2824)
  if A0_2824 and type(A0_2824) == "table" then
    BroadcastEvent(A0_2824, "Spawned")
  end
end
DelayedBroadcastEventSpawned = L0_2758
L0_2758 = AIWave
function L1_2759(A0_2825, A1_2826)
  if A0_2825.bIsPreparingBookmarks then
    return
  end
  if not ActiveWaves[A1_2826] and (not A0_2825.nPoolQueueCount or A0_2825.nPoolQueueCount <= 0) then
    ActiveWaves[A1_2826] = true
    BroadcastEvent(A0_2825, "Enabled")
  end
end
L0_2758.TryBecomeActive = L1_2759
L0_2758 = AIWave
function L1_2759(A0_2827)
  local L1_2828, L2_2829, L3_2830, L4_2831, L5_2832, L6_2833, L7_2834
  L1_2828 = A0_2827.GetName
  L1_2828 = L1_2828(L2_2829)
  if L2_2829 then
    L5_2832 = " .'Kill' input has been triggered, but the wave has already been DisabledAndCleared. Nothing will happen."
    L2_2829(L3_2830)
    return
  end
  if L2_2829 then
    for L5_2832, L6_2833 in L2_2829(L3_2830) do
      L7_2834 = System
      L7_2834 = L7_2834.GetEntity
      L7_2834 = L7_2834(L5_2832)
      if L7_2834 and A0_2827:CheckAlive(L7_2834) and (not L7_2834.AI.TerritoryShape or ActiveTerritories[L7_2834.AI.TerritoryShape]) and L7_2834:IsActive() then
        L7_2834:Event_Kill()
      end
    end
  end
end
L0_2758.Event_Kill = L1_2759
L0_2758 = AIWave
function L1_2759(A0_2835)
  local L1_2836, L2_2837, L3_2838, L4_2839, L5_2840
  L1_2836 = A0_2835.GetName
  L1_2836 = L1_2836(L2_2837)
  if L2_2837 then
    L5_2840 = " .'DisableAndClear' input has been triggered, but the wave has already been DisabledAndCleared. Nothing will happen."
    L2_2837(L3_2838)
    return
  end
  L2_2837(L3_2838)
  L2_2837(L3_2838)
  for L5_2840, _FORV_6_ in L2_2837(L3_2838) do
    if System.GetEntity(L5_2840) and System.GetEntity(L5_2840).whoSpawnedMe then
      System.RemoveEntity(L5_2840)
    end
  end
  for L5_2840, _FORV_6_ in L2_2837(L3_2838) do
    if System.GetEntity(L5_2840) and System.GetEntity(L5_2840).whoSpawnedMe then
      System.RemoveEntity(L5_2840)
    end
  end
  L2_2837(L3_2838)
  A0_2835.bDisabledAndCleared = true
end
L0_2758.Event_DisableAndClear = L1_2759
L0_2758 = AIWave
function L1_2759(A0_2841, A1_2842)
  if not ActiveWaves[A0_2841:GetName()] then
    return true
  end
  if Set.Get(A0_2841.deadAIs, A1_2842.id) then
    return false
  end
  return true
end
L0_2758.AllowActorRemoval = L1_2759
L0_2758 = AIWave
function L1_2759(A0_2843)
  A0_2843.bookmarkAIs = Set.New()
  A0_2843:OnReset()
end
L0_2758.OnInit = L1_2759
L0_2758 = AIWave
function L1_2759(A0_2844, A1_2845)
  ActiveWaves[A0_2844:GetName()] = A1_2845.bIsActive
  A0_2844.liveAIs = Set.DeserializeValues(A1_2845.liveAIs)
  A0_2844.deadAIs = Set.DeserializeValues(A1_2845.deadAIs)
  A0_2844.toSpawnFromDeadBookmarks = Set.DeserializeEntities(A1_2845.toSpawnFromDeadBookmarks)
  A0_2844.bookmarkAIs = Set.New()
  A0_2844.bookmarkAIs = Set.DeserializeItems(A1_2845.bookmarkAIs)
  A0_2844.nActiveCount = A1_2845.nActiveCount
  A0_2844.nBodyCount = A1_2845.nBodyCount
  A0_2844.nPoolQueueCount = A1_2845.nPoolQueueCount
  A0_2844.bEnableOnAdd = A1_2845.bEnableOnAdd
  A0_2844.bIsEnabling = A1_2845.bIsEnabling
  A0_2844.bIsPreparingBookmarks = A1_2845.bIsPreparingBookmarks
  A0_2844.bBookmarsHaveBeenPrepared = A1_2845.bBookmarsHaveBeenPrepared
  A0_2844.bDisabledAndCleared = A1_2845.bDisabledAndCleared
  A0_2844.currentAssignment = A1_2845.currentAssignment
end
L0_2758.OnLoad = L1_2759
L0_2758 = AIWave
function L1_2759(A0_2846)
  local L1_2847, L2_2848, L3_2849, L4_2850, L5_2851
  for L4_2850, L5_2851 in L1_2847(L2_2848) do
    if System.GetEntity(L4_2850) and L4_2850 ~= L5_2851 then
      if System.GetEntity(L5_2851) then
        System.GetEntity(L4_2850).whoSpawnedMe = System.GetEntity(L5_2851)
      else
        System.GetEntity(L4_2850).whoSpawnedMe = {}
        System.GetEntity(L4_2850).whoSpawnedMe.id = L5_2851
      end
    end
  end
  for L4_2850, L5_2851 in L1_2847(L2_2848) do
    if System.GetEntity(L4_2850) and L4_2850 ~= L5_2851 then
      if System.GetEntity(L5_2851) then
        System.GetEntity(L4_2850).whoSpawnedMe = System.GetEntity(L5_2851)
      else
        System.GetEntity(L4_2850).whoSpawnedMe = {}
        System.GetEntity(L4_2850).whoSpawnedMe.id = L5_2851
      end
    end
  end
end
L0_2758.OnPostLoad = L1_2759
L0_2758 = AIWave
function L1_2759(A0_2852)
  A0_2852:Reset()
end
L0_2758.OnReset = L1_2759
L0_2758 = AIWave
function L1_2759(A0_2853)
  local L1_2854
  L1_2854 = A0_2853.GetName
  L1_2854 = L1_2854(A0_2853)
  ActiveWaves[L1_2854] = false
  A0_2853.liveAIs = Set.New()
  A0_2853.deadAIs = Set.New()
  A0_2853.toSpawnFromDeadBookmarks = Set.New()
  ExecuteAIWaveBookmarkCache(L1_2854)
  A0_2853.nActiveCount = 0
  A0_2853.nBodyCount = 0
  A0_2853.nPoolQueueCount = 0
  A0_2853.bEnableOnAdd = false
  A0_2853.bIsEnabling = false
  A0_2853.bIsPreparingBookmarks = false
  A0_2853.bBookmarsHaveBeenPrepared = false
  A0_2853.currentAssignment = nil
  A0_2853.bDisabledAndCleared = false
end
L0_2758.Reset = L1_2759
L0_2758 = AIWave
function L1_2759(A0_2855, A1_2856)
  A1_2856.bIsActive = ActiveWaves[A0_2855:GetName()]
  A1_2856.liveAIs = Set.SerializeValues(A0_2855.liveAIs)
  A1_2856.deadAIs = Set.SerializeValues(A0_2855.deadAIs)
  A1_2856.toSpawnFromDeadBookmarks = Set.SerializeEntities(A0_2855.toSpawnFromDeadBookmarks)
  A1_2856.bookmarkAIs = Set.SerializeItems(A0_2855.bookmarkAIs)
  A1_2856.nActiveCount = A0_2855.nActiveCount
  A1_2856.nBodyCount = A0_2855.nBodyCount
  A1_2856.nPoolQueueCount = A0_2855.nPoolQueueCount
  A1_2856.bEnableOnAdd = A0_2855.bEnableOnAdd
  A1_2856.bIsEnabling = A0_2855.bIsEnabling
  A1_2856.bIsPreparingBookmarks = A0_2855.bIsPreparingBookmarks
  A1_2856.bBookmarsHaveBeenPrepared = A0_2855.bBookmarsHaveBeenPrepared
  A1_2856.bDisabledAndCleared = A0_2855.bDisabledAndCleared
  A1_2856.currentAssignment = A0_2855.currentAssignment
end
L0_2758.OnSave = L1_2759
L0_2758 = AIWave
function L1_2759(A0_2857)
  A0_2857:ResetBookmarkedAI()
end
L0_2758.OnHidden = L1_2759
L0_2758 = AIWave
function L1_2759(A0_2858, A1_2859)
  local L2_2860
  L2_2860 = A1_2859.whoSpawnedMe
  if L2_2860 then
    L2_2860 = A1_2859.whoSpawnedMe
    L2_2860 = L2_2860.id
    return L2_2860
  else
    L2_2860 = A1_2859.id
    return L2_2860
  end
end
L0_2758.GetStaticEntityID = L1_2759
L0_2758 = AIWave
function L1_2759(A0_2861, A1_2862)
  local L2_2863, L3_2864
  L3_2864 = A0_2861
  L2_2863 = A0_2861.GetName
  L2_2863 = L2_2863(L3_2864)
  L3_2864 = A1_2862.AI
  L3_2864 = L3_2864.Wave
  if L2_2863 == L3_2864 then
    L3_2864 = A0_2861.GetStaticEntityID
    L3_2864 = L3_2864(A0_2861, A1_2862)
    if Set.Get(A0_2861.bookmarkAIs, A1_2862.id) then
      if not Set.Get(A0_2861.toSpawnFromDeadBookmarks, A1_2862.id) then
        Set.Add(A0_2861.liveAIs, A1_2862.id, L3_2864)
        A0_2861:AddFromBookmark(A1_2862)
      end
    else
      Set.Add(A0_2861.liveAIs, A1_2862.id, L3_2864)
      A0_2861:AddNormal(A1_2862)
    end
  end
end
L0_2758.Add = L1_2759
L0_2758 = AIWave
function L1_2759(A0_2865, A1_2866)
  if A1_2866:IsActive() then
    if not A1_2866.AI.TerritoryShape or ActiveTerritories[A1_2866.AI.TerritoryShape] then
      if not ActiveWaves[A0_2865:GetName()] and A0_2865.bEnableOnAdd then
        A0_2865:EnableEntity(A1_2866)
      end
      A0_2865.bEnableOnAdd = false
      if ActiveWaves[A0_2865:GetName()] then
        A0_2865:UpdateActiveCount()
        return
      end
    end
  end
  A1_2866:Event_Disable()
end
L0_2758.AddNormal = L1_2759
L0_2758 = AIWave
function L1_2759(A0_2867, A1_2868)
  local L2_2869
  L2_2869 = A0_2867.nPoolQueueCount
  L2_2869 = L2_2869 - 1
  A0_2867.nPoolQueueCount = L2_2869
  L2_2869 = A0_2867.GetName
  L2_2869 = L2_2869(A0_2867)
  if not A1_2868.AI.TerritoryShape or ActiveTerritories[A1_2868.AI.TerritoryShape] then
    A1_2868:Activate(1)
    A0_2867:EnableEntity(A1_2868)
    A0_2867:TryBecomeActive(L2_2869)
    A0_2867:UpdateActiveCount()
  end
end
L0_2758.AddFromBookmark = L1_2759
L0_2758 = AIWave
function L1_2759(A0_2870, A1_2871)
  Set.Add(A0_2870.bookmarkAIs, A1_2871)
end
L0_2758.AddBookmarked = L1_2759
L0_2758 = AIWave
function L1_2759(A0_2872, A1_2873)
  local L2_2874, L3_2875
  L2_2874 = Set
  L2_2874 = L2_2874.Get
  L3_2875 = A0_2872.toSpawnFromDeadBookmarks
  L2_2874 = L2_2874(L3_2875, A1_2873.id)
  if L2_2874 then
    L3_2875 = System
    L3_2875 = L3_2875.GetEntity
    L3_2875 = L3_2875(L2_2874)
    if L3_2875 then
      if L3_2875.whoSpawnedMe then
        L3_2875.whoSpawnedMe = A1_2873
      end
      A1_2873.spawnedEntity = nil
      A0_2872:SpawnEntity(L3_2875)
    end
    Set.Remove(A0_2872.deadAIs, L2_2874)
    Set.Remove(A0_2872.toSpawnFromDeadBookmarks, A1_2873.id)
  end
end
L0_2758.OnEntityPreparedFromPool = L1_2759
L0_2758 = AIWave
function L1_2759(A0_2876, A1_2877)
  local L2_2878
  L2_2878 = Set
  L2_2878 = L2_2878.Get
  L2_2878 = L2_2878(A0_2876.liveAIs, A1_2877.id)
  if L2_2878 then
    L2_2878 = A0_2876.GetStaticEntityID
    L2_2878 = L2_2878(A0_2876, A1_2877)
    Set.Remove(A0_2876.liveAIs, A1_2877.id)
    Set.Add(A0_2876.deadAIs, A1_2877.id, L2_2878)
    A0_2876:UpdateActiveCount(true)
    A0_2876.nBodyCount = A0_2876.nBodyCount + 1
    A0_2876:ActivateOutput("BodyCount", A0_2876.nBodyCount)
  end
end
L0_2758.NotifyDeath = L1_2759
L0_2758 = AIWave
function L1_2759(A0_2879)
  local L1_2880
  L1_2880 = A0_2879.bIsEnabling
  return L1_2880
end
L0_2758.IsEnabling = L1_2759
L0_2758 = AIWave
function L1_2759(A0_2881)
  if A0_2881.nPoolQueueCount >= 0 then
    return A0_2881.nPoolQueueCount
  end
  return 0
end
L0_2758.GetPoolQueueCount = L1_2759
L0_2758 = AIWave
function L1_2759(A0_2882)
  local L1_2883
  L1_2883 = A0_2882.nActiveCount
  return L1_2883
end
L0_2758.GetActiveCount = L1_2759
L0_2758 = AIWave
function L1_2759(A0_2884, A1_2885)
  local L2_2886, L3_2887, L4_2888, L5_2889, L6_2890, L7_2891, L8_2892, L9_2893, L10_2894, L11_2895
  L3_2887 = A0_2884
  L2_2886 = A0_2884.IsEnabling
  L2_2886 = L2_2886(L3_2887)
  if L2_2886 then
    return
  end
  L3_2887 = A0_2884
  L2_2886 = A0_2884.GetName
  L2_2886 = L2_2886(L3_2887)
  L4_2888 = A0_2884
  L3_2887 = A0_2884.GetPoolQueueCount
  L3_2887 = L3_2887(L4_2888)
  L4_2888 = Set
  L4_2888 = L4_2888.New
  L4_2888 = L4_2888()
  if L5_2889 then
    for L8_2892, L9_2893 in L5_2889(L6_2890) do
      L10_2894 = System
      L10_2894 = L10_2894.GetEntity
      L11_2895 = L8_2892
      L10_2894 = L10_2894(L11_2895)
      if L10_2894 then
        L11_2895 = L10_2894.IsDead
        L11_2895 = L11_2895(L10_2894)
        if not L11_2895 then
          L11_2895 = L10_2894.IsActive
          L11_2895 = L11_2895(L10_2894)
          if L11_2895 then
            L3_2887 = L3_2887 + 1
          end
        end
        L11_2895 = L10_2894.AI
        L11_2895 = L11_2895.TerritoryShape
        if L11_2895 then
          Set.Add(L4_2888, L11_2895)
        end
      end
    end
  end
  if L3_2887 ~= L5_2889 then
    A0_2884.nActiveCount = L3_2887
    if L5_2889 == 0 then
      L8_2892 = A0_2884.nActiveCount
      L5_2889(L6_2890, L7_2891, L8_2892)
      L5_2889(L6_2890)
    end
    if A1_2885 then
      if L5_2889 == 0 then
        L5_2889(L6_2890, L7_2891)
      end
    end
  end
end
L0_2758.UpdateActiveCount = L1_2759
L0_2758 = AIWave
function L1_2759(A0_2896, A1_2897)
  if A1_2897:IsDead() then
    A0_2896:NotifyDeath(A1_2897)
    return false
  end
  return true
end
L0_2758.CheckAlive = L1_2759
L0_2758 = AIWave
function L1_2759(A0_2898, A1_2899)
  A1_2899:Event_Enable()
  if A0_2898.currentAssignment then
    A0_2898:IndividualDispatchSetAssignment(A1_2899)
  end
end
L0_2758.EnableEntity = L1_2759
L0_2758 = AIWave
function L1_2759(A0_2900, A1_2901)
  local L2_2902, L3_2903
  L3_2903 = A1_2901
  L2_2902 = A1_2901.Event_Spawn
  L2_2902(L3_2903)
  L2_2902 = A0_2900.currentAssignment
  if L2_2902 then
    L2_2902 = nil
    L3_2903 = A1_2901.whoSpawnedMe
    if L3_2903 then
      L3_2903 = A1_2901.whoSpawnedMe
      L2_2902 = L3_2903.lastSpawnedEntity
    else
      L2_2902 = A1_2901.lastSpawnedEntity
    end
    if L2_2902 then
      L3_2903 = System
      L3_2903 = L3_2903.GetEntity
      L3_2903 = L3_2903(L2_2902)
      A0_2900:IndividualDispatchSetAssignment(L3_2903)
    end
  end
end
L0_2758.SpawnEntity = L1_2759
L0_2758 = AIWave
function L1_2759(A0_2904, A1_2905, A2_2906)
  A0_2904:ClearAssignment()
  A0_2904.currentAssignment = {}
  A0_2904.currentAssignment.assignment = A1_2905
  A0_2904.currentAssignment.data = {}
  if A2_2906 ~= nil then
    mergef(A0_2904.currentAssignment.data, A2_2906, 1)
  end
  A0_2904:DispatchSetAssignment()
end
L0_2758.SetAssignment = L1_2759
L0_2758 = AIWave
function L1_2759(A0_2907)
  A0_2907.currentAssignment = nil
  A0_2907:DispatchClearAssignment()
end
L0_2758.ClearAssignment = L1_2759
L0_2758 = AIWave
function L1_2759(A0_2908)
  local L1_2909, L2_2910, L3_2911, L4_2912
  for L4_2912, _FORV_5_ in L1_2909(L2_2910) do
    if System.GetEntity(L4_2912) and System.GetEntity(L4_2912):IsActive() and System.GetEntity(L4_2912).SetAssignment then
      System.GetEntity(L4_2912):SetAssignment(A0_2908.currentAssignment.assignment, A0_2908.currentAssignment.data)
    end
  end
end
L0_2758.DispatchSetAssignment = L1_2759
L0_2758 = AIWave
function L1_2759(A0_2913)
  local L1_2914, L2_2915, L3_2916, L4_2917
  for L4_2917, _FORV_5_ in L1_2914(L2_2915) do
    if System.GetEntity(L4_2917) and System.GetEntity(L4_2917):IsActive() and System.GetEntity(L4_2917).ClearAssignment then
      System.GetEntity(L4_2917):ClearAssignment()
    end
  end
end
L0_2758.DispatchClearAssignment = L1_2759
L0_2758 = AIWave
function L1_2759(A0_2918, A1_2919)
  if A1_2919 and A1_2919.SetAssignment then
    A1_2919:SetAssignment(A0_2918.currentAssignment.assignment, A0_2918.currentAssignment.data)
  end
end
L0_2758.IndividualDispatchSetAssignment = L1_2759
L0_2758 = AIWave
L1_2759 = {}
L2_2760 = {}
L3_2761 = {
  AIWave.Event_Disable,
  "bool"
}
L2_2760.Disable = L3_2761
L3_2761 = {
  AIWave.Event_Enable,
  "bool"
}
L2_2760.Enable = L3_2761
L3_2761 = {
  AIWave.Event_Kill,
  "bool"
}
L2_2760.Kill = L3_2761
L3_2761 = {
  AIWave.Event_Spawn,
  "bool"
}
L2_2760.Spawn = L3_2761
L3_2761 = {
  AIWave.Event_DisableAndClear,
  "bool"
}
L2_2760.DisableAndClear = L3_2761
L1_2759.Inputs = L2_2760
L2_2760 = {}
L2_2760.ActiveCount = "int"
L2_2760.BodyCount = "int"
L2_2760.Dead = "bool"
L2_2760.Disabled = "bool"
L2_2760.Enabled = "bool"
L2_2760.Spawned = "bool"
L1_2759.Outputs = L2_2760
L0_2758.FlowEvents = L1_2759
