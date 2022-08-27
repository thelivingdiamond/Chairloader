local L0_8238, L1_8239, L2_8240, L3_8241
L0_8238 = {}
L0_8238.type = "ViewDistController"
L1_8239 = {}
L1_8239.MaxViewDist = 25
L1_8239.fFadeTime = 1
L0_8238.Properties = L1_8239
L1_8239 = {}
L1_8239.Model = "Editor/Objects/T.cgf"
L0_8238.Editor = L1_8239
ViewDist = L0_8238
L0_8238 = ViewDist
function L1_8239(A0_8242)
  A0_8242:SetFlagsExtended(ENTITY_FLAG_EXTENDED_NEEDS_MOVEINSIDE, 0)
end
L0_8238.OnSpawn = L1_8239
L0_8238 = ViewDist
function L1_8239(A0_8243, A1_8244)
  local L2_8245
  L2_8245 = A0_8243.outsideViewDist
  A1_8244.outsideViewDist = L2_8245
  L2_8245 = A0_8243.occupied
  A1_8244.occupied = L2_8245
  L2_8245 = A0_8243.fadeamt
  A1_8244.fadeamt = L2_8245
  L2_8245 = A0_8243.lasttime
  A1_8244.lasttime = L2_8245
  L2_8245 = A0_8243.exitfrom
  A1_8244.exitfrom = L2_8245
end
L0_8238.OnSave = L1_8239
L0_8238 = ViewDist
function L1_8239(A0_8246, A1_8247)
  local L2_8248
  L2_8248 = A1_8247.outsideViewDist
  A0_8246.outsideViewDist = L2_8248
  L2_8248 = A1_8247.occupied
  A0_8246.occupied = L2_8248
  L2_8248 = A1_8247.fadeamt
  A0_8246.fadeamt = L2_8248
  L2_8248 = A1_8247.lasttime
  A0_8246.lasttime = L2_8248
  L2_8248 = A1_8247.exitfrom
  A0_8246.exitfrom = L2_8248
end
L0_8238.OnLoad = L1_8239
L0_8238 = ViewDist
function L1_8239(A0_8249)
  A0_8249.outsideViewDist = 0
  A0_8249.occupied = 0
  A0_8249:OnReset()
  A0_8249.outsideViewDist = System.ViewDistanceGet()
  A0_8249:RegisterForAreaEvents(1)
end
L0_8238.OnInit = L1_8239
L0_8238 = ViewDist
function L1_8239(A0_8250)
  A0_8250:OnReset()
end
L0_8238.OnPropertyChange = L1_8239
L0_8238 = ViewDist
function L1_8239(A0_8251)
  if A0_8251.occupied == 1 then
    A0_8251:OnLeaveArea()
  end
  A0_8251.occupied = 0
  A0_8251:KillTimer(0)
end
L0_8238.OnReset = L1_8239
L0_8238 = ViewDist
function L1_8239(A0_8252, A1_8253, A2_8254, A3_8255)
  A0_8252:FadeViewDist(A3_8255)
end
L0_8238.OnProceedFadeArea = L1_8239
L0_8238 = ViewDist
function L1_8239(A0_8256)
  System.ViewDistanceSet(A0_8256.outsideViewDist)
end
L0_8238.ResetValues = L1_8239
L0_8238 = ViewDist
function L1_8239(A0_8257, A1_8258, A2_8259)
  if A0_8257.occupied == 1 then
    return
  end
  A0_8257.outsideViewDist = System.ViewDistanceGet()
  A0_8257.occupied = 1
end
L0_8238.OnEnterArea = L1_8239
L0_8238 = ViewDist
function L1_8239(A0_8260, A1_8261, A2_8262)
  A0_8260:ResetValues()
  A0_8260.occupied = 0
end
L0_8238.OnLeaveArea = L1_8239
L0_8238 = ViewDist
function L1_8239(A0_8263)
  A0_8263:RegisterForAreaEvents(0)
end
L0_8238.OnShutDown = L1_8239
L0_8238 = ViewDist
function L1_8239(A0_8264, A1_8265)
  if A0_8264.occupied == 0 then
    if A0_8264.fadeamt and A0_8264.fadeamt < 1 then
      A0_8264:ResetValues()
    end
    A0_8264:OnEnterArea()
    A0_8264.fadeamt = 0
    A0_8264.lasttime = _time
    A0_8264.exitfrom = nil
  end
  A0_8264:SetTimer(0, 1)
  BroadcastEvent(A0_8264, "Enable")
end
L0_8238.Event_Enable = L1_8239
L0_8238 = ViewDist
function L1_8239(A0_8266, A1_8267)
  if A0_8266.occupied == 1 then
    A0_8266.occupied = 0
    A0_8266.fadeamt = 0
    A0_8266.lasttime = _time
    A0_8266.exitfrom = 1
  end
  A0_8266:SetTimer(0, 1)
  BroadcastEvent(A0_8266, "Disable")
end
L0_8238.Event_Disable = L1_8239
L0_8238 = ViewDist
function L1_8239(A0_8268)
  local L1_8269, L2_8270
  L2_8270 = A0_8268
  L1_8269 = A0_8268.SetTimer
  L1_8269(L2_8270, 0, 1)
  L1_8269 = A0_8268.fadeamt
  if L1_8269 then
    L1_8269 = _time
    L2_8270 = A0_8268.lasttime
    L1_8269 = L1_8269 - L2_8270
    L2_8270 = _time
    A0_8268.lasttime = L2_8270
    L2_8270 = A0_8268.fadeamt
    L2_8270 = L2_8270 + L1_8269 / A0_8268.Properties.fFadeTime
    A0_8268.fadeamt = L2_8270
    L2_8270 = A0_8268.fadeamt
    if L2_8270 >= 1 then
      A0_8268.fadeamt = 1
      L2_8270 = A0_8268.KillTimer
      L2_8270(A0_8268, 0)
    end
    L2_8270 = A0_8268.fadeamt
    if A0_8268.exitfrom then
      L2_8270 = 1 - L2_8270
    end
    L2_8270 = math.sqrt(L2_8270)
    A0_8268:FadeViewDist(L2_8270)
  else
    L2_8270 = A0_8268
    L1_8269 = A0_8268.KillTimer
    L1_8269(L2_8270, 0)
  end
end
L0_8238.OnTimer = L1_8239
L0_8238 = ViewDist
function L1_8239(A0_8271, A1_8272)
  A1_8272 = math.sqrt(A1_8272)
  System.ViewDistanceSet(Lerp(A0_8271.outsideViewDist, A0_8271.Properties.MaxViewDist, A1_8272))
end
L0_8238.FadeViewDist = L1_8239
L0_8238 = ViewDist
L1_8239 = {}
L2_8240 = {}
L3_8241 = {
  ViewDist.Event_Disable,
  "bool"
}
L2_8240.Disable = L3_8241
L3_8241 = {
  ViewDist.Event_Enable,
  "bool"
}
L2_8240.Enable = L3_8241
L1_8239.Inputs = L2_8240
L2_8240 = {}
L2_8240.Disable = "bool"
L2_8240.Enable = "bool"
L1_8239.Outputs = L2_8240
L0_8238.FlowEvents = L1_8239
