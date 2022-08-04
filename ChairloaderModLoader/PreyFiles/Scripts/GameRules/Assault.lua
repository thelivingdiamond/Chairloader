Script.ReloadScript("scripts/gamerules/GameRulesUtils.lua")
Assault = {}
GameRulesSetStandardFuncs(Assault)
Assault.OldCVars = {}
Assault.OldCVars.AllSeeingRadar = nil
Assault.OldCVars.NoEnemiesOnRadar = nil
function Assault.SetupPlayerTeamSpecifics(A0_9451, A1_9452)
  local L2_9453, L3_9454
  L2_9453 = assert
  L3_9454 = A1_9452
  L2_9453(L3_9454)
  L2_9453 = A0_9451.game
  L3_9454 = L2_9453
  L2_9453 = L2_9453.GetTeam
  L2_9453 = L2_9453(L3_9454, A1_9452)
  L3_9454 = L2_9453 and L2_9453 > 0 and L2_9453 == L3_9454
  Log("[tlh] @ Assault:SetupPlayerTeamSpecifics(), isAttacker=%s", tostring(L3_9454))
  if not A0_9451.OldCVars.AllSeeingRadar or A0_9451.OldCVars.AllSeeingRadar == nil then
    A0_9451.OldCVars.AllSeeingRadar = System.GetCVar("g_mpAllSeeingRadar")
  end
  if not A0_9451.OldCVars.NoEnemiesOnRadar or A0_9451.OldCVars.NoEnemiesOnRadar == nil then
    A0_9451.OldCVars.NoEnemiesOnRadar = System.GetCVar("g_mpNoEnemiesOnRadar")
  end
  if L3_9454 and L3_9454 == true then
    System.SetCVar("g_mpNoEnemiesOnRadar", 0)
  else
    System.SetCVar("g_mpAllSeeingRadar", 0)
  end
  A0_9451:SetTeamSpecificsForGeneralPlayer(A1_9452)
end
function Assault.SetupRemotePlayerTeamSpecifics(A0_9455, A1_9456)
  assert(A1_9456)
  assert(A1_9456 ~= g_localActorId)
  A0_9455:SetTeamSpecificsForGeneralPlayer(A1_9456)
end
function Assault.SetTeamSpecificsForGeneralPlayer(A0_9457, A1_9458)
  local L2_9459, L3_9460, L4_9461, L5_9462
  L2_9459 = Log
  L3_9460 = "[tlh] @ Assault:SetTeamSpecificsForGeneralPlayer(playerId)"
  L2_9459(L3_9460)
  L2_9459 = assert
  L3_9460 = A1_9458
  L2_9459(L3_9460)
  L2_9459 = System
  L2_9459 = L2_9459.GetEntity
  L3_9460 = A1_9458
  L2_9459 = L2_9459(L3_9460)
  L3_9460 = assert
  L4_9461 = L2_9459 and L2_9459 ~= nil
  L3_9460(L4_9461)
  if L2_9459 and L2_9459 ~= nil then
    L3_9460 = L2_9459.actor
    if L3_9460 then
      L3_9460 = Log
      L4_9461 = "[tlh]     setting team-specific settings for player \"%s\"..."
      L5_9462 = L2_9459.GetName
      L5_9462 = L5_9462(L2_9459)
      L3_9460(L4_9461, L5_9462, L5_9462(L2_9459))
      L3_9460 = A0_9457.game
      L4_9461 = L3_9460
      L3_9460 = L3_9460.GetTeam
      L5_9462 = A1_9458
      L3_9460 = L3_9460(L4_9461, L5_9462)
      L4_9461 = L3_9460 and L3_9460 > 0 and L3_9460 == L4_9461
      L5_9462 = L2_9459.Properties
      L5_9462 = L5_9462.Damage
      L5_9462 = L5_9462.health
      if not L4_9461 or L4_9461 == false then
        L5_9462 = System.GetCVar("g_mp_as_DefendersMaxHealth")
      end
      if L2_9459.actor then
        Log("[tlh]     setting MaxHealth to %f", L5_9462)
        L2_9459.actor:SetMaxHealth(L5_9462)
      end
    end
  end
end
function Assault.ResetPlayerTeamSpecifics(A0_9463)
  Log("[tlh] @ Assault:ResetTeamSpecifics()")
  if A0_9463.OldCVars.AllSeeingRadar and A0_9463.OldCVars.AllSeeingRadar ~= nil then
    System.SetCVar("g_mpAllSeeingRadar", A0_9463.OldCVars.AllSeeingRadar)
    A0_9463.OldCVars.AllSeeingRadar = nil
  end
  if A0_9463.OldCVars.NoEnemiesOnRadar and A0_9463.OldCVars.NoEnemiesOnRadar ~= nil then
    System.SetCVar("g_mpNoEnemiesOnRadar", A0_9463.OldCVars.NoEnemiesOnRadar)
    A0_9463.OldCVars.NoEnemiesOnRadar = nil
  end
end
function Assault.EquipTeamSpecifics(A0_9464, A1_9465)
  local L2_9466, L3_9467, L4_9468
  L2_9466 = System
  L2_9466 = L2_9466.GetEntity
  L3_9467 = A1_9465
  L2_9466 = L2_9466(L3_9467)
  L3_9467 = A0_9464.game
  L4_9468 = L3_9467
  L3_9467 = L3_9467.GetTeam
  L3_9467 = L3_9467(L4_9468, A1_9465)
  L4_9468 = L3_9467 and L3_9467 > 0 and L3_9467 == L4_9468
  Log("[tlh] @ Assault:EquipTeamSpecifics(), isAttacker=%s", tostring(L4_9468))
  if L4_9468 and L4_9468 == true then
    ItemSystem.GiveItem("FlashBangGrenades", A1_9465, false)
    ItemSystem.GiveItem("Nova", A1_9465, false)
  else
    ItemSystem.GiveItem("FragGrenades", A1_9465, false)
    ItemSystem.GiveItem("K-Volt", A1_9465, false)
    ItemSystem.GiveItem("SCAR", A1_9465, false)
  end
end
