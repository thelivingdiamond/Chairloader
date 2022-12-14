local L0_5912, L1_5913, L2_5914, L3_5915
L0_5912 = {}
L1_5913 = {}
L1_5913._nVersion = -1
L1_5913.bActive = 1
L1_5913.Radius = 10
L1_5913.fAttenuationBulbSize = 0.05
L2_5914 = {}
L2_5914.nLightStyle = 0
L2_5914.fAnimationSpeed = 1
L2_5914.nAnimationPhase = 0
L2_5914.bAttachToSun = 0
L2_5914.lightanimation_LightAnimation = ""
L2_5914.bTimeScrubbingInTrackView = 0
L2_5914._fTimeScrubbed = 0
L2_5914.bFlareEnable = 1
L2_5914.flare_Flare = ""
L2_5914.fFlareFOV = 360
L1_5913.Style = L2_5914
L2_5914 = {}
L2_5914.texture_Texture = ""
L2_5914.fProjectorFov = 90
L2_5914.fProjectorNearPlane = 0
L1_5913.Projector = L2_5914
L2_5914 = {}
L3_5915 = {}
L3_5915.x = 1
L3_5915.y = 1
L3_5915.z = 1
L2_5914.clrDiffuse = L3_5915
L2_5914.fDiffuseMultiplier = 1
L2_5914.fSpecularMultiplier = 1
L1_5913.Color = L2_5914
L2_5914 = {}
L2_5914.bAffectsThisAreaOnly = 1
L2_5914.bIgnoresVisAreas = 0
L2_5914.bAmbient = 0
L2_5914.bFakeLight = 0
L2_5914.bVolumetricFog = 1
L2_5914.bAffectsVolumetricFogOnly = 0
L2_5914.fFogRadialLobe = 0
L1_5913.Options = L2_5914
L2_5914 = {}
L2_5914.nCastShadows = 0
L2_5914.nCastShadowViewDistRatio = 100
L2_5914.fShadowBias = 1
L2_5914.fShadowSlopeBias = 1
L2_5914.fShadowResolutionScale = 1
L2_5914.nShadowMinResPercent = 0
L2_5914.fShadowUpdateMinRadius = 10
L2_5914.fShadowUpdateRatio = 1
L1_5913.Shadows = L2_5914
L2_5914 = {}
L2_5914.bAreaLight = 0
L2_5914.fPlaneWidth = 1
L2_5914.fPlaneHeight = 1
L1_5913.Shape = L2_5914
L0_5912.Properties = L1_5913
L1_5913 = {}
L1_5913.Model = "Editor/Objects/Light_Omni.cgf"
L1_5913.Icon = "Light.bmp"
L1_5913.ShowBounds = 0
L1_5913.AbsoluteRadius = 1
L1_5913.IsScalable = false
L0_5912.Editor = L1_5913
L0_5912.m_specularMultiplier = nil
L0_5912.m_diffuseMultiplier = nil
L0_5912.m_radius = nil
L0_5912.m_clrDiffuse = nil
L0_5912.m_bIsGameRunning = false
L1_5913 = {}
L0_5912._LightTable = L1_5913
Light = L0_5912
L0_5912 = 1
LightSlot = L0_5912
L0_5912 = Light
function L1_5913(A0_5916)
  A0_5916:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
  A0_5916:Reset()
  A0_5916:CacheResources("Light.lua")
  A0_5916:CacheMutableProperties()
end
L0_5912.OnInit = L1_5913
L0_5912 = Light
function L1_5913(A0_5917, A1_5918)
  local L2_5919
  L2_5919 = 0
  Game.CacheResource(A1_5918, A0_5917.Properties.Projector.texture_Texture, eGameCacheResourceType_Texture, L2_5919)
end
L0_5912.CacheResources = L1_5913
L0_5912 = Light
function L1_5913(A0_5920)
  A0_5920:FreeSlot(LightSlot)
end
L0_5912.OnShutDown = L1_5913
L0_5912 = Light
function L1_5913(A0_5921, A1_5922)
  A0_5921.Properties.Radius = A1_5922.m_radius
  A0_5921.Properties.Color.fDiffuseMultiplier = A1_5922.m_diffuseMultiplier
  A0_5921.Properties.Color.fSpecularMultiplier = A1_5922.m_specularMultiplier
  A0_5921.Properties.Color.clrDiffuse = NewVector(A1_5922.m_clrDiffuse)
  A0_5921:ActivateLight(A1_5922.bActive)
  A0_5921:CacheMutableProperties()
  A0_5921:OnPropertyChange()
end
L0_5912.OnLoad = L1_5913
L0_5912 = Light
function L1_5913(A0_5923, A1_5924)
  A0_5923:CacheMutableProperties()
  A1_5924.bActive = A0_5923.bActive
  A1_5924.m_radius = A0_5923.m_radius
  A1_5924.m_diffuseMultiplier = A0_5923.m_diffuseMultiplier
  A1_5924.m_specularMultiplier = A0_5923.m_specularMultiplier
  A1_5924.m_clrDiffuse = NewVector(A0_5923.m_clrDiffuse)
end
L0_5912.OnSave = L1_5913
L0_5912 = Light
function L1_5913(A0_5925)
  if System.IsEditing() and not A0_5925.m_bIsGameRunning then
    A0_5925:CacheMutableProperties()
  end
  A0_5925:Reset()
  A0_5925:ActivateLight(A0_5925.bActive)
  if A0_5925.Properties.Options.bAffectsThisAreaOnly then
    A0_5925:UpdateLightClipBounds(LightSlot)
  end
end
L0_5912.OnPropertyChange = L1_5913
L0_5912 = Light
function L1_5913(A0_5926, A1_5927)
  local L2_5928, L3_5929, L4_5930, L5_5931, L6_5932
  L2_5928 = false
  if A1_5927 == "fDiffuseMultiplier" or A1_5927 == "fSpecularMultiplier" then
    L2_5928 = true
    L3_5929 = A0_5926.Properties
    L3_5929 = L3_5929.Color
    L4_5930 = L3_5929.fDiffuseMultiplier
    L5_5931 = L3_5929.fSpecularMultiplier
    L6_5932 = {}
    L6_5932.x = L3_5929.clrDiffuse.x * L4_5930
    L6_5932.y = L3_5929.clrDiffuse.y * L4_5930
    L6_5932.z = L3_5929.clrDiffuse.z * L4_5930
    A0_5926:SetLightColorParams(LightSlot, L6_5932, L5_5931)
  end
  return L2_5928
end
L0_5912.OnPropertyAnimated = L1_5913
L0_5912 = Light
function L1_5913(A0_5933)
  A0_5933:OnPropertyChange()
end
L0_5912.OnSysSpecLightChanged = L1_5913
L0_5912 = Light
function L1_5913(A0_5934)
  if A0_5934.Properties.Options.bAffectsThisAreaOnly then
    A0_5934:UpdateLightClipBounds(LightSlot)
  end
end
L0_5912.OnLevelLoaded = L1_5913
L0_5912 = Light
function L1_5913(A0_5935)
  if A0_5935.bActive ~= A0_5935.Properties.bActive then
    A0_5935:ActivateLight(A0_5935.Properties.bActive)
  end
end
L0_5912.Reset = L1_5913
L0_5912 = Light
function L1_5913(A0_5936)
  A0_5936.Properties.Radius = A0_5936.m_radius
  A0_5936.Properties.Color.fDiffuseMultiplier = A0_5936.m_diffuseMultiplier
  A0_5936.Properties.Color.fSpecularMultiplier = A0_5936.m_specularMultiplier
  if A0_5936.m_clrDiffuse ~= nil then
    A0_5936.Properties.Color.clrDiffuse = NewVector(A0_5936.m_clrDiffuse)
  end
  A0_5936.m_bIsGameRunning = false
  A0_5936:OnPropertyChange()
end
L0_5912.OnReset = L1_5913
L0_5912 = Light
function L1_5913(A0_5937)
  if System.IsEditor() then
    A0_5937:CacheMutableProperties()
  end
  A0_5937.m_bIsGameRunning = true
end
L0_5912.OnStartGame = L1_5913
L0_5912 = Light
function L1_5913(A0_5938)
  if System.IsEditor() then
    A0_5938:CacheMutableProperties()
  end
end
L0_5912.OnStartLevel = L1_5913
L0_5912 = Light
function L1_5913(A0_5939)
  A0_5939.m_radius = A0_5939.Properties.Radius
  A0_5939.m_diffuseMultiplier = A0_5939.Properties.Color.fDiffuseMultiplier
  A0_5939.m_clrDiffuse = NewVector(A0_5939.Properties.Color.clrDiffuse)
  A0_5939.m_specularMultiplier = A0_5939.Properties.Color.fSpecularMultiplier
end
L0_5912.CacheMutableProperties = L1_5913
L0_5912 = Light
function L1_5913(A0_5940, A1_5941)
  if A1_5941 and A1_5941 ~= 0 then
    A0_5940.bActive = 1
    A0_5940:LoadLightToSlot(LightSlot)
    A0_5940:ActivateOutput("Active", true)
  else
    A0_5940.bActive = 0
    A0_5940:FreeSlot(LightSlot)
    A0_5940:ActivateOutput("Active", false)
  end
end
L0_5912.ActivateLight = L1_5913
L0_5912 = Light
function L1_5913(A0_5942, A1_5943)
  local L2_5944, L3_5945, L4_5946, L5_5947, L6_5948, L7_5949, L8_5950, L9_5951, L10_5952, L11_5953
  L2_5944 = A0_5942.Properties
  L3_5945 = L2_5944.Style
  L4_5946 = L2_5944.Projector
  L5_5947 = L2_5944.Color
  L6_5948 = L2_5944.Options
  L7_5949 = L2_5944.Shape
  L8_5950 = L2_5944.Shadows
  L9_5951 = L5_5947.fDiffuseMultiplier
  L10_5952 = L5_5947.fSpecularMultiplier
  L11_5953 = A0_5942._LightTable
  L11_5953.radius = L2_5944.Radius
  L11_5953.attenuation_bulbsize = L2_5944.fAttenuationBulbSize
  L11_5953.diffuse_color = {
    x = L5_5947.clrDiffuse.x * L9_5951,
    y = L5_5947.clrDiffuse.y * L9_5951,
    z = L5_5947.clrDiffuse.z * L9_5951
  }
  L11_5953.specular_multiplier = L10_5952
  L11_5953.this_area_only = L6_5948.bAffectsThisAreaOnly
  L11_5953.ambient = L2_5944.Options.bAmbient
  L11_5953.fake = L6_5948.bFakeLight
  L11_5953.ignore_visareas = L6_5948.bIgnoresVisAreas
  L11_5953.volumetric_fog = L6_5948.bVolumetricFog
  L11_5953.volumetric_fog_only = L6_5948.bAffectsVolumetricFogOnly
  L11_5953.fog_radial_lobe = L6_5948.fFogRadialLobe
  L11_5953.cast_shadow = L8_5950.nCastShadows
  L11_5953.cast_shadow_viewDistRatio = L8_5950.nCastShadowViewDistRatio
  L11_5953.shadow_bias = L8_5950.fShadowBias
  L11_5953.shadow_slope_bias = L8_5950.fShadowSlopeBias
  L11_5953.shadowResolutionScale = L8_5950.fShadowResolutionScale
  L11_5953.shadowMinResolution = L8_5950.nShadowMinResPercent
  L11_5953.shadowUpdate_MinRadius = L8_5950.fShadowUpdateMinRadius
  L11_5953.shadowUpdate_ratio = L8_5950.fShadowUpdateRatio
  L11_5953.projector_texture = L4_5946.texture_Texture
  L11_5953.proj_fov = L4_5946.fProjectorFov
  L11_5953.proj_nearplane = L4_5946.fProjectorNearPlane
  L11_5953.area_light = L7_5949.bAreaLight
  L11_5953.area_width = L7_5949.fPlaneWidth
  L11_5953.area_height = L7_5949.fPlaneHeight
  L11_5953.style = L3_5945.nLightStyle
  L11_5953.attach_to_sun = L3_5945.bAttachToSun
  L11_5953.anim_speed = L3_5945.fAnimationSpeed
  L11_5953.anim_phase = L3_5945.nAnimationPhase
  L11_5953.light_animation = L3_5945.lightanimation_LightAnimation
  L11_5953.time_scrubbing_in_trackview = L3_5945.bTimeScrubbingInTrackView
  L11_5953.time_scrubbed = L3_5945._fTimeScrubbed
  L11_5953.flare_enable = L3_5945.bFlareEnable
  L11_5953.flare_Flare = L3_5945.flare_Flare
  L11_5953.flare_FOV = L3_5945.fFlareFOV
  L11_5953.lightmap_linear_attenuation = 1
  L11_5953.is_rectangle_light = 0
  L11_5953.is_sphere_light = 0
  L11_5953.area_sample_number = 1
  L11_5953.indoor_only = 0
  A0_5942:LoadLight(A1_5943, L11_5953)
end
L0_5912.LoadLightToSlot = L1_5913
L0_5912 = Light
function L1_5913(A0_5954, A1_5955)
  local L2_5956, L3_5957, L4_5958
  L2_5956 = A0_5954.Properties
  L3_5957 = "Point"
  L4_5958 = L2_5956.Shape
  L4_5958 = L4_5958.bAreaLight
  if L4_5958 ~= 0 then
    L3_5957 = "Area"
  else
    L4_5958 = L2_5956.Projector
    L4_5958 = L4_5958.texture_Texture
    if L4_5958 ~= nil then
      L4_5958 = L2_5956.Projector
      L4_5958 = L4_5958.texture_Texture
      if L4_5958 ~= "" then
        L3_5957 = "Projector"
      end
    end
  end
  L4_5958 = "NoShadows"
  if 0 < L2_5956.Shadows.nCastShadows then
    L4_5958 = "Shadows"
  end
  A1_5955.Icon = "Light." .. L3_5957 .. "." .. L4_5958 .. ".bmp"
end
L0_5912.GetEditorIcon = L1_5913
L0_5912 = Light
function L1_5913(A0_5959)
  if A0_5959.bActive == 0 then
    A0_5959:ActivateLight(1)
  end
end
L0_5912.Event_Enable = L1_5913
L0_5912 = Light
function L1_5913(A0_5960)
  if A0_5960.bActive == 1 then
    A0_5960:ActivateLight(0)
  end
end
L0_5912.Event_Disable = L1_5913
L0_5912 = Light
function L1_5913(A0_5961, A1_5962)
  if A0_5961.bActive == 1 and A1_5962 ~= true then
    A0_5961:ActivateLight(0)
  elseif A0_5961.bActive == 0 and A1_5962 then
    A0_5961:ActivateLight(1)
  end
end
L0_5912.NotifySwitchOnOffFromParent = L1_5913
L0_5912 = Light
function L1_5913(A0_5963, A1_5964, A2_5965)
  if A0_5963.bActive == 0 and A2_5965 == true then
    A0_5963:ActivateLight(1)
  elseif A0_5963.bActive == 1 and A2_5965 == false then
    A0_5963:ActivateLight(0)
  end
end
L0_5912.Event_Active = L1_5913
L0_5912 = Light
function L1_5913(A0_5966, A1_5967, A2_5968)
  A0_5966.Properties.Radius = A2_5968
  A0_5966:OnPropertyChange()
end
L0_5912.Event_Radius = L1_5913
L0_5912 = Light
function L1_5913(A0_5969, A1_5970, A2_5971)
  A0_5969.Properties.Color.clrDiffuse = A2_5971
  A0_5969:OnPropertyChange()
end
L0_5912.Event_DiffuseColor = L1_5913
L0_5912 = Light
function L1_5913(A0_5972, A1_5973, A2_5974)
  A0_5972.Properties.Color.fDiffuseMultiplier = A2_5974
  A0_5972:OnPropertyChange()
end
L0_5912.Event_DiffuseMultiplier = L1_5913
L0_5912 = Light
function L1_5913(A0_5975, A1_5976, A2_5977)
  A0_5975.Properties.Color.fSpecularMultiplier = A2_5977
  A0_5975:OnPropertyChange()
end
L0_5912.Event_SpecularMultiplier = L1_5913
L0_5912 = Light
L1_5913 = {}
L2_5914 = {}
L3_5915 = {
  Light.Event_Active,
  "bool"
}
L2_5914.Active = L3_5915
L3_5915 = {
  Light.Event_Enable,
  "bool"
}
L2_5914.Enable = L3_5915
L3_5915 = {
  Light.Event_Disable,
  "bool"
}
L2_5914.Disable = L3_5915
L3_5915 = {
  Light.Event_Radius,
  "float"
}
L2_5914.Radius = L3_5915
L3_5915 = {
  Light.Event_DiffuseColor,
  "vec3"
}
L2_5914.DiffuseColor = L3_5915
L3_5915 = {
  Light.Event_DiffuseMultiplier,
  "float"
}
L2_5914.DiffuseMultiplier = L3_5915
L3_5915 = {
  Light.Event_SpecularMultiplier,
  "float"
}
L2_5914.SpecularMultiplier = L3_5915
L1_5913.Inputs = L2_5914
L2_5914 = {}
L2_5914.Active = "bool"
L1_5913.Outputs = L2_5914
L0_5912.FlowEvents = L1_5913
