Script.ReloadScript("Scripts/Entities/Ark/Pickups/ArkItem.lua")
ArkFabricationPlan = {
  Properties = {
    fabricationplan_Plan = "",
    gametokenid_FirstAcquiredToken = "",
    bUnlimited = 0,
    Inventory = {bAddToInventory = 0}
  },
  Editor = {Icon = "Seed.bmp"},
  m_bVerbose = false,
  m_audioIds = {}
}
ArkMakeDerivedEntityOverride(ArkFabricationPlan, ArkItem, true)
ArkFabricationPlanPharma = ArkFabricationPlan
ArkFabricationPlanCharge = ArkFabricationPlan
ArkFabricationPlanAmmo = ArkFabricationPlan
ArkFabricationPlanWeapon = ArkFabricationPlan
ArkFabricationPlanSuitMaint = ArkFabricationPlan
function ArkFabricationPlan.GetRandomPlan(A0_3140)
  return A0_3140.Properties.fabricationplan_Plan
end
function ArkFabricationPlan.OnPickup(A0_3141, A1_3142)
  if A1_3142 == g_localActorId then
    g_localActor.arkPlayer:GiveFabricationPlan(A0_3141.Properties.fabricationplan_Plan, A0_3141.arkitem:GetCount(), A0_3141.Properties.bUnlimited)
  end
  BroadcastEvent(A0_3141, "OnPickup")
end
ArkFabricationPlan.FlowEvents = {
  Inputs = {},
  Outputs = {OnPickup = "bool"}
}
