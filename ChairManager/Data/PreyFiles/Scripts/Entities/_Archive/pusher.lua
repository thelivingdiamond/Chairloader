local L0_1251, L1_1252, L2_1253, L3_1254
L0_1251 = {}
L0_1251.type = "Pusher"
L1_1252 = {}
L1_1252.fImpulse = 10
L1_1252.bEnabled = 1
L1_1252.bOnce = 0
L0_1251.Properties = L1_1252
L1_1252 = {}
L1_1252.Model = "Objects/Editor/T.cgf"
L0_1251.Editor = L1_1252
Pusher = L0_1251
L0_1251 = Pusher
function L1_1252(A0_1255)
  A0_1255:OnReset()
end
L0_1251.OnInit = L1_1252
L0_1251 = Pusher
function L1_1252(A0_1256)
  local L1_1257
  L1_1257 = A0_1256.Properties
  L1_1257 = L1_1257.bEnabled
  A0_1256.isEnabled = L1_1257
end
L0_1251.OnReset = L1_1252
L0_1251 = Pusher
function L1_1252(A0_1258, A1_1259, A2_1260)
  local L3_1261, L4_1262
  L3_1261 = A0_1258.isEnabled
  if L3_1261 == 0 then
    return
  end
  L3_1261 = A1_1259.Who
  if not L3_1261 then
    return
  end
  L4_1262 = L3_1261.theVehicle
  if not L4_1262 then
    return
  end
  if not L4_1262.driverT then
    return
  end
  if L4_1262.driverT.entity ~= L3_1261 then
    return
  end
  L4_1262:AddImpulseObj(A0_1258:GetDirectionVector(), A0_1258.Properties.fImpulse)
  if A0_1258.Properties.bOnce == 1 then
    A0_1258.isEnabled = 0
  end
end
L0_1251.Event_Push = L1_1252
L0_1251 = Pusher
function L1_1252(A0_1263)
  local L1_1264
end
L0_1251.OnShutDown = L1_1252
L0_1251 = Pusher
function L1_1252(A0_1265, A1_1266)
  A0_1265.isEnabled = 1
end
L0_1251.Event_Enable = L1_1252
L0_1251 = Pusher
function L1_1252(A0_1267, A1_1268)
  A0_1267.isEnabled = 0
end
L0_1251.Event_Disable = L1_1252
L0_1251 = Pusher
L1_1252 = {}
L2_1253 = {}
L3_1254 = {
  Pusher.Event_Disable,
  "bool"
}
L2_1253.Disable = L3_1254
L3_1254 = {
  Pusher.Event_Enable,
  "bool"
}
L2_1253.Enable = L3_1254
L3_1254 = {
  Pusher.Event_Push,
  "bool"
}
L2_1253.Push = L3_1254
L1_1252.Inputs = L2_1253
L2_1253 = {}
L2_1253.Disable = "bool"
L2_1253.Enable = "bool"
L2_1253.Push = "bool"
L1_1252.Outputs = L2_1253
L0_1251.FlowEvents = L1_1252
