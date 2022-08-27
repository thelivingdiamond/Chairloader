local L1_267, L2_268
L1_267 = AICharacter
L2_268 = {}
function L2_268.Constructor(A0_269, A1_270)
  A1_270.AI.weaponIdx = 1
end
L2_268.AnyBehavior = {STOP_VEHICLE = "TankIdle"}
L2_268.TankIdle = {
  ACT_GOTO = "TankGoto",
  STOP_VEHICLE = "",
  VEHICLE_GOTO_DONE = "",
  TO_TANK_ALERT = "",
  TO_TANK_ALERT2 = "",
  TO_TANK_ATTACK = "",
  TO_TANK_MOVE = "",
  OnEnemySeen = "TankAttack",
  TO_TANK_EMERGENCYEXIT = "",
  TO_TANK_IDLE = "TankIdle"
}
L2_268.TankGoto = {
  ACT_GOTO = "",
  STOP_VEHICLE = "TankIdle",
  VEHICLE_GOTO_DONE = "TankIdle",
  TO_TANK_ALERT = "",
  TO_TANK_ALERT2 = "",
  TO_TANK_ATTACK = "",
  TO_TANK_MOVE = "",
  OnEnemySeen = "TankAttack",
  TO_TANK_EMERGENCYEXIT = "",
  TO_TANK_IDLE = "TankIdle"
}
L2_268.TankAttack = {
  ACT_GOTO = "",
  STOP_VEHICLE = "TankIdle",
  VEHICLE_GOTO_DONE = "",
  TO_TANK_ALERT = "",
  TO_TANK_ALERT2 = "",
  TO_TANK_ATTACK = "",
  TO_TANK_MOVE = "TankMove",
  OnEnemySeen = "",
  TO_TANK_EMERGENCYEXIT = "",
  TO_TANK_IDLE = "TankIdle"
}
L2_268.TankMove = {
  ACT_GOTO = "",
  STOP_VEHICLE = "TankIdle",
  VEHICLE_GOTO_DONE = "",
  TO_TANK_ALERT = "",
  TO_TANK_ALERT2 = "TankAlert",
  TO_TANK_ATTACK = "TankAttack",
  TO_TANK_MOVE = "",
  OnEnemySeen = "",
  TO_TANK_EMERGENCYEXIT = "TankEmergencyExit",
  TO_TANK_IDLE = "TankIdle"
}
L2_268.TankAlert = {
  ACT_GOTO = "",
  STOP_VEHICLE = "TankIdle",
  VEHICLE_GOTO_DONE = "",
  TO_TANK_ALERT = "",
  TO_TANK_ALERT2 = "",
  TO_TANK_ATTACK = "TankAttack",
  TO_TANK_MOVE = "",
  OnEnemySeen = "",
  TO_TANK_EMERGENCYEXIT = "",
  TO_TANK_IDLE = "TankIdle"
}
L2_268.TankEmergencyExit = {
  ACT_GOTO = "",
  STOP_VEHICLE = "TankIdle",
  VEHICLE_GOTO_DONE = "",
  TO_TANK_ALERT = "",
  TO_TANK_ALERT2 = "",
  TO_TANK_ATTACK = "TankAttack",
  TO_TANK_MOVE = "",
  OnEnemySeen = "",
  TO_TANK_EMERGENCYEXIT = "",
  TO_TANK_IDLE = "TankIdle"
}
L1_267.Tank = L2_268
