Script.ReloadScript("Scripts/Entities/Ark/ArkContainer.lua")
Script.ReloadScript("scripts/Entities/Ark/ArkKeypad.lua")
ArkKeypadContainer = {
  Properties = {
    archetype_KeypadArchetype = "",
    KeypadBoneName = "",
    textDisplayNameLocked = "@i_container_locked"
  },
  PropertiesInstance = {
    keycode_UnlockCode = "",
    ability_HackRequirementOverride = "",
    bStartsLocked = 0
  },
  States = {"Locked", "Unlocked"}
}
ArkKeypadContainerInstanceVars = {
  m_bLocked = false,
  m_keypad = false,
  m_savedState = false
}
ArkMakeDerivedEntityOverride(ArkKeypadContainer, ArkContainer, true)
ArkMakeLockable(ArkKeypadContainer)
function CreateKeypadContainer(A0_4122)
  mergef(A0_4122, ArkKeypadContainerInstanceVars, 1)
  A0_4122.m_referenceTable = ArkKeypadContainerInstanceVars
end
function ArkKeypadContainer.Init(A0_4123, A1_4124)
  A0_4123:Log("Init()")
  if not A0_4123.m_bInit then
    A0_4123:Log("ArkKeypadContainer:Init")
    A0_4123.m_bInit = true
    A0_4123:SetFromProperties()
    if A0_4123.Properties.bCanTriggerAreas == 1 then
      A0_4123:SetFlags(ENTITY_FLAG_TRIGGER_AREAS, 0)
    else
      A0_4123:SetFlags(ENTITY_FLAG_TRIGGER_AREAS, 2)
    end
    if A1_4124 then
      CryAction.CreateGameObjectForEntity(A0_4123.id)
      A0_4123:InitInventory()
      A0_4123:InitKeypad()
      A0_4123:SpawnLootFromTable()
      if A0_4123.m_bLocked then
        A0_4123:GotoState("Locked")
      else
        A0_4123:GotoState("Unlocked")
      end
    end
  end
end
function ArkKeypadContainer.SetFromProperties(A0_4125)
  A0_4125:Log("SetFromProperties()")
  A0_4125.m_bLocked = A0_4125.PropertiesInstance.bStartsLocked == 1
  ArkContainer.SetFromProperties(A0_4125)
end
function ArkKeypadContainer.GetUsable(A0_4126)
  local L1_4127, L2_4128, L3_4129
  L1_4127 = {}
  L2_4128 = A0_4126.m_bUsable
  if L2_4128 then
    L2_4128 = A0_4126.m_bLocked
    if not L2_4128 then
      L2_4128 = {}
      L2_4128.ActionType = "ScriptDefined"
      L3_4129 = A0_4126.Properties
      L3_4129 = L3_4129.textDisplayText
      L2_4128.DisplayText = L3_4129
      L1_4127.Loot = L2_4128
    end
    L2_4128 = A0_4126.Properties
    L2_4128 = L2_4128.Physics
    L2_4128 = L2_4128.bRigidBody
    if L2_4128 == 1 then
      L2_4128 = A0_4126.Properties
      L2_4128 = L2_4128.ability_CarryRequirement
      if L2_4128 then
        L3_4129 = {}
        L3_4129.ActionType = "Carry"
        L1_4127["Hold Use"] = L3_4129
      end
    end
  end
  return L1_4127
end
function ArkKeypadContainer.InitKeypad(A0_4130)
  local L1_4131, L2_4132, L3_4133, L4_4134, L5_4135, L6_4136, L7_4137
  L1_4131 = A0_4130.Properties
  L1_4131 = L1_4131.archetype_KeypadArchetype
  L2_4132 = "ArkKeypad"
  L3_4133 = System
  L3_4133 = L3_4133.GetEntityLayer
  L4_4134 = A0_4130.id
  L3_4133 = L3_4133(L4_4134)
  L4_4134 = A0_4130.Properties
  L4_4134 = L4_4134.KeypadBoneName
  L6_4136 = A0_4130
  L5_4135 = A0_4130.GetBonePos
  L7_4137 = L4_4134
  L5_4135 = L5_4135(L6_4136, L7_4137)
  L7_4137 = A0_4130
  L6_4136 = A0_4130.GetBoneDir
  L6_4136 = L6_4136(L7_4137, A0_4130.Properties.KeypadBoneName)
  L7_4137 = A0_4130.GetBoneUp
  L7_4137 = L7_4137(A0_4130, L4_4134)
  A0_4130.m_keypad = A0_4130:SpawnAccessController(L1_4131, L2_4132, L3_4133, L5_4135, L6_4136, L7_4137)
  A0_4130.m_keypad:InitDoorAccessController(A0_4130)
end
function ArkKeypadContainer.DoFunctionOnKeypad(A0_4138, A1_4139, A2_4140, A3_4141)
  A0_4138:ControllerFunction(A0_4138.m_keypad, A1_4139, A2_4140, A3_4141)
end
function ArkKeypadContainer.ControllerFunction(A0_4142, A1_4143, A2_4144, A3_4145, A4_4146)
  local L5_4147
  if A1_4143 then
    L5_4147 = A1_4143[A2_4144]
    L5_4147(A1_4143, A3_4145, A4_4146)
  end
end
function ArkKeypadContainer.OnRemoteManipulation(A0_4148)
  if A0_4148:GetState() == "Unlocked" then
    A0_4148:OpenExternalInventory()
  end
end
function ArkKeypadContainer.Event_Lock(A0_4149, A1_4150)
  A0_4149:Log("ArkKeypadContainer:Event_Lock()")
  A0_4149:GotoState("Locked")
  BroadcastEvent(A0_4149, "Locked")
end
function ArkKeypadContainer.Event_Unlock(A0_4151, A1_4152)
  A0_4151:Log("ArkKeypadContainer:Event_Unlock()")
  A0_4151:GotoState("Unlocked")
  BroadcastEvent(A0_4151, "Unlocked")
end
function ArkKeypadContainer.OnPostLoad(A0_4153)
  A0_4153:Log("OnPostLoad")
  A0_4153:GotoState("")
  A0_4153:SetupModelAndPhysics()
  A0_4153:GotoState(A0_4153.m_savedState)
end
function ArkKeypadContainer.OnReset(A0_4154)
  A0_4154:GotoState("")
  A0_4154.m_keypad = false
  ArkContainer.OnReset(A0_4154)
end
function ArkKeypadContainer.OnSpawn(A0_4155)
  CreateKeypadContainer(A0_4155)
  A0_4155:Log("OnSpawn")
end
ArkKeypadContainer.Locked = {
  OnStartLevel = function(A0_4156)
    local L1_4157
  end,
  OnBeginState = function(A0_4158)
    A0_4158:Log("Locked state begin")
    A0_4158.m_bLocked = true
    A0_4158.m_bUsable = false
    A0_4158:SetDisplayName(A0_4158.Properties.textDisplayNameLocked)
    A0_4158:DoFunctionOnKeypad("Event_Lock")
    BroadcastEvent(A0_4158, "Locked")
  end,
  OnEndState = function(A0_4159)
    A0_4159:Log("Locked state end")
  end
}
ArkKeypadContainer.Unlocked = {
  OnStartLevel = function(A0_4160)
    local L1_4161
  end,
  OnBeginState = function(A0_4162)
    A0_4162:Log("Unlocked state begin")
    A0_4162.m_bLocked = false
    A0_4162.m_bUsable = true
    A0_4162:SetDisplayName(A0_4162.Properties.textDisplayName)
    A0_4162:DoFunctionOnKeypad("Event_Unlock")
    BroadcastEvent(A0_4162, "Unlocked")
  end,
  OnEndState = function(A0_4163)
    A0_4163:Log("Unlocked state end")
  end
}
ArkKeypadContainer.FlowEvents = {
  Inputs = {
    Lock = {
      ArkKeypadContainer.Event_Lock,
      "bool"
    },
    Unlock = {
      ArkKeypadContainer.Event_Unlock,
      "bool"
    }
  },
  Outputs = {
    OnOpen = "bool",
    OnQuickLooted = "bool",
    Locked = "bool",
    Unlocked = "bool"
  }
}
