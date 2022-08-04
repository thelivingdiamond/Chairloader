Script.ReloadScript("SCRIPTS/Entities/actor/BasicActor.lua")
Script.ReloadScript("SCRIPTS/Entities/AI/Shared/BasicAI.lua")
NullAI_x = {
  IsAIControlled = function()
    local L0_2937, L1_2938
    L0_2937 = true
    return L0_2937
  end,
  PropertiesInstance = {
    AITerritoryAndWave = {aiterritory_Territory = "<None>", aiwave_Wave = "<None>"},
    soclasses_SmartObjectClass = "",
    groupid = -1,
    bAutoDisable = 0
  },
  Properties = {
    fileModel = "",
    fileHitDeathReactionsParamsDataFile = "",
    soclasses_SmartObjectClass = ""
  },
  gameParams = {
    physicsParams = {
      Living = {inertia = 0, inertiaAccel = 0}
    }
  },
  AIMovementAbility = {},
  hitDeathReactionsParamsDefFile = "",
  AnimationGraph = "",
  UpperBodyGraph = "",
  ActionController = "",
  _Parent = {}
}
function NullAI_x.InitNullAI(A0_2939)
  local L1_2940, L2_2941
  L1_2940 = A0_2939._Parent
  L2_2941 = A0_2939.Reset
  L1_2940.Reset = L2_2941
  L1_2940 = A0_2939.NullAI_Reset
  A0_2939.Reset = L1_2940
  L1_2940 = A0_2939._Parent
  L2_2941 = A0_2939.OnReset
  L1_2940.OnReset = L2_2941
  L1_2940 = A0_2939.NullAI_OnReset
  A0_2939.OnReset = L1_2940
  L1_2940 = A0_2939._Parent
  L2_2941 = A0_2939.ResetCommon
  L1_2940.ResetCommon = L2_2941
  L1_2940 = A0_2939.NullAI_ResetCommon
  A0_2939.ResetCommon = L1_2940
  L1_2940 = A0_2939._Parent
  L2_2941 = A0_2939.OnInit
  L1_2940.OnInit = L2_2941
  L1_2940 = A0_2939.NullAI_OnInit
  A0_2939.OnInit = L1_2940
  L1_2940 = A0_2939._Parent
  L2_2941 = A0_2939.SetActorModel
  L1_2940.SetActorModel = L2_2941
  L1_2940 = A0_2939.NullAI_SetActorModel
  A0_2939.SetActorModel = L1_2940
  L1_2940 = A0_2939._Parent
  L2_2941 = A0_2939.OnSpawn
  L1_2940.OnSpawn = L2_2941
  L1_2940 = A0_2939.NullAI_OnSpawn
  A0_2939.OnSpawn = L1_2940
end
function NullAI_x.NullAI_Reset(A0_2942, A1_2943, A2_2944)
  A0_2942:NullAI_ResetCommon(A1_2943, A2_2944)
end
function NullAI_x.NullAI_OnReset(A0_2945, A1_2946, A2_2947)
  A0_2945.UpdateTime = 0.05
  A0_2945:NetPresent(1)
  A0_2945:SetScriptUpdateRate(A0_2945.UpdateTime)
  A0_2945:NullAI_ResetCommon(A1_2946, A2_2947)
end
function NullAI_x.NullAI_ResetCommon(A0_2948, A1_2949, A2_2950)
  A0_2948.AI = {}
end
function NullAI_x.NullAI_OnInit(A0_2951, A1_2952)
  A0_2951.AI = {}
  if not A1_2952 or A1_2952 == false then
    BasicAI.RegisterAI(A0_2951)
  end
  A0_2951:NullAI_OnReset(true, A1_2952)
end
function NullAI_x.NullAI_SetActorModel(A0_2953, A1_2954)
  A0_2953:CreateRenderProxy()
end
function NullAI_x.NullAI_OnSpawn(A0_2955)
  local L1_2956
end
function NullAI_x.RegisterAI(A0_2957, A1_2958)
end
