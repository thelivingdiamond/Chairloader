AI.TacticalPositionManager = AI.TacticalPositionManager or {}
Script.ReloadScript("Scripts/AI/TPS/SDKGruntQueries.lua")
Script.ReloadScript("Scripts/AI/TPS/HumanGruntQueries.lua")
Script.ReloadScript("Scripts/AI/TPS/SharedQueries.lua")
Script.ReloadScript("Scripts/AI/TPS/HelicopterQueries.lua")
function AI.TacticalPositionManager.OnInit(A0_425)
  local L1_426, L2_427, L3_428, L4_429, L5_430
  for L4_429, L5_430 in L1_426(L2_427) do
    if type(L5_430) == "table" and L5_430.OnInit then
      L5_430:OnInit()
    end
  end
end
