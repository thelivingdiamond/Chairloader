Script.ReloadScript("Scripts/Entities/Ark/Pickups/ArkItem.lua")
ArkNeuroMod = {
  Properties = {
    MultiPickup = {object_MultiGeometryTP = "", nSubMaterialId = 3}
  }
}
ArkMakeDerivedEntityOverride(ArkNeuroMod, ArkItem, true)
