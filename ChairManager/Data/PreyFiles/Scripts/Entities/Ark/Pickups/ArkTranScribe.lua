Script.ReloadScript("Scripts/Entities/Ark/Pickups/ArkItem.lua")
ArkTranScribe = {
  Properties = {nSubMatIndex = 3},
  PropertiesInstance = {audioLogCollection_OnPickup = "", bAutoPlayAudioLog = false}
}
ArkMakeDerivedEntityOverride(ArkTranScribe, ArkItem, true)
ArkMakeInstanceObjectSaveable(ArkTranScribe)
function ArkTranScribe.IsPlotCritical(A0_3244)
  return Ark.IsAudioLogCollectionPlotCritical(A0_3244.PropertiesInstance.audioLogCollection_OnPickup)
end
function ArkTranScribe.UpdateDisplayName(A0_3245)
  local L1_3246, L2_3247
  L1_3246 = A0_3245.PropertiesInstance
  L1_3246 = L1_3246.audioLogCollection_OnPickup
  if L1_3246 ~= "" then
    L2_3247 = A0_3245.arkitem
    L2_3247 = L2_3247.GetAudioLogCollectionOwnerName
    L2_3247 = L2_3247(L2_3247, L1_3246)
    if L2_3247 then
      A0_3245.displayName = A0_3245.Properties.textDisplayName .. " @ui_Colon " .. L2_3247
    else
      A0_3245.displayName = A0_3245.Properties.textDisplayName
    end
  else
    L2_3247 = A0_3245.Properties
    L2_3247 = L2_3247.textDisplayName
    A0_3245.displayName = L2_3247
  end
end
function ArkTranScribe.OnPickup(A0_3248, A1_3249)
  BroadcastEvent(A0_3248, "OnPickup")
  A0_3248:ActivateOutput("ItemType", A0_3248.Properties.sType)
  A0_3248:UpdateDisplayName()
  if not g_localActor.arkPlayer:IsExternalInventoryOpen() then
    A0_3248:GiveAudioLogData()
  end
end
function ArkTranScribe.OnMyContainerClose(A0_3250)
  ArkItem.OnMyContainerClose(A0_3250)
  A0_3250:GiveAudioLogData()
end
function ArkTranScribe.GiveAudioLogData(A0_3251)
  local L1_3252, L2_3253
  L1_3252 = A0_3251.PropertiesInstance
  L1_3252 = L1_3252.audioLogCollection_OnPickup
  if L1_3252 ~= "" then
    L2_3253 = A0_3251.PropertiesInstance
    L2_3253 = L2_3253.bAutoPlayAudioLog
    g_localActor.arkPlayer:GiveAudioLog(L1_3252, L2_3253)
  end
end
