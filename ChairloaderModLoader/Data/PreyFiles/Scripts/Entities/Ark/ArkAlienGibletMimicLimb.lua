Script.ReloadScript("scripts/ArkEntityUtils.lua")
Script.ReloadScript("scripts/Entities/Ark/ArkAlienGibletSmall.lua")
ArkAlienGibletMimicLimb = {
  Properties = {
    model = "Objects/ArkEffects/Characters/Aliens/Mimic/Limb/Limb_Mimic.cdf",
    particleAttachment = "lower_jiggle",
    particleeffect_particleEffect = "Characters.Aliens.Shared.Death.AlienGib_Trail_01"
  }
}
ArkMakeDerivedEntityOverride(ArkAlienGibletMimicLimb, ArkAlienGibletSmall, true)
