BasicAIEvent = {}
MakeUsable(BasicAIEvent)
function BasicAIEvent.Event_WakeUp(A0_2506, A1_2507)
  if not AI.IsEnabled(A0_2506.id) then
    return
  end
  if A0_2506.actor:GetPhysicalizationProfile() == "sleep" then
    A0_2506.actor:StandUp()
  end
end
function BasicAIEvent.Event_Sleep(A0_2508, A1_2509)
  if not A0_2508.isFallen then
    BroadcastEvent(A0_2508, "Sleep")
  end
  A0_2508.actor:Fall(A0_2508:GetPos())
  A0_2508.isFallen = 1
end
function BasicAIEvent.Event_Enabled(A0_2510, A1_2511)
  BroadcastEvent(A0_2510, "Enabled")
end
function BasicAIEvent.Event_Disabled(A0_2512, A1_2513)
  BroadcastEvent(A0_2512, "Disabled")
end
function BasicAIEvent.Event_OnAlert(A0_2514, A1_2515)
  BroadcastEvent(A0_2514, "OnAlert")
end
function BasicAIEvent.Event_Disable(A0_2516, A1_2517)
  A0_2516:Hide(1)
  A0_2516:TriggerEvent(AIEVENT_DISABLE)
  A0_2516._enabled = false
  A0_2516:Event_Disabled(A0_2516)
  if CryAction.IsServer() then
    A0_2516.allClients:ClAIDisable()
  end
  GameAI.PauseAllModules(A0_2516.id)
  if A0_2516.OnDisabled then
    A0_2516:OnDisabled()
  end
end
function BasicAIEvent.Event_Enable(A0_2518, A1_2519)
  if not A0_2518:IsDead() then
    A0_2518._enabled = true
    A0_2518:Hide(0)
    GameAI.ResumeAllModules(A0_2518.id)
    A0_2518:Event_Enabled(A0_2518)
    if A0_2518.SoundSignals and A0_2518.SoundSignals.Idle then
      GameAudio.PlayEntitySignal(A0_2518.SoundSignals.Idle, A0_2518.id)
    end
    if CryAction.IsServer() then
      A0_2518.allClients:ClAIEnable()
    end
  end
  if A0_2518.OnEnabled then
    A0_2518:OnEnabled()
  end
end
function BasicAIEvent.Event_Kill(A0_2520, A1_2521)
  if not AI.IsEnabled(A0_2520.id) then
    return
  end
  if not A0_2520:IsDead() and A0_2520.arknpc ~= nil then
    A0_2520.arknpc:Kill(nil)
  end
end
function BasicAIEvent.Event_SetForcedLookDir(A0_2522, A1_2523, A2_2524)
  A0_2522.actor:SetForcedLookDir(A2_2524)
end
function BasicAIEvent.Event_ClearForcedLookDir(A0_2525, A1_2526)
  A0_2525.actor:ClearForcedLookDir()
end
function BasicAIEvent.Event_SetForcedLookObjectId(A0_2527, A1_2528, A2_2529)
  A0_2527.actor:SetForcedLookObjectId(A2_2529.id)
end
function BasicAIEvent.Event_ClearForcedLookObjectId(A0_2530, A1_2531)
  A0_2530.actor:ClearForcedLookObjectId()
end
function BasicAIEvent.Event_Follow(A0_2532, A1_2533)
  local L2_2534
  L2_2534 = BroadcastEvent
  L2_2534(A0_2532, "Follow")
  L2_2534 = nil
  if A1_2533.Who and A1_2533.Who.id and A1_2533.Who.id ~= NULL_ENTITY then
    L2_2534 = AI.GetGroupOf(A1_2533.Who.id)
  else
    L2_2534 = AI.GetGroupOf(A1_2533.id)
  end
  AI.ChangeParameter(A0_2532.id, AIPARAM_GROUPID, L2_2534)
  AI.Signal(SIGNALFILTER_SENDER, 0, "FOLLOW_LEADER", A0_2532.id)
end
function BasicAIEvent.Event_Test(A0_2535, A1_2536)
  g_SignalData.fValue = 2
  AI.Signal(SIGNALFILTER_LEADER, 0, "OnScaleFormation", A0_2535.id, g_SignalData)
end
function BasicAIEvent.Event_TestStealth(A0_2537, A1_2538)
  AI.SetPFProperties(A0_2537.id, AIPATH_HUMAN_COVER)
end
function BasicAIEvent.Event_ResetHealth(A0_2539)
  entity.actor:SetHealth(entity.actor:GetMaxHealth())
  A0_2539.lastHealth = A0_2539.actor:GetHealth()
end
function BasicAIEvent.Event_MakeVulnerable(A0_2540)
  A0_2540.AI.invulnerable = false
end
function BasicAIEvent.Event_MakeInvulnerable(A0_2541)
  A0_2541.AI.invulnerable = true
end
BasicAIEvent.FlowEvents = {
  Inputs = {
    Used = {
      BasicAIEvent.Event_Used,
      "bool"
    },
    EnableUsable = {
      BasicAIEvent.Event_EnableUsable,
      "bool"
    },
    DisableUsable = {
      BasicAIEvent.Event_DisableUsable,
      "bool"
    },
    Disable = {
      BasicAIEvent.Event_Disable,
      "bool"
    },
    Enable = {
      BasicAIEvent.Event_Enable,
      "bool"
    },
    Kill = {
      BasicAIEvent.Event_Kill,
      "bool"
    },
    Sleep = {
      BasicAIEvent.Event_Sleep,
      "bool"
    },
    WakeUp = {
      BasicAIEvent.Event_WakeUp,
      "bool"
    },
    ResetHealth = {
      BasicAIEvent.Event_ResetHealth,
      "any"
    },
    MakeVulnerable = {
      BasicAIEvent.Event_MakeVulnerable,
      "any"
    },
    MakeInvulnerable = {
      BasicAIEvent.Event_MakeInvulnerable,
      "any"
    },
    SetForcedLookDir = {
      BasicAIEvent.Event_SetForcedLookDir,
      "Vec3"
    },
    ClearForcedLookDir = {
      BasicAIEvent.Event_ClearForcedLookDir,
      "bool"
    },
    SetForcedLookObjectId = {
      BasicAIEvent.Event_SetForcedLookObjectId,
      "entity"
    },
    ClearForcedLookObjectId = {
      BasicAIEvent.Event_ClearForcedLookObjectId,
      "bool"
    }
  },
  Outputs = {
    Used = "bool",
    Dead = "bool",
    KilledBy = "entity",
    OnAlert = "bool",
    Sleep = "bool",
    Stunned = "bool",
    TempPlayerControl = "bool",
    Enabled = "bool",
    Disabled = "bool"
  }
}
