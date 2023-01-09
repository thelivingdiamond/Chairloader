Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkApexTentacle = {
  Properties = {
    object_Model = "",
    metaTags_ArkMetaTags = "",
    faction_ArkFaction = "17591291352619661944",
    scanningDisplayName = "@npc_apextentacle",
    sJointPrefix = "tentacle",
    signalpackage_Hazard = "10641886185795233761",
    nPlayerDamageTick = 100,
    bDisallowGrenades = true,
    anim_IdleAnimation = "Idle_A",
    sHeadAttachmentName = "head",
    Damaged = {
      signalGroup_Damaged = "3149325216949251681",
      fDamageCostPerSegment = 50,
      fDamageBleed = 20,
      nStunDuration = 1000,
      signalGroup_Stunned = "",
      signalmodifier_DefaultModifier = "3149325216954238976"
    },
    Dissipation = {
      nTimeUntilDissipation = 1500,
      nDissipationVariation = 250,
      fMinSpeed = 0.2,
      particleeffect_DissipationVFX = "Characters.Aliens.Apex.Tentacle.Dissipate_00",
      materialanimations_DissipationMaterialAnim = ""
    },
    Movement = {
      fSpeed = 1,
      fMaxTurnRadius = 90,
      fHeadMaxTurnAngle = 45,
      nMinMovementNoisePeriod = 3000,
      nMaxMovementNoisePeriod = 10000,
      fMovementNoiseMinTargetDist = 2,
      nMovementRollPeriod = 2000,
      fMovementRollDegree = 90
    },
    Retract = {
      fRetractSpeed = 3,
      nTargetChangeRetractSegments = 3,
      nMinSegmentsToRetract = 2,
      fMinAdjustDistForRetract = 3,
      nPickClosestSegmentFrequency = 250
    },
    Size = {
      fSegmentLength = 0.75,
      nMaxNumSegments = 30,
      nDefaultTargetNumSegments = 8,
      fTentacleRadius = 1
    },
    Sound = {
      audioTrigger_Exist = "",
      audioTrigger_Damage = "",
      audioTrigger_Dissipation = "",
      audioTrigger_TargetChange = ""
    },
    Strike = {
      fStrikeRange = 3,
      fStrikeSpeed = 3.5,
      fStrikeRetractDist = 2
    },
    TargetAcquisition = {
      fPerceptionRange = 15,
      nTargetLockDuration = 200,
      nInvalidTargetDelay = 2000,
      nRevertToDefaultDuration = 5000,
      fSpeedThreshold = 2,
      signal_LureSignal = "10641886185830929654"
    },
    Physics = {
      bPhysicalize = 1,
      bRigidBody = 0,
      bPushableByPlayers = 0,
      bPushableByAI = 0,
      bResting = 1,
      bRigidBodyActive = 1,
      Density = -1,
      Mass = -1
    },
    Silhouette = {
      color_RGB = {
        x = 1,
        y = 1,
        z = 1
      },
      fAlpha = 0.25
    }
  },
  Editor = {Icon = "Hazard.bmp", IconOnTop = 1},
  PropertiesInstance = {
    bVerbose = 0,
    vector_DefaultTarget = {
      x = 0,
      y = 0,
      z = 0
    }
  }
}
GetArkEntityUtils(ArkApexTentacle)
SetupCollisionFiltering(ArkApexTentacle)
function ArkApexTentacle.Init(A0_3448, A1_3449)
end
function ArkApexTentacle.SetFromProperties(A0_3450)
  Ark.RemoveInboundSignalModifier(A0_3450.id, A0_3450.Properties.Damaged.signalmodifier_DefaultModifier)
  Ark.AttachInboundSignalModifier(A0_3450.id, A0_3450.Properties.Damaged.signalmodifier_DefaultModifier)
end
function ArkApexTentacle.OnReset(A0_3451, A1_3452)
  A0_3451:SetFromProperties()
end
function ArkApexTentacle.OnSpawn(A0_3453)
  A0_3453:SetFromProperties()
end
