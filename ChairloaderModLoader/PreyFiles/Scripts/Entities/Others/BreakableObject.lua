Script.ReloadScript("Scripts/Default/Entities/Others/BasicEntity.lua")
BreakableObject = {
  Properties = {
    soclasses_SmartObjectClass = "",
    bAutoGenAIHidePts = 0,
    object_Model = "",
    nDamage = 10,
    fBreakImpuls = 7,
    nExplosionRadius = 5,
    bExplosion = 1,
    bTriggeredOnlyByExplosion = 0,
    impulsivePressure = 200,
    rmin = 2,
    rmax = 20.5,
    Parts = {
      bRigidBody = 0,
      LifeTime = 20,
      Density = 100
    },
    DyingSound = {
      sndFilename = "",
      InnerRadius = 1,
      OuterRadius = 10,
      nVolume = 255
    },
    Physics = {
      bRigidBody = 0,
      bRigidBodyActive = 1,
      bActivateOnDamage = 0,
      bResting = 0,
      Density = -1,
      Mass = 700,
      vector_Impulse = {
        x = 0,
        y = 0,
        z = 0
      },
      max_time_step = 0.01,
      sleep_speed = 0.04,
      damping = 0,
      water_damping = 0,
      water_resistance = 1000,
      water_density = 1000,
      Type = "Unknown",
      bFixedDamping = 0,
      HitDamageScale = 0
    }
  },
  bBreakByCar = 1,
  dead = 0,
  deathVector = {
    x = 0,
    y = 0,
    z = 1
  },
  isLoading = nil,
  StopLastPhysicsSounds = BasicEntity.StopLastPhysicsSounds,
  OnStopRollSlideContact = BasicEntity.OnStopRollSlideContact
}
function BreakableObject.OnInit(A0_6569)
  A0_6569:RegisterState("Active")
  A0_6569:RegisterState("Dead")
  A0_6569:Activate(0)
  A0_6569:TrackColliders(1)
  A0_6569.dead = 0
  A0_6569:OnReset()
end
function BreakableObject.OnPropertyChange(A0_6570)
  A0_6570:OnReset()
end
function BreakableObject.OnShutDown(A0_6571)
  local L1_6572
end
function BreakableObject.SetPhysicsProperties(A0_6573)
  local L1_6574, L2_6575, L3_6576, L4_6577, L5_6578
  L1_6574 = A0_6573.Properties
  L1_6574 = L1_6574.Physics
  L1_6574 = L1_6574.bRigidBody
  if L1_6574 ~= 1 then
    return
  end
  L1_6574, L2_6575, L3_6576 = nil, nil, nil
  L4_6577 = A0_6573.Properties
  L4_6577 = L4_6577.Physics
  L1_6574 = L4_6577.Mass
  L4_6577 = A0_6573.Properties
  L4_6577 = L4_6577.Physics
  L2_6575 = L4_6577.Density
  L5_6578 = A0_6573
  L4_6577 = A0_6573.CreateRigidBody
  L4_6577(L5_6578, L2_6575, L1_6574, -1)
  L4_6577 = A0_6573.bCharacter
  if L4_6577 == 1 then
    L5_6578 = A0_6573
    L4_6577 = A0_6573.PhysicalizeCharacter
    L4_6577(L5_6578, L1_6574, 0, 0, 0)
  end
  L4_6577 = {}
  L5_6578 = A0_6573.Properties
  L5_6578 = L5_6578.Physics
  L5_6578 = L5_6578.max_time_step
  L4_6577.max_time_step = L5_6578
  L5_6578 = A0_6573.Properties
  L5_6578 = L5_6578.Physics
  L5_6578 = L5_6578.sleep_speed
  L4_6577.sleep_speed = L5_6578
  L5_6578 = A0_6573.Properties
  L5_6578 = L5_6578.Physics
  L5_6578 = L5_6578.damping
  L4_6577.damping = L5_6578
  L5_6578 = A0_6573.Properties
  L5_6578 = L5_6578.Physics
  L5_6578 = L5_6578.water_damping
  L4_6577.water_damping = L5_6578
  L5_6578 = A0_6573.Properties
  L5_6578 = L5_6578.Physics
  L5_6578 = L5_6578.water_resistance
  L4_6577.water_resistance = L5_6578
  L5_6578 = A0_6573.Properties
  L5_6578 = L5_6578.Physics
  L5_6578 = L5_6578.water_density
  L4_6577.water_density = L5_6578
  L4_6577.mass = L1_6574
  L4_6577.density = L2_6575
  L5_6578 = A0_6573.Properties
  L5_6578 = L5_6578.Physics
  L5_6578 = L5_6578.bRigidBodyActive
  A0_6573.bRigidBodyActive = L5_6578
  L5_6578 = A0_6573.bRigidBodyActive
  if L5_6578 ~= 1 then
    L4_6577.mass = 0
    L4_6577.density = 0
  end
  L5_6578 = {}
  L5_6578.flags_mask = pef_fixed_damping
  L5_6578.flags = 0
  if A0_6573.Properties.Physics.bFixedDamping ~= 0 then
    L5_6578.flags = pef_fixed_damping
  end
  A0_6573:SetPhysicParams(PHYSICPARAM_SIMULATION, L4_6577)
  A0_6573:SetPhysicParams(PHYSICPARAM_BUOYANCY, A0_6573.Properties.Physics)
  A0_6573:SetPhysicParams(PHYSICPARAM_FLAGS, L5_6578)
  if A0_6573.Properties.Physics.bResting == 0 then
    A0_6573:Activate(1)
    A0_6573:AwakePhysics(1)
  else
    A0_6573:Activate(0)
    A0_6573:AwakePhysics(0)
  end
  if PhysicsSoundsTable then
    A0_6573.ContactSounds_Soft = {}
    if PhysicsSoundsTable.Soft and PhysicsSoundsTable.Soft[A0_6573.Properties.Physics.Type] then
      if PhysicsSoundsTable.Soft[A0_6573.Properties.Physics.Type].Impact then
        A0_6573.ContactSounds_Soft.Impact = Sound.Load3DSound(PhysicsSoundsTable.Soft[A0_6573.Properties.Physics.Type].Impact[1], PhysicsSoundsTable.Soft[A0_6573.Properties.Physics.Type].Impact[2], PhysicsSoundsTable.Soft[A0_6573.Properties.Physics.Type].Impact[6], 255, PhysicsSoundsTable.Soft[A0_6573.Properties.Physics.Type].Impact[4], PhysicsSoundsTable.Soft[A0_6573.Properties.Physics.Type].Impact[5])
        A0_6573.ContactSounds_Soft.ImpactVolume = PhysicsSoundsTable.Soft[A0_6573.Properties.Physics.Type].Impact[3]
      end
      if PhysicsSoundsTable.Soft[A0_6573.Properties.Physics.Type].Roll then
        A0_6573.ContactSounds_Soft.Roll = Sound.Load3DSound(PhysicsSoundsTable.Soft[A0_6573.Properties.Physics.Type].Roll[1], PhysicsSoundsTable.Soft[A0_6573.Properties.Physics.Type].Roll[2], PhysicsSoundsTable.Soft[A0_6573.Properties.Physics.Type].Roll[6], 255, PhysicsSoundsTable.Soft[A0_6573.Properties.Physics.Type].Roll[4], PhysicsSoundsTable.Soft[A0_6573.Properties.Physics.Type].Roll[5])
        A0_6573.ContactSounds_Soft.RollVolume = PhysicsSoundsTable.Soft[A0_6573.Properties.Physics.Type].Roll[3]
        Sound.SetSoundLoop(A0_6573.ContactSounds_Soft.Roll, 1)
      end
      if PhysicsSoundsTable.Soft[A0_6573.Properties.Physics.Type].Slide then
        A0_6573.ContactSounds_Soft.Slide = Sound.Load3DSound(PhysicsSoundsTable.Soft[A0_6573.Properties.Physics.Type].Slide[1], PhysicsSoundsTable.Soft[A0_6573.Properties.Physics.Type].Slide[2], PhysicsSoundsTable.Soft[A0_6573.Properties.Physics.Type].Slide[6], 255, PhysicsSoundsTable.Soft[A0_6573.Properties.Physics.Type].Slide[4], PhysicsSoundsTable.Soft[A0_6573.Properties.Physics.Type].Slide[5])
        A0_6573.ContactSounds_Soft.SlideVolume = PhysicsSoundsTable.Soft[A0_6573.Properties.Physics.Type].Slide[3]
        Sound.SetSoundLoop(A0_6573.ContactSounds_Soft.Slide, 1)
      end
    else
    end
    A0_6573.ContactSounds_Hard = {}
    if PhysicsSoundsTable.Hard and PhysicsSoundsTable.Hard[A0_6573.Properties.Physics.Type] then
      if PhysicsSoundsTable.Hard[A0_6573.Properties.Physics.Type].Impact then
        A0_6573.ContactSounds_Hard.Impact = Sound.Load3DSound(PhysicsSoundsTable.Hard[A0_6573.Properties.Physics.Type].Impact[1], PhysicsSoundsTable.Hard[A0_6573.Properties.Physics.Type].Impact[2], PhysicsSoundsTable.Hard[A0_6573.Properties.Physics.Type].Impact[6], 255, PhysicsSoundsTable.Hard[A0_6573.Properties.Physics.Type].Impact[4], PhysicsSoundsTable.Hard[A0_6573.Properties.Physics.Type].Impact[5])
        A0_6573.ContactSounds_Hard.ImpactVolume = PhysicsSoundsTable.Hard[A0_6573.Properties.Physics.Type].Impact[3]
      end
      if PhysicsSoundsTable.Hard[A0_6573.Properties.Physics.Type].Roll then
        A0_6573.ContactSounds_Hard.Roll = Sound.Load3DSound(PhysicsSoundsTable.Hard[A0_6573.Properties.Physics.Type].Roll[1], PhysicsSoundsTable.Hard[A0_6573.Properties.Physics.Type].Roll[2], PhysicsSoundsTable.Hard[A0_6573.Properties.Physics.Type].Roll[6], 255, PhysicsSoundsTable.Hard[A0_6573.Properties.Physics.Type].Roll[4], PhysicsSoundsTable.Hard[A0_6573.Properties.Physics.Type].Roll[5])
        A0_6573.ContactSounds_Hard.RollVolume = PhysicsSoundsTable.Hard[A0_6573.Properties.Physics.Type].Roll[3]
        Sound.SetSoundLoop(A0_6573.ContactSounds_Hard.Roll, 1)
      end
      if PhysicsSoundsTable.Hard[A0_6573.Properties.Physics.Type].Slide then
        A0_6573.ContactSounds_Hard.Slide = Sound.Load3DSound(PhysicsSoundsTable.Hard[A0_6573.Properties.Physics.Type].Slide[1], PhysicsSoundsTable.Hard[A0_6573.Properties.Physics.Type].Slide[2], PhysicsSoundsTable.Hard[A0_6573.Properties.Physics.Type].Slide[6], 255, PhysicsSoundsTable.Hard[A0_6573.Properties.Physics.Type].Slide[4], PhysicsSoundsTable.Hard[A0_6573.Properties.Physics.Type].Slide[5])
        A0_6573.ContactSounds_Hard.SlideVolume = PhysicsSoundsTable.Hard[A0_6573.Properties.Physics.Type].Slide[3]
        Sound.SetSoundLoop(A0_6573.ContactSounds_Hard.Slide, 1)
      end
    else
    end
  else
  end
end
function BreakableObject.Event_Die(A0_6579, A1_6580)
  A0_6579:GoDead()
  BroadcastEvent(A0_6579, "Die")
end
function BreakableObject.Event_IsDead(A0_6581, A1_6582)
  BroadcastEvent(A0_6581, "IsDead")
end
function BreakableObject.OnReset(A0_6583)
  A0_6583:Activate(0)
  A0_6583:TrackColliders(1)
  A0_6583.dead = 0
  if A0_6583.Properties.object_Model == "" then
    return
  end
  if A0_6583.Properties.object_Model ~= A0_6583.CurrModel then
    A0_6583.CurrModel = A0_6583.Properties.object_Model
    A0_6583:LoadBreakable(A0_6583.Properties.object_Model)
    A0_6583:CreateStaticEntity(10, -2)
  end
  if A0_6583.DyingSound and Sound.IsPlaying(A0_6583.DyingSound) then
    Sound.StopSound(A0_6583.DyingSound)
  end
  if A0_6583.Properties.DyingSound.sndFilename ~= "" then
    A0_6583.DyingSound = Sound.Load3DSound(A0_6583.Properties.DyingSound.sndFilename, SOUND_DEFAULT_3D)
    if A0_6583.DyingSound then
      Sound.SetSoundPosition(A0_6583.DyingSound, A0_6583:GetPos())
      Sound.SetSoundVolume(A0_6583.DyingSound, A0_6583.Properties.DyingSound.nVolume)
      Sound.SetMinMaxDistance(A0_6583.DyingSound, A0_6583.Properties.DyingSound.InnerRadius, A0_6583.Properties.DyingSound.OuterRadius)
    end
  else
    A0_6583.DyingSound = nil
  end
  A0_6583.curr_damage = A0_6583.Properties.nDamage
  if A0_6583.dead == 0 then
    A0_6583:GoAlive()
    A0_6583:SetPhysicsProperties()
  else
    A0_6583:GoDead()
  end
  if A0_6583.Properties.bAutoGenAIHidePts == 1 then
    A0_6583:SetFlags(ENTITY_FLAG_AI_HIDEABLE, 0)
  else
    A0_6583:SetFlags(ENTITY_FLAG_AI_HIDEABLE, 2)
  end
end
function BreakableObject.GoAlive(A0_6584)
  A0_6584:EnablePhysics(1)
  A0_6584:DrawObject(0, 1)
  A0_6584:DrawObject(1, 0)
  A0_6584:GotoState("Active")
end
function BreakableObject.GoDead(A0_6585, A1_6586)
  if A1_6586 then
    A0_6585.deathVector = new(A1_6586)
  else
    A0_6585.deathVector = {
      x = 0,
      y = 0,
      z = 1
    }
  end
  if A0_6585.DyingSound and not Sound.IsPlaying(A0_6585.DyingSound) then
    Sound.PlaySound(A0_6585.DyingSound)
  end
  A0_6585:GotoState("Dead")
  A0_6585:SetTimer(30)
end
function BreakableObject.OnDamage(A0_6587, A1_6588)
  if A0_6587.dead == 1 then
    return
  end
  if A0_6587.Properties.Physics.bRigidBody then
    A0_6587:AwakePhysics(1)
    if A1_6588.ipart and A1_6588.ipart >= 0 then
      A0_6587:AddImpulse(A1_6588.ipart, A1_6588.pos, A1_6588.dir, A1_6588.impact_force_mul)
    end
  end
  if A1_6588 then
    A0_6587.curr_damage = A0_6587.curr_damage - A1_6588.damage
  end
  if 0 >= A0_6587.curr_damage then
    A0_6587:GoDead(A1_6588.dir)
    A0_6587.NoDecals = 1
    A1_6588.target_material = nil
  end
end
BreakableObject.Active = {
  OnBeginState = function(A0_6589)
    local L1_6590
  end,
  OnContact = function(A0_6591, A1_6592)
    if A1_6592.driverT and A0_6591.bBreakByCar == 1 then
      A0_6591:GoDead()
    end
  end,
  OnDamage = BreakableObject.OnDamage,
  OnCollide = BasicEntity.OnCollide
}
BreakableObject.Dead = {
  OnBeginState = function(A0_6593)
    A0_6593.dead = 1
    if A0_6593.isLoading == nil then
      A0_6593:Event_IsDead()
      A0_6593:BreakEntity(A0_6593.deathVector, A0_6593.Properties.fBreakImpuls, A0_6593.Properties.Parts.bRigidBody, A0_6593.Properties.Parts.LifeTime, A0_6593.Properties.Parts.Density)
    end
    A0_6593:DrawObject(0, 0)
    A0_6593:DrawObject(1, 1)
    A0_6593:EnablePhysics(0)
  end,
  OnTimer = function(A0_6594)
    A0_6594:RemoveDecals()
  end
}
function BreakableObject.OnSave(A0_6595, A1_6596)
  A1_6596.dead = A0_6595.dead
end
function BreakableObject.OnLoad(A0_6597, A1_6598)
  A0_6597.dead = A1_6598.dead
  if A0_6597.dead == 0 then
    A0_6597:GoAlive()
  else
    A0_6597.isLoading = 1
    A0_6597:GoDead()
  end
end
BreakableObject.FlowEvents = {
  Inputs = {
    Die = {
      BreakableObject.Event_Die,
      "bool"
    },
    IsDead = {
      BreakableObject.Event_IsDead,
      "bool"
    }
  },
  Outputs = {Die = "bool", IsDead = "bool"}
}
MakeUsable(BreakableObject)
MakePickable(BreakableObject)
MakeTargetableByAI(BreakableObject)
MakeKillable(BreakableObject)
