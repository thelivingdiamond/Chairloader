local L0_9408, L1_9409
L0_9408 = {}
VehicleSeat = L0_9408
L0_9408 = VehicleSeat
function L1_9409(A0_9410, A1_9411, A2_9412)
  A0_9410.vehicleId = A1_9411.id
  A0_9410.seatId = A2_9412
  A0_9410.status = 0
  A0_9410.playerId = 0
  if System.GetEntity(A0_9410.vehicleId).vehicle then
    System.GetEntity(A0_9410.vehicleId).vehicle:AddSeat(A0_9410)
  end
end
L0_9408.Init = L1_9409
L0_9408 = VehicleSeat
function L1_9409(A0_9413)
  local L1_9414
end
L0_9408.OnReset = L1_9409
L0_9408 = VehicleSeat
function L1_9409(A0_9415, A1_9416)
  return A0_9415.seat:IsFree(A1_9416)
end
L0_9408.IsFree = L1_9409
L0_9408 = VehicleSeat
function L1_9409(A0_9417)
  local L1_9418, L2_9419
  L1_9418 = System
  L1_9418 = L1_9418.GetEntity
  L2_9419 = A0_9417.vehicleId
  L1_9418 = L1_9418(L2_9419)
  L2_9419 = {}
  L2_9419.x = 0
  L2_9419.y = 0
  L2_9419.z = 0
  if A0_9417.exitHelper then
    L2_9419 = L1_9418.vehicle:MultiplyWithWorldTM(L1_9418:GetVehicleHelperPos(A0_9417.exitHelper))
  elseif A0_9417.enterHelper then
    L2_9419 = L1_9418.vehicle:MultiplyWithWorldTM(L1_9418:GetVehicleHelperPos(A0_9417.enterHelper))
  end
  if LengthSqVector(L2_9419) == 0 then
    CopyVector(L2_9419, L1_9418.State.pos)
    L2_9419.z = L2_9419.z + 1
  end
  return L2_9419
end
L0_9408.GetExitPos = L1_9409
L0_9408 = VehicleSeat
function L1_9409(A0_9420, A1_9421)
  if A0_9420.Weapons and A0_9420.Weapons[A1_9421] then
    return A0_9420.seat:GetWeapon(i)
  else
    Log("Error: weapon index #%s invalid.", tostring(A1_9421))
  end
end
L0_9408.GetWeaponId = L1_9409
L0_9408 = VehicleSeat
function L1_9409(A0_9422)
  return count(A0_9422.Weapons)
end
L0_9408.GetWeaponCount = L1_9409
L0_9408 = VehicleSeat
function L1_9409(A0_9423)
  local L1_9424
  L1_9424 = true
  return L1_9424
end
L0_9408.IsPassengerReady = L1_9409
L0_9408 = VehicleSeat
function L1_9409(A0_9425)
  local L1_9426
  L1_9426 = A0_9425.isRemote
  return L1_9426
end
L0_9408.IsPassengerRemote = L1_9409
L0_9408 = VehicleSeat
function L1_9409(A0_9427, A1_9428)
end
L0_9408.OnUpdate = L1_9409
L0_9408 = VehicleSeat
function L1_9409(A0_9429)
  local L1_9430
end
L0_9408.OnUpdateView = L1_9409
L0_9408 = VehicleSeat
function L1_9409(A0_9431, A1_9432)
end
L0_9408.LoadPassenger = L1_9409
