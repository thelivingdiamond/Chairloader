ArkPlayer = {
  shadowYMod = -1,
  ActionController = "Animations/Mannequin/ADB/ArkPlayerControllerDefs.xml",
  AnimDatabase3P = "Animations/Mannequin/ADB/ArkPlayerDatabase3P.adb",
  AnimDatabase1P = "Animations/Mannequin/ADB/ArkPlayerDatabase1P.adb",
  Properties = {
    fileModel = "objects/characters/Player/Player.cdf",
    shadowFileModel = "objects/characters/Player/Player.cdf",
    clientFileModel = "objects/characters/Player/Player.cdf",
    femaleClientFileModel = "objects/characters/Player/Player.cdf",
    femaleShadowFileModel = "objects/characters/Player/Player.cdf",
    maleClientFileModel = "objects/characters/Player/Player.cdf",
    maleShadowFileModel = "objects/characters/Player/Player.cdf",
    faction_ArkFaction = "17591291352618367183",
    metaTags_ArkMetaTags = "17591291352642463355,9469288860498988629,13680621263410569670",
    Physics = {
      signalpackage_collisionDamagePackage = "5345056487456352301"
    },
    MaterialAnimations = {
      materialanimations_EtherIn = "12635110349625296610"
    }
  },
  MaterialEffects = {
    footStep = "footstep_player",
    footStepSprinting = "footstep_player_sprinting",
    footStepSneaking = "footstep_player_sneaking",
    footStepCrawling = "footstep_player_crawling",
    footStepBloody = "footstep_player_sprinting_bloody",
    bodyFall = "bodyfall",
    bodyFallSneaking = "bodyFallSneaking",
    bodyFallSprinting = "bodyFallSprinting"
  },
  physicsParams = {
    flags = 0,
    mass = 110,
    mass_Player = 120,
    mass_Grunt = 180,
    stiffness_scale = 73,
    fallNPlayStiffness_scale = 100,
    Living = {
      gravity = 9.81,
      mass = 110,
      mass_Player = 120,
      mass_Grunt = 180,
      air_resistance = 0.2,
      k_air_control = 0.9,
      inertia = 15,
      inertiaAccel = 7,
      max_vel_ground = 100,
      min_slide_angle = 50,
      max_climb_angle = 50,
      min_fall_angle = 70,
      timeImpulseRecover = 1,
      colliderMat = "mat_player_collider",
      min_slide_angle_goo = 90,
      min_fall_angle_goo = 95,
      max_climb_angle_goo = 85
    },
    Ragdoll = {
      damping = 0.3,
      dampingFreefall = 0.1,
      maxTimeStep = 0.025,
      minEnergy = 6.25E-4,
      dampingLyingMode = 1.5,
      nCollLyingMode = 4,
      minEnergyLyingMode = 0.004225
    }
  },
  gameParams = {
    boneIDs = {
      BONE_BIP01 = "root_jnt",
      BONE_SPINE = "spine1_jnt",
      BONE_SPINE2 = "spine2_jnt",
      BONE_SPINE3 = "spine3_jnt",
      BONE_HEAD = "head_jnt",
      BONE_EYE_R = "r_eye_jnt",
      BONE_EYE_L = "l_eye_jnt",
      BONE_WEAPON = "r_handProp_jnt",
      BONE_WEAPON2 = "l_handProp_jnt",
      BONE_FOOT_R = "r_foot_jnt",
      BONE_FOOT_L = "l_foot_jnt",
      BONE_ARM_R = "r_lowerArm_jnt",
      BONE_ARM_L = "l_lowerArm_jnt",
      BONE_CALF_R = "r_lowerLeg_jnt",
      BONE_CALF_L = "l_lowerLeg_jnt",
      BONE_CAMERA = "camera_jnt",
      BONE_HUD = "hud_jnt"
    },
    jumpImpulse = 5,
    stance = {
      {
        stanceId = STANCE_STAND,
        maxSpeed = 5,
        heightCollider = 1.25,
        heightPivot = 0,
        size = {
          x = 0.41,
          y = 0.41,
          z = 0.3
        },
        viewOffset = {
          x = 0,
          y = 0,
          z = 1.7
        },
        weaponOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        name = "stand",
        useCapsule = 1,
        CollisionHeight = 1.9,
        CollisionDiameter = 0.7,
        CapsuleOffset = 0.53
      },
      {stanceId = -2},
      {
        stanceId = STANCE_SNEAK,
        maxSpeed = 2,
        heightCollider = 0.7,
        heightPivot = 0,
        size = {
          x = 0.41,
          y = 0.41,
          z = 0.1
        },
        viewOffset = {
          x = 0,
          y = 0,
          z = 1
        },
        weaponOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        viewDownYMod = 0,
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        name = "sneak",
        useCapsule = 1,
        CollisionHeight = 1.5,
        CollisionDiameter = 0.7,
        CapsuleOffset = 0.4
      },
      {
        stanceId = STANCE_SWIM,
        maxSpeed = 2.1,
        heightCollider = 1,
        heightPivot = 0,
        size = {
          x = 0.41,
          y = 0.41,
          z = 0.35
        },
        viewOffset = {
          x = 0,
          y = 0,
          z = 1.7
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        weaponOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        name = "swim",
        useCapsule = 1
      },
      {
        stanceId = STANCE_ZEROG,
        maxSpeed = 2,
        heightCollider = 0.4,
        heightPivot = 0,
        size = {
          x = 0.2,
          y = 0.2,
          z = 0.2
        },
        viewOffset = {
          x = 0,
          y = 0,
          z = 0.46
        },
        weaponOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        name = "zerog",
        useCapsule = 1,
        CollisionHeight = 0.7,
        CollisionDiameter = 0.7,
        CapsuleOffset = 0
      },
      {
        stanceId = STANCE_CRAWL,
        maxSpeed = 2,
        heightCollider = 0.4,
        heightPivot = 0,
        size = {
          x = 0.2,
          y = 0.2,
          z = 0.2
        },
        viewOffset = {
          x = 0,
          y = 0,
          z = 0.46
        },
        weaponOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        name = "crawl",
        useCapsule = 1,
        CollisionHeight = 0.7,
        CollisionDiameter = 0.7,
        CapsuleOffset = 0
      },
      {
        stanceId = STANCE_SMOKE,
        maxSpeed = 2,
        heightCollider = 0.4,
        heightPivot = 0,
        size = {
          x = 0.2,
          y = 0.2,
          z = 0.2
        },
        viewOffset = {
          x = 0,
          y = 0,
          z = 0.46
        },
        weaponOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        modelOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        name = "crawl",
        useCapsule = 1,
        CollisionHeight = 0.7,
        CollisionDiameter = 0.7,
        CapsuleOffset = 0
      },
      {stanceId = -2}
    },
    viewDownYMod = 0.1
  },
  Fabrication = {
    Plans = {}
  },
  Server = {},
  m_damageID = 0,
  m_interferenceAuraRadius = 0
}
bAreCCRegistered = bAreCCRegistered
if not bAreCCRegistered then
  System.AddCCommand("pl_setPsiPoints", "g_localActor.arkPlayer:SetPsiPoints( tonumber( %1 ))", "Sets the player's psi points to given value.")
  System.AddCCommand("pl_unlockPsiScanning", "g_localActor.arkPlayer:UnlockPsiScanning( tonumber( %1 ))", "Enable or disable psi scanning.")
  System.AddCCommand("pl_playerInterferenceAura", "g_localActor:SetInterferenceAura( tonumber( %1 ))", "Set the interference aura radius for debugging interference. 0 means disable.")
  System.AddCCommand("pl_loglevelloottables", "g_localActor:LogLootTables()", "Logs the contents of every loot table.")
  bAreCCRegistered = true
end
function ArkPlayer.IsDead(A0_1528)
  local L1_1529
  L1_1529 = false
  return L1_1529
end
function ArkPlayer.GetNextDamageID(A0_1530)
  local L1_1531
  L1_1531 = A0_1530.m_damageID
  L1_1531 = L1_1531 + 1
  A0_1530.m_damageID = L1_1531
  L1_1531 = A0_1530.m_damageID
  if L1_1531 > 1000 then
    A0_1530.m_damageID = 0
  end
  L1_1531 = A0_1530.m_damageID
  return L1_1531
end
function ArkPlayer.IndicateDamageOnHUD(A0_1532, A1_1533)
  local L2_1534, L3_1535
  L2_1534 = GetDirection
  L3_1535 = A0_1532.GetCenterOfMassPos
  L3_1535 = L3_1535(A0_1532)
  L2_1534 = L2_1534(L3_1535, A1_1533)
  L3_1535 = GetAngleBetweenVectors2D
  L3_1535 = L3_1535(g_Vectors.v010, L2_1534)
  L3_1535 = L3_1535 * g_Rad2Deg
  L3_1535 = L3_1535 + 90
  UIAction.StartAction("Ark_HUD_DamageIndication", {
    A0_1532:GetNextDamageID(),
    L3_1535
  })
end
function ArkPlayer.GetFabPlans(A0_1536)
  return A0_1536.Fabrication.Plans
end
function ArkPlayer.GiveFabPlan(A0_1537, A1_1538)
  local L2_1539, L3_1540
  L2_1539 = A0_1537.Fabrication
  L2_1539 = L2_1539.Plans
  L3_1540 = A0_1537.Fabrication
  L3_1540 = L3_1540.Plans
  L3_1540 = #L3_1540
  L3_1540 = L3_1540 + 1
  L2_1539[L3_1540] = A1_1538
end
function ArkPlayer.LogLootTables(A0_1541)
  Log("***BEGINNING LOOT DUMP***")
  System.GetEntitiesByClass("ArkContainer").LogContents = function(A0_1542)
    local L1_1543, L2_1544, L3_1545, L4_1546, L5_1547, L6_1548
    L1_1543 = {}
    for L5_1547, L6_1548 in L2_1544(L3_1545) do
      if type(L6_1548) ~= "function" then
        if L6_1548.inventory:IsEmpty() then
          Log("[EMPTY][CONTAINER]" .. L6_1548:GetName())
        else
          L1_1543 = L6_1548.inventory:GetAllItems()
          for _FORV_10_, _FORV_11_ in pairs(L1_1543) do
            Log("[LOOT][CONTAINER]" .. _FORV_11_:GetArchetype() .. " x" .. tostring(_FORV_11_.arkitem:GetCount()) .. " inside " .. L6_1548:GetName())
          end
        end
      end
    end
  end
  System.GetEntitiesByClass("ArkKeypadContainer").LogContents = System.GetEntitiesByClass("ArkContainer").LogContents
  System.GetEntitiesByClass("ArkHuman").LogContents = System.GetEntitiesByClass("ArkContainer").LogContents
  System.GetEntitiesByClass("ArkContainer"):LogContents()
  System.GetEntitiesByClass("ArkKeypadContainer"):LogContents()
  System.GetEntitiesByClass("ArkHuman"):LogContents()
  Log("***END LOOT DUMP***")
end
function ArkPlayer.OnFear(A0_1549, A1_1550)
  local L2_1551
  L2_1551 = 1
  return L2_1551
end
function ArkPlayer.OnHypnosis(A0_1552, A1_1553)
  local L2_1554
  L2_1554 = 1
  return L2_1554
end
function ArkPlayer.OnCyberkinesis(A0_1555, A1_1556)
  local L2_1557
  L2_1557 = 1
  return L2_1557
end
function ArkPlayer.Server.OnHit(A0_1558, A1_1559)
  return A0_1558.actor:SetHealth(A0_1558.actor:GetHealth() - A1_1559.damage) > 0
end
function ArkPlayer.Server.OnUpdate(A0_1560, A1_1561)
  local L2_1562, L3_1563
  L2_1562 = A0_1560.m_interferenceAuraRadius
  if L2_1562 > 0 then
    L2_1562 = 0.5
    L3_1563 = 10
    if A0_1560.lastSignalTime ~= nil then
      if L2_1562 < System.GetCurrTime() - A0_1560.lastSignalTime then
        A0_1560.lastSignalTime = System.GetCurrTime()
        Ark.SendSignalPackageInAOE(A0_1560.id, A0_1560.id, "3149325216951319437", A0_1560:GetWorldBoundsCenter(), L3_1563, L3_1563, 0, 0)
      end
    else
      A0_1560.lastSignalTime = System.GetCurrTime()
    end
  end
  L2_1562 = GameToken
  L2_1562 = L2_1562.GetTokenFromId
  L3_1563 = "1058263810"
  L2_1562 = L2_1562(L3_1563)
  if L2_1562 ~= "collected" then
    if L2_1562 == "triggered" then
      A0_1560.bHasTriggeredTutorial = true
    end
    L3_1563 = A0_1560.bHasTriggeredTutorial
    if L3_1563 and L2_1562 == "disabled" then
      L3_1563 = GameToken
      L3_1563 = L3_1563.SetTokenFromId
      L3_1563("1058263810", "collect")
    end
  end
end
function ArkPlayer.SetInterferenceAura(A0_1564, A1_1565)
  A0_1564.m_interferenceAuraRadius = A1_1565
end
