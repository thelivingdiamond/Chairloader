local L0_5978
L0_5978 = Script
L0_5978 = L0_5978.ReloadScript
L0_5978("Scripts/Entities/Physics/BasicEntity.lua")
L0_5978 = {}
L0_5978.Properties = {
  Physics = {
    bRigidBodyActive = 1,
    bActivateOnDamage = 0,
    bResting = 1,
    bCanBreakOthers = 0,
    Simulation = {
      max_time_step = 0.02,
      sleep_speed = 0.04,
      damping = 0,
      bFixedDamping = 0,
      bUseSimpleSolver = 0
    },
    Buoyancy = {
      water_density = 1000,
      water_damping = 0,
      water_resistance = 1000
    }
  },
  Sound = {
    soundTurnOn = "",
    soundTurnOff = "",
    soundDestroy = "",
    soundIdle = "",
    soundRun = "",
    vOffset = {
      x = 0,
      y = 0,
      z = 0
    }
  }
}
L0_5978.PropertiesInstance = {
  bTurnedOn = 1,
  LightProperties_Base = {
    _nVersion = -1,
    bUseThisLight = 1,
    Radius = 10,
    fAttenuationBulbSize = 0.05,
    Style = {
      nLightStyle = 0,
      fAnimationSpeed = 1,
      nAnimationPhase = 0,
      bFlareEnable = 1,
      flare_Flare = "",
      fFlareFOV = 360
    },
    Projector = {
      texture_Texture = "",
      fProjectorFov = 90,
      fProjectorNearPlane = 0
    },
    Color = {
      clrDiffuse = {
        x = 1,
        y = 1,
        z = 1
      },
      fDiffuseMultiplier = 1,
      fSpecularMultiplier = 1
    },
    Options = {
      bAffectsThisAreaOnly = 1,
      bIgnoresVisAreas = 0,
      bAmbient = 0,
      bFakeLight = 0,
      nGlowSubmatId = 0,
      vOffset = {
        x = 0,
        y = 0,
        z = 0
      },
      vDirection = {
        x = 0,
        y = 1,
        z = 0
      }
    },
    Shadows = {
      nCastShadows = 0,
      bIgnoreGeomCaster = 1,
      fShadowBias = 1,
      fShadowSlopeBias = 1,
      fShadowResolutionScale = 1,
      nShadowMinResPercent = 0,
      fShadowUpdateMinRadius = 10,
      fShadowUpdateRatio = 1
    }
  },
  LightProperties_Destroyed = {
    _nVersion = -1,
    bUseThisLight = 0,
    Radius = 10,
    fAttenuationBulbSize = 0.05,
    Style = {
      nLightStyle = 0,
      fAnimationSpeed = 1,
      nAnimationPhase = 0,
      bFlareEnable = 1,
      flare_Flare = "",
      fFlareFOV = 360
    },
    Projector = {
      texture_Texture = "",
      fProjectorFov = 90,
      fProjectorNearPlane = 0
    },
    Color = {
      clrDiffuse = {
        x = 1,
        y = 1,
        z = 1
      },
      fDiffuseMultiplier = 1,
      fSpecularMultiplier = 1
    },
    Options = {
      bAffectsThisAreaOnly = 1,
      bIgnoresVisAreas = 0,
      bAmbient = 0,
      bFakeLight = 0,
      nGlowSubmatId = 0,
      vOffset = {
        x = 0,
        y = 0,
        z = 0
      },
      vDirection = {
        x = 0,
        y = 1,
        z = 0
      }
    },
    Shadows = {
      nCastShadows = 0,
      bIgnoreGeomCaster = 1,
      fShadowBias = 1,
      fShadowSlopeBias = 1,
      fShadowResolutionScale = 1,
      nShadowMinResPercent = 0,
      fShadowUpdateMinRadius = 10,
      fShadowUpdateRatio = 1
    }
  }
}
L0_5978._LightTable = {}
L0_5978.lightSlot = -1
L0_5978.materialIsCloned = false
L0_5978.Editor = {Icon = "Light.bmp", IconOnTop = 1}
RigidBodyLight = L0_5978
L0_5978 = {}
L0_5978.bRigidBodyActive = 0
L0_5978.bActivateOnDamage = 0
L0_5978.bResting = 1
L0_5978.Simulation = {
  max_time_step = 0.02,
  sleep_speed = 0.04,
  damping = 0,
  bFixedDamping = 0,
  bUseSimpleSolver = 0
}
L0_5978.Buoyancy = {
  water_density = 1000,
  water_damping = 0,
  water_resistance = 1000
}
MakeDerivedEntity(RigidBodyLight, BasicEntity)
function RigidBodyLight.OnLoad(A0_5979, A1_5980)
  if A0_5979.lightSlot then
    A0_5979:FreeSlot(A0_5979.lightSlot)
  end
  A0_5979.bRigidBodyActive = A1_5980.bRigidBodyActive
  A0_5979.lightSlot = A1_5980.lightSlot
  A0_5979.origGlowValue = A1_5980.origGlowValue
  A0_5979.destroyed = A1_5980.destroyed
  if not A0_5979.materialIsCloned and A1_5980.materialIsCloned then
    A0_5979:CloneMaterial(0)
  end
  A0_5979.materialIsCloned = A0_5979.materialIsCloned or A1_5980.materialIsCloned
  A0_5979.lightOn = A1_5980.lightOn
  A0_5979.runSoundId = 0
  A0_5979.idleSoundId = 0
  A0_5979:ShowCorrectLight()
end
function RigidBodyLight.OnSave(A0_5981, A1_5982)
  local L2_5983
  L2_5983 = A0_5981.bRigidBodyActive
  A1_5982.bRigidBodyActive = L2_5983
  L2_5983 = A0_5981.lightSlot
  A1_5982.lightSlot = L2_5983
  L2_5983 = A0_5981.origGlowValue
  A1_5982.origGlowValue = L2_5983
  L2_5983 = A0_5981.materialIsCloned
  A1_5982.materialIsCloned = L2_5983
  L2_5983 = A0_5981.lightOn
  A1_5982.lightOn = L2_5983
  L2_5983 = A0_5981.destroyed
  A1_5982.destroyed = L2_5983
end
function RigidBodyLight.OnSpawn(A0_5984)
  if A0_5984.Properties.Physics.bRigidBodyActive == 1 then
    A0_5984.bRigidBodyActive = 1
  end
  A0_5984:SetFromProperties()
  A0_5984:SetupHealthProperties()
  A0_5984:CacheResources("RigidBodyLight.lua")
end
function RigidBodyLight.CacheResources(A0_5985, A1_5986)
  local L2_5987
  L2_5987 = 0
  Game.CacheResource(A1_5986, A0_5985.PropertiesInstance.LightProperties_Base.Projector.texture_Texture, eGameCacheResourceType_Texture, L2_5987)
  L2_5987 = 0
  Game.CacheResource(A1_5986, A0_5985.PropertiesInstance.LightProperties_Destroyed.Projector.texture_Texture, eGameCacheResourceType_Texture, L2_5987)
end
function RigidBodyLight.SetFromProperties(A0_5988)
  local L1_5989
  L1_5989 = A0_5988.Properties
  A0_5988.destroyed = false
  if L1_5989.object_Model ~= "" then
    A0_5988:LoadObject(0, L1_5989.object_Model)
    A0_5988:CharacterUpdateOnRender(0, 1)
    A0_5988:DrawSlot(0, 1)
    if L1_5989.Physics.bPhysicalize == 1 then
      A0_5988:PhysicalizeThis()
    end
    if A0_5988.Properties.bAutoGenAIHidePts == 1 then
      A0_5988:SetFlags(ENTITY_FLAG_AI_HIDEABLE, 0)
    else
      A0_5988:SetFlags(ENTITY_FLAG_AI_HIDEABLE, 2)
    end
  end
  if not A0_5988.origGlowValue or A0_5988.lightOn then
    A0_5988.origGlowValue = A0_5988:GetMaterialFloat(0, A0_5988.PropertiesInstance.LightProperties_Base.Options.nGlowSubmatId, MaterialFloatParams.emissive_intensity)
  end
  A0_5988.lightOn = A0_5988.PropertiesInstance.bTurnedOn == 1
  if A0_5988.idleSoundId == nil then
    A0_5988.idleSoundId = 0
  end
  if A0_5988.runSoundId == nil then
    A0_5988.runSoundId = 0
  end
  A0_5988:ShowCorrectLight()
end
function RigidBodyLight.PhysicalizeThis(A0_5990)
  local L1_5991
  L1_5991 = A0_5990.Properties
  L1_5991 = L1_5991.Physics
  if CryAction.IsImmersivenessEnabled() == 0 then
    L1_5991 = _UPVALUE0_
  end
  EntityCommon.PhysicalizeRigid(A0_5990, 0, L1_5991, A0_5990.bRigidBodyActive)
end
function RigidBodyLight.OnPropertyChange(A0_5992)
  if A0_5992.lightOn then
    A0_5992.origGlowValue = A0_5992:GetMaterialFloat(0, A0_5992.PropertiesInstance.LightProperties_Base.Options.nGlowSubmatId, MaterialFloatParams.emissive_intensity)
  end
  A0_5992:SetFromProperties()
  if A0_5992.PropertiesInstance.LightProperties_Base.Options.bAffectsThisAreaOnly then
    A0_5992:UpdateLightClipBounds(A0_5992.lightSlot)
  end
  A0_5992:StopIdleSound()
  A0_5992:StopRunSound()
end
function RigidBodyLight.Client.OnLevelLoaded(A0_5993)
  if A0_5993.PropertiesInstance.LightProperties_Base.Options.bAffectsThisAreaOnly then
    A0_5993:UpdateLightClipBounds(A0_5993.lightSlot)
  end
end
function RigidBodyLight.OnReset(A0_5994)
  A0_5994:ResetOnUsed()
  A0_5994.lightOn = A0_5994.PropertiesInstance.bTurnedOn == 1
  A0_5994.destroyed = false
  A0_5994.materialIsCloned = false
  A0_5994:ShowCorrectLight()
  if A0_5994.Properties.Physics.bPhysicalize == 1 then
    if A0_5994.bRigidBodyActive ~= A0_5994.Properties.Physics.bRigidBodyActive then
      A0_5994.bRigidBodyActive = A0_5994.Properties.Physics.bRigidBodyActive
      A0_5994:PhysicalizeThis()
    end
    if A0_5994.Properties.Physics.bRigidBody == 1 then
      A0_5994:AwakePhysics(1 - A0_5994.Properties.Physics.bResting)
      A0_5994.bRigidBodyActive = A0_5994.Properties.Physics.bRigidBodyActive
    end
  end
end
function RigidBodyLight.Event_Hide(A0_5995)
  A0_5995:Hide(1)
  A0_5995:ActivateOutput("Hidden", true)
end
function RigidBodyLight.Event_UnHide(A0_5996)
  A0_5996:Hide(0)
  A0_5996:ActivateOutput("UnHidden", true)
end
function RigidBodyLight.Event_Enable(A0_5997)
  if not A0_5997.destroyed then
    A0_5997.lightOn = true
    A0_5997:ShowCorrectLight()
    A0_5997:ActivateOutput("Enabled", true)
  end
end
function RigidBodyLight.Event_Disable(A0_5998)
  A0_5998:SwitchOnOff(false)
end
function RigidBodyLight.PlaySound(A0_5999, A1_6000)
  local L2_6001
  if A1_6000 and A1_6000 ~= "" then
    L2_6001 = SOUND_DEFAULT_3D
  end
end
function RigidBodyLight.PlaySoundLoop(A0_6002, A1_6003)
  local L2_6004
  if A1_6003 and A1_6003 ~= "" then
    L2_6004 = SOUND_DEFAULT_3D
    L2_6004 = bor(L2_6004, FLAG_SOUND_LOOP)
    return 0
  end
end
function RigidBodyLight.PlayIdleSound(A0_6005)
  if A0_6005.idleSoundId == 0 then
    A0_6005.idleSoundId = A0_6005:PlaySoundLoop(A0_6005.Properties.Sound.soundIdle)
  end
end
function RigidBodyLight.PlayRunSound(A0_6006)
  if A0_6006.runSoundId == 0 then
    A0_6006.runSoundId = A0_6006:PlaySoundLoop(A0_6006.Properties.Sound.soundRun)
  end
end
function RigidBodyLight.StopIdleSound(A0_6007)
  if A0_6007.idleSoundId ~= 0 then
    A0_6007.idleSoundId = 0
  end
end
function RigidBodyLight.StopRunSound(A0_6008)
  if A0_6008.runSoundId ~= 0 then
    A0_6008.runSoundId = 0
  end
end
function RigidBodyLight.OnEditorSetGameMode(A0_6009, A1_6010)
  if A1_6010 ~= true then
    A0_6009:StopIdleSound()
    A0_6009:StopRunSound()
  end
end
function RigidBodyLight.ShowLightOn(A0_6011)
  if A0_6011.lightSlot ~= -1 then
    A0_6011:FreeSlot(A0_6011.lightSlot)
    A0_6011.lightSlot = -1
  end
  if A0_6011.PropertiesInstance.LightProperties_Base.bUseThisLight ~= 0 then
    A0_6011:UseLight(1)
  end
  if A0_6011.origGlowValue and A0_6011:GetMaterialFloat(0, A0_6011.PropertiesInstance.LightProperties_Base.Options.nGlowSubmatId, MaterialFloatParams.emissive_intensity) ~= A0_6011.origGlowValue then
    A0_6011:SetMaterialFloat(0, A0_6011.PropertiesInstance.LightProperties_Base.Options.nGlowSubmatId, MaterialFloatParams.emissive_intensity, A0_6011.origGlowValue)
  end
end
function RigidBodyLight.ShowLightOff(A0_6012)
  if A0_6012.lightSlot ~= -1 then
    A0_6012:FreeSlot(A0_6012.lightSlot)
    A0_6012.lightSlot = -1
  end
  if A0_6012.PropertiesInstance.LightProperties_Destroyed.bUseThisLight ~= 0 then
    A0_6012:UseLight(0)
  end
  if A0_6012:GetMaterialFloat(0, A0_6012.PropertiesInstance.LightProperties_Base.Options.nGlowSubmatId, MaterialFloatParams.emissive_intensity) ~= 0 then
    if not A0_6012.materialIsCloned then
      A0_6012:CloneMaterial(0)
      A0_6012.materialIsCloned = true
    end
    A0_6012:SetMaterialFloat(0, A0_6012.PropertiesInstance.LightProperties_Base.Options.nGlowSubmatId, MaterialFloatParams.emissive_intensity, 0)
  end
end
function RigidBodyLight.Client.OnPhysicsBreak(A0_6013, A1_6014, A2_6015, A3_6016)
  A0_6013:ActivateOutput("Break", A2_6015 + 1)
  A0_6013.destroyed = true
  A0_6013:ShowCorrectLight()
  A0_6013:StopRunSound()
  A0_6013:StopIdleSound()
  A0_6013:SwitchOnOffChildren(false)
end
function RigidBodyLight.SwitchOnOffChildren(A0_6017, A1_6018)
  local L2_6019, L3_6020, L4_6021, L5_6022, L6_6023
  L2_6019 = A0_6017.GetChildCount
  L2_6019 = L2_6019(L3_6020)
  for L6_6023 = 0, L2_6019 do
    if A0_6017:GetChild(L6_6023) and A0_6017:GetChild(L6_6023).NotifySwitchOnOffFromParent then
      A0_6017:GetChild(L6_6023):NotifySwitchOnOffFromParent(A1_6018)
    end
  end
end
function RigidBodyLight.NotifySwitchOnOffFromParent(A0_6024, A1_6025)
  A0_6024:SwitchOnOff(A1_6025)
end
function RigidBodyLight.SwitchOnOff(A0_6026, A1_6027)
  local L2_6028
  L2_6028 = A0_6026.destroyed
  if not L2_6028 then
    L2_6028 = A1_6027 ~= true
    if A0_6026.lightOn and L2_6028 then
      A0_6026.lightOn = false
      BroadcastEvent(A0_6026, "Disabled")
      A0_6026:ShowCorrectLight()
      A0_6026:SwitchOnOffChildren(A1_6027)
    elseif A0_6026.lightOn ~= true and A1_6027 then
      A0_6026.lightOn = true
      BroadcastEvent(A0_6026, "Enabled")
      A0_6026:ShowCorrectLight()
      A0_6026:SwitchOnOffChildren(A1_6027)
    end
  end
end
function RigidBodyLight.OnDamage(A0_6029, A1_6030)
  if A1_6030.ipart and A1_6030.ipart >= 0 then
    A0_6029:AddImpulse(A1_6030.ipart, A1_6030.pos, A1_6030.dir, A1_6030.impact_force_mul)
  end
end
function RigidBodyLight.ShowCorrectLight(A0_6031)
  if A0_6031.lightOn and not A0_6031.destroyed then
    A0_6031:StopIdleSound()
    A0_6031:PlayRunSound()
    A0_6031:ShowLightOn()
  else
    A0_6031:ShowLightOff()
    A0_6031:StopRunSound()
    if not A0_6031.destroyed then
      A0_6031:PlayIdleSound()
    end
  end
end
function RigidBodyLight.UseLight(A0_6032, A1_6033)
  local L2_6034, L3_6035, L4_6036, L5_6037, L6_6038, L7_6039, L8_6040, L9_6041, L10_6042, L11_6043, L12_6044, L13_6045
  if A1_6033 == 0 then
    L3_6035 = A0_6032.PropertiesInstance
    L2_6034 = L3_6035.LightProperties_Destroyed
  else
    L3_6035 = A0_6032.PropertiesInstance
    L2_6034 = L3_6035.LightProperties_Base
  end
  L3_6035 = L2_6034.Style
  L4_6036 = L2_6034.Projector
  L5_6037 = L2_6034.Color
  L6_6038 = L2_6034.Options
  L7_6039 = L2_6034.Shadows
  L8_6040 = L5_6037.fDiffuseMultiplier
  L9_6041 = L5_6037.fSpecularMultiplier
  L10_6042 = A0_6032._LightTable
  L11_6043 = L2_6034.Radius
  L10_6042.radius = L11_6043
  L11_6043 = L2_6034.fAttenuationBulbSize
  L10_6042.attenuation_bulbsize = L11_6043
  L11_6043 = {}
  L12_6044 = L5_6037.clrDiffuse
  L12_6044 = L12_6044.x
  L12_6044 = L12_6044 * L8_6040
  L11_6043.x = L12_6044
  L12_6044 = L5_6037.clrDiffuse
  L12_6044 = L12_6044.y
  L12_6044 = L12_6044 * L8_6040
  L11_6043.y = L12_6044
  L12_6044 = L5_6037.clrDiffuse
  L12_6044 = L12_6044.z
  L12_6044 = L12_6044 * L8_6040
  L11_6043.z = L12_6044
  L10_6042.diffuse_color = L11_6043
  L10_6042.specular_multiplier = L9_6041
  L11_6043 = L6_6038.bAffectsThisAreaOnly
  L10_6042.this_area_only = L11_6043
  L11_6043 = L2_6034.Options
  L11_6043 = L11_6043.bAmbient
  L10_6042.ambient = L11_6043
  L11_6043 = L6_6038.bFakeLight
  L10_6042.fake = L11_6043
  L11_6043 = L6_6038.bIgnoresVisAreas
  L10_6042.ignore_visareas = L11_6043
  L11_6043 = L7_6039.nCastShadows
  L10_6042.cast_shadow = L11_6043
  L11_6043 = L7_6039.fShadowBias
  L10_6042.shadow_bias = L11_6043
  L11_6043 = L7_6039.fShadowSlopeBias
  L10_6042.shadow_slope_bias = L11_6043
  L11_6043 = L7_6039.fShadowResolutionScale
  L10_6042.shadowResolutionScale = L11_6043
  L11_6043 = L7_6039.nShadowMinResPercent
  L10_6042.shadowMinResolution = L11_6043
  L11_6043 = L7_6039.fShadowUpdateMinRadius
  L10_6042.shadowUpdate_MinRadius = L11_6043
  L11_6043 = L7_6039.fShadowUpdateRatio
  L10_6042.shadowUpdate_ratio = L11_6043
  L11_6043 = L4_6036.texture_Texture
  L10_6042.projector_texture = L11_6043
  L11_6043 = L4_6036.fProjectorFov
  L10_6042.proj_fov = L11_6043
  L11_6043 = L4_6036.fProjectorNearPlane
  L10_6042.proj_nearplane = L11_6043
  L11_6043 = L3_6035.nLightStyle
  L10_6042.style = L11_6043
  L11_6043 = L3_6035.fAnimationSpeed
  L10_6042.anim_speed = L11_6043
  L11_6043 = L3_6035.nAnimationPhase
  L10_6042.anim_phase = L11_6043
  L11_6043 = L3_6035.bFlareEnable
  L10_6042.flare_enable = L11_6043
  L11_6043 = L3_6035.flare_Flare
  L10_6042.flare_Flare = L11_6043
  L11_6043 = L3_6035.fFlareFOV
  L10_6042.flare_FOV = L11_6043
  L10_6042.lightmap_linear_attenuation = 1
  L10_6042.is_rectangle_light = 0
  L10_6042.is_sphere_light = 0
  L10_6042.area_sample_number = 1
  L10_6042.indoor_only = 0
  L11_6043 = {}
  L11_6043.x = 0
  L11_6043.y = 0
  L11_6043.z = 0
  L10_6042.RAE_AmbientColor = L11_6043
  L10_6042.RAE_MaxShadow = 1
  L10_6042.RAE_DistMul = 1
  L10_6042.RAE_DivShadow = 1
  L10_6042.RAE_ShadowHeight = 1
  L10_6042.RAE_FallOff = 2
  L10_6042.RAE_VisareaNumber = 0
  L12_6044 = A0_6032
  L11_6043 = A0_6032.LoadLight
  L13_6045 = -1
  L11_6043 = L11_6043(L12_6044, L13_6045, L10_6042)
  A0_6032.lightSlot = L11_6043
  L11_6043 = g_Vectors
  L11_6043 = L11_6043.temp_v1
  L11_6043.x = 0
  L12_6044 = math
  L12_6044 = L12_6044.sqrt
  L13_6045 = L2_6034.Options
  L13_6045 = L13_6045.vDirection
  L13_6045 = L13_6045.x
  L13_6045 = L13_6045 * L2_6034.Options.vDirection.x
  L13_6045 = L13_6045 + L2_6034.Options.vDirection.y * L2_6034.Options.vDirection.y
  L12_6044 = L12_6044(L13_6045)
  L13_6045 = math
  L13_6045 = L13_6045.atan2
  L13_6045 = L13_6045(-L2_6034.Options.vDirection.z, L12_6044)
  L11_6043.y = L13_6045
  L13_6045 = math
  L13_6045 = L13_6045.atan2
  L13_6045 = L13_6045(L2_6034.Options.vDirection.y, L2_6034.Options.vDirection.x)
  L11_6043.z = L13_6045
  L13_6045 = A0_6032.SetSlotAngles
  L13_6045(A0_6032, A0_6032.lightSlot, L11_6043)
  L13_6045 = g_Vectors
  L13_6045 = L13_6045.temp_v1
  L13_6045.x = L2_6034.Options.vOffset.x
  L13_6045.y = L2_6034.Options.vOffset.y
  L13_6045.z = L2_6034.Options.vOffset.z
  A0_6032:SetSlotPos(A0_6032.lightSlot, L13_6045)
  if L7_6039.nCastShadows ~= 0 and L7_6039.bIgnoreGeomCaster ~= 0 then
    A0_6032:SetSelfAsLightCasterException(A0_6032.lightSlot)
  end
end
RigidBodyLight.Default = {
  OnBeginState = function(A0_6046)
    if A0_6046:IsARigidBody() == 1 then
      if A0_6046.bRigidBodyActive ~= A0_6046.Properties.Physics.bRigidBodyActive then
        A0_6046:SetPhysicsProperties(0, A0_6046.Properties.Physics.bRigidBodyActive)
      else
        A0_6046:AwakePhysics(1 - A0_6046.Properties.Physics.bResting)
      end
    end
  end,
  OnDamage = RigidBodyLight.OnDamage,
  OnCollision = RigidBodyLight.OnCollision,
  OnPhysicsBreak = RigidBodyLight.OnPhysicsBreak
}
RigidBodyLight.Activated = {
  OnBeginState = function(A0_6047)
    if A0_6047:IsARigidBody() == 1 and A0_6047.bRigidBodyActive == 0 then
      A0_6047:SetPhysicsProperties(0, 1)
      A0_6047:AwakePhysics(1)
    end
  end,
  OnDamage = RigidBodyLight.OnDamage,
  OnCollision = RigidBodyLight.OnCollision,
  OnPhysicsBreak = RigidBodyLight.OnPhysicsBreak
}
RigidBodyLight.FlowEvents = {
  Inputs = {
    Disable = {
      RigidBodyLight.Event_Disable,
      "bool"
    },
    Enable = {
      RigidBodyLight.Event_Enable,
      "bool"
    },
    Hide = {
      RigidBodyLight.Event_Hide,
      "bool"
    },
    UnHide = {
      RigidBodyLight.Event_UnHide,
      "bool"
    },
    DisableUsable = {
      RigidBodyLight.Event_DisableUsable,
      "bool"
    },
    EnableUsable = {
      RigidBodyLight.Event_EnableUsable,
      "bool"
    },
    Use = {
      RigidBodyLight.Event_Use,
      "bool"
    }
  },
  Outputs = {
    Disabled = "bool",
    Enabled = "bool",
    Hidden = "bool",
    UnHidden = "bool",
    Used = "bool",
    DisableUsable = "bool",
    EnableUsable = "bool",
    Break = "bool",
    Used = "bool",
    Health = "float"
  }
}
MakeUsable(RigidBodyLight)
function RigidBodyLight.OnUsed(A0_6048, A1_6049, A2_6050)
  local L3_6051
  L3_6051 = BroadcastEvent
  L3_6051(A0_6048, "Used")
  L3_6051 = A0_6048.destroyed
  if not L3_6051 then
    L3_6051 = A0_6048.lightOn
    L3_6051 = L3_6051 == false
    A0_6048:SwitchOnOff(L3_6051)
  end
end
