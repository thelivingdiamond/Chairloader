Script.ReloadScript("Scripts/Entities/Lights/Light.lua")
EnvironmentLight = {
  Properties = {
    _nVersion = -1,
    bActive = 0,
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
      _texture_deferred_cubemap = "",
      SortPriority = 0,
      fAttenuationFalloffMax = 0.3
    },
    OptionsAdvanced = {texture_deferred_cubemap = "", bIgnoreDecals = 0}
  },
  Editor = {ShowBounds = 0, AbsoluteRadius = 1},
  _LightTable = {}
}
LightSlot = 1
function EnvironmentLight.OnInit(A0_5874)
  A0_5874:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
  A0_5874:OnReset()
  A0_5874:Activate(1)
  A0_5874:CacheResources("EnvironmentLight.lua")
end
function EnvironmentLight.CacheResources(A0_5875, A1_5876)
  if A0_5875.Properties.OptionsAdvanced.texture_deferred_cubemap == "" then
    A0_5875.Properties.OptionsAdvanced.texture_deferred_cubemap = A0_5875.Properties.Options._texture_deferred_cubemap
  end
  Game.CacheResource(A1_5876, A0_5875.Properties.OptionsAdvanced.texture_deferred_cubemap, eGameCacheResourceType_TextureDeferredCubemap, 0)
end
function EnvironmentLight.OnShutDown(A0_5877)
  A0_5877:FreeSlot(LightSlot)
end
function EnvironmentLight.OnLoad(A0_5878, A1_5879)
  A0_5878:OnReset()
  A0_5878:ActivateLight(A1_5879.bActive)
  A0_5878.diffuse_color = A1_5879.diffuse_color
end
function EnvironmentLight.OnSave(A0_5880, A1_5881)
  local L2_5882
  L2_5882 = A0_5880.bActive
  A1_5881.bActive = L2_5882
  L2_5882 = A0_5880.diffuse_color
  A1_5881.diffuse_color = L2_5882
end
function EnvironmentLight.OnPostLoad(A0_5883)
  if A0_5883.diffuse_color ~= nil then
    A0_5883:SetLightColorParams(LightSlot, A0_5883.diffuse_color, A0_5883.Properties.Color.fSpecularMultiplier)
  end
end
function EnvironmentLight.OnPropertyChange(A0_5884)
  A0_5884:OnReset()
  A0_5884:ActivateLight(A0_5884.bActive)
  if A0_5884.Properties.Options.bAffectsThisAreaOnly then
    A0_5884:UpdateLightClipBounds(LightSlot)
  end
end
function EnvironmentLight.OnPropertyAnimated(A0_5885, A1_5886)
  local L2_5887, L3_5888, L4_5889, L5_5890
  L2_5887 = false
  if A1_5886 == "fDiffuseMultiplier" or A1_5886 == "fSpecularMultiplier" then
    L2_5887 = true
    L3_5888 = A0_5885.Properties
    L3_5888 = L3_5888.Color
    L4_5889 = L3_5888.fDiffuseMultiplier
    L5_5890 = L3_5888.fSpecularMultiplier
    A0_5885.diffuse_color = {
      x = L3_5888.clrDiffuse.x * L4_5889,
      y = L3_5888.clrDiffuse.y * L4_5889,
      z = L3_5888.clrDiffuse.z * L4_5889
    }
    A0_5885:SetLightColorParams(LightSlot, A0_5885.diffuse_color, L5_5890)
  end
  return L2_5887
end
function EnvironmentLight.OnUpdate(A0_5891, A1_5892)
  if A0_5891.bActive and A0_5891.Properties.Options.bAffectsThisAreaOnly then
    A0_5891:UpdateLightClipBounds(LightSlot)
  end
  if not System.IsEditor() then
    A0_5891:Activate(0)
  end
end
function EnvironmentLight.OnReset(A0_5893)
  if A0_5893.bActive ~= A0_5893.Properties.bActive then
    A0_5893:ActivateLight(A0_5893.Properties.bActive)
  end
end
function EnvironmentLight.ActivateLight(A0_5894, A1_5895)
  if A1_5895 and A1_5895 ~= 0 then
    A0_5894.bActive = 1
    A0_5894:LoadLightToSlot(LightSlot)
    A0_5894:ActivateOutput("Active", true)
  else
    A0_5894.bActive = 0
    A0_5894:FreeSlot(LightSlot)
    A0_5894:ActivateOutput("Active", false)
  end
end
function EnvironmentLight.LoadLightToSlot(A0_5896, A1_5897)
  local L2_5898, L3_5899, L4_5900, L5_5901, L6_5902, L7_5903, L8_5904, L9_5905
  L2_5898 = A0_5896.Properties
  L3_5899 = L2_5898.Color
  L4_5900 = L2_5898.Options
  L5_5901 = L2_5898.OptionsAdvanced
  L6_5902 = L2_5898.Projection
  L7_5903 = L3_5899.fDiffuseMultiplier
  L8_5904 = L3_5899.fSpecularMultiplier
  L9_5905 = A0_5896._LightTable
  L9_5905.radius = 0.5 * (L2_5898.BoxSizeX * L2_5898.BoxSizeX + L2_5898.BoxSizeY * L2_5898.BoxSizeY + L2_5898.BoxSizeZ * L2_5898.BoxSizeZ) ^ 0.5
  L9_5905.box_size_x = L2_5898.BoxSizeX
  L9_5905.box_size_y = L2_5898.BoxSizeY
  L9_5905.box_size_z = L2_5898.BoxSizeZ
  L9_5905.diffuse_color = {
    x = L3_5899.clrDiffuse.x * L7_5903,
    y = L3_5899.clrDiffuse.y * L7_5903,
    z = L3_5899.clrDiffuse.z * L7_5903
  }
  L9_5905.specular_multiplier = L8_5904
  if L5_5901.texture_deferred_cubemap == "" then
    L5_5901.texture_deferred_cubemap = L4_5900._texture_deferred_cubemap
  end
  L9_5905.deferred_cubemap = L5_5901.texture_deferred_cubemap
  L9_5905.this_area_only = L4_5900.bAffectsThisAreaOnly
  L9_5905.ignore_visareas = L4_5900.bIgnoresVisAreas
  L9_5905.box_projection = L6_5902.bBoxProject
  L9_5905.box_width = L6_5902.fBoxWidth
  L9_5905.box_height = L6_5902.fBoxHeight
  L9_5905.box_length = L6_5902.fBoxLength
  L9_5905.sort_priority = L4_5900.SortPriority
  L9_5905.attenuation_falloff_max = L4_5900.fAttenuationFalloffMax
  L9_5905.lightmap_linear_attenuation = 1
  L9_5905.is_rectangle_light = 0
  L9_5905.is_sphere_light = 0
  L9_5905.area_sample_number = 1
  L9_5905.RAE_AmbientColor = {
    x = 0,
    y = 0,
    z = 0
  }
  L9_5905.RAE_MaxShadow = 1
  L9_5905.RAE_DistMul = 1
  L9_5905.RAE_DivShadow = 1
  L9_5905.RAE_ShadowHeight = 1
  L9_5905.RAE_FallOff = 2
  L9_5905.RAE_VisareaNumber = 0
  A0_5896:LoadLight(A1_5897, L9_5905)
end
function EnvironmentLight.Event_Enable(A0_5906)
  if A0_5906.bActive == 0 then
    A0_5906:ActivateLight(1)
  end
end
function EnvironmentLight.Event_Disable(A0_5907)
  if A0_5907.bActive == 1 then
    A0_5907:ActivateLight(0)
  end
end
function Light.NotifySwitchOnOffFromParent(A0_5908, A1_5909)
  if A0_5908.bActive == 1 and A1_5909 ~= true then
    A0_5908:ActivateLight(0)
  elseif A0_5908.bActive == 0 and A1_5909 then
    A0_5908:ActivateLight(1)
  end
end
function EnvironmentLight.Event_Active(A0_5910, A1_5911)
  if A0_5910.bActive == 0 and A1_5911 == true then
    A0_5910:ActivateLight(1)
  elseif A0_5910.bActive == 1 and A1_5911 == false then
    A0_5910:ActivateLight(0)
  end
end
EnvironmentLight.FlowEvents = {
  Inputs = {
    Active = {
      EnvironmentLight.Event_Active,
      "bool"
    },
    Enable = {
      EnvironmentLight.Event_Enable,
      "bool"
    },
    Disable = {
      EnvironmentLight.Event_Disable,
      "bool"
    }
  },
  Outputs = {Active = "bool"}
}
