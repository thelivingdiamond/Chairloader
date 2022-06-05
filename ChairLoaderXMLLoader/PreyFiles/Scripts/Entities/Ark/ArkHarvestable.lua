Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkHarvestable = {
  Properties = {
    object_Model = "",
    object_HarvestedModel = "",
    archetype_PickupToHarvest = "",
    nPickupCount = 1,
    textDisplayName = "",
    textUseMessage = "",
    Sound = {audioTrigger_Harvest = ""},
    Physics = {
      bPhysicalize = 1,
      bRigidBody = 0,
      bPushableByPlayers = 0,
      bPushableByAI = 0,
      Density = -1,
      Mass = -1
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
    Icon = "prefab.bmp",
    IconOnTop = 1,
    IsScalable = false
  },
  PropertiesInstance = {bVerbose = 0}
}
ArkHarvestableInstanceVars = {
  m_bInit = false,
  m_referenceTable = false,
  m_bVerbose = false,
  m_audioIds = {},
  m_bEnabled = true,
  m_displayName = ""
}
GetArkEntityUtils(ArkHarvestable)
ArkMakeSaveable(ArkHarvestable)
SetupCollisionFiltering(ArkHarvestable)
function CreateHarvestable(A0_4035)
  mergef(A0_4035, ArkHarvestableInstanceVars, 1)
  A0_4035.m_referenceTable = ArkHarvestableInstanceVars
end
function ArkHarvestable.Init(A0_4036, A1_4037)
  A0_4036:Log("Init")
  if not A0_4036.m_bInit then
    A0_4036.m_bInit = true
    A0_4036.m_displayName = A0_4036.Properties.textDisplayName
    A0_4036:SetFromProperties()
  end
end
function ArkHarvestable.SetFromProperties(A0_4038)
  local L1_4039, L2_4040
  L2_4040 = A0_4038
  L1_4039 = A0_4038.Log
  L1_4039(L2_4040, "SetFromProperties")
  L1_4039 = A0_4038.Properties
  L2_4040 = ""
  if A0_4038.m_bEnabled then
    L2_4040 = L1_4039.object_Model
  else
    L2_4040 = L1_4039.object_HarvestedModel
  end
  A0_4038:SetupModelAndPhysics(L2_4040)
  GetAudioIds(L1_4039.Sound, A0_4038.m_audioIds)
  A0_4038.m_bVerbose = A0_4038.PropertiesInstance.bVerbose == 1
  A0_4038:SetDisplayName(A0_4038.m_displayName)
end
function ArkHarvestable.GetUsable(A0_4041)
  local L2_4042, L3_4043
  L2_4042 = {}
  L3_4043 = A0_4041.m_bEnabled
  if L3_4043 then
    L3_4043 = {}
    L3_4043.ActionType = "ScriptDefined"
    L3_4043.DisplayText = A0_4041.Properties.textUseMessage
    L2_4042.Use = L3_4043
  end
  return L2_4042
end
function ArkHarvestable.OnUsed(A0_4044)
  A0_4044:Log("OnUsed()")
  A0_4044:Harvest()
  A0_4044.m_bEnabled = false
end
function ArkHarvestable.OnRemoteManipulation(A0_4045)
  A0_4045:Harvest()
  A0_4045.m_bEnabled = false
end
function ArkHarvestable.GetRemoteManipulationInteraction(A0_4046)
  local L1_4047, L2_4048
  L1_4047 = {}
  L2_4048 = A0_4046.m_bEnabled
  if L2_4048 then
    L1_4047.ActionType = "ScriptDefined"
    L2_4048 = A0_4046.Properties
    L2_4048 = L2_4048.textUseMessage
    L1_4047.DisplayText = L2_4048
  end
  return L1_4047
end
function ArkHarvestable.Harvest(A0_4049)
  local L1_4050, L2_4051
  L1_4050 = A0_4049.Properties
  L2_4051 = L1_4050.object_HarvestedModel
  if L2_4051 ~= nil then
    A0_4049:SetupModelAndPhysics(L2_4051)
  end
  if A0_4049.m_audioIds.audioTrigger_Harvest then
    A0_4049:ExecuteAudioTrigger(A0_4049.m_audioIds.audioTrigger_Harvest, A0_4049:GetDefaultAuxAudioProxyID())
  end
  A0_4049.m_displayName = ""
  A0_4049:SetDisplayName(A0_4049.m_displayName)
  ItemSystem.GiveItem(L1_4050.archetype_PickupToHarvest, g_localActor:GetRawId(), L1_4050.nPickupCount)
  BroadcastEvent(A0_4049, "Harvested")
end
function ArkHarvestable.OnSpawn(A0_4052)
  CreateHarvestable(A0_4052)
end
function ArkHarvestable.OnReset(A0_4053)
  A0_4053.m_bEnabled = true
  A0_4053.m_bInit = false
  A0_4053:SetFromProperties()
end
function ArkHarvestable.OnPostLoad(A0_4054)
  A0_4054:SetFromProperties()
end
ArkHarvestable.FlowEvents = {
  Inputs = {},
  Outputs = {Harvested = "bool"}
}
