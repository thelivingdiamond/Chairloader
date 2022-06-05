Script.ReloadScript("Scripts/Entities/Ark/Pickups/ArkItem.lua")
RW_Fruit = {
  Properties = {sType = "random"}
}
ArkMakeDerivedEntityOverride(RW_Fruit, ArkItem, true)
function RW_Fruit.GetValidTypes(A0_8728)
  local L1_8729
  L1_8729 = {"apple", "banana"}
  return L1_8729
end
