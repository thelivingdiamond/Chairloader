Script.ReloadScript("Scripts/Entities/Lights/Light.lua")
ArkEnvironmentLightTOD = {
  Properties = {
    _nVersion = -1,
    bActive = 0,
    _bCheapLight = 0,
    BoxSizeX = 10,
    BoxSizeY = 10,
    BoxSizeZ = 10,
    Color = {
      clrDiffuse = {
        x = 1,
        y = 1,
        z = 1
      },
      fDiffuseMultiplier = 1,
      fSpecularMultiplier = 1
    },
    Projection = {
      bBoxProject = 0,
      fBoxWidth = 10,
      fBoxHeight = 10,
      fBoxLength = 10
    },
    Options = {
      bAffectsThisAreaOnly = 1,
      bIgnoresVisAreas = 0,
      SortPriority = 0,
      fAttenuationFalloffMax = 0.3
    },
    TimeOfDayOptions = {
      TimeOfDay1 = {fHour = 0, texture_deferred_cubemap_tod1 = ""},
      TimeOfDay2 = {fHour = 4, texture_deferred_cubemap_tod2 = ""},
      TimeOfDay3 = {fHour = 8, texture_deferred_cubemap_tod3 = ""},
      TimeOfDay4 = {fHour = 12, texture_deferred_cubemap_tod4 = ""},
      TimeOfDay5 = {fHour = 16, texture_deferred_cubemap_tod5 = ""},
      TimeOfDay6 = {fHour = 20, texture_deferred_cubemap_tod6 = ""}
    }
  },
  Editor = {ShowBounds = 0, AbsoluteRadius = 1},
  _LightTable = {}
}
LightSlot = 1
function ArkEnvironmentLightTOD.OnInit(A0_3762)
  A0_3762:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
  A0_3762:OnReset()
  A0_3762:Activate(1)
  A0_3762:CacheResources("ArkEnvironmentLightTOD.lua")
end
function ArkEnvironmentLightTOD.CacheResources(A0_3763, A1_3764)
end
function ArkEnvironmentLightTOD.OnShutDown(A0_3765)
  A0_3765:FreeSlot(LightSlot)
end
function ArkEnvironmentLightTOD.OnLoad(A0_3766, A1_3767)
  A0_3766:OnReset()
  A0_3766:ActivateLight(A1_3767.bActive)
end
function ArkEnvironmentLightTOD.OnSave(A0_3768, A1_3769)
  A1_3769.bActive = A0_3768.bActive
end
function ArkEnvironmentLightTOD.OnPropertyChange(A0_3770)
  A0_3770:OnReset()
  A0_3770:ActivateLight(A0_3770.bActive)
  if A0_3770.Properties.Options.bAffectsThisAreaOnly then
    A0_3770:UpdateLightClipBounds(LightSlot)
  end
end
function ArkEnvironmentLightTOD.OnPropertyAnimated(A0_3771, A1_3772)
  local L2_3773, L3_3774, L4_3775, L5_3776, L6_3777
  L2_3773 = false
  if A1_3772 == "fDiffuseMultiplier" or A1_3772 == "fSpecularMultiplier" then
    L2_3773 = true
    L3_3774 = A0_3771.Properties
    L3_3774 = L3_3774.Color
    L4_3775 = L3_3774.fDiffuseMultiplier
    L5_3776 = L3_3774.fSpecularMultiplier
    L6_3777 = {}
    L6_3777.x = L3_3774.clrDiffuse.x * L4_3775
    L6_3777.y = L3_3774.clrDiffuse.y * L4_3775
    L6_3777.z = L3_3774.clrDiffuse.z * L4_3775
    A0_3771:SetLightColorParams(LightSlot, L6_3777, L5_3776)
  end
  return L2_3773
end
function ArkEnvironmentLightTOD.OnUpdate(A0_3778, A1_3779)
  if A0_3778.bActive and A0_3778.Properties.Options.bAffectsThisAreaOnly then
    A0_3778:UpdateLightClipBounds(LightSlot)
  end
  if not System.IsEditor() then
    A0_3778:Activate(0)
  end
end
function ArkEnvironmentLightTOD.OnReset(A0_3780)
  if A0_3780.bActive ~= A0_3780.Properties.bActive then
    A0_3780:ActivateLight(A0_3780.Properties.bActive)
  end
end
function ArkEnvironmentLightTOD.ActivateLight(A0_3781, A1_3782)
  if A1_3782 and A1_3782 ~= 0 then
    A0_3781.bActive = 1
    A0_3781:LoadLightToSlot(LightSlot)
    A0_3781:ActivateOutput("Active", true)
  else
    A0_3781.bActive = 0
    A0_3781:FreeSlot(LightSlot)
    A0_3781:ActivateOutput("Active", false)
  end
end
function ArkEnvironmentLightTOD.LoadLightToSlot(A0_3783, A1_3784)
  local L2_3785, L3_3786, L4_3787, L5_3788, L6_3789, L7_3790, L8_3791
  L2_3785 = A0_3783.Properties
  L3_3786 = L2_3785.Color
  L4_3787 = L2_3785.Options
  L5_3788 = L2_3785.Projection
  L6_3789 = L3_3786.fDiffuseMultiplier
  L7_3790 = L3_3786.fSpecularMultiplier
  L8_3791 = A0_3783._LightTable
  L8_3791.cheapLight = L2_3785._bCheapLight
  L8_3791.radius = 0.5 * (L2_3785.BoxSizeX * L2_3785.BoxSizeX + L2_3785.BoxSizeY * L2_3785.BoxSizeY + L2_3785.BoxSizeZ * L2_3785.BoxSizeZ) ^ 0.5
  L8_3791.box_size_x = L2_3785.BoxSizeX
  L8_3791.box_size_y = L2_3785.BoxSizeY
  L8_3791.box_size_z = L2_3785.BoxSizeZ
  L8_3791.diffuse_color = {
    x = L3_3786.clrDiffuse.x * L6_3789,
    y = L3_3786.clrDiffuse.y * L6_3789,
    z = L3_3786.clrDiffuse.z * L6_3789
  }
  L8_3791.specular_multiplier = L7_3790
  L8_3791.this_area_only = L4_3787.bAffectsThisAreaOnly
  L8_3791.ignore_visareas = L4_3787.bIgnoresVisAreas
  L8_3791.box_projection = L5_3788.bBoxProject
  L8_3791.box_width = L5_3788.fBoxWidth
  L8_3791.box_height = L5_3788.fBoxHeight
  L8_3791.box_length = L5_3788.fBoxLength
  L8_3791.sort_priority = L4_3787.SortPriority
  L8_3791.attenuation_falloff_max = L4_3787.fAttenuationFalloffMax
  L8_3791.lightmap_linear_attenuation = 1
  L8_3791.is_rectangle_light = 0
  L8_3791.is_sphere_light = 0
  L8_3791.area_sample_number = 1
  L8_3791.RAE_AmbientColor = {
    x = 0,
    y = 0,
    z = 0
  }
  L8_3791.RAE_MaxShadow = 1
  L8_3791.RAE_DistMul = 1
  L8_3791.RAE_DivShadow = 1
  L8_3791.RAE_ShadowHeight = 1
  L8_3791.RAE_FallOff = 2
  L8_3791.RAE_VisareaNumber = 0
  A0_3783:LoadLight(A1_3784, L8_3791)
end
function ArkEnvironmentLightTOD.Event_Enable(A0_3792)
  if A0_3792.bActive == 0 then
    A0_3792:ActivateLight(1)
  end
end
function ArkEnvironmentLightTOD.Event_Disable(A0_3793)
  if A0_3793.bActive == 1 then
    A0_3793:ActivateLight(0)
  end
end
function Light.NotifySwitchOnOffFromParent(A0_3794, A1_3795)
  if A0_3794.bActive == 1 and A1_3795 ~= true then
    A0_3794:ActivateLight(0)
  elseif A0_3794.bActive == 0 and A1_3795 then
    A0_3794:ActivateLight(1)
  end
end
function ArkEnvironmentLightTOD.Event_Active(A0_3796, A1_3797)
  if A0_3796.bActive == 0 and A1_3797 == true then
    A0_3796:ActivateLight(1)
  elseif A0_3796.bActive == 1 and A1_3797 == false then
    A0_3796:ActivateLight(0)
  end
end
ArkEnvironmentLightTOD.FlowEvents = {
  Inputs = {
    Active = {
      ArkEnvironmentLightTOD.Event_Active,
      "bool"
    },
    Enable = {
      ArkEnvironmentLightTOD.Event_Enable,
      "bool"
    },
    Disable = {
      ArkEnvironmentLightTOD.Event_Disable,
      "bool"
    }
  },
  Outputs = {Active = "bool"}
}
