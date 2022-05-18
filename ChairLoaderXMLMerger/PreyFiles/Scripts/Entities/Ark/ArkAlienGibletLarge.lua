Script.ReloadScript("scripts/ArkEntityUtils.lua")
Script.ReloadScript("scripts/Entities/Ark/ArkAlienGibletSmall.lua")
ArkAlienGibletLarge = {
  Properties = {
    model = "Objects/characters/Aliens/AlienCorpses/AlienCorpsePieces_Large.cgf",
    particleAttachment = "lower_jiggle",
    particleeffect_particleEffect = "Characters.Aliens.Shared.Death.AlienGib_Trail_01"
  }
}
ArkMakeDerivedEntityOverride(ArkAlienGibletLarge, ArkAlienGibletSmall, true)
