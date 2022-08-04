local L1_249, L2_250
L1_249 = AICharacter
L2_250 = {}
function L2_250.Constructor(A0_251, A1_252)
  A1_252.AI.weaponIdx = 1
end
L2_250.AnyBehavior = {STOP_VEHICLE = "TankIdle"}
L2_250.AAAIdle = {
  ACT_GOTO = "TankGoto",
  STOP_VEHICLE = "",
  VEHICLE_GOTO_DONE = "",
  TO_TANK_ALERT = "",
  TO_TANK_ALERT2 = "",
  TO_TANK_ATTACK = "",
  TO_TANK_MOVE = "",
  OnEnemySeen = "TankAttack"
}
L2_250.TankIdle = {
  ACT_GOTO = "TankGoto",
  STOP_VEHICLE = "",
  VEHICLE_GOTO_DONE = "",
  TO_TANK_ALERT = "",
  TO_TANK_ALERT2 = "",
  TO_TANK_ATTACK = "",
  TO_TANK_MOVE = "",
  OnEnemySeen = "TankAttack"
}
L2_250.TankGoto = {
  ACT_GOTO = "",
  STOP_VEHICLE = "TankIdle",
  VEHICLE_GOTO_DONE = "TankIdle",
  TO_TANK_ALERT = "",
  TO_TANK_ALERT2 = "",
  TO_TANK_ATTACK = "",
  TO_TANK_MOVE = "",
  OnEnemySeen = "TankAttack"
}
L2_250.TankAttack = {
  ACT_GOTO = "",
  STOP_VEHICLE = "TankIdle",
  VEHICLE_GOTO_DONE = "",
  TO_TANK_ALERT = "",
  TO_TANK_ALERT2 = "",
  TO_TANK_ATTACK = "",
  TO_TANK_MOVE = "TankMove",
  OnEnemySeen = ""
}
L2_250.TankMove = {
  ACT_GOTO = "",
  STOP_VEHICLE = "TankIdle",
  VEHICLE_GOTO_DONE = "",
  TO_TANK_ALERT = "",
  TO_TANK_ALERT2 = "TankAlert",
  TO_TANK_ATTACK = "TankAttack",
  TO_TANK_MOVE = "",
  OnEnemySeen = ""
}
L2_250.TankAlert = {
  ACT_GOTO = "",
  STOP_VEHICLE = "TankIdle",
  VEHICLE_GOTO_DONE = "",
  TO_TANK_ALERT = "",
  TO_TANK_ALERT2 = "",
  TO_TANK_ATTACK = "TankAttack",
  TO_TANK_MOVE = "",
  OnEnemySeen = ""
}
L1_249.AAA = L2_250
