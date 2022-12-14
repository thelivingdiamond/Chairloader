Script.ReloadScript("scripts/Utils/EntityUtils.lua")
GeomCache = {
  Properties = {
    geomcacheFile = "EngineAssets/GeomCaches/default.cax",
    bPlaying = 0,
    fStartTime = 0,
    bLooping = 0,
    objectStandIn = "",
    materialStandInMaterial = "",
    objectFirstFrameStandIn = "",
    materialFirstFrameStandInMaterial = "",
    objectLastFrameStandIn = "",
    materialLastFrameStandInMaterial = "",
    fSortOffset = 0,
    fStandInDistance = 0,
    fStreamInDistance = 0,
    Physics = {bPhysicalize = 0}
  },
  Editor = {
    Icon = "animobject.bmp",
    IconOnTop = 1
  },
  bPlaying = 0,
  currentTime = 0,
  precacheTime = 0,
  bPrecachedOutputTriggered = false
}
function GeomCache.OnLoad(A0_8130, A1_8131)
  A0_8130.currentTime = A1_8131.currentTime
end
function GeomCache.OnSave(A0_8132, A1_8133)
  A1_8133.currentTime = A0_8132.currentTime
end
function GeomCache.OnPostLoad(A0_8134)
  A0_8134:SetGeomCachePlaybackTime(A0_8134.currentTime)
end
function GeomCache.OnSpawn(A0_8135)
  A0_8135.currentTime = A0_8135.Properties.fStartTime
  A0_8135:SetFromProperties()
end
function GeomCache.OnReset(A0_8136)
  A0_8136.currentTime = A0_8136.Properties.fStartTime
  A0_8136.bPrecachedOutputTriggered = true
  A0_8136:SetFromProperties()
end
function GeomCache.SetFromProperties(A0_8137)
  local L1_8138, L2_8139
  L1_8138 = A0_8137.Properties
  L2_8139 = L1_8138.geomcacheFile
  if L2_8139 == "" then
    return
  end
  L2_8139 = A0_8137.LoadGeomCache
  L2_8139(A0_8137, 0, L1_8138.geomcacheFile)
  L2_8139 = L1_8138.bPlaying
  A0_8137.bPlaying = L2_8139
  L2_8139 = A0_8137.bPlaying
  if L2_8139 == 0 then
    L2_8139 = L1_8138.fStartTime
    A0_8137.currentTime = L2_8139
  end
  L2_8139 = A0_8137.SetGeomCachePlaybackTime
  L2_8139(A0_8137, A0_8137.currentTime)
  L2_8139 = A0_8137.SetGeomCacheParams
  L2_8139(A0_8137, L1_8138.bLooping, L1_8138.objectStandIn, L1_8138.materialStandInMaterial, L1_8138.objectFirstFrameStandIn, L1_8138.materialFirstFrameStandInMaterial, L1_8138.objectLastFrameStandIn, L1_8138.materialLastFrameStandInMaterial, L1_8138.fStandInDistance, L1_8138.fStreamInDistance)
  L2_8139 = A0_8137.SetGeomCacheStreaming
  L2_8139(A0_8137, false, 0)
  L2_8139 = A0_8137.SetGeomCacheSortOffset
  L2_8139(A0_8137, L1_8138.fSortOffset)
  L2_8139 = L1_8138.Physics
  L2_8139 = L2_8139.bPhysicalize
  if L2_8139 == 1 then
    L2_8139 = EntityCommon
    L2_8139 = L2_8139.TempPhysParams
    A0_8137:Physicalize(0, PE_ARTICULATED, L2_8139)
  end
  L2_8139 = A0_8137.Activate
  L2_8139(A0_8137, 1)
end
function GeomCache.PhysicalizeThis(A0_8140)
  local L1_8141
  L1_8141 = A0_8140.Properties
  L1_8141 = L1_8141.Physics
  EntityCommon.PhysicalizeRigid(A0_8140, 0, L1_8141, false)
end
function GeomCache.OnUpdate(A0_8142, A1_8143)
  if A0_8142.bPlaying == 1 then
    A0_8142:SetGeomCachePlaybackTime(A0_8142.currentTime)
  end
  if A0_8142:IsGeomCacheStreaming() and not A0_8142.bPrecachedOutputTriggered and A0_8142:GetGeomCachePrecachedTime() >= A0_8142.precacheTime then
    A0_8142:ActivateOutput("Precached", true)
    A0_8142.bPrecachedOutputTriggered = true
  end
  if A0_8142.bPlaying == 1 then
    A0_8142.currentTime = A0_8142.currentTime + A1_8143
  end
end
function GeomCache.OnPropertyChange(A0_8144)
  A0_8144:SetFromProperties()
end
function GeomCache.Event_Start(A0_8145, A1_8146, A2_8147)
  A0_8145.bPlaying = 1
end
function GeomCache.Event_Stop(A0_8148, A1_8149, A2_8150)
  A0_8148.bPlaying = 0
end
function GeomCache.Event_SetTime(A0_8151, A1_8152, A2_8153)
  A0_8151.currentTime = A2_8153
end
function GeomCache.Event_StartStreaming(A0_8154, A1_8155, A2_8156)
  A0_8154.bPrecachedOutputTriggered = false
  A0_8154:SetGeomCacheStreaming(true, A0_8154.currentTime)
end
function GeomCache.Event_StopStreaming(A0_8157, A1_8158, A2_8159)
  A0_8157:SetGeomCacheStreaming(false, 0)
end
function GeomCache.Event_PrecacheTime(A0_8160, A1_8161, A2_8162)
  A0_8160.precacheTime = A2_8162
end
function GeomCache.Event_Hide(A0_8163, A1_8164, A2_8165)
  A0_8163:Hide(1)
end
function GeomCache.Event_Unhide(A0_8166, A1_8167, A2_8168)
  A0_8166:Hide(0)
end
function GeomCache.Event_StopDrawing(A0_8169, A1_8170, A2_8171)
  A0_8169:SetGeomCacheDrawing(false)
end
function GeomCache.Event_StartDrawing(A0_8172, A1_8173, A2_8174)
  A0_8172:SetGeomCacheDrawing(true)
end
GeomCache.FlowEvents = {
  Inputs = {
    Start = {
      GeomCache.Event_Start,
      "any"
    },
    Stop = {
      GeomCache.Event_Stop,
      "any"
    },
    SetTime = {
      GeomCache.Event_SetTime,
      "float"
    },
    StartStreaming = {
      GeomCache.Event_StartStreaming,
      "any"
    },
    StopStreaming = {
      GeomCache.Event_StopStreaming,
      "any"
    },
    PrecacheTime = {
      GeomCache.Event_PrecacheTime,
      "float"
    },
    Hide = {
      GeomCache.Event_Hide,
      "any"
    },
    Unhide = {
      GeomCache.Event_Unhide,
      "any"
    },
    StopDrawing = {
      GeomCache.Event_StopDrawing,
      "any"
    },
    StartDrawing = {
      GeomCache.Event_StartDrawing,
      "any"
    }
  },
  Outputs = {Precached = "bool"}
}
