Script.ReloadScript("Scripts/Entities/Ark/Pickups/ArkItem.lua")
ArkTrackingChip = {
  PropertiesInstance = {character_TrackedCharacter = ""}
}
ArkMakeDerivedEntityOverride(ArkTrackingChip, ArkItem, true)
ArkMakeInstanceObjectSaveable(ArkTrackingChip)
function ArkTrackingChip.OnPickup(A0_3233, A1_3234)
  local L2_3235
  L2_3235 = A0_3233.PropertiesInstance
  L2_3235 = L2_3235.character_TrackedCharacter
  if A1_3234 == g_localActorId and not ArkRoster.GetCharacterHasTrackingChip(L2_3235) then
    ArkRoster.DiscoverCharacter(L2_3235)
  end
  ArkItem.OnPickup(A0_3233, A1_3234)
end
function ArkTrackingChip.OnPostLoad(A0_3236)
  local L1_3237
  L1_3237 = A0_3236.PropertiesInstance
  L1_3237 = L1_3237.character_TrackedCharacter
  ArkRoster.UpdateTrackingChipLocation(L1_3237)
  ArkItem.OnPostLoad()
end
function ArkTrackingChip.GetUsable(A0_3238)
  local L1_3239
  L1_3239 = A0_3238.PropertiesInstance
  L1_3239 = L1_3239.character_TrackedCharacter
  if not ArkRoster.GetCharacterHasTrackingChip(L1_3239) then
    ArkRoster.DiscoverCharacter(L1_3239)
  end
  return {}
end
function ArkTrackingChip.UpdateDisplayName(A0_3240)
  local L1_3241
  L1_3241 = ArkRoster
  L1_3241 = L1_3241.GetCharacterName
  L1_3241 = L1_3241(A0_3240.PropertiesInstance.character_TrackedCharacter)
  if L1_3241 ~= nil then
    A0_3240.displayName = L1_3241 .. ": " .. A0_3240.Properties.textDisplayName
  else
    LogWarning(A0_3240:GetName() .. ": Invalid characterId assigned to tracking bracelet.")
    A0_3240.displayName = A0_3240.Properties.textDisplayName
  end
end
function ArkTrackingChip.UpdateInventoryName(A0_3242)
  local L1_3243
  L1_3243 = ArkRoster
  L1_3243 = L1_3243.GetCharacterName
  L1_3243 = L1_3243(A0_3242.PropertiesInstance.character_TrackedCharacter)
  if L1_3243 ~= nil then
    return " " .. L1_3243 .. " @ui_Colon " .. A0_3242.Properties.textDisplayName
  else
    LogWarning(A0_3242:GetName() .. ": Invalid characterId assigned to tracking bracelet.")
    return A0_3242.Properties.textDisplayName
  end
end
