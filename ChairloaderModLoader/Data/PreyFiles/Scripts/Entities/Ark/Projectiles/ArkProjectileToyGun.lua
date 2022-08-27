local L0_3388, L1_3389, L2_3390, L3_3391
L0_3388 = {}
L1_3389 = {}
L1_3389.object_GeometryFP = "objects/weapons/toygun/toygun_projectile_00.cgf"
L1_3389.bCanTriggerAreas = 1
L1_3389.bCapacitive = 1
L1_3389.bInteractiveCollision = 1
L1_3389.textDisplayName = "@i_ammotoygunprojectile"
L1_3389.archetype_PickupToCollect = "ArkPickups.Ammo.ToyGunDarts"
L1_3389.nPickupCount = 1
L2_3390 = {}
L2_3390.signal_DetonationSignal = ""
L2_3390.signalpackage_Explosion = ""
L2_3390.particleeffect_ExplosionVFX = ""
L2_3390.fMinExplosionRadius = 0.25
L2_3390.fMaxExplosionRadius = 2
L2_3390.fParticleEffectScale = 1
L2_3390.fExplosionImpulse = 1
L1_3389.ExplosiveDart = L2_3390
L2_3390 = {}
L2_3390.sType = "rigid"
L2_3390.bPhysicalize = 1
L2_3390.bRigidBody = 1
L2_3390.bPushableByPlayers = 0
L2_3390.bPushableByAI = 0
L2_3390.bRigidBodyActive = 1
L2_3390.signalpackage_collisionDamagePackage = "3149325216948552760"
L2_3390.Density = -1
L2_3390.Mass = 0.05
L2_3390.Speed = 50
L2_3390.SpeedFromCamera = 10
L3_3391 = {}
L3_3391.x = 0
L3_3391.y = 0
L3_3391.z = -13
L2_3390.vGravity = L3_3391
L1_3389.Physics = L2_3390
L2_3390 = {}
L2_3390.bOverrideGravity = 0
L2_3390.fLifetime = 600
L2_3390.fTimeBeforeOwnerCollides = 0.2
L2_3390.bDestroyOnCollision = 0
L2_3390.bAlignWithVelocity = 1
L2_3390.metaTags_SneakAttackTargetTags = "9469288860498988665,9469288860498988629,9469288860517748071"
L2_3390.textPromptUseMessage = "@use_pickup"
L2_3390.signalpackage_SignalPackageId = "3149325216950003142"
L2_3390.signalpackage_CriticalSignalPackageId = "3149325216966269047"
L2_3390.hitType = "ArkProjectileToyGun"
L2_3390.bCollideWithEtherForm = false
L2_3390.fDestroyDelay = 0.5
L1_3389.Projectile = L2_3390
L0_3388.Properties = L1_3389
ArkProjectileToyGun = L0_3388
L0_3388 = ArkProjectileToyGun
function L1_3389(A0_3392)
  if A0_3392.Properties.bCanTriggerAreas == 1 then
    A0_3392:SetFlags(ENTITY_FLAG_TRIGGER_AREAS, 0)
  else
    A0_3392:SetFlags(ENTITY_FLAG_TRIGGER_AREAS, 2)
  end
  if A0_3392.Properties.ExplosiveDart.signal_DetonationSignal ~= "" then
    Ark.RegisterForSignal(A0_3392.id, A0_3392.Properties.ExplosiveDart.signal_DetonationSignal)
  end
end
L0_3388.OnInit = L1_3389
L0_3388 = ArkProjectileToyGun
function L1_3389(A0_3393)
  A0_3393.m_bIsUsable = false
  A0_3393.m_bIsExplosionPending = false
  A0_3393:SetDisplayName("")
end
L0_3388.OnReInitFromPool = L1_3389
L0_3388 = ArkProjectileToyGun
function L1_3389(A0_3394)
  local L1_3395, L2_3396, L3_3397
  L1_3395 = A0_3394.m_bIsExplosionPending
  if not L1_3395 then
    L1_3395 = A0_3394.m_bIsUsable
    if L1_3395 then
      L1_3395 = {}
      L2_3396 = {}
      L2_3396.ActionType = "ScriptDefined"
      L1_3395.Use = L2_3396
      L3_3397 = A0_3394.Properties
      L3_3397 = L3_3397.Projectile
      L3_3397 = L3_3397.textPromptUseMessage
      L2_3396.DisplayText = L3_3397
      return L1_3395
    end
  end
end
L0_3388.GetUsable = L1_3389
L0_3388 = ArkProjectileToyGun
function L1_3389(A0_3398)
  local L1_3399, L2_3400
  L1_3399 = A0_3398.m_bIsExplosionPending
  if not L1_3399 then
    L1_3399 = A0_3398.m_bIsUsable
    if L1_3399 then
      L1_3399 = {}
      L1_3399.ActionType = "ScriptDefined"
      L2_3400 = A0_3398.Properties
      L2_3400 = L2_3400.Projectile
      L2_3400 = L2_3400.textPromptUseMessage
      L1_3399.DisplayText = L2_3400
      return L1_3399
    end
  end
end
L0_3388.GetRemoteManipulationInteraction = L1_3389
L0_3388 = ArkProjectileToyGun
function L1_3389(A0_3401)
  local L1_3402
  L1_3402 = A0_3401.m_bIsExplosionPending
  if not L1_3402 then
    L1_3402 = A0_3401.Properties
    ItemSystem.GiveItem(L1_3402.archetype_PickupToCollect, g_localActor:GetRawId(), L1_3402.nPickupCount)
    Game.ReturnToProjectilePool(A0_3401.id)
  end
end
L0_3388.Interact = L1_3389
L0_3388 = ArkProjectileToyGun
function L1_3389(A0_3403)
  if not A0_3403.m_bIsExplosionPending then
    if not A0_3403.m_bIsUsable then
      A0_3403:SetDisplayName(A0_3403.Properties.textDisplayName)
    end
    A0_3403.m_bIsUsable = true
  end
end
L0_3388.OnCollision = L1_3389
L0_3388 = ArkProjectileToyGun
function L1_3389(A0_3404, A1_3405)
  local L2_3406
  L2_3406 = A0_3404.m_bIsUsable
  A1_3405.m_bIsUsable = L2_3406
  L2_3406 = A0_3404.m_bIsExplosionPending
  A1_3405.m_bIsExplosionPending = L2_3406
end
L0_3388.OnSave = L1_3389
L0_3388 = ArkProjectileToyGun
function L1_3389(A0_3407, A1_3408)
  local L2_3409
  L2_3409 = A1_3408.m_bIsUsable
  A0_3407.m_bIsUsable = L2_3409
  L2_3409 = A1_3408.m_bIsExplosionPending
  A0_3407.m_bIsExplosionPending = L2_3409
end
L0_3388.OnLoad = L1_3389
L0_3388 = ArkProjectileToyGun
function L1_3389(A0_3410)
  local L1_3411
  L1_3411 = A0_3410.Properties
  L1_3411 = L1_3411.ExplosiveDart
  g_Vectors.temp_v1 = A0_3410:GetWorldPos()
  Particle.SpawnEffect(L1_3411.particleeffect_ExplosionVFX, g_Vectors.temp_v1, g_Vectors.v000, L1_3411.fParticleEffectScale)
  Ark.SendSignalPackageInAOE(A0_3410.id, g_localActor.id, L1_3411.signalpackage_Explosion, g_Vectors.temp_v1, L1_3411.fMinExplosionRadius, L1_3411.fMaxExplosionRadius, false, L1_3411.fExplosionImpulse)
  A0_3410.m_bIsExplosionPending = false
  Game.ReturnToProjectilePool(A0_3410.id)
end
L0_3388.Explode = L1_3389
L0_3388 = ArkProjectileToyGun
function L1_3389(A0_3412)
  A0_3412:Interact()
end
L0_3388.OnUsed = L1_3389
L0_3388 = ArkProjectileToyGun
function L1_3389(A0_3413)
  A0_3413:Interact()
end
L0_3388.OnRemoteManipulation = L1_3389
