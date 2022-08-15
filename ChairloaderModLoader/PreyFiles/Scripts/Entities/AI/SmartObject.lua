local L0_2974, L1_2975, L2_2976
L0_2974 = {}
L0_2974.type = "SmartObject"
L1_2975 = {}
L1_2975.soclasses_SmartObjectClass = ""
L0_2974.Properties = L1_2975
L1_2975 = {}
L1_2975.Model = "Editor/Objects/anchor.cgf"
L1_2975.Icon = "smartobject.bmp"
L1_2975.IconOnTop = 1
L0_2974.Editor = L1_2975
SmartObject = L0_2974
L0_2974 = SmartObject
function L1_2975(A0_2977)
  local L1_2978
end
L0_2974.OnInit = L1_2975
L0_2974 = SmartObject
function L1_2975(A0_2979)
  local L1_2980
end
L0_2974.OnReset = L1_2975
L0_2974 = SmartObject
function L1_2975(A0_2981)
  BroadcastEvent(A0_2981, "Used")
end
L0_2974.OnUsed = L1_2975
L0_2974 = SmartObject
function L1_2975(A0_2982, A1_2983)
  A0_2982:ActivateOutput("NavigationStarted", A1_2983 or NULL_ENTITY)
end
L0_2974.OnNavigationStarted = L1_2975
L0_2974 = SmartObject
function L1_2975(A0_2984, A1_2985)
  BroadcastEvent(A0_2984, "Used")
end
L0_2974.Event_Used = L1_2975
L0_2974 = SmartObject
L1_2975 = {}
L2_2976 = {}
L2_2976.Used = {
  SmartObject.Event_Used,
  "bool"
}
L1_2975.Inputs = L2_2976
L2_2976 = {}
L2_2976.Used = "bool"
L2_2976.NavigationStarted = "entity"
L1_2975.Outputs = L2_2976
L0_2974.FlowEvents = L1_2975
