local L0_341, L1_342
L0_341 = AI
L0_341 = L0_341.TacticalPositionManager
L1_342 = AI
L1_342 = L1_342.TacticalPositionManager
L1_342 = L1_342.HumanGrunt
L1_342 = L1_342 or {}
L0_341.HumanGrunt = L1_342
L0_341 = AI
L0_341 = L0_341.TacticalPositionManager
L0_341 = L0_341.HumanGrunt
function L1_342(A0_343)
  AI.RegisterTacticalPointQuery({
    Name = "PointVisibleFromTarget",
    {
      Parameters = {density = 8},
      Generation = {grid_around_puppet = 25},
      Conditions = {max_changeInDistance_to_attentionTarget = 0, visible_from_attentionTarget = true},
      Weights = {
        distance_from_puppet = -0.5,
        distance_from_attentionTarget = 0.3,
        towards_the_attentionTarget = 1
      }
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "LeapfrogCoverTowardsTarget",
    {
      Generation = {cover_from_attentionTarget_around_puppet = 25},
      Conditions = {min_distance_to_attentionTarget = 8, max_changeInDistance_to_attentionTarget = -2},
      Weights = {
        distance_to_puppet = -0.5,
        distance_to_attentionTarget = -0.5,
        directness_to_attentionTarget = 1
      }
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "FindCoverImmediately",
    {
      Generation = {cover_from_attentionTarget_around_puppet = 25},
      Conditions = {min_distance_to_attentionTarget = 5},
      Weights = {
        distance_to_puppet = -0.9,
        distance_to_attentionTarget = -0.1,
        changeInDistance_to_attentionTarget = -0.5,
        otherSide_of_attentionTarget = -3
      }
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "FindCoverImmediatelyForHuman",
    {
      Generation = {cover_from_attentionTarget_around_puppet = 20},
      Conditions = {min_distance_to_attentionTarget = 10},
      Weights = {
        distance_to_puppet = -0.9,
        distance_to_attentionTarget = -0.1,
        otherSide_of_attentionTarget = -5
      },
      Generation = {cover_from_attentionTarget_around_puppet = 60},
      Conditions = {min_distance_to_attentionTarget = 10},
      Weights = {
        distance_to_puppet = -0.9,
        distance_to_attentionTarget = -0.1,
        otherSide_of_attentionTarget = -5
      }
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "FindAdvanceCoverForHuman",
    {
      Generation = {cover_from_attentionTarget_around_puppet = 30},
      Conditions = {
        min_distance_to_attentionTarget = 15,
        max_changeInDistance_to_attentionTarget = -15,
        otherSide_of_attentionTarget = false
      },
      Weights = {distance_to_puppet = -0.8, distance_to_attentionTarget = 0.2}
    },
    {
      Generation = {cover_from_attentionTarget_around_puppet = 60},
      Conditions = {
        min_distance_to_attentionTarget = 15,
        max_changeInDistance_to_attentionTarget = -15,
        otherSide_of_attentionTarget = false
      },
      Weights = {distance_to_puppet = -0.8, distance_to_attentionTarget = 0.2}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "FindCloseCoverWithShootingPostureForHuman",
    {
      Generation = {cover_from_attentionTarget_around_puppet = 6},
      Conditions = {
        otherSide_of_attentionTarget = false,
        min_distance_from_attentionTarget = 4,
        hasShootingPosture_to_attentionTarget = true
      },
      Weights = {distance_to_puppet = -1}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "CoverWithShootingPosture",
    {
      Generation = {cover_from_attentionTarget_around_puppet = 5},
      Conditions = {hasShootingPosture_to_attentionTarget = true},
      Weights = {distance_to_puppet = -1}
    },
    {
      Generation = {cover_from_attentionTarget_around_puppet = 15},
      Conditions = {min_distance_to_attentionTarget = 8, hasShootingPosture_to_attentionTarget = true},
      Weights = {distance_to_puppet = -1}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "HumanCoverWithShootingPostureToTarget",
    {
      Generation = {cover_from_attentionTarget_around_puppet = 25},
      Conditions = {hasShootingPosture_to_attentionTarget = true, min_effectiveCoverHeight_from_attentionTarget = 1.75},
      Weights = {distance_to_puppet = -0.9, distance_to_attentionTarget = -0.1}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "SniperCombatCover",
    {
      Generation = {cover_from_attentionTarget_around_puppet = 10},
      Conditions = {},
      Weights = {distance_to_puppet = -1}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "EngageCloseCover",
    {
      Generation = {cover_from_attentionTarget_around_puppet = 5},
      Conditions = {hasShootingPosture_to_attentionTarget = true},
      Weights = {distance_to_puppet = -1}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "HumanCombatHidespotQuery",
    {
      Generation = {cover_from_attentionTarget_around_puppet = 25},
      Conditions = {
        min_distance_to_attentionTarget = 8,
        canReachBefore_the_attentionTarget = true,
        max_distance_from_battlefront = 15,
        hasShootingPosture_to_attentionTarget = true,
        max_changeInDistance_to_attentionTarget = 10
      },
      Weights = {distance_to_puppet = -0.05, distance_to_attentionTarget = -0.05}
    },
    {
      Generation = {cover_from_attentionTarget_around_puppet = 20},
      Conditions = {
        min_distance_to_attentionTarget = 8,
        hasShootingPosture_to_attentionTarget = true,
        max_changeInDistance_to_attentionTarget = 10
      },
      Weights = {
        distance_to_puppet = -0.1,
        distance_to_attentionTarget = -0.2,
        distance_to_battlefront = -0.7
      }
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "HumanDistantCombatHidespotQuery",
    {
      Generation = {cover_from_attentionTarget_around_puppet = 30},
      Conditions = {min_distance_to_attentionTarget = 8, canReachBefore_the_attentionTarget = true},
      Weights = {
        distance_to_puppet = -0.05,
        distance_to_attentionTarget = -0.05,
        distance_to_battlefront = -0.7
      }
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "HumanUnderPressureHidespotQuery",
    {
      Generation = {cover_from_attentionTarget_around_puppet = 30},
      Conditions = {min_distance_to_attentionTarget = 8, canReachBefore_the_attentionTarget = true},
      Weights = {distance_to_puppet = -0.1, distance_to_attentionTarget = -0.01}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "HideSpotFromRefPointQuery",
    {
      Generation = {cover_from_referencePoint_around_puppet = 15},
      Conditions = {towards_the_attentionTarget = false},
      Weights = {distance_to_puppet = -0.1}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "HumanBaseOfFireQuery",
    {
      Generation = {cover_from_attentionTarget_around_attentionTarget = 20},
      Conditions = {
        towards_the_attentionTarget = true,
        hasShootingPosture_to_attentionTarget = true,
        min_distance_to_attentionTarget = 8
      },
      Weights = {distance_to_puppet = -0.1}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "SniperSpotQuery",
    {
      Parameters = {
        objectsType = AIAnchorTable.SNIPER_SPOT
      },
      Generation = {objects_around_puppet = 15},
      Conditions = {min_distance_to_attentionTarget = 10, visible_from_attentionTarget = true},
      Weights = {distance_from_puppet = -1}
    },
    {
      Parameters = {
        objectsType = AIAnchorTable.SNIPER_SPOT
      },
      Generation = {objects_around_puppet = 15},
      Conditions = {min_distance_to_attentionTarget = 10},
      Weights = {distance_from_puppet = -1}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "SniperSpotQueryForceVisible",
    {
      Parameters = {
        objectsType = AIAnchorTable.SNIPER_SPOT
      },
      Generation = {objects_around_puppet = 30},
      Conditions = {min_distance_to_attentionTarget = 10, visible_from_attentionTarget = true},
      Weights = {distance_from_puppet = -1}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "GrenadierSpotQuery",
    {
      Parameters = {
        objectsType = AIAnchorTable.GRENADIER_SPOT
      },
      Generation = {objects_around_puppet = 15},
      Conditions = {
        min_distance_to_attentionTarget = 10,
        visible_from_attentionTarget = true,
        isAdvantageSpotOccupied_for_puppet = false
      },
      Weights = {distance_from_puppet = -1}
    },
    {
      Parameters = {
        objectsType = AIAnchorTable.GRENADIER_SPOT
      },
      Generation = {objects_around_puppet = 15},
      Conditions = {min_distance_to_attentionTarget = 10, isAdvantageSpotOccupied_for_puppet = false},
      Weights = {distance_from_puppet = -1}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "DefensiveLineLeft",
    {
      Generation = {cover_from_attentionTarget_around_battlefront = 20},
      Conditions = {
        min_distance_to_attentionTarget = 10,
        min_distance_to_battlefront = 10,
        hasShootingPosture_to_attentionTarget = true,
        max_changeInDistance_to_attentionTarget = 5,
        max_distanceLeft_to_attentionTarget = 0,
        towards_the_attentionTarget = true,
        crossesLineOfFire_to_attentionTarget = false
      },
      Weights = {
        distance_to_puppet = -0.25,
        distance_to_attentionTarget = -0.5,
        directness_to_attentionTarget = -0.25
      }
    },
    {
      Generation = {cover_from_attentionTarget_around_battlefront = 20},
      Conditions = {
        min_distance_to_attentionTarget = 10,
        min_distance_to_battlefront = 10,
        hasShootingPosture_to_attentionTarget = true,
        max_changeInDistance_to_attentionTarget = 5,
        towards_the_attentionTarget = true
      },
      Weights = {
        distance_to_puppet = -0.15,
        distance_to_attentionTarget = -0.5,
        directness_to_attentionTarget = -0.2,
        distanceLeft_to_attentionTarget = 0.15
      }
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "DefensiveLineCenter",
    {
      Generation = {cover_from_attentionTarget_around_puppet = 20},
      Conditions = {
        min_distance_to_attentionTarget = 10,
        min_distance_to_battlefront = 10,
        hasShootingPosture_to_attentionTarget = true,
        max_changeInDistance_to_attentionTarget = 5
      },
      Weights = {distance_to_puppet = -0.5, distance_to_attentionTarget = -0.5}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "DefensiveLineRight",
    {
      Generation = {cover_from_attentionTarget_around_battlefront = 20},
      Conditions = {
        min_distance_to_attentionTarget = 10,
        min_distance_to_battlefront = 10,
        hasShootingPosture_to_attentionTarget = true,
        max_changeInDistance_to_attentionTarget = 5,
        min_distanceLeft_to_attentionTarget = 0,
        towards_the_attentionTarget = true,
        crossesLineOfFire_to_attentionTarget = false
      },
      Weights = {
        distance_to_puppet = -0.25,
        distance_to_attentionTarget = -0.5,
        directness_to_attentionTarget = -0.25
      }
    },
    {
      Generation = {cover_from_attentionTarget_around_battlefront = 20},
      Conditions = {
        min_distance_to_attentionTarget = 10,
        min_distance_to_battlefront = 10,
        hasShootingPosture_to_attentionTarget = true,
        max_changeInDistance_to_attentionTarget = 5,
        towards_the_attentionTarget = true
      },
      Weights = {
        distance_to_puppet = -0.15,
        distance_to_attentionTarget = -0.5,
        directness_to_attentionTarget = -0.2,
        distanceLeft_to_attentionTarget = -0.15
      }
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "HumanCoverAroundDefendPos",
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
  AI.RegisterTacticalPointQuery({
    Name = "HumanCoverTowardsDefendPos",
    {
      Generation = {cover_from_attentionTarget_around_puppet = 20},
      Conditions = {
        max_distance_to_referencePoint = 15,
        min_distance_to_attentionTarget = 10,
        hasShootingPosture_to_attentionTarget = true
      },
      Weights = {distance_to_referencePoint = -1}
    },
    {
      Generation = {cover_from_attentionTarget_around_puppet = 20},
      Conditions = {min_distance_to_attentionTarget = 10, hasShootingPosture_to_attentionTarget = true},
      Weights = {distance_to_referencePoint = -1}
    },
    {
      Generation = {cover_from_attentionTarget_around_referencePoint = 15},
      Conditions = {min_distance_to_attentionTarget = 10, hasShootingPosture_to_attentionTarget = true},
      Weights = {distance_to_puppet = -1}
    },
    {
      Generation = {cover_from_attentionTarget_around_referencePoint = 15},
      Conditions = {min_distance_to_attentionTarget = 10},
      Weights = {distance_to_puppet = -1}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "HumanHoldGround",
    {
      Generation = {cover_from_attentionTarget_around_referencePoint = 5},
      Conditions = {hasShootingPosture_to_attentionTarget = true},
      Weights = {distance_to_puppet = -1}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "HumanCoverShift",
    {
      Generation = {cover_from_attentionTarget_around_puppet = 5},
      Conditions = {min_distance_from_puppet = 2, hasShootingPosture_to_attentionTarget = true},
      Weights = {random = 1}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "HumanEstablishLineOfSightQuery",
    {
      Parameters = {density = 4},
      Generation = {grid_around_puppet = 15},
      Conditions = {
        max_changeInDistance_to_referencePoint = 4,
        min_changeInDistance_to_referencePoint = -4,
        visible_from_referencePoint = true
      },
      Weights = {distance_from_puppet = -0.8, distance_from_referencePoint = -0.2}
    }
  })
  AI.RegisterTacticalPointQuery({
    Name = "FindPositionNearSuspiciousSound",
    {
      Generation = {pointsInNavigationMesh_around_attentionTarget = 5},
      Conditions = {min_distance_from_attentionTarget = 3},
      Weights = {distance_from_attentionTarget = -1}
    }
  })
end
L0_341.OnInit = L1_342
