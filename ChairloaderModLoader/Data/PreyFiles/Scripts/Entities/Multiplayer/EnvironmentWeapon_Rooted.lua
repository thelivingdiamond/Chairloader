local L0_6346, L1_6347
L0_6346 = {}
L0_6346.None = 0
L0_6346.SelfNotAffected = 1
L0_6346.TeamNotAffected = 2
FriendlyFire = L0_6346
L0_6346 = {}
L0_6346.unspecified = 0
L0_6346.panel = 1
L0_6346.pole = 2
L0_6346.other = 3
Classifications = L0_6346
L0_6346 = {}
L1_6347 = {}
L0_6346.Server = L1_6347
L1_6347 = {}
L0_6346.Client = L1_6347
L1_6347 = {}
L1_6347.szUseMessage = "@pick_object"
L1_6347.szMFXLibrary = "melee"
L1_6347.fileModelOverride = ""
L1_6347.bPickable = 1
L1_6347.szRootedGrabAnimTagOverride = ""
L1_6347.szGrabAnimTagOverride = ""
L1_6347.bInitiallyRooted = 1
L1_6347.RagdollPostMeleeImpactSpeed = 20
L1_6347.RagdollPostThrowImpactSpeed = 17
L1_6347.classification = ""
L1_6347.RootedAngleMin = 0
L1_6347.RootedAngleMax = 180
L1_6347.initialHealth = 800
L1_6347.damageable = 0
L1_6347.idleKillTime = -1
L1_6347.States = {}
L1_6347.shieldsFromExplosionConeAngle = 0
L1_6347.collisionDamageScale = 0.5
L1_6347.explosionMinDamageToDestroy = 100
L0_6346.Properties = L1_6347
L1_6347 = {}
L1_6347.Icon = "Item.bmp"
L1_6347.IconOnTop = 1
L1_6347.ShowBounds = 1
L0_6346.Editor = L1_6347
L0_6346.ModelSlot = -1
L0_6346.currentHealth = 800
L1_6347 = NULL_ENTITY
L0_6346.ownerID = L1_6347
L0_6346.lowestThresholdFractionReached = 1.1
L0_6346.IsRooted = true
L0_6346.bCurrentlyPickable = 0
L0_6346.teamID = -1
EnvironmentalWeapon = L0_6346
L0_6346 = EnvironmentalWeapon
L1_6347 = {}
L1_6347.flags = 0
L1_6347.mass = 250
L0_6346.physParams = L1_6347
L0_6346 = EnvironmentalWeapon
L0_6346.DEFAULT_FILE_MODEL = "Objects/props/c3mp_strfrn/c3mp_lamp_post/c3mp_sign_post.cgf"
L0_6346 = EnvironmentalWeapon
function L1_6347(A0_6348, A1_6349)
  local L2_6350
  L2_6350 = A0_6348.Properties
  L2_6350 = L2_6350.bPickable
  L2_6350 = L2_6350 and A0_6348.bCurrentlyPickable
  return L2_6350
end
L0_6346.IsUsable = L1_6347
L0_6346 = EnvironmentalWeapon
function L1_6347(A0_6351)
  A0_6351:Physicalize(A0_6351.ModelSlot, PE_RIGID, A0_6351.physParams)
  A0_6351.IsRooted = false
end
L0_6346.OnAttached = L1_6347
L0_6346 = EnvironmentalWeapon
function L1_6347(A0_6352)
  return A0_6352.Properties.szUseMessage
end
L0_6346.GetUsableMessage = L1_6347
L0_6346 = EnvironmentalWeapon
L0_6346 = L0_6346.Server
function L1_6347(A0_6353)
  if not A0_6353.bInitialized then
    A0_6353:OnReset()
    A0_6353.bInitialized = 1
    A0_6353:SetViewDistRatio(255)
  end
end
L0_6346.OnInit = L1_6347
L0_6346 = EnvironmentalWeapon
function L1_6347(A0_6354, A1_6355)
  A0_6354.ownerID = A1_6355
  if A1_6355 == NULL_ENTITY then
    if A0_6354.originalViewDistRatio ~= nil then
      A0_6354:SetViewDistRatio(A0_6354.originalViewDistRatio)
    end
    A0_6354.teamID = -1
  else
    A0_6354.originalViewDistRatio = A0_6354:GetViewDistRatio()
    A0_6354:SetViewDistRatio(255)
    if g_gameRules.game:IsMultiplayer() then
      A0_6354.teamID = g_gameRules.game:GetTeam(A1_6355)
    end
  end
end
L0_6346.SetOwnerID = L1_6347
L0_6346 = EnvironmentalWeapon
L0_6346 = L0_6346.Client
function L1_6347(A0_6356)
  if not A0_6356.bInitialized then
    A0_6356:OnReset()
    A0_6356.bInitialized = 1
  end
end
L0_6346.OnInit = L1_6347
L0_6346 = EnvironmentalWeapon
function L1_6347(A0_6357)
  local L1_6358, L2_6359, L3_6360, L4_6361, L5_6362, L6_6363, L7_6364
  L1_6358 = A0_6357.ModelSlot
  L1_6358 = L1_6358 == -1
  if L1_6358 then
    A0_6357.ModelSlot = -1
    L2_6359 = A0_6357.DEFAULT_FILE_MODEL
    if L3_6360 then
      if L3_6360 ~= "" then
        L2_6359 = L3_6360.fileModelOverride
      end
    end
    L6_6363 = L2_6359
    A0_6357.ModelSlot = L3_6360
    if L3_6360 ~= nil then
      for L6_6363, L7_6364 in L3_6360(L4_6361) do
        if L7_6364 ~= nil and type(L7_6364) == "table" and L7_6364.Model ~= nil then
          L7_6364.Slot = A0_6357:LoadObject(-1, L7_6364.Model)
          if L7_6364 ~= -1 then
            A0_6357:DrawSlot(L7_6364.Slot, 0)
          end
        end
      end
    end
  end
  L2_6359 = A0_6357.Properties
  L2_6359 = L2_6359.initialHealth
  A0_6357.currentHealth = L2_6359
  L2_6359 = NULL_ENTITY
  A0_6357.ownerID = L2_6359
  A0_6357.lowestThresholdFractionReached = 1.1
  L2_6359 = A0_6357.Properties
  L2_6359 = L2_6359.bInitiallyRooted
  A0_6357.IsRooted = L2_6359
  L2_6359 = A0_6357.IsRooted
  if L2_6359 then
    L2_6359 = A0_6357.Physicalize
    L6_6363 = {}
    L6_6363.mass = 0
    L2_6359(L3_6360, L4_6361, L5_6362, L6_6363)
  else
    L2_6359 = A0_6357.Physicalize
    L6_6363 = A0_6357.physParams
    L2_6359(L3_6360, L4_6361, L5_6362, L6_6363)
  end
  L2_6359 = A0_6357.Properties
  L2_6359 = L2_6359.bPickable
  A0_6357.bCurrentlyPickable = L2_6359
end
L0_6346.OnReset = L1_6347
L0_6346 = EnvironmentalWeapon
function L1_6347(A0_6365)
  A0_6365:OnReset()
end
L0_6346.OnPropertyChange = L1_6347
L0_6346 = EnvironmentalWeapon
function L1_6347(A0_6366)
  A0_6366:OnReset()
end
L0_6346.OnSpawn = L1_6347
L0_6346 = EnvironmentalWeapon
L0_6346 = L0_6346.Server
function L1_6347(A0_6367, A1_6368)
  local L2_6369, L3_6370
  L2_6369 = A0_6367.Properties
  L2_6369 = L2_6369.damageable
  if L2_6369 ~= 0 then
    L2_6369 = A0_6367.IsRooted
    if L2_6369 == false then
      L2_6369 = A0_6367.ownerID
      L3_6370 = NULL_ENTITY
      if L2_6369 ~= L3_6370 then
        L2_6369 = g_gameRules
        L2_6369 = L2_6369.game
        L3_6370 = L2_6369
        L2_6369 = L2_6369.IsMultiplayer
        L2_6369 = L2_6369(L3_6370)
        if L2_6369 then
          L2_6369 = g_gameRules
          L2_6369 = L2_6369.game
          L3_6370 = L2_6369
          L2_6369 = L2_6369.GetTeam
          L2_6369 = L2_6369(L3_6370, A1_6368.shooterId)
          L3_6370 = A0_6367.teamID
        elseif L2_6369 ~= L3_6370 then
          L2_6369 = A1_6368.damage
          L3_6370 = A1_6368.type
          if L3_6370 == "collision" then
            L3_6370 = A0_6367.Properties
            L3_6370 = L3_6370.collisionDamageScale
            L2_6369 = L2_6369 * L3_6370
          else
            L3_6370 = A1_6368.damage
            if L3_6370 >= A0_6367.Properties.explosionMinDamageToDestroy then
              L3_6370 = A1_6368.type
              if L3_6370 == "frag" then
                L2_6369 = A0_6367.currentHealth
              end
            end
          end
          L3_6370 = A0_6367.currentHealth
          A0_6367.currentHealth = A0_6367.currentHealth - L2_6369
          Game.OnEnvironmentalWeaponHealthChanged(A0_6367.id, L3_6370, A0_6367.currentHealth)
          A0_6367:OnClientHealthChanged()
        end
      end
    end
  end
  L2_6369 = false
  return L2_6369
end
L0_6346.OnHit = L1_6347
L0_6346 = EnvironmentalWeapon
function L1_6347(A0_6371)
  A0_6371:UpdateHealthState()
end
L0_6346.OnClientHealthChanged = L1_6347
L0_6346 = EnvironmentalWeapon
function L1_6347(A0_6372)
  local L1_6373, L2_6374, L3_6375, L4_6376, L5_6377, L6_6378, L7_6379, L8_6380, L9_6381
  L2_6374 = A0_6372.lowestThresholdFractionReached
  L3_6375 = nil
  L4_6376 = A0_6372.Properties
  L4_6376 = L4_6376.initialHealth
  if L4_6376 == nil then
    return
  end
  L4_6376 = A0_6372.currentHealth
  L4_6376 = L4_6376 / L5_6377
  if L5_6377 ~= nil then
    for L8_6380, L9_6381 in L5_6377(L6_6378) do
      if L9_6381 ~= nil and type(L9_6381) == "table" and L9_6381.ThresholdFraction ~= nil and L9_6381.Model ~= nil and L4_6376 <= L9_6381.ThresholdFraction and L2_6374 >= L9_6381.ThresholdFraction then
        L1_6373 = L9_6381.Model
        L2_6374 = L9_6381.ThresholdFraction
        L3_6375 = L9_6381.Slot
      end
    end
    if L5_6377 ~= L2_6374 then
      L8_6380 = A0_6372
      L9_6381 = -1
      L7_6379(L8_6380, L9_6381, 0)
      L8_6380 = A0_6372
      L9_6381 = L3_6375
      L7_6379(L8_6380, L9_6381, 1)
      L8_6380 = A0_6372
      L9_6381 = L3_6375
      L7_6379(L8_6380, L9_6381, PE_RIGID, A0_6372.physParams)
      A0_6372.ModelSlot = L3_6375
      L8_6380 = A0_6372
      L9_6381 = L5_6377
      L7_6379(L8_6380, L9_6381, L6_6378)
      A0_6372.lowestThresholdFractionReached = L2_6374
      L8_6380 = NULL_ENTITY
      if L7_6379 ~= L8_6380 then
        L8_6380 = A0_6372.ownerID
        if L7_6379 then
          L8_6380 = L7_6379.actor
          L9_6381 = L8_6380
          L8_6380 = L8_6380.RefreshPickAndThrowObjectPhysics
          L8_6380(L9_6381)
        end
      end
    end
  end
end
L0_6346.UpdateHealthState = L1_6347
L0_6346 = EnvironmentalWeapon
function L1_6347(A0_6382)
  local L1_6383, L2_6384
  L1_6383 = 0
  id = L1_6383
  L1_6383 = Classifications
  L2_6384 = A0_6382.Properties
  L2_6384 = L2_6384.classification
  L1_6383 = L1_6383[L2_6384]
  id = L1_6383
  L1_6383 = A0_6382.Properties
  L1_6383 = L1_6383.classification
  if L1_6383 == "" then
    L1_6383 = Classifications
    L1_6383 = L1_6383.Unspecified
    id = L1_6383
  else
    L1_6383 = id
    if L1_6383 == nil then
      L1_6383 = Classifications
      L1_6383 = L1_6383.Other
      id = L1_6383
    end
  end
  L1_6383 = id
  return L1_6383
end
L0_6346.GetClassification = L1_6347
