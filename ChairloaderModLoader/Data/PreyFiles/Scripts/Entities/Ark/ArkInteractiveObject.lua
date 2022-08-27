Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkInteractiveObject = {
  Properties = {
    bUseSafeCarry = false,
    carryHeightOffset = 0,
    carryForwardOffset = 0,
    object_Model = "",
    textDisplayName = "",
    textUseMessage = "",
    textActiveUseMessage = "",
    fDuration = 1,
    bDisableOnUse = 0,
    material_DisabledMaterial = "",
    material_EnabledMaterial = "",
    fVfxScale = 1,
    fVfxPulsePeriod = 1,
    sVfxBoneName = "",
    bCollisionInteraction = 0,
    bDisallowGrenades = false,
    vector_vfxOffset = {
      x = 0,
      y = 0,
      z = 0
    },
    vector_vfxDirInDegrees = {
      x = 0,
      y = 0,
      z = 0
    },
    ability_CarryRequirement = "",
    bIsMimicable = 0,
    bInteractLOSToParent = 1,
    glintconfig_GlintConfig = "13856881013222815427",
    RecycleData = {
      organic = 0,
      mineral = 0,
      synthetic = 0,
      exotic = 0
    },
    Glow = {
      sSkinAttachmentName = "",
      color_EnabledColor = {
        x = 1,
        y = 0,
        z = 0
      },
      color_DisabledColor = {
        x = 1,
        y = 1,
        z = 1
      },
      fEnabledGlowAmount = 1,
      fDisabledGlowAmount = 0,
      nGlowSubmatIdA = 0,
      bUseGlow = 0
    },
    MissionReward = {
      gametokenid_IsPsiAddedToWater = "",
      bIsWaterSource = 0,
      signalPackage_PsiRewardOnUse = "",
      signalPackage_HealthOnUse = ""
    },
    Animation = {anim_Activated = "", anim_Deactivated = ""},
    Effects = {particleeffect_Activated = ""},
    GameNoise = {gameNoiseLoudness_GameNoiseLoudness = "", gameNoiseType_GameNoiseType = ""},
    Sound = {
      audioTrigger_Start = "",
      audioTrigger_Stop = "",
      audioTrigger_Carry = "",
      audioTrigger_HoldCarryStart = "",
      audioTrigger_HoldCarryCancel = ""
    },
    Disrupt = {
      disruptionProfile_Profile = "10739735956140212131",
      particleeffect_SparkVFX = "",
      audioTrigger_SparkSFX = ""
    },
    Physics = {
      bPhysicalize = 1,
      bRigidBody = 0,
      bPushableByPlayers = 0,
      bPushableByAI = 0,
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
  Editor = {
    Icon = "switch.bmp",
    IconOnTop = 1,
    IsScalable = false
  },
  PropertiesInstance = {
    bVerbose = 0,
    bPreviewVfx = 0,
    bStartsActive = 0,
    bStartsDisabled = 0
  }
}
GetArkEntityUtils(ArkInteractiveObject)
SetupCollisionFiltering(ArkInteractiveObject)
function ArkInteractiveObject.Init(A0_4077, A1_4078)
end
function ArkInteractiveObject.InitDoorAccessController(A0_4079, A1_4080)
  Ark.LinkInteractiveObjectToDoor(A0_4079.id, A1_4080.id)
end
function ArkInteractiveObject.SetFromProperties(A0_4081)
  local L1_4082
end
function ArkInteractiveObject.OnSpawn(A0_4083)
  local L1_4084
end
function ArkInteractiveObject.OnReset(A0_4085)
  local L1_4086
end
function ArkInteractiveObject.Event_Activate(A0_4087)
  Ark.ActivateInteractiveObject(A0_4087.id, true)
end
function ArkInteractiveObject.Event_Deactivate(A0_4088)
  Ark.ActivateInteractiveObject(A0_4088.id, false)
end
function ArkInteractiveObject.Event_Enable(A0_4089)
  Ark.DisableInteractiveObject(A0_4089.id, false)
end
function ArkInteractiveObject.Event_Disable(A0_4090)
  Ark.DisableInteractiveObject(A0_4090.id, true)
end
function ArkInteractiveObject.Event_PowerOn(A0_4091)
  A0_4091:Event_Enable()
end
function ArkInteractiveObject.Event_PowerOff(A0_4092)
  A0_4092:Event_Disable()
end
function ArkInteractiveObject.Event_EnableGlint(A0_4093)
  Ark.SetShouldGlint(A0_4093.id, true)
end
function ArkInteractiveObject.Event_DisableGlint(A0_4094)
  Ark.SetShouldGlint(A0_4094.id, false)
end
ArkInteractiveObject.FlowEvents = {
  Inputs = {
    Activate = {
      ArkInteractiveObject.Event_Activate,
      "bool"
    },
    Deactivate = {
      ArkInteractiveObject.Event_Deactivate,
      "bool"
    },
    Enable = {
      ArkInteractiveObject.Event_Enable,
      "bool"
    },
    Disable = {
      ArkInteractiveObject.Event_Disable,
      "bool"
    },
    EnableGlint = {
      ArkInteractiveObject.Event_EnableGlint,
      "bool"
    },
    DisableGlint = {
      ArkInteractiveObject.Event_DisableGlint,
      "bool"
    }
  },
  Outputs = {
    Activated = "bool",
    Deactivated = "bool",
    Enabled = "bool",
    Disabled = "bool"
  }
}
