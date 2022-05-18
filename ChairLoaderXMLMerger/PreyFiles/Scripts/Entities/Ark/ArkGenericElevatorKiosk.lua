Script.ReloadScript("scripts/ArkEntityUtils.lua")
Script.ReloadScript("scripts/Entities/Ark/ArkBasicEntity.lua")
ArkGenericElevatorKiosk = {
  Properties = {
    object_Model = "",
    object_Screen = "",
    sUIElementName = "",
    nSubMatIndex = 0,
    sScreenBoneName = "",
    fInteractDistance = 1,
    fActiveDistance = 1,
    fInteractAngle = 75,
    bDisallowGrenades = true,
    bEnableCollisionInteraction = 1,
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
    Icon = "Prefab.bmp",
    IconOnTop = 1,
    IsScalable = false
  },
  PropertiesInstance = {bVerbose = 0, bMovePlayerOnExamine = 1},
  FlowEvents = {
    Inputs = {}
  }
}
function GetElevatorFlowgraphEvents(A0_3955)
  local L1_3956, L2_3957, L3_3958, L4_3959, L5_3960, L6_3961
  L1_3956 = {
    L2_3957,
    L3_3958,
    L4_3959
  }
  L2_3957 = "One"
  L2_3957 = A0_3955.FlowEvents
  L2_3957 = L2_3957.Inputs
  for L6_3961, _FORV_7_ in L3_3958(L4_3959) do
    A0_3955["Event_Button" .. tostring(L6_3961) .. "_HeaderText"] = function(A0_3962, A1_3963, A2_3964)
      ArkKioskScript.SetElevatorButtonFloor(A0_3962.id, _UPVALUE0_, A2_3964)
    end
    L2_3957["Button" .. tostring(L6_3961) .. "HeaderText"] = {
      A0_3955["Event_Button" .. tostring(L6_3961) .. "_HeaderText"],
      "string"
    }
    A0_3955["Event_Button" .. tostring(L6_3961) .. "SubText"] = function(A0_3965, A1_3966, A2_3967)
      ArkKioskScript.SetElevatorButtonSecondary(A0_3965.id, _UPVALUE0_, A2_3967)
    end
    L2_3957["Button" .. tostring(L6_3961) .. "SubText"] = {
      A0_3955["Event_Button" .. tostring(L6_3961) .. "SubText"],
      "string"
    }
  end
  A0_3955.Event_SetStateDefault = L3_3958
  L2_3957.SetStateDefault = L3_3958
  A0_3955.Event_SetStateProcessing = L3_3958
  L2_3957.SetStateProcessing = L3_3958
  A0_3955.Event_SetStateFail = L3_3958
  L2_3957.SetStateFail = L3_3958
  A0_3955.Event_SetCurrentFloorText = L3_3958
  L2_3957.SetCurrentFloorText = L3_3958
  A0_3955.Event_SetDefaultStateText = L3_3958
  L2_3957.SetDefaultStateText = L3_3958
  A0_3955.Event_SetFailStateText = L3_3958
  L2_3957.SetFailStateText = L3_3958
  L4_3959.ButtonOnePressed = "bool"
  L4_3959.ButtonTwoPressed = "bool"
  L4_3959.ButtonThreePressed = "bool"
  L4_3959.StateDefault = "bool"
  L4_3959.StateProcessing = "bool"
  L4_3959.StateFail = "bool"
  L3_3958.Outputs = L4_3959
end
GetArkEntityUtils(ArkGenericElevatorKiosk)
SetupCollisionFiltering(ArkGenericElevatorKiosk)
GetElevatorFlowgraphEvents(ArkGenericElevatorKiosk)
function ArkGenericElevatorKiosk.Init(A0_3968, A1_3969)
end
function ArkGenericElevatorKiosk.SetFromProperties(A0_3970)
  local L1_3971
end
function ArkGenericElevatorKiosk.OnReset(A0_3972)
  local L1_3973
end
function ArkGenericElevatorKiosk.OnSpawn(A0_3974)
  local L1_3975
end
