Script.ReloadScript("scripts/ArkEntityUtils.lua")
Script.ReloadScript("scripts/Entities/Ark/ArkBasicEntity.lua")
ArkApexTentacleHead = {
  Properties = {
    metaTags_ArkMetaTags = "17591291352642463355"
  }
}
ArkMakeDerivedEntityOverride(ArkApexTentacleHead, ArkBasicEntity, true)
