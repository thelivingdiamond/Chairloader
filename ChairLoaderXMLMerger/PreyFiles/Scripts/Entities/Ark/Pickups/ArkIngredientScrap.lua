Script.ReloadScript("Scripts/Entities/Ark/Pickups/ArkItem.lua")
ArkIngredientScrap = {
  Properties = {
    minScaleForSpawnedScraps = 0.5,
    maxScaleForSpawnedScraps = 3,
    minCountForSpawnedScraps = 100,
    maxCountForSpawnedScraps = 500
  }
}
ArkMakeDerivedEntityOverride(ArkIngredientScrap, ArkItem, true)
function ArkIngredientScrap.OnReset(A0_3143, A1_3144)
  ArkItem.OnReset(A0_3143, A1_3144)
  A0_3143:OnUpdateAppearance()
end
function ArkIngredientScrap.OnUpdateAppearance(A0_3145)
  local L1_3146, L2_3147, L3_3148, L4_3149, L5_3150, L6_3151, L7_3152
  L1_3146 = A0_3145.arkitem
  L2_3147 = L1_3146
  L1_3146 = L1_3146.GetCount
  L1_3146 = L1_3146(L2_3147)
  if L1_3146 > 0 then
    L2_3147 = A0_3145.Properties
    L2_3147 = L2_3147.minScaleForSpawnedScraps
    L3_3148 = A0_3145.Properties
    L3_3148 = L3_3148.maxScaleForSpawnedScraps
    L4_3149 = L3_3148 - L2_3147
    if L4_3149 > 0 then
      L5_3150 = A0_3145.Properties
      L5_3150 = L5_3150.maxCountForSpawnedScraps
      L6_3151 = A0_3145.Properties
      L6_3151 = L6_3151.minCountForSpawnedScraps
      if L1_3146 > L5_3150 then
        L1_3146 = L5_3150
      end
      if L6_3151 > L1_3146 then
        L1_3146 = L6_3151
      end
      if L5_3150 > 0 then
        L7_3152 = L1_3146 * L4_3149
        L7_3152 = L7_3152 / L5_3150
        L7_3152 = L2_3147 + L7_3152
        A0_3145:SetScale(L7_3152)
      end
    end
  end
end
function ArkIngredientScrap.OnInit(A0_3153)
  ArkItem.OnInit(A0_3153)
  A0_3153:OnUpdateAppearance()
end
function ArkIngredientScrap.OnPropertyChange(A0_3154)
  ArkItem.OnPropertyChange(A0_3154)
  A0_3154:OnUpdateAppearance()
end
