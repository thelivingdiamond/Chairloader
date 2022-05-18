local L0_2986, L1_2987, L2_2988
L0_2986 = {}
L0_2986.type = "SmartObjectCondition"
L1_2987 = {}
L1_2987.bEnabled = true
L1_2987.bIncludeInNavigation = true
L1_2987.bRelativeToTarget = false
L2_2988 = {}
L2_2988.soclass_Class = "BasicEntity"
L2_2988.sostate_State = "Idle"
L2_2988.object_Model = ""
L1_2987.Object = L2_2988
L2_2988 = {}
L2_2988.soclass_Class = "AIOBJECT_ACTOR"
L2_2988.sostate_State = "Idle"
L2_2988.object_Model = ""
L1_2987.User = L2_2988
L2_2988 = {}
L2_2988.fDistance = 10
L2_2988.fOrientation = 360
L1_2987.Limits = L2_2988
L2_2988 = {}
L2_2988.fMinimum = 0.5
L2_2988.fMaximum = 15
L2_2988.fMemory = 1
L1_2987.Delay = L2_2988
L2_2988 = {}
L2_2988.fProximity = 1
L2_2988.fOrientation = 0
L2_2988.fVisibility = 0
L2_2988.fRandomness = 0.25
L1_2987.Multipliers = L2_2988
L2_2988 = {}
L2_2988.soaction_Name = ""
L2_2988.sostate_ObjectState = "Busy"
L2_2988.sostate_UserState = "Busy"
L1_2987.Action = L2_2988
L0_2986.Properties = L1_2987
L1_2987 = {}
L1_2987.Model = "Editor/Objects/Pyramid.cgf"
L0_2986.Editor = L1_2987
SmartObjectCondition = L0_2986
L0_2986 = SmartObjectCondition
function L1_2987(A0_2989)
  local L1_2990
end
L0_2986.OnPropertyChange = L1_2987
L0_2986 = SmartObjectCondition
function L1_2987(A0_2991)
  local L1_2992
end
L0_2986.OnInit = L1_2987
L0_2986 = SmartObjectCondition
function L1_2987(A0_2993)
  A0_2993:Register()
end
L0_2986.OnReset = L1_2987
L0_2986 = SmartObjectCondition
function L1_2987(A0_2994)
  local L1_2995
end
L0_2986.Register = L1_2987
