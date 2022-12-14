local L0_503, L1_504, L2_505, L3_506
L0_503 = {}
L1_504 = {}
L1_504.bActive = 1
L1_504.MapVisMask = 0
L2_505 = {}
L2_505.X = 0
L2_505.Y = 0
L2_505.Z = 1
L1_504.Direction = L2_505
L1_504.OpenDelay = 1.5
L1_504.CloseDelay = 1.5
L1_504.RetriggerDelay = 1
L1_504.MovingDistance = 2
L1_504.MovingSpeed = 0.5
L1_504.bAutomatic = 1
L1_504.fileModel = "Objects/indoor/lift/lift.cgf"
L1_504.fileStartSound = "Sounds/lifts/liftst.wav"
L1_504.fileLoopSound = "Sounds/lifts/liftlp.wav"
L1_504.fileStopSound = "Sounds/lifts/liftend.wav"
L1_504.LoopSoundStart = 1.1
L2_505 = {}
L2_505.bHasWarnLight = 1
L2_505.fLightRadius = 10
L3_506 = {
  1,
  0,
  0
}
L2_505.clrLightDiffuse = L3_506
L3_506 = {
  1,
  1,
  1
}
L2_505.clrLightSpecular = L3_506
L3_506 = {}
L3_506.x = 0
L3_506.y = 0
L3_506.z = 0
L2_505.LightAngles = L3_506
L2_505.fLightRotSpeed = 50
L2_505.bProjectInAllDirs = 0
L2_505.ProjectorFov = 90
L2_505.texture_ProjectorTexture = "Textures/projector.jpg"
L2_505.shader_lightShader = ""
L2_505.bAffectsThisAreaOnly = 1
L2_505.bUsedInRealTime = 1
L2_505.bFakeLight = 0
L2_505.bHeatSource = 0
L1_504.WarnLight = L2_505
L1_504.sMaterialDefault = "m06_ben.Lift.reseach_lift_Default"
L1_504.sMaterialUp = "m06_ben.Lift.reseach_lift_UP"
L1_504.sMaterialDown = "m06_ben.Lift.reseach_lift_DOWN"
L0_503.Properties = L1_504
L0_503.base = nil
L1_504 = {}
L1_504.x = 0
L1_504.y = 0
L1_504.z = 0
L0_503.temp_vec = L1_504
L1_504 = {}
L1_504.x = 0
L1_504.y = 0
L1_504.z = 0
L0_503.base_pos = L1_504
L0_503.Distance = 0
L0_503.bOpeningDelay = nil
L0_503.bTriggerOpenRequest = nil
L0_503.bActive = 1
L0_503.MoveDir = 1
AutomaticElevator = L0_503
L0_503 = AutomaticElevator
function L1_504(A0_507, A1_508)
  WriteToStream(A1_508, A0_507.base_pos)
  A1_508:WriteFloat(A0_507.Distance)
  A1_508:WriteInt(A0_507.bActive)
  if A0_507.InUpPos then
    A1_508:WriteInt(A0_507.InUpPos)
  else
    A1_508:WriteInt(0)
  end
end
L0_503.OnSave = L1_504
L0_503 = AutomaticElevator
function L1_504(A0_509, A1_510)
  A0_509:OnPropertyChange()
  A0_509.base_pos = ReadFromStream(A1_510)
  A0_509:SetPos(A0_509.base_pos)
  A0_509.Distance = A1_510:ReadFloat()
  A0_509.bActive = A1_510:ReadInt()
  A0_509.InUpPos = A1_510:ReadInt()
  if A0_509.InUpPos == 0 then
    A0_509.InUpPos = nil
  else
    A0_509.temp_vec.x = A0_509.Properties.Direction.X * A0_509.Properties.MovingDistance * A0_509.MoveDir + A0_509.base_pos.x
    A0_509.temp_vec.y = A0_509.Properties.Direction.Y * A0_509.Properties.MovingDistance * A0_509.MoveDir + A0_509.base_pos.y
    A0_509.temp_vec.z = A0_509.Properties.Direction.Z * A0_509.Properties.MovingDistance * A0_509.MoveDir + A0_509.base_pos.z
    A0_509:SetPos(A0_509.temp_vec)
  end
end
L0_503.OnLoad = L1_504
L0_503 = AutomaticElevator
function L1_504(A0_511, A1_512)
  A0_511:OnPropertyChange()
  A0_511.base_pos = ReadFromStream(A1_512)
  A0_511:SetPos(A0_511.base_pos)
  A0_511.Distance = A1_512:ReadFloat()
  A0_511.bActive = A1_512:ReadInt()
end
L0_503.OnLoadRELEASE = L1_504
L0_503 = AutomaticElevator
function L1_504(A0_513)
  A0_513:OnReset()
  if A0_513.Properties.fileStartSound ~= A0_513.CurrStartSound then
    A0_513.CurrStartSound = A0_513.Properties.fileStartSound
    A0_513.StartSound = Sound.Load3DSound(A0_513.CurrStartSound)
    Sound.SetSoundVolume(A0_513.StartSound, 255)
    Sound.SetMinMaxDistance(A0_513.StartSound, 10, 30)
  end
  if A0_513.Properties.fileLoopSound ~= A0_513.CurrLoopSound then
    A0_513.CurrLoopSound = A0_513.Properties.fileLoopSound
    A0_513.LoopSound = Sound.Load3DSound(A0_513.CurrLoopSound)
    Sound.SetSoundLoop(A0_513.LoopSound, 1)
    Sound.SetSoundVolume(A0_513.LoopSound, 255)
    Sound.SetMinMaxDistance(A0_513.LoopSound, 10, 30)
  end
  if A0_513.Properties.fileStopSound ~= A0_513.CurrStopSound then
    A0_513.CurrStopSound = A0_513.Properties.fileStopSound
    A0_513.StopSound = Sound.Load3DSound(A0_513.CurrStopSound)
    Sound.SetSoundVolume(A0_513.StopSound, 255)
    Sound.SetMinMaxDistance(A0_513.StopSound, 10, 30)
  end
end
L0_503.OnPropertyChange = L1_504
L0_503 = AutomaticElevator
function L1_504(A0_514, A1_515)
  local L2_516
  L2_516 = A0_514.Properties
  L2_516 = L2_516.WarnLight
  L2_516 = L2_516.bHasWarnLight
  if L2_516 > 0 then
    L2_516 = A0_514.GetHelperPos
    L2_516 = L2_516(A0_514, "warnlight")
    if L2_516 then
      if A1_515 > 5 then
        A1_515 = 0
      end
      A0_514.Properties.WarnLight.LightAngles.z = A0_514.Properties.WarnLight.LightAngles.z + A0_514.Properties.WarnLight.fLightRotSpeed * A1_515
      if A0_514.Properties.WarnLight.LightAngles.z >= 360 then
        A0_514.Properties.WarnLight.LightAngles.z = A0_514.Properties.WarnLight.LightAngles.z - 360
      end
      if 0 > A0_514.Properties.WarnLight.LightAngles.z then
        A0_514.Properties.WarnLight.LightAngles.z = A0_514.Properties.WarnLight.LightAngles.z + 360
      end
      A0_514:AddDynamicLight(L2_516, A0_514.Properties.WarnLight.fLightRadius, A0_514.Properties.WarnLight.clrLightDiffuse[1], A0_514.Properties.WarnLight.clrLightDiffuse[2], A0_514.Properties.WarnLight.clrLightDiffuse[3], 1, A0_514.Properties.WarnLight.clrLightSpecular[1], A0_514.Properties.WarnLight.clrLightSpecular[2], A0_514.Properties.WarnLight.clrLightSpecular[3], 1, 0, 0, A0_514.Properties.WarnLight.LightAngles, A0_514.Properties.WarnLight.ProjectorFov, A0_514.proj_tex_id, A0_514.Properties.WarnLight.bAffectsThisAreaOnly, A0_514.Properties.WarnLight.bUsedInRealTime, A0_514.Properties.WarnLight.bHeatSource, A0_514.Properties.WarnLight.bFakeLight)
    end
  else
  end
end
L0_503.IsMovingClient = L1_504
L0_503 = AutomaticElevator
function L1_504(A0_517)
  if A0_517.Properties.OpenDelay <= 0 then
    A0_517.Properties.OpenDelay = 0.001
  end
  if 0 >= A0_517.Properties.RetriggerDelay then
    A0_517.Properties.RetriggerDelay = 0.001
  end
  if 0 > A0_517.Properties.MovingDistance then
    A0_517.Properties.MovingDistance = 0
  end
  A0_517.bActive = A0_517.Properties.bActive
  A0_517:LoadObject(A0_517.Properties.fileModel, 0, 1)
  A0_517:DrawObject(0, 1)
  A0_517:CreateRigidBody(0, 0, -1)
  A0_517:AwakePhysics(0)
  A0_517:SetUpdateType(eUT_Always)
  A0_517.DuringLoading = 1
  A0_517:RegisterState("Idle")
  A0_517:RegisterState("Opening")
  A0_517:RegisterState("Closing")
  A0_517:GotoState("Idle")
  A0_517.DuringLoading = nil
  if 0 > A0_517.Properties.MovingSpeed then
    A0_517.MoveDir = -1
  else
    A0_517.MoveDir = 1
  end
  A0_517:SetVelocity(0)
  A0_517.Distance = 0
  A0_517.proj_tex_id = System.LoadTexture(A0_517.Properties.WarnLight.texture_ProjectorTexture, 1)
  A0_517:InitDynamicLight(A0_517.Properties.WarnLight.texture_ProjectorTexture, A0_517.Properties.WarnLight.shader_lightShader, A0_517.Properties.WarnLight.bProjectInAllDirs, 0)
end
L0_503.OnReset = L1_504
L0_503 = AutomaticElevator
function L1_504(A0_518, A1_519)
  A0_518.Velocity = {}
  A0_518.Velocity.v = {}
  A0_518.Velocity.v.x = A0_518.Properties.Direction.X * A0_518.Properties.MovingSpeed * A1_519
  A0_518.Velocity.v.y = A0_518.Properties.Direction.Y * A0_518.Properties.MovingSpeed * A1_519
  A0_518.Velocity.v.z = A0_518.Properties.Direction.Z * A0_518.Properties.MovingSpeed * A1_519
  if A1_519 == 0 then
    A0_518:SetUpdateType(eUT_Always)
  else
    A0_518:AwakePhysics(1)
    A0_518:SetUpdateType(eUT_PhysicsPostStep)
  end
end
L0_503.SetVelocity = L1_504
L0_503 = AutomaticElevator
function L1_504(A0_520)
  A0_520:OnReset()
  A0_520:OnPropertyChange()
  A0_520:NetPresent(nil)
  A0_520:Activate(0)
  A0_520:TrackColliders(1)
  A0_520.base_pos = new(A0_520:GetPos())
end
L0_503.OnInit = L1_504
L0_503 = AutomaticElevator
function L1_504(A0_521, A1_522)
  if A0_521.bActive == 0 then
    return
  end
  A0_521:GotoState("Opening")
  BroadcastEvent(A0_521, "Open")
end
L0_503.Event_Open = L1_504
L0_503 = AutomaticElevator
function L1_504(A0_523, A1_524)
  if A0_523.bActive == 0 then
    return
  end
  A0_523:GotoState("Closing")
  BroadcastEvent(A0_523, "Close")
end
L0_503.Event_Close = L1_504
L0_503 = AutomaticElevator
function L1_504(A0_525, A1_526)
  if A0_525.bActive == 0 then
    return
  end
  BroadcastEvent(A0_525, "Opened")
end
L0_503.Event_Opened = L1_504
L0_503 = AutomaticElevator
function L1_504(A0_527, A1_528)
  if A0_527.bActive == 0 then
    return
  end
  BroadcastEvent(A0_527, "Closed")
end
L0_503.Event_Closed = L1_504
L0_503 = AutomaticElevator
function L1_504(A0_529, A1_530)
  A0_529.bActive = 1
end
L0_503.Event_Activate = L1_504
L0_503 = AutomaticElevator
function L1_504(A0_531, A1_532)
  A0_531.bActive = 0
end
L0_503.Event_Deactivate = L1_504
L0_503 = AutomaticElevator
function L1_504(A0_533)
  if A0_533.bActive == 0 then
    return
  end
  A0_533:ResetAnimation(0, -1)
end
L0_503.Event_ResetAnimation = L1_504
L0_503 = AutomaticElevator
function L1_504(A0_534, A1_535)
  if A0_534.bActive == 0 then
    return
  end
  A0_534:ResetAnimation(0, -1)
  A0_534:StartAnimation(0, "default", 0, 0, 1, 0)
  A0_534:SetAnimationSpeed(1)
end
L0_503.Event_StartAnimation = L1_504
L0_503 = AutomaticElevator
L1_504 = {}
function L2_505(A0_536)
  A0_536.server = 1
  A0_536:OnInit()
end
L1_504.OnInit = L2_505
L2_505 = {}
function L3_506(A0_537)
  A0_537:Activate(0)
  A0_537:SetVelocity(0)
  if not A0_537.InUpPos then
    A0_537.bOpeningDelay = nil
    A0_537.bTriggerOpenRequest = nil
  end
  A0_537:SetMaterial(A0_537.Properties.sMaterialDefault)
end
L2_505.OnBeginState = L3_506
function L3_506(A0_538)
  A0_538:Activate(1)
end
L2_505.OnEndState = L3_506
function L3_506(A0_539, A1_540)
  if A0_539.bActive == 0 or A0_539.Properties.bAutomatic == 0 then
    return
  end
  if not A0_539.InUpPos and not A0_539.WaitForDownDelay and A0_539.bOpeningDelay == nil then
    A0_539:SetTimer(A0_539.Properties.OpenDelay * 1000)
    A0_539.bOpeningDelay = 1
  end
end
L2_505.OnContact = L3_506
function L3_506(A0_541)
  if A0_541.bActive == 0 then
    return
  end
  if not A0_541.InUpPos then
    if not A0_541.WaitForDownDelay then
      A0_541:GotoState("Opening")
    end
  else
    System.LogToConsole("Opened State Timer Exprired")
    A0_541:GotoState("Closing")
    A0_541:Event_Close(A0_541)
  end
  A0_541.InUpPos = nil
  A0_541.WaitForDownDelay = nil
end
L2_505.OnTimer = L3_506
L1_504.Idle = L2_505
L2_505 = {}
function L3_506(A0_542)
  A0_542.EventSent = nil
  A0_542:SetVelocity(1)
  A0_542:SetMaterial(A0_542.Properties.sMaterialUp)
end
L2_505.OnBeginState = L3_506
function L3_506(A0_543)
  local L1_544
end
L2_505.OnEndState = L3_506
function L3_506(A0_545, A1_546)
  A0_545.Distance = A0_545.Distance + abs(A1_546 * A0_545.Properties.MovingSpeed)
  if A0_545.Distance > A0_545.Properties.MovingDistance then
    A0_545.Distance = A0_545.Properties.MovingDistance
    if not A0_545.EventSent then
      A0_545.Event_Opened(A0_545)
      A0_545.InUpPos = 1
      A0_545:GotoState("Idle")
      if A0_545.Properties.bAutomatic ~= 0 and 0 < A0_545.Properties.CloseDelay then
        A0_545:SetTimer(A0_545.Properties.CloseDelay * 1000)
      end
    end
    A0_545.EventSent = 1
  end
  A0_545.temp_vec.x = A0_545.Properties.Direction.X * A0_545.Distance * A0_545.MoveDir + A0_545.base_pos.x
  A0_545.temp_vec.y = A0_545.Properties.Direction.Y * A0_545.Distance * A0_545.MoveDir + A0_545.base_pos.y
  A0_545.temp_vec.z = A0_545.Properties.Direction.Z * A0_545.Distance * A0_545.MoveDir + A0_545.base_pos.z
  A0_545:SetPos(A0_545.temp_vec)
  A0_545:SetPhysicParams(PHYSICPARAM_VELOCITY, A0_545.Velocity)
end
L2_505.OnUpdate = L3_506
L1_504.Opening = L2_505
L2_505 = {}
function L3_506(A0_547)
  A0_547.EventSent = nil
  A0_547:SetVelocity(-1)
  A0_547:SetMaterial(A0_547.Properties.sMaterialDown)
end
L2_505.OnBeginState = L3_506
function L3_506(A0_548)
  local L1_549
end
L2_505.OnEndState = L3_506
function L3_506(A0_550, A1_551)
  A0_550.Distance = A0_550.Distance - abs(A1_551 * A0_550.Properties.MovingSpeed)
  if A0_550.Distance < 0 then
    A0_550.Distance = 0
    if not A0_550.EventSent then
      System.Log("Server-EVENT-Closed")
      A0_550:Event_Closed()
      A0_550.WaitForDownDelay = 1
      A0_550:GotoState("Idle")
      A0_550.InUpPos = nil
      if A0_550.Properties.bAutomatic ~= 0 then
        A0_550:SetTimer(A0_550.Properties.RetriggerDelay * 1000)
      end
    end
    A0_550.EventSent = 1
  end
  A0_550.temp_vec.x = A0_550.Properties.Direction.X * A0_550.Distance * A0_550.MoveDir + A0_550.base_pos.x
  A0_550.temp_vec.y = A0_550.Properties.Direction.Y * A0_550.Distance * A0_550.MoveDir + A0_550.base_pos.y
  A0_550.temp_vec.z = A0_550.Properties.Direction.Z * A0_550.Distance * A0_550.MoveDir + A0_550.base_pos.z
  A0_550:SetPos(A0_550.temp_vec)
  A0_550:SetPhysicParams(PHYSICPARAM_VELOCITY, A0_550.Velocity)
end
L2_505.OnUpdate = L3_506
L1_504.Closing = L2_505
L0_503.Server = L1_504
L0_503 = AutomaticElevator
L1_504 = {}
L2_505 = AutomaticElevator
L2_505 = L2_505.OnInit
L1_504.OnInit = L2_505
L2_505 = {}
function L3_506(A0_552)
  A0_552:SetVelocity(0)
  if not A0_552.DuringLoading then
    Sound.SetSoundPosition(A0_552.StopSound, A0_552:GetPos())
    Sound.PlaySound(A0_552.StopSound)
    Sound.StopSound(A0_552.LoopSound)
    Sound.StopSound(A0_552.StartSound)
  end
  A0_552.LoopStarted = nil
end
L2_505.OnBeginState = L3_506
L1_504.Idle = L2_505
L2_505 = {}
function L3_506(A0_553)
  A0_553:SetVelocity(1)
  A0_553:StartAnimation(0, "open")
  System.LogToConsole("CLIENT:Open")
  Sound.SetSoundPosition(A0_553.StartSound, A0_553:GetPos())
  Sound.PlaySound(A0_553.StartSound)
  A0_553.StartMoveTime = _time
end
L2_505.OnBeginState = L3_506
function L3_506(A0_554, A1_555)
  if not A0_554.server then
    A0_554.Distance = A0_554.Distance + abs(A1_555 * A0_554.Properties.MovingSpeed)
    if A0_554.Distance > A0_554.Properties.MovingDistance then
      A0_554.Distance = A0_554.Properties.MovingDistance
    end
    A0_554.temp_vec.x = A0_554.Properties.Direction.X * A0_554.Distance * A0_554.MoveDir + A0_554.base_pos.x
    A0_554.temp_vec.y = A0_554.Properties.Direction.Y * A0_554.Distance * A0_554.MoveDir + A0_554.base_pos.y
    A0_554.temp_vec.z = A0_554.Properties.Direction.Z * A0_554.Distance * A0_554.MoveDir + A0_554.base_pos.z
    A0_554:SetPos(A0_554.temp_vec)
    A0_554:SetPhysicParams(PHYSICPARAM_VELOCITY, A0_554.Velocity)
  end
  if _time - A0_554.StartMoveTime >= A0_554.Properties.LoopSoundStart and not A0_554.LoopStarted then
    Sound.PlaySound(A0_554.LoopSound)
    A0_554.LoopStarted = 1
  end
  Sound.SetSoundPosition(A0_554.StartSound, A0_554:GetPos())
  Sound.SetSoundPosition(A0_554.LoopSound, A0_554:GetPos())
  A0_554:IsMovingClient(A1_555)
end
L2_505.OnUpdate = L3_506
L1_504.Opening = L2_505
L2_505 = {}
function L3_506(A0_556)
  A0_556:SetVelocity(-1)
  A0_556:StartAnimation(0, "close")
  System.LogToConsole("CLIENT:Close")
  Sound.SetSoundPosition(A0_556.StartSound, A0_556:GetPos())
  Sound.PlaySound(A0_556.StartSound)
  A0_556.StartMoveTime = _time
end
L2_505.OnBeginState = L3_506
function L3_506(A0_557, A1_558)
  if not A0_557.server then
    A0_557.Distance = A0_557.Distance - abs(A1_558 * A0_557.Properties.MovingSpeed)
    if A0_557.Distance < 0 then
      A0_557.Distance = 0
    end
    A0_557.temp_vec.x = A0_557.Properties.Direction.X * A0_557.Distance * A0_557.MoveDir + A0_557.base_pos.x
    A0_557.temp_vec.y = A0_557.Properties.Direction.Y * A0_557.Distance * A0_557.MoveDir + A0_557.base_pos.y
    A0_557.temp_vec.z = A0_557.Properties.Direction.Z * A0_557.Distance * A0_557.MoveDir + A0_557.base_pos.z
    A0_557:SetPos(A0_557.temp_vec)
    A0_557:SetPhysicParams(PHYSICPARAM_VELOCITY, A0_557.Velocity)
  end
  if _time - A0_557.StartMoveTime >= A0_557.Properties.LoopSoundStart and not A0_557.LoopStarted then
    Sound.PlaySound(A0_557.LoopSound)
    A0_557.LoopStarted = 1
  end
  Sound.SetSoundPosition(A0_557.StartSound, A0_557:GetPos())
  Sound.SetSoundPosition(A0_557.LoopSound, A0_557:GetPos())
  A0_557.IsMovingClient(A0_557, A1_558)
end
L2_505.OnUpdate = L3_506
L1_504.Closing = L2_505
L0_503.Client = L1_504
L0_503 = AutomaticElevator
L1_504 = {}
L2_505 = {}
L3_506 = {
  AutomaticElevator.Event_Activate,
  "bool"
}
L2_505.Activate = L3_506
L3_506 = {
  AutomaticElevator.Event_Close,
  "bool"
}
L2_505.Close = L3_506
L3_506 = {
  AutomaticElevator.Event_Closed,
  "bool"
}
L2_505.Closed = L3_506
L3_506 = {
  AutomaticElevator.Event_Deactivate,
  "bool"
}
L2_505.Deactivate = L3_506
L3_506 = {
  AutomaticElevator.Event_Open,
  "bool"
}
L2_505.Open = L3_506
L3_506 = {
  AutomaticElevator.Event_Opened,
  "bool"
}
L2_505.Opened = L3_506
L3_506 = {
  AutomaticElevator.Event_ResetAnimation,
  "bool"
}
L2_505.ResetAnimation = L3_506
L3_506 = {
  AutomaticElevator.Event_StartAnimation,
  "bool"
}
L2_505.StartAnimation = L3_506
L1_504.Inputs = L2_505
L2_505 = {}
L2_505.Activate = "bool"
L2_505.Close = "bool"
L2_505.Closed = "bool"
L2_505.Deactivate = "bool"
L2_505.Open = "bool"
L2_505.Opened = "bool"
L2_505.ResetAnimation = "bool"
L2_505.StartAnimation = "bool"
L1_504.Outputs = L2_505
L0_503.FlowEvents = L1_504
