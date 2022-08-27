local L0_998, L1_999, L2_1000
L0_998 = {}
L1_999 = {}
L1_999.TimeDelay = 0.1
L1_999.fUpdateRadius = 100
L1_999.bActive = 1
L1_999.nType = 0
L1_999.Focus = 4
L2_1000 = {
  1,
  1,
  1
}
L1_999.clrColorStart = L2_1000
L2_1000 = {
  1,
  1,
  1
}
L1_999.clrColorEnd = L2_1000
L1_999.Speed = 1.2
L1_999.nCount = 1
L1_999.Size = 0.2
L1_999.SizeSpeed = 2.2
L1_999.LifeTime = 2
L1_999.FadeInTime = 0.5
L1_999.nFramesSpeed = 0
L1_999.nFrames = 0
L1_999.Tail = 0
L1_999.Bounciness = 0.5
L1_999.bPhysics = 0
L1_999.bAdditiveBlend = 0
L1_999.bColorBlend = 0
L1_999.nDrawOrder = 0
L2_1000 = {}
L2_1000.X = 0
L2_1000.Y = 0
L2_1000.Z = 1
L1_999.Gravity = L2_1000
L2_1000 = {}
L2_1000.X = 0
L2_1000.Y = 0
L2_1000.Z = 0
L1_999.Rotation = L2_1000
L2_1000 = {}
L2_1000.fileTex1 = "Textures\\carsmoke.tga"
L2_1000.fileTex2 = ""
L2_1000.fileTex3 = ""
L2_1000.fileTex4 = ""
L2_1000.fileTex5 = ""
L1_999.Textures = L2_1000
L2_1000 = {}
L2_1000.objObject1 = ""
L2_1000.objObject2 = ""
L2_1000.objObject3 = ""
L2_1000.objObject4 = ""
L2_1000.objObject5 = ""
L1_999.Objects = L2_1000
L1_999.turbulence_size = 0
L1_999.turbulence_speed = 0
L1_999.bLinearSizeSpeed = 0
L1_999.ShaderName = "ParticleLight"
L2_1000 = {}
L2_1000.X = 0
L2_1000.Y = 0
L2_1000.Z = 0
L1_999.SpaceLoopBoxSize = L2_1000
L1_999.bBindToCamera = 0
L1_999.bNoIndoor = 0
L1_999.ChildSpawnPeriod = 0
L2_1000 = {}
L2_1000.nType = 0
L2_1000.Focus = 0.7
L2_1000.clrColorStart = {
  1,
  1,
  1
}
L2_1000.clrColorEnd = {
  1,
  1,
  1
}
L2_1000.Speed = 1.2
L2_1000.nCount = 2
L2_1000.Size = 1.2
L2_1000.SizeSpeed = 0.2
L2_1000.LifeTime = 1
L2_1000.FadeInTime = 0.5
L2_1000.nFrames = 0
L2_1000.Tail = 0
L2_1000.Bounciness = 0.5
L2_1000.bPhysics = 0
L2_1000.bAdditiveBlend = 0
L2_1000.bColorBlend = 0
L2_1000.nDrawOrder = 0
L2_1000.Gravity = {
  X = 0,
  Y = 0,
  Z = 0
}
L2_1000.Rotation = {
  X = 0,
  Y = 0,
  Z = 0
}
L2_1000.fileTexture = ""
L2_1000.objGeometry = ""
L2_1000.SpaceLoopBoxSize = {
  X = 0,
  Y = 0,
  Z = 0
}
L2_1000.bBindToCamera = 0
L2_1000.bNoIndoor = 0
L1_999.ChildProcess = L2_1000
L0_998.Properties = L1_999
L1_999 = {}
L1_999.Model = "Objects/Editor/Particles.cgf"
L0_998.Editor = L1_999
L0_998.TotDelta = 0
L0_998.CurrTid = 0
ParticleSpray = L0_998
L0_998 = ParticleSpray
function L1_999(A0_1001)
  A0_1001:RegisterState("Active")
  A0_1001:RegisterState("Idle")
  A0_1001.ParticleParams = {}
  A0_1001.Textures = {}
  A0_1001.TexturesId = {}
  A0_1001.Objects = {}
  A0_1001.Direction = {
    x = 0,
    y = 0,
    z = 1
  }
  A0_1001:Activate(0)
  A0_1001:SetRegisterInSectors(1)
  A0_1001:SetRadius(0.01)
  A0_1001:OnReset()
  A0_1001:NetPresent(nil)
  A0_1001:SetUpdateType(eUT_PotVisible)
end
L0_998.OnInit = L1_999
L0_998 = ParticleSpray
function L1_999(A0_1002, A1_1003, A2_1004)
  local L3_1005, L4_1006
  L3_1005 = A2_1004.Focus
  A1_1003.focus = L3_1005
  L3_1005 = A2_1004.Speed
  A1_1003.speed = L3_1005
  L3_1005 = A2_1004.nCount
  A1_1003.count = L3_1005
  L3_1005 = A2_1004.Size
  A1_1003.size = L3_1005
  L3_1005 = A2_1004.SizeSpeed
  L3_1005 = L3_1005 / 10
  A1_1003.size_speed = L3_1005
  L3_1005 = A2_1004.LifeTime
  A1_1003.lifetime = L3_1005
  L3_1005 = A2_1004.FadeInTime
  A1_1003.fadeintime = L3_1005
  L3_1005 = A2_1004.nFramesSpeed
  A1_1003.frames = L3_1005
  L3_1005 = A2_1004.Tail
  A1_1003.tail_length = L3_1005
  L3_1005 = A2_1004.Bounciness
  A1_1003.bouncyness = L3_1005
  L3_1005 = A2_1004.bPhysics
  A1_1003.physics = L3_1005
  L3_1005 = A2_1004.bBindToCamera
  A1_1003.BindToCamera = L3_1005
  L3_1005 = A2_1004.bNoIndoor
  A1_1003.NoIndoor = L3_1005
  L3_1005 = A2_1004.nDrawOrder
  A1_1003.draw_last = L3_1005
  L3_1005 = A2_1004.nType
  A1_1003.particle_type = L3_1005
  A1_1003.blend_type = 0
  L3_1005 = A2_1004.bColorBlend
  if L3_1005 ~= 0 then
    A1_1003.blend_type = 1
  end
  L3_1005 = A2_1004.bAdditiveBlend
  if L3_1005 ~= 0 then
    A1_1003.blend_type = 2
  end
  L3_1005 = {}
  A1_1003.gravity = L3_1005
  L3_1005 = A1_1003.gravity
  L4_1006 = A2_1004.Gravity
  L4_1006 = L4_1006.X
  L3_1005.x = L4_1006
  L3_1005 = A1_1003.gravity
  L4_1006 = A2_1004.Gravity
  L4_1006 = L4_1006.Y
  L3_1005.y = L4_1006
  L3_1005 = A1_1003.gravity
  L4_1006 = A2_1004.Gravity
  L4_1006 = L4_1006.Z
  L3_1005.z = L4_1006
  L3_1005 = {}
  A1_1003.SpaceLoopBoxSize = L3_1005
  L3_1005 = A1_1003.SpaceLoopBoxSize
  L4_1006 = A2_1004.SpaceLoopBoxSize
  L4_1006 = L4_1006.X
  L3_1005.x = L4_1006
  L3_1005 = A1_1003.SpaceLoopBoxSize
  L4_1006 = A2_1004.SpaceLoopBoxSize
  L4_1006 = L4_1006.Y
  L3_1005.y = L4_1006
  L3_1005 = A1_1003.SpaceLoopBoxSize
  L4_1006 = A2_1004.SpaceLoopBoxSize
  L4_1006 = L4_1006.Z
  L3_1005.z = L4_1006
  L3_1005 = {}
  A1_1003.rotation = L3_1005
  L3_1005 = A1_1003.rotation
  L4_1006 = A2_1004.Rotation
  L4_1006 = L4_1006.X
  L3_1005.x = L4_1006
  L3_1005 = A1_1003.rotation
  L4_1006 = A2_1004.Rotation
  L4_1006 = L4_1006.Y
  L3_1005.y = L4_1006
  L3_1005 = A1_1003.rotation
  L4_1006 = A2_1004.Rotation
  L4_1006 = L4_1006.Z
  L3_1005.z = L4_1006
  L3_1005 = {}
  A1_1003.start_color = L3_1005
  L3_1005 = A1_1003.start_color
  L4_1006 = A2_1004.clrColorStart
  L4_1006 = L4_1006[1]
  L3_1005[1] = L4_1006
  L3_1005 = A1_1003.start_color
  L4_1006 = A2_1004.clrColorStart
  L4_1006 = L4_1006[2]
  L3_1005[2] = L4_1006
  L3_1005 = A1_1003.start_color
  L4_1006 = A2_1004.clrColorStart
  L4_1006 = L4_1006[3]
  L3_1005[3] = L4_1006
  L3_1005 = {}
  A1_1003.end_color = L3_1005
  L3_1005 = A1_1003.end_color
  L4_1006 = A2_1004.clrColorEnd
  L4_1006 = L4_1006[1]
  L3_1005[1] = L4_1006
  L3_1005 = A1_1003.end_color
  L4_1006 = A2_1004.clrColorEnd
  L4_1006 = L4_1006[2]
  L3_1005[2] = L4_1006
  L3_1005 = A1_1003.end_color
  L4_1006 = A2_1004.clrColorEnd
  L4_1006 = L4_1006[3]
  L3_1005[3] = L4_1006
  L3_1005 = A2_1004.turbulence_size
  A1_1003.turbulence_size = L3_1005
  L3_1005 = A2_1004.turbulence_speed
  A1_1003.turbulence_speed = L3_1005
  L3_1005 = A2_1004.bLinearSizeSpeed
  A1_1003.bLinearSizeSpeed = L3_1005
  L3_1005 = A2_1004.ChildSpawnPeriod
  A1_1003.ChildSpawnPeriod = L3_1005
  L3_1005 = A2_1004.ShaderName
  A1_1003.ShaderName = L3_1005
end
L0_998.Property2ParticleTable = L1_999
L0_998 = ParticleSpray
function L1_999(A0_1007)
  A0_1007:OnReset()
  if A0_1007.Properties.bActive ~= 0 then
    A0_1007:CreateParticleEmitter(A0_1007.ParticleParams, A0_1007.Properties.TimeDelay)
  end
end
L0_998.OnPropertyChange = L1_999
L0_998 = ParticleSpray
function L1_999(A0_1008)
  A0_1008:Property2ParticleTable(A0_1008.ParticleParams, A0_1008.Properties)
  A0_1008.ParticleParams.ChildSpawnPeriod = A0_1008.Properties.ChildSpawnPeriod
  if A0_1008.Properties.ChildProcess.fileTexture ~= "" or A0_1008.Properties.ChildProcess.objGeometry ~= "" then
    A0_1008.ParticleParams.ChildProcess = {}
    A0_1008:Property2ParticleTable(A0_1008.ParticleParams.ChildProcess, A0_1008.Properties.ChildProcess)
  else
    A0_1008.ParticleParams.ChildProcess = nil
  end
  for _FORV_5_, _FORV_6_ in pairs(A0_1008.Properties.Textures) do
  end
  if 1 then
    A0_1008.ReloadTexures(A0_1008)
  end
  A0_1008.ParticleParams.tid = A0_1008:GetRandomTextureId()
  A0_1008:Activate(1)
  A0_1008:SetUpdateRadius(A0_1008.Properties.fUpdateRadius)
  A0_1008:GotoState("")
  if A0_1008.Properties.bActive ~= 0 then
    A0_1008:GotoState("Active")
  else
    A0_1008:GotoState("Idle")
  end
end
L0_998.OnReset = L1_999
L0_998 = ParticleSpray
function L1_999(A0_1009, A1_1010)
end
L0_998.OnSave = L1_999
L0_998 = ParticleSpray
function L1_999(A0_1011, A1_1012)
end
L0_998.OnLoad = L1_999
L0_998 = ParticleSpray
function L1_999(A0_1013)
  A0_1013:GotoState("Active")
end
L0_998.Event_Enable = L1_999
L0_998 = ParticleSpray
function L1_999(A0_1014)
  A0_1014:GotoState("Idle")
end
L0_998.Event_Disable = L1_999
L0_998 = ParticleSpray
function L1_999(A0_1015)
  local L1_1016, L2_1017, L3_1018, L4_1019, L5_1020, L6_1021
  L1_1016 = 1
  A0_1015.TextureIds = L2_1017
  for L5_1020, L6_1021 in L2_1017(L3_1018) do
    if L6_1021 ~= "" then
      if A0_1015.Properties.nFrames > 0 then
        A0_1015.TexturesId[L1_1016] = System.LoadAnimatedTexture(L6_1021, A0_1015.Properties.nFrames)
      else
        A0_1015.TexturesId[L1_1016] = System.LoadTexture(L6_1021)
      end
      L1_1016 = L1_1016 + 1
    end
    A0_1015.Textures[L5_1020] = L6_1021
  end
  if L2_1017 == "" then
    L2_1017.ChildProcess = nil
  else
    A0_1015.ChildTexture = L2_1017
    L2_1017.ChildProcess = L3_1018
    L5_1020 = A0_1015.Properties
    L5_1020 = L5_1020.ChildProcess
    L2_1017(L3_1018, L4_1019, L5_1020)
    L2_1017.tid = L3_1018
  end
end
L0_998.ReloadTexures = L1_999
L0_998 = ParticleSpray
function L1_999(A0_1022)
  A0_1022.ObjectIds = {}
  for _FORV_5_, _FORV_6_ in pairs(A0_1022.Properties.Objects) do
    A0_1022.Objects[_FORV_5_] = _FORV_6_
  end
end
L0_998.ReloadObjects = L1_999
L0_998 = ParticleSpray
function L1_999(A0_1023)
  local L1_1024, L2_1025
  L1_1024 = A0_1023.TexturesId
  L2_1025 = getn
  L2_1025 = L2_1025(L1_1024)
  if L2_1025 > 0 then
    return L1_1024[random(1, L2_1025)]
  else
    return nil
  end
end
L0_998.GetRandomTextureId = L1_999
L0_998 = ParticleSpray
L1_999 = {}
function L2_1000(A0_1026)
  A0_1026:Activate(1)
  A0_1026:CreateParticleEmitter(A0_1026.ParticleParams, A0_1026.Properties.TimeDelay)
  A0_1026.bHaveEmitter = 1
end
L1_999.OnBeginState = L2_1000
function L2_1000(A0_1027)
  A0_1027.bHaveEmitter = nil
  A0_1027:DeleteParticleEmitter()
  A0_1027:Activate(0)
end
L1_999.OnEndState = L2_1000
L0_998.Active = L1_999
L0_998 = ParticleSpray
L1_999 = {}
function L2_1000(A0_1028)
  A0_1028:Activate(0)
  if A0_1028.bHaveEmitter then
    A0_1028:DeleteParticleEmitter(0)
    A0_1028.bHaveEmitter = nil
  end
end
L1_999.OnBeginState = L2_1000
L0_998.Idle = L1_999
L0_998 = ParticleSpray
function L1_999(A0_1029)
  local L1_1030
end
L0_998.OnShutDown = L1_999
L0_998 = ParticleSpray
L1_999 = {}
L2_1000 = {}
L2_1000.Disable = {
  ParticleSpray.Event_Disable,
  "bool"
}
L2_1000.Enable = {
  ParticleSpray.Event_Enable,
  "bool"
}
L1_999.Inputs = L2_1000
L2_1000 = {}
L2_1000.Disable = "bool"
L2_1000.Enable = "bool"
L1_999.Outputs = L2_1000
L0_998.FlowEvents = L1_999
