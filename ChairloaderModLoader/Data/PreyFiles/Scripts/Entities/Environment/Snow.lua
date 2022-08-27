local L0_5258, L1_5259, L2_5260, L3_5261
L0_5258 = {}
L0_5258.type = "Snow"
L1_5259 = {}
L1_5259.bEnabled = 1
L1_5259.fRadius = 50
L2_5260 = {}
L2_5260.fSnowAmount = 10
L2_5260.fFrostAmount = 1
L2_5260.fSurfaceFreezing = 1
L1_5259.Surface = L2_5260
L2_5260 = {}
L2_5260.nSnowFlakeCount = 100
L2_5260.fSnowFlakeSize = 1
L2_5260.fBrightness = 1
L2_5260.fGravityScale = 0.1
L2_5260.fWindScale = 0.1
L2_5260.fTurbulenceStrength = 0.5
L2_5260.fTurbulenceFreq = 0.1
L1_5259.SnowFall = L2_5260
L0_5258.Properties = L1_5259
L1_5259 = {}
L1_5259.Icon = "shake.bmp"
L0_5258.Editor = L1_5259
Snow = L0_5258
L0_5258 = Snow
function L1_5259(A0_5262)
  A0_5262:OnReset()
end
L0_5258.OnInit = L1_5259
L0_5258 = Snow
function L1_5259(A0_5263)
  A0_5263:OnReset()
end
L0_5258.OnPropertyChange = L1_5259
L0_5258 = Snow
function L1_5259(A0_5264)
  local L1_5265
end
L0_5258.OnReset = L1_5259
L0_5258 = Snow
function L1_5259(A0_5266, A1_5267)
end
L0_5258.OnSave = L1_5259
L0_5258 = Snow
function L1_5259(A0_5268, A1_5269)
end
L0_5258.OnLoad = L1_5259
L0_5258 = Snow
function L1_5259(A0_5270)
  local L1_5271
end
L0_5258.OnShutDown = L1_5259
L0_5258 = Snow
function L1_5259(A0_5272, A1_5273)
  A0_5272.Properties.bEnabled = 1
  A0_5272:ActivateOutput("Enable", true)
end
L0_5258.Event_Enable = L1_5259
L0_5258 = Snow
function L1_5259(A0_5274, A1_5275)
  A0_5274.Properties.bEnabled = 0
  A0_5274:ActivateOutput("Disable", true)
end
L0_5258.Event_Disable = L1_5259
L0_5258 = Snow
function L1_5259(A0_5276, A1_5277, A2_5278)
  A0_5276.Properties.fRadius = A2_5278
end
L0_5258.Event_SetRadius = L1_5259
L0_5258 = Snow
function L1_5259(A0_5279, A1_5280, A2_5281)
  local L3_5282
  L3_5282 = A0_5279.Properties
  L3_5282 = L3_5282.Surface
  L3_5282.fSnowAmount = A2_5281
end
L0_5258.Event_SetSnowAmount = L1_5259
L0_5258 = Snow
function L1_5259(A0_5283, A1_5284, A2_5285)
  local L3_5286
  L3_5286 = A0_5283.Properties
  L3_5286 = L3_5286.Surface
  L3_5286.fFrostAmount = A2_5285
end
L0_5258.Event_SetFrostAmount = L1_5259
L0_5258 = Snow
function L1_5259(A0_5287, A1_5288, A2_5289)
  local L3_5290
  L3_5290 = A0_5287.Properties
  L3_5290 = L3_5290.Surface
  L3_5290.fSurfaceFreezing = A2_5289
end
L0_5258.Event_SetSurfaceFreezing = L1_5259
L0_5258 = Snow
function L1_5259(A0_5291, A1_5292, A2_5293)
  local L3_5294
  L3_5294 = A0_5291.Properties
  L3_5294 = L3_5294.SnowFall
  L3_5294.fSnowFlakeSize = A2_5293
end
L0_5258.Event_SetSnowFlakeSize = L1_5259
L0_5258 = Snow
function L1_5259(A0_5295, A1_5296, A2_5297)
  local L3_5298
  L3_5298 = A0_5295.Properties
  L3_5298 = L3_5298.SnowFall
  L3_5298.fBrightness = A2_5297
end
L0_5258.Event_SetSnowFallBrightness = L1_5259
L0_5258 = Snow
function L1_5259(A0_5299, A1_5300, A2_5301)
  local L3_5302
  L3_5302 = A0_5299.Properties
  L3_5302 = L3_5302.SnowFall
  L3_5302.fGravityScale = A2_5301
end
L0_5258.Event_SetSnowFallGravityScale = L1_5259
L0_5258 = Snow
function L1_5259(A0_5303, A1_5304, A2_5305)
  local L3_5306
  L3_5306 = A0_5303.Properties
  L3_5306 = L3_5306.SnowFall
  L3_5306.fWindScale = A2_5305
end
L0_5258.Event_SetSnowFallWindScale = L1_5259
L0_5258 = Snow
function L1_5259(A0_5307, A1_5308, A2_5309)
  local L3_5310
  L3_5310 = A0_5307.Properties
  L3_5310 = L3_5310.SnowFall
  L3_5310.fTurbulenceStrength = A2_5309
end
L0_5258.Event_SetSnowFallTurbulence = L1_5259
L0_5258 = Snow
function L1_5259(A0_5311, A1_5312, A2_5313)
  local L3_5314
  L3_5314 = A0_5311.Properties
  L3_5314 = L3_5314.SnowFall
  L3_5314.fTurbulenceFreq = A2_5313
end
L0_5258.Event_SetSnowFallTurbulenceFreq = L1_5259
L0_5258 = Snow
L1_5259 = {}
L2_5260 = {}
L3_5261 = {
  Snow.Event_Disable,
  "bool"
}
L2_5260.Disable = L3_5261
L3_5261 = {
  Snow.Event_Enable,
  "bool"
}
L2_5260.Enable = L3_5261
L3_5261 = {
  Snow.Event_SetRadius,
  "float"
}
L2_5260.Radius = L3_5261
L3_5261 = {
  Snow.Event_SetSnowAmount,
  "float"
}
L2_5260.SnowAmount = L3_5261
L3_5261 = {
  Snow.Event_SetFrostAmount,
  "float"
}
L2_5260.FrostAmount = L3_5261
L3_5261 = {
  Snow.Event_SetSurfaceFreezing,
  "float"
}
L2_5260.SurfaceFreezing = L3_5261
L3_5261 = {
  Snow.Event_SetSnowFlakeSize,
  "float"
}
L2_5260.SnowFlakeSize = L3_5261
L3_5261 = {
  Snow.Event_SetSnowFallBrightness,
  "float"
}
L2_5260.SnowFallBrightness = L3_5261
L3_5261 = {
  Snow.Event_SetSnowFallGravityScale,
  "float"
}
L2_5260.SnowFallGravityScale = L3_5261
L3_5261 = {
  Snow.Event_SetSnowFallWindScale,
  "float"
}
L2_5260.SnowFallWindScale = L3_5261
L3_5261 = {
  Snow.Event_SetSnowFallTurbulence,
  "float"
}
L2_5260.SnowFallTurbulence = L3_5261
L3_5261 = {
  Snow.Event_SetSnowFallTurbulenceFreq,
  "float"
}
L2_5260.SnowFallTurbulenceFreq = L3_5261
L1_5259.Inputs = L2_5260
L2_5260 = {}
L2_5260.Disable = "bool"
L2_5260.Enable = "bool"
L1_5259.Outputs = L2_5260
L0_5258.FlowEvents = L1_5259
