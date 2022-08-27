Script.ReloadScript("Scripts/Entities/Ark/Pickups/ArkItem.lua")
ArkKeycard = {
  PropertiesInstance = {keycard_Keycard = ""}
}
ArkMakeDerivedEntityOverride(ArkKeycard, ArkItem, true)
ArkMakeInstanceObjectSaveable(ArkKeycard)
function ArkKeycard.UpdateDisplayName(A0_3207)
  A0_3207.displayName = Ark.GetKeyCardLabel(A0_3207.PropertiesInstance.keycard_Keycard)
end
function ArkKeycard.UpdateInventoryName(A0_3208)
  return Ark.GetKeyCardLabel(A0_3208.PropertiesInstance.keycard_Keycard)
end
function ArkKeycard.OnPickup(A0_3209, A1_3210)
  BroadcastEvent(A0_3209, "OnPickup")
  A0_3209:ActivateOutput("ItemType", A0_3209.Properties.sType)
  A0_3209:UpdateDisplayName()
  if not g_localActor.arkPlayer:IsExternalInventoryOpen() then
    A0_3209:GiveKeycard()
  end
end
function ArkKeycard.OnMyContainerClose(A0_3211)
  ArkItem.OnMyContainerClose(A0_3211)
  A0_3211:GiveKeycard()
end
function ArkKeycard.GiveKeycard(A0_3212)
  local L1_3213
  L1_3213 = A0_3212.Log
  L1_3213(A0_3212, "ArkKeycard:GiveKeycard()")
  L1_3213 = A0_3212.PropertiesInstance
  L1_3213 = L1_3213.keycard_Keycard
  if L1_3213 ~= "" then
    g_localActor.arkPlayer:GiveKeyCard(L1_3213)
  else
    LogWarning(A0_3212:GetName() .. " attempted to add a Keycard to player, but no Keycard was specified.")
  end
end
function ArkKeycard.OnStartLevel(A0_3214)
  A0_3214:UpdateDisplayName()
end
