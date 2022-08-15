Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkFogWall = {
  Properties = {
    object_Model = "",
    fReverseSpeedScale = -1,
    nGrowthInterval = 100,
    nHaltDuration = 100,
    nUpdateRate = 100,
    fSpeed = 1,
    archetype_Tentacle = "",
    signalPackage_ApexFog = "",
    Sound = {audioTrigger_ExistStart = "", audioTrigger_ExistStop = ""},
    Physics = {
      bPhysicalize = 0,
      bRigidBody = 0,
      bPushableByPlayers = 0,
      bPushableByAI = 0,
      Density = -1,
      Mass = -1
    }
  },
  PropertiesInstance = {
    bGrowTentacles = 0,
    nMaxTentacles = 5,
    fRadius = 1,
    fPortalWidth = 5,
    fPortalHeight = 5,
    fLongitude = 0,
    fLatitude = 0
  },
  Editor = {
    Icon = "physicsobject.bmp",
    IconOnTop = 1
  }
}
ArkFogWallInstanceVars = {
  m_audioIds = {},
  m_bVerbose = false,
  m_bInit = false,
  m_tentacles = false,
  m_waypoints = false,
  m_haltedTimer = false,
  m_growthTimer = false,
  m_bWantsToGrow = true,
  m_direction = 1,
  m_waypointsCount = 0,
  m_latitude = 0,
  m_longitude = 0,
  m_updateRate = 0,
  m_updateIdx = 1,
  m_startPos = ConstVec({
    x = 0,
    y = 0,
    z = 0
  }),
  m_currentPos = ConstVec({
    x = 0,
    y = 0,
    z = 0
  })
}
GetArkEntityUtils(ArkFogWall)
function CreateFogWallInstance(A0_3873)
  mergef(A0_3873, ArkFogWallInstanceVars, 1)
  A0_3873.m_referenceTable = ArkFogWallInstanceVars
end
function ArkFogWall.Init(A0_3874, A1_3875)
  A0_3874:GetWorldPos(A0_3874.m_startPos)
  A0_3874.m_currentPos = NewVector(A0_3874.m_startPos)
  A0_3874:SetFromProperties()
  if not A0_3874.m_bInit and A1_3875 then
    GetAudioIds(A0_3874.Properties.Sound, A0_3874.m_audioIds)
    A0_3874.m_tentacles = {}
    A0_3874:GetLinkedWaypoints()
    A0_3874:SetScriptUpdateRate(A0_3874.Properties.nUpdateRate)
    A0_3874:Activate(1)
    A0_3874:ExecuteAudioTrigger(A0_3874.m_audioIds.audioTrigger_ExistStart, A0_3874:GetDefaultAuxAudioProxyID())
  end
end
function ArkFogWall.SetFromProperties(A0_3876)
  local L1_3877
  L1_3877 = A0_3876.PropertiesInstance
  A0_3876.m_latitude = L1_3877.fLatitude * g_Deg2Rad
  A0_3876.m_longitude = L1_3877.fLongitude * g_Deg2Rad
  A0_3876.m_width = L1_3877.fPortalWidth * g_Deg2Rad
  A0_3876.m_height = L1_3877.fPortalHeight * g_Deg2Rad
  A0_3876.m_updateRate = A0_3876.Properties.nUpdateRate
  A0_3876:SetupModelAndPhysics()
  A0_3876:SetSlotScale(0, L1_3877.fRadius)
  EntityCommon.PhysicalizeRigid(A0_3876, 0, A0_3876.Properties.Physics, 0, PE_NONE)
end
function ArkFogWall.GetLinkedWaypoints(A0_3878)
  local L1_3879, L2_3880, L3_3881, L4_3882
  L2_3880 = A0_3878
  L1_3879 = A0_3878.CountLinks
  L1_3879 = L1_3879(L2_3880)
  A0_3878.m_waypointsCount = L1_3879
  L1_3879 = 0
  L2_3880 = {}
  while true do
    L3_3881 = A0_3878.m_waypointsCount
    if L1_3879 < L3_3881 then
      L4_3882 = A0_3878
      L3_3881 = A0_3878.GetLink
      L3_3881 = L3_3881(L4_3882, L1_3879)
      L4_3882 = L3_3881.GetWorldPos
      L4_3882 = L4_3882(L3_3881)
      table.insert(L2_3880, L4_3882)
      L1_3879 = L1_3879 + 1
    end
  end
  A0_3878.m_waypoints = L2_3880
end
function ArkFogWall.GetNumTentacles(A0_3883)
  if A0_3883.m_tentacles then
    return #A0_3883.m_tentacles
  else
    return math.random(0, A0_3883.PropertiesInstance.nMaxTentacles)
  end
end
function ArkFogWall.KillTentacles(A0_3884)
  if A0_3884.m_tentacles then
    for _FORV_4_, _FORV_5_ in ipairs(A0_3884.m_tentacles) do
      _FORV_5_:DeleteThis()
    end
    A0_3884.m_tentacles = false
  end
end
function ArkFogWall.DrawPortalCorners(A0_3885)
  local L1_3886, L2_3887, L3_3888, L4_3889, L5_3890, L6_3891
  L1_3886 = A0_3885.PropertiesInstance
  L2_3887 = g_Vectors
  L2_3887 = L2_3887.v100
  L3_3888 = g_Vectors
  L3_3888 = L3_3888.v010
  L4_3889 = g_Vectors
  L4_3889 = L4_3889.v001
  L5_3890 = NewVector
  L6_3891 = g_Vectors
  L6_3891 = L6_3891.v010
  L5_3890 = L5_3890(L6_3891)
  L6_3891 = NewVector
  L6_3891 = L6_3891(g_Vectors.v010)
  RotateVectorAroundR(L5_3890, L3_3888, L2_3887, A0_3885.m_latitude)
  RotateVectorAroundR(L5_3890, L5_3890, L4_3889, A0_3885.m_longitude)
  RotateVectorAroundR(L6_3891, L3_3888, L2_3887, A0_3885.m_latitude + A0_3885.m_height)
  RotateVectorAroundR(L6_3891, L6_3891, L4_3889, A0_3885.m_longitude + A0_3885.m_width)
  ScaleVectorInPlace(L6_3891, L1_3886.fRadius)
  ScaleVectorInPlace(L5_3890, L1_3886.fRadius)
  FastSumVectors(L6_3891, L6_3891, A0_3885.m_currentPos)
  FastSumVectors(L5_3890, L5_3890, A0_3885.m_currentPos)
  CryAction.PersistantSphere(L5_3890, 0.25, g_Vectors.v101, "latLon", 3)
  CryAction.PersistantSphere(L6_3891, 0.25, g_Vectors.v010, "portal", 3)
end
function ArkFogWall.GetTentacleSpawnPos(A0_3892, A1_3893)
  local L2_3894, L3_3895, L4_3896, L5_3897, L6_3898, L7_3899, L8_3900, L9_3901, L10_3902
  L2_3894 = A0_3892.PropertiesInstance
  L3_3895 = g_Vectors
  L3_3895 = L3_3895.v100
  L4_3896 = g_Vectors
  L4_3896 = L4_3896.v010
  L5_3897 = g_Vectors
  L5_3897 = L5_3897.v001
  L6_3898 = A0_3892.m_width
  L7_3899 = clamp
  L9_3901 = A0_3892
  L8_3900 = A0_3892.GetNumTentacles
  L8_3900 = L8_3900(L9_3901)
  L9_3901 = 0.25
  L10_3902 = L2_3894.nMaxTentacles
  L10_3902 = L10_3902 - 0.25
  L7_3899 = L7_3899(L8_3900, L9_3901, L10_3902)
  L8_3900 = L2_3894.nMaxTentacles
  L7_3899 = L7_3899 / L8_3900
  L6_3898 = L6_3898 * L7_3899
  L7_3899 = A0_3892.m_height
  L8_3900 = math
  L8_3900 = L8_3900.random
  L8_3900 = L8_3900()
  L7_3899 = L7_3899 * L8_3900
  L8_3900 = false
  L9_3901 = NewVector
  L10_3902 = g_Vectors
  L10_3902 = L10_3902.v010
  L9_3901 = L9_3901(L10_3902)
  L10_3902 = NewVector
  L10_3902 = L10_3902(g_Vectors.v010)
  RotateVectorAroundR(L9_3901, L4_3896, L3_3895, A0_3892.m_latitude)
  RotateVectorAroundR(L9_3901, L9_3901, L5_3897, A0_3892.m_longitude)
  RotateVectorAroundR(L10_3902, L4_3896, L3_3895, A0_3892.m_latitude + L7_3899)
  RotateVectorAroundR(L10_3902, L10_3902, L5_3897, A0_3892.m_longitude + L6_3898)
  L8_3900 = NewVector(L10_3902)
  ScaleVectorInPlace(L10_3902, L2_3894.fRadius * A1_3893)
  FastSumVectors(L10_3902, L10_3902, A0_3892.m_currentPos)
  CryAction.PersistantSphere(L10_3902, 0.25, g_Vectors.v111, "tPos", 3)
  return L10_3902, L8_3900
end
function ArkFogWall.AddTentacle(A0_3903, A1_3904, A2_3905)
  local L3_3906, L4_3907
  L4_3907 = A0_3903
  L3_3906 = A0_3903.Log
  L3_3906(L4_3907, "Spawning tentacle!")
  L3_3906 = {}
  L4_3907 = A0_3903.Properties
  L4_3907 = L4_3907.archetype_Tentacle
  L3_3906.archetype = L4_3907
  L3_3906.class = "ArkTentacle"
  L4_3907 = A0_3903.GetName
  L4_3907 = L4_3907(A0_3903)
  L4_3907 = L4_3907 .. "Tentacle"
  L3_3906.name = L4_3907
  L4_3907 = System
  L4_3907 = L4_3907.SpawnEntity
  L4_3907 = L4_3907(L3_3906)
  table.insert(A0_3903.m_tentacles, L4_3907)
  L4_3907:SetWorldPos(A1_3904)
  L4_3907:SetDirectionVector(A2_3905)
  L4_3907:Init(true)
end
function ArkFogWall.TryToGrowTentacle(A0_3908)
  if A0_3908.m_bWantsToGrow then
    A0_3908.m_bWantsToGrow = false
    if A0_3908.PropertiesInstance.bGrowTentacles == 1 then
      A0_3908:AddTentacle(A0_3908:GetTentacleSpawnPos(0.8))
      A0_3908.m_updateRate = A0_3908.Properties.nUpdateRate / A0_3908:GetNumTentacles()
      A0_3908:SetScriptUpdateRate(A0_3908.m_updateRate)
    else
      A0_3908:KillTentacles()
      A0_3908:GetTentacleSpawnPos(1)
      A0_3908:DrawPortalCorners()
    end
    A0_3908.m_growthTimer = Script.SetTimer(A0_3908.Properties.nGrowthInterval, function()
      _UPVALUE0_:ResetGrowthTimer()
    end)
  end
end
function ArkFogWall.ResetGrowthTimer(A0_3909)
  local L1_3910, L2_3911
  L1_3910 = A0_3909.m_tentacles
  if L1_3910 then
    L1_3910 = A0_3909.m_tentacles
    L1_3910 = #L1_3910
    L2_3911 = A0_3909.PropertiesInstance
    L2_3911 = L2_3911.nMaxTentacles
    if L1_3910 < L2_3911 then
      A0_3909.m_bWantsToGrow = true
    end
  else
    A0_3909.m_bWantsToGrow = true
  end
end
function ArkFogWall.GetNextWaypoint(A0_3912)
  return A0_3912.m_waypoints[A0_3912.m_waypointsCount]
end
function ArkFogWall.StopAdvancing(A0_3913)
  A0_3913.m_direction = A0_3913.Properties.fReverseSpeedScale
  A0_3913:KillTimer(A0_3913.m_haltedTimer)
  A0_3913.m_haltedTimer = Script.SetTimer(A0_3913.Properties.nHaltDuration, function()
    local L1_3914
    L1_3914 = _UPVALUE0_
    L1_3914.m_direction = 1
  end)
end
function ArkFogWall.UpdatePositionAndVelocity(A0_3915, A1_3916)
  local L2_3917, L3_3918, L4_3919, L5_3920
  L3_3918 = A0_3915
  L2_3917 = A0_3915.GetNextWaypoint
  L2_3917 = L2_3917(L3_3918)
  if L2_3917 then
    L3_3918 = DistanceSqVectors
    L4_3919 = A0_3915.m_currentPos
    L5_3920 = L2_3917
    L3_3918 = L3_3918(L4_3919, L5_3920)
    if L3_3918 > 1 then
      L3_3918 = DistanceSqVectors
      L4_3919 = A0_3915.m_startPos
      L5_3920 = A0_3915.m_currentPos
      L3_3918 = L3_3918(L4_3919, L5_3920)
      if L3_3918 < 1 then
        L3_3918 = A0_3915.m_direction
        if L3_3918 < 0 then
          return
        end
      end
      L3_3918 = g_Vectors
      L3_3918 = L3_3918.temp_v1
      L4_3919 = A0_3915.m_direction
      if L4_3919 > 0 then
        L4_3919 = SubVectors
        L5_3920 = L3_3918
        L4_3919(L5_3920, L2_3917, A0_3915.m_currentPos)
      else
        L4_3919 = SubVectors
        L5_3920 = L3_3918
        L4_3919(L5_3920, A0_3915.m_startPos, A0_3915.m_currentPos)
      end
      L4_3919 = LengthVector
      L5_3920 = L3_3918
      L4_3919 = L4_3919(L5_3920)
      L5_3920 = __min
      L5_3920 = L5_3920(L4_3919, A1_3916 * A0_3915.Properties.fSpeed * math.abs(A0_3915.m_direction))
      NormalizeVector(L3_3918)
      ScaleVectorInPlace(L3_3918, L5_3920)
      FastSumVectors(A0_3915.m_currentPos, A0_3915.m_currentPos, L3_3918)
      A0_3915:SetWorldPos(A0_3915.m_currentPos)
      if A0_3915.m_tentacles then
        for _FORV_9_, _FORV_10_ in ipairs(A0_3915.m_tentacles) do
          FastSumVectors(_FORV_10_.m_currentPos, _FORV_10_.m_currentPos, L3_3918)
          _FORV_10_:SetWorldPos(_FORV_10_.m_currentPos)
        end
      end
    end
  else
  end
end
function ArkFogWall.OnUpdate(A0_3921, A1_3922)
  A0_3921:TryToGrowTentacle()
  Ark.SendSignalPackageInAOE(A0_3921.id, A0_3921.id, A0_3921.Properties.signalPackage_ApexFog, A0_3921.m_currentPos, 0, A0_3921.PropertiesInstance.fRadius, 1, 0)
  if A0_3921.m_tentacles then
    A0_3921.m_tentacles[A0_3921.m_updateIdx]:OnUpdate(A1_3922)
    if A0_3921.m_tentacles[A0_3921.m_updateIdx].m_numSegments == 1 then
      A0_3921:StopAdvancing()
    else
      A0_3921:UpdatePositionAndVelocity(A1_3922)
    end
    A0_3921.m_updateIdx = A0_3921.m_updateIdx + 1
    if A0_3921.m_updateIdx > A0_3921:GetNumTentacles() then
      A0_3921.m_updateIdx = 1
    end
  end
end
function ArkFogWall.OnSpawn(A0_3923)
  CreateFogWallInstance(A0_3923)
  A0_3923:Log("OnSpawn")
end
function ArkFogWall.OnDestroy(A0_3924)
  A0_3924:ExecuteAudioTrigger(A0_3924.m_audioIds.audioTrigger_ExistStop)
end
function ArkFogWall.OnReset(A0_3925)
  A0_3925:Log("OnReset")
  A0_3925:Activate(0)
  if A0_3925.m_audioIds.audioTrigger_ExistStop then
    A0_3925:ExecuteAudioTrigger(A0_3925.m_audioIds.audioTrigger_ExistStop, A0_3925:GetDefaultAuxAudioProxyID())
  end
  A0_3925.m_updateIdx = 1
  A0_3925.m_direction = 1
  A0_3925.m_waypoints = false
  A0_3925.m_tentacles = false
  A0_3925.m_bWantsToGrow = true
  A0_3925:KillTimer(A0_3925.m_growthTimer)
  A0_3925:KillTimer(A0_3925.m_haltedTimer)
  A0_3925:KillTentacles()
end
