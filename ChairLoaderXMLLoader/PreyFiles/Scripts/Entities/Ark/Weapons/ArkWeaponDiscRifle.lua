Script.ReloadScript("Scripts/Entities/Ark/Pickups/ArkItem.lua")
ArkWeaponDiscRifle = {
  Properties = {
    object_GeometryFP = "Objects/weapons/Shotgun/1P/Shotgun1P.cdf",
    object_GeometryTP = "Objects/weapons/Shotgun/3P/shotgun3p_01.cgf",
    bEquippable = 1,
    fLerpSpeed = 10,
    Weapon = {
      playerImpulse = 0,
      fAmmoLootImpulse = 1,
      recoilPitchMin = 0,
      recoilPitchMax = 0,
      recoilYawMin = 0,
      recoilYawMax = 0,
      recoilDuration = 0,
      recoilDelay = 0,
      anim_Animation = "Animations/Mannequin/ADB/ArkWeaponShotgun1P.adb",
      sAnimTag = "shotgun",
      sAttachmentName = "weapon",
      archetype_ammo = "ArkProjectileDiscRifle",
      sAmmoSpawnPointName = "muzzle",
      fBaseAmmoCost = 1,
      nClipSize = 3,
      fReloadSpeed = 1,
      fRateOfAttack = 1,
      bAutoloadAmmo = 1,
      nNumAmmoReloaded = 1,
      fCriticalShotChance = 0,
      bAffectedByDisruption = 0,
      fCombatFocusAmount = 2,
      fWalkSpeedMultiplier = 1,
      fCameraSpeedMultiplier = 1,
      fZoomedHFOV = 15,
      fZoomTime = 0,
      fZoomedWalkSpeedMultiplier = 0.25,
      fZoomedCameraSpeedMultiplier = 0.25,
      bUsesCrosshairReticle = 0,
      sUIElementName = "DanielleWeaponUI",
      nWeaponUIType = 5,
      fIdleBreakDelayTime = 15,
      fIronsightsTargetWidth = 0,
      fIronsightsTargetDistance = 0,
      fIronsightsTargetSpeed = 0,
      fIronsightsSuccessDistance = 0,
      fIronsightsMaxAngularVelocity = 0,
      fAimAssistRangeMax = 100,
      sLeverageImpulseScaleBaseName = "Leverage Base",
      sLeverageImpulseScale1Name = "Leverage I",
      sLeverageImpulseScale2Name = "Leverage II",
      sLeverageImpulseScale3Name = "Leverage III",
      fLeverage0_ImpulseScale = 1,
      fLeverage1_ImpulseScale = 0,
      fLeverage2_ImpulseScale = 0,
      fLeverage3_ImpulseScale = 0,
      Degradation = {
        fDegradationRate = 1,
        fMalfunctionThreshold = 20,
        fMalfunctionRate = 12.5,
        sBrokenIcon = "",
        audioTrigger_StartMalfunction = "",
        audioTrigger_StopMalfunction = "",
        audioTrigger_Break = "",
        fHazardIconTime = 1,
        bTakeHazardDamage = 1,
        fMinStartCondition = 20,
        fMaxStartCondition = 50
      },
      iDismantleCount = 2,
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
    DiscRifle = {
      fTargetAcquireTime = 2,
      fTargetLockTimeoutTime = 3,
      sCancelHintString = "@ui_Weapon_Cancel",
      sOutOfAmmoString = "@ui_Weapon_Out_Of_Ammo",
      fDialogTimerDuration = 30,
      fDialogTimerVariation = 10
    }
  },
  PropertiesInstance = {nInitialAmmo = 3, fStartingConditionOverride = -1}
}
ArkMakeDerivedEntityOverride(ArkWeaponDiscRifle, ArkItem, true)
