local L0_8096, L1_8097, L2_8098, L3_8099
L0_8096 = {}
L0_8096.type = "FogVolume"
L1_8097 = {}
L1_8097.bActive = 1
L1_8097.eiVolumeType = 0
L2_8098 = {}
L2_8098.x = 1
L2_8098.y = 1
L2_8098.z = 1
L1_8097.Size = L2_8098
L2_8098 = {}
L2_8098.x = 1
L2_8098.y = 1
L2_8098.z = 1
L1_8097.color_Color = L2_8098
L1_8097.fHDRDynamic = 0
L1_8097.bUseGlobalFogColor = 0
L1_8097.GlobalDensity = 1
L1_8097.DensityOffset = 0
L1_8097.NearCutoff = 0
L1_8097.FallOffDirLong = 0
L1_8097.FallOffDirLati = 90
L1_8097.FallOffShift = 0
L1_8097.FallOffScale = 1
L1_8097.SoftEdges = 1
L1_8097.RampStart = 0
L1_8097.RampEnd = 50
L1_8097.RampInfluence = 0
L1_8097.WindInfluence = 1
L1_8097.DensityNoiseScale = 0
L1_8097.DensityNoiseOffset = 0
L1_8097.DensityNoiseTimeFrequency = 0
L2_8098 = {}
L2_8098.x = 10
L2_8098.y = 10
L2_8098.z = 10
L1_8097.DensityNoiseFrequency = L2_8098
L1_8097.bIgnoresVisAreas = 0
L1_8097.bAffectsThisAreaOnly = 0
L0_8096.Properties = L1_8097
L1_8097 = {}
L1_8097.fadeTime = 0
L1_8097.fadeToValue = 0
L0_8096.Fader = L1_8097
L1_8097 = {}
L1_8097.Model = "Editor/Objects/invisiblebox.cgf"
L1_8097.Icon = "FogVolume.bmp"
L1_8097.ShowBounds = 1
L0_8096.Editor = L1_8097
FogVolume = L0_8096
L0_8096 = FogVolume
function L1_8097(A0_8100)
  A0_8100:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
  A0_8100:SetFlags(ENTITY_FLAG_NO_PROXIMITY, 0)
end
L0_8096.OnSpawn = L1_8097
L0_8096 = FogVolume
function L1_8097(A0_8101)
  local L1_8102
  L1_8102 = A0_8101.Properties
  A0_8101:LoadFogVolume(0, A0_8101.Properties)
end
L0_8096.InitFogVolumeProperties = L1_8097
L0_8096 = FogVolume
function L1_8097(A0_8103)
  A0_8103:InitFogVolumeProperties()
  A0_8103.active = true
end
L0_8096.CreateFogVolume = L1_8097
L0_8096 = FogVolume
function L1_8097(A0_8104)
  A0_8104:FreeSlot(0)
  A0_8104.active = false
end
L0_8096.DeleteFogVolume = L1_8097
L0_8096 = FogVolume
function L1_8097(A0_8105)
  A0_8105.active = false
  if A0_8105.Properties.bActive == 1 then
    A0_8105:CreateFogVolume()
  end
end
L0_8096.OnInit = L1_8097
L0_8096 = FogVolume
function L1_8097(A0_8106)
  local L1_8107
end
L0_8096.CheckMove = L1_8097
L0_8096 = FogVolume
function L1_8097(A0_8108)
  local L1_8109
end
L0_8096.OnShutDown = L1_8097
L0_8096 = FogVolume
function L1_8097(A0_8110)
  if A0_8110.Properties.bActive == 1 then
    A0_8110:CreateFogVolume()
  else
    A0_8110:DeleteFogVolume()
  end
end
L0_8096.OnPropertyChange = L1_8097
L0_8096 = FogVolume
function L1_8097(A0_8111, A1_8112)
  local L2_8113
  L2_8113 = false
  if A1_8112 == "GlobalDensity" then
    A0_8111:FadeGlobalDensity(0, 0, A0_8111.Properties.GlobalDensity)
    A0_8111.targetFadeValue = A0_8111.Properties.GlobalDensity
    L2_8113 = true
  end
  return L2_8113
end
L0_8096.OnPropertyAnimated = L1_8097
L0_8096 = FogVolume
function L1_8097(A0_8114)
  A0_8114.active = false
  if A0_8114.Properties.bActive == 1 then
    A0_8114:CreateFogVolume()
  end
end
L0_8096.OnReset = L1_8097
L0_8096 = FogVolume
function L1_8097(A0_8115)
  A0_8115:DeleteFogVolume()
  BroadcastEvent(A0_8115, "Hide")
end
L0_8096.Event_Hide = L1_8097
L0_8096 = FogVolume
function L1_8097(A0_8116)
  A0_8116:CreateFogVolume()
  BroadcastEvent(A0_8116, "Show")
end
L0_8096.Event_Show = L1_8097
L0_8096 = FogVolume
function L1_8097(A0_8117)
  A0_8117:FadeGlobalDensity(0, A0_8117.Fader.fadeTime, A0_8117.Fader.fadeToValue)
  A0_8117.targetFadeValue = A0_8117.Fader.fadeToValue
end
L0_8096.Event_Fade = L1_8097
L0_8096 = FogVolume
function L1_8097(A0_8118, A1_8119, A2_8120)
  A0_8118.Fader.fadeTime = A2_8120
end
L0_8096.Event_FadeTime = L1_8097
L0_8096 = FogVolume
function L1_8097(A0_8121, A1_8122, A2_8123)
  A0_8121.Fader.fadeToValue = A2_8123
end
L0_8096.Event_FadeValue = L1_8097
L0_8096 = FogVolume
function L1_8097(A0_8124)
  if A0_8124.targetFadeValue ~= nil then
    A0_8124:FadeGlobalDensity(0, 0, A0_8124.targetFadeValue)
  end
end
L0_8096.OnPostLoad = L1_8097
L0_8096 = FogVolume
function L1_8097(A0_8125, A1_8126)
  if A0_8125.active and not A1_8126.active then
    A0_8125:DeleteFogVolume()
  elseif not A0_8125.active and A1_8126.active then
    A0_8125:CreateFogVolume()
  end
  A0_8125.active = A1_8126.active
  A0_8125.targetFadeValue = A1_8126.targetFadeValue
end
L0_8096.OnLoad = L1_8097
L0_8096 = FogVolume
function L1_8097(A0_8127, A1_8128)
  local L2_8129
  L2_8129 = A0_8127.active
  A1_8128.active = L2_8129
  L2_8129 = A0_8127.targetFadeValue
  A1_8128.targetFadeValue = L2_8129
end
L0_8096.OnSave = L1_8097
L0_8096 = FogVolume
L1_8097 = {}
L2_8098 = {}
L3_8099 = {
  FogVolume.Event_Hide,
  "bool"
}
L2_8098.Hide = L3_8099
L3_8099 = {
  FogVolume.Event_Show,
  "bool"
}
L2_8098.Show = L3_8099
L3_8099 = {
  FogVolume.Event_FadeTime,
  "float"
}
L2_8098.x_Time = L3_8099
L3_8099 = {
  FogVolume.Event_FadeValue,
  "float"
}
L2_8098.y_Value = L3_8099
L3_8099 = {
  FogVolume.Event_Fade,
  "bool"
}
L2_8098.z_Fade = L3_8099
L1_8097.Inputs = L2_8098
L2_8098 = {}
L2_8098.Hide = "bool"
L2_8098.Show = "bool"
L1_8097.Outputs = L2_8098
L0_8096.FlowEvents = L1_8097
