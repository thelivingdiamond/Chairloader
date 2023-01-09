Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkElevator = {
  Properties = {
    object_Model = "",
    bDisallowGrenades = true,
    bIgnoreLiftPower = true,
    Sound = {audioTrigger_Start = "", audioTrigger_Stop = ""},
    Slide = {
      fSpeed = 1,
      fAcceleration = 1,
      fStopTime = 0.06,
      bExactPosition = 1
    }
  },
  PropertiesInstance = {bVerbose = 0},
  Editor = {
    Icon = "elevator.bmp",
    IconOnTop = 0,
    IsScalable = false
  }
}
ArkElevatorInstanceVars = {
  m_bVerbose = false,
  m_bInit = false,
  m_bMoving = false,
  m_bIsForward = true,
  m_bSlidingRequested = false,
  m_referenceTable = false,
  m_transitRequest = "",
  m_teleportRequest = "",
  m_maxSqDistance = 0,
  m_startingPosition = ConstVec({
    x = 0,
    y = 0,
    z = 0
  }),
  m_destinationPosition = ConstVec({
    x = 0,
    y = 0,
    z = 0
  }),
  m_forwardDirection = ConstVec({
    x = 0,
    y = 0,
    z = 0
  }),
  m_audioIds = {}
}
GetArkEntityUtils(ArkElevator)
ArkMakeSaveable(ArkElevator)
SetupCollisionFiltering(ArkElevator)
function CreateElevator(A0_3723)
  mergef(A0_3723, ArkElevatorInstanceVars, 1)
  A0_3723.m_referenceTable = ArkElevatorInstanceVars
end
function ArkElevator.DoPhysicalize(A0_3724)
  local L1_3725
  L1_3725 = CryAction
  L1_3725 = L1_3725.ActivateExtensionForGameObject
  L1_3725(A0_3724.id, "ScriptControlledPhysics", false)
  L1_3725 = A0_3724.LoadObject
  L1_3725(A0_3724, 0, A0_3724.Properties.object_Model)
  L1_3725 = A0_3724.Physicalize
  L1_3725(A0_3724, 0, PE_RIGID, {mass = 0})
  L1_3725 = CryAction
  L1_3725 = L1_3725.ActivateExtensionForGameObject
  L1_3725(A0_3724.id, "ScriptControlledPhysics", true)
  L1_3725 = EntityCommon
  L1_3725 = L1_3725.TempPhysicsFlags
  L1_3725.flags = pef_ignore_areas
  L1_3725.flags_mask = pef_ignore_areas
  A0_3724:SetPhysicParams(PHYSICPARAM_FLAGS, L1_3725)
end
function ArkElevator.SetFromProperties(A0_3726)
  GetAudioIds(A0_3726.Properties.Sound, A0_3726.m_audioIds)
  A0_3726.m_bVerbose = A0_3726.PropertiesInstance.bVerbose == 1
end
function ArkElevator.SetMoving(A0_3727, A1_3728)
  A0_3727.m_bMoving = A1_3728
  A0_3727:ActivateOutput("Moving", A0_3727.m_bMoving)
end
function ArkElevator.Init(A0_3729, A1_3730)
  A0_3729:Activate(0)
  if not A0_3729.m_bInit then
    A0_3729:Log("Init")
    A0_3729.m_bInit = true
    A0_3729:SetFromProperties()
    A0_3729:DoPhysicalize()
    A0_3729.scp:Reset()
    if A1_3730 then
      A0_3729:AwakePhysics(1)
      if 0 < A0_3729:CountLinks() then
        A0_3729.m_destinationPosition = A0_3729:GetLink(0):GetWorldPos()
      else
        LogError("ArkElevator has no linked destination entity. A destination entity is required.")
      end
      A0_3729.m_startingPosition = A0_3729:GetWorldPos()
      A0_3729.m_maxSqDistance = DistanceSqVectors(A0_3729.m_startingPosition, A0_3729.m_destinationPosition)
      A0_3729.m_forwardDirection = GetDirection(A0_3729.m_startingPosition, A0_3729.m_destinationPosition)
    end
  end
end
function ArkElevator.OnUpdate(A0_3731, A1_3732)
  local L2_3733, L3_3734, L4_3735
  L2_3733 = A0_3731.m_transitRequest
  if L2_3733 ~= "" then
    L2_3733 = A0_3731.scp
    L3_3734 = L2_3733
    L2_3733 = L2_3733.HasArrived
    L2_3733 = L2_3733(L3_3734)
    if L2_3733 then
      L3_3734 = A0_3731
      L2_3733 = A0_3731.ActivateOutput
      L4_3735 = "TransitComplete"
      L2_3733(L3_3734, L4_3735, A0_3731.m_transitRequest)
      A0_3731.m_transitRequest = ""
      L3_3734 = A0_3731
      L2_3733 = A0_3731.Activate
      L4_3735 = 0
      L2_3733(L3_3734, L4_3735)
      L3_3734 = A0_3731
      L2_3733 = A0_3731.SetMoving
      L4_3735 = false
      L2_3733(L3_3734, L4_3735)
    end
  else
    L2_3733 = A0_3731.m_teleportRequest
    if L2_3733 ~= "" then
      L2_3733 = A0_3731.scp
      L3_3734 = L2_3733
      L2_3733 = L2_3733.HasArrived
      L2_3733 = L2_3733(L3_3734)
      if L2_3733 then
        L3_3734 = A0_3731
        L2_3733 = A0_3731.ActivateOutput
        L4_3735 = A0_3731.m_transitRequest
        L2_3733(L3_3734, L4_3735)
        L3_3734 = A0_3731
        L2_3733 = A0_3731.ActivateOutput
        L4_3735 = "TeleportComplete"
        L2_3733(L3_3734, L4_3735, A0_3731.m_teleportRequest)
        A0_3731.m_teleportRequest = ""
        L3_3734 = A0_3731
        L2_3733 = A0_3731.Activate
        L4_3735 = 0
        L2_3733(L3_3734, L4_3735)
        L3_3734 = A0_3731
        L2_3733 = A0_3731.SetMoving
        L4_3735 = false
        L2_3733(L3_3734, L4_3735)
      end
    else
      L2_3733 = A0_3731.m_bMoving
      if not L2_3733 then
        L2_3733 = A0_3731.m_bSlidingRequested
        if L2_3733 then
          L3_3734 = A0_3731
          L2_3733 = A0_3731.Slide
          L2_3733(L3_3734)
        end
      else
        L2_3733 = A0_3731.m_bMoving
        if L2_3733 then
          L3_3734 = A0_3731
          L2_3733 = A0_3731.GetWorldPos
          L2_3733 = L2_3733(L3_3734)
          L3_3734 = DistanceSqVectors
          L4_3735 = A0_3731.m_startingPosition
          L3_3734 = L3_3734(L4_3735, L2_3733)
          L4_3735 = A0_3731.ActivateOutput
          L4_3735(A0_3731, "Distance", math.sqrt(L3_3734))
          L4_3735 = A0_3731.m_bIsForward
          if L4_3735 then
            L4_3735 = A0_3731.m_maxSqDistance
            if L3_3734 >= L4_3735 then
              L4_3735 = A0_3731.Stop
              L4_3735(A0_3731)
            end
          else
            L4_3735 = GetDirection
            L4_3735 = L4_3735(A0_3731.m_startingPosition, L2_3733)
            if 0 > dotproduct3d(A0_3731.m_forwardDirection, L4_3735) then
              A0_3731:Stop()
            end
          end
        end
      end
    end
  end
  A0_3731.m_bSlidingRequested = false
end
function ArkElevator.Stop(A0_3736)
  A0_3736.scp:Stop(A0_3736.Properties.Slide.fStopTime)
  A0_3736:SetMoving(false)
  A0_3736:Activate(0)
  if A0_3736.m_audioIds.audioTrigger_Stop ~= nil then
    A0_3736:ExecuteAudioTrigger(A0_3736.m_audioIds.audioTrigger_Stop, A0_3736:GetDefaultAuxAudioProxyID())
  end
  if A0_3736.m_bIsForward then
    BroadcastEvent(A0_3736, "StoppedForward")
  else
    BroadcastEvent(A0_3736, "StoppedBackward")
  end
end
function ArkElevator.StopImmediate(A0_3737)
  A0_3737.scp:Stop(0)
  A0_3737:SetMoving(false)
  A0_3737:Activate(0)
  if A0_3737.m_audioIds.audioTrigger_Stop ~= nil then
    A0_3737:ExecuteAudioTrigger(A0_3737.m_audioIds.audioTrigger_Stop, A0_3737:GetDefaultAuxAudioProxyID())
  end
  if A0_3737.m_bIsForward then
    BroadcastEvent(A0_3737, "StoppedForward")
  else
    BroadcastEvent(A0_3737, "StoppedBackward")
  end
end
function ArkElevator.Slide(A0_3738)
  local L1_3739, L2_3740
  L2_3740 = A0_3738
  L1_3739 = A0_3738.Log
  L1_3739(L2_3740, "Sliding start")
  L1_3739 = A0_3738.Properties
  L1_3739 = L1_3739.Slide
  L2_3740 = nil
  if A0_3738.m_bIsForward then
    L2_3740 = NewVector(A0_3738.m_forwardDirection)
  else
    L2_3740 = ScaleVector(A0_3738.m_forwardDirection, -1)
  end
  ScaleVectorInPlace(L2_3740, L1_3739.fSpeed)
  LogVec("velocity", L2_3740)
  A0_3738.scp:Move(L2_3740, L1_3739.fAcceleration)
  A0_3738:SetMoving(true)
  if A0_3738.m_audioIds.audioTrigger_Start ~= nil then
    A0_3738:ExecuteAudioTrigger(A0_3738.m_audioIds.audioTrigger_Start, A0_3738:GetDefaultAuxAudioProxyID())
  end
end
function ArkElevator.Forward(A0_3741)
  A0_3741:Activate(1)
  A0_3741.m_bSlidingRequested = true
  A0_3741.m_bIsForward = true
  BroadcastEvent(A0_3741, "StartedForward")
end
function ArkElevator.Backward(A0_3742)
  A0_3742:Activate(1)
  A0_3742.m_bSlidingRequested = true
  A0_3742.m_bIsForward = false
  BroadcastEvent(A0_3742, "StartedBackward")
end
function ArkElevator.TransitToLink(A0_3743, A1_3744, A2_3745)
  A0_3743:Log("Transiting to " .. A2_3745)
  A0_3743:Log("Linked destination entity found: " .. A0_3743:GetLinkTarget(A2_3745):GetName())
  if A0_3743:GetLinkTarget(A2_3745) ~= nil then
    A0_3743.scp:MoveTo(A0_3743:GetLinkTarget(A2_3745):GetWorldPos(), A0_3743:GetSpeed(), A0_3743.Properties.Slide.fSpeed, A0_3743.Properties.Slide.fAcceleration, A0_3743.Properties.Slide.fStopTime, A0_3743.Properties.Slide.bExactPosition)
    A0_3743.m_transitRequest = A2_3745
    A0_3743:SetMoving(true)
    A0_3743:Activate(1)
  else
    LogError("Error: TransitToLink requested on " .. A0_3743:GetName() .. ", check bExpressMode to enable this function.")
  end
end
function ArkElevator.TeleportToLink(A0_3746, A1_3747, A2_3748)
  A0_3746:Log("Teleporting to " .. A2_3748)
  A0_3746:Log("Linked destination entity found: " .. A0_3746:GetLinkTarget(A2_3748):GetName())
  if A0_3746:GetLinkTarget(A2_3748) ~= nil then
    A0_3746.scp:MoveTo(A0_3746:GetLinkTarget(A2_3748):GetWorldPos(), A0_3746:GetSpeed(), 1500, 100, A0_3746.Properties.Slide.fStopTime, 1)
    A0_3746.m_teleportRequest = A2_3748
    A0_3746:SetMoving(true)
    A0_3746:Activate(1)
  else
    LogError("Error: TeleportToLink requested on " .. A0_3746:GetName() .. ", check bExpressMode to enable this function.")
  end
end
function ArkElevator.OnPostLoad(A0_3749)
  A0_3749:DoPhysicalize()
  A0_3749.scp:Reset()
  if A0_3749.m_teleportRequest ~= "" then
    A0_3749:TeleportToLink(nil, A0_3749.m_teleportRequest)
  elseif A0_3749.m_transitRequest ~= "" then
    A0_3749:TransitToLink(nil, A0_3749.m_transitRequest)
  end
end
function ArkElevator.OnReset(A0_3750)
  A0_3750:DoPhysicalize()
  A0_3750.scp:Reset()
  A0_3750.m_bInit = false
  A0_3750.m_bSlidingRequested = false
  A0_3750.m_bMoving = false
  A0_3750:SetupModelAndPhysics()
  A0_3750:Activate(0)
end
function ArkElevator.OnSpawn(A0_3751)
  CreateElevator(A0_3751)
  CryAction.CreateGameObjectForEntity(A0_3751.id)
  CryAction.BindGameObjectToNetwork(A0_3751.id)
  CryAction.ForceGameObjectUpdate(A0_3751.id, true)
  A0_3751:SetupModelAndPhysics()
  A0_3751:SetFromProperties()
  A0_3751:Activate(0)
end
ArkElevator.FlowEvents = {
  Inputs = {
    Forward = {
      ArkElevator.Forward,
      "any"
    },
    Backward = {
      ArkElevator.Backward,
      "any"
    },
    Stop = {
      ArkElevator.Stop,
      "any"
    },
    TransitToLink = {
      ArkElevator.TransitToLink,
      "string"
    },
    TeleportToLink = {
      ArkElevator.TeleportToLink,
      "string"
    }
  },
  Outputs = {
    StartedForward = "bool",
    StoppedForward = "bool",
    StartedBackward = "bool",
    StoppedBackward = "bool",
    Moving = "bool",
    TransitComplete = "string",
    TeleportComplete = "string",
    Distance = "float"
  }
}
