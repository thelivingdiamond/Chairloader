Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkFruitTree = {
  Properties = {
    object_Model = "",
    Spawns = {
      SpawnOption_1 = {
        archetype_PickupToSpawn = "",
        nNumberOfHelpers = 1,
        sHelperNamePrefix = ""
      },
      SpawnOption_2 = {
        archetype_PickupToSpawn = "",
        nNumberOfHelpers = 1,
        sHelperNamePrefix = ""
      }
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
  Editor = {
    Icon = "prefab.bmp",
    IconOnTop = 1,
    IsScalable = false
  },
  PropertiesInstance = {
    bVerbose = 0,
    bSpawnItemsOnGameStart = 1,
    SpawnCountOverrides = {SpawnOption_1 = -1, SpawnOption_2 = -1}
  }
}
ArkFruitTreeInstanceVars = {
  m_bInit = false,
  m_referenceTable = false,
  m_bVerbose = false
}
GetArkEntityUtils(ArkFruitTree)
ArkMakeSaveable(ArkFruitTree)
SetupCollisionFiltering(ArkFruitTree)
function CreateFruitTree(A0_3926)
  mergef(A0_3926, ArkFruitTreeInstanceVars, 1)
  A0_3926.m_referenceTable = ArkFruitTreeInstanceVars
end
function ArkFruitTree.SetFromProperties(A0_3927)
  A0_3927:Log("SetFromProperties")
  A0_3927.m_bVerbose = A0_3927.PropertiesInstance.bVerbose == 1
  A0_3927:SetupModelAndPhysics()
end
function ArkFruitTree.Init(A0_3928, A1_3929)
  A0_3928:Log("Init")
  if not A0_3928.m_bInit then
    A0_3928.m_bInit = true
    A0_3928:SetFromProperties()
    if A1_3929 and A0_3928.PropertiesInstance.bSpawnItemsOnGameStart == 1 then
      A0_3928:SpawnPickups()
    end
  end
end
function ArkFruitTree.SpawnPickups(A0_3930)
  local L1_3931, L2_3932, L3_3933, L4_3934, L5_3935, L6_3936, L7_3937, L8_3938, L9_3939, L10_3940, L11_3941, L12_3942, L13_3943, L14_3944
  for L4_3934, L5_3935 in L1_3931(L2_3932) do
    L6_3936 = {}
    L7_3937 = {}
    L8_3938 = {}
    L9_3939 = ""
    L10_3940 = L5_3935.nNumberOfHelpers
    if L11_3941 ~= -1 then
      L10_3940 = L11_3941[L4_3934]
    end
    if L11_3941 ~= "" and L10_3940 ~= 0 then
      for L14_3944 = 1, L10_3940 do
        L9_3939 = L5_3935.sHelperNamePrefix .. tostring(L14_3944)
        L6_3936 = A0_3930:GetBonePos(L9_3939)
        L7_3937 = A0_3930:GetBoneDir(L9_3939)
        L8_3938 = A0_3930:GetBoneUp(L9_3939)
        if L6_3936 ~= nil and L7_3937 ~= nil then
          A0_3930:SpawnPickupAtHelper(L5_3935.archetype_PickupToSpawn, L6_3936, L7_3937, L8_3938)
        end
      end
    end
  end
end
function ArkFruitTree.SpawnPickupAtHelper(A0_3945, A1_3946, A2_3947, A3_3948, A4_3949)
  local L5_3950
  L5_3950 = A0_3945.Log
  L5_3950(A0_3945, "ArkFruitTree:SpawnPickupAtHelper()")
  L5_3950 = {}
  L5_3950.archetype = A1_3946
  L5_3950.name = A0_3945:GetName()
  System.SpawnEntity(L5_3950):SetWorldPos(A2_3947)
  System.SpawnEntity(L5_3950):SetDirectionVector(A3_3948, A4_3949)
  if System.SpawnEntity(L5_3950).arkitem then
    System.SpawnEntity(L5_3950).arkitem:SetPhysicalizeAsStatic(true, true)
  end
  A0_3945:ActivateOutput("SpawnedEntityId", System.SpawnEntity(L5_3950):GetRawId())
end
function ArkFruitTree.OnSpawn(A0_3951)
  CreateFruitTree(A0_3951)
end
function ArkFruitTree.OnReset(A0_3952)
  A0_3952.m_bInit = false
  A0_3952:SetFromProperties()
end
function ArkFruitTree.OnPostLoad(A0_3953)
  A0_3953:SetFromProperties()
end
function ArkFruitTree.Event_Spawn(A0_3954)
  A0_3954:SpawnPickups()
end
ArkFruitTree.FlowEvents = {
  Inputs = {
    Spawn = {
      ArkFruitTree.Event_Spawn,
      "void"
    }
  },
  Outputs = {SpawnedEntityId = "int"}
}
