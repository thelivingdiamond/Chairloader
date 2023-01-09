Script.ReloadScript("Scripts/Utils/Math.lua")
Script.ReloadScript("Scripts/Entities/Vehicles/VehicleSeat.lua")
VehicleBase = {
  State = {
    pos = {},
    aiDriver = nil
  },
  Seats = {},
  AI = {},
  Client = {},
  Server = {},
  Hit = {}
}
function VehicleBase.HasDriver(A0_9130)
  for _FORV_4_, _FORV_5_ in pairs(A0_9130.Seats) do
    if _FORV_5_.isDriver and _FORV_5_.passengerId then
      return true
    end
  end
  return false
end
function VehicleBase.GetDriverId(A0_9131)
  if A0_9131.Seats and A0_9131.Seats[1] then
    return A0_9131.Seats[1].seat:GetPassengerId()
  end
  return nil
end
function VehicleBase.Server.OnSpawnComplete(A0_9132)
  A0_9132.vehicle:OnSpawnComplete()
end
function GetNextAvailableSeat(A0_9133)
  for _FORV_4_, _FORV_5_ in pairs(A0_9133) do
    if not _FORV_5_.seat:GetPassengerId() then
      return _FORV_4_
    end
  end
  return -1
end
function VehicleBase.InitSeats(A0_9134)
  local L1_9135, L2_9136, L3_9137, L4_9138, L5_9139
  if L1_9135 then
    for L4_9138, L5_9139 in L1_9135(L2_9136) do
      mergef(L5_9139, VehicleSeat, 1)
      L5_9139:Init(A0_9134, L4_9138)
    end
  end
end
function VehicleBase.InitVehicleBase(A0_9140)
  A0_9140:OnPropertyChange()
  if A0_9140.Properties.bSyncPhysics == 0 then
    CryAction.DontSyncPhysics(A0_9140.id)
  end
end
function VehicleBase.OnPropertyChange(A0_9141)
  if A0_9141.OnPropertyChangeExtra then
    A0_9141:OnPropertyChangeExtra()
  end
end
function VehicleBase.DestroyVehicleBase(A0_9142)
  if A0_9142.DestroyAI then
    A0_9142:DestroyAI()
  end
end
function VehicleBase.GetExitPos(A0_9143, A1_9144)
  local L2_9145
  L2_9145 = A0_9143.Seats
  L2_9145 = L2_9145[A1_9144]
  if L2_9145 == nil then
    L2_9145 = Log
    L2_9145("VehicleBase:GetExitPos(seatId) - Invalid seat id: " .. tostring(A1_9144))
    return
  end
  L2_9145 = nil
  if A0_9143.Seats[A1_9144].exitHelper then
    L2_9145 = A0_9143.vehicle:MultiplyWithWorldTM(A0_9143:GetVehicleHelperPos(A0_9143.Seats[A1_9144].exitHelper))
  else
    L2_9145 = A0_9143.vehicle:MultiplyWithWorldTM(A0_9143:GetVehicleHelperPos(A0_9143.Seats[A1_9144].enterHelper))
  end
  return L2_9145
end
function VehicleBase.GetSeatPos(A0_9146, A1_9147)
  local L2_9148, L3_9149
  if A1_9147 == -1 then
    L2_9148 = Log
    L3_9149 = "Error: VehicleBase:GetSeatPos(seatId) - seatId -1 is invalid"
    L2_9148(L3_9149)
    L2_9148 = {}
    L2_9148.x = 0
    L2_9148.y = 0
    L2_9148.z = 0
    return L2_9148
  else
    L2_9148 = A0_9146.Seats
    L2_9148 = L2_9148[A1_9147]
    L2_9148 = L2_9148.enterHelper
    L3_9149 = nil
    if A0_9146.vehicle:HasHelper(L2_9148) then
      L3_9149 = A0_9146.vehicle:GetHelperWorldPos(L2_9148)
    else
      L3_9149 = A0_9146:GetHelperPos(L2_9148, HELPER_WORLD)
    end
    return L3_9149
  end
end
function VehicleBase.OnUsed(A0_9150, A1_9151, A2_9152)
  if not CryAction.IsClient() then
    return
  end
  A0_9150.vehicle:OnUsed(A1_9151.id, A2_9152)
end
function VehicleBase.IsUsable(A0_9153, A1_9154)
  if A1_9154:IsOnVehicle() then
    return 0
  end
  if A0_9153.vehicle:IsUsable(A1_9154.id) ~= 0 then
    return (A0_9153.vehicle:IsUsable(A1_9154.id))
  end
  return 0
end
function VehicleBase.CanEnter(A0_9155, A1_9156)
  if g_gameRules and g_gameRules.CanEnterVehicle then
    return g_gameRules:CanEnterVehicle(A0_9155, A1_9156)
  end
end
function VehicleBase.GetSeat(A0_9157, A1_9158)
  if A0_9157.vehicle:GetSeatForPassenger(A1_9158) then
    return A0_9157.Seats[A0_9157.vehicle:GetSeatForPassenger(A1_9158)]
  end
  return nil
end
function VehicleBase.GetSeatByIndex(A0_9159, A1_9160)
  return A0_9159.Seats[A1_9160]
end
function VehicleBase.GetSeatId(A0_9161, A1_9162)
  return A0_9161.vehicle:GetSeatForPassenger(A1_9162)
end
function VehicleBase.ResetVehicleBase(A0_9163)
  A0_9163.State.pos = A0_9163:GetWorldPos(A0_9163.State.pos)
  if A0_9163.AIDriver then
    A0_9163:AIDriver(0)
  end
  A0_9163.State.aiDriver = nil
  A0_9163:OnPropertyChange()
  if A0_9163.Seats then
    for _FORV_4_, _FORV_5_ in pairs(A0_9163.Seats) do
      if _FORV_5_ and _FORV_5_.OnReset then
        _FORV_5_:OnReset()
      end
    end
  end
  if A0_9163.ResetAI then
    A0_9163:ResetAI()
  end
end
function VehicleBase.OnShutDown(A0_9164)
  Game.RemoveTacticalEntity(A0_9164.id, eTacticalEntity_Vehicle)
end
function VehicleBase.OnDestroy(A0_9165)
  A0_9165:DestroyVehicleBase()
end
function VehicleBase.UseCustomFiring(A0_9166, A1_9167)
  local L2_9168
  L2_9168 = false
  return L2_9168
end
function VehicleBase.GetFiringPos(A0_9169, A1_9170)
  return g_Vectors.v000
end
function VehicleBase.GetFiringVelocity(A0_9171)
  return g_Vectors.v000
end
function VehicleBase.OnAIShoot(A0_9172)
  local L1_9173
  L1_9173 = A0_9172.Seats
  L1_9173 = L1_9173[1]
  L1_9173 = L1_9173.GetWeaponId
  L1_9173 = L1_9173(L1_9173, 1)
  if L1_9173 then
    System.GetEntity(L1_9173):StartFire(A0_9172.id)
    System.GetEntity(L1_9173):StopFire()
  end
end
function VehicleBase.PrepareSeatMountedWeapon(A0_9174, A1_9175)
  local L2_9176, L3_9177
  L3_9177 = A0_9174
  L2_9176 = A0_9174.GetSeat
  L2_9176 = L2_9176(L3_9177, A1_9175.id)
  if L2_9176 then
    L3_9177 = A1_9175.PrepareForMountedWeaponUse
    if L3_9177 then
      L3_9177 = L2_9176.seat
      L3_9177 = L3_9177.GetWeaponId
      L3_9177 = L3_9177(L3_9177, 1)
      if L3_9177 then
        A1_9175:PrepareForMountedWeaponUse(L3_9177)
      end
    end
  end
end
function VehicleBase.IsGunner(A0_9178, A1_9179)
  if A0_9178:GetSeat(A1_9179) and A0_9178:GetSeat(A1_9179).Weapons then
    return true
  end
  return false
end
function VehicleBase.IsDriver(A0_9180, A1_9181)
  if A0_9180:GetSeat(A1_9181) and A0_9180:GetSeat(A1_9181).isDriver then
    return true
  end
  return false
end
function VehicleBase.GetVehicleHelperPos(A0_9182, A1_9183)
  local L2_9184
  A1_9183 = A1_9183 or ""
  L2_9184 = nil
  if A0_9182.vehicle:HasHelper(A1_9183) then
    L2_9184 = A0_9182.vehicle:GetHelperPos(A1_9183, true)
  else
    L2_9184 = A0_9182:GetHelperPos(A1_9183, HELPER_LOCAL)
  end
  return L2_9184
end
function VehicleBase.RequestSeatByPosition(A0_9185, A1_9186)
  local L2_9187, L3_9188, L4_9189, L5_9190, L6_9191, L7_9192, L8_9193, L9_9194
  L2_9187 = System
  L2_9187 = L2_9187.GetEntity
  L3_9188 = A1_9186
  L2_9187 = L2_9187(L3_9188)
  L3_9188 = L2_9187
  L2_9187 = L2_9187.GetWorldPos
  L2_9187 = L2_9187(L3_9188)
  L3_9188 = 10
  for L7_9192, L8_9193 in L4_9189(L5_9190) do
    L9_9194 = L8_9193.enterHelper
    if L9_9194 then
      L9_9194 = L8_9193.passengerId
      if not L9_9194 then
        L9_9194 = L8_9193.useBoundsForEntering
        if L9_9194 ~= nil then
          L9_9194 = L8_9193.useBoundsForEntering
        else
          if L9_9194 == true then
            L9_9194 = A0_9185.vehicle
            L9_9194 = L9_9194.IsInsideRadius
            L9_9194 = L9_9194(L9_9194, L2_9187, 1)
            if L9_9194 then
              return L7_9192
            end
        end
        else
          L9_9194 = nil
          if A0_9185.vehicle:HasHelper(L8_9193.enterHelper) then
            L9_9194 = A0_9185.vehicle:GetHelperWorldPos(L8_9193.enterHelper)
          else
            L9_9194 = A0_9185:GetHelperPos(L8_9193.enterHelper, HELPER_WORLD)
          end
          if L3_9188 >= DistanceSqVectors(L2_9187, L9_9194) then
            return L7_9192
          end
        end
      end
    end
  end
  return L4_9189
end
function VehicleBase.RequestClosestSeat(A0_9195, A1_9196)
  local L2_9197, L3_9198, L4_9199, L5_9200, L6_9201, L7_9202, L8_9203, L9_9204, L10_9205
  L2_9197 = System
  L2_9197 = L2_9197.GetEntity
  L3_9198 = A1_9196
  L2_9197 = L2_9197(L3_9198)
  L3_9198 = L2_9197
  L2_9197 = L2_9197.GetWorldPos
  L2_9197 = L2_9197(L3_9198)
  L3_9198 = 100000
  L4_9199 = nil
  for L8_9203, L9_9204 in L5_9200(L6_9201) do
    L10_9205 = L9_9204.enterHelper
    if L10_9205 then
      L10_9205 = L9_9204.IsFree
      L10_9205 = L10_9205(L9_9204, A1_9196)
      if L10_9205 then
        L10_9205 = nil
        if A0_9195.vehicle:HasHelper(L9_9204.enterHelper) then
          L10_9205 = A0_9195.vehicle:GetHelperWorldPos(L9_9204.enterHelper)
        else
          L10_9205 = A0_9195:GetHelperPos(L9_9204.enterHelper, HELPER_WORLD)
        end
        if L3_9198 >= DistanceSqVectors(L2_9197, L10_9205) then
          L3_9198 = DistanceSqVectors(L2_9197, L10_9205)
          L4_9199 = L8_9203
        end
      end
    end
  end
  if L4_9199 then
    if L5_9200 then
      L8_9203 = L4_9199
      L5_9200(L6_9201)
    end
  elseif L5_9200 then
    L5_9200(L6_9201)
  end
  return L4_9199
end
function VehicleBase.RequestMostPrioritarySeat(A0_9206, A1_9207)
  local L2_9208, L3_9209, L4_9210, L5_9211, L6_9212, L7_9213, L8_9214
  L2_9208 = System
  L2_9208 = L2_9208.GetEntity
  L3_9209 = A1_9207
  L2_9208 = L2_9208(L3_9209)
  L3_9209 = L2_9208
  L2_9208 = L2_9208.GetWorldPos
  L2_9208 = L2_9208(L3_9209)
  L3_9209 = nil
  L4_9210 = A0_9206.Seats
  L4_9210 = L4_9210[1]
  if L5_9211 then
    return L5_9211
  end
  for L8_9214, _FORV_9_ in L5_9211(L6_9212) do
    if _FORV_9_.enterHelper and _FORV_9_.Weapons and _FORV_9_:IsFree(A1_9207) then
      if AI then
        AI.LogEvent(System.GetEntity(A1_9207):GetName() .. " found seat " .. L8_9214)
      end
      return L8_9214
    end
  end
  for L8_9214, _FORV_9_ in L5_9211(L6_9212) do
    if _FORV_9_.enterHelper and _FORV_9_:IsFree(A1_9207) then
      if AI then
        AI.LogEvent(System.GetEntity(A1_9207):GetName() .. " found seat " .. L8_9214)
      end
      return L8_9214
    end
  end
  return
end
function VehicleBase.RequestSeat(A0_9215, A1_9216)
  for _FORV_7_, _FORV_8_ in pairs(A0_9215.Seats) do
    if _FORV_8_:IsFree(A1_9216) then
      return _FORV_7_
    end
  end
  return nil
end
function VehicleBase.EnterVehicle(A0_9217, A1_9218, A2_9219, A3_9220)
  return A0_9217.vehicle:EnterVehicle(A1_9218, A2_9219, A3_9220)
end
function VehicleBase.LeaveVehicle(A0_9221, A1_9222, A2_9223)
  if AI then
    AI.Signal(SIGNALFILTER_SENDER, 0, "exited_vehicle", A1_9222)
  end
  return A0_9221.vehicle:ExitVehicle(A1_9222)
end
function VehicleBase.ReserveSeat(A0_9224, A1_9225, A2_9226)
  local L3_9227
  L3_9227 = A0_9224.Seats
  L3_9227 = L3_9227[A2_9226]
  L3_9227.passengerId = A1_9225
end
function VehicleBase.IsDead(A0_9228)
  return A0_9228.vehicle:IsDestroyed()
end
function VehicleBase.GetWeaponVelocity(A0_9229, A1_9230)
  return A0_9229:GetFiringVelocity()
end
function VehicleBase.OnShoot(A0_9231, A1_9232, A2_9233)
  if A1_9232.userId and A0_9231:GetSeat(A1_9232.userId) and A0_9231:GetSeat(A1_9232.userId).Animations and A0_9231:GetSeat(A1_9232.userId).Animations.weaponRecoil then
    if System.GetEntity(A1_9232.userId):IsDead() then
      return
    end
    System.GetEntity(A1_9232.userId):StartAnimation(0, A0_9231:GetSeat(A1_9232.userId).Animations.weaponRecoil, 0, 1.0E-9, 1, false)
  end
  return true
end
function VehicleBase.SpawnVehicleBase(A0_9234)
  if A0_9234.OnPreSpawn then
    A0_9234:OnPreSpawn()
  end
  if _G[A0_9234.class .. "Properties"] then
    mergef(A0_9234, _G[A0_9234.class .. "Properties"], 1)
  end
  if A0_9234.OnPreInit then
    A0_9234:OnPreInit()
  end
  A0_9234:InitVehicleBase()
  A0_9234.ProcessMovement = nil
  if A0_9234.OnPostSpawn then
    A0_9234:OnPostSpawn()
  end
  if A0_9234.AIMovementAbility and A0_9234.Properties.aiSpeedMult and A0_9234.Properties.aiSpeedMult ~= 1 then
    if A0_9234.AIMovementAbility.walkSpeed then
      A0_9234.AIMovementAbility.walkSpeed = A0_9234.AIMovementAbility.walkSpeed * A0_9234.Properties.aiSpeedMult
    end
    if A0_9234.AIMovementAbility.runSpeed then
      A0_9234.AIMovementAbility.runSpeed = A0_9234.AIMovementAbility.runSpeed * A0_9234.Properties.aiSpeedMult
    end
    if A0_9234.AIMovementAbility.sprintSpeed then
      A0_9234.AIMovementAbility.sprintSpeed = A0_9234.AIMovementAbility.sprintSpeed * A0_9234.Properties.aiSpeedMult
    end
    if A0_9234.AIMovementAbility.maneuverSpeed then
      A0_9234.AIMovementAbility.maneuverSpeed = A0_9234.AIMovementAbility.maneuverSpeed * A0_9234.Properties.aiSpeedMult
    end
  end
  if A0_9234.InitAI then
    A0_9234:InitAI()
  end
  A0_9234:InitSeats()
  A0_9234:OnReset()
  ApplyCollisionFiltering(A0_9234, GetCollisionFiltering(A0_9234))
  Game.AddTacticalEntity(A0_9234.id, eTacticalEntity_Vehicle)
end
function VehicleBase.Client.OnHit(A0_9235, A1_9236)
end
function VehicleBase.ProcessPassengerDamage(A0_9237, A1_9238, A2_9239, A3_9240, A4_9241, A5_9242)
  return A0_9237.vehicle:ProcessPassengerDamage(A1_9238, A2_9239, A3_9240, A4_9241, A5_9242)
end
function VehicleBase.OnActorSitDown(A0_9243, A1_9244, A2_9245)
  local L3_9246, L4_9247
  L3_9246 = System
  L3_9246 = L3_9246.GetEntity
  L4_9247 = A2_9245
  L3_9246 = L3_9246(L4_9247)
  if not L3_9246 then
    L4_9247 = Log
    L4_9247("Error: entity for player id <%s> could not be found. %s", tostring(A2_9245))
    return
  end
  L4_9247 = A0_9243.Seats
  L4_9247 = L4_9247[A1_9244]
  if not L4_9247 then
    Log("Error: entity for player id <%s> could not be found!", tostring(A2_9245))
    return
  end
  if g_gameRules.OnEnterVehicleSeat then
    g_gameRules:OnEnterVehicleSeat(A0_9243, L4_9247, A2_9245)
  end
  if L4_9247.isDriver then
    A0_9243:SetTimer(AISOUND_TIMER, AISOUND_TIMEOUT)
  end
  L4_9247.passengerId = A2_9245
  L3_9246.vehicleId = A0_9243.id
  L3_9246.AI.theVehicle = A0_9243
  if CryAction.HasAI(A2_9245) and L4_9247.isDriver then
    A0_9243.State.aiDriver = 1
    if A0_9243.AIDriver then
      if L3_9246.actor and L3_9246.actor:GetHealth() > 0 then
        A0_9243:AIDriver(1)
      else
        A0_9243:AIDriver(0)
      end
    end
  end
  if not L3_9246.ai then
    if A0_9243.hidesUser == 1 then
      if AI and not (L4_9247.Sounds and 0 < L4_9247.seat:GetWeaponCount() and L4_9247.Sounds.inout == 1) then
        AI.ChangeParameter(A2_9245, AIPARAM_INVISIBLE, 1)
      end
    end
    if AI and L4_9247.isDriver then
      CopyVector(g_SignalData.point, g_Vectors.v000)
      CopyVector(g_SignalData.point2, g_Vectors.v000)
      g_SignalData.iValue = AIUSEOP_VEHICLE
      g_SignalData.iValue2 = 1
      g_SignalData.fValue = 1
      g_SignalData.id = L4_9247.vehicleId
      AI.Signal(SIGNALFILTER_LEADER, 1, "ORD_USE", A2_9245, g_SignalData)
    end
    A0_9243:EnableMountedWeapons(false)
  end
  if L4_9247.isDriver and AI.GetFactionOf(L3_9246.id) and A0_9243.ChangeFaction then
    A0_9243:ChangeFaction(L3_9246, 1)
  else
  end
  if AI then
    if 0 < L4_9247.seat:GetWeaponCount() then
      AI.Signal(SIGNALFILTER_SENDER, 1, "entered_vehicle_gunner", A2_9245)
    else
      AI.Signal(SIGNALFILTER_SENDER, 1, "entered_vehicle", A2_9245)
    end
    AI.Signal(SIGNALFILTER_SENDER, 9, "ENTERING_END", A2_9245)
  end
end
function VehicleBase.OnActorChangeSeat(A0_9248, A1_9249, A2_9250)
  local L3_9251
  L3_9251 = Log
  L3_9251("ai changed a seat")
  L3_9251 = A0_9248.GetSeat
  L3_9251 = L3_9251(A0_9248, A1_9249)
  if not L3_9251 then
    Log("Error: VehicleBase:OnActorChangeSeat() could not find passenger id %s on the vehicle", tostring(A1_9249))
    return
  end
  L3_9251.passengerId = nil
  if g_gameRules and g_gameRules.OnLeaveVehicleSeat then
    g_gameRules:OnLeaveVehicleSeat(A0_9248, L3_9251, A1_9249, A2_9250)
  end
  if not passenger then
    return
  end
  passenger.vehicleId = nil
  passenger.vehicleSeatId = nil
  if passenger.ai and passenger:IsDead() then
    return
  end
  if L3_9251.isDriver then
    A0_9248.State.aiDriver = nil
    if passenger.ai and A2_9250 and A0_9248.AIDriver then
      A0_9248:AIDriver(0)
    end
  end
  BroadcastEvent(A0_9248, "PassengerExit")
end
function VehicleBase.OnActorStandUp(A0_9252, A1_9253, A2_9254)
  local L3_9255
  L3_9255 = A0_9252.GetSeat
  L3_9255 = L3_9255(A0_9252, A1_9253)
  if not L3_9255 then
    Log("Error: VehicleBase:OnActorStandUp() could not find passenger id %s on the vehicle", tostring(A1_9253))
    return
  end
  L3_9255.passengerId = nil
  if g_gameRules and g_gameRules.OnLeaveVehicleSeat then
    g_gameRules:OnLeaveVehicleSeat(A0_9252, L3_9255, A1_9253, A2_9254)
  end
  if not System.GetEntity(A1_9253) then
    return
  end
  System.GetEntity(A1_9253).vehicleId = nil
  System.GetEntity(A1_9253).vehicleSeatId = nil
  if System.GetEntity(A1_9253).ai and System.GetEntity(A1_9253):IsDead() then
    return
  end
  if L3_9255.isDriver then
    A0_9252.State.aiDriver = nil
    if A2_9254 and A0_9252.AIDriver and CryAction.HasAI(A1_9253) then
      A0_9252:AIDriver(0)
    end
  end
  if System.GetEntity(A1_9253).ai ~= 1 and A2_9254 then
    if A0_9252.ChangeFaction then
      A0_9252:ChangeFaction()
    end
    if AI then
      AI.Signal(SIGNALFILTER_LEADERENTITY, 0, "ORD_LEAVE_VEHICLE", A1_9253)
      AI.Signal(SIGNALFILTER_GROUPONLY, 0, "ORDER_EXIT_VEHICLE", A1_9253)
      System.GetEntity(A1_9253).AI.theVehicle = nil
    end
  end
  if A0_9252.AI.unloadCount then
    A0_9252.AI.unloadCount = A0_9252.AI.unloadCount - 1
  end
  if A0_9252.AI.unloadCount == 0 then
    AI.Signal(SIGNALFILTER_SENDER, 9, "UNLOAD_DONE", A0_9252.id)
  end
  if A2_9254 and System.GetEntity(A1_9253).AI.theVehicle ~= nil and AI then
    AI.Signal(SIGNALFILTER_SENDER, 0, "EXIT_VEHICLE_STAND", System.GetEntity(A1_9253).id)
  end
  if not System.GetEntity(A1_9253).ai then
    if AI then
      AI.ChangeParameter(A1_9253, AIPARAM_INVISIBLE, 0)
    end
    A0_9252:EnableMountedWeapons(true)
  end
  if AI then
    AI.Signal(SIGNALFILTER_SENDER, 9, "EXITING_END", A1_9253)
  end
  BroadcastEvent(A0_9252, "PassengerExit")
end
function VehicleBase.EnableMountedWeapons(A0_9256, A1_9257)
  local L2_9258, L3_9259, L4_9260, L5_9261, L6_9262, L7_9263, L8_9264, L9_9265, L10_9266, L11_9267, L12_9268
  if not L2_9258 then
    return
  end
  if not L2_9258 then
    return
  end
  for L5_9261, L6_9262 in L2_9258(L3_9259) do
    L7_9263 = L6_9262.seat
    L7_9263 = L7_9263.GetWeaponCount
    L7_9263 = L7_9263(L8_9264)
    for L11_9267 = 1, L7_9263 do
      L12_9268 = L6_9262.seat
      L12_9268 = L12_9268.GetWeaponId
      L12_9268 = L12_9268(L12_9268, L11_9267)
      if L12_9268 then
        if A1_9257 then
          AI.SetSmartObjectState(L12_9268, "Idle")
        else
          AI.SetSmartObjectState(L12_9268, "Busy")
        end
      end
    end
  end
end
