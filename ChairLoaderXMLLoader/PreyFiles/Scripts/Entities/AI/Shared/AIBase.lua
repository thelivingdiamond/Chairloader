local L0_2293, L1_2294, L2_2295
L0_2293 = 0
TargetTypeNone = L0_2293
L0_2293 = 1
TargetTypeInteresting = L0_2293
L0_2293 = 2
TargetTypeThreatening = L0_2293
L0_2293 = 3
TargetTypeMemory = L0_2293
L0_2293 = 4
TargetTypeVisual = L0_2293
L0_2293 = {}
L1_2294 = {}
L2_2295 = {}
L2_2295.aiterritory_Territory = "<None>"
L2_2295.aiwave_Wave = "<None>"
L1_2294.AITerritoryAndWave = L2_2295
L2_2295 = {}
L2_2295.bHostileIfAttacked = 0
L2_2295.bGoBackToStartOnIdle = 0
L1_2294.AI = L2_2295
L0_2293.PropertiesInstance = L1_2294
L1_2294 = {}
L2_2295 = {}
L2_2295.cloakMaxDistCrouchedAndMoving = 4
L2_2295.cloakMaxDistCrouchedAndStill = 4
L2_2295.cloakMaxDistMoving = 4
L2_2295.cloakMaxDistStill = 4
L1_2294.Perception = L2_2295
L0_2293.Properties = L1_2294
L1_2294 = {}
L1_2294.ReactToSoundFromPotentialTargetTimeOut = 2
L0_2293.BehaviorProperties = L1_2294
L1_2294 = {}
L1_2294.angleThreshold = 40
L0_2293.melee = L1_2294
L1_2294 = {}
L2_2295 = AVOIDANCE_ALL
L1_2294.avoidanceAbilities = L2_2295
L1_2294.pushableObstacleWeakAvoidance = true
L1_2294.pushableObstacleAvoidanceRadiusMin = 0.4
L1_2294.pushableObstacleAvoidanceRadiusMax = 0.4
L0_2293.AIMovementAbility = L1_2294
L1_2294 = {}
function L2_2295(A0_2296)
  A0_2296:SetupTerritoryAndWave()
end
L1_2294.OnStartGame = L2_2295
function L2_2295(A0_2297, A1_2298)
  if A0_2297.PropertiesInstance.AI.bHostileIfAttacked and tonumber(A0_2297.PropertiesInstance.AI.bHostileIfAttacked) ~= 0 and A1_2298.shooterId and A1_2298.shooterId ~= g_localActorId and not AI.Hostile(A0_2297.id, A1_2298.shooterId) and (A1_2298.type ~= "collision" or A1_2298.damage > 50) then
    AI.AddPersonallyHostile(A0_2297.id, A1_2298.shooterId)
  end
  return BasicActor.Server.OnHit(A0_2297, A1_2298)
end
L1_2294.OnHit = L2_2295
L0_2293.Server = L1_2294
L1_2294 = {}
L2_2295 = {}
L2_2295.x = 0
L2_2295.y = 0
L2_2295.z = 0
L1_2294.pos = L2_2295
L1_2294.radius = 15
L0_2293.DefendPosition = L1_2294
function L1_2294(A0_2299)
  if A0_2299.AI.GoToData then
    A0_2299:Log("Suspending goto")
    A0_2299.AI.GoToData.Queued = true
    AI.SetBehaviorVariable(A0_2299.id, "GoTo", false)
  end
end
L0_2293.SuspendGoTo = L1_2294
function L1_2294(A0_2300)
  if A0_2300.AI.GoToData and A0_2300.AI.GoToData.Queued then
    A0_2300:Log("Resuming goto")
    A0_2300.AI.GoToData.Queued = nil
    AI.SetBehaviorVariable(A0_2300.id, "GoTo", true)
  end
end
L0_2293.ResumeGoTo = L1_2294
function L1_2294(A0_2301)
  A0_2301:Log("OnActionStart")
  A0_2301:SuspendGoTo(A0_2301)
end
L0_2293.OnActionStart = L1_2294
function L1_2294(A0_2302)
  A0_2302:Log("OnActionEnd")
  A0_2302:ResumeGoTo(A0_2302)
end
L0_2293.OnActionEnd = L1_2294
function L1_2294(A0_2303)
  AI.SetBehaviorTreeEvaluationEnabled(A0_2303.id, true)
end
L0_2293.EnableBehaviorTreeEvaluation = L1_2294
function L1_2294(A0_2304)
  AI.SetBehaviorTreeEvaluationEnabled(A0_2304.id, false)
end
L0_2293.DisableBehaviorTreeEvaluation = L1_2294
AIBase = L0_2293
L0_2293 = AIBase
function L1_2294(A0_2305, A1_2306)
  A0_2305:SelectPipe(0, A1_2306, 0, 0, 1)
end
L0_2293.StartOrRestartPipe = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2307)
  return A0_2307:CheckCurWeapon() == 1
end
L0_2293.IsUsingSecondaryWeapon = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2308, A1_2309, A2_2310)
  local L3_2311, L4_2312
  L3_2311 = TargetTypeNone
  L4_2312 = AITARGET_MEMORY
  if A1_2309 == L4_2312 then
    L3_2311 = TargetTypeMemory
  else
    L4_2312 = AITARGET_SOUND
    if A1_2309 == L4_2312 then
      L4_2312 = AITHREAT_INTERESTING
      if A2_2310 == L4_2312 then
        L3_2311 = TargetTypeInteresting
      else
        L4_2312 = AITHREAT_THREATENING
        if A2_2310 == L4_2312 then
          L3_2311 = TargetTypeThreatening
        end
      end
    else
      L4_2312 = AITARGET_VISUAL
      if A1_2309 == L4_2312 then
        L3_2311 = TargetTypeVisual
      end
    end
  end
  return L3_2311
end
L0_2293.GetTargetType = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2313)
  local L1_2314, L2_2315, L3_2316
  L1_2314 = AI
  L1_2314 = L1_2314.GetTargetType
  L2_2315 = A0_2313.id
  L1_2314 = L1_2314(L2_2315)
  L2_2315 = nil
  L3_2316 = TARGET_NONE
  if L1_2314 == L3_2316 then
    L3_2316 = g_Vectors
    L3_2316 = L3_2316.temp_v1
    AI.GetBeaconPosition(A0_2313.id, L3_2316)
    L2_2315 = DistanceVectors(A0_2313:GetPos(), L3_2316)
  else
    L3_2316 = AI
    L3_2316 = L3_2316.GetAttentionTargetDistance
    L3_2316 = L3_2316(A0_2313.id)
    L2_2315 = L3_2316
  end
  if L2_2315 == nil then
    L3_2316 = Log
    L3_2316("dist is nil")
  end
  return L2_2315
end
L0_2293.GetDistanceToSearchTarget = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2317)
  local L1_2318, L2_2319
  L1_2318 = AI
  L1_2318 = L1_2318.GetAttentionTargetEntity
  L2_2319 = A0_2317.id
  L1_2318 = L1_2318(L2_2319)
  L2_2319 = nil
  if L1_2318 then
    L2_2319 = AI.GetParameter(L1_2318.id, AIPARAM_CLOAKED)
  end
  return L2_2319
end
L0_2293.IsTargetCloaked = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2320, A1_2321, ...)
  if System.GetCVar("ai_DebugDraw") == 1 then
    Log("%s: %s", EntityName(A0_2320), string.format(A1_2321, ...))
  end
end
L0_2293.Log = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2323, A1_2324, ...)
  local L3_2326, L4_2327
  L3_2326 = Log
  L4_2327 = "[Warning] %s: %s"
  L3_2326(L4_2327, EntityName(A0_2323), string.format(A1_2324, ...))
end
L0_2293.Warning = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2328, A1_2329, ...)
  local L4_2331
  L4_2331 = A0_2328.traceMe
  if L4_2331 then
    L4_2331 = Log
    L4_2331("%s: %s", EntityName(A0_2328), string.format(A1_2329, ...))
  end
end
L0_2293.Trace = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2332, A1_2333, ...)
  local L3_2335, L4_2336
  L3_2335 = Log
  L4_2336 = "%s: %s"
  L3_2335(L4_2336, EntityName(A0_2332), string.format(A1_2333, ...))
end
L0_2293.LogAlways = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2337, A1_2338, ...)
  if System.GetCVar("ai_DebugVisualScriptErrors") == 1 then
    A0_2337:DrawSlot(0, 0)
    A0_2337:LoadObject(1, "objects/characters/animals/dog/dog_02.cgf")
    A0_2337:DrawSlot(1, 1)
    A0_2337:SetSlotScale(1, 4)
    if A0_2337.dogTimer then
      Script.KillTimer(A0_2337.dogTimer)
    end
    A0_2337.dogTimer = Script.SetTimerForFunction(6000, "AIBase.OnDogTimer", A0_2337)
  end
  if A1_2338 then
    Log("%s: %s", EntityName(A0_2337), string.format(A1_2338, ...))
  end
end
L0_2293.OnError = L1_2294
L0_2293 = AIBase
L1_2294 = AIBase
L1_2294 = L1_2294.OnError
L0_2293.Error = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2340)
  A0_2340:DrawSlot(1, 0)
  A0_2340:FreeSlot(1)
  A0_2340:DrawSlot(0, 1)
end
L0_2293.OnDogTimer = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2341)
  AI.Signal(SIGNALFILTER_SENDER, 1, "OnTargetLost", A0_2341.id)
end
L0_2293.TargetLost = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2342)
  local L1_2343
end
L0_2293.OnNoTarget = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2344)
  AI.Signal(SIGNALFILTER_SENDER, 1, "OnTargetNotVisible", A0_2344.id)
end
L0_2293.TargetNotVisible = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2345, A1_2346)
  local L2_2347
  L2_2347 = A0_2345.GetTargetTypeForComm
  L2_2347 = L2_2347(A0_2345, A1_2346)
  if L2_2347 ~= nil then
  end
  if A0_2345:GetGroupBlackboard()[L2_2347 .. "LastSeen"] == nil then
    return -1
  elseif A0_2345:GetGroupBlackboard()[L2_2347 .. "LastSeen"] == -1 then
    return 0
  else
    return _time - A0_2345:GetGroupBlackboard()[L2_2347 .. "LastSeen"]
  end
end
L0_2293.GetTimeSinceTargetLastSeen = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2348, A1_2349)
  local L2_2350, L3_2351
  L3_2351 = A0_2348
  L2_2350 = A0_2348.GetGroupBlackboard
  L2_2350 = L2_2350(L3_2351)
  L3_2351 = A0_2348.GetTargetTypeForComm
  L3_2351 = L3_2351(A0_2348, A1_2349)
  if L3_2351 ~= nil then
    L2_2350[L3_2351 .. "Acknowledged"] = true
  end
end
L0_2293.AcknowledgeEnemy = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2352, A1_2353)
  local L2_2354, L3_2355
  L3_2355 = A0_2352
  L2_2354 = A0_2352.GetGroupBlackboard
  L2_2354 = L2_2354(L3_2355)
  L3_2355 = A0_2352.GetTargetTypeForComm
  L3_2355 = L3_2355(A0_2352, A1_2353)
  if L3_2355 ~= nil then
    if not L2_2354[L3_2355 .. "Acknowledged"] then
      return false
    else
      return true
    end
  end
  return true
end
L0_2293.IsEnemyAcknowledged = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2356)
  local L1_2357, L2_2358, L3_2359
  L2_2358 = A0_2356
  L1_2357 = A0_2356.GetGroupBlackboard
  L1_2357 = L1_2357(L2_2358)
  L2_2358 = AI
  L2_2358 = L2_2358.GetAttentionTargetEntity
  L3_2359 = A0_2356.id
  L2_2358 = L2_2358(L3_2359)
  L3_2359 = A0_2356.ValidateAttentionTarget
  L3_2359 = L3_2359(A0_2356, L2_2358)
  if not L3_2359 then
    return
  end
  L3_2359 = A0_2356.GetTargetTypeForComm
  L3_2359 = L3_2359(A0_2356, L2_2358)
  if L3_2359 ~= nil then
    L1_2357[L3_2359 .. "LastSeen"] = -1
  end
  A0_2356.AI.lastTimeTargetWasSeen = -1
  A0_2356:ResetTargetLostTimer()
  A0_2356:SafeKillTimer(A0_2356.targetNotVisibleTimer)
end
L0_2293.OnEnemySeen = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2360, A1_2361)
  local L2_2362
  if A1_2361 then
    attTargetClassName = A1_2361.class
    if attTargetClassName == "HumanGrunt" then
      L2_2362 = "Marine"
    elseif A1_2361.actor and A1_2361.actor:IsPlayer() then
      L2_2362 = "Player"
    end
  end
  return L2_2362
end
L0_2293.GetTargetTypeForComm = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2363)
  local L1_2364, L2_2365, L3_2366
  L2_2365 = A0_2363
  L1_2364 = A0_2363.GetGroupBlackboard
  L1_2364 = L1_2364(L2_2365)
  L2_2365 = AI
  L2_2365 = L2_2365.GetAttentionTargetEntity
  L3_2366 = A0_2363.id
  L2_2365 = L2_2365(L3_2366)
  L3_2366 = A0_2363.ValidateAttentionTarget
  L3_2366 = L3_2366(A0_2363, L2_2365)
  if not L3_2366 then
    return
  end
  L3_2366 = A0_2363.GetTargetTypeForComm
  L3_2366 = L3_2366(A0_2363, L2_2365)
  if L3_2366 ~= nil then
    L1_2364[L3_2366 .. "LastSeen"] = _time
  end
  A0_2363.AI.lastTimeTargetWasSeen = _time
  A0_2363.AI.lastKnownTargetPosition = nil
  if AI.GetAttentionTargetEntity(A0_2363.id) then
    A0_2363.AI.lastKnownTargetPosition = AI.GetAttentionTargetEntity(A0_2363.id):GetWorldPos()
  end
  A0_2363:SafeKillTimer(A0_2363.targetLostTimer)
  if A0_2363.BehaviorProperties and A0_2363.BehaviorProperties.fTimeUntilSearchInCombat then
    A0_2363.targetLostTimer = Script.SetTimer(A0_2363.BehaviorProperties.fTimeUntilSearchInCombat * 1000, function()
      _UPVALUE0_:TargetLost()
    end)
  end
  A0_2363:SafeKillTimer(A0_2363.targetNotVisibleTimer)
  A0_2363.targetNotVisibleTimer = Script.SetTimer(2000, function()
    _UPVALUE0_:TargetNotVisible()
  end)
end
L0_2293.OnLostSightOfTarget = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2367)
  local L1_2368
end
L0_2293.OnGroupEnemySeen = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2369)
  local L1_2370
end
L0_2293.OnGroupUnderAttack = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2371)
  A0_2371:SafeKillTimer(A0_2371.targetLostTimer)
end
L0_2293.ResetTargetLostTimer = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2372, A1_2373, A2_2374)
end
L0_2293.OnNewAttentionTarget = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2375, A1_2376, A2_2377)
end
L0_2293.OnAttentionTargetThreatChanged = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2378, A1_2379)
  A0_2378.AI.NextGoToData = A1_2379
end
L0_2293.SetGoToData = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2380, A1_2381)
  if A0_2380.AI.GoToData then
    A0_2380.AI.GoToData.Position = A1_2381.Position
  else
    entity:LogAlways("Trying to set go data position with no current go to data")
  end
end
L0_2293.SetGoToPosition = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2382, A1_2383)
  local L2_2384, L3_2385
  L2_2384 = A0_2382.lastReactionToSoundFromPotentialTargetTime
  if L2_2384 then
    L2_2384 = A0_2382.lastReactionToSoundFromPotentialTargetTime
    L3_2385 = A0_2382.BehaviorProperties
    L3_2385 = L3_2385.ReactToSoundFromPotentialTargetTimeOut
    L2_2384 = L2_2384 + L3_2385
    L3_2385 = _time
    if L2_2384 > L3_2385 then
      L2_2384 = false
      return L2_2384
    end
  end
  if A1_2383 then
    L2_2384 = g_Vectors
    L2_2384 = L2_2384.temp_v1
    L3_2385 = SubVectors
    L3_2385(L2_2384, A1_2383, A0_2382:GetWorldPos())
    L3_2385 = dotproduct3d
    L3_2385 = L3_2385(L2_2384, A0_2382:GetDirectionVector())
    if L3_2385 > 0 then
      return false
    end
  end
  L2_2384 = _time
  A0_2382.lastReactionToSoundFromPotentialTargetTime = L2_2384
  L2_2384 = true
  return L2_2384
end
L0_2293.ShouldReactToSoundFromPotentialTarget = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2386)
  AI.SetInCover(A0_2386.id, false)
end
L0_2293.LeaveCover = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2387, A1_2388, A2_2389)
  if A1_2388 and A1_2388 ~= "" then
    A0_2387.PropertiesInstance.AITerritoryAndWave.aiterritory_Territory = A1_2388
  end
  if A2_2389 and A2_2389 ~= "" then
    A0_2387.PropertiesInstance.AITerritoryAndWave.aiwave_Wave = A2_2389
  end
  AI_Utils:SetupTerritory(A0_2387)
  AI_Utils:SetupStandby(A0_2387)
end
L0_2293.SetupTerritoryAndWave = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2390)
  A0_2390:TriggerEvent(AIEVENT_DROPBEACON)
end
L0_2293.DropBeacon = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2391, A1_2392, A2_2393, A3_2394)
  AI.Signal(SIGNALFILTER_GROUPONLY_EXCEPT, 1, A1_2392, A0_2391.id, A3_2394)
end
L0_2293.SendGroupSignal = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2395, A1_2396)
  if A1_2396 then
    if not A0_2395.assaultTarget then
      A0_2395.assaultTarget = {
        x = 0,
        y = 0,
        z = 0
      }
    end
    CopyVector(A0_2395.assaultTarget, A1_2396)
  end
end
L0_2293.AssaultTarget = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2397, A1_2398)
  if A1_2398 then
    Script.KillTimer(A1_2398)
  end
end
L0_2293.SafeKillTimer = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2399, A1_2400, A2_2401)
  if A1_2400 then
    CopyVector(A0_2399.DefendPosition.pos, A1_2400)
    if A2_2401 > 1 then
      A0_2399.DefendPosition.radius = A2_2401
    else
      A0_2399.DefendPosition.radius = 15
    end
    AI.SetBehaviorVariable(A0_2399.id, "DefendPosition", true)
  else
    Log("SetDefendTarget failed.")
  end
end
L0_2293.SetDefendPosition = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2402)
  AI.SetBehaviorVariable(A0_2402.id, "DefendPosition", false)
end
L0_2293.CancelDefendPosition = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2403, A1_2404, A2_2405, A3_2406, A4_2407)
  if A0_2403.AI.HoldGround == nil then
    A0_2403.AI.HoldGround = {
      pos = {
        x = 0,
        y = 0,
        z = 0
      },
      dir = {
        x = 0,
        y = 0,
        z = 0
      },
      radius = 5,
      skipCover = false
    }
  end
  if IsNotNullVector(A1_2404) then
    CopyVector(A0_2403.AI.HoldGround.pos, A1_2404)
  else
    Log("SetHoldGround failed.")
    return
  end
  if IsNotNullVector(A2_2405) then
    CopyVector(A0_2403.AI.HoldGround.dir, A2_2405)
  end
  A0_2403.AI.HoldGround.skipCover = A3_2406 > 0
  A0_2403.AI.HoldGround.stance = A4_2407
  A0_2403:LeaveCover()
  AI.SetBehaviorVariable(A0_2403.id, "AtHoldGroundPos", false)
  AI.SetBehaviorVariable(A0_2403.id, "HoldGround", true)
end
L0_2293.SetHoldGround = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2408)
  AI.SetBehaviorVariable(A0_2408.id, "HoldGround", false)
end
L0_2293.CancelHoldGround = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2409, A1_2410, A2_2411)
end
L0_2293.OnGroupMemberDiedWithinCommRange = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2412)
  if not AI.IsTakingCover(A0_2412.id, 7.5) and not A0_2412:IsUsingPipe("BulletReaction") then
    A0_2412:InsertSubpipe(0, "BulletReaction")
  end
end
L0_2293.PerformBulletReaction = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2413)
  local L1_2414
  L1_2414 = AI
  L1_2414 = L1_2414.GetGroupOf
  L1_2414 = L1_2414(A0_2413.id)
  AI_Utils:VerifyGroupBlackBoard(L1_2414)
  return AIBlackBoard[L1_2414]
end
L0_2293.GetGroupBlackboard = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2415)
  local L1_2416
  L1_2416 = A0_2415.AI
  L1_2416 = L1_2416.bGoBackToStartOnIdle
  L1_2416 = L1_2416 and A0_2415.lastIdlePosition
  return L1_2416
end
L0_2293.ShouldGoBackToStartOnIdle = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2417)
  local L1_2418
  L1_2418 = A0_2417.AI
  L1_2418.inCoverStartTime = _time
  L1_2418 = A0_2417.AI
  L1_2418.outOfCoverStartTime = nil
end
L0_2293.EnteredCover = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2419)
  local L1_2420
  L1_2420 = A0_2419.AI
  L1_2420.inCoverStartTime = nil
  L1_2420 = A0_2419.AI
  L1_2420.outOfCoverStartTime = _time
end
L0_2293.LeftCover = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2421)
  local L1_2422, L2_2423
  L1_2422 = A0_2421.AI
  L1_2422 = L1_2422.inCoverStartTime
  if L1_2422 == nil then
    L1_2422 = 0
    return L1_2422
  end
  L1_2422 = _time
  L2_2423 = A0_2421.AI
  L2_2423 = L2_2423.inCoverStartTime
  L1_2422 = L1_2422 - L2_2423
  return L1_2422
end
L0_2293.GetTimeInCover = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2424)
  local L1_2425, L2_2426
  L1_2425 = A0_2424.AI
  L1_2425 = L1_2425.outOfCoverStartTime
  if L1_2425 == nil then
    L1_2425 = 0
    return L1_2425
  end
  L1_2425 = _time
  L2_2426 = A0_2424.AI
  L2_2426 = L2_2426.outOfCoverStartTime
  L1_2425 = L1_2425 - L2_2426
  return L1_2425
end
L0_2293.GetTimeOutOfCover = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2427)
  return AI.GetTargetType(A0_2427.id) == AITARGET_VISUAL or AI.GetTargetType(A0_2427.id) == AITARGET_ENEMY
end
L0_2293.IsTargetVisual = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2428, A1_2429)
  if A1_2429 == nil then
    A0_2428:Log("AttentionTarget is unexpectedly invalid!")
    return false
  else
    return true
  end
end
L0_2293.ValidateAttentionTarget = L1_2294
L0_2293 = AIBase
function L1_2294(A0_2430, A1_2431, ...)
  local L3_2433, L5_2434, L6_2435, L7_2436
  L3_2433 = A0_2430.Behavior
  if L3_2433 then
    L5_2434 = L3_2433[A1_2431]
    if L5_2434 then
      L5_2434 = L3_2433[A1_2431]
      L6_2435 = L3_2433
      L7_2436 = A0_2430
      L5_2434(L6_2435, L7_2436, ...)
    end
  end
end
L0_2293.CallBehaviorFunction = L1_2294
