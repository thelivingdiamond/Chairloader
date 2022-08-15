Script.ReloadScript("scripts/Entities/Ark/ArkKeypad.lua")
Script.ReloadScript("scripts/Entities/Ark/ArkKeycardReader.lua")
Script.ReloadScript("scripts/Entities/Ark/ArkInteractiveObject.lua")
ArkDoor = {
  Properties = {
    object_Model = "",
    object_KeypadModel = "",
    object_FreeExitModel = "",
    signalpackage_DamagePackage = "",
    archetype_Keypad = "",
    archetype_KeycardReader = "",
    archetype_FreeExitButton = "",
    ei_ObjectMapIcon = "",
    textMessageLockedAndUnpowered = "",
    textMessageUnlockedAndUnpowered = "",
    textMessageLockedAndManual = "",
    textMessageUnlockedAndManual = "",
    textPromptManualOpen = "",
    textPromptManualClose = "",
    textPromptButtonVerb = "",
    textPromptUseAbility = "",
    ability_HackRequirement = "",
    ability_PryOpenRequirement = "",
    nHoldToUseDuration = 1000,
    bDisruptable = 0,
    bActivatePortal = 0,
    bIsOnlyBackSideUsable = 0,
    fInteractDistanceOverride = 0,
    bNoFriendlyFire = 0,
    triggerLength = 5,
    triggerWidth = 3,
    triggerHeight = 3,
    allowedPenetration = 0.31,
    openTimer = 3,
    ignoreCollisionTimer = 5,
    NavAgentTypes = "MediumSizedCharacters ArkOperator ArkAlien_Small ArkAlien_Medium ArkWeaver ArkEtherForm",
    bDisallowGrenades = true,
    vector_InteractionOffset = {
      x = 0,
      y = 0,
      z = 1.6
    },
    vector_linkOffset = {
      x = 0,
      y = 0,
      z = 0
    },
    Glow = {
      sDoorSkinAttachmentName = "door_skin",
      color_LockedColor = {
        x = 1,
        y = 0,
        z = 0
      },
      color_UnlockedColor = {
        x = 0,
        y = 1,
        z = 0
      },
      color_UnpoweredColor = {
        x = 1,
        y = 1,
        z = 1
      },
      fLockedGlowAmount = 50,
      fUnlockedGlowAmount = 50,
      fUnpoweredGlowAmount = 0,
      nGlowSubmatIdA = 0,
      nGlowSubmatIdB = -1,
      bUseGlow = 0,
      bModelIsCGF = 0
    },
    KeypadBoneNames = {
      left = {outside = "", inside = ""},
      right = {outside = "", inside = ""}
    },
    Signals = {signal_Goo = ""},
    Sound = {
      audioTrigger_Open = "",
      audioTrigger_Close = "",
      audioTrigger_Locked = ""
    },
    Animation = {
      anim_Open = "Default",
      anim_Close = "",
      anim_PryIn = "Open_Leverage_In",
      anim_PryLoop = "Open_Leverage",
      anim_PryOpen = "Open_Leverage_Out",
      anim_PryCancel = "Cancel_Leverage"
    },
    Pry = {
      bPryable = 1,
      sFrontAttachment = "pry_front",
      sBackAttachment = "pry_back",
      fragment_PlayerIn = "Door_PryIn",
      fragment_PlayerOut = "Door_PryOut",
      fragment_PlayerCancel = "Door_PryCancel",
      fLerpSpeed = 5,
      fAngularLerp = 3
    },
    Physics = {
      bPhysicalize = 1,
      bArticulated = 1,
      bPushableByPlayers = 0,
      bPushableByAI = 0,
      Density = -1,
      Mass = -1
    },
    Portal = {
      bHasAudioPortal = 0,
      fWidth = 1,
      fHeight = 1,
      fMinOcclusion = 0,
      fMaxOcclusion = 1,
      fMinHazardOcclusion = 0,
      fMaxHazardOcclusion = 1,
      vectorOffset = ""
    },
    Disrupt = {
      disruptionProfile_Profile = "10739735956140212131",
      particleeffect_SparkVFX = "",
      audioTrigger_SparkSFX = "",
      sSparkAttachment = ""
    }
  },
  PropertiesInstance = {
    nKeypads = 0,
    keycode_UnlockCode = "",
    keycard_UnlockKeycard = "",
    bKeypadsOnLeftSide = 1,
    bUseKeycardReaders = 0,
    bStartsLocked = 0,
    bStartsOpen = 0,
    bUseFreeExitButton = 0,
    vector_FreeExitOffset = {
      x = 0,
      y = 0,
      z = 0
    },
    bStartsPoweredOn = 1,
    TriggerDimensionsOverride = {
      triggerLength = 0,
      triggerWidth = 0,
      triggerHeight = 0
    },
    ability_HackRequirementOverride = "",
    bVerbose = 0,
    vectorPortalOffset = "",
    MaterialOverride = {
      attachment = "",
      material_Material = "",
      nSubMtlId = 0
    }
  },
  Editor = {
    IconOnTop = true,
    Icon = "Door.bmp",
    ShowBounds = 0,
    IsScalable = false
  }
}
GetArkEntityUtils(ArkDoor)
SetupCollisionFiltering(ArkDoor)
ArkMakeLockable(ArkDoor)
ArkMakeSaveable(ArkDoor)
ArkDoorInstanceVars = {
  m_insideController = false,
  m_outsideController = false,
  m_referenceTable = false,
  m_bInit = false,
  m_bVerbose = false,
  m_bUseKeycardReader = false,
  m_bUseLeftSide = false,
  m_bUseFreeExit = false,
  m_currentSound = false,
  m_bIsPowerSupplied = false,
  m_bIsDisrupted = false,
  m_bLocked = false,
  m_audioIds = {}
}
function CreateArkDoor(A0_3653)
  mergef(A0_3653, ArkDoorInstanceVars, 1)
  A0_3653.m_referenceTable = ArkDoorInstanceVars
end
function ArkDoor.Init(A0_3654, A1_3655)
  if not A0_3654.m_bInit then
    A0_3654.m_bInit = true
    A0_3654:SetFromProperties()
    if A1_3655 then
      if A0_3654.PropertiesInstance.nKeypads > 0 or A0_3654.m_bUseFreeExit then
        A0_3654:FreeSlot(1)
        A0_3654:FreeSlot(2)
        A0_3654:SetupAccessControl(A0_3654.m_bUseKeycardReader, A0_3654.PropertiesInstance.nKeypads, A0_3654.m_bUseLeftSide, A0_3654.m_bUseFreeExit, A0_3654.PropertiesInstance.vector_FreeExitOffset)
      end
      if A0_3654:IsPowered() then
        A0_3654:Event_PowerOn()
      else
        A0_3654:Event_PowerOff()
      end
      A0_3654:SetIsDoorLocked(A0_3654.m_bLocked)
    end
  end
end
function ArkDoor.DoFunctionOnControllers(A0_3656, A1_3657, A2_3658)
  A0_3656:ControllerFunction(A0_3656.m_outsideController, A1_3657)
  if A2_3658 or not A0_3656.m_bUseFreeExit then
    A0_3656:ControllerFunction(A0_3656.m_insideController, A1_3657)
  end
end
function ArkDoor.ControllerFunction(A0_3659, A1_3660, A2_3661, A3_3662, A4_3663)
  local L5_3664
  if A1_3660 then
    L5_3664 = A1_3660[A2_3661]
    L5_3664(A1_3660, A3_3662, A4_3663)
  end
end
function ArkDoor.SetDoorGlow(A0_3665)
  local L1_3666, L2_3667, L3_3668, L4_3669
  L1_3666 = A0_3665.Properties
  L1_3666 = L1_3666.Glow
  L2_3667, L3_3668 = nil, nil
  L4_3669 = "unset"
  if L1_3666.bUseGlow == 1 then
    if A0_3665:IsPowered() then
      if A0_3665.m_bLocked then
        L2_3667 = L1_3666.color_LockedColor
        L3_3668 = L1_3666.fLockedGlowAmount
        L4_3669 = "locked"
      else
        L2_3667 = L1_3666.color_UnlockedColor
        L3_3668 = L1_3666.fUnlockedGlowAmount
        L4_3669 = "unlocked"
      end
    else
      L2_3667 = L1_3666.color_UnpoweredColor
      L3_3668 = L1_3666.fUnpoweredGlowAmount
      L4_3669 = "unpowered"
    end
    if L1_3666.bModelIsCGF == 1 then
      A0_3665:SetMaterialFloat(0, L1_3666.nGlowSubmatIdA, MaterialFloatParams.emissive_intensity, L3_3668)
      A0_3665:SetMaterialVec3(0, L1_3666.nGlowSubmatIdA, MaterialVec3Params.emissive_color, L2_3667)
      if 0 <= L1_3666.nGlowSubmatIdB then
        A0_3665:SetMaterialFloat(0, L1_3666.nGlowSubmatIdB, MaterialFloatParams.emissive_intensity, L3_3668)
        A0_3665:SetMaterialVec3(0, L1_3666.nGlowSubmatIdB, MaterialVec3Params.emissive_color, L2_3667)
      end
    else
      A0_3665:SetAttachmentMaterialFloat(0, L1_3666.sDoorSkinAttachmentName, L1_3666.nGlowSubmatIdA, MaterialFloatParams.emissive_intensity, L3_3668)
      A0_3665:SetAttachmentMaterialVec3(0, L1_3666.sDoorSkinAttachmentName, L1_3666.nGlowSubmatIdA, MaterialVec3Params.emissive_color, L2_3667)
      if 0 <= L1_3666.nGlowSubmatIdB then
        A0_3665:SetAttachmentMaterialFloat(0, L1_3666.sDoorSkinAttachmentName, L1_3666.nGlowSubmatIdB, MaterialFloatParams.emissive_intensity, L3_3668)
        A0_3665:SetAttachmentMaterialVec3(0, L1_3666.sDoorSkinAttachmentName, L1_3666.nGlowSubmatIdB, MaterialVec3Params.emissive_color, L2_3667)
      end
    end
    A0_3665:Log("DOOR EMISSIVE SET " .. L4_3669)
  end
end
function ArkDoor.UpdateForEditorDisplay(A0_3670)
  A0_3670:LoadAccessControllersForEditor(A0_3670.PropertiesInstance.nKeypads, A0_3670.m_bUseLeftSide, A0_3670.m_bUseFreeExit, A0_3670.PropertiesInstance.vector_FreeExitOffset)
  A0_3670:SetDoorGlow()
end
function ArkDoor.SetFromProperties(A0_3671)
  GetAudioIds(A0_3671.Properties.Sound, A0_3671.m_audioIds)
  A0_3671.m_bUseKeycardReader = A0_3671.PropertiesInstance.bUseKeycardReaders == 1
  A0_3671.m_bUseLeftSide = A0_3671.PropertiesInstance.bKeypadsOnLeftSide == 1
  A0_3671.m_bUseFreeExit = A0_3671.PropertiesInstance.bUseFreeExitButton == 1
  A0_3671.m_bIsPowerSupplied = A0_3671.PropertiesInstance.bStartsPoweredOn == 1
  A0_3671.m_bLocked = A0_3671.PropertiesInstance.bStartsLocked == 1
  A0_3671.m_bVerbose = A0_3671.PropertiesInstance.bVerbose == 1
  if A0_3671.Properties.Glow.bUseGlow == 1 then
    if A0_3671.Properties.Glow.bModelIsCGF == 1 then
      A0_3671:CloneMaterial(0)
    else
      A0_3671:CloneAttachmentMaterial(0, A0_3671.Properties.Glow.sDoorSkinAttachmentName)
    end
  end
end
function ArkDoor.Reset(A0_3672)
  A0_3672:SetFromProperties()
  A0_3672:SetIsDoorLocked(A0_3672.m_bLocked)
end
function ArkDoor.IsPowered(A0_3673)
  local L1_3674
  L1_3674 = A0_3673.m_bIsPowerSupplied
  if L1_3674 then
    L1_3674 = A0_3673.m_bIsDisrupted
    L1_3674 = not L1_3674
  end
  return L1_3674
end
function ArkDoor.UpdatePowerState(A0_3675)
  if A0_3675:IsPowered() then
    A0_3675:DoFunctionOnControllers("Event_PowerOn", true)
    BroadcastEvent(A0_3675, "PoweredOn")
  else
    A0_3675:DoFunctionOnControllers("Event_PowerOff", true)
    BroadcastEvent(A0_3675, "PoweredOff")
  end
  Ark.PowerDoor(A0_3675.id, A0_3675.m_bIsPowerSupplied)
  A0_3675:SetDoorGlow()
end
function ArkDoor.SetIsDoorLocked(A0_3676, A1_3677)
  local L2_3678, L3_3679
  L2_3678 = "Lock"
  if not A1_3677 then
    L2_3678 = "Unlock"
  end
  L3_3679 = "Event_"
  L3_3679 = L3_3679 .. L2_3678
  if A0_3676.m_bLocked ~= A1_3677 then
    BroadcastEvent(A0_3676, L2_3678)
  end
  A0_3676:Log(L3_3679)
  A0_3676:DoFunctionOnControllers(L3_3679, false)
  if A0_3676.m_bUseFreeExit then
    if A1_3677 then
      A0_3676:ControllerFunction(A0_3676.m_insideController, "Event_Deactivate")
    else
      A0_3676:ControllerFunction(A0_3676.m_insideController, "Event_Activate")
    end
  end
  A0_3676.m_bLocked = A1_3677
  Ark.LockDoor(A0_3676.id, A1_3677)
  A0_3676:SetDoorGlow()
end
function ArkDoor.OnPostLoad(A0_3680)
  A0_3680:UpdatePowerState()
end
function ArkDoor.OnSave(A0_3681, A1_3682)
  for _FORV_5_, _FORV_6_ in pairs(A0_3681.m_referenceTable) do
    A1_3682[_FORV_5_] = A0_3681[_FORV_5_]
  end
end
function ArkDoor.OnInit(A0_3683)
  A0_3683:Log("OnInit")
  if System.IsEditor() then
    A0_3683:Init()
    A0_3683:UpdateForEditorDisplay()
  end
end
function ArkDoor.OnPropertyChange(A0_3684)
  A0_3684:Reset()
  A0_3684:UpdateForEditorDisplay()
  A0_3684:Log("OnPropertyChange")
end
function ArkDoor.OnReset(A0_3685)
  A0_3685:Log("OnReset")
  A0_3685:Activate(0)
  A0_3685.m_bInit = false
  A0_3685.m_outsideController = false
  A0_3685.m_insideController = false
  A0_3685:Reset()
  A0_3685:UpdateForEditorDisplay()
end
function ArkDoor.OnSpawn(A0_3686)
  CreateArkDoor(A0_3686)
  A0_3686:Log("OnSpawn")
  A0_3686:Reset()
end
function ArkDoor.Event_Disrupted(A0_3687, A1_3688)
  A0_3687:Log("Event_Disrupted: " .. tostring(A1_3688))
  A0_3687.m_bIsDisrupted = A1_3688
  A0_3687:UpdatePowerState()
end
function ArkDoor.Event_PowerOn(A0_3689)
  A0_3689:Log("Event_PowerOn")
  A0_3689.m_bIsPowerSupplied = true
  A0_3689:UpdatePowerState()
end
function ArkDoor.Event_PowerOff(A0_3690)
  A0_3690:Log("Event_PowerOff")
  A0_3690.m_bIsPowerSupplied = false
  A0_3690:UpdatePowerState()
end
function ArkDoor.Event_Unlock(A0_3691)
  A0_3691:SetIsDoorLocked(false)
  if A0_3691:IsPowered() then
    Ark.OpenDoor(A0_3691.id)
  end
end
function ArkDoor.Event_Lock(A0_3692)
  A0_3692:SetIsDoorLocked(true)
end
function ArkDoor.Event_Open(A0_3693)
  A0_3693:Log("Event_Open")
  Ark.OpenDoor(A0_3693.id)
end
function ArkDoor.Event_Close(A0_3694)
  A0_3694:Log("Event_Close")
  Ark.CloseDoor(A0_3694.id)
end
function ArkDoor.Event_Hide(A0_3695)
  A0_3695:Hide(1)
  if A0_3695.m_insideController then
    A0_3695.m_insideController:Hide(1)
  end
  if A0_3695.m_outsideController then
    A0_3695.m_outsideController:Hide(1)
  end
  A0_3695:ActivateOutput("Hide", true)
end
function ArkDoor.Event_UnHide(A0_3696)
  A0_3696:Hide(0)
  if A0_3696.m_insideController then
    A0_3696.m_insideController:Hide(0)
  end
  if A0_3696.m_outsideController then
    A0_3696.m_outsideController:Hide(0)
  end
  A0_3696:ActivateOutput("UnHide", true)
end
function ArkDoor.OnObstructed(A0_3697, A1_3698, A2_3699)
  if A2_3699 then
    A0_3697:Log(A2_3699:GetName() .. " is obstructing")
  else
    A0_3697:Log("entityId: " .. tostring(A1_3698) .. " has no script table and is obstructing")
  end
  Ark.SendSignalPackage(A1_3698, A0_3697.id, A0_3697.id, A0_3697.Properties.signalpackage_DamagePackage)
  A0_3697:ActivateOutput("Obstructed", true)
end
ArkDoor.FlowEvents = {
  Inputs = {
    Close = {
      ArkDoor.Event_Close,
      "bool"
    },
    Open = {
      ArkDoor.Event_Open,
      "bool"
    },
    Lock = {
      ArkDoor.Event_Lock,
      "bool"
    },
    Unlock = {
      ArkDoor.Event_Unlock,
      "bool"
    },
    Hide = {
      ArkDoor.Event_Hide,
      "bool"
    },
    UnHide = {
      ArkDoor.Event_UnHide,
      "bool"
    },
    PowerOn = {
      ArkDoor.Event_PowerOn,
      "bool"
    },
    PowerOff = {
      ArkDoor.Event_PowerOff,
      "bool"
    }
  },
  Outputs = {
    Close = "bool",
    Open = "bool",
    Lock = "bool",
    Unlock = "bool",
    Hide = "bool",
    UnHide = "bool",
    Obstructed = "bool",
    Hacked = "bool",
    Failed = "bool",
    PoweredOn = "bool",
    PoweredOff = "bool",
    Opening = "bool",
    Closing = "bool",
    Prying = "bool",
    PryingCanceled = "bool"
  }
}
