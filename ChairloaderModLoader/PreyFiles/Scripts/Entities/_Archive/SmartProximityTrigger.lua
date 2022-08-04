local L0_1302, L1_1303, L2_1304, L3_1305
L0_1302 = {}
L0_1302.type = "Trigger"
L1_1303 = {}
L1_1303.DimX = 5
L1_1303.DimY = 5
L1_1303.DimZ = 5
L1_1303.bEnabled = 1
L1_1303.EnterDelay = 0
L1_1303.ExitDelay = 0
L1_1303.bOnlyPlayer = 1
L1_1303.bOnlyMyPlayer = 0
L0_1302.Properties = L1_1303
L1_1303 = {}
L1_1303.Model = "Objects/Editor/T.cgf"
L1_1303.ShowBounds = 1
L0_1302.Editor = L1_1303
L0_1302.Who = nil
L0_1302.Enabled = 1
L0_1302.Entered = 0
SmartProximityTrigger = L0_1302
L0_1302 = SmartProximityTrigger
function L1_1303(A0_1306)
  A0_1306:OnReset()
end
L0_1302.OnPropertyChange = L1_1303
L0_1302 = SmartProximityTrigger
function L1_1303(A0_1307)
  A0_1307:OnReset()
end
L0_1302.OnInit = L1_1303
L0_1302 = SmartProximityTrigger
function L1_1303(A0_1308)
  local L1_1309
end
L0_1302.OnShutDown = L1_1303
L0_1302 = SmartProximityTrigger
function L1_1303(A0_1310)
  local L1_1311, L2_1312
  L1_1311 = {}
  L2_1312 = A0_1310.Properties
  L2_1312 = L2_1312.DimX
  L2_1312 = -L2_1312
  L2_1312 = L2_1312 / 2
  L1_1311.x = L2_1312
  L2_1312 = A0_1310.Properties
  L2_1312 = L2_1312.DimY
  L2_1312 = -L2_1312
  L2_1312 = L2_1312 / 2
  L1_1311.y = L2_1312
  L2_1312 = A0_1310.Properties
  L2_1312 = L2_1312.DimZ
  L2_1312 = -L2_1312
  L2_1312 = L2_1312 / 2
  L1_1311.z = L2_1312
  L2_1312 = {}
  L2_1312.x = A0_1310.Properties.DimX / 2
  L2_1312.y = A0_1310.Properties.DimY / 2
  L2_1312.z = A0_1310.Properties.DimZ / 2
  A0_1310:SetBBox(L1_1311, L2_1312)
  A0_1310.Enabled = A0_1310.Properties.bEnabled
  A0_1310.Who = nil
  A0_1310.UpdateCounter = 0
  A0_1310.Entered = 0
  A0_1310:GotoState("Empty")
end
L0_1302.OnReset = L1_1303
L0_1302 = SmartProximityTrigger
function L1_1303(A0_1313, A1_1314)
  if A0_1313.Enabled ~= 1 or A0_1313.Entered ~= 0 then
    return
  end
  A0_1313.Entered = 1
  if A1_1314 then
    System.LogToConsole("Player " .. A1_1314:GetName() .. " Enter SmartProximityTrigger " .. A0_1313:GetName())
  end
  BroadcastEvent(A0_1313, "Enter")
end
L0_1302.Event_Enter = L1_1303
L0_1302 = SmartProximityTrigger
function L1_1303(A0_1315, A1_1316)
  if A0_1315.Enabled ~= 1 or A0_1315.Entered == 0 then
    return
  end
  System.LogToConsole("Player " .. A1_1316:GetName() .. " Leave SmartProximityTrigger " .. A0_1315:GetName())
  BroadcastEvent(A0_1315, "Leave")
end
L0_1302.Event_Leave = L1_1303
L0_1302 = SmartProximityTrigger
function L1_1303(A0_1317, A1_1318)
  A0_1317.Enabled = 1
  BroadcastEvent(A0_1317, "Enable")
end
L0_1302.Event_Enable = L1_1303
L0_1302 = SmartProximityTrigger
function L1_1303(A0_1319, A1_1320)
  A0_1319.Enabled = 0
  A0_1319:GotoState("Empty")
  BroadcastEvent(A0_1319, "Disable")
end
L0_1302.Event_Disable = L1_1303
L0_1302 = SmartProximityTrigger
L1_1303 = {}
function L2_1304(A0_1321)
  local L1_1322
  A0_1321.Who = nil
  A0_1321.UpdateCounter = 0
  A0_1321.Entered = 0
  A0_1321.StartEnterDelay = nil
end
L1_1303.OnBeginState = L2_1304
function L2_1304(A0_1323)
  local L1_1324
end
L1_1303.OnEndState = L2_1304
function L2_1304(A0_1325)
  local L1_1326
  A0_1325.StartEnterDelay = nil
end
L1_1303.OnTimer = L2_1304
function L2_1304(A0_1327, A1_1328)
  if A0_1327.Enabled ~= 1 then
    return
  end
  if A0_1327.Properties.bOnlyPlayer ~= 0 and A1_1328.type ~= "Player" then
    return
  end
  if A0_1327.Properties.bOnlyMyPlayer ~= 0 and A1_1328 ~= _localplayer then
    return
  end
  if A0_1327.Who == nil then
    if 0 < A0_1327.Properties.EnterDelay then
      if A0_1327.StartEnterDelay == nil then
        A0_1327:SetTimer(500)
        System.LogToConsole("tada!")
        A0_1327.StartEnterDelay = _time * 1000
      elseif _time * 1000 - A0_1327.StartEnterDelay >= A0_1327.Properties.EnterDelay * 1000 then
        A0_1327.Who = A1_1328
        A0_1327.StartEnterDelay = nil
        A0_1327:KillTimer()
        A0_1327:GotoState("Occupied")
      else
        A0_1327:SetTimer(500)
      end
    else
      A0_1327.Who = A1_1328
      A0_1327:GotoState("Occupied")
    end
  end
end
L1_1303.OnContact = L2_1304
L0_1302.Empty = L1_1303
L0_1302 = SmartProximityTrigger
L1_1303 = {}
function L2_1304(A0_1329)
  A0_1329:Event_Enter(A0_1329.Who)
end
L1_1303.OnBeginState = L2_1304
function L2_1304(A0_1330)
  local L1_1331
end
L1_1303.OnEndState = L2_1304
function L2_1304(A0_1332)
  A0_1332:Event_Enter(A0_1332.Who)
end
L1_1303.OnTimer = L2_1304
function L2_1304(A0_1333, A1_1334)
  if A0_1333.Enabled ~= 1 then
    return
  end
  if A0_1333.Properties.bOnlyPlayer ~= 0 and A1_1334.type ~= "Player" then
    return
  end
  if A0_1333.Properties.bOnlyMyPlayer ~= 0 and A1_1334 ~= _localplayer then
    return
  end
  if A0_1333.Properties.ExitDelay == 0 then
    A0_1333.Properties.ExitDelay = 0.01
  end
  A0_1333:SetTimer(A0_1333.Properties.ExitDelay * 1000)
end
L1_1303.OnContact = L2_1304
function L2_1304(A0_1335)
  System.LogToConsole("Sending on leave")
  A0_1335:Event_Leave(A0_1335, A0_1335.Who)
  A0_1335:GotoState("Empty")
end
L1_1303.OnTimer = L2_1304
L0_1302.Occupied = L1_1303
L0_1302 = SmartProximityTrigger
L1_1303 = {}
L2_1304 = {}
L3_1305 = {
  SmartProximityTrigger.Event_Disable,
  "bool"
}
L2_1304.Disable = L3_1305
L3_1305 = {
  SmartProximityTrigger.Event_Enable,
  "bool"
}
L2_1304.Enable = L3_1305
L3_1305 = {
  SmartProximityTrigger.Event_Enter,
  "bool"
}
L2_1304.Enter = L3_1305
L3_1305 = {
  SmartProximityTrigger.Event_Leave,
  "bool"
}
L2_1304.Leave = L3_1305
L1_1303.Inputs = L2_1304
L2_1304 = {}
L2_1304.Disable = "bool"
L2_1304.Enable = "bool"
L2_1304.Enter = "bool"
L2_1304.Leave = "bool"
L1_1303.Outputs = L2_1304
L0_1302.FlowEvents = L1_1303
