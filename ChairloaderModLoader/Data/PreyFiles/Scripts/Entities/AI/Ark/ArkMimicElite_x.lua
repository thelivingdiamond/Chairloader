Script.ReloadScript("SCRIPTS/Entities/AI/Shared/AIBase.lua")
ArkMimicElite_x = {
  AIMovementAbility = {
    walkSpeed = 5,
    runSpeed = 8,
    sprintSpeed = 12.5,
    maneuverSpeed = 5,
    maxAccel = 40,
    maxDecel = 50,
    pushableObstacleWeakAvoidance = true,
    obstacleAvoidanceMaxPathDeviation = 5,
    ignoreMinimumMassObstaclesAtHighUrgency = 0,
    ignoreMinimumMassObstaclesAtLowUrgency = 0,
    pushableObstacleAvoidanceRadiusMin = 0.15,
    pushableObstacleAvoidanceRadiusMax = 0.35,
    avoidanceRadius = 2,
    collisionAvoidanceRadiusIncrement = 0.01,
    pushableObstacleMassMin = 5,
    pushableObstacleMassMax = 80,
    pushableObstacleHeightMin = 0.25,
    pushableObstacleHeightMax = 1,
    AIMovementSpeeds = {
      Relaxed = {
        Slow = {
          4,
          0,
          4
        },
        Walk = {
          8.5,
          0,
          8.5
        },
        Run = {
          12.5,
          0,
          12.5
        },
        Sprint = {
          12.5,
          0,
          12.5
        }
      },
      Alerted = {
        Slow = {
          4,
          0,
          4
        },
        Walk = {
          8.5,
          0,
          8.5
        },
        Run = {
          12.5,
          0,
          12.5
        },
        Sprint = {
          12.5,
          0,
          12.5
        }
      },
      Combat = {
        Slow = {
          4,
          0,
          4
        },
        Walk = {
          8.5,
          0,
          8.5
        },
        Run = {
          12.5,
          0,
          12.5
        },
        Sprint = {
          12.5,
          0,
          12.5
        }
      }
    }
  }
}
mergef(ArkMimicElite_x, AIBase, 1)
