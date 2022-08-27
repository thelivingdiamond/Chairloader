Script.ReloadScript("Scripts/Entities/Ark/Pickups/ArkItem.lua")
ArkAmmoPickupGooGun = {
  Properties = {
    iCount = 50,
    Damage = {health = 1},
    bIsAmmo = true
  },
  Editor = {Icon = "mine.bmp"}
}
ArkMakeDerivedEntityOverride(ArkAmmoPickupGooGun, ArkItem, true)
function ArkAmmoPickupGooGun.OnUsedFromInventory(A0_3108, A1_3109)
  Log("ArkAmmoPickupGooGun used from inventory!")
end
