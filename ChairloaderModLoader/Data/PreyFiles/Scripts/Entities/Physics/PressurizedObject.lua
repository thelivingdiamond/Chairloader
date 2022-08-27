local L0_7827
L0_7827 = -1
PressurizedObject = {
  Properties = {
    bAutoGenAIHidePts = 0,
    objModel = "engine/engineassets/objects/default.cgf",
    Vulnerability = {
      bExplosion = 1,
      bCollision = 1,
      bMelee = 1,
      bBullet = 1,
      bOther = 1
    },
    DamageMultipliers = {fCollision = 1, fBullet = 1},
    fDamageTreshold = 0,
    Leak = {
      Effect = {
        ParticleEffect = "smoke_and_fire.geysir.intense_steam_small",
        PulsePeriod = 0,
        Scale = 1,
        CountScale = 1,
        bCountPerUnit = 0,
        bSizePerUnit = 0,
        AttachType = "none",
        AttachForm = "none",
        bPrime = 1
      },
      Damage = 100,
      DamageRange = 3,
      DamageHitType = "fire",
      Pressure = 100,
      PressureDecay = 10,
      PressureImpulse = 10,
      MaxLeaks = 10,
      ImpulseScale = 1,
      Volume = 10,
      VolumeDecay = 1
    },
    bPlayerOnly = 1,
    fDensity = -1,
    fMass = 25,
    bResting = 1,
    bRigidBody = 1,
    bCanBreakOthers = 0,
    bPushableByPlayers = 0,
    bPushableByAI = 0,
    PhysicsBuoyancy = {
      water_density = 1,
      water_damping = 1.5,
      water_resistance = 0
    },
    PhysicsSimulation = {
      max_time_step = 0.01,
      sleep_speed = 0.04,
      damping = 0
    },
    TacticalInfo = {bScannable = 0, LookupName = ""}
  },
  Client = {},
  Server = {},
  Editor = {
    Icon = "tornado.bmp",
    IconOnTop = 1
  }
}
Net.Expose({
  Class = PressurizedObject,
  ClientMethods = {
    AddLeak = {
      RELIABLE_ORDERED,
      PRE_ATTACH,
      VEC3,
      VEC3
    }
  },
  ServerMethods = {},
  ServerProperties = {}
})
function PressurizedObject.IsUsable(A0_7828, A1_7829, A2_7830)
  if not A0_7828.__usable then
    A0_7828.__usable = A0_7828.Properties.bUsable
  end
  if System.IsMultiplayer() and System.IsMultiplayer() ~= 0 then
    return 0
  end
  return 2 or 0
end
function PressurizedObject.OnSpawn(A0_7831)
  local L1_7832
  L1_7832 = A0_7831.Properties
  L1_7832 = L1_7832.objModel
  if string.len(L1_7832) > 0 then
    if string.lower(string.sub(L1_7832, -4)) == ".chr" or string.lower(string.sub(L1_7832, -4)) == ".cdf" or string.lower(string.sub(L1_7832, -4)) == ".cga" then
      A0_7831:LoadCharacter(0, L1_7832)
    else
      A0_7831:LoadObject(0, L1_7832)
    end
  end
  g_gameRules.game:MakeMovementVisibleToAI("PressurizedObject")
end
function PressurizedObject.Server.OnInit(A0_7833)
  if not A0_7833.bInitialized then
    A0_7833:OnReset()
    A0_7833.bInitialized = 1
  end
end
function PressurizedObject.Client.OnInit(A0_7834)
  if not A0_7834.bInitialized then
    A0_7834:OnReset()
    A0_7834.bInitialized = 1
  end
  A0_7834:CacheResources()
end
function PressurizedObject.CacheResources(A0_7835)
  A0_7835:PreLoadParticleEffect(A0_7835.Properties.Leak.Effect.ParticleEffect)
end
function PressurizedObject.OnReset(A0_7836)
  local L1_7837, L2_7838, L3_7839
  L1_7837 = A0_7836.Properties
  L1_7837 = L1_7837.TacticalInfo
  L1_7837 = L1_7837.bScannable
  A0_7836.bScannable = L1_7837
  L1_7837 = A0_7836.bScannable
  if L1_7837 == 1 then
    L1_7837 = Game
    L1_7837 = L1_7837.AddTacticalEntity
    L2_7838 = A0_7836.id
    L3_7839 = eTacticalEntity_Story
    L1_7837(L2_7838, L3_7839)
  else
    L1_7837 = Game
    L1_7837 = L1_7837.RemoveTacticalEntity
    L2_7838 = A0_7836.id
    L3_7839 = eTacticalEntity_Story
    L1_7837(L2_7838, L3_7839)
  end
  L1_7837 = {}
  L2_7838 = A0_7836.Properties
  L2_7838 = L2_7838.fMass
  L1_7837.mass = L2_7838
  L2_7838 = A0_7836.Properties
  L2_7838 = L2_7838.fDensity
  L1_7837.density = L2_7838
  L2_7838 = tonumber
  L3_7839 = A0_7836.Properties
  L3_7839 = L3_7839.bRigidBody
  L2_7838 = L2_7838(L3_7839)
  L2_7838 = L2_7838 ~= 0
  L3_7839 = CryAction
  L3_7839 = L3_7839.IsImmersivenessEnabled
  L3_7839 = L3_7839()
  if L3_7839 == 0 then
    L2_7838 = nil
  end
  if L2_7838 then
    L3_7839 = A0_7836.Physicalize
    L3_7839(A0_7836, 0, PE_RIGID, L1_7837)
    L3_7839 = tonumber
    L3_7839 = L3_7839(A0_7836.Properties.bResting)
    if L3_7839 ~= 0 then
      L3_7839 = A0_7836.AwakePhysics
      L3_7839(A0_7836, 0)
    else
      L3_7839 = A0_7836.AwakePhysics
      L3_7839(A0_7836, 1)
    end
    L3_7839 = A0_7836.SetPhysicParams
    L3_7839(A0_7836, PHYSICPARAM_BUOYANCY, A0_7836.Properties.PhysicsBuoyancy)
    L3_7839 = A0_7836.SetPhysicParams
    L3_7839(A0_7836, PHYSICPARAM_SIMULATION, A0_7836.Properties.PhysicsSimulation)
  else
    L3_7839 = A0_7836.Physicalize
    L3_7839(A0_7836, 0, PE_STATIC, L1_7837)
  end
  L3_7839 = {}
  L3_7839.flags = 0
  if A0_7836.Properties.bPushableByPlayers == 1 then
    L3_7839.flags = pef_pushable_by_players
  end
  if A0_7836.Properties.bCanBreakOthers == nil or A0_7836.Properties.bCanBreakOthers == 0 then
    L3_7839.flags = L3_7839.flags + pef_never_break
  end
  L3_7839.flags_mask = pef_pushable_by_players + pef_never_break
  A0_7836:SetPhysicParams(PHYSICPARAM_FLAGS, L3_7839)
  A0_7836:Activate(0)
  A0_7836:ClearLeaks()
  A0_7836.pressure = A0_7836.Properties.Leak.Pressure
  A0_7836.totalPressure = A0_7836.pressure
  A0_7836.pressureDecay = A0_7836.Properties.Leak.PressureDecay
  A0_7836.pressureImpulse = A0_7836.Properties.Leak.PressureImpulse
  A0_7836.maxLeaks = A0_7836.Properties.Leak.MaxLeaks
  A0_7836.damage = A0_7836.Properties.Leak.Damage
  A0_7836.damageRange = A0_7836.Properties.Leak.DamageRange
  A0_7836.damageCheckTime = 0.5
  A0_7836.damageCheckTimer = A0_7836.damageCheckTime
  A0_7836.shooterId = nil
  A0_7836.volume = A0_7836.Properties.Leak.Volume
  if 0 < A0_7836.volume then
    A0_7836.volumeConv = A0_7836.volume / 1
    A0_7836.totalVolume = A0_7836.volume
  end
  if A0_7836.Properties.bAutoGenAIHidePts == 1 then
    A0_7836:SetFlags(ENTITY_FLAG_AI_HIDEABLE, 0)
  else
    A0_7836:SetFlags(ENTITY_FLAG_AI_HIDEABLE, 2)
  end
end
function PressurizedObject.OnPropertyChange(A0_7840)
  A0_7840:OnReset()
end
function PressurizedObject.OnDestroy(A0_7841)
  if A0_7841.bScannable == 1 then
    Game.RemoveTacticalEntity(A0_7841.id, eTacticalEntity_Story)
  end
end
function PressurizedObject.Server.OnHit(A0_7842, A1_7843)
  local L2_7844, L3_7845, L4_7846, L5_7847, L6_7848, L7_7849, L8_7850, L9_7851
  L2_7844 = A1_7843.explosion
  if not L2_7844 then
    L2_7844 = A1_7843.normal
  elseif not L2_7844 then
    return
  end
  L2_7844 = NumberToBool
  L3_7845 = A0_7842.Properties
  L3_7845 = L3_7845.bPlayerOnly
  L2_7844 = L2_7844(L3_7845)
  L3_7845 = A1_7843.shooterId
  L4_7846 = g_localActorId
  L3_7845 = L3_7845 == L4_7846
  L4_7846 = A1_7843.damage
  L5_7847 = A0_7842.Properties
  L5_7847 = L5_7847.Vulnerability
  L6_7848 = A0_7842.Properties
  L6_7848 = L6_7848.DamageMultipliers
  L7_7849 = true
  L8_7850 = A1_7843.explosion
  if L8_7850 then
    L8_7850 = NumberToBool
    L9_7851 = L5_7847.bExplosion
    L8_7850 = L8_7850(L9_7851)
    L7_7849 = L8_7850
  else
    L8_7850 = A1_7843.type
    if L8_7850 == "collision" then
      L8_7850 = NumberToBool
      L9_7851 = L5_7847.bCollision
      L8_7850 = L8_7850(L9_7851)
      L7_7849 = L8_7850
      L8_7850 = L6_7848.fCollision
      L4_7846 = L4_7846 * L8_7850
    else
      L8_7850 = A1_7843.type
      if L8_7850 == "bullet" then
        L8_7850 = NumberToBool
        L9_7851 = L5_7847.bBullet
        L8_7850 = L8_7850(L9_7851)
        L7_7849 = L8_7850
        L8_7850 = L6_7848.fBullet
        L8_7850 = L4_7846 * L8_7850
        A1_7843.damage = L8_7850
      else
        L8_7850 = A1_7843.type
        if L8_7850 == "melee" then
          L8_7850 = NumberToBool
          L9_7851 = L5_7847.bMelee
          L8_7850 = L8_7850(L9_7851)
          L7_7849 = L8_7850
        else
          L8_7850 = NumberToBool
          L9_7851 = L5_7847.bOther
          L8_7850 = L8_7850(L9_7851)
          L7_7849 = L8_7850
        end
      end
    end
  end
  if L7_7849 then
    L8_7850 = A0_7842.Properties
    L8_7850 = L8_7850.fDamageTreshold
    L7_7849 = L4_7846 >= L8_7850
  end
  if not L7_7849 then
    return
  end
  L8_7850 = A1_7843.shooterId
  if not L8_7850 or not L2_7844 or L3_7845 then
    L9_7851 = A0_7842
    L8_7850 = A0_7842.Event_Hit
    L8_7850(L9_7851)
  end
  L8_7850 = A0_7842.leaks
  L9_7851 = A0_7842.maxLeaks
  if L8_7850 < L9_7851 then
    L8_7850 = CryAction
    L8_7850 = L8_7850.IsImmersivenessEnabled
    L8_7850 = L8_7850()
    if L8_7850 ~= 0 then
      L9_7851 = A0_7842
      L8_7850 = A0_7842.ToLocal
      L8_7850 = L8_7850(L9_7851, _UPVALUE0_, A1_7843.pos)
      L9_7851 = A0_7842.VectorToLocal
      L9_7851 = L9_7851(A0_7842, _UPVALUE0_, A1_7843.normal)
      A0_7842.allClients:AddLeak(L8_7850, L9_7851)
      if A0_7842.leaks == 0 then
        A0_7842.shooterId = A1_7843.shooterId
      end
    end
  end
  L9_7851 = A0_7842
  L8_7850 = A0_7842.Activate
  L8_7850(L9_7851, 1)
end
function PressurizedObject.CheckDamage(A0_7852, A1_7853)
  local L2_7854, L3_7855, L4_7856, L5_7857, L6_7858, L7_7859, L8_7860, L9_7861, L10_7862
  A0_7852.damageCheckTimer = L2_7854
  if L2_7854 <= 0 then
    A0_7852.damageCheckTimer = L2_7854
  else
    return
  end
  if L2_7854 > 0 then
    for L5_7857, L6_7858 in L2_7854(L3_7855) do
      L8_7860 = A0_7852
      L7_7859 = A0_7852.GetSlotWorldPos
      L9_7861 = L6_7858.slot
      L10_7862 = A0_7852.leakPos
      L7_7859 = L7_7859(L8_7860, L9_7861, L10_7862)
      A0_7852.leakPos = L7_7859
      L8_7860 = A0_7852
      L7_7859 = A0_7852.GetSlotWorldDir
      L9_7861 = L6_7858.slot
      L10_7862 = A0_7852.leakDir
      L7_7859 = L7_7859(L8_7860, L9_7861, L10_7862)
      A0_7852.leakDir = L7_7859
      L7_7859 = Physics
      L7_7859 = L7_7859.RayWorldIntersection
      L8_7860 = A0_7852.leakPos
      L9_7861 = vecScale
      L10_7862 = A0_7852.leakDir
      L9_7861 = L9_7861(L10_7862, A0_7852.damageRange)
      L10_7862 = 2
      L7_7859 = L7_7859(L8_7860, L9_7861, L10_7862, ent_all, A0_7852.id, nil, g_HitTable)
      if L7_7859 > 0 then
        L8_7860 = g_HitTable
        L8_7860 = L8_7860[1]
        L8_7860 = L8_7860.entity
        if L8_7860 then
          L9_7861 = L8_7860.IsDead
          if L9_7861 then
            L10_7862 = L8_7860
            L9_7861 = L8_7860.IsDead
            L9_7861 = L9_7861(L10_7862)
          end
          if not L9_7861 then
            L10_7862 = L8_7860.Server
            if L10_7862 then
              L10_7862 = L8_7860.Server
              L10_7862 = L10_7862.OnHit
              if L10_7862 then
                L10_7862 = A0_7852.damage
                L10_7862 = L10_7862 * A0_7852.damageCheckTime
                L10_7862 = L10_7862 / A0_7852.leaks
                g_gameRules:CreateHit(L8_7860.id, A0_7852.shooterId, A0_7852.id, L10_7862, nil, nil, nil, A0_7852.Properties.DamageHitType)
              end
            end
          end
        end
      end
    end
  end
end
function PressurizedObject.Event_Hide(A0_7863)
  A0_7863:Hide(1)
end
function PressurizedObject.Event_UnHide(A0_7864)
  A0_7864:Hide(0)
end
function PressurizedObject.HasBeenScanned(A0_7865)
  A0_7865:ActivateOutput("Scanned", true)
end
function PressurizedObject.UpdateLeaks(A0_7866, A1_7867)
  local L2_7868, L3_7869, L4_7870, L5_7871, L6_7872
  if L2_7868 <= 0 then
    if L2_7868 > 0 then
      L2_7868(L3_7869)
    end
  end
  A0_7866.gravity = L2_7868
  for L5_7871, L6_7872 in L2_7868(L3_7869) do
    A0_7866:UpdateLeak(A1_7867, L6_7872, vecNormalize(vecScale(A0_7866.gravity, -1)))
  end
end
function PressurizedObject.UpdateLeak(A0_7873, A1_7874, A2_7875, A3_7876)
  A0_7873.leakPos = A0_7873:ToGlobal(_UPVALUE0_, A2_7875.pos)
  if true or 0 < A0_7873.pressure then
    A0_7873.volume = A0_7873.volume - A0_7873.Properties.Leak.VolumeDecay * A1_7874
    if 0 >= A0_7873.volume then
      A0_7873.volume = 0
    else
      A0_7873:StartLeaking(A2_7875)
    end
  else
    A0_7873:StopLeaking(A2_7875)
  end
end
function PressurizedObject.StartLeaking(A0_7877, A1_7878)
  local L2_7879, L3_7880
  L2_7879 = A1_7878.leaking
  if not L2_7879 then
    A1_7878.leaking = true
    L3_7880 = A0_7877
    L2_7879 = A0_7877.ToGlobal
    L2_7879 = L2_7879(L3_7880, _UPVALUE0_, A1_7878.pos)
    L3_7880 = A0_7877.VectorToGlobal
    L3_7880 = L3_7880(A0_7877, _UPVALUE0_, A1_7878.dir)
    A1_7878.slot = A0_7877:LoadParticleEffect(-1, A0_7877.Properties.Leak.Effect.ParticleEffect, A0_7877.Properties.Leak.Effect)
    A0_7877:SetSlotWorldTM(A1_7878.slot, L2_7879, L3_7880)
    A0_7877.leaks = A0_7877.leaks + 1
  end
end
function PressurizedObject.StopLeaking(A0_7881, A1_7882)
  if A1_7882.leaking then
    A1_7882.leaking = false
    A0_7881:FreeSlot(A1_7882.slot)
    A1_7882.slot = -1
    A0_7881.leaks = A0_7881.leaks - 1
  end
end
function PressurizedObject.Client.AddLeak(A0_7883, A1_7884, A2_7885)
  local L3_7886
  L3_7886 = {}
  L3_7886.pos = A1_7884
  L3_7886.dir = A2_7885
  L3_7886.slot = -1
  L3_7886.leaking = false
  table.insert(A0_7883.leakInfo, L3_7886)
  if not A0_7883.IsActive() then
    A0_7883:Activate(1)
  end
end
function PressurizedObject.ClearLeaks(A0_7887)
  local L1_7888, L2_7889, L3_7890, L4_7891, L5_7892
  if L1_7888 then
    for L4_7891, L5_7892 in L1_7888(L2_7889) do
      A0_7887:StopLeaking(L5_7892)
      if L5_7892.slot then
        A0_7887:FreeSlot(L5_7892.slot)
      end
    end
  end
  A0_7887.leaks = 0
  A0_7887.leakInfo = L1_7888
end
function PressurizedObject.Server.OnUpdate(A0_7893, A1_7894)
  A0_7893:CheckDamage(A1_7894)
end
function PressurizedObject.Client.OnUpdate(A0_7895, A1_7896)
  A0_7895:UpdateLeaks(A1_7896)
  A0_7895.pressure = A0_7895.pressure - A0_7895.pressureDecay * A0_7895.leaks * A1_7896
  if A0_7895.pressure < 0 then
    A0_7895.pressure = 0
  end
  if A0_7895.pressure > 0 and A0_7895.leaks > 0 then
    if 0 < A0_7895.pressureImpulse * A0_7895.pressure / A0_7895.leaks * A1_7896 * A0_7895.Properties.Leak.ImpulseScale then
      for _FORV_7_, _FORV_8_ in ipairs(A0_7895.leakInfo) do
        A0_7895.impulseDir = A0_7895:GetSlotWorldDir(_FORV_8_.slot, A0_7895.impulseDir)
        A0_7895.impulsePos = A0_7895:GetSlotWorldPos(_FORV_8_.slot, A0_7895.impulsePos)
        A0_7895:AddImpulse(-1, A0_7895.impulsePos, A0_7895.impulseDir, -(A0_7895.pressureImpulse * A0_7895.pressure / A0_7895.leaks * A1_7896 * A0_7895.Properties.Leak.ImpulseScale), 1)
      end
    end
  elseif A0_7895.pressure <= 0 and 0 >= A0_7895.volume then
    A0_7895:ClearLeaks()
    if A0_7895.bScannable == 1 then
      Game.RemoveTacticalEntity(A0_7895.id, eTacticalEntity_Story)
    end
  end
  if A0_7895.leaks < 1 then
    A0_7895:Activate(0)
  end
end
function PressurizedObject.Event_Hit(A0_7897, A1_7898)
  BroadcastEvent(A0_7897, "Hit")
end
PressurizedObject.FlowEvents = {
  Inputs = {
    Hit = {
      PressurizedObject.Event_Hit,
      "bool"
    },
    Hide = {
      PressurizedObject.Event_Hide,
      "bool"
    },
    UnHide = {
      PressurizedObject.Event_UnHide,
      "bool"
    }
  },
  Outputs = {
    Hit = "bool",
    Hide = "bool",
    UnHide = "bool",
    Scanned = "bool"
  }
}
MakeUsable(PressurizedObject)
MakePickable(PressurizedObject)
MakeTargetableByAI(PressurizedObject)
MakeKillable(PressurizedObject)
