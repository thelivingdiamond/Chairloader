Script.ReloadScript("Scripts/Entities/Ark/Pickups/ArkItem.lua")
ArkWeaponWrench = {
  Properties = {
    object_GeometryFP = "Objects/weapons/Wrench/1P/Wrench1P.cdf",
    object_GeometryTP = "Objects/weapons/Wrench/3P/Wrench3P_01.cgf",
    bEquippable = 1,
    fLerpSpeed = 10,
    DmgFactorWhenCollidingAI = 0,
    Description = {
      quickHitBaseKeyword = "",
      quickHitFinalKeyword = "",
      chargedHitBaseKeyword = "",
      chargedHitFinalKeyword = "",
      signal_damageSignal = "",
      textFocusDescription = ""
    },
    Weapon = {
      anim_Animation = "Animations/Mannequin/ADB/ArkWrenchWeapon.adb",
      sAnimTag = "wrench",
      sAttachmentName = "weapon",
      fRateOfAttack = 0,
      fWalkSpeedMultiplier = 1,
      fCameraSpeedMultiplier = 1,
      bAutoloadAmmo = 1,
      nNumAmmoReloaded = 1,
      fBaseAmmoCost = 0,
      nClipSize = 1,
      fZoomedHFOV = 70,
      fZoomTime = 0.4,
      bAffectedByDisruption = 0,
      fCombatFocusAmount = 1,
      fAimRange = 3.25,
      fZoomedWalkSpeedMultiplier = 0.5,
      fZoomedCameraSpeedMultiplier = 0.5,
      fIdleBreakDelayTime = 8,
      fIronsightsTargetWidth = 2,
      fIronsightsTargetDistance = 3,
      fIronsightsTargetSpeed = 10,
      fIronsightsSuccessDistance = 0.1,
      fIronsightsMaxAngularVelocity = 450,
      fAimAssistRangeMax = 20,
      sLeverageImpulseScaleBaseName = "Leverage Base",
      sLeverageImpulseScale1Name = "Leverage I",
      sLeverageImpulseScale2Name = "Leverage II",
      sLeverageImpulseScale3Name = "Leverage III",
      fLeverage0_ImpulseScale = 1,
      fLeverage1_ImpulseScale = 0,
      fLeverage2_ImpulseScale = 0,
      fLeverage3_ImpulseScale = 0,
      sBrokenIcon = "",
      tutorial_firstTimePickup = "",
      tutorial_weaponCard = "",
      metaTags_SneakAttackTargetTags = "9469288860498988665,9469288860498988629,9469288860517748071",
      Light = {
        sLightAttachmentName = "",
        archetype_LightArchetype = "",
        vector_DefaultLightColor = {
          x = 1,
          y = 1,
          z = 1
        },
        vector_DamagedLightColor = {
          x = 1,
          y = 1,
          z = 0
        },
        vector_BrokenLightColor = {
          x = 1,
          y = 0,
          z = 0
        }
      }
    },
    Wrench = {
      maxChargeTime = 1,
      maxChargeDamageBonus = 1,
      timeBeforeShowingCancelPrompt = 0.2,
      rayRange = 2,
      signalpackage_SignalPackageId = "",
      signalPackage_CriticalPackageId = "",
      signalpackage_ChargedPackageId = "",
      signalPackage_ChargedCriticalPackageId = "",
      hitType = "",
      radius = 0.5,
      force = 10,
      hitOffset = 0.7,
      ability_ChainRequirement = "",
      maxForceMassScale = 50,
      speedRangeFactor = 1,
      speedRangeMax = 1,
      fatalityChance = 0.25,
      fallbackSideSwipeLength = 0.2
    }
  }
}
ArkMakeDerivedEntityOverride(ArkWeaponWrench, ArkItem, true)
