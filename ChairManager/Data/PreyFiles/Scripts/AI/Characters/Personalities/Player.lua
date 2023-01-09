local L1_243, L2_244
L1_243 = AICharacter
L2_244 = {}
L2_244.Class = UNIT_CLASS_LEADER
function L2_244.InitItems(A0_245, A1_246)
end
function L2_244.Constructor(A0_247, A1_248)
  A0_247:InitItems(A1_248)
  AI.ChangeParameter(A1_248.id, AIPARAM_COMBATCLASS, AICombatClasses.Infantry)
end
L2_244.AnyBehavior = {entered_vehicle = "", entered_vehicle_gunner = ""}
L2_244.PlayerIdle = {
  entered_vehicle = "",
  entered_vehicle_gunner = "",
  START_ATTACK = "PlayerAttack"
}
L2_244.PlayerAttack = {
  entered_vehicle = "",
  entered_vehicle_gunner = "",
  OnLeaderActionCompleted = "PlayerIdle",
  OnLeaderActionFailed = "PlayerIdle"
}
L1_243.Player = L2_244
