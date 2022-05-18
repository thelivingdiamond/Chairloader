Script.ReloadScript("Scripts/Entities/AlienTech/AlienTech.lua")
PowerStruggleNode = new(AlienTech)
PowerStruggleNode.Properties.ControlRadius = 8
PowerStruggleNode.Properties.ControlHeight = 5
PowerStruggleNode.Properties.ControlOffsetZ = 0
PowerStruggleNode.Properties.DebugDraw = 0
PowerStruggleNode.Properties.Letter = ""
PowerStruggleNode.NumTimesEmerged = 0
PowerStruggleNode.UseableChildEntity = 0
function PowerStruggleNode.Server.OnInit(A0_6508)
  if not A0_6508.bInitialized then
    A0_6508:OnReset()
    A0_6508.bInitialized = 1
  end
end
function PowerStruggleNode.Client.OnInit(A0_6509)
  if not A0_6509.bInitialized then
    A0_6509:OnReset()
    A0_6509.bInitialized = 1
  end
end
function PowerStruggleNode.OnReset(A0_6510)
  local L1_6511, L2_6512, L3_6513, L4_6514, L5_6515
  L1_6511 = A0_6510.Properties
  L1_6511 = L1_6511.ControlRadius
  L2_6512 = A0_6510.Properties
  L2_6512 = L2_6512.ControlOffsetZ
  L3_6513 = A0_6510.Properties
  L3_6513 = L3_6513.ControlHeight
  L4_6514 = {}
  L5_6515 = -L1_6511
  L4_6514.x = L5_6515
  L5_6515 = -L1_6511
  L4_6514.y = L5_6515
  L4_6514.z = L2_6512
  L5_6515 = {}
  L5_6515.x = L1_6511
  L5_6515.y = L1_6511
  L5_6515.z = L3_6513 + L2_6512
  A0_6510:SetTriggerBBox(L4_6514, L5_6515)
  A0_6510:SetViewDistRatio(255)
  if System.IsEditor() then
    if A0_6510.Properties.DebugDraw ~= 0 then
      A0_6510:Activate(1)
      CryAction.ForceGameObjectUpdate(A0_6510.id, true)
    else
      A0_6510:Activate(0)
    end
  end
end
function PowerStruggleNode.OnPropertyChange(A0_6516)
  A0_6516:OnReset()
end
function PowerStruggleNode.Server.OnUpdate(A0_6517)
  local L1_6518, L2_6519, L3_6520
  L1_6518 = System
  L1_6518 = L1_6518.IsEditor
  L1_6518 = L1_6518()
  if L1_6518 then
    L1_6518 = A0_6517.Properties
    L1_6518 = L1_6518.DebugDraw
    if L1_6518 ~= 0 then
      L2_6519 = A0_6517
      L1_6518 = A0_6517.GetWorldPos
      L1_6518 = L1_6518(L2_6519)
      L2_6519 = A0_6517.Properties
      L2_6519 = L2_6519.ControlRadius
      L3_6520 = A0_6517.Properties
      L3_6520 = L3_6520.ControlHeight
      L1_6518.z = L1_6518.z + A0_6517.Properties.ControlOffsetZ
      Game.DebugDrawCone(L1_6518.x, L1_6518.y, L1_6518.z, L2_6519, L3_6520, 60, 60, 255, 150)
    end
  end
end
function PowerStruggleNode.ActivateNode(A0_6521)
  Log("PowerStruggleNode:ActivateNode()")
  BroadcastEvent(A0_6521, "Activated")
  A0_6521:SetViewDistRatio(255)
end
function PowerStruggleNode.DeActivateNode(A0_6522)
  BroadcastEvent(A0_6522, "DeActivatedImmediately")
  A0_6522:Event_Buried()
end
function PowerStruggleNode.Event_Buried(A0_6523)
  Log("PowerStruggleNode:Event_Buried()")
  g_gameRules.game:SendGameRulesObjectiveEntitySignal(A0_6523.id, 0)
end
function PowerStruggleNode.Event_Emerging(A0_6524)
  Log("PowerStruggleNoed:Event_Emerging()")
  if A0_6524.NumTimesEmerged == 0 then
    BroadcastEvent(A0_6524, "OnFirstEmerging")
  else
    BroadcastEvent(A0_6524, "OnRepeatEmerging")
  end
  BroadcastEvent(A0_6524, "OnAnyEmerging")
  A0_6524.NumTimesEmerged = A0_6524.NumTimesEmerged + 1
end
function PowerStruggleNode.Event_Emerged(A0_6525)
  Log("PowerStruggleNode:Event_Emerged()")
  g_gameRules.game:SendGameRulesObjectiveEntitySignal(A0_6525.id, 1)
end
function PowerStruggleNode.Event_Burying(A0_6526)
  Log("PowerStruggleNoed:Event_Burying()")
end
function PowerStruggleNode.Event_ShowIcon(A0_6527)
  Log("PowerStruggleNoed:Event_ShowIcon()")
end
function PowerStruggleNode.IsUsable(A0_6528, A1_6529)
  A0_6528.UseableChildEntity = g_gameRules.game:CanUsePowerStruggleNode(A1_6529.id, A0_6528.id)
  return A0_6528.UseableChildEntity
end
PowerStruggleNode.FlowEvents = {
  Inputs = {
    Buried = {
      PowerStruggleNode.Event_Buried,
      "any"
    },
    Emerging = {
      PowerStruggleNode.Event_Emerging,
      "any"
    },
    Emerged = {
      PowerStruggleNode.Event_Emerged,
      "any"
    },
    Burying = {
      PowerStruggleNode.Event_Burying,
      "any"
    },
    ShowIcon = {
      CrashSiteLocation.Event_ShowIcon,
      "any"
    }
  },
  Outputs = {
    Activated = "bool",
    OnFirstEmerging = "bool",
    OnRepeatEmerging = "bool",
    OnAnyEmerging = "bool",
    DeActivated = "bool",
    DeActivatedImmediately = "bool"
  }
}
