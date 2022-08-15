local L0_3365, L1_3366, L2_3367, L3_3368, L4_3369
L0_3365 = {}
L1_3366 = {}
L1_3366.object_GeometryFP = "Objects/weapons/RecyclerGrenade/3P/recyclergrenade3p_01.cgf"
L1_3366.bUsable = 1
L1_3366.textDisplayName = "@i_weaponrecyclegrenade"
L1_3366.textDescription = "@i_recyclegrenadeDesc"
L1_3366.fHealth = 10
L1_3366.signalGroup_Damage = "3149325216937655803"
L1_3366.signalGroup_EMP = "2524450536722832464"
L1_3366.signalmodifier_InboundModifier = "3149325216965814264"
L2_3367 = {}
L2_3367.sType = "rigid"
L2_3367.bPhysicalize = 1
L2_3367.bRigidBody = 1
L2_3367.bPushableByPlayers = 0
L2_3367.bPushableByAI = 0
L2_3367.bRigidBodyActive = 1
L2_3367.signalpackage_collisionDamagePackage = "3149325216948552760"
L2_3367.Density = -1
L2_3367.Mass = 3
L2_3367.Speed = 20
L3_3368 = {}
L3_3368.x = 0
L3_3368.y = 0
L3_3368.z = 0
L2_3367.vGravity = L3_3368
L2_3367.fDamping = 0.85
L1_3366.Physics = L2_3367
L1_3366.bCanTriggerAreas = 1
L2_3367 = {}
L2_3367.disruptionProfile_Profile = "10739735956140212131"
L2_3367.particleeffect_SparkVFX = "PlayerWeapons.Grenade.Generic.EMPDisrupt_00"
L2_3367.audioTrigger_SparkSFX = ""
L1_3366.Disrupt = L2_3367
L2_3367 = {}
L2_3367.fLifetime = 1.5
L2_3367.bOverrideGravity = 0
L2_3367.fTimeBeforeOwnerCollides = 0.2
L2_3367.bDestroyOnCollision = 0
L2_3367.metaTags_SneakAttackTargetTags = "9469288860498988665,9469288860498988629,9469288860517748071"
L2_3367.signalpackage_SignalPackageId = "10641886185818137195"
L2_3367.signalpackage_CriticalSignalPackageId = "10641886185835675803"
L2_3367.hitType = "ArkProjectileRecyclerGrenade"
L2_3367.bCollideWithEtherForm = false
L2_3367.fDestroyDelay = 2
L3_3368 = {}
L4_3369 = {}
L4_3369.gameNoiseType_type = "9469288860501649125"
L4_3369.gameNoiseLoudness_loudness = "9469288860501649195"
L3_3368.Noise = L4_3369
L3_3368.particleeffect_ArmedFriendlyEffect = "PlayerWeapons.Grenade.Recycler.Recycler_LightingFriendlyArmed"
L3_3368.particleeffect_ArmedEnemyEffect = "PlayerWeapons.Grenade.Generic.LightingArmed_00"
L3_3368.particleeffect_DetonateEffect = "PlayerWeapons.Grenade.Generic.LightingDetonation_00"
L3_3368.textPromptUseMessage = "@use_pickup"
L3_3368.textPromptEquipMessage = "@use_equip"
L3_3368.fExplosionRadius = 6
L3_3368.fExplosionImpulse = 0
L3_3368.fProximityRadius = 5
L3_3368.fProximitySpeed = 0.5
L3_3368.fProximityTime = 0.25
L3_3368.bImpendingDanger = 1
L3_3368.bShouldCheckLOS = 1
L3_3368.fHitNPCTime = 0.25
L3_3368.fArmingDuration = 2
L3_3368.cameraShake_CameraShake = "10739735956147043737"
L2_3367.Grenade = L3_3368
L3_3368 = {}
L3_3368.particleeffect_EntityGravityEffect = "PlayerWeapons.Grenade.Recycler.RefractionPull_01"
L3_3368.particleeffect_EntityGravityEffect_Cheap = "PlayerWeapons.Grenade.Recycler.RefractionPull_01"
L3_3368.particleeffect_PullEffect = "PlayerWeapons.Grenade.Recycler.Recycler_Pinch_00"
L3_3368.particleeffect_PullEffect_Cheap = "PlayerWeapons.Grenade.Recycler.Recycler_Pinch_00"
L3_3368.particleeffect_PopEffect = "PlayerWeapons.Grenade.Recycler.Recycler_Bulge_00"
L3_3368.particleeffect_PopEffect_Cheap = "PlayerWeapons.Grenade.Recycler.Recycler_Bulge_00"
L3_3368.particleeffect_FlashEffect = "PlayerWeapons.Grenade.Recycler.Recycler_Flash_00"
L3_3368.particleeffect_FlashEffect_Cheap = "PlayerWeapons.Grenade.Recycler.Recycler_Flash_00"
L3_3368.fVibrateTime = 0.35
L3_3368.fVibrationRadius = 1.75
L3_3368.fRaiseGravityZ = 0
L3_3368.fVibrationAmount = 4
L3_3368.fPullTime = 1.5
L3_3368.fGravitationalPullRadius = 10
L3_3368.fGravitationalPull = -13
L3_3368.fGravitationalPullPlayer = -26
L3_3368.fRecyclingTime = 0.65
L3_3368.fRecyclingRadius = 6
L3_3368.fRecyclingKillRadius = 1
L3_3368.fRecyclingImpulse = 0
L3_3368.fSprayImpulseDegree = 10
L4_3369 = {}
L4_3369.min = 8
L4_3369.max = 12
L3_3368.SprayImpulseRange = L4_3369
L4_3369 = {}
L4_3369.min = 0.8
L4_3369.max = 1.2
L3_3368.SprayImpulseZeroGRange = L4_3369
L4_3369 = {}
L4_3369.min = 0.75
L4_3369.max = 0.79
L3_3368.PercentRecycleRange = L4_3369
L3_3368.nMaxIngredientsPerType = 6
L3_3368.nMaxTotalIngredients = 12
L3_3368.nMaxTotalScraps = 500
L3_3368.fPercentScrapPool = 0.42
L3_3368.bHideCenterObjects = 1
L3_3368.signalpackage_RecyclePackageId = "10641886185795235880"
L3_3368.signalpackage_RecycleKillPackageId = "10641886185795235880"
L3_3368.sOverrideRecycleClasses = "OverrideRecycleClasses"
L2_3367.RecyclerGrenade = L3_3368
L1_3366.Projectile = L2_3367
L2_3367 = {}
L2_3367.organic = 0
L2_3367.mineral = 0
L2_3367.synthetic = 0
L2_3367.exotic = 0
L1_3366.RecycleData = L2_3367
L0_3365.Properties = L1_3366
L0_3365.displayName = ""
ArkProjectileRecyclerGrenade = L0_3365
L0_3365 = ArkProjectileRecyclerGrenade
function L1_3366(A0_3370)
  if A0_3370.Properties.bCanTriggerAreas == 1 then
    A0_3370:SetFlags(ENTITY_FLAG_TRIGGER_AREAS, 0)
  else
    A0_3370:SetFlags(ENTITY_FLAG_TRIGGER_AREAS, 2)
  end
end
L0_3365.OnInit = L1_3366
L0_3365 = ArkProjectileRecyclerGrenade
function L1_3366(A0_3371)
  Ark.AttachInboundSignalModifier(A0_3371.id, A0_3371.Properties.signalmodifier_InboundModifier)
end
L0_3365.OnSpawn = L1_3366
L0_3365 = ArkProjectileRecyclerGrenade
function L1_3366(A0_3372)
  local L1_3373
  L1_3373 = A0_3372.Properties
  L1_3373 = L1_3373.textDisplayName
  A0_3372.displayName = L1_3373
end
L0_3365.UpdateDisplayName = L1_3366
