Script.ReloadScript("scripts/ArkEntityUtils.lua")
Script.ReloadScript("scripts/Entities/Ark/ArkBasicEntity.lua")
ArkDockingStation = {
  Properties = {
    object_Model = "objects/environment/props/tech/screen_utility_a/screen_interactive_a.cga",
    object_Screen = "Objects/Environment/Props/Transtar/Screen_Interactive_A/screen_interactive_a_uiquad.cga",
    sUIElementName = "DanielleWorkstationV2",
    nSubMatIndex = 0,
    sScreenBoneName = "helper_screen",
    fInteractDistance = 15,
    fActiveDistance = 2.25,
    fInteractAngle = 75,
    bEnableCollisionInteraction = 1,
    textDisplayName = "@i_DockingStation",
    tutorial_ContextualTutorial = "",
    bHideTutorialOnOwner = 1,
    nContainerSearchDuration = 1000,
    material_ScreensaverMaterial = "Objects/Environment/Props/Gameplay/Screen_Workstation_A/workstation_screensaver",
    material_PowerOffMaterial = "Objects/Environment/Props/Gameplay/Screen_Workstation_A/workstation_poweroff",
    Disrupt = {
      disruptionProfile_Profile = "10739735956140212131",
      particleeffect_SparkVFX = "",
      audioTrigger_SparkSFX = ""
    },
    Physics = {
      bPhysicalize = 1,
      bRigidBody = 0,
      bPushableByPlayers = 0,
      bPushableByAI = 0,
      Density = -1,
      Mass = -1
    },
    Sound = {audioTrigger_PowerLP = ""}
  },
  Editor = {
    Icon = "Prefab.bmp",
    IconOnTop = 1,
    IsScalable = false
  },
  PropertiesInstance = {
    bStartsPowered = 1,
    bVerbose = 0,
    bMovePlayerOnExamine = 1
  }
}
GetArkEntityUtils(ArkDockingStation)
ArkMakeHackable(ArkDockingStation)
function ArkDockingStation.Init(A0_3644, A1_3645)
end
function ArkDockingStation.SetFromProperties(A0_3646)
  local L1_3647
end
function ArkDockingStation.OnReset(A0_3648)
  local L1_3649
end
function ArkDockingStation.OnSpawn(A0_3650)
  local L1_3651
end
function ArkDockingStation.Event_UndockAll(A0_3652)
  BroadcastEvent(A0_3652, "AllUndocked")
end
ArkDockingStation.FlowEvents = {
  Inputs = {
    UndockAll = {
      ArkDockingStation.Event_UndockAll,
      "bool"
    }
  },
  Outputs = {
    Bay1Docked = "bool",
    Bay1Undocked = "bool",
    Bay2Docked = "bool",
    Bay2Undocked = "bool"
  }
}
