local L0_3289, L1_3290, L2_3291, L3_3292, L4_3293
L0_3289 = {}
L1_3290 = {}
L1_3290.object_GeometryFP = "Objects/weapons/RecyclerGrenade/1P/recyclergrenade.cgf"
L1_3290.bUsable = 1
L1_3290.textDisplayName = "Explosive Grenade"
L1_3290.textDescription = "Grenades that explode."
L1_3290.fHealth = 30
L1_3290.signalGroup_Damage = "3149325216937655803"
L1_3290.signalGroup_EMP = "2524450536722832464"
L2_3291 = {}
L2_3291.sType = "rigid"
L2_3291.bPhysicalize = 1
L2_3291.bRigidBody = 1
L2_3291.bPushableByPlayers = 0
L2_3291.bPushableByAI = 0
L2_3291.bRigidBodyActive = 1
L2_3291.signalpackage_collisionDamagePackage = "3149325216948552760"
L2_3291.Density = -1
L2_3291.Mass = 25
L2_3291.Speed = 20
L3_3292 = {}
L3_3292.x = 0
L3_3292.y = 0
L3_3292.z = 0
L2_3291.vGravity = L3_3292
L2_3291.fDamping = 0.85
L1_3290.Physics = L2_3291
L1_3290.bCanTriggerAreas = 1
L2_3291 = {}
L2_3291.disruptionProfile_Profile = "10739735956140212131"
L2_3291.particleeffect_SparkVFX = ""
L2_3291.audioTrigger_SparkSFX = ""
L1_3290.Disrupt = L2_3291
L2_3291 = {}
L2_3291.fLifetime = 3.25
L2_3291.bOverrideGravity = 0
L2_3291.fTimeBeforeOwnerCollides = 0.2
L2_3291.bDestroyOnCollision = 0
L2_3291.metaTags_SneakAttackTargetTags = "9469288860498988665,9469288860498988629,9469288860517748071"
L2_3291.signalpackage_SignalPackageId = "10641886185795235783"
L2_3291.signalpackage_CriticalSignalPackageId = "10641886185835675585"
L2_3291.hitType = "ArkProjectileExplosiveGrenade"
L2_3291.bCollideWithEtherForm = false
L2_3291.fDestroyDelay = 1.5
L3_3292 = {}
L3_3292.particleeffect_ParticleEffect = "PlayerWeapons.Grenade.Explosive.Explosive_00"
L3_3292.fEffectScale = 1
L4_3293 = {}
L4_3293.x = 0
L4_3293.y = 0
L4_3293.z = 1
L3_3292.vDirection = L4_3293
L2_3291.ExplosionEffect = L3_3292
L3_3292 = {}
L3_3292.particleeffect_ArmedFriendlyEffect = "PlayerWeapons.Grenade.Generic.LightingFriendlyArmed_00"
L3_3292.particleeffect_ArmedEnemyEffect = "PlayerWeapons.Grenade.Generic.LightingArmed_00"
L3_3292.particleeffect_DetonateEffect = "PlayerWeapons.Grenade.Generic.LightingDetonation_00"
L4_3293 = {}
L4_3293.gameNoiseType_type = "9469288860501649125"
L4_3293.gameNoiseLoudness_loudness = "9469288860501649195"
L3_3292.Noise = L4_3293
L3_3292.textPromptUseMessage = "@use_pickup"
L3_3292.textPromptEquipMessage = "@use_equip"
L3_3292.fExplosionRadius = 8
L3_3292.fExplosionImpulse = 1500
L3_3292.fProximityRadius = 5
L3_3292.fProximitySpeed = 0.5
L3_3292.fProximityTime = 2
L3_3292.bImpendingDanger = 1
L3_3292.bShouldCheckLOS = 1
L3_3292.bShouldBreakGlass = 1
L3_3292.fHitNPCTime = 0.5
L3_3292.fArmingDuration = 1
L3_3292.cameraShake_CameraShake = "10739735956147043737"
L2_3291.Grenade = L3_3292
L1_3290.Projectile = L2_3291
L0_3289.Properties = L1_3290
L0_3289.displayName = ""
ArkProjectileExplosiveGrenade = L0_3289
L0_3289 = ArkProjectileExplosiveGrenade
function L1_3290(A0_3294)
  if A0_3294.Properties.bCanTriggerAreas == 1 then
    A0_3294:SetFlags(ENTITY_FLAG_TRIGGER_AREAS, 0)
  else
    A0_3294:SetFlags(ENTITY_FLAG_TRIGGER_AREAS, 2)
  end
end
L0_3289.OnInit = L1_3290
L0_3289 = ArkProjectileExplosiveGrenade
function L1_3290(A0_3295)
  local L1_3296
  L1_3296 = A0_3295.Properties
  L1_3296 = L1_3296.textDisplayName
  A0_3295.displayName = L1_3296
end
L0_3289.UpdateDisplayName = L1_3290
