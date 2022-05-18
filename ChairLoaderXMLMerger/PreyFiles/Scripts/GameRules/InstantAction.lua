Script.ReloadScript("scripts/gamerules/GameRulesUtils.lua")
InstantAction = {}
GameRulesSetStandardFuncs(InstantAction)
function InstantAction.EquipActor(A0_9520, A1_9521)
  local L2_9522
  L2_9522 = A0_9520.game
  L2_9522 = L2_9522.IsDemoMode
  L2_9522 = L2_9522(L2_9522)
  if L2_9522 ~= 0 then
    return
  end
  L2_9522 = A1_9521.inventory
  if L2_9522 then
    L2_9522 = A1_9521.inventory
    L2_9522 = L2_9522.Destroy
    L2_9522(L2_9522)
  end
  L2_9522 = A1_9521.actor
  if L2_9522 then
    L2_9522 = A1_9521.actor
    L2_9522 = L2_9522.IsPlayer
    L2_9522 = L2_9522(L2_9522)
    if not L2_9522 then
      L2_9522 = A1_9521.Properties
      if L2_9522 then
        L2_9522 = A1_9521.Properties
        L2_9522 = L2_9522.equip_EquipmentPack
        if L2_9522 and L2_9522 ~= "" then
          ItemSystem.GiveItemPack(A1_9521.id, L2_9522, false, false)
          if A1_9521.AssignPrimaryWeapon then
            A1_9521:AssignPrimaryWeapon()
          end
        end
        if not A1_9521.bGunReady then
          A1_9521.actor:HolsterItem(true)
        end
      end
    end
  end
end
