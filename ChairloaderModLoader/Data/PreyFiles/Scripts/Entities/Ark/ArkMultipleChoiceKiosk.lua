Script.ReloadScript("scripts/ArkEntityUtils.lua")
Script.ReloadScript("scripts/Entities/Ark/ArkBasicEntity.lua")
ArkMultipleChoiceKiosk = {
  Properties = {
    object_Model = "",
    object_Screen = "",
    sUIElementName = "",
    nSubMatIndex = 0,
    sScreenBoneName = "",
    fInteractDistance = 1,
    fActiveDistance = 1,
    fInteractAngle = 75,
    bEnableCollisionInteraction = 1,
    nDelayOnButtonSelect = 1000,
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
  PropertiesInstance = {
    bVerbose = 0,
    bStartsPowered = 1,
    bMovePlayerOnExamine = 1
  },
  FlowEvents = {
    Inputs = {}
  },
  m_alphabet = {
    "A",
    "B",
    "C",
    "D"
  }
}
function GetFlowgraphEvents(A0_4320)
  local L1_4321, L2_4322, L3_4323, L4_4324, L5_4325, L6_4326, L7_4327
  L1_4321 = A0_4320.m_alphabet
  L2_4322 = A0_4320.FlowEvents
  L2_4322 = L2_4322.Inputs
  for L6_4326, L7_4327 in L3_4323(L4_4324) do
    A0_4320["Event_SetAnswerText" .. L7_4327] = function(A0_4328, A1_4329, A2_4330)
      A0_4328:Log(_UPVALUE0_ .. " " .. A2_4330)
      ArkKioskScript.SetMultipleChoiceAnswer(A0_4328.id, _UPVALUE1_, A2_4330)
    end
    L2_4322["SetAnswerText" .. L7_4327] = {
      A0_4320["Event_SetAnswerText" .. L7_4327],
      "string"
    }
  end
  A0_4320.Event_SetQuestionText = L3_4323
  L2_4322.SetQuestionText = L3_4323
  A0_4320.Event_DisplayNewQuestion = L3_4323
  L2_4322.DisplayNewQuestion = L3_4323
  A0_4320.Event_DisplayRorschachPage = L3_4323
  L2_4322.DisplayRorschachPage = L3_4323
  A0_4320.Event_DisplayLogoPage = L3_4323
  L2_4322.DisplayLogoPage = L3_4323
  A0_4320.Event_DisplayStartPage = L3_4323
  L2_4322.DisplayStartPage = L3_4323
  A0_4320.Event_KioskPowerOn = L3_4323
  L2_4322.KioskPowerOn = L3_4323
  A0_4320.Event_KioskPowerOff = L3_4323
  L2_4322.KioskPowerOff = L3_4323
  L4_4324.Used = "bool"
  L4_4324.AnswerAPressed = "bool"
  L4_4324.AnswerBPressed = "bool"
  L4_4324.AnswerCPressed = "bool"
  L4_4324.AnswerDPressed = "bool"
  L4_4324.PoweredOn = "bool"
  L4_4324.PoweredOff = "bool"
  L4_4324.StartButtonPressed = "bool"
  L4_4324.NewQuestionDisplayed = "bool"
  L4_4324.RorshachDisplayed = "bool"
  L4_4324.LogoPageDisplayed = "bool"
  L4_4324.StartPageDisplayed = "bool"
  L3_4323.Outputs = L4_4324
end
GetArkEntityUtils(ArkMultipleChoiceKiosk)
SetupCollisionFiltering(ArkMultipleChoiceKiosk)
GetFlowgraphEvents(ArkMultipleChoiceKiosk)
function ArkMultipleChoiceKiosk.Init(A0_4331, A1_4332)
end
function ArkMultipleChoiceKiosk.SetFromProperties(A0_4333)
  local L1_4334
end
function ArkMultipleChoiceKiosk.OnReset(A0_4335)
  local L1_4336
end
function ArkMultipleChoiceKiosk.OnSpawn(A0_4337)
  local L1_4338
end
