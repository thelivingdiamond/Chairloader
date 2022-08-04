Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkGravShaft = {
  type = "ArkGravShaftEntity",
  Properties = {
    GravShaft = {
      fSpeed = 3,
      fCenteringSpeed = 3,
      fExitSpeed = 3,
      fBounceSpeedMultiplier = 1,
      fParticleMetersPerSec = 1,
      posteffect_PostProcessVFX = "",
      particleeffect_Object = "",
      particleeffect_FirstPerson = "",
      audioTrigger_PowerOnSFX = "",
      audioTrigger_PowerOffSFX = "",
      audioTrigger_EnterSFX = "",
      audioTrigger_ExitSFX = "",
      audioTrigger_BounceSFX = "",
      bBiDirectional = false
    },
    ei_ObjectMapIcon = "",
    NavAgentTypes = "MediumSizedCharacters ArkAlien_Small ArkAlien_Medium ArkOperator ArkEtherForm"
  },
  PropertiesInstance = {
    GravShaft = {
      DimX = 4,
      DimY = 2.5,
      DimZ = 10,
      fPortalHeight = 1,
      vTravelDirection = {
        x = 0,
        y = 0,
        z = 1
      },
      vEnterDirection = {
        x = 0,
        y = 1,
        z = 0
      },
      vExitDirection = {
        x = 1,
        y = 0,
        z = 0
      },
      bEnabled = 1,
      bDrawDebugEditor = 0,
      bDrawDebugGame = 0,
      bReverseDirection = 0,
      particleeffect_Main = ""
    }
  },
  SoundParams = {fShaftAmbientVolume = 2, fShaftAmbientSoundRadiusMultiplier = 1},
  Editor = {
    Model = "Editor/Objects/T.cgf",
    Icon = "elevator.bmp",
    ShowBounds = 0,
    IsScalable = false,
    IsRotatable = true
  },
  m_bUpdateLinkedEntitiesSetEmpInfluence = false,
  m_bUpdateLinkedEntitiesSetLightScale = false,
  m_bUpdateLinkedEntitiesSetEmpLightScale = false
}
GetArkEntityUtils(ArkGravShaft)
function ArkGravShaft.SetLightScale(A0_3984, A1_3985)
  local L2_3986, L3_3987, L4_3988, L5_3989, L6_3990
  L2_3986 = m_bUpdateLinkedEntitiesSetLightScale
  if L2_3986 ~= true then
    L2_3986 = true
    m_bUpdateLinkedEntitiesSetLightScale = L2_3986
    L2_3986 = A0_3984.CountLinks
    L2_3986 = L2_3986(L3_3987)
    for L6_3990 = 0, L2_3986 - 1 do
      if A0_3984:GetLink(L6_3990) and A0_3984:GetLink(L6_3990).SetLightScale then
        A0_3984:GetLink(L6_3990):SetLightScale(A1_3985)
      end
    end
  end
  L2_3986 = false
  m_bUpdateLinkedEntitiesSetLightScale = L2_3986
end
function ArkGravShaft.SetEmpLightScale(A0_3991, A1_3992)
  local L2_3993, L3_3994, L4_3995, L5_3996, L6_3997
  L2_3993 = m_bUpdateLinkedEntitiesSetEmpLightScale
  if L2_3993 ~= true then
    L2_3993 = true
    m_bUpdateLinkedEntitiesSetEmpLightScale = L2_3993
    L2_3993 = A0_3991.CountLinks
    L2_3993 = L2_3993(L3_3994)
    for L6_3997 = 0, L2_3993 - 1 do
      if A0_3991:GetLink(L6_3997) and A0_3991:GetLink(L6_3997).SetEmpLightScale then
        A0_3991:GetLink(L6_3997):SetEmpLightScale(A1_3992)
      end
    end
  end
  L2_3993 = false
  m_bUpdateLinkedEntitiesSetEmpLightScale = L2_3993
end
function ArkGravShaft.SetEmpInfluence(A0_3998, A1_3999)
  local L2_4000, L3_4001, L4_4002, L5_4003, L6_4004
  L2_4000 = m_bUpdateLinkedEntitiesSetEmpInfluence
  if L2_4000 ~= true then
    L2_4000 = true
    m_bUpdateLinkedEntitiesSetEmpInfluence = L2_4000
    L2_4000 = A0_3998.CountLinks
    L2_4000 = L2_4000(L3_4001)
    for L6_4004 = 0, L2_4000 - 1 do
      if A0_3998:GetLink(L6_4004) and A0_3998:GetLink(L6_4004).SetEmpInfluence then
        A0_3998:GetLink(L6_4004):SetEmpInfluence(A1_3999)
      end
    end
  end
  L2_4000 = false
  m_bUpdateLinkedEntitiesSetEmpInfluence = L2_4000
end
function ArkGravShaft.Event_Enter(A0_4005, A1_4006)
  A0_4005:ActivateOutput("Enter", A1_4006)
end
function ArkGravShaft.Event_Leave(A0_4007, A1_4008)
  A0_4007:ActivateOutput("Leave", A1_4008)
end
function ArkGravShaft.Event_Enable(A0_4009)
  BroadcastEvent(A0_4009, "Enable")
end
function ArkGravShaft.Event_Disable(A0_4010)
  BroadcastEvent(A0_4010, "Disable")
end
function ArkGravShaft.SetFromProperties(A0_4011)
  local L1_4012
end
ArkGravShaft.FlowEvents = {
  Inputs = {
    Disable = {
      ArkGravShaft.Event_Disable,
      "bool"
    },
    Enable = {
      ArkGravShaft.Event_Enable,
      "bool"
    },
    Enter = {
      ArkGravShaft.Event_Enter,
      "bool"
    },
    Leave = {
      ArkGravShaft.Event_Leave,
      "bool"
    }
  },
  Outputs = {
    Disable = "bool",
    Enable = "bool",
    Enter = "int",
    Leave = "int"
  }
}
