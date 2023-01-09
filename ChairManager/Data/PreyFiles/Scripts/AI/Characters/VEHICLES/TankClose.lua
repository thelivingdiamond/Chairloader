local L1_271, L2_272
L1_271 = AICharacter
L2_272 = {}
function L2_272.Constructor(A0_273, A1_274)
  A1_274.AI.weaponIdx = 1
end
L2_272.AnyBehavior = {
  STOP_VEHICLE = "TankCloseIdle"
}
L2_272.TankCloseIdle = {
  ACT_GOTO = "TankCloseGoto",
  STOP_VEHICLE = "",
  VEHICLE_GOTO_DONE = "",
  TO_TANKCLOSE_ATTACK = "TankCloseAttack",
  TO_TANKCLOSE_GOTOPATH = "TankCloseGotoPath",
  TO_TANKCLOSE_SWITCHPATH = "TankCloseSwitchPath",
  TO_TANKCLOSE_RUNAWAY = "TankCloseRunAway",
  TO_TANKCLOSE_IDLE = "",
  OnEnemySeen = ""
}
L2_272.TankCloseGoto = {
  ACT_GOTO = "",
  STOP_VEHICLE = "TankCloseIdle",
  VEHICLE_GOTO_DONE = "TankCloseIdle",
  TO_TANKCLOSE_ATTACK = "",
  TO_TANKCLOSE_GOTOPATH = "",
  TO_TANKCLOSE_SWITCHPATH = "TankCloseSwitchPath",
  TO_TANKCLOSE_RUNAWAY = "TankCloseRunAway",
  TO_TANKCLOSE_IDLE = "",
  OnEnemySeen = "TankCloseAttack"
}
L2_272.TankCloseAttack = {
  ACT_GOTO = "",
  STOP_VEHICLE = "TankCloseIdle",
  VEHICLE_GOTO_DONE = "TankCloseIdle",
  TO_TANKCLOSE_ATTACK = "",
  TO_TANKCLOSE_GOTOPATH = "",
  TO_TANKCLOSE_SWITCHPATH = "TankCloseSwitchPath",
  TO_TANKCLOSE_RUNAWAY = "TankCloseRunAway",
  TO_TANKCLOSE_IDLE = "",
  OnEnemySeen = ""
}
L2_272.TankCloseGotoPath = {
  ACT_GOTO = "",
  STOP_VEHICLE = "TankCloseIdle",
  VEHICLE_GOTO_DONE = "TankCloseIdle",
  TO_TANKCLOSE_ATTACK = "",
  TO_TANKCLOSE_GOTOPATH = "",
  TO_TANKCLOSE_SWITCHPATH = "TankCloseSwitchPath",
  TO_TANKCLOSE_RUNAWAY = "TankCloseRunAway",
  TO_TANKCLOSE_IDLE = "TankCloseIdle",
  OnEnemySeen = "TankCloseAttack"
}
L2_272.TankCloseSwitchPath = {
  ACT_GOTO = "",
  STOP_VEHICLE = "TankCloseIdle",
  VEHICLE_GOTO_DONE = "TankCloseIdle",
  TO_TANKCLOSE_ATTACK = "TankCloseAttack",
  TO_TANKCLOSE_GOTOPATH = "",
  TO_TANKCLOSE_SWITCHPATH = "",
  TO_TANKCLOSE_RUNAWAY = "TankCloseRunAway",
  TO_TANKCLOSE_IDLE = "TankCloseIdle",
  OnEnemySeen = ""
}
L2_272.TankCloseRunAway = {
  ACT_GOTO = "",
  STOP_VEHICLE = "TankCloseIdle",
  VEHICLE_GOTO_DONE = "TankCloseIdle",
  TO_TANKCLOSE_ATTACK = "",
  TO_TANKCLOSE_GOTOPATH = "",
  TO_TANKCLOSE_SWITCHPATH = "",
  TO_TANKCLOSE_RUNAWAY = "",
  TO_TANKCLOSE_IDLE = "TankCloseIdle",
  OnEnemySeen = ""
}
L1_271.TankClose = L2_272
