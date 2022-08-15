Script.ReloadScript("Scripts/Entities/Ark/Pickups/ArkItem.lua")
ArkCraftingIngredient = {
  Properties = {
    Scraps = {
      iRandomMin = 100,
      iRandomMax = 500,
      fMinScale = 0.75,
      fMaxScale = 1.75,
      fXLMaxScale = 2.5,
      iXLMaxScaleCount = 10000,
      object_PickupModel = "",
      material_PickupMaterial = "",
      textDescription = "",
      sIcon = "",
      iScrapsPerIngredient = 1000
    }
  },
  PropertiesInstance = {bSpawnAsScrap = 0}
}
ArkMakeDerivedEntityOverride(ArkCraftingIngredient, ArkItem, true)
