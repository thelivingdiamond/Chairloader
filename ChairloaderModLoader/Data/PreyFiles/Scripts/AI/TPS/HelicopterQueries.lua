local L0_338, L1_339
L0_338 = AI
L0_338 = L0_338.TacticalPositionManager
L1_339 = AI
L1_339 = L1_339.TacticalPositionManager
L1_339 = L1_339.Helicopter
L1_339 = L1_339 or {}
L0_338.Helicopter = L1_339
L0_338 = AI
L0_338 = L0_338.TacticalPositionManager
L0_338 = L0_338.Helicopter
function L1_339(A0_340)
  AI.RegisterTacticalPointQuery({
    Name = "HelicopterFindGoodFiringSpot",
    {
      Parameters = {density = 8, horizontalSpacing = 4},
      Generation = {pointsInDesignerPath_around_puppet = 75},
      Conditions = {min_distance2d_to_attentionTarget = 15, canShootTwoRayTest_to_attentionTarget = true},
      Weights = {distance_from_puppet = -1}
    }
  })
end
L0_338.OnInit = L1_339
