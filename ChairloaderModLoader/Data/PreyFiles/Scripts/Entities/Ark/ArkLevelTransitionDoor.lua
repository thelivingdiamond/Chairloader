Script.ReloadScript("Scripts/ArkEntityUtils.lua")
ArkLevelTransitionDoor = {
  Properties = {
    object_Model = "",
    object_Screen = "",
    sScreenBoneName = "",
    sUIElementName = "",
    nSubMatIndex = 0,
    fInteractDistance = 2,
    fActiveDistance = 1,
    fInteractAngle = 75,
    nMessageDelay = 1000,
    textConfirmLabelPrefix = "",
    textConfirmQuery = "",
    textPromptUseMessage = "@use_object",
    ei_ObjectMapIcon = "",
    bShowUnderFog = true,
    postEffect_DialogPostEffect = "9805661808544907835",
    Materials = {
      material_LockedMaterial = "",
      material_UnlockedMaterial = "",
      material_PowerOffMaterial = ""
    },
    Physics = {
      bPhysicalize = 1,
      bRigidBody = 0,
      bPushableByPlayers = 0,
      bPushableByAI = 0,
      Density = -1,
      Mass = -1
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
    }
  },
  Editor = {
    Icon = "physicsobject.bmp",
    IconOnTop = 0,
    IsScalable = false
  },
  PropertiesInstance = {
    location_Destination = "",
    keycard_UnlockKeycard = "",
    bVerbose = 0,
    bStartsLocked = 0,
    bMovePlayerOnExamine = 1,
    bStartsInaccessible = 0,
    textInaccessibleText = ""
  }
}
GetArkEntityUtils(ArkLevelTransitionDoor)
function ArkLevelTransitionDoor.SetFromProperties(A0_4218)
  local L1_4219
end
function ArkLevelTransitionDoor.Init(A0_4220, A1_4221)
end
function ArkLevelTransitionDoor.OnReset(A0_4222)
  local L1_4223
end
function ArkLevelTransitionDoor.OnSpawn(A0_4224)
  local L1_4225
end
function ArkLevelTransitionDoor.OnDestroy(A0_4226)
  local L1_4227
end
function ArkLevelTransitionDoor.Event_SetStateInaccessibleOn(A0_4228)
  Ark.SetLevelTransitionDoorInaccessible(A0_4228.id, true)
end
function ArkLevelTransitionDoor.Event_SetStateInaccessibleOff(A0_4229)
  Ark.SetLevelTransitionDoorInaccessible(A0_4229.id, false)
end
function ArkLevelTransitionDoor.Event_SetTextInaccessible(A0_4230, A1_4231, A2_4232)
  Ark.SetLevelTransitionDoorInaccessibleText(A0_4230.id, A2_4232)
end
function ArkLevelTransitionDoor.Event_Lock(A0_4233)
  Ark.SetKeyUILocked(A0_4233.id, true)
end
function ArkLevelTransitionDoor.Event_Unlock(A0_4234)
  Ark.SetKeyUILocked(A0_4234.id, false)
end
ArkLevelTransitionDoor.FlowEvents = {
  Inputs = {
    SetStateInaccessibleOn = {
      ArkLevelTransitionDoor.Event_SetStateInaccessibleOn,
      "bool"
    },
    SetStateInaccessibleOff = {
      ArkLevelTransitionDoor.Event_SetStateInaccessibleOff,
      "bool"
    },
    SetTextInaccessible = {
      ArkLevelTransitionDoor.Event_SetTextInaccessible,
      "string"
    },
    Lock = {
      ArkLevelTransitionDoor.Event_Lock,
      "bool"
    },
    Unlock = {
      ArkLevelTransitionDoor.Event_Unlock,
      "bool"
    }
  },
  Outputs = {
    Cancelled = "bool",
    Confirmed = "bool",
    Used = "bool",
    Locked = "bool",
    Unlocked = "bool",
    Inaccessible = "bool"
  }
}
