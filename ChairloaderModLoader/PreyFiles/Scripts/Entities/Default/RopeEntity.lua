Script.ReloadScript("scripts/Utils/EntityUtils.lua")
RopeEntity = {
  Properties = {
    MultiplayerOptions = {bNetworked = 0}
  }
}
function RopeEntity.OnSpawn(A0_4722)
  if A0_4722.Properties.MultiplayerOptions.bNetworked == 0 then
    A0_4722:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
  end
end
function RopeEntity.OnPhysicsBreak(A0_4723, A1_4724, A2_4725, A3_4726)
  A0_4723:ActivateOutput("Break", A2_4725 + 1)
end
function RopeEntity.Event_Remove(A0_4727)
  A0_4727:DrawSlot(0, 0)
  A0_4727:DestroyPhysics()
  A0_4727:ActivateOutput("Remove", true)
end
function RopeEntity.Event_Hide(A0_4728)
  A0_4728:Hide(1)
  A0_4728:ActivateOutput("Hide", true)
end
function RopeEntity.Event_UnHide(A0_4729)
  A0_4729:Hide(0)
  A0_4729:ActivateOutput("UnHide", true)
end
function RopeEntity.Event_BreakStart(A0_4730, A1_4731, A2_4732, A3_4733)
  local L4_4734
  L4_4734 = {}
  L4_4734.entity_name_1 = "#unattached"
  A0_4730:SetPhysicParams(PHYSICPARAM_ROPE, L4_4734)
end
function RopeEntity.Event_BreakEnd(A0_4735, A1_4736, A2_4737, A3_4738)
  local L4_4739
  L4_4739 = {}
  L4_4739.entity_name_2 = "#unattached"
  A0_4735:SetPhysicParams(PHYSICPARAM_ROPE, L4_4739)
end
function RopeEntity.Event_BreakDist(A0_4740, A1_4741, A2_4742)
  local L3_4743
  L3_4743 = {}
  L3_4743.break_point = A2_4742
  A0_4740:SetPhysicParams(PHYSICPARAM_ROPE, L3_4743)
end
function RopeEntity.Event_Disable(A0_4744)
  local L1_4745
  L1_4745 = {}
  L1_4745.bDisabled = 1
  A0_4744:SetPhysicParams(PHYSICPARAM_ROPE, L1_4745)
end
function RopeEntity.Event_Enable(A0_4746)
  local L1_4747
  L1_4747 = {}
  L1_4747.bDisabled = 0
  A0_4746:SetPhysicParams(PHYSICPARAM_ROPE, L1_4747)
end
RopeEntity.FlowEvents = {
  Inputs = {
    Hide = {
      RopeEntity.Event_Hide,
      "bool"
    },
    UnHide = {
      RopeEntity.Event_UnHide,
      "bool"
    },
    Remove = {
      RopeEntity.Event_Remove,
      "bool"
    },
    BreakStart = {
      RopeEntity.Event_BreakStart,
      "bool"
    },
    BreakEnd = {
      RopeEntity.Event_BreakEnd,
      "bool"
    },
    BreakDist = {
      RopeEntity.Event_BreakDist,
      "float"
    },
    Disable = {
      RopeEntity.Event_Disable,
      "bool"
    },
    Enable = {
      RopeEntity.Event_Enable,
      "bool"
    }
  },
  Outputs = {
    Hide = "bool",
    UnHide = "bool",
    Remove = "bool",
    Break = "int"
  }
}
