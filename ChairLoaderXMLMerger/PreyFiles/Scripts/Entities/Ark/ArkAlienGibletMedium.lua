Script.ReloadScript("scripts/ArkEntityUtils.lua")
Script.ReloadScript("scripts/Entities/Ark/ArkAlienGibletSmall.lua")
ArkAlienGibletMedium = {
  Properties = {
    model = "Objects/characters/Aliens/AlienCorpses/AlienCorpsePieces_Medium.cgf",
    particleAttachment = "lower_jiggle",
    particleeffect_particleEffect = "Characters.Aliens.Shared.Death.AlienGib_Trail_01"
  }
}
ArkMakeDerivedEntityOverride(ArkAlienGibletMedium, ArkAlienGibletSmall, true)
