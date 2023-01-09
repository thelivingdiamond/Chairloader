local L0_3317, L1_3318, L2_3319, L3_3320, L4_3321
L0_3317 = {}
L1_3318 = {}
L1_3318.object_GeometryFP = "Objects/weapons/AlienLure/3P/alienlure3p_01.cgf"
L1_3318.bUsable = 1
L1_3318.textDisplayName = "@i_weaponluregrenade"
L1_3318.textDescription = "Grenades that lure aliens."
L1_3318.fHealth = 10
L1_3318.signalGroup_Damage = "3149325216937655803"
L1_3318.signalGroup_EMP = "2524450536722832464"
L1_3318.signalmodifier_InboundModifier = "3149325216965814264"
L2_3319 = {}
L2_3319.sType = "rigid"
L2_3319.bPhysicalize = 1
L2_3319.bRigidBody = 1
L2_3319.bPushableByPlayers = 0
L2_3319.bPushableByAI = 0
L2_3319.bRigidBodyActive = 1
L2_3319.signalpackage_collisionDamagePackage = "3149325216948552760"
L2_3319.Density = -1
L2_3319.Mass = 3
L2_3319.Speed = 20
L3_3320 = {}
L3_3320.x = 0
L3_3320.y = 0
L3_3320.z = 0
L2_3319.vGravity = L3_3320
L2_3319.fDamping = 0.85
L1_3318.Physics = L2_3319
L1_3318.bCanTriggerAreas = 1
L2_3319 = {}
L2_3319.disruptionProfile_Profile = "10739735956140212131"
L2_3319.particleeffect_SparkVFX = "PlayerWeapons.Grenade.Generic.EMPDisrupt_00"
L2_3319.audioTrigger_SparkSFX = ""
L1_3318.Disrupt = L2_3319
L2_3319 = {}
L2_3319.fLifetime = 1.5
L2_3319.bOverrideGravity = 0
L2_3319.fTimeBeforeOwnerCollides = 0.2
L2_3319.bDestroyOnCollision = 0
L2_3319.metaTags_SneakAttackTargetTags = ""
L2_3319.signalpackage_SignalPackageId = "10641886185830927780"
L2_3319.signalpackage_CriticalSignalPackageId = "10641886185830927780"
L2_3319.hitType = "ArkProjectileLureGrenade"
L2_3319.bCollideWithEtherForm = false
L2_3319.fDestroyDelay = 1
L3_3320 = {}
L3_3320.particleeffect_ParticleEffect = "PlayerWeapons.Grenade.Generic.SelfDestruct_00"
L3_3320.particleeffect_ParticleEffect_Cheap = "PlayerWeapons.Grenade.Generic.SelfDestruct_00"
L3_3320.fEffectScale = 1
L2_3319.DestroyEffect = L3_3320
L3_3320 = {}
L3_3320.particleeffect_ParticleEffect = "PlayerWeapons.Grenade.Lure.LureFlare_00"
L3_3320.particleeffect_ParticleEffect_Cheap = "PlayerWeapons.Grenade.Lure.LureFlare_00"
L3_3320.fEffectScale = 13
L2_3319.AOEEffect = L3_3320
L3_3320 = {}
L4_3321 = {}
L4_3321.gameNoiseType_type = "9469288860501649125"
L4_3321.gameNoiseLoudness_loudness = "9469288860501649195"
L3_3320.Noise = L4_3321
L3_3320.particleeffect_ArmedFriendlyEffect = "PlayerWeapons.Grenade.Generic.LightingFriendlyArmed_00"
L3_3320.particleeffect_ArmedEnemyEffect = "PlayerWeapons.Grenade.Generic.LightingArmed_00"
L3_3320.particleeffect_DetonateEffect = "PlayerWeapons.Grenade.Generic.LightingDetonation_00"
L3_3320.textPromptUseMessage = "@use_pickup"
L3_3320.textPromptEquipMessage = "@use_equip"
L3_3320.fExplosionRadius = 13
L3_3320.fExplosionImpulse = 0
L3_3320.fProximityRadius = 10
L3_3320.fProximitySpeed = 0.5
L3_3320.fProximityTime = 2
L3_3320.fPulseDuration = 8
L3_3320.fPulseFrequency = 0.1
L3_3320.bImpendingDanger = 0
L3_3320.bShouldCheckLOS = 1
L3_3320.fHitNPCTime = 0.25
L3_3320.fArmingDuration = 2
L3_3320.cameraShake_CameraShake = "10739735956147043737"
L2_3319.Grenade = L3_3320
L1_3318.Projectile = L2_3319
L2_3319 = {}
L2_3319.organic = 0
L2_3319.mineral = 150
L2_3319.synthetic = 150
L2_3319.exotic = 100
L1_3318.RecycleData = L2_3319
L0_3317.Properties = L1_3318
L0_3317.displayName = ""
ArkProjectileLureGrenade = L0_3317
L0_3317 = ArkProjectileLureGrenade
function L1_3318(A0_3322)
  if A0_3322.Properties.bCanTriggerAreas == 1 then
    A0_3322:SetFlags(ENTITY_FLAG_TRIGGER_AREAS, 0)
  else
    A0_3322:SetFlags(ENTITY_FLAG_TRIGGER_AREAS, 2)
  end
end
L0_3317.OnInit = L1_3318
L0_3317 = ArkProjectileLureGrenade
function L1_3318(A0_3323)
  Ark.AttachInboundSignalModifier(A0_3323.id, A0_3323.Properties.signalmodifier_InboundModifier)
end
L0_3317.OnSpawn = L1_3318
L0_3317 = ArkProjectileLureGrenade
function L1_3318(A0_3324)
  local L1_3325
  L1_3325 = A0_3324.Properties
  L1_3325 = L1_3325.textDisplayName
  A0_3324.displayName = L1_3325
end
L0_3317.UpdateDisplayName = L1_3318
