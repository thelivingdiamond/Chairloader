local L0_9122, L1_9123
L0_9122 = {}
L1_9123 = {}
L1_9123.bDisableEngine = 0
L1_9123.material = ""
L1_9123.Modification = ""
L1_9123.soclasses_SmartObjectClass = ""
L1_9123.esModularBehaviorTree = ""
L1_9123.Perception = {
  FOVPrimary = -1,
  FOVSecondary = -1,
  sightrange = 200,
  stanceScale = 1,
  persistence = 60
}
L0_9122.Properties = L1_9123
L0_9122.isWheelRetracted = true
L1_9123 = {}
L0_9122.Client = L1_9123
L1_9123 = {}
L0_9122.Server = L1_9123
MH60_Blackhawk = L0_9122
L0_9122 = MH60_Blackhawk
L1_9123 = {}
L1_9123.AIType = AIOBJECT_HELICOPTERCRYSIS2
L1_9123.AICombatClass = SafeTableGet(AICombatClasses, "Heli")
L1_9123.PropertiesInstance = {aibehavior_behaviour = "HeliIdle"}
L1_9123.Properties = {aicharacter_character = "Heli"}
L1_9123.AIMovementAbility = {
  walkSpeed = 15,
  runSpeed = 25,
  sprintSpeed = 40,
  maneuverSpeed = 5,
  b3DMove = 1,
  attackZoneHeight = 6,
  pathType = "AIPATH_DEFAULT",
  minTurnRadius = 1,
  maxTurnRadius = 35,
  optimalFlightHeight = 45,
  minFlightHeight = 25,
  maxFlightHeight = 300,
  pathLookAhead = 40,
  pathSpeedLookAheadPerSpeed = 8,
  cornerSlowDown = 1,
  pathFindPrediction = 2,
  pathRadius = 10,
  velDecay = 60,
  passRadius = 9,
  resolveStickingInTrace = 0,
  pathRegenIntervalDuringTrace = 0,
  avoidanceRadius = 20
}
L0_9122.AIProperties = L1_9123
