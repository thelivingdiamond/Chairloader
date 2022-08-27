Script.ReloadScript("scripts/ArkEntityUtils.lua")
Script.ReloadScript("scripts/Entities/Ark/ArkAlienGibletSmall.lua")
ArkAlienGibletXLarge = {
  Properties = {
    model = "Objects/characters/Aliens/AlienCorpses/AlienCorpsePieces_XLarge.cgf",
    particleAttachment = "lower_jiggle",
    particleeffect_particleEffect = "Characters.Aliens.Shared.Death.AlienGib_Trail_01"
  }
}
ArkMakeDerivedEntityOverride(ArkAlienGibletXLarge, ArkAlienGibletSmall, true)
