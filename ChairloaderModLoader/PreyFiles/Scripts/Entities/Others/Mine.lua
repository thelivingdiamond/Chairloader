local L0_6973, L1_6974
L0_6973 = {}
L1_6974 = {}
L0_6973.Client = L1_6974
L1_6974 = {}
L0_6973.Server = L1_6974
L1_6974 = {}
L1_6974.fileModel = "engine/engineassets/objects/default.cgf"
L1_6974.Radius = 2
L1_6974.bAdjustToTerrain = 1
L1_6974.Options = {
  fDisarmDistance = 0.5,
  fMinTriggerWeight = 50,
  bNoVehicles = 0,
  bWaterMine = 0
}
L1_6974.FrogMine = {
  bIsFrogMine = 0,
  fJumpHeight = 2.5,
  bJumpWhenShot = 1,
  fDetonationDelay = 0.75
}
L1_6974.Claymore = {
  bIsClaymore = 0,
  fCone = 45,
  bCenterExplosion = 1,
  fDamage = 100
}
L1_6974.Destruction = {
  ParticleEffect = "explosions.rocket.soil",
  EffectScale = 0.2,
  Radius = 5,
  Pressure = 2500,
  Damage = 500,
  Direction = {
    x = 0,
    y = 0,
    z = -1
  }
}
L1_6974.Vulnerability = {
  fDamageTreshold = 0,
  bExplosion = 1,
  bCollision = 1,
  bMelee = 1,
  bBullet = 1,
  bOther = 1
}
L0_6973.Properties = L1_6974
L1_6974 = {}
L1_6974.impulse = {
  x = 0,
  y = 0,
  z = 0
}
L1_6974.pos = {
  x = 0,
  y = 0,
  z = 0
}
L0_6973.LastHit = L1_6974
L1_6974 = {}
L1_6974.Icon = "mine.bmp"
L1_6974.IconOnTop = 1
L1_6974.ShowBounds = 1
L0_6973.Editor = L1_6974
L1_6974 = {
  "Deactivated",
  "Armed",
  "Disarmed",
  "Destroyed"
}
L0_6973.States = L1_6974
Mine = L0_6973
L0_6973 = 1
MINE_CHECK = L0_6973
L0_6973 = 2
MINE_JUMP = L0_6973
L0_6973 = Mine
function L1_6974(A0_6975)
  local L1_6976, L2_6977, L3_6978, L4_6979
  L1_6976 = A0_6975.Properties
  L2_6977 = EmptyString
  L3_6978 = L1_6976.fileModel
  L2_6977 = L2_6977(L3_6978)
  if not L2_6977 then
    L3_6978 = A0_6975
    L2_6977 = A0_6975.LoadObject
    L4_6979 = 0
    L2_6977(L3_6978, L4_6979, L1_6976.fileModel)
  end
  L2_6977 = {}
  L3_6978 = L1_6976.Radius
  L3_6978 = -L3_6978
  L3_6978 = L3_6978 / 2
  L2_6977.x = L3_6978
  L3_6978 = L1_6976.Radius
  L3_6978 = -L3_6978
  L3_6978 = L3_6978 / 2
  L2_6977.y = L3_6978
  L2_6977.z = -1.25
  L3_6978 = {}
  L4_6979 = L1_6976.Radius
  L4_6979 = L4_6979 / 2
  L3_6978.x = L4_6979
  L4_6979 = L1_6976.Radius
  L4_6979 = L4_6979 / 2
  L3_6978.y = L4_6979
  L3_6978.z = 1.25
  L4_6979 = A0_6975.SetTriggerBBox
  L4_6979(A0_6975, L2_6977, L3_6978)
  L4_6979 = EntityCommon
  L4_6979 = L4_6979.PhysicalizeRigid
  L4_6979(A0_6975, 0, A0_6975.physics, 0)
  L4_6979 = A0_6975.SetCurrentSlot
  L4_6979(A0_6975, 0)
  L4_6979 = A0_6975.Properties
  L4_6979 = L4_6979.Claymore
  L4_6979 = L4_6979.bIsClaymore
  if L4_6979 == 0 then
    L4_6979 = A0_6975.Properties
    L4_6979 = L4_6979.Options
    L4_6979 = L4_6979.bWaterMine
    if L4_6979 == 0 then
    end
  end
  A0_6975.health = 1
  L4_6979 = {}
  A0_6975.ents = L4_6979
  L4_6979 = A0_6975.Properties
  L4_6979 = L4_6979.bAdjustToTerrain
  if L4_6979 == 1 then
    L4_6979 = A0_6975.Properties
    L4_6979 = L4_6979.Claymore
    L4_6979 = L4_6979.bIsClaymore
    if L4_6979 == 0 then
      L4_6979 = {}
      L4_6979.x = 0
      L4_6979.y = 0
      L4_6979.z = 0
      CopyVector(L4_6979, A0_6975:GetPos())
      L4_6979.z = System.GetTerrainElevation(A0_6975:GetPos()) - 0.01
      A0_6975:SetPos(L4_6979)
    end
  end
  L4_6979 = A0_6975.GotoState
  L4_6979(A0_6975, "Armed")
end
L0_6973.OnReset = L1_6974
L0_6973 = Mine
function L1_6974(A0_6980, A1_6981)
  local L2_6982
  L2_6982 = A0_6980.health
  A1_6981.health = L2_6982
  L2_6982 = A0_6980.ents
  A1_6981.ents = L2_6982
  L2_6982 = A0_6980.disarmed
  A1_6981.disarmed = L2_6982
end
L0_6973.OnSave = L1_6974
L0_6973 = Mine
function L1_6974(A0_6983, A1_6984)
  A0_6983.health = A1_6984.health
  A0_6983.ents = A1_6984.ents
  A0_6983.disarmed = A1_6984.disarmed
  EntityCommon.PhysicalizeRigid(A0_6983, 0, A0_6983.physics, 0)
  A0_6983:SetCurrentSlot(0)
end
L0_6973.OnLoad = L1_6974
L0_6973 = Mine
function L1_6974(A0_6985)
  A0_6985:OnReset()
end
L0_6973.OnPropertyChange = L1_6974
L0_6973 = Mine
L0_6973 = L0_6973.Server
function L1_6974(A0_6986)
  local L1_6987
  L1_6987 = A0_6986.Properties
  L1_6987 = L1_6987.FrogMine
  if L1_6987.bIsFrogMine == 1 then
    A0_6986.physics = {
      bRigidBody = 1,
      bRigidBodyActive = 1,
      bResting = 1,
      Density = -1,
      Mass = 20
    }
  else
    A0_6986.physics = {
      bRigidBody = 0,
      bRigidBodyActive = 0,
      bResting = 1,
      Density = -1,
      Mass = 20
    }
  end
  A0_6986.health = 1
  A0_6986.ents = {}
  A0_6986.disarmed = 0
  A0_6986.tmp = {
    x = 0,
    y = 0,
    z = 0
  }
  A0_6986.tmp_2 = {
    x = 0,
    y = 0,
    z = 0
  }
  A0_6986.tmp_3 = {
    x = 0,
    y = 0,
    z = 0
  }
  A0_6986:OnReset()
end
L0_6973.OnInit = L1_6974
L0_6973 = Mine
function L1_6974(A0_6988, A1_6989)
  if A0_6988:GetState() ~= "Destroyed" and A0_6988:GetState() ~= "Disarmed" then
    A0_6988:GetPos(A0_6988.tmp_2)
    A1_6989:GetPos(A0_6988.tmp_3)
    SubVectors(A0_6988.tmp, A0_6988.tmp_2, A0_6988.tmp_3)
    if LengthVector(A0_6988.tmp) < A0_6988.Properties.Options.fDisarmDistance then
      return 2
    else
      return 0
    end
  else
    return 0
  end
end
L0_6973.IsUsable = L1_6974
L0_6973 = Mine
function L1_6974(A0_6990, A1_6991)
  local L2_6992
  L2_6992 = "Press USE to disarm!"
  return L2_6992
end
L0_6973.GetUsableMessage = L1_6974
L0_6973 = Mine
function L1_6974(A0_6993)
  A0_6993:GotoState("Disarmed")
end
L0_6973.OnUsed = L1_6974
L0_6973 = Mine
L0_6973 = L0_6973.Server
function L1_6974(A0_6994, A1_6995)
  local L2_6996, L3_6997
  L3_6997 = A0_6994
  L2_6996 = A0_6994.GetState
  L2_6996 = L2_6996(L3_6997)
  if L2_6996 ~= "Disarmed" then
    L3_6997 = A0_6994
    L2_6996 = A0_6994.GetState
    L2_6996 = L2_6996(L3_6997)
    if L2_6996 ~= "Destroyed" then
      L3_6997 = A0_6994
      L2_6996 = A0_6994.GetState
      L2_6996 = L2_6996(L3_6997)
    end
  elseif L2_6996 == "Deactivated" then
    return
  end
  L2_6996 = A0_6994.Properties
  L2_6996 = L2_6996.Vulnerability
  L3_6997 = A1_6995.damage
  L3_6997 = L3_6997 >= A0_6994.Properties.Vulnerability.fDamageTreshold
  if L3_6997 and A1_6995.explosion then
    L3_6997 = NumberToBool(L2_6996.bExplosion)
    if A1_6995.shooterId and System.GetEntityClass(A1_6995.shooterId) == "Mine" then
      L3_6997 = false
    end
  elseif L3_6997 and A1_6995.type == "collision" then
    L3_6997 = NumberToBool(L2_6996.bCollision)
  elseif L3_6997 and A1_6995.type == "bullet" then
    L3_6997 = NumberToBool(L2_6996.bBullet)
  elseif L3_6997 and A1_6995.type == "melee" then
    L3_6997 = NumberToBool(L2_6996.bMelee)
  else
    L3_6997 = L3_6997 and NumberToBool(L2_6996.bOther)
  end
  if L3_6997 then
    A0_6994.shooterId = A1_6995.shooterId
    A0_6994.health = A0_6994.health - A1_6995.damage
    if A0_6994.health <= 0 then
      A0_6994:GotoState("Destroyed")
    end
  end
end
L0_6973.OnHit = L1_6974
L0_6973 = Mine
function L1_6974(A0_6998)
  if A0_6998.health <= 0 then
    return true
  else
    return false
  end
end
L0_6973.IsDead = L1_6974
L0_6973 = Mine
function L1_6974(A0_6999, A1_7000)
  if A1_7000 == 0 then
    A0_6999:DrawSlot(0, 1)
    A0_6999:DrawSlot(1, 0)
  else
    A0_6999:DrawSlot(0, 0)
    A0_6999:DrawSlot(1, 1)
  end
  A0_6999.currentSlot = A1_7000
end
L0_6973.SetCurrentSlot = L1_6974
L0_6973 = Mine
function L1_6974(A0_7001)
  local L1_7002, L2_7003, L3_7004, L4_7005
  L2_7003 = A0_7001
  L1_7002 = A0_7001.Hide
  L3_7004 = 1
  L1_7002(L2_7003, L3_7004)
  L1_7002 = A0_7001.Properties
  L2_7003 = L1_7002.Destruction
  L3_7004 = L2_7003.Radius
  L4_7005 = L1_7002.FrogMine
  L4_7005 = L4_7005.bIsFrogMine
  if L4_7005 == 1 then
    L3_7004 = L3_7004 + 1.5
  end
  L4_7005 = L1_7002.Claymore
  L4_7005 = L4_7005.bIsClaymore
  if L4_7005 == 0 then
    L4_7005 = g_gameRules
    L4_7005 = L4_7005.CreateExplosion
    L4_7005(L4_7005, A0_7001.id, A0_7001.id, L2_7003.Damage, A0_7001:GetWorldPos(), L2_7003.Direction, L3_7004, nil, L2_7003.Pressure, L2_7003.HoleSize, L2_7003.ParticleEffect, L2_7003.EffectScale)
  else
    L4_7005 = L1_7002.Claymore
    L4_7005 = L4_7005.fCone
    L4_7005 = L4_7005 * g_Deg2Rad
    if L1_7002.Claymore.bCenterExplosion == 1 then
      g_gameRules:CreateExplosion(A0_7001.id, A0_7001.id, L2_7003.Damage, A0_7001:GetWorldPos(), L2_7003.Direction, 1, nil, 0, 0, "", L2_7003.EffectScale)
    end
    g_gameRules:CreateExplosion(A0_7001.id, A0_7001.id, L2_7003.Damage, A0_7001:GetWorldPos(), A0_7001:GetDirectionVector(1), L3_7004, L4_7005, L2_7003.Pressure, L2_7003.HoleSize, L2_7003.ParticleEffect, L2_7003.EffectScale)
  end
end
L0_6973.Explode = L1_6974
L0_6973 = Mine
function L1_6974(A0_7006)
  local L1_7007, L2_7008, L3_7009
  L1_7007 = EntityCommon
  L1_7007 = L1_7007.PhysicalizeRigid
  L2_7008 = A0_7006
  L3_7009 = 0
  L1_7007(L2_7008, L3_7009, A0_7006.physics, 1)
  L1_7007 = math
  L1_7007 = L1_7007.sqrt
  L2_7008 = A0_7006.Properties
  L2_7008 = L2_7008.FrogMine
  L2_7008 = L2_7008.fJumpHeight
  L2_7008 = 19.62 * L2_7008
  L1_7007 = L1_7007(L2_7008)
  L2_7008 = 20 * L1_7007
  L3_7009 = g_Vectors
  L3_7009 = L3_7009.v000
  CopyVector(L3_7009, A0_7006:GetPos())
  L3_7009.x = L3_7009.x + 0.005
  A0_7006:AddImpulse(-1, L3_7009, {
    x = 0,
    y = 0,
    z = 1
  }, L2_7008, 1)
  A0_7006:SetTimer(MINE_JUMP, A0_7006.Properties.FrogMine.fDetonationDelay * 1000)
end
L0_6973.Jump = L1_6974
L0_6973 = Mine
function L1_6974(A0_7010)
  local L1_7011, L2_7012, L3_7013, L4_7014, L5_7015, L6_7016, L7_7017, L8_7018, L9_7019, L10_7020
  L2_7012 = {}
  L2_7012.x = 0
  L2_7012.y = 0
  L2_7012.z = 0
  L3_7013 = nil
  L4_7014 = A0_7010.Properties
  L4_7014 = L4_7014.Options
  for L8_7018, L9_7019 in L5_7015(L6_7016) do
    if L9_7019 ~= nil then
      L10_7020 = L9_7019.GetMass
      L10_7020 = L10_7020(L9_7019)
      if L10_7020 < L4_7014.fMinTriggerWeight then
        break
      else
        L10_7020 = L4_7014.bNoVehicles
        if L10_7020 == 1 then
          L10_7020 = L9_7019.vehicle
          if L10_7020 ~= nil then
            break
          end
        end
      end
      L10_7020 = A0_7010.Properties
      L10_7020 = L10_7020.Options
      L10_7020 = L10_7020.bWaterMine
      if L10_7020 == 0 then
        L10_7020 = {}
        L10_7020.x = 0
        L10_7020.y = 0
        L10_7020.z = 0
        L9_7019:GetVelocity(L10_7020)
        L1_7011 = LengthVector(L10_7020)
        A0_7010:GetPos(A0_7010.tmp)
        L9_7019:GetPos(A0_7010.tmp_2)
        SubVectors(L2_7012, A0_7010.tmp_2, A0_7010.tmp_2)
        L3_7013 = LengthVector(L2_7012)
        if L1_7011 > 0.55 * (1 + L3_7013 / 2.5) then
          A0_7010:GotoState("Destroyed")
          break
        end
      else
        L10_7020 = L9_7019.IsEntityInside
        L10_7020 = L10_7020(L9_7019, A0_7010.id)
        if L10_7020 then
          L10_7020 = A0_7010.GotoState
          L10_7020(A0_7010, "Destroyed")
          break
        end
      end
    end
  end
  if L5_7015 ~= 0 then
    L8_7018 = 100
    L5_7015(L6_7016, L7_7017, L8_7018)
  end
end
L0_6973.CheckEntities = L1_6974
L0_6973 = Mine
function L1_6974(A0_7021)
  A0_7021:GotoState("Disarmed")
  BroadcastEvent(A0_7021, "Disarmed")
end
L0_6973.Event_Disarmed = L1_6974
L0_6973 = Mine
function L1_6974(A0_7022)
  A0_7022:GotoState("Destroyed")
  BroadcastEvent(A0_7022, "Detonated")
end
L0_6973.Event_Detonated = L1_6974
L0_6973 = Mine
function L1_6974(A0_7023)
  if A0_7023.disarmed == 0 then
    A0_7023:GotoState("Armed")
  end
  BroadcastEvent(A0_7023, "Activated")
end
L0_6973.Event_Activated = L1_6974
L0_6973 = Mine
function L1_6974(A0_7024)
  A0_7024:GotoState("Deactivated")
  BroadcastEvent(A0_7024, "Deactivated")
end
L0_6973.Event_Deactivated = L1_6974
L0_6973 = Mine
L0_6973 = L0_6973.Server
L1_6974 = {}
L0_6973.Deactivated = L1_6974
L0_6973 = Mine
L0_6973 = L0_6973.Server
L1_6974 = {}
function L1_6974.OnBeginState(A0_7025)
  if A0_7025.Properties.Claymore.bIsClaymore ~= 0 or A0_7025.Properties.Options.bWaterMine == 0 then
  end
  BroadcastEvent(A0_7025, "Armed")
end
function L1_6974.OnEnterArea(A0_7026, A1_7027, A2_7028)
  if A1_7027 and A1_7027:GetMass() >= A0_7026.Properties.Options.fMinTriggerWeight then
    if A1_7027.actor then
      table.insert(A0_7026.ents, A1_7027)
      A0_7026:SetTimer(MINE_CHECK, 100)
    else
      A0_7026:GotoState("Destroyed")
    end
  end
end
function L1_6974.OnLeaveArea(A0_7029, A1_7030, A2_7031)
  local L3_7032, L4_7033, L5_7034, L6_7035
  for L6_7035, _FORV_7_ in L3_7032(L4_7033) do
    if _FORV_7_ == A1_7030 then
      table.remove(A0_7029.ents, L6_7035)
      break
    end
  end
end
function L1_6974.OnTimer(A0_7036, A1_7037)
  if A1_7037 == MINE_CHECK then
    A0_7036:CheckEntities()
  end
end
L0_6973.Armed = L1_6974
L0_6973 = Mine
L0_6973 = L0_6973.Server
L1_6974 = {}
function L1_6974.OnBeginState(A0_7038)
  local L1_7039, L2_7040, L3_7041, L4_7042
  A0_7038.disarmed = 1
  for L4_7042, _FORV_5_ in L1_7039(L2_7040) do
    table.remove(A0_7038.ents, L4_7042)
  end
  L1_7039(L2_7040, L3_7041)
end
L0_6973.Disarmed = L1_6974
L0_6973 = Mine
L0_6973 = L0_6973.Server
L1_6974 = {}
function L1_6974.OnBeginState(A0_7043)
  local L1_7044
  L1_7044 = A0_7043.Properties
  L1_7044 = L1_7044.FrogMine
  if L1_7044.bIsFrogMine == 1 then
    if A0_7043:IsDead() then
      if not L1_7044.bJumpWhenShot then
        A0_7043:Explode()
      else
        A0_7043:Jump()
      end
    else
      A0_7043:Jump()
    end
  else
    A0_7043:Explode()
  end
  BroadcastEvent(A0_7043, "Detonated")
end
function L1_6974.OnTimer(A0_7045, A1_7046)
  if A1_7046 == MINE_JUMP then
    A0_7045:Explode()
  end
end
L0_6973.Destroyed = L1_6974
L0_6973 = Mine
L1_6974 = {}
L1_6974.Inputs = {
  Detonated = {
    Mine.Event_Detonated,
    "bool"
  },
  Disarmed = {
    Mine.Event_Disarmed,
    "bool"
  },
  Activated = {
    Mine.Event_Activated,
    "bool"
  },
  Deactivated = {
    Mine.Event_Deactivated,
    "bool"
  }
}
L1_6974.Outputs = {
  Detonated = "bool",
  Disarmed = "bool",
  Activated = "bool",
  Deactivated = "bool"
}
L0_6973.FlowEvents = L1_6974
