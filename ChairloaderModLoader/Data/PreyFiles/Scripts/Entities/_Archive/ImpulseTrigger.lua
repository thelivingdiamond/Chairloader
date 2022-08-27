local L0_966, L1_967, L2_968, L3_969
L0_966 = {}
L0_966.type = "Trigger"
L1_967 = {}
L1_967.DimX = 5
L1_967.DimY = 5
L1_967.DimZ = 5
L1_967.bEnabled = 1
L1_967.bTriggerOnce = 0
L1_967.bKillOnTrigger = 0
L1_967.bOnlyPlayer = 0
L1_967.bOnlyMyPlayer = 1
L1_967.bOnlyAI = 0
L1_967.ImpulseStrength = 20
L1_967.ImpulseFadeInTime = 0
L1_967.ImpulseDuration = 0.1
L0_966.Properties = L1_967
L1_967 = {}
L1_967.x = 0
L1_967.y = 0
L1_967.z = 0
L0_966.imp = L1_967
L0_966.MaxImpulse = 0
L0_966.InitImpulseTime = 0
L0_966.TotalImpulseDuration = 0
L1_967 = {}
L1_967.Model = "Objects/Editor/T.cgf"
L0_966.Editor = L1_967
ImpulseTrigger = L0_966
L0_966 = ImpulseTrigger
function L1_967(A0_970)
  A0_970:OnReset()
end
L0_966.OnPropertyChange = L1_967
L0_966 = ImpulseTrigger
function L1_967(A0_971)
  A0_971.Who = nil
  A0_971.Entered = 0
  A0_971:RegisterState("Inactive")
  A0_971:RegisterState("Empty")
  A0_971:RegisterState("Occupied")
  A0_971:OnReset()
  A0_971:Activate(0)
  A0_971:TrackColliders(1)
end
L0_966.OnInit = L1_967
L0_966 = ImpulseTrigger
function L1_967(A0_972)
  local L1_973
end
L0_966.OnShutDown = L1_967
L0_966 = ImpulseTrigger
function L1_967(A0_974, A1_975)
end
L0_966.OnSave = L1_967
L0_966 = ImpulseTrigger
function L1_967(A0_976, A1_977)
end
L0_966.OnLoad = L1_967
L0_966 = ImpulseTrigger
function L1_967(A0_978)
  local L1_979, L2_980
  L1_979 = new
  L2_980 = A0_978.GetDirectionVector
  L2_980 = L2_980(A0_978)
  L1_979 = L1_979(L2_980, L2_980(A0_978))
  A0_978.imp = L1_979
  L1_979 = {}
  L2_980 = A0_978.Properties
  L2_980 = L2_980.DimX
  L2_980 = -L2_980
  L2_980 = L2_980 / 2
  L1_979.x = L2_980
  L2_980 = A0_978.Properties
  L2_980 = L2_980.DimY
  L2_980 = -L2_980
  L2_980 = L2_980 / 2
  L1_979.y = L2_980
  L2_980 = A0_978.Properties
  L2_980 = L2_980.DimZ
  L2_980 = -L2_980
  L2_980 = L2_980 / 2
  L1_979.z = L2_980
  L2_980 = {}
  L2_980.x = A0_978.Properties.DimX / 2
  L2_980.y = A0_978.Properties.DimY / 2
  L2_980.z = A0_978.Properties.DimZ / 2
  A0_978:SetBBox(L1_979, L2_980)
  A0_978.Who = nil
  A0_978.Entered = 0
  A0_978.TotalImpulseDuration = A0_978.Properties.ImpulseFadeInTime + A0_978.Properties.ImpulseDuration
  if A0_978.Properties.bEnabled == 1 then
    A0_978:GotoState("Empty")
  else
    A0_978:GotoState("Inactive")
  end
end
L0_966.OnReset = L1_967
L0_966 = ImpulseTrigger
function L1_967(A0_981, A1_982)
  if A0_981.Entered ~= 0 then
    return
  end
  AI:RegisterWithAI(A0_981.id, 0)
  BroadcastEvent(A0_981, "Enter")
  A0_981.Entered = 1
  A0_981.InitImpulseTime = _time
  A0_981:SetTimer(1)
  if A0_981.Who == nil then
    A0_981.Who = A1_982
    A0_981:GotoState("Occupied")
  end
end
L0_966.Event_Enter = L1_967
L0_966 = ImpulseTrigger
function L1_967(A0_983, A1_984)
  if A0_983.Entered == 0 then
    return
  end
  A0_983.Entered = 0
  BroadcastEvent(A0_983, "Leave")
end
L0_966.Event_Leave = L1_967
L0_966 = ImpulseTrigger
function L1_967(A0_985, A1_986)
  A0_985:GotoState("Empty")
  BroadcastEvent(A0_985, "Enable")
end
L0_966.Event_Enable = L1_967
L0_966 = ImpulseTrigger
function L1_967(A0_987, A1_988)
  A0_987:GotoState("Inactive")
  AI:RegisterWithAI(A0_987.id, 0)
  BroadcastEvent(A0_987, "Disable")
end
L0_966.Event_Disable = L1_967
L0_966 = ImpulseTrigger
function L1_967(A0_989)
  local L1_990
  if A0_989.Who then
    if A0_989.Properties.ImpulseFadeInTime > 0 then
      L1_990 = (_time - A0_989.InitImpulseTime) / A0_989.Properties.ImpulseFadeInTime
    else
      L1_990 = 1
    end
    if L1_990 > 1 then
      L1_990 = 1
    end
    A0_989.Who:AddImpulseObj(A0_989.imp, A0_989.Properties.ImpulseStrength * L1_990)
    if _time - A0_989.InitImpulseTime >= A0_989.TotalImpulseDuration and 0 <= A0_989.TotalImpulseDuration then
      A0_989:SetTimer(2000)
      A0_989.Who = nil
    else
      A0_989:SetTimer(1)
    end
  else
    A0_989:Event_Leave(A0_989, A0_989.Who)
    if 0 < A0_989.Properties.bKillOnTrigger then
      Server:RemoveEntity(A0_989.id)
    elseif 0 < A0_989.Properties.bTriggerOnce then
      A0_989:GotoState("Inactive")
    else
      A0_989:GotoState("Empty")
    end
    A0_989:KillTimer()
  end
end
L0_966.OnTimeF = L1_967
L0_966 = ImpulseTrigger
L1_967 = {}
function L2_968(A0_991)
  printf("ImpulseTrigger deactivating")
end
L1_967.OnBeginState = L2_968
function L2_968(A0_992)
  printf("ImpulseTrigger activating")
end
L1_967.OnEndState = L2_968
L0_966.Inactive = L1_967
L0_966 = ImpulseTrigger
L1_967 = {}
function L2_968(A0_993)
  local L1_994
  A0_993.Who = nil
end
L1_967.OnBeginState = L2_968
function L2_968(A0_995, A1_996)
  if A0_995.Properties.bOnlyPlayer ~= 0 and A1_996.type ~= "Player" then
    return
  end
  if A0_995.Properties.bOnlyAI ~= 0 and A1_996.ai == nil then
    return
  end
  if A0_995.Properties.bOnlyMyPlayer ~= 0 and A1_996 ~= _localplayer then
    return
  end
  if A0_995.Who == nil then
    A0_995.Who = A1_996
    A0_995:GotoState("Occupied")
  end
end
L1_967.OnEnterArea = L2_968
L2_968 = ImpulseTrigger
L2_968 = L2_968.OnTimeF
L1_967.OnTimer = L2_968
L0_966.Empty = L1_967
L0_966 = ImpulseTrigger
L1_967 = {}
function L2_968(A0_997)
  A0_997:Event_Enter(A0_997.Who)
end
L1_967.OnBeginState = L2_968
L2_968 = ImpulseTrigger
L2_968 = L2_968.OnTimeF
L1_967.OnTimer = L2_968
L0_966.Occupied = L1_967
L0_966 = ImpulseTrigger
L1_967 = {}
L2_968 = {}
L3_969 = {
  ImpulseTrigger.Event_Disable,
  "bool"
}
L2_968.Disable = L3_969
L3_969 = {
  ImpulseTrigger.Event_Enable,
  "bool"
}
L2_968.Enable = L3_969
L3_969 = {
  ImpulseTrigger.Event_Enter,
  "bool"
}
L2_968.Enter = L3_969
L3_969 = {
  ImpulseTrigger.Event_Leave,
  "bool"
}
L2_968.Leave = L3_969
L1_967.Inputs = L2_968
L2_968 = {}
L2_968.Disable = "bool"
L2_968.Enable = "bool"
L2_968.Enter = "bool"
L2_968.Leave = "bool"
L1_967.Outputs = L2_968
L0_966.FlowEvents = L1_967
