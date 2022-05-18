ParticleEffect = {
  Properties = {
    soclasses_SmartObjectClass = "",
    ParticleEffect = "",
    Comment = "",
    bActive = 1,
    bPrime = 1,
    Scale = 1,
    SpeedScale = 1,
    TimeScale = 1,
    CountScale = 1,
    bCountPerUnit = 0,
    Strength = -1,
    esAttachType = "",
    esAttachForm = "",
    PulsePeriod = 0,
    NetworkSync = 0,
    bRegisterByBBox = 0,
    bUseUITime = 0,
    bForceVAClip = 0,
    Audio = {bEnableAudio = 1, audioRTPCRtpc = "particlefx"}
  },
  Editor = {
    Model = "Editor/Objects/Particles.cgf",
    Icon = "Particles.bmp"
  },
  States = {"Active", "Idle"},
  Client = {},
  Server = {}
}
Net.Expose({
  Class = ParticleEffect,
  ClientMethods = {
    ClEvent_Spawn = {RELIABLE_ORDERED, POST_ATTACH},
    ClEvent_Enable = {RELIABLE_ORDERED, POST_ATTACH},
    ClEvent_Disable = {RELIABLE_ORDERED, POST_ATTACH},
    ClEvent_Restart = {RELIABLE_ORDERED, POST_ATTACH},
    ClEvent_Kill = {RELIABLE_ORDERED, POST_ATTACH}
  },
  ServerMethods = {},
  ServerProperties = {}
})
function ParticleEffect.OnSpawn(A0_7355)
  A0_7355:CreateRenderProxy()
  if not table.NetworkSync then
    A0_7355:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
  end
end
function ParticleEffect.OnLoad(A0_7356, A1_7357)
  A0_7356:GotoState("")
  if not A1_7357.nParticleSlot then
    if A0_7356.nParticleSlot then
      A0_7356:DeleteParticleEmitter(A0_7356.nParticleSlot)
    end
    A0_7356:GotoState("Idle")
  elseif not A0_7356.nParticleSlot or A0_7356.nParticleSlot ~= A1_7357.nParticleSlot then
    if A0_7356.nParticleSlot then
      A0_7356:DeleteParticleEmitter(A0_7356.nParticleSlot)
    end
    A0_7356:GotoState("Idle")
    A0_7356.nParticleSlot = A0_7356:LoadParticleEffect(A1_7357.nParticleSlot, A0_7356.Properties.ParticleEffect, A0_7356.Properties)
    A0_7356:GotoState("Active")
  end
end
function ParticleEffect.OnSave(A0_7358, A1_7359)
  A1_7359.nParticleSlot = A0_7358.nParticleSlot
end
function ParticleEffect.OnPropertyChange(A0_7360)
  if A0_7360.Properties.bActive ~= 0 then
    A0_7360:GotoState("")
    A0_7360:GotoState("Active")
  else
    A0_7360:GotoState("Idle")
  end
end
function ParticleEffect.OnReset(A0_7361)
  A0_7361:GotoState("Idle")
  if A0_7361.Properties.bActive ~= 0 then
    A0_7361:GotoState("Active")
  end
end
function ParticleEffect.Event_Enable(A0_7362)
  A0_7362:GotoState("Active")
  A0_7362:ActivateOutput("Enable", true)
  if CryAction.IsServer() and A0_7362.allClients then
    A0_7362.allClients:ClEvent_Enable()
  end
end
function ParticleEffect.Event_Disable(A0_7363)
  A0_7363:GotoState("Idle")
  A0_7363:ActivateOutput("Disable", true)
  if CryAction.IsServer() and A0_7363.allClients then
    A0_7363.allClients:ClEvent_Disable()
  end
end
function ParticleEffect.Event_Restart(A0_7364)
  A0_7364:GotoState("Idle")
  A0_7364:GotoState("Active")
  A0_7364:ActivateOutput("Restart", true)
  if CryAction.IsServer() and A0_7364.allClients then
    A0_7364.allClients:ClEvent_Restart()
  end
end
function ParticleEffect.Event_Spawn(A0_7365)
  A0_7365:GetDirectionVector(1, g_Vectors.temp_v2)
  Particle.SpawnEffect(A0_7365.Properties.ParticleEffect, A0_7365:GetPos(g_Vectors.temp_v1), g_Vectors.temp_v2, A0_7365.Properties.Scale)
  A0_7365:ActivateOutput("Spawn", true)
  if CryAction.IsServer() and A0_7365.allClients then
    A0_7365.allClients:ClEvent_Spawn()
  end
end
function ParticleEffect.Event_Kill(A0_7366)
  if A0_7366.nParticleSlot then
    A0_7366:DeleteParticleEmitter(A0_7366.nParticleSlot)
  end
  A0_7366:GotoState("Idle")
  if CryAction.IsServer() and A0_7366.allClients then
    A0_7366.allClients:ClEvent_Kill()
  end
end
function ParticleEffect.Enable(A0_7367)
  A0_7367:GotoState("Active")
  if CryAction.IsServer() and A0_7367.allClients then
    A0_7367.allClients:ClEvent_Enable()
  end
end
function ParticleEffect.Disable(A0_7368)
  A0_7368:GotoState("Idle")
  if CryAction.IsServer() and A0_7368.allClients then
    A0_7368.allClients:ClEvent_Disable()
  end
end
ParticleEffect.Active = {
  OnBeginState = function(A0_7369)
    if not A0_7369.nParticleSlot then
      A0_7369.nParticleSlot = -1
    end
    A0_7369.nParticleSlot = A0_7369:LoadParticleEffect(A0_7369.nParticleSlot, A0_7369.Properties.ParticleEffect, A0_7369.Properties)
  end,
  OnLeaveArea = function(A0_7370, A1_7371, A2_7372)
    A0_7370:GotoState("Idle")
  end
}
ParticleEffect.Idle = {
  OnBeginState = function(A0_7373)
    if A0_7373.nParticleSlot then
      A0_7373:FreeSlot(A0_7373.nParticleSlot)
      A0_7373.nParticleSlot = nil
    end
  end,
  OnEnterArea = function(A0_7374, A1_7375, A2_7376)
    A0_7374:GotoState("Active")
  end
}
function ParticleEffect.DefaultState(A0_7377, A1_7378, A2_7379)
  local L3_7380, L5_7381, L6_7382
  L3_7380 = A0_7377[A2_7379]
  L5_7381 = A0_7377[A1_7378]
  L6_7382 = {}
  L6_7382.OnBeginState = L3_7380.OnBeginState
  L6_7382.OnEndState = L3_7380.OnEndState
  L6_7382.OnLeaveArea = L3_7380.OnLeaveArea
  L6_7382.OnEnterArea = L3_7380.OnEnterArea
  L5_7381[A2_7379] = L6_7382
end
ParticleEffect:DefaultState("Server", "Idle")
ParticleEffect:DefaultState("Server", "Active")
ParticleEffect:DefaultState("Client", "Idle")
ParticleEffect:DefaultState("Client", "Active")
ParticleEffect.FlowEvents = {
  Inputs = {
    Disable = {
      ParticleEffect.Event_Disable,
      "bool"
    },
    Enable = {
      ParticleEffect.Event_Enable,
      "bool"
    },
    Restart = {
      ParticleEffect.Event_Restart,
      "bool"
    },
    Spawn = {
      ParticleEffect.Event_Spawn,
      "bool"
    },
    Kill = {
      ParticleEffect.Event_Kill,
      "bool"
    }
  },
  Outputs = {
    Disable = "bool",
    Enable = "bool",
    Restart = "bool",
    Spawn = "bool"
  }
}
function ParticleEffect.Client.OnInit(A0_7383)
  A0_7383:SetRegisterInSectors(1)
  A0_7383.Properties.ParticleEffect = A0_7383:PreLoadParticleEffect(A0_7383.Properties.ParticleEffect)
  A0_7383:SetUpdatePolicy(ENTITY_UPDATE_POT_VISIBLE)
  if A0_7383.Properties.bActive ~= 0 then
    A0_7383:GotoState("Active")
  else
    A0_7383:GotoState("Idle")
  end
end
function ParticleEffect.Client.ClEvent_Spawn(A0_7384)
  if not CryAction.IsServer() then
    A0_7384:Event_Spawn()
  end
end
function ParticleEffect.Client.ClEvent_Enable(A0_7385)
  if not CryAction.IsServer() then
    A0_7385:Event_Enable()
  end
end
function ParticleEffect.Client.ClEvent_Disable(A0_7386)
  if not CryAction.IsServer() then
    A0_7386:Event_Disable()
  end
end
function ParticleEffect.Client.ClEvent_Restart(A0_7387)
  if not CryAction.IsServer() then
    A0_7387:Event_Restart()
  end
end
function ParticleEffect.Client.ClEvent_Kill(A0_7388)
  if not CryAction.IsServer() then
    A0_7388:Event_Kill()
  end
end
