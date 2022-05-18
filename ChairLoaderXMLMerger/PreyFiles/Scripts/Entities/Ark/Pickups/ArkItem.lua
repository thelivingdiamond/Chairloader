Script.ReloadScript("Scripts/ArkEntityUtils.lua")
ArkItem = {
  Properties = {
    Sound = {audioTrigger_PickupSFX = "", audioTrigger_InventorySFX = ""},
    Physics = {
      bPhysicalize = 1,
      bRigidBody = 1,
      bResting = 1,
      bPushableByPlayers = 1,
      bPushableByAI = 1,
      Density = 100,
      Mass = -1
    },
    sType = "",
    object_GeometryTP = "",
    material_MaterialTP = "",
    object_GeometryFP = "",
    material_MaterialFP = "",
    textDisplayName = "@i_defaultPickup",
    textDescription = "",
    metaTags_ArkMetaTags = "",
    glintconfig_GlintConfig = "16934642289625103724",
    bImportant = 0,
    gameMetric_MetricPickedUp = "",
    iDismantleCount = 0,
    bDisallowGrenades = true,
    Stacks = {
      iCount = 1,
      iMaxCount = 10,
      iFabricationCount = 0,
      iRandomMin = 1,
      iRandomMax = 10,
      bRandomizeCount = 0,
      bStackable = 0,
      iDropIncrement = 1
    },
    fLerpSpeed = 9,
    Inventory = {
      bAddToInventory = 1,
      iWidth = 1,
      iHeight = 1,
      sIcon = "",
      ei_ItemCategory = 0
    },
    RecycleData = {
      organic = 0,
      mineral = 0,
      synthetic = 0,
      exotic = 0
    },
    bConsumable = 1,
    bDroppable = 1,
    bUsable = 0,
    bIsMimicable = true,
    bIsRandom = 0,
    bUniqueRandom = 0,
    bAvailableForRandom = 1,
    bCanBeFavorited = 0,
    bIsTrash = 0,
    bIsPlotCritical = 0,
    sHUDIcon = "",
    sStylizedIcon = "",
    bSurvivalMode = false,
    fDropDistance = 2,
    fDropHeightOffset = 0,
    fDropRotationMin = 1,
    fDropRotationMax = 15,
    bCanTriggerAreas = 0,
    bGooCannotAttachInGravity = 0,
    Silhouette = {
      color_RGB = {
        x = 1,
        y = 1,
        z = 1
      },
      fAlpha = 0.25
    }
  },
  PropertiesInstance = {iCountOverride = 0},
  Editor = {
    Icon = "Seed.bmp",
    IconOnTop = 1,
    IsScalable = false
  },
  m_bVerbose = false,
  m_usable = 1,
  m_bWasPickedUp = false,
  displayName = "",
  inventoryName = ""
}
GetArkEntityUtils(ArkItem)
SetupCollisionFiltering(ArkItem)
function ArkItem.GetRemoteManipulationInteraction(A0_3155)
  local L1_3156
  L1_3156 = {}
  L1_3156.ActionType = "Pickup"
  L1_3156.CouldChange = false
  return L1_3156
end
function ArkItem.PlaySFX(A0_3157, A1_3158)
  local L2_3159
  L2_3159 = Sound
  L2_3159 = L2_3159.GetAudioTriggerID
  L2_3159 = L2_3159(A1_3158)
  g_localActor:ExecuteAudioTrigger(L2_3159, A0_3157:GetDefaultAuxAudioProxyID())
end
function ArkItem.SetItemUsable(A0_3160)
  local L1_3161
  A0_3160.m_usable = 1
end
function ArkItem.IsPlotCritical(A0_3162)
  return A0_3162.Properties.bIsPlotCritical
end
function ArkItem.OnRandomArchetypeSet(A0_3163)
  A0_3163:UpdateDisplayName()
end
function ArkItem.UpdateDisplayName(A0_3164)
  local L1_3165
  L1_3165 = A0_3164.Properties
  L1_3165 = L1_3165.textDisplayName
  A0_3164.displayName = L1_3165
end
function ArkItem.UpdateInventoryName(A0_3166)
  return A0_3166.Properties.textDisplayName
end
function ArkItem.PickUp(A0_3167, A1_3168)
  return (A0_3167.arkitem:PickUp(g_localActor.id, A1_3168))
end
function ArkItem.OnUpdateAppearance(A0_3169)
  A0_3169:Log("OnUpdateAppearance not overriden or unused")
end
function ArkItem.Event_Hide(A0_3170)
  A0_3170:Hide(1)
end
function ArkItem.Event_Unhide(A0_3171)
  A0_3171:Hide(0)
end
function ArkItem.OnPickup(A0_3172, A1_3173)
  A0_3172.m_bWasPickedUp = true
  BroadcastEvent(A0_3172, "OnPickup")
  A0_3172:ActivateOutput("ItemType", A0_3172.Properties.sType)
  A0_3172:UpdateDisplayName()
  Ark.ModifyGameMetric(A0_3172.Properties.gameMetric_MetricPickedUp, A0_3172.arkitem:GetCount())
  A0_3172.arkitem:SetPhysicalizeAsStatic(false, false)
end
function ArkItem.OnUsedFromInventory(A0_3174, A1_3175)
  if A1_3175 == g_localActor then
    A0_3174:PlaySFX(A0_3174.Properties.Sound.audioTrigger_InventorySFX)
  end
  A0_3174:ActivateOutput("UsedFromInventory", true)
end
function ArkItem.OnUsedFromWorld(A0_3176, A1_3177)
  A0_3176:Log("OnUsedFromWorld not overridden.")
end
function ArkItem.OnInventoryTransfer(A0_3178, A1_3179, A2_3180)
  A0_3178:Log("ArkItem:OnInventoryTransfer")
  if A2_3180 == g_localActor then
    A0_3178:Log("target inventory was player")
    A1_3179:RegisterListenerForOnMyContainerClose(A0_3178)
  else
    A0_3178:Log("target inventory was a container")
  end
end
function ArkItem.OnMyContainerClose(A0_3181)
  A0_3181:Log("OnMyContainerClose()")
  BroadcastEvent(A0_3181, "OnMyContainerClose")
end
function ArkItem.OnInit(A0_3182)
  local L1_3183
  L1_3183 = A0_3182.Properties
  L1_3183 = L1_3183.bCanTriggerAreas
  if L1_3183 == 1 then
    L1_3183 = A0_3182.SetFlags
    L1_3183(A0_3182, ENTITY_FLAG_TRIGGER_AREAS, 0)
  else
    L1_3183 = A0_3182.SetFlags
    L1_3183(A0_3182, ENTITY_FLAG_TRIGGER_AREAS, 2)
  end
  L1_3183 = A0_3182.GetMaterial
  L1_3183 = L1_3183(A0_3182)
  if L1_3183 == nil then
    L1_3183 = A0_3182:GetMaterial(0)
  end
end
function ArkItem.OnStartGame(A0_3184)
  A0_3184:Log("OnStartGame")
  if System.IsEditor() then
    A0_3184:Init(true)
  end
end
function ArkItem.Init(A0_3185, A1_3186)
  A0_3185:Log("OnStartGame")
  Ark.SetGlintConfig(A0_3185.id, A0_3185.Properties.glintconfig_GlintConfig)
  if A1_3186 then
    Ark.SetShouldGlint(A0_3185.id, true)
  end
end
function ArkItem.SetupModelAndPhysics(A0_3187, A1_3188)
end
function ArkItem.OnDestroy(A0_3189)
  Ark.SetShouldGlint(A0_3189.id, false)
end
function ArkItem.OnReset(A0_3190, A1_3191)
  Ark.SetShouldGlint(A0_3190.id, false)
end
function ArkItem.OnPostLoad(A0_3192)
  A0_3192:Log("OnPostLoad()")
  Ark.SetShouldGlint(A0_3192.id, true)
end
function ArkItem.OnSpawn(A0_3193)
  A0_3193.bRigidBodyActive = 1
  if not System.IsEditing() then
    Ark.SetGlintConfig(A0_3193.id, A0_3193.Properties.glintconfig_GlintConfig)
    Ark.SetShouldGlint(A0_3193.id, true)
  end
end
function CreateArkItemTable(A0_3194)
  local L1_3195
  L1_3195 = _G
  L1_3195 = L1_3195[A0_3194]
  if not L1_3195 then
    L1_3195 = _G
    L1_3195[A0_3194] = new(ArkItem)
  end
end
function ArkItem.OnUnHidden(A0_3196)
  local L1_3197
end
function ArkItem.CanUse(A0_3198)
  local L1_3199
  L1_3199 = A0_3198.Properties
  L1_3199 = L1_3199.bUsable
  L1_3199 = L1_3199 ~= 0
  return L1_3199
end
function ArkItem.Event_EnableGlint(A0_3200)
  Ark.SetShouldGlint(A0_3200.id, true)
end
function ArkItem.Event_DisableGlint(A0_3201)
  Ark.SetShouldGlint(A0_3201.id, false)
end
function ArkItem.ConsumedItem(A0_3202, A1_3203)
  A0_3202:ActivateOutput("OnConsumed", true)
end
function ArkItem.PhysicalizeThis(A0_3204, A1_3205, A2_3206)
  A0_3204:Log("PhysicalizeThis:  Slot - " .. A1_3205 .. " PhysType - " .. A2_3206)
  EntityCommon.PhysicalizeRigid(A0_3204, A1_3205, A0_3204.Properties.Physics, A0_3204.bRigidBodyActive, A2_3206)
end
ArkItem.FlowEvents = {
  Inputs = {
    Hide = {
      ArkItem.Event_Hide,
      "bool"
    },
    Unhide = {
      ArkItem.Event_Unhide,
      "bool"
    },
    EnableGlint = {
      ArkItem.Event_EnableGlint,
      "bool"
    },
    DisableGlint = {
      ArkItem.Event_DisableGlint,
      "bool"
    }
  },
  Outputs = {
    OnPickup = "bool",
    ItemType = "string",
    UsedFromInventory = "bool",
    OnMyContainerClose = "bool",
    OnConsumed = "bool"
  }
}
