Script.ReloadScript("Scripts/Entities/Ark/Pickups/ArkItem.lua")
ArkZeroGSuit = {
  Properties = {
    fPropulsionForce = 0,
    fPropulsionDuration = 0,
    gametokenid_PlayerHasZeroGSuit = "",
    tutorial_ZeroGSuitTutorial = ""
  }
}
ArkMakeDerivedEntityOverride(ArkZeroGSuit, ArkItem, true)
function ArkZeroGSuit.OnPickup(A0_3268, A1_3269)
  if A1_3269 == g_localActorId then
    A0_3268:PickupHelper()
  end
end
function ArkZeroGSuit.PickupHelper(A0_3270)
  local L1_3271
  L1_3271 = A0_3270.Properties
  if GameToken.GetTokenFromId(A0_3270.Properties.gametokenid_PlayerHasZeroGSuit) ~= "true" then
    GameToken.SetTokenFromId(A0_3270.Properties.gametokenid_PlayerHasZeroGSuit, true)
    g_localActor.arkPlayer:AddStatModifier("propulsionForce", L1_3271.fPropulsionForce, "Propulsion Suit Pickup")
    g_localActor.arkPlayer:AddStatModifier("propulsionDuration", L1_3271.fPropulsionDuration, "Propulsion Suit Pickup")
    Ark.DisplayTutorial(A0_3270.Properties.tutorial_ZeroGSuitTutorial)
  end
  BroadcastEvent(A0_3270, "OnPickup")
  A0_3270:ActivateOutput("ItemType", A0_3270.Properties.sType)
end
