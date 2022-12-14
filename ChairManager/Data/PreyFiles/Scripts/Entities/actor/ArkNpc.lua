Script.ReloadScript("Scripts/ArkEntityUtils.lua")
ArkNpc = {
  Properties = {
    scanningDisplayName = "",
    fileAiTree = "",
    attentionModel_AttentionModel = "1",
    visionCone_VisionCone = "0",
    visionCone_SecondaryVisionCone = "0",
    visionDirection = 0,
    roomPerceptionModel_RoomPerceptionModel = "",
    metaTags_ArkMetaTags = "",
    loottable_ContainerLootTable = "",
    npcManagerCombatPoints = 500,
    fCombatIntensityContribution = 0,
    fCombatIntensityRange = 0,
    fForceResistScrunchDistance = 4,
    fFallDistanceForFallAnim = 0.2,
    fFallDistanceForLandAnim = 1,
    fFallDistanceForDamage = 5,
    fFallDistanceForGlooBreak = 2,
    fFallDistanceForDialog = 10,
    fFallDamagePerMeter = 15,
    bCanFall = true,
    signalpackage_fallDamagePackageId = "10850392949533909004",
    signalpackage_collisionDamagePackage = "3149325216948552760",
    signalmodifier_markedByPlayerInboundModifier = "",
    signalModifier_ragdollSignalModifier = "3149325216984939231",
    attachmenteffects_LifetimeEffects = "",
    fBrokenRepeatDialogCD = 10,
    fFlickerDuration = 5,
    fSmallHitCooldown = 0.25,
    SmallHitSignalId = "9469288860523156056",
    bSupportsSmallAdditives = true,
    fMinDamageForSmallHitReaction = 1,
    textCorpseName = "@npc_corpse",
    fHealth = 300,
    playerPowerTierTriggerThreshold = -1,
    AbortTrackviewOnHostileAttentionLevel = 4,
    fRecycleResistScrunchDistance = 4,
    ArkCombatRoleInfo = {
      bUsesCombatRoles = 0,
      fMeleeRolePreference = 0,
      fMeleeRoleSlotCost = 1,
      fMinDistanceToAllowRangeRoleSwitch = 2.5,
      bCanGetStaleInMeleeRole = 1,
      fMeleeRoleScoreBias = 0
    },
    ArkFatality = {
      fFatalityFlingForce = 65,
      vulnerabilityHealthThreshold = 200,
      minDownwardAngle = -90,
      maxRotationDelta = 180,
      ability_alwaysVulnerableRequirement = ""
    },
    ArkNullwave = {signalModifier_nullwavedSignalModifier = ""},
    ArkDeathInfo = {
      bExplodesOnDeath = 0,
      numSmallGibs = 0,
      numMediumGibs = 0,
      numLargeGibs = 0,
      numExtraLargeGibs = 0,
      numParticleGibs = 0,
      LimbGibsMaxNumber = 1,
      fLimbChanceToSpawn = 0.5,
      limbGibClassName = "",
      bExplodesOnContact = 0,
      bCorpseOrGibsVisible = 1,
      fTimeUntilGib = 0.8,
      bGibsInheritVelocity = 1,
      inheritVelocityScalar = 1,
      GibAttachmentPrefix_Small = "fx_gibspawnsml",
      GibAttachmentPrefix_Medium = "fx_gibspawnmed",
      GibAttachmentPrefix_Large = "fx_gibspawnlrg",
      GibAttachmentPrefix_XLarge = "fx_gibspawnxlrg",
      GibAttachmentPrefix_Limb = "fx_gibspawnlimb",
      GibAttachmentPrefix_Particle = "fx_gibspawnprt",
      particleeffect_gibEffect = "Characters.Aliens.Shared.Death.AlienGib_Piece01",
      particleeffect_onKillingBlowHitEffect = "",
      attachmenteffects_onDeathEffect = "",
      fMinFlingAngle = 45,
      fFlingSpreadAngle = 25,
      gameEffect_Disintegration = "0",
      bStartGibExplosionTimerFromDeath = false,
      bStartDisintegrationTimerFromDeath = false,
      fTimeUntilDisintegration = 0,
      fTimeUntilEntityHide = 1.5,
      fTimeUntilOptimizedDeadUpdates = 20,
      fMinFlingForceCalcDamage = 1,
      fMaxFlingForceCalcDamage = 1000,
      fMinFlingForce = 20,
      fMaxFlingForce = 90,
      fMinExplosionGibFlingForce = 40,
      fMaxExplosionGibFlingForce = 65,
      fCameraEffectChance = 1,
      fDistToPlayerForCameraEffect = 3,
      particleeffect_CameraEffect = ""
    },
    MaterialAnimations = {
      materialanimations_Disintegrate = "0",
      materialanimations_AlienSpikeDisintegration = "0",
      materialanimations_HitReaction = "0",
      materialanimations_LaserBurn = "0"
    },
    ArkMetrics = {gameMetric_increaseOnDeath = ""},
    ArkAccumulator = {
      signalGroup_PsiSuppressingAccumulatorSignalGroupId = "3473393341384819491",
      signalGroup_StaggerAccumulatorSignalGroupId = "10739735956146799720",
      signalGroup_KnockdownAccumulatorSignalGroupId = "7293080054622468800",
      signalGroup_GooAccumulatorSignalGroupId = "3473393341384819343",
      signalGroup_StopGooAccumulatorSignalGroupId = "3473393341384819344",
      signalGroup_FearAccumulatorSignalGroupId = "3473393341384819471"
    },
    ArkAudio = {
      distanceToPlayerParam = "Ark_NPC_Distance"
    },
    ArkAbility = {npcAbilityContextProfileId = "1"},
    ArkGeneralEffects = {
      attachmenteffects_glitch = "17591291352656483511",
      attachmenteffects_onHit = ""
    },
    Hypnotize = {timeBetweenHypnotize = 20.25},
    ArkGooed = {
      gameEffect_GlooSlow = "16",
      signalModifier_FrozenInGoo = "8109010857446316334",
      npcAbilityContext_OnNpcGlooedAbilityId = "",
      attachment_GlooSkinAttachment = "fx_goo01",
      animation_GlooGrowAnimation = "goo",
      glooSlowFadeDuration = 1,
      glooSlowDuration = 1.5,
      glooHardenDuration = 0.75,
      glooFrozenDuration = -1,
      glooOnHitCooldown = 0.15,
      particleeffect_BreakGlooEffect = "Characters.Aliens.Generic.Goo.GooBreak_00",
      particleeffect_OnHitGlooEffect = "Characters.Aliens.Generic.Goo.GooHit_00",
      audioTrigger_glooBreakSFX = "Play_GLOO_BreakOut",
      audioTrigger_glooStartSFX = "",
      audioTrigger_glooHardenSFX = "Play_GLOO_Freeze_Big"
    },
    ArkOnFire = {attachmenteffects_OnFireEffects = "", onFireGameEffectId = ""},
    ArkLaserExplosion = {
      signalpackage_laserExplosionPackage = "8109010857459426814"
    },
    ThermalAura = {attachmenteffects_ThermalAura = ""},
    ElectricAura = {attachmenteffects_ElectricAura = ""},
    ArkDiscHit = {signalpackage_discDirectHitPackage = ""},
    ArkEnergized = {
      gameEffect_EnergizedGameEffectId = "24",
      attachmenteffects_energizedLaserExplosion = "",
      attachmenteffects_laserEnergize = ""
    },
    ArkCorrupted = {
      corruptedDisplayText = "@npc_corrupted",
      mindcontrolledDisplayText = "@npc_mindcontrol"
    },
    ArkMindControl = {
      attachmenteffects_MindControlEffectsStart = "12635110349632389795",
      attachmenteffects_MindControlEffects = "17591291352644294396",
      attachmenteffects_MindControlEffectsEnd = "12635110349632389797",
      arkNpcGameEffectId = "11",
      machineMindDisplayText = "@npc_machinemind",
      mindJackDisplayText = "@npc_mindjack"
    },
    ArkFear = {
      attachmenteffects_OnFeared = "",
      signalmodifier_OnFearedModifier = "",
      gameEffect_Feared = "19"
    },
    ArkDodge = {
      fCooldown = 5,
      fChance = 0.25,
      bEnabled = true,
      signalpackage_DodgeRipostePackageId = ""
    },
    ArkStunned = {gameEffect_StunnedGameEffectId = "2000"},
    ArkMannequin = {LifetimeTag = ""},
    ArkHitReaction = {gameEffect_HitReactionMaterialAnimation = "21"},
    ArkCallForHelp = {
      gameNoiseType_OnAttackNoiseType = "10850392949532183295",
      gameNoiseLoudness_OnAttackNoiseLoudness = "9469288860501649190",
      gameNoiseType_OnNewCombatAttentionNoiseType = "10850392949532183295",
      gameNoiseLoudness_OnNewCombatAttentionNoiseLoudness = "9469288860501649190"
    },
    ArkPlayerControlled = {gameEffect_PlayerControlledGameEffectId = "3000"},
    OnPsychoshockTargeting = {
      attachmenteffects_OnPsychoshockTargeting = "12635110349633668793"
    },
    RecycleData = {
      organic = 0,
      mineral = 0,
      synthetic = 0,
      exotic = 0
    },
    ArkInteractMessages = {
      textAliveInteractText = "@use_npc",
      textDeadInteractText = "@use_search"
    },
    OnKineticBacklashed = {attachmenteffects_OnKineticBacklashedEffects = ""},
    Surprise = {gameNoiseType_surprisedNoiseType = "", gameNoiseLoudness_surprisedNoiseLoudness = ""},
    Damage = {arkHitImpulseScale = 10},
    Sound = {
      audioTrigger_AmbientLivingStart = "",
      audioTrigger_AmbientLivingStop = "",
      audioTrigger_Death = "",
      NoiseStates = {
        audioTrigger_IdleState = "",
        audioTrigger_NoticeState = "",
        audioTrigger_StareState = "",
        audioTrigger_SearchState = "",
        audioTrigger_CombatState = ""
      }
    },
    ZeroG = {visionCone_VisionCone = "0"},
    ArkUnreachableTargeting = {
      defaultCombatReachabilityCheckUp = 1,
      defaultCombatReachabilityCheckDown = 1,
      defaultCombatReachabilityCheckHorizontal = 1,
      startingTraceRadius = 0.75,
      startingMinSearchRadius = 4,
      chanceToSearchInReverseOrder = 0.1,
      horizontalOffsetStanding = 0.25,
      standardCombatHeight = 1.75
    }
  },
  PropertiesInstance = {bIsInvulnerable = false},
  Notice = {globalNoticeAnimCooldown = 4.5},
  ArkFactionLink = {
    faction_PlayerFaction = "17591291352618367183",
    faction_PlayerControlledAlienFaction = "17591291352647918218",
    faction_PlayerControlledOperatorFaction = "961149214835558829",
    faction_PlayerControlledTurretFaction = "17591291352646192141",
    faction_PlayerControlledHumanFaction = "17591291352664927822",
    faction_PlayerAsMimicFaction = "17937592727507003218"
  },
  Editor = {
    ArchetypeEntityObjectClassName = "Entity::ArkNpcSpawner"
  },
  bHasSpawnedLoot = false,
  character_Character = "",
  alternateDisplayText = false,
  nBacklashedTimerId = -1
}
ArkMakeContainer(ArkNpc)
function CreateArkNpc(A0_1475)
  mergef(A0_1475, ArkNpc, 1)
end
function ArkNpc.IsNpcInvulnerable(A0_1476)
  return System.GetCVar("ai_invulnerable") ~= 0 or A0_1476.PropertiesInstance.bIsInvulnerable
end
function ArkNpc.CantDie(A0_1477)
  return System.GetCVar("ai_cantdie") ~= 0
end
function ArkNpc.OnDiscHitSignal(A0_1478, A1_1479, A2_1480, A3_1481)
  A0_1478.arknpc:OnDiscHit()
end
function ArkNpc.OnGooSignal(A0_1482, A1_1483, A2_1484, A3_1485, A4_1486)
  if A4_1486 > 0 then
    A0_1482.arknpc:OnGlooSignal()
  end
end
function ArkNpc.OnRecycleSignal(A0_1487, A1_1488, A2_1489, A3_1490)
  if not A0_1487:IsNpcInvulnerable() then
    if A0_1487:CantDie() and value >= A0_1487.actor:GetHealth() then
      A0_1487.actor:SetHealth(A0_1487.actor:GetMaxHealth())
    else
      A0_1487.actor:SetHealth(A0_1487.actor:GetHealth() - A1_1488.damage)
    end
  end
  if A1_1488 ~= nil then
    A0_1487.arknpc:OnRecycle(A1_1488)
  end
  if A0_1487.arknpc:IsDead() and not A0_1487:IsNpcInvulnerable() then
    if isNightmare then
      A0_1487.arknpc:Kill(A1_1488, A3_1490, false)
    else
      A0_1487.arknpc:Kill(A1_1488, A3_1490, true)
    end
    BroadcastEvent(A0_1487, "Dead")
    return
  end
end
function ArkNpc.LightOnFire(A0_1491)
  A0_1491.arknpc:LightOnFire()
end
function ArkNpc.SetupInventoryOnDeath(A0_1492)
  local L1_1493
  if A0_1492.character_Character ~= "" then
    L1_1493 = ArkRoster.GetCharacterName(A0_1492.character_Character)
  else
    L1_1493 = A0_1492.Properties.scanningDisplayName
  end
  A0_1492:SetDisplayName(L1_1493)
  Ark.SpawnLootFromTable(A0_1492.Properties.loottable_ContainerLootTable, A0_1492.id)
  A0_1492.bHasSpawnedLoot = true
end
function ArkNpc.OnResetCustom(A0_1494, A1_1495, A2_1496)
  local L3_1497
  if A1_1495 then
    L3_1497 = A0_1494.Properties
    L3_1497 = L3_1497.ArkCharacter
    if L3_1497 ~= nil then
      L3_1497 = A0_1494.Properties
      L3_1497 = L3_1497.ArkCharacter
      L3_1497 = L3_1497.character_Character
      A0_1494.character_Character = L3_1497
    end
    L3_1497 = A0_1494.ResetContainer
    L3_1497(A0_1494)
    L3_1497 = A0_1494.InitInventory
    L3_1497(A0_1494)
    L3_1497 = nil
    characterName = L3_1497
    L3_1497 = A0_1494.Properties
    L3_1497 = L3_1497.ArkCharacter
    L3_1497 = L3_1497.character_Character
    if L3_1497 ~= "" and L3_1497 ~= "13680621263400265247" then
      characterName = ArkRoster.GetCharacterName(L3_1497)
    end
    if characterName ~= nil then
      A0_1494:SetDisplayName(characterName)
    else
      A0_1494:SetDisplayName("")
    end
  end
end
function ArkNpc.IsLootable(A0_1498)
  return A0_1498.arknpc:IsDead()
end
function ArkNpc.OnNpcKilled(A0_1499)
  A0_1499.__usable = 0
  if not A0_1499.bHasSpawnedLoot then
    A0_1499:SetupInventoryOnDeath()
  end
end
function ArkNpc.OnLoot(A0_1500, A1_1501)
  if A0_1500.__usable ~= 0 and A0_1500:IsLootable() then
    A0_1500:OpenExternalInventory()
  end
end
function ArkNpc.OnUsed(A0_1502, A1_1503)
  BroadcastEvent(A0_1502, "PlayerUsed")
  BroadcastEvent(A0_1502, "Used")
end
function ArkNpc.OnSaveCustom(A0_1504, A1_1505)
  local L2_1506
  L2_1506 = A0_1504.alternateDisplayText
  A1_1505.alternateDisplayText = L2_1506
  L2_1506 = A0_1504.bHasSpawnedLoot
  A1_1505.bHasSpawnedLoot = L2_1506
end
function ArkNpc.OnLoadCustom(A0_1507, A1_1508)
  local L2_1509
  L2_1509 = A1_1508.alternateDisplayText
  A0_1507.alternateDisplayText = L2_1509
  L2_1509 = A1_1508.bHasSpawnedLoot
  A0_1507.bHasSpawnedLoot = L2_1509
end
function ArkNpc.OnStartBeingCarried(A0_1510)
  BroadcastEvent(A0_1510, "PlayerCarry")
end
function ArkNpc.OnNpcStunned(A0_1511)
  BroadcastEvent(A0_1511, "Stunned")
end
function ArkNpc.Event_Sleep(A0_1512, A1_1513)
  A0_1512.arknpc:GoToSleep()
  BroadcastEvent(A0_1512, "Sleep")
end
function ArkNpc.Event_UseAlternateMessage(A0_1514, A1_1515, A2_1516)
  A0_1514.alternateDisplayText = A2_1516
end
function ArkNpc.Event_UseDefaultMessage(A0_1517)
  local L1_1518
  A0_1517.alternateDisplayText = false
end
function ArkNpc.OnKineticBacklashSignal(A0_1519, A1_1520, A2_1521, A3_1522, A4_1523)
  A0_1519.arknpc:StartCharacterEffect(CHARACTEREFFECTTYPE_KINETICBACKLASHED)
  A0_1519.nBacklashedTimerId = Script.SetTimerForFunction(1000, "ArkNpc.EndKineticBacklashEffectTimer", A0_1519)
end
function ArkNpc.EndKineticBacklashEffectTimer(A0_1524)
  A0_1524.nBacklashedTimerId = -1
  A0_1524.arknpc:StopCharacterEffect(CHARACTEREFFECTTYPE_KINETICBACKLASHED)
end
function ArkNpc.OnDeathCustom(A0_1525, A1_1526)
  local L2_1527
  L2_1527 = A0_1525.Properties
  L2_1527 = L2_1527.ArkDeathInfo
  if L2_1527.particleeffect_CameraEffect ~= "" and randomF(0, 1) < L2_1527.fCameraEffectChance and DistanceSqVectors(A0_1525:GetWorldPos(), g_localActor:GetWorldPos()) <= sqr(L2_1527.fDistToPlayerForCameraEffect) then
    Particle.SpawnEffect(L2_1527.particleeffect_CameraEffect, g_Vectors.v000, g_Vectors.v000, 1)
  end
end
ArkNpc.FlowEvents = {
  Inputs = {
    UseAlternateMessage = {
      ArkNpc.Event_UseAlternateMessage,
      "string"
    },
    UseDefaultMessage = {
      ArkNpc.Event_UseDefaultMessage,
      "bool"
    },
    Sleep = {
      ArkNpc.Event_Sleep,
      "bool"
    }
  },
  Outputs = {
    OnOpen = "bool",
    ReachedPatrolIdx = "int",
    OnCarry = "bool",
    OnGlooed = "bool"
  }
}
