Script.ReloadScript("Scripts/Entities/Ark/Pickups/ArkItem.lua")
ArkAmmoPickupShells = {
  Properties = {
    sSubMaterial = "opaque_box",
    nSubMaterialId = 3,
    sProjectileClass = "ArkProjectileShotgunShell",
    bIsAmmo = true
  },
  Editor = {IconOnTop = true, Icon = "mine.bmp"}
}
ArkMakeDerivedEntityOverride(ArkAmmoPickupShells, ArkItem, true)
function ArkAmmoPickupShells.OnReset(A0_3116, A1_3117)
  ArkItem.OnReset(A0_3116, A1_3117)
  A0_3116:OnUpdateAppearance()
end
function ArkAmmoPickupShells.OnUpdateAppearance(A0_3118)
  local L1_3119, L2_3120
  L1_3119 = A0_3118.Properties
  L1_3119 = L1_3119.Stacks
  L1_3119 = L1_3119.iMaxCount
  L1_3119 = 1 / L1_3119
  L2_3120 = A0_3118.arkitem
  L2_3120 = L2_3120.GetCount
  L2_3120 = L2_3120(L2_3120)
  L2_3120 = L2_3120 * L1_3119
  L2_3120 = 1 - L2_3120
  A0_3118:SetMaterialFloat(thirdPersonSlot, A0_3118.Properties.nSubMaterialId, MaterialFloatParams.alpha_test, L2_3120)
end
function ArkAmmoPickupShells.OnUsedFromInventory(A0_3121, A1_3122)
  Log("ArkAmmoPickupShells used from inventory!")
end
function ArkAmmoPickupShells.OnPropertyChange(A0_3123)
  ArkItem.OnPropertyChange(A0_3123)
  A0_3123:OnUpdateAppearance()
end
function ArkAmmoPickupShells.OnSpawn(A0_3124)
  ArkItem.OnSpawn(A0_3124)
  A0_3124:CloneMaterial(thirdPersonSlot)
end
