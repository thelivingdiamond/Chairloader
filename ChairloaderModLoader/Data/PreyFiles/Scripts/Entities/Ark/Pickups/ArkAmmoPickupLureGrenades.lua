Script.ReloadScript("Scripts/Entities/Ark/Pickups/ArkItem.lua")
ArkAmmoPickupLureGrenades = {
  Properties = {
    iCount = 10,
    sSubMaterial = "opaque_box",
    nSubMaterialId = 3,
    bIsGrenade = true,
    bIsAmmo = true
  },
  Editor = {IconOnTop = true, Icon = "mine.bmp"}
}
ArkMakeDerivedEntityOverride(ArkAmmoPickupLureGrenades, ArkItem, true)
function ArkAmmoPickupLureGrenades.OnUsedFromInventory(A0_3112, A1_3113)
  Log("ArkAmmoPickupLureGrenades used from inventory!")
end
