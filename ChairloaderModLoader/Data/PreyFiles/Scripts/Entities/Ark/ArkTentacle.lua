Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkTentacle = {
  Properties = {
    object_Model = "",
    nGrowthInterval = 1000,
    nRegrowthInterval = 1000,
    nVarianceInterval = 1000,
    nUpdateRate = 1000,
    fMaxLength = 5,
    nMaxSegments = 5,
    fMinScale = 0.1,
    fMaxScale = 1,
    fMinNoise = 1,
    fMaxNoise = 1,
    fAmplitude = 1,
    fFrequency = 100,
    fDistanceExponent = 1,
    fReactionProximity = 1,
    material_Material = "",
    signalPackage_ApexFog = "",
    particleeffect_DeathVfx = "",
    Signals = {signal_Laser = ""},
    Sound = {audioTrigger_Damage = "", audioTrigger_Attack = ""},
    Physics = {
      bPhysicalize = 1,
      bRigidBody = 0,
      bPushableByPlayers = 0,
      bPushableByAI = 0,
      Density = -1,
      Mass = -1
    }
  },
  Editor = {
    Icon = "physicsobject.bmp",
    IconOnTop = 1
  }
}
ArkTentacleInstanceVars = {
  m_bVerbose = false,
  m_bInit = false,
  m_segments = false,
  m_increment = 0,
  m_interval = 0,
  m_intervalOffset = 0,
  m_growthTimer = false,
  m_regrowthTimer = false,
  m_varianceTimer = false,
  m_bReverseDirection = true,
  m_bCanGrow = true,
  m_direction = -1,
  m_distanceModifier = 0,
  m_playerDistance = 0,
  m_numSegments = 0,
  m_audioIds = {},
  m_playerPos = ConstVec({
    x = 0,
    y = 0,
    z = 0
  }),
  m_diffToPlayer = ConstVec({
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
GetArkEntityUtils(ArkTentacle)
SetupCollisionFiltering(ArkTentacle)
function CreateTentacle(A0_4587)
  mergef(A0_4587, ArkTentacleInstanceVars, 1)
  A0_4587.m_referenceTable = ArkTentacleInstanceVars
end
function ArkTentacle.Init(A0_4588, A1_4589)
  A0_4588:SetFromProperties()
  if not A0_4588.m_bInit and A1_4589 then
    GetAudioIds(A0_4588.Properties.Sound, A0_4588.m_audioIds)
    A0_4588:GetWorldPos(A0_4588.m_currentPos)
    A0_4588.m_segments = {}
    A0_4588:SetScriptUpdateRate(A0_4588.Properties.nUpdateRate)
    A0_4588:SetMaterial(A0_4588.Properties.material_Material)
    A0_4588.m_interval = math.random()
    A0_4588.m_intervalOffset = math.random(-1, 1)
  end
end
function ArkTentacle.SetFromProperties(A0_4590)
  local L1_4591, L2_4592
  L1_4591 = A0_4590.Properties
  L2_4592 = L1_4591.fMaxLength
  L2_4592 = L2_4592 / L1_4591.nMaxSegments
  A0_4590.m_increment = L2_4592
  L2_4592 = L1_4591.nVarianceInterval
  A0_4590.m_varianceInterval = L2_4592
end
function ArkTentacle.AddSegment(A0_4593)
  local L1_4594, L2_4595, L3_4596
  L1_4594 = A0_4593.Properties
  L2_4595 = -1
  L3_4596 = {}
  L3_4596.slot = -1
  L3_4596.pos = NewVector(g_Vectors.v000)
  L3_4596.scale = 1
  L3_4596.slot = A0_4593:LoadObject(L3_4596.slot, L1_4594.object_Model)
  table.insert(A0_4593.m_segments, 1, L3_4596)
end
function ArkTentacle.PlayerSegmentDeathFX(A0_4597, A1_4598)
  Particle.SpawnEffect(A0_4597.Properties.particleeffect_DeathVfx, A1_4598, g_Vectors.v001)
end
function ArkTentacle.UpdateDistancesToPlayer(A0_4599)
  A0_4599.m_playerPos = g_localActor:GetCenterOfMassPos()
  A0_4599.m_diffToPlayer = A0_4599:ToLocal(-1, A0_4599.m_playerPos)
  A0_4599.m_playerDistance = DistanceVectors(A0_4599.m_playerPos, A0_4599.m_currentPos)
end
function ArkTentacle.ReverseDirection(A0_4600)
  local L1_4601
  L1_4601 = A0_4600.m_direction
  L1_4601 = L1_4601 * -1
  A0_4600.m_direction = L1_4601
  A0_4600.m_bReverseDirection = true
  L1_4601 = A0_4600.Properties
  L1_4601 = L1_4601.nVarianceInterval
  L1_4601 = L1_4601 * math.random(A0_4600.m_distanceModifier, 1)
  A0_4600.m_varianceInterval = L1_4601
end
function ArkTentacle.TryToGrow(A0_4602)
  if A0_4602.m_bCanGrow then
    A0_4602.m_bCanGrow = false
    A0_4602:AddSegment()
    A0_4602.m_growthTimer = Script.SetTimer(A0_4602.Properties.nGrowthInterval, function()
      _UPVALUE0_:ResetGrowthTimer()
    end)
  end
end
function ArkTentacle.ResetGrowthTimer(A0_4603)
  local L2_4604
  L2_4604 = A0_4603.m_numSegments
  if L2_4604 < A0_4603.Properties.nMaxSegments then
    A0_4603.m_bCanGrow = true
  end
end
function ArkTentacle.UpdateSegments(A0_4605, A1_4606)
  local L2_4607, L3_4608, L4_4609, L5_4610, L6_4611, L7_4612, L8_4613, L9_4614, L10_4615
  L2_4607 = A0_4605.Properties
  L3_4608 = g_Vectors
  L3_4608 = L3_4608.temp_v1
  L4_4609 = __min
  L4_4609 = L4_4609(L5_4610, L6_4611)
  A0_4605.m_interval = L5_4610
  L5_4610(L6_4611, L7_4612)
  L8_4613 = L2_4607.nMaxSegments
  L5_4610(L6_4611, L7_4612)
  for L8_4613, L9_4614 in L5_4610(L6_4611) do
    L10_4615 = L8_4613 - 1
    L10_4615 = L10_4615 / L2_4607.nMaxSegments
    L9_4614.scale = Lerp(L2_4607.fMaxScale, L2_4607.fMinScale, L10_4615)
    L9_4614.pos.y = Lerp(0, L4_4609, L10_4615)
    L9_4614.pos.x = (math.cos(L9_4614.pos.y - A0_4605.m_interval) + randomF(L2_4607.fMinNoise, L2_4607.fMaxNoise) + A0_4605.m_distanceModifier * L3_4608.x) * sqr(L10_4615) * L2_4607.fAmplitude
    L9_4614.pos.z = (math.sin(L9_4614.pos.y + A0_4605.m_interval) + randomF(L2_4607.fMinNoise, L2_4607.fMaxNoise) + A0_4605.m_distanceModifier * L3_4608.z) * sqr(L10_4615) * L2_4607.fAmplitude
    A0_4605:SetSlotScale(L9_4614.slot, L9_4614.scale)
    A0_4605:SetSlotPos(L9_4614.slot, L9_4614.pos)
    EntityCommon.PhysicalizeRigid(A0_4605, L9_4614.slot, L2_4607.Physics, 0)
  end
end
function ArkTentacle.AbsoluteVectorInPlace(A0_4616, A1_4617)
  A1_4617.x = math.abs(A1_4617.x)
  A1_4617.y = math.abs(A1_4617.y)
  A1_4617.z = math.abs(A1_4617.z)
end
function ArkTentacle.OnUpdate(A0_4618, A1_4619)
  local L2_4620
  L2_4620 = A0_4618.m_segments
  L2_4620 = #L2_4620
  A0_4618.m_numSegments = L2_4620
  L2_4620 = A0_4618.TryToGrow
  L2_4620(A0_4618)
  L2_4620 = A0_4618.UpdateDistancesToPlayer
  L2_4620(A0_4618)
  L2_4620 = A0_4618.Properties
  L2_4620 = L2_4620.fReactionProximity
  L2_4620 = L2_4620 / A0_4618.m_playerDistance
  A0_4618.m_distanceModifier = math.pow(__min(1, L2_4620), A0_4618.Properties.fDistanceExponent)
  A0_4618:UpdateSegments(A1_4619 * A0_4618.m_intervalOffset)
end
function ArkTentacle.OnCollision(A0_4621, A1_4622)
  Ark.SendSignalPackage(A1_4622.target.id, A0_4621.id, A0_4621.id, A0_4621.Properties.signalPackage_ApexFog)
  A0_4621:ExecuteAudioTrigger(A0_4621.m_audioIds.audioTrigger_Attack, A0_4621:GetDefaultAuxAudioProxyID())
  if A1_4622.target == g_localActor then
    g_localActor:IndicateDamageOnHUD(A1_4622.pos)
  end
end
function ArkTentacle.OnPackageReceived(A0_4623, A1_4624, A2_4625)
  local L3_4626
  L3_4626 = A0_4623.Properties
  L3_4626 = L3_4626.Signals
  L3_4626 = L3_4626.signal_Laser
  L3_4626 = A2_4625[L3_4626]
  if L3_4626 then
    L3_4626 = 1
    while L3_4626 > 0 do
      L3_4626 = L3_4626 - 1
      if 1 < A0_4623.m_numSegments then
        A0_4623:PlayerSegmentDeathFX(A0_4623:GetSlotWorldPos(table.remove(A0_4623.m_segments).slot))
        A0_4623:FreeSlot(table.remove(A0_4623.m_segments).slot)
        A0_4623:ExecuteAudioTrigger(A0_4623.m_audioIds.audioTrigger_Damage, A0_4623:GetDefaultAuxAudioProxyID())
      end
    end
    A0_4623:KillTimer(A0_4623.m_growthTimer)
    A0_4623:KillTimer(A0_4623.m_regrowthTimer)
    A0_4623.m_regrowthTimer = Script.SetTimer(A0_4623.Properties.nRegrowthInterval, function()
      _UPVALUE0_:ResetGrowthTimer()
    end)
  end
end
function ArkTentacle.OnSpawn(A0_4627)
  CreateTentacle(A0_4627)
  A0_4627:Log("OnSpawn")
end
function ArkTentacle.OnReset(A0_4628)
  A0_4628:Log("OnReset")
  A0_4628.m_interval = 0
  A0_4628.m_bCanGrow = true
  A0_4628:KillTimer(A0_4628.m_growthTimer)
  if A0_4628.m_segments then
    for _FORV_4_, _FORV_5_ in ipairs(A0_4628.m_segments) do
      A0_4628:FreeSlot(_FORV_5_.slot)
    end
    A0_4628.m_segments = false
  end
end
