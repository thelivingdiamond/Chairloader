Script.ReloadScript("scripts/Entities/Sound/Shared/AudioUtils.lua")
Lightning = {
  Properties = {
    bActive = 1,
    fDistance = 0,
    fDistanceVariation = 0.2,
    bRelativeToPlayer = 0,
    Timing = {
      fDelay = 5,
      fDelayVariation = 0.5,
      fLightningDuration = 0.2
    },
    Effects = {
      LightRadius = 1000,
      LightIntensity = 1,
      ParticleEffect = "",
      ParticleScale = 1,
      ParticleScaleVariation = 0.2,
      SkyHighlightVerticalOffset = 0,
      SkyHighlightMultiplier = 1,
      color_SkyHighlightColor = {
        x = 0.8,
        y = 0.8,
        z = 1
      },
      SkyHighlightAtten = 10
    },
    Audio = {
      audioTriggerPlayTrigger = "",
      audioTriggerStopTrigger = "",
      audioRTPCDistanceRtpc = "",
      fSpeedOfSoundScale = 1
    }
  },
  TempPos = {
    x = 0,
    y = 0,
    z = 0
  },
  Editor = {
    Model = "Editor/Objects/Particles.cgf",
    Icon = "Lightning.bmp"
  },
  _LightTable = {
    diffuse_color = {
      x = 1,
      y = 1,
      z = 1
    },
    specular_color = {
      x = 1,
      y = 1,
      z = 1
    }
  },
  _ParticleTable = {},
  _SkyHighlight = {
    size = 0,
    color = {
      x = 0,
      y = 0,
      z = 0
    },
    position = {
      x = 0,
      y = 0,
      z = 0
    }
  },
  _StrikeCount = 0,
  hOnTriggerID = nil,
  hOffTriggerID = nil,
  hRtpcID = nil,
  nAudioTimerMinID = 2,
  aAudioThunders = {},
  nNumAuxAudioProxies = 4,
  nNumThunder = 1
}
function Lightning._LookupControlIDs(A0_8175)
  A0_8175.hOnTriggerID = AudioUtils.LookupTriggerID(A0_8175.Properties.Audio.audioTriggerPlayTrigger)
  A0_8175.hOffTriggerID = AudioUtils.LookupTriggerID(A0_8175.Properties.Audio.audioTriggerStopTrigger)
  A0_8175.hRtpcID = AudioUtils.LookupRtpcID(A0_8175.Properties.Audio.audioRTPCDistanceRtpc)
end
function Lightning._KillAllAudioTimers(A0_8176)
  local L1_8177
  L1_8177 = 1
  while A0_8176.aAudioThunders[L1_8177] ~= nil do
    A0_8176:KillTimer(A0_8176.aAudioThunders[L1_8177].nTimerID)
    A0_8176.aAudioThunders[L1_8177].fDistance = 0
    A0_8176.aAudioThunders[L1_8177].vStrikeOffset.x = 0
    A0_8176.aAudioThunders[L1_8177].vStrikeOffset.y = 0
    A0_8176.aAudioThunders[L1_8177].vStrikeOffset.z = 0
    L1_8177 = L1_8177 + 1
  end
end
function Lightning.OnSpawn(A0_8178)
  A0_8178:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
end
function Lightning.OnInit(A0_8179)
  local L1_8180
  A0_8179.bStriking = 0
  A0_8179.light_fade = 0
  A0_8179.light_intensity = 0
  L1_8180 = {}
  L1_8180.x = 0
  L1_8180.y = 0
  L1_8180.z = 0
  A0_8179.vStrikeOffset = L1_8180
  L1_8180 = {}
  L1_8180.x = 0
  L1_8180.y = 0
  L1_8180.z = 0
  A0_8179.vSkyHighlightPos = L1_8180
  L1_8180 = A0_8179.Properties
  L1_8180 = L1_8180.bActive
  A0_8179.bActive = L1_8180
  L1_8180 = {}
  L1_8180.nTimerID = A0_8179.nAudioTimerMinID
  L1_8180.nAudioProxyID = A0_8179:GetDefaultAuxAudioProxyID()
  L1_8180.fDistance = 0
  L1_8180.vStrikeOffset = {
    x = 0,
    y = 0,
    z = 0
  }
  table.insert(A0_8179.aAudioThunders, L1_8180)
  for _FORV_5_ = 1, A0_8179.nNumAuxAudioProxies do
    L1_8180 = {
      nTimerID = A0_8179.nAudioTimerMinID + _FORV_5_,
      nAudioProxyID = A0_8179:CreateAuxAudioProxy(),
      fDistance = 0,
      vStrikeOffset = {
        x = 0,
        y = 0,
        z = 0
      }
    }
    table.insert(A0_8179.aAudioThunders, L1_8180)
  end
  _FOR_(_FOR_)
  A0_8179:ScheduleNextStrike()
  A0_8179:CacheResources()
end
function Lightning.CacheResources(A0_8181)
  A0_8181:PreLoadParticleEffect(A0_8181.Properties.Effects.ParticleEffect)
end
function Lightning.OnShutDown(A0_8182)
  A0_8182:StopStrike()
end
function Lightning.OnLoad(A0_8183, A1_8184)
  A0_8183.bActive = A1_8184.bActive
  A0_8183:StopStrike()
  A0_8183:ScheduleNextStrike()
end
function Lightning.OnSave(A0_8185, A1_8186)
  A1_8186.bActive = A0_8185.bActive
end
function Lightning.OnPropertyChange(A0_8187)
  A0_8187.bActive = A0_8187.Properties.bActive
  if A0_8187.bActive == 1 then
    A0_8187:_LookupControlIDs()
    A0_8187:ScheduleNextStrike()
  else
    A0_8187:KillTimer(0)
    A0_8187:KillTimer(1)
    A0_8187:_KillAllAudioTimers()
    if A0_8187.hOffTriggerID ~= nil then
      A0_8187:ExecuteAudioTrigger(A0_8187.hOffTriggerID, A0_8187:GetAllAuxAudioProxiesID())
    end
  end
end
function Lightning.LoadLightToSlot(A0_8188, A1_8189)
  local L2_8190, L3_8191, L4_8192, L5_8193
  L2_8190 = A0_8188.Properties
  L3_8191 = L2_8190.Effects
  L4_8192 = A0_8188._LightTable
  L4_8192.style = 0
  L4_8192.deferred_light = 1
  L4_8192.corona_scale = 1
  L4_8192.corona_dist_size_factor = 1
  L4_8192.corona_dist_intensity_factor = 1
  L5_8193 = L3_8191.LightRadius
  L4_8192.radius = L5_8193
  L5_8193 = A0_8188.light_intensity
  L5_8193 = L5_8193 * L3_8191.LightIntensity
  L4_8192.diffuse_color.x = L5_8193
  L4_8192.diffuse_color.y = L5_8193
  L4_8192.diffuse_color.z = L5_8193
  L4_8192.specular_color.x = L5_8193
  L4_8192.specular_color.y = L5_8193
  L4_8192.specular_color.z = L5_8193
  L4_8192.hdrdyn = 0
  L4_8192.lifetime = 0
  L4_8192.realtime = 1
  L4_8192.dot3 = 1
  L4_8192.cast_shadow = 0
  A0_8188:LoadLight(A1_8189, L4_8192)
  A0_8188:SetSlotPos(A1_8189, A0_8188.vStrikeOffset)
end
function Lightning.OnTimer(A0_8194, A1_8195)
  if A1_8195 == 0 then
    A0_8194:Event_Strike()
  elseif A1_8195 == 1 then
    A0_8194.bStopStrike = 1
  else
    while A0_8194.aAudioThunders[1] ~= nil do
      if A0_8194.aAudioThunders[1].nTimerID == A1_8195 then
        if A0_8194.hOnTriggerID ~= nil then
          if A0_8194.hRtpcID ~= nil then
            A0_8194:SetAudioRtpcValue(A0_8194.hRtpcID, A0_8194.aAudioThunders[1].fDistance, A0_8194.aAudioThunders[1].nAudioProxyID)
          end
          A0_8194:SetAudioProxyOffset(A0_8194.aAudioThunders[1].vStrikeOffset, A0_8194.aAudioThunders[1].nAudioProxyID)
          A0_8194:ExecuteAudioTrigger(A0_8194.hOnTriggerID, A0_8194.aAudioThunders[1].nAudioProxyID)
        end
        A0_8194.aAudioThunders[1].fDistance = 0
        A0_8194.aAudioThunders[1].vStrikeOffset.x = 0
        A0_8194.aAudioThunders[1].vStrikeOffset.y = 0
        A0_8194.aAudioThunders[1].vStrikeOffset.z = 0
        break
      end
    end
  end
end
function Lightning.StopStrike(A0_8196)
  if A0_8196.bStriking == 0 then
    A0_8196:ScheduleNextStrike()
    return
  end
  A0_8196:FreeSlot(0)
  A0_8196:FreeSlot(1)
  A0_8196:Activate(0)
  A0_8196.bStriking = 0
  A0_8196.bStopStrike = 0
  A0_8196:ScheduleNextStrike()
  A0_8196._SkyHighlight.size = 0
  A0_8196._SkyHighlight.color.x = 0
  A0_8196._SkyHighlight.color.y = 0
  A0_8196._SkyHighlight.color.z = 0
  A0_8196._SkyHighlight.position.x = 0
  A0_8196._SkyHighlight.position.y = 0
  A0_8196._SkyHighlight.position.z = 0
  System.SetSkyHighlight(A0_8196._SkyHighlight)
  A0_8196._StrikeCount = A0_8196._StrikeCount - 1
end
function Lightning.OnUpdate(A0_8197, A1_8198)
  A0_8197.light_intensity = A0_8197.light_intensity - A0_8197.light_fade * A1_8198
  if A0_8197.light_intensity <= 0 then
    if A0_8197.bStopStrike == 1 then
      A0_8197:StopStrike()
      return
    end
    A0_8197.light_intensity = 1 - math.random() * 0.5
    A0_8197.light_fade = 3 + math.random() * 5
  end
  A0_8197:UpdateLightningParams()
end
function Lightning.OnStartGame(A0_8199)
  CryAction.ForceGameObjectUpdate(A0_8199.id, true)
end
function Lightning.UpdateLightningParams(A0_8200)
  A0_8200:LoadLightToSlot(0)
  A0_8200._SkyHighlight.color.x = A0_8200.light_intensity * A0_8200.Properties.Effects.SkyHighlightMultiplier * A0_8200.Properties.Effects.color_SkyHighlightColor.x
  A0_8200._SkyHighlight.color.y = A0_8200.light_intensity * A0_8200.Properties.Effects.SkyHighlightMultiplier * A0_8200.Properties.Effects.color_SkyHighlightColor.y
  A0_8200._SkyHighlight.color.z = A0_8200.light_intensity * A0_8200.Properties.Effects.SkyHighlightMultiplier * A0_8200.Properties.Effects.color_SkyHighlightColor.z
  A0_8200._SkyHighlight.size = A0_8200.Properties.Effects.SkyHighlightAtten
  A0_8200._SkyHighlight.position.x = A0_8200.vSkyHighlightPos.x
  A0_8200._SkyHighlight.position.y = A0_8200.vSkyHighlightPos.y
  A0_8200._SkyHighlight.position.z = A0_8200.vSkyHighlightPos.z + A0_8200.Properties.Effects.SkyHighlightVerticalOffset
  System.SetSkyHighlight(A0_8200._SkyHighlight)
end
function Lightning.GetValueWithVariation(A0_8201, A1_8202, A2_8203)
  return A1_8202 + (math.random() * 2 - 1) * A1_8202 * A2_8203
end
function Lightning.ScheduleNextStrike(A0_8204)
  local L1_8205
  L1_8205 = A0_8204.bActive
  if L1_8205 == 1 then
    L1_8205 = A0_8204.Properties
    L1_8205 = L1_8205.Timing
    L1_8205 = L1_8205.fDelay
    L1_8205 = A0_8204.Properties.Timing.fLightningDuration + A0_8204:GetValueWithVariation(L1_8205, A0_8204.Properties.Timing.fDelayVariation)
    A0_8204:SetTimer(0, L1_8205 * 1000)
  end
end
function Lightning.Event_Strike(A0_8206)
  local L1_8207, L2_8208, L3_8209, L4_8210, L5_8211, L6_8212, L7_8213, L8_8214, L9_8215, L10_8216
  L1_8207 = A0_8206.bStriking
  if L1_8207 == 0 then
    A0_8206.bStriking = 1
    L1_8207 = A0_8206._StrikeCount
    L1_8207 = L1_8207 + 1
    A0_8206._StrikeCount = L1_8207
    L1_8207 = A0_8206.Properties
    L2_8208 = L1_8207.Effects
    L3_8209 = math
    L3_8209 = L3_8209.random
    L3_8209 = L3_8209()
    L3_8209 = L3_8209 * 0.5
    L3_8209 = 1 - L3_8209
    A0_8206.light_intensity = L3_8209
    L3_8209 = math
    L3_8209 = L3_8209.random
    L3_8209 = L3_8209()
    L3_8209 = L3_8209 * 5
    L3_8209 = 3 + L3_8209
    A0_8206.light_fade = L3_8209
    L4_8210 = A0_8206
    L3_8209 = A0_8206.GetPos
    L3_8209 = L3_8209(L4_8210)
    L4_8210 = System
    L4_8210 = L4_8210.GetViewCameraDir
    L4_8210 = L4_8210()
    L5_8211 = System
    L5_8211 = L5_8211.GetViewCameraPos
    L5_8211 = L5_8211()
    L6_8212 = L3_8209
    L8_8214 = A0_8206
    L7_8213 = A0_8206.GetValueWithVariation
    L9_8215 = L1_8207.fDistance
    L10_8216 = L1_8207.fDistanceVariation
    L7_8213 = L7_8213(L8_8214, L9_8215, L10_8216)
    L8_8214 = 0
    L9_8215 = 360
    L10_8216 = L1_8207.bRelativeToPlayer
    if L10_8216 == 1 then
      L10_8216 = L4_8210.x
      if L10_8216 > 0 then
        L10_8216 = L4_8210.y
        if L10_8216 > 0 then
          L8_8214 = -90
          L9_8215 = 180
        end
      end
      L10_8216 = L4_8210.x
      if L10_8216 > 0 then
        L10_8216 = L4_8210.y
        if L10_8216 < 0 then
          L8_8214 = 0
          L9_8215 = 270
        end
      end
      L10_8216 = L4_8210.x
      if L10_8216 < 0 then
        L10_8216 = L4_8210.y
        if L10_8216 < 0 then
          L8_8214 = 90
          L9_8215 = 360
        end
      end
      L10_8216 = L4_8210.x
      if L10_8216 < 0 then
        L10_8216 = L4_8210.y
        if L10_8216 > 0 then
          L8_8214 = 180
          L9_8215 = 450
        end
      end
      L8_8214 = L8_8214 + 100
      L9_8215 = L9_8215 - 100
    end
    L10_8216 = math
    L10_8216 = L10_8216.random
    L10_8216 = L10_8216()
    L10_8216 = L10_8216 * (L9_8215 - L8_8214)
    L10_8216 = L8_8214 + L10_8216
    L10_8216 = L10_8216 * 3.14
    L10_8216 = L10_8216 / 180
    A0_8206.vStrikeOffset.x = L7_8213 * math.sin(L10_8216)
    A0_8206.vStrikeOffset.y = L7_8213 * math.cos(L10_8216)
    if L1_8207.bRelativeToPlayer == 1 then
      A0_8206.vStrikeOffset.x = A0_8206.vStrikeOffset.x + (L5_8211.x - L3_8209.x)
      A0_8206.vStrikeOffset.y = A0_8206.vStrikeOffset.y + (L5_8211.y - L3_8209.y)
    end
    A0_8206.vSkyHighlightPos.x = L3_8209.x + A0_8206.vStrikeOffset.x
    A0_8206.vSkyHighlightPos.y = L3_8209.y + A0_8206.vStrikeOffset.y
    A0_8206.vSkyHighlightPos.z = L3_8209.z
    if L2_8208.ParticleEffect ~= "" then
      A0_8206._ParticleTable.Scale = A0_8206:GetValueWithVariation(L2_8208.ParticleScale, L2_8208.ParticleScaleVariation) * math.sqrt((L5_8211.x - (L3_8209.x + A0_8206.vStrikeOffset.x)) * (L5_8211.x - (L3_8209.x + A0_8206.vStrikeOffset.x)) + (L5_8211.y - (L3_8209.y + A0_8206.vStrikeOffset.y)) * (L5_8211.y - (L3_8209.y + A0_8206.vStrikeOffset.y)))
      A0_8206:LoadParticleEffect(1, L2_8208.ParticleEffect, A0_8206._ParticleTable)
      A0_8206:SetSlotPos(1, A0_8206.vStrikeOffset)
    end
    A0_8206:UpdateLightningParams()
    if A0_8206.hOnTriggerID ~= nil then
      if A0_8206.nNumThunder > A0_8206.nNumAuxAudioProxies + 1 then
        A0_8206.nNumThunder = 1
      end
      A0_8206.aAudioThunders[A0_8206.nNumThunder].fDistance = math.sqrt((L5_8211.x - (L3_8209.x + A0_8206.vStrikeOffset.x)) * (L5_8211.x - (L3_8209.x + A0_8206.vStrikeOffset.x)) + (L5_8211.y - (L3_8209.y + A0_8206.vStrikeOffset.y)) * (L5_8211.y - (L3_8209.y + A0_8206.vStrikeOffset.y)))
      A0_8206.aAudioThunders[A0_8206.nNumThunder].vStrikeOffset.x = A0_8206.vStrikeOffset.x
      A0_8206.aAudioThunders[A0_8206.nNumThunder].vStrikeOffset.y = A0_8206.vStrikeOffset.y
      A0_8206.aAudioThunders[A0_8206.nNumThunder].vStrikeOffset.z = A0_8206.vStrikeOffset.z
      A0_8206:SetTimer(A0_8206.aAudioThunders[A0_8206.nNumThunder].nTimerID, math.sqrt((L5_8211.x - (L3_8209.x + A0_8206.vStrikeOffset.x)) * (L5_8211.x - (L3_8209.x + A0_8206.vStrikeOffset.x)) + (L5_8211.y - (L3_8209.y + A0_8206.vStrikeOffset.y)) * (L5_8211.y - (L3_8209.y + A0_8206.vStrikeOffset.y))) / 340.29 * A0_8206.Properties.Audio.fSpeedOfSoundScale * 1000)
      A0_8206.nNumThunder = A0_8206.nNumThunder + 1
    end
    A0_8206:SetTimer(1, A0_8206:GetValueWithVariation(A0_8206.Properties.Timing.fLightningDuration, 0.5) * 1000)
    A0_8206:Activate(1)
  end
  L1_8207 = BroadcastEvent
  L2_8208 = A0_8206
  L3_8209 = "Strike"
  L1_8207(L2_8208, L3_8209)
end
function Lightning.Event_Enable(A0_8217)
  if A0_8217.bActive == 0 then
    A0_8217.bActive = 1
    A0_8217:ScheduleNextStrike()
  end
end
function Lightning.Event_Disable(A0_8218)
  local L1_8219
  A0_8218.bActive = 0
end
Lightning.FlowEvents = {
  Inputs = {
    Strike = {
      Lightning.Event_Strike,
      "bool"
    },
    Enable = {
      Lightning.Event_Enable,
      "bool"
    },
    Disable = {
      Lightning.Event_Disable,
      "bool"
    }
  },
  Outputs = {Strike = "bool"}
}
