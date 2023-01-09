AreaTrigger = {
  Properties = {
    bEnabled = 1,
    bTriggerOnce = 0,
    bOnlyPlayers = 1,
    bOnlyLocalPlayer = 0,
    ScriptCommand = "",
    PlaySequence = "",
    bInVehicleOnly = 0,
    MultiplayerOptions = {bNetworked = 0, bPerPlayer = 0}
  },
  Client = {},
  Server = {},
  Editor = {
    Model = "Editor/Objects/T.cgf",
    Icon = "AreaTrigger.bmp",
    IsScalable = false,
    IsRotatable = true
  }
}
Net.Expose({
  Class = AreaTrigger,
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
  ServerMethods = {},
  ServerProperties = {}
})
function AreaTrigger.OnPropertyChange(A0_8498)
  A0_8498:OnReset()
end
function AreaTrigger.OnReset(A0_8499)
  A0_8499.enabled = nil
  A0_8499.triggerOnce = tonumber(A0_8499.Properties.bTriggerOnce) ~= 0
  A0_8499.localOnly = A0_8499.Properties.MultiplayerOptions.bNetworked == 0
  A0_8499.perPlayer = tonumber(A0_8499.Properties.MultiplayerOptions.bPerPlayer) ~= 0
  A0_8499.isServer = CryAction.IsServer()
  A0_8499.isClient = CryAction.IsClient()
  A0_8499.inside = {}
  A0_8499.insideCount = 0
  if not A0_8499.localOnly then
    A0_8499.triggeredPP = {}
    A0_8499.triggeredOncePP = {}
  else
    A0_8499:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
  end
  A0_8499.triggeredOnce = nil
  A0_8499.triggered = nil
  A0_8499:Enable(false)
end
function AreaTrigger.Server.OnStartGame(A0_8500)
  A0_8500:Enable(tonumber(A0_8500.Properties.bEnabled) ~= 0)
  A0_8500:ActivateOutput("NrOfEntitiesInside", 0)
end
function AreaTrigger.Enable(A0_8501, A1_8502)
  A0_8501.enabled = A1_8502
  A0_8501:RegisterForAreaEvents(A1_8502 and 1 or 0)
end
function AreaTrigger.OnSpawn(A0_8503)
  A0_8503:OnReset()
end
function AreaTrigger.OnSave(A0_8504, A1_8505)
  local L2_8506
  L2_8506 = A0_8504.enabled
  A1_8505.enabled = L2_8506
  L2_8506 = A0_8504.triggered
  A1_8505.triggered = L2_8506
  L2_8506 = A0_8504.triggeredOnce
  A1_8505.triggeredOnce = L2_8506
end
function AreaTrigger.OnLoad(A0_8507, A1_8508)
  local L2_8509
  L2_8509 = A1_8508.enabled
  A0_8507.enabled = L2_8509
  L2_8509 = A1_8508.triggered
  A0_8507.triggered = L2_8509
  L2_8509 = A1_8508.triggeredOnce
  A0_8507.triggeredOnce = L2_8509
end
function AreaTrigger.CanTrigger(A0_8510, A1_8511)
  if not System.GetEntity(A1_8511) then
    return
  end
  if A0_8510.Properties.bOnlyPlayers ~= 0 and (not System.GetEntity(A1_8511).actor or not System.GetEntity(A1_8511).actor:IsPlayer()) then
    return false
  end
  if A0_8510.Properties.bOnlyLocalPlayer ~= 0 and System.GetEntity(A1_8511) ~= g_localActor then
    return false
  end
  if A0_8510.Properties.bInVehicleOnly ~= 0 and not System.GetEntity(A1_8511).vehicleId then
    return false
  end
  return true
end
function AreaTrigger.Trigger(A0_8512, A1_8513, A2_8514)
  local L3_8515
  L3_8515 = A0_8512.ActivateOutput
  L3_8515(A0_8512, "NrOfEntitiesInside", A0_8512.insideCount)
  L3_8515 = A0_8512.ActivateOutput
  L3_8515(A0_8512, "Sender", A1_8513 or NULL_ENTITY)
  if A2_8514 then
    L3_8515 = A0_8512.Properties
    L3_8515 = L3_8515.ScriptCommand
    if L3_8515 then
      L3_8515 = A0_8512.Properties
      L3_8515 = L3_8515.ScriptCommand
      if L3_8515 ~= "" then
        L3_8515 = loadstring
        L3_8515 = L3_8515(A0_8512.Properties.ScriptCommand)
        if L3_8515 ~= nil then
          L3_8515()
        end
      end
    end
    L3_8515 = A0_8512.Properties
    L3_8515 = L3_8515.PlaySequence
    if L3_8515 ~= "" then
      L3_8515 = Movie
      L3_8515 = L3_8515.PlaySequence
      L3_8515(A0_8512.Properties.PlaySequence)
    end
  end
end
function AreaTrigger.EnteredArea(A0_8516, A1_8517, A2_8518)
  if not A0_8516:CanTrigger(A1_8517.id, A2_8518) then
    return
  end
  A0_8516.inside[A1_8517.id] = true
  A0_8516.insideCount = A0_8516.insideCount + 1
  A0_8516:Event_Enter(A1_8517.id)
end
function AreaTrigger.LeftArea(A0_8519, A1_8520, A2_8521)
  if not A0_8519:CanTrigger(A1_8520.id, A2_8521) then
    return
  end
  A0_8519.inside[A1_8520.id] = nil
  A0_8519.insideCount = A0_8519.insideCount - 1
  A0_8519:Event_Leave(A1_8520.id)
end
function AreaTrigger.Server.OnEnterArea(A0_8522, A1_8523, A2_8524)
  if A0_8522:CanTrigger(A1_8523.id) then
    A0_8522:EnteredArea(A1_8523, A2_8524)
  end
end
function AreaTrigger.Server.OnLeaveArea(A0_8525, A1_8526, A2_8527)
  A0_8525:LeftArea(A1_8526, A2_8527)
end
function AreaTrigger.Client.OnEnterArea(A0_8528, A1_8529, A2_8530)
  if not A0_8528:CanTrigger(A1_8529.id) then
    return
  end
  if not A0_8528.localOnly or A0_8528.isServer then
    return
  end
  A0_8528:EnteredArea(A1_8529, A2_8530)
end
function AreaTrigger.Client.OnLeaveArea(A0_8531, A1_8532, A2_8533)
  if not A0_8531.localOnly or A0_8531.isServer then
    return
  end
  A0_8531:LeftArea(A1_8532, A2_8533)
end
function AreaTrigger.Event_Enter(A0_8534, A1_8535)
  if not A0_8534.enabled then
    return
  end
  if A0_8534.triggerOnce then
    if A0_8534.localOnly then
      if A0_8534.triggeredOnce then
        return
      end
    elseif A0_8534.perPlayer and A0_8534.triggeredOncePP[A1_8535] then
      return
    elseif not A0_8534.perPlayer and A0_8534.triggeredOnce then
      return
    end
  end
  A0_8534.triggered = true
  A0_8534.triggeredOnce = true
  if not A0_8534.localOnly and A1_8535 then
    A0_8534.triggeredPP[A1_8535] = true
    A0_8534.triggeredOncePP[A1_8535] = true
  end
  A0_8534:Trigger(A1_8535, true)
  A0_8534:ActivateOutput("Enter", A1_8535 or NULL_ENTITY)
  if not A0_8534.localOnly and A0_8534.isServer then
    A0_8534.otherClients:ClEnter(g_localChannelId, A1_8535 or NULL_ENTITY, A0_8534.insideCount)
  end
end
function AreaTrigger.Event_Leave(A0_8536, A1_8537)
  if not A0_8536.enabled then
    return
  end
  if A0_8536.localOnly and not A0_8536.triggered then
    return
  end
  if A0_8536.perPlayer then
    if not A0_8536.localOnly and A1_8537 and not A0_8536.triggeredPP[A1_8537] then
      return
    end
  elseif not A0_8536.triggered then
    return
  end
  if A0_8536.insideCount == 0 then
    A0_8536.triggered = nil
  end
  if not A0_8536.localOnly and A1_8537 and A0_8536.insideCount == 0 then
    A0_8536.triggeredPP[A1_8537] = nil
  end
  A0_8536:Trigger(A1_8537, false)
  A0_8536:ActivateOutput("Leave", A1_8537 or NULL_ENTITY)
  if not A0_8536.localOnly and A0_8536.isServer then
    A0_8536.otherClients:ClLeave(g_localChannelId, A1_8537 or NULL_ENTITY, A0_8536.insideCount)
  end
end
function AreaTrigger.Client.ClEnter(A0_8538, A1_8539, A2_8540)
  A0_8538.insideCount = A2_8540
  A0_8538.inside[A1_8539] = true
  A0_8538:Trigger(A1_8539, true)
  A0_8538:ActivateOutput("Enter", A1_8539)
end
function AreaTrigger.Client.ClLeave(A0_8541, A1_8542, A2_8543)
  A0_8541.insideCount = A2_8543
  A0_8541.inside[A1_8542] = nil
  A0_8541:Trigger(A1_8542, false)
  A0_8541:ActivateOutput("Sender", A1_8542)
  A0_8541:ActivateOutput("NrOfEntitiesInside", A2_8543)
  A0_8541:ActivateOutput("Leave", A1_8542)
end
function AreaTrigger.Event_Enable(A0_8544)
  local L1_8545
  L1_8545 = A0_8544.Enable
  L1_8545(A0_8544, true)
  L1_8545 = next
  L1_8545 = L1_8545(A0_8544.inside)
  if L1_8545 then
    A0_8544:Event_Enter(L1_8545)
  end
  A0_8544:ActivateOutput("NrOfEntitiesInside", A0_8544.insideCount)
  BroadcastEvent(A0_8544, "Enable")
end
function AreaTrigger.Event_Disable(A0_8546)
  A0_8546:Enable(false)
  BroadcastEvent(A0_8546, "Disable")
end
AreaTrigger.FlowEvents = {
  Inputs = {
    Disable = {
      AreaTrigger.Event_Disable,
      "bool"
    },
    Enable = {
      AreaTrigger.Event_Enable,
      "bool"
    },
    Enter = {
      AreaTrigger.Event_Enter,
      "bool"
    },
    Leave = {
      AreaTrigger.Event_Leave,
      "bool"
    }
  },
  Outputs = {
    Disable = "bool",
    Enable = "bool",
    Enter = "entity",
    Leave = "entity",
    NrOfEntitiesInside = "int",
    Sender = "entity",
    Faction = "string"
  }
}
