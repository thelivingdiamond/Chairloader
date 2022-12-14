ArkLight = {
  Properties = {
    bUseSafeCarry = false,
    bIsMimicable = true,
    ability_CarryRequirement = "",
    bCanTriggerAreas = 0,
    ei_TransparencyMode = 0,
    textDisplayName = "",
    vector_ThrowAngularImpulse = {
      x = -10,
      y = 0,
      z = 0
    },
    color_DiffuseColor = {
      x = 1,
      y = 1,
      z = 1
    },
    eiMovementResponse = 0,
    particleeffect_MovementResponseVFX = "",
    carryDirection = {
      x = 0,
      y = 0,
      z = 0
    },
    carryHeightOffset = 0,
    carryForwardOffset = 0,
    vector_throwParticleOffset = {
      x = 0,
      y = 0,
      z = 0
    },
    bIsCarryable = 1,
    AI = {bUsedAsDynamicObstacle = 0},
    Audio = {
      audioTrigger_TurnOn = "",
      audioTrigger_TurnOff = "",
      audioTrigger_DisruptStart = "",
      audioTrigger_DisruptStop = "",
      audioTrigger_DestroySound = "",
      vector_Offset = {
        x = 0,
        y = 0,
        z = 0
      }
    },
    Sound = {
      audioTrigger_Carry = "",
      audioTrigger_HoldCarryStart = "",
      audioTrigger_HoldCarryCancel = ""
    },
    RecycleData = {
      organic = 0,
      mineral = 0,
      synthetic = 0,
      exotic = 0
    },
    EMPLight = {fRadius = 10},
    Light1 = {
      bEnabled = 1,
      fAttenuationBulbSize = 0.05,
      fDiffuseMultiplier = 1,
      fRadius = 10,
      fSpecularMultiplier = 1,
      vector_Offset = {
        x = 0,
        y = 0,
        z = 0
      },
      vector_Angles = {
        x = 0,
        y = 0,
        z = 0
      },
      nViewDistRatio = 100,
      Flare = {
        bFlareEnable = 1,
        flare_Flare = "",
        fFlareFOV = 360
      },
      Options = {
        bAmbient = 0,
        bFakeLight = 0,
        bGameplayLight = 0
      },
      Shadows = {
        eiCastShadows = 0,
        nCastShadowViewDistRatio = 100,
        bIgnoreGeomCaster = 1,
        fShadowBias = 1,
        fShadowSlopeBias = 1,
        fShadowResolutionScale = 1,
        eiShadowMinResPercent = 0,
        fShadowUpdateMinRadius = 10,
        fShadowUpdateRatio = 1
      },
      Shape = {
        fFov = 90,
        bPlanarLight = 0,
        fProjectorNearPlane = 0,
        texture_ProjectorTexture = "",
        bProjectModelEmissive = 0,
        fSourceDiameter = 1,
        fSourceWidth = 1
      },
      Style = {
        nAnimationPhase = 0,
        fAnimationSpeed = 1,
        lightanimation_LightAnimation = "",
        nLightStyle = 0,
        bTimeScrubbingInTrackView = 0,
        _fTimeScrubbed = 0
      }
    },
    Light2 = {
      bEnabled = 0,
      fAttenuationBulbSize = 0.05,
      fDiffuseMultiplier = 1,
      fRadius = 10,
      fSpecularMultiplier = 1,
      vector_Offset = {
        x = 0,
        y = 0,
        z = 0
      },
      vector_Angles = {
        x = 0,
        y = 0,
        z = 0
      },
      nViewDistRatio = 100,
      Flare = {
        bFlareEnable = 1,
        flare_Flare = "",
        fFlareFOV = 360
      },
      Options = {
        bAmbient = 0,
        bFakeLight = 0,
        bGameplayLight = 0
      },
      Shadows = {
        eiCastShadows = 0,
        nCastShadowViewDistRatio = 100,
        bIgnoreGeomCaster = 1,
        fShadowBias = 1,
        fShadowSlopeBias = 1,
        fShadowResolutionScale = 1,
        eiShadowMinResPercent = 0,
        fShadowUpdateMinRadius = 10,
        fShadowUpdateRatio = 1
      },
      Shape = {
        fFov = 90,
        bPlanarLight = 0,
        fProjectorNearPlane = 0,
        texture_ProjectorTexture = "",
        bProjectModelEmissive = 0,
        fSourceDiameter = 1,
        fSourceWidth = 1
      },
      Style = {
        nAnimationPhase = 0,
        fAnimationSpeed = 1,
        lightanimation_LightAnimation = "",
        nLightStyle = 0,
        bTimeScrubbingInTrackView = 0,
        _fTimeScrubbed = 0
      }
    },
    Model = {
      object_Model = "Objects/User/GamePlayTest/ArkLight_DefaultMesh/arklight_defaultmesh.cgf",
      material_Material = "",
      nGlowSubmatId = 3,
      color_EmissiveScalar = {
        x = 1,
        y = 1,
        z = 1
      }
    },
    Physics = {
      bPhysicalize = 1,
      bRigidBody = 0,
      bRigidBodyActive = 0,
      bActivateOnDamage = 0,
      bResting = 1,
      Density = -1,
      Mass = -1,
      bPushableByPlayers = 0,
      bPushableByAI = 0,
      bCanBreakOthers = 0,
      Simulation = {
        max_time_step = 0.02,
        sleep_speed = 0.04,
        damping = 0
      },
      MP = {bHackDontSyncPos = 0}
    },
    Emp = {
      lightDisruptionProfile_Profile = "10739735956140282401",
      particleeffect_EffectDisruptStart = "",
      particleeffect_EffectInterference = "",
      vector_EffectPositionOffset = {
        x = 0,
        y = 0,
        z = 0
      },
      vector_EffectRotationOffset = {
        x = 0,
        y = 0,
        z = 0
      }
    },
    Disrupt = {
      disruptionProfile_Profile = "10739735956140218188",
      particleeffect_SparkVFX = "",
      audioTrigger_SparkSFX = ""
    },
    Breakable = {
      object_BrokenModel = "",
      material_BrokenMaterial = "",
      signalgroup_SignalGroup = "",
      particleeffect_DestroyEffect = "",
      fMaxHealth = 0
    },
    Enabled = {
      particleeffect_Effect = "",
      vector_EffectPositionOffset = {
        x = 0,
        y = 0,
        z = 0
      },
      vector_EffectRotationOffset = {
        x = 0,
        y = 0,
        z = 0
      }
    }
  },
  PropertiesInstance = {
    bActive = 1,
    bIsBroken = 0,
    nViewDistRatioOverride = 0,
    bHideMeshInProbes = 0,
    texture_EmissiveOverride = "",
    bUsedAsDynamicObstacle = 1,
    EMPLight = {
      bEnabled = 0,
      fRadiusOverride = 0,
      vector_Offset = {
        x = 0,
        y = 0,
        z = 0
      }
    },
    Light1 = {
      bForceDisable = 0,
      bHiddenInProbes = 0,
      bAffectsThisAreaOnly = 1,
      fRadiusOverride = 0,
      eiCastShadowsOverride = -1,
      fShadowBiasOverride = 0,
      fFovOverride = 0,
      bForceIgnoreGeomCaster = 0,
      bIgnoresVisAreas = 0,
      nLightStyleOverride = -1,
      nLightStylePhaseOverride = 0,
      fLightStyleSpeedOverride = 0,
      nViewDistRatioOverride = 0,
      nCastShadowViewDistRatioOverride = 0,
      Fog = {
        bVolumetricFog = 0,
        bAffectsVolumetricFogOnly = 0,
        fFogRadialLobe = 0
      }
    },
    Light2 = {
      bForceDisable = 0,
      bHiddenInProbes = 0,
      bAffectsThisAreaOnly = 1,
      fRadiusOverride = 0,
      eiCastShadowsOverride = -1,
      fShadowBiasOverride = 0,
      fFovOverride = 0,
      bForceIgnoreGeomCaster = 0,
      bIgnoresVisAreas = 0,
      nLightStyleOverride = -1,
      nLightStylePhaseOverride = 0,
      fLightStyleSpeedOverride = 0,
      nViewDistRatioOverride = 0,
      nCastShadowViewDistRatioOverride = 0,
      Fog = {
        bVolumetricFog = 0,
        bAffectsVolumetricFogOnly = 0,
        fFogRadialLobe = 0
      }
    },
    Time = {fTimeOn = 0, fTimeOff = 0},
    Enabled = {fStrength = 1}
  },
  Editor = {
    Icon = "Light.bmp",
    ShowBounds = 0,
    AbsoluteRadius = 1,
    IsScalable = false
  },
  _fBrightness = 1,
  _cDiffuseColor0 = {
    x = 1,
    y = 1,
    z = 1
  },
  _cDiffuseColor1 = {
    x = 1,
    y = 1,
    z = 1
  },
  _nLightStyle0 = -1,
  _nLightStyle1 = -1,
  m_bVerbose = false
}
GetArkEntityUtils(ArkLight)
SetupCollisionFiltering(ArkLight)
SetupShadowCasterTypeFiltering(ArkLight.PropertiesInstance.Light1)
SetupShadowCasterTypeFiltering(ArkLight.PropertiesInstance.Light2)
LightSlot1 = 1
LightSlot2 = 2
function ArkLight.OnSpawn(A0_4235)
  A0_4235:DoReset()
end
function ArkLight.OnInit(A0_4236)
  A0_4236:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
  A0_4236:DoReset()
  A0_4236:CacheResources("ArkLight.lua")
end
function ArkLight.OnReset(A0_4237)
  A0_4237:DoReset()
end
function ArkLight.OnShutDown(A0_4238)
  local L1_4239
end
function ArkLight.OnPropertyChange(A0_4240)
  A0_4240:DoReset()
  if A0_4240.PropertiesInstance.Light1.bAffectsThisAreaOnly then
    A0_4240:UpdateLightClipBounds(LightSlot1)
  end
  if A0_4240.PropertiesInstance.Light2.bAffectsThisAreaOnly then
    A0_4240:UpdateLightClipBounds(LightSlot2)
  end
end
function ArkLight.OnSysSpecLightChanged(A0_4241)
  A0_4241:OnPropertyChange()
end
function ArkLight.CacheResources(A0_4242, A1_4243)
  Game.CacheResource(A1_4243, A0_4242.Properties.Light1.Shape.texture_ProjectorTexture, eGameCacheResourceType_Texture, 0)
  Game.CacheResource(A1_4243, A0_4242.Properties.Light2.Shape.texture_ProjectorTexture, eGameCacheResourceType_Texture, 0)
end
function ArkLight.DoReset(A0_4244)
  A0_4244:SetDisplayName(A0_4244.Properties.textDisplayName)
end
function ArkLight.SetupPhysics(A0_4245, A1_4246, A2_4247)
  local L3_4248, L4_4249
  L3_4248 = A0_4245.Properties
  L3_4248 = L3_4248.Physics
  L4_4249 = L3_4248.bPhysicalize
  if L4_4249 ~= 0 then
    L4_4249 = EmptyString
    L4_4249 = L4_4249(A2_4247)
    if not L4_4249 then
      L4_4249 = EntityCommon
      L4_4249 = L4_4249.PhysicalizeRigid
      L4_4249(A0_4245, A1_4246, L3_4248, A0_4245.bRigidBodyActive)
    end
  else
    L4_4249 = {}
    A0_4245:Physicalize(A1_4246, PE_NONE, L4_4249)
  end
  L4_4249 = A0_4245.Properties
  L4_4249 = L4_4249.bCanTriggerAreas
  if L4_4249 == 1 then
    L4_4249 = EmptyString
    L4_4249 = L4_4249(A2_4247)
    if not L4_4249 then
      L4_4249 = A0_4245.SetFlags
      L4_4249(A0_4245, ENTITY_FLAG_TRIGGER_AREAS, 0)
    end
  else
    L4_4249 = A0_4245.SetFlags
    L4_4249(A0_4245, ENTITY_FLAG_TRIGGER_AREAS, 2)
  end
end
function ArkLight.OnUnHidden(A0_4250)
  local L1_4251
end
function ArkLight.GetRemoteManipulationInteraction(A0_4252)
  local L1_4253
  L1_4253 = {}
  if A0_4252.Properties.Physics.bRigidBody == 1 and A0_4252:GetPhysicalStats().mass > 0 and A0_4252.Properties.ability_CarryRequirement ~= "" and A0_4252.Properties.bIsCarryable == 1 then
    L1_4253.ActionType = "Carry"
  end
  L1_4253.CouldChange = false
  return L1_4253
end
function ArkLight.OnStartBeingCarried(A0_4254)
  BroadcastEvent(A0_4254, "OnStartBeingCarried")
end
function ArkLight.GetEditorIcon(A0_4255, A1_4256)
  local L2_4257, L3_4258, L4_4259, L5_4260, L6_4261
  L2_4257 = A0_4255.Properties
  L2_4257 = L2_4257.Light1
  L3_4258 = A0_4255.PropertiesInstance
  L3_4258 = L3_4258.Light1
  L4_4259 = "Point"
  L5_4260 = L2_4257.Shape
  L5_4260 = L5_4260.bPlanarLight
  if L5_4260 ~= 0 then
    L4_4259 = "Area"
  else
    L5_4260 = L2_4257.Shape
    L5_4260 = L5_4260.texture_ProjectorTexture
    if L5_4260 ~= nil then
      L5_4260 = L2_4257.Shape
      L5_4260 = L5_4260.texture_ProjectorTexture
      if L5_4260 ~= "" then
        L4_4259 = "Projector"
      end
    end
  end
  L5_4260 = L2_4257.Shadows
  L5_4260 = L5_4260.eiCastShadows
  L6_4261 = L3_4258.eiCastShadowsOverride
  if L6_4261 >= 0 then
    L5_4260 = L3_4258.eiCastShadowsOverride
  end
  L6_4261 = "NoShadows"
  if L5_4260 > 0 then
    L6_4261 = "Shadows"
  end
  A1_4256.Icon = "Light." .. L4_4259 .. "." .. L6_4261 .. ".bmp"
end
function ArkLight.SetBrightness(A0_4262, A1_4263)
  A0_4262._fBrightness = A1_4263
  BroadcastEvent(A0_4262, "SetBrightness")
end
function ArkLight.SetDiffuseColor(A0_4264, A1_4265, A2_4266)
  A0_4264["_cDiffuseColor" .. A1_4265] = A2_4266
  BroadcastEvent(A0_4264, "SetDiffuseColor")
end
function ArkLight.SetLightStyle(A0_4267, A1_4268, A2_4269)
  A0_4267["_nLightStyle" .. A1_4268] = A2_4269
  BroadcastEvent(A0_4267, "SetLightStyle")
end
function ArkLight.Event_Brightness(A0_4270, A1_4271, A2_4272)
  A0_4270:SetBrightness(A2_4272)
end
function ArkLight.Event_ResetBrightness(A0_4273)
  A0_4273:SetBrightness(1)
end
function ArkLight.Event_DiffuseColor1(A0_4274, A1_4275, A2_4276)
  A0_4274:SetDiffuseColor(0, A2_4276)
end
function ArkLight.Event_DiffuseColor2(A0_4277, A1_4278, A2_4279)
  A0_4277:SetDiffuseColor(1, A2_4279)
end
function ArkLight.Event_LightStyle1(A0_4280, A1_4281, A2_4282)
  A0_4280:SetLightStyle(0, A2_4282)
end
function ArkLight.Event_LightStyle2(A0_4283, A1_4284, A2_4285)
  A0_4283:SetLightStyle(1, A2_4285)
end
function ArkLight.Event_On(A0_4286)
  A0_4286:SetBrightness(1)
end
function ArkLight.Event_Off(A0_4287)
  A0_4287:SetBrightness(0)
end
ArkLight.FlowEvents = {
  Inputs = {
    Brightness = {
      ArkLight.Event_Brightness,
      "float"
    },
    ResetBrightness = {
      ArkLight.Event_ResetBrightness,
      "bool"
    },
    DiffuseColor1 = {
      ArkLight.Event_DiffuseColor1,
      "vec3"
    },
    DiffuseColor2 = {
      ArkLight.Event_DiffuseColor2,
      "vec3"
    },
    LightStyle1 = {
      ArkLight.Event_LightStyle1,
      "int"
    },
    LightStyle2 = {
      ArkLight.Event_LightStyle2,
      "int"
    },
    On = {
      ArkLight.Event_On,
      "bool"
    },
    Off = {
      ArkLight.Event_Off,
      "bool"
    }
  },
  Outputs = {}
}
