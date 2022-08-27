Script.ReloadScript("Scripts/Entities/Ark/Pickups/ArkItem.lua")
ArkPsychoscope = {
  Properties = {gametokenid_HasPsychoscope = "", tutorial_PsychoscopeTutorial = ""}
}
ArkMakeDerivedEntityOverride(ArkPsychoscope, ArkItem, true)
function ArkPsychoscope.OnPickup(A0_3230, A1_3231)
  if A1_3231 == g_localActor.id then
    A0_3230:PickupHelper()
  end
end
function ArkPsychoscope.PickupHelper(A0_3232)
  if GameToken.GetTokenFromId(A0_3232.Properties.gametokenid_HasPsychoscope) == "false" then
    GameToken.SetTokenFromId(A0_3232.Properties.gametokenid_HasPsychoscope, true)
    g_localActor.arkPlayer:UnlockPsiScanning(true)
    g_localActor.arkPlayer:AddStatModifier("scopeModSlots", 2)
    g_localActor.arkPlayer:AddStatModifier("psiPointsPool", 50)
  end
  BroadcastEvent(A0_3232, "OnPickup")
end
