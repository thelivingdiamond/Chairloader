Script.ReloadScript("Scripts/Entities/Ark/Pickups/ArkItem.lua")
ArkWeaponLureGrenade = {
  Properties = {
    object_GeometryFP = "Objects/weapons/AlienLure/1P/AlienLure1P.cdf",
    object_GeometryTP = "Objects/weapons/AlienLure/3P/alienlure3p_01.cgf",
    bEquippable = 1,
    fLerpSpeed = 10,
    textDisplayName = "@i_weaponluregrenade",
    sHUDIcon = "Lures Aliens to Grenade",
    Description = {textFocusDescription = ""},
    Weapon = {
      anim_Animation = "",
      sAnimTag = "lure",
      sAttachmentName = "weapon",
      archetype_ammo = "ArkProjectiles.Charges.Lure",
      sAmmoSpawnPointName = "weapon",
      fAimRange = 3,
      fBaseAmmoCost = 1,
      nClipSize = 1,
      fReloadSpeed = 1,
      fRateOfAttack = 20,
      bAutoloadAmmo = 1,
      nNumAmmoReloaded = 1,
      fCriticalShotChance = 0,
      fWalkSpeedMultiplier = 1,
      fCameraSpeedMultiplier = 0.4,
      fZoomedHFOV = 70,
      fZoomTime = 0.4,
      fZoomedWalkSpeedMultiplier = 0.5,
      fZoomedCameraSpeedMultiplier = 0.5,
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
      tutorial_firstTimePickup = "15373294129886683758",
      tutorial_weaponCard = "",
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
    Grenade = {
      fProximityRange = 1.25,
      signalpackage_ProximityPlacedPackageId = "2524450536727669218",
      fMinSpeed = 10,
      fMaxSpeed = 45,
      fAttachDistance = 0.07,
      fMaxHoldTime = 3,
      sCancelHintString = "@ui_Weapon_Cancel",
      sDeployHintString = "@ui_NagPlaceCharge"
    }
  }
}
ArkMakeDerivedEntityOverride(ArkWeaponLureGrenade, ArkItem, true)
