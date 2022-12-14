Script.ReloadScript("Scripts/Entities/AI/AITerritory.lua")
AI_Utils = {}
function AI_Utils.VerifyGroupBlackBoard(A0_295, A1_296)
  local L2_297
  L2_297 = AIBlackBoard
  L2_297 = L2_297[A1_296]
  if not L2_297 then
    L2_297 = AIBlackBoard
    L2_297[A1_296] = {}
  end
end
function AI_Utils.SetupTerritory(A0_298, A1_299)
  local L2_300
  L2_300 = A1_299.PropertiesInstance
  L2_300 = L2_300.AITerritoryAndWave
  L2_300 = L2_300.aiterritory_Territory
  if L2_300 == "<None>" then
    AI.SetTerritoryShapeName(A1_299.id, "<None>")
    A1_299.AI.TerritoryShape = nil
    A1_299.AI.Wave = nil
    return
  end
  if not L2_300 or L2_300 == "" or L2_300 == "<Auto>" then
    L2_300 = AI.GetEnclosingGenericShapeOfType(A1_299:GetPos(), AIAnchorTable.COMBAT_TERRITORY, 1)
  end
  if L2_300 and L2_300 ~= "" then
    AI.SetTerritoryShapeName(A1_299.id, L2_300)
  else
    AI.SetTerritoryShapeName(A1_299.id, "<None>")
    A1_299.AI.TerritoryShape = nil
    A1_299.AI.Wave = nil
    return
  end
  A1_299.AI.TerritoryShape = L2_300
  A1_299.AI.Wave = nil
  AddToTerritoryAndWave(A1_299)
end
function AI_Utils.SetupStandby(A0_301, A1_302, A2_303)
  A1_302.AI.StandbyShape = AI.GetEnclosingGenericShapeOfType(A1_302:GetPos(), AIAnchorTable.ALERT_STANDBY_IN_RANGE, 0)
  if A2_303 and A2_303 == true and not A1_302.AI.StandbyShape then
    A1_302.AI.StandbyShape = AI.CreateTempGenericShapeBox(A1_302:GetPos(), 15, 0, AIAnchorTable.ALERT_STANDBY_IN_RANGE)
  end
  if A1_302.AI.StandbyShape then
    AI.SetRefShapeName(A1_302.id, A1_302.AI.StandbyShape)
  else
    AI.SetRefShapeName(A1_302.id, "")
  end
end
function AI_Utils.CanThrowGrenade(A0_304, A1_305, A2_306)
  local L3_307, L4_308
  L3_307 = AIBlackBoard
  L3_307 = L3_307.lastGrenadeTime
  if not L3_307 then
    L3_307 = AIBlackBoard
    L4_308 = _time
    L4_308 = L4_308 - 20
    L3_307.lastGrenadeTime = L4_308
  end
  L3_307 = _time
  L4_308 = AIBlackBoard
  L4_308 = L4_308.lastGrenadeTime
  L3_307 = L3_307 - L4_308
  if L3_307 < 9 then
    L4_308 = 0
    return L4_308
  end
  if A2_306 == nil then
    L4_308 = AI
    L4_308 = L4_308.GetTargetType
    L4_308 = L4_308(A1_305.id)
    if L4_308 ~= AITARGET_MEMORY and L4_308 ~= AITARGET_ENEMY then
      return 0
    end
    if AI.GetAttentionTargetDistance(A1_305.id) < 10 or AI.GetAttentionTargetDistance(A1_305.id) > 45 then
      return 0
    end
  end
  L4_308 = A1_305.inventory
  L4_308 = L4_308.GetGrenadeWeaponByClass
  L4_308 = L4_308(L4_308, "AIGrenades")
  if A2_306 then
    L4_308 = A1_305.inventory:GetGrenadeWeaponByClass("AISmokeGrenades")
    if L4_308 == nil then
      return 0
    end
  elseif L4_308 == nil then
    L4_308 = A1_305.inventory:GetGrenadeWeaponByClass("AIFlashbangs")
    if L4_308 == nil then
      return 0
    end
  end
  if System.GetEntity(L4_308) == nil then
    return 0
  end
  if 0 >= System.GetEntity(L4_308).weapon:GetAmmoCount() then
    return 0
  end
  AIBlackBoard.lastGrenadeTime = _time
  return 1
end
function AI_Utils.CanThrowSmokeGrenade(A0_309, A1_310)
  local L2_311, L3_312, L4_313, L5_314
  L2_311 = AIBlackBoard
  L2_311 = L2_311.lastSmokeGrenadeTime
  if not L2_311 then
    L2_311 = AIBlackBoard
    L3_312 = _time
    L3_312 = L3_312 - 40
    L2_311.lastSmokeGrenadeTime = L3_312
  end
  L2_311 = _time
  L3_312 = AIBlackBoard
  L3_312 = L3_312.lastSmokeGrenadeTime
  L2_311 = L2_311 - L3_312
  if L2_311 < 30 then
    L3_312 = 0
    return L3_312
  end
  L3_312 = AI
  L3_312 = L3_312.GetTargetType
  L4_313 = A1_310.id
  L3_312 = L3_312(L4_313)
  L4_313 = AITARGET_MEMORY
  if L3_312 ~= L4_313 then
    L4_313 = AITARGET_ENEMY
    if L3_312 ~= L4_313 then
      L4_313 = 0
      return L4_313
    end
  end
  L4_313 = AI
  L4_313 = L4_313.GetAttentionTargetDistance
  L5_314 = A1_310.id
  L4_313 = L4_313(L5_314)
  if L4_313 < 20 or L4_313 > 60 then
    L5_314 = 0
    return L5_314
  end
  L5_314 = A1_310.inventory
  L5_314 = L5_314.GetGrenadeWeaponByClass
  L5_314 = L5_314(L5_314, "AISmokeGrenades")
  if L5_314 == nil then
    return 0
  end
  if System.GetEntity(L5_314) == nil then
    return 0
  end
  if 0 >= System.GetEntity(L5_314).weapon:GetAmmoCount() then
    return 0
  end
  AIBlackBoard.lastSmokeGrenadeTime = _time
  return 1
end
function AI_Utils.HasPlayerAsAttentionTarget(A0_315, A1_316)
  if AI.GetAttentionTargetAIType(A1_316) == AIOBJECT_PLAYER then
    return true
  end
  return false
end
function AI_Utils.AttentionTargetIsPlayerOrAssociatedWithPlayer(A0_317, A1_318)
  if AI.GetAttentionTargetAIType(A1_318) == AIOBJECT_PLAYER then
    return true
  elseif AI.GetAttentionTargetAIType(A1_318) == AIOBJECT_DUMMY and AI.GetAttentionTargetEntity(A1_318) ~= nil and AI.GetTypeOf(AI.GetAttentionTargetEntity(A1_318).id) == AIOBJECT_PLAYER then
    return true
  end
  return false
end
function AI_Utils.AttentionTargetIsTurretOrAssociatedWithTurret(A0_319, A1_320)
  if (AI.GetAttentionTargetAIType(A1_320) == AIOBJECT_TARGET or AI.GetAttentionTargetAIType(A1_320) == AIOBJECT_DUMMY) and AI.GetAttentionTargetEntity(A1_320) ~= nil and System.GetEntityClass(AI.GetAttentionTargetEntity(A1_320).id) == "Turret" then
    return true
  end
  return false
end
function GetTargetElevationAngleInDegrees(A0_321)
  local L1_322, L2_323, L3_324, L4_325
  if A0_321 == nil then
    L1_322 = 0
    return L1_322
  end
  L1_322 = g_Vectors
  L1_322 = L1_322.temp_v1
  L2_323 = AI
  L2_323 = L2_323.GetAttentionTargetPosition
  L3_324 = A0_321.id
  L4_325 = L1_322
  L2_323 = L2_323(L3_324, L4_325)
  if not L2_323 then
    L2_323 = 0
    return L2_323
  end
  L3_324 = A0_321
  L2_323 = A0_321.GetWorldPos
  L4_325 = g_Vectors
  L4_325 = L4_325.temp_v2
  L2_323 = L2_323(L3_324, L4_325)
  L3_324 = GetDirection
  L4_325 = L2_323
  L3_324 = L3_324(L4_325, L1_322)
  L4_325 = GetAngleBetweenVectors
  L4_325 = L4_325(g_Vectors.down, L3_324)
  return math.deg(L4_325) - 90
end
function SetTimerForBehaviorFunction(A0_326, A1_327, A2_328, A3_329, A4_330)
  local L5_331
  L5_331 = {}
  L5_331.behavior = A2_328
  L5_331.entity = A3_329
  L5_331.extraData = A4_330
  if A3_329.AI.behaviorFuntions == nil then
    A3_329.AI.behaviorFuntions = {}
  end
  A3_329.AI.behaviorFuntions[Script.SetTimerForFunction(A0_326, "OnBehaviorFunctionTimerDone", L5_331)] = A1_327
  return (Script.SetTimerForFunction(A0_326, "OnBehaviorFunctionTimerDone", L5_331))
end
function OnBehaviorFunctionTimerDone(A0_332, A1_333)
  A0_332.entity.AI.behaviorFuntions[A1_333](A0_332.behavior, A0_332.entity, A0_332.extraData)
  A0_332.entity.AI.behaviorFuntions[A1_333] = nil
end
function SafeKillBehaviorTimer(A0_334, A1_335)
  if A1_335 and A0_334.AI.behaviorFuntions and A0_334.AI.behaviorFuntions[A1_335] then
    A0_334.AI.behaviorFuntions[A1_335] = nil
    Script.KillTimer(A1_335)
  end
end
