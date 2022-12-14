local L0_3344, L1_3345, L2_3346, L3_3347, L4_3348
L0_3344 = {}
L1_3345 = {}
L1_3345.object_GeometryFP = "Objects/weapons/RecyclerGrenade/1P/recyclergrenade.cgf"
L1_3345.bUsable = 1
L1_3345.textDisplayName = "Explosive Grenade"
L1_3345.textDescription = "Grenades that explode."
L1_3345.fHealth = 10
L1_3345.signalGroup_Damage = "3149325216937655803"
L1_3345.signalGroup_EMP = "2524450536722832464"
L2_3346 = {}
L2_3346.sType = "rigid"
L2_3346.bPhysicalize = 1
L2_3346.bRigidBody = 1
L2_3346.bPushableByPlayers = 0
L2_3346.bPushableByAI = 0
L2_3346.bRigidBodyActive = 1
L2_3346.signalpackage_collisionDamagePackage = "3149325216948552760"
L2_3346.Density = -1
L2_3346.Mass = 1
L2_3346.Speed = 14
L3_3347 = {}
L3_3347.x = 0
L3_3347.y = 0
L3_3347.z = -20
L2_3346.vGravity = L3_3347
L1_3345.Physics = L2_3346
L1_3345.bCanTriggerAreas = 1
L2_3346 = {}
L2_3346.disruptionProfile_Profile = "10739735956140212131"
L2_3346.particleeffect_SparkVFX = "PlayerWeapons.Grenade.Generic.EMPDisrupt_00"
L2_3346.audioTrigger_SparkSFX = ""
L1_3345.Disrupt = L2_3346
L2_3346 = {}
L2_3346.fLifetime = 1.35
L2_3346.bOverrideGravity = 1
L2_3346.fTimeBeforeOwnerCollides = 0.2
L2_3346.bDestroyOnCollision = 0
L2_3346.metaTags_SneakAttackTargetTags = "9469288860498988665,9469288860498988629,9469288860517748071"
L2_3346.signalpackage_SignalPackageId = "10641886185795235783"
L2_3346.signalpackage_CriticalSignalPackageId = "10641886185795235783"
L2_3346.hitType = "ArkProjectileExplosiveGrenade"
L2_3346.bCollideWithEtherForm = false
L2_3346.fDestroyDelay = 1
L3_3347 = {}
L3_3347.particleeffect_ParticleEffect = "PlayerWeapons.Grenade.Explosive.Explosion_Proxy_01"
L3_3347.fEffectScale = 1
L2_3346.ExplosionEffect = L3_3347
L3_3347 = {}
L4_3348 = {}
L4_3348.gameNoiseType_type = "9469288860501649125"
L4_3348.gameNoiseLoudness_loudness = "9469288860501649195"
L3_3347.Noise = L4_3348
L4_3348 = {}
L4_3348.particleeffect_ParticleEffect = "PlayerWeapons.Grenade.Generic.LightingFriendlyArmed_00"
L4_3348.fEffectScale = 1
L4_3348.audioTrigger_SoundStart = ""
L4_3348.audioTrigger_SoundStop = ""
L3_3347.ArmedFriendlyEffect = L4_3348
L4_3348 = {}
L4_3348.particleeffect_ParticleEffect = "PlayerWeapons.Grenade.Generic.LightingArmed_00"
L4_3348.fEffectScale = 1
L4_3348.audioTrigger_SoundStart = ""
L4_3348.audioTrigger_SoundStop = ""
L3_3347.ArmedEnemyEffect = L4_3348
L4_3348 = {}
L4_3348.particleeffect_ParticleEffect = "PlayerWeapons.Grenade.Generic.LightingDetonation_00"
L4_3348.fEffectScale = 1
L4_3348.audioTrigger_SoundStart = ""
L4_3348.audioTrigger_SoundStop = ""
L3_3347.DetonateEffect = L4_3348
L3_3347.textPromptUseMessage = "@use_pickup"
L3_3347.textPromptEquipMessage = "@use_equip"
L3_3347.fExplosionRadius = 5
L3_3347.fExplosionImpulse = 1500
L3_3347.fProximityRadius = 5
L3_3347.fProximitySpeed = 0.5
L3_3347.fProximityTime = 2
L3_3347.bImpendingDanger = 1
L3_3347.bShouldCheckLOS = 1
L3_3347.fHitNPCTime = 0
L3_3347.fArmingDuration = 1
L3_3347.bAutoDeploy = 1
L3_3347.cameraShake_CameraShake = "10739735956147043737"
L2_3346.Grenade = L3_3347
L1_3345.Projectile = L2_3346
L0_3344.Properties = L1_3345
L0_3344.displayName = ""
ArkProjectileOperatorGrenade = L0_3344
L0_3344 = ArkProjectileOperatorGrenade
function L1_3345(A0_3349)
  if A0_3349.Properties.bCanTriggerAreas == 1 then
    A0_3349:SetFlags(ENTITY_FLAG_TRIGGER_AREAS, 0)
  else
    A0_3349:SetFlags(ENTITY_FLAG_TRIGGER_AREAS, 2)
  end
end
L0_3344.OnInit = L1_3345
L0_3344 = ArkProjectileOperatorGrenade
function L1_3345(A0_3350)
  local L1_3351, L2_3352, L3_3353, L4_3354
  L1_3351 = {}
  L2_3352 = {}
  L2_3352.ActionType = "CodeDefined"
  L1_3351.Use = L2_3352
  L3_3353 = A0_3350.Properties
  L3_3353 = L3_3353.Projectile
  L3_3353 = L3_3353.Grenade
  L3_3353 = L3_3353.textPromptUseMessage
  L2_3352.DisplayText = L3_3353
  L3_3353 = {}
  L3_3353.ActionType = "CodeDefined"
  L4_3354 = A0_3350.Properties
  L4_3354 = L4_3354.Projectile
  L4_3354 = L4_3354.Grenade
  L4_3354 = L4_3354.textPromptEquipMessage
  L3_3353.DisplayText = L4_3354
  L1_3351.Special = L3_3353
  return L1_3351
end
L0_3344.GetUsable = L1_3345
L0_3344 = ArkProjectileOperatorGrenade
function L1_3345(A0_3355)
  local L1_3356
  L1_3356 = A0_3355.Properties
  L1_3356 = L1_3356.textDisplayName
  A0_3355.displayName = L1_3356
end
L0_3344.UpdateDisplayName = L1_3345
L0_3344 = ArkProjectileOperatorGrenade
function L1_3345(A0_3357)
  local L1_3358, L2_3359
  L1_3358 = {}
  L1_3358.ActionType = "CodeDefined"
  L2_3359 = A0_3357.Properties
  L2_3359 = L2_3359.Projectile
  L2_3359 = L2_3359.Grenade
  L2_3359 = L2_3359.textPromptUseMessage
  L1_3358.DisplayText = L2_3359
  L1_3358.CouldChange = false
  return L1_3358
end
L0_3344.GetRemoteManipulationInteraction = L1_3345
