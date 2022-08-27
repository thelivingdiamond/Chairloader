Script.ReloadScript("Scripts/Entities/Ark/Pickups/ArkItem.lua")
ArkAmmoPickupStunGun = {
  Properties = {bIsAmmo = true},
  Editor = {Icon = "mine.bmp"}
}
ArkMakeDerivedEntityOverride(ArkAmmoPickupStunGun, ArkItem, true)
function ArkAmmoPickupStunGun.OnUsedFromInventory(A0_3125, A1_3126)
  Log("ArkAmmoPickupStunGun used from inventory!")
end
