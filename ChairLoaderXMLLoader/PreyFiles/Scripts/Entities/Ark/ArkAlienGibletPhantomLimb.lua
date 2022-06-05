Script.ReloadScript("scripts/ArkEntityUtils.lua")
Script.ReloadScript("scripts/Entities/Ark/ArkAlienGibletSmall.lua")
ArkAlienGibletPhantomLimb = {
  Properties = {
    model = "Objects/ArkEffects/Characters/Aliens/Phantom/Limb/Limb_Phantom.cdf",
    particleAttachment = "lower_jiggle",
    particleeffect_particleEffect = "Characters.Aliens.Shared.Death.AlienGib_Trail_01"
  }
}
ArkMakeDerivedEntityOverride(ArkAlienGibletPhantomLimb, ArkAlienGibletSmall, true)
