local L0_5442, L1_5443, L2_5444, L3_5445
L0_5442 = {}
L0_5442.type = "HUD_MessagePlane"
L1_5443 = {}
L1_5443.bEnabled = 1
L0_5442.Properties = L1_5443
L1_5443 = {}
L1_5443.Icon = "Prompt.bmp"
L1_5443.IconOnTop = 1
L1_5443.Model = "Objects/hud/HintTest.cgf"
L0_5442.Editor = L1_5443
HUD_MessagePlane = L0_5442
L0_5442 = HUD_MessagePlane
function L1_5443(A0_5446)
  A0_5446:OnReset()
  A0_5446:Enable(tonumber(A0_5446.Properties.bEnabled) ~= 0)
  if System.IsEditor() then
    A0_5446:LoadObject(0, A0_5446.Editor.Model)
  end
end
L0_5442.OnInit = L1_5443
L0_5442 = HUD_MessagePlane
function L1_5443(A0_5447, A1_5448)
  if A1_5448 then
    A0_5447:DrawSlot(0, 0)
  else
    A0_5447:DrawSlot(0, 1)
  end
end
L0_5442.OnEditorSetGameMode = L1_5443
L0_5442 = HUD_MessagePlane
function L1_5443(A0_5449)
  A0_5449:OnReset()
end
L0_5442.OnPropertyChange = L1_5443
L0_5442 = HUD_MessagePlane
function L1_5443(A0_5450, A1_5451)
  A0_5450.enabled = A1_5451
end
L0_5442.Enable = L1_5443
L0_5442 = HUD_MessagePlane
function L1_5443(A0_5452)
  local L1_5453
end
L0_5442.OnReset = L1_5443
L0_5442 = HUD_MessagePlane
function L1_5443(A0_5454, A1_5455)
end
L0_5442.OnSave = L1_5443
L0_5442 = HUD_MessagePlane
function L1_5443(A0_5456, A1_5457)
end
L0_5442.OnLoad = L1_5443
L0_5442 = HUD_MessagePlane
function L1_5443(A0_5458)
  local L1_5459
end
L0_5442.OnPostLoad = L1_5443
L0_5442 = HUD_MessagePlane
function L1_5443(A0_5460)
  local L1_5461
end
L0_5442.OnShutDown = L1_5443
L0_5442 = HUD_MessagePlane
function L1_5443(A0_5462)
  local L1_5463
  L1_5463 = A0_5462.enabled
  return L1_5463
end
L0_5442.IsEnabled = L1_5443
L0_5442 = HUD_MessagePlane
function L1_5443(A0_5464)
  A0_5464:Enable(true)
  BroadcastEvent(A0_5464, "Enabled")
end
L0_5442.Event_Enable = L1_5443
L0_5442 = HUD_MessagePlane
function L1_5443(A0_5465)
  A0_5465:Enable(false)
  BroadcastEvent(A0_5465, "Disabled")
end
L0_5442.Event_Disable = L1_5443
L0_5442 = HUD_MessagePlane
L1_5443 = {}
L2_5444 = {}
L3_5445 = {
  HUD_MessagePlane.Event_Enable,
  "bool"
}
L2_5444.Enable = L3_5445
L3_5445 = {
  HUD_MessagePlane.Event_Disable,
  "bool"
}
L2_5444.Disable = L3_5445
L1_5443.Inputs = L2_5444
L2_5444 = {}
L2_5444.Enabled = "bool"
L2_5444.Disabled = "bool"
L1_5443.Outputs = L2_5444
L0_5442.FlowEvents = L1_5443
