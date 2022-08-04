local L0_8313, L1_8314, L2_8315, L3_8316
L0_8313 = {}
L0_8313.type = "AudioAreaAmbience"
L1_8314 = {}
L1_8314.Model = "Editor/Objects/Sound.cgf"
L1_8314.Icon = "AudioAreaAmbience.bmp"
L0_8313.Editor = L1_8314
L1_8314 = {}
L1_8314.bEnabled = true
L1_8314.audioTriggerPlayTrigger = ""
L1_8314.audioTriggerStopTrigger = ""
L1_8314.audioRTPCRtpc = ""
L1_8314.audioEnvironmentEnvironment = ""
L1_8314.eiSoundObstructionType = 1
L1_8314.fRtpcDistance = 5
L1_8314.fEnvironmentDistance = 5
L0_8313.Properties = L1_8314
L0_8313.fFadeValue = 0
L0_8313.nState = 0
L0_8313.fFadeOnUnregister = 1
L0_8313.hOnTriggerID = nil
L0_8313.hOffTriggerID = nil
L0_8313.hRtpcID = nil
L0_8313.hEnvironmentID = nil
L1_8314 = {}
L0_8313.tObstructionType = L1_8314
L0_8313.bIsPlaying = false
AudioAreaAmbience = L0_8313
L0_8313 = AudioAreaAmbience
function L1_8314(A0_8317)
  A0_8317.hOnTriggerID = AudioUtils.LookupTriggerID(A0_8317.Properties.audioTriggerPlayTrigger)
  A0_8317.hOffTriggerID = AudioUtils.LookupTriggerID(A0_8317.Properties.audioTriggerStopTrigger)
  A0_8317.hRtpcID = AudioUtils.LookupRtpcID(A0_8317.Properties.audioRTPCRtpc)
  A0_8317.hEnvironmentID = AudioUtils.LookupAudioEnvironmentID(A0_8317.Properties.audioEnvironmentEnvironment)
end
L0_8313._LookupControlIDs = L1_8314
L0_8313 = AudioAreaAmbience
function L1_8314(A0_8318)
  A0_8318.tObstructionType = AudioUtils.LookupObstructionSwitchAndStates()
end
L0_8313._LookupObstructionSwitchIDs = L1_8314
L0_8313 = AudioAreaAmbience
function L1_8314(A0_8319)
  local L1_8320, L2_8321, L3_8322, L5_8323
  L1_8320 = A0_8319.Properties
  L1_8320 = L1_8320.eiSoundObstructionType
  L1_8320 = L1_8320 + 1
  L2_8321 = A0_8319.tObstructionType
  L2_8321 = L2_8321.hSwitchID
  if L2_8321 ~= nil then
    L2_8321 = A0_8319.tObstructionType
    L2_8321 = L2_8321.tStateIDs
    L2_8321 = L2_8321[L1_8320]
    if L2_8321 ~= nil then
      L3_8322 = A0_8319
      L2_8321 = A0_8319.SetAudioSwitchState
      L5_8323 = A0_8319.tObstructionType
      L5_8323 = L5_8323.hSwitchID
      L2_8321(L3_8322, L5_8323, A0_8319.tObstructionType.tStateIDs[L1_8320], A0_8319:GetDefaultAuxAudioProxyID())
    end
  end
end
L0_8313._SetObstruction = L1_8314
L0_8313 = AudioAreaAmbience
function L1_8314(A0_8324)
  local L1_8325, L2_8326, L3_8327, L5_8328
  L1_8325 = 1
  L2_8326 = A0_8324.tObstructionType
  L2_8326 = L2_8326.hSwitchID
  if L2_8326 ~= nil then
    L2_8326 = A0_8324.tObstructionType
    L2_8326 = L2_8326.tStateIDs
    L2_8326 = L2_8326[L1_8325]
    if L2_8326 ~= nil then
      L3_8327 = A0_8324
      L2_8326 = A0_8324.SetAudioSwitchState
      L5_8328 = A0_8324.tObstructionType
      L5_8328 = L5_8328.hSwitchID
      L2_8326(L3_8327, L5_8328, A0_8324.tObstructionType.tStateIDs[L1_8325], A0_8324:GetDefaultAuxAudioProxyID())
    end
  end
end
L0_8313._DisableObstruction = L1_8314
L0_8313 = AudioAreaAmbience
function L1_8314(A0_8329)
  if A0_8329.Properties.bEnabled then
    A0_8329:Play()
  end
end
L0_8313._PlayFirstTime = L1_8314
L0_8313 = AudioAreaAmbience
function L1_8314(A0_8330)
  if A0_8330.Properties.bEnabled then
    if A0_8330.hEnvironmentID ~= nil then
      A0_8330:SetAudioEnvironmentID(A0_8330.hEnvironmentID)
    end
  else
    A0_8330:SetAudioEnvironmentID(INVALID_AUDIO_ENVIRONMENT_ID)
  end
  A0_8330:SetFadeDistance(A0_8330.Properties.fRtpcDistance)
  A0_8330:SetEnvironmentFadeDistance(A0_8330.Properties.fEnvironmentDistance)
end
L0_8313._UpdateParameters = L1_8314
L0_8313 = AudioAreaAmbience
function L1_8314(A0_8331)
  local L2_8332, L3_8333, L4_8334
  L2_8332 = A0_8331.hRtpcID
  if L2_8332 ~= nil then
    L3_8333 = A0_8331
    L2_8332 = A0_8331.SetAudioRtpcValue
    L4_8334 = A0_8331.hRtpcID
    L2_8332(L3_8333, L4_8334, A0_8331.fFadeValue, A0_8331:GetDefaultAuxAudioProxyID())
  end
end
L0_8313._UpdateRtpc = L1_8314
L0_8313 = AudioAreaAmbience
function L1_8314(A0_8335)
  A0_8335:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
end
L0_8313.OnSpawn = L1_8314
L0_8313 = AudioAreaAmbience
function L1_8314(A0_8336, A1_8337)
  A0_8336.Properties = A1_8337.Properties
  A0_8336.fFadeValue = A1_8337.fFadeValue
  A0_8336.nState = A1_8337.nState
  A0_8336.fFadeOnUnregister = A1_8337.fFadeOnUnregister
  A0_8336:_SetObstruction()
end
L0_8313.OnLoad = L1_8314
L0_8313 = AudioAreaAmbience
function L1_8314(A0_8338, A1_8339)
  local L2_8340
  L2_8340 = A0_8338.Properties
  A1_8339.Properties = L2_8340
  L2_8340 = A0_8338.fFadeValue
  A1_8339.fFadeValue = L2_8340
  L2_8340 = A0_8338.nState
  A1_8339.nState = L2_8340
  L2_8340 = A0_8338.fFadeOnUnregister
  A1_8339.fFadeOnUnregister = L2_8340
end
L0_8313.OnSave = L1_8314
L0_8313 = AudioAreaAmbience
function L1_8314(A0_8341)
  A0_8341:Stop()
  A0_8341:_LookupControlIDs()
  A0_8341:_UpdateParameters()
  if A0_8341.Properties.eiSoundObstructionType < 0 then
    A0_8341.Properties.eiSoundObstructionType = 0
  elseif A0_8341.Properties.eiSoundObstructionType > 2 then
    A0_8341.Properties.eiSoundObstructionType = 2
  end
  A0_8341:SetAudioProxyOffset(g_Vectors.v000, A0_8341:GetDefaultAuxAudioProxyID())
  if A0_8341.nState == 1 then
    A0_8341:_SetObstruction()
    A0_8341:_PlayFirstTime()
  elseif A0_8341.nState == 2 then
    A0_8341:_DisableObstruction()
    A0_8341:_PlayFirstTime()
  end
end
L0_8313.OnPropertyChange = L1_8314
L0_8313 = AudioAreaAmbience
function L1_8314(A0_8342)
  A0_8342:_UpdateParameters()
end
L0_8313.OnReset = L1_8314
L0_8313 = AudioAreaAmbience
function L1_8314(A0_8343)
  if A0_8343.Properties.bEnabled and A0_8343.hOnTriggerID ~= nil then
    A0_8343:Stop()
    A0_8343:SetCurrentAudioEnvironments()
    A0_8343:ExecuteAudioTrigger(A0_8343.hOnTriggerID, A0_8343:GetDefaultAuxAudioProxyID())
    A0_8343.bIsPlaying = true
  end
end
L0_8313.Play = L1_8314
L0_8313 = AudioAreaAmbience
function L1_8314(A0_8344)
  local L1_8345, L2_8346, L3_8347
  L1_8345 = A0_8344.bIsPlaying
  if L1_8345 then
    L1_8345 = A0_8344.hOffTriggerID
    if L1_8345 ~= nil then
      L2_8346 = A0_8344
      L1_8345 = A0_8344.ExecuteAudioTrigger
      L3_8347 = A0_8344.hOffTriggerID
      L1_8345(L2_8346, L3_8347, A0_8344:GetDefaultAuxAudioProxyID())
    else
      L2_8346 = A0_8344
      L1_8345 = A0_8344.StopAudioTrigger
      L3_8347 = A0_8344.hOnTriggerID
      L1_8345(L2_8346, L3_8347, A0_8344:GetDefaultAuxAudioProxyID())
    end
    A0_8344.bIsPlaying = false
  end
end
L0_8313.Stop = L1_8314
L0_8313 = AudioAreaAmbience
function L1_8314(A0_8348)
  A0_8348.nState = 0
  A0_8348.fFadeValue = 0
  A0_8348.fFadeOnUnregister = 1
  A0_8348:SetFlags(ENTITY_FLAG_VOLUME_SOUND, 0)
  A0_8348:_UpdateParameters()
  A0_8348.bIsPlaying = false
  A0_8348:NetPresent(0)
end
L0_8313.CliSrv_OnInit = L1_8314
L0_8313 = AudioAreaAmbience
function L1_8314(A0_8349, A1_8350, A2_8351, A3_8352)
  local L4_8353
  L4_8353 = A0_8349.Properties
  L4_8353 = L4_8353.bEnabled
  if not L4_8353 or A2_8351 == 0 and A3_8352 == 0 then
    A0_8349.fFadeValue = 0
    L4_8353 = A0_8349._UpdateRtpc
    L4_8353(A0_8349)
    return
  end
  L4_8353 = A0_8349.Properties
  L4_8353 = L4_8353.fRtpcDistance
  if L4_8353 > 0 then
    L4_8353 = A0_8349.nState
    if L4_8353 == 2 then
      L4_8353 = A0_8349.fFadeValue
      if L4_8353 ~= A2_8351 then
        L4_8353 = math
        L4_8353 = L4_8353.abs
        L4_8353 = L4_8353(A2_8351)
        A0_8349.fFadeValue = L4_8353
        L4_8353 = A0_8349._UpdateRtpc
        L4_8353(A0_8349)
      end
    else
      L4_8353 = math
      L4_8353 = L4_8353.sqrt
      L4_8353 = L4_8353(A3_8352)
      L4_8353 = L4_8353 / A0_8349.Properties.fRtpcDistance
      L4_8353 = 1 - L4_8353
      A0_8349.fFadeValue = math.max(0, L4_8353)
      A0_8349:_UpdateRtpc()
    end
  end
end
L0_8313.UpdateFadeValue = L1_8314
L0_8313 = AudioAreaAmbience
L1_8314 = {}
function L2_8315(A0_8354)
  A0_8354:CliSrv_OnInit()
end
L1_8314.OnInit = L2_8315
function L2_8315(A0_8355)
  local L1_8356
end
L1_8314.OnShutDown = L2_8315
L0_8313.Server = L1_8314
L0_8313 = AudioAreaAmbience
L1_8314 = {}
function L2_8315(A0_8357)
  A0_8357:RegisterForAreaEvents(1)
  A0_8357:_LookupControlIDs()
  A0_8357:_LookupObstructionSwitchIDs()
  A0_8357:CliSrv_OnInit()
end
L1_8314.OnInit = L2_8315
function L2_8315(A0_8358)
  A0_8358.nState = 0
  A0_8358:RegisterForAreaEvents(0)
  A0_8358:Stop()
end
L1_8314.OnShutDown = L2_8315
function L2_8315(A0_8359, A1_8360, A2_8361, A3_8362)
  if A0_8359.nState == 0 then
    A0_8359:_PlayFirstTime()
    A0_8359.nState = 1
    A0_8359.fFadeValue = 0
    A0_8359:_UpdateRtpc()
  end
end
L1_8314.OnAudioListenerEnterNearArea = L2_8315
function L2_8315(A0_8363, A1_8364, A2_8365, A3_8366, A4_8367)
  A0_8363.nState = 1
  A0_8363:UpdateFadeValue(A1_8364, A3_8366, A4_8367)
end
L1_8314.OnAudioListenerMoveNearArea = L2_8315
function L2_8315(A0_8368, A1_8369, A2_8370, A3_8371)
  if A0_8368.nState == 0 then
    A0_8368:_PlayFirstTime()
  end
  A0_8368.nState = 2
  A0_8368.fFadeValue = 1
  A0_8368:_UpdateRtpc()
  A0_8368:_DisableObstruction()
end
L1_8314.OnAudioListenerEnterArea = L2_8315
function L2_8315(A0_8372, A1_8373, A2_8374, A3_8375)
  if A3_8375 > 0 then
    A0_8372.nState = 2
    A0_8372:UpdateFadeValue(A1_8373, A3_8375, 0)
  else
    A0_8372:UpdateFadeValue(A1_8373, 0, 0)
  end
end
L1_8314.OnAudioListenerProceedFadeArea = L2_8315
function L2_8315(A0_8376, A1_8377, A2_8378, A3_8379)
  A0_8376.nState = 1
  A0_8376:_SetObstruction()
end
L1_8314.OnAudioListenerLeaveArea = L2_8315
function L2_8315(A0_8380, A1_8381, A2_8382, A3_8383)
  A0_8380:Stop()
  A0_8380.nState = 0
  A0_8380.fFadeValue = 0
  A0_8380:_UpdateRtpc()
end
L1_8314.OnAudioListenerLeaveNearArea = L2_8315
function L2_8315(A0_8384)
  local L1_8385
  A0_8384.nState = 0
end
L1_8314.OnUnBindThis = L2_8315
function L2_8315(A0_8386, A1_8387)
  if A0_8386.hOnTriggerID == A1_8387 then
    A0_8386:ActivateOutput("Done", true)
  end
end
L1_8314.OnSoundDone = L2_8315
L0_8313.Client = L1_8314
L0_8313 = AudioAreaAmbience
function L1_8314(A0_8388, A1_8389)
  A0_8388.Properties.bEnabled = true
  A0_8388:OnPropertyChange()
end
L0_8313.Event_Enable = L1_8314
L0_8313 = AudioAreaAmbience
function L1_8314(A0_8390, A1_8391)
  A0_8390.Properties.bEnabled = false
  A0_8390:OnPropertyChange()
end
L0_8313.Event_Disable = L1_8314
L0_8313 = AudioAreaAmbience
L1_8314 = {}
L2_8315 = {}
L3_8316 = {
  AudioAreaAmbience.Event_Enable,
  "bool"
}
L2_8315.Enable = L3_8316
L3_8316 = {
  AudioAreaAmbience.Event_Disable,
  "bool"
}
L2_8315.Disable = L3_8316
L1_8314.Inputs = L2_8315
L2_8315 = {}
L2_8315.Done = "bool"
L1_8314.Outputs = L2_8315
L0_8313.FlowEvents = L1_8314
