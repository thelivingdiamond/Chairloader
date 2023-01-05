Script.ReloadScript("Scripts/Entities/Ark/Pickups/ArkItem.lua")
ArkPages = {
  Properties = {
    Inventory = {bAddToInventory = 0}
  },
  PropertiesInstance = {note_OnPickup = ""}
}
ArkMakeDerivedEntityOverride(ArkPages, ArkItem, true)
function ArkPages.IsPlotCritical(A0_3219)
  return Ark.IsNotePlotCritical(A0_3219.PropertiesInstance.note_OnPickup)
end
function ArkPages.OnPickup(A0_3220, A1_3221)
  local L2_3222
  L2_3222 = A0_3220.PropertiesInstance
  L2_3222 = L2_3222.note_OnPickup
  if L2_3222 ~= "" then
    g_localActor.arkPlayer:GiveNote(L2_3222)
  else
    LogWarning(A0_3220:GetName() .. " attempted to add a note to player, but no note was specified.")
  end
  BroadcastEvent(A0_3220, "OnPickup")
end
