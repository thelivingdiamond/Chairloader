Script.ReloadScript("Scripts/Entities/Ark/Pickups/ArkConsumable.lua")
ArkFood = {
  Properties = {textConsumeVerb = "@ui_Eat"}
}
ArkMakeDerivedEntityOverride(ArkFood, ArkConsumable, true)
