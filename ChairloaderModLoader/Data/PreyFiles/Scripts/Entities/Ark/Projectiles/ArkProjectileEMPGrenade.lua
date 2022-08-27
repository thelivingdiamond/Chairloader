local L0_3276, L1_3277, L2_3278, L3_3279, L4_3280
L0_3276 = {}
L1_3277 = {}
L1_3277.object_GeometryFP = "Objects/weapons/EMPGrenade/3P/empgrenade3p_01.cgf"
L1_3277.bUsable = 1
L1_3277.textDisplayName = "@i_weaponEMPgrenade"
L1_3277.textDescription = "Grenades that EMP."
L1_3277.fHealth = 10
L1_3277.signalGroup_Damage = "3149325216937655803"
L1_3277.signalGroup_EMP = "2524450536722832464"
L1_3277.signalmodifier_InboundModifier = "3149325216965814264"
L2_3278 = {}
L2_3278.sType = "rigid"
L2_3278.bPhysicalize = 1
L2_3278.bRigidBody = 1
L2_3278.bPushableByPlayers = 0
L2_3278.bPushableByAI = 0
L2_3278.bRigidBodyActive = 1
L2_3278.signalpackage_collisionDamagePackage = "3149325216948552760"
L2_3278.Density = -1
L2_3278.Mass = 3
L2_3278.Speed = 20
L3_3279 = {}
L3_3279.x = 0
L3_3279.y = 0
L3_3279.z = 0
L2_3278.vGravity = L3_3279
L2_3278.fDamping = 0.85
L1_3277.Physics = L2_3278
L1_3277.bCanTriggerAreas = 1
L2_3278 = {}
L2_3278.disruptionProfile_Profile = "10739735956140212131"
L2_3278.particleeffect_SparkVFX = "PlayerWeapons.Grenade.Generic.EMPDisrupt_00"
L2_3278.audioTrigger_SparkSFX = ""
L1_3277.Disrupt = L2_3278
L2_3278 = {}
L2_3278.fLifetime = 1.5
L2_3278.bOverrideGravity = 0
L2_3278.fTimeBeforeOwnerCollides = 0.2
L2_3278.bDestroyOnCollision = 0
L2_3278.metaTags_SneakAttackTargetTags = "9469288860498988665,9469288860498988629,9469288860517748071"
L2_3278.signalpackage_SignalPackageId = "10641886185795235992"
L2_3278.signalpackage_CriticalSignalPackageId = "10641886185835675738"
L2_3278.hitType = "ArkProjectileEMPGrenade"
L2_3278.bCollideWithEtherForm = false
L2_3278.fDestroyDelay = 0.1
L3_3279 = {}
L3_3279.particleeffect_ParticleEffect = "PlayerWeapons.Grenade.EMP.EmpBase_00"
L3_3279.particleeffect_ParticleEffect_Cheap = "PlayerWeapons.Grenade.EMP.EmpBase_00"
L3_3279.fEffectScale = 1
L2_3278.ExplosionEffect = L3_3279
L3_3279 = {}
L4_3280 = {}
L4_3280.gameNoiseType_type = "9469288860501649125"
L4_3280.gameNoiseLoudness_loudness = "9469288860501649195"
L3_3279.Noise = L4_3280
L3_3279.particleeffect_ArmedFriendlyEffect = "PlayerWeapons.Grenade.Generic.LightingFriendlyArmed_00"
L3_3279.particleeffect_ArmedEnemyEffect = "PlayerWeapons.Grenade.Generic.LightingArmed_00"
L3_3279.particleeffect_DetonateEffect = "PlayerWeapons.Grenade.Generic.LightingDetonation_00"
L3_3279.textPromptUseMessage = "@use_pickup"
L3_3279.textPromptEquipMessage = "@use_equip"
L3_3279.fExplosionRadius = 8
L3_3279.fExplosionImpulse = 10
L3_3279.fProximityRadius = 5
L3_3279.fProximitySpeed = 0.5
L3_3279.fProximityTime = 2
L3_3279.bImpendingDanger = 1
L3_3279.bShouldCheckLOS = 0
L3_3279.fHitNPCTime = 0.25
L3_3279.fArmingDuration = 2
L3_3279.cameraShake_CameraShake = "10739735956147043737"
L2_3278.Grenade = L3_3279
L1_3277.Projectile = L2_3278
L2_3278 = {}
L2_3278.organic = 0
L2_3278.mineral = 200
L2_3278.synthetic = 250
L2_3278.exotic = 0
L1_3277.RecycleData = L2_3278
L0_3276.Properties = L1_3277
L0_3276.displayName = ""
ArkProjectileEMPGrenade = L0_3276
L0_3276 = ArkProjectileEMPGrenade
function L1_3277(A0_3281)
  if A0_3281.Properties.bCanTriggerAreas == 1 then
    A0_3281:SetFlags(ENTITY_FLAG_TRIGGER_AREAS, 0)
  else
    A0_3281:SetFlags(ENTITY_FLAG_TRIGGER_AREAS, 2)
  end
end
L0_3276.OnInit = L1_3277
L0_3276 = ArkProjectileEMPGrenade
function L1_3277(A0_3282)
  Ark.AttachInboundSignalModifier(A0_3282.id, A0_3282.Properties.signalmodifier_InboundModifier)
end
L0_3276.OnSpawn = L1_3277
L0_3276 = ArkProjectileEMPGrenade
function L1_3277(A0_3283)
  local L1_3284
  L1_3284 = A0_3283.Properties
  L1_3284 = L1_3284.textDisplayName
  A0_3283.displayName = L1_3284
end
L0_3276.UpdateDisplayName = L1_3277
