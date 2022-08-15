Script.ReloadScript("Scripts/Entities/Ark/Pickups/ArkItem.lua")
Script.ReloadScript("Scripts/ArkEntityUtils.lua")
ArkConsumable = {
  Properties = {
    Description = {
      sKeyword = "",
      signal_keywordSignal = "",
      sKeyword2 = "",
      signal_keywordSignal2 = "",
      fSignalScale = 1,
      fSignalScale2 = 1
    },
    bCanBeFavorited = 1,
    gameMetric_MetricUsedFromWorld = "",
    gameMetric_MetricUsedTotal = "",
    AppliedOnConsume = {
      es_RestoredPoints = "",
      signalpackage_SignalPackage = "",
      OptionalAbilityRequirement = {ability_AbilityRequirement = "", signalpackage_AbilityRequirementSignalPackage = ""}
    },
    Effects = {posteffect_ConsumeVFX = ""},
    Sound = {audioTrigger_ConsumeSFX = ""},
    Inventory = {ei_ItemCategory = 2},
    textConsumeVerb = "@ui_Use"
  }
}
ArkMakeDerivedEntityOverride(ArkConsumable, ArkItem, true)
function ArkConsumable.Consume(A0_3127, A1_3128, A2_3129)
  local L3_3130, L4_3131, L5_3132
  L3_3130 = A0_3127.Properties
  L4_3131 = L3_3130.AppliedOnConsume
  L4_3131 = L4_3131.signalpackage_SignalPackage
  L5_3132 = L3_3130.AppliedOnConsume
  L5_3132 = L5_3132.OptionalAbilityRequirement
  L5_3132 = L5_3132.signalpackage_AbilityRequirementSignalPackage
  if L4_3131 ~= "" then
    Ark.SendSignalPackage(A1_3128.id, A0_3127.id, A1_3128.id, L4_3131)
  end
  if L5_3132 ~= "" and g_localActor.arkPlayer:HasAbility(L3_3130.AppliedOnConsume.OptionalAbilityRequirement.ability_AbilityRequirement) then
    Ark.SendSignalPackage(A1_3128.id, A0_3127.id, A1_3128.id, L5_3132)
  end
  Ark.TriggerPostEffect(L3_3130.Effects.posteffect_ConsumeVFX)
  A0_3127:PlaySFX(L3_3130.Sound.audioTrigger_ConsumeSFX)
  ArkItem.ConsumedItem(A0_3127, A1_3128)
end
function ArkConsumable.CanUse(A0_3133)
  if A0_3133.Properties.AppliedOnConsume.es_RestoredPoints == "HEALTH" then
    return g_localActor.arkPlayer:IsMaxHealth() ~= true
  elseif A0_3133.Properties.AppliedOnConsume.es_RestoredPoints == "PSI" then
    return g_localActor.arkPlayer:IsMaxPsi() ~= true
  elseif A0_3133.Properties.AppliedOnConsume.es_RestoredPoints == "OXYGEN" then
    return g_localActor.arkPlayer:IsMaxOxygen() ~= true
  else
    return true
  end
end
function ArkConsumable.PlayCameraFX(A0_3134, A1_3135)
  Particle.SpawnEffect(A1_3135, g_Vectors.v000, g_Vectors.v000, 1)
end
function ArkConsumable.OnUsedFromInventory(A0_3136, A1_3137)
  A0_3136:Log("ArkConsumable used from inventory!")
  ArkItem.OnUsedFromInventory(A0_3136, A1_3137)
  A0_3136:Consume(A1_3137, true)
  Ark.ModifyGameMetric(A0_3136.Properties.gameMetric_MetricUsedTotal, 1)
end
function ArkConsumable.OnUsedFromWorld(A0_3138, A1_3139)
  A0_3138:Log("ArkConsumable consumed from world!")
  A0_3138:Consume(A1_3139, false)
  Ark.ModifyGameMetric(A0_3138.Properties.gameMetric_MetricUsedFromWorld, 1)
  Ark.ModifyGameMetric(A0_3138.Properties.gameMetric_MetricUsedTotal, 1)
end
