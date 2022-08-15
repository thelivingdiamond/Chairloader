Script.ReloadScript("scripts/ArkEntityUtils.lua")
Script.ReloadScript("scripts/Entities/Ark/ArkBasicEntity.lua")
ArkKiosk = {
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
    bDisallowGrenades = true,
    ei_ObjectMapIcon = "",
    material_ScreensaverMaterial = "",
    material_PowerOffMaterial = "",
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
  }
}
function GetKioskEventsForButtons(A0_4164)
  local L1_4165, L2_4166, L3_4167, L4_4168, L5_4169, L6_4170, L7_4171, L8_4172, L9_4173, L10_4174, L11_4175, L12_4176, L13_4177, L14_4178, L15_4179, L16_4180
  L1_4165 = {
    L2_4166,
    L3_4167,
    L4_4168
  }
  L2_4166 = "One"
  L3_4167 = "Two"
  L2_4166 = {}
  L2_4166.Default = 1
  L2_4166.Processing = 2
  L2_4166.Error = 3
  L2_4166.Disabled = 0
  L3_4167 = A0_4164.FlowEvents
  L3_4167 = L3_4167.Inputs
  for L7_4171, L8_4172 in L4_4168(L5_4169) do
    L9_4173 = "Event_Button"
    L10_4174 = tostring
    L11_4175 = L7_4171
    L10_4174 = L10_4174(L11_4175)
    L11_4175 = "_HeaderText"
    L9_4173 = L9_4173 .. L10_4174 .. L11_4175
    function L10_4174(A0_4181, A1_4182, A2_4183)
      ArkKioskScript.SetKioskButtonHeader(A0_4181.id, _UPVALUE0_, A2_4183)
    end
    A0_4164[L9_4173] = L10_4174
    L10_4174 = "Button"
    L11_4175 = tostring
    L12_4176 = L7_4171
    L11_4175 = L11_4175(L12_4176)
    L12_4176 = "HeaderText"
    L10_4174 = L10_4174 .. L11_4175 .. L12_4176
    L11_4175 = {L12_4176, L13_4177}
    L12_4176 = A0_4164[L9_4173]
    L3_4167[L10_4174] = L11_4175
    L11_4175 = "Event_Button"
    L12_4176 = tostring
    L12_4176 = L12_4176(L13_4177)
    L11_4175 = L11_4175 .. L12_4176 .. L13_4177
    function L12_4176(A0_4184, A1_4185, A2_4186)
      ArkKioskScript.SetKioskButtonBody(A0_4184.id, _UPVALUE0_, A2_4186)
    end
    A0_4164[L11_4175] = L12_4176
    L12_4176 = "Button"
    L12_4176 = L12_4176 .. L13_4177 .. L14_4178
    L3_4167[L12_4176] = L13_4177
    for L16_4180, _FORV_17_ in L13_4177(L14_4178) do
      A0_4164["Event_Button" .. tostring(L7_4171) .. "_" .. L16_4180] = function(A0_4187)
        ArkKioskScript.SetKioskButtonState(A0_4187.id, _UPVALUE0_, _UPVALUE1_)
      end
      L3_4167["Button" .. tostring(L7_4171) .. L16_4180] = {
        A0_4164["Event_Button" .. tostring(L7_4171) .. "_" .. L16_4180],
        "bool"
      }
    end
    A0_4164[L13_4177] = L14_4178
    L16_4180 = L7_4171
    L16_4180 = "Hide"
    L16_4180 = A0_4164[L13_4177]
    L3_4167[L14_4178] = L15_4179
  end
  A0_4164.Event_KioskHeaderText = L4_4168
  L3_4167.KioskHeaderText = L4_4168
  A0_4164.Event_KioskPowerOn = L4_4168
  L3_4167.KioskPowerOn = L4_4168
  A0_4164.Event_KioskPowerOff = L4_4168
  L3_4167.KioskPowerOff = L4_4168
  L5_4169.ButtonOnePressed = "bool"
  L5_4169.ButtonTwoPressed = "bool"
  L5_4169.ButtonThreePressed = "bool"
  L5_4169.PoweredOn = "bool"
  L5_4169.PoweredOff = "bool"
  L4_4168.Outputs = L5_4169
end
GetArkEntityUtils(ArkKiosk)
SetupCollisionFiltering(ArkKiosk)
GetKioskEventsForButtons(ArkKiosk)
function ArkKiosk.Init(A0_4188, A1_4189)
end
function ArkKiosk.SetFromProperties(A0_4190)
  local L1_4191
end
function ArkKiosk.OnReset(A0_4192)
  local L1_4193
end
function ArkKiosk.OnSpawn(A0_4194)
  local L1_4195
end
