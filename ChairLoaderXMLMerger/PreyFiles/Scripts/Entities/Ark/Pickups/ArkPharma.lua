Script.ReloadScript("Scripts/Entities/Ark/Pickups/ArkConsumable.lua")
ArkPharma = {
  Properties = {
    nDuration = 30000,
    bIsAlcohol = false,
    AppliedOnConsume = {
      playerstatmodpkg_StatModifierPackage = "",
      signalmodifier_InboundSignalModifier = "",
      signalmodifier_OutboundSignalModifier = "",
      trauma_Cures = ""
    },
    UIStatusInfo = {
      textEffectsText = "",
      textRemovalText = "",
      sIcon = ""
    },
    Effects = {posteffect_PharmaStopVFX = ""},
    Sound = {audioTrigger_PharmaStopSFX = ""}
  }
}
ArkPharmaInstanceVars = {m_referenceTable = false, m_ownerId = false}
ArkMakeDerivedEntityOverride(ArkPharma, ArkConsumable, true)
ArkAlcohol = ArkPharma
ArkCure = ArkPharma
ArkSuitPatch = ArkPharma
function CreatePharma(A0_3223)
  mergef(A0_3223, ArkPharmaInstanceVars, 1)
  A0_3223.m_referenceTable = ArkPharmaInstanceVars
end
function ArkPharma.Consume(A0_3224, A1_3225, A2_3226)
  A0_3224:Log("StartPharma()")
  A0_3224.m_ownerId = A1_3225
  Ark.ApplyPharma(A0_3224.id)
  ArkConsumable.Consume(A0_3224, A0_3224.m_ownerId, A2_3226)
end
function ArkPharma.CanUse(A0_3227)
  if A0_3227.Properties.AppliedOnConsume.trauma_Cures ~= "" and A0_3227.Properties.bIsAlcohol == false then
    if A0_3227.Properties.AppliedOnConsume.es_RestoredPoints == "" then
      return (g_localActor.arkPlayer:CanHealTrauma(A0_3227.Properties.AppliedOnConsume.trauma_Cures))
    else
      return g_localActor.arkPlayer:CanHealTrauma(A0_3227.Properties.AppliedOnConsume.trauma_Cures) or ArkConsumable.CanUse(A0_3227)
    end
  else
    return ArkConsumable.CanUse(A0_3227)
  end
end
function ArkPharma.OnReset(A0_3228)
  A0_3228:KillTimer(A0_3228.m_timerId)
  A0_3228.m_ownerId = false
  ArkItem.OnReset(A0_3228)
end
function ArkPharma.OnSpawn(A0_3229)
  CreatePharma(A0_3229)
  A0_3229:Log("ArkPharma:OnSpawn")
  A0_3229.bRigidBodyActive = 1
end
