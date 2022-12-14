local L0_1336, L1_1337
L0_1336 = {}
L0_1336.type = "StormController"
L1_1337 = {}
L1_1337.fRainAmount = 0.5
L1_1337.vWindDir = {
  0,
  1,
  0
}
L1_1337.nRandomFrequency = 50
L1_1337.nSoundDistortionTime = 3
L1_1337.nDistanceFromTerrain = 512
L0_1336.Properties = L1_1337
L1_1337 = {}
L1_1337.Model = "Objects/Editor/T.cgf"
L0_1336.Editor = L1_1337
L0_1336.bInside = 0
L0_1336.fLastFadeCoeff = 1
L0_1336.nCurrentPos = 0
L0_1336.fCurrentRain = 0.5
L1_1337 = {}
L1_1337.focus = 90
L1_1337.start_color = {
  1,
  1,
  1
}
L1_1337.end_color = {
  1,
  1,
  1
}
L1_1337.rotation = {
  x = 0,
  y = 0,
  z = 0
}
L1_1337.speed = 0
L1_1337.count = 1
L1_1337.size = 512
L1_1337.size_speed = 0
L1_1337.gravity = {
  x = 0,
  y = 0,
  z = 0
}
L1_1337.lifetime = 0.75
L1_1337.frames = 9
L1_1337.blend_type = 2
L1_1337.tid = System.LoadAnimatedTexture("textures/animated/lightning/lightning_y%02d.tga", 9)
L0_1336.LightningParticles = L1_1337
Storm = L0_1336
L0_1336 = Storm
function L1_1337(A0_1338)
  A0_1338.thunder_sounds = {
    Sound.Load3DSound("sounds\\thunder\\tclap1.wav", SOUND_UNSCALABLE, 0, 255, 7, 1000),
    Sound.Load3DSound("sounds\\thunder\\tclap2.wav", SOUND_UNSCALABLE, 0, 255, 7, 1000),
    Sound.Load3DSound("sounds\\thunder\\tclap3.wav", SOUND_UNSCALABLE, 0, 255, 7, 1000)
  }
  A0_1338:Activate(1)
  A0_1338:OnReset()
end
L0_1336.OnInit = L1_1337
L0_1336 = Storm
function L1_1337(A0_1339)
  A0_1339:OnReset()
end
L0_1336.OnPropertyChange = L1_1337
L0_1336 = Storm
function L1_1337(A0_1340)
  local L1_1341
  A0_1340.bInside = 0
  A0_1340.fLastFadeCoeff = 1
  A0_1340.nCurrentPos = 0
  L1_1341 = A0_1340.Properties
  L1_1341 = L1_1341.fRainAmount
  A0_1340.fCurrentRain = L1_1341
end
L0_1336.OnReset = L1_1337
L0_1336 = Storm
function L1_1337(A0_1342, A1_1343, A2_1344, A3_1345)
  A0_1342.fLastFadeCoeff = A3_1345
end
L0_1336.OnProceedFadeArea = L1_1337
L0_1336 = Storm
function L1_1337(A0_1346)
  local L1_1347, L2_1348, L3_1349
  L1_1347 = A0_1346.nCurrentPos
  if L1_1347 ~= 1 then
    L1_1347 = A0_1346.nCurrentPos
  elseif L1_1347 == 4 then
    L2_1348 = A0_1346
    L1_1347 = A0_1346.GetPos
    L1_1347 = L1_1347(L2_1348)
    L2_1348 = random
    L3_1349 = -20
    L2_1348 = L2_1348(L3_1349, 20)
    L1_1347.x = L2_1348
    L2_1348 = random
    L3_1349 = -20
    L2_1348 = L2_1348(L3_1349, 20)
    L1_1347.y = L2_1348
    L2_1348 = L1_1347.z
    L3_1349 = A0_1346.Properties
    L3_1349 = L3_1349.nDistanceFromTerrain
    L2_1348 = L2_1348 + L3_1349
    L1_1347.z = L2_1348
    L2_1348 = Particle
    L2_1348 = L2_1348.CreateParticle
    L3_1349 = L1_1347
    L2_1348(L3_1349, {
      x = 0,
      y = 0,
      z = 1
    }, A0_1346.LightningParticles)
  end
  L1_1347 = A0_1346.nCurrentPos
  if L1_1347 == 10 then
    L2_1348 = A0_1346
    L1_1347 = A0_1346.GetPos
    L1_1347 = L1_1347(L2_1348)
    L2_1348 = A0_1346.thunder_sounds
    L3_1349 = random
    L3_1349 = L3_1349(1, 3)
    L2_1348 = L2_1348[L3_1349]
    L3_1349 = Sound
    L3_1349 = L3_1349.SetSoundPosition
    L3_1349(L2_1348, L1_1347)
    L3_1349 = Sound
    L3_1349 = L3_1349.PlaySound
    L3_1349(L2_1348)
    L3_1349 = AI
    L3_1349 = L3_1349.ApplySoundDistortion
    L3_1349(L3_1349, A0_1346.Properties.nSoundDistortionTime * 1000)
    A0_1346.nCurrentPos = 0
    L3_1349 = random
    L3_1349 = L3_1349(0, 100 - A0_1346.Properties.nRandomFrequency)
    L3_1349 = L3_1349 * 100
    L3_1349 = L3_1349 * 2
    A0_1346:SetTimer(L3_1349)
    A0_1346.fCurrentRain = random(0, 16 * A0_1346.Properties.fRainAmount) / 16
    Game:ApplyStormToEnvironment(A0_1346.Properties.vWindDir, A0_1346.fCurrentRain)
  else
    L1_1347 = random
    L2_1348 = 0
    L3_1349 = A0_1346.Properties
    L3_1349 = L3_1349.nRandomFrequency
    L3_1349 = 100 - L3_1349
    L1_1347 = L1_1347(L2_1348, L3_1349)
    L1_1347 = L1_1347 * 10
    L2_1348 = A0_1346.nCurrentPos
    if L2_1348 ~= 0 then
      L2_1348 = A0_1346.nCurrentPos
    elseif L2_1348 == 6 then
      L2_1348 = Hud
      L3_1349 = L2_1348
      L2_1348 = L2_1348.OnLightning
      L2_1348(L3_1349)
    end
    L3_1349 = A0_1346
    L2_1348 = A0_1346.SetTimer
    L2_1348(L3_1349, L1_1347)
    L2_1348 = A0_1346.nCurrentPos
    L2_1348 = L2_1348 + 1
    A0_1346.nCurrentPos = L2_1348
  end
end
L0_1336.SetThunder = L1_1337
L0_1336 = Storm
function L1_1337(A0_1350, A1_1351, A2_1352)
  A0_1350:SetTimer(1000)
  A0_1350.bInside = 1
  A0_1350.nCurrentPos = 0
  Game:ApplyStormToEnvironment(A0_1350.Properties.vWindDir, A0_1350.Properties.fRainAmount)
end
L0_1336.OnEnterArea = L1_1337
L0_1336 = Storm
function L1_1337(A0_1353, A1_1354, A2_1355)
  A0_1353.bInside = 0
  Game:ApplyStormToEnvironment(A0_1353.Properties.vWindDir, 0)
  A0_1353.nCurrentPos = 0
end
L0_1336.OnLeaveArea = L1_1337
L0_1336 = Storm
function L1_1337(A0_1356)
  local L1_1357
  A0_1356.thunder_sounds = nil
end
L0_1336.OnShutDown = L1_1337
L0_1336 = Storm
function L1_1337(A0_1358)
  if A0_1358.bInside == 1 then
    A0_1358:SetThunder()
  end
end
L0_1336.Client_OnTimer = L1_1337
L0_1336 = Storm
L1_1337 = {}
L1_1337.OnTimer = Storm.Client_OnTimer
L0_1336.Client = L1_1337
