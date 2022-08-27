local L0_344, L1_345
L0_344 = AI
L0_344 = L0_344.TacticalPositionManager
L1_345 = AI
L1_345 = L1_345.TacticalPositionManager
L1_345 = L1_345.SDKGrunt
L1_345 = L1_345 or {}
L0_344.SDKGrunt = L1_345
L0_344 = AI
L0_344 = L0_344.TacticalPositionManager
L0_344 = L0_344.SDKGrunt
function L1_345(A0_346)
  AI.RegisterTacticalPointQuery({
    Name = "SDKGrunt_CoverFromUnknownEnemy",
    {
      Generation = {cover_from_attentionTarget_around_puppet = 15},
      Conditions = {},
      Weights = {distance_to_puppet = -1}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "SDKGrunt_GetAwayFromUnknownEnemy",
    {
      Generation = {grid_around_puppet = 5},
      Conditions = {isInNavigationMesh = true},
      Weights = {distance_to_attentionTarget = 0.75, towards_the_attentionTarget = -1}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "SDKGrunt_OpenCombat",
    {
      Generation = {grid_around_attentionTarget = 15},
      Conditions = {
        canShoot_to_attentionTarget = true,
        min_distance_to_attentionTarget = 5,
        max_distance_to_attentionTarget = 15,
        isInNavigationMesh = true
      },
      Weights = {random = 1}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "SDKGrunt_OpenCombat_LimitedTravelDistance",
    {
      Parameters = {density = 4},
      Generation = {grid_around_attentionTarget = 15},
      Conditions = {
        canShoot_to_attentionTarget = true,
        min_distance_to_attentionTarget = 5,
        max_distance_to_puppet = 10,
        isInNavigationMesh = true
      },
      Weights = {random = 1}
    },
    {
      Parameters = {density = 4},
      Generation = {grid_around_attentionTarget = 15},
      Conditions = {
        min_distance_to_attentionTarget = 5,
        max_distance_to_puppet = 10,
        isInNavigationMesh = true
      },
      Weights = {
        random = 0.5,
        distance_to_attentionTarget = -0.5,
        distance_to_puppet = -1
      }
    },
    {
      Generation = {grid_around_puppet = 10},
      Conditions = {isInNavigationMesh = true},
      Weights = {random = 0.5, distance_to_attentionTarget = -0.5}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "SDKGrunt_CoverToShootFrom",
    {
      Generation = {cover_from_attentionTarget_around_puppet = 15},
      Conditions = {hasShootingPosture_to_attentionTarget = true, min_distance_to_attentionTarget = 5},
      Weights = {distance_to_puppet = -1}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "SDKGrunt_CoverToShootFrom_LimitedTravelDistance",
    {
      Generation = {cover_from_attentionTarget_around_puppet = 15},
      Conditions = {
        hasShootingPosture_to_attentionTarget = true,
        min_distance_to_attentionTarget = 5,
        max_distance_to_puppet = 10
      },
      Weights = {distance_to_puppet = -1}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "SDKGrunt_TargetPositionOnNavMesh",
    {
      Generation = {grid_around_attentionTarget = 20},
      Conditions = {isInNavigationMesh = true},
      Weights = {distance_to_attentionTarget = -1}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "SDKGrunt_RandomSearchSpotAroundPuppet",
    {
      Generation = {grid_around_puppet = 30},
      Conditions = {
        min_distance_to_puppet = 10,
        visible_from_puppet = false,
        isInNavigationMesh = true
      },
      Weights = {distance_to_puppet = -0.5, random = 1}
    },
    {
      Generation = {grid_around_puppet = 30},
      Conditions = {min_distance_to_puppet = 10, isInNavigationMesh = true},
      Weights = {distance_to_puppet = -0.5, random = 1}
    },
    {
      Generation = {grid_around_puppet = 30},
      Conditions = {min_distance_to_puppet = 5, isInNavigationMesh = true},
      Weights = {distance_to_puppet = -0.5, random = 1}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "SDKGrunt_CombatMove_CoverFromTarget",
    {
      Generation = {cover_from_attentionTarget_around_puppet = 25},
      Conditions = {
        min_distance_to_puppet = 5,
        towards_the_referencePoint = true,
        min_distance_to_referencePoint = 4
      },
      Weights = {distance_to_puppet = -1}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "SDK_Grunt_DefendArea_Cover",
    {
      Generation = {cover_from_attentionTarget_around_puppet = 15},
      Conditions = {hasShootingPosture_to_attentionTarget = true, min_distance_to_attentionTarget = 5},
      Weights = {distance_to_puppet = -1}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "SDK_Grunt_DefendArea_RandomPointAroundRefPoint",
    {
      Generation = {grid_around_referencePoint = 10},
      Conditions = {isInNavigationMesh = true},
      Weights = {random = 1}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "SDK_Grunt_HoldPosition_Cover",
    {
      Generation = {cover_from_attentionTarget_around_referencePoint = 3},
      Conditions = {hasShootingPosture_to_attentionTarget = true, min_distance_to_attentionTarget = 5},
      Weights = {distance_to_puppet = -1}
    }
  })
end
L0_344.OnInit = L1_345
