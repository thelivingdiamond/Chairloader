local L0_718, L1_719, L2_720, L3_721
L0_718 = {}
L0_718.type = "DamageArea"
L1_719 = {}
L1_719.damageRate = 5
L1_719.bEnabled = 1
L0_718.Properties = L1_719
L1_719 = {}
L1_719.Model = "Objects/Editor/T.cgf"
L0_718.Editor = L1_719
L0_718.curDamageRate = 0
L0_718.curDamage = 0
L0_718.isEnabled = 1
L1_719 = {}
L2_720 = {}
L2_720.x = 0
L2_720.y = 0
L2_720.z = 1
L1_719.dir = L2_720
L1_719.damage = 0
L1_719.target = nil
L1_719.shooter = nil
L1_719.landed = 1
L1_719.impact_force_mul_final = 5
L1_719.impact_force_mul = 5
L1_719.damage_type = "normal"
L0_718.hit = L1_719
DamageArea = L0_718
L0_718 = DamageArea
function L1_719(A0_722)
  A0_722:RegisterState("Inactive")
  A0_722:RegisterState("Active")
  A0_722:GotoState("Inactive")
end
L0_718.CliSrv_OnInit = L1_719
L0_718 = DamageArea
function L1_719(A0_723, A1_724, A2_725, A3_726)
  A0_723:GotoState("Inactive")
  A0_723.isEnabled = A0_723.Properties.bEnabled
end
L0_718.OnReset = L1_719
L0_718 = DamageArea
function L1_719(A0_727, A1_728, A2_729, A3_730)
  local L4_731
  L4_731 = A0_727.Properties
  L4_731 = L4_731.damageRate
  L4_731 = L4_731 * A3_730
  A0_727.curDamageRate = L4_731
end
L0_718.OnProceedFadeAreaClient = L1_719
L0_718 = DamageArea
function L1_719(A0_732, A1_733, A2_734)
  System.LogToConsole("--> Entering DamageArea Area " .. A2_734)
  A0_732:GotoState("Active")
end
L0_718.OnEnterAreaClient = L1_719
L0_718 = DamageArea
function L1_719(A0_735, A1_736, A2_737)
  System.LogToConsole("--> Leaving DamageArea Area " .. A2_737)
  A0_735:GotoState("Inactive")
end
L0_718.OnLeaveAreaClient = L1_719
L0_718 = DamageArea
function L1_719(A0_738, A1_739)
  if A0_738.isEnabled == 0 then
    return
  end
  A0_738.curDamage = A0_738.curDamage + A0_738.curDamageRate * A1_739
  if A0_738.curDamage > 1 then
    A0_738.hit.damage = A0_738.curDamage
    A0_738.hit.target = _localplayer
    A0_738.hit.shooter = _localplayer
    A0_738.hit.dir = {
      x = 0,
      y = 0,
      z = 1
    }
    A0_738.hit.landed = 1
    A0_738.hit.impact_force_mul_final = 0
    A0_738.hit.impact_force_mul = 0
    A0_738.hit.damage_type = "normal"
    _localplayer:Damage(A0_738.hit)
    A0_738.curDamage = 0
  end
end
L0_718.OnUpdateActiveClient = L1_719
L0_718 = DamageArea
function L1_719(A0_740)
  local L1_741
end
L0_718.OnShutDown = L1_719
L0_718 = DamageArea
L1_719 = {}
function L2_720(A0_742)
  A0_742:CliSrv_OnInit()
end
L1_719.OnInit = L2_720
function L2_720(A0_743)
  local L1_744
end
L1_719.OnShutDown = L2_720
L2_720 = {}
L1_719.Inactive = L2_720
L2_720 = {}
function L3_721(A0_745)
  local L1_746
end
L2_720.OnBeginState = L3_721
L1_719.Active = L2_720
L0_718.Server = L1_719
L0_718 = DamageArea
L1_719 = {}
function L2_720(A0_747)
  A0_747:CliSrv_OnInit()
end
L1_719.OnInit = L2_720
function L2_720(A0_748)
  local L1_749
end
L1_719.OnShutDown = L2_720
L2_720 = {}
L3_721 = DamageArea
L3_721 = L3_721.OnEnterAreaClient
L2_720.OnEnterArea = L3_721
L1_719.Inactive = L2_720
L2_720 = {}
function L3_721(A0_750)
  A0_750:Activate(1)
  A0_750.curDamage = 0
end
L2_720.OnBeginState = L3_721
L3_721 = DamageArea
L3_721 = L3_721.OnLeaveAreaClient
L2_720.OnLeaveArea = L3_721
L3_721 = DamageArea
L3_721 = L3_721.OnProceedFadeAreaClient
L2_720.OnProceedFadeArea = L3_721
L3_721 = DamageArea
L3_721 = L3_721.OnUpdateActiveClient
L2_720.OnUpdate = L3_721
L1_719.Active = L2_720
L0_718.Client = L1_719
L0_718 = DamageArea
function L1_719(A0_751, A1_752)
  A0_751.isEnabled = 1
end
L0_718.Event_Enable = L1_719
L0_718 = DamageArea
function L1_719(A0_753, A1_754)
  A0_753.isEnabled = 0
end
L0_718.Event_Disable = L1_719
L0_718 = DamageArea
L1_719 = {}
L2_720 = {}
L3_721 = {
  DamageArea.Event_Disable,
  "bool"
}
L2_720.Disable = L3_721
L3_721 = {
  DamageArea.Event_Enable,
  "bool"
}
L2_720.Enable = L3_721
L1_719.Inputs = L2_720
L2_720 = {}
L2_720.Disable = "bool"
L2_720.Enable = "bool"
L1_719.Outputs = L2_720
L0_718.FlowEvents = L1_719
