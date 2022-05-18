local L0_3424, L1_3425, L2_3426
L0_3424 = {}
L1_3425 = {}
L1_3425.model = "Objects/characters/Aliens/AlienCorpses/AlienCorpsePieces_Small.cgf"
L1_3425.particleAttachment = "lower_jiggle"
L1_3425.particleeffect_particleEffect = "Characters.Aliens.Shared.Death.AlienGib_Trail_01"
L1_3425.bUsable = 0
L1_3425.fInteractDelay = 1
L1_3425.staticSpawnDownTraceDistance = 25
L1_3425.staticSpawnHorizontalNavSearchRadius = 5
L1_3425.staticSpawnVerticalNavSearchRadius = 5
L2_3426 = {}
L2_3426.bPhysicalize = 1
L2_3426.bRigidBody = 1
L2_3426.bPushableByPlayers = 1
L2_3426.bPushableByAI = 1
L2_3426.signalpackage_collisionDamagePackage = "3149325216948552760"
L2_3426.bResting = 1
L2_3426.bRigidBodyActive = 0
L2_3426.Density = -1
L2_3426.mass = 5
L2_3426.damping = 0.35
L1_3425.Physics = L2_3426
L2_3426 = {}
L2_3426.organic = 5
L2_3426.mineral = 0
L2_3426.synthetic = 0
L2_3426.exotic = 10
L1_3425.RecycleData = L2_3426
L0_3424.Properties = L1_3425
ArkAlienGibletSmall = L0_3424
L0_3424 = ArkAlienGibletSmall
function L1_3425(A0_3427)
  local L1_3428
  L1_3428 = A0_3427.Properties
  L1_3428 = L1_3428.Physics
  L1_3428.CollisionFiltering = {}
  L1_3428 = A0_3427.Properties
  L1_3428 = L1_3428.Physics
  L1_3428 = L1_3428.CollisionFiltering
  L1_3428.collisionType = {}
  L1_3428.collisionIgnore = {}
  for _FORV_5_, _FORV_6_ in pairs(g_PhysicsCollisionClass) do
    L1_3428.collisionType[_FORV_5_] = 0
    L1_3428.collisionIgnore[_FORV_5_] = 0
  end
  L1_3428.collisionIgnore[gcc_ai] = 1
  L1_3428.collisionIgnore[gcc_coral] = 1
  L1_3428.collisionIgnore[gcc_ragdoll] = 1
  A0_3427:SetPhysicParams(PHYSICPARAM_COLLISION_CLASS, L1_3428)
end
L0_3424.OnSpawn = L1_3425
