Script.ReloadScript("scripts/gamerules/SinglePlayer.lua")
function GameRulesSetStandardFuncs(A0_9486)
  local L1_9487
  if not A0_9486 then
    return
  end
  L1_9487 = A0_9486.Server
  if not L1_9487 then
    L1_9487 = {}
    A0_9486.Server = L1_9487
  end
  L1_9487 = A0_9486.Client
  if not L1_9487 then
    L1_9487 = {}
    A0_9486.Client = L1_9487
  end
  L1_9487 = A0_9486.Createhit
  if not L1_9487 then
    L1_9487 = SinglePlayer
    L1_9487 = L1_9487.CreateHit
    A0_9486.CreateHit = L1_9487
  end
  L1_9487 = A0_9486.CreateExplosion
  if not L1_9487 then
    L1_9487 = SinglePlayer
    L1_9487 = L1_9487.CreateExplosion
    A0_9486.CreateExplosion = L1_9487
  end
end
