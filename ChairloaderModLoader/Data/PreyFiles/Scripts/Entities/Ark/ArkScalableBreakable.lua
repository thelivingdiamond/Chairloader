Script.ReloadScript("scripts/ArkEntityUtils.lua")
Script.ReloadScript("scripts/Entities/Ark/ArkBreakable.lua")
ArkScalableBreakable = {
  Editor = {IsScalable = true},
  PropertiesInstance = {bOverrideAIIgnore = false}
}
MakeDerivedEntityOverride(ArkScalableBreakable, ArkBreakable, true)
