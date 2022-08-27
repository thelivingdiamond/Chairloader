ForbiddenArea = {
  Server = {},
  Client = {},
  Editor = {
    Icon = "forbiddenarea.bmp"
  },
  type = "ForbiddenArea",
  Properties = {
    bEnabled = 1,
    bReversed = 1,
    DamagePerSecond = 35,
    esDamageType = "punish",
    Delay = 5,
    bShowWarning = 1,
    bInfiniteFall = 0,
    teamName = "",
    overrideTimerLength = 0,
    bResetsObjects = 1,
    MultiplayerOptions = {bNetworked = 0}
  },
  owner = 0,
  bTimerStarted = false,
  TIMER_LENGTH = 1000
}
Net.Expose({
  Class = ForbiddenArea,
  ClientMethods = {
    ClSetOwner = {
      RELIABLE_UNORDERED,
      NO_ATTACH,
      ENTITYID
    }
  },
  ServerMethods = {
    SvSetOwner = {
      RELIABLE_UNORDERED,
      NO_ATTACH,
      ENTITYID
    }
  }
})
ForbiddenArea.AUDIO_SIGNAL = nil
function ForbiddenArea.OnSpawn(A0_6438)
  if A0_6438.Properties.MultiplayerOptions.bNetworked == 0 then
    A0_6438:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
  end
end
function ForbiddenArea.Server.SvSetOwner(A0_6439, A1_6440)
  A0_6439.owner = A1_6440
  A0_6439.otherClients:ClSetOwner(System.GetEntity(A1_6440).actor:GetChannel(), A1_6440 or NULL_ENTITY)
end
function ForbiddenArea.Client.ClSetOwner(A0_6441, A1_6442)
  A0_6441.owner = A1_6442
end
function ForbiddenArea.OnPropertyChange(A0_6443)
  A0_6443:OnReset()
end
function ForbiddenArea.Server.OnInit(A0_6444)
  A0_6444.inside = {}
  A0_6444.warning = {}
  A0_6444:OnReset()
end
function ForbiddenArea.Client.OnInit(A0_6445)
  if not CryAction.IsServer() then
    A0_6445.inside = {}
    A0_6445.warning = {}
    A0_6445:OnReset()
  end
end
function ForbiddenArea.Client.OnTimer(A0_6446, A1_6447, A2_6448)
  local L3_6449
  L3_6449 = A0_6446.Properties
  L3_6449 = L3_6449.bEnabled
  if L3_6449 == 0 then
    return
  end
  L3_6449 = A0_6446.GetTimerLength
  L3_6449 = L3_6449(A0_6446)
  if 0 < g_localActor.actor:GetHealth() then
    A0_6446:SetTimer(A1_6447, L3_6449)
  end
  if g_localActor then
    vehId = g_localActor.actor:GetLinkedVehicleId()
    if not true then
      if not A0_6446.reverse then
        if A0_6446:IsPlayerInside(g_localActorId) and (not A0_6446.teamId or A0_6446.teamId ~= g_gameRules.game:GetTeam(g_localActorId)) then
          A0_6446:PunishPlayer(g_localActor, L3_6449)
        end
      elseif not A0_6446:IsPlayerInside(g_localActorId) and (not A0_6446.teamId or A0_6446.teamId ~= g_gameRules.game:GetTeam(g_localActorId)) then
        A0_6446:PunishPlayer(g_localActor, L3_6449)
      end
    end
  end
end
function ForbiddenArea.PunishPlayer(A0_6450, A1_6451, A2_6452)
  local L3_6453, L4_6454, L5_6455
  L3_6453 = A1_6451.actor
  if L3_6453 then
    L3_6453 = A1_6451.actor
    L4_6454 = L3_6453
    L3_6453 = L3_6453.IsImmuneToForbiddenArea
    L3_6453 = L3_6453(L4_6454)
  end
  L4_6454 = A1_6451.actor
  L5_6455 = L4_6454
  L4_6454 = L4_6454.GetSpectatorMode
  L4_6454 = L4_6454(L5_6455)
  if L4_6454 == 0 then
    L5_6455 = A1_6451
    L4_6454 = A1_6451.IsDead
    L4_6454 = L4_6454(L5_6455)
  elseif L4_6454 or L3_6453 then
    return
  end
  L4_6454 = -1
  L5_6455 = A0_6450.Properties
  L5_6455 = L5_6455.bInfiniteFall
  if L5_6455 ~= 0 then
    L5_6455 = g_gameRules
    L5_6455 = L5_6455.game
    L5_6455 = L5_6455.GetHitTypeId
    L5_6455 = L5_6455(L5_6455, "punishFall")
    L4_6454 = L5_6455
  else
    L5_6455 = g_gameRules
    L5_6455 = L5_6455.game
    L5_6455 = L5_6455.GetHitTypeId
    L5_6455 = L5_6455(L5_6455, A0_6450.Properties.esDamageType)
    L4_6454 = L5_6455
  end
  L5_6455 = A0_6450.dps
  L5_6455 = L5_6455 * (A2_6452 / 1000)
  if not A0_6450.owner or A0_6450.owner == 0 then
    g_gameRules.game:ClientSelfHarm(L5_6455, 0, -1, L4_6454, {
      x = 0,
      y = 0,
      z = 0
    }, {
      x = 0,
      y = 0,
      z = 1
    }, {
      x = 0,
      y = 0,
      z = -1
    })
  else
    g_gameRules.game:ClientSelfHarmByEntity(A0_6450.owner, L5_6455, 0, -1, L4_6454, {
      x = 0,
      y = 0,
      z = 0
    }, {
      x = 0,
      y = 0,
      z = 1
    }, {
      x = 0,
      y = 0,
      z = -1
    })
  end
end
function ForbiddenArea.DamageVehicle(A0_6456, A1_6457, A2_6458)
  local L3_6459, L4_6460
  L3_6459 = A0_6456.Properties
  L3_6459 = L3_6459.bInfiniteFall
  if L3_6459 == 0 then
    L3_6459 = A0_6456.Properties
    L3_6459 = L3_6459.esDamageType
    if L3_6459 ~= "punish" then
      L3_6459 = A0_6456.Properties
      L3_6459 = L3_6459.esDamageType
    end
  elseif L3_6459 == "punishFall" then
    return
  end
  L3_6459 = g_gameRules
  L3_6459 = L3_6459.game
  L4_6460 = L3_6459
  L3_6459 = L3_6459.GetHitTypeId
  L3_6459 = L3_6459(L4_6460, A0_6456.Properties.esDamageType)
  L4_6460 = A0_6456.dps
  L4_6460 = L4_6460 * A2_6458
  L4_6460 = L4_6460 * 10
  g_gameRules.game:ServerHarmVehicle(A1_6457, L4_6460, 0, L3_6459, {
    x = 0,
    y = 0,
    z = 0
  }, {
    x = 0,
    y = 0,
    z = 1
  }, {
    x = 0,
    y = 0,
    z = -1
  })
end
function ForbiddenArea.ActorEnteredArea(A0_6461, A1_6462)
  for _FORV_6_, _FORV_7_ in ipairs(A0_6461.inside) do
    if _FORV_7_ == A1_6462.id then
      break
    end
  end
  if true then
    return
  end
  table.insert(A0_6461.inside, A1_6462.id)
end
function ForbiddenArea.Client.OnEnterArea_Internal(A0_6463, A1_6464)
  if not A0_6463.teamId or A0_6463.teamId ~= g_gameRules.game:GetTeam(A1_6464.id) then
    if not A0_6463.reverse then
      A0_6463.warning[A1_6464.id] = A0_6463.delay
      if g_localActorId and g_localActorId == A1_6464.id and A1_6464.actor:GetSpectatorMode() == 0 and not A1_6464:IsDead() then
        if A1_6464.actor:IsImmuneToForbiddenArea() then
          A0_6463:SetTimer(0, A0_6463.delay * 1000)
        else
          if A0_6463.showWarning then
            g_gameRules.game:ForbiddenAreaWarning(true, A0_6463.delay, A1_6464.id)
            GameAudio.PlaySignal(A0_6463.AUDIO_SIGNAL)
            GameAudio.Announce("LeavingMap", 0)
          end
          A0_6463:SetTimer(0, A0_6463.delay * 1000)
        end
      end
    else
      A0_6463.warning[A1_6464.id] = nil
      if g_localActorId and g_localActorId == A1_6464.id then
        if A0_6463.showWarning then
          g_gameRules.game:ForbiddenAreaWarning(false, 0, A1_6464.id)
          GameAudio.StopSignal(A0_6463.AUDIO_SIGNAL)
        end
        A0_6463:KillTimer(0)
      end
    end
  end
end
function ForbiddenArea.Client.OnEnterArea(A0_6465, A1_6466, A2_6467)
  if A1_6466.actor then
    A0_6465:ActorEnteredArea(A1_6466)
    A0_6465.Client.OnEnterArea_Internal(A0_6465, A1_6466)
  end
end
function ForbiddenArea.ActorLeftArea(A0_6468, A1_6469)
  local L2_6470, L3_6471, L4_6472, L5_6473, L6_6474
  L2_6470 = false
  for L6_6474, _FORV_7_ in L3_6471(L4_6472) do
    if _FORV_7_ == A1_6469.id then
      L2_6470 = true
      table.remove(A0_6468.inside, L6_6474)
      break
    end
  end
  return L2_6470
end
function ForbiddenArea.Client.OnLeaveArea_Internal(A0_6475, A1_6476, A2_6477)
  if not A0_6475.teamId or A0_6475.teamId ~= g_gameRules.game:GetTeam(A1_6476.id) then
    if A0_6475.reverse then
      if A2_6477 then
        A0_6475.warning[A1_6476.id] = A0_6475.delay
        if g_localActorId and g_localActorId == A1_6476.id and A1_6476.actor:GetSpectatorMode() == 0 and not A1_6476:IsDead() then
          if A1_6476.actor:IsImmuneToForbiddenArea() then
            A0_6475:SetTimer(0, A0_6475.delay * 1000)
          else
            if A0_6475.showWarning then
              g_gameRules.game:ForbiddenAreaWarning(true, A0_6475.delay, A1_6476.id)
              GameAudio.PlaySignal(A0_6475.AUDIO_SIGNAL)
              GameAudio.Announce("LeavingMap", 0)
            end
            A0_6475:SetTimer(0, A0_6475.delay * 1000)
          end
        end
      end
    else
      A0_6475.warning[A1_6476.id] = nil
      if g_localActorId and g_localActorId == A1_6476.id then
        if A0_6475.showWarning then
          g_gameRules.game:ForbiddenAreaWarning(false, 0, A1_6476.id)
          GameAudio.StopSignal(A0_6475.AUDIO_SIGNAL)
        end
        A0_6475:KillTimer(0)
      end
    end
  end
end
function ForbiddenArea.Client.OnLeaveArea(A0_6478, A1_6479, A2_6480)
  local L3_6481
  L3_6481 = A1_6479.actor
  if L3_6481 then
    L3_6481 = A0_6478.ActorLeftArea
    L3_6481 = L3_6481(A0_6478, A1_6479)
    A0_6478.Client.OnLeaveArea_Internal(A0_6478, A1_6479, L3_6481)
  end
end
function ForbiddenArea.OnSave(A0_6482, A1_6483)
  A1_6483.inside = A0_6482.inside
end
function ForbiddenArea.OnLoad(A0_6484, A1_6485)
  A0_6484:OnReset()
  A0_6484.inside = A1_6485.inside
end
function ForbiddenArea.OnReset(A0_6486)
  A0_6486.reverse = tonumber(A0_6486.Properties.bReversed) ~= 0
  A0_6486.delay = tonumber(A0_6486.Properties.Delay)
  A0_6486.dps = tonumber(A0_6486.Properties.DamagePerSecond)
  A0_6486.showWarning = tonumber(A0_6486.Properties.bShowWarning) ~= 0
  A0_6486.warning = {}
  A0_6486.isServer = CryAction.IsServer()
  A0_6486.isClient = CryAction.IsClient()
  if A0_6486.Properties.teamName ~= "" then
    A0_6486.teamId = g_gameRules.game:GetTeamId(A0_6486.Properties.teamName)
    if A0_6486.teamId == 0 then
      A0_6486.teamId = nil
    end
  end
  if A0_6486.Properties.bEnabled ~= 0 then
    g_gameRules.game:AddForbiddenArea(A0_6486.id)
  end
  A0_6486:RegisterForAreaEvents(A0_6486.Properties.bEnabled and 1 or 0)
end
function ForbiddenArea.IsPlayerInside(A0_6487, A1_6488)
  for _FORV_5_, _FORV_6_ in pairs(A0_6487.inside) do
    if _FORV_6_ == A1_6488 then
      return true
    end
  end
  return false
end
function ForbiddenArea.GetTimerLength(A0_6489)
  local L1_6490
  L1_6490 = A0_6489.Properties
  L1_6490 = L1_6490.overrideTimerLength
  if L1_6490 == 0 then
    L1_6490 = A0_6489.TIMER_LENGTH
  end
  return L1_6490
end
function ForbiddenArea.Server.OnShutDown(A0_6491)
  if g_gameRules then
    g_gameRules.game:RemoveForbiddenArea(A0_6491.id)
  end
end
function ForbiddenArea.Client.OnShutDown(A0_6492)
  if g_gameRules and not CryAction.IsServer() then
    g_gameRules.game:RemoveForbiddenArea(A0_6492.id)
  end
end
function ForbiddenArea.OnLocalPlayerRevived(A0_6493)
  if A0_6493.Properties.bEnabled ~= 0 then
    A0_6493.bTimerStarted = true
  else
    A0_6493:KillTimer(0)
  end
end
function ForbiddenArea.OnLocalPlayerImmunityOff(A0_6494)
  local L1_6495
  L1_6495 = A0_6494.Properties
  L1_6495 = L1_6495.bEnabled
  if L1_6495 ~= 0 then
    L1_6495 = g_localActorId
    if L1_6495 ~= nil then
      L1_6495 = System
      L1_6495 = L1_6495.GetEntity
      L1_6495 = L1_6495(g_localActorId)
      if L1_6495 and L1_6495.actor then
        if A0_6494:IsPlayerInside(g_localActorId) then
          A0_6494.Client.OnEnterArea_Internal(A0_6494, L1_6495)
        else
          A0_6494.Client.OnLeaveArea_Internal(A0_6494, L1_6495, true)
        end
      end
    end
  end
end
function ForbiddenArea.OnLocalPlayerImmunityOn(A0_6496)
  local L1_6497
  L1_6497 = A0_6496.Properties
  L1_6497 = L1_6497.bEnabled
  if L1_6497 ~= 0 then
    L1_6497 = g_localActorId
    if L1_6497 ~= nil then
      L1_6497 = System
      L1_6497 = L1_6497.GetEntity
      L1_6497 = L1_6497(g_localActorId)
      if L1_6497 and L1_6497.actor then
        if A0_6496:IsPlayerInside(g_localActorId) then
          A0_6496.Client.OnLeaveArea_Internal(A0_6496, L1_6497, true)
        else
          A0_6496.Client.OnEnterArea_Internal(A0_6496, L1_6497)
        end
      end
    end
  end
end
function ForbiddenArea.Event_Enable(A0_6498)
  if A0_6498.Properties.bEnabled ~= 1 then
    A0_6498.Properties.bEnabled = 1
    BroadcastEvent(A0_6498, "Enabled")
    g_gameRules.game:AddForbiddenArea(A0_6498.id)
    A0_6498:SetTimer(0, A0_6498.delay * 1000)
    A0_6498:RegisterForAreaEvents(1)
  end
end
function ForbiddenArea.Event_Disable(A0_6499)
  if A0_6499.Properties.bEnabled ~= 0 then
    A0_6499.Properties.bEnabled = 0
    BroadcastEvent(A0_6499, "Disabled")
    g_gameRules.game:RemoveForbiddenArea(A0_6499.id)
    A0_6499:RegisterForAreaEvents(0)
  end
end
function ForbiddenArea.Event_SetOwner(A0_6500, A1_6501, A2_6502)
  A0_6500.owner = A2_6502.id
  if A0_6500.bNetworked ~= 0 then
    if A0_6500.isServer then
      if g_localChannelId ~= nil then
        A0_6500.otherClients:ClSetOwner(g_localChannelId, A0_6500.owner or NULL_ENTITY)
      else
        A0_6500.allClients:ClSetOwner(A0_6500.owner or NULL_ENTITY)
      end
    else
      A0_6500.server:SvSetOwner(A0_6500.owner or NULL_ENTITY)
    end
  end
end
ForbiddenArea.FlowEvents = {
  Inputs = {
    Disable = {
      ForbiddenArea.Event_Disable,
      "bool"
    },
    Enable = {
      ForbiddenArea.Event_Enable,
      "bool"
    },
    SetOwner = {
      ForbiddenArea.Event_SetOwner,
      "entity"
    }
  },
  Outputs = {Disabled = "bool", Enabled = "bool"}
}
