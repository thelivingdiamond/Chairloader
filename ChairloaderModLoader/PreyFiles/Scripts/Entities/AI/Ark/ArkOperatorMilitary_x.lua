Script.ReloadScript("SCRIPTS/Entities/AI/Shared/AIBase.lua")
ArkOperatorMilitary_x = {
  ActionController = "Animations/Mannequin/ADB/Ai_OperatorMilitary_ControllerDefs.xml",
  AnimDatabase3P = "Animations/Mannequin/ADB/Ai_OperatorMilitary_Database.adb",
  ProceduralContextAim = {
    polarCoordinatesSmoothTimeSeconds = 0.5,
    polarCoordinatesMaxYawDegreesPerSecond = 180,
    polarCoordinatesMaxPitchDegreesPerSecond = 80,
    fadeInSeconds = 0.25,
    fadeOutMinDistance = 0,
    fadeOutSeconds = 1,
    fadeOutAngleDegrees = 180,
    maxAngleDegreesXY = 360,
    maxAngleDegreesZ = 180
  }
}
mergef(ArkOperatorMilitary_x, AIBase, 1)
