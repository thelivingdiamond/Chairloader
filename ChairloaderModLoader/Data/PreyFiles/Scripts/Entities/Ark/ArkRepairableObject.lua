Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkRepairableObject = {
  Properties = {
    object_Model = "",
    object_ModelBroken = "",
    material_Broken = "",
    particleeffect_BrokenVFX = "",
    fBrokenVFXScale = 1,
    nBrokenVFXRate = 1000,
    nBrokenVFXRateVariation = 100,
    vector_BrokenVFXOffset = {
      x = 0,
      y = 0,
      z = 0
    },
    tutorial_ContextualTutorial = "",
    vector_InteractionOffset = {
      x = 0,
      y = 0,
      z = 0
    },
    ei_TransparencyMode = 0,
    carryDirection = {
      x = 0,
      y = 0,
      z = 0
    },
    carryHeightOffset = 0,
    carryForwardOffset = 0,
    bIsCarryable = 0,
    bCanTriggerAreas = 0,
    bUseSafeCarry = false,
    ei_TransparencyMode = 0,
    Repair = {
      textPromptItemRequired = "",
      textDisplayName = "",
      textDisplayNameBroken = "",
      nSparePartsRequired = 1,
      nHoldToUseDuration = 1000,
      ability_RepairRequirement = "",
      archetype_RepairItem = "",
      fRepairIconRange = 10
    },
    Sound = {
      audioTrigger_Break = "",
      audioTrigger_BrokenLoop = "",
      audioTrigger_Repaired = "",
      audioTrigger_RepairLoop = "",
      audioTrigger_RepairStop = "",
      audioTrigger_Carry = ""
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
  PropertiesInstance = {bStartsBroken = 0, bVerbose = 0},
  Editor = {
    IsScalable = false,
    Icon = "clock.bmp",
    IconOnTop = 0
  }
}
GetArkEntityUtils(ArkRepairableObject)
SetupCollisionFiltering(ArkRepairableObject)
function ArkRepairableObject.Init(A0_4478, A1_4479)
end
function ArkRepairableObject.SetFromProperties(A0_4480)
  A0_4480.m_bVerbose = A0_4480.PropertiesInstance.bVerbose == 1
  GetAudioIds(A0_4480.Properties.Sound, A0_4480.m_audioIds)
  if A0_4480.Properties.bCanTriggerAreas == 1 then
    A0_4480:SetFlags(ENTITY_FLAG_TRIGGER_AREAS, 0)
  else
    A0_4480:SetFlags(ENTITY_FLAG_TRIGGER_AREAS, 2)
  end
end
function ArkRepairableObject.GetUsable(A0_4481)
  if A0_4481:GetPhysicalStats().mass > 0 and A0_4481.Properties.bIsCarryable == 1 then
    ({}).Use, ({}).ActionType = {}, "Carry"
  end
  return {}
end
function ArkRepairableObject.Event_Repair(A0_4482)
  BroadcastEvent(A0_4482, "Repair")
end
function ArkRepairableObject.Event_Break(A0_4483)
  BroadcastEvent(A0_4483, "Break")
end
function ArkRepairableObject.OnReset(A0_4484)
  local L1_4485
end
function ArkRepairableObject.OnSpawn(A0_4486)
  local L1_4487
end
ArkRepairableObject.FlowEvents = {
  Inputs = {
    Break = {
      ArkRepairableObject.Event_Break,
      "bool"
    },
    Repair = {
      ArkRepairableObject.Event_Repair,
      "bool"
    }
  },
  Outputs = {Repaired = "bool"}
}
