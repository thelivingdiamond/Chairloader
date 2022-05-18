Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkCargoContainer = {
  Properties = {
    object_Model = "",
    AI = {bUsedAsDynamicObstacle = 0},
    FrontDoor = {
      vector_offsetPosition = {
        x = 0,
        y = 0,
        z = 0
      },
      vector_offsetRotation = {
        x = 0,
        y = 0,
        z = 0
      },
      archetype_DoorArchetype = ""
    },
    BackDoor = {
      vector_offsetPosition = {
        x = 0,
        y = 0,
        z = 0
      },
      vector_offsetRotation = {
        x = 0,
        y = 0,
        z = 0
      },
      archetype_DoorArchetype = ""
    },
    DoorInstanceProperties = {
      nKeypads = 2,
      keycode_UnlockCode = "",
      keycard_UnlockKeycard = "",
      bKeypadsOnLeftSide = 1,
      bUseKeycardReaders = 0,
      bStartsLocked = 1,
      bStartsOpen = 0,
      bUseFreeExitButton = 1,
      bStartsPoweredOn = 1,
      vector_FreeExitOffset = {
        x = 0,
        y = 0,
        z = 0
      }
    },
    Physics = {
      bPhysicalize = 1,
      bRigidBody = 0,
      bPushableByPlayers = 0,
      bPushableByAI = 0,
      Density = -1,
      Mass = -1
    }
  },
  PropertiesInstance = {
    sContainerCode = "",
    bUsedAsDynamicObstacle = 1,
    textConfirmDoorOpenMessage = "",
    seq_SequenceToCargoBay1 = "",
    seq_SequenceToCargoBay2 = "",
    seq_SequenceFromCargoBay1 = "",
    seq_SequenceFromCargoBay2 = ""
  },
  Editor = {
    IsScalable = false,
    Icon = "Prefab.bmp",
    IconOnTop = 0
  }
}
GetArkEntityUtils(ArkCargoContainer)
SetupCollisionFiltering(ArkCargoContainer)
function ArkCargoContainer.Init(A0_3519, A1_3520)
end
function ArkCargoContainer.SetFromProperties(A0_3521)
  local L1_3522
end
function ArkCargoContainer.OnReset(A0_3523)
  local L1_3524
end
function ArkCargoContainer.OnSpawn(A0_3525)
  local L1_3526
end
function ArkCargoContainer.Event_CloseDoors(A0_3527)
  BroadcastEvent(A0_3527, "DoorsClosed")
end
function ArkCargoContainer.Event_OpenDoors(A0_3528)
  BroadcastEvent(A0_3528, "DoorsOpened")
end
function ArkCargoContainer.Event_OverrideOpenDoorConfirmation(A0_3529, A1_3530, A2_3531)
  A0_3529:ActivateOutput("ConfirmationOverridden", A2_3531)
end
ArkCargoContainer.FlowEvents = {
  Inputs = {
    OpenDoors = {
      ArkCargoContainer.Event_OpenDoors,
      "bool"
    },
    CloseDoors = {
      ArkCargoContainer.Event_CloseDoors,
      "bool"
    },
    OverrideOpenDoorConfirmation = {
      ArkCargoContainer.Event_OverrideOpenDoorConfirmation,
      "string"
    }
  },
  Outputs = {
    Opening = "bool",
    Opened = "bool",
    Docking = "bool",
    Docked = "bool",
    Undocking = "bool",
    Undocked = "bool",
    ConfirmationOverridden = "string"
  }
}
