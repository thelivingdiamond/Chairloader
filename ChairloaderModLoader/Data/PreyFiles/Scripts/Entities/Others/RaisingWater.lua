local L0_7088, L1_7089, L2_7090, L3_7091
L0_7088 = {}
L0_7088.type = "Trigger"
L1_7089 = {}
L1_7089.WaterVolume = ""
L1_7089.height_start = 0
L1_7089.height_end = 3
L1_7089.fSpeed = 0.1
L1_7089.fUpdateTime = 0.1
L1_7089.bDrain = 0
L1_7089.fDrainSpeed = 0.1
L0_7088.Properties = L1_7089
L0_7088.bStopped = 0
L0_7088.bDraining = 0
L1_7089 = {}
L1_7089.Icon = "item.bmp"
L0_7088.Editor = L1_7089
RaisingWater = L0_7088
L0_7088 = RaisingWater
function L1_7089(A0_7092)
  A0_7092:OnReset()
end
L0_7088.OnPropertyChange = L1_7089
L0_7088 = RaisingWater
function L1_7089(A0_7093)
  A0_7093:OnReset()
end
L0_7088.OnInit = L1_7089
L0_7088 = RaisingWater
function L1_7089(A0_7094)
  local L1_7095
end
L0_7088.OnShutDown = L1_7089
L0_7088 = RaisingWater
function L1_7089(A0_7096, A1_7097)
  local L2_7098
  L2_7098 = A0_7096.currlevel
  A1_7097.currlevel = L2_7098
  L2_7098 = A0_7096.bStopped
  A1_7097.bStopped = L2_7098
  L2_7098 = A0_7096.bDraining
  A1_7097.bDraining = L2_7098
  L2_7098 = A0_7096.band_height
  A1_7097.band_height = L2_7098
  L2_7098 = A0_7096.speed
  A1_7097.speed = L2_7098
  L2_7098 = A0_7096.drainspeed
  A1_7097.drainspeed = L2_7098
end
L0_7088.OnSave = L1_7089
L0_7088 = RaisingWater
function L1_7089(A0_7099, A1_7100)
  A0_7099.currlevel = A1_7100.currlevel
  A0_7099.bStopped = A1_7100.bStopped
  A0_7099.bDraining = A1_7100.bDraining
  A0_7099.band_height = A1_7100.band_height
  A0_7099.speed = A1_7100.speed
  A0_7099.drainspeed = A1_7100.drainspeed
  if A0_7099.currlevel > 1.0E-4 then
    A0_7099:OnTimer()
  end
end
L0_7088.OnLoad = L1_7089
L0_7088 = RaisingWater
function L1_7089(A0_7101)
  A0_7101:Activate(1)
  A0_7101.currlevel = 0
  A0_7101.bStopped = 0
  A0_7101.bDraining = 0
  A0_7101.band_height = A0_7101.Properties.height_end - A0_7101.Properties.height_start
  A0_7101.speed = (A0_7101.Properties.height_end - A0_7101.Properties.height_start) * (A0_7101.Properties.fSpeed / 100)
  A0_7101.drainspeed = (A0_7101.Properties.height_end - A0_7101.Properties.height_start) * (A0_7101.Properties.fDrainSpeed / 100)
  System.SetWaterVolumeOffset(A0_7101.Properties.WaterVolume, 0, 0, 0)
end
L0_7088.OnReset = L1_7089
L0_7088 = RaisingWater
function L1_7089(A0_7102)
  A0_7102:OnReset()
  A0_7102:SetTimer(A0_7102.Properties.fUpdateTime * 1000, 0)
  BroadcastEvent(A0_7102, "RaiseWater")
end
L0_7088.Event_RaiseWater = L1_7089
L0_7088 = RaisingWater
function L1_7089(A0_7103)
  A0_7103.bStopped = 1
  if A0_7103.Properties.bDrain == 1 then
    A0_7103.bDraining = 1
  end
  BroadcastEvent(A0_7103, "StopWater")
end
L0_7088.Event_StopWater = L1_7089
L0_7088 = RaisingWater
function L1_7089(A0_7104)
  BroadcastEvent(A0_7104, "WaterEnded")
end
L0_7088.Event_WaterEnded = L1_7089
L0_7088 = RaisingWater
function L1_7089(A0_7105)
  if A0_7105.bDraining == 1 then
    A0_7105.currlevel = A0_7105.currlevel - A0_7105.drainspeed
    System.SetWaterVolumeOffset(A0_7105.Properties.WaterVolume, 0, 0, A0_7105.currlevel)
    if math.abs(A0_7105.currlevel) > math.abs(A0_7105.Properties.height_start) then
      A0_7105:SetTimer(A0_7105.Properties.fUpdateTime * 1000, 0)
    else
      System.SetWaterVolumeOffset(A0_7105.Properties.WaterVolume, 0, 0, A0_7105.Properties.height_start)
      A0_7105:Event_WaterEnded()
    end
  else
    A0_7105.currlevel = A0_7105.currlevel + A0_7105.speed
    System.SetWaterVolumeOffset(A0_7105.Properties.WaterVolume, 0, 0, A0_7105.currlevel)
    if math.abs(A0_7105.currlevel) < math.abs(A0_7105.band_height) then
      if A0_7105.bStopped == 0 then
        A0_7105:SetTimer(A0_7105.Properties.fUpdateTime * 1000, 0)
      end
    else
      System.SetWaterVolumeOffset(A0_7105.Properties.WaterVolume, 0, 0, A0_7105.band_height)
      A0_7105:Event_WaterEnded()
    end
  end
end
L0_7088.OnTimer = L1_7089
L0_7088 = RaisingWater
L1_7089 = {}
L2_7090 = {}
L3_7091 = {
  RaisingWater.Event_RaiseWater,
  "bool"
}
L2_7090.RaiseWater = L3_7091
L3_7091 = {
  RaisingWater.Event_StopWater,
  "bool"
}
L2_7090.StopWater = L3_7091
L1_7089.Inputs = L2_7090
L2_7090 = {}
L2_7090.RaiseWater = "bool"
L2_7090.StopWater = "bool"
L2_7090.WaterEnded = "bool"
L1_7089.Outputs = L2_7090
L0_7088.FlowEvents = L1_7089
