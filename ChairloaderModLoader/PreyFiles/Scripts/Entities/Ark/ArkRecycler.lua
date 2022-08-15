Script.ReloadScript("scripts/ArkEntityUtils.lua")
Script.ReloadScript("scripts/Entities/Ark/ArkBasicEntity.lua")
Script.ReloadScript("Scripts/Entities/Ark/ArkKiosk.lua")
ArkRecycler = {
  Properties = {
    object_Model = "",
    textContainerName = "",
    sSpawnAttachmentName = "",
    sScreenBoneName = "",
    sVfxAttachmentName = "",
    sInteractionAttachmentName = "",
    textPromptUseMessage = "",
    particleeffect_RecycleVFX = "",
    particleeffect_RecyclerFinishedVFX = "Interactables.Recycler.RecyclerOff",
    particleeffect_IdleVFX = "",
    nRecycleDelay = 1000,
    nSpawnInterval = 1000,
    nProcessingInterval = 1000,
    fSpawnImpulseScale = 1,
    ei_ObjectMapIcon = "",
    object_Screen = "",
    sUIElementName = "",
    nSubMatIndex = 0,
    fInteractDistance = 1,
    fActiveDistance = 1,
    fInteractAngle = 75,
    bEnableCollisionInteraction = 1,
    tutorial_ContextualTutorial = "",
    material_ScreensaverMaterial = "",
    material_PowerOffMaterial = "",
    nMaxNumSpawnedEntities = 16,
    fInteractDistanceOverride = -1,
    gameNoiseLoudness_GameNoiseLoudness = "9469288860501649195",
    gameNoiseType_GameNoiseType = "9469288860501998057",
    PercentRecycleRange = {min = 0.9, max = 1},
    Repair = {
      textDisplayNameBroken = "",
      archetype_RepairBox = "",
      sRepairAttachment = ""
    },
    Disrupt = {
      disruptionProfile_Profile = "10739735956140212131",
      particleeffect_SparkVFX = "",
      audioTrigger_SparkSFX = "",
      vector_SparkPosOffset = {
        x = 0,
        y = 0,
        z = 0
      },
      vector_SparkRotOffset = {
        x = 0,
        y = 0,
        z = 0
      }
    },
    Sound = {audioTrigger_RecyclingLP = "", audioTrigger_CompletedSFX = ""},
    Physics = {
      bPhysicalize = 1,
      bRigidBody = 1,
      bPushableByPlayers = 1,
      bPushableByAI = 1,
      Density = -1,
      Mass = -1
    },
    ContainerInfo = {
      es_ContainerSize = "LARGE",
      Animation = {anim_open = "", anim_close = ""},
      Sound = {audioTrigger_Open = "", audioTrigger_Close = ""}
    }
  },
  PropertiesInstance = {
    bUsable = 1,
    bVerbose = 0,
    bStartsPoweredOn = 1,
    bStartsBroken = 0,
    bMovePlayerOnExamine = 1
  },
  Editor = {
    Icon = "Prefab.bmp",
    IconOnTop = 1,
    IsScalable = false
  }
}
GetArkEntityUtils(ArkRecycler)
SetupCollisionFiltering(ArkRecycler)
ArkMakeContainer(ArkRecycler)
function ArkRecycler.SetFromProperties(A0_4464)
  local L1_4465
end
function ArkRecycler.Init(A0_4466, A1_4467)
end
function ArkRecycler.OnSpawn(A0_4468)
  local L1_4469
end
function ArkRecycler.OnReset(A0_4470)
  local L1_4471
end
function ArkRecycler.Event_PowerOn(A0_4472)
  Ark.SetRecyclerPowered(A0_4472.id, true)
end
function ArkRecycler.Event_PowerOff(A0_4473)
  Ark.SetRecyclerPowered(A0_4473.id, false)
end
function ArkRecycler.OnPostLoad(A0_4474)
  local L1_4475
end
ArkRecycler.FlowEvents = {
  Inputs = {
    PowerOn = {
      ArkRecycler.Event_PowerOn,
      "bool"
    },
    PowerOff = {
      ArkRecycler.Event_PowerOff,
      "bool"
    }
  },
  Outputs = {
    OnRecycle = "bool",
    OnOpen = "bool",
    RepairBox = "entity"
  }
}
