Script.ReloadScript("scripts/ArkEntityUtils.lua")
Script.ReloadScript("scripts/Entities/Ark/ArkElectricalBox.lua")
ArkTechnopathEMPHazard = {
  Properties = {
    metaTags_ArkMetaTags = "17591291352642463355",
    lifeTime = 4.74
  }
}
ArkMakeDerivedEntityOverride(ArkTechnopathEMPHazard, ArkElectricalBox, true)
