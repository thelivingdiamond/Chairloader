Script.ReloadScript("scripts/entities/ark/ArkKiosk.lua")
ArkOxygenRefillStation = {
  Properties = {
    ei_ObjectMapIcon = "",
    textKioskHeaderText = "",
    textButtonHeaderText = "",
    textButtonBodyText = "",
    bSurvivalModeOnly = 1,
    Sound = {audioTrigger_RefillOxygen = ""}
  },
  PropertiesInstance = {
    bVerbose = 0,
    bStartsPowered = 1,
    bMovePlayerOnExamine = 1
  }
}
ArkMakeDerivedEntityOverride(ArkOxygenRefillStation, ArkKiosk, true)
SetupCollisionFiltering(ArkOxygenRefillStation)
function ArkOxygenRefillStation.InitDisplay(A0_4431)
  local L1_4432
  L1_4432 = A0_4431.Properties
  ArkKioskScript.SetKioskHeader(A0_4431.id, L1_4432.textKioskHeaderText)
  ArkKioskScript.SetKioskButtonHeader(A0_4431.id, 1, L1_4432.textButtonHeaderText)
  ArkKioskScript.SetKioskButtonBody(A0_4431.id, 1, L1_4432.textButtonBodyText)
  ArkKioskScript.SetKioskButtonState(A0_4431.id, 1, 1)
end
function ArkOxygenRefillStation.ButtonOnePressed(A0_4433)
  local L1_4434
  L1_4434 = Sound
  L1_4434 = L1_4434.GetAudioTriggerID
  L1_4434 = L1_4434(A0_4433.Properties.Sound.audioTrigger_RefillOxygen)
  g_localActor:ExecuteAudioTrigger(L1_4434, A0_4433:GetDefaultAuxAudioProxyID())
  g_localActor.arkPlayer:RefillOxygen()
  BroadcastEvent(A0_4433, "Used")
end
function ArkOxygenRefillStation.Init(A0_4435, A1_4436)
  if not A0_4435.m_bInit then
    A0_4435:Log("Initializing...")
    A0_4435.m_bInit = true
    A0_4435:SetFromProperties()
    if A1_4436 then
      A0_4435:InitDisplay()
    end
  end
end
ArkOxygenRefillStation.FlowEvents = {
  Inputs = {
    PowerOn = {
      ArkOxygenRefillStation.Event_KioskPowerOn,
      "bool"
    },
    PowerOff = {
      ArkOxygenRefillStation.Event_KioskPowerOff,
      "bool"
    }
  },
  Outputs = {
    Used = "bool",
    PoweredOn = "bool",
    PoweredOff = "bool"
  }
}
