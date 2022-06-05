Script.ReloadScript("scripts/ArkEntityUtils.lua")
Script.ReloadScript("scripts/Entities/Ark/ArkBasicEntity.lua")
Script.ReloadScript("scripts/Entities/Ark/ArkWorkstationScreen.lua")
ArkSecurityStationScreen = {
  PropertiesInstance = {
    securitystation_SecurityStation = "",
    bStartsPowered = 1,
    bStartsUnlocked = 0,
    bVerbose = 0,
    bMovePlayerOnExamine = 1,
    ability_HackRequirementOverride = "",
    tutorial_ContextualTutorial = ""
  }
}
ArkMakeDerivedEntityOverride(ArkSecurityStationScreen, ArkWorkstationScreen, true)
function ArkSecurityStationScreen.Event_Refresh(A0_4517)
  Ark.RefreshSecurityStationRoster(A0_4517.id)
end
function ArkSecurityStationScreen.OnSpawn(A0_4518)
  local L1_4519
end
ArkSecurityStationScreen.FlowEvents = {
  Inputs = {
    PowerOn = {
      ArkSecurityStationScreen.Event_PowerOn,
      "bool"
    },
    PowerOff = {
      ArkSecurityStationScreen.Event_PowerOff,
      "bool"
    },
    Refresh = {
      ArkSecurityStationScreen.Event_Refresh,
      "bool"
    }
  },
  Outputs = {
    Used = "bool",
    PoweredOn = "bool",
    PoweredOff = "bool",
    Locked = "bool",
    LoggedIn = "bool",
    RootMenu = "bool",
    EmailApp = "bool",
    EmailAcquired = "string",
    PersonnelUsed = "string",
    UtilityApp = "bool",
    UtilityUsed = "string",
    UtilityOutput = "string"
  }
}
