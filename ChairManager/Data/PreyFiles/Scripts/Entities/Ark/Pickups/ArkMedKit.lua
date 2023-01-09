Script.ReloadScript("Scripts/Entities/Ark/Pickups/ArkConsumable.lua")
ArkMedKit = {
  Properties = {
    ability_cureTraumaAbility = "3149325216929346739"
  }
}
ArkMakeDerivedEntityOverride(ArkMedKit, ArkConsumable, true)
function ArkMedKit.CanUse(A0_3215)
  if g_localActor.arkPlayer:IsAnyTraumaActive() == true and g_localActor.arkPlayer:HasAbility(A0_3215.Properties.ability_cureTraumaAbility) then
    return true
  else
    return g_localActor.arkPlayer:IsMaxHealth() ~= true
  end
end
