local L0_4748, L1_4749
L0_4748 = {}
L1_4749 = {}
L0_4748.Client = L1_4749
L1_4749 = {}
L0_4748.Server = L1_4749
L1_4749 = {}
L1_4749.bLocked = 0
L0_4748.PropertiesInstance = L1_4749
L1_4749 = {}
L1_4749.soclasses_SmartObjectClass = "Door"
L1_4749.fileModel = "engine/engineassets/objects/default.cgf"
L1_4749.ModelSubObject = ""
L1_4749.fileModelDestroyed = ""
L1_4749.DestroyedSubObject = ""
L1_4749.fHealth = 500
L1_4749.Mass = 50
L1_4749.bUsePortal = 1
L1_4749.Limits = {
  fUseDistance = 2,
  OpeningRange = 90,
  MaxForce = 0,
  MaxBend = 0,
  Damping = 0,
  fSpeed = 1,
  fAutoCloseTime = 0,
  bOpenFromFront = 1,
  bOpenFromBack = 1,
  InitialAngle = 0,
  bIsBreachable = 1
}
L1_4749.Breakage = {
  fLifeTime = 10,
  fExplodeImpulse = 0,
  bSurfaceEffects = 1
}
L1_4749.Destruction = {
  bExplode = 1,
  ParticleEffect = "breakable_objects.tree_break.small",
  EffectScale = 1,
  Radius = 1,
  Pressure = 12,
  Damage = 0,
  Decal = "",
  Direction = {
    x = 0,
    y = 0,
    z = -1
  }
}
L1_4749.Vulnerability = {
  fDamageTreshold = 0,
  bExplosion = 1,
  bCollision = 1,
  bMelee = 1,
  bBullet = 1,
  bOther = 1
}
L1_4749.Sound = {
  soundOpenSound = "Sounds/physics:objects/doors:metal_wire_door_open",
  soundCloseSound = "Sounds/physics:objects/doors:metal_wire_door_close",
  soundLockedSound = "Sounds/physics:objects/doors:metal_wire_door_locked"
}
L0_4748.Properties = L1_4749
L1_4749 = {}
L1_4749.impulse = {
  x = 0,
  y = 0,
  z = 0
}
L1_4749.pos = {
  x = 0,
  y = 0,
  z = 0
}
L0_4748.LastHit = L1_4749
L1_4749 = {}
L1_4749.Icon = "door.bmp"
L1_4749.ShowBounds = 1
L0_4748.Editor = L1_4749
L1_4749 = {
  "Opened",
  "Closed",
  "Destroyed"
}
L0_4748.States = L1_4749
L0_4748.advancedDoor = true
AdvancedDoor = L0_4748
L0_4748 = AdvancedDoor
function L1_4749(A0_4750)
  AI.SetSmartObjectState(A0_4750.id, "Closed")
  if not EmptyString(A0_4750.Properties.fileModel) then
    A0_4750:LoadSubObject(0, A0_4750.Properties.fileModel, A0_4750.Properties.ModelSubObject)
  end
  if not EmptyString(A0_4750.Properties.fileModelDestroyed) then
    A0_4750:LoadSubObject(1, A0_4750.Properties.fileModelDestroyed, A0_4750.Properties.DestroyedSubObject)
  elseif not EmptyString(A0_4750.Properties.DestroyedSubObject) then
    A0_4750:LoadSubObject(1, A0_4750.Properties.fileModel, A0_4750.Properties.DestroyedSubObject)
  end
  A0_4750.openingrange = A0_4750.Properties.Limits.OpeningRange
  A0_4750.openingrange = clamp(A0_4750.Properties.Limits.OpeningRange, -175, 175)
  A0_4750:GetAngles(A0_4750.rad)
  A0_4750:GetAngles(A0_4750.initialrot)
  A0_4750:GetPos(A0_4750.initialpos)
  A0_4750.angle.z = A0_4750.rad.z * g_Rad2Deg
  A0_4750.defaultangle = A0_4750.angle.z
  A0_4750:UpdateImpulsePos()
  A0_4750:SetCurrentSlot(0)
  A0_4750:PhysicalizeThis(0, 0)
  A0_4750:EnablePhysics(true)
  A0_4750:AwakePhysics(0)
  A0_4750:Activate(0)
  A0_4750.bUpdate = 0
  A0_4750.lasttime = 0
  A0_4750.bOpenNow = 0
  A0_4750.bBreachNow = 0
  A0_4750.lockbroken = 0
  A0_4750.openpercentage = 0
  A0_4750.health = A0_4750.Properties.fHealth
  A0_4750.locked = A0_4750.PropertiesInstance.bLocked
  if A0_4750.Properties.bUsePortal == 0 then
    System.ActivatePortal(A0_4750:GetWorldPos(), 1, A0_4750.id)
  end
  if A0_4750.locked == 1 then
    AI.ModifySmartObjectStates(A0_4750.id, "Locked")
  end
  A0_4750:CheckInitalAngle()
end
L0_4748.OnReset = L1_4749
L0_4748 = AdvancedDoor
function L1_4749(A0_4751)
  local L1_4752, L2_4753
  L1_4752 = A0_4751.Properties
  L1_4752 = L1_4752.Limits
  L1_4752 = L1_4752.InitialAngle
  if L1_4752 ~= 0 then
    if L1_4752 < 0 then
      L2_4753 = A0_4751.openingrange
    else
      if not (L2_4753 < 0) then
        if L1_4752 > 0 then
          L2_4753 = A0_4751.openingrange
        end
    end
    elseif L2_4753 > 0 then
      L2_4753 = A0_4751.PhysicalizeThis
      L2_4753(A0_4751, 0, 1)
      L2_4753 = A0_4751.EnablePhysics
      L2_4753(A0_4751, true)
      L2_4753 = A0_4751.AwakePhysics
      L2_4753(A0_4751, 1)
      L2_4753 = A0_4751.Activate
      L2_4753(A0_4751, 1)
      L2_4753 = A0_4751.Apply
      L2_4753(A0_4751)
      L2_4753 = {}
      L2_4753.x = 0
      L2_4753.y = 0
      L2_4753.z = 0
      CopyVector(L2_4753, A0_4751.initialrot)
      L2_4753.z = L2_4753.z + L1_4752 * g_Deg2Rad
      A0_4751:SetAngles(L2_4753)
      A0_4751:UpdateImpulsePos()
      if A0_4751.Properties.bUsePortal == 1 then
        System.ActivatePortal(A0_4751:GetWorldPos(), 0, A0_4751.id)
      end
      A0_4751:GotoState("Opened")
    end
  else
    L2_4753 = A0_4751.GotoState
    L2_4753(A0_4751, "Closed")
  end
end
L0_4748.CheckInitalAngle = L1_4749
L0_4748 = AdvancedDoor
function L1_4749(A0_4754)
  local L1_4755
  L1_4755 = A0_4754.openpercentage
  return L1_4755
end
L0_4748.GetOpenPercentage = L1_4749
L0_4748 = AdvancedDoor
function L1_4749(A0_4756)
  A0_4756.impulsepos = A0_4756:GetWorldPos()
  if A0_4756:GetLocalBBox().x > 0.1 then
    A0_4756.leftsided = 0
    ;({
      x = 0,
      y = 0,
      z = 0
    }).x = A0_4756:GetLocalBBox().x
  else
    A0_4756.leftsided = 1
    ;({
      x = 0,
      y = 0,
      z = 0
    }).x = A0_4756:GetLocalBBox().x
  end
  ;({
    x = 0,
    y = 0,
    z = 0
  }).y = A0_4756:GetLocalBBox().y / 2
  ;({
    x = 0,
    y = 0,
    z = 0
  }).z = A0_4756:GetLocalBBox().z / 2
  A0_4756.impulsepos.x = A0_4756.impulsepos.x + A0_4756:GetDirectionVector(0).x * ({
    x = 0,
    y = 0,
    z = 0
  }).x + A0_4756:GetDirectionVector(1).x * ({
    x = 0,
    y = 0,
    z = 0
  }).y + A0_4756:GetDirectionVector(2).x * ({
    x = 0,
    y = 0,
    z = 0
  }).z
  A0_4756.impulsepos.y = A0_4756.impulsepos.y + A0_4756:GetDirectionVector(0).y * ({
    x = 0,
    y = 0,
    z = 0
  }).x + A0_4756:GetDirectionVector(1).y * ({
    x = 0,
    y = 0,
    z = 0
  }).y + A0_4756:GetDirectionVector(2).y * ({
    x = 0,
    y = 0,
    z = 0
  }).z
  A0_4756.impulsepos.z = A0_4756.impulsepos.z + A0_4756:GetDirectionVector(0).z * ({
    x = 0,
    y = 0,
    z = 0
  }).x + A0_4756:GetDirectionVector(1).z * ({
    x = 0,
    y = 0,
    z = 0
  }).y + A0_4756:GetDirectionVector(2).z * ({
    x = 0,
    y = 0,
    z = 0
  }).z
end
L0_4748.UpdateImpulsePos = L1_4749
L0_4748 = AdvancedDoor
function L1_4749(A0_4757)
  local L1_4758
  L1_4758 = {}
  L1_4758.pivot = {}
  L1_4758.frame0 = {}
  L1_4758.frame1 = {}
  CopyVector(L1_4758.pivot, A0_4757.initialpos)
  CopyVector(L1_4758.frame1, A0_4757.initialrot)
  CopyVector(L1_4758.frame0, L1_4758.frame1)
  L1_4758.frame0_inner = {
    x = 0,
    y = 90,
    z = 0
  }
  L1_4758.frame1_inner = {
    x = 0,
    y = 90,
    z = 0
  }
  if 0 < A0_4757.openingrange then
    L1_4758.xmin = -A0_4757.openingrange
    L1_4758.xmax = 0
  else
    L1_4758.xmin = 0
    L1_4758.xmax = -A0_4757.openingrange
  end
  L1_4758.yzmin = 0
  L1_4758.yzmax = 0
  L1_4758.ignore_buddy = 1
  L1_4758.damping = A0_4757.Properties.Limits.Damping
  L1_4758.sensor_size = A0_4757.Properties.radius
  L1_4758.max_pull_force = A0_4757.Properties.Limits.MaxForce
  L1_4758.max_bend_torque = A0_4757.Properties.Limits.MaxBend
  idConstr = A0_4757:SetPhysicParams(PHYSICPARAM_CONSTRAINT, L1_4758)
end
L0_4748.Apply = L1_4749
L0_4748 = AdvancedDoor
function L1_4749(A0_4759)
  if A0_4759.bUpdate == 1 then
    if A0_4759.bWasReset == 1 then
      A0_4759:PhysicalizeThis(0, 1)
      A0_4759:EnablePhysics(true)
      A0_4759:AwakePhysics(1)
      A0_4759:Activate(1)
      A0_4759:Apply()
      A0_4759.bWasReset = 0
    elseif A0_4759.bOpenNow == 1 then
      A0_4759:OpenDoor(A0_4759.user, A0_4759.idx)
      A0_4759.bOpenNow = 0
    end
    A0_4759:GetAngles(A0_4759.rad)
    A0_4759.angle.z = A0_4759.rad.z * g_Rad2Deg
    if A0_4759.angle.z == A0_4759.lastangle then
      if A0_4759.lasttime == 0 then
        A0_4759.lasttime = System.GetCurrTime()
      end
      if System.GetCurrTime() - A0_4759.lasttime > 5 then
        A0_4759.lasttime = 0
        A0_4759.bUpdate = 0
      end
    end
    A0_4759.lastangle = A0_4759.angle.z
    A0_4759.openpercentage = math.abs(A0_4759.angle.z - A0_4759.defaultangle) / (math.abs(A0_4759.openingrange) / 100)
    if math.abs(A0_4759.angle.z - A0_4759.defaultangle) < 0.5 and A0_4759:GetState() ~= "Closed" then
      A0_4759:Play(0)
      A0_4759:GotoState("Closed")
    elseif math.abs(A0_4759.angle.z - A0_4759.defaultangle) > 0.5 and A0_4759:GetState() ~= "Opened" then
      A0_4759:GotoState("Opened")
    elseif 0.5 > 360 - math.abs(A0_4759.angle.z - A0_4759.defaultangle) and A0_4759:GetState() ~= "Closed" then
      A0_4759:SetAngles(A0_4759.initialrot)
      A0_4759:Play(0)
      A0_4759:GotoState("Closed")
    end
    if A0_4759.Properties.Limits.fAutoCloseTime ~= 0 and A0_4759:GetState() == "Opened" and A0_4759.iAutoCloseTimer == nil then
      A0_4759.iAutoCloseTimer = Script.SetTimerForFunction(A0_4759.Properties.Limits.fAutoCloseTime * 1000, "AdvancedDoor.AutoClose", A0_4759)
    end
  else
    A0_4759:GetAngles(A0_4759.rad)
    A0_4759.angle.z = A0_4759.rad.z * g_Rad2Deg
    if A0_4759.angle.z ~= A0_4759.lastangle then
      A0_4759.bUpdate = 1
    end
    A0_4759.lastangle = A0_4759.angle.z
  end
end
L0_4748.OnUpdate = L1_4749
L0_4748 = AdvancedDoor
function L1_4749(A0_4760)
  if A0_4760:GetState() == "Opened" then
    A0_4760:Close()
  end
end
L0_4748.AutoClose = L1_4749
L0_4748 = AdvancedDoor
function L1_4749(A0_4761, A1_4762, A2_4763)
  if A2_4763 ~= 1 then
    A0_4761.physics.Mass = -1
    A0_4761.physics.Density = -1
  else
    A0_4761.physics.Mass = A0_4761.Properties.Mass
  end
  A0_4761.physics.bCanBreakOthers = 1
  EntityCommon.PhysicalizeRigid(A0_4761, A1_4762, A0_4761.physics, A2_4763)
  A0_4761:SetPhysicParams(PHYSICPARAM_VELOCITY, {
    v = {
      x = 0,
      y = 0,
      z = 0
    }
  })
end
L0_4748.PhysicalizeThis = L1_4749
L0_4748 = AdvancedDoor
function L1_4749(A0_4764, A1_4765)
  if A1_4765 == 0 then
    A0_4764:DrawSlot(0, 1)
    A0_4764:DrawSlot(1, 0)
  else
    A0_4764:DrawSlot(0, 0)
    A0_4764:DrawSlot(1, 1)
  end
  A0_4764.currentSlot = A1_4765
end
L0_4748.SetCurrentSlot = L1_4749
L0_4748 = AdvancedDoor
function L1_4749(A0_4766)
  A0_4766:OnReset()
end
L0_4748.OnPropertyChange = L1_4749
L0_4748 = AdvancedDoor
L0_4748 = L0_4748.Server
function L1_4749(A0_4767)
  A0_4767.bUpdate = 1
  A0_4767.bWasReset = 0
  A0_4767.bWasDetached = 0
  A0_4767.idConstr = -1
  A0_4767.health = 0
  A0_4767.rad = {}
  A0_4767.angle = {}
  A0_4767.lasttime = 0
  A0_4767.lastangle = 0
  A0_4767.locked = 0
  A0_4767.span = 0
  A0_4767.openingrange = 0
  A0_4767.defaultangle = 0
  A0_4767.bOpenNow = 0
  A0_4767.bBreachNow = 0
  A0_4767.user = 0
  A0_4767.idx = 0
  A0_4767.sndid = nil
  A0_4767.lockbroken = 0
  A0_4767.leftsided = 0
  A0_4767.iAutoCloseTimer = nil
  A0_4767.initialrot = {
    x = 0,
    y = 0,
    z = 0
  }
  A0_4767.initialpos = {
    x = 0,
    y = 0,
    z = 0
  }
  A0_4767.impulsedir = {
    x = 0,
    y = 0,
    z = 0
  }
  A0_4767.impulsepos = {
    x = 0,
    y = 0,
    z = 0
  }
  A0_4767.tmp = {
    x = 0,
    y = 0,
    z = 0
  }
  A0_4767.tmp_2 = {
    x = 0,
    y = 0,
    z = 0
  }
  A0_4767.tmp_3 = {
    x = 0,
    y = 0,
    z = 0
  }
  A0_4767.physics = {
    bRigidBody = 1,
    bRigidBodyActive = 1,
    bResting = 1,
    Density = -1,
    Mass = 100,
    Buoyancy = {
      water_density = 1000,
      water_damping = 0,
      water_resistance = 1000
    }
  }
  A0_4767.initialdir = A0_4767:GetDirectionVector(1)
  A0_4767:OnReset()
end
L0_4748.OnInit = L1_4749
L0_4748 = AdvancedDoor
function L1_4749(A0_4768)
  if A0_4768.health <= 0 then
    return true
  else
    return false
  end
end
L0_4748.IsDead = L1_4749
L0_4748 = AdvancedDoor
L0_4748 = L0_4748.Server
function L1_4749(A0_4769, A1_4770)
  local L2_4771, L3_4772, L4_4773
  L3_4772 = A0_4769
  L2_4771 = A0_4769.GetState
  L2_4771 = L2_4771(L3_4772)
  if L2_4771 == "Destroyed" then
    return
  end
  A0_4769.bUpdate = 1
  L2_4771 = A1_4770.damage
  L3_4772 = A0_4769.Properties
  L3_4772 = L3_4772.Vulnerability
  L4_4773 = A1_4770.damage
  L4_4773 = L4_4773 >= A0_4769.Properties.Vulnerability.fDamageTreshold
  if L4_4773 and A1_4770.explosion then
    L4_4773 = NumberToBool(L3_4772.bExplosion)
  elseif L4_4773 and A1_4770.type == "collision" then
    L4_4773 = NumberToBool(L3_4772.bCollision)
  elseif L4_4773 and A1_4770.type == "bullet" then
    L4_4773 = NumberToBool(L3_4772.bBullet)
  elseif L4_4773 and A1_4770.type == "melee" then
    L4_4773 = NumberToBool(L3_4772.bMelee)
  else
    L4_4773 = L4_4773 and NumberToBool(L3_4772.bOther)
  end
  if L4_4773 then
    A0_4769.shooterId = A1_4770.shooterId
    BroadcastEvent(A0_4769, "Hit")
    if A1_4770.type == "collision" then
      L2_4771 = A0_4769:CheckCollision(A1_4770)
    end
    A0_4769.health = A0_4769.health - L2_4771
    if A0_4769:IsDead() then
      A0_4769:GotoState("Destroyed")
    end
  end
  if A1_4770.type == "melee" and NumberToBool(L3_4772.bMelee) then
    A0_4769.shooterId = A1_4770.shooterId
    L2_4771 = L2_4771 / 4
    if L2_4771 > 80 and A0_4769:GetState() == "Closed" then
      A0_4769:BreachDoor()
    end
  end
end
L0_4748.OnHit = L1_4749
L0_4748 = AdvancedDoor
function L1_4749(A0_4774, A1_4775)
  CopyVector(A0_4774.LastHit.pos, A1_4775.pos)
  CopyVector(A0_4774.LastHit.impulse, A1_4775.dir)
  A0_4774.LastHit.impulse.x = A0_4774.LastHit.impulse.x * A1_4775.damage
  A0_4774.LastHit.impulse.y = A0_4774.LastHit.impulse.y * A1_4775.damage
  A0_4774.LastHit.impulse.z = A0_4774.LastHit.impulse.z * A1_4775.damage
  return LengthVector(A1_4775.weapon:GetVelocity()) * A1_4775.weapon:GetMass() / 1.5
end
L0_4748.CheckCollision = L1_4749
L0_4748 = AdvancedDoor
function L1_4749(A0_4776, A1_4777)
  if A0_4776.Properties.bIsBreachable == 0 or not A0_4776:CheckBreachDirection(A1_4777) then
    return
  end
  A0_4776:Activate(1)
  A0_4776.bUpdate = 1
  A0_4776.bWasReset = 1
  A0_4776.locked = 0
  A0_4776.bBreachNow = 1
  A0_4776.lockbroken = 1
  A0_4776:Open(nil, 0)
  A0_4776:ActivateOutput("Breached", 1)
end
L0_4748.BreachDoor = L1_4749
L0_4748 = AdvancedDoor
L0_4748 = L0_4748.Client
function L1_4749(A0_4778, A1_4779, A2_4780)
  CopyVector(A0_4778.LastHit.pos, A1_4779.pos)
  CopyVector(A0_4778.LastHit.impulse, A1_4779.dir)
  A0_4778.LastHit.impulse.x = A0_4778.LastHit.impulse.x * A1_4779.damage
  A0_4778.LastHit.impulse.y = A0_4778.LastHit.impulse.y * A1_4779.damage
  A0_4778.LastHit.impulse.z = A0_4778.LastHit.impulse.z * A1_4779.damage
  A0_4778:AddImpulse(-1, A1_4779.pos, A1_4779.dir, 20, 1)
end
L0_4748.OnHit = L1_4749
L0_4748 = AdvancedDoor
function L1_4749(A0_4781, A1_4782)
  BroadcastEvent(A0_4781, "ConstraintBroken")
end
L0_4748.Event_ConstraintBroken = L1_4749
L0_4748 = AdvancedDoor
function L1_4749(A0_4783, A1_4784)
  local L2_4785
  L2_4785 = A0_4783.idConstr
  A1_4784.idConstr = L2_4785
  L2_4785 = A0_4783.bWasDetached
  A1_4784.bWasDetached = L2_4785
  L2_4785 = A0_4783.bWasReset
  A1_4784.bWasReset = L2_4785
  L2_4785 = A0_4783.health
  A1_4784.health = L2_4785
  L2_4785 = A0_4783.rad
  A1_4784.rad = L2_4785
  L2_4785 = A0_4783.angle
  A1_4784.angle = L2_4785
  L2_4785 = A0_4783.span
  A1_4784.span = L2_4785
  L2_4785 = A0_4783.openingrange
  A1_4784.opeingrange = L2_4785
  L2_4785 = A0_4783.defaultangle
  A1_4784.defaultangle = L2_4785
  L2_4785 = A0_4783.locked
  A1_4784.locked = L2_4785
  L2_4785 = A0_4783.bOpenNow
  A1_4784.bOpenNow = L2_4785
  L2_4785 = A0_4783.bBreachNow
  A1_4784.bBreachNow = L2_4785
  L2_4785 = A0_4783.user
  A1_4784.user = L2_4785
  L2_4785 = A0_4783.idx
  A1_4784.idx = L2_4785
  L2_4785 = A0_4783.lockbroken
  A1_4784.lockbroken = L2_4785
  L2_4785 = A0_4783.iAutoCloseTimer
  A1_4784.iAutoCloseTimer = L2_4785
  L2_4785 = A0_4783.initialpos
  A1_4784.initialpos = L2_4785
  L2_4785 = A0_4783.initialrot
  A1_4784.initialrot = L2_4785
  L2_4785 = A0_4783.impulsedir
  A1_4784.impulsedir = L2_4785
  L2_4785 = A0_4783.leftsided
  A1_4784.leftsided = L2_4785
  L2_4785 = A0_4783.impulsepos
  A1_4784.impulsepos = L2_4785
end
L0_4748.OnSave = L1_4749
L0_4748 = AdvancedDoor
function L1_4749(A0_4786, A1_4787)
  local L2_4788
  L2_4788 = A1_4787.idConstr
  A0_4786.idConstr = L2_4788
  L2_4788 = A1_4787.bWasDetached
  A0_4786.bWasDetached = L2_4788
  L2_4788 = A1_4787.bWasReset
  A0_4786.bWasReset = L2_4788
  L2_4788 = A1_4787.health
  A0_4786.health = L2_4788
  L2_4788 = A1_4787.rad
  A0_4786.rad = L2_4788
  L2_4788 = A1_4787.angle
  A0_4786.angle = L2_4788
  L2_4788 = A1_4787.span
  A0_4786.span = L2_4788
  L2_4788 = A1_4787.opeingrange
  A0_4786.openingrange = L2_4788
  L2_4788 = A1_4787.defaultangle
  A0_4786.defaultangle = L2_4788
  L2_4788 = A1_4787.locked
  A0_4786.locked = L2_4788
  L2_4788 = A1_4787.bOpenNow
  A0_4786.bOpenNow = L2_4788
  L2_4788 = A1_4787.bBreachNow
  A0_4786.bBreachNow = L2_4788
  L2_4788 = A1_4787.user
  A0_4786.user = L2_4788
  L2_4788 = A1_4787.idx
  A0_4786.idx = L2_4788
  L2_4788 = A1_4787.lockbroken
  A0_4786.lockbroken = L2_4788
  L2_4788 = A1_4787.iAutoCloseTimer
  A0_4786.iAutoCloseTimer = L2_4788
  L2_4788 = A1_4787.initialpos
  A0_4786.initialpos = L2_4788
  L2_4788 = A1_4787.initialrot
  A0_4786.initialrot = L2_4788
  L2_4788 = A1_4787.impulsedir
  A0_4786.impulsedir = L2_4788
  L2_4788 = A1_4787.leftsided
  A0_4786.leftsided = L2_4788
  L2_4788 = A1_4787.impulsepos
  A0_4786.impulsepos = L2_4788
end
L0_4748.OnLoad = L1_4749
L0_4748 = AdvancedDoor
function L1_4749(A0_4789, A1_4790)
end
L0_4748.Play = L1_4749
L0_4748 = AdvancedDoor
function L1_4749(A0_4791, A1_4792)
  if A1_4792 ~= nil then
    CopyVector(A0_4791.tmp, A0_4791.initialdir)
    A0_4791:GetWorldPos(A0_4791.tmp_2)
    A1_4792:GetWorldPos(A0_4791.tmp_3)
    SubVectors(A0_4791.tmp_2, A0_4791.tmp_2, A0_4791.tmp_3)
    NormalizeVector(A0_4791.tmp_2)
    if A0_4791.openingrange > 0 then
      if dotproduct3d(A0_4791.tmp, A0_4791.tmp_2) < 0 then
        if A0_4791.leftsided == 0 then
          return false
        else
          return true
        end
      elseif A0_4791.leftsided == 0 then
        return true
      else
        return false
      end
    elseif dotproduct3d(A0_4791.tmp, A0_4791.tmp_2) > 0 then
      if A0_4791.leftsided == 0 then
        return false
      else
        return true
      end
    elseif A0_4791.leftsided == 0 then
      return true
    else
      return false
    end
  end
end
L0_4748.CheckBreachDirection = L1_4749
L0_4748 = AdvancedDoor
function L1_4749(A0_4793, A1_4794)
  local L2_4795
  L2_4795 = A0_4793.Properties
  L2_4795 = L2_4795.Limits
  CopyVector(A0_4793.tmp, A0_4793.initialdir)
  A0_4793:GetWorldPos(A0_4793.tmp_2)
  A1_4794:GetWorldPos(A0_4793.tmp_3)
  SubVectors(A0_4793.tmp_2, A0_4793.tmp_2, A0_4793.tmp_3)
  NormalizeVector(A0_4793.tmp_2)
  if dotproduct3d(A0_4793.tmp, A0_4793.tmp_2) > 0 then
    if L2_4795.bOpenFromFront == 0 then
      return false
    end
  elseif L2_4795.bOpenFromBack == 0 then
    return false
  end
  return true
end
L0_4748.CheckUseDirection = L1_4749
L0_4748 = AdvancedDoor
function L1_4749(A0_4796, A1_4797, A2_4798)
  if A0_4796:GetState() == "Closed" then
    if A0_4796:CheckUseDirection(A1_4797) then
      if A0_4796.locked == 1 then
        A0_4796:Play(1)
        return
      else
        A0_4796:Use(A1_4797, A2_4798)
      end
    end
  else
    A0_4796:Use(A1_4797, A2_4798)
  end
end
L0_4748.OnUsed = L1_4749
L0_4748 = AdvancedDoor
function L1_4749(A0_4799, A1_4800, A2_4801)
  A0_4799:Activate(1)
  A0_4799.bUpdate = 1
  A0_4799.lasttime = 0
  Log("self:GetState(): " .. A0_4799:GetState())
  if A0_4799:GetState() == "Closed" then
    A0_4799:Open(A1_4800, A2_4801)
  else
    A0_4799:Close(A1_4800, A2_4801)
  end
end
L0_4748.Use = L1_4749
L0_4748 = AdvancedDoor
function L1_4749(A0_4802, A1_4803, A2_4804)
  if A0_4802:GetState() == "Closed" then
    A0_4802:SetPos(A0_4802.initialpos)
    A0_4802:SetAngles(A0_4802.initialrot)
    A0_4802.bWasReset = 1
    A0_4802.bOpenNow = 1
    A0_4802.user = A1_4803
    A0_4802.idx = A2_4804
  end
end
L0_4748.Open = L1_4749
L0_4748 = AdvancedDoor
function L1_4749(A0_4805, A1_4806, A2_4807)
  local L3_4808, L4_4809
  L4_4809 = A0_4805
  L3_4808 = A0_4805.GetDirectionVector
  L3_4808 = L3_4808(L4_4809, 1)
  A0_4805.impulsedir = L3_4808
  L3_4808 = A0_4805.openingrange
  if L3_4808 > 0 then
    L3_4808 = A0_4805.leftsided
    if L3_4808 == 1 then
      L3_4808 = ScaleVectorInPlace
      L4_4809 = A0_4805.impulsedir
      L3_4808(L4_4809, -1)
    end
  else
    L3_4808 = A0_4805.leftsided
    if L3_4808 == 0 then
      L3_4808 = ScaleVectorInPlace
      L4_4809 = A0_4805.impulsedir
      L3_4808(L4_4809, -1)
    end
  end
  L3_4808, L4_4809 = nil, nil
  if A1_4806 and A1_4806 == g_localActor then
    L4_4809 = A0_4805.Properties.Mass
  elseif A0_4805.bBreachNow == 1 then
    L4_4809 = A0_4805.Properties.Mass * 4
    bBreachNow = 0
  else
    L4_4809 = A0_4805.Properties.Mass
  end
  L4_4809 = L4_4809 * A0_4805.Properties.Limits.fSpeed
  A0_4805:UpdateImpulsePos()
  A0_4805:AddImpulse(-1, A0_4805.impulsepos, A0_4805.impulsedir, L4_4809, 1)
end
L0_4748.OpenDoor = L1_4749
L0_4748 = AdvancedDoor
function L1_4749(A0_4810, A1_4811, A2_4812)
  local L3_4813, L4_4814
  A0_4810.bUpdate = 1
  A0_4810.lasttime = 0
  L4_4814 = A0_4810
  L3_4813 = A0_4810.GetDirectionVector
  L3_4813 = L3_4813(L4_4814, 1)
  A0_4810.impulsedir = L3_4813
  L3_4813 = ScaleVectorInPlace
  L4_4814 = A0_4810.impulsedir
  L3_4813(L4_4814, -1)
  L3_4813 = A0_4810.openingrange
  if L3_4813 > 0 then
    L3_4813 = A0_4810.leftsided
    if L3_4813 == 1 then
      L3_4813 = ScaleVectorInPlace
      L4_4814 = A0_4810.impulsedir
      L3_4813(L4_4814, -1)
    end
  else
    L3_4813 = A0_4810.leftsided
    if L3_4813 == 0 then
      L3_4813 = ScaleVectorInPlace
      L4_4814 = A0_4810.impulsedir
      L3_4813(L4_4814, -1)
    end
  end
  L3_4813, L4_4814 = nil, nil
  if A1_4811 and A1_4811 == g_localActor then
    L4_4814 = A0_4810.Properties.Mass
  elseif A0_4810.bBreachNow == 1 then
    L4_4814 = A0_4810.Properties.Mass * 4
    bBreachNow = 0
  else
    L4_4814 = A0_4810.Properties.Mass
  end
  L4_4814 = L4_4814 * A0_4810.Properties.Limits.fSpeed
  A0_4810:UpdateImpulsePos()
  A0_4810:AddImpulse(-1, A0_4810.impulsepos, A0_4810.impulsedir, L4_4814, 1)
end
L0_4748.Close = L1_4749
L0_4748 = AdvancedDoor
function L1_4749(A0_4815, A1_4816)
  if A0_4815:GetState() ~= "Destroyed" then
    A0_4815:GetPos(A0_4815.tmp_2)
    A1_4816:GetPos(A0_4815.tmp_3)
    SubVectors(A0_4815.tmp, A0_4815.tmp_2, A0_4815.tmp_3)
    if LengthVector(A0_4815.tmp) < A0_4815.Properties.Limits.fUseDistance then
      return 2
    else
      return 0
    end
  else
    return 0
  end
end
L0_4748.IsUsable = L1_4749
L0_4748 = AdvancedDoor
function L1_4749(A0_4817, A1_4818)
  local L2_4819
  L2_4819 = A0_4817.Properties
  L2_4819 = L2_4819.bUsable
  if L2_4819 == 1 then
    L2_4819 = A0_4817.Properties
    L2_4819 = L2_4819.UseMessage
    return L2_4819
  else
    L2_4819 = "@use_door"
    return L2_4819
  end
end
L0_4748.GetUsableMessage = L1_4749
L0_4748 = AdvancedDoor
function L1_4749(A0_4820)
  local L1_4821
end
L0_4748.OnShutDown = L1_4749
L0_4748 = AdvancedDoor
function L1_4749(A0_4822)
  local L1_4823, L2_4824, L3_4825
  L1_4823 = A0_4822.Properties
  L2_4824 = A0_4822.LastHit
  L2_4824 = L2_4824.pos
  L3_4825 = A0_4822.LastHit
  L3_4825 = L3_4825.impulse
  A0_4822:BreakToPieces(0, 0, L1_4823.Breakage.fExplodeImpulse, L2_4824, L3_4825, L1_4823.Breakage.fLifeTime, L1_4823.Breakage.bSurfaceEffects)
  if NumberToBool(A0_4822.Properties.Destruction.bExplode) then
    g_gameRules:CreateExplosion(A0_4822.shooterId, A0_4822.id, A0_4822.Properties.Destruction.Damage, A0_4822:GetWorldPos(), A0_4822.Properties.Destruction.Direction, A0_4822.Properties.Destruction.Radius, nil, A0_4822.Properties.Destruction.Pressure, A0_4822.Properties.Destruction.HoleSize, A0_4822.Properties.Destruction.ParticleEffect, A0_4822.Properties.Destruction.EffectScale)
  end
  A0_4822:RemoveDecals()
  A0_4822:SetCurrentSlot(1)
  A0_4822:PhysicalizeThis(1, 1)
  A0_4822:AwakePhysics(1)
end
L0_4748.Explode = L1_4749
L0_4748 = AdvancedDoor
function L1_4749(A0_4826)
  AI.ModifySmartObjectStates(A0_4826.id, "Locked")
  A0_4826.locked = 1
end
L0_4748.Lock = L1_4749
L0_4748 = AdvancedDoor
function L1_4749(A0_4827)
  AI.ModifySmartObjectStates(A0_4827.id, "-Locked")
  A0_4827.locked = 0
end
L0_4748.Unlock = L1_4749
L0_4748 = AdvancedDoor
L0_4748 = L0_4748.Server
L1_4749 = {}
function L1_4749.OnBeginState(A0_4828)
  AI.ModifySmartObjectStates(A0_4828.id, "Destroyed-Closed,Open,Locked")
  A0_4828:Explode()
  BroadcastEvent(A0_4828, "Destroyed")
end
function L1_4749.OnUpdate(A0_4829, A1_4830)
end
function L1_4749.OnEndState(A0_4831)
  local L1_4832
end
L0_4748.Destroyed = L1_4749
L0_4748 = AdvancedDoor
L0_4748 = L0_4748.Server
L1_4749 = {}
function L1_4749.OnBeginState(A0_4833)
  if A0_4833.iAutoCloseTimer ~= nil then
    Script.KillTimer(A0_4833.iAutoCloseTimer)
    A0_4833.iAutoCloseTimer = nil
  end
  AI.ModifySmartObjectStates(A0_4833.id, "Closed-Open")
  A0_4833:PhysicalizeThis(0, 0)
  A0_4833:EnablePhysics(true)
  A0_4833:AwakePhysics(0)
  A0_4833:Activate(0)
  A0_4833.bUpdate = 0
  A0_4833.lasttime = 0
  if A0_4833.Properties.bUsePortal == 1 then
    System.ActivatePortal(A0_4833:GetWorldPos(), 0, A0_4833.id)
  end
end
function L1_4749.OnUpdate(A0_4834, A1_4835)
  A0_4834:OnUpdate()
end
function L1_4749.OnEndState(A0_4836)
  local L1_4837
end
L0_4748.Closed = L1_4749
L0_4748 = AdvancedDoor
L0_4748 = L0_4748.Server
L1_4749 = {}
function L1_4749.OnBeginState(A0_4838)
  if A0_4838.Properties.bUsePortal == 1 then
    System.ActivatePortal(A0_4838:GetWorldPos(), 1, A0_4838.id)
  end
  A0_4838.bUpdate = 1
  A0_4838.lasttime = 0
  AI.ModifySmartObjectStates(A0_4838.id, "Open-Closed")
  A0_4838:Play(1)
end
function L1_4749.OnUpdate(A0_4839, A1_4840)
  A0_4839:OnUpdate()
end
function L1_4749.OnEndState(A0_4841)
  local L1_4842
end
L0_4748.Opened = L1_4749
L0_4748 = AdvancedDoor
function L1_4749(A0_4843)
  A0_4843:Unlock()
  BroadcastEvent(A0_4843, "Unlock")
end
L0_4748.Event_Unlock = L1_4749
L0_4748 = AdvancedDoor
function L1_4749(A0_4844)
  A0_4844:Lock()
  BroadcastEvent(A0_4844, "Lock")
end
L0_4748.Event_Lock = L1_4749
L0_4748 = AdvancedDoor
function L1_4749(A0_4845)
  A0_4845.bUpdate = 1
  A0_4845.bWasReset = 1
  A0_4845:Open()
  BroadcastEvent(A0_4845, "Open")
end
L0_4748.Event_Open = L1_4749
L0_4748 = AdvancedDoor
function L1_4749(A0_4846)
  A0_4846:Close()
  BroadcastEvent(A0_4846, "Close")
end
L0_4748.Event_Close = L1_4749
L0_4748 = AdvancedDoor
function L1_4749(A0_4847)
  A0_4847.locked = 0
  A0_4847:GotoState("Destroyed")
end
L0_4748.Event_Destroyed = L1_4749
L0_4748 = AdvancedDoor
L1_4749 = {}
L1_4749.Inputs = {
  Unlock = {
    AdvancedDoor.Event_Unlock,
    "bool"
  },
  Lock = {
    AdvancedDoor.Event_Lock,
    "bool"
  },
  Open = {
    AdvancedDoor.Event_Open,
    "bool"
  },
  Close = {
    AdvancedDoor.Event_Close,
    "bool"
  },
  Destroyed = {
    AdvancedDoor.Event_Destroyed,
    "bool"
  }
}
L1_4749.Outputs = {
  Unlock = "bool",
  Lock = "bool",
  Open = "bool",
  Close = "bool",
  Destroyed = "bool",
  Breached = "bool"
}
L0_4748.FlowEvents = L1_4749
