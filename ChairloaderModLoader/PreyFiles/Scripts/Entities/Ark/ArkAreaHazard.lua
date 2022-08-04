Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkAreaHazard = {
  Properties = {
    bUseSafeCarry = false,
    object_Model = "",
    carryHeightOffset = 0,
    carryForwardOffset = 0,
    signalpackage_AreaHazard = "",
    fAreaHazardRadius = 1,
    nAreaHazardInterval = 1000,
    ability_CarryRequirement = "",
    material_IntactMaterial = "",
    material_HazardMaterial = "",
    signalGroup_Damaging = "3149325216937655803",
    particleeffect_Hazard = "",
    ei_TransparencyMode = 0,
    textDisplayName = "Name Not Set",
    bHideDisplayName = 0,
    Sound = {
      audioTrigger_Carry = "",
      audioTrigger_HoldCarryStart = "",
      audioTrigger_HoldCarryCancel = ""
    },
    AI = {bUsedAsDynamicObstacle = 0},
    Physics = {
      bPhysicalize = 1,
      bRigidBody = 0,
      bPushableByPlayers = 0,
      bPushableByAI = 0,
      bResting = 1,
      bRigidBodyActive = 1,
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
    },
    RecycleData = {
      organic = 0,
      mineral = 0,
      synthetic = 0,
      exotic = 0
    }
  },
  Editor = {Icon = "Hazard.bmp", IconOnTop = 1},
  PropertiesInstance = {bHazardStartsActive = 0, bUsedAsDynamicObstacle = 1}
}
GetArkEntityUtils(ArkAreaHazard)
SetupCollisionFiltering(ArkAreaHazard)
function ArkAreaHazard.Init(A0_3469, A1_3470)
  A0_3469:Log("Initializing...")
end
function ArkAreaHazard.SetFromProperties(A0_3471)
  local L1_3472
  L1_3472 = A0_3471.Properties
  A0_3471:SetDisplayName(A0_3471.Properties.textDisplayName)
end
function ArkAreaHazard.GetUsable(A0_3473)
  local L2_3474
  L2_3474 = {}
  L2_3474.Use, ({}).ActionType = {}, "Carry"
  return L2_3474
end
function ArkAreaHazard.GetRemoteManipulationInteraction(A0_3475)
  local L1_3476
  L1_3476 = {}
  L1_3476.ActionType = "Carry"
  L1_3476.CouldChange = false
  return L1_3476
end
function ArkAreaHazard.OnReset(A0_3477, A1_3478)
  A0_3477:SetFromProperties()
end
function ArkAreaHazard.OnSpawn(A0_3479)
  A0_3479:SetFromProperties()
end
