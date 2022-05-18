Script.ReloadScript("scripts/ArkEntityUtils.lua")
Script.ReloadScript("scripts/Entities/Ark/ArkBasicEntity.lua")
ArkKeycardReader = {
  Properties = {
    object_Model = "",
    object_Screen = "",
    sUIElementName = "",
    nSubMatIndex = 0,
    sScreenBoneName = "",
    textMessagePoweredOffMessage = "",
    textPromptUseMessage = "",
    fInteractDistance = 1,
    fActiveDistance = 1,
    fInteractAngle = 75,
    bDisallowGrenades = true,
    bEnableCollisionInteraction = 1,
    nMessageDelay = 1000,
    Materials = {
      material_LockedMaterial = "",
      material_UnlockedMaterial = "",
      material_PowerOffMaterial = ""
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
    Physics = {
      bPhysicalize = 1,
      bRigidBody = 1,
      bPushableByPlayers = 1,
      bPushableByAI = 0,
      Density = -1,
      Mass = -1
    }
  },
  Editor = {
    Icon = "Prefab.bmp",
    IconOnTop = 1,
    IsScalable = false
  },
  PropertiesInstance = {
    keycard_UnlockKeycard = "",
    bStartsLocked = 1,
    bUsable = 1,
    bMovePlayerOnExamine = 1
  }
}
GetArkEntityUtils(ArkKeycardReader)
SetupCollisionFiltering(ArkKeycardReader)
function ArkKeycardReader.Init(A0_4095, A1_4096)
end
function ArkKeycardReader.InitDoorAccessController(A0_4097, A1_4098)
  Ark.LinkKeyUIToDoor(A0_4097.id, A1_4098.id)
end
function ArkKeycardReader.SetFromProperties(A0_4099)
  local L1_4100
end
function ArkKeycardReader.Event_Lock(A0_4101)
  Ark.SetKeyUILocked(A0_4101.id, true)
end
function ArkKeycardReader.Event_Unlock(A0_4102)
  Ark.SetKeyUILocked(A0_4102.id, false)
end
function ArkKeycardReader.Event_PowerOn(A0_4103)
  Ark.SetKeyUIPowered(A0_4103.id, true)
end
function ArkKeycardReader.Event_PowerOff(A0_4104)
  Ark.SetKeyUIPowered(A0_4104.id, false)
end
function ArkKeycardReader.OnReset(A0_4105)
  local L1_4106
end
function ArkKeycardReader.OnSpawn(A0_4107)
  A0_4107:Log("OnSpawn")
end
ArkKeycardReader.FlowEvents = {
  Inputs = {
    Lock = {
      ArkKeycardReader.Event_Lock,
      "bool"
    },
    Unlock = {
      ArkKeycardReader.Event_Unlock,
      "bool"
    }
  },
  Outputs = {
    Used = "bool",
    Locked = "bool",
    Unlocked = "bool",
    Failed = "bool"
  }
}
