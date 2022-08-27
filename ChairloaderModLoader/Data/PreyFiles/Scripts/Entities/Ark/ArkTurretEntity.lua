Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkTurret = {
  Properties = {
    bUseSafeCarry = true,
    carryHeightOffset = 0,
    type = "ArkTurretEntity",
    scanningDisplayName = "@npc_turret",
    textDisplayName = "@npc_turret",
    textCorpseName = "@npc_destroyed",
    gibalYawJointName = "gimbal",
    gibalPitchJointName = "gimbal",
    barrelEndJointName = "barrel_end",
    barrelStartJointName = "turret_stock",
    metaTags_ArkMetaTags = "9469288860498988699",
    signalmodifier_technoControlled = "3149325216954609881",
    signalmodifier_default = "0",
    signalpackage_collisionDamagePackage = "3149325216931792051",
    aliveSkin = "skin",
    destroyedSkin = "damaged_skin",
    fHealth = 100,
    fMaxPitchVelocity = 150,
    fMaxYawVelocity = 200,
    fPitchAcceleration = 50,
    fYawAcceleration = 80,
    fPitchLowerLimit = 10,
    fPitchUpperLimit = 60,
    fYawLimit = 45,
    fVelocityDamp = 0.997,
    fAcquiredLineOfSightDuration = 0,
    fLostLineOfSightDuration = 0,
    canDeployBoundingSize = {
      x = 0.25,
      y = 0.75,
      z = 1.25
    },
    fDeadCarryHoldUseDuration = 0.5,
    fDeployHoldUseDuration = 1,
    DialogNonHostileApproachDistance = 5,
    PlayerLoiterDistance = 5,
    PlayerLoiterCD = 10,
    fBrokenRepeatDialogCD = 10,
    fBrokenFlickerDuration = 5,
    ability_HackRequirement = "",
    ability_CarryRequirement = "",
    signalGroup_Damage = "3149325216937655803",
    signalGroup_Stun = "2524450536722832464",
    signalGroup_Electric = "",
    signal_mindControlSignal = "10641886185795236267",
    signal_glooSignal = "3149325216915549017",
    gameNoiseType_callForHelpGameNoiseType = "10850392949532183295",
    gameNoiseLoudness_callForHelpLoudness = "10850392949532183296",
    loottable_ContainerLootTable = "",
    shieldJointName = "",
    shieldDamageScale = 0,
    viewAttachmentName = "viewattachment",
    carryDirection = {
      x = 0,
      y = 1,
      z = 0
    },
    vector_ThrowAngularImpulse = {
      x = -10,
      y = 0,
      z = 0
    },
    ei_TransparencyMode = 2,
    sHUDIcon = "",
    AI = {bUsedAsDynamicObstacle = 1},
    RecycleData = {
      organic = 0,
      mineral = 0,
      synthetic = 0,
      exotic = 0
    },
    bCanTriggerAreas = 1,
    ArkAttention = {
      attentionModel_AttentionModel = "1",
      visionCone_VisionCone = "0",
      visionCone_SecondaryVisionCone = "0"
    },
    ArkMindControl = {
      attachmenteffects_MindControlEffects = "12635110349635930688"
    },
    Light = {
      archetype_lightFriendly = "",
      archetype_lightHostile = "",
      archetype_lightHacked = "",
      ArkLightAttachmentName = "LightAttachment",
      fFlickerToggleMaxDuration = 0.15,
      fTalkMinBrightness = 0.6,
      fTalkMaxBrightness = 0.9
    },
    OnElectrocuted = {attachmenteffects_OnElectrocutedEffects = ""},
    OnFire = {attachmenteffects_OnFireEffects = ""},
    OnStun = {attachmenteffects_OnStunEffects = ""},
    attachmenteffects_LifetimeEffects = "",
    Sound = {
      audioTrigger_Carry = "",
      audioTrigger_Detect = "Sounds/Ark_Incubation:Turret:Turret_Detect",
      audioTrigger_LostTarget = "",
      audioTrigger_Destroy = "Sounds/Ark_Incubation:Turret:Turret_Destroyed",
      audioTrigger_Fire = "Sounds/Ark_Incubation:Turret:Turret_Fire",
      audioTrigger_GooStuck = "",
      audioTrigger_RepairLoop = "",
      audioTrigger_RepairStop = "",
      audioTrigger_FortifyLoop = "",
      audioTrigger_FortifyStop = "",
      audioTrigger_DamagedStart = "",
      audioTrigger_DamagedStop = "",
      audioTrigger_DisabledStart = "",
      audioTrigger_DisabledStopRepaired = "",
      audioTrigger_DisabledStopDestroyed = "",
      audioTrigger_StunnedStart = "",
      audioTrigger_StunnedStop = ""
    },
    Physics = {
      bPhysicalize = 1,
      bRigidBody = 1,
      bPushableByPlayers = 1,
      bPushableByAI = 1,
      bResting = 1,
      bRigidBodyActive = 0,
      Density = -1,
      Mass = 80
    },
    Silhouette = {
      color_RGB = {
        x = 1,
        y = 1,
        z = 1
      },
      fAlpha = 0.25
    },
    ArkCharacter = {character_Character = "0"},
    ArkDialog = {playerBumpCD = 5},
    ArkFaction = {
      faction_DefaultFaction = "17591291352618367179",
      faction_PlayerControlledFaction = "17591291352646192141",
      faction_HackedFaction = "17591291352646192141"
    },
    ArkModel = {
      model_DefaultTurretModel = "objects/characters/Robots/Turret/Turret.cdf",
      model_DestroyedTurretModel = "objects/characters/Robots/Turret/TurretDestroyed.cdf"
    },
    ArkTurretWeapon = {
      archetype_ammoType = "ArkProjectiles.Bullets.TurretRound_Default",
      itemarchetype_LootAmmoLaser = "",
      itemarchetype_LootAmmoStun = "",
      fBulletSpeed = 150,
      fTimeTillBulletsPerSecMax = 3,
      fBulletsPerSecondMin = 2,
      fBulletsPerSecondMax = 12,
      fMissSpreadMinDegrees = 15,
      fMissSpreadMaxDegrees = 45,
      fPercentagePlayerHitMin = 0.1,
      fPercentagePlayerHitMax = 0.5,
      fDistanceForMinHitChance = 20,
      fDistanceForMaxHitChance = 0,
      Burst = {
        bBurstModeEnabled = 0,
        iNumBulletsPerBurst = 10,
        fBurstCooldownSeconds = 10
      },
      MuzzleFlash = {
        effect = "Characters.Robots.Turret.Main",
        fScale = 1
      },
      CinematicMissing = {
        fTargetPredictionMissing = 1,
        PlayerViewTowards = {
          fDegreesConsideredTowards = 110,
          vecOffsetFromCamera = {
            x = 0,
            y = 0,
            z = -0.5
          }
        },
        PlayerViewSide = {
          fDegreesConsideredSide = 200,
          vecOffsetFromCamera = {
            x = 0,
            y = 1.5,
            z = -0.5
          }
        },
        PlayerViewAway = {
          vecOffsetFromCamera = {
            x = 0,
            y = 0,
            z = -0.5
          }
        }
      }
    },
    ArkTurretWeaponTechnoControlled = {
      fMissSpreadMinDegrees = 15,
      fMissSpreadMaxDegrees = 45,
      fPercentagePlayerHitMin = 0.1,
      fPercentagePlayerHitMax = 0.5,
      fDistanceForMinHitChance = 20,
      fDistanceForMaxHitChance = 0
    },
    Mannequin = {
      fileControllerDef = "Animations/Mannequin/ADB/ArkTurretEntityControllerDefs.xml",
      fileAnimationDatabase = "Animations/Mannequin/ADB/ArkTurretEntity.adb"
    },
    Behavior = {
      fAmberBlockDuration = 5,
      fUprightToFallenDelaySeconds = 1,
      fFallenActivePysicsTime = 2,
      fFallenToUprightDelaySeconds = 1,
      fStunnedDuration = 15,
      Attacking = {fLostLOSDelay = 2, fCallForHelpPulseTime = 2},
      Searching = {fSearchAnimDelayTimeMin = 1, fSearchAnimDelayTimeMax = 7},
      Spazzing = {
        fSpazOutTimeSeconds = 5,
        fSpazRotateUpdateTimer = 0.25,
        fSpazNoShootingDelayForSpazzing = 1
      }
    },
    DamageStates = {
      HealthThresholdDamaged = 1250,
      HealthThresholdDisabled = 300,
      AttachmentNameUndamaged = "skin",
      AttachmentNameDamaged = "damaged_skin",
      AttachmentNameDisabled = "broken_skin",
      attachmenteffects_OnDamagedEffects = "17591291352643607050",
      attachmenteffects_OnDisabledEffects = "17591291352643607091",
      attachmenteffects_OnDestroyedEffects = "17591291352643607109"
    },
    Repair = {
      nHoldToUseDuration = 1000,
      archetype_RepairItem = "",
      ability_RepairRequirement = "3149325216929347161",
      nSparePartsRequired = 0,
      textDisplayNameBroken = "@i_brokenturret",
      bRepairable = 1,
      fRepairIconRange = 10
    },
    Fortify = {
      nHoldToUseDuration = 1000,
      archetype_FortifyItem = "",
      ability_FortifyRequirement = "3149325216929347161",
      nSparePartsRequired = 0,
      bFortifiable = 1,
      fHealthIncrease = 1000
    },
    ArkInteractMessages = {
      textAliveInteractText = "@use_npc",
      textDeadInteractText = "@use_search",
      textDeployInteractText = "",
      textLootInteractText = "",
      textCantDeployInteractText = "@ui_no_room_deploy"
    },
    ArkGooed = {
      attachment_GlooSkinAttachment = "fx_goo01",
      animation_GlooGrowAnimation = "goo",
      glooSlowFadeDuration = 1,
      glooSlowDuration = 1.5,
      glooHardenDuration = 0.75,
      glooFrozenDuration = 10,
      glooOnHitCooldown = 0.15,
      particleeffect_BreakGlooEffect = "Characters.Aliens.Generic.Goo.GooBreak_00",
      particleeffect_OnHitGlooEffect = "Characters.Aliens.Generic.Goo.GooHit_00",
      audioTrigger_glooBreakSFX = "",
      audioTrigger_glooStartSFX = "",
      audioTrigger_glooHardenSFX = ""
    },
    ArkFalling = {
      signalpackage_damagePackageId = "3149325216943200410",
      fMinDistanceForDamage = 5,
      fMinSpeedForFalling = 5,
      fFallingDamagePerMeter = 25
    },
    ZeroG = {visionCone_VisionCone = "0"}
  },
  States = {"Normal", "Hacking"},
  PropertiesInstance = {
    bStartsActive = 1,
    bStartsBroken = 0,
    bStartsInPickupMode = 0,
    bUsedAsDynamicObstacle = 1,
    ability_HackRequirementOverride = ""
  },
  Editor = {
    Icon = "User.bmp",
    ShowBounds = 1,
    IsScalable = false,
    IsRotatable = true
  }
}
GetArkEntityUtils(ArkTurret)
ArkMakeHackable(ArkTurret)
SetupCollisionFiltering(ArkTurret)
function ArkTurret.OnReset(A0_4649)
  A0_4649:GotoState("Normal")
  A0_4649:UpdateDisplayName()
end
function ArkTurret.OnInit(A0_4650)
  if A0_4650.Properties.bCanTriggerAreas == 1 then
    A0_4650:SetFlags(ENTITY_FLAG_TRIGGER_AREAS, 0)
  else
    A0_4650:SetFlags(ENTITY_FLAG_TRIGGER_AREAS, 2)
  end
  A0_4650:UpdateDisplayName()
end
function ArkTurret.OnKilled(A0_4651)
  Ark.SpawnLootFromTable(A0_4651.Properties.loottable_ContainerLootTable, A0_4651.id)
  BroadcastEvent(A0_4651, "Died")
end
function ArkTurret.OnBroken(A0_4652)
  BroadcastEvent(A0_4652, "Broken")
end
function ArkTurret.OnStartBeingCarried(A0_4653)
  A0_4653.arkturret:StartBeingCarried()
end
function ArkTurret.OnStopBeingCarried(A0_4654)
  A0_4654.arkturret:StopBeingCarried()
end
function ArkTurret.OnLoot(A0_4655, A1_4656)
end
function ArkTurret.SpawnedByFabricator(A0_4657)
  A0_4657.arkturret:SpawnedByFabricator()
end
function ArkTurret.HackSuccess(A0_4658)
  BroadcastEvent(A0_4658, "HackSucceed")
  A0_4658:UpdateDisplayName()
end
function ArkTurret.HackFail(A0_4659)
  BroadcastEvent(A0_4659, "HackFailed")
end
function ArkTurret.UpdateDisplayName(A0_4660)
  local L1_4661
  L1_4661 = A0_4660.Properties
  L1_4661 = L1_4661.textDisplayName
  A0_4660:SetDisplayName(L1_4661)
end
function ArkTurret.OnSpawn(A0_4662)
  A0_4662:UpdateDisplayName()
end
function ArkTurret.Event_Activate(A0_4663)
  BroadcastEvent(A0_4663, "Activate")
end
function ArkTurret.Event_Deactivate(A0_4664)
  BroadcastEvent(A0_4664, "DeActivate")
end
function ArkTurret.Event_StartFire(A0_4665)
  BroadcastEvent(A0_4665, "StartFire")
end
function ArkTurret.Event_StopFire(A0_4666)
  BroadcastEvent(A0_4666, "StopFire")
end
function ArkTurret.Event_Destroy(A0_4667)
  BroadcastEvent(A0_4667, "Destroy")
end
function ArkTurret.Event_Reset(A0_4668)
  BroadcastEvent(A0_4668, "Reset")
end
ArkTurret.FlowEvents = {
  Inputs = {
    Activate = {
      ArkTurret.Event_Activate,
      "void"
    },
    DeActivate = {
      ArkTurret.Event_Deactivate,
      "void"
    },
    StartFire = {
      ArkTurret.Event_StartFire,
      "void"
    },
    StopFire = {
      ArkTurret.Event_StopFire,
      "void"
    },
    Destroy = {
      ArkTurret.Event_Destroy,
      "void"
    },
    Reset = {
      ArkTurret.Event_Reset,
      "void"
    }
  },
  Outputs = {
    Activated = "bool",
    Died = "bool",
    Hidden = "bool",
    Attacking = "bool",
    Searching = "bool",
    Out = "bool",
    Broken = "bool",
    Repaired = "bool",
    Fortified = "bool"
  }
}
