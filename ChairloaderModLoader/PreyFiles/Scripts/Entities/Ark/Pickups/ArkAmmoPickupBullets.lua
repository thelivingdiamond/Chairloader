Script.ReloadScript("Scripts/Entities/Ark/Pickups/ArkItem.lua")
Script.ReloadScript("Scripts/Entities/Ark/Pickups/ArkAmmoPickupShells.lua")
ArkAmmoPickupBullets = {
  Properties = {
    sSubMaterial = "opaque_box",
    nSubMaterialId = 3,
    sProjectileClass = "ArkProjectilePistolBullet",
    bIsAmmo = true
  },
  Editor = {IconOnTop = true, Icon = "mine.bmp"}
}
ArkMakeDerivedEntityOverride(ArkAmmoPickupBullets, ArkAmmoPickupShells, true)
