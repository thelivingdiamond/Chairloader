local L0_7195, L1_7196, L2_7197, L3_7198
L0_7195 = {}
L1_7196 = {}
L1_7196.bEnabled = 1
L1_7196.bOnlyOnce = 0
L1_7196.fEMPChance = 1
L1_7196.fScanChance = 1
L0_7195.Properties = L1_7196
L1_7196 = {}
L1_7196.Icon = "switch.bmp"
L1_7196.IconOnTop = 1
L0_7195.Editor = L1_7196
SpotterScannable = L0_7195
L0_7195 = SpotterScannable
function L1_7196(A0_7199)
  local L1_7200
  A0_7199.entityId = nil
  L1_7200 = A0_7199.GetParent
  L1_7200 = L1_7200(A0_7199)
  L1_7200 = L1_7200 or A0_7199:GetChild(0)
  if L1_7200 then
    A0_7199.entityId = L1_7200.id
  end
end
L0_7195.OnStartGame = L1_7196
L0_7195 = SpotterScannable
function L1_7196(A0_7201)
  A0_7201:OnReset()
end
L0_7195.OnPropertyChange = L1_7196
L0_7195 = SpotterScannable
function L1_7196(A0_7202)
  A0_7202.onlyOnce = A0_7202.Properties.bOnlyOnce ~= 0
  A0_7202.empChance = math.min(math.max(0, A0_7202.Properties.fEMPChance), 1)
  A0_7202.scanChance = math.min(math.max(0, A0_7202.Properties.fScanChance), 1)
  A0_7202.scannable = A0_7202.Properties.bEnabled ~= 0
  A0_7202.scanned = nil
end
L0_7195.OnReset = L1_7196
L0_7195 = SpotterScannable
function L1_7196(A0_7203)
  local L1_7204
  L1_7204 = A0_7203.scannable
  L1_7204 = L1_7204 and (not L1_7204 or not L1_7204)
  return L1_7204
end
L0_7195.IsScannable = L1_7196
L0_7195 = SpotterScannable
function L1_7196(A0_7205, A1_7206)
  A0_7205:Event_ScanStarted(A1_7206)
  A0_7205.scanned = true
end
L0_7195.ScanStarted = L1_7196
L0_7195 = SpotterScannable
function L1_7196(A0_7207, A1_7208)
  A0_7207:Event_ScanEnded(A1_7208)
end
L0_7195.ScanEnded = L1_7196
L0_7195 = SpotterScannable
function L1_7196(A0_7209, A1_7210)
  A0_7209:Event_EMP(A1_7210)
end
L0_7195.EMP = L1_7196
L0_7195 = SpotterScannable
function L1_7196(A0_7211, A1_7212)
  A0_7211:Event_SpotterInterested(A1_7212)
end
L0_7195.SpotterInterested = L1_7196
L0_7195 = SpotterScannable
function L1_7196(A0_7213)
  local L1_7214
  L1_7214 = A0_7213.empChance
  return L1_7214
end
L0_7195.GetEMPChance = L1_7196
L0_7195 = SpotterScannable
function L1_7196(A0_7215)
  local L1_7216
  L1_7216 = A0_7215.scanChance
  return L1_7216
end
L0_7195.GetScanChance = L1_7196
L0_7195 = SpotterScannable
function L1_7196(A0_7217, A1_7218)
  A0_7217:ActivateOutput("Entity", A0_7217.entityId or NULL_ENTITY)
  A0_7217:ActivateOutput("Spotter", A1_7218 or NULL_ENTITY)
  BroadcastEvent(A0_7217, "ScanStarted")
end
L0_7195.Event_ScanStarted = L1_7196
L0_7195 = SpotterScannable
function L1_7196(A0_7219, A1_7220)
  A0_7219:ActivateOutput("Entity", A0_7219.entityId or NULL_ENTITY)
  A0_7219:ActivateOutput("Spotter", A1_7220 or NULL_ENTITY)
  BroadcastEvent(A0_7219, "ScanEnded")
end
L0_7195.Event_ScanEnded = L1_7196
L0_7195 = SpotterScannable
function L1_7196(A0_7221, A1_7222)
  A0_7221:ActivateOutput("Entity", A0_7221.entityId or NULL_ENTITY)
  A0_7221:ActivateOutput("Spotter", A1_7222 or NULL_ENTITY)
  BroadcastEvent(A0_7221, "SpotterInterested")
end
L0_7195.Event_SpotterInterested = L1_7196
L0_7195 = SpotterScannable
function L1_7196(A0_7223, A1_7224)
  A0_7223:ActivateOutput("Entity", A0_7223.entityId or NULL_ENTITY)
  A0_7223:ActivateOutput("Spotter", A1_7224 or NULL_ENTITY)
  BroadcastEvent(A0_7223, "EMP")
end
L0_7195.Event_EMP = L1_7196
L0_7195 = SpotterScannable
function L1_7196(A0_7225, A1_7226)
  A0_7225.scannable = true
  BroadcastEvent(A0_7225, "Enable")
end
L0_7195.Event_Enable = L1_7196
L0_7195 = SpotterScannable
function L1_7196(A0_7227, A1_7228)
  A0_7227.scannable = false
  BroadcastEvent(A0_7227, "Disable")
end
L0_7195.Event_Disable = L1_7196
L0_7195 = SpotterScannable
L1_7196 = {}
L2_7197 = {}
L3_7198 = {
  SpotterScannable.Event_Disable
}
L2_7197.Disable = L3_7198
L3_7198 = {
  SpotterScannable.Event_Enable
}
L2_7197.Enable = L3_7198
L1_7196.Inputs = L2_7197
L2_7197 = {}
L2_7197.ScanEnded = "bool"
L2_7197.ScanStarted = "bool"
L2_7197.EMP = "bool"
L2_7197.SpotterInterested = "bool"
L2_7197.Disable = "bool"
L2_7197.Enable = "bool"
L2_7197.Entity = "entity"
L2_7197.Spotter = "entity"
L1_7196.Outputs = L2_7197
L0_7195.FlowEvents = L1_7196
