local L1_259, L2_260
L1_259 = AICharacter
L2_260 = {}
L2_260.AnyBehavior = {STOP_VEHICLE = "CarIdle"}
L2_260.CarIdle = {
  ACT_GOTO = "CarGoto",
  STOP_VEHICLE = "",
  VEHICLE_GOTO_DONE = "",
  OnEnemySeen = "CarAlerted",
  TO_CAR_IDLE = "",
  TO_CAR_SKID = "CarSkid"
}
L2_260.CarAlerted = {
  ACT_GOTO = "",
  STOP_VEHICLE = "CarIdle",
  VEHICLE_GOTO_DONE = "",
  OnEnemySeen = "",
  TO_CAR_IDLE = "",
  TO_CAR_SKID = "CarSkid",
  OnNoTarget = "CarIdle"
}
L2_260.CarGoto = {
  ACT_GOTO = "",
  STOP_VEHICLE = "CarIdle",
  VEHICLE_GOTO_DONE = "CarIdle",
  OnEnemySeen = "CarAlerted",
  TO_CAR_IDLE = "",
  TO_CAR_SKID = "CarSkid"
}
L2_260.CarSkid = {
  STOP_VEHICLE = "CarIdle",
  VEHICLE_GOTO_DONE = "",
  OnEnemySeen = "",
  TO_CAR_IDLE = "CarIdle",
  TO_CAR_SKID = ""
}
L1_259.Car = L2_260
