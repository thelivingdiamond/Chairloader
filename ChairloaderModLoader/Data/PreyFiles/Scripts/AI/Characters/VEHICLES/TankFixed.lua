local L1_275, L2_276
L1_275 = AICharacter
L2_276 = {}
function L2_276.Constructor(A0_277, A1_278)
  A1_278.AI.weaponIdx = 1
end
L2_276.AnyBehavior = {
  STOP_VEHICLE = "TankFixedIdle"
}
L2_276.TankFixedIdle = {
  ACT_GOTO = "TankFixedGoto",
  STOP_VEHICLE = "",
  VEHICLE_GOTO_DONE = "",
  TO_TANKCLOSE_ATTACK = "",
  OnEnemySeen = ""
}
L2_276.TankFixedGoto = {
  ACT_GOTO = "",
  STOP_VEHICLE = "TankFixedIdle",
  VEHICLE_GOTO_DONE = "TankFixedIdle",
  TO_TANKCLOSE_ATTACK = "",
  OnEnemySeen = ""
}
L2_276.TankFixedAttack = {
  ACT_GOTO = "",
  STOP_VEHICLE = "TankFixedIdle",
  VEHICLE_GOTO_DONE = "TankFixedIdle",
  TO_TANKCLOSE_ATTACK = "",
  OnEnemySeen = ""
}
L1_275.TankFixed = L2_276
