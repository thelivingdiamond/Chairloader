Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkGrower = {
  Properties = {
    object_Model = "objects/environment/props/gameplay/food/jamontomato_a/jamontomato_a_super.cgf",
    archetype_PickupToSpawn = "ArkPickups.MissionItems.MM_Superfruit",
    fMinScale = 0.05,
    fMaxScale = 1,
    fScaleTime = 5,
    Physics = {
      bPhysicalize = 0,
      bPushableByPlayers = 0,
      bPushableByAI = 0,
      Density = -1,
      Mass = -1
    }
  },
  Editor = {
    IconOnTop = true,
    Icon = "GravitySphere.bmp",
    ShowBounds = 0,
    IsScalable = false
  }
}
GetArkEntityUtils(ArkGrower)
ArkMakeSaveable(ArkGrower)
ArkGrowerInstanceVars = {
  m_bInit = false,
  m_bVerbose = false,
  m_currentTime = 0,
  m_endTime = 0,
  m_bIsStillGrowing = true,
  m_referenceTable = false
}
function CreateArkGrower(A0_4013)
  mergef(A0_4013, ArkGrowerInstanceVars, 1)
  A0_4013.m_referenceTable = ArkGrowerInstanceVars
end
function ArkGrower.Init(A0_4014)
  if not A0_4014.m_bInit and not System.IsEditing() then
    A0_4014.m_bInit = true
    A0_4014:SetScale(A0_4014.Properties.fMinScale)
    A0_4014.m_bIsStillGrowing = true
    A0_4014:Activate(1)
    A0_4014.m_currentTime = System.GetCurrTime()
    A0_4014.m_endTime = A0_4014.m_currentTime + A0_4014.Properties.fScaleTime
  end
end
function ArkGrower.OnSpawn(A0_4015)
  CreateArkGrower(A0_4015)
  A0_4015:SetFromProperties()
  if not System.IsEditor() then
    A0_4015:Init(true)
  end
end
function ArkGrower.OnReset(A0_4016)
  A0_4016:SetFromProperties()
  A0_4016.m_bInit = false
  A0_4016.m_bIsStillGrowing = false
  A0_4016:Activate(0)
end
function ArkGrower.OnUpdate(A0_4017, A1_4018)
  local L2_4019, L3_4020, L4_4021, L5_4022
  L2_4019 = A0_4017.Properties
  L3_4020 = L2_4019.fScaleTime
  L4_4021 = A0_4017.m_endTime
  L5_4022 = A0_4017.m_currentTime
  L4_4021 = L4_4021 - L5_4022
  L3_4020 = L3_4020 - L4_4021
  L4_4021 = L2_4019.fScaleTime
  L4_4021 = L3_4020 / L4_4021
  L5_4022 = Lerp
  L5_4022 = L5_4022(L2_4019.fMinScale, L2_4019.fMaxScale, L4_4021)
  A0_4017:SetScale(L5_4022)
  if L5_4022 >= L2_4019.fMaxScale then
    A0_4017:CompleteGrowth()
  else
    A0_4017.m_currentTime = A0_4017.m_currentTime + A1_4018
  end
end
function ArkGrower.OnPostLoad(A0_4023)
  local L1_4024
  L1_4024 = A0_4023.m_bIsStillGrowing
  if L1_4024 then
    L1_4024 = A0_4023.m_endTime
    L1_4024 = L1_4024 - A0_4023.m_currentTime
    A0_4023.m_currentTime = System.GetCurrTime()
    A0_4023.m_endTime = A0_4023.m_currentTime + L1_4024
    A0_4023:Activate(1)
  end
end
function ArkGrower.CompleteGrowth(A0_4025)
  A0_4025:Activate(0)
  A0_4025.m_bIsStillGrowing = false
  BroadcastEvent(A0_4025, "GrowthComplete")
end
function ArkGrower.SpawnPickupAtHelper(A0_4026, A1_4027, A2_4028, A3_4029)
  local L4_4030
  L4_4030 = A0_4026.Log
  L4_4030(A0_4026, "ArkFruitTree:SpawnPickupAtHelper()")
  L4_4030 = {}
  L4_4030.archetype = A1_4027
  L4_4030.name = A0_4026:GetName()
  System.SpawnEntity(L4_4030):SetWorldPos(A2_4028)
  System.SpawnEntity(L4_4030):SetDirectionVector(A3_4029)
  if System.SpawnEntity(L4_4030).arkitem then
    System.SpawnEntity(L4_4030).arkitem:SetPhysicalizeAsStatic(true, true)
  end
  A0_4026:ActivateOutput("SpawnedEntityId", System.SpawnEntity(L4_4030):GetRawId())
end
function ArkGrower.Event_MakePickable(A0_4031)
  A0_4031:SpawnPickupAtHelper(A0_4031.Properties.archetype_PickupToSpawn, A0_4031:GetWorldPos(), A0_4031:GetDirectionVector())
  A0_4031:DeleteThis()
end
function ArkGrower.Event_SetSecondsRemaining(A0_4032, A1_4033, A2_4034)
  if A2_4034 > 0 then
    A0_4032.m_currentTime = System.GetCurrTime()
    A0_4032.m_endTime = A0_4032.m_currentTime + A2_4034
    A0_4032:Activate(1)
  else
    A0_4032:CompleteGrowth()
  end
end
ArkGrower.FlowEvents = {
  Inputs = {
    MakePickable = {
      ArkGrower.Event_MakePickable,
      "bool"
    },
    SetSecondsRemaining = {
      ArkGrower.Event_SetSecondsRemaining,
      "float"
    }
  },
  Outputs = {SpawnedEntityId = "int", GrowthComplete = "bool"}
}
