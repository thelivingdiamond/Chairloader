local L0_1566, L1_1567
L0_1566 = {}
L1_1567 = {}
L1_1567.fileHitDeathReactionsParamsDataFile = "Libs/HitDeathReactionsData/HitDeathReactions_Default.xml"
L1_1567.bEnableHitReaction = 1
L1_1567.soclasses_SmartObjectClass = "Actor"
L1_1567.physicMassMult = 1
L1_1567.Damage = {bLogDamages = 0}
L1_1567.Rendering = {bWrinkleMap = 0}
L1_1567.CharacterSounds = {
  footstepEffect = "footstep",
  remoteFootstepEffect = "footstep",
  bFootstepGearEffect = 1,
  footstepIndGearAudioSignal_Walk = "",
  footstepIndGearAudioSignal_Run = "",
  foleyEffect = "",
  bodyFallEffect = "bodyfall"
}
L0_1566.Properties = L1_1567
L1_1567 = {}
L0_1566.tempSetStats = L1_1567
L1_1567 = {}
L0_1566.Server = L1_1567
L1_1567 = {}
L0_1566.Client = L1_1567
L1_1567 = {
  {
    0,
    "rightArm",
    "Bip01 R UpperArm",
    "Bip01 R Forearm",
    "Bip01 R Hand",
    IKLIMB_RIGHTHAND
  },
  {
    0,
    "leftArm",
    "Bip01 L UpperArm",
    "Bip01 L Forearm",
    "Bip01 L Hand",
    IKLIMB_LEFTHAND
  },
  {
    5,
    "rightArmShadow",
    "Bip01 R UpperArm",
    "Bip01 R Forearm",
    "Bip01 R Hand",
    IKLIMB_RIGHTHAND
  },
  {
    5,
    "leftArmShadow",
    "Bip01 L UpperArm",
    "Bip01 L Forearm",
    "Bip01 L Hand",
    IKLIMB_LEFTHAND
  }
}
L0_1566.IKLimbs = L1_1567
BasicActor = L0_1566
L0_1566 = {}
L1_1567 = {}
L1_1567.flags = 0
L1_1567.mass = 110
L1_1567.mass_Player = 120
L1_1567.mass_Grunt = 180
L1_1567.stiffness_scale = 73
L1_1567.fallNPlayStiffness_scale = 100
L1_1567.Living = {
  gravity = 9.81,
  mass = 110,
  mass_Player = 120,
  mass_Grunt = 180,
  air_resistance = 0.2,
  k_air_control = 0.9,
  inertia = 10,
  inertiaAccel = 11,
  max_vel_ground = 16,
  min_slide_angle = 45,
  max_climb_angle = 50,
  min_fall_angle = 50,
  timeImpulseRecover = 1,
  colliderMat = "mat_player_collider"
}
L0_1566.physicsParams = L1_1567
L1_1567 = {}
L1_1567.autoAimTargetParams = {
  primaryTargetBone = BONE_SPINE,
  physicsTargetBone = BONE_SPINE,
  secondaryTargetBone = BONE_HEAD,
  fallbackOffset = 1.2,
  innerRadius = 0.4,
  outerRadius = 0.5,
  snapRadius = 2,
  snapRadiusTagged = 4
}
L1_1567.sprintMultiplier = 1.5
L1_1567.sneakMultiplier = 1
L1_1567.strafeMultiplier = 1
L1_1567.backwardMultiplier = 0.7
L1_1567.jumpHeight = 1.5
L1_1567.meeleHitRagdollImpulseScale = 1
L1_1567.leanShift = 0.35
L1_1567.leanAngle = 15
L1_1567.lookFOV = 80
L1_1567.lookInVehicleFOV = 80
L1_1567.aimFOV = 70
L0_1566.gameParams = L1_1567
BasicActorParams = L0_1566
function L0_1566(A0_1568)
  local L1_1569
  if A0_1568 then
    L1_1569 = A0_1568.gameParams
    if not L1_1569 then
      L1_1569 = {}
      A0_1568.gameParams = L1_1569
    end
    L1_1569 = A0_1568.gameParams
    L1_1569 = L1_1569.stance
    if not L1_1569 then
      L1_1569 = A0_1568.gameParams
      L1_1569.stance = {
        {
          stanceId = STANCE_STAND,
          normalSpeed = 1,
          maxSpeed = 50,
          heightCollider = 1.2,
          heightPivot = 0,
          size = {
            x = 0.4,
            y = 0.4,
            z = 0.2
          },
          modelOffset = {
            x = 0,
            y = 0,
            z = 0
          },
          viewOffset = {
            x = 0,
            y = 0.1,
            z = 1.625
          },
          weaponOffset = {
            x = 0.2,
            y = 0,
            z = 1.35
          },
          leanLeftViewOffset = {
            x = -0.5,
            y = 0.1,
            z = 1.525
          },
          leanRightViewOffset = {
            x = 0.5,
            y = 0.1,
            z = 1.525
          },
          leanLeftWeaponOffset = {
            x = -0.45,
            y = 0,
            z = 1.3
          },
          leanRightWeaponOffset = {
            x = 0.65,
            y = 0,
            z = 1.3
          },
          name = "stand",
          useCapsule = 1
        },
        {
          stanceId = STANCE_STEALTH,
          normalSpeed = 0.6,
          maxSpeed = 3,
          heightCollider = 1,
          heightPivot = 0,
          size = {
            x = 0.4,
            y = 0.4,
            z = 0.1
          },
          modelOffset = {
            x = 0,
            y = 0,
            z = 0
          },
          viewOffset = {
            x = 0,
            y = 0.3,
            z = 1.35
          },
          weaponOffset = {
            x = 0.2,
            y = 0,
            z = 1.1
          },
          name = "stealth",
          useCapsule = 1
        },
        {
          stanceId = STANCE_SNEAK,
          normalSpeed = 0.5,
          maxSpeed = 3,
          heightCollider = 0.8,
          heightPivot = 0,
          size = {
            x = 0.4,
            y = 0.4,
            z = 0.1
          },
          modelOffset = {
            x = 0,
            y = 0,
            z = 0
          },
          viewOffset = {
            x = 0,
            y = 0,
            z = 1.1
          },
          weaponOffset = {
            x = 0.2,
            y = 0,
            z = 0.85
          },
          leanLeftViewOffset = {
            x = -0.55,
            y = 0,
            z = 0.95
          },
          leanRightViewOffset = {
            x = 0.55,
            y = 0,
            z = 0.95
          },
          leanLeftWeaponOffset = {
            x = -0.5,
            y = 0,
            z = 0.65
          },
          leanRightWeaponOffset = {
            x = 0.5,
            y = 0,
            z = 0.65
          },
          name = "sneak",
          useCapsule = 1
        },
        {
          stanceId = STANCE_SWIM,
          normalSpeed = 1,
          maxSpeed = 2.5,
          heightCollider = 0.9,
          heightPivot = 0.5,
          size = {
            x = 0.4,
            y = 0.4,
            z = 0.1
          },
          modelOffset = {
            x = 0,
            y = 0,
            z = 0
          },
          viewOffset = {
            x = 0,
            y = 0.1,
            z = 0.5
          },
          weaponOffset = {
            x = 0.2,
            y = 0,
            z = 0.3
          },
          name = "swim",
          useCapsule = 1
        },
        {
          stanceId = STANCE_ZEROG,
          normalSpeed = 1,
          maxSpeed = 2.5,
          heightCollider = 0.9,
          heightPivot = 0.5,
          size = {
            x = 0.4,
            y = 0.4,
            z = 0.1
          },
          modelOffset = {
            x = 0,
            y = 0,
            z = 0
          },
          viewOffset = {
            x = 0,
            y = 0.1,
            z = 0.5
          },
          weaponOffset = {
            x = 0.2,
            y = 0,
            z = 0.3
          },
          name = "zerog",
          useCapsule = 1
        },
        {
          stanceId = STANCE_RELAXED,
          normalSpeed = 1,
          maxSpeed = 50,
          heightCollider = 1.2,
          heightPivot = 0,
          size = {
            x = 0.4,
            y = 0.4,
            z = 0.2
          },
          modelOffset = {
            x = 0,
            y = 0,
            z = 0
          },
          viewOffset = {
            x = 0,
            y = 0.1,
            z = 1.625
          },
          weaponOffset = {
            x = 0.2,
            y = 0,
            z = 1.3
          },
          name = "relaxed",
          useCapsule = 1
        }
      }
    end
  end
end
CreateDefaultStances = L0_1566
function L0_1566(A0_1570)
  mergef(A0_1570, BasicActorParams, 1)
  mergef(A0_1570, BasicActor, 1)
  CreateDefaultStances(A0_1570)
  SetupCollisionFiltering(A0_1570)
end
CreateActor = L0_1566
function L0_1566(A0_1571)
  mergef(A0_1571, BasicActorParams, 1)
  mergef(A0_1571, BasicActor, 1)
end
CreateActorForAISubclass = L0_1566
function L0_1566(A0_1572)
  CreateDefaultStances(A0_1572)
  SetupCollisionFiltering(A0_1572)
end
InitActorForAISubclass = L0_1566
L0_1566 = BasicActor
function L1_1567(A0_1573, A1_1574, A2_1575)
  if A0_1573.actor and (A0_1573:IsDead() or System.IsEditor()) then
    A0_1573.actor:Revive()
  end
  if A0_1573.Properties.bEnableHitReaction and A0_1573.Properties.bEnableHitReaction == 0 then
    A0_1573.actor:DisableHitReaction()
  else
    A0_1573.actor:EnableHitReaction()
  end
  A0_1573:StopSounds()
  A0_1573:RemoveDecals()
  A0_1573:EnableDecals(0, true)
  A0_1573.lastDeathImpulse = 0
  A0_1573.painSoundTriggered = nil
  if A0_1573.lastSpawnPoint then
    A0_1573.lastSpawnPoint = 0
  end
  A0_1573.AI = {}
end
L0_1566.ResetCommon = L1_1567
L0_1566 = BasicActor
function L1_1567(A0_1576, A1_1577, A2_1578)
  BasicActor.ResetCommon(A0_1576, A1_1577, A2_1578)
  if A0_1576.actor then
    A0_1576.actor:SetMovementTarget(g_Vectors.v000, g_Vectors.v000, g_Vectors.v000, 1)
  end
  A0_1576.AI.theVehicle = nil
end
L0_1566.Reset = L1_1567
L0_1566 = BasicActor
function L1_1567(A0_1579)
  local L1_1580
end
L0_1566.ResetLoad = L1_1567
L0_1566 = BasicActor
function L1_1567(A0_1581)
  if A0_1581.IKLimbs then
    for _FORV_4_, _FORV_5_ in pairs(A0_1581.IKLimbs) do
      A0_1581.actor:CreateIKLimb(_FORV_5_[1], _FORV_5_[2], _FORV_5_[3], _FORV_5_[4], _FORV_5_[5], _FORV_5_[6] or 0)
    end
  end
end
L0_1566.InitIKLimbs = L1_1567
L0_1566 = BasicActor
function L1_1567(A0_1582)
  A0_1582:ResetAttachment(0, "weapon")
  A0_1582:ResetAttachment(0, "right_item_attachment")
  A0_1582:ResetAttachment(0, "left_item_attachment")
  A0_1582:ResetAttachment(0, "laser_attachment")
  A0_1582.actor:ShutDown()
end
L0_1566.ShutDown = L1_1567
L0_1566 = BasicActor
function L1_1567(A0_1583)
  local L1_1584, L2_1585
  L1_1584 = A0_1583.actor
  L2_1585 = L1_1584
  L1_1584 = L1_1584.GetHealth
  L1_1584 = L1_1584(L2_1585)
  L2_1585 = A0_1583.lastHealth
  L2_1585 = L2_1585 - L1_1584
  if A0_1583.Properties.Damage.bLogDamages ~= 0 then
    Log(A0_1583:GetName() .. " health:" .. L1_1584 .. " (last damage:" .. L2_1585 .. ")")
  end
  A0_1583.lastHealth = L1_1584
end
L0_1566.HealthChanged = L1_1567
L0_1566 = BasicActor
L0_1566 = L0_1566.Server
function L1_1567(A0_1586, A1_1587)
  local L2_1588, L3_1589, L4_1590, L5_1591, L6_1592
  L2_1588 = System
  L2_1588 = L2_1588.GetFrameID
  L2_1588 = L2_1588()
  L3_1589 = A0_1586.lastDeathImpulse
  L3_1589 = L2_1588 - L3_1589
  if L3_1589 > 10 then
    L3_1589 = g_Vectors
    L3_1589 = L3_1589.temp_v2
    L4_1590 = CopyVector
    L5_1591 = L3_1589
    L6_1592 = A1_1587.dir
    L4_1590(L5_1591, L6_1592)
    L4_1590 = L3_1589.z
    L4_1590 = L4_1590 + 1
    L3_1589.z = L4_1590
    L4_1590 = g_Vectors
    L4_1590 = L4_1590.temp_v3
    L5_1591 = math
    L5_1591 = L5_1591.random
    L5_1591 = L5_1591()
    L5_1591 = L5_1591 * 2
    L5_1591 = L5_1591 - 1
    L4_1590.x = L5_1591
    L5_1591 = math
    L5_1591 = L5_1591.random
    L5_1591 = L5_1591()
    L5_1591 = L5_1591 * 2
    L5_1591 = L5_1591 - 1
    L4_1590.y = L5_1591
    L5_1591 = math
    L5_1591 = L5_1591.random
    L5_1591 = L5_1591()
    L5_1591 = L5_1591 * 2
    L5_1591 = L5_1591 - 1
    L4_1590.z = L5_1591
    L5_1591 = math
    L5_1591 = L5_1591.random
    L5_1591 = L5_1591()
    L5_1591 = L5_1591 * 20
    L5_1591 = L5_1591 + 10
    L6_1592 = math
    L6_1592 = L6_1592.random
    L6_1592 = L6_1592()
    L6_1592 = L6_1592 * 20
    L6_1592 = L6_1592 + 10
    if A1_1587.type ~= "silentMelee" and not g_gameRules:IsStealthHealthHit(A1_1587.type) then
      A0_1586:AddImpulse(A1_1587.partId, A1_1587.pos, L3_1589, L5_1591, 1, L4_1590, L6_1592, 8)
      A0_1586.lastDeathImpulse = L2_1588
    end
  end
end
L0_1566.OnDeadHit = L1_1567
L0_1566 = BasicActor
L0_1566 = L0_1566.Server
function L1_1567(A0_1593, A1_1594)
  if A0_1593.ShouldIgnoreHit and A0_1593:ShouldIgnoreHit(A1_1594) then
    return false
  end
  if A1_1594.damage > 5 and A0_1593.actor:GetHealth() > 0 then
    A0_1593:DoPainSounds(false, A1_1594.type, false)
  end
  if A1_1594.damage == 0 then
    return (g_gameRules:ProcessActorDamage(A1_1594))
  end
  if A1_1594.type and A1_1594.type ~= "collision" and A1_1594.type ~= "fall" and A1_1594.type ~= "event" then
    if A1_1594.shooter then
      CopyVector(g_SignalData.point, A1_1594.shooter:GetWorldPos())
      g_SignalData.id = A1_1594.shooterId
    else
      g_SignalData.id = NULL_ENTITY
      CopyVector(g_SignalData.point, g_Vectors.v000)
    end
    g_SignalData.fValue = A1_1594.damage
    if AI then
      if A1_1594.shooter and AI.Hostile(A0_1593.id, A1_1594.shooterId) then
        AI.Signal(SIGNALFILTER_SENDER, 0, "OnEnemyDamage", A0_1593.id, g_SignalData)
        AI.UpTargetPriority(A0_1593.id, A1_1594.shooterId, 0.2)
      elseif A1_1594.shooter ~= nil and A1_1594.shooter ~= A0_1593 then
        if A1_1594.weapon and A1_1594.weapon.vehicle then
          AI.Signal(SIGNALFILTER_SENDER, 0, "OnDamage", A0_1593.id, g_SignalData)
        else
          AI.Signal(SIGNALFILTER_SENDER, 0, "OnFriendlyDamage", A0_1593.id, g_SignalData)
        end
      else
        AI.Signal(SIGNALFILTER_SENDER, 0, "OnDamage", A0_1593.id, g_SignalData)
      end
    end
  end
  if A0_1593.RushTactic then
    A0_1593:RushTactic(5)
  end
  A0_1593:HealthChanged()
  return (g_gameRules:ProcessActorDamage(A1_1594))
end
L0_1566.OnHit = L1_1567
L0_1566 = BasicActor
function L1_1567(A0_1595)
  A0_1595.actor:SetPhysicalizationProfile("ragdoll")
end
L0_1566.TurnRagdoll = L1_1567
L0_1566 = BasicActor
function L1_1567(A0_1596, A1_1597)
  local L2_1598, L3_1599
  if A1_1597 == nil then
    L2_1598 = Log
    L3_1599 = "Error: BasicActor:Kill - Parameter 'hit' is nil"
    L2_1598(L3_1599)
    return
  end
  L2_1598 = A1_1597.shooterId
  L3_1599 = A1_1597.weaponId
  if AI then
    AI.LogEvent("BasicActor:ClientKill( " .. tostring(L2_1598) .. ", " .. tostring(L3_1599))
  end
  if A0_1596.actor:GetHealth() > 0 then
    A0_1596.actor:SetHealth(0)
  end
  if A0_1596.OnCustomKill then
    A0_1596:OnCustomKill(A1_1597)
  end
  A0_1596:DoPainSounds(1, A1_1597.type, false)
  if L2_1598 and System.GetEntity(L2_1598) and 0 < A1_1597.projectileClassId then
    A0_1596.deathProjectileClassId = A1_1597.projectileClassId
    A0_1596.deathProjectileClass = A1_1597.projectileClass
  end
  if A0_1596 == g_localActor then
    if AI then
      AI.Signal(SIGNALFILTER_GROUPONLY_EXCEPT, 1, "OnPlayerDied", A0_1596.id)
    end
  elseif AI.GetReactionOf(A0_1596.id, g_localActorId) == Friendly then
    if L2_1598 and System.GetEntity(L2_1598) and (L2_1598 and System.GetEntity(L2_1598)) == g_localActor then
      g_SignalData.id = (L2_1598 and System.GetEntity(L2_1598)).id
      AI.Signal(SIGNALFILTER_LEADER, 10, "OnUnitBusy", A0_1596.id)
      AI.Signal(SIGNALFILTER_GROUPONLY_EXCEPT, 1, "OnPlayerTeamKill", A0_1596.id, g_SignalData)
    else
      AI.Signal(SIGNALFILTER_GROUPONLY_EXCEPT, 1, "OnSquadmateDied", A0_1596.id)
    end
  end
  if AI then
    AI.Signal(SIGNALFILTER_LEADER, 10, "OnUnitDied", A0_1596.id)
    AI.Signal(SIGNALFILTER_LEADERENTITY, 10, "OnUnitDied", A0_1596.id)
    g_SignalData.id = A0_1596.id
    CopyVector(g_SignalData.point, A0_1596:GetPos())
    if 1 < AI.GetGroupCount(A0_1596.id) then
      AI.ChangeParameter(A0_1596.id, AIPARAM_COMMRANGE, 100)
      AI.ChangeParameter(A0_1596.id, AIPARAM_COMMRANGE, 10)
      AI.Signal(SIGNALFILTER_NEARESTINCOMM, 10, "OnBodyFallSound", A0_1596.id, g_SignalData)
    else
      AI.Signal(SIGNALFILTER_ANYONEINCOMM, 10, "OnSomebodyDied", A0_1596.id)
    end
    if L2_1598 and System.GetEntity(L2_1598) then
      AI.LogEvent("Shooter position:" .. Vec2Str((L2_1598 and System.GetEntity(L2_1598)):GetWorldPos()))
      AI.SetRefPointPosition(A0_1596.id, (L2_1598 and System.GetEntity(L2_1598)):GetWorldPos())
      AI.SetBeaconPosition(A0_1596.id, (L2_1598 and System.GetEntity(L2_1598)):GetWorldPos())
    end
    if A0_1596.Behaviour and A0_1596.Behaviour.Destructor then
      AI.LogEvent("Calling Destructor for " .. A0_1596:GetName() .. " on Kill.")
      A0_1596.Behaviour:Destructor(A0_1596)
    end
  end
  A0_1596:TriggerEvent(AIEVENT_AGENTDIED, L2_1598 or NULL_ENTITY)
  if BasicAI then
    Script.SetTimerForFunction(1000, "BasicAI.OnDeath", A0_1596)
  end
  NotifyDeathToTerritoryAndWave(A0_1596)
  if A0_1596.OnDisabled then
    A0_1596:OnDisabled()
  end
  return true
end
L0_1566.Kill = L1_1567
L0_1566 = BasicActor
L0_1566 = L0_1566.Client
function L1_1567(A0_1600, A1_1601)
  local L2_1602
  L2_1602 = A1_1601.shooter
  if A1_1601.radius == 0 and g_gameRules.game:IsMultiplayer() then
    A0_1600:WallBloodSplat(A1_1601)
  end
  if 0 >= A0_1600.actor:GetHealth() then
    return
  end
  if L2_1602 and A0_1600 == g_localActor and AI.GetReactionOf(A0_1600.id, L2_1602.id) ~= Friendly then
    g_SignalData.id = shooterId
    g_SignalData.fValue = 0
    g_SignalData.iValue = LAS_DEFAULT
    L2_1602:GetWorldPos(g_SignalData.point)
    if AI then
      AI.Signal(SIGNALFILTER_SUPERGROUP, 1, "OnPlayerHit", A0_1600.id, g_SignalData)
    end
  end
end
L0_1566.OnHit = L1_1567
L0_1566 = BasicActor
function L1_1567(A0_1603, A1_1604)
  if A1_1604.shooter == nil then
    return false
  end
  if A1_1604.shooter ~= g_localActor then
    return false
  end
  if A1_1604.target.actor:GetHealth() <= 0 then
    return false
  end
  if g_gameRules:IsStealthHealthHit(A1_1604.type) then
    return false
  end
  return g_gameRules.game:ShouldGiveLocalPlayerHitFeedback2DSound(A1_1604.damage)
end
L0_1566.ShouldGiveLocalPlayerHitFeedback2DSounds = L1_1567
L0_1566 = BasicActor
function L1_1567(A0_1605)
  local L1_1606
  A0_1605.lastPainSound = nil
  A0_1605.lastPainTime = 0
end
L0_1566.StopSounds = L1_1567
L0_1566 = BasicActor
function L1_1567(A0_1607, A1_1608)
end
L0_1566.DoPainSounds = L1_1567
L0_1566 = BasicActor
function L1_1567(A0_1609, A1_1610)
  local L2_1611, L3_1612, L4_1613, L5_1614
  L2_1611 = false
  L3_1612 = A0_1609.PropertiesInstance
  L4_1613 = A0_1609.Properties
  L4_1613 = L4_1613.fileModel
  L5_1614 = A0_1609.Properties
  L5_1614 = L5_1614.clientFileModel
  if L5_1614 and A1_1610 then
    L5_1614 = A0_1609.Properties
    L4_1613 = L5_1614.clientFileModel
  end
  L5_1614 = A0_1609.currModel
  if L5_1614 ~= L4_1613 then
    L2_1611 = true
    A0_1609.currModel = L4_1613
    L5_1614 = A0_1609.LoadCharacter
    L5_1614(A0_1609, 0, L4_1613)
    L5_1614 = A0_1609.InitIKLimbs
    L5_1614(A0_1609)
    L5_1614 = A0_1609.ForceCharacterUpdate
    L5_1614(A0_1609, 0, false)
    L5_1614 = A0_1609.CreateBoneAttachment
    L5_1614(A0_1609, 0, "weapon_bone", "right_item_attachment")
    L5_1614 = A0_1609.CreateBoneAttachment
    L5_1614(A0_1609, 0, "weapon_bone", "weapon")
    L5_1614 = A0_1609.CreateBoneAttachment
    L5_1614(A0_1609, 0, "alt_weapon_bone01", "left_item_attachment")
    L5_1614 = A0_1609.CreateBoneAttachment
    L5_1614(A0_1609, 0, "weapon_bone", "laser_attachment")
    L5_1614 = A0_1609.CreateAttachments
    if L5_1614 then
      L5_1614 = A0_1609.CreateAttachments
      L5_1614(A0_1609)
    end
    L5_1614 = A0_1609.inventory
    if L5_1614 then
      L5_1614 = A0_1609.inventory
      L5_1614 = L5_1614.GetCurrentItemId
      L5_1614 = L5_1614(L5_1614)
      if L5_1614 ~= nil then
        A0_1609.actor:SelectItem(L5_1614, true)
      end
    end
  end
  L5_1614 = A0_1609.Properties
  L5_1614 = L5_1614.shadowFileModel
  if L5_1614 and A1_1610 and A0_1609.currShadowModel ~= L5_1614 then
    A0_1609.currShadowModel = L5_1614
    A0_1609:LoadCharacter(5, A0_1609.Properties.shadowFileModel)
  end
  return L2_1611
end
L0_1566.SetActorModel = L1_1567
L0_1566 = BasicActor
function L1_1567(A0_1615)
  local L1_1616, L2_1617, L3_1618, L4_1619
  L1_1616 = System
  L1_1616 = L1_1616.GetEntitiesByClass
  L2_1617 = "SpawnPoint"
  L1_1616 = L1_1616(L2_1617)
  L2_1617 = table
  L2_1617 = L2_1617.getn
  L3_1618 = L1_1616
  L2_1617 = L2_1617(L3_1618)
  L3_1618 = table
  L3_1618 = L3_1618.sort
  L3_1618(L4_1619, CompareEntitiesByName)
  L3_1618 = L2_1617
  if L4_1619 then
    for _FORV_7_ = 1, L2_1617 do
      if A0_1615.lastSpawnPoint == L1_1616[_FORV_7_]:GetName() then
        L3_1618 = _FORV_7_
      end
    end
  end
  L3_1618 = L3_1618 + 1
  if L2_1617 < L3_1618 then
    L3_1618 = 1
  end
  A0_1615:InternalSpawnAtSpawnPoint(L4_1619)
end
L0_1566.OnNextSpawnPoint = L1_1567
L0_1566 = BasicActor
function L1_1567(A0_1620, A1_1621)
  if A1_1621 then
    A0_1620.lastSpawnPoint = A1_1621:GetName()
    if AI then
      AI.LogEvent("Teleport to " .. A0_1620.lastSpawnPoint)
    end
    A0_1620:SetWorldPos(A1_1621:GetWorldPos(g_Vectors.temp_v1))
    A1_1621:GetAngles(g_Vectors.temp_v1)
    g_Vectors.temp_v1.x = 0
    g_Vectors.temp_v1.y = 0
    A0_1620.actor:PlayerSetViewAngles(g_Vectors.temp_v1)
    A1_1621:Spawned(A0_1620)
  end
end
L0_1566.InternalSpawnAtSpawnPoint = L1_1567
L0_1566 = BasicActor
function L1_1567(A0_1622)
  local L1_1623
  L1_1623 = true
  L1_1623 = A0_1622.actor and A0_1622.actor:GetHealth() and A0_1622.actor:GetHealth() <= 0
  return L1_1623
end
L0_1566.IsDead = L1_1567
L0_1566 = BasicActor
function L1_1567(A0_1624, A1_1625)
end
L0_1566.OnSave = L1_1567
L0_1566 = BasicActor
function L1_1567(A0_1626, A1_1627)
end
L0_1566.OnLoad = L1_1567
L0_1566 = BasicActor
function L1_1567(A0_1628)
  A0_1628.lastHealth = A0_1628.actor:GetHealth()
  A0_1628.lastDeathImpulse = 0
  if A0_1628.AssignPrimaryWeapon then
    A0_1628:AssignPrimaryWeapon()
  end
end
L0_1566.OnPostLoad = L1_1567
L0_1566 = BasicActor
function L1_1567(A0_1629)
  A0_1629.actor:SetPhysicalizationProfile("alive")
end
L0_1566.OnResetLoad = L1_1567
L0_1566 = BasicActor
function L1_1567(A0_1630, A1_1631)
  A0_1630.grabParams = new(A0_1630.grabParams)
  A0_1630.waterStats = new(A0_1630.waterStats)
  if A0_1630.ai then
    BasicAI.OnSpawn(A0_1630, A1_1631)
  else
    A0_1630:InitialSetup(A1_1631)
  end
  ApplyCollisionFiltering(A0_1630, GetCollisionFiltering(A0_1630))
end
L0_1566.OnSpawn = L1_1567
L0_1566 = BasicActor
function L1_1567(A0_1632, A1_1633)
  BasicActor.Reset(A0_1632, A1_1633)
end
L0_1566.InitialSetup = L1_1567
L0_1566 = BasicActor
L0_1566 = L0_1566.Client
function L1_1567(A0_1634, A1_1635, A2_1636, A3_1637)
  local L4_1638, L5_1639
  L4_1638 = A0_1634.onAnimationKey
  if L4_1638 then
    L5_1639 = L4_1638[A2_1636]
    if L5_1639 then
      L5_1639(A0_1634, A1_1635)
    end
  end
end
L0_1566.OnAnimationEvent = L1_1567
L0_1566 = BasicActor
function L1_1567(A0_1640)
  return WaveAllowActorRemoval(A0_1640)
end
L0_1566.AIWaveAllowsRemoval = L1_1567
L0_1566 = BasicActor
function L1_1567(A0_1641, A1_1642, A2_1643)
  local L3_1644, L4_1645
  L3_1644 = ""
  L4_1645 = STANCE_SNEAK
  L4_1645 = A1_1642 == L4_1645 or A1_1642 == L4_1645
  if L4_1645 then
    L3_1644 = "sounds/physics:foleys/player:crouch_on"
  else
    L3_1644 = "sounds/physics:foleys/player:crouch_off"
  end
end
L0_1566.OnStanceChanged = L1_1567
