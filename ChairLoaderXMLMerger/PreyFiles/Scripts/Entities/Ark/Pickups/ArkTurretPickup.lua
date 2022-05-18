Script.ReloadScript("Scripts/Entities/Ark/Pickups/ArkItem.lua")
ArkTurretPickup = {
  Properties = {
    archetype_Turret = "",
    textUseMessage = "",
    AI = {bUsedAsDynamicObstacle = 1}
  },
  PropertiesInstance = {bUsedAsDynamicObstacle = 1},
  Editor = {IconOnTop = true, Icon = "mine.bmp"}
}
ArkMakeDerivedEntityOverride(ArkTurretPickup, ArkItem, true)
function ArkTurretPickup.GetUsable(A0_3254)
  local L2_3255, L3_3256
  L2_3255 = {}
  L3_3256 = {}
  L3_3256.ActionType = "ScriptDefined"
  L3_3256.DisplayText = A0_3254.Properties.textUseMessage
  if A0_3254.m_usable == 1 then
    L2_3255.Use = L3_3256
  end
  return L2_3255
end
function ArkTurretPickup.GetRemoteManipulationInteraction(A0_3257)
  local L1_3258
  L1_3258 = {}
  L1_3258.ActionType = "ScriptDefined"
  L1_3258.CouldChange = false
  return L1_3258
end
function ArkTurretPickup.SpawnTurret(A0_3259)
  local L1_3260
  L1_3260 = {}
  L1_3260.class = "ArkTurret"
  L1_3260.archetype = A0_3259.Properties.archetype_Turret
  L1_3260.name = "PickupSpawnedTurret"
  L1_3260.position = A0_3259:GetWorldPos()
  L1_3260.orientation = A0_3259:GetDirectionVector(1)
  System.SpawnEntity(L1_3260)
end
function ArkTurretPickup.OnUsed(A0_3261, A1_3262, A2_3263)
  BroadcastEvent(A0_3261, "OnPickup")
  A0_3261:SpawnTurret()
  if System.IsEditor() then
    A0_3261:Hide(1)
  else
    A0_3261:DeleteThis()
  end
end
function ArkTurretPickup.OnRemoteManipulation(A0_3264, A1_3265)
  A0_3264:OnUsed()
end
function ArkTurretPickup.OnReset(A0_3266, A1_3267)
  ArkItem.OnReset(A0_3266, A1_3267)
  A0_3266:Hide(0)
end
