Script.ReloadScript("Scripts/Entities/Ark/Pickups/ArkItem.lua")
ArkAmmoPickupRecyclerGrenades = {
  Properties = {
    iCount = 10,
    sSubMaterial = "opaque_box",
    nSubMaterialId = 3,
    bIsGrenade = true,
    bIsAmmo = true
  },
  Editor = {IconOnTop = true, Icon = "mine.bmp"}
}
ArkMakeDerivedEntityOverride(ArkAmmoPickupRecyclerGrenades, ArkItem, true)
function ArkAmmoPickupRecyclerGrenades.OnUsedFromInventory(A0_3114, A1_3115)
  Log("ArkAmmoPickupRecyclerGrenades used from inventory!")
end
