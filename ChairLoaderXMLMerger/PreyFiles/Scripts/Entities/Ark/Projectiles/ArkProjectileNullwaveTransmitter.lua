local L0_3335, L1_3336, L2_3337, L3_3338, L4_3339
L0_3335 = {}
L1_3336 = {}
L1_3336.object_GeometryFP = "Objects/weapons/Nullwave_Transmitter/3P/nullwave3p_01.cgf"
L1_3336.bUsable = 1
L1_3336.textDisplayName = "@i_weaponNullwaveTransmitter"
L1_3336.textDescription = "Grenades that transmit no waves."
L1_3336.fHealth = 10
L1_3336.signalGroup_Damage = "3149325216937655803"
L1_3336.signalGroup_EMP = "2524450536722832464"
L1_3336.signalmodifier_InboundModifier = "3149325216965814264"
L2_3337 = {}
L2_3337.sType = "rigid"
L2_3337.bPhysicalize = 1
L2_3337.bRigidBody = 1
L2_3337.bPushableByPlayers = 0
L2_3337.bPushableByAI = 0
L2_3337.bRigidBodyActive = 1
L2_3337.signalpackage_collisionDamagePackage = "3149325216948552760"
L2_3337.Density = -1
L2_3337.Mass = 3
L2_3337.Speed = 20
L3_3338 = {}
L3_3338.x = 0
L3_3338.y = 0
L3_3338.z = 0
L2_3337.vGravity = L3_3338
L2_3337.fDamping = 0.85
L1_3336.Physics = L2_3337
L1_3336.bCanTriggerAreas = 1
L2_3337 = {}
L2_3337.disruptionProfile_Profile = "10739735956140212131"
L2_3337.particleeffect_SparkVFX = "PlayerWeapons.Grenade.Generic.EMPDisrupt_00"
L2_3337.audioTrigger_SparkSFX = ""
L1_3336.Disrupt = L2_3337
L2_3337 = {}
L2_3337.fLifetime = 1.5
L2_3337.bOverrideGravity = 0
L2_3337.fTimeBeforeOwnerCollides = 0.2
L2_3337.bDestroyOnCollision = 0
L2_3337.metaTags_SneakAttackTargetTags = ""
L2_3337.signalpackage_SignalPackageId = "10641886185795235359"
L2_3337.signalpackage_CriticalSignalPackageId = "10641886185795235359"
L2_3337.hitType = "ArkProjectileNullwaveTransmitter"
L2_3337.bCollideWithEtherForm = true
L2_3337.fDestroyDelay = 0.1
L3_3338 = {}
L3_3338.particleeffect_ParticleEffect = "PlayerWeapons.Grenade.NullWaveGenerator.NullWave_Explosion_00"
L3_3338.particleeffect_ParticleEffect_Cheap = "PlayerWeapons.Grenade.NullWaveGenerator.NullWave_Explosion_00"
L3_3338.fEffectScale = 15
L2_3337.ExplosionEffect = L3_3338
L3_3338 = {}
L3_3338.particleeffect_ParticleEffect = "PlayerWeapons.Grenade.Generic.SelfDestruct_00"
L3_3338.particleeffect_ParticleEffect_Cheap = "PlayerWeapons.Grenade.Generic.SelfDestruct_00"
L3_3338.fEffectScale = 1
L2_3337.DestroyEffect = L3_3338
L3_3338 = {}
L4_3339 = {}
L4_3339.gameNoiseType_type = "9469288860501649125"
L4_3339.gameNoiseLoudness_loudness = "9469288860501649195"
L3_3338.Noise = L4_3339
L3_3338.particleeffect_ArmedFriendlyEffect = "PlayerWeapons.Grenade.Generic.LightingFriendlyArmed_00"
L3_3338.particleeffect_ArmedEnemyEffect = "PlayerWeapons.Grenade.Generic.LightingArmed_00"
L3_3338.particleeffect_DetonateEffect = "PlayerWeapons.Grenade.Generic.LightingDetonation_00"
L3_3338.textPromptUseMessage = "@use_pickup"
L3_3338.textPromptEquipMessage = "@use_equip"
L3_3338.fExplosionRadius = 10
L3_3338.fExplosionImpulse = 0
L3_3338.fProximityRadius = 6
L3_3338.fProximitySpeed = 0.5
L3_3338.fProximityTime = 2
L3_3338.fPulseDuration = 0.1
L3_3338.fPulseFrequency = 0.1
L3_3338.bShouldCheckLOS = 0
L3_3338.fHitNPCTime = 0.25
L3_3338.fArmingDuration = 2
L3_3338.cameraShake_CameraShake = "10739735956147043737"
L2_3337.Grenade = L3_3338
L1_3336.Projectile = L2_3337
L2_3337 = {}
L2_3337.organic = 0
L2_3337.mineral = 100
L2_3337.synthetic = 100
L2_3337.exotic = 150
L1_3336.RecycleData = L2_3337
L0_3335.Properties = L1_3336
L0_3335.displayName = ""
ArkProjectileNullwaveTransmitter = L0_3335
L0_3335 = ArkProjectileNullwaveTransmitter
function L1_3336(A0_3340)
  if A0_3340.Properties.bCanTriggerAreas == 1 then
    A0_3340:SetFlags(ENTITY_FLAG_TRIGGER_AREAS, 0)
  else
    A0_3340:SetFlags(ENTITY_FLAG_TRIGGER_AREAS, 2)
  end
end
L0_3335.OnInit = L1_3336
L0_3335 = ArkProjectileNullwaveTransmitter
function L1_3336(A0_3341)
  Ark.AttachInboundSignalModifier(A0_3341.id, A0_3341.Properties.signalmodifier_InboundModifier)
end
L0_3335.OnSpawn = L1_3336
L0_3335 = ArkProjectileNullwaveTransmitter
function L1_3336(A0_3342)
  local L1_3343
  L1_3343 = A0_3342.Properties
  L1_3343 = L1_3343.textDisplayName
  A0_3342.displayName = L1_3343
end
L0_3335.UpdateDisplayName = L1_3336
