local L1_281, L2_282
L1_281 = AICharacter
L2_282 = {}
L2_282.NoBehaviorFound = {
  BackToJob = "FIRST",
  BackToPrevious = "PREVIOUS",
  START_SWIMMING = "Swim",
  STOP_SWIMMING = "PREVIOUS",
  ORDER_SEARCH = "",
  OnEndFollow = "Job_StandIdle",
  FASTKILL = "FastKill",
  ACT_DIALOG = "Dialog"
}
L2_282.UseMountedTranquilized = {
  OnFallAndPlayWakeUp = "UseMountedIdle",
  RESUME_FOLLOWING = "",
  ENTERING_VEHICLE = "",
  USE_MOUNTED_WEAPON = "",
  OnEnemySeen = "",
  OnBulletRain = "",
  OnGrenadeSeen = "",
  OnSuspiciousSoundHeard = "",
  OnInterestingSoundHeard = "",
  OnThreateningSoundHeard = "",
  entered_vehicle = "",
  exited_vehicle = "",
  exited_vehicle_investigate = "",
  OnSomethingSeen = "",
  GO_TO_SEEK = "",
  GO_TO_IDLE = "",
  GO_TO_SEARCH = "",
  GO_TO_ATTACK = "",
  GO_TO_AVOIDEXPLOSIVES = "",
  GO_TO_ALERT = "",
  GO_TO_CHECKDEAD = ""
}
L2_282.FastKill = {FASTKILL_EXIT = "PREVIOUS", TO_SEEK = ""}
L2_282.Dialog = {ACT_DIALOG_OVER = "PREVIOUS"}
L1_281.DEFAULT = L2_282
