local L0_1412, L1_1413, L2_1414, L3_1415
L0_1412 = {}
L0_1412.type = "Trigger"
L1_1413 = {}
L1_1413.DimX = 1
L1_1413.DimY = 1
L1_1413.DimZ = 1
L1_1413.Distance = 100
L1_1413.bEnabled = 1
L1_1413.EnterDelay = 0
L1_1413.ExitDelay = 0
L1_1413.bTriggerOnce = 0
L1_1413.ScriptCommand = ""
L1_1413.PlaySequence = ""
L1_1413.TextInstruction = ""
L1_1413.bUseKey = 0
L0_1412.Properties = L1_1413
L1_1413 = {}
L1_1413.Model = "Editor/Objects/Vis.cgf"
L1_1413.ShowBounds = 1
L0_1412.Editor = L1_1413
VisibilityTrigger = L0_1412
L0_1412 = VisibilityTrigger
function L1_1413(A0_1416)
  A0_1416:OnReset()
end
L0_1412.OnPropertyChange = L1_1413
L0_1412 = VisibilityTrigger
function L1_1413(A0_1417)
  A0_1417:Activate(0)
  A0_1417:SetUpdateType(eUT_Visible)
  A0_1417:SetRegisterInSectors(1)
  A0_1417:RegisterState("Disabled")
  A0_1417:RegisterState("Visible")
  A0_1417:RegisterState("Invisible")
  A0_1417:OnReset()
end
L0_1412.OnInit = L1_1413
L0_1412 = VisibilityTrigger
function L1_1413(A0_1418)
  local L1_1419
end
L0_1412.OnShutDown = L1_1413
L0_1412 = VisibilityTrigger
function L1_1413(A0_1420, A1_1421)
  A1_1421:WriteInt(A0_1420.bTriggered)
end
L0_1412.OnSave = L1_1413
L0_1412 = VisibilityTrigger
function L1_1413(A0_1422, A1_1423)
  A0_1422.bTriggered = A1_1423:ReadInt()
end
L0_1412.OnLoad = L1_1413
L0_1412 = VisibilityTrigger
function L1_1413(A0_1424)
  local L1_1425, L2_1426
  L2_1426 = A0_1424
  L1_1425 = A0_1424.KillTimer
  L1_1425(L2_1426)
  A0_1424.bTriggered = 0
  A0_1424.bVisible = 0
  L1_1425 = {}
  L2_1426 = A0_1424.Properties
  L2_1426 = L2_1426.DimX
  L2_1426 = -L2_1426
  L2_1426 = L2_1426 / 2
  L1_1425.x = L2_1426
  L2_1426 = A0_1424.Properties
  L2_1426 = L2_1426.DimY
  L2_1426 = -L2_1426
  L2_1426 = L2_1426 / 2
  L1_1425.y = L2_1426
  L2_1426 = A0_1424.Properties
  L2_1426 = L2_1426.DimZ
  L2_1426 = -L2_1426
  L2_1426 = L2_1426 / 2
  L1_1425.z = L2_1426
  L2_1426 = {}
  L2_1426.x = A0_1424.Properties.DimX / 2
  L2_1426.y = A0_1424.Properties.DimY / 2
  L2_1426.z = A0_1424.Properties.DimZ / 2
  A0_1424:SetBBox(L1_1425, L2_1426)
  A0_1424:SetUpdateRadius(A0_1424.Properties.Distance)
  if A0_1424.Properties.bEnabled == 1 then
    A0_1424:GotoState("Invisible")
  else
    A0_1424:GotoState("Disabled")
  end
end
L0_1412.OnReset = L1_1413
L0_1412 = VisibilityTrigger
function L1_1413(A0_1427, A1_1428)
  if A0_1427.bVisible ~= 0 then
    return
  end
  if A0_1427.Properties.bTriggerOnce == 1 and A0_1427.bTriggered == 1 then
    return
  end
  A0_1427.bTriggered = 1
  A0_1427.bVisible = 1
  if A0_1427.Properties.ScriptCommand and A0_1427.Properties.ScriptCommand ~= "" then
    dostring(A0_1427.Properties.ScriptCommand)
  end
  if A0_1427.Properties.PlaySequence ~= "" then
    Movie.PlaySequence(A0_1427.Properties.PlaySequence)
  end
  BroadcastEvent(A0_1427, "Visible")
  A0_1427:GotoState("Visible")
  System.Log("* VISIBLE")
end
L0_1412.Event_Visible = L1_1413
L0_1412 = VisibilityTrigger
function L1_1413(A0_1429, A1_1430)
  if A0_1429.bVisible == 0 then
    return
  end
  A0_1429.bVisible = 0
  BroadcastEvent(A0_1429, "Invisible")
  if A0_1429.Properties.bTriggerOnce == 1 then
    A0_1429:GotoState("Disabled")
  else
    A0_1429:GotoState("Invisible")
  end
  System.Log("* INVISIBLE")
end
L0_1412.Event_Invisible = L1_1413
L0_1412 = VisibilityTrigger
function L1_1413(A0_1431, A1_1432)
  A0_1431:GotoState("Invisible")
  BroadcastEvent(A0_1431, "Enable")
end
L0_1412.Event_Enable = L1_1413
L0_1412 = VisibilityTrigger
function L1_1413(A0_1433, A1_1434)
  A0_1433:GotoState("Disabled")
  BroadcastEvent(A0_1433, "Disable")
end
L0_1412.Event_Disable = L1_1413
L0_1412 = VisibilityTrigger
L1_1413 = {}
L0_1412.Disabled = L1_1413
L0_1412 = VisibilityTrigger
L1_1413 = {}
function L2_1414(A0_1435)
  local L1_1436
  A0_1435.bVisible = 0
end
L1_1413.OnBeginState = L2_1414
function L2_1414(A0_1437)
  A0_1437.OnUpdateCalled = nil
  A0_1437:GotoState("Visible")
end
L1_1413.OnTimer = L2_1414
function L2_1414(A0_1438)
  if A0_1438.OnUpdateCalled == nil then
    A0_1438.OnUpdateCalled = 1
    if A0_1438.Properties.bUseKey ~= 0 then
      A0_1438.OnUpdateCalled = nil
      A0_1438:GotoState("VisibleUse")
      return
    end
    if A0_1438.Properties.EnterDelay ~= 0 then
      A0_1438:SetTimer(A0_1438.Properties.EnterDelay * 1000)
    else
      A0_1438.OnUpdateCalled = nil
      A0_1438:GotoState("Visible")
    end
  end
end
L1_1413.OnUpdate = L2_1414
L0_1412.Invisible = L1_1413
L0_1412 = VisibilityTrigger
L1_1413 = {}
function L2_1414(A0_1439)
  A0_1439.ExitDelay = A0_1439.Properties.ExitDelay
  A0_1439:Event_Visible(A0_1439)
end
L1_1413.OnBeginState = L2_1414
function L2_1414(A0_1440)
  if A0_1440.ExitDelay ~= 0 then
    A0_1440:SetTimer(A0_1440.ExitDelay * 1000)
    A0_1440.ExitDelay = 0
  else
    A0_1440:Event_Invisible(A0_1440)
  end
  A0_1440.ExitDelay = A0_1440.Properties.ExitDelay
end
L1_1413.OnTimer = L2_1414
function L2_1414(A0_1441)
  A0_1441:SetTimer(200)
end
L1_1413.OnUpdate = L2_1414
L0_1412.Visible = L1_1413
L0_1412 = VisibilityTrigger
L1_1413 = {}
function L2_1414(A0_1442)
  local L1_1443
end
L1_1413.OnBeginState = L2_1414
function L2_1414(A0_1444)
  A0_1444:GotoState("Invisible")
end
L1_1413.OnTimer = L2_1414
function L2_1414(A0_1445)
  A0_1445:SetTimer(200)
  if _localplayer and _localplayer.cnt and _localplayer.cnt.use_pressed then
    A0_1445:GotoState("Visible")
  elseif Hud then
    Hud.label = A0_1445.Properties.TextInstruction
  end
end
L1_1413.OnUpdate = L2_1414
L0_1412.VisibleUse = L1_1413
L0_1412 = VisibilityTrigger
L1_1413 = {}
L2_1414 = {}
L3_1415 = {
  VisibilityTrigger.Event_Disable,
  "bool"
}
L2_1414.Disable = L3_1415
L3_1415 = {
  VisibilityTrigger.Event_Enable,
  "bool"
}
L2_1414.Enable = L3_1415
L3_1415 = {
  VisibilityTrigger.Event_Invisible,
  "bool"
}
L2_1414.Invisible = L3_1415
L3_1415 = {
  VisibilityTrigger.Event_Visible,
  "bool"
}
L2_1414.Visible = L3_1415
L1_1413.Inputs = L2_1414
L2_1414 = {}
L2_1414.Disable = "bool"
L2_1414.Enable = "bool"
L2_1414.Invisible = "bool"
L2_1414.Visible = "bool"
L1_1413.Outputs = L2_1414
L0_1412.FlowEvents = L1_1413
