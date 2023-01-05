local L0_1391, L1_1392, L2_1393, L3_1394
L0_1391 = {}
L1_1392 = {}
L1_1392.object_Model = "Objects/Outdoor/props/PORTABLE_TV/portable_TV.cgf"
L1_1392.object_ModelDestroyed = ""
L1_1392.nDamage = 5
L1_1392.fSndRadius = 25
L1_1392.fSndVolume = 255
L2_1393 = {}
L2_1393.sndFilename = ""
L2_1393.InnerRadius = 1
L2_1393.OuterRadius = 10
L2_1393.nVolume = 255
L1_1392.AliveSoundLoop = L2_1393
L2_1393 = {}
L2_1393.sndFilename = ""
L2_1393.InnerRadius = 1
L2_1393.OuterRadius = 10
L2_1393.nVolume = 255
L1_1392.DeadSoundLoop = L2_1393
L2_1393 = {}
L2_1393.sndFilename = ""
L2_1393.InnerRadius = 1
L2_1393.OuterRadius = 10
L2_1393.nVolume = 255
L1_1392.DyingSound = L2_1393
L0_1391.PropertiesInstance = L1_1392
L1_1392 = {}
L1_1392.mass = 5
L0_1391.Properties = L1_1392
TV = L0_1391
L0_1391 = TV
function L1_1392(A0_1395)
  A0_1395:Activate(0)
  AI:RegisterWithAI(A0_1395.id, AIOBJECT_SNDSUPRESSOR, A0_1395.Properties)
  A0_1395:SetAICustomFloat(A0_1395.PropertiesInstance.fSndRadius)
  A0_1395:OnReset()
end
L0_1391.OnInit = L1_1392
L0_1391 = TV
function L1_1392(A0_1396)
  A0_1396:OnReset()
end
L0_1391.OnPropertyChange = L1_1392
L0_1391 = TV
function L1_1392(A0_1397)
  local L1_1398
end
L0_1391.OnShutDown = L1_1392
L0_1391 = TV
function L1_1392(A0_1399)
  if A0_1399.PropertiesInstance.object_Model ~= A0_1399.CurrModel then
    A0_1399.CurrModel = A0_1399.PropertiesInstance.object_Model
    A0_1399:LoadObject(A0_1399.PropertiesInstance.object_Model, 0, 1)
    A0_1399:DrawObject(0, 1)
    A0_1399:CreateStaticEntity(10, 100)
    A0_1399:CreateRigidBody(0, A0_1399.Properties.Mass, 0)
  end
  if A0_1399.PropertiesInstance.object_ModelDestroyed ~= "" and A0_1399.PropertiesInstance.object_ModelDestroyed ~= A0_1399.CurrDestroyedModel then
    A0_1399.CurrDestroyedModel = A0_1399.PropertiesInstance.object_ModelDestroyed
    A0_1399:LoadObject(A0_1399.PropertiesInstance.object_ModelDestroyed, 1, 1)
    A0_1399:DrawObject(1, 0)
    A0_1399:CreateStaticEntity(10, 100)
  end
  if A0_1399.DyingSoundLoop and Sound.IsPlaying(A0_1399.DyingSound) then
    Sound.StopSound(A0_1399.DyingSound)
  end
  if A0_1399.DeadSoundLoop and Sound.IsPlaying(A0_1399.DeadSoundLoop) then
    Sound.StopSound(A0_1399.DeadSoundLoop)
  end
  if A0_1399.AliveSoundLoop and Sound.IsPlaying(A0_1399.AliveSoundLoop) then
    Sound.StopSound(A0_1399.AliveSoundLoop)
  end
  if A0_1399.PropertiesInstance.AliveSoundLoop.sndFilename ~= "" then
    A0_1399.AliveSoundLoop = Sound.Load3DSound(A0_1399.PropertiesInstance.AliveSoundLoop.sndFilename, 0)
    if A0_1399.AliveSoundLoop then
      Sound.SetSoundPosition(A0_1399.AliveSoundLoop, A0_1399:GetPos())
      Sound.SetSoundLoop(A0_1399.AliveSoundLoop, 1)
      Sound.SetSoundVolume(A0_1399.AliveSoundLoop, A0_1399.PropertiesInstance.AliveSoundLoop.nVolume)
      Sound.SetMinMaxDistance(A0_1399.AliveSoundLoop, A0_1399.PropertiesInstance.AliveSoundLoop.InnerRadius, A0_1399.PropertiesInstance.AliveSoundLoop.OuterRadius)
    end
  else
    A0_1399.AliveSoundLoop = nil
  end
  if A0_1399.PropertiesInstance.DeadSoundLoop.sndFilename ~= "" then
    A0_1399.DeadSoundLoop = Sound.Load3DSound(A0_1399.PropertiesInstance.DeadSoundLoop.sndFilename, 0)
    if A0_1399.DeadSoundLoop then
      Sound.SetSoundPosition(A0_1399.DeadSoundLoop, A0_1399:GetPos())
      Sound.SetSoundLoop(A0_1399.DeadSoundLoop, 1)
      Sound.SetSoundVolume(A0_1399.DeadSoundLoop, A0_1399.PropertiesInstance.DeadSoundLoop.nVolume)
      Sound.SetMinMaxDistance(A0_1399.DeadSoundLoop, A0_1399.PropertiesInstance.DeadSoundLoop.InnerRadius, A0_1399.PropertiesInstance.DeadSoundLoop.OuterRadius)
    end
  else
    A0_1399.DeadSoundLoop = nil
  end
  if A0_1399.PropertiesInstance.DyingSound.sndFilename ~= "" then
    A0_1399.DyingSound = Sound.Load3DSound(A0_1399.PropertiesInstance.DyingSound.sndFilename, 0)
    if A0_1399.DyingSound then
      Sound.SetSoundPosition(A0_1399.DyingSound, A0_1399:GetPos())
      Sound.SetSoundVolume(A0_1399.DyingSound, A0_1399.PropertiesInstance.DyingSound.nVolume)
      Sound.SetMinMaxDistance(A0_1399.DyingSound, A0_1399.PropertiesInstance.DyingSound.InnerRadius, A0_1399.PropertiesInstance.DyingSound.OuterRadius)
    end
  else
    A0_1399.DyingSound = nil
  end
  A0_1399.curr_damage = A0_1399.PropertiesInstance.nDamage
  System.Log("---RESET TV")
  A0_1399:GoAlive()
end
L0_1391.OnReset = L1_1392
L0_1391 = TV
function L1_1392(A0_1400)
  A0_1400:EnablePhysics(1)
  A0_1400:DrawObject(0, 1)
  A0_1400:DrawObject(1, 0)
  if A0_1400.DeadSoundLoop then
    Sound.StopSound(A0_1400.DeadSoundLoop)
    System.Log("stopping dead-loop")
  end
  A0_1400:GotoState("Active")
end
L0_1391.GoAlive = L1_1392
L0_1391 = TV
function L1_1392(A0_1401)
  if A0_1401.DyingSound and not Sound.IsPlaying(A0_1401.DyingSound) then
    Sound.PlaySound(A0_1401.DyingSound)
    System.Log("starting dying")
  end
  if A0_1401.DeadSoundLoop and not Sound.IsPlaying(A0_1401.DeadSoundLoop) then
    Sound.PlaySound(A0_1401.DeadSoundLoop)
    System.Log("starting dead-loop")
  end
  A0_1401:GotoState("Dead")
end
L0_1391.GoDead = L1_1392
L0_1391 = TV
L1_1392 = {}
function L2_1393(A0_1402)
  A0_1402:Event_On()
end
L1_1392.OnBeginState = L2_1393
function L2_1393(A0_1403, A1_1404)
  A0_1403.curr_damage = A0_1403.curr_damage - A1_1404.damage
  if A0_1403.curr_damage <= 0 then
    A0_1403:GoDead()
  end
end
L1_1392.OnDamage = L2_1393
L0_1391.Active = L1_1392
L0_1391 = TV
L1_1392 = {}
function L2_1393(A0_1405)
  System.Log("enter dead")
  A0_1405:Event_Off()
  A0_1405:DrawObject(0, 0)
  if A0_1405.PropertiesInstance.object_ModelDestroyed ~= "" then
    A0_1405:DrawObject(1, 1)
  else
    A0_1405:EnablePhysics(0)
  end
end
L1_1392.OnBeginState = L2_1393
L0_1391.Dead = L1_1392
L0_1391 = TV
function L1_1392(A0_1406, A1_1407)
  BroadcastEvent(A0_1406, "OnDamage")
end
L0_1391.Event_OnDamage = L1_1392
L0_1391 = TV
function L1_1392(A0_1408, A1_1409)
  A0_1408:TriggerEvent(AIEVENT_ENABLE)
  if A0_1408.AliveSoundLoop and not Sound.IsPlaying(A0_1408.AliveSoundLoop) then
    Sound.PlaySound(A0_1408.AliveSoundLoop)
    System.Log("starting alive-loop")
  end
end
L0_1391.Event_On = L1_1392
L0_1391 = TV
function L1_1392(A0_1410, A1_1411)
  A0_1410:TriggerEvent(AIEVENT_DISABLE)
  if A0_1410.AliveSoundLoop then
    Sound.StopSound(A0_1410.AliveSoundLoop)
    System.Log("stopping alive-loop")
  end
end
L0_1391.Event_Off = L1_1392
L0_1391 = TV
L1_1392 = {}
L2_1393 = {}
L3_1394 = {
  TV.Event_Disable,
  "bool"
}
L2_1393.Off = L3_1394
L3_1394 = {
  TV.Event_Enable,
  "bool"
}
L2_1393.On = L3_1394
L3_1394 = {
  TV.Event_Enable,
  "bool"
}
L2_1393.OnDamage = L3_1394
L1_1392.Inputs = L2_1393
L2_1393 = {}
L2_1393.Off = "bool"
L2_1393.On = "bool"
L2_1393.OnDamage = "bool"
L1_1392.Outputs = L2_1393
L0_1391.FlowEvents = L1_1392
