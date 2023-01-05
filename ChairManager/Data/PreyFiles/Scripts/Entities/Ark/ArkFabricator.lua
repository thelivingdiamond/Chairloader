Script.ReloadScript("scripts/ArkEntityUtils.lua")
Script.ReloadScript("scripts/Entities/Ark/ArkBasicEntity.lua")
ArkFabricator = {
  Properties = {
    object_Model = "",
    object_Screen = "",
    nSlotsGlowAmount = 1,
    nSubMaterialId = 0,
    sSubMaterial = "",
    textMessageIngredientSlots = "",
    textPromptAddIngredients = "",
    textMessagePoweredOffMessage = "",
    textPromptUseMessage = "",
    gametokenid_NumTimesFabricatorUsed = "",
    gametokenid_FabricatedEntityId = "",
    gametokenid_FabricatedEntityName = "",
    sUIElementName = "",
    sSpawnAttachmentName = "helper_spawn",
    sSerializeAttachmentName = "helper_serialize",
    sSpawnBoneName = "helper_spawn",
    sScreenBoneName = "",
    nSubMatIndex = 1,
    nIdleDelay = 1,
    nErrorDelay = 5000,
    nItemReadyMinDuration = 1,
    nIngredientPickupDelay = 1,
    nUpdateRate = 1,
    fItemClearDistance = 1,
    bInteractAlwaysCheckAngle = 1,
    fInteractDistance = 1,
    fActiveDistance = 1,
    fInteractAngle = 75,
    bEnableCollisionInteraction = 0,
    ei_ObjectMapIcon = "",
    tutorial_ContextualTutorial = "",
    material_ScreensaverMaterial = "",
    material_PowerOffMaterial = "",
    fFabricatedWeaponIntegrity = 80,
    particleeffect_IdleVFX = "",
    gameNoiseLoudness_GameNoiseLoudness = "9469288860501649195",
    gameNoiseType_GameNoiseType = "9469288860501998057",
    Repair = {
      textDisplayNameBroken = "",
      archetype_RepairBox = "",
      sRepairAttachment = ""
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
    },
    Animation = {anim_Fabricate = "", anim_FabricateFast = ""},
    Sound = {
      audioTrigger_Craft = "",
      audioTrigger_PowerOff = "",
      audioTrigger_PowerLP = "",
      audioTrigger_PlaceIngredients = "",
      audioTrigger_PleaseTakeItem = "",
      audioTrigger_PleaseSelectAPlan = "",
      audioTrigger_NoFabricationPlans = ""
    },
    Physics = {
      bPhysicalize = 1,
      bRigidBody = 0,
      bPushableByPlayers = 0,
      bPushableByAI = 0,
      bResting = 1,
      Density = -1,
      Mass = -1,
      bArticulated = 0,
      bBulletCollisionEnabled = 1
    }
  },
  Editor = {Icon = "Prefab.bmp", IconOnTop = 1},
  IngredientArchetypes = {
    organic = "ArkPickups.Crafting.Ingredients.Organic",
    mineral = "ArkPickups.Crafting.Ingredients.Mineral",
    synthetic = "ArkPickups.Crafting.Ingredients.Synthetic",
    exotic = "ArkPickups.Crafting.Ingredients.Exotic"
  },
  m_vecInteractOffset = {
    x = -0.35,
    y = 0.1,
    z = 0.45
  },
  m_GridSpacingInfo = {rows = 3},
  PropertiesInstance = {
    bUsable = 1,
    bVerbose = 0,
    bStartsPoweredOn = 1,
    bStartsBroken = 0,
    bMovePlayerOnExamine = 1
  }
}
GetArkEntityUtils(ArkFabricator)
SetupCollisionFiltering(ArkFabricator)
function ArkFabricator.SetFromProperties(A0_3865)
  local L1_3866
end
function ArkFabricator.Init(A0_3867, A1_3868)
  if not A0_3867.m_bInit then
    A0_3867.m_bInit = true
    A0_3867:Log("Init")
    A0_3867:SetFromProperties()
  end
end
function ArkFabricator.OnSpawn(A0_3869)
  A0_3869:Log("OnSpawn")
end
function ArkFabricator.OnReset(A0_3870)
  A0_3870:Log("OnReset")
  A0_3870:SetFromProperties()
  A0_3870.m_bInit = false
end
function ArkFabricator.Event_PowerOn(A0_3871)
  Ark.SetFabricatorPowered(A0_3871.id, true)
end
function ArkFabricator.Event_PowerOff(A0_3872)
  Ark.SetFabricatorPowered(A0_3872.id, false)
end
ArkFabricator.FlowEvents = {
  Inputs = {
    PowerOn = {
      ArkFabricator.Event_PowerOn,
      "bool"
    },
    PowerOff = {
      ArkFabricator.Event_PowerOff,
      "bool"
    }
  },
  Outputs = {
    InUse = "bool",
    Fabricating = "bool",
    Standby = "bool",
    PoweredOn = "bool",
    PoweredOff = "bool",
    CraftedItemName = "string",
    CraftedItemEntity = "entity",
    RepairBox = "entity"
  }
}
