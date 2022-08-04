local L0_5315, L1_5316, L2_5317, L3_5318
L0_5315 = {}
L0_5315.type = "Tornado"
L1_5316 = {}
L1_5316.Radius = 30
L1_5316.fWanderSpeed = 10
L1_5316.FunnelEffect = "weather.tornado.large"
L1_5316.fCloudHeight = 376
L1_5316.fSpinImpulse = 9
L1_5316.fAttractionImpulse = 13
L1_5316.fUpImpulse = 18
L0_5315.Properties = L1_5316
L1_5316 = {}
L1_5316.Icon = "Tornado.bmp"
L0_5315.Editor = L1_5316
Tornado = L0_5315
L0_5315 = Tornado
function L1_5316(A0_5319)
  A0_5319:OnReset()
end
L0_5315.OnInit = L1_5316
L0_5315 = Tornado
function L1_5316(A0_5320)
  A0_5320:OnReset()
end
L0_5315.OnPropertyChange = L1_5316
L0_5315 = Tornado
function L1_5316(A0_5321)
  local L1_5322
end
L0_5315.OnReset = L1_5316
L0_5315 = Tornado
function L1_5316(A0_5323)
  local L1_5324
end
L0_5315.OnShutDown = L1_5316
L0_5315 = Tornado
function L1_5316(A0_5325, A1_5326)
end
L0_5315.Event_TargetReached = L1_5316
L0_5315 = Tornado
function L1_5316(A0_5327, A1_5328)
end
L0_5315.Event_Enable = L1_5316
L0_5315 = Tornado
function L1_5316(A0_5329, A1_5330)
end
L0_5315.Event_Disable = L1_5316
L0_5315 = Tornado
L1_5316 = {}
L2_5317 = {}
L3_5318 = {
  Tornado.Event_Disable,
  "bool"
}
L2_5317.Disable = L3_5318
L3_5318 = {
  Tornado.Event_Enable,
  "bool"
}
L2_5317.Enable = L3_5318
L1_5316.Inputs = L2_5317
L2_5317 = {}
L2_5317.Disable = "bool"
L2_5317.Enable = "bool"
L2_5317.TargetReached = "bool"
L1_5316.Outputs = L2_5317
L0_5315.FlowEvents = L1_5316
