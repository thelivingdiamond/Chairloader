local L0_10069, L1_10070
L0_10069 = {}
L1_10070 = {}
L0_10069.gravityNodes = L1_10070
GravityGlobals = L0_10069
L0_10069 = GravityGlobals
function L1_10070(A0_10071, A1_10072)
  local L2_10073
  if not A1_10072 then
    return
  end
  L2_10073 = table
  L2_10073 = L2_10073.getn
  L2_10073 = L2_10073(A0_10071.gravityNodes)
  for _FORV_6_ = 1, L2_10073 do
    if A0_10071.gravityNodes[_FORV_6_] and A0_10071.gravityNodes[_FORV_6_].id == A1_10072.id then
      if A1_10072.GetName then
        System.Log(A1_10072:GetName() .. "removed from the gravity array!")
      end
      A0_10071.gravityNodes[_FORV_6_] = nil
      return
    end
  end
end
L0_10069.RemoveGravityArea = L1_10070
L0_10069 = GravityGlobals
function L1_10070(A0_10074, A1_10075)
  local L2_10076
  if not A1_10075 then
    return
  end
  L2_10076 = table
  L2_10076 = L2_10076.getn
  L2_10076 = L2_10076(A0_10074.gravityNodes)
  for _FORV_6_ = 1, L2_10076 do
    if A0_10074.gravityNodes[_FORV_6_] and A0_10074.gravityNodes[_FORV_6_].id == A1_10075.id then
      return
    end
  end
  for _FORV_6_ = 1, L2_10076 do
    if A0_10074.gravityNodes[_FORV_6_] == nil then
      A0_10074.gravityNodes[_FORV_6_] = A1_10075
      return
    end
  end
  A0_10074.gravityNodes[L2_10076 + 1] = A1_10075
end
L0_10069.AddGravityArea = L1_10070
L0_10069 = GravityGlobals
function L1_10070(A0_10077, A1_10078)
  local L2_10079, L3_10080, L4_10081
  L2_10079 = table
  L2_10079 = L2_10079.getn
  L3_10080 = A0_10077.gravityNodes
  L2_10079 = L2_10079(L3_10080)
  L3_10080, L4_10081 = nil, nil
  for _FORV_8_ = 1, L2_10079 do
    L3_10080 = A0_10077.gravityNodes[_FORV_8_]
    if L3_10080 and L3_10080.GetPos and L3_10080.GetPosGravity then
      if L3_10080:GetPosGravity(A1_10078) and (not L4_10081 or L4_10081 < L3_10080:GetPosGravity(A1_10078)) then
        L4_10081 = L3_10080:GetPosGravity(A1_10078)
      end
    elseif L3_10080 then
      A0_10077.gravityNodes[_FORV_8_] = nil
    end
  end
  return L4_10081
end
L0_10069.GetPosGravity = L1_10070
function L0_10069(A0_10082)
  local L1_10083, L2_10084, L3_10085, L4_10086, L5_10087
  L1_10083 = GravityGlobals
  if L1_10083 then
    L1_10083 = 0
    L2_10084 = g_Vectors
    L2_10084 = L2_10084.temp_v1
    L3_10085 = CopyVector
    L4_10086 = L2_10084
    L5_10087 = A0_10082.GetPos
    L5_10087 = L5_10087(A0_10082)
    L3_10085(L4_10086, L5_10087, L5_10087(A0_10082))
    L3_10085 = nil
    L4_10086 = GravityGlobals
    L5_10087 = L4_10086
    L4_10086 = L4_10086.GetPosGravity
    L4_10086 = L4_10086(L5_10087, L2_10084)
    if L4_10086 then
      L5_10087 = A0_10082.SaveLastGravity
      if L5_10087 == nil then
        L5_10087 = A0_10082.GetPhysicalStats
        L5_10087 = L5_10087(A0_10082)
        A0_10082:AwakePhysics(1)
        A0_10082.SaveLastGravity = L5_10087.gravity
        if math.abs(L4_10086) < 9.81 then
          L1_10083 = L5_10087.mass
          if L1_10083 then
            L1_10083 = L1_10083 * 1
          else
            L1_10083 = 0
          end
        end
      end
      L5_10087 = A0_10082.TempPhysicsParams
      if L5_10087 == nil then
        L5_10087 = {}
        L5_10087.gravityz = -9.81
        L5_10087.freefall_gravityz = -9.81
        L5_10087.lying_gravityz = -9.81
        L5_10087.zeroG = 0
        L5_10087.air_control = 0
        A0_10082.TempPhysicsParams = L5_10087
      end
      L3_10085 = L4_10086
    else
      L5_10087 = A0_10082.SaveLastGravity
      if L5_10087 then
        L3_10085 = A0_10082.SaveLastGravity
        A0_10082.SaveLastGravity = nil
      end
    end
    if L3_10085 then
      L5_10087 = A0_10082.SaveLastGravity
      if L5_10087 then
        L5_10087 = A0_10082.SaveLastGravity
        L5_10087 = L5_10087 / -9.81
        L3_10085 = L3_10085 * L5_10087
      end
      L5_10087 = A0_10082.TempPhysicsParams
      L5_10087.gravityz = L3_10085
      L5_10087.freefall_gravityz = L3_10085
      L5_10087.lying_gravityz = L3_10085
      if A0_10082.type == "Player" and A0_10082.isDedbody ~= 1 then
        L5_10087.gravity = -L3_10085
        A0_10082:SetPhysicParams(PHYSICPARAM_PLAYERDYN, L5_10087)
      elseif A0_10082.IsProjectile then
        if not L5_10087.gravity then
          L5_10087.gravity = {
            x = 0,
            y = 0,
            z = L3_10085
          }
        else
          L5_10087.gravity.z = L3_10085
        end
        A0_10082:SetPhysicParams(PHYSICPARAM_PARTICLE, L5_10087)
      else
        A0_10082:SetPhysicParams(PHYSICPARAM_SIMULATION, L5_10087)
      end
    end
    if L1_10083 > 0 then
      L5_10087 = A0_10082.AddImpulse
      L5_10087(A0_10082, -1, L2_10084, g_Vectors.v001, L1_10083)
    end
  end
end
EntityUpdateGravity = L0_10069
