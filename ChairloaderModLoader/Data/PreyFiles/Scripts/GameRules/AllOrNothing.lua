Script.ReloadScript("scripts/gamerules/GameRulesUtils.lua")
AllOrNothing = {}
GameRulesSetStandardFuncs(AllOrNothing)
AllOrNothing.OldCVars = {}
AllOrNothing.OldCVars.AllSeeingRadarSv = nil
function AllOrNothing.SvStartSuddenDeath(A0_9449)
  Log("*** AllOrNothing:SvStartSuddenDeath()")
  if not A0_9449.OldCVars.AllSeeingRadarSv then
    A0_9449.OldCVars.AllSeeingRadarSv = System.GetCVar("g_mpAllSeeingRadarSv")
    Log("    (remembered)")
  end
  System.SetCVar("g_mpAllSeeingRadarSv", 1)
end
function AllOrNothing.SvEndSuddenDeath(A0_9450)
  Log("*** AllOrNothing:SvEndSuddenDeath()")
  if A0_9450.OldCVars.AllSeeingRadarSv then
    System.SetCVar("g_mpAllSeeingRadarSv", A0_9450.OldCVars.AllSeeingRadarSv)
    A0_9450.OldCVars.AllSeeingRadarSv = nil
    Log("    (reverted)")
  end
end
