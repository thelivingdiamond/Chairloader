local L0_1452, L1_1453
L0_1452 = {}
L0_1452.type = "Trigger"
L0_1452.triggered = nil
L0_1452.time = 0
L0_1452.closed = nil
L0_1452.nTextureId = -1
L1_1453 = {}
L1_1453.Radius = 1.5
L1_1453.TextTrigger = "Waypoint*TxtTrg"
L1_1453.TextInstruction = "Waypoint*TxtInst"
L1_1453.NeededItem = ""
L1_1453.RepeatTime = 5
L1_1453.Objective = "Waypoint*Reached"
L1_1453.NextPoint = "Waypoint*"
L1_1453.ActiveByDefault = 1
L1_1453.LabelSize = 2
L1_1453.LabelText = "Waypoint*LblTxt"
L1_1453.LabelImage = "Textures/Hud/Icons/Waypoint.tga"
L1_1453.CutsceneName = "Cutscenes/"
L1_1453.TextTriggerTimeout = 15
L1_1453.Map = "0"
L0_1452.Properties = L1_1453
L0_1452.DialogId = -1
Waypoint = L0_1452
L0_1452 = Waypoint
function L1_1453(A0_1454)
  A0_1454:OnReset()
end
L0_1452.OnPropertyChange = L1_1453
L0_1452 = Waypoint
function L1_1453(A0_1455)
  A0_1455:SetRadius(A0_1455.Properties.Radius)
end
L0_1452.OnReset = L1_1453
L0_1452 = Waypoint
function L1_1453(A0_1456)
  A0_1456:OnReset()
  A0_1456:LoadObject("Objects/Editor/HUD/W.cgf", 0, 1)
  A0_1456:DrawObject(0, 1)
end
L0_1452.OnInit = L1_1453
L0_1452 = Waypoint
function L1_1453(A0_1457, A1_1458)
  local L2_1459
  L2_1459 = A0_1457.closed
  if L2_1459 ~= nil then
    return
  end
  L2_1459 = _localplayer
  if L2_1459 ~= A1_1458 then
    return
  end
  L2_1459 = A0_1457.triggered
  if L2_1459 == nil then
    A0_1457.triggered = 1
    A0_1457.time = 0
    L2_1459 = A0_1457.Properties
    L2_1459 = L2_1459.NeededItem
    if L2_1459 ~= "" then
      L2_1459 = A1_1458.MyInventory
      L2_1459 = L2_1459.HasItem
      L2_1459 = L2_1459(A1_1458.MyInventory, A0_1457.Properties.NeededItem)
      if L2_1459 then
        L2_1459 = Game
        L2_1459 = L2_1459.ShowIngameDialog
        L2_1459 = L2_1459(L2_1459, -1, "", "", 12, Language[A0_1457.Properties.TextTrigger])
        A0_1457.DialogId = L2_1459
        L2_1459 = Game
        L2_1459 = L2_1459.SetTimer
        L2_1459(L2_1459, A0_1457, A0_1457.Properties.TextTriggerTimeout * 1000)
        A0_1457.closed = 1
        L2_1459 = A0_1457.DeActivate
        L2_1459(A0_1457)
        L2_1459 = A0_1457.OnEvent
        L2_1459(A0_1457, ScriptEvent_DropItem)
        L2_1459 = System
        L2_1459 = L2_1459.LogToConsole
        L2_1459("Objective= " .. A0_1457.Properties.Objective)
        L2_1459 = Mission
        L2_1459 = L2_1459[A0_1457.Properties.Objective]
        if L2_1459 ~= nil then
          L2_1459 = Mission
          L2_1459[A0_1457.Properties.Objective] = 1
          L2_1459 = Mission
          L2_1459 = L2_1459.OnUpdate
          L2_1459(Mission)
          L2_1459 = System
          L2_1459 = L2_1459.LogToConsole
          L2_1459("mission objective set OK!!")
        else
          L2_1459 = System
          L2_1459 = L2_1459.LogToConsole
          L2_1459("Tried to set to true unexistant mission objective")
        end
      else
        L2_1459 = System
        L2_1459 = L2_1459.LogToConsole
        L2_1459(Language[A0_1457.Properties.TextInstruction])
      end
    else
      L2_1459 = Game
      L2_1459 = L2_1459.ShowIngameDialog
      L2_1459 = L2_1459(L2_1459, -1, "", "", 12, Language[A0_1457.Properties.TextTrigger])
      A0_1457.DialogId = L2_1459
      L2_1459 = Game
      L2_1459 = L2_1459.SetTimer
      L2_1459(L2_1459, A0_1457, A0_1457.Properties.TextTriggerTimeout * 1000)
      A0_1457.closed = 1
      L2_1459 = A0_1457.DeActivate
      L2_1459(A0_1457)
      L2_1459 = nil
      L2_1459 = System.GetEntityByName(A0_1457.Properties.NextPoint)
      if L2_1459 ~= nil then
        System.LogToConsole("Activating " .. A0_1457.Properties.NextPoint)
        L2_1459.Activate(L2_1459)
      end
      System.LogToConsole("Objective= " .. A0_1457.Properties.Objective)
      if Mission[A0_1457.Properties.Objective] ~= nil then
        Mission[A0_1457.Properties.Objective] = 1
        Mission.OnUpdate(Mission)
        System.LogToConsole("mission objective set OK!!")
      else
        System.LogToConsole("Tried to set to true unexistant mission objective")
      end
    end
  end
end
L0_1452.OnContact = L1_1453
L0_1452 = Waypoint
function L1_1453(A0_1460, A1_1461)
  local L2_1462, L3_1463
  L2_1462 = A0_1460.closed
  if L2_1462 ~= nil then
    return
  end
  L3_1463 = A0_1460
  L2_1462 = A0_1460.GetPos
  L2_1462 = L2_1462(L3_1463)
  L3_1463 = L2_1462.z
  L3_1463 = L3_1463 + 2
  L2_1462.z = L3_1463
  L3_1463 = Game
  L3_1463 = L3_1463.DrawLabel
  L3_1463(L3_1463, L2_1462, A0_1460.Properties.LabelSize, Language[A0_1460.Properties.LabelText])
  L3_1463 = A0_1460.nTextureId
  if L3_1463 ~= nil then
    L3_1463 = System
    L3_1463 = L3_1463.DrawLabelImage
    L3_1463(L2_1462, A0_1460.Properties.LabelSize, A0_1460.nTextureId)
  end
  L3_1463 = A0_1460.GetAngles
  L3_1463 = L3_1463(A0_1460)
  L3_1463.z = L3_1463.z + 8
  A0_1460:SetAngles(L3_1463)
  if A0_1460.triggered ~= nil then
    A0_1460.time = A0_1460.time + System.GetFrameTime()
    if A0_1460.time > A0_1460.Properties.RepeatTime then
      A0_1460.triggered = nil
    end
  end
end
L0_1452.OnUpdate = L1_1453
L0_1452 = Waypoint
function L1_1453(A0_1464, A1_1465, A2_1466)
  if A1_1465 == ScriptEvent_Reset then
    A0_1464:SetRadius(A0_1464.Properties.Radius)
    A0_1464.nTextureId = System.LoadTexture(A0_1464.Properties.LabelImage)
    if A0_1464.Properties.ActiveByDefault == 1 then
      A0_1464:Activate()
    else
      A0_1464:DeActivate()
    end
  elseif A1_1465 == ScriptEvent_Activate then
    A0_1464:Activate()
  elseif A1_1465 == ScriptEvent_Timer then
    Game:HideIngameDialog(A0_1464.DialogId)
  end
end
L0_1452.OnEvent = L1_1453
L0_1452 = Waypoint
function L1_1453(A0_1467)
  local L1_1468
end
L0_1452.OnShutDown = L1_1453
L0_1452 = Waypoint
function L1_1453(A0_1469)
  System.LogToConsole("Activating " .. A0_1469:GetName())
  A0_1469:Activate(1)
  A0_1469.closed = nil
  A0_1469:DrawObject(0, 1)
end
L0_1452.Activate = L1_1453
L0_1452 = Waypoint
function L1_1453(A0_1470)
  System.LogToConsole("DEActivating " .. A0_1470:GetName())
  A0_1470:Activate(nil)
  A0_1470.closed = 1
  A0_1470:DrawObject(0, 0)
end
L0_1452.DeActivate = L1_1453
L0_1452 = Waypoint
function L1_1453(A0_1471, A1_1472)
  A1_1472:WriteBool(A0_1471.triggered)
  A1_1472:WriteBool(A0_1471.closed)
  A1_1472:WriteFloat(A0_1471.Properties.Radius)
  A1_1472:WriteString(A0_1471.Properties.TextTrigger)
  A1_1472:WriteString(A0_1471.Properties.TextInstruction)
  A1_1472:WriteString(A0_1471.Properties.NeededItem)
  A1_1472:WriteInt(A0_1471.Properties.RepeatTime)
  A1_1472:WriteString(A0_1471.Properties.Objective)
  A1_1472:WriteString(A0_1471.Properties.NextPoint)
  A1_1472:WriteInt(A0_1471.Properties.ActiveByDefault)
  A1_1472:WriteInt(A0_1471.Properties.LabelSize)
  A1_1472:WriteString(A0_1471.Properties.LabelText)
  A1_1472:WriteString(A0_1471.Properties.LabelImage)
  A1_1472:WriteString(A0_1471.Properties.CutsceneName)
  A1_1472:WriteInt(A0_1471.Properties.TextTriggerTimeout)
  A1_1472:WriteString(A0_1471.Properties.Map)
end
L0_1452.OnSave = L1_1453
L0_1452 = Waypoint
function L1_1453(A0_1473, A1_1474)
  A0_1473.triggered = A1_1474:ReadBool()
  A0_1473.closed = A1_1474:ReadBool()
  if A0_1473.closed ~= nil then
    A0_1473:DeActivate()
  end
  A0_1473.Properties.Radius = A1_1474:ReadFloat()
  A0_1473.Properties.TextTrigger = A1_1474:ReadString()
  A0_1473.Properties.TextInstruction = A1_1474:ReadString()
  A0_1473.Properties.NeededItem = A1_1474:ReadString()
  A0_1473.Properties.RepeatTime = A1_1474:ReadInt()
  A0_1473.Properties.Objective = A1_1474:ReadString()
  A0_1473.Properties.NextPoint = A1_1474:ReadString()
  A0_1473.Properties.ActiveByDefault = A1_1474:ReadInt()
  A0_1473.Properties.LabelSize = A1_1474:ReadInt()
  A0_1473.Properties.LabelText = A1_1474:ReadString()
  A0_1473.Properties.LabelImage = A1_1474:ReadString()
  if A0_1473.Properties.LabelImage then
    A0_1473.nTextureId = System.LoadImage(A0_1473.Properties.LabelImage)
  end
  A0_1473.Properties.CutsceneName = A1_1474:ReadString()
  A0_1473.Properties.TextTriggerTimeout = A1_1474:ReadInt()
  A0_1473.Properties.Map = A1_1474:ReadString()
end
L0_1452.OnLoad = L1_1453
