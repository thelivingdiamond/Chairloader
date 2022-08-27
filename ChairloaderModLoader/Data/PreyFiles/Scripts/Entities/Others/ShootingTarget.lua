local L0_7134, L1_7135
L0_7134 = {}
L1_7135 = {}
L0_7134.Client = L1_7135
L1_7135 = {}
L0_7134.Server = L1_7135
L1_7135 = {}
L1_7135.fileModel = "objects/library/architecture/aircraftcarrier/props/misc/target.cgf"
L1_7135.bTurningMode = 1
L1_7135.fIntervallMin = 3
L1_7135.fIntervallMax = 5
L1_7135.fLightUpTime = 2
L1_7135.fTurnSpeed = 0.5
L1_7135.soclasses_SmartObjectClass = "ShootingTarget"
L0_7134.Properties = L1_7135
L1_7135 = {}
L1_7135.Icon = "Item.bmp"
L1_7135.ShowBounds = 1
L0_7134.Editor = L1_7135
L1_7135 = {
  "Activated",
  "Deactivated",
  "Turning",
  "Init"
}
L0_7134.States = L1_7135
ShootingTarget = L0_7134
L0_7134 = 0
ACTIVATION_TIMER = L0_7134
L0_7134 = 1
TURN_TIMER = L0_7134
L0_7134 = ShootingTarget
function L1_7135(A0_7136)
  local L1_7137
  L1_7137 = A0_7136.Properties
  if not EmptyString(L1_7137.fileModel) then
    A0_7136:LoadObject(0, L1_7137.fileModel)
  end
  EntityCommon.PhysicalizeRigid(A0_7136, 0, A0_7136.physics, 0)
  A0_7136.side = 0
  A0_7136.ended = 0
  A0_7136:GetAngles(A0_7136.initialrot)
  CopyVector(A0_7136.turnrot, A0_7136.initialrot)
  A0_7136.turnrot.z = A0_7136.turnrot.z + math.pi / 2
  A0_7136:Activate(1)
  A0_7136:GotoState("Deactivated")
end
L0_7134.OnReset = L1_7135
L0_7134 = ShootingTarget
function L1_7135(A0_7138, A1_7139)
  local L2_7140
  L2_7140 = A0_7138.side
  A1_7139.side = L2_7140
  L2_7140 = A0_7138.ended
  A1_7139.ended = L2_7140
end
L0_7134.OnSave = L1_7135
L0_7134 = ShootingTarget
function L1_7135(A0_7141, A1_7142)
  local L2_7143
  L2_7143 = A1_7142.side
  A0_7141.side = L2_7143
  L2_7143 = A1_7142.ended
  A0_7141.ended = L2_7143
end
L0_7134.OnLoad = L1_7135
L0_7134 = ShootingTarget
function L1_7135(A0_7144)
  A0_7144:OnReset()
end
L0_7134.OnPropertyChange = L1_7135
L0_7134 = ShootingTarget
L0_7134 = L0_7134.Server
function L1_7135(A0_7145)
  A0_7145.physics = {
    bRigidBody = 0,
    bRigidBodyActive = 0,
    Density = -1,
    Mass = -1
  }
  A0_7145.tmp = {
    x = 0,
    y = 0,
    z = 0
  }
  A0_7145.turnrot = {
    x = 0,
    y = 0,
    z = 0
  }
  A0_7145.initialrot = {
    x = 0,
    y = 0,
    z = 0
  }
  A0_7145.inc = 0
  A0_7145.init = 1
  A0_7145:OnReset()
end
L0_7134.OnInit = L1_7135
L0_7134 = ShootingTarget
L0_7134 = L0_7134.Server
function L1_7135(A0_7146, A1_7147)
  local L2_7148, L3_7149
  L3_7149 = A0_7146
  L2_7148 = A0_7146.GetState
  L2_7148 = L2_7148(L3_7149)
  if L2_7148 ~= "Activated" then
    return
  end
  L2_7148 = g_Vectors
  L2_7148 = L2_7148.temp
  L3_7149 = SubVectors
  L3_7149(L2_7148, A0_7146:GetPos(), A1_7147.pos)
  L3_7149 = LengthVector
  L3_7149 = L3_7149(L2_7148)
  L3_7149 = (1 - L3_7149 * 2 + 0.08) * 10
  if L3_7149 > 9.4 then
    L3_7149 = 10
  else
    dec = string.find(L3_7149, ".", 1, 1)
    L3_7149 = tonumber(string.sub(L3_7149, 1, dec - 1))
  end
  if A0_7146.Properties.bTurningMode == 1 then
    if A1_7147.shooter and A1_7147.shooter == g_localActor then
    else
    end
    if A0_7146.side == 1 then
      A0_7146:GotoState("Init")
      A0_7146:ActivateOutput("Hit", L3_7149)
    else
      A0_7146:ActivateOutput("Hit", -1)
    end
  else
  end
end
L0_7134.OnHit = L1_7135
L0_7134 = ShootingTarget
function L1_7135(A0_7150)
  A0_7150:GotoState("Init")
  BroadcastEvent(A0_7150, "Activated")
end
L0_7134.Event_Activated = L1_7135
L0_7134 = ShootingTarget
function L1_7135(A0_7151)
  A0_7151.ended = 1
  A0_7151:GotoState("Deactivated")
  BroadcastEvent(A0_7151, "Deactivated")
end
L0_7134.Event_Deactivated = L1_7135
L0_7134 = ShootingTarget
L0_7134 = L0_7134.Server
L1_7135 = {}
function L1_7135.OnBeginState(A0_7152)
  local L1_7153
  L1_7153 = A0_7152.init
  if L1_7153 == 0 then
    L1_7153 = A0_7152.Properties
    A0_7152:KillTimer(ACTIVATION_TIMER)
    A0_7152:KillTimer(TURN_TIMER)
    AI.SetSmartObjectState(A0_7152.id, "Neutral")
    if L1_7153.fIntervallMin > L1_7153.fIntervallMax then
      L1_7153.fIntervallMin = L1_7153.fIntervallMax
    end
    A0_7152:SetTimer(ACTIVATION_TIMER, 20)
  else
    A0_7152.init = 0
  end
end
function L1_7135.OnTimer(A0_7154, A1_7155, A2_7156)
  if A1_7155 == ACTIVATION_TIMER then
    A0_7154:GetAngles(A0_7154.tmp)
    A0_7154.inc = A0_7154.inc + A0_7154.Properties.fTurnSpeed
    A0_7154.tmp.z = A0_7154.tmp.z + A0_7154.Properties.fTurnSpeed
    A0_7154:SetAngles(A0_7154.tmp)
    if A0_7154.inc < math.pi then
      A0_7154:SetTimer(ACTIVATION_TIMER, 20)
    else
      A0_7154:SetAngles(A0_7154.initialrot)
    end
  end
end
L0_7134.Deactivated = L1_7135
L0_7134 = ShootingTarget
L0_7134 = L0_7134.Server
L1_7135 = {}
function L1_7135.OnBeginState(A0_7157)
  A0_7157.ended = 0
  if A0_7157.Properties.bTurningMode == 1 then
    AI.SetSmartObjectState(A0_7157.id, "Neutral")
    if A0_7157.Properties.fIntervallMin > A0_7157.Properties.fIntervallMax then
      A0_7157.Properties.fIntervallMin = A0_7157.Properties.fIntervallMax
    end
    A0_7157:SetTimer(ACTIVATION_TIMER, 1000 * random(A0_7157.Properties.fIntervallMin, A0_7157.Properties.fIntervallMax))
  end
end
function L1_7135.OnTimer(A0_7158, A1_7159, A2_7160)
  if A0_7158.ended == 1 then
    A0_7158:GotoState("Deactivated")
    return
  end
  if A1_7159 == ACTIVATION_TIMER then
    A0_7158:GetAngles(A0_7158.tmp)
    A0_7158.inc = A0_7158.inc + A0_7158.Properties.fTurnSpeed
    A0_7158.tmp.z = A0_7158.tmp.z - A0_7158.Properties.fTurnSpeed
    A0_7158:SetAngles(A0_7158.tmp)
    if A0_7158.inc < math.pi then
      A0_7158:SetTimer(ACTIVATION_TIMER, 20)
    else
      A0_7158:SetAngles(A0_7158.initialrot)
      AI.SetSmartObjectState(A0_7158.id, "Colored")
      A0_7158.side = 1
      A0_7158:SetTimer(TURN_TIMER, 1000 * A0_7158.Properties.fLightUpTime)
    end
  elseif A1_7159 == TURN_TIMER then
    AI.SetSmartObjectState(A0_7158.id, "Neutral")
    A0_7158:GotoState("Init")
  end
end
L0_7134.Activated = L1_7135
L0_7134 = ShootingTarget
L0_7134 = L0_7134.Server
L1_7135 = {}
function L1_7135.OnBeginState(A0_7161)
  A0_7161:KillTimer(ACTIVATION_TIMER)
  A0_7161:KillTimer(TURN_TIMER)
  A0_7161.inc = 0
  A0_7161.side = 0
  A0_7161:SetTimer(ACTIVATION_TIMER, 25)
end
function L1_7135.OnTimer(A0_7162, A1_7163, A2_7164)
  if A1_7163 == ACTIVATION_TIMER then
    A0_7162:GetAngles(A0_7162.tmp)
    A0_7162.inc = A0_7162.inc + A0_7162.Properties.fTurnSpeed
    A0_7162.tmp.z = A0_7162.tmp.z + A0_7162.Properties.fTurnSpeed
    A0_7162:SetAngles(A0_7162.tmp)
    if A0_7162.inc < math.pi / 2 then
      A0_7162:SetTimer(ACTIVATION_TIMER, 25)
    else
      A0_7162:SetAngles(A0_7162.turnrot)
      A0_7162:GotoState("Activated")
    end
  end
end
L0_7134.Init = L1_7135
L0_7134 = ShootingTarget
L1_7135 = {}
L1_7135.Inputs = {
  Deactivated = {
    ShootingTarget.Event_Deactivated,
    "bool"
  },
  Activated = {
    ShootingTarget.Event_Activated,
    "bool"
  }
}
L1_7135.Outputs = {
  Deactivated = "bool",
  Activated = "bool",
  Hit = "int",
  PlayerOne = "int",
  PlayerTwo = "int"
}
L0_7134.FlowEvents = L1_7135
