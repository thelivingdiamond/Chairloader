local L0_8047, L1_8048, L2_8049, L3_8050
L0_8047 = {}
L1_8048 = {}
L2_8049 = {}
L2_8049.fFadeInTime = 0.1
L2_8049.fFadeOutTime = 0.1
L2_8049.fFlashDuration = 1
L1_8048.Timing = L2_8049
L2_8049 = {}
L2_8049.SkyHighlightMultiplier = 1
L3_8050 = {}
L3_8050.x = 0.8
L3_8050.y = 0.8
L3_8050.z = 1
L2_8049.color_SkyHighlightColor = L3_8050
L2_8049.SkyHighlightAtten = 10
L2_8049.sound_Sound = ""
L1_8048.Effects = L2_8049
L0_8047.Properties = L1_8048
L1_8048 = {}
L1_8048.x = 0
L1_8048.y = 0
L1_8048.z = 0
L0_8047.TempPos = L1_8048
L1_8048 = {}
L1_8048.Icon = "Flash.bmp"
L0_8047.Editor = L1_8048
L1_8048 = {}
L1_8048.size = 0
L2_8049 = {}
L2_8049.x = 0
L2_8049.y = 0
L2_8049.z = 0
L1_8048.color = L2_8049
L2_8049 = {}
L2_8049.x = 0
L2_8049.y = 0
L2_8049.z = 0
L1_8048.position = L2_8049
L0_8047._SkyHighlight = L1_8048
Flash = L0_8047
L0_8047 = Flash
function L1_8048(A0_8051)
  local L1_8052
  A0_8051.bStriking = 0
  A0_8051.light_fade = 0
  A0_8051.time = 0
  A0_8051.state = 0
  A0_8051.light_intensity = 0
  L1_8052 = {}
  L1_8052.x = 0
  L1_8052.y = 0
  L1_8052.z = 0
  A0_8051.vStrikeOffset = L1_8052
  L1_8052 = {}
  L1_8052.x = 0
  L1_8052.y = 0
  L1_8052.z = 0
  A0_8051.vSkyHighlightPos = L1_8052
end
L0_8047.OnInit = L1_8048
L0_8047 = Flash
function L1_8048(A0_8053)
  A0_8053:StopStrike()
end
L0_8047.OnShutDown = L1_8048
L0_8047 = Flash
function L1_8048(A0_8054)
  A0_8054.bStriking = 0
  A0_8054.bStopStrike = 0
  A0_8054.state = 0
  A0_8054._SkyHighlight.size = 0
  A0_8054._SkyHighlight.color.x = 0
  A0_8054._SkyHighlight.color.y = 0
  A0_8054._SkyHighlight.color.z = 0
  A0_8054._SkyHighlight.position.x = 0
  A0_8054._SkyHighlight.position.y = 0
  A0_8054._SkyHighlight.position.z = 0
  System.SetSkyHighlight(A0_8054._SkyHighlight)
  A0_8054:Activate(0)
end
L0_8047.StopStrike = L1_8048
L0_8047 = Flash
function L1_8048(A0_8055, A1_8056)
  A0_8055:StopStrike()
  A0_8055.bStriking = A1_8056.bStriking
  A0_8055.light_fade = A1_8056.light_fade
  A0_8055.time = A1_8056.time
  A0_8055.state = A1_8056.state
  A0_8055.light_intensity = A1_8056.light_intensity
  A0_8055.vStrikeOffset = A1_8056.vStrikeOffset
  A0_8055.vSkyHighlightPos = A1_8056.vSkyHighlightPos
  if A1_8056.bActive == true then
    A0_8055:Activate(1)
  end
end
L0_8047.OnLoad = L1_8048
L0_8047 = Flash
function L1_8048(A0_8057, A1_8058)
  A1_8058.bActive = A0_8057:IsActive()
  A1_8058.bStriking = A0_8057.bStriking
  A1_8058.light_fade = A0_8057.light_fade
  A1_8058.time = A0_8057.time
  A1_8058.state = A0_8057.state
  A1_8058.light_intensity = A0_8057.light_intensity
  A1_8058.vStrikeOffset = A0_8057.vStrikeOffset
  A1_8058.vSkyHighlightPos = A0_8057.vSkyHighlightPos
end
L0_8047.OnSave = L1_8048
L0_8047 = Flash
function L1_8048(A0_8059, A1_8060)
  if A0_8059.state == 0 then
    A0_8059.light_fade = 1 / A0_8059.Properties.Timing.fFadeInTime
    A0_8059.time = A0_8059.time + A1_8060
    if A0_8059.Properties.Timing.fFadeInTime < A0_8059.time then
      A0_8059.state = 1
      A0_8059.time = 0
    end
  elseif A0_8059.state == 1 then
    A0_8059.light_intensity = 1
    A0_8059.light_fade = 0
    A0_8059.time = A0_8059.time + A1_8060
    if A0_8059.Properties.Timing.fFlashDuration < A0_8059.time then
      A0_8059.state = 2
      A0_8059.time = 0
    end
  elseif A0_8059.state == 2 then
    A0_8059.light_fade = -1 / A0_8059.Properties.Timing.fFadeOutTime
    A0_8059.time = A0_8059.time + A1_8060
    if A0_8059.Properties.Timing.fFadeOutTime < A0_8059.time then
      A0_8059.time = 0
      A0_8059:StopStrike()
    end
  end
  A0_8059.light_intensity = A0_8059.light_intensity + A0_8059.light_fade * A1_8060
  if 1 < A0_8059.light_intensity then
    A0_8059.light_intensity = 1
  end
  if 0 > A0_8059.light_intensity then
    A0_8059.light_intensity = 0
  end
  A0_8059:UpdateFlashParams()
end
L0_8047.OnUpdate = L1_8048
L0_8047 = Flash
function L1_8048(A0_8061)
  local L1_8062, L2_8063
  L1_8062 = A0_8061.Properties
  L1_8062 = L1_8062.Effects
  L2_8063 = A0_8061.light_intensity
  L2_8063 = L2_8063 * L1_8062.SkyHighlightMultiplier
  A0_8061._SkyHighlight.color.x = L2_8063 * L1_8062.color_SkyHighlightColor.x
  A0_8061._SkyHighlight.color.y = L2_8063 * L1_8062.color_SkyHighlightColor.y
  A0_8061._SkyHighlight.color.z = L2_8063 * L1_8062.color_SkyHighlightColor.z
  A0_8061._SkyHighlight.size = L1_8062.SkyHighlightAtten
  A0_8061._SkyHighlight.position.x = A0_8061.vSkyHighlightPos.x
  A0_8061._SkyHighlight.position.y = A0_8061.vSkyHighlightPos.y
  A0_8061._SkyHighlight.position.z = A0_8061.vSkyHighlightPos.z
  System.SetSkyHighlight(A0_8061._SkyHighlight)
end
L0_8047.UpdateFlashParams = L1_8048
L0_8047 = Flash
function L1_8048(A0_8064)
  if A0_8064.bStriking == 0 then
    A0_8064.bStriking = 1
    A0_8064.vSkyHighlightPos.x = A0_8064:GetPos().x
    A0_8064.vSkyHighlightPos.y = A0_8064:GetPos().y
    A0_8064.vSkyHighlightPos.z = A0_8064:GetPos().z
    A0_8064.bStriking = 0
    A0_8064.light_fade = 0
    A0_8064.time = 0
    A0_8064.state = 0
    A0_8064.light_intensity = 0
    A0_8064.light_fade = 1 / A0_8064.Properties.Timing.fFadeInTime
    A0_8064:UpdateFlashParams()
    if A0_8064.Properties.Effects.sound_Sound ~= "" then
    end
    A0_8064:Activate(1)
  end
  BroadcastEvent(A0_8064, "Strike")
end
L0_8047.Event_Strike = L1_8048
L0_8047 = Flash
function L1_8048(A0_8065)
  A0_8065:StopStrike()
  BroadcastEvent(A0_8065, "Stop")
end
L0_8047.Event_Stop = L1_8048
L0_8047 = Flash
L1_8048 = {}
L2_8049 = {}
L3_8050 = {
  Flash.Event_Strike,
  "bool"
}
L2_8049.Strike = L3_8050
L3_8050 = {
  Flash.Event_Stop,
  "bool"
}
L2_8049.Stop = L3_8050
L1_8048.Inputs = L2_8049
L2_8049 = {}
L2_8049.Strike = "bool"
L2_8049.Stop = "bool"
L1_8048.Outputs = L2_8049
L0_8047.FlowEvents = L1_8048
