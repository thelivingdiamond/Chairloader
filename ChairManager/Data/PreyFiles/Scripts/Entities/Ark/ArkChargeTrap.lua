Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkChargeTrap = {
  Properties = {
    object_Model = "",
    object_ModelDisarmed = "",
    signalGroup_DamagingSignals = "",
    archetype_ChargeArchetype = "ArkProjectiles.Charges.Recycler",
    vector_ChargeOffset = {
      x = 0,
      y = 0,
      z = 0
    },
    textDisplayText = "@ui_use",
    tutorial_ContextualTutorial = "",
    vector_InteractionOffset = {
      x = 0,
      y = 0,
      z = 0
    },
    Repair = {
      textPromptItemRequired = "",
      textDisplayName = "",
      textDisplayNameBroken = "",
      nSparePartsRequired = 0,
      nHoldToUseDuration = 1000,
      ability_RepairRequirement = "",
      archetype_RepairItem = "",
      textRepairVerb = "@ui_disarm"
    },
    Sound = {
      audioTrigger_Break = "",
      audioTrigger_BrokenLoop = "",
      audioTrigger_RepairLoop = "",
      audioTrigger_RepairStop = ""
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
  PropertiesInstance = {bStartsBroken = 1},
  Editor = {
    IsScalable = false,
    Icon = "explosion.bmp",
    IconOnTop = 0
  }
}
GetArkEntityUtils(ArkChargeTrap)
SetupCollisionFiltering(ArkChargeTrap)
function ArkChargeTrap.Event_Trigger(A0_3532)
  BroadcastEvent(A0_3532, "Trigger")
end
function ArkChargeTrap.Event_Disarm(A0_3533)
  BroadcastEvent(A0_3533, "Disarm")
end
ArkChargeTrap.FlowEvents = {
  Inputs = {
    Trigger = {
      ArkChargeTrap.Event_Trigger,
      "bool"
    },
    Disarm = {
      ArkChargeTrap.Event_Disarm,
      "bool"
    }
  },
  Outputs = {Triggered = "bool", Disarmed = "bool"}
}
