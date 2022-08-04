local L0_1168, L1_1169, L2_1170, L3_1171
L0_1168 = {}
L0_1168.type = "Trigger"
L1_1169 = {}
L1_1169.DimX = 5
L1_1169.DimY = 5
L1_1169.DimZ = 5
L1_1169.bEnabled = 1
L1_1169.EnterDelay = 0
L1_1169.ExitDelay = 0
L1_1169.bOnlyPlayer = 1
L1_1169.bOnlyMyPlayer = 0
L1_1169.bOnlyAI = 0
L1_1169.bOnlySpecialAI = 0
L1_1169.bKillOnTrigger = 0
L1_1169.bTriggerOnce = 0
L1_1169.ScriptCommand = ""
L1_1169.PlaySequence = ""
L1_1169.aianchorAIAction = ""
L1_1169.TextInstruction = ""
L1_1169.bActivateWithUseButton = 0
L1_1169.bInVehicleOnly = 0
L1_1169.iNeededKey = 0
L1_1169.bKeepKeycardAfterUse = 0
L0_1168.Properties = L1_1169
L1_1169 = {}
L1_1169.Model = "Objects/Editor/T.cgf"
L1_1169.ShowBounds = 1
L0_1168.Editor = L1_1169
L0_1168.bLocked = false
ProximityKeyTrigger = L0_1168
L0_1168 = ProximityKeyTrigger
function L1_1169(A0_1172)
  A0_1172:OnReset()
end
L0_1168.OnPropertyChange = L1_1169
L0_1168 = ProximityKeyTrigger
function L1_1169(A0_1173)
  A0_1173:Activate(0)
  A0_1173:SetUpdateType(eUT_Physics)
  A0_1173:TrackColliders(1)
  A0_1173.Who = nil
  A0_1173.Entered = 0
  A0_1173.bLocked = 0
  A0_1173.bTriggered = 0
  A0_1173:RegisterState("Inactive")
  A0_1173:RegisterState("Empty")
  A0_1173:RegisterState("Occupied")
  A0_1173:RegisterState("OccupiedUse")
  A0_1173:OnReset()
end
L0_1168.OnInit = L1_1169
L0_1168 = ProximityKeyTrigger
function L1_1169(A0_1174)
  local L1_1175
end
L0_1168.OnShutDown = L1_1169
L0_1168 = ProximityKeyTrigger
function L1_1169(A0_1176, A1_1177)
  A1_1177:WriteInt(A0_1176.bTriggered)
  A1_1177:WriteInt(A0_1176.bLocked)
  if A0_1176.Who then
    if A0_1176.Who == _localplayer then
      A1_1177:WriteInt(0)
    else
      A1_1177:WriteInt(A0_1176.Who.id)
    end
  else
    A1_1177:WriteInt(-1)
  end
end
L0_1168.OnSave = L1_1169
L0_1168 = ProximityKeyTrigger
function L1_1169(A0_1178, A1_1179)
  A0_1178.bTriggered = A1_1179:ReadInt()
  A0_1178.bLocked = A1_1179:ReadInt()
  A0_1178.WhoID = A1_1179:ReadInt()
  if A0_1178.WhoID < 0 then
    A0_1178.WhoID = nil
  elseif A0_1178.WhoID == 0 then
    A0_1178.WhoID = 0
  end
end
L0_1168.OnLoad = L1_1169
L0_1168 = ProximityKeyTrigger
function L1_1169(A0_1180, A1_1181)
  A0_1180.bTriggered = A1_1181:ReadInt()
  A0_1180.bLocked = A1_1181:ReadInt()
end
L0_1168.OnLoadRELEASE = L1_1169
L0_1168 = ProximityKeyTrigger
function L1_1169(A0_1182)
  local L1_1183, L2_1184
  L2_1184 = A0_1182
  L1_1183 = A0_1182.KillTimer
  L1_1183(L2_1184)
  A0_1182.bTriggered = 0
  L1_1183 = {}
  L2_1184 = A0_1182.Properties
  L2_1184 = L2_1184.DimX
  L2_1184 = -L2_1184
  L2_1184 = L2_1184 / 2
  L1_1183.x = L2_1184
  L2_1184 = A0_1182.Properties
  L2_1184 = L2_1184.DimY
  L2_1184 = -L2_1184
  L2_1184 = L2_1184 / 2
  L1_1183.y = L2_1184
  L2_1184 = A0_1182.Properties
  L2_1184 = L2_1184.DimZ
  L2_1184 = -L2_1184
  L2_1184 = L2_1184 / 2
  L1_1183.z = L2_1184
  L2_1184 = {}
  L2_1184.x = A0_1182.Properties.DimX / 2
  L2_1184.y = A0_1182.Properties.DimY / 2
  L2_1184.z = A0_1182.Properties.DimZ / 2
  A0_1182:SetBBox(L1_1183, L2_1184)
  A0_1182.Who = nil
  A0_1182.UpdateCounter = 0
  A0_1182.Entered = 0
  if A0_1182.Properties.bEnabled == 1 then
    A0_1182:GotoState("Empty")
  else
    A0_1182:GotoState("Inactive")
  end
  if A0_1182.Properties.iNeededKey ~= -1 then
    A0_1182.bLocked = 1
  else
    A0_1182.bLocked = 0
  end
end
L0_1168.OnReset = L1_1169
L0_1168 = ProximityKeyTrigger
function L1_1169(A0_1185, A1_1186)
  if A0_1185:GetState() == "Inactive" then
    return
  end
  if A0_1185.Entered ~= 0 then
    return
  end
  if A0_1185.Properties.bTriggerOnce == 1 and A0_1185.bTriggered == 1 then
    return
  end
  A0_1185.bTriggered = 1
  A0_1185.Entered = 1
  if A0_1185.Properties.ScriptCommand and A0_1185.Properties.ScriptCommand ~= "" then
    dostring(A0_1185.Properties.ScriptCommand)
  end
  if A0_1185.Properties.PlaySequence ~= "" then
    Movie.PlaySequence(A0_1185.Properties.PlaySequence)
  end
  BroadcastEvent(A0_1185, "Enter")
  AI:RegisterWithAI(A0_1185.id, 0)
end
L0_1168.Event_Enter = L1_1169
L0_1168 = ProximityKeyTrigger
function L1_1169(A0_1187, A1_1188)
  if A0_1187.Entered == 0 then
    return
  end
  A0_1187.Entered = 0
  BroadcastEvent(A0_1187, "Leave")
  if A0_1187.Properties.bTriggerOnce == 1 then
    A0_1187:GotoState("Inactive")
  end
end
L0_1168.Event_Leave = L1_1169
L0_1168 = ProximityKeyTrigger
function L1_1169(A0_1189, A1_1190)
  A0_1189:GotoState("Empty")
  BroadcastEvent(A0_1189, "Enable")
end
L0_1168.Event_Enable = L1_1169
L0_1168 = ProximityKeyTrigger
function L1_1169(A0_1191, A1_1192)
  A0_1191:GotoState("Inactive")
  AI:RegisterWithAI(A0_1191.id, 0)
  BroadcastEvent(A0_1191, "Disable")
end
L0_1168.Event_Disable = L1_1169
L0_1168 = ProximityKeyTrigger
function L1_1169(A0_1193, A1_1194)
  A0_1193.bLocked = 0
  BroadcastEvent(A0_1193, "Unlocked")
end
L0_1168.Event_Unlocked = L1_1169
L0_1168 = ProximityKeyTrigger
function L1_1169(A0_1195, A1_1196)
  if A0_1195.Properties.bOnlyPlayer ~= 0 and A1_1196.type ~= "Player" then
    return 0
  end
  if A0_1195.Properties.bOnlySpecialAI ~= 0 and A1_1196.ai ~= nil and A1_1196.Properties.special == 0 then
    return 0
  end
  if A0_1195.Properties.bOnlyAI ~= 0 and A1_1196.ai == nil then
    return 0
  end
  if A0_1195.Properties.bOnlyMyPlayer ~= 0 and A1_1196 ~= _localplayer then
    return 0
  end
  if A0_1195.Properties.bInVehicleOnly ~= 0 and not A1_1196.theVehicle then
    return 0
  end
  if A1_1196:IsDead() then
    return 0
  end
  return 1
end
L0_1168.IsValidSource = L1_1169
L0_1168 = ProximityKeyTrigger
L1_1169 = {}
function L2_1170(A0_1197)
  AI:RegisterWithAI(A0_1197.id, 0)
end
L1_1169.OnBeginState = L2_1170
function L2_1170(A0_1198)
  local L1_1199
end
L1_1169.OnEndState = L2_1170
L0_1168.Inactive = L1_1169
L0_1168 = ProximityKeyTrigger
L1_1169 = {}
function L2_1170(A0_1200)
  A0_1200.Who = nil
  A0_1200.UpdateCounter = 0
  A0_1200.Entered = 0
  if A0_1200.Properties.aianchorAIAction ~= "" then
    AI:RegisterWithAI(A0_1200.id, AIAnchor[A0_1200.Properties.aianchorAIAction])
  end
end
L1_1169.OnBeginState = L2_1170
function L2_1170(A0_1201)
  A0_1201:GotoState("Occupied")
end
L1_1169.OnTimer = L2_1170
function L2_1170(A0_1202, A1_1203, A2_1204)
  if A0_1202:IsValidSource(A1_1203) == 0 then
    return
  end
  if A1_1203.ai == nil and A0_1202.Properties.bActivateWithUseButton ~= 0 then
    A0_1202.Who = A1_1203
    A0_1202:GotoState("OccupiedUse")
    return
  end
  if 0 < A0_1202.Properties.EnterDelay then
    if A0_1202.Who == nil then
      A0_1202.Who = A1_1203
      A0_1202:SetTimer(A0_1202.Properties.EnterDelay * 1000)
    end
  else
    A0_1202.Who = A1_1203
    A0_1202:GotoState("Occupied")
  end
end
L1_1169.OnEnterArea = L2_1170
L0_1168.Empty = L1_1169
L0_1168 = ProximityKeyTrigger
L1_1169 = {}
function L2_1170(A0_1205)
  A0_1205:Event_Enter(A0_1205.Who)
  if A0_1205.Properties.bKillOnTrigger == 1 then
    Server:RemoveEntity(A0_1205.id)
  end
end
L1_1169.OnBeginState = L2_1170
function L2_1170(A0_1206)
  A0_1206:Event_Leave(A0_1206, A0_1206.Who)
  if A0_1206.Properties.bTriggerOnce ~= 1 then
    A0_1206:GotoState("Empty")
  end
end
L1_1169.OnTimer = L2_1170
function L2_1170(A0_1207, A1_1208, A2_1209)
  if A0_1207:IsValidSource(A1_1208) == 0 then
    return
  end
  if A0_1207.Properties.ExitDelay == 0 then
    A0_1207.Properties.ExitDelay = 0.01
  end
  A0_1207:SetTimer(A0_1207.Properties.ExitDelay * 1000)
end
L1_1169.OnLeaveArea = L2_1170
L0_1168.Occupied = L1_1169
L0_1168 = ProximityKeyTrigger
L1_1169 = {}
function L2_1170(A0_1210)
  A0_1210:Activate(1)
end
L1_1169.OnBeginState = L2_1170
function L2_1170(A0_1211)
  A0_1211:Activate(0)
end
L1_1169.OnEndState = L2_1170
function L2_1170(A0_1212)
  if A0_1212.WhoID then
    if A0_1212.WhoID == 0 then
      A0_1212.Who = _localplayer
    else
      A0_1212.Who = System.GetEntity(A0_1212.WhoID)
    end
    A0_1212.WhoID = nil
  end
  if A0_1212.Who.cnt and not A0_1212.Who.cnt.use_pressed then
    if 0 < strlen(A0_1212.Properties.TextInstruction) then
      Hud.label = A0_1212.Properties.TextInstruction
    end
    return
  end
  if A0_1212.bLocked ~= 0 then
    if A0_1212.Who.keycards and A0_1212.Who.keycards[A0_1212.Properties.iNeededKey] == 1 then
      if A0_1212.Properties.bKeepKeycardAfterUse == 0 then
        A0_1212.Who.keycards[A0_1212.Properties.iNeededKey] = 0
      end
      A0_1212:Event_Unlocked(A0_1212)
      System.LogToConsole("Trigger unlocked !")
    else
      return 0
    end
  end
  if 0 < A0_1212.Properties.EnterDelay then
    A0_1212:SetTimer(A0_1212.Properties.EnterDelay * 1000)
  else
    A0_1212:GotoState("Occupied")
  end
end
L1_1169.OnUpdate = L2_1170
function L2_1170(A0_1213)
  A0_1213:GotoState("Occupied")
end
L1_1169.OnTimer = L2_1170
function L2_1170(A0_1214, A1_1215, A2_1216)
  if A0_1214.Who == A1_1215 then
    A0_1214:GotoState("Empty")
  end
end
L1_1169.OnLeaveArea = L2_1170
L0_1168.OccupiedUse = L1_1169
L0_1168 = ProximityKeyTrigger
L1_1169 = {}
L2_1170 = {}
L3_1171 = {
  ProximityKeyTrigger.Event_Disable,
  "bool"
}
L2_1170.Disable = L3_1171
L3_1171 = {
  ProximityKeyTrigger.Event_Enable,
  "bool"
}
L2_1170.Enable = L3_1171
L3_1171 = {
  ProximityKeyTrigger.Event_Enter,
  "bool"
}
L2_1170.Enter = L3_1171
L3_1171 = {
  ProximityKeyTrigger.Event_Leave,
  "bool"
}
L2_1170.Leave = L3_1171
L3_1171 = {
  ProximityKeyTrigger.Event_Unlocked,
  "bool"
}
L2_1170.Leave = L3_1171
L1_1169.Inputs = L2_1170
L2_1170 = {}
L2_1170.Disable = "bool"
L2_1170.Enable = "bool"
L2_1170.Enter = "bool"
L2_1170.Leave = "bool"
L2_1170.Leave = "bool"
L1_1169.Outputs = L2_1170
L0_1168.FlowEvents = L1_1169
