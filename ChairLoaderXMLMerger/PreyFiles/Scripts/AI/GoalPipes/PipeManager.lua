local L0_285, L1_286
L0_285 = {}
PipeManager = L0_285
L0_285 = PipeManager
function L1_286(A0_287)
  local L1_288
end
L0_285.OnInit = L1_286
L0_285 = PipeManager
function L1_286(A0_289)
  Script.ReloadScript("Scripts/AI/GoalPipes/PipeManagerVehicle.lua")
  Script.ReloadScript("Scripts/AI/GoalPipes/PipeManagerHuman.lua")
  Script.ReloadScript("Scripts/AI/GoalPipes/PipeManagerReusable.lua")
end
L0_285.ReloadScripts = L1_286
L0_285 = PipeManager
function L1_286(A0_290)
  AI.LoadGoalPipes("Scripts/AI/GoalPipes/GoalPipesShared.xml")
  AI.LoadGoalPipes("Scripts/AI/GoalPipes/GoalPipesCoordination.xml")
  PipeManager:InitVehicle()
  PipeManager:InitHuman()
  PipeManager:InitReusable()
  AI.LoadGoalPipes("Scripts/AI/GoalPipes/GoalPipesHuman.xml")
  AI.LoadGoalPipes("Scripts/AI/GoalPipes/GoalPipesHeli.xml")
  A0_290:CreateAISystemGoalPipes()
end
L0_285.CreateGoalPipes = L1_286
L0_285 = PipeManager
function L1_286(A0_291)
  AI.CreateGoalPipe("_action_")
  AI.PushGoal("_action_", "timeout", 1, 0.1)
  AI.PushGoal("_action_", "branch", 1, -1, BRANCH_ALWAYS)
  AI.CreateGoalPipe("_SETINCODE_HIT_REACT_")
  AI.PushGoal("_SETINCODE_HIT_REACT_", "timeout", 1, 0.1)
  AI.PushGoal("_SETINCODE_HIT_REACT_", "branch", 1, -1, BRANCH_ALWAYS)
  AI.CreateGoalPipe("_last_")
end
L0_285.CreateAISystemGoalPipes = L1_286
