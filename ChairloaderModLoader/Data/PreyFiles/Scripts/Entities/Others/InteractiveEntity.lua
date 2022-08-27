local L0_6850
L0_6850 = {}
L0_6850.Client = {}
L0_6850.Server = {}
L0_6850.Properties = {
  fileModel = "engine/engineassets/objects/default.cgf",
  ModelSubObject = "",
  fileModelDestroyed = "",
  DestroyedSubObject = "",
  bDestroyable = 0,
  bTurnedOn = 0,
  bUsable = 1,
  bTwoState = 0,
  bUsableOnlyOnce = 0,
  UseMessage = "@use_object",
  OnUse = {
    fUseDelay = 0,
    fCoolDownTime = 0.1,
    bEffectOnUse = 0,
    bSoundOnUse = 1,
    bSpawnOnUse = 1,
    bChangeMatOnUse = 0,
    bChangeModelOnUse = 0,
    fileModelOnUse = ""
  },
  Sound = {
    soundSound = "",
    soundTurnOnSound = "",
    soundTurnOffSound = "",
    soundIdleSound = "",
    vOffset = {
      x = 0,
      y = 0,
      z = 0
    }
  },
  Effect = {
    ParticleEffect = "",
    bPrime = 0,
    Scale = 1,
    CountScale = 1,
    bCountPerUnit = 0,
    AttachType = "",
    AttachForm = "Surface",
    PulsePeriod = 0,
    SpawnPeriod = 0,
    vOffset = {
      x = 0,
      y = 0,
      z = 0
    },
    vRotation = {
      x = 0,
      y = 0,
      z = 0
    }
  },
  fHealth = 100,
  Physics = {
    bRigidBody = 0,
    bRigidBodyActive = 0,
    bResting = 0,
    Density = -1,
    Mass = -1,
    Buoyancy = {
      water_density = 0,
      water_damping = 0,
      water_resistance = 0
    },
    bStaticInDX9Multiplayer = 1,
    MP = {bDontSyncPos = 0}
  },
  Breakage = {
    fLifeTime = 10,
    fExplodeImpulse = 0,
    bSurfaceEffects = 1
  },
  Destruction = {
    bExplode = 1,
    ParticleEffect = "explosions.monitor.a",
    EffectScale = 1,
    Radius = 0,
    Pressure = 0,
    Damage = 0,
    Decal = "",
    Direction = {
      x = 0,
      y = 0.2,
      z = 1
    },
    vOffset = {
      x = 0,
      y = 0,
      z = 0
    }
  },
  Vulnerability = {
    fDamageTreshold = 0,
    bExplosion = 1,
    bCollision = 1,
    bMelee = 1,
    bBullet = 1,
    bOther = 1
  },
  SpawnEntity = {
    iSpawnLimit = 10,
    Archetype = "Props_Physics.Junk.can_b",
    vOffset = {
      x = 0,
      y = -0.5,
      z = 0.5
    },
    vRotation = {
      x = 0,
      y = 0,
      z = 0
    },
    fImpulse = 10,
    vImpulseDir = {
      x = 0,
      y = -1,
      z = 1
    }
  },
  ChangeMaterial = {fileMaterial = "", Duration = 0},
  ScreenFunctions = {
    bHasScreenFunction = 0,
    FlashMatId = -1,
    Type = {bProgressBar = 0}
  },
  TacticalInfo = {bScannable = 0, LookupName = ""}
}
L0_6850.Editor = {Icon = "Item.bmp", IconOnTop = 1}
L0_6850.LastHit = {
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
L0_6850.States = {
  "TurnedOn",
  "TurnedOff",
  "Destroyed"
}
L0_6850.health = 0
L0_6850.soundid = nil
L0_6850.turnoffsoundid = nil
L0_6850.idleSoundId = nil
L0_6850.FXSlot = -1
L0_6850.spawncount = 0
L0_6850.iDelayTimer = -1
L0_6850.iCoolDownTimer = -1
L0_6850.iTurnOffSoundTimer = -1
L0_6850.bCoolDown = 0
L0_6850.shooterId = 0
L0_6850.currentMat = nil
L0_6850.MatResetTimer = nil
L0_6850.progress = 0
InteractiveEntity = L0_6850
L0_6850 = Net
L0_6850 = L0_6850.Expose
L0_6850({
  Class = InteractiveEntity,
  ClientMethods = {
    DeactivateTacticalInfo = {RELIABLE_ORDERED, POST_ATTACH}
  },
  ServerMethods = {},
  ServerProperties = {}
})
L0_6850 = MakePickable
L0_6850(InteractiveEntity)
L0_6850 = {}
L0_6850.bPhysicalize = 1
L0_6850.bPushableByPlayers = 0
L0_6850.bPushableByAI = 0
L0_6850.Density = -1
L0_6850.Mass = -1
L0_6850.bStaticInDX9Multiplayer = 1
function InteractiveEntity.OnPropertyChange(A0_6851)
  A0_6851:OnReset()
  A0_6851:StopIdleSound()
end
function InteractiveEntity.OnEditorSetGameMode(A0_6852, A1_6853)
  if A1_6853 ~= true then
    A0_6852:StopIdleSound()
  end
end
function InteractiveEntity.OnSave(A0_6854, A1_6855)
  A1_6855.health = A0_6854.health
  A1_6855.FXSlot = A0_6854.FXSlot
  A1_6855.spawncount = A0_6854.spawncount
  A1_6855.iDelayTimer = A0_6854.iDelayTimer
  A1_6855.iCoolDownTimer = A0_6854.iCoolDownTimer
  A1_6855.bCoolDown = A0_6854.bCoolDown
  A1_6855.currentMat = A0_6854.currentMat
  A1_6855.MatResetTimer = A0_6854.MatResetTimer
  A1_6855.progress = A0_6854.progress
  A1_6855.bUsable = A0_6854.bUsable
  A1_6855.material = A0_6854:GetEntityMaterial()
  A1_6855.bScannable = A0_6854.bScannable
end
function InteractiveEntity.OnLoad(A0_6856, A1_6857)
  if A1_6857.FXSlot <= 0 and A0_6856.FXSlot > 0 then
    A0_6856:DeleteParticleEmitter(A0_6856.FXSlot)
    A0_6856:RemoveEffect()
  end
  A0_6856:OnReset()
  A0_6856.health = A1_6857.health
  A0_6856.FXSlot = A1_6857.FXSlot
  A0_6856.spawncount = A1_6857.spawncount
  A0_6856.iDelayTimer = A1_6857.iDelayTimer
  A0_6856.iCoolDownTimer = A1_6857.iCoolDownTimer
  A0_6856.bCoolDown = A1_6857.bCoolDown
  A0_6856.currentMat = A1_6857.currentMat
  A0_6856.MatResetTimer = A1_6857.MatResetTimer
  A0_6856.progress = A1_6857.progress
  A0_6856.bUsable = A1_6857.bUsable
  if A1_6857.material then
    A0_6856:SetMaterial(A1_6857.material)
  end
  A0_6856.bScannable = A1_6857.bScannable
  if A0_6856.bScannable == 1 then
    Game.AddTacticalEntity(A0_6856.id, eTacticalEntity_Story)
  else
    Game.RemoveTacticalEntity(A0_6856.id, eTacticalEntity_Story)
  end
  if A0_6856.Properties.ScreenFunctions.bHasScreenFunction == 1 and A0_6856.Properties.ScreenFunctions.Type.bProgressBar == 1 then
    A0_6856:MaterialFlashInvoke(0, A0_6856.Properties.ScreenFunctions.FlashMatId, 0, "SetProgress", A0_6856.progress)
  end
  if 0 >= A0_6856.health then
    A0_6856:GotoState("Destroyed")
  end
end
function InteractiveEntity.OnReset(A0_6858)
  if A0_6858.MatResetTimer ~= nil then
    Script.KillTimer(A0_6858.MatResetTimer)
    A0_6858.MatResetTimer = nil
  end
  A0_6858:StopIdleSound()
  A0_6858:ResetMaterial(0)
  A0_6858:ResetMat()
  A0_6858:Stop(0)
  A0_6858:RemoveEffect()
  A0_6858.spawncount = 0
  if not EmptyString(A0_6858.Properties.fileModel) then
    A0_6858:LoadSubObject(0, A0_6858.Properties.fileModel, A0_6858.Properties.ModelSubObject)
  end
  if not EmptyString(A0_6858.Properties.fileModelDestroyed) then
    A0_6858:LoadSubObject(1, A0_6858.Properties.fileModelDestroyed, A0_6858.Properties.DestroyedSubObject)
  elseif not EmptyString(A0_6858.Properties.DestroyedSubObject) then
    A0_6858:LoadSubObject(1, A0_6858.Properties.fileModel, A0_6858.Properties.DestroyedSubObject)
  end
  if not EmptyString(A0_6858.Properties.OnUse.fileModelOnUse) then
    A0_6858:LoadSubObject(2, A0_6858.Properties.OnUse.fileModelOnUse, A0_6858.Properties.ModelSubObject)
  end
  A0_6858:SetCurrentSlot(0)
  A0_6858:PhysicalizeThis(0)
  A0_6858.health = A0_6858.Properties.fHealth
  A0_6858:PlayIdleSound()
  if A0_6858.Properties.bTurnedOn == 1 then
    A0_6858:GotoState("TurnedOn")
  else
    A0_6858:GotoState("TurnedOff")
  end
  A0_6858.progress = 0
  A0_6858.bUsable = A0_6858.Properties.bUsable
  if A0_6858.Properties.ScreenFunctions.bHasScreenFunction == 1 and A0_6858.Properties.ScreenFunctions.Type.bProgressBar == 1 then
    A0_6858:MaterialFlashInvoke(0, A0_6858.Properties.ScreenFunctions.FlashMatId, 0, "SetProgress", 0)
  end
  A0_6858.bScannable = A0_6858.Properties.TacticalInfo.bScannable
  if A0_6858.bScannable == 1 then
    Game.AddTacticalEntity(A0_6858.id, eTacticalEntity_Story)
  else
    Game.RemoveTacticalEntity(A0_6858.id, eTacticalEntity_Story)
  end
end
function InteractiveEntity.PhysicalizeThis(A0_6859, A1_6860)
  local L2_6861
  L2_6861 = A0_6859.Properties
  L2_6861 = L2_6861.Physics
  L2_6861 = L2_6861.MP
  L2_6861 = L2_6861.bDontSyncPos
  if L2_6861 == 1 then
    L2_6861 = CryAction
    L2_6861 = L2_6861.DontSyncPhysics
    L2_6861(A0_6859.id)
  end
  L2_6861 = A0_6859.Properties
  L2_6861 = L2_6861.Physics
  if CryAction.IsImmersivenessEnabled() == 0 then
    L2_6861 = _UPVALUE0_
  end
  EntityCommon.PhysicalizeRigid(A0_6859, A1_6860, L2_6861, 1)
  if L2_6861.Buoyancy then
    A0_6859:SetPhysicParams(PHYSICPARAM_BUOYANCY, L2_6861.Buoyancy)
  end
end
function InteractiveEntity.Server.OnHit(A0_6862, A1_6863)
  local L2_6864, L3_6865
  L2_6864 = A0_6862.Properties
  L2_6864 = L2_6864.bDestroyable
  if L2_6864 == 1 then
    L2_6864 = A0_6862.Properties
    L2_6864 = L2_6864.Vulnerability
    L3_6865 = A1_6863.damage
    L3_6865 = L3_6865 >= A0_6862.Properties.Vulnerability.fDamageTreshold
    if L3_6865 and A1_6863.explosion then
      L3_6865 = NumberToBool(L2_6864.bExplosion)
    elseif L3_6865 and A1_6863.type == "collision" then
      L3_6865 = NumberToBool(L2_6864.bCollision)
    elseif L3_6865 and A1_6863.type == "bullet" then
      L3_6865 = NumberToBool(L2_6864.bBullet)
    elseif L3_6865 and A1_6863.type == "melee" then
      L3_6865 = NumberToBool(L2_6864.bMelee)
    else
      L3_6865 = L3_6865 and NumberToBool(L2_6864.bOther)
    end
    if L3_6865 then
      A0_6862.shooterId = A1_6863.shooterId
      BroadcastEvent(A0_6862, "Hit")
      A0_6862.health = A0_6862.health - A1_6863.damage
      if A0_6862.health <= 0 and CryAction.IsImmersivenessEnabled() ~= 0 then
        A0_6862:GotoState("Destroyed")
        if A1_6863.dir then
          A0_6862:AddImpulse(A1_6863.partId or -1, A1_6863.pos, A1_6863.dir, A1_6863.damage)
        end
      end
    end
  end
end
function InteractiveEntity.Client.OnHit(A0_6866, A1_6867, A2_6868)
  CopyVector(A0_6866.LastHit.pos, A1_6867.pos)
  CopyVector(A0_6866.LastHit.impulse, A1_6867.dir)
  A0_6866.LastHit.impulse.x = A0_6866.LastHit.impulse.x * A1_6867.damage
  A0_6866.LastHit.impulse.y = A0_6866.LastHit.impulse.y * A1_6867.damage
  A0_6866.LastHit.impulse.z = A0_6866.LastHit.impulse.z * A1_6867.damage
end
function InteractiveEntity.OnUsed(A0_6869, A1_6870, A2_6871)
  local L3_6872
  L3_6872 = A0_6869.bUsable
  if L3_6872 == 0 then
    return
  end
  L3_6872 = A0_6869.Properties
  L3_6872 = L3_6872.OnUse
  if A0_6869.bCoolDown == 0 and A0_6869.iDelayTimer == -1 then
    if 0 < L3_6872.fUseDelay then
      A0_6869.iDelayTimer = Script.SetTimerForFunction(L3_6872.fUseDelay * 1000, "InteractiveEntity.Use", A0_6869)
    else
      A0_6869:Use(A1_6870, A2_6871)
    end
  end
  if A0_6869.bScannable == 1 then
    Game.RemoveTacticalEntity(A0_6869.id, eTacticalEntity_Story)
  end
end
function InteractiveEntity.ResetMat(A0_6873)
  if A0_6873.currentMat then
    A0_6873:SetMaterial(A0_6873.currentMat)
  end
  A0_6873.MatResetTimer = nil
end
function InteractiveEntity.EndCoolDown(A0_6874)
  local L1_6875
  A0_6874.bCoolDown = 0
  L1_6875 = A0_6874.Properties
  L1_6875 = L1_6875.bUsableOnlyOnce
  if L1_6875 ~= 1 then
    A0_6874.bUsable = 1
  end
end
function InteractiveEntity.Use(A0_6876)
  local L1_6877
  L1_6877 = A0_6876.Properties
  L1_6877 = L1_6877.OnUse
  A0_6876.iDelayTimer = -1
  A0_6876.iCoolDownTimer = -1
  if L1_6877.fCoolDownTime ~= 0 then
    A0_6876.bCoolDown = 1
    A0_6876.bUsable = 0
    A0_6876.iCoolDownTimer = Script.SetTimerForFunction(L1_6877.fCoolDownTime * 1000, "InteractiveEntity.EndCoolDown", A0_6876)
  end
  A0_6876:ActivateOutput("Used", true)
  if A0_6876.Properties.bTwoState ~= 0 then
    if A0_6876:GetState() == "TurnedOn" then
      A0_6876:Stop(1)
      A0_6876:GotoState("TurnedOff")
    elseif A0_6876:GetState() == "TurnedOff" then
      A0_6876:GotoState("TurnedOn")
    elseif A0_6876:GetState() == "Destroyed" then
      return
    end
  else
    A0_6876:Play()
    A0_6876:DoEffect()
    A0_6876:DoSpawn()
    A0_6876:DoMaterialChange()
  end
  if A0_6876.Properties.bUsableOnlyOnce == 1 then
    A0_6876.bUsable = 0
  end
end
function InteractiveEntity.IsUsable(A0_6878, A1_6879)
  if System.IsMultiplayer() and System.IsMultiplayer() ~= 0 then
    return 0
  end
  if A0_6878.bUsable == 1 and A0_6878:GetState() ~= "Destroyed" then
    return 2
  end
  if A0_6878.Properties.bPickable == 1 then
    if not EmptyString(A0_6878.Properties.fileModelDestroyed) or not EmptyString(A0_6878.Properties.DestroyedSubObject) then
      return 1
    end
  end
  return 0
end
function InteractiveEntity.GetUsableMessage(A0_6880, A1_6881)
  local L2_6882
  L2_6882 = A0_6880.bUsable
  if L2_6882 == 1 then
    L2_6882 = A0_6880.Properties
    L2_6882 = L2_6882.UseMessage
    return L2_6882
  else
    L2_6882 = "@grab_object"
    return L2_6882
  end
end
function InteractiveEntity.DoSpawn(A0_6883)
  local L1_6884, L2_6885, L3_6886, L4_6887, L5_6888, L6_6889, L7_6890, L8_6891, L9_6892, L10_6893
  L1_6884 = CryAction
  L1_6884 = L1_6884.IsGameStarted
  L1_6884 = L1_6884()
  if not L1_6884 then
    return
  end
  L1_6884 = A0_6883.Properties
  L1_6884 = L1_6884.OnUse
  L1_6884 = L1_6884.bSpawnOnUse
  if L1_6884 ~= 1 then
    return
  end
  L1_6884 = A0_6883.spawncount
  L2_6885 = A0_6883.Properties
  L2_6885 = L2_6885.SpawnEntity
  L2_6885 = L2_6885.iSpawnLimit
  if not (L1_6884 >= L2_6885) then
    L1_6884 = A0_6883.spawncount
  elseif L1_6884 >= 20 then
    return
  end
  L1_6884 = A0_6883.Properties
  L1_6884 = L1_6884.SpawnEntity
  L2_6885 = {}
  L2_6885.class = "BasicEntity"
  L3_6886 = L1_6884.Archetype
  L2_6885.archetype = L3_6886
  L4_6887 = A0_6883
  L3_6886 = A0_6883.GetName
  L3_6886 = L3_6886(L4_6887)
  L4_6887 = "_spawnedentity_"
  L5_6888 = A0_6883.spawncount
  L3_6886 = L3_6886 .. L4_6887 .. L5_6888
  L2_6885.name = L3_6886
  L2_6885.flags = 0
  L3_6886 = {}
  L3_6886.x = 0
  L3_6886.y = 1
  L3_6886.z = 0
  L2_6885.orientation = L3_6886
  L4_6887 = A0_6883
  L3_6886 = A0_6883.GetPos
  L3_6886 = L3_6886(L4_6887)
  L2_6885.position = L3_6886
  L2_6885.scale = nil
  L3_6886 = System
  L3_6886 = L3_6886.SpawnEntity
  L4_6887 = L2_6885
  L3_6886 = L3_6886(L4_6887)
  L4_6887 = A0_6883.spawncount
  L4_6887 = L4_6887 + 1
  A0_6883.spawncount = L4_6887
  L4_6887 = A0_6883.spawncount
  L5_6888 = A0_6883.Properties
  L5_6888 = L5_6888.SpawnEntity
  L5_6888 = L5_6888.iSpawnLimit
  if L4_6887 >= L5_6888 then
    A0_6883.bUsable = 0
  end
  if L3_6886 ~= nil then
    L3_6886.health = 5
    L5_6888 = A0_6883
    L4_6887 = A0_6883.GetWorldPos
    L4_6887 = L4_6887(L5_6888)
    L5_6888 = g_Vectors
    L5_6888 = L5_6888.temp_v1
    L7_6890 = A0_6883
    L6_6889 = A0_6883.GetDirectionVector
    L8_6891 = 0
    L6_6889 = L6_6889(L7_6890, L8_6891)
    L8_6891 = A0_6883
    L7_6890 = A0_6883.GetDirectionVector
    L9_6892 = 1
    L7_6890 = L7_6890(L8_6891, L9_6892)
    L9_6892 = A0_6883
    L8_6891 = A0_6883.GetDirectionVector
    L10_6893 = 2
    L8_6891 = L8_6891(L9_6892, L10_6893)
    L9_6892 = CopyVector
    L10_6893 = L5_6888
    L9_6892(L10_6893, A0_6883.Properties.SpawnEntity.vOffset)
    L9_6892 = L4_6887.x
    L10_6893 = L6_6889.x
    L10_6893 = L10_6893 * L5_6888.x
    L9_6892 = L9_6892 + L10_6893
    L10_6893 = L7_6890.x
    L10_6893 = L10_6893 * L5_6888.y
    L9_6892 = L9_6892 + L10_6893
    L10_6893 = L8_6891.x
    L10_6893 = L10_6893 * L5_6888.z
    L9_6892 = L9_6892 + L10_6893
    L4_6887.x = L9_6892
    L9_6892 = L4_6887.y
    L10_6893 = L6_6889.y
    L10_6893 = L10_6893 * L5_6888.x
    L9_6892 = L9_6892 + L10_6893
    L10_6893 = L7_6890.y
    L10_6893 = L10_6893 * L5_6888.y
    L9_6892 = L9_6892 + L10_6893
    L10_6893 = L8_6891.y
    L10_6893 = L10_6893 * L5_6888.z
    L9_6892 = L9_6892 + L10_6893
    L4_6887.y = L9_6892
    L9_6892 = L4_6887.z
    L10_6893 = L6_6889.z
    L10_6893 = L10_6893 * L5_6888.x
    L9_6892 = L9_6892 + L10_6893
    L10_6893 = L7_6890.z
    L10_6893 = L10_6893 * L5_6888.y
    L9_6892 = L9_6892 + L10_6893
    L10_6893 = L8_6891.z
    L10_6893 = L10_6893 * L5_6888.z
    L9_6892 = L9_6892 + L10_6893
    L4_6887.z = L9_6892
    L9_6892 = g_Vectors
    L9_6892 = L9_6892.temp_v2
    L10_6893 = L6_6889.x
    L10_6893 = L10_6893 * L1_6884.vImpulseDir.x
    L10_6893 = L10_6893 + L7_6890.x * L1_6884.vImpulseDir.y
    L10_6893 = L10_6893 + L8_6891.x * L1_6884.vImpulseDir.z
    L9_6892.x = L10_6893
    L10_6893 = L6_6889.y
    L10_6893 = L10_6893 * L1_6884.vImpulseDir.x
    L10_6893 = L10_6893 + L7_6890.y * L1_6884.vImpulseDir.y
    L10_6893 = L10_6893 + L8_6891.y * L1_6884.vImpulseDir.z
    L9_6892.y = L10_6893
    L10_6893 = L6_6889.z
    L10_6893 = L10_6893 * L1_6884.vImpulseDir.x
    L10_6893 = L10_6893 + L7_6890.z * L1_6884.vImpulseDir.y
    L10_6893 = L10_6893 + L8_6891.z * L1_6884.vImpulseDir.z
    L9_6892.z = L10_6893
    L10_6893 = g_Vectors
    L10_6893 = L10_6893.temp_v4
    L10_6893 = A0_6883:CalcWorldAnglesFromRelativeDir(L1_6884.vRotation)
    L3_6886:SetWorldPos(L4_6887)
    L3_6886:SetAngles(L10_6893)
    if 0 < L1_6884.fImpulse then
      L3_6886:AddImpulse(-1, L3_6886:GetPos(), L9_6892, L1_6884.fImpulse, 1)
    end
  end
end
function InteractiveEntity.DoMaterialChange(A0_6894)
  local L1_6895
  L1_6895 = A0_6894.Properties
  L1_6895 = L1_6895.OnUse
  L1_6895 = L1_6895.bChangeMatOnUse
  if L1_6895 ~= 1 then
    return
  end
  L1_6895 = A0_6894.Properties
  L1_6895 = L1_6895.ChangeMaterial
  L1_6895 = L1_6895.fileMaterial
  if not EmptyString(L1_6895) then
    A0_6894.currentMat = A0_6894:GetMaterial(0)
    A0_6894:SetMaterial(L1_6895)
    if A0_6894.Properties.bTwoState ~= 1 and A0_6894.Properties.ChangeMaterial.Duration ~= 0 and A0_6894.MatResetTimer == nil then
      A0_6894.MatResetTimer = Script.SetTimerForFunction(A0_6894.Properties.ChangeMaterial.Duration * 1000, "InteractiveEntity.ResetMat", A0_6894)
    end
  end
end
function InteractiveEntity.DoEffect(A0_6896)
  local L1_6897
  L1_6897 = A0_6896.Properties
  L1_6897 = L1_6897.OnUse
  L1_6897 = L1_6897.bEffectOnUse
  if L1_6897 ~= 1 then
    return
  end
  L1_6897 = A0_6896.Properties
  L1_6897 = L1_6897.Effect
  L1_6897 = L1_6897.ParticleEffect
  if not EmptyString(L1_6897) then
    A0_6896.FXSlot = A0_6896:LoadParticleEffect(-1, A0_6896.Properties.Effect.ParticleEffect, A0_6896.Properties.Effect)
    A0_6896:SetSlotPos(A0_6896.FXSlot, A0_6896.Properties.Effect.vOffset)
    A0_6896:SetSlotAngles(A0_6896.FXSlot, A0_6896.Properties.Effect.vRotation)
  end
end
function InteractiveEntity.RemoveEffect(A0_6898)
  A0_6898:FreeSlot(A0_6898.FXSlot)
  A0_6898.FXSlot = -1
end
function InteractiveEntity.Play(A0_6899)
  if A0_6899.Properties.OnUse.bSoundOnUse ~= 1 then
    return
  end
  A0_6899:Stop(0)
  if A0_6899.Properties.Sound.soundTurnOnSound ~= "" then
    A0_6899:StopIdleSound()
  end
  if A0_6899.Properties.Sound.soundSound ~= "" then
  end
end
function InteractiveEntity.StopIdleSound(A0_6900)
  if A0_6900.idleSoundId ~= nil then
    Sound.StopSound(A0_6900.idleSoundId)
    A0_6900.idleSoundId = nil
  end
end
function InteractiveEntity.PlayIdleSound(A0_6901)
  local L1_6902
  L1_6902 = A0_6901.idleSoundId
  if L1_6902 == nil then
    L1_6902 = A0_6901.health
    if L1_6902 > 0 then
      L1_6902 = A0_6901.Properties
      L1_6902 = L1_6902.Sound
      L1_6902 = L1_6902.soundIdleSound
      if L1_6902 ~= "" then
      end
    end
  end
end
function InteractiveEntity.Stop(A0_6903, A1_6904)
  if A0_6903.soundid ~= nil then
    Sound.StopSound(A0_6903.soundid)
    A0_6903.soundid = nil
  end
  A0_6903:PlayIdleSound()
end
function InteractiveEntity.Explode(A0_6905)
  local L1_6906, L2_6907, L3_6908, L4_6909, L5_6910, L6_6911, L7_6912, L8_6913, L9_6914, L10_6915, L11_6916, L12_6917, L13_6918
  L1_6906 = A0_6905.Properties
  L2_6907 = A0_6905.LastHit
  L2_6907 = L2_6907.pos
  L3_6908 = A0_6905.LastHit
  L3_6908 = L3_6908.impulse
  L5_6910 = A0_6905
  L4_6909 = A0_6905.BreakToPieces
  L6_6911 = 0
  L7_6912 = 0
  L8_6913 = L1_6906.Breakage
  L8_6913 = L8_6913.fExplodeImpulse
  L9_6914 = L2_6907
  L10_6915 = L3_6908
  L11_6916 = L1_6906.Breakage
  L11_6916 = L11_6916.fLifeTime
  L12_6917 = L1_6906.Breakage
  L12_6917 = L12_6917.bSurfaceEffects
  L4_6909(L5_6910, L6_6911, L7_6912, L8_6913, L9_6914, L10_6915, L11_6916, L12_6917)
  L5_6910 = A0_6905
  L4_6909 = A0_6905.Stop
  L6_6911 = 0
  L4_6909(L5_6910, L6_6911)
  L4_6909 = NumberToBool
  L5_6910 = A0_6905.Properties
  L5_6910 = L5_6910.Destruction
  L5_6910 = L5_6910.bExplode
  L4_6909 = L4_6909(L5_6910)
  if L4_6909 then
    L4_6909 = A0_6905.Properties
    L4_6909 = L4_6909.Destruction
    L6_6911 = A0_6905
    L5_6910 = A0_6905.GetWorldPos
    L5_6910 = L5_6910(L6_6911)
    L7_6912 = A0_6905
    L6_6911 = A0_6905.GetDirectionVector
    L8_6913 = 0
    L6_6911 = L6_6911(L7_6912, L8_6913)
    L8_6913 = A0_6905
    L7_6912 = A0_6905.GetDirectionVector
    L9_6914 = 1
    L7_6912 = L7_6912(L8_6913, L9_6914)
    L9_6914 = A0_6905
    L8_6913 = A0_6905.GetDirectionVector
    L10_6915 = 2
    L8_6913 = L8_6913(L9_6914, L10_6915)
    L9_6914 = {}
    L9_6914.x = 0
    L9_6914.y = 0
    L9_6914.z = 0
    L10_6915 = CopyVector
    L11_6916 = L9_6914
    L12_6917 = L4_6909.vOffset
    L10_6915(L11_6916, L12_6917)
    L10_6915 = L5_6910.x
    L11_6916 = L6_6911.x
    L12_6917 = L9_6914.x
    L11_6916 = L11_6916 * L12_6917
    L10_6915 = L10_6915 + L11_6916
    L11_6916 = L7_6912.x
    L12_6917 = L9_6914.y
    L11_6916 = L11_6916 * L12_6917
    L10_6915 = L10_6915 + L11_6916
    L11_6916 = L8_6913.x
    L12_6917 = L9_6914.z
    L11_6916 = L11_6916 * L12_6917
    L10_6915 = L10_6915 + L11_6916
    L5_6910.x = L10_6915
    L10_6915 = L5_6910.y
    L11_6916 = L6_6911.y
    L12_6917 = L9_6914.x
    L11_6916 = L11_6916 * L12_6917
    L10_6915 = L10_6915 + L11_6916
    L11_6916 = L7_6912.y
    L12_6917 = L9_6914.y
    L11_6916 = L11_6916 * L12_6917
    L10_6915 = L10_6915 + L11_6916
    L11_6916 = L8_6913.y
    L12_6917 = L9_6914.z
    L11_6916 = L11_6916 * L12_6917
    L10_6915 = L10_6915 + L11_6916
    L5_6910.y = L10_6915
    L10_6915 = L5_6910.z
    L11_6916 = L6_6911.z
    L12_6917 = L9_6914.x
    L11_6916 = L11_6916 * L12_6917
    L10_6915 = L10_6915 + L11_6916
    L11_6916 = L7_6912.z
    L12_6917 = L9_6914.y
    L11_6916 = L11_6916 * L12_6917
    L10_6915 = L10_6915 + L11_6916
    L11_6916 = L8_6913.z
    L12_6917 = L9_6914.z
    L11_6916 = L11_6916 * L12_6917
    L10_6915 = L10_6915 + L11_6916
    L5_6910.z = L10_6915
    L10_6915 = L5_6910
    L11_6916 = g_Vectors
    L11_6916 = L11_6916.temp_v1
    L12_6917 = g_Vectors
    L12_6917 = L12_6917.temp_v2
    L13_6918 = CopyVector
    L13_6918(L12_6917, L4_6909.Direction)
    L13_6918 = L12_6917.x
    if L13_6918 == 0 then
      L13_6918 = L12_6917.y
      if L13_6918 == 0 then
        L13_6918 = L12_6917.z
        if L13_6918 == 0 then
          L12_6917.y = 1
        end
      end
    end
    L13_6918 = L6_6911.x
    L13_6918 = L13_6918 * L12_6917.x
    L13_6918 = L13_6918 + L7_6912.x * L12_6917.y
    L13_6918 = L13_6918 + L8_6913.x * L12_6917.z
    L11_6916.x = L13_6918
    L13_6918 = L6_6911.y
    L13_6918 = L13_6918 * L12_6917.x
    L13_6918 = L13_6918 + L7_6912.y * L12_6917.y
    L13_6918 = L13_6918 + L8_6913.y * L12_6917.z
    L11_6916.y = L13_6918
    L13_6918 = L6_6911.z
    L13_6918 = L13_6918 * L12_6917.x
    L13_6918 = L13_6918 + L7_6912.z * L12_6917.y
    L13_6918 = L13_6918 + L8_6913.z * L12_6917.z
    L11_6916.z = L13_6918
    L13_6918 = EmptyString
    L13_6918 = L13_6918(L4_6909.ParticleEffect)
    if not L13_6918 then
      L13_6918 = {}
      L13_6918.Scale = L4_6909.EffectScale
      A0_6905.FXSlot = A0_6905:LoadParticleEffect(-1, L4_6909.ParticleEffect, L13_6918)
      A0_6905:SetSlotPosAndDir(A0_6905.FXSlot, L4_6909.vOffset, L11_6916)
    end
    L13_6918 = g_gameRules
    L13_6918 = L13_6918.game
    L13_6918 = L13_6918.GetHitTypeId
    L13_6918 = L13_6918(L13_6918, "explosion")
    g_gameRules:CreateExplosion(A0_6905.shooterId, A0_6905.id, L4_6909.Damage, L10_6915, L11_6916, L4_6909.Radius, nil, L4_6909.Pressure, L4_6909.HoleSize, nil, nil, nil, nil, nil, L13_6918)
  end
  L5_6910 = A0_6905
  L4_6909 = A0_6905.RemoveDecals
  L4_6909(L5_6910)
  L5_6910 = A0_6905
  L4_6909 = A0_6905.SetCurrentSlot
  L6_6911 = 1
  L4_6909(L5_6910, L6_6911)
  L5_6910 = A0_6905
  L4_6909 = A0_6905.PhysicalizeThis
  L6_6911 = 1
  L4_6909(L5_6910, L6_6911)
  L5_6910 = A0_6905
  L4_6909 = A0_6905.AwakePhysics
  L6_6911 = 1
  L4_6909(L5_6910, L6_6911)
  L4_6909 = A0_6905.bScannable
  if L4_6909 == 1 then
    L4_6909 = Game
    L4_6909 = L4_6909.RemoveTacticalEntity
    L5_6910 = A0_6905.id
    L6_6911 = eTacticalEntity_Story
    L4_6909(L5_6910, L6_6911)
  end
end
function InteractiveEntity.SetProgress(A0_6919)
  if A0_6919:GetState() ~= "Destroyed" then
    if A0_6919.Properties.ScreenFunctions.bHasScreenFunction == 1 and A0_6919.Properties.ScreenFunctions.Type.bProgressBar == 1 then
      if A0_6919.progress <= 100 then
        if A0_6919:MaterialFlashInvoke(0, A0_6919.Properties.ScreenFunctions.FlashMatId, 0, "SetProgress", A0_6919.progress) == "" then
          Log("Invalid Material ID! ID" .. A0_6919.Properties.ScreenFunctions.FlashMatId .. "on Entity " .. A0_6919:GetName() .. " is not a flash material.")
        end
        A0_6919.progress = A0_6919.progress + 1
        A0_6919:ActivateOutput("Progress", A0_6919.progress)
      end
    else
      Log("No Progressbar Type!")
    end
  end
end
function InteractiveEntity.SetCurrentSlot(A0_6920, A1_6921)
  if A1_6921 == 0 then
    A0_6920:DrawSlot(0, 1)
    A0_6920:DrawSlot(1, 0)
    A0_6920:DrawSlot(2, 0)
  elseif A1_6921 == 1 then
    A0_6920:DrawSlot(0, 0)
    A0_6920:DrawSlot(1, 1)
    A0_6920:DrawSlot(2, 0)
  elseif A1_6921 == 2 then
    A0_6920:DrawSlot(0, 0)
    A0_6920:DrawSlot(1, 0)
    A0_6920:DrawSlot(2, 1)
  end
  A0_6920.currentSlot = A1_6921
end
function InteractiveEntity.Server.OnInit(A0_6922)
  if not A0_6922.bInitialized then
    A0_6922:OnReset()
    A0_6922.bInitialized = 1
  end
end
function InteractiveEntity.Client.OnInit(A0_6923)
  if not A0_6923.bInitialized then
    A0_6923:OnReset()
    A0_6923.bInitialized = 1
  end
  A0_6923:CacheResources()
end
function InteractiveEntity.CacheResources(A0_6924)
  local L1_6925
  L1_6925 = A0_6924.PreLoadParticleEffect
  L1_6925(A0_6924, A0_6924.Properties.Effect.ParticleEffect)
  L1_6925 = A0_6924.PreLoadParticleEffect
  L1_6925(A0_6924, A0_6924.Properties.Destruction.ParticleEffect)
  L1_6925 = A0_6924.Properties
  L1_6925 = L1_6925.ChangeMaterial
  L1_6925 = L1_6925.fileMaterial
  if not EmptyString(L1_6925) then
    Game.CacheResource("InteractiveEntity.lua", L1_6925, eGameCacheResourceType_Material, 0)
  end
end
function InteractiveEntity.Event_TurnedOn(A0_6926)
  if A0_6926.bScannable == 1 then
    Game.AddTacticalEntity(A0_6926.id, eTacticalEntity_Story)
  end
  BroadcastEvent(A0_6926, "TurnedOn")
  A0_6926:GotoState("TurnedOn")
end
function InteractiveEntity.Event_TurnedOff(A0_6927)
  if A0_6927.bScannable == 1 then
    Game.RemoveTacticalEntity(A0_6927.id, eTacticalEntity_Story)
  end
  BroadcastEvent(A0_6927, "TurnedOff")
  A0_6927:GotoState("TurnedOff")
end
function InteractiveEntity.Event_Destroyed(A0_6928)
  if A0_6928.bScannable == 1 then
    Game.RemoveTacticalEntity(A0_6928.id, eTacticalEntity_Story)
  end
  BroadcastEvent(A0_6928, "Destroyed")
  A0_6928:GotoState("Destroyed")
end
function InteractiveEntity.Event_Hit(A0_6929, A1_6930)
  BroadcastEvent(A0_6929, "Hit")
end
function InteractiveEntity.Event_SetProgress(A0_6931)
  A0_6931:SetProgress()
end
function InteractiveEntity.Event_ResetProgress(A0_6932)
  local L1_6933
  A0_6932.progress = 0
  L1_6933 = A0_6932.Properties
  L1_6933 = L1_6933.ScreenFunctions
  if L1_6933.bHasScreenFunction == 1 and L1_6933.Type.bProgressBar == 1 then
    A0_6932:MaterialFlashInvoke(0, L1_6933.FlashMatId, 0, "SetProgress", 0)
  end
end
function InteractiveEntity.Event_Use(A0_6934, A1_6935)
  A0_6934:OnUsed(A0_6934, 0)
end
function InteractiveEntity.Event_Hide(A0_6936)
  if A0_6936.bScannable == 1 then
    Game.RemoveTacticalEntity(A0_6936.id, eTacticalEntity_Story)
  end
  A0_6936:Hide(1)
end
function InteractiveEntity.Event_UnHide(A0_6937)
  A0_6937:Hide(0)
  if A0_6937.bScannable == 1 then
    Game.AddTacticalEntity(A0_6937.id, eTacticalEntity_Story)
  end
end
function InteractiveEntity.Event_EnableUsable(A0_6938)
  local L1_6939
  A0_6938.bUsable = 1
end
function InteractiveEntity.Event_DisableUsable(A0_6940)
  local L1_6941
  A0_6940.bUsable = 0
end
function InteractiveEntity.Event_EnableScannable(A0_6942)
  A0_6942.bScannable = 1
  Game.AddTacticalEntity(A0_6942.id, eTacticalEntity_Story)
end
function InteractiveEntity.Event_DisableScannable(A0_6943)
  A0_6943.bScannable = 0
  Game.RemoveTacticalEntity(A0_6943.id, eTacticalEntity_Story)
end
InteractiveEntity.Server.TurnedOn = {
  OnBeginState = function(A0_6944)
    A0_6944:Play()
    A0_6944:DoEffect()
    A0_6944:DoSpawn()
    A0_6944:DoMaterialChange()
    if A0_6944.Properties.OnUse.bChangeModelOnUse ~= 0 then
      A0_6944:SetCurrentSlot(2)
    end
    BroadcastEvent(A0_6944, "TurnedOn")
  end,
  OnEndState = function(A0_6945)
    local L1_6946
  end
}
InteractiveEntity.Server.TurnedOff = {
  OnBeginState = function(A0_6947)
    A0_6947:RemoveEffect()
    if A0_6947.currentMat ~= nil then
      A0_6947:SetMaterial(A0_6947.currentMat)
    end
    if A0_6947.Properties.OnUse.bChangeModelOnUse ~= 0 then
      A0_6947:SetCurrentSlot(0)
    end
    BroadcastEvent(A0_6947, "TurnedOff")
  end,
  OnEndState = function(A0_6948)
    local L1_6949
  end
}
InteractiveEntity.Server.Destroyed = {
  OnBeginState = function(A0_6950)
    A0_6950:StopIdleSound()
    A0_6950:RemoveEffect()
    A0_6950:Explode()
    A0_6950:ActivateOutput("Destroyed", 1)
    A0_6950.allClients:DeactivateTacticalInfo()
  end,
  OnEndState = function(A0_6951)
    local L1_6952
  end
}
function InteractiveEntity.Client.DeactivateTacticalInfo(A0_6953)
  if A0_6953.bScannable == 1 then
    Game.RemoveTacticalEntity(A0_6953.id, eTacticalEntity_Story)
  end
end
function InteractiveEntity.HasBeenScanned(A0_6954)
  if A0_6954.bScannable == 1 then
    A0_6954:ActivateOutput("Scanned", true)
  end
end
function InteractiveEntity.GetMaxHealth(A0_6955)
  return A0_6955.Properties.fHealth
end
InteractiveEntity.FlowEvents = {
  Inputs = {
    TurnedOn = {
      InteractiveEntity.Event_TurnedOn,
      "bool"
    },
    TurnedOff = {
      InteractiveEntity.Event_TurnedOff,
      "bool"
    },
    Destroyed = {
      InteractiveEntity.Event_Destroyed,
      "bool"
    },
    Hit = {
      InteractiveEntity.Event_Hit,
      "bool"
    },
    SetProgress = {
      InteractiveEntity.Event_SetProgress,
      "bool"
    },
    ResetProgress = {
      InteractiveEntity.Event_ResetProgress,
      "bool"
    },
    Use = {
      InteractiveEntity.Event_Use,
      "bool"
    },
    Hide = {
      InteractiveEntity.Event_Hide,
      "bool"
    },
    UnHide = {
      InteractiveEntity.Event_UnHide,
      "bool"
    },
    EnableUsable = {
      InteractiveEntity.Event_EnableUsable,
      "bool"
    },
    DisableUsable = {
      InteractiveEntity.Event_DisableUsable,
      "bool"
    },
    EnableScannable = {
      InteractiveEntity.Event_EnableScannable,
      "bool"
    },
    DisableScannable = {
      InteractiveEntity.Event_DisableScannable,
      "bool"
    }
  },
  Outputs = {
    TurnedOn = "bool",
    TurnedOff = "bool",
    Destroyed = "bool",
    Hit = "bool",
    Progress = "float",
    Used = "bool",
    Scanned = "bool"
  }
}
