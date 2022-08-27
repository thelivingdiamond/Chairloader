local L0_9269, L1_9270, L2_9271
L0_9269 = {}
L1_9270 = {}
L1_9270.groupid = 173
L1_9270.aibehavior_behaviour = "TankIdle"
L1_9270.bCircularPath = 0
L1_9270.PathName = ""
L1_9270.FormationType = ""
L1_9270.bAutoDisable = 1
L0_9269.PropertiesInstance = L1_9270
L1_9270 = {}
L1_9270.soclasses_SmartObjectClass = ""
L1_9270.bAutoGenAIHidePts = 0
L1_9270.bFactionHostility = 1
L1_9270.aicharacter_character = "Tank"
L1_9270.leaderName = ""
L1_9270.followDistance = 5
L1_9270.attackrange = 100
L1_9270.commrange = 100
L1_9270.accuracy = 1
L1_9270.bCanUsePrimaryWeapon = 1
L1_9270.bCanUseSecondaryWeapon = 0
L2_9271 = {}
L2_9271.FOVPrimary = -1
L2_9271.FOVSecondary = -1
L2_9271.sightrange = 100
L2_9271.sightrangeVehicle = -1
L2_9271.stanceScale = 1
L1_9270.Perception = L2_9271
L2_9271 = {}
L2_9271.bHostileEnable = 0
L2_9271.hostileRadius = 0
L2_9271.hostilePressureInc = 0
L2_9271.bFriendlyEnable = 0
L2_9271.friendlyRadius = 0
L2_9271.friendlyPressureDec = 0
L1_9270.AIPressureAOE = L2_9271
L0_9269.Properties = L1_9270
L1_9270 = {}
L0_9269.AI = L1_9270
L1_9270 = {}
L1_9270.walkSpeed = 5
L1_9270.runSpeed = 8
L1_9270.sprintSpeed = 10
L1_9270.maneuverSpeed = 4
L1_9270.b3DMove = 0
L1_9270.minTurnRadius = 1
L1_9270.maxTurnRadius = 30
L1_9270.maxAccel = 1000000
L1_9270.maxDecel = 1000000
L1_9270.usePathfinder = 1
L2_9271 = AIPATH_DEFAULT
L1_9270.pathType = L2_9271
L1_9270.passRadius = 3
L1_9270.pathLookAhead = 5
L1_9270.pathRadius = 2
L1_9270.maneuverTrh = 2
L1_9270.velDecay = 30
L0_9269.AIMovementAbility = L1_9270
L1_9270 = {}
L0_9269.AIFireProperties = L1_9270
L0_9269.AISoundRadius = 120
L0_9269.hidesUser = 1
L0_9269.forgetTimeTarget = 16
L0_9269.forgetTimeSeek = 20
L0_9269.forgetTimeMemory = 20
VehicleBaseAI = L0_9269
L0_9269 = VehicleBaseAI
function L1_9270(A0_9272, A1_9273)
  if not A0_9272.State then
    return
  end
  if not AI then
    return
  end
  if A1_9273 == 0 then
    AI.LogEvent(" >>>> VehicleBaseAI:AIDriver disabling " .. A0_9272:GetName())
    A0_9272:ChangeFaction()
    A0_9272:TriggerEvent(AIEVENT_DRIVER_OUT)
    A0_9272.State.aiDriver = nil
    A0_9272:EnableMountedWeapons(true)
  else
    if A0_9272.health and 0 >= A0_9272.health then
      return
    end
    AI.LogEvent(" >>>> VehicleBaseAI:AIDriver enabling " .. A0_9272:GetName())
    A0_9272:TriggerEvent(AIEVENT_DRIVER_IN)
    if A0_9272.Behavior and A0_9272.Behavior.Constructor then
      A0_9272.Behavior:Constructor(A0_9272)
    end
    A0_9272:EnableMountedWeapons(false)
    return 1
  end
end
L0_9269.AIDriver = L1_9270
L0_9269 = VehicleBaseAI
function L1_9270(A0_9274)
  if not AI then
    return
  end
  A0_9274.AI = {}
  CryAction.RegisterWithAI(A0_9274.id, A0_9274.AIType, A0_9274.Properties, A0_9274.PropertiesInstance, A0_9274.AIMovementAbility)
  AI.ChangeParameter(A0_9274.id, AIPARAM_FORGETTIME_TARGET, A0_9274.forgetTimeTarget)
  AI.ChangeParameter(A0_9274.id, AIPARAM_FORGETTIME_SEEK, A0_9274.forgetTimeSeek)
  AI.ChangeParameter(A0_9274.id, AIPARAM_FORGETTIME_MEMORY, A0_9274.forgetTimeMemory)
  if A0_9274.AICombatClass then
    AI.ChangeParameter(A0_9274.id, AIPARAM_COMBATCLASS, A0_9274.AICombatClass)
  end
  if A0_9274.Properties.Perception.config and A0_9274.Properties.Perception.config ~= "" then
    AI.RegisterTargetTrack(A0_9274.id, A0_9274.Properties.Perception.config, A0_9274.Properties.Perception.TargetTracks.targetLimit, A0_9274.Properties.Perception.TargetTracks.classThreat)
  end
  if A0_9274.Properties.bAutoGenAIHidePts and A0_9274.Properties.bAutoGenAIHidePts == 1 then
    A0_9274:SetFlags(ENTITY_FLAG_AI_HIDEABLE, 0)
  else
    A0_9274:SetFlags(ENTITY_FLAG_AI_HIDEABLE, 2)
  end
end
L0_9269.InitAI = L1_9270
L0_9269 = VehicleBaseAI
function L1_9270(A0_9275)
  if not AI then
    return
  end
  A0_9275.AI = {}
  A0_9275:AIDriver(0)
  AI.ResetParameters(A0_9275.id, false, A0_9275.Properties, A0_9275.PropertiesInstance, nil)
  if A0_9275.AICombatClass then
    AI.ChangeParameter(A0_9275.id, AIPARAM_COMBATCLASS, A0_9275.AICombatClass)
  end
  AI.ChangeParameter(A0_9275.id, AIPARAM_FORGETTIME_TARGET, A0_9275.forgetTimeTarget)
  AI.ChangeParameter(A0_9275.id, AIPARAM_FORGETTIME_SEEK, A0_9275.forgetTimeSeek)
  AI.ChangeParameter(A0_9275.id, AIPARAM_FORGETTIME_MEMORY, A0_9275.forgetTimeMemory)
  if A0_9275.Properties.bAutoGenAIHidePts and A0_9275.Properties.bAutoGenAIHidePts == 1 then
    A0_9275:SetFlags(ENTITY_FLAG_AI_HIDEABLE, 0)
  else
    A0_9275:SetFlags(ENTITY_FLAG_AI_HIDEABLE, 2)
  end
  if A0_9275.Properties.Perception.config and A0_9275.Properties.Perception.config ~= "" then
    AI.RegisterTargetTrack(A0_9275.id, A0_9275.Properties.Perception.config, A0_9275.Properties.Perception.TargetTracks.targetLimit, A0_9275.Properties.Perception.TargetTracks.classThreat)
  end
end
L0_9269.ResetAI = L1_9270
L0_9269 = VehicleBaseAI
function L1_9270(A0_9276, A1_9277)
  local L2_9278
  L2_9278 = {}
  A0_9276.AI = L2_9278
  L2_9278 = A1_9277.AI
  if L2_9278 then
    L2_9278 = A1_9277.AI
    A0_9276.AI = L2_9278
  end
  L2_9278 = A0_9276.Properties
  if L2_9278 then
    L2_9278 = A0_9276.Properties
    L2_9278 = L2_9278.aicharacter_character
    if L2_9278 then
      L2_9278 = AICharacter
      L2_9278 = L2_9278[A0_9276.Properties.aicharacter_character]
      if L2_9278 and L2_9278.OnLoad then
        L2_9278.OnLoad(A0_9276, A1_9277)
      end
    end
  end
end
L0_9269.OnLoadAI = L1_9270
L0_9269 = VehicleBaseAI
function L1_9270(A0_9279, A1_9280)
  local L2_9281
  L2_9281 = A0_9279.AI
  if L2_9281 then
    L2_9281 = A0_9279.AI
    A1_9280.AI = L2_9281
  end
  L2_9281 = A0_9279.Properties
  if L2_9281 then
    L2_9281 = A0_9279.Properties
    L2_9281 = L2_9281.aicharacter_character
    if L2_9281 then
      L2_9281 = AICharacter
      L2_9281 = L2_9281[A0_9279.Properties.aicharacter_character]
      if L2_9281 and L2_9281.OnSave then
        L2_9281.OnSave(A0_9279, A1_9280)
      end
    end
  end
end
L0_9269.OnSaveAI = L1_9270
L0_9269 = VehicleBaseAI
function L1_9270(A0_9282)
  local L1_9283
end
L0_9269.DestroyAI = L1_9270
L0_9269 = VehicleBaseAI
function L1_9270(A0_9284, A1_9285, A2_9286)
  if not AI then
    return
  end
  if A0_9284.Seats then
    for _FORV_6_, _FORV_7_ in pairs(A0_9284.Seats) do
      if _FORV_7_.passengerId then
        AI.Signal(SIGNALFILTER_SENDER, 0, A1_9285, _FORV_7_.passengerId, A2_9286)
      end
    end
  end
end
L0_9269.SignalCrew = L1_9270
function L0_9269(A0_9287)
  if A0_9287.AIProperties then
    mergef(A0_9287, A0_9287.AIProperties, 1)
  end
  A0_9287.AIProperties = nil
  mergef(A0_9287, VehicleBaseAI, 1)
end
CreateVehicleAI = L0_9269
L0_9269 = VehicleBaseAI
function L1_9270(A0_9288, A1_9289)
  if not AI then
    return
  end
  if A0_9288:IsDriver(A1_9289.id) then
    A0_9288:ChangeFaction(A1_9289, 1)
  end
  A0_9288:PrepareSeatMountedWeapon(A1_9289)
end
L0_9269.UserEntered = L1_9270
L0_9269 = VehicleBaseAI
function L1_9270(A0_9290, A1_9291)
  if not AI then
    return
  end
  AI.Signal(0, 1, "STOP_VEHICLE", A0_9290.id)
end
L0_9269.Act_Unload = L1_9270
L0_9269 = VehicleBaseAI
function L1_9270(A0_9292)
  if not AI then
    return
  end
  A0_9292:DisableAI()
  if A0_9292.AI.spawnerListenerId and System.GetEntity(A0_9292.AI.spawnerListenerId) then
    System.GetEntity(A0_9292.AI.spawnerListenerId):UnitDown()
  end
  A0_9292:TriggerEvent(AIEVENT_AGENTDIED)
  if A0_9292.AI.MaybeNextLevel then
    A0_9292:MaybeNextLevel()
  end
end
L0_9269.OnVehicleDestroyedAI = L1_9270
L0_9269 = VehicleBaseAI
function L1_9270(A0_9293)
  local L1_9294
end
L0_9269.OnVehicleImmobilized = L1_9270
L0_9269 = VehicleBaseAI
function L1_9270(A0_9295)
  A0_9295:SignalCrew("SHARED_LEAVE_ME_VEHICLE")
  if A0_9295.AIDriver then
    A0_9295:AIDriver(0)
  end
end
L0_9269.DisableAI = L1_9270
L0_9269 = VehicleBaseAI
function L1_9270(A0_9296, A1_9297)
  local L2_9298, L3_9299, L4_9300, L5_9301, L6_9302, L7_9303, L8_9304, L9_9305, L10_9306, L11_9307
  for L5_9301, L6_9302 in L2_9298(L3_9299) do
    L7_9303 = L6_9302.seat
    L7_9303 = L7_9303.GetWeaponCount
    L7_9303 = L7_9303(L8_9304)
    for L11_9307 = 1, L7_9303 do
      if L6_9302.seat:GetWeaponId(L11_9307) == A1_9297.id then
        return L5_9301
      end
    end
  end
  return L2_9298
end
L0_9269.GetSeatWithWeapon = L1_9270
L0_9269 = VehicleBaseAI
function L1_9270(A0_9308, A1_9309, A2_9310)
  local L3_9311
  L3_9311 = AI
  if not L3_9311 then
    return
  end
  if A2_9310 == 0 or A2_9310 == nil then
    L3_9311 = AI
    L3_9311 = L3_9311.ChangeParameter
    L3_9311(A0_9308.id, AIPARAM_FACTION, "")
    L3_9311 = A0_9308.AI
    L3_9311.hostileSet = nil
    return
  end
  L3_9311 = AI
  L3_9311 = L3_9311.GetFactionOf
  L3_9311 = L3_9311(A1_9309.id)
  if A0_9308.Properties.bHidesPlayer == 1 and A2_9310 == 1 and A1_9309.ai == nil and L3_9311 ~= A0_9308.defaultFaction then
    return
  end
  AI.ChangeParameter(A0_9308.id, AIPARAM_FACTION, L3_9311)
  A0_9308.AI.hostileSet = 1
end
L0_9269.ChangeFaction = L1_9270
L0_9269 = VehicleBaseAI
function L1_9270(A0_9312)
  local L1_9313, L2_9314, L3_9315, L4_9316, L5_9317, L6_9318, L7_9319, L8_9320
  L1_9313 = {}
  L2_9314 = A0_9312.class
  L1_9313.class = L2_9314
  L3_9315 = A0_9312
  L2_9314 = A0_9312.GetPos
  L2_9314 = L2_9314(L3_9315)
  L1_9313.position = L2_9314
  L3_9315 = A0_9312
  L2_9314 = A0_9312.GetDirectionVector
  L4_9316 = 1
  L2_9314 = L2_9314(L3_9315, L4_9316)
  L1_9313.orientation = L2_9314
  L3_9315 = A0_9312
  L2_9314 = A0_9312.GetScale
  L2_9314 = L2_9314(L3_9315)
  L1_9313.scale = L2_9314
  L2_9314 = A0_9312.Properties
  L1_9313.properties = L2_9314
  L2_9314 = A0_9312.PropertiesInstance
  L1_9313.propertiesInstance = L2_9314
  L2_9314 = 1
  L3_9315 = L1_9313.position
  L4_9316 = L1_9313.position
  L4_9316 = L4_9316.x
  L4_9316 = L4_9316 + L5_9317
  L4_9316 = L4_9316 - L2_9314
  L3_9315.x = L4_9316
  L3_9315 = L1_9313.position
  L4_9316 = L1_9313.position
  L4_9316 = L4_9316.y
  L4_9316 = L4_9316 + L5_9317
  L4_9316 = L4_9316 - L2_9314
  L3_9315.y = L4_9316
  L4_9316 = A0_9312
  L3_9315 = A0_9312.GetName
  L3_9315 = L3_9315(L4_9316)
  L1_9313.name = L3_9315
  L3_9315 = System
  L3_9315 = L3_9315.SpawnEntity
  L4_9316 = L1_9313
  L3_9315 = L3_9315(L4_9316)
  if L3_9315 then
    L4_9316 = L3_9315.id
    A0_9312.spawnedEntity = L4_9316
    L4_9316 = L3_9315.Events
    if not L4_9316 then
      L4_9316 = {}
      L3_9315.Events = L4_9316
    end
    L4_9316 = L3_9315.Events
    for L8_9320, _FORV_9_ in L5_9317(L6_9318) do
      if not L4_9316[L8_9320] then
        L4_9316[L8_9320] = {}
      end
      table.insert(L4_9316[L8_9320], {
        A0_9312.id,
        L8_9320
      })
    end
    L5_9317(L6_9318, L7_9319)
  end
end
L0_9269.SpawnCopyAndLoad = L1_9270
L0_9269 = VehicleBaseAI
function L1_9270(A0_9321, A1_9322)
  local L2_9323, L3_9324
  L2_9323 = AI
  if not L2_9323 then
    return
  end
  L2_9323 = 0
  L3_9324 = A0_9321.GetLink
  L3_9324 = L3_9324(A0_9321, L2_9323)
  while L3_9324 do
    if L3_9324 and L3_9324.Event_SpawnKeep then
      L3_9324:Event_SpawnKeep()
      if L3_9324.PropertiesInstance.bAutoDisable ~= 1 then
        AI.AutoDisable(System.GetEntity(L3_9324.spawnedEntity).id, 0)
      end
      System.GetEntity(L3_9324.spawnedEntity):SetName(System.GetEntity(L3_9324.spawnedEntity):GetName() .. "_vspawned")
      if System.GetEntity(L3_9324.spawnedEntity) then
        g_SignalData.fValue = L2_9323 + 1
        g_SignalData.id = A1_9322.id
        g_SignalData.iValue2 = 1
        AI.Signal(SIGNALFILTER_SENDER, 0, "ACT_ENTERVEHICLE", System.GetEntity(L3_9324.spawnedEntity).id, g_SignalData)
      end
    end
    L2_9323 = L2_9323 + 1
    L3_9324 = A0_9321:GetLink(L2_9323)
  end
end
L0_9269.LoadLinked = L1_9270
L0_9269 = VehicleBaseAI
function L1_9270(A0_9325, A1_9326)
  local L2_9327, L3_9328, L4_9329, L5_9330, L6_9331, L7_9332
  if not L2_9327 then
    return
  end
  for L5_9330, L6_9331 in L2_9327(L3_9328) do
    L7_9332 = L6_9331.GetPassengerId
    L7_9332 = L7_9332()
    if L7_9332 then
      AI.AutoDisable(L7_9332, A1_9326)
    end
  end
end
L0_9269.AutoDisablePassangers = L1_9270
L0_9269 = VehicleBaseAI
function L1_9270(A0_9333, A1_9334)
  if A0_9333.class == "Asian_helicopter" then
    for _FORV_5_, _FORV_6_ in pairs(A0_9333.Seats) do
      if _FORV_6_.passengerId and System.GetEntity(_FORV_6_.passengerId) ~= nil and _FORV_6_.isDriver and A1_9334.id == System.GetEntity(_FORV_6_.passengerId).id then
        Script.SetTimerForFunction(4000, "VehicleBaseAI.PassengerDeadExplode", A0_9333)
      end
    end
  end
end
L0_9269.OnPassengerDead = L1_9270
L0_9269 = VehicleBaseAI
function L1_9270(A0_9335)
  g_gameRules:CreateExplosion(A0_9335.id, A0_9335.id, 1000, A0_9335:GetPos(), nil, 10)
end
L0_9269.PassengerDeadExplode = L1_9270
L0_9269 = VehicleBaseAI
function L1_9270(A0_9336, A1_9337)
  local L2_9338, L3_9339, L4_9340, L5_9341, L6_9342
  if A1_9337 then
    L2_9338 = count
    L2_9338 = L2_9338(L3_9339)
    for L6_9342 = 1, L2_9338 do
      if A0_9336:GetSeatByIndex(L6_9342) and A0_9336:GetSeatByIndex(L6_9342):GetPassengerId() == A1_9337 then
        return true
      end
    end
  end
end
L0_9269.IsEntityOnVehicle = L1_9270
L0_9269 = VehicleBaseAI
function L1_9270(A0_9343)
  return A0_9343.Properties.bCanUsePrimaryWeapon
end
L0_9269.IsAllowedToUsePrimaryWeapon = L1_9270
L0_9269 = VehicleBaseAI
function L1_9270(A0_9344)
  return A0_9344.Properties.bCanUseSecondaryWeapon
end
L0_9269.IsAllowedToUseSecondaryWeapon = L1_9270
