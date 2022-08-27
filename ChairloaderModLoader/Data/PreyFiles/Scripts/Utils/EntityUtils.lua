local L0_9728, L1_9729
L0_9728 = {}
L1_9729 = {}
L1_9729.mass = 0
L1_9729.density = 0
L0_9728.TempPhysParams = L1_9729
L1_9729 = {}
L1_9729.flags_mask = 0
L1_9729.flags = 0
L1_9729.arkFlags_mask = 0
L1_9729.arkFlags = 0
L0_9728.TempPhysicsFlags = L1_9729
L1_9729 = {}
L1_9729.max_time_step = 0.02
L0_9728.TempSimulationParams = L1_9729
EntityCommon = L0_9728
function L0_9728(A0_9730, A1_9731)
  local L2_9732
  L2_9732 = A0_9730.Properties
  A0_9730.Properties = {}
  mergef(A0_9730, A1_9731, 1)
  mergef(A0_9730.Properties, L2_9732, 1)
  A0_9730.__super = BasicEntity
  return A0_9730
end
MakeDerivedEntity = L0_9728
function L0_9728(A0_9733, A1_9734)
  mergef(A0_9733, A1_9734, 1)
  A0_9733.__super = A1_9734
  return A0_9733
end
MakeDerivedEntityOverride = L0_9728
function L0_9728(A0_9735, A1_9736)
  local L2_9737, L3_9738, L4_9739, L5_9740, L6_9741, L7_9742, L8_9743, L9_9744, L10_9745, L11_9746, L12_9747
  L2_9737 = A0_9735.ProcessBroadcastEvent
  L2_9737(L3_9738, L4_9739)
  L2_9737 = A0_9735.Events
  if L2_9737 then
    L2_9737 = A0_9735.Events
    L2_9737 = L2_9737[A1_9736]
    if L2_9737 then
      for L6_9741, L7_9742 in L3_9738(L4_9739) do
        L8_9743 = L7_9742[1]
        L9_9744 = L7_9742[2]
        if L8_9743 == 0 then
          L10_9745 = Mission
          if L10_9745 then
            L10_9745 = Mission
            L11_9746 = "Event_"
            L12_9747 = L9_9744
            L11_9746 = L11_9746 .. L12_9747
            L10_9745 = L10_9745[L11_9746]
            if L10_9745 ~= nil then
              L11_9746 = L10_9745
              L12_9747 = A0_9735
              L11_9746(L12_9747)
            else
              L11_9746 = System
              L11_9746 = L11_9746.Log
              L12_9747 = "Mission does not support event "
              L12_9747 = L12_9747 .. L9_9744
              L11_9746(L12_9747)
            end
          end
        else
          L10_9745 = System
          L10_9745 = L10_9745.GetEntity
          L11_9746 = L8_9743
          L10_9745 = L10_9745(L11_9746)
          if L10_9745 ~= nil then
            L12_9747 = L10_9745
            L11_9746 = L10_9745.GetName
            L11_9746 = L11_9746(L12_9747)
            L12_9747 = "Event_"
            L12_9747 = L12_9747 .. L9_9744
            L12_9747 = L10_9745[L12_9747]
            if L12_9747 ~= nil then
              L12_9747(L10_9745, A0_9735)
            end
          end
        end
      end
    end
  end
end
BroadcastEvent = L0_9728
function L0_9728()
  local L0_9748
  L0_9748 = System
  L0_9748 = L0_9748.GetEntities
  L0_9748 = L0_9748()
  System.Log("Entities dump")
  for _FORV_4_, _FORV_5_ in pairs(L0_9748) do
    System.Log("address=[" .. tostring(_FORV_5_.id) .. "] rawId=[" .. tostring(_FORV_5_:GetRawId()) .. "] name=[" .. _FORV_5_:GetName() .. "] class=[" .. _FORV_5_.class .. "]")
  end
end
DumpEntities = L0_9728
function L0_9728(A0_9749)
  local L1_9750, L2_9751
  L1_9750 = A0_9749.Properties
  if not L1_9750 then
    L1_9750 = {}
    A0_9749.Properties = L1_9750
  end
  function L1_9750(A0_9752)
    local L1_9753
  end
  A0_9749.RegisterWithAI = L1_9750
  L1_9750 = A0_9749.OnReset
  function L2_9751(A0_9754, ...)
    if _UPVALUE0_ then
      _UPVALUE0_(A0_9754, ...)
    end
    A0_9754:RegisterWithAI()
  end
  A0_9749.OnReset = L2_9751
  L2_9751 = A0_9749.OnSpawn
  function A0_9749.OnSpawn(A0_9756, ...)
    if _UPVALUE0_ then
      _UPVALUE0_(A0_9756, ...)
    end
    A0_9756:RegisterWithAI()
  end
end
MakeTargetableByAI = L0_9728
function L0_9728(A0_9758)
  local L1_9759
  L1_9759 = A0_9758.Properties
  if not L1_9759 then
    L1_9759 = {}
    A0_9758.Properties = L1_9759
  end
  L1_9759 = A0_9758.Properties
  L1_9759 = L1_9759.bProvideAICover
  if not L1_9759 then
    L1_9759 = A0_9758.Properties
    L1_9759.bProvideAICover = 1
  end
  L1_9759 = A0_9758.Server
  if L1_9759 then
    L1_9759 = A0_9758.Server
  else
    L1_9759 = L1_9759 or A0_9758
  end
  function L1_9759.OnStartGame(A0_9760)
    if A0_9760.PropertiesInstance.bProvideAICover ~= 0 and AI ~= nil then
      AI.AddCoverEntity(A0_9760.id)
    end
    if _UPVALUE0_ then
      _UPVALUE0_(A0_9760)
    end
  end
end
MakeAICoverEntity = L0_9728
function L0_9728(A0_9761)
  local L1_9762, L2_9763, L3_9764, L4_9765, L5_9766, L6_9767, L7_9768
  L1_9762 = A0_9761.Properties
  if not L1_9762 then
    L1_9762 = {}
    A0_9761.Properties = L1_9762
  end
  L1_9762 = A0_9761.Properties
  L1_9762 = L1_9762.Health
  if not L1_9762 then
    L1_9762 = A0_9761.Properties
    L2_9763 = {}
    L1_9762.Health = L2_9763
  end
  L1_9762 = A0_9761.Properties
  L1_9762 = L1_9762.Health
  L1_9762.MaxHealth = 500
  L1_9762.bInvulnerable = 0
  L1_9762.bOnlyEnemyFire = 1
  function L2_9763(A0_9769)
    local L1_9770
    L1_9770 = A0_9769.dead
    return L1_9770
  end
  A0_9761.IsDead = L2_9763
  function L2_9763(A0_9771)
    local L1_9772
    A0_9771.dead = nil
    L1_9772 = A0_9771.Properties
    L1_9772 = L1_9772.Health
    L1_9772 = L1_9772.MaxHealth
    A0_9771.health = L1_9772
    L1_9772 = A0_9771.Properties
    L1_9772 = L1_9772.Health
    L1_9772 = L1_9772.bInvulnerable
    L1_9772 = L1_9772 ~= 0
    A0_9771.invulnerable = L1_9772
    L1_9772 = A0_9771.Properties
    L1_9772 = L1_9772.Health
    L1_9772 = L1_9772.bOnlyEnemyFire
    L1_9772 = L1_9772 == 0
    A0_9771.friendlyFire = L1_9772
  end
  A0_9761.SetupHealthProperties = L2_9763
  L2_9763 = A0_9761.Server
  if not L2_9763 then
    L2_9763 = {}
    A0_9761.Server = L2_9763
  end
  L2_9763 = A0_9761.Client
  if not L2_9763 then
    L2_9763 = {}
    A0_9761.Client = L2_9763
  end
  function L2_9763(A0_9773)
    local L2_9774
    L2_9774 = 1
    if A0_9773.Properties.Health.MaxHealth > 0 then
      L2_9774 = A0_9773.health / A0_9773.Properties.Health.MaxHealth
    end
    return L2_9774
  end
  A0_9761.GetHealthRatio = L2_9763
  function L2_9763(A0_9775)
    local L1_9776
    L1_9776 = A0_9775.invulnerable
    return L1_9776
  end
  A0_9761.IsInvulnerable = L2_9763
  function L2_9763(A0_9777)
    local L1_9778
    L1_9778 = A0_9777.Properties
    L1_9778 = L1_9778.Health
    L1_9778 = L1_9778.MaxHealth
    return L1_9778
  end
  A0_9761.GetMaxHealth = L2_9763
  L2_9763 = A0_9761.Server
  L2_9763 = L2_9763.OnHit
  L3_9764 = A0_9761.Server
  function L4_9765(A0_9779, A1_9780)
    local L2_9781
    L2_9781 = A0_9779.health
    if L2_9781 then
      L2_9781 = A0_9779.IsInvulnerable
    elseif L2_9781 == nil then
      L2_9781 = Log
      L2_9781("$4%s:%s Health not initialized!", A0_9779.class, A0_9779:GetName())
      L2_9781 = A0_9779.SetupHealthProperties
      L2_9781(A0_9779)
    end
    L2_9781 = false
    if _UPVALUE0_ then
      L2_9781 = _UPVALUE0_(A0_9779, A1_9780)
    end
    if not L2_9781 then
      if A0_9779:IsInvulnerable() then
        A0_9779:ActivateOutput("Health", A0_9779:GetHealthRatio() * 100)
        A0_9779:Event_Hit()
        return false
      end
      if not A0_9779.friendlyFire and System.GetEntity(A1_9780.shooterId) ~= nil and AI.GetReactionOf(A0_9779.id, A1_9780.shooterId) == Friendly then
        A0_9779:ActivateOutput("Health", A0_9779:GetHealthRatio() * 100)
        A0_9779:Event_Hit()
        return false
      end
      A0_9779.health = A0_9779.health - A1_9780.damage
    end
    A0_9779:ActivateOutput("Health", A0_9779:GetHealthRatio() * 100)
    A0_9779:Event_Hit()
    if A0_9779.health <= 0 then
      A0_9779.dead = true
      A0_9779:Event_Dead()
      return true
    end
  end
  L3_9764.OnHit = L4_9765
  L3_9764 = A0_9761.OnReset
  function L4_9765(A0_9782, ...)
    if _UPVALUE0_ then
      _UPVALUE0_(A0_9782, ...)
    end
    A0_9782:SetupHealthProperties()
  end
  A0_9761.OnReset = L4_9765
  L4_9765 = A0_9761.OnSpawn
  function L5_9766(A0_9784, ...)
    if _UPVALUE0_ then
      _UPVALUE0_(A0_9784, ...)
    end
    A0_9784:SetupHealthProperties()
  end
  A0_9761.OnSpawn = L5_9766
  function L5_9766(A0_9786)
    local L1_9787
    A0_9786.dead = nil
    L1_9787 = A0_9786.Properties
    L1_9787 = L1_9787.Health
    L1_9787 = L1_9787.MaxHealth
    A0_9786.health = L1_9787
  end
  A0_9761.Event_ResetHealth = L5_9766
  function L5_9766(A0_9788, A1_9789)
    A0_9788.invulnerable = A1_9789
  end
  A0_9761.SetInvulnerability = L5_9766
  function L5_9766(A0_9790)
    A0_9790:SetInvulnerability(false)
  end
  A0_9761.Event_MakeVulnerable = L5_9766
  function L5_9766(A0_9791)
    A0_9791:SetInvulnerability(true)
  end
  A0_9761.Event_MakeInvulnerable = L5_9766
  function L5_9766(A0_9792)
    A0_9792:TriggerEvent(AIEVENT_DISABLE)
    BroadcastEvent(A0_9792, "Dead")
  end
  A0_9761.Event_Dead = L5_9766
  function L5_9766(A0_9793)
    BroadcastEvent(A0_9793, "Hit")
  end
  A0_9761.Event_Hit = L5_9766
  L5_9766 = A0_9761.FlowEvents
  if not L5_9766 then
    L5_9766 = {}
    A0_9761.FlowEvents = L5_9766
  end
  L5_9766 = A0_9761.FlowEvents
  L6_9767 = L5_9766.Inputs
  L6_9767 = L6_9767 or {}
  L5_9766.Inputs = L6_9767
  L6_9767 = L5_9766.Outputs
  L6_9767 = L6_9767 or {}
  L5_9766.Outputs = L6_9767
  L6_9767 = L5_9766.Inputs
  L7_9768 = {
    A0_9761.Event_ResetHealth,
    "any"
  }
  L6_9767.ResetHealth = L7_9768
  L6_9767 = L5_9766.Inputs
  L7_9768 = {
    A0_9761.Event_MakeVulnerable,
    "any"
  }
  L6_9767.MakeVulnerable = L7_9768
  L6_9767 = L5_9766.Inputs
  L7_9768 = {
    A0_9761.Event_MakeInvulnerable,
    "any"
  }
  L6_9767.MakeInvulnerable = L7_9768
  L6_9767 = L5_9766.Outputs
  L6_9767.Dead = "bool"
  L6_9767 = L5_9766.Outputs
  L6_9767.Hit = "bool"
  L6_9767 = L5_9766.Outputs
  L6_9767.Health = "float"
end
MakeKillable = L0_9728
function L0_9728(A0_9794)
  local L1_9795, L2_9796
  L1_9795 = A0_9794.Properties
  if not L1_9795 then
    L1_9795 = {}
    A0_9794.Properties = L1_9795
  end
  L1_9795 = A0_9794.Properties
  L1_9795 = L1_9795.RenderProxyOptions
  if not L1_9795 then
    L1_9795 = A0_9794.Properties
    L2_9796 = {}
    L1_9795.RenderProxyOptions = L2_9796
  end
  L1_9795 = A0_9794.Properties
  L1_9795 = L1_9795.RenderProxyOptions
  L1_9795.bAnimateOffScreenShadow = 0
  function L1_9795(A0_9797)
    A0_9797.bAnimateOffScreenShadow = A0_9797.Properties.RenderProxyOptions.bAnimateOffScreenShadow ~= 0
    if A0_9797.bAnimateOffScreenShadow then
      A0_9797:CreateRenderProxy()
    end
    A0_9797:SetAnimateOffScreenShadow(A0_9797.bAnimateOffScreenShadow)
  end
  A0_9794.SetRenderProxyOptions = L1_9795
  L1_9795 = A0_9794.OnReset
  function L2_9796(A0_9798, ...)
    if _UPVALUE0_ then
      _UPVALUE0_(A0_9798, ...)
    end
    A0_9798:SetRenderProxyOptions()
  end
  A0_9794.OnReset = L2_9796
  L2_9796 = A0_9794.OnSpawn
  function A0_9794.OnSpawn(A0_9800, ...)
    if _UPVALUE0_ then
      _UPVALUE0_(A0_9800, ...)
    end
    A0_9800:SetRenderProxyOptions()
  end
end
MakeRenderProxyOptions = L0_9728
function L0_9728(A0_9802)
  local L1_9803
  L1_9803 = A0_9802.Properties
  if not L1_9803 then
    L1_9803 = {}
    A0_9802.Properties = L1_9803
  end
  L1_9803 = A0_9802.Properties
  L1_9803.UseMessage = ""
  L1_9803 = A0_9802.Properties
  L1_9803.bUsable = 0
  function L1_9803(A0_9804)
    local L1_9805
    L1_9805 = A0_9804.__usable
    if not L1_9805 then
      L1_9805 = A0_9804.Properties
      L1_9805 = L1_9805.bUsable
      A0_9804.__origUsable = L1_9805
      L1_9805 = A0_9804.Properties
      L1_9805 = L1_9805.bPickable
      A0_9804.__origPickable = L1_9805
      L1_9805 = A0_9804.Properties
      L1_9805 = L1_9805.bUsable
      if L1_9805 ~= 1 then
        L1_9805 = A0_9804.Properties
        L1_9805 = L1_9805.bPickable
      else
        if L1_9805 == 1 then
          A0_9804.__usable = 1
      end
      else
        A0_9804.__usable = 0
      end
    end
    L1_9805 = A0_9804.__usable
    return L1_9805
  end
  A0_9802.IsUsable = L1_9803
  function L1_9803(A0_9806)
    local L1_9807
    A0_9806.__usable = nil
  end
  A0_9802.ResetOnUsed = L1_9803
  function L1_9803(A0_9808)
    return A0_9808.Properties.UseMessage
  end
  A0_9802.GetUsableMessage = L1_9803
  function L1_9803(A0_9809, A1_9810, A2_9811)
    BroadcastEvent(A0_9809, "Used")
    if A0_9809.Base_OnUsed then
      A0_9809:Base_OnUsed(A1_9810, A2_9811)
    end
  end
  A0_9802.OnUsed = L1_9803
  function L1_9803(A0_9812)
    BroadcastEvent(A0_9812, "Used")
  end
  A0_9802.Event_Used = L1_9803
  function L1_9803(A0_9813)
    A0_9813.__usable = 1
    BroadcastEvent(A0_9813, "EnableUsable")
  end
  A0_9802.Event_EnableUsable = L1_9803
  function L1_9803(A0_9814)
    A0_9814.__usable = 0
    BroadcastEvent(A0_9814, "DisableUsable")
  end
  A0_9802.Event_DisableUsable = L1_9803
end
MakeUsable = L0_9728
function L0_9728(A0_9815)
  local L1_9816
  L1_9816 = A0_9815.Properties
  if not L1_9816 then
    L1_9816 = {}
    A0_9815.Properties = L1_9816
  end
  L1_9816 = A0_9815.Properties
  L1_9816.bPickable = 0
end
MakePickable = L0_9728
function L0_9728(A0_9817)
  local L1_9818
  L1_9818 = A0_9817.Properties
  if not L1_9818 then
    L1_9818 = {}
    A0_9817.Properties = L1_9818
  end
  L1_9818 = A0_9817.Properties
  L1_9818.bHeavyObject = 0
end
AddHeavyObjectProperty = L0_9728
function L0_9728(A0_9819)
  local L1_9820, L2_9821, L3_9822
  L1_9820 = A0_9819.Properties
  if not L1_9820 then
    L1_9820 = {}
    A0_9819.Properties = L1_9820
  end
  L1_9820 = A0_9819.Properties
  L1_9820 = L1_9820.AutoAimTarget
  if not L1_9820 then
    L1_9820 = A0_9819.Properties
    L2_9821 = {}
    L1_9820.AutoAimTarget = L2_9821
  end
  L1_9820 = A0_9819.Properties
  L1_9820 = L1_9820.AutoAimTarget
  L1_9820.bMakeTargetableOnThrown = 0
  L1_9820 = A0_9819.Properties
  L1_9820 = L1_9820.AutoAimTarget
  L1_9820.InnerRadiusVolumeFactor = 0.35
  L1_9820 = A0_9819.Properties
  L1_9820 = L1_9820.AutoAimTarget
  L1_9820.OuterRadiusVolumeFactor = 0.6
  L1_9820 = A0_9819.Properties
  L1_9820 = L1_9820.AutoAimTarget
  L1_9820.SnapRadiusVolumeFactor = 1.25
  L1_9820 = A0_9819.Properties
  L1_9820 = L1_9820.AutoAimTarget
  L1_9820.AfterThrownTargetableTime = 3
  function L1_9820(A0_9823)
    if A0_9823.Properties.AutoAimTarget.bMakeTargetableOnThrown ~= 0 and A0_9823:CanBeMadeTargetable() then
      Game.RegisterWithAutoAimManager(A0_9823.id, A0_9823.Properties.AutoAimTarget.InnerRadiusVolumeFactor, A0_9823.Properties.AutoAimTarget.OuterRadiusVolumeFactor, A0_9823.Properties.AutoAimTarget.SnapRadiusVolumeFactor)
      Script.SetTimer(A0_9823.Properties.AutoAimTarget.AfterThrownTargetableTime * 1000, function()
        _UPVALUE0_:AfterThrownTimer()
      end)
      A0_9823.isTargetable = 1
    end
  end
  A0_9819.OnThrown = L1_9820
  function L1_9820(A0_9824)
    if A0_9824.isTargetable then
      Game.UnregisterFromAutoAimManager(A0_9824.id)
      A0_9824.isTargetable = nil
    end
  end
  A0_9819.AfterThrownTimer = L1_9820
  L1_9820 = A0_9819.CanBeMadeTargetable
  function L2_9821(A0_9825, ...)
    local L3_9827, L4_9828
    L3_9827 = _UPVALUE0_
    if L3_9827 then
      L3_9827 = _UPVALUE0_
      L4_9828 = A0_9825
      return L3_9827(L4_9828, ...)
    end
    L3_9827 = true
    return L3_9827
  end
  A0_9819.CanBeMadeTargetable = L2_9821
  L2_9821 = A0_9819.OnShutDown
  function L3_9822(A0_9829, ...)
    if _UPVALUE0_ then
      _UPVALUE0_(A0_9829, ...)
    end
    if A0_9829.isTargetable then
      Game.UnregisterFromAutoAimManager(A0_9829.id)
      A0_9829.isTargetable = nil
    end
  end
  A0_9819.OnShutDown = L3_9822
  L3_9822 = A0_9819.OnReset
  function A0_9819.OnReset(A0_9831, ...)
    if _UPVALUE0_ then
      _UPVALUE0_(A0_9831, ...)
    end
    if A0_9831.isTargetable then
      Game.UnregisterFromAutoAimManager(A0_9831.id)
      A0_9831.isTargetable = nil
    end
  end
end
MakeThrownObjectTargetable = L0_9728
function L0_9728(A0_9833)
  local L1_9834, L2_9835, L3_9836, L4_9837, L5_9838, L6_9839, L7_9840, L8_9841, L9_9842, L10_9843, L11_9844, L12_9845, L13_9846, L14_9847, L15_9848, L16_9849, L17_9850
  A0_9833.spawnedEntity = nil
  L1_9834 = A0_9833.Properties
  if not L1_9834 then
    L1_9834 = {}
    A0_9833.Properties = L1_9834
  end
  L1_9834 = A0_9833.Properties
  L1_9834.bSpawner = false
  L2_9835 = A0_9833.OnDestroy
  function L3_9836(A0_9851, ...)
    if A0_9851.whoSpawnedMe then
      A0_9851.whoSpawnedMe:NotifyRemoval(A0_9851.id)
    end
    if _UPVALUE0_ then
      _UPVALUE0_(A0_9851, ...)
    end
  end
  A0_9833.OnDestroy = L3_9836
  function L3_9836(A0_9853, A1_9854)
    local L2_9855
    L2_9855 = A0_9853.spawnedEntity
    if L2_9855 then
      L2_9855 = A0_9853.spawnedEntity
      if L2_9855 == A1_9854 then
        A0_9853.spawnedEntity = nil
        A0_9853.lastSpawnedEntity = nil
      end
    end
  end
  A0_9833.NotifyRemoval = L3_9836
  L3_9836 = A0_9833.OnReset
  function L4_9837(A0_9856, ...)
    A0_9856.lastSpawnedEntity = nil
    if A0_9856.spawnedEntity then
      System.RemoveEntity(A0_9856.spawnedEntity)
      A0_9856.spawnedEntity = nil
    end
    if A0_9856.whoSpawnedMe then
      System.RemoveEntity(A0_9856.id)
      return
    end
    _UPVALUE0_(A0_9856, ...)
  end
  A0_9833.OnReset = L4_9837
  L4_9837 = A0_9833.OnEditorSetGameMode
  function L5_9838(A0_9858, ...)
    local L2_9860, L3_9861, L4_9862
    A0_9858.lastSpawnedEntity = nil
    L2_9860 = A0_9858.spawnedEntity
    if L2_9860 then
      A0_9858.spawnedEntity = nil
    end
    L2_9860 = _UPVALUE0_
    if L2_9860 then
      L2_9860 = _UPVALUE0_
      L3_9861 = A0_9858
      L4_9862 = ...
      L2_9860(L3_9861, L4_9862)
    end
  end
  A0_9833.OnEditorSetGameMode = L5_9838
  function L5_9838(A0_9863)
    if A0_9863.spawnedEntity then
      return A0_9863.spawnedEntity
    else
      return A0_9863.lastSpawnedEntity
    end
  end
  A0_9833.GetFlowgraphForwardingEntity = L5_9838
  function L5_9838(A0_9864)
    BroadcastEvent(A0_9864, "Spawned")
  end
  A0_9833.Event_Spawned = L5_9838
  L5_9838 = A0_9833.FlowEvents
  if not L5_9838 then
    L5_9838 = {}
    A0_9833.FlowEvents = L5_9838
  end
  L5_9838 = A0_9833.FlowEvents
  L6_9839 = L5_9838.Inputs
  L6_9839 = L6_9839 or {}
  L5_9838.Inputs = L6_9839
  L6_9839 = L5_9838.Outputs
  L6_9839 = L6_9839 or {}
  L5_9838.Outputs = L6_9839
  L6_9839 = {}
  L7_9840, L8_9841 = nil, nil
  for L12_9845, L13_9846 in L9_9842(L10_9843) do
    L6_9839[L12_9845] = L13_9846
  end
  for L12_9845, L13_9846 in L9_9842(L10_9843) do
    L6_9839[L12_9845] = L13_9846
  end
  for L12_9845, L13_9846 in L9_9842(L10_9843) do
    L14_9847 = L5_9838.Inputs
    L14_9847 = L14_9847[L12_9845]
    L15_9848 = L5_9838.Outputs
    L15_9848 = L15_9848[L12_9845]
    L16_9849 = L12_9845 == "Dead"
    L17_9850 = L13_9846
    if type(L17_9850) == "table" then
      L17_9850 = L17_9850[1]
    else
      L17_9850 = nil
    end
    A0_9833["Event_" .. L12_9845] = function(A0_9865, A1_9866, A2_9867)
      local L3_9868
      L3_9868 = _UPVALUE0_
      if L3_9868 then
        if A1_9866 then
          L3_9868 = A1_9866.id
        else
        end
        if L3_9868 == A0_9865.spawnedEntity or A1_9866 == A0_9865 then
          L3_9868 = BroadcastEvent
          L3_9868(A0_9865, _UPVALUE1_)
        end
      end
      L3_9868 = _UPVALUE2_
      if L3_9868 then
        L3_9868 = A0_9865.spawnedEntity
        if L3_9868 then
          if A1_9866 then
            L3_9868 = A0_9865.spawnedEntity
          elseif L3_9868 ~= A1_9866.id then
            L3_9868 = System
            L3_9868 = L3_9868.GetEntity
            L3_9868 = L3_9868(A0_9865.spawnedEntity)
            if _UPVALUE3_ and L3_9868 and L3_9868 ~= A1_9866 then
              _UPVALUE3_(L3_9868, A1_9866, A2_9867)
            end
          end
        end
      else
        L3_9868 = _UPVALUE3_
        if L3_9868 then
          L3_9868 = A0_9865.spawnedEntity
          if not L3_9868 then
            L3_9868 = _UPVALUE3_
            L3_9868(A0_9865, A1_9866, A2_9867)
          end
        end
      end
      L3_9868 = _UPVALUE4_
      if L3_9868 and A1_9866 then
        L3_9868 = A1_9866.id
        if L3_9868 == A0_9865.spawnedEntity then
          A0_9865.spawnedEntity = nil
        end
      end
    end
  end
  A0_9833.Event_Spawn = L9_9842
  A0_9833.Event_Spawn_Internal = L9_9842
  A0_9833.Event_SpawnKeep = L9_9842
  L12_9845 = "bool"
  L9_9842.Spawn = L10_9843
  L9_9842.Spawned = "entity"
end
MakeSpawnable = L0_9728
function L0_9728(A0_9869)
  local L1_9870
  if A0_9869 == nil then
    return
  end
  L1_9870 = A0_9869.Properties
  if L1_9870 == nil then
    L1_9870 = {}
    A0_9869.Properties = L1_9870
  end
  L1_9870 = A0_9869.Properties
  L1_9870 = L1_9870.Physics
  if L1_9870 == nil then
    L1_9870 = A0_9869.Properties
    L1_9870.Physics = {}
  end
  L1_9870 = A0_9869.Properties
  L1_9870 = L1_9870.Physics
  L1_9870.CollisionFiltering = {}
  L1_9870 = A0_9869.Properties
  L1_9870 = L1_9870.Physics
  L1_9870 = L1_9870.CollisionFiltering
  L1_9870.collisionType = {}
  L1_9870.collisionIgnore = {}
  for _FORV_5_, _FORV_6_ in pairs(g_PhysicsCollisionClass) do
    L1_9870.collisionType[_FORV_5_] = 0
    L1_9870.collisionIgnore[_FORV_5_] = 0
  end
end
SetupCollisionFiltering = L0_9728
function L0_9728(A0_9871)
  local L1_9872, L2_9873
  L1_9872 = {}
  L1_9872.collisionClass = 0
  L2_9873 = gcc_coral
  L1_9872.collisionClassIgnore = L2_9873
  L2_9873 = A0_9871.Properties
  L2_9873 = L2_9873.Physics
  if L2_9873 == nil then
    return L1_9872
  end
  L2_9873 = A0_9871.Properties
  L2_9873 = L2_9873.Physics
  L2_9873 = L2_9873.CollisionFiltering
  if L2_9873 == nil then
    return L1_9872
  end
  L2_9873 = A0_9871.Properties
  L2_9873 = L2_9873.Physics
  L2_9873 = L2_9873.CollisionFiltering
  for _FORV_6_, _FORV_7_ in pairs(L2_9873.collisionType) do
    if g_PhysicsCollisionClass[_FORV_6_] ~= nil and _FORV_7_ == 1 then
      L1_9872.collisionClass = L1_9872.collisionClass + g_PhysicsCollisionClass[_FORV_6_]
    end
  end
  for _FORV_6_, _FORV_7_ in pairs(L2_9873.collisionIgnore) do
    if g_PhysicsCollisionClass[_FORV_6_] ~= nil and _FORV_7_ == 1 then
      L1_9872.collisionClassIgnore = L1_9872.collisionClassIgnore + g_PhysicsCollisionClass[_FORV_6_]
    end
  end
  return L1_9872
end
GetCollisionFiltering = L0_9728
function L0_9728(A0_9874, A1_9875)
  if A0_9874.Properties.Physics ~= nil and A0_9874.Properties.Physics.CollisionFiltering ~= nil then
    A0_9874:SetPhysicParams(PHYSICPARAM_COLLISION_CLASS, A1_9875)
  end
end
ApplyCollisionFiltering = L0_9728
L0_9728 = EntityCommon
function L1_9729(A0_9876, A1_9877, A2_9878, A3_9879, A4_9880)
  local L5_9881, L6_9882, L7_9883, L8_9884, L9_9885, L10_9886, L11_9887, L12_9888, L13_9889, L14_9890, L15_9891, L16_9892, L17_9893, L18_9894
  L5_9881 = A2_9878.Mass
  L6_9882 = A2_9878.Density
  if A3_9879 and A3_9879 == 0 then
    L5_9881 = 0
    L6_9882 = 0
  end
  L7_9883 = nil
  if A4_9880 ~= nil then
    L7_9883 = A4_9880
  else
    L8_9884 = A2_9878.bArticulated
    if L8_9884 == 1 then
      L7_9883 = PE_ARTICULATED
    else
      L8_9884 = A2_9878.bRigidBody
      if L8_9884 == 1 then
        L7_9883 = PE_RIGID
      else
        L7_9883 = PE_STATIC
      end
    end
  end
  L8_9884 = EntityCommon
  L8_9884 = L8_9884.TempPhysParams
  L8_9884.density = L6_9882
  L8_9884.mass = L5_9881
  L8_9884.flags = 0
  if L9_9885 then
    L8_9884.CGFprops = ""
    for L12_9888, L13_9889 in L9_9885(L10_9886) do
      if L14_9890 == "table" then
        for L17_9893, L18_9894 in L14_9890(L15_9891) do
          if L18_9894 ~= "" then
            L8_9884.CGFprops = L8_9884.CGFprops .. L17_9893 .. "=" .. L18_9894 .. "\n"
          end
        end
      elseif L13_9889 ~= "" then
        L17_9893 = L13_9889
        L18_9894 = "\n"
        L8_9884.CGFprops = L14_9890
      end
    end
  end
  L9_9885(L10_9886, L11_9887, L12_9888, L13_9889)
  L18_9894 = L11_9887(L12_9888)
  L9_9885(L10_9886, L11_9887, L12_9888, L13_9889, L14_9890, L15_9891, L16_9892, L17_9893, L18_9894, L11_9887(L12_9888))
  if L5_9881 > 0 or L6_9882 > 0 then
    L9_9885.collisionClass = L10_9886
    L10_9886(L11_9887, L12_9888)
  end
  if L9_9885 then
    for L14_9890, L15_9891 in next, L10_9886, nil do
      L10_9886[L14_9890] = nil
    end
    for L14_9890, L15_9891 in next, L9_9885, nil do
      if (L14_9890 ~= "max_time_step" or L15_9891 < 0.0199 or L15_9891 > 0.0201) and (L14_9890 ~= "sleep_speed" or L15_9891 < 0.0399 or L15_9891 > 0.0401) then
        L10_9886[L14_9890] = L15_9891
      end
    end
    L11_9887(L12_9888, L13_9889, L14_9890)
  end
  if L9_9885 then
    L10_9886(L11_9887, L12_9888, L13_9889)
  end
  if L10_9886 then
    if L11_9887 == 1 then
      L14_9890.foreignFlags = L15_9891
      L11_9887(L12_9888, L13_9889, L14_9890)
    end
  end
  L11_9887.flags = 0
  if L12_9888 == 1 then
    L11_9887.flags = L12_9888
  end
  if L12_9888 then
    if L12_9888 then
      if L12_9888 == 1 then
        L11_9887.flags = L12_9888
      end
    end
  end
  if L12_9888 then
    if L12_9888 then
      if L12_9888 == 1 then
        L11_9887.flags = L12_9888
      end
    end
  end
  if L12_9888 ~= nil then
  elseif L12_9888 == 0 then
    L11_9887.flags = L12_9888
  end
  if L12_9888 then
    if L12_9888 then
      L11_9887.flags = L12_9888
    end
  end
  L11_9887.flags_mask = L12_9888
  L12_9888(L13_9889, L14_9890, L15_9891)
  L11_9887.arkFlags = 0
  if L12_9888 == 1 then
    L11_9887.arkFlags = L12_9888
  end
  L12_9888(L13_9889, L14_9890, L15_9891)
  if L12_9888 == 0 then
    L12_9888(L13_9889, L14_9890)
  else
    L12_9888(L13_9889, L14_9890)
  end
end
L0_9728.PhysicalizeRigid = L1_9729
function L0_9728(A0_9895, A1_9896)
  return A0_9895:GetName() < A1_9896:GetName()
end
CompareEntitiesByName = L0_9728
function L0_9728(A0_9897)
  function CompareEntitiesByDistanceFromPoint(A0_9898, A1_9899)
    distance1 = DistanceSqVectors(A0_9898:GetWorldPos(), _UPVALUE0_)
    distance2 = DistanceSqVectors(A1_9899:GetWorldPos(), _UPVALUE0_)
    return distance1 > distance2
  end
  return CompareEntitiesByDistanceFromPoint
end
MakeCompareEntitiesByDistanceFromPoint = L0_9728
function L0_9728(A0_9900, A1_9901)
  local L2_9902
  if A1_9901 and A1_9901.AITerritoryAndWave then
    L2_9902 = A1_9901.AITerritoryAndWave.aiwave_Wave
  end
  if L2_9902 and L2_9902 ~= "<None>" then
    AddBookmarkedToWave(A0_9900, L2_9902)
    return false
  end
  return true
end
OnEntityBookmarkCreated = L0_9728
