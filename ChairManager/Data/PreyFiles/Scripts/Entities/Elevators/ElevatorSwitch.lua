ElevatorSwitch = {
  Server = {},
  Client = {},
  Properties = {
    soclasses_SmartObjectClass = "ElevatorSwitch",
    objModel = "engine/engineassets/objects/default.cgf",
    nFloor = 0,
    fDelay = 3,
    fUseDistance = 1,
    UseMessage = "Use Elevator",
    Sounds = {soundSoundOnPress = ""},
    bEnabled = 1
  },
  Editor = {
    Icon = "elevator.bmp",
    IconOnTop = 0
  }
}
Net.Expose({
  Class = ElevatorSwitch,
  ClientMethods = {
    ClUsed = {RELIABLE_UNORDERED, POST_ATTACH}
  },
  ServerMethods = {
    SvRequestUse = {
      RELIABLE_UNORDERED,
      POST_ATTACH,
      ENTITYID
    }
  },
  ServerProperties = {}
})
function ElevatorSwitch.OnPreFreeze(A0_5113, A1_5114, A2_5115)
  local L3_5116
  if A1_5114 then
    L3_5116 = false
    return L3_5116
  end
end
function ElevatorSwitch.OnPropertyChange(A0_5117)
  A0_5117:Reset()
end
function ElevatorSwitch.OnReset(A0_5118)
  A0_5118:Reset()
end
function ElevatorSwitch.OnSpawn(A0_5119)
  CryAction.CreateGameObjectForEntity(A0_5119.id)
  CryAction.BindGameObjectToNetwork(A0_5119.id)
  CryAction.ForceGameObjectUpdate(A0_5119.id, true)
  A0_5119.isServer = CryAction.IsServer()
  A0_5119.isClient = CryAction.IsClient()
  A0_5119.user = 0
  A0_5119.tmp = {
    x = 0,
    y = 0,
    z = 0
  }
  A0_5119.tmp_2 = {
    x = 0,
    y = 0,
    z = 0
  }
  A0_5119.tmp_3 = {
    x = 0,
    y = 0,
    z = 0
  }
  A0_5119.initialdir = A0_5119:GetDirectionVector(1)
  A0_5119:Reset(1)
end
function ElevatorSwitch.OnDestroy(A0_5120)
  local L1_5121
end
function ElevatorSwitch.DoPhysicalize(A0_5122)
  if A0_5122.currModel ~= A0_5122.Properties.objModel then
    A0_5122:LoadObject(0, A0_5122.Properties.objModel)
    A0_5122:Physicalize(0, PE_RIGID, {mass = 0})
  end
  A0_5122.currModel = A0_5122.Properties.objModel
end
function ElevatorSwitch.Reset(A0_5123, A1_5124)
  A0_5123:Activate(0)
  A0_5123:DoPhysicalize()
  A0_5123.enabled = tonumber(A0_5123.Properties.bEnabled) ~= 0
end
function ElevatorSwitch.GetUsable(A0_5125)
  A0_5125:GetPos(A0_5125.tmp_2)
  g_localActor:GetPos(A0_5125.tmp_3)
  SubVectors(A0_5125.tmp, A0_5125.tmp_2, A0_5125.tmp_3)
  if A0_5125.enabled and LengthVector(A0_5125.tmp) < A0_5125.Properties.fUseDistance then
    ({}).ActionType = "ScriptDefined"
    ;({}).Use, ({}).DisplayText = {}, A0_5125.Properties.UseMessage
  end
  return {}
end
function ElevatorSwitch.OnUsed(A0_5126, A1_5127)
  A0_5126.server:SvRequestUse(A1_5127.id)
end
function ElevatorSwitch.Server.SvRequestUse(A0_5128, A1_5129)
  if A0_5128.Properties.fDelay > 0 then
    A0_5128:SetTimer(0, 1000 * A0_5128.Properties.fDelay)
  else
    A0_5128:Used()
  end
end
function ElevatorSwitch.Server.OnTimer(A0_5130, A1_5131, A2_5132)
  A0_5130:Used()
end
function ElevatorSwitch.Used(A0_5133)
  local L1_5134, L2_5135
  L1_5134 = A0_5133.enabled
  if not L1_5134 then
    return
  end
  L1_5134 = 0
  L2_5135 = A0_5133.GetLinkTarget
  L2_5135 = L2_5135(A0_5133, "up", L1_5134)
  while L2_5135 do
    L2_5135:Up(A0_5133.Properties.nFloor)
    L1_5134 = L1_5134 + 1
    L2_5135 = A0_5133:GetLinkTarget("up", L1_5134)
  end
  L1_5134 = 0
  L2_5135 = A0_5133:GetLinkTarget("down", L1_5134)
  while L2_5135 do
    L2_5135:Down(A0_5133.Properties.nFloor)
    L1_5134 = L1_5134 + 1
    L2_5135 = A0_5133:GetLinkTarget("down", L1_5134)
  end
  A0_5133:ActivateOutput("Used", true)
  A0_5133.allClients:ClUsed()
end
function ElevatorSwitch.Client.ClUsed(A0_5136)
  local L1_5137
  L1_5137 = A0_5136.Properties
  L1_5137 = L1_5137.Sounds
  L1_5137 = L1_5137.soundSoundOnPress
  if not L1_5137 or L1_5137 ~= "" then
  end
end
function ElevatorSwitch.Event_Enable(A0_5138)
  A0_5138.enabled = true
  A0_5138:ActivateOutput("Enabled", true)
end
function ElevatorSwitch.Event_Disable(A0_5139)
  A0_5139.enabled = false
  A0_5139:ActivateOutput("Disabled", true)
end
function ElevatorSwitch.Event_Use(A0_5140)
  A0_5140:Used()
end
ElevatorSwitch.FlowEvents = {
  Inputs = {
    Enable = {
      ElevatorSwitch.Event_Enable,
      "any"
    },
    Disable = {
      ElevatorSwitch.Event_Disable,
      "any"
    },
    Use = {
      ElevatorSwitch.Event_Use,
      "any"
    }
  },
  Outputs = {
    Enabled = "bool",
    Disabled = "bool",
    Used = "bool"
  }
}
