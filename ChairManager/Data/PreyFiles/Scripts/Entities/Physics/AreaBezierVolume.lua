local L0_7455, L1_7456, L2_7457, L3_7458
L0_7455 = {}
L0_7455.type = "AreaBezierVolume"
L1_7456 = {}
L1_7456.bEnabled = 1
L2_7457 = {}
L2_7457.bNetworked = 0
L1_7456.MultiplayerOptions = L2_7457
L0_7455.Properties = L1_7456
AreaBezierVolume = L0_7455
L0_7455 = AreaBezierVolume
function L1_7456(A0_7459)
  if A0_7459.Properties.MultiplayerOptions.bNetworked == 0 then
    A0_7459:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
  end
end
L0_7455.OnSpawn = L1_7456
L0_7455 = AreaBezierVolume
function L1_7456(A0_7460, A1_7461)
  A0_7460.bEnabled = A1_7461.bEnabled
  if A0_7460.bEnabled == 1 then
    A0_7460:Event_Enable()
  else
    A0_7460:Event_Disable()
  end
end
L0_7455.OnLoad = L1_7456
L0_7455 = AreaBezierVolume
function L1_7456(A0_7462, A1_7463)
  A1_7463.bEnabled = A0_7462.bEnabled
end
L0_7455.OnSave = L1_7456
L0_7455 = AreaBezierVolume
function L1_7456(A0_7464)
  if A0_7464.Properties.bEnabled == 1 then
    A0_7464:Event_Enable()
  else
    A0_7464:Event_Disable()
  end
end
L0_7455.OnInit = L1_7456
L0_7455 = AreaBezierVolume
function L1_7456(A0_7465)
  if A0_7465.Properties.bEnabled == 1 then
    A0_7465:Event_Enable()
  else
    A0_7465:Event_Disable()
  end
end
L0_7455.OnPropertyChange = L1_7456
L0_7455 = AreaBezierVolume
function L1_7456(A0_7466, A1_7467)
  A0_7466:SetPhysicParams(PHYSICPARAM_FOREIGNDATA, {foreignData = ZEROG_AREA_ID})
end
L0_7455.OnEnable = L1_7456
L0_7455 = AreaBezierVolume
function L1_7456(A0_7468)
  A0_7468.bEnabled = 1
  BroadcastEvent(A0_7468, "Enable")
end
L0_7455.Event_Enable = L1_7456
L0_7455 = AreaBezierVolume
function L1_7456(A0_7469)
  A0_7469.bEnabled = 0
  BroadcastEvent(A0_7469, "Disable")
end
L0_7455.Event_Disable = L1_7456
L0_7455 = AreaBezierVolume
L1_7456 = {}
L2_7457 = {}
L3_7458 = {
  AreaBezierVolume.Event_Disable,
  "bool"
}
L2_7457.Disable = L3_7458
L3_7458 = {
  AreaBezierVolume.Event_Enable,
  "bool"
}
L2_7457.Enable = L3_7458
L1_7456.Inputs = L2_7457
L2_7457 = {}
L2_7457.Disable = "bool"
L2_7457.Enable = "bool"
L1_7456.Outputs = L2_7457
L0_7455.FlowEvents = L1_7456
