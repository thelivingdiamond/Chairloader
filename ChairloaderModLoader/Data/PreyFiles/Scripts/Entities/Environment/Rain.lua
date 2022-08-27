local L0_5196, L1_5197, L2_5198, L3_5199
L0_5196 = {}
L0_5196.type = "Rain"
L1_5197 = {}
L1_5197.bEnabled = 1
L1_5197.bIgnoreVisareas = 0
L1_5197.bDisableOcclusion = 0
L1_5197.fRadius = 10000
L1_5197.fAmount = 1
L2_5198 = {}
L2_5198.x = 1
L2_5198.y = 1
L2_5198.z = 1
L1_5197.clrColor = L2_5198
L1_5197.fFakeGlossiness = 0.5
L1_5197.fFakeReflectionsAmount = 1.5
L1_5197.fDiffuseDarkening = 0.5
L1_5197.fRainDropsAmount = 0.5
L1_5197.fRainDropsSpeed = 1
L1_5197.fRainDropsLighting = 1
L1_5197.fMistAmount = 3
L1_5197.fMistHeight = 8
L1_5197.fPuddlesAmount = 1.5
L1_5197.fPuddlesMaskAmount = 1
L1_5197.fPuddlesRippleAmount = 2
L1_5197.fSplashesAmount = 1.3
L0_5196.Properties = L1_5197
L1_5197 = {}
L1_5197.Icon = "shake.bmp"
L0_5196.Editor = L1_5197
Rain = L0_5196
L0_5196 = Rain
function L1_5197(A0_5200)
  A0_5200:OnReset()
end
L0_5196.OnInit = L1_5197
L0_5196 = Rain
function L1_5197(A0_5201)
  A0_5201:OnReset()
end
L0_5196.OnPropertyChange = L1_5197
L0_5196 = Rain
function L1_5197(A0_5202)
  local L1_5203
end
L0_5196.OnReset = L1_5197
L0_5196 = Rain
function L1_5197(A0_5204, A1_5205)
  local L2_5206
  L2_5206 = A0_5204.Properties
  L2_5206 = L2_5206.bEnabled
  A1_5205.bEnabled = L2_5206
end
L0_5196.OnSave = L1_5197
L0_5196 = Rain
function L1_5197(A0_5207, A1_5208)
  A0_5207.Properties.bEnabled = A1_5208.bEnabled
end
L0_5196.OnLoad = L1_5197
L0_5196 = Rain
function L1_5197(A0_5209)
  local L1_5210
end
L0_5196.OnShutDown = L1_5197
L0_5196 = Rain
function L1_5197(A0_5211, A1_5212)
  A0_5211.Properties.bEnabled = 1
  A0_5211:ActivateOutput("Enable", true)
end
L0_5196.Event_Enable = L1_5197
L0_5196 = Rain
function L1_5197(A0_5213, A1_5214)
  A0_5213.Properties.bEnabled = 0
  A0_5213:ActivateOutput("Disable", true)
end
L0_5196.Event_Disable = L1_5197
L0_5196 = Rain
function L1_5197(A0_5215, A1_5216, A2_5217)
  A0_5215.Properties.fAmount = A2_5217
end
L0_5196.Event_Amount = L1_5197
L0_5196 = Rain
function L1_5197(A0_5218, A1_5219, A2_5220)
  A0_5218.Properties.fRadius = A2_5220
end
L0_5196.Event_Radius = L1_5197
L0_5196 = Rain
function L1_5197(A0_5221, A1_5222, A2_5223)
  A0_5221.Properties.fMistAmount = A2_5223
end
L0_5196.Event_MistAmount = L1_5197
L0_5196 = Rain
function L1_5197(A0_5224, A1_5225, A2_5226)
  A0_5224.Properties.fPuddlesAmount = A2_5226
end
L0_5196.Event_PuddlesAmount = L1_5197
L0_5196 = Rain
function L1_5197(A0_5227, A1_5228, A2_5229)
  A0_5227.Properties.fRainDropsAmount = A2_5229
end
L0_5196.Event_RainDropsAmount = L1_5197
L0_5196 = Rain
function L1_5197(A0_5230, A1_5231, A2_5232)
  A0_5230.Properties.fRainDropsSpeed = A2_5232
end
L0_5196.Event_RainDropsSpeed = L1_5197
L0_5196 = Rain
L1_5197 = {}
L2_5198 = {}
L3_5199 = {
  Rain.Event_Disable,
  "bool"
}
L2_5198.Disable = L3_5199
L3_5199 = {
  Rain.Event_Enable,
  "bool"
}
L2_5198.Enable = L3_5199
L3_5199 = {
  Rain.Event_Amount,
  "float"
}
L2_5198.Amount = L3_5199
L3_5199 = {
  Rain.Event_Radius,
  "float"
}
L2_5198.Radius = L3_5199
L3_5199 = {
  Rain.Event_MistAmount,
  "float"
}
L2_5198.MistAmount = L3_5199
L3_5199 = {
  Rain.Event_PuddlesAmount,
  "float"
}
L2_5198.PuddlesAmount = L3_5199
L3_5199 = {
  Rain.Event_RainDropsAmount,
  "float"
}
L2_5198.RainDropsAmount = L3_5199
L3_5199 = {
  Rain.Event_RainDropsSpeed,
  "float"
}
L2_5198.RainDropsSpeed = L3_5199
L1_5197.Inputs = L2_5198
L2_5198 = {}
L2_5198.Disable = "bool"
L2_5198.Enable = "bool"
L1_5197.Outputs = L2_5198
L0_5196.FlowEvents = L1_5197
