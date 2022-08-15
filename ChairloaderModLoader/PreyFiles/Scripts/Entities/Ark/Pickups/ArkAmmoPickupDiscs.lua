Script.ReloadScript("Scripts/Entities/Ark/Pickups/ArkItem.lua")
ArkAmmoPickupDiscs = {
  Properties = {bIsAmmo = true},
  Editor = {Icon = "mine.bmp"}
}
ArkMakeDerivedEntityOverride(ArkAmmoPickupDiscs, ArkItem, true)
function ArkAmmoPickupDiscs.OnUsedFromInventory(A0_3102, A1_3103)
  Log("ArkAmmoPickupHeavyLaser used from inventory!")
end
