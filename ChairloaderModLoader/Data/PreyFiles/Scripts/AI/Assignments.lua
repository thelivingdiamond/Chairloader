local L0_360, L1_361
L0_360 = assignmentsHaveBeenCreated
if L0_360 == nil then
  L0_360 = true
  assignmentsHaveBeenCreated = L0_360
  L0_360 = {}
  L1_361 = {}
  L0_360.Assignments = L1_361
  function L1_361(A0_362)
    if A0_362.AI.currentAssignment ~= nil and A0_362.AI.currentAssignment ~= Assignment_NoAssignment then
      A0_362:SetAssignment(A0_362.AI.currentAssignment, A0_362.AI.currentAssignmentData)
    end
  end
  L0_360.OnResetSavedAssignment = L1_361
  function L1_361(A0_363, A1_364, A2_365)
    if A1_364 == Assignment_NoAssignment then
      A0_363:ClearAssignment()
      return
    end
    if A0_363.AI.currentAssignment and A0_363.AI.currentAssignment == A1_364 then
      A0_363:CallBehaviorFunction("Reset")
      AI.Signal(SIGNALFILTER_SENDER, 1, "OnResetAssignment", A0_363.id)
    end
    A0_363:ClearAssignment()
    if A0_363.Assignments[A1_364] == nil then
      A0_363:OnError("Assignment not available for this entity : " .. A1_364)
      return
    end
    if A0_363.Assignments[A1_364]:Start(A0_363, A2_365) then
      A0_363.AI.currentAssignment = A1_364
      A0_363.AI.currentAssignmentData = A2_365
    else
      A0_363:OnError("Assignment failed to start")
    end
  end
  L0_360.SetAssignment = L1_361
  function L1_361(A0_366)
    local L1_367
    L1_367 = A0_366.AI
    L1_367 = L1_367.currentAssignment
    if L1_367 ~= nil then
      L1_367 = A0_366.Assignments
      L1_367 = L1_367[A0_366.AI.currentAssignment]
      L1_367:Stop(A0_366)
      A0_366.AI.currentAssignment = nil
      A0_366.AI.currentAssignmentData = nil
    end
  end
  L0_360.ClearAssignment = L1_361
  AssignmentFunctionality = L0_360
  function L0_360(A0_368)
    mergef(A0_368, AssignmentFunctionality, 1)
  end
  InjectAssignmentFunctionality = L0_360
  L0_360 = {}
  function L1_361(A0_369, A1_370, A2_371)
    if IsNullVector(A2_371.position) then
      A1_370:OnError("DefendArea : position not valid")
      return false
    end
    A1_370.AI.defendArea = {
      position = {
        x = 0,
        y = 0,
        z = 0
      },
      radiusSq = 225
    }
    CopyVector(A1_370.AI.defendArea.position, A2_371.position)
    AI.SetBehaviorVariable(A1_370.id, "DefendArea", true)
    AI.SetBehaviorVariable(A1_370.id, "InsideDefendArea", A0_369:IsInsideDefendArea(A1_370))
    return true
  end
  L0_360.Start = L1_361
  function L1_361(A0_372, A1_373)
    AI.RequestToStopMovement(A1_373.id)
    AI.SetBehaviorVariable(A1_373.id, "DefendArea", false)
  end
  L0_360.Stop = L1_361
  function L1_361(A0_374, A1_375)
    return DistanceSqVectors(A1_375:GetWorldPos(), A1_375.AI.defendArea.position) < A1_375.AI.defendArea.radiusSq
  end
  L0_360.IsInsideDefendArea = L1_361
  DefendAreaAssignment = L0_360
  function L0_360(A0_376)
    A0_376.Assignments[Assignment_DefendArea] = DefendAreaAssignment
  end
  AddDefendAreaAssignment = L0_360
  L0_360 = {}
  function L1_361(A0_377, A1_378, A2_379)
    if IsNullVector(A2_379.position) then
      A1_378:OnError("HoldPosition : position not valid")
      return false
    end
    A1_378.AI.holdPosition = {
      position = {
        x = 0,
        y = 0,
        z = 0
      },
      direction = {
        x = 0,
        y = 0,
        z = 0
      },
      radiusSq = 9,
      useCover = A2_379.useCover
    }
    CopyVector(A1_378.AI.holdPosition.position, A2_379.position)
    CopyVector(A1_378.AI.holdPosition.direction, A2_379.direction)
    if 0 < A2_379.radius then
      A1_378.AI.holdPosition.radiusSq = A2_379.radius * A2_379.radius
    end
    AI.SetBehaviorVariable(A1_378.id, "HoldPosition", true)
    AI.SetBehaviorVariable(A1_378.id, "AtHoldPosition", A0_377:IsAtHoldPosition(A1_378))
    return true
  end
  L0_360.Start = L1_361
  function L1_361(A0_380, A1_381)
    AI.RequestToStopMovement(A1_381.id)
    AI.SetBehaviorVariable(A1_381.id, "HoldPosition", false)
  end
  L0_360.Stop = L1_361
  function L1_361(A0_382, A1_383)
    return DistanceSqVectors(A1_383:GetWorldPos(), A1_383.AI.holdPosition.position) < A1_383.AI.holdPosition.radiusSq
  end
  L0_360.IsAtHoldPosition = L1_361
  HoldPositionAssignment = L0_360
  function L0_360(A0_384)
    A0_384.Assignments[Assignment_HoldPosition] = HoldPositionAssignment
  end
  AddHoldPositionAssignment = L0_360
  L0_360 = {}
  function L1_361(A0_385, A1_386, A2_387)
    if IsNullVector(A2_387.position) then
      A1_386:OnError("CombatMove : position not valid")
      return false
    end
    A1_386.AI.combatMove = {
      position = {
        x = 0,
        y = 0,
        z = 0
      },
      useCover = A2_387.useCover
    }
    CopyVector(A1_386.AI.combatMove.position, A2_387.position)
    AI.SetBehaviorVariable(A1_386.id, "CombatMove", true)
    return true
  end
  L0_360.Start = L1_361
  function L1_361(A0_388, A1_389)
    AI.RequestToStopMovement(A1_389.id)
    AI.SetBehaviorVariable(A1_389.id, "CombatMove", false)
  end
  L0_360.Stop = L1_361
  CombatMoveAssignment = L0_360
  function L0_360(A0_390)
    A0_390.Assignments[Assignment_CombatMove] = CombatMoveAssignment
  end
  AddCombatMoveAssignment = L0_360
  L0_360 = {}
  function L1_361(A0_391, A1_392, A2_393)
    if A2_393.scanSpotEntityId == 0 then
      A1_392:Error("ScanSpotAssignment : ScanSpot entityId not set")
      return false
    end
    A1_392.AI.scanSpotAssignment = {}
    A1_392.AI.scanSpotAssignment.scanSpotEntityId = A2_393.scanSpotEntityId
    AI.SetBehaviorVariable(A1_392.id, "ScanSpotAssignment", true)
    return true
  end
  L0_360.Start = L1_361
  function L1_361(A0_394, A1_395)
    AI.RequestToStopMovement(A1_395.id)
    A1_395.AI.scanSpotAssignment = nil
    AI.SetBehaviorVariable(A1_395.id, "ScanSpotAssignment", false)
  end
  L0_360.Stop = L1_361
  ScanSpotAssignment = L0_360
  function L0_360(A0_396)
    A0_396.Assignments[Assignment_ScanSpot] = ScanSpotAssignment
  end
  AddScanSpotAssignment = L0_360
  L0_360 = {}
  function L1_361(A0_397, A1_398, A2_399)
    local L3_400
    L3_400 = A2_399.scorchSpotEntityID
    if L3_400 == 0 then
      A1_398:OnError("ScorchSpotAssignment : Entity ID invalid!")
      return false
    end
    A1_398.AI.scorchSpotAssignment = {
      scorchSpotEntityID = L3_400,
      aimOffset = A2_399.aimOffset,
      firingPattern = A2_399.firingPattern
    }
    AI.SetBehaviorVariable(A1_398.id, "ScorchSpotAssignment", true)
    return true
  end
  L0_360.Start = L1_361
  function L1_361(A0_401, A1_402)
    AI.SetBehaviorVariable(A1_402.id, "ScorchSpotAssignment", false)
  end
  L0_360.Stop = L1_361
  ScorchSpotAssignment = L0_360
  function L0_360(A0_403)
    A0_403.Assignments[Assignment_ScorchSpot] = ScorchSpotAssignment
  end
  AddScorchSpotAssignment = L0_360
  L0_360 = {}
  function L1_361(A0_404, A1_405, A2_406)
    AI.SetBehaviorVariable(A1_405.id, "PsychoCombatAllowed", true)
    return true
  end
  L0_360.Start = L1_361
  function L1_361(A0_407, A1_408)
    AI.SetBehaviorVariable(A1_408.id, "PsychoCombatAllowed", false)
  end
  L0_360.Stop = L1_361
  PsychoCombatAllowedAssignment = L0_360
  function L0_360(A0_409)
    A0_409.Assignments[Assignment_PsychoCombatAllowed] = PsychoCombatAllowedAssignment
  end
  AddPsychoCombatAllowedAssignment = L0_360
  L0_360 = {}
  function L1_361(A0_410, A1_411, A2_412)
    AI.SetBehaviorVariable(A1_411.id, "StalkerAggressive", true)
    return true
  end
  L0_360.Start = L1_361
  function L1_361(A0_413, A1_414)
    AI.SetBehaviorVariable(A1_414.id, "StalkerAggressive", false)
  end
  L0_360.Stop = L1_361
  StalkerAggressiveAssignment = L0_360
  function L0_360(A0_415)
    A0_415.Assignments[Assignment_StalkerAggressive] = StalkerAggressiveAssignment
  end
  AddStalkerAggressiveAssignment = L0_360
end
