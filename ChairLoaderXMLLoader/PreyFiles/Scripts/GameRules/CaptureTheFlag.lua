Script.ReloadScript("scripts/gamerules/GameRulesUtils.lua")
CaptureTheFlag = {}
GameRulesSetStandardFuncs(CaptureTheFlag)
CaptureTheFlag.TeamInfo = {
  {
    DbgTeamName = "North Korea",
    Flag = nil,
    Base = nil
  },
  {
    DbgTeamName = "USA",
    Flag = nil,
    Base = nil
  }
}
function CaptureTheFlag.SetupPlayerTeamSpecifics(A0_9469, A1_9470)
  local L2_9471
  L2_9471 = assert
  L2_9471(A1_9470)
  L2_9471 = A0_9469.game
  L2_9471 = L2_9471.GetTeam
  L2_9471 = L2_9471(L2_9471, A1_9470)
  Log("[tlh] @ CaptureTheFlag:SetupPlayerTeamSpecifics(), localTeam = " .. L2_9471)
  A0_9469:RecolourEntitiesOfClass("CTFFlag", L2_9471, A1_9470)
end
function CaptureTheFlag.RecolourEntitiesOfClass(A0_9472, A1_9473, A2_9474, A3_9475)
  local L4_9476, L5_9477, L6_9478, L7_9479, L8_9480, L9_9481
  L4_9476 = Log
  L4_9476(L5_9477)
  L4_9476 = System
  L4_9476 = L4_9476.GetEntitiesByClass
  L4_9476 = L4_9476(L5_9477)
  if L4_9476 then
    for L8_9480, L9_9481 in L5_9477(L6_9478) do
      if L9_9481.id ~= A3_9475 then
        A0_9472:RecolourTeamEntity(L9_9481, A2_9474)
      end
    end
  end
end
function CaptureTheFlag.RecolourTeamEntity(A0_9482, A1_9483, A2_9484)
  local L3_9485
  L3_9485 = A0_9482.game
  L3_9485 = L3_9485.GetTeam
  L3_9485 = L3_9485(L3_9485, A1_9483.id)
  Log("CaptureTheFlag:RecolourTeamEntity - class=\"" .. A1_9483.class .. "\" name=\"" .. A1_9483:GetName() .. "\" teamId=" .. L3_9485 .. " playerTeamId=" .. A2_9484)
  if A1_9483.class == "CTFFlag" then
    A1_9483:LoadCorrectGeometry()
  end
end
