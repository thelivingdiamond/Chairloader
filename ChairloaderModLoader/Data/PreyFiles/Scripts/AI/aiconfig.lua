AI.LogEvent("[AISYSTEM] AIConfig starts  -------------------------------------")
Script.ReloadScript("Scripts/AI/Anchor.lua")
Script.ReloadScript("Scripts/AI/Group.lua")
Script.ReloadScript("Scripts/AI/pathfindProperties.lua")
Script.ReloadScript("Scripts/AI/Characters/AICharacter.lua")
Script.ReloadScript("Scripts/AI/GoalPipes/PipeManager.lua")
Script.ReloadScript("Scripts/AI/Formations/FormationManager.lua")
Script.ReloadScript("Scripts/AI/Logic/AI_Utils.lua")
Script.ReloadScript("SCRIPTS/AI/Logic/BlackBoard.lua")
function ReloadTPS()
  AI.DestroyAllTPSQueries()
  Script.ReloadScript("Scripts/AI/TacticalPositionManager.lua")
  AI.TacticalPositionManager:OnInit()
end
function ReloadTPSExtensions()
  ReloadTPS()
  if PipeManager then
    PipeManager:OnInit()
  end
end
function AIReload()
  ReloadTPSExtensions()
  assignmentsHaveBeenCreated = nil
end
if FormationManager then
  FormationManager:OnInit()
end
AI.SetAssesmentMultiplier(AIOBJECT_PLAYER, 1)
AI.SetAssesmentMultiplier(AIOBJECT_ATTRIBUTE, 1)
AI.SetAssesmentMultiplier(AIOBJECT_RPG, 100)
AICombatClasses = {}
AI.AddCombatClass()
AICombatClasses.Player = 0
AICombatClasses.PlayerRPG = 1
AICombatClasses.Infantry = 2
AICombatClasses.InfantryRPG = 3
AICombatClasses.Tank = 4
AICombatClasses.TankHi = 5
AICombatClasses.Heli = 6
AICombatClasses.VehicleGunner = 7
AICombatClasses.Hunter = 8
AICombatClasses.Civilian = 9
AICombatClasses.Car = 10
AICombatClasses.Warrior = 11
AICombatClasses.AAA = 12
AICombatClasses.BOAT = 13
AICombatClasses.APC = 14
AICombatClasses.Squadmate = 15
AICombatClasses.Scout = 16
AICombatClasses.ascensionScout = 17
AICombatClasses.ascensionVTOL = 18
AICombatClasses.ascensionScout2 = 19
AI.AddCombatClass(AICombatClasses.Player, {
  1,
  1,
  1,
  1,
  1.1,
  1.1,
  1,
  1,
  2,
  0,
  0,
  0,
  1,
  1,
  1,
  0.1,
  1,
  1,
  0,
  0
})
AI.AddCombatClass(AICombatClasses.PlayerRPG, {
  1,
  1,
  1,
  1,
  1.5,
  1.5,
  1,
  1,
  2,
  0,
  1.2,
  0,
  1.2,
  1,
  1.2,
  0.1,
  1,
  1,
  0,
  0
})
AI.AddCombatClass(AICombatClasses.Infantry, {
  1,
  1,
  1,
  1,
  1.1,
  1.1,
  1,
  1,
  2,
  0,
  0,
  0,
  1,
  1,
  1,
  0.1,
  1,
  1,
  0,
  0
})
AI.AddCombatClass(AICombatClasses.InfantryRPG, {
  1,
  1,
  1,
  1,
  1.5,
  1.5,
  1,
  1,
  2,
  0,
  1.2,
  0,
  1.2,
  1,
  1.2,
  0.1,
  1,
  1,
  0,
  0
})
AI.AddCombatClass(AICombatClasses.Tank, {
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  1,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  1
}, "OnTankSeen")
AI.AddCombatClass(AICombatClasses.TankHi, {
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  1,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  1
}, "OnTankSeen")
AI.AddCombatClass(AICombatClasses.Heli, {
  1,
  1,
  1,
  1,
  0.9,
  0.9,
  1,
  1,
  1,
  0,
  1,
  0,
  0.9,
  1,
  0.9,
  1,
  1,
  1,
  0,
  1
}, "OnHeliSeen")
AI.AddCombatClass(AICombatClasses.VehicleGunner, {
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  1,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  1
})
AI.AddCombatClass(AICombatClasses.Hunter, {
  1,
  1.2,
  0.8,
  1,
  2,
  2,
  2,
  1,
  2,
  0,
  1,
  0,
  2,
  2,
  2,
  0.8,
  1.5,
  0,
  0,
  0
})
AI.AddCombatClass(AICombatClasses.Civilian, {
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  0.5,
  0,
  1,
  1,
  1,
  0.1,
  1,
  0,
  0,
  0
})
AI.AddCombatClass(AICombatClasses.Car, {
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0
})
AI.AddCombatClass(AICombatClasses.Warrior, {
  0.05,
  0.2,
  0.05,
  0.2,
  0.2,
  1.5,
  2,
  1.5,
  0.05,
  0.05,
  1.5,
  1.5,
  1.5,
  0.2,
  1.5,
  0.05,
  0.05,
  0,
  0,
  0
})
AI.AddCombatClass(AICombatClasses.AAA, {
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  1,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  1
}, "OnTankSeen")
AI.AddCombatClass(AICombatClasses.BOAT, {
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  1,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  1
}, "OnBoatSeen")
AI.AddCombatClass(AICombatClasses.APC, {
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  1,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  1
}, "OnTankSeen")
AI.AddCombatClass(AICombatClasses.Squadmate, {
  1,
  1,
  1,
  1,
  1.1,
  1.1,
  1,
  1,
  2,
  0,
  0,
  0,
  1,
  1,
  1,
  1,
  1,
  0,
  0,
  0
})
AI.AddCombatClass(AICombatClasses.Scout, {
  1,
  1,
  0.7,
  0.7,
  0.9,
  0.9,
  1,
  0.7,
  1,
  0,
  1,
  0,
  0.9,
  0.9,
  0.9,
  0.7,
  1,
  1,
  0,
  0
})
AI.AddCombatClass(AICombatClasses.ascensionScout, {
  1,
  1,
  0,
  0.5,
  0.5,
  0,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0
})
AI.AddCombatClass(AICombatClasses.ascensionVTOL, {
  1,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0
})
AI.AddCombatClass(AICombatClasses.ascensionScout2, {
  1,
  1,
  0,
  0.7,
  0.7,
  0,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0
})
function AIReset()
  AIBlackBoard_Reset()
  spectacularKillInProgress = false
  lastWalkabilityCheckTime = false
end
function AI.OnSave(A0_350, A1_351)
  A1_351.AIBlackBoard = AIBlackBoard
end
function AI.OnLoad(A0_352, A1_353)
  AIBlackBoard_Reset()
  merge(AIBlackBoard, A1_353.AIBlackBoard)
end
function AI.OnEditorMoveSimulation(A0_354, A1_355, A2_356, A3_357)
  AI.SetRefPointPosition(A1_355.id, A3_357)
  A1_355:InsertSubpipe(AIGOALPIPE_SAMEPRIORITY, "MoveToMiddleClickPositionInEditor", nil, A2_356)
end
AI.LogEvent("[AISSYSTEM] CONFIG SCRIPT FILE LOADED. --------------------------")
