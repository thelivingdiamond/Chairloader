Script.ReloadScript("scripts/ArkEntityUtils.lua")
Script.ReloadScript("scripts/Entities/Ark/ArkBasicEntity.lua")
ArkOperatorDispenser = {
  Properties = {
    object_Model = "",
    object_Screen = "",
    sUIElementName = "",
    nSubMatIndex = 0,
    sScreenBoneName = "",
    fInteractDistance = 1,
    fActiveDistance = 15,
    fInteractAngle = 75,
    bEnableCollisionInteraction = 1,
    ability_HackRequirement = "",
    ability_DahlHackRequirement = "3149325216928600154",
    textDisplayName = "",
    sSpawnAttachment = "helper_spawn",
    vector_OperatorTarget = {
      x = 0,
      y = 0,
      z = 0
    },
    archetype_OperatorArchetype = "",
    nMaxNumOperators = 0,
    nMaxLifetimeOperators = -1,
    nAutospawnDuration = -1,
    vector_ObstructionTestCenter = {
      x = 0,
      y = 0,
      z = 0
    },
    vector_ObstructionTestSize = {
      x = 0,
      y = 0,
      z = 0
    },
    character_DialogCharacter = "",
    ei_ObjectMapIcon = "",
    material_ScreensaverMaterial = "",
    material_PowerOffMaterial = "",
    bDisallowGrenades = true,
    particleeffect_IdleVFX = "Interactables.OperatorDispenser.Idle_00",
    signalmodifier_SpawnModifier = "243995946810793617",
    operatorSpeed = 5,
    gameNoiseLoudness_GameNoiseLoudness = "9469288860501649195",
    gameNoiseType_GameNoiseType = "9469288860501998057",
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
    Repair = {
      textDisplayNameBroken = "",
      archetype_RepairBox = "",
      sRepairAttachment = ""
    },
    Animation = {animation_Open = "", animation_Close = ""},
    Physics = {
      bPhysicalize = 1,
      bRigidBody = 0,
      bPushableByPlayers = 0,
      bPushableByAI = 0,
      Density = -1,
      Mass = -1
    },
    Sound = {audioTrigger_PowerLP = ""},
    MaterialOverride = {
      attachment = "",
      material_Material = "",
      nSubMtlId = 0
    }
  },
  Editor = {
    Icon = "Prefab.bmp",
    IconOnTop = 1,
    IsScalable = false
  },
  PropertiesInstance = {
    character_Password = "",
    bStartsPoweredOn = 1,
    bStartsUnlocked = 0,
    bStartsBroken = 0,
    bVerbose = 0,
    bMovePlayerOnExamine = 1,
    ability_HackRequirementOverride = ""
  }
}
GetArkEntityUtils(ArkOperatorDispenser)
SetupCollisionFiltering(ArkOperatorDispenser)
ArkMakeHackable(ArkOperatorDispenser)
function ArkOperatorDispenser.Init(A0_4413, A1_4414)
end
function ArkOperatorDispenser.SetFromProperties(A0_4415)
  local L1_4416
end
function ArkOperatorDispenser.Event_PowerOn(A0_4417)
  Ark.SetOperatorDispenserPowered(A0_4417.id, true)
end
function ArkOperatorDispenser.Event_PowerOff(A0_4418)
  Ark.SetOperatorDispenserPowered(A0_4418.id, false)
end
function ArkOperatorDispenser.Event_Lock(A0_4419)
  Ark.SetOperatorDispenserLocked(A0_4419.id, true)
end
function ArkOperatorDispenser.Event_Unlock(A0_4420)
  Ark.SetOperatorDispenserLocked(A0_4420.id, false)
end
function ArkOperatorDispenser.Event_Spawn(A0_4421)
  Ark.ForceOperatorDispenserSpawn(A0_4421.id)
end
function ArkOperatorDispenser.Event_AssignOperator(A0_4422, A1_4423, A2_4424)
  Ark.OperatorDispenserAssignOperator(A0_4422.id, A2_4424.id)
end
function ArkOperatorDispenser.Event_DahlOn(A0_4425)
  Ark.OperatorDispenserOverrideValues(A0_4425.id, "ArkRobots.Operators\\Generic.MilitaryOperator", 3, 6, 30)
end
function ArkOperatorDispenser.Event_DahlOff(A0_4426)
  Ark.OperatorDispenserClearOverrides(A0_4426.id)
end
function ArkOperatorDispenser.OnReset(A0_4427)
  local L1_4428
end
function ArkOperatorDispenser.OnSpawn(A0_4429)
  local L1_4430
end
ArkOperatorDispenser.FlowEvents = {
  Inputs = {
    PowerOn = {
      ArkOperatorDispenser.Event_PowerOn,
      "bool"
    },
    PowerOff = {
      ArkOperatorDispenser.Event_PowerOff,
      "bool"
    },
    Unlock = {
      ArkOperatorDispenser.Event_Unlock,
      "bool"
    },
    Lock = {
      ArkOperatorDispenser.Event_Lock,
      "bool"
    },
    Spawn = {
      ArkOperatorDispenser.Event_Spawn,
      "bool"
    },
    AssignOperator = {
      ArkOperatorDispenser.Event_AssignOperator,
      "entity"
    },
    DahlOverrideOn = {
      ArkOperatorDispenser.Event_DahlOn,
      "bool"
    },
    DahlOverrideOff = {
      ArkOperatorDispenser.Event_DahlOff,
      "bool"
    }
  },
  Outputs = {
    Used = "bool",
    Locked = "bool",
    Unlocked = "bool",
    Processing = "bool",
    Error = "bool",
    Overridden = "bool",
    OperatorEntityId = "entity",
    OperatorIndex = "int",
    ScriptedSpawn = "bool",
    SpawnFinished = "entity",
    RepairBox = "entity"
  }
}
