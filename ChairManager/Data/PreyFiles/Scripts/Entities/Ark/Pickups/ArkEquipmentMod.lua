Script.ReloadScript("Scripts/Entities/Ark/Pickups/ArkItem.lua")
ArkEquipmentMod = {
  Properties = {
    bConsumable = false,
    bUsable = true,
    object_GeometryTP = "objectsenvironmentpropsgameplaymod_suit_pickup_amod_suit_pickup_a.cgf",
    EquipmentMod = {
      bSuitMod = true,
      signalModifiers_inboundSignalMods = "",
      signalModifiers_outboundSignalMods = "",
      signalModifiers_inboundActivationSignalMods = "",
      signalModifiers_outboundActivationSignalMods = "",
      playerStatModPkgs_statMods = "",
      chipsetArchetypes_exclusives = "",
      signalPackage_package = ""
    },
    audioTrigger_installFailed = "Play_Container_Cannot_Loot"
  }
}
ArkMakeDerivedEntityOverride(ArkEquipmentMod, ArkItem, true)
ArkPsychoscopeMod = ArkEquipmentMod
