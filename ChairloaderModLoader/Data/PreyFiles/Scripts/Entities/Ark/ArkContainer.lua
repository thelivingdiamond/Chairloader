Script.ReloadScript("Scripts/ArkEntityUtils.lua")
ArkContainer = {
  Properties = {
    bUseSafeCarry = false,
    carryDirection = {
      x = 0,
      y = 0,
      z = 0
    },
    carryHeightOffset = 0,
    carryForwardOffset = 0,
    object_Model = "",
    ability_CarryRequirement = "",
    bIsMimicable = true,
    sPlayerMimicSurrogate = "",
    bCanTriggerAreas = 0,
    textDisplayName = "@i_defaultContainer",
    textDisplayText = "",
    ei_TransparencyMode = 0,
    vector_ThrowAngularImpulse = {
      x = -10,
      y = 0,
      z = 0
    },
    fLookAtDelay = 0.3,
    AI = {bUsedAsDynamicObstacle = 1},
    Physics = {
      bPhysicalize = 1,
      bRigidBody = 1,
      bPushableByPlayers = 1,
      bPushableByAI = 1,
      Density = 10,
      Mass = -1
    },
    Sound = {
      audioTrigger_Carry = "",
      audioTrigger_HoldCarryStart = "",
      audioTrigger_HoldCarryCancel = ""
    },
    RecycleData = {
      organic = 0,
      mineral = 0,
      synthetic = 0,
      exotic = 0
    },
    Silhouette = {
      color_RGB = {
        x = 1,
        y = 1,
        z = 1
      },
      fAlpha = 0.25
    }
  },
  Editor = {
    Icon = "Prefab.bmp",
    IconOnTop = 1,
    IsScalable = false
  },
  PropertiesInstance = {
    bUsable = 1,
    bVerbose = 0,
    bUsedAsDynamicObstacle = 1
  }
}
ArkContainerInstanceVars = {
  m_bVerbose = false,
  m_referenceTable = false,
  m_bUsable = false,
  m_bInit = false,
  m_audioIds = {},
  Container = {}
}
GetArkEntityUtils(ArkContainer)
SetupCollisionFiltering(ArkContainer)
ArkMakeContainer(ArkContainer)
ArkMakeSaveable(ArkContainer)
function CreateContainer(A0_3608)
  mergef(A0_3608, ArkContainerInstanceVars, 1)
  A0_3608.m_referenceTable = ArkContainerInstanceVars
end
function ArkContainer.GetUsable(A0_3609)
  local L1_3610, L2_3611, L3_3612
  L1_3610 = {}
  L2_3611 = A0_3609.m_bUsable
  if L2_3611 then
    L2_3611 = A0_3609.Properties
    L2_3611 = L2_3611.ContainerInfo
    L2_3611 = L2_3611.bPreventStorage
    if not L2_3611 then
      L2_3611 = {}
      L2_3611.ActionType = "ScriptDefined"
      L3_3612 = A0_3609.Properties
      L3_3612 = L3_3612.textDisplayText
      L2_3611.DisplayText = L3_3612
      L1_3610.Loot = L2_3611
    end
    L2_3611 = A0_3609.Properties
    L2_3611 = L2_3611.Physics
    L2_3611 = L2_3611.bRigidBody
    if L2_3611 == 1 then
      L2_3611 = A0_3609.Properties
      L2_3611 = L2_3611.ability_CarryRequirement
      if L2_3611 then
        L3_3612 = {}
        L3_3612.ActionType = "Carry"
        L1_3610["Hold Use"] = L3_3612
      end
    end
  end
  return L1_3610
end
function ArkContainer.GetRemoteManipulationInteraction(A0_3613)
  local L1_3614, L2_3615
  L1_3614 = {}
  L2_3615 = A0_3613.PropertiesInstance
  L2_3615 = L2_3615.bUsable
  if L2_3615 == 1 then
    L2_3615 = A0_3613.Properties
    L2_3615 = L2_3615.ContainerInfo
    L2_3615 = L2_3615.bPreventStorage
    if not L2_3615 then
      L1_3614.ActionType = "ScriptDefined"
    end
  end
  L1_3614.CouldChange = false
  return L1_3614
end
function ArkContainer.OnRemoteManipulation(A0_3616, A1_3617)
  A0_3616:OpenExternalInventory()
end
function ArkContainer.Init(A0_3618, A1_3619)
  A0_3618:Log("Init()")
  if not A0_3618.m_bInit then
    A0_3618:Log("ArkContainer:Init")
    A0_3618.m_bInit = true
    A0_3618:SetFromProperties()
    if A0_3618.Properties.bCanTriggerAreas == 1 then
      A0_3618:SetFlags(ENTITY_FLAG_TRIGGER_AREAS, 0)
    else
      A0_3618:SetFlags(ENTITY_FLAG_TRIGGER_AREAS, 2)
    end
    if A1_3619 then
      CryAction.CreateGameObjectForEntity(A0_3618.id)
      A0_3618:SetDisplayName(A0_3618.Properties.textDisplayName)
      A0_3618:InitInventory()
      A0_3618:SpawnLootFromTable()
    end
  end
end
function ArkContainer.SetFromProperties(A0_3620)
  A0_3620:Log("SetFromProperties()")
  A0_3620.m_bVerbose = A0_3620.PropertiesInstance.bVerbose == 1
  A0_3620.m_bUsable = A0_3620.PropertiesInstance.bUsable == 1
  A0_3620:SetupModelAndPhysics()
  GetAudioIds(A0_3620.Properties.Sound, A0_3620.m_audioIds)
end
function ArkContainer.OnLoot(A0_3621, A1_3622)
  A0_3621:OpenExternalInventory()
end
function ArkContainer.OnReset(A0_3623)
  A0_3623:ResetContainer()
  A0_3623:SetFromProperties()
  A0_3623.m_bInit = false
end
function ArkContainer.OnSpawn(A0_3624)
  CreateContainer(A0_3624)
end
function ArkContainer.OnPostLoad(A0_3625)
  A0_3625:Log("OnPostLoad")
  A0_3625:GotoState("")
  A0_3625:SetupModelAndPhysics()
end
function ArkContainer.OnQuickLooted(A0_3626, A1_3627)
  BroadcastEvent(A0_3626, "OnQuickLooted")
end
ArkContainer.FlowEvents = {
  Outputs = {OnOpen = "bool", OnQuickLooted = "bool"}
}
