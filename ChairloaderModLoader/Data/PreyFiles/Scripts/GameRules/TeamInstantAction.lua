Script.ReloadScript("scripts/gamerules/GameRulesUtils.lua")
TeamInstantAction = {}
GameRulesSetStandardFuncs(TeamInstantAction)
function TeamInstantAction.EquipActor(A0_9657, A1_9658)
  local L2_9659
  L2_9659 = A0_9657.game
  L2_9659 = L2_9659.IsDemoMode
  L2_9659 = L2_9659(L2_9659)
  if L2_9659 ~= 0 then
    return
  end
  L2_9659 = A1_9658.inventory
  if L2_9659 then
    L2_9659 = A1_9658.inventory
    L2_9659 = L2_9659.Destroy
    L2_9659(L2_9659)
  end
  L2_9659 = A1_9658.actor
  if L2_9659 then
    L2_9659 = A1_9658.actor
    L2_9659 = L2_9659.IsPlayer
    L2_9659 = L2_9659(L2_9659)
    if not L2_9659 then
      L2_9659 = A1_9658.Properties
      if L2_9659 then
        L2_9659 = A1_9658.Properties
        L2_9659 = L2_9659.equip_EquipmentPack
        if L2_9659 and L2_9659 ~= "" then
          ItemSystem.GiveItemPack(A1_9658.id, L2_9659, false, false)
          if A1_9658.AssignPrimaryWeapon then
            A1_9658:AssignPrimaryWeapon()
          end
        end
        if not A1_9658.bGunReady then
          A1_9658.actor:HolsterItem(true)
        end
      end
    end
  end
end
