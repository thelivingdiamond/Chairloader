CinematicTrigger = {
  Properties = {
    fDimX = 1,
    fDimY = 1,
    fDimZ = 1,
    bEnabled = 1,
    ScriptCommand = "",
    Sequence = "",
    bTriggerOnce = 0,
    fMaxDistance = 200,
    fMinDistance = 0,
    fMinVisibleTime = 0.5,
    fDelay = 0,
    fCheckTimer = 0.25,
    fZoomMinimum = 1,
    bInVehicleOnly = 0,
    bCheckLOS = 0,
    MultiplayerOptions = {
      bNetworked = 0,
      bPerPlayer = 0,
      MinPlayers = 1
    }
  },
  VISIBILITY_TIMER_ID = 0,
  Client = {},
  Server = {},
  Editor = {
    Model = "Editor/Objects/T.cgf",
    Icon = "Trigger.bmp",
    ShowBounds = 1
  }
}
Net.Expose({
  Class = CinematicTrigger,
  ClientMethods = {
    ClEnable = {
      RELIABLE_ORDERED,
      PRE_ATTACH,
      BOOL
    },
    ClVisible = {
      RELIABLE_ORDERED,
      PRE_ATTACH,
      ENTITYID
    },
    ClInvisible = {
      RELIABLE_ORDERED,
      PRE_ATTACH,
      ENTITYID
    },
    ClTrigger = {
      RELIABLE_ORDERED,
      PRE_ATTACH,
      ENTITYID
    }
  },
  ServerMethods = {
    SvRequestVisible = {
      RELIABLE_ORDERED,
      PRE_ATTACH,
      ENTITYID
    },
    SvRequestInvisible = {
      RELIABLE_ORDERED,
      PRE_ATTACH,
      ENTITYID
    }
  },
  ServerProperties = {}
})
function CinematicTrigger.OnSpawn(A0_8547)
  A0_8547:OnReset()
end
function CinematicTrigger.OnPropertyChange(A0_8548)
  A0_8548:OnReset()
end
function CinematicTrigger.OnReset(A0_8549)
  local L1_8550, L2_8551, L3_8552, L4_8553
  if L1_8550 then
    for L4_8553, _FORV_5_ in L1_8550(L2_8551) do
      A0_8549:KillTimer(L4_8553)
    end
  end
  L4_8553 = A0_8549.Properties
  L4_8553 = L4_8553.fDimY
  L4_8553 = L4_8553 * 0.5
  L1_8550.x = -L3_8552
  L1_8550.y = -L4_8553
  L1_8550.z = -(A0_8549.Properties.fDimZ * 0.5)
  L2_8551.x = L3_8552
  L2_8551.z, L2_8551.y = A0_8549.Properties.fDimZ * 0.5, L4_8553
  A0_8549:SetTriggerBBox(L1_8550, L2_8551)
  A0_8549:Activate(0)
  A0_8549.timerId = 1
  A0_8549.isvisible = nil
  A0_8549.enabled = nil
  A0_8549.triggerOnce = tonumber(A0_8549.Properties.bTriggerOnce) ~= 0
  A0_8549.localOnly = A0_8549.Properties.MultiplayerOptions.bNetworked == 0
  A0_8549.perPlayer = tonumber(A0_8549.Properties.MultiplayerOptions.bPerPlayer) ~= 0
  A0_8549.minPlayers = tonumber(A0_8549.Properties.MultiplayerOptions.MinPlayers)
  if 1 > A0_8549.minPlayers then
    A0_8549.minPlayers = 1
  end
  A0_8549.isServer = CryAction.IsServer()
  A0_8549.isClient = CryAction.IsClient()
  A0_8549.visible = {}
  A0_8549.timers = {}
  if not A0_8549.localOnly then
    A0_8549.triggeredPP = {}
    A0_8549.triggeredOncePP = {}
  end
  A0_8549.triggeredOnce = nil
  A0_8549.triggered = nil
  A0_8549.visibleCount = 0
  A0_8549:Enable(tonumber(A0_8549.Properties.bEnabled) ~= 0)
  A0_8549.enableChanged = false
end
function CinematicTrigger.Enable(A0_8554, A1_8555)
  if A1_8555 then
    if A0_8554.isClient then
      A0_8554:SetTimer(A0_8554.VISIBILITY_TIMER_ID, A0_8554.Properties.fCheckTimer * 1000)
      A0_8554.last_visible_time = nil
    end
  elseif A0_8554.isClient then
    A0_8554:KillTimer(A0_8554.VISIBILITY_TIMER_ID)
  end
  if not A0_8554.localOnly and A0_8554.isServer and A1_8555 ~= A0_8554.enabled and A0_8554.otherClients then
    A0_8554.otherClients:ClEnable(g_localChannelId, A1_8555)
  end
  A0_8554.enabled = A1_8555
  A0_8554.enableChanged = true
end
function CinematicTrigger.OnLoad(A0_8556, A1_8557)
  A0_8556:OnReset()
  A0_8556:Enable(A1_8557.enabled)
  A0_8556.triggered = A1_8557.triggered
  A0_8556.triggeredOnce = A1_8557.triggeredOnce
end
function CinematicTrigger.OnSave(A0_8558, A1_8559)
  local L2_8560
  L2_8560 = A0_8558.enabled
  A1_8559.enabled = L2_8560
  L2_8560 = A0_8558.triggered
  A1_8559.triggered = L2_8560
  L2_8560 = A0_8558.triggeredOnce
  A1_8559.triggeredOnce = L2_8560
end
function CinematicTrigger.Client.ClEnable(A0_8561, A1_8562)
  if A1_8562 then
    A0_8561:SetTimer(A0_8561.VISIBILITY_TIMER_ID, A0_8561.Properties.fCheckTimer * 1000)
    A0_8561.last_visible_time = nil
  else
    A0_8561:KillTimer(A0_8561.VISIBILITY_TIMER_ID)
  end
  A0_8561.enabled = A1_8562
end
function CinematicTrigger.Server.OnPostInitClient(A0_8563, A1_8564)
  if A0_8563.enableChanged then
    A0_8563.onClient:ClEnable(A1_8564, A0_8563.enabled)
  end
end
function CinematicTrigger.Server.SvRequestVisible(A0_8565, A1_8566)
  A0_8565:Visible(A1_8566)
end
function CinematicTrigger.Server.SvRequestInvisible(A0_8567, A1_8568)
  A0_8567:Invisible(A1_8568)
end
function CinematicTrigger.Trigger(A0_8569, A1_8570)
  local L2_8571
  L2_8571 = A0_8569.triggerOnce
  if L2_8571 then
    L2_8571 = A0_8569.KillTimer
    L2_8571(A0_8569, A0_8569.VISIBILITY_TIMER_ID)
  end
  L2_8571 = A0_8569.Properties
  L2_8571 = L2_8571.ScriptCommand
  if L2_8571 then
    L2_8571 = A0_8569.Properties
    L2_8571 = L2_8571.ScriptCommand
    if L2_8571 ~= "" then
      L2_8571 = loadstring
      L2_8571 = L2_8571(A0_8569.Properties.ScriptCommand)
      if L2_8571 ~= nil then
        L2_8571()
      end
    end
  end
  L2_8571 = A0_8569.Properties
  L2_8571 = L2_8571.Sequence
  if L2_8571 ~= "" then
    L2_8571 = Movie
    L2_8571 = L2_8571.PlaySequence
    L2_8571(A0_8569.Properties.Sequence)
  end
end
function CinematicTrigger.Visible(A0_8572, A1_8573)
  if not A0_8572:CanTrigger(A1_8573) then
    return
  end
  A0_8572.visible[A1_8573] = true
  A0_8572.visibleCount = A0_8572.visibleCount + 1
  if not A0_8572.localOnly and A0_8572.visibleCount < A0_8572.minPlayers then
    return
  end
  A0_8572:Event_Visible(A1_8573)
  A0_8572:CreateTimer(A1_8573, A0_8572.Properties.fDelay * 1000)
end
function CinematicTrigger.Invisible(A0_8574, A1_8575)
  if not A0_8574:CanTrigger(A1_8575) then
    return
  end
  A0_8574.visible[A1_8575] = nil
  A0_8574.visibleCount = A0_8574.visibleCount - 1
  A0_8574:Event_Invisible(A1_8575)
end
function CinematicTrigger.CanTrigger(A0_8576, A1_8577)
  local L3_8578
  L3_8578 = A0_8576.Properties
  if L3_8578.bInVehicleOnly ~= 0 and not A1_8577.vehicle then
    return false
  end
  return true
end
function CinematicTrigger.IsVisible(A0_8579)
  local L1_8580, L2_8581, L3_8582, L4_8583
  L1_8580 = g_Vectors
  L1_8580 = L1_8580.temp_v1
  L2_8581 = g_Vectors
  L2_8581 = L2_8581.temp_v2
  L3_8582 = g_Vectors
  L3_8582 = L3_8582.temp_v3
  L4_8583 = g_Vectors
  L4_8583 = L4_8583.temp_v4
  A0_8579.pos = A0_8579:GetWorldPos(A0_8579.pos)
  L1_8580.x = A0_8579.pos.x + A0_8579.Properties.fDimX * 0.5
  L1_8580.y = A0_8579.pos.y + A0_8579.Properties.fDimY * 0.5
  L1_8580.z = A0_8579.pos.z + A0_8579.Properties.fDimZ * 0.5
  L2_8581.x = A0_8579.pos.x + A0_8579.Properties.fDimX * 0.5
  L2_8581.y = A0_8579.pos.y + A0_8579.Properties.fDimY * 0.5
  L2_8581.z = A0_8579.pos.z - A0_8579.Properties.fDimZ * 0.5
  L3_8582.x = A0_8579.pos.x + A0_8579.Properties.fDimX * 0.5
  L3_8582.y = A0_8579.pos.y - A0_8579.Properties.fDimY * 0.5
  L3_8582.z = A0_8579.pos.z + A0_8579.Properties.fDimZ * 0.5
  L4_8583.x = A0_8579.pos.x + A0_8579.Properties.fDimX * 0.5
  L4_8583.y = A0_8579.pos.y - A0_8579.Properties.fDimY * 0.5
  L4_8583.z = A0_8579.pos.z - A0_8579.Properties.fDimZ * 0.5
  if System.IsPointVisible(L1_8580) and System.IsPointVisible(L2_8581) and System.IsPointVisible(L3_8582) and System.IsPointVisible(L4_8583) then
    L1_8580.x = A0_8579.pos.x - A0_8579.Properties.fDimX * 0.5
    L1_8580.y = A0_8579.pos.y + A0_8579.Properties.fDimY * 0.5
    L1_8580.z = A0_8579.pos.z + A0_8579.Properties.fDimZ * 0.5
    L2_8581.x = A0_8579.pos.x - A0_8579.Properties.fDimX * 0.5
    L2_8581.y = A0_8579.pos.y + A0_8579.Properties.fDimY * 0.5
    L2_8581.z = A0_8579.pos.z - A0_8579.Properties.fDimZ * 0.5
    L3_8582.x = A0_8579.pos.x - A0_8579.Properties.fDimX * 0.5
    L3_8582.y = A0_8579.pos.y - A0_8579.Properties.fDimY * 0.5
    L3_8582.z = A0_8579.pos.z + A0_8579.Properties.fDimZ * 0.5
    L4_8583.x = A0_8579.pos.x - A0_8579.Properties.fDimX * 0.5
    L4_8583.y = A0_8579.pos.y - A0_8579.Properties.fDimY * 0.5
    L4_8583.z = A0_8579.pos.z - A0_8579.Properties.fDimZ * 0.5
    if System.IsPointVisible(L1_8580) and System.IsPointVisible(L2_8581) and System.IsPointVisible(L3_8582) and System.IsPointVisible(L4_8583) then
      return true
    end
  end
  return false
end
function CinematicTrigger.CheckZoom(A0_8584)
  if A0_8584.Properties.fZoomMinimum > 1 then
    if System.GetCVar("cl_fov") / (System.GetViewCameraFov() / math.pi * 180) >= A0_8584.Properties.fZoomMinimum then
      return true
    else
      return false
    end
  else
    return true
  end
end
function CinematicTrigger.IsInRange(A0_8585)
  local L1_8586, L2_8587
  L1_8586 = g_localActor
  if not L1_8586 then
    return
  end
  L2_8587 = A0_8585
  L1_8586 = A0_8585.GetWorldPos
  L1_8586 = L1_8586(L2_8587, g_Vectors.temp_v1)
  L2_8587 = g_localActor
  L2_8587 = L2_8587.GetWorldPos
  L2_8587 = L2_8587(L2_8587, g_Vectors.temp_v2)
  if vecDistanceSq(L1_8586, L2_8587) < A0_8585.Properties.fMinDistance * A0_8585.Properties.fMinDistance or vecDistanceSq(L1_8586, L2_8587) > A0_8585.Properties.fMaxDistance * A0_8585.Properties.fMaxDistance then
    return false
  end
  return true
end
function CinematicTrigger.CheckLOS(A0_8588)
  local L1_8589, L2_8590
  L1_8589 = A0_8588.Properties
  L1_8589 = L1_8589.bCheckLOS
  if L1_8589 == 0 then
    L1_8589 = true
    return L1_8589
  end
  L1_8589 = g_localActor
  if not L1_8589 then
    return
  end
  L2_8590 = A0_8588
  L1_8589 = A0_8588.GetWorldPos
  L1_8589 = L1_8589(L2_8590, g_Vectors.temp_v1)
  L2_8590 = System
  L2_8590 = L2_8590.GetViewCameraPos
  L2_8590 = L2_8590(g_Vectors.temp_v2)
  return System.RayTraceCheck(L2_8590, L1_8589, g_localActor:GetRawId(), A0_8588:GetRawId(), gcc_coral + gcc_transparent)
end
function CinematicTrigger.CreateTimer(A0_8591, A1_8592, A2_8593)
  local L3_8594
  L3_8594 = A0_8591.timerId
  if L3_8594 > 1023 then
    L3_8594 = 1
  end
  L3_8594 = L3_8594 + 1
  A0_8591.timerId = L3_8594
  A0_8591.timers[L3_8594] = A1_8592
  A0_8591:SetTimer(L3_8594, A2_8593)
end
function CinematicTrigger.Client.OnTimer(A0_8595, A1_8596, A2_8597)
  if A1_8596 == A0_8595.VISIBILITY_TIMER_ID then
    if A0_8595:IsInRange() and A0_8595:IsVisible() and A0_8595:CheckZoom() and A0_8595:CheckLOS() then
      if not A0_8595.isvisible then
        if not A0_8595.last_visible_time then
          A0_8595.last_visible_time = _time
        end
        if _time - A0_8595.last_visible_time > A0_8595.Properties.fMinVisibleTime then
          if A0_8595.isServer then
            A0_8595:Visible(g_localActorId)
          else
            A0_8595.server:SvRequestVisible(g_localActorId)
          end
          A0_8595.isvisible = true
        end
      end
    else
      if A0_8595.last_visible_time and A0_8595.isvisible then
        if A0_8595.isServer then
          A0_8595:Invisible(g_localActorId)
        else
          A0_8595.server:SvRequestInvisible(g_localActorId)
        end
        A0_8595.isvisible = nil
      end
      A0_8595.last_visible_time = nil
    end
    A0_8595:SetTimer(A0_8595.VISIBILITY_TIMER_ID, A0_8595.Properties.fCheckTimer * 1000)
  elseif A0_8595.localOnly and not A0_8595.isServer then
    A0_8595:Event_Trigger(g_localActorId)
  end
end
function CinematicTrigger.Server.OnTimer(A0_8598, A1_8599, A2_8600)
  local L3_8601
  L3_8601 = A0_8598.VISIBILITY_TIMER_ID
  if A1_8599 ~= L3_8601 then
    L3_8601 = A0_8598.timers
    L3_8601 = L3_8601[A1_8599]
    if not L3_8601 then
      return
    end
    A0_8598:Event_Trigger(L3_8601)
  end
end
function CinematicTrigger.Event_Enable(A0_8602)
  A0_8602:Enable(true)
  BroadcastEvent(A0_8602, "Enable")
end
function CinematicTrigger.Event_Disable(A0_8603)
  A0_8603:Enable(false)
  BroadcastEvent(A0_8603, "Disable")
end
function CinematicTrigger.Event_Visible(A0_8604, A1_8605)
  if not A0_8604.enabled then
    return
  end
  if A0_8604.triggerOnce then
    if A0_8604.localOnly then
      if A0_8604.triggeredOnce then
        return
      end
    elseif A0_8604.perPlayer and A0_8604.triggeredOncePP[A1_8605] then
      return
    elseif not A0_8604.perPlayer and A0_8604.triggeredOnce then
      return
    end
  end
  A0_8604.triggered = true
  A0_8604.triggeredOnce = true
  if not A0_8604.localOnly and A1_8605 then
    A0_8604.triggeredPP[A1_8605] = true
    A0_8604.triggeredOncePP[A1_8605] = true
  end
  Log("%s:Event_Visible(%s)", A0_8604:GetName(), EntityName(A1_8605))
  BroadcastEvent(A0_8604, "Visible")
  if not A0_8604.localOnly and A0_8604.isServer then
    A0_8604.otherClients:ClVisible(g_localChannelId, A1_8605 or NULL_ENTITY)
  end
end
function CinematicTrigger.Client.ClVisible(A0_8606, A1_8607)
  Log("%s.Client:ClVisible(%s)", A0_8606:GetName(), EntityName(A1_8607))
  BroadcastEvent(A0_8606, "Visible")
end
function CinematicTrigger.Event_Invisible(A0_8608, A1_8609)
  if not A0_8608.enabled then
    return
  end
  if A0_8608.localOnly and not A0_8608.triggered then
    return
  end
  if A0_8608.perPlayer then
    if not A0_8608.localOnly and A1_8609 and not A0_8608.triggeredPP[A1_8609] then
      return
    end
  elseif not A0_8608.triggered then
    return
  end
  A0_8608.triggered = nil
  if not A0_8608.localOnly and A1_8609 then
    A0_8608.triggeredPP[A1_8609] = nil
  end
  Log("%s:Event_Invisible(%s)", A0_8608:GetName(), EntityName(A1_8609))
  BroadcastEvent(A0_8608, "Invisible")
  if not A0_8608.localOnly and A0_8608.isServer then
    A0_8608.otherClients:ClInvisible(g_localChannelId, A1_8609 or NULL_ENTITY)
  end
end
function CinematicTrigger.Client.ClInvisible(A0_8610, A1_8611)
  Log("%s.Client:ClInvisible(%s)", A0_8610:GetName(), EntityName(A1_8611))
  BroadcastEvent(A0_8610, "Invisible")
end
function CinematicTrigger.Event_Trigger(A0_8612, A1_8613)
  Log("%s:Trigger(%s)", A0_8612:GetName(), EntityName(A1_8613))
  A0_8612:Trigger(A1_8613)
  BroadcastEvent(A0_8612, "Trigger")
  if not A0_8612.localOnly and A0_8612.isServer then
    A0_8612.otherClients:ClTrigger(g_localChannelId, A1_8613 or NULL_ENTITY)
  end
end
function CinematicTrigger.Client.ClTrigger(A0_8614, A1_8615)
  Log("%s.Client:ClTrigger(%s)", A0_8614:GetName(), EntityName(A1_8615))
  A0_8614:Trigger(A1_8615)
  BroadcastEvent(A0_8614, "Trigger")
end
CinematicTrigger.FlowEvents = {
  Inputs = {
    Disable = {
      CinematicTrigger.Event_Disable,
      "bool"
    },
    Enable = {
      CinematicTrigger.Event_Enable,
      "bool"
    },
    Invisible = {
      CinematicTrigger.Event_Invisible,
      "bool"
    },
    Visible = {
      CinematicTrigger.Event_Visible,
      "bool"
    },
    Trigger = {
      CinematicTrigger.Event_Trigger,
      "bool"
    }
  },
  Outputs = {
    Disable = "bool",
    Enable = "bool",
    Invisible = "bool",
    Visible = "bool",
    Trigger = "bool"
  }
}
