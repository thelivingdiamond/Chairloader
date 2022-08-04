local L0_6956, L1_6957, L2_6958, L3_6959
L0_6956 = {}
L1_6957 = {}
L1_6957.fileModel = "engine/engineassets/objects/default.cgf"
L1_6957.bUsable = 1
L1_6957.bTopBlocked = 0
L1_6957.height = 3.7
L1_6957.approachAngle = 60
L1_6957.approachAngleTop = 0
L2_6958 = {}
L2_6958.horizontalViewLimit = 30
L2_6958.verticalUpViewLimit = 0
L2_6958.verticalDownViewLimit = 0
L1_6957.ViewLimits = L2_6958
L2_6958 = {}
L2_6958.stopClimbDistanceFromTop = 1.92
L2_6958.stopClimbDistanceFromBottom = 0.5
L2_6958.playerHorizontalOffset = 0.38
L2_6958.getOnDistanceAwayTop = 1.4
L2_6958.getOnDistanceAwayBottom = 0.54
L1_6957.Offsets = L2_6958
L2_6958 = {}
L2_6958.movementAcceleration = 5
L2_6958.movementSpeedUpwards = 2.5
L2_6958.movementSpeedDownwards = 2.25
L2_6958.movementSettleSpeed = 0.8
L2_6958.movementInertiaDecayRate = 5.5
L1_6957.Movement = L2_6958
L2_6958 = {}
L2_6958.distanceBetweenRungs = 0.5
L2_6958.cameraAnimFraction_getOn = 0.85
L2_6958.cameraAnimFraction_getOff = 0.85
L2_6958.cameraAnimFraction_onLadder = 0.3
L2_6958.bUseThirdPersonCamera = 1
L2_6958.bRenderLadderLast = 0
L1_6957.Camera = L2_6958
L0_6956.Properties = L1_6957
L1_6957 = {}
L1_6957.Icon = "ladder.bmp"
L1_6957.IconOnTop = 1
L0_6956.Editor = L1_6957
L1_6957 = {}
L0_6956.Server = L1_6957
Ladder = L0_6956
L0_6956 = Ladder
function L1_6957(A0_6960)
  A0_6960:LoadObject(0, A0_6960.Properties.fileModel)
  A0_6960:Physicalize(0, PE_STATIC, {mass = 0, density = 0})
  if System.IsEditor() then
    A0_6960:Activate(1)
  end
end
L0_6956.OnSpawn = L1_6957
L0_6956 = Ladder
function L1_6957(A0_6961)
  A0_6961:LoadObject(0, A0_6961.Properties.fileModel)
  A0_6961:Physicalize(0, PE_STATIC, {mass = 0, density = 0})
end
L0_6956.OnPropertyChange = L1_6957
L0_6956 = Ladder
function L1_6957(A0_6962, A1_6963)
  return A0_6962.Properties.bUsable
end
L0_6956.IsUsable = L1_6957
L0_6956 = Ladder
function L1_6957(A0_6964, A1_6965)
  local L2_6966
  L2_6966 = A0_6964.Properties
  L2_6966 = L2_6966.bUsable
  if L2_6966 == 1 then
    L2_6966 = "@use_ladder"
    return L2_6966
  end
end
L0_6956.GetUsableMessage = L1_6957
L0_6956 = Ladder
L0_6956 = L0_6956.Server
function L1_6957(A0_6967, A1_6968)
  if System.IsEditing() then
    Game.DebugDrawCylinder(A0_6967:GetWorldPos().x, A0_6967:GetWorldPos().y, A0_6967:GetWorldPos().z, 0.3, 0.3, 60, 60, 255, 100)
    Game.DebugDrawCylinder(A0_6967:GetWorldPos().x, A0_6967:GetWorldPos().y, A0_6967:GetWorldPos().z + A0_6967.Properties.height, 0.3, 0.3, 60, 60, 255, 100)
    Game.DebugDrawCylinder(A0_6967:GetWorldPos().x, A0_6967:GetWorldPos().y, A0_6967:GetWorldPos().z + A0_6967.Properties.height - A0_6967.Properties.Offsets.stopClimbDistanceFromTop, 0.3, 0.3, 255, 60, 60, 100)
    Game.DebugDrawCylinder(A0_6967:GetWorldPos().x, A0_6967:GetWorldPos().y, A0_6967:GetWorldPos().z + A0_6967.Properties.Offsets.stopClimbDistanceFromBottom, 0.3, 0.3, 255, 60, 60, 100)
  end
end
L0_6956.OnUpdate = L1_6957
L0_6956 = Ladder
function L1_6957(A0_6969)
  A0_6969.Properties.bUsable = 1
end
L0_6956.Event_Enable = L1_6957
L0_6956 = Ladder
function L1_6957(A0_6970)
  A0_6970.Properties.bUsable = 0
end
L0_6956.Event_Disable = L1_6957
L0_6956 = Ladder
function L1_6957(A0_6971)
  A0_6971.Properties.bTopBlocked = 1
end
L0_6956.Event_TopBlocked = L1_6957
L0_6956 = Ladder
function L1_6957(A0_6972)
  A0_6972.Properties.bTopBlocked = 0
end
L0_6956.Event_TopUnblocked = L1_6957
L0_6956 = Ladder
L1_6957 = {}
L2_6958 = {}
L3_6959 = {
  Ladder.Event_Enable,
  "any"
}
L2_6958.EnableUsable = L3_6959
L3_6959 = {
  Ladder.Event_Disable,
  "any"
}
L2_6958.DisableUsable = L3_6959
L3_6959 = {
  Ladder.Event_TopBlocked,
  "any"
}
L2_6958.TopBlocked = L3_6959
L3_6959 = {
  Ladder.Event_TopUnblocked,
  "any"
}
L2_6958.TopUnblocked = L3_6959
L1_6957.Inputs = L2_6958
L2_6958 = {}
L2_6958.PlayerOn = "entity"
L2_6958.PlayerOff = "entity"
L1_6957.Outputs = L2_6958
L0_6956.FlowEvents = L1_6957
