Script.ReloadScript("Scripts/Entities/Ark/Pickups/ArkItem.lua")
ArkWeaponDoubleWrench = {
  Properties = {
    object_GeometryFP = "Objects/weapons/Wrench/1P/Wrench1P.cdf",
    object_GeometryTP = "Objects/weapons/Wrench/3P/Wrench3P_01.cgf",
    bEquippable = 1,
    fLerpSpeed = 10,
    DmgFactorWhenCollidingAI = 0,
    Weapon = {
      sAnimTag = "doublewrench",
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
      fCombatFocusAmount = 2,
      fZoomedWalkSpeedMultiplier = 0.5,
      fZoomedCameraSpeedMultiplier = 0.5,
      fIdleBreakDelayTime = 8,
      fIronsightsTargetWidth = 2,
      fIronsightsTargetDistance = 3,
      fIronsightsTargetSpeed = 10,
      fIronsightsSuccessDistance = 0.1,
      fIronsightsMaxAngularVelocity = 450,
      fAimAssistRangeMax = 20,
      sBrokenIcon = "",
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
      range = 2,
      rayRange = 2,
      signalpackage_SignalPackageId = "10641886185795235646",
      signalPackage_CriticalPackageId = "3149325216940338584",
      signalpackage_ChargedPackageId = "10641886185795235646",
      signalPackage_ChargedCriticalPackageId = "3149325216940338584",
      damage = 2000,
      hitType = "ArkProjectileShotgunShell",
      radius = 0.5,
      force = 10,
      hitOffset = 0.7,
      ability_ChainRequirement = "",
      maxForceMassScale = 50,
      speedRangeFactor = 1,
      speedRangeMax = 1
    }
  },
  PropertiesInstance = {fConditionPercent = 100}
}
ArkMakeDerivedEntityOverride(ArkWeaponDoubleWrench, ArkItem, true)
