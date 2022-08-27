local L0_7939, L1_7940, L2_7941, L3_7942
L0_7939 = {}
L0_7939.type = "WindController"
L1_7940 = {}
L2_7941 = {}
L2_7941.x = 1
L2_7941.y = 0
L2_7941.z = 0
L1_7940.vVelocity = L2_7941
L1_7940.fFadeTime = 1
L0_7939.Properties = L1_7940
L1_7940 = {}
L1_7940.Icon = "Tornado.bmp"
L0_7939.Editor = L1_7940
Wind = L0_7939
L0_7939 = Wind
function L1_7940(A0_7943)
  A0_7943.oldVelocity = {
    x = 0,
    y = 0,
    z = 0
  }
  A0_7943.occupied = 0
  A0_7943.lasttime = 0
  A0_7943:OnReset()
  A0_7943:RegisterForAreaEvents(1)
end
L0_7939.OnInit = L1_7940
L0_7939 = Wind
function L1_7940(A0_7944)
  A0_7944:OnReset()
end
L0_7939.OnPropertyChange = L1_7940
L0_7939 = Wind
function L1_7940(A0_7945)
  A0_7945:RegisterForAreaEvents(1)
end
L0_7939.OnReset = L1_7940
L0_7939 = Wind
function L1_7940(A0_7946, A1_7947)
  local L2_7948
  L2_7948 = A0_7946.bTriggered
  A1_7947.bTriggered = L2_7948
  L2_7948 = A0_7946.oldVelocity
  A1_7947.oldVelocity = L2_7948
  L2_7948 = A0_7946.fadeamt
  A1_7947.fadeamt = L2_7948
  L2_7948 = A0_7946.Who
  A1_7947.Who = L2_7948
end
L0_7939.OnSave = L1_7940
L0_7939 = Wind
function L1_7940(A0_7949, A1_7950)
  local L2_7951
  L2_7951 = A1_7950.bTriggered
  A0_7949.bTriggered = L2_7951
  L2_7951 = A1_7950.oldVelocity
  A0_7949.oldVelocity = L2_7951
  L2_7951 = A1_7950.fadeamt
  A0_7949.fadamt = L2_7951
  L2_7951 = A1_7950.Who
  A0_7949.Who = L2_7951
end
L0_7939.OnLoad = L1_7940
L0_7939 = Wind
function L1_7940(A0_7952, A1_7953, A2_7954, A3_7955)
  A0_7952:Fade(A3_7955)
end
L0_7939.OnProceedFadeArea = L1_7940
L0_7939 = Wind
function L1_7940(A0_7956)
  System.SetWind(A0_7956.oldVelocity)
end
L0_7939.ResetValues = L1_7940
L0_7939 = Wind
function L1_7940(A0_7957, A1_7958, A2_7959)
  if A1_7958 and not A1_7958.actor:IsPlayer() or A0_7957.occupied == 1 then
    return
  end
  A0_7957.oldVelocity = System.GetWind()
  A0_7957.occupied = 1
end
L0_7939.OnEnterArea = L1_7940
L0_7939 = Wind
function L1_7940(A0_7960, A1_7961, A2_7962)
  if A1_7961 and not A1_7961.actor:IsPlayer() then
    return
  end
  A0_7960:ResetValues()
  A0_7960.occupied = 0
end
L0_7939.OnLeaveArea = L1_7940
L0_7939 = Wind
function L1_7940(A0_7963)
  A0_7963:RegisterForAreaEvents(0)
end
L0_7939.OnShutDown = L1_7940
L0_7939 = Wind
function L1_7940(A0_7964, A1_7965)
  if A0_7964.occupied == 0 then
    if A0_7964.fadeamt and A0_7964.fadeamt < 1 then
      A0_7964:ResetValues()
    end
    A0_7964:OnEnterArea()
    A0_7964.fadeamt = 0
    A0_7964.lasttime = _time
    A0_7964.exitfrom = nil
  end
  A0_7964:SetTimer(0, 1)
  BroadcastEvent(A0_7964, "Enable")
end
L0_7939.Event_Enable = L1_7940
L0_7939 = Wind
function L1_7940(A0_7966, A1_7967)
  if A0_7966.occupied == 1 then
    A0_7966.occupied = 0
    A0_7966.fadeamt = 0
    A0_7966.lasttime = _time
    A0_7966.exitfrom = 1
  end
  A0_7966:SetTimer(0, 1)
  BroadcastEvent(A0_7966, "Disable")
end
L0_7939.Event_Disable = L1_7940
L0_7939 = Wind
function L1_7940(A0_7968)
  local L1_7969, L2_7970
  L2_7970 = A0_7968
  L1_7969 = A0_7968.SetTimer
  L1_7969(L2_7970, 0, 1)
  L1_7969 = A0_7968.fadeamt
  if L1_7969 then
    L1_7969 = _time
    L2_7970 = A0_7968.lasttime
    L1_7969 = L1_7969 - L2_7970
    L2_7970 = _time
    A0_7968.lasttime = L2_7970
    L2_7970 = A0_7968.fadeamt
    L2_7970 = L2_7970 + L1_7969 / A0_7968.Properties.fFadeTime
    A0_7968.fadeamt = L2_7970
    L2_7970 = A0_7968.fadeamt
    if L2_7970 >= 1 then
      A0_7968.fadeamt = 1
      L2_7970 = A0_7968.KillTimer
      L2_7970(A0_7968, 0)
    end
    L2_7970 = A0_7968.fadeamt
    if A0_7968.exitfrom then
      L2_7970 = 1 - L2_7970
    end
    L2_7970 = math.sqrt(L2_7970)
    L2_7970 = math.sqrt(L2_7970)
    A0_7968:Fade(L2_7970)
  else
    L2_7970 = A0_7968
    L1_7969 = A0_7968.KillTimer
    L1_7969(L2_7970, 0)
  end
end
L0_7939.OnTimer = L1_7940
L0_7939 = Wind
function L1_7940(A0_7971, A1_7972)
  System.SetWind(LerpColors(A0_7971.oldVelocity, A0_7971.Properties.vVelocity, A1_7972))
end
L0_7939.Fade = L1_7940
L0_7939 = Wind
L1_7940 = {}
L2_7941 = {}
L3_7942 = {
  Wind.Event_Disable,
  "bool"
}
L2_7941.Disable = L3_7942
L3_7942 = {
  Wind.Event_Enable,
  "bool"
}
L2_7941.Enable = L3_7942
L1_7940.Inputs = L2_7941
L2_7941 = {}
L2_7941.Disable = "bool"
L2_7941.Enable = "bool"
L1_7940.Outputs = L2_7941
L0_7939.FlowEvents = L1_7940
