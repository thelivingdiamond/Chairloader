Script.ReloadScript("Scripts/Entities/Ark/Pickups/ArkItem.lua")
ArkAmmoPickupNullwaveTransmitter = {
  Properties = {
    object_GeometryTP = "Objects/weapons/Nullwave_Transmitter/Nullwave_Transmitter_Base.cgf",
    object_GeometryFP = "Objects/weapons/Nullwave_Transmitter/Nullwave_Transmitter_Base.cgf",
    iCount = 10,
    sSubMaterial = "opaque_box",
    nSubMaterialId = 3,
    bIsGrenade = true,
    bIsAmmo = true
  },
  Editor = {IconOnTop = true, Icon = "mine.bmp"}
}
ArkMakeDerivedEntityOverride(ArkAmmoPickupNullwaveTransmitter, ArkItem, true)
