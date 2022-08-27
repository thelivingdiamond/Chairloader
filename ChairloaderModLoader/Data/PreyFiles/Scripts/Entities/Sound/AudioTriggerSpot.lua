Script.ReloadScript("scripts/Entities/Sound/Shared/AudioUtils.lua")
AudioTriggerSpot = {
  Editor = {
    Model = "Editor/Objects/Sound.cgf",
    Icon = "Sound.bmp"
  },
  Properties = {
    bEnabled = true,
    audioTriggerPlayTriggerName = "",
    audioTriggerStopTriggerName = "",
    bSerializePlayState = true,
    eiSoundObstructionType = 1,
    bPlayOnX = false,
    bPlayOnY = false,
    bPlayOnZ = false,
    fRadiusRandom = 10,
    bPlayRandom = false,
    fMinDelay = 1,
    fMaxDelay = 2
  },
  hOnTriggerID = nil,
  hOffTriggerID = nil,
  tObstructionType = {},
  bIsHidden = false,
  bIsPlaying = false,
  bHasMoved = false
}
function AudioTriggerSpot._LookupTriggerIDs(A0_8456)
  A0_8456.hOnTriggerID = AudioUtils.LookupTriggerID(A0_8456.Properties.audioTriggerPlayTriggerName)
  A0_8456.hOffTriggerID = AudioUtils.LookupTriggerID(A0_8456.Properties.audioTriggerStopTriggerName)
end
function AudioTriggerSpot._LookupObstructionSwitchIDs(A0_8457)
  A0_8457.tObstructionType = AudioUtils.LookupObstructionSwitchAndStates()
end
function AudioTriggerSpot._SetObstruction(A0_8458)
  local L1_8459, L2_8460, L3_8461, L5_8462
  L1_8459 = A0_8458.Properties
  L1_8459 = L1_8459.eiSoundObstructionType
  L1_8459 = L1_8459 + 1
  L2_8460 = A0_8458.tObstructionType
  L2_8460 = L2_8460.hSwitchID
  if L2_8460 ~= nil then
    L2_8460 = A0_8458.tObstructionType
    L2_8460 = L2_8460.tStateIDs
    L2_8460 = L2_8460[L1_8459]
    if L2_8460 ~= nil then
      L3_8461 = A0_8458
      L2_8460 = A0_8458.SetAudioSwitchState
      L5_8462 = A0_8458.tObstructionType
      L5_8462 = L5_8462.hSwitchID
      L2_8460(L3_8461, L5_8462, A0_8458.tObstructionType.tStateIDs[L1_8459], A0_8458:GetDefaultAuxAudioProxyID())
    end
  end
end
function AudioTriggerSpot._PlayFirstTime(A0_8463)
  A0_8463:_SetObstruction()
  A0_8463:SetCurrentAudioEnvironments()
  if A0_8463.Properties.bEnabled and not A0_8463.bIsHidden then
    A0_8463:Play()
  end
end
function AudioTriggerSpot._GenerateOffset(A0_8464)
  local L1_8465, L2_8466
  L1_8465 = {}
  L1_8465.x = 0
  L1_8465.y = 0
  L1_8465.z = 0
  L2_8466 = 0
  if A0_8464.Properties.bPlayOnX then
    L1_8465.x = randomF(-1, 1)
  end
  if A0_8464.Properties.bPlayOnY then
    L1_8465.y = randomF(-1, 1)
  end
  if A0_8464.Properties.bPlayOnZ then
    L1_8465.z = randomF(-1, 1)
  end
  NormalizeVector(L1_8465)
  ScaleVectorInPlace(L1_8465, randomF(0, A0_8464.Properties.fRadiusRandom))
  return L1_8465
end
function AudioTriggerSpot.OnSpawn(A0_8467)
  A0_8467:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
end
function AudioTriggerSpot.OnSave(A0_8468, A1_8469)
  local L2_8470
  L2_8470 = A0_8468.Properties
  A1_8469.Properties = L2_8470
  L2_8470 = A0_8468.bIsPlaying
  A1_8469.bIsPlaying = L2_8470
end
function AudioTriggerSpot.OnLoad(A0_8471, A1_8472)
  A0_8471:Stop()
  A0_8471.Properties = A1_8472.Properties
  A0_8471.bIsPlaying = A1_8472.bIsPlaying
end
function AudioTriggerSpot.OnPostLoad(A0_8473)
  A0_8473:_SetObstruction()
  A0_8473:SetCurrentAudioEnvironments()
  if A0_8473.bIsPlaying and A0_8473.Properties.bSerializePlayState then
    A0_8473.bIsPlaying = false
    A0_8473:Play()
  else
    A0_8473.bIsPlaying = false
  end
end
function AudioTriggerSpot._Init(A0_8474)
  A0_8474.bIsPlaying = false
  A0_8474:SetAudioProxyOffset(g_Vectors.v000, A0_8474:GetDefaultAuxAudioProxyID())
  A0_8474:NetPresent(0)
end
function AudioTriggerSpot.OnPropertyChange(A0_8475)
  A0_8475:Stop()
  A0_8475:_LookupTriggerIDs()
  if A0_8475.Properties.eiSoundObstructionType < 0 then
    A0_8475.Properties.eiSoundObstructionType = 0
  elseif A0_8475.Properties.eiSoundObstructionType > 1 then
    A0_8475.Properties.eiSoundObstructionType = 2
  end
  A0_8475:SetAudioProxyOffset(g_Vectors.v000, A0_8475:GetDefaultAuxAudioProxyID())
  A0_8475:_PlayFirstTime()
end
function AudioTriggerSpot.OnReset(A0_8476)
  A0_8476:Stop()
  A0_8476:_PlayFirstTime()
end
AudioTriggerSpot.Server = {
  OnInit = function(A0_8477)
    A0_8477:_Init()
  end,
  OnShutDown = function(A0_8478)
    local L1_8479
  end
}
AudioTriggerSpot.Client = {
  OnInit = function(A0_8480)
    A0_8480:_Init()
    A0_8480:_LookupObstructionSwitchIDs()
    A0_8480:_LookupTriggerIDs()
    A0_8480:_PlayFirstTime()
  end,
  OnShutDown = function(A0_8481)
    A0_8481:Stop()
  end,
  OnSoundDone = function(A0_8482, A1_8483)
    if A0_8482.hOnTriggerID == A1_8483 then
      A0_8482:ActivateOutput("Done", true)
      A0_8482.bIsPlaying = false
    end
  end,
  OnTimer = function(A0_8484, A1_8485, A2_8486)
    if A1_8485 == 0 then
      A0_8484:Play()
    end
  end,
  OnHidden = function(A0_8487)
    A0_8487:Stop()
    A0_8487.bIsHidden = true
  end,
  OnUnHidden = function(A0_8488)
    A0_8488.bIsHidden = false
    A0_8488:_PlayFirstTime()
  end,
  OnMove = function(A0_8489)
    local L1_8490
    A0_8489.bHasMoved = true
  end
}
function AudioTriggerSpot.Play(A0_8491)
  local L1_8492
  L1_8492 = A0_8491.hOnTriggerID
  if L1_8492 ~= nil then
    L1_8492 = A0_8491.Properties
    L1_8492 = L1_8492.bEnabled
    if L1_8492 then
      L1_8492 = A0_8491.Stop
      L1_8492(A0_8491)
      L1_8492 = A0_8491._GenerateOffset
      L1_8492 = L1_8492(A0_8491)
      if LengthSqVector(L1_8492) > 1.0E-5 then
        A0_8491:SetAudioProxyOffset(L1_8492, A0_8491:GetDefaultAuxAudioProxyID())
        A0_8491:SetCurrentAudioEnvironments()
      elseif A0_8491.bHasMoved then
        A0_8491:SetCurrentAudioEnvironments()
      end
      A0_8491:ExecuteAudioTrigger(A0_8491.hOnTriggerID, A0_8491:GetDefaultAuxAudioProxyID())
      A0_8491.bIsPlaying = true
      A0_8491.bHasMoved = false
      if A0_8491.Properties.bPlayRandom then
        A0_8491:SetTimer(0, 1000 * randomF(A0_8491.Properties.fMinDelay, A0_8491.Properties.fMaxDelay))
      end
    end
  end
end
function AudioTriggerSpot.Stop(A0_8493)
  if A0_8493.bIsPlaying then
    if A0_8493.hOffTriggerID ~= nil then
      A0_8493:ExecuteAudioTrigger(A0_8493.hOffTriggerID, A0_8493:GetDefaultAuxAudioProxyID())
    else
      A0_8493:StopAudioTrigger(A0_8493.hOnTriggerID, A0_8493:GetDefaultAuxAudioProxyID())
    end
    A0_8493.bIsPlaying = false
    A0_8493:KillTimer(0)
  end
end
function AudioTriggerSpot.Event_Enable(A0_8494, A1_8495)
  if not A0_8494.Properties.bEnabled then
    A0_8494.Properties.bEnabled = true
    A0_8494:Play()
  end
end
function AudioTriggerSpot.Event_Disable(A0_8496, A1_8497)
  A0_8496:Stop()
  A0_8496.Properties.bEnabled = false
end
AudioTriggerSpot.FlowEvents = {
  Inputs = {
    Enable = {
      AudioTriggerSpot.Event_Enable,
      "bool"
    },
    Disable = {
      AudioTriggerSpot.Event_Disable,
      "bool"
    }
  },
  Outputs = {Done = "bool"}
}
