local L0_7595
L0_7595 = {}
L0_7595.Client = {}
L0_7595.Server = {}
L0_7595.States = {"Alive", "Dead"}
L0_7595.Properties = {
  soclasses_SmartObjectClass = "",
  bAutoGenAIHidePts = 0,
  object_Model = "engine/engineassets/objects/default.cgf",
  ModelSubObject = "",
  object_ModelDestroyed = "engine/engineassets/objects/default.cgf",
  DestroyedSubObject = "",
  DmgFactorWhenCollidingAI = 1,
  bPlayerOnly = 1,
  bOnlyAllowPlayerToFullyDestroyObject = 0,
  fDamageTreshold = 0,
  bExplode = 1,
  Vulnerability = {
    bExplosion = 1,
    bCollision = 1,
    bMelee = 1,
    bBullet = 1,
    bOther = 1,
    projectileClass = ""
  },
  DamageMultipliers = {
    fCollision = 1,
    fBullet = 1,
    fProjectileClass = 1
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
    SoundRadius = 0,
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
  Sounds = {
    sound_Alive = "",
    sound_Dead = "",
    sound_Dying = "",
    fAISoundRadius = 30,
    bStopSoundsOnDestroyed = 1
  },
  Physics = {
    bRigidBody = 1,
    bRigidBodyActive = 1,
    bRigidBodyAfterDeath = 1,
    bActivateOnDamage = 0,
    Density = -1,
    Mass = 100,
    bPushableByPlayers = 0,
    bPushableByAI = 0,
    bCanBreakOthers = 0,
    Simulation = {
      max_time_step = 0.02,
      sleep_speed = 0.04,
      damping = 0
    },
    MP = {bDontSyncPos = 0}
  },
  TacticalInfo = {bScannable = 0, LookupName = ""}
}
L0_7595.Editor = {
  Icon = "explosion.bmp",
  IsScalable = false
}
DestroyableObject = L0_7595
L0_7595 = {}
L0_7595.bRigidBody = 0
L0_7595.bRigidBodyActive = 1
L0_7595.bRigidBodyAfterDeath = 0
L0_7595.bActivateOnDamage = 0
L0_7595.Density = -1
L0_7595.Mass = -1
Net.Expose({
  Class = DestroyableObject,
  ClientMethods = {
    ClActivateDelayEffect = {RELIABLE_ORDERED, POST_ATTACH},
    ClExplode = {RELIABLE_ORDERED, POST_ATTACH},
    ClUsedBy = {
      RELIABLE_ORDERED,
      NO_ATTACH,
      ENTITYID
    }
  },
  ServerMethods = {
    SvRequestUsedBy = {
      RELIABLE_UNORDERED,
      NO_ATTACH,
      ENTITYID
    }
  },
  ServerProperties = {}
})
function DestroyableObject.OnLoad(A0_7596, A1_7597)
  A0_7596.bTemporaryUsable = A1_7597.bTemporaryUsable
  A0_7596.shooterId = A1_7597.shooterId
  A0_7596.health = A1_7597.health
  A0_7596.exploded = A1_7597.exploded
  A0_7596.rigidBodySlot = A1_7597.rigidBodySlot
  A0_7596.isRigidBody = A1_7597.isRigidBody
  A0_7596.currentSlot = A1_7597.currentSlot
  A0_7596.LastHit = A1_7597.LastHit
  if (A1_7597.FXSlot or 0) <= 0 then
    if 0 < (A0_7596.FXSlot or 0) then
      A0_7596:DeleteParticleEmitter(A0_7596.FXSlot)
      A0_7596:RemoveEffect()
    end
  end
  A0_7596.FXSlot = A1_7597.FXSlot
  A0_7596.dead = A1_7597.dead
  A0_7596:SetCurrentSlot(A0_7596.currentSlot)
  if A0_7596.dead then
    if A0_7596.Properties.Physics.bRigidBodyAfterDeath == 1 then
      A0_7596.Properties.Physics.bRigidBody = 1
      A0_7596:PhysicalizeThis(A0_7596.currentSlot)
      A0_7596.Properties.Physics.bRigidBody = A0_7596.Properties.Physics.bRigidBody
    end
  else
    A0_7596:PhysicalizeThis(A0_7596.currentSlot)
  end
  if A0_7596:GetState() ~= A1_7597.state then
    A0_7596:GotoState(A1_7597.state)
  end
end
function DestroyableObject.OnSave(A0_7598, A1_7599)
  A1_7599.bTemporaryUsable = A0_7598.bTemporaryUsable
  A1_7599.shooterId = A0_7598.shooterId
  A1_7599.health = A0_7598.health
  A1_7599.FXSlot = A0_7598.FXSlot
  A1_7599.dead = A0_7598.dead
  A1_7599.exploded = A0_7598.exploded
  A1_7599.rigidBodySlot = A0_7598.rigidBodySlot
  A1_7599.isRigidBody = A0_7598.isRigidBody
  A1_7599.currentSlot = A0_7598.currentSlot
  A1_7599.LastHit = A0_7598.LastHit
  A1_7599.state = A0_7598:GetState()
end
function DestroyableObject.CommonInit(A0_7600)
  A0_7600.bReloadGeoms = 1
  A0_7600.bTemporaryUsable = 0
  if not A0_7600.bInitialized then
    A0_7600.LastHit = {
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
    A0_7600:Reload()
    A0_7600.bInitialized = 1
    A0_7600:GotoState("Alive")
  end
  g_gameRules.game:MakeMovementVisibleToAI("DestroyableObject")
end
function DestroyableObject.Server.OnInit(A0_7601)
  A0_7601:CommonInit()
end
function DestroyableObject.Client.OnInit(A0_7602)
  A0_7602:CommonInit()
  A0_7602:CacheResources()
end
function DestroyableObject.CacheResources(A0_7603)
  A0_7603:PreLoadParticleEffect(A0_7603.Properties.Explosion.ParticleEffect)
  A0_7603:PreLoadParticleEffect(A0_7603.Properties.Explosion.DelayEffect.ParticleEffect)
end
function DestroyableObject.OnPropertyChange(A0_7604)
  A0_7604.bReloadGeoms = 1
  A0_7604:Reload()
end
function DestroyableObject.OnShutDown(A0_7605)
  local L1_7606
end
function DestroyableObject.OnReset(A0_7607)
  A0_7607:RemoveEffect()
  if A0_7607.timerShooterId then
  end
  A0_7607:ResetTacticalInfo()
  if A0_7607:GetState() ~= "Alive" then
    A0_7607:Reload()
  end
  A0_7607:AwakePhysics(0)
end
function DestroyableObject.RemoveEffect(A0_7608)
  if A0_7608.FXSlot then
    A0_7608:FreeSlot(A0_7608.FXSlot)
    A0_7608.FXSlot = -1
  end
end
function DestroyableObject.ResetTacticalInfo(A0_7609)
  A0_7609.bScannable = A0_7609.Properties.TacticalInfo.bScannable
  if A0_7609.bScannable == 1 then
    Game.AddTacticalEntity(A0_7609.id, eTacticalEntity_Hazard)
  else
    Game.RemoveTacticalEntity(A0_7609.id, eTacticalEntity_Hazard)
  end
end
function DestroyableObject.Reload(A0_7610)
  A0_7610:ResetTacticalInfo()
  A0_7610:ResetOnUsed()
  A0_7610.bTemporaryUsable = A0_7610.Properties.bUsable
  A0_7610.shooterId = NULL_ENTITY
  A0_7610.health = A0_7610.Properties.Health.MaxHealth
  A0_7610.dead = nil
  A0_7610.exploded = nil
  A0_7610.rigidBodySlot = nil
  A0_7610.isRigidBody = nil
  if A0_7610.bReloadGeoms == 1 then
    if not EmptyString(A0_7610.Properties.object_Model) then
      A0_7610:LoadObject(3, A0_7610.Properties.object_Model)
      A0_7610:DrawSlot(3, 0)
      A0_7610:LoadSubObject(0, A0_7610.Properties.object_Model, A0_7610.Properties.ModelSubObject)
    end
    if not EmptyString(A0_7610.Properties.object_ModelDestroyed) then
      A0_7610:LoadSubObject(1, A0_7610.Properties.object_ModelDestroyed, A0_7610.Properties.DestroyedSubObject)
    elseif not EmptyString(A0_7610.Properties.DestroyedSubObject) then
      A0_7610:LoadSubObject(1, A0_7610.Properties.object_Model, A0_7610.Properties.DestroyedSubObject)
    end
    A0_7610:SetCurrentSlot(0)
    A0_7610:PhysicalizeThis(0)
  end
  A0_7610.bReloadGeoms = 0
  A0_7610:GotoState("Alive")
  if A0_7610.Properties.bAutoGenAIHidePts == 1 then
    A0_7610:SetFlags(ENTITY_FLAG_AI_HIDEABLE, 0)
  else
    A0_7610:SetFlags(ENTITY_FLAG_AI_HIDEABLE, 2)
  end
  A0_7610.radius = 0.15 + math.max(A0_7610:GetWorldBBox(g_Vectors.temp_v1, g_Vectors.temp_v2).x - A0_7610:GetWorldBBox(g_Vectors.temp_v1, g_Vectors.temp_v2).x, math.max(A0_7610:GetWorldBBox(g_Vectors.temp_v1, g_Vectors.temp_v2).y - A0_7610:GetWorldBBox(g_Vectors.temp_v1, g_Vectors.temp_v2).y, A0_7610:GetWorldBBox(g_Vectors.temp_v1, g_Vectors.temp_v2).z - A0_7610:GetWorldBBox(g_Vectors.temp_v1, g_Vectors.temp_v2).z))
  A0_7610.center = {
    x = (A0_7610:GetWorldBBox(g_Vectors.temp_v1, g_Vectors.temp_v2).x + A0_7610:GetWorldBBox(g_Vectors.temp_v1, g_Vectors.temp_v2).x) * 0.5,
    y = (A0_7610:GetWorldBBox(g_Vectors.temp_v1, g_Vectors.temp_v2).y + A0_7610:GetWorldBBox(g_Vectors.temp_v1, g_Vectors.temp_v2).y) * 0.5,
    z = (A0_7610:GetWorldBBox(g_Vectors.temp_v1, g_Vectors.temp_v2).z + A0_7610:GetWorldBBox(g_Vectors.temp_v1, g_Vectors.temp_v2).z) * 0.5
  }
end
function DestroyableObject.PhysicalizeThis(A0_7611, A1_7612)
  local L2_7613
  L2_7613 = A0_7611.Properties
  L2_7613 = L2_7613.Physics
  L2_7613 = L2_7613.MP
  L2_7613 = L2_7613.bDontSyncPos
  if L2_7613 == 1 then
    L2_7613 = CryAction
    L2_7613 = L2_7613.DontSyncPhysics
    L2_7613(A0_7611.id)
  end
  L2_7613 = A0_7611.Properties
  L2_7613 = L2_7613.Physics
  if CryAction.IsImmersivenessEnabled() == 0 then
    L2_7613 = _UPVALUE0_
  end
  EntityCommon.PhysicalizeRigid(A0_7611, A1_7612, L2_7613, A0_7611.bRigidBodyActive)
end
function DestroyableObject.SetCurrentSlot(A0_7614, A1_7615)
  if A1_7615 == 0 then
    A0_7614:DrawSlot(0, 1)
    A0_7614:DrawSlot(1, 0)
  else
    A0_7614:DrawSlot(0, 0)
    A0_7614:DrawSlot(1, 1)
  end
  A0_7614.currentSlot = A1_7615
end
function DestroyableObject.Explode(A0_7616)
  local L1_7617, L2_7618, L3_7619, L4_7620, L5_7621, L6_7622, L7_7623, L8_7624, L9_7625, L10_7626, L11_7627, L12_7628, L13_7629
  L1_7617 = CryAction
  L1_7617 = L1_7617.IsImmersivenessEnabled
  L1_7617 = L1_7617()
  if L1_7617 == 0 then
    return
  end
  L1_7617 = CryAction
  L1_7617 = L1_7617.IsClient
  L1_7617 = L1_7617()
  if not L1_7617 then
    L1_7617 = A0_7616.allClients
    L2_7618 = L1_7617
    L1_7617 = L1_7617.ClExplode
    L1_7617(L2_7618)
  end
  L1_7617 = A0_7616.Properties
  A0_7616.bTemporaryUsable = 0
  A0_7616.bReloadGeoms = 1
  L2_7618 = A0_7616.LastHit
  L2_7618 = L2_7618.pos
  L3_7619 = A0_7616.LastHit
  L3_7619 = L3_7619.impulse
  L4_7620 = CryAction
  L4_7620 = L4_7620.IsClient
  L4_7620 = L4_7620()
  if L4_7620 then
    L5_7621 = A0_7616
    L4_7620 = A0_7616.BreakToPieces
    L6_7622 = 0
    L7_7623 = 0
    L8_7624 = L1_7617.Breakage
    L8_7624 = L8_7624.fExplodeImpulse
    L9_7625 = L2_7618
    L10_7626 = L3_7619
    L11_7627 = L1_7617.Breakage
    L11_7627 = L11_7627.fLifeTime
    L12_7628 = L1_7617.Breakage
    L12_7628 = L12_7628.bSurfaceEffects
    L4_7620(L5_7621, L6_7622, L7_7623, L8_7624, L9_7625, L10_7626, L11_7627, L12_7628)
  end
  L4_7620 = AI
  L4_7620 = L4_7620.BreakEvent
  L5_7621 = A0_7616.id
  L6_7622 = A0_7616.center
  L7_7623 = A0_7616.radius
  L4_7620(L5_7621, L6_7622, L7_7623)
  L5_7621 = A0_7616
  L4_7620 = A0_7616.RemoveDecals
  L4_7620(L5_7621)
  L4_7620 = false
  L6_7622 = A0_7616
  L5_7621 = A0_7616.SetCurrentSlot
  L7_7623 = 1
  L5_7621(L6_7622, L7_7623)
  L5_7621 = L1_7617.object_ModelDestroyed
  if L5_7621 == "" then
    L5_7621 = L1_7617.DestroyedSubObject
  else
    if L5_7621 ~= "" then
      L5_7621 = L1_7617.Physics
      L5_7621 = L5_7621.bRigidBodyAfterDeath
      if L5_7621 == 1 then
        L5_7621 = L1_7617.Physics
        L5_7621 = L5_7621.bRigidBody
        L6_7622 = L1_7617.Physics
        L6_7622.bRigidBody = 1
        L7_7623 = A0_7616
        L6_7622 = A0_7616.PhysicalizeThis
        L8_7624 = 1
        L6_7622(L7_7623, L8_7624)
        L6_7622 = L1_7617.Physics
        L6_7622.bRigidBody = L5_7621
        L7_7623 = A0_7616
        L6_7622 = A0_7616.AwakePhysics
        L8_7624 = 1
        L6_7622(L7_7623, L8_7624)
      else
        L6_7622 = A0_7616
        L5_7621 = A0_7616.PhysicalizeThis
        L7_7623 = 1
        L5_7621(L6_7622, L7_7623)
        L6_7622 = A0_7616
        L5_7621 = A0_7616.AwakePhysics
        L7_7623 = 1
        L5_7621(L6_7622, L7_7623)
      end
  end
  else
    L4_7620 = true
  end
  L5_7621 = CryAction
  L5_7621 = L5_7621.IsServer
  L5_7621 = L5_7621()
  if L5_7621 then
    L5_7621 = NumberToBool
    L6_7622 = A0_7616.Properties
    L6_7622 = L6_7622.bExplode
    L5_7621 = L5_7621(L6_7622)
    if L5_7621 then
      L5_7621 = A0_7616.Properties
      L5_7621 = L5_7621.Explosion
      L7_7623 = A0_7616
      L6_7622 = A0_7616.GetWorldPos
      L8_7624 = g_Vectors
      L8_7624 = L8_7624.temp_v1
      L6_7622 = L6_7622(L7_7623, L8_7624)
      L8_7624 = A0_7616
      L7_7623 = A0_7616.GetDirectionVector
      L9_7625 = 0
      L10_7626 = g_Vectors
      L10_7626 = L10_7626.temp_v2
      L7_7623 = L7_7623(L8_7624, L9_7625, L10_7626)
      L9_7625 = A0_7616
      L8_7624 = A0_7616.GetDirectionVector
      L10_7626 = 1
      L11_7627 = g_Vectors
      L11_7627 = L11_7627.temp_v3
      L8_7624 = L8_7624(L9_7625, L10_7626, L11_7627)
      L10_7626 = A0_7616
      L9_7625 = A0_7616.GetDirectionVector
      L11_7627 = 2
      L12_7628 = g_Vectors
      L12_7628 = L12_7628.temp_v4
      L9_7625 = L9_7625(L10_7626, L11_7627, L12_7628)
      L10_7626 = g_Vectors
      L10_7626 = L10_7626.temp_v5
      L11_7627 = CopyVector
      L12_7628 = L10_7626
      L13_7629 = L5_7621.vOffset
      L11_7627(L12_7628, L13_7629)
      L11_7627 = g_Vectors
      L11_7627 = L11_7627.temp_v6
      L12_7628 = CopyVector
      L13_7629 = L11_7627
      L12_7628(L13_7629, L5_7621.Direction)
      L12_7628 = L6_7622.x
      L13_7629 = L7_7623.x
      L13_7629 = L13_7629 * L10_7626.x
      L12_7628 = L12_7628 + L13_7629
      L13_7629 = L8_7624.x
      L13_7629 = L13_7629 * L10_7626.y
      L12_7628 = L12_7628 + L13_7629
      L13_7629 = L9_7625.x
      L13_7629 = L13_7629 * L10_7626.z
      L12_7628 = L12_7628 + L13_7629
      L6_7622.x = L12_7628
      L12_7628 = L6_7622.y
      L13_7629 = L7_7623.y
      L13_7629 = L13_7629 * L10_7626.x
      L12_7628 = L12_7628 + L13_7629
      L13_7629 = L8_7624.y
      L13_7629 = L13_7629 * L10_7626.y
      L12_7628 = L12_7628 + L13_7629
      L13_7629 = L9_7625.y
      L13_7629 = L13_7629 * L10_7626.z
      L12_7628 = L12_7628 + L13_7629
      L6_7622.y = L12_7628
      L12_7628 = L6_7622.z
      L13_7629 = L7_7623.z
      L13_7629 = L13_7629 * L10_7626.x
      L12_7628 = L12_7628 + L13_7629
      L13_7629 = L8_7624.z
      L13_7629 = L13_7629 * L10_7626.y
      L12_7628 = L12_7628 + L13_7629
      L13_7629 = L9_7625.z
      L13_7629 = L13_7629 * L10_7626.z
      L12_7628 = L12_7628 + L13_7629
      L6_7622.z = L12_7628
      L12_7628 = L6_7622
      L13_7629 = g_gameRules
      L13_7629 = L13_7629.game
      L13_7629 = L13_7629.GetHitTypeId
      L13_7629 = L13_7629(L13_7629, "explosion")
      g_gameRules:CreateExplosion(A0_7616.shooterId, A0_7616.id, L5_7621.Damage, L12_7628, L11_7627, L5_7621.Radius, nil, L5_7621.Pressure, L5_7621.HoleSize, L5_7621.ParticleEffect, L5_7621.EffectScale, L5_7621.MinRadius, L5_7621.MinPhysRadius, L5_7621.PhysRadius, L13_7629, L5_7621.SoundRadius)
    end
  end
  L5_7621 = A0_7616.dead
  if L5_7621 ~= true then
  end
  A0_7616.exploded = true
  L5_7621 = BroadcastEvent
  L6_7622 = A0_7616
  L7_7623 = "Explode"
  L5_7621(L6_7622, L7_7623)
  if L4_7620 == true then
    L6_7622 = A0_7616
    L5_7621 = A0_7616.Hide
    L7_7623 = 1
    L5_7621(L6_7622, L7_7623)
  end
end
function DestroyableObject.ActivateDelayEffect(A0_7630)
  local L1_7631
  L1_7631 = A0_7630.Properties
  L1_7631 = L1_7631.Explosion
  if L1_7631.DelayEffect.bHasDelayEffect == 1 and (not A0_7630.FXSlot or A0_7630.FXSlot == -1) and not EmptyString(L1_7631.DelayEffect.ParticleEffect) then
    A0_7630.FXSlot = A0_7630:LoadParticleEffect(-1, L1_7631.DelayEffect.ParticleEffect, L1_7631.DelayEffect.Params)
    if A0_7630.FXSlot then
      A0_7630:SetSlotPos(A0_7630.FXSlot, L1_7631.DelayEffect.vOffset)
      A0_7630:SetSlotAngles(A0_7630.FXSlot, L1_7631.DelayEffect.vRotation)
    end
  end
end
function DestroyableObject.Die(A0_7632, A1_7633)
  local L2_7634
  if A1_7633 then
    L2_7634 = A1_7633.shooterId
    A0_7632.shooterId = L2_7634
  else
    L2_7634 = NULL_ENTITY
    A0_7632.shooterId = L2_7634
  end
  A0_7632.dead = true
  L2_7634 = A0_7632.health
  if L2_7634 > 0 then
    A0_7632.health = 0
  end
  L2_7634 = A0_7632.exploded
  if not L2_7634 then
    L2_7634 = A0_7632.Properties
    L2_7634 = L2_7634.Explosion
    if 0 < L2_7634.Delay and not L2_7634.DelayEffect.bHasDelayEffect == 1 then
      A0_7632:SetTimer(0, L2_7634.Delay * 1000)
    else
      A0_7632:GotoState("Dead")
      if A1_7633 and A1_7633.dir then
        A0_7632:AddImpulse(A1_7633.partId or -1, A1_7633.pos, A1_7633.dir, A1_7633.damage)
      end
    end
  end
end
function DestroyableObject.Server.OnHit(A0_7635, A1_7636)
  local L2_7637, L3_7638, L4_7639, L5_7640
  L2_7637 = CopyVector
  L3_7638 = A0_7635.LastHit
  L3_7638 = L3_7638.pos
  L4_7639 = A1_7636.pos
  L2_7637(L3_7638, L4_7639)
  L2_7637 = CopyVector
  L3_7638 = A0_7635.LastHit
  L3_7638 = L3_7638.impulse
  L4_7639 = A1_7636.dir
  if not L4_7639 then
    L4_7639 = g_Vectors
    L4_7639 = L4_7639.v000
  end
  L2_7637(L3_7638, L4_7639)
  L2_7637 = A0_7635.LastHit
  L2_7637 = L2_7637.impulse
  L3_7638 = A0_7635.LastHit
  L3_7638 = L3_7638.impulse
  L3_7638 = L3_7638.x
  L4_7639 = A1_7636.damage
  L3_7638 = L3_7638 * L4_7639
  L2_7637.x = L3_7638
  L2_7637 = A0_7635.LastHit
  L2_7637 = L2_7637.impulse
  L3_7638 = A0_7635.LastHit
  L3_7638 = L3_7638.impulse
  L3_7638 = L3_7638.y
  L4_7639 = A1_7636.damage
  L3_7638 = L3_7638 * L4_7639
  L2_7637.y = L3_7638
  L2_7637 = A0_7635.LastHit
  L2_7637 = L2_7637.impulse
  L3_7638 = A0_7635.LastHit
  L3_7638 = L3_7638.impulse
  L3_7638 = L3_7638.z
  L4_7639 = A1_7636.damage
  L3_7638 = L3_7638 * L4_7639
  L2_7637.z = L3_7638
  L3_7638 = A0_7635
  L2_7637 = A0_7635.ActivateOutput
  L4_7639 = "HitBy"
  L5_7640 = A1_7636.shooterId
  L2_7637(L3_7638, L4_7639, L5_7640)
  L3_7638 = A0_7635
  L2_7637 = A0_7635.IsInvulnerable
  L2_7637 = L2_7637(L3_7638)
  if L2_7637 then
    L2_7637 = true
    return L2_7637
  end
  L2_7637 = A1_7636.damage
  L3_7638 = A0_7635.Properties
  L3_7638 = L3_7638.Vulnerability
  L4_7639 = A0_7635.Properties
  L4_7639 = L4_7639.DamageMultipliers
  L5_7640 = A1_7636.shooterId
  A0_7635.shooterId = L5_7640
  L5_7640 = true
  if L3_7638.projectileClass ~= "" and L3_7638.projectileClass == A1_7636.projectileClass then
    L5_7640 = true
    L2_7637 = L2_7637 * L4_7639.fProjectileClass
  elseif A1_7636.explosion then
    L5_7640 = NumberToBool(L3_7638.bExplosion)
  elseif A1_7636.type == "collision" then
    L5_7640 = NumberToBool(L3_7638.bCollision)
    L2_7637 = L2_7637 * L4_7639.fCollision
  elseif A1_7636.type == "bullet" then
    L5_7640 = NumberToBool(L3_7638.bBullet)
    L2_7637 = L2_7637 * L4_7639.fBullet
  elseif A1_7636.type == "melee" then
    L5_7640 = NumberToBool(L3_7638.bMelee)
  else
    L5_7640 = NumberToBool(L3_7638.bOther)
  end
  L5_7640 = L5_7640 and L2_7637 > A0_7635.Properties.fDamageTreshold
  if not System.IsMultiplayer() and L5_7640 and NumberToBool(A0_7635.Properties.bPlayerOnly) and A1_7636.shooterId and A1_7636.shooterId ~= g_localActorId then
    L5_7640 = false
  end
  if L5_7640 then
    A0_7635.health = A0_7635.health - L2_7637
    if NumberToBool(A0_7635.Properties.bOnlyAllowPlayerToFullyDestroyObject) and not System.IsMultiplayer() and A1_7636.shooterId ~= g_localActorId and A0_7635.health <= 0 then
      A0_7635.health = 1
    end
    if A0_7635.health <= 0 then
      A0_7635:Die(A1_7636)
    end
    if NumberToBool(A0_7635.Properties.bActivateOnDamage) then
      A0_7635:AwakePhysics(1)
    end
    if A0_7635.Properties.Explosion.DelayEffect.bHasDelayEffect == 1 and (not A0_7635.FXSlot or A0_7635.FXSlot == -1) then
      CopyVector(g_SignalData.point, A0_7635:GetPos())
      AI.FreeSignal(10, "OnExposedToExplosion", A0_7635:GetPos(), A0_7635.Properties.Explosion.Radius, A0_7635.id, g_SignalData)
      A0_7635:SetTimer(0, (A0_7635.Properties.Explosion.Delay + randomF(0, 1.5)) * 1000)
      if CryAction.IsClient() then
        A0_7635:ActivateDelayEffect()
      end
      if CryAction.IsServer() then
        A0_7635.allClients:ClActivateDelayEffect()
      end
    end
  end
  return true
end
function DestroyableObject.CanBeMadeTargetable(A0_7641)
  return A0_7641:GetState() == "Alive"
end
function DestroyableObject.Server.OnTimer(A0_7642, A1_7643, A2_7644)
  if A1_7643 == 0 then
    A0_7642:GotoState("Dead")
  end
end
DestroyableObject.Client.Alive = {
  OnBeginState = function(A0_7645)
    local L1_7646
  end,
  OnPhysicsBreak = function(A0_7647, A1_7648, A2_7649, A3_7650)
    A0_7647:DeactivateTacticalInfo()
  end
}
DestroyableObject.Server.Alive = {
  OnTimer = function(A0_7651, A1_7652, A2_7653)
    if A1_7652 == 0 then
      A0_7651:GotoState("Dead")
    end
  end
}
DestroyableObject.Client.Dead = {
  OnBeginState = function(A0_7654)
    A0_7654:DeactivateTacticalInfo()
    if A0_7654.Properties.Sounds.bStopSoundsOnDestroyed == 1 then
    end
    if not CryAction.IsServer() then
      A0_7654:RemoveEffect()
      A0_7654:Explode()
      A0_7654.dead = true
    end
  end
}
DestroyableObject.Server.Dead = {
  OnBeginState = function(A0_7655)
    A0_7655:RemoveEffect()
    A0_7655:Explode()
    A0_7655.dead = true
  end
}
function DestroyableObject.DeactivateTacticalInfo(A0_7656)
  if A0_7656.bScannable == 1 then
    Game.RemoveTacticalEntity(A0_7656.id, eTacticalEntity_Story)
  end
end
function DestroyableObject.Event_Reset(A0_7657, A1_7658)
  A0_7657:OnReset()
  BroadcastEvent(A0_7657, "Reset")
end
function DestroyableObject.Event_Explode(A0_7659, A1_7660)
  if A0_7659:GetState() == "Dead" then
    return
  end
  if A0_7659.exploded then
    return
  end
  BroadcastEvent(A0_7659, "Explode")
  BroadcastEvent(A0_7659, "Break")
  A0_7659:Die()
end
function DestroyableObject.Base_OnUsed(A0_7661, A1_7662, A2_7663)
  if CryAction.IsServer() then
    A0_7661:ActivateOutput("UsedBy", A1_7662.id)
    A0_7661.allClients:ClUsedBy(A1_7662.id)
  else
    A0_7661.server:SvRequestUsedBy(A1_7662.id)
  end
end
function DestroyableObject.Client.OnPhysicsBreak(A0_7664, A1_7665, A2_7666, A3_7667)
  A0_7664:DeactivateTacticalInfo()
  A0_7664:ActivateOutput("Break", A2_7666 + 1)
end
function DestroyableObject.IsUsable(A0_7668, A1_7669)
  local L3_7670
  if A0_7668.Properties.bUsable == 1 and A0_7668.bTemporaryUsable == 1 then
    L3_7670 = 2
  end
  return L3_7670 or 0
end
function DestroyableObject.GetUsableMessage(A0_7671, A1_7672)
  local L2_7673
  L2_7673 = A0_7671.Properties
  L2_7673 = L2_7673.bUsable
  if L2_7673 == 1 then
    L2_7673 = A0_7671.bTemporaryUsable
    if L2_7673 == 1 then
      L2_7673 = A0_7671.Properties
      L2_7673 = L2_7673.UseMessage
      return L2_7673
    end
  else
    L2_7673 = "@grab_object"
    return L2_7673
  end
end
function DestroyableObject.Event_Hide(A0_7674)
  A0_7674:Hide(1)
  BroadcastEvent(A0_7674, "Hide")
end
function DestroyableObject.Event_UnHide(A0_7675)
  A0_7675:Hide(0)
  BroadcastEvent(A0_7675, "UnHide")
end
DestroyableObject.FlowEvents = {
  Inputs = {
    Explode = {
      DestroyableObject.Event_Explode,
      "bool"
    },
    Reset = {
      DestroyableObject.Event_Reset,
      "bool"
    },
    Used = {
      DestroyableObject.Event_Used,
      "bool"
    },
    EnableUsable = {
      DestroyableObject.Event_EnableUsable,
      "bool"
    },
    DisableUsable = {
      DestroyableObject.Event_DisableUsable,
      "bool"
    },
    Hide = {
      DestroyableObject.Event_Hide,
      "bool"
    },
    UnHide = {
      DestroyableObject.Event_UnHide,
      "bool"
    }
  },
  Outputs = {
    Explode = "bool",
    Reset = "bool",
    Used = "bool",
    EnableUsable = "bool",
    DisableUsable = "bool",
    Hide = "bool",
    UnHide = "bool",
    Break = "int",
    Scanned = "bool",
    HitBy = "entity",
    UsedBy = "entity"
  }
}
function DestroyableObject.HasBeenScanned(A0_7676)
  A0_7676:ActivateOutput("Scanned", true)
end
function DestroyableObject.SavePhysicalState(A0_7677)
  A0_7677.initPos = A0_7677:GetPos()
  A0_7677.initRot = A0_7677:GetWorldAngles()
  A0_7677.initScale = A0_7677:GetScale()
end
function DestroyableObject.RestorePhysicalState(A0_7678)
  if not A0_7678.initPos then
    return
  end
  A0_7678:KillTimer(0)
  if A0_7678:IsHidden() then
    A0_7678:Hide(0)
  end
  A0_7678:RemoveEffect()
  A0_7678.bReloadGeoms = 1
  A0_7678:Reload()
  A0_7678:AwakePhysics(0)
  A0_7678:SetPos(A0_7678.initPos)
  A0_7678:SetWorldAngles(A0_7678.initRot)
  A0_7678:SetScale(A0_7678.initScale)
end
function DestroyableObject.Server.SvRequestUsedBy(A0_7679, A1_7680)
  A0_7679:ActivateOutput("UsedBy", A1_7680)
  A0_7679.allClients:ClUsedBy(A1_7680)
end
function DestroyableObject.Client.ClActivateDelayEffect(A0_7681)
  if not CryAction.IsServer() then
    A0_7681:ActivateDelayEffect()
  end
end
function DestroyableObject.Client.ClExplode(A0_7682)
  if not CryAction.IsServer() then
    A0_7682:Explode()
  end
end
function DestroyableObject.Client.ClUsedBy(A0_7683, A1_7684)
  if not CryAction.IsServer() then
    A0_7683:ActivateOutput("UsedBy", A1_7684)
  end
end
MakeUsable(DestroyableObject)
MakePickable(DestroyableObject)
MakeTargetableByAI(DestroyableObject)
MakeKillable(DestroyableObject)
MakeThrownObjectTargetable(DestroyableObject)
