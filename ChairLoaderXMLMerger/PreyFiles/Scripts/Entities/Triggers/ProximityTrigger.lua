ProximityTrigger = {
  Properties = {
    DimX = 5,
    DimY = 5,
    DimZ = 5,
    bEnabled = 1,
    EnterDelay = 0,
    ExitDelay = 0,
    bTriggerAny = 0,
    bTriggerOnPlayer = 1,
    bTriggerOnAI = 0,
    bTriggerOnSpecialAI = 0,
    TriggerOnSelectedEntity = "None",
    bRemoveOnTrigger = 0,
    bTriggerOnce = 0,
    ScriptCommand = "",
    PlaySequence = "",
    bInVehicleOnly = 0,
    bOnlyOneEntity = 0,
    UsableMessage = "",
    bActivateWithUseButton = 0,
    MultiplayerOptions = {bNetworked = 0, bPerPlayer = 0}
  },
  Client = {},
  Server = {},
  Editor = {
    Model = "Editor/Objects/T.cgf",
    Icon = "Trigger.bmp",
    ShowBounds = 1,
    IsScalable = false,
    IsRotatable = false
  }
}
Net.Expose({
  Class = ProximityTrigger,
  ClientMethods = {
    ClEnter = {
      RELIABLE_ORDERED,
      PRE_ATTACH,
      ENTITYID,
      INT8
    },
    ClLeave = {
      RELIABLE_ORDERED,
      PRE_ATTACH,
      ENTITYID,
      INT8
    }
  },
  ServerMethods = {
    SvRequestUse = {
      RELIABLE_ORDERED,
      PRE_ATTACH,
      ENTITYID
    }
  },
  ServerProperties = {}
})
function ProximityTrigger.OnPropertyChange(A0_8616)
  A0_8616:OnReset()
end
function ProximityTrigger.OnReset(A0_8617)
  local L1_8618, L2_8619, L3_8620, L4_8621
  A0_8617.bUsesExactSelectedEntity = false
  A0_8617.bUsesWildcardSelectedEntity = false
  if L1_8618 ~= "None" then
    if L1_8618 ~= "" then
      if L1_8618 and L1_8618 > 1 then
        if L1_8618 < 5 then
          L4_8621 = A0_8617.GetName
          L4_8621 = L4_8621(A0_8617)
          L2_8619(L3_8620, L4_8621, L4_8621(A0_8617))
        end
        A0_8617.bUsesWildcardSelectedEntity = true
        L4_8621 = 1
        A0_8617.stringRootSelectedEntity = L2_8619
      else
        A0_8617.bUsesExactSelectedEntity = true
      end
    end
  end
  if L1_8618 then
    for L4_8621, _FORV_5_ in L1_8618(L2_8619) do
      A0_8617:KillTimer(L4_8621)
    end
  end
  A0_8617.timerId = 0
  A0_8617.enabled = nil
  L1_8618 = L1_8618 ~= 0
  A0_8617.usable = L1_8618
  L1_8618 = L1_8618 ~= 0
  A0_8617.triggerOnce = L1_8618
  L1_8618 = L1_8618 == 0
  A0_8617.localOnly = L1_8618
  L1_8618 = L1_8618 ~= 0
  A0_8617.perPlayer = L1_8618
  A0_8617.isServer = L1_8618
  A0_8617.isClient = L1_8618
  A0_8617.inside = L1_8618
  A0_8617.timers = L1_8618
  if not L1_8618 then
    A0_8617.triggeredPP = L1_8618
    A0_8617.triggeredOncePP = L1_8618
  else
    L4_8621 = 0
    L1_8618(L2_8619, L3_8620, L4_8621)
  end
  A0_8617.triggeredOnce = nil
  A0_8617.triggered = nil
  A0_8617.insideCount = 0
  L1_8618.x = L2_8619
  L1_8618.y = L2_8619
  L1_8618.z = L2_8619
  L2_8619.x = L3_8620
  L2_8619.y = L3_8620
  L2_8619.z = L3_8620
  L4_8621 = A0_8617
  L3_8620(L4_8621, L1_8618, L2_8619)
  L4_8621 = A0_8617
  L3_8620(L4_8621)
  L4_8621 = A0_8617
  L3_8620(L4_8621, ENTITY_UPDATE_PHYSICS)
  L4_8621 = A0_8617
  L3_8620(L4_8621, false)
end
function ProximityTrigger.Server.OnStartGame(A0_8622)
  A0_8622:Enable(tonumber(A0_8622.Properties.bEnabled) ~= 0)
  A0_8622:RegisterForAreaEvents(1)
  A0_8622:ActivateOutput("IsInside", 0)
end
function ProximityTrigger.Enable(A0_8623, A1_8624)
  A0_8623.enabled = A1_8624
  if not A1_8624 then
    A0_8623.inside = {}
  end
end
function ProximityTrigger.OnSpawn(A0_8625)
  A0_8625:OnReset()
end
function ProximityTrigger.OnDestroy(A0_8626)
  local L1_8627
end
function ProximityTrigger.OnSave(A0_8628, A1_8629)
  local L2_8630
  L2_8630 = A0_8628.enabled
  A1_8629.enabled = L2_8630
  L2_8630 = A0_8628.triggered
  A1_8629.triggered = L2_8630
  L2_8630 = A0_8628.triggeredOnce
  A1_8629.triggeredOnce = L2_8630
end
function ProximityTrigger.OnLoad(A0_8631, A1_8632)
  A0_8631:Enable(A1_8632.enabled)
  A0_8631.triggered = A1_8632.triggered
  A0_8631.triggeredOnce = A1_8632.triggeredOnce
end
function ProximityTrigger.Event_Enter(A0_8633, A1_8634)
  if not A0_8633.enabled then
    return
  end
  if A0_8633.triggerOnce then
    if A0_8633.localOnly then
      if A0_8633.triggeredOnce then
        return
      end
    elseif A0_8633.perPlayer and A0_8633.triggeredOncePP[A1_8634] then
      return
    elseif not A0_8633.perPlayer and A0_8633.triggeredOnce then
      return
    end
  end
  A0_8633.triggered = true
  A0_8633.triggeredOnce = true
  if not A0_8633.localOnly and A1_8634 then
    A0_8633.triggeredPP[A1_8634] = true
    A0_8633.triggeredOncePP[A1_8634] = true
  end
  A0_8633:Trigger(A1_8634, A0_8633.insideCount)
  A0_8633:ActivateOutput("Enter", A1_8634 or NULL_ENTITY)
  if not A0_8633.localOnly and A0_8633.isServer then
    A0_8633.otherClients:ClEnter(g_localChannelId, A1_8634 or NULL_ENTITY, A0_8633.insideCount)
  end
end
function ProximityTrigger.Client.ClEnter(A0_8635, A1_8636, A2_8637)
  if not A0_8635.enabled then
    return
  end
  A0_8635:Trigger(A1_8636, A2_8637)
  A0_8635:ActivateOutput("Enter", A1_8636)
end
function ProximityTrigger.Event_Leave(A0_8638, A1_8639)
  if not A0_8638.enabled then
    return
  end
  if A0_8638.localOnly and not A0_8638.triggered then
    return
  end
  if A0_8638.perPlayer then
    if not A0_8638.localOnly and A1_8639 and not A0_8638.triggeredPP[A1_8639] then
      return
    end
  elseif not A0_8638.triggered then
    return
  end
  if A0_8638.insideCount == 0 then
    A0_8638.triggered = nil
  end
  if not A0_8638.localOnly and A1_8639 and A0_8638.insideCount == 0 then
    A0_8638.triggeredPP[A1_8639] = nil
  end
  A0_8638:ActivateOutput("Sender", A1_8639 or NULL_ENTITY)
  A0_8638:ActivateOutput("IsInside", A0_8638.insideCount)
  A0_8638:ActivateOutput("Leave", A1_8639 or NULL_ENTITY)
  if not A0_8638.localOnly and A0_8638.isServer then
    A0_8638.otherClients:ClLeave(g_localChannelId, A1_8639 or NULL_ENTITY, A0_8638.insideCount)
  end
end
function ProximityTrigger.Client.ClLeave(A0_8640, A1_8641, A2_8642)
  if not A0_8640.enabled then
    return
  end
  A0_8640:ActivateOutput("Sender", A1_8641)
  A0_8640:ActivateOutput("IsInside", A2_8642)
  A0_8640:ActivateOutput("Leave", A1_8641)
end
function ProximityTrigger.Event_Enable(A0_8643)
  A0_8643:Enable(true)
  A0_8643:ActivateOutput("IsInside", A0_8643.insideCount)
  BroadcastEvent(A0_8643, "Enable")
end
function ProximityTrigger.Event_Disable(A0_8644)
  A0_8644:Enable(false)
  BroadcastEvent(A0_8644, "Disable")
end
function ProximityTrigger.CreateTimer(A0_8645, A1_8646, A2_8647, A3_8648)
  local L4_8649
  L4_8649 = A0_8645.timerId
  if L4_8649 > 1023 then
    L4_8649 = 0
  end
  L4_8649 = L4_8649 + 1
  A0_8645.timerId = L4_8649
  if A3_8648 then
    L4_8649 = L4_8649 + 1024
  end
  A0_8645.timers[L4_8649] = A1_8646
  A0_8645:SetTimer(L4_8649, A2_8647)
end
function ProximityTrigger.Client.OnTimer(A0_8650, A1_8651, A2_8652)
  if A0_8650.localOnly and not A0_8650.isServer then
    A0_8650:OnTimer(A1_8651, A2_8652)
  end
end
function ProximityTrigger.Server.OnTimer(A0_8653, A1_8654, A2_8655)
  A0_8653:OnTimer(A1_8654, A2_8655)
end
function ProximityTrigger.OnTimer(A0_8656, A1_8657, A2_8658)
  local L3_8659
  if A1_8657 == 2048 then
    L3_8659 = A0_8656.CheckAIDeaths
    L3_8659(A0_8656)
    return
  end
  L3_8659 = A0_8656.timers
  L3_8659 = L3_8659[A1_8657]
  if not L3_8659 then
    return
  end
  if A1_8657 > 1023 then
    A0_8656:Event_Leave(L3_8659)
  else
    A0_8656:Event_Enter(L3_8659)
  end
end
function ProximityTrigger.CheckAIDeaths(A0_8660)
  local L1_8661, L2_8662, L3_8663, L4_8664, L5_8665
  L1_8661 = A0_8660.enabled
  if not L1_8661 then
    return
  end
  L1_8661 = 0
  for L5_8665, _FORV_6_ in L2_8662(L3_8663) do
    if System.GetEntity(L5_8665) ~= nil and System.GetEntity(L5_8665).ai ~= nil and System.GetEntity(L5_8665).lastHealth ~= nil then
      if 0 >= System.GetEntity(L5_8665).lastHealth then
        A0_8660.inside[L5_8665] = nil
      end
    else
      L1_8661 = L1_8661 + 1
    end
  end
  if L1_8661 ~= L2_8662 then
    A0_8660.insideCount = L1_8661
    L5_8665 = A0_8660.insideCount
    L2_8662(L3_8663, L4_8664, L5_8665)
  end
  if L1_8661 ~= 0 then
    L2_8662(L3_8663)
  else
    L2_8662[2048] = false
  end
end
function ProximityTrigger.CreateAIDeathsCheckTrigger(A0_8666)
  A0_8666.timers[2048] = true
  A0_8666:SetTimer(2048, 3000)
end
function ProximityTrigger.Server.SvRequestUse(A0_8667, A1_8668)
  local L2_8669
  L2_8669 = System
  L2_8669 = L2_8669.GetEntity
  L2_8669 = L2_8669(A1_8668)
  if L2_8669 then
    A0_8667:OnUsed(L2_8669)
  end
end
function ProximityTrigger.OnUsed(A0_8670, A1_8671)
  if not A0_8670:CanTrigger(A1_8671) then
    return
  end
  Log("%s:OnUsed(%s)", A0_8670:GetName(), EntityName(A1_8671))
  A0_8670:LockUsability(false)
  BroadcastEvent(A0_8670, "OnUsed")
  A0_8670:ActivateOutput("Sender", A1_8671.id)
  if A0_8670.localOnly or A0_8670.isServer then
    A0_8670:CreateTimer(A1_8671.id, A0_8670.Properties.EnterDelay * 1000)
  else
    A0_8670.server:SvRequestUse(A1_8671.id)
  end
end
function ProximityTrigger.Trigger(A0_8672, A1_8673, A2_8674)
  local L3_8675
  L3_8675 = A0_8672.enabled
  if not L3_8675 then
    return
  end
  L3_8675 = A0_8672.ActivateOutput
  L3_8675(A0_8672, "IsInside", A2_8674)
  L3_8675 = A0_8672.Properties
  L3_8675 = L3_8675.ScriptCommand
  if L3_8675 then
    L3_8675 = A0_8672.Properties
    L3_8675 = L3_8675.ScriptCommand
    if L3_8675 ~= "" then
      L3_8675 = loadstring
      L3_8675 = L3_8675(A0_8672.Properties.ScriptCommand)
      if L3_8675 ~= nil then
        L3_8675()
      end
    end
  end
  L3_8675 = A0_8672.Properties
  L3_8675 = L3_8675.PlaySequence
  if L3_8675 ~= "" then
    L3_8675 = Movie
    L3_8675 = L3_8675.PlaySequence
    L3_8675(A0_8672.Properties.PlaySequence)
  end
  L3_8675 = A0_8672.ActivateOutput
  L3_8675(A0_8672, "Sender", A1_8673 or NULL_ENTITY)
  L3_8675 = A0_8672.Properties
  L3_8675 = L3_8675.bRemoveOnTrigger
  if L3_8675 == 1 then
    L3_8675 = Game
    L3_8675 = L3_8675.IsPlayer
    L3_8675 = L3_8675(A1_8673)
    if L3_8675 == false then
      L3_8675 = System
      L3_8675 = L3_8675.RemoveEntity
      L3_8675(A1_8673)
    end
  end
end
function ProximityTrigger.EnteredArea(A0_8676, A1_8677, A2_8678)
  if not A0_8676:CanTrigger(A1_8677, A2_8678) then
    return
  end
  if tonumber(A0_8676.Properties.bOnlyOneEntity) ~= 0 and 0 < A0_8676.insideCount then
    return
  end
  A0_8676.inside[A1_8677.id] = true
  if 0 > A0_8676.insideCount then
    A0_8676.insideCount = 0
  end
  A0_8676.insideCount = A0_8676.insideCount + 1
  if A0_8676.enabled then
    A0_8676:ActivateOutput("IsInside", A0_8676.insideCount)
  end
  if not A1_8677.ai and A0_8676.Properties.bActivateWithUseButton ~= 0 then
    return
  end
  A0_8676:CreateTimer(A1_8677.id, A0_8676.Properties.EnterDelay * 1000)
  if A1_8677.ai and A0_8676.timers[2048] ~= true then
    A0_8676:CreateAIDeathsCheckTrigger()
  end
end
function ProximityTrigger.LeftArea(A0_8679, A1_8680, A2_8681)
  if not A0_8679:CanTrigger(A1_8680, A2_8681) then
    return
  end
  A0_8679.inside[A1_8680.id] = nil
  A0_8679.insideCount = A0_8679.insideCount - 1
  if A0_8679.insideCount < 0 then
    A0_8679.insideCount = 0
  end
  if A0_8679.enabled then
    A0_8679:ActivateOutput("IsInside", A0_8679.insideCount)
  end
  if A0_8679.Properties.ExitDelay == 0 then
    A0_8679.Properties.ExitDelay = 0.01
  end
  A0_8679:CreateTimer(A1_8680.id, A0_8679.Properties.ExitDelay * 1000, true)
end
function ProximityTrigger.Server.OnEnterArea(A0_8682, A1_8683, A2_8684)
  if A0_8682:CanTrigger(A1_8683) then
    A0_8682:EnteredArea(A1_8683, A2_8684)
  end
end
function ProximityTrigger.Server.OnLeaveArea(A0_8685, A1_8686, A2_8687)
  A0_8685:LeftArea(A1_8686, A2_8687)
end
function ProximityTrigger.Client.OnEnterArea(A0_8688, A1_8689, A2_8690)
  if not A0_8688:CanTrigger(A1_8689) then
    return
  end
  if A1_8689.actor and A0_8688.usable and A0_8688.enabled then
    A0_8688:LockUsability(true)
  end
  if not A0_8688.localOnly or A0_8688.isServer then
    return
  end
  A0_8688:EnteredArea(A1_8689, A2_8690)
end
function ProximityTrigger.Client.OnLeaveArea(A0_8691, A1_8692, A2_8693)
  if A1_8692.actor and A0_8691.usable and A0_8691.enabled then
    A0_8691:LockUsability(false)
  end
  if not A0_8691.localOnly or A0_8691.isServer then
    return
  end
  A0_8691:LeftArea(A1_8692, A2_8693)
end
function ProximityTrigger.CanTrigger(A0_8694, A1_8695)
  local L2_8696
  L2_8696 = A0_8694.Properties
  if A1_8695.ai and A1_8695.lastHealth and A1_8695.lastHealth <= 0 then
    return false
  end
  if L2_8696.bInVehicleOnly ~= 0 and not A1_8695.vehicleId then
    return false
  end
  if L2_8696.bTriggerAny ~= 0 then
    return true
  end
  if L2_8696.bTriggerOnPlayer ~= 0 and A1_8695 == g_localActor then
    return true
  end
  if L2_8696.bTriggerOnAI ~= 0 and A1_8695.ai then
    return true
  end
  if L2_8696.bTriggerOnSpecialAI ~= 0 and A1_8695.ai and A1_8695.Properties.special ~= 0 then
    return true
  end
  if A0_8694.bUsesExactSelectedEntity and A1_8695:GetName() == L2_8696.TriggerOnSelectedEntity then
    return true
  end
  if A0_8694.bUsesWildcardSelectedEntity and string.find(A1_8695:GetName(), A0_8694.stringRootSelectedEntity) == 1 then
    return true
  end
  return false
end
function ProximityTrigger.IsUsable(A0_8697, A1_8698)
  return A0_8697.usable and A0_8697.enabled
end
function ProximityTrigger.LockUsability(A0_8699, A1_8700)
  local L2_8701
  L2_8701 = g_localActor
  if L2_8701 then
    if A1_8700 then
      L2_8701.actor:SetExtensionParams("Interactor", {
        locker = A0_8699.id,
        lockId = A0_8699.id,
        lockIdx = 1
      })
    else
      L2_8701.actor:SetExtensionParams("Interactor", {
        locker = A0_8699.id,
        lockId = NULL_ENTITY,
        lockIdx = 0
      })
    end
  end
end
function ProximityTrigger.GetUsableMessage(A0_8702)
  local L1_8703
  L1_8703 = A0_8702.Properties
  L1_8703 = L1_8703.UsableMessage
  L1_8703 = L1_8703 or ""
  return L1_8703
end
ProximityTrigger.FlowEvents = {
  Inputs = {
    Disable = {
      ProximityTrigger.Event_Disable,
      "bool"
    },
    Enable = {
      ProximityTrigger.Event_Enable,
      "bool"
    },
    Enter = {
      ProximityTrigger.Event_Enter,
      "bool"
    },
    Leave = {
      ProximityTrigger.Event_Leave,
      "bool"
    }
  },
  Outputs = {
    IsInside = "int",
    Disable = "bool",
    Enable = "bool",
    Enter = "entity",
    Leave = "entity",
    Sender = "entity",
    Faction = "string",
    OnUsed = "bool"
  }
}
