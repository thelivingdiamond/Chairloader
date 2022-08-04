Script.ReloadScript("Scripts/Entities/Ark/Pickups/ArkItem.lua")
ArkAmmoPickupHeavyLaser = {
  Properties = {bIsAmmo = true},
  Editor = {Icon = "mine.bmp"}
}
ArkMakeDerivedEntityOverride(ArkAmmoPickupHeavyLaser, ArkItem, true)
function ArkAmmoPickupHeavyLaser.OnUsedFromInventory(A0_3110, A1_3111)
  Log("ArkAmmoPickupHeavyLaser used from inventory!")
end
