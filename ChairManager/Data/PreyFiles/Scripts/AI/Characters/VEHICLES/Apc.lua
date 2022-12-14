local L1_253, L2_254
L1_253 = AICharacter
L2_254 = {}
function L2_254.Constructor(A0_255, A1_256)
  A1_256.AI.weaponIdx = 1
end
L2_254.AnyBehavior = {STOP_VEHICLE = "TankIdle"}
L2_254.APCIdle = {
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
L2_254.TankIdle = {
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
L2_254.TankGoto = {
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
L2_254.TankAttack = {
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
L2_254.TankMove = {
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
L2_254.TankAlert = {
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
L2_254.TankEmergencyExit = {
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
L1_253.APC = L2_254
