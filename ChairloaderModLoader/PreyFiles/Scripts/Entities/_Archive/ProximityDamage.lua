local L0_1129, L1_1130, L2_1131, L3_1132
L0_1129 = {}
L0_1129.type = "ProximityDamage"
L1_1130 = {}
L1_1130.fDamageRate = 70
L1_1130.bEnabled = 1
L1_1130.fRadius = 3
L1_1130.fHeight = 2
L1_1130.bShakeOnly = 0
L1_1130.bTriggerOnce = 0
L1_1130.nShakeType = 0
L1_1130.bSkipPlayer = 0
L1_1130.bSkipAI = 0
L1_1130.nDamageType = 0
L0_1129.Properties = L1_1130
L1_1130 = {}
L1_1130.Model = "Objects/Editor/T.cgf"
L0_1129.Editor = L1_1130
L0_1129.damageTime = 0
L0_1129.lastDamageTime = 0
L0_1129.bTriggeredServer = 0
L0_1129.bTriggeredClient = 0
ProximityDamage = L0_1129
L0_1129 = ProximityDamage
function L1_1130(A0_1133)
  A0_1133:RegisterState("Inactive")
  A0_1133:RegisterState("Active")
  A0_1133:OnReset()
end
L0_1129.CliSrv_OnInit = L1_1130
L0_1129 = ProximityDamage
function L1_1130(A0_1134)
  A0_1134:OnReset()
end
L0_1129.OnPropertyChange = L1_1130
L0_1129 = ProximityDamage
function L1_1130(A0_1135)
  A0_1135:Activate(0)
  A0_1135:SetUpdateType(eUT_Physics)
  A0_1135:TrackColliders(1)
  A0_1135.bTriggeredServer = 0
  A0_1135.bTriggeredClient = 0
  A0_1135.nNumColliders = 0
  if A0_1135.Properties.bEnabled == 1 then
    A0_1135:GotoState("Active")
  else
    A0_1135:GotoState("Inactive")
  end
  A0_1135:SetBBox({
    x = -A0_1135.Properties.fRadius,
    y = -A0_1135.Properties.fRadius,
    z = 0
  }, {
    x = A0_1135.Properties.fRadius,
    y = A0_1135.Properties.fRadius,
    z = A0_1135.Properties.fHeight
  })
  A0_1135.damageTime = 1 / A0_1135.Properties.fDamageRate
  A0_1135.lastDamageTime = _time + A0_1135.damageTime
  A0_1135.lastLocalTime = _time + 1
end
L0_1129.OnReset = L1_1130
L0_1129 = ProximityDamage
function L1_1130(A0_1136, A1_1137)
  local L2_1138
  L2_1138 = A0_1136.bTriggeredClient
  if L2_1138 == 1 then
    return
  else
    L2_1138 = A0_1136.Properties
    L2_1138 = L2_1138.bTriggerOnce
    if L2_1138 == 1 then
      A0_1136.bTriggeredClient = 1
    end
  end
  L2_1138 = A0_1136.CanBeDamaged
  L2_1138 = L2_1138(A0_1136, A1_1137)
  if L2_1138 == 0 then
    return
  end
  L2_1138 = _time
  L2_1138 = L2_1138 - A0_1136.lastLocalTime
  if L2_1138 <= 1 then
    return
  end
  L2_1138 = _time
  L2_1138 = L2_1138 + 0.6
  L2_1138 = L2_1138 + random(1, 100) / 200
  A0_1136.lastLocalTime = L2_1138
  L2_1138 = A0_1136.Properties
  L2_1138 = L2_1138.nShakeType
  if L2_1138 == 0 then
    L2_1138 = A0_1136.Properties
    L2_1138 = L2_1138.fDamageRate
    L2_1138 = L2_1138 * 2.2
    if L2_1138 > 45 then
      L2_1138 = 45
    end
    if random(1, 100) < 50 then
      L2_1138 = -L2_1138
    end
    A1_1137.cnt:ShakeCamera({
      x = 0,
      y = 0,
      z = 1
    }, L2_1138, 4, 0.25)
  else
    L2_1138 = A1_1137.cnt
    L2_1138 = L2_1138.ShakeCameraL
    L2_1138(L2_1138, 0.1, 11.73, 1.73)
  end
  L2_1138 = A0_1136.Properties
  L2_1138 = L2_1138.bShakeOnly
  if L2_1138 == 0 then
    L2_1138 = "MeleeDamageNormal"
    if A0_1136.Properties.nDamageType == 1 then
      L2_1138 = "MeleeDamageGas"
    end
    Hud:OnMeleeDamage(L2_1138)
  end
end
L0_1129.OnContactClient = L1_1130
L0_1129 = ProximityDamage
function L1_1130(A0_1139, A1_1140)
  local L2_1141
  L2_1141 = A0_1139.bTriggeredServer
  if L2_1141 == 1 then
    return
  else
    L2_1141 = A0_1139.Properties
    L2_1141 = L2_1141.bTriggerOnce
    if L2_1141 == 1 then
      A0_1139.bTriggeredServer = 1
    end
  end
  L2_1141 = A0_1139.CanBeDamaged
  L2_1141 = L2_1141(A0_1139, A1_1140)
  if L2_1141 ~= 0 then
    L2_1141 = A0_1139.Properties
    L2_1141 = L2_1141.bShakeOnly
  elseif L2_1141 == 1 then
    return
  end
  L2_1141 = A1_1140.dmgTime
  if L2_1141 == nil then
    L2_1141 = _time
    L2_1141 = L2_1141 + A0_1139.damageTime
    A1_1140.dmgTime = L2_1141
    return
  end
  L2_1141 = _time
  L2_1141 = L2_1141 - A1_1140.dmgTime
  if L2_1141 <= 1 then
    return
  end
  L2_1141 = A1_1140.ai
  if L2_1141 then
    L2_1141 = A1_1140.TriggerEvent
    L2_1141(A1_1140, AIEVENT_DISABLE)
  end
  L2_1141 = {}
  L2_1141.dir = {
    x = 0,
    y = 0,
    z = 1
  }
  L2_1141.damage = A0_1139.Properties.fDamageRate
  L2_1141.target = A1_1140
  L2_1141.shooter = A1_1140
  L2_1141.landed = 1
  L2_1141.impact_force_mul_final = 5
  L2_1141.impact_force_mul = 5
  L2_1141.damage_type = "normal"
  A1_1140:Damage(L2_1141)
  A1_1140.dmgTime = _time + A0_1139.damageTime
end
L0_1129.OnContactServer = L1_1130
L0_1129 = ProximityDamage
function L1_1130(A0_1142)
  local L1_1143
end
L0_1129.OnShutDown = L1_1130
L0_1129 = ProximityDamage
L1_1130 = {}
function L2_1131(A0_1144)
  A0_1144:CliSrv_OnInit()
end
L1_1130.OnInit = L2_1131
function L2_1131(A0_1145)
  local L1_1146
end
L1_1130.OnShutDown = L2_1131
L2_1131 = {}
L1_1130.Inactive = L2_1131
L2_1131 = {}
function L3_1132(A0_1147)
  local L1_1148
end
L2_1131.OnBeginState = L3_1132
function L3_1132(A0_1149)
  A0_1149:Activate(0)
end
L2_1131.OnEndState = L3_1132
L3_1132 = ProximityDamage
L3_1132 = L3_1132.OnContactServer
L2_1131.OnContact = L3_1132
function L3_1132(A0_1150, A1_1151)
  if A0_1150:CanBeDamaged(A1_1151) == 1 then
    A0_1150.nNumColliders = A0_1150.nNumColliders + 1
    A0_1150:Activate(1)
  end
end
L2_1131.OnEnterArea = L3_1132
function L3_1132(A0_1152, A1_1153)
  if A0_1152:CanBeDamaged(A1_1153) == 1 then
    A0_1152.nNumColliders = A0_1152.nNumColliders - 1
    if A0_1152.nNumColliders <= 0 then
      A0_1152:Activate(0)
    end
  end
end
L2_1131.OnLeaveArea = L3_1132
L1_1130.Active = L2_1131
L0_1129.Server = L1_1130
L0_1129 = ProximityDamage
L1_1130 = {}
function L2_1131(A0_1154)
  A0_1154:CliSrv_OnInit()
end
L1_1130.OnInit = L2_1131
function L2_1131(A0_1155)
  local L1_1156
end
L1_1130.OnShutDown = L2_1131
L2_1131 = {}
L1_1130.Inactive = L2_1131
L2_1131 = {}
function L3_1132(A0_1157)
  A0_1157:Activate(0)
end
L2_1131.OnEndState = L3_1132
L3_1132 = ProximityDamage
L3_1132 = L3_1132.OnContactClient
L2_1131.OnContact = L3_1132
function L3_1132(A0_1158, A1_1159)
  if A0_1158:CanBeDamaged(A1_1159) == 1 then
    A0_1158.nNumColliders = A0_1158.nNumColliders + 1
    A0_1158:Activate(1)
  end
end
L2_1131.OnEnterArea = L3_1132
function L3_1132(A0_1160, A1_1161)
  if A0_1160:CanBeDamaged(A1_1161) == 1 then
    A0_1160.nNumColliders = A0_1160.nNumColliders - 1
    if A0_1160.nNumColliders <= 0 then
      A0_1160:Activate(0)
    end
  end
end
L2_1131.OnLeaveArea = L3_1132
L1_1130.Active = L2_1131
L0_1129.Client = L1_1130
L0_1129 = ProximityDamage
function L1_1130(A0_1162, A1_1163)
  A0_1162:GotoState("Active")
end
L0_1129.Event_Enable = L1_1130
L0_1129 = ProximityDamage
function L1_1130(A0_1164, A1_1165)
  A0_1164:GotoState("Inactive")
end
L0_1129.Event_Disable = L1_1130
L0_1129 = ProximityDamage
function L1_1130(A0_1166, A1_1167)
  if A1_1167.type ~= "Player" then
    return 0
  end
  if A1_1167.Properties.bTakeProximityDamage and A1_1167.Properties.bTakeProximityDamage == 0 then
    return 0
  end
  if A1_1167:IsDead() then
    return 0
  end
  if A1_1167.Properties.bInvulnerable and A1_1167.Properties.bInvulnerable == 1 then
    return 0
  end
  if A0_1166.Properties.bSkipPlayer == 1 and A1_1167 == _localplayer then
    return 0
  end
  if A0_1166.Properties.bSkipAI == 1 and A1_1167.ai ~= nil then
    return 0
  end
  return 1
end
L0_1129.CanBeDamaged = L1_1130
L0_1129 = ProximityDamage
L1_1130 = {}
L2_1131 = {}
L3_1132 = {
  ProximityDamage.Event_Disable,
  "bool"
}
L2_1131.Disable = L3_1132
L3_1132 = {
  ProximityDamage.Event_Enable,
  "bool"
}
L2_1131.Enable = L3_1132
L1_1130.Inputs = L2_1131
L2_1131 = {}
L2_1131.Disable = "bool"
L2_1131.Enable = "bool"
L1_1130.Outputs = L2_1131
L0_1129.FlowEvents = L1_1130
