Script.ReloadScript("Scripts/Entities/Ark/Pickups/ArkItem.lua")
ArkWeaponGooGun = {
  Properties = {
    object_GeometryFP = "Objects/weapons/GooGun/1p/GooGun1p.cdf",
    object_GeometryTP = "Objects/weapons/GooGun/3p/googun3p_01.cgf",
    bEquippable = 1,
    fLerpSpeed = 10,
    DmgFactorWhenCollidingAI = 0,
    Description = {
      baseDamageKeyword = "",
      finalDamageKeyword = "",
      signal_damageSignal = ""
    },
    Weapon = {
      playerImpulse = 1,
      playerImpulseZeroG = 1,
      fAmmoLootImpulse = 1,
      recoilPitchMin = 0,
      recoilPitchMax = 0,
      recoilYawMin = 0,
      recoilYawMax = 0,
      recoilDuration = 0,
      recoilDelay = 0,
      anim_Animation = "Animations/Mannequin/ADB/ArkGooGunWeaponAnims.adb",
      sAnimTag = "goo",
      sAttachmentName = "weapon",
      archetype_ammo = "ArkProjectiles.Gloo.GlooShot",
      sAmmoSpawnPointName = "muzzle",
      fAimRange = 15,
      fBaseAmmoCost = 10,
      nClipSize = 100,
      fReloadSpeed = 1,
      fRateOfAttack = 2,
      bAutoloadAmmo = 1,
      nNumAmmoReloaded = 100,
      nInitialAmmoMin = 0,
      nInitialAmmoMax = 100,
      fSpawnFromCameraTestDistance = 1.5,
      fSpawnBehindCameraDistance = 0.3,
      fCriticalShotChance = 0,
      bAffectedByDisruption = 0,
      fCombatFocusAmount = 0.5,
      fWalkSpeedMultiplier = 1,
      fCameraSpeedMultiplier = 0.4,
      fZoomedHFOV = 70,
      fZoomTime = 0.4,
      fZoomedWalkSpeedMultiplier = 0.5,
      fZoomedCameraSpeedMultiplier = 0.5,
      sUIElementName = "DanielleWeaponUI",
      nWeaponUIType = 3,
      fIdleBreakDelayTime = 8,
      fIronsightsTargetWidth = 0.5,
      fIronsightsTargetDistance = 5,
      fIronsightsTargetSpeed = 5,
      fAimAssistRangeMax = 20,
      sLeverageImpulseScaleBaseName = "Leverage Base",
      sLeverageImpulseScale1Name = "Leverage I",
      sLeverageImpulseScale2Name = "Leverage II",
      sLeverageImpulseScale3Name = "Leverage III",
      fLeverage0_ImpulseScale = 0,
      fLeverage1_ImpulseScale = 0,
      fLeverage2_ImpulseScale = 0,
      fLeverage3_ImpulseScale = 0,
      Degradation = {
        fDegradationRate = 1,
        fMalfunctionThreshold = 20,
        fMalfunctionRate = 12.5,
        sBrokenIcon = "",
        sBrokenHUDIcon = "",
        audioTrigger_StartMalfunction = "",
        audioTrigger_StopMalfunction = "",
        audioTrigger_Break = "",
        fHazardIconTime = 1,
        bTakeHazardDamage = 1,
        fMinStartCondition = 20,
        fMaxStartCondition = 50
      },
      tutorial_firstTimePickup = "",
      tutorial_weaponCard = "",
      sUpgradeInfoDesc = "@ui_LabtechRequired",
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
    GooGun = {
      fZeroGravityTime = 0.25,
      nDisruptSubMaterial = 1,
      fDisruptMaxEmittance = 10
    }
  },
  PropertiesInstance = {iInitialAmmo = 42, fStartingConditionOverride = -1}
}
ArkMakeDerivedEntityOverride(ArkWeaponGooGun, ArkItem, true)
