local L0_9345, L1_9346, L2_9347
L0_9345 = {}
L1_9346 = {}
L0_9345.Client = L1_9346
L1_9346 = {}
L0_9345.Server = L1_9346
L1_9346 = {}
L1_9346.bPickable = 1
L0_9345.Properties = L1_9346
L1_9346 = {}
L1_9346.Icon = "Item.bmp"
L1_9346.IconOnTop = 1
L0_9345.Editor = L1_9346
VehiclePartDetached = L0_9345
L0_9345 = VehiclePartDetached
function L1_9346(A0_9348, A1_9349)
  local L2_9350
  L2_9350 = 1
  return L2_9350
end
L0_9345.IsUsable = L1_9346
L0_9345 = VehiclePartDetached
function L1_9346(A0_9351, A1_9352)
  local L2_9353
  L2_9353 = "@grab_object"
  return L2_9353
end
L0_9345.GetUsableMessage = L1_9346
L0_9345 = VehiclePartDetached
function L1_9346(A0_9354)
  A0_9354:OnReset()
end
L0_9345.OnInit = L1_9346
L0_9345 = VehiclePartDetached
function L1_9346(A0_9355)
  A0_9355:OnReset()
end
L0_9345.OnPropertyChange = L1_9346
L0_9345 = VehiclePartDetached
function L1_9346(A0_9356)
  local L1_9357
end
L0_9345.OnReset = L1_9346
L0_9345 = VehiclePartDetached
function L1_9346(A0_9358, A1_9359)
end
L0_9345.SetObjectModel = L1_9346
L0_9345 = VehiclePartDetached
function L1_9346(A0_9360)
  local L1_9361
end
L0_9345.OnShutDown = L1_9346
L0_9345 = VehiclePartDetached
function L1_9346(A0_9362, A1_9363)
end
L0_9345.Event_TargetReached = L1_9346
L0_9345 = VehiclePartDetached
function L1_9346(A0_9364, A1_9365)
end
L0_9345.Event_Enable = L1_9346
L0_9345 = VehiclePartDetached
function L1_9346(A0_9366, A1_9367)
end
L0_9345.Event_Disable = L1_9346
L0_9345 = VehiclePartDetached
function L1_9346(A0_9368, A1_9369)
  local L2_9370
  L2_9370 = 100
  return A0_9368:GetTimeSinceLastSeen() * L2_9370 + L2_9370
end
L0_9345.GetReturnToPoolWeight = L1_9346
L0_9345 = VehiclePartDetached
L1_9346 = {}
L2_9347 = {}
L1_9346.Inputs = L2_9347
L2_9347 = {}
L1_9346.Outputs = L2_9347
L0_9345.FlowEvents = L1_9346
