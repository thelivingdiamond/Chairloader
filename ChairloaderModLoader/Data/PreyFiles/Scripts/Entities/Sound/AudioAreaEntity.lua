local L0_8392, L1_8393, L2_8394, L3_8395
L0_8392 = {}
L0_8392.type = "AudioAreaEntity"
L1_8393 = {}
L1_8393.Model = "Editor/Objects/Sound.cgf"
L1_8393.Icon = "AudioAreaEntity.bmp"
L0_8392.Editor = L1_8393
L1_8393 = {}
L1_8393.bEnabled = true
L1_8393.audioEnvironmentEnvironment = ""
L1_8393.eiSoundObstructionType = 1
L1_8393.fFadeDistance = 5
L1_8393.fEnvironmentDistance = 5
L0_8392.Properties = L1_8393
L0_8392.fFadeValue = 0
L0_8392.nState = 0
L0_8392.fFadeOnUnregister = 1
L0_8392.hEnvironmentID = nil
L1_8393 = {}
L0_8392.tObstructionType = L1_8393
AudioAreaEntity = L0_8392
L0_8392 = AudioAreaEntity
function L1_8393(A0_8396, A1_8397, A2_8398)
  if A0_8396.Properties.bEnabled then
    A0_8396:ActivateOutput(A1_8397, A2_8398)
  end
end
L0_8392._ActivateOutput = L1_8393
L0_8392 = AudioAreaEntity
function L1_8393(A0_8399)
  A0_8399.hEnvironmentID = AudioUtils.LookupAudioEnvironmentID(A0_8399.Properties.audioEnvironmentEnvironment)
  if A0_8399.hEnvironmentID ~= nil then
    A0_8399:SetAudioEnvironmentID(A0_8399.hEnvironmentID)
  end
  A0_8399:SetFadeDistance(A0_8399.Properties.fFadeDistance)
  A0_8399:SetEnvironmentFadeDistance(A0_8399.Properties.fEnvironmentDistance)
end
L0_8392._UpdateParameters = L1_8393
L0_8392 = AudioAreaEntity
function L1_8393(A0_8400)
  A0_8400.tObstructionType = AudioUtils.LookupObstructionSwitchAndStates()
end
L0_8392._LookupObstructionSwitchIDs = L1_8393
L0_8392 = AudioAreaEntity
function L1_8393(A0_8401)
  local L1_8402, L2_8403, L3_8404, L5_8405
  L1_8402 = A0_8401.Properties
  L1_8402 = L1_8402.eiSoundObstructionType
  L1_8402 = L1_8402 + 1
  L2_8403 = A0_8401.tObstructionType
  L2_8403 = L2_8403.hSwitchID
  if L2_8403 ~= nil then
    L2_8403 = A0_8401.tObstructionType
    L2_8403 = L2_8403.tStateIDs
    L2_8403 = L2_8403[L1_8402]
    if L2_8403 ~= nil then
      L3_8404 = A0_8401
      L2_8403 = A0_8401.SetAudioSwitchState
      L5_8405 = A0_8401.tObstructionType
      L5_8405 = L5_8405.hSwitchID
      L2_8403(L3_8404, L5_8405, A0_8401.tObstructionType.tStateIDs[L1_8402], A0_8401:GetDefaultAuxAudioProxyID())
    end
  end
end
L0_8392._SetObstruction = L1_8393
L0_8392 = AudioAreaEntity
function L1_8393(A0_8406)
  A0_8406:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
end
L0_8392.OnSpawn = L1_8393
L0_8392 = AudioAreaEntity
function L1_8393(A0_8407, A1_8408)
  A0_8407.Properties = A1_8408.Properties
  A0_8407.fFadeOnUnregister = A1_8408.fFadeOnUnregister
  A0_8407:_SetObstruction()
  A0_8407.nState = 0
  A0_8407.fFadeValue = 0
end
L0_8392.OnLoad = L1_8393
L0_8392 = AudioAreaEntity
function L1_8393(A0_8409)
  A0_8409:_UpdateParameters()
end
L0_8392.OnPostLoad = L1_8393
L0_8392 = AudioAreaEntity
function L1_8393(A0_8410, A1_8411)
  local L2_8412
  L2_8412 = A0_8410.Properties
  A1_8411.Properties = L2_8412
  L2_8412 = A0_8410.fFadeOnUnregister
  A1_8411.fFadeOnUnregister = L2_8412
end
L0_8392.OnSave = L1_8393
L0_8392 = AudioAreaEntity
function L1_8393(A0_8413)
  A0_8413:_UpdateParameters()
  if A0_8413.Properties.eiSoundObstructionType < 0 then
    A0_8413.Properties.eiSoundObstructionType = 0
  elseif A0_8413.Properties.eiSoundObstructionType > 1 then
    A0_8413.Properties.eiSoundObstructionType = 2
  end
  A0_8413:_SetObstruction()
end
L0_8392.OnPropertyChange = L1_8393
L0_8392 = AudioAreaEntity
function L1_8393(A0_8414)
  A0_8414.nState = 0
  A0_8414.fFadeValue = 0
  A0_8414.fFadeOnUnregister = 1
  A0_8414:SetFlags(ENTITY_FLAG_VOLUME_SOUND, 0)
  A0_8414:_UpdateParameters()
end
L0_8392.CliSrv_OnInit = L1_8393
L0_8392 = AudioAreaEntity
function L1_8393(A0_8415, A1_8416, A2_8417, A3_8418)
  local L4_8419
  L4_8419 = A0_8415.Properties
  L4_8419 = L4_8419.bEnabled
  if not L4_8419 or A2_8417 == 0 and A3_8418 == 0 then
    L4_8419 = A0_8415.fFadeValue
    if L4_8419 ~= 0 then
      L4_8419 = A0_8415._ActivateOutput
      L4_8419(A0_8415, "FadeValue", 0)
    end
    A0_8415.fFadeValue = 0
    return
  end
  L4_8419 = A0_8415.Properties
  L4_8419 = L4_8419.fFadeDistance
  if L4_8419 > 0 then
    L4_8419 = A0_8415.nState
    if L4_8419 == 2 then
      L4_8419 = A0_8415.fFadeValue
      if L4_8419 ~= A2_8417 then
        L4_8419 = math
        L4_8419 = L4_8419.abs
        L4_8419 = L4_8419(A2_8417)
        A0_8415.fFadeValue = L4_8419
        L4_8419 = A0_8415._ActivateOutput
        L4_8419(A0_8415, "FadeValue", A0_8415.fFadeValue)
      end
    else
      L4_8419 = math
      L4_8419 = L4_8419.sqrt
      L4_8419 = L4_8419(A3_8418)
      L4_8419 = L4_8419 / A0_8415.Properties.fFadeDistance
      L4_8419 = 1 - L4_8419
      A0_8415.fFadeValue = math.max(0, L4_8419)
      A0_8415:_ActivateOutput("FadeValue", A0_8415.fFadeValue)
    end
  end
end
L0_8392.UpdateFadeValue = L1_8393
L0_8392 = AudioAreaEntity
L1_8393 = {}
function L2_8394(A0_8420)
  A0_8420:CliSrv_OnInit()
end
L1_8393.OnInit = L2_8394
function L2_8394(A0_8421)
  local L1_8422
end
L1_8393.OnShutDown = L2_8394
L0_8392.Server = L1_8393
L0_8392 = AudioAreaEntity
L1_8393 = {}
function L2_8394(A0_8423)
  A0_8423:RegisterForAreaEvents(1)
  A0_8423:_LookupObstructionSwitchIDs()
  A0_8423:CliSrv_OnInit()
end
L1_8393.OnInit = L2_8394
function L2_8394(A0_8424)
  A0_8424.nState = 0
  A0_8424:RegisterForAreaEvents(0)
end
L1_8393.OnShutDown = L2_8394
function L2_8394(A0_8425, A1_8426, A2_8427, A3_8428)
  if A0_8425.nState == 0 then
    A0_8425:_SetObstruction()
    A0_8425:_ActivateOutput("OnFarToNear", true)
  elseif A0_8425.nState == 2 then
    A0_8425:_ActivateOutput("OnInsideToNear", true)
  end
  A0_8425.nState = 1
  A0_8425.fFadeValue = 0
  A0_8425:_ActivateOutput("FadeValue", A0_8425.fFadeValue)
end
L1_8393.OnAudioListenerEnterNearArea = L2_8394
function L2_8394(A0_8429, A1_8430, A2_8431, A3_8432, A4_8433)
  A0_8429.nState = 1
  A0_8429:UpdateFadeValue(A1_8430, A3_8432, A4_8433)
end
L1_8393.OnAudioListenerMoveNearArea = L2_8394
function L2_8394(A0_8434, A1_8435, A2_8436, A3_8437)
  if A0_8434.nState == 0 then
    A0_8434:_SetObstruction()
    A0_8434:_ActivateOutput("OnFarToNear", true)
  end
  A0_8434.nState = 2
  A0_8434.fFadeValue = 1
  A0_8434:_ActivateOutput("OnNearToInside", true)
  A0_8434:_ActivateOutput("FadeValue", A0_8434.fFadeValue)
end
L1_8393.OnAudioListenerEnterArea = L2_8394
function L2_8394(A0_8438, A1_8439, A2_8440, A3_8441)
  if A3_8441 > 0 then
    A0_8438.nState = 2
    A0_8438:UpdateFadeValue(A1_8439, A3_8441, 0)
  else
    A0_8438:UpdateFadeValue(A1_8439, 0, 0)
  end
end
L1_8393.OnAudioListenerProceedFadeArea = L2_8394
function L2_8394(A0_8442, A1_8443, A2_8444, A3_8445)
  A0_8442.nState = 1
  A0_8442:_ActivateOutput("OnInsideToNear", true)
end
L1_8393.OnAudioListenerLeaveArea = L2_8394
function L2_8394(A0_8446, A1_8447, A2_8448, A3_8449)
  A0_8446.nState = 0
  A0_8446.fFadeValue = 0
  A0_8446:_ActivateOutput("OnNearToFar", true)
  A0_8446:_ActivateOutput("FadeValue", A0_8446.fFadeValue)
end
L1_8393.OnAudioListenerLeaveNearArea = L2_8394
function L2_8394(A0_8450)
  local L1_8451
  A0_8450.nState = 0
end
L1_8393.OnUnBindThis = L2_8394
L0_8392.Client = L1_8393
L0_8392 = AudioAreaEntity
function L1_8393(A0_8452, A1_8453)
  A0_8452.Properties.bEnabled = true
  A0_8452:OnPropertyChange()
end
L0_8392.Event_Enable = L1_8393
L0_8392 = AudioAreaEntity
function L1_8393(A0_8454, A1_8455)
  A0_8454.Properties.bEnabled = false
  A0_8454:OnPropertyChange()
end
L0_8392.Event_Disable = L1_8393
L0_8392 = AudioAreaEntity
L1_8393 = {}
L2_8394 = {}
L3_8395 = {
  AudioAreaEntity.Event_Enable,
  "bool"
}
L2_8394.Enable = L3_8395
L3_8395 = {
  AudioAreaEntity.Event_Disable,
  "bool"
}
L2_8394.Disable = L3_8395
L1_8393.Inputs = L2_8394
L2_8394 = {}
L2_8394.FadeValue = "float"
L2_8394.OnFarToNear = "bool"
L2_8394.OnNearToInside = "bool"
L2_8394.OnInsideToNear = "bool"
L2_8394.OnNearToFar = "bool"
L1_8393.Outputs = L2_8394
L0_8392.FlowEvents = L1_8393
