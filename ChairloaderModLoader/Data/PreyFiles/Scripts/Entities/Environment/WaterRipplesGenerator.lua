local L0_5373, L1_5374, L2_5375, L3_5376
L0_5373 = {}
L0_5373.type = "WaterRipplesGenerator"
L1_5374 = {}
L1_5374.bEnabled = 1
L1_5374.fScale = 1
L1_5374.fStrength = 1
L2_5375 = {}
L2_5375.bAutoSpawn = 0
L2_5375.bSpawnOnMovement = 1
L2_5375.fFrequency = 1
L1_5374.Spawning = L2_5375
L2_5375 = {}
L2_5375.fRandomFreq = 0
L2_5375.fRandomScale = 0
L2_5375.fRandomStrength = 0
L2_5375.fRandomOffsetX = 0
L2_5375.fRandomOffsetY = 0
L1_5374.Randomization = L2_5375
L0_5373.Properties = L1_5374
L1_5374 = {}
L1_5374.Icon = "seed.bmp"
L0_5373.Editor = L1_5374
L1_5374 = {}
L0_5373.Client = L1_5374
L1_5374 = {}
L0_5373.Server = L1_5374
WaterRipplesGenerator = L0_5373
L0_5373 = WaterRipplesGenerator
function L1_5374(A0_5377)
  Game.SendEventToGameObject(A0_5377.id, "propertyChanged")
end
L0_5373.OnPropertyChange = L1_5374
L0_5373 = WaterRipplesGenerator
function L1_5374(A0_5378)
  Game.SendEventToGameObject(A0_5378.id, "enable")
end
L0_5373.Event_Enable = L1_5374
L0_5373 = WaterRipplesGenerator
function L1_5374(A0_5379)
  Game.SendEventToGameObject(A0_5379.id, "disable")
end
L0_5373.Event_Disable = L1_5374
L0_5373 = WaterRipplesGenerator
function L1_5374(A0_5380, A1_5381, A2_5382)
  local L3_5383
  L3_5383 = A0_5380.Properties
  L3_5383 = L3_5383.Spawning
  L3_5383.bAutoSpawn = A2_5382
end
L0_5373.Event_AutoSpawn = L1_5374
L0_5373 = WaterRipplesGenerator
function L1_5374(A0_5384, A1_5385, A2_5386)
  local L3_5387
  L3_5387 = A0_5384.Properties
  L3_5387 = L3_5387.Spawning
  L3_5387.bSpawnOnMovement = A2_5386
end
L0_5373.Event_SpawnOnMovement = L1_5374
L0_5373 = WaterRipplesGenerator
function L1_5374(A0_5388, A1_5389, A2_5390)
  A0_5388.Properties.fScale = A2_5390
end
L0_5373.Event_SetScale = L1_5374
L0_5373 = WaterRipplesGenerator
function L1_5374(A0_5391, A1_5392, A2_5393)
  local L3_5394
  L3_5394 = A0_5391.Properties
  L3_5394 = L3_5394.Randomization
  L3_5394.fRandomScale = A2_5393
end
L0_5373.Event_SetRandomScale = L1_5374
L0_5373 = WaterRipplesGenerator
function L1_5374(A0_5395, A1_5396, A2_5397)
  A0_5395.Properties.fStrength = A2_5397
end
L0_5373.Event_SetStrength = L1_5374
L0_5373 = WaterRipplesGenerator
function L1_5374(A0_5398, A1_5399, A2_5400)
  local L3_5401
  L3_5401 = A0_5398.Properties
  L3_5401 = L3_5401.Randomization
  L3_5401.fRandomStrength = A2_5400
end
L0_5373.Event_SetRandomStrength = L1_5374
L0_5373 = WaterRipplesGenerator
function L1_5374(A0_5402, A1_5403, A2_5404)
  local L3_5405
  L3_5405 = A0_5402.Properties
  L3_5405 = L3_5405.Spawning
  L3_5405.fFrequency = A2_5404
end
L0_5373.Event_SetFrequency = L1_5374
L0_5373 = WaterRipplesGenerator
function L1_5374(A0_5406, A1_5407, A2_5408)
  local L3_5409
  L3_5409 = A0_5406.Properties
  L3_5409 = L3_5409.Randomization
  L3_5409.fRandomFreq = A2_5408
end
L0_5373.Event_SetRandomFreq = L1_5374
L0_5373 = WaterRipplesGenerator
function L1_5374(A0_5410, A1_5411, A2_5412)
  local L3_5413, L4_5414
  L3_5413 = A0_5410.Properties
  L3_5413 = L3_5413.Randomization
  L4_5414 = A2_5412.x
  L3_5413.fRandomOffsetX = L4_5414
  L3_5413 = A0_5410.Properties
  L3_5413 = L3_5413.Randomization
  L4_5414 = A2_5412.y
  L3_5413.fRandomOffsetY = L4_5414
end
L0_5373.Event_SetRandomOffset = L1_5374
L0_5373 = WaterRipplesGenerator
L1_5374 = {}
L2_5375 = {}
L3_5376 = {
  WaterRipplesGenerator.Event_Enable,
  "any"
}
L2_5375.Enable = L3_5376
L3_5376 = {
  WaterRipplesGenerator.Event_Disable,
  "any"
}
L2_5375.Disable = L3_5376
L3_5376 = {
  WaterRipplesGenerator.Event_AutoSpawn,
  "bool"
}
L2_5375.AutoSpawn = L3_5376
L3_5376 = {
  WaterRipplesGenerator.Event_SpawnOnMovement,
  "bool"
}
L2_5375.SpawnOnMovement = L3_5376
L3_5376 = {
  WaterRipplesGenerator.Event_SetScale,
  "float"
}
L2_5375.Scale = L3_5376
L3_5376 = {
  WaterRipplesGenerator.Event_SetRandomScale,
  "float"
}
L2_5375.RandomScale = L3_5376
L3_5376 = {
  WaterRipplesGenerator.Event_SetStrength,
  "float"
}
L2_5375.Strength = L3_5376
L3_5376 = {
  WaterRipplesGenerator.Event_SetRandomStrength,
  "float"
}
L2_5375.RandomStrength = L3_5376
L3_5376 = {
  WaterRipplesGenerator.Event_SetFrequency,
  "float"
}
L2_5375.Frequency = L3_5376
L3_5376 = {
  WaterRipplesGenerator.Event_SetRandomFreq,
  "float"
}
L2_5375.RandomFreq = L3_5376
L3_5376 = {
  WaterRipplesGenerator.Event_SetRandomOffset,
  "vec3"
}
L2_5375.RandomOffset = L3_5376
L1_5374.Inputs = L2_5375
L2_5375 = {}
L2_5375.Disable = "bool"
L2_5375.Enable = "bool"
L1_5374.Outputs = L2_5375
L0_5373.FlowEvents = L1_5374
