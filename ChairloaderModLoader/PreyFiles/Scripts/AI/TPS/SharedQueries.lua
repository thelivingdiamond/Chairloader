local L0_347, L1_348
L0_347 = AI
L0_347 = L0_347.TacticalPositionManager
L1_348 = AI
L1_348 = L1_348.TacticalPositionManager
L1_348 = L1_348.Shared
L1_348 = L1_348 or {}
L0_347.Shared = L1_348
L0_347 = AI
L0_347 = L0_347.TacticalPositionManager
L0_347 = L0_347.Shared
function L1_348(A0_349)
  AI.RegisterTacticalPointQuery({
    Name = "HoldPositionCover",
    {
      Generation = {cover_from_attentionTarget_around_referencePoint = 3},
      Conditions = {
        max_heightRelative_to_referencePoint = 1.5,
        min_heightRelative_to_referencePoint = -1.5,
        min_distance_to_attentionTarget = 5,
        hasShootingPosture_to_attentionTarget = true
      },
      Weights = {distance_to_puppet = -0.5}
    },
    {
      Generation = {cover_from_attentionTarget_around_referencePoint = 3},
      Conditions = {
        max_heightRelative_to_referencePoint = 1.5,
        min_heightRelative_to_referencePoint = -1.5,
        min_distance_to_attentionTarget = 5
      },
      Weights = {distance_to_puppet = -0.5}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "CoverAroundHoldPositionFromReferencePointDirection",
    {
      Generation = {cover_from_referencePointOffsettedByItsForwardDirection_around_referencePoint = 3},
      Conditions = {
        max_heightRelative_to_referencePoint = 1.5,
        min_heightRelative_to_referencePoint = -1.5,
        hasShootingPosture_to_referencePointOffsettedByItsForwardDirection = true
      },
      Weights = {distance_to_puppet = -0.5}
    },
    {
      Generation = {cover_from_referencePointOffsettedByItsForwardDirection_around_referencePoint = 3},
      Conditions = {max_heightRelative_to_referencePoint = 1.5, min_heightRelative_to_referencePoint = -1.5},
      Weights = {distance_to_puppet = -0.5}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "CombatMove",
    {
      Generation = {cover_from_attentionTarget_around_puppet = 15},
      Conditions = {
        min_distance_to_puppet = 7,
        towards_the_referencePoint = true,
        hasShootingPosture_to_attentionTarget = true,
        min_dot_to_referencePoint = 0.85
      },
      Weights = {distance_to_puppet = -1}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "CombatMoveCoverFromTarget",
    {
      Generation = {cover_from_attentionTarget_around_puppet = 15},
      Conditions = {
        min_distance_to_puppet = 7,
        towards_the_referencePoint = true,
        hasShootingPosture_to_attentionTarget = true,
        min_dot_to_referencePoint = 0.85
      },
      Weights = {distance_to_puppet = -1}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "CombatMoveCoverFromRefPoint",
    {
      Generation = {cover_from_referencePoint_around_puppet = 15},
      Conditions = {
        min_distance_to_puppet = 7,
        towards_the_referencePoint = true,
        min_dot_to_referencePoint = 0.85
      },
      Weights = {distance_to_puppet = -1}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "CombatMoveSimple",
    {
      Generation = {cover_from_attentionTarget_around_puppet = 15},
      Conditions = {
        min_distance_to_puppet = 7,
        towards_the_referencePoint = true,
        min_dot_to_referencePoint = 0.85
      },
      Weights = {distance_to_puppet = -1}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "AvoidThreatCover",
    {
      Generation = {cover_from_referencePoint_around_puppet = 15},
      Conditions = {min_distance_to_attentionTarget = 5, min_distance_to_referencePoint = 6},
      Weights = {
        distance_to_puppet = -0.25,
        distance_to_referencePoint = 1,
        otherSide_of_referencePoint = -3,
        distance_to_attentionTarget = 0.5
      }
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "AvoidThreatGridSmall",
    {
      Parameters = {density = 5},
      Generation = {grid_around_puppet = 7},
      Conditions = {min_distance_to_referencePoint = 4, isInNavigationMesh = true},
      Weights = {
        distance_to_puppet = -0.25,
        distance_to_referencePoint = 0.75,
        towards_the_referencePoint = -1,
        distance_to_attentionTarget = 0.5
      }
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "AvoidThreatGrid",
    {
      Parameters = {density = 5},
      Generation = {grid_around_puppet = 15},
      Conditions = {min_distance_to_referencePoint = 8, isInNavigationMesh = true},
      Weights = {
        distance_to_puppet = -0.25,
        distance_to_referencePoint = 0.75,
        towards_the_referencePoint = -1,
        distance_to_attentionTarget = 0.5
      }
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "CombatHidespotQuery",
    {
      Generation = {cover_from_attentionTarget_around_puppet = 25},
      Conditions = {
        min_distance_to_attentionTarget = 5,
        canReachBefore_the_attentionTarget = true,
        max_distance_from_battlefront = 15,
        hasShootingPosture_to_attentionTarget = true
      },
      Weights = {distance_to_puppet = -0.05, distance_to_attentionTarget = -0.05}
    },
    {
      Generation = {cover_from_attentionTarget_around_puppet = 25},
      Conditions = {
        min_distance_to_attentionTarget = 5,
        canReachBefore_the_attentionTarget = true,
        hasShootingPosture_to_attentionTarget = true
      },
      Weights = {
        distance_to_puppet = -0.1,
        distance_to_attentionTarget = -0.2,
        distance_to_battlefront = -0.7
      }
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "FlankQuery",
    {
      Generation = {cover_from_attentionTarget_around_puppet = 25},
      Conditions = {
        min_distance_from_puppet = 3,
        myflank_to_attentionTarget = true,
        max_directness_to_attentionTarget = 0.4
      },
      Weights = {distance_to_attentionTarget = -1}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "FlankLeftQuery",
    {
      Generation = {cover_from_attentionTarget_around_puppet = 25},
      Conditions = {
        min_distance_from_puppet = 5,
        min_distance_from_attentionTarget = 5,
        max_distanceLeft_to_attentionTarget = 0,
        towards_the_attentionTarget = true,
        crossesLineOfFire_to_attentionTarget = false
      },
      Weights = {
        distance_to_attentionTarget = -0.4,
        directness_to_attentionTarget = -0.25,
        distance_to_puppet = -0.35
      }
    },
    {
      Generation = {cover_from_attentionTarget_around_puppet = 25},
      Conditions = {
        min_distance_from_puppet = 2,
        min_distance_from_attentionTarget = 4,
        towards_the_attentionTarget = true
      },
      Weights = {
        distance_to_attentionTarget = -0.35,
        directness_to_attentionTarget = -0.2,
        distance_to_puppet = -0.3,
        distanceLeft_to_attentionTarget = 0.15
      }
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "FlankRightQuery",
    {
      Generation = {cover_from_attentionTarget_around_puppet = 25},
      Conditions = {
        min_distance_from_puppet = 5,
        min_distance_from_attentionTarget = 5,
        min_distanceLeft_to_attentionTarget = 0,
        towards_the_attentionTarget = true,
        crossesLineOfFire_to_attentionTarget = false
      },
      Weights = {
        distance_to_attentionTarget = -0.4,
        directness_to_attentionTarget = -0.25,
        distance_to_puppet = -0.35
      }
    },
    {
      Generation = {cover_from_attentionTarget_around_puppet = 25},
      Conditions = {
        min_distance_from_puppet = 2,
        min_distance_from_attentionTarget = 4,
        towards_the_attentionTarget = true
      },
      Weights = {
        distance_to_attentionTarget = -0.35,
        directness_to_attentionTarget = -0.2,
        distance_to_puppet = -0.3,
        distanceLeft_to_attentionTarget = -0.15
      }
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "DefendHidespotQuery",
    {
      Generation = {cover_from_attentionTarget_around_referencePoint = 35},
      Conditions = {},
      Weights = {
        distance_to_puppet = -0.05,
        distance_to_referencePoint = -0.125,
        directness_to_attentionTarget = -0.075,
        canReachBefore_the_attentionTarget = 1
      }
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "DefendHidespotUnderPressureQuery",
    {
      Generation = {cover_from_attentionTarget_around_referencePoint = 25},
      Conditions = {},
      Weights = {distance_to_puppet = -1}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "ApproachHidespotQuery",
    {
      Generation = {cover_from_attentionTarget_around_puppet = 15},
      Conditions = {
        min_distance_to_puppet = 1,
        min_distance_to_attentionTarget = 10,
        towards_the_attentionTarget = true,
        max_distance_to_battlefront = 20
      },
      Weights = {distance_from_puppet = -0.3, distance_from_attentionTarget = -0.7}
    },
    {
      Generation = {cover_from_attentionTarget_around_puppet = 15},
      Conditions = {
        min_distance_to_puppet = 1,
        min_distance_to_attentionTarget = 10,
        towards_the_attentionTarget = true
      },
      Weights = {
        distance_from_puppet = -0.1,
        distance_from_attentionTarget = -0.6,
        distance_to_battlefront = -0.3
      }
    },
    {
      Generation = {cover_from_attentionTarget_around_puppet = 25},
      Conditions = {min_distance_from_puppet = 1},
      Weights = {
        directness_to_attentionTarget = 1,
        distance_from_attentionTarget = -0.7,
        distance_to_battlefront = -0.3
      }
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "UnderPressureHidespotQuery",
    {
      Generation = {cover_from_attentionTarget_around_puppet = 20},
      Conditions = {min_distance_to_attentionTarget = 7, canReachBefore_the_attentionTarget = true},
      Weights = {distance_to_puppet = -0.1, distance_to_attentionTarget = -0.01}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "LowAmmoHidespotQuery",
    {
      Generation = {cover_from_attentionTarget_around_puppet = 20},
      Conditions = {min_distance_to_attentionTarget = 7, canReachBefore_the_attentionTarget = true},
      Weights = {distance_to_puppet = -0.1, distance_to_attentionTarget = -0.01}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "SearchApproachHidespotQuery",
    {
      Generation = {cover_from_attentionTarget_around_puppet = 25},
      Conditions = {
        max_directness_to_attentionTarget = 0.7,
        min_distance_to_puppet = 4,
        towards_the_attentionTarget = true
      },
      Weights = {distance_from_attentionTarget = -1, directness_to_attentionTarget = 1}
    },
    {
      Generation = {cover_from_attentionTarget_around_puppet = 25},
      Conditions = {min_distance_to_puppet = 1, towards_the_attentionTarget = true},
      Weights = {distance_from_attentionTarget = -1}
    },
    {
      Generation = {cover_from_attentionTarget_around_puppet = 40},
      Conditions = {},
      Weights = {distance_from_attentionTarget = -1}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "ScannerSearchQuery",
    {
      Parameters = {density = 5},
      Generation = {grid_around_puppet = 7},
      Conditions = {min_distance_to_puppet = 2},
      Weights = {distance_to_attentionTarget = -0.5, random = 1}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "VisorSearchQuery",
    {
      Parameters = {density = 5},
      Generation = {grid_around_attentionTarget = 5},
      Conditions = {min_distance_to_puppet = 2},
      Weights = {distance_to_puppet = -0.1, random = 0.5}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "CloseSearchQuery",
    {
      Parameters = {density = 5},
      Generation = {grid_around_attentionTarget = 5},
      Conditions = {min_distance_to_puppet = 2},
      Weights = {distance_to_puppet = -0.1, random = 0.5}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "ApproachTargetQuery",
    {
      Parameters = {density = 7},
      Generation = {grid_around_attentionTarget = 12},
      Conditions = {},
      Weights = {
        visible_from_attentionTarget = 1,
        distance_to_puppet = -0.7,
        distance_to_battlefront = -0.3
      }
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "ClosestHideSpotQuery",
    {
      Generation = {cover_from_attentionTarget_around_puppet = 15},
      Conditions = {},
      Weights = {distance_to_puppet = -1}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "DefendAreaCover",
    {
      Generation = {cover_from_attentionTarget_around_referencePoint = 15},
      Conditions = {
        min_distance_to_attentionTarget = 5,
        min_distance_to_puppet = 2,
        hasShootingPosture_to_attentionTarget = true
      },
      Weights = {distance_to_puppet = -0.5}
    },
    {
      Generation = {cover_from_attentionTarget_around_referencePoint = 15},
      Conditions = {min_distance_to_attentionTarget = 5, hasShootingPosture_to_attentionTarget = true},
      Weights = {distance_to_puppet = -0.5}
    },
    {
      Generation = {cover_from_attentionTarget_around_referencePoint = 15},
      Conditions = {min_distance_to_attentionTarget = 5},
      Weights = {distance_to_puppet = -0.5}
    }
  })
end
L0_347.OnInit = L1_348
