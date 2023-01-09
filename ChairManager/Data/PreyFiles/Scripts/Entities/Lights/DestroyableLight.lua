DestroyableLight = {
  Client = {},
  Server = {},
  States = {"Alive", "Dead"},
  Properties = {
    Model = {
      object_Model = "engine/engineassets/objects/default.cgf",
      SubObject_Name = "",
      object_ModelDestroyed = "",
      SubObject_NameDestroyed = ""
    },
    Damage = {
      bPlayerOnly = 1,
      fHealth = 100,
      fDamageTreshold = 0,
      bExplode = 0
    },
    DamageMultipliers = {fCollision = 1, fBullet = 1},
    Vulnerability = {
      bExplosion = 1,
      bCollision = 1,
      bMelee = 1,
      bBullet = 1,
      bOther = 1
    },
    Breakage = {
      fLifeTime = 10,
      fExplodeImpulse = 0,
      bSurfaceEffects = 1
    },
    Explosion = {
      Delay = 0,
      ParticleEffect = "explosions.grenade_air.explosion",
      EffectScale = 1,
      MinRadius = 5,
      Radius = 10,
      MinPhysRadius = 2.5,
      PhysRadius = 5,
      Pressure = 1000,
      Damage = 1000,
      Direction = {
        x = 0,
        y = 0,
        z = 1
      },
      vOffset = {
        x = 0,
        y = 0,
        z = 0
      },
      DelayEffect = {
        bHasDelayEffect = 0,
        ParticleEffect = "",
        vOffset = {
          x = 0,
          y = 0,
          z = 0
        },
        vRotation = {
          x = 0,
          y = 0,
          z = 0
        },
        Params = {
          SpawnPeriod = 0,
          Scale = 1,
          CountScale = 1,
          bCountPerUnit = 0,
          bSizePerUnit = 0,
          AttachType = "none",
          AttachForm = "none",
          bPrime = 0
        }
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
      },
      fAISoundRadius = 30
    },
    Physics = {
      bRigidBody = 1,
      bRigidBodyActive = 1,
      bRigidBodyAfterDeath = 1,
      bActivateOnDamage = 0,
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
    }
  },
  PropertiesInstance = {
    bTurnedOn = 1,
    LightProperties_Base = {
      _nVersion = -1,
      bUseThisLight = 1,
      Radius = 10,
      fAttenuationBulbSize = 0.05,
      Style = {
        nLightStyle = 0,
        fAnimationSpeed = 1,
        nAnimationPhase = 0
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
        nCastShadowViewDistRatio = 100,
        bIgnoreGeomCaster = 1,
        fShadowBias = 1,
        fShadowSlopeBias = 1,
        fShadowResolutionScale = 1,
        nShadowMinResPercent = 0,
        fShadowUpdateMinRadius = 10,
        fShadowUpdateRatio = 1
      },
      Shape = {
        bAreaLight = 0,
        fPlaneWidth = 1,
        fPlaneHeight = 1
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
        nAnimationPhase = 0
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
      },
      Shape = {
        bAreaLight = 0,
        fPlaneWidth = 1,
        fPlaneHeight = 1
      }
    }
  },
  Editor = {IsScalable = false},
  _LightTable = {},
  lightSlot = -1,
  lightOn = true,
  materialIsCloned = false
}
function DestroyableLight.OnLoad(A0_5749, A1_5750)
  if A0_5749.lightSlot then
    A0_5749:FreeSlot(A0_5749.lightSlot)
  end
  A0_5749.bUsable = A1_5750.bUsable
  A0_5749.shooterId = A1_5750.shooterId
  A0_5749.health = A1_5750.health
  A0_5749.dead = A1_5750.dead
  A0_5749.FXSlot = A1_5750.FXSlot
  A0_5749.exploded = A1_5750.exploded
  A0_5749.rigidBodySlot = A1_5750.rigidBodySlot
  A0_5749.isRigidBody = A1_5750.isRigidBody
  A0_5749.currentSlot = A1_5750.currentSlot
  A0_5749.LastHit = A1_5750.LastHit
  A0_5749.lightSlot = A1_5750.lightSlot
  A0_5749.lightOn = A1_5750.lightOn
  A0_5749.origGlowValue = A1_5750.origGlowValue
  A0_5749.materialIsCloned = A1_5750.materialIsCloned
  A0_5749:SetCurrentSlot(A0_5749.currentSlot)
  if A0_5749.dead then
    if A0_5749.Properties.Physics.bRigidBodyAfterDeath == 1 then
      A0_5749.Properties.Physics.bRigidBody = 1
      A0_5749:PhysicalizeThis(A0_5749.currentSlot)
      A0_5749.Properties.Physics.bRigidBody = A0_5749.Properties.Physics.bRigidBody
    end
  else
    A0_5749:PhysicalizeThis(A0_5749.currentSlot)
  end
  if A0_5749:GetState() ~= A1_5750.state then
    A0_5749:GotoState(A1_5750.state)
  end
  A0_5749.runSoundId = 0
  A0_5749.idleSoundId = 0
  A0_5749:ShowCorrectLight()
end
function DestroyableLight.OnSave(A0_5751, A1_5752)
  A1_5752.bUsable = A0_5751.bUsable
  A1_5752.shooterId = A0_5751.shooterId
  A1_5752.health = A0_5751.health
  A1_5752.FXSlot = A0_5751.FXSlot
  A1_5752.dead = A0_5751.dead
  A1_5752.exploded = A0_5751.exploded
  A1_5752.rigidBodySlot = A0_5751.rigidBodySlot
  A1_5752.isRigidBody = A0_5751.isRigidBody
  A1_5752.currentSlot = A0_5751.currentSlot
  A1_5752.LastHit = A0_5751.LastHit
  A1_5752.state = A0_5751:GetState()
  A1_5752.lightSlot = A0_5751.lightSlot
  A1_5752.lightOn = A0_5751.lightOn
  A1_5752.origGlowValue = A0_5751.origGlowValue
  A1_5752.materialIsCloned = A0_5751.materialIsCloned
end
function DestroyableLight.CommonInit(A0_5753)
  A0_5753.bReloadGeoms = 1
  A0_5753.bUsable = A0_5753.Properties.bUsable
  A0_5753.lightOn = A0_5753.PropertiesInstance.bTurnedOn == 1
  if not A0_5753.bInitialized then
    A0_5753.LastHit = {
      impulse = {
        x = 0,
        y = 0,
        z = 0
      },
      pos = {
        x = 0,
        y = 0,
        z = 0
      }
    }
    A0_5753:Reload()
    A0_5753.bInitialized = 1
    A0_5753:GotoState("Alive")
  end
end
function DestroyableLight.Server.OnInit(A0_5754)
  A0_5754:CommonInit()
end
function DestroyableLight.Client.OnInit(A0_5755)
  A0_5755:CommonInit()
  A0_5755:ShowCorrectLight()
  A0_5755:CacheResources("DestroyableLight.lua")
end
function DestroyableLight.CacheResources(A0_5756, A1_5757)
  local L2_5758
  L2_5758 = 0
  Game.CacheResource(A1_5757, A0_5756.PropertiesInstance.LightProperties_Base.Projector.texture_Texture, eGameCacheResourceType_Texture, L2_5758)
  L2_5758 = 0
  Game.CacheResource(A1_5757, A0_5756.PropertiesInstance.LightProperties_Destroyed.Projector.texture_Texture, eGameCacheResourceType_Texture, L2_5758)
  A0_5756:PreLoadParticleEffect(A0_5756.Properties.Explosion.ParticleEffect)
  A0_5756:PreLoadParticleEffect(A0_5756.Properties.Explosion.DelayEffect.ParticleEffect)
end
function DestroyableLight.OnPropertyChange(A0_5759)
  A0_5759.bReloadGeoms = 1
  A0_5759:Reload()
  if A0_5759.PropertiesInstance.LightProperties_Base.Options.bAffectsThisAreaOnly then
    A0_5759:UpdateLightClipBounds(A0_5759.lightSlot)
  end
  A0_5759:StopIdleSound()
  A0_5759:StopRunSound()
end
function DestroyableLight.OnShutDown(A0_5760)
  local L1_5761
end
function DestroyableLight.OnReset(A0_5762)
  A0_5762:RemoveEffect()
  if A0_5762:GetState() ~= "Alive" then
    A0_5762:Reload()
  else
    A0_5762.lightOn = A0_5762.PropertiesInstance.bTurnedOn == 1
    A0_5762:ShowCorrectLight()
  end
  A0_5762:AwakePhysics(0)
end
function DestroyableLight.RemoveEffect(A0_5763)
  if A0_5763.FXSlot then
    A0_5763:FreeSlot(A0_5763.FXSlot)
    A0_5763.FXSlot = -1
  end
end
function DestroyableLight.Reload(A0_5764)
  A0_5764:ResetOnUsed()
  A0_5764.bUsable = A0_5764.Properties.bUsable
  A0_5764.shooterId = NULL_ENTITY
  A0_5764.health = A0_5764.Properties.Damage.fHealth
  A0_5764.dead = nil
  A0_5764.exploded = nil
  A0_5764.rigidBodySlot = nil
  A0_5764.isRigidBody = nil
  if A0_5764.bReloadGeoms == 1 then
    if not EmptyString(A0_5764.Properties.Model.object_Model) then
      A0_5764:LoadObject(3, A0_5764.Properties.Model.object_Model)
      A0_5764:DrawSlot(3, 0)
      A0_5764:LoadSubObject(0, A0_5764.Properties.Model.object_Model, A0_5764.Properties.Model.SubObject_Name)
    end
    if not EmptyString(A0_5764.Properties.Model.object_ModelDestroyed) then
      A0_5764:LoadSubObject(1, A0_5764.Properties.Model.object_ModelDestroyed, A0_5764.Properties.Model.SubObject_NameDestroyed)
    elseif not EmptyString(A0_5764.Properties.Model.SubObject_NameDestroyed) then
      A0_5764:LoadSubObject(1, A0_5764.Properties.Model.object_Model, A0_5764.Properties.Model.SubObject_NameDestroyed)
    end
    A0_5764:SetCurrentSlot(0)
    A0_5764:PhysicalizeThis(0)
    if not A0_5764.origGlowValue or A0_5764.lightOn then
      A0_5764.origGlowValue = A0_5764:GetMaterialFloat(0, A0_5764.PropertiesInstance.LightProperties_Base.Options.nGlowSubmatId, MaterialFloatParams.emissive_intensity)
    end
  end
  A0_5764.bReloadGeoms = 0
  A0_5764:GotoState("Alive")
  A0_5764.lightOn = A0_5764.PropertiesInstance.bTurnedOn == 1
  if A0_5764.idleSoundId == nil then
    A0_5764.idleSoundId = 0
  end
  if A0_5764.runSoundId == nil then
    A0_5764.runSoundId = 0
  end
  A0_5764:ShowCorrectLight()
end
function DestroyableLight.PhysicalizeThis(A0_5765, A1_5766)
  local L2_5767
  L2_5767 = A0_5765.Properties
  L2_5767 = L2_5767.Physics
  L2_5767 = L2_5767.MP
  L2_5767 = L2_5767.bHackDontSyncPos
  if L2_5767 == 1 then
    L2_5767 = CryAction
    L2_5767 = L2_5767.DontSyncPhysics
    L2_5767(A0_5765.id)
  end
  L2_5767 = A0_5765.Properties
  L2_5767 = L2_5767.Physics
  EntityCommon.PhysicalizeRigid(A0_5765, A1_5766, L2_5767, A0_5765.bRigidBodyActive)
end
function DestroyableLight.SetCurrentSlot(A0_5768, A1_5769)
  if A1_5769 == 0 then
    A0_5768:DrawSlot(0, 1)
    A0_5768:DrawSlot(1, 0)
  else
    A0_5768:DrawSlot(0, 0)
    A0_5768:DrawSlot(1, 1)
  end
  A0_5768.currentSlot = A1_5769
end
function DestroyableLight.Explode(A0_5770)
  local L1_5771, L2_5772, L3_5773, L4_5774, L5_5775, L6_5776, L7_5777, L8_5778, L9_5779, L10_5780, L11_5781, L12_5782, L13_5783, L14_5784, L15_5785
  L1_5771 = A0_5770.Properties
  A0_5770.bUsable = 0
  A0_5770.bReloadGeoms = 1
  A0_5770.lightOn = false
  L2_5772 = A0_5770.LastHit
  L2_5772 = L2_5772.pos
  L3_5773 = A0_5770.LastHit
  L3_5773 = L3_5773.impulse
  L5_5775 = A0_5770
  L4_5774 = A0_5770.BreakToPieces
  L6_5776 = 0
  L7_5777 = 0
  L8_5778 = L1_5771.Breakage
  L8_5778 = L8_5778.fExplodeImpulse
  L9_5779 = L2_5772
  L10_5780 = L3_5773
  L11_5781 = L1_5771.Breakage
  L11_5781 = L11_5781.fLifeTime
  L12_5782 = L1_5771.Breakage
  L12_5782 = L12_5782.bSurfaceEffects
  L4_5774(L5_5775, L6_5776, L7_5777, L8_5778, L9_5779, L10_5780, L11_5781, L12_5782)
  L5_5775 = A0_5770
  L4_5774 = A0_5770.RemoveDecals
  L4_5774(L5_5775)
  L4_5774 = false
  L6_5776 = A0_5770
  L5_5775 = A0_5770.SetCurrentSlot
  L7_5777 = 1
  L5_5775(L6_5776, L7_5777)
  L5_5775 = L1_5771.Model
  L5_5775 = L5_5775.object_ModelDestroyed
  if L5_5775 == "" then
    L5_5775 = L1_5771.Model
    L5_5775 = L5_5775.SubObject_NameDestroyed
  else
    if L5_5775 ~= "" then
      L5_5775 = L1_5771.Physics
      L5_5775 = L5_5775.bRigidBodyAfterDeath
      if L5_5775 == 1 then
        L5_5775 = L1_5771.Physics
        L5_5775 = L5_5775.bRigidBody
        L6_5776 = L1_5771.Physics
        L6_5776.bRigidBody = 1
        L7_5777 = A0_5770
        L6_5776 = A0_5770.PhysicalizeThis
        L8_5778 = 1
        L6_5776(L7_5777, L8_5778)
        L6_5776 = L1_5771.Physics
        L6_5776.bRigidBody = L5_5775
        L7_5777 = A0_5770
        L6_5776 = A0_5770.AwakePhysics
        L8_5778 = 1
        L6_5776(L7_5777, L8_5778)
      else
        L6_5776 = A0_5770
        L5_5775 = A0_5770.PhysicalizeThis
        L7_5777 = 1
        L5_5775(L6_5776, L7_5777)
        L6_5776 = A0_5770
        L5_5775 = A0_5770.AwakePhysics
        L7_5777 = 1
        L5_5775(L6_5776, L7_5777)
      end
  end
  else
    L4_5774 = true
  end
  L5_5775 = NumberToBool
  L6_5776 = A0_5770.Properties
  L6_5776 = L6_5776.Damage
  L6_5776 = L6_5776.bExplode
  L5_5775 = L5_5775(L6_5776)
  if L5_5775 then
    L5_5775 = A0_5770.Properties
    L5_5775 = L5_5775.Explosion
    L7_5777 = A0_5770
    L6_5776 = A0_5770.GetWorldPos
    L6_5776 = L6_5776(L7_5777)
    L8_5778 = A0_5770
    L7_5777 = A0_5770.GetDirectionVector
    L9_5779 = 0
    L7_5777 = L7_5777(L8_5778, L9_5779)
    L9_5779 = A0_5770
    L8_5778 = A0_5770.GetDirectionVector
    L10_5780 = 1
    L8_5778 = L8_5778(L9_5779, L10_5780)
    L10_5780 = A0_5770
    L9_5779 = A0_5770.GetDirectionVector
    L11_5781 = 2
    L9_5779 = L9_5779(L10_5780, L11_5781)
    L10_5780 = {}
    L10_5780.x = 0
    L10_5780.y = 0
    L10_5780.z = 0
    L11_5781 = CopyVector
    L12_5782 = L10_5780
    L13_5783 = L5_5775.vOffset
    L11_5781(L12_5782, L13_5783)
    L11_5781 = L6_5776.x
    L12_5782 = L7_5777.x
    L13_5783 = L10_5780.x
    L12_5782 = L12_5782 * L13_5783
    L11_5781 = L11_5781 + L12_5782
    L12_5782 = L8_5778.x
    L13_5783 = L10_5780.y
    L12_5782 = L12_5782 * L13_5783
    L11_5781 = L11_5781 + L12_5782
    L12_5782 = L9_5779.x
    L13_5783 = L10_5780.z
    L12_5782 = L12_5782 * L13_5783
    L11_5781 = L11_5781 + L12_5782
    L6_5776.x = L11_5781
    L11_5781 = L6_5776.y
    L12_5782 = L7_5777.y
    L13_5783 = L10_5780.x
    L12_5782 = L12_5782 * L13_5783
    L11_5781 = L11_5781 + L12_5782
    L12_5782 = L8_5778.y
    L13_5783 = L10_5780.y
    L12_5782 = L12_5782 * L13_5783
    L11_5781 = L11_5781 + L12_5782
    L12_5782 = L9_5779.y
    L13_5783 = L10_5780.z
    L12_5782 = L12_5782 * L13_5783
    L11_5781 = L11_5781 + L12_5782
    L6_5776.y = L11_5781
    L11_5781 = L6_5776.z
    L12_5782 = L7_5777.z
    L13_5783 = L10_5780.x
    L12_5782 = L12_5782 * L13_5783
    L11_5781 = L11_5781 + L12_5782
    L12_5782 = L8_5778.z
    L13_5783 = L10_5780.y
    L12_5782 = L12_5782 * L13_5783
    L11_5781 = L11_5781 + L12_5782
    L12_5782 = L9_5779.z
    L13_5783 = L10_5780.z
    L12_5782 = L12_5782 * L13_5783
    L11_5781 = L11_5781 + L12_5782
    L6_5776.z = L11_5781
    L11_5781 = L6_5776
    L12_5782 = g_Vectors
    L12_5782 = L12_5782.temp_v1
    L13_5783 = g_Vectors
    L13_5783 = L13_5783.temp_v2
    L14_5784 = CopyVector
    L15_5785 = L13_5783
    L14_5784(L15_5785, L5_5775.Direction)
    L14_5784 = L13_5783.x
    if L14_5784 == 0 then
      L14_5784 = L13_5783.y
      if L14_5784 == 0 then
        L14_5784 = L13_5783.z
        if L14_5784 == 0 then
          L13_5783.y = 1
        end
      end
    end
    L14_5784 = L7_5777.x
    L15_5785 = L13_5783.x
    L14_5784 = L14_5784 * L15_5785
    L15_5785 = L8_5778.x
    L15_5785 = L15_5785 * L13_5783.y
    L14_5784 = L14_5784 + L15_5785
    L15_5785 = L9_5779.x
    L15_5785 = L15_5785 * L13_5783.z
    L14_5784 = L14_5784 + L15_5785
    L12_5782.x = L14_5784
    L14_5784 = L7_5777.y
    L15_5785 = L13_5783.x
    L14_5784 = L14_5784 * L15_5785
    L15_5785 = L8_5778.y
    L15_5785 = L15_5785 * L13_5783.y
    L14_5784 = L14_5784 + L15_5785
    L15_5785 = L9_5779.y
    L15_5785 = L15_5785 * L13_5783.z
    L14_5784 = L14_5784 + L15_5785
    L12_5782.y = L14_5784
    L14_5784 = L7_5777.z
    L15_5785 = L13_5783.x
    L14_5784 = L14_5784 * L15_5785
    L15_5785 = L8_5778.z
    L15_5785 = L15_5785 * L13_5783.y
    L14_5784 = L14_5784 + L15_5785
    L15_5785 = L9_5779.z
    L15_5785 = L15_5785 * L13_5783.z
    L14_5784 = L14_5784 + L15_5785
    L12_5782.z = L14_5784
    L14_5784 = EmptyString
    L15_5785 = L5_5775.ParticleEffect
    L14_5784 = L14_5784(L15_5785)
    if not L14_5784 then
      L14_5784 = {}
      L15_5785 = L5_5775.EffectScale
      L14_5784.Scale = L15_5785
      L15_5785 = A0_5770.LoadParticleEffect
      L15_5785 = L15_5785(A0_5770, -1, L5_5775.ParticleEffect, L14_5784)
      A0_5770:SetSlotPosAndDir(L15_5785, L5_5775.vOffset, L13_5783)
    end
    L14_5784 = g_gameRules
    L15_5785 = L14_5784
    L14_5784 = L14_5784.CreateExplosion
    L14_5784(L15_5785, A0_5770.shooterId, A0_5770.id, L5_5775.Damage, L11_5781, L12_5782, L5_5775.Radius, nil, L5_5775.Pressure, L5_5775.HoleSize, nil, nil, L5_5775.MinRadius, L5_5775.MinPhysRadius, L5_5775.PhysRadius)
  end
  A0_5770.exploded = true
  L5_5775 = A0_5770.Properties
  L5_5775 = L5_5775.Sound
  L5_5775 = L5_5775.fAISoundRadius
  if L5_5775 > 0 then
    L6_5776 = A0_5770.shooterId
    if L6_5776 then
      L6_5776 = AI
      L6_5776 = L6_5776.SoundEvent
      L8_5778 = A0_5770
      L7_5777 = A0_5770.GetWorldPos
      L7_5777 = L7_5777(L8_5778)
      L8_5778 = L5_5775
      L9_5779 = AISOUND_EXPLOSION
      L10_5780 = A0_5770.shooterId
      L6_5776(L7_5777, L8_5778, L9_5779, L10_5780)
    else
      L6_5776 = Log
      L7_5777 = "AI.SoundEvent invalid parameter self.shooterId"
      L6_5776(L7_5777)
    end
  end
  L6_5776 = BroadcastEvent
  L7_5777 = A0_5770
  L8_5778 = "Explode"
  L6_5776(L7_5777, L8_5778)
  if L4_5774 == true then
    L7_5777 = A0_5770
    L6_5776 = A0_5770.Hide
    L8_5778 = 1
    L6_5776(L7_5777, L8_5778)
  end
end
function DestroyableLight.Die(A0_5786, A1_5787)
  local L2_5788
  A0_5786.shooterId = A1_5787
  A0_5786.dead = true
  L2_5788 = A0_5786.health
  if L2_5788 > 0 then
    A0_5786.health = 0
  end
  L2_5788 = A0_5786.exploded
  if not L2_5788 then
    L2_5788 = A0_5786.Properties
    L2_5788 = L2_5788.Explosion
    if 0 < L2_5788.Delay and not L2_5788.DelayEffect.bHasDelayEffect == 1 then
      A0_5786:SetTimer(0, L2_5788.Delay * 1000)
    else
      A0_5786:GotoState("Dead")
    end
  end
end
function DestroyableLight.IsDead(A0_5789)
  local L1_5790
  L1_5790 = A0_5789.health
  L1_5790 = L1_5790 <= 0 or L1_5790 == true
  return L1_5790
end
function DestroyableLight.GetHealth(A0_5791)
  local L1_5792
  L1_5792 = A0_5791.health
  return L1_5792
end
function DestroyableLight.Server.OnHit(A0_5793, A1_5794)
  local L2_5795, L3_5796, L4_5797, L5_5798
  L2_5795 = A1_5794.dir
  if L2_5795 then
    L3_5796 = A0_5793
    L2_5795 = A0_5793.AddImpulse
    L4_5797 = A1_5794.partId
    L4_5797 = L4_5797 or -1
    L5_5798 = A1_5794.pos
    L2_5795(L3_5796, L4_5797, L5_5798, A1_5794.dir, A1_5794.damage, 1)
  end
  L2_5795 = CopyVector
  L3_5796 = A0_5793.LastHit
  L3_5796 = L3_5796.pos
  L4_5797 = A1_5794.pos
  L2_5795(L3_5796, L4_5797)
  L2_5795 = CopyVector
  L3_5796 = A0_5793.LastHit
  L3_5796 = L3_5796.impulse
  L4_5797 = A1_5794.dir
  if not L4_5797 then
    L4_5797 = g_Vectors
    L4_5797 = L4_5797.v000
  end
  L2_5795(L3_5796, L4_5797)
  L2_5795 = A0_5793.LastHit
  L2_5795 = L2_5795.impulse
  L3_5796 = A0_5793.LastHit
  L3_5796 = L3_5796.impulse
  L3_5796 = L3_5796.x
  L4_5797 = A1_5794.damage
  L3_5796 = L3_5796 * L4_5797
  L2_5795.x = L3_5796
  L2_5795 = A0_5793.LastHit
  L2_5795 = L2_5795.impulse
  L3_5796 = A0_5793.LastHit
  L3_5796 = L3_5796.impulse
  L3_5796 = L3_5796.y
  L4_5797 = A1_5794.damage
  L3_5796 = L3_5796 * L4_5797
  L2_5795.y = L3_5796
  L2_5795 = A0_5793.LastHit
  L2_5795 = L2_5795.impulse
  L3_5796 = A0_5793.LastHit
  L3_5796 = L3_5796.impulse
  L3_5796 = L3_5796.z
  L4_5797 = A1_5794.damage
  L3_5796 = L3_5796 * L4_5797
  L2_5795.z = L3_5796
  L2_5795 = A1_5794.damage
  L3_5796 = A0_5793.Properties
  L3_5796 = L3_5796.Vulnerability
  L4_5797 = A0_5793.Properties
  L4_5797 = L4_5797.DamageMultipliers
  L5_5798 = true
  if A1_5794.explosion then
    L5_5798 = NumberToBool(L3_5796.bExplosion)
  elseif A1_5794.type == "collision" then
    L5_5798 = NumberToBool(L3_5796.bCollision)
    L2_5795 = L2_5795 * L4_5797.fCollision
  elseif A1_5794.type == "bullet" then
    L5_5798 = NumberToBool(L3_5796.bBullet)
    L2_5795 = L2_5795 * L4_5797.fBullet
  elseif A1_5794.type == "melee" then
    L5_5798 = NumberToBool(L3_5796.bMelee)
  else
    L5_5798 = NumberToBool(L3_5796.bOther)
  end
  L5_5798 = L5_5798 and L2_5795 > A0_5793.Properties.Damage.fDamageTreshold
  if L5_5798 and NumberToBool(A0_5793.Properties.Damage.bPlayerOnly) and not g_gameRules.game:IsPlayer(A1_5794.shooterId) then
    L5_5798 = false
  end
  BroadcastEvent(A0_5793, "Hit")
  if L5_5798 then
    A0_5793.health = A0_5793.health - L2_5795
    if A0_5793.health <= 0 then
      A0_5793:Die(A1_5794.shooterId)
    end
    if NumberToBool(A0_5793.Properties.bActivateOnDamage) then
      A0_5793:AwakePhysics(1)
    end
    if A0_5793.Properties.Explosion.DelayEffect.bHasDelayEffect == 1 and (not A0_5793.FXSlot or A0_5793.FXSlot == -1) then
      A0_5793:SetTimer(0, (A0_5793.Properties.Explosion.Delay + randomF(0, 1.5)) * 1000)
      if not EmptyString(A0_5793.Properties.Explosion.DelayEffect.ParticleEffect) then
        A0_5793.FXSlot = A0_5793:LoadParticleEffect(-1, A0_5793.Properties.Explosion.DelayEffect.ParticleEffect, A0_5793.Properties.Explosion.DelayEffect.Params)
        A0_5793:SetSlotPos(A0_5793.FXSlot, A0_5793.Properties.Explosion.DelayEffect.vOffset)
        A0_5793:SetSlotAngles(A0_5793.FXSlot, A0_5793.Properties.Explosion.DelayEffect.vRotation)
      end
    end
  end
  return A0_5793.health <= 0
end
function DestroyableLight.Server.OnTimer(A0_5799, A1_5800, A2_5801)
  if A1_5800 == 0 then
    A0_5799:GotoState("Dead")
  end
end
function DestroyableLight.UseLight(A0_5802, A1_5803)
  local L2_5804, L3_5805, L4_5806, L5_5807, L6_5808, L7_5809, L8_5810, L9_5811, L10_5812, L11_5813, L12_5814, L13_5815, L14_5816
  if A1_5803 == 0 then
    L3_5805 = A0_5802.PropertiesInstance
    L2_5804 = L3_5805.LightProperties_Destroyed
  else
    L3_5805 = A0_5802.PropertiesInstance
    L2_5804 = L3_5805.LightProperties_Base
  end
  L3_5805 = L2_5804.Style
  L4_5806 = L2_5804.Projector
  L5_5807 = L2_5804.Color
  L6_5808 = L2_5804.Options
  L7_5809 = L2_5804.Shape
  L8_5810 = L2_5804.Shadows
  L9_5811 = L5_5807.fDiffuseMultiplier
  L10_5812 = L5_5807.fSpecularMultiplier
  L11_5813 = A0_5802._LightTable
  L12_5814 = L2_5804.Radius
  L11_5813.radius = L12_5814
  L12_5814 = L2_5804.fAttenuationBulbSize
  L11_5813.attenuation_bulbsize = L12_5814
  L12_5814 = {}
  L13_5815 = L5_5807.clrDiffuse
  L13_5815 = L13_5815.x
  L13_5815 = L13_5815 * L9_5811
  L12_5814.x = L13_5815
  L13_5815 = L5_5807.clrDiffuse
  L13_5815 = L13_5815.y
  L13_5815 = L13_5815 * L9_5811
  L12_5814.y = L13_5815
  L13_5815 = L5_5807.clrDiffuse
  L13_5815 = L13_5815.z
  L13_5815 = L13_5815 * L9_5811
  L12_5814.z = L13_5815
  L11_5813.diffuse_color = L12_5814
  L11_5813.specular_multiplier = L10_5812
  L12_5814 = L6_5808.bAffectsThisAreaOnly
  L11_5813.this_area_only = L12_5814
  L12_5814 = L6_5808.bIgnoresVisAreas
  L11_5813.ignore_visareas = L12_5814
  L12_5814 = L6_5808.bFakeLight
  L11_5813.fake = L12_5814
  L12_5814 = L6_5808.bAmbient
  L11_5813.ambient = L12_5814
  L12_5814 = L8_5810.nCastShadows
  L11_5813.cast_shadow = L12_5814
  L12_5814 = L8_5810.nCastShadowViewDistRatio
  L11_5813.cast_shadow_viewDistRatio = L12_5814
  L12_5814 = L8_5810.fShadowBias
  L11_5813.shadow_bias = L12_5814
  L12_5814 = L8_5810.fShadowSlopeBias
  L11_5813.shadow_slope_bias = L12_5814
  L12_5814 = L8_5810.fShadowResolutionScale
  L11_5813.shadowResolutionScale = L12_5814
  L12_5814 = L8_5810.nShadowMinResPercent
  L11_5813.shadowMinResolution = L12_5814
  L12_5814 = L8_5810.fShadowUpdateMinRadius
  L11_5813.shadowUpdate_MinRadius = L12_5814
  L12_5814 = L8_5810.fShadowUpdateRatio
  L11_5813.shadowUpdate_ratio = L12_5814
  L12_5814 = L4_5806.texture_Texture
  L11_5813.projector_texture = L12_5814
  L12_5814 = L4_5806.fProjectorFov
  L11_5813.proj_fov = L12_5814
  L12_5814 = L4_5806.fProjectorNearPlane
  L11_5813.proj_nearplane = L12_5814
  L12_5814 = L7_5809.bAreaLight
  L11_5813.area_light = L12_5814
  L12_5814 = L7_5809.fPlaneWidth
  L11_5813.area_width = L12_5814
  L12_5814 = L7_5809.fPlaneHeight
  L11_5813.area_height = L12_5814
  L12_5814 = L3_5805.nLightStyle
  L11_5813.style = L12_5814
  L12_5814 = L3_5805.fAnimationSpeed
  L11_5813.anim_speed = L12_5814
  L12_5814 = L3_5805.nAnimationPhase
  L11_5813.anim_phase = L12_5814
  L11_5813.lightmap_linear_attenuation = 1
  L11_5813.is_rectangle_light = 0
  L11_5813.is_sphere_light = 0
  L11_5813.area_sample_number = 1
  L11_5813.indoor_only = 0
  L12_5814 = {}
  L12_5814.x = 0
  L12_5814.y = 0
  L12_5814.z = 0
  L11_5813.RAE_AmbientColor = L12_5814
  L11_5813.RAE_MaxShadow = 1
  L11_5813.RAE_DistMul = 1
  L11_5813.RAE_DivShadow = 1
  L11_5813.RAE_ShadowHeight = 1
  L11_5813.RAE_FallOff = 2
  L11_5813.RAE_VisareaNumber = 0
  L13_5815 = A0_5802
  L12_5814 = A0_5802.LoadLight
  L14_5816 = -1
  L12_5814 = L12_5814(L13_5815, L14_5816, L11_5813)
  A0_5802.lightSlot = L12_5814
  L12_5814 = g_Vectors
  L12_5814 = L12_5814.temp_v1
  L12_5814.x = 0
  L13_5815 = math
  L13_5815 = L13_5815.sqrt
  L14_5816 = L2_5804.Options
  L14_5816 = L14_5816.vDirection
  L14_5816 = L14_5816.x
  L14_5816 = L14_5816 * L2_5804.Options.vDirection.x
  L14_5816 = L14_5816 + L2_5804.Options.vDirection.y * L2_5804.Options.vDirection.y
  L13_5815 = L13_5815(L14_5816)
  L14_5816 = math
  L14_5816 = L14_5816.atan2
  L14_5816 = L14_5816(-L2_5804.Options.vDirection.z, L13_5815)
  L12_5814.y = L14_5816
  L14_5816 = math
  L14_5816 = L14_5816.atan2
  L14_5816 = L14_5816(L2_5804.Options.vDirection.y, L2_5804.Options.vDirection.x)
  L12_5814.z = L14_5816
  L14_5816 = A0_5802.SetSlotAngles
  L14_5816(A0_5802, A0_5802.lightSlot, L12_5814)
  L14_5816 = g_Vectors
  L14_5816 = L14_5816.temp_v1
  L14_5816.x = L2_5804.Options.vOffset.x
  L14_5816.y = L2_5804.Options.vOffset.y
  L14_5816.z = L2_5804.Options.vOffset.z
  A0_5802:SetSlotPos(A0_5802.lightSlot, L14_5816)
  if L8_5810.nCastShadows ~= 0 and L8_5810.bIgnoreGeomCaster ~= 0 then
    A0_5802:SetSelfAsLightCasterException(A0_5802.lightSlot)
  end
end
function DestroyableLight.SwitchOnOffChildren(A0_5817, A1_5818)
  local L2_5819, L3_5820, L4_5821, L5_5822, L6_5823
  L2_5819 = A0_5817.GetChildCount
  L2_5819 = L2_5819(L3_5820)
  for L6_5823 = 0, L2_5819 do
    if A0_5817:GetChild(L6_5823) and A0_5817:GetChild(L6_5823).NotifySwitchOnOffFromParent then
      A0_5817:GetChild(L6_5823):NotifySwitchOnOffFromParent(A1_5818)
    end
  end
end
function DestroyableLight.NotifySwitchOnOffFromParent(A0_5824, A1_5825)
  A0_5824:SwitchOnOff(A1_5825)
end
function DestroyableLight.SwitchOnOff(A0_5826, A1_5827)
  local L2_5828
  L2_5828 = A0_5826.dead
  if not L2_5828 then
    L2_5828 = A1_5827 ~= true
    if A0_5826.lightOn and L2_5828 then
      A0_5826.lightOn = false
      BroadcastEvent(A0_5826, "LightOff")
      A0_5826:ShowCorrectLight()
      A0_5826:SwitchOnOffChildren(A1_5827)
    elseif A0_5826.lightOn ~= true and A1_5827 then
      A0_5826.lightOn = true
      BroadcastEvent(A0_5826, "LightOn")
      A0_5826:ShowCorrectLight()
      A0_5826:SwitchOnOffChildren(A1_5827)
    end
  end
end
DestroyableLight.Client.Alive = {
  OnBeginState = function(A0_5829)
    A0_5829:ShowCorrectLight()
  end,
  OnLevelLoaded = function(A0_5830)
    if A0_5830.PropertiesInstance.LightProperties_Base.Options.bAffectsThisAreaOnly then
      A0_5830:UpdateLightClipBounds(A0_5830.lightSlot)
    end
  end
}
DestroyableLight.Server.Alive = {
  OnTimer = function(A0_5831, A1_5832, A2_5833)
    if A1_5832 == 0 then
      A0_5831:GotoState("Dead")
    end
  end,
  OnLevelLoaded = function(A0_5834)
    if A0_5834.PropertiesInstance.LightProperties_Base.Options.bAffectsThisAreaOnly then
      A0_5834:UpdateLightClipBounds(A0_5834.lightSlot)
    end
  end
}
DestroyableLight.Client.Dead = {
  OnBeginState = function(A0_5835)
    A0_5835:SwitchOnOff(false)
    A0_5835:ShowCorrectLight()
    if not CryAction.IsServer() then
      A0_5835:RemoveEffect()
      A0_5835:Explode()
      A0_5835.dead = true
    end
  end
}
DestroyableLight.Server.Dead = {
  OnBeginState = function(A0_5836)
    A0_5836:RemoveEffect()
    A0_5836:Explode()
    A0_5836.dead = true
  end
}
function DestroyableLight.Event_Reset(A0_5837, A1_5838)
  A0_5837:OnReset()
  BroadcastEvent(A0_5837, "Reset")
end
function DestroyableLight.Event_Hit(A0_5839, A1_5840)
  BroadcastEvent(A0_5839, "Hit")
end
function DestroyableLight.Event_Explode(A0_5841, A1_5842)
  if A0_5841:GetState() == "Dead" then
    return
  end
  if A0_5841.exploded then
    return
  end
  BroadcastEvent(A0_5841, "Explode")
  BroadcastEvent(A0_5841, "Break")
  A0_5841:Die(NULL_ENTITY)
end
function DestroyableLight.Client.OnPhysicsBreak(A0_5843, A1_5844, A2_5845, A3_5846)
  A0_5843:ActivateOutput("Break", A2_5845 + 1)
end
function DestroyableLight.Event_Hide(A0_5847)
  A0_5847:Hide(1)
  BroadcastEvent(A0_5847, "Hide")
end
function DestroyableLight.Event_UnHide(A0_5848)
  A0_5848:Hide(0)
  BroadcastEvent(A0_5848, "UnHide")
end
function DestroyableLight.Event_LightOn(A0_5849)
  A0_5849:SwitchOnOff(true)
end
function DestroyableLight.Event_LightOff(A0_5850)
  A0_5850:SwitchOnOff(false)
end
function DestroyableLight.ShowLightOn(A0_5851)
  if A0_5851.lightSlot ~= -1 then
    A0_5851:FreeSlot(A0_5851.lightSlot)
    A0_5851.lightSlot = -1
  end
  if A0_5851.PropertiesInstance.LightProperties_Base.bUseThisLight ~= 0 then
    A0_5851:UseLight(1)
  end
  if A0_5851:GetMaterialFloat(1, A0_5851.PropertiesInstance.LightProperties_Base.Options.nGlowSubmatId, MaterialFloatParams.emissive_intensity) ~= A0_5851.origGlowValue and A0_5851.origGlowValue and A0_5851.materialIsCloned then
    A0_5851:SetMaterialFloat(1, A0_5851.PropertiesInstance.LightProperties_Base.Options.nGlowSubmatId, MaterialFloatParams.emissive_intensity, A0_5851.origGlowValue)
  end
end
function DestroyableLight.ShowLightOff(A0_5852)
  if A0_5852.lightSlot ~= -1 then
    A0_5852:FreeSlot(A0_5852.lightSlot)
    A0_5852.lightSlot = -1
  end
  if A0_5852.PropertiesInstance.LightProperties_Destroyed.bUseThisLight ~= 0 then
    A0_5852:UseLight(0)
  end
  if 0 < A0_5852:GetMaterialFloat(1, A0_5852.PropertiesInstance.LightProperties_Base.Options.nGlowSubmatId, MaterialFloatParams.emissive_intensity) then
    if not A0_5852.materialIsCloned then
      A0_5852:CloneMaterial(1)
      A0_5852.materialIsCloned = true
    end
    A0_5852:SetMaterialFloat(1, A0_5852.PropertiesInstance.LightProperties_Base.Options.nGlowSubmatId, MaterialFloatParams.emissive_intensity, 1.0E-4)
  end
end
function DestroyableLight.PlaySound(A0_5853, A1_5854)
  local L2_5855
  if A1_5854 and A1_5854 ~= "" then
    L2_5855 = SOUND_DEFAULT_3D
  end
end
function DestroyableLight.PlaySoundLoop(A0_5856, A1_5857)
  local L2_5858
  if A1_5857 and A1_5857 ~= "" then
    L2_5858 = SOUND_DEFAULT_3D
    L2_5858 = bor(L2_5858, FLAG_SOUND_LOOP)
    return 0
  end
end
function DestroyableLight.PlayIdleSound(A0_5859)
  if A0_5859.idleSoundId == 0 then
    A0_5859.idleSoundId = A0_5859:PlaySoundLoop(A0_5859.Properties.Sound.soundIdle)
  end
end
function DestroyableLight.PlayRunSound(A0_5860)
  if A0_5860.runSoundId == 0 then
    A0_5860.runSoundId = A0_5860:PlaySoundLoop(A0_5860.Properties.Sound.soundRun)
  end
end
function DestroyableLight.StopIdleSound(A0_5861)
  if A0_5861.idleSoundId ~= 0 then
    A0_5861.idleSoundId = 0
  end
end
function DestroyableLight.StopRunSound(A0_5862)
  if A0_5862.runSoundId ~= 0 then
    A0_5862.runSoundId = 0
  end
end
function DestroyableLight.OnEditorSetGameMode(A0_5863, A1_5864)
  if A1_5864 ~= true then
    A0_5863:StopIdleSound()
    A0_5863:StopRunSound()
  end
end
function DestroyableLight.ShowCorrectLight(A0_5865)
  if A0_5865.lightOn and not A0_5865.dead then
    A0_5865:StopIdleSound()
    A0_5865:PlayRunSound()
    A0_5865:ShowLightOn()
  else
    A0_5865:ShowLightOff()
    A0_5865:StopRunSound()
    if A0_5865.dead then
      A0_5865:StopIdleSound()
    else
      A0_5865:PlayIdleSound()
    end
  end
end
DestroyableLight.FlowEvents = {
  Inputs = {
    Explode = {
      DestroyableLight.Event_Explode,
      "bool"
    },
    Reset = {
      DestroyableLight.Event_Reset,
      "bool"
    },
    Used = {
      DestroyableLight.Event_Used,
      "bool"
    },
    EnableUsable = {
      DestroyableLight.Event_EnableUsable,
      "bool"
    },
    DisableUsable = {
      DestroyableLight.Event_DisableUsable,
      "bool"
    },
    Hit = {
      DestroyableLight.Event_Hit,
      "bool"
    },
    Hide = {
      DestroyableLight.Event_Hide,
      "bool"
    },
    UnHide = {
      DestroyableLight.Event_UnHide,
      "bool"
    },
    LightOn = {
      DestroyableLight.Event_LightOn,
      "bool"
    },
    LightOff = {
      DestroyableLight.Event_LightOff,
      "bool"
    }
  },
  Outputs = {
    Explode = "bool",
    Reset = "bool",
    Used = "bool",
    EnableUsable = "bool",
    DisableUsable = "bool",
    Hit = "bool",
    Hide = "bool",
    UnHide = "bool",
    Break = "int",
    LightOn = "bool",
    LightOff = "bool"
  }
}
MakeUsable(DestroyableLight)
function DestroyableLight.IsUsable(A0_5866, A1_5867)
  local L3_5868
  if not A0_5866.bUsable then
    A0_5866.bUsable = A0_5866.Properties.bUsable
  end
  if A0_5866.bUsable == 1 then
    L3_5868 = 2
  end
  return L3_5868 or 0
end
function DestroyableLight.OnUsed(A0_5869, A1_5870, A2_5871)
  local L3_5872
  L3_5872 = BroadcastEvent
  L3_5872(A0_5869, "Used")
  L3_5872 = A0_5869.dead
  if not L3_5872 then
    L3_5872 = A0_5869.lightOn
    L3_5872 = L3_5872 == false
    A0_5869:SwitchOnOff(L3_5872)
  end
end
MakePickable(DestroyableLight)
MakeTargetableByAI(DestroyableLight)
MakeKillable(DestroyableLight)
function DestroyableLight.Event_Dead(A0_5873)
  A0_5873:Die()
  A0_5873:TriggerEvent(AIEVENT_DISABLE)
  BroadcastEvent(A0_5873, "Dead")
end
