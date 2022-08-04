Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkEtherForm = {
  Properties = {
    object_Model = "",
    material_Material = "",
    signalpackage_EtherFormHazard = "",
    fHazardRadius = 1,
    fSpeed = 50,
    nUpdateRate = 1,
    nHazardRate = 100,
    nCameraVFXInterval = 1000,
    fMinDesiredDistance = 0.2,
    fMaxDesiredDistance = 1,
    fVfxScale = 1,
    Damage = {health = 1000},
    Signals = {
      signal_Electric = "",
      signal_Fire = "",
      signal_Laser = ""
    },
    Physics = {
      bPhysicalize = 0,
      bRigidBody = 0,
      bPushableByPlayers = 0,
      bResting = 0,
      bRigidBodyActive = 0,
      Density = 1,
      Mass = -1
    },
    Effects = {
      particleeffect_Follow = "",
      particleeffect_Tail = "",
      particleeffect_Camera = ""
    },
    Sound = {
      audioTrigger_FollowStart = "",
      audioTrigger_FollowStop = "",
      audioTrigger_Death = ""
    }
  },
  States = {"Follow", "Dead"},
  Editor = {
    Icon = "tornado.bmp",
    IconOnTop = 1
  }
}
GetArkEntityUtils(ArkEtherForm)
SetupCollisionFiltering(ArkEtherForm)
ArkEtherFormInstanceVars = {
  m_bVerbose = true,
  m_bIsScripted = false,
  m_bRepeatHazard = true,
  m_bRepeatCameraVfx = false,
  m_hazardTimer = false,
  m_cameraVfxTimer = false,
  m_referenceTable = false,
  m_audioIds = {},
  m_movementVector = ConstVec({
    x = 0,
    y = 0,
    z = 0
  }),
  m_lastValidTargetPos = ConstVec({
    x = 0,
    y = 0,
    z = 0
  }),
  m_targetPos = ConstVec({
    x = 0,
    y = 0,
    z = 0
  }),
  m_position = ConstVec({
    x = 0,
    y = 0,
    z = 0
  }),
  m_health = 0,
  m_minSqDistance = -1,
  m_maxSqDistance = -1,
  m_target = -1,
  m_hazardVfxSlot = -1
}
function CreateEtherForm(A0_3800)
  mergef(A0_3800, ArkEtherFormInstanceVars, 1)
  A0_3800.m_referenceTable = ArkEtherFormInstanceVars
end
function ArkEtherForm.Init(A0_3801, A1_3802)
  A0_3801:Log("Init")
  A0_3801:SetViewDistUnlimited()
  A0_3801:SetFromProperties()
  GetAudioIds(A0_3801.Properties.Sound, A0_3801.m_audioIds)
  if A1_3802 then
    A0_3801:DoHazardVfx()
  end
end
function ArkEtherForm.SetFromProperties(A0_3803, A1_3804)
  local L2_3805
  L2_3805 = A0_3803.Properties
  A0_3803.m_minSqDistance = sqr(L2_3805.fMinDesiredDistance)
  A0_3803.m_maxSqDistance = sqr(L2_3805.fMaxDesiredDistance)
  A0_3803.m_health = L2_3805.Damage.health
  A0_3803.m_bRepeatCameraVfx = A0_3803:IsCameraVfxEnabled()
  A0_3803:SetupModelAndPhysics()
  A0_3803:SetMaterial(L2_3805.material_Material)
end
function ArkEtherForm.SetTarget(A0_3806, A1_3807)
  if A1_3807 then
    A0_3806:Log("setting target to" .. A1_3807:GetName())
    A0_3806.m_target = A1_3807
  else
    A0_3806.m_target = g_localActor
  end
end
function ArkEtherForm.CanRayTraceToPos(A0_3808, A1_3809, A2_3810)
  local L3_3811, L4_3812, L5_3813
  if A2_3810 then
    L3_3811 = System
    L3_3811 = L3_3811.RayTraceCheck
    L4_3812 = A1_3809
    L5_3813 = A2_3810
    L3_3811 = L3_3811(L4_3812, L5_3813, A0_3808:GetRawId(), A0_3808.m_target:GetRawId())
    L4_3812 = nil
    if L3_3811 then
      L5_3813 = g_Vectors
      L4_3812 = L5_3813.v010
    else
      L5_3813 = g_Vectors
      L4_3812 = L5_3813.v100
    end
    return L3_3811
  else
    L3_3811 = false
    return L3_3811
  end
end
function ArkEtherForm.Move(A0_3814, A1_3815)
  local L2_3816, L3_3817
  L2_3816 = A0_3814.Properties
  L3_3817 = SubVectors
  L3_3817(A0_3814.m_movementVector, A1_3815, A0_3814.m_position)
  L3_3817 = LengthVector
  L3_3817 = L3_3817(A0_3814.m_movementVector)
  NormalizeVector(A0_3814.m_movementVector)
  A0_3814:SetWorldPos(A1_3815)
  if L3_3817 < 0.297 then
    ScaleVectorInPlace(A0_3814.m_movementVector, L3_3817)
  else
    ScaleVectorInPlace(A0_3814.m_movementVector, 9)
  end
end
function ArkEtherForm.DoHazardVfx(A0_3818)
  local L1_3819, L2_3820
  L1_3819 = A0_3818.Properties
  L2_3820 = {}
  L2_3820.PulsePeriod = 1
  L2_3820.bPrime = true
  L2_3820.Scale = A0_3818.Properties.fVfxScale
  L2_3820.SpeedScale = 1
  L2_3820.TimeScale = 1
  L2_3820.CountScale = 1
  L2_3820.Strength = -1
  A0_3818.m_hazardVfxSlot = A0_3818:LoadParticleEffect(A0_3818.m_hazardVfxSlot, L1_3819.Effects.particleeffect_Follow, L2_3820)
end
function ArkEtherForm.CreateHazardArea(A0_3821)
  local L1_3822
  L1_3822 = A0_3821.Properties
  Ark.SendSignalPackageInAOE(A0_3821.id, A0_3821.id, L1_3822.signalpackage_EtherFormHazard, A0_3821:GetWorldBoundsCenter(), L1_3822.fHazardRadius, L1_3822.fHazardRadius, 1, 0)
end
function ArkEtherForm.OnUpdate(A0_3823, A1_3824)
  A0_3823:Log("I'm updating and not in a state.")
end
function ArkEtherForm.OnReset(A0_3825, A1_3826)
  A0_3825:Log("OnReset")
  A0_3825:StopAudioTrigger(A0_3825.m_audioIds.audioTrigger_FollowStart, A0_3825:GetDefaultAuxAudioProxyID())
  A0_3825:GotoState("")
  A0_3825:FreeAllSlots()
  A0_3825.m_bRepeatHazard = true
  A0_3825.m_bInHazardRangeOfTarget = false
  A0_3825.m_health = A0_3825.Properties.Damage.health
  A0_3825:Activate(0)
  A0_3825:SetupModelAndPhysics()
end
function ArkEtherForm.OnPackageReceived(A0_3827, A1_3828, A2_3829)
  for _FORV_7_, _FORV_8_ in pairs(A0_3827.Properties.Signals) do
    if A2_3829[_FORV_8_] then
      A0_3827.m_health = A0_3827.m_health - A2_3829[_FORV_8_]
      if A0_3827.m_health < 0 then
        A0_3827:GotoState("Dead")
        break
      end
    end
  end
end
function ArkEtherForm.OnDestroy(A0_3830)
  A0_3830:Log("ArkEtherForm: OnDestroy()")
  A0_3830:ExecuteAudioTrigger(A0_3830.m_audioIds.audioTrigger_FollowStop, A0_3830:GetDefaultAuxAudioProxyID())
end
function ArkEtherForm.OnSpawn(A0_3831)
  local L1_3832, L2_3833, L3_3834, L4_3835, L5_3836, L6_3837
  L1_3832 = CreateEtherForm
  L1_3832(L2_3833)
  L1_3832 = A0_3831.Log
  L1_3832(L2_3833, L3_3834)
  L1_3832 = A0_3831.SetFromProperties
  L1_3832(L2_3833)
  L1_3832 = A0_3831.Init
  L1_3832(L2_3833)
  L1_3832 = A0_3831.Properties
  for L5_3836, L6_3837 in L2_3833(L3_3834) do
    Ark.RegisterForSignal(A0_3831.id, L6_3837)
  end
end
function ArkEtherForm.OnPostLoad(A0_3838)
  A0_3838:KillTimers()
  A0_3838:StopAudioTrigger(A0_3838.m_audioIds.audioTrigger_FollowStop, A0_3838:GetDefaultAuxAudioProxyID())
  A0_3838:GotoState("")
  A0_3838:GotoState("Follow")
end
function ArkEtherForm.Event_Follow(A0_3839, A1_3840, A2_3841)
  A0_3839.m_bIsScripted = true
  A0_3839:SetTarget(A2_3841)
  A0_3839:GotoState("Follow")
end
function ArkEtherForm.Event_ResumeAI(A0_3842)
  A0_3842:SetTarget()
  A0_3842.m_bIsScripted = false
  A0_3842:GotoState("Follow")
end
function ArkEtherForm.OnShutDown(A0_3843)
  local L1_3844
end
ArkEtherForm.Follow = {
  OnStartLevel = function(A0_3845)
    A0_3845:OnStartLevel()
  end,
  OnBeginState = function(A0_3846)
    A0_3846:SetScriptUpdateRate(1)
    A0_3846:DrawSlot(0, 1)
    A0_3846:Activate(1)
    BroadcastEvent(A0_3846, "Follow")
    A0_3846:Log("Follow state begin")
    A0_3846.m_bRepeatHazard = true
    A0_3846.m_bRepeatCameraVfx = A0_3846:IsCameraVfxEnabled()
    A0_3846:ExecuteAudioTrigger(A0_3846.m_audioIds.audioTrigger_FollowStart, A0_3846:GetDefaultAuxAudioProxyID())
  end,
  OnUpdate = function(A0_3847)
    local L1_3848
    L1_3848 = A0_3847.Properties
    A0_3847:GetWorldPos(A0_3847.m_position)
    A0_3847.m_target:GetCenterOfMassPos(A0_3847.m_targetPos)
    A0_3847.m_targetPos.z = A0_3847.m_targetPos.z
    A0_3847:Move(A0_3847.m_targetPos)
    if DistanceSqVectors(A0_3847.m_position, A0_3847.m_targetPos) > A0_3847.m_maxSqDistance and not (DistanceSqVectors(A0_3847.m_position, A0_3847.m_targetPos) < A0_3847.m_minSqDistance) then
      A0_3847.m_bInHazardRangeOfTarget = false
    else
      A0_3847.m_bInHazardRangeOfTarget = true
    end
    if A0_3847.m_bRepeatHazard then
      A0_3847:CreateHazardArea()
      A0_3847.m_bRepeatHazard = false
      A0_3847.m_hazardTimer = Script.SetTimer(L1_3848.nHazardRate, function()
        local L1_3849
        L1_3849 = _UPVALUE0_
        L1_3849.m_bRepeatHazard = true
      end)
      Particle.SpawnEffect(L1_3848.Effects.particleeffect_Tail, A0_3847.m_position, g_Vectors.v000)
      if A0_3847.m_target == g_localActor and A0_3847.m_bInHazardRangeOfTarget and A0_3847.m_bRepeatCameraVfx then
        g_localActor:IndicateDamageOnHUD(A0_3847.m_position)
        A0_3847:DoCameraFX("m_bRepeatCameraVfx", "m_cameraVfxTimer", L1_3848.Effects.particleeffect_Camera, L1_3848.nCameraVFXInterval, function()
          local L1_3850
          L1_3850 = _UPVALUE0_
          L1_3850.m_bRepeatCameraVfx = true
        end)
      end
    end
  end,
  OnEndState = function(A0_3851)
    A0_3851:Log("Follow state end")
    A0_3851:ExecuteAudioTrigger(A0_3851.m_audioIds.audioTrigger_FollowStop, A0_3851:GetDefaultAuxAudioProxyID())
  end
}
ArkEtherForm.Dead = {
  OnStartLevel = function(A0_3852)
    A0_3852:OnStartLevel()
  end,
  OnBeginState = function(A0_3853)
    A0_3853:Log("Dead state begin")
    A0_3853:Activate(0)
    A0_3853:FreeAllSlots()
    A0_3853:DrawSlot(0, 0)
    BroadcastEvent(A0_3853, "Dead")
  end,
  OnEndState = function(A0_3854)
    A0_3854:Log("Dead state end")
  end
}
ArkEtherForm.FlowEvents = {
  Inputs = {
    Follow = {
      ArkEtherForm.Event_Follow,
      "entity"
    },
    ResumeAI = {
      ArkEtherForm.Event_ResumeAI,
      "bool"
    }
  },
  Outputs = {Follow = "bool", Dead = "bool"}
}
