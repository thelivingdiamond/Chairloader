local L0_8273, L1_8274, L2_8275, L3_8276
L0_8273 = {}
L0_8273.type = "VolumeObject"
L0_8273.ENTITY_DETAIL_ID = 1
L1_8274 = {}
L1_8274.file_VolumeObjectFile = "Libs/Clouds/Default.xml"
L2_8275 = {}
L2_8275.bAutoMove = 0
L3_8276 = {}
L3_8276.x = 0
L3_8276.y = 0
L3_8276.z = 0
L2_8275.vector_Speed = L3_8276
L3_8276 = {}
L3_8276.x = 2000
L3_8276.y = 2000
L3_8276.z = 2000
L2_8275.vector_SpaceLoopBox = L3_8276
L2_8275.fFadeDistance = 0
L1_8274.Movement = L2_8275
L0_8273.Properties = L1_8274
L1_8274 = {}
L1_8274.Model = "Editor/Objects/Particles.cgf"
L1_8274.Icon = "Clouds.bmp"
L0_8273.Editor = L1_8274
VolumeObject = L0_8273
L0_8273 = VolumeObject
function L1_8274(A0_8277)
  A0_8277:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
end
L0_8273.OnSpawn = L1_8274
L0_8273 = VolumeObject
function L1_8274(A0_8278)
  A0_8278:NetPresent(0)
  A0_8278:Create()
end
L0_8273.OnInit = L1_8274
L0_8273 = VolumeObject
function L1_8274(A0_8279)
  local L1_8280
  L1_8280 = A0_8279.Properties
  L1_8280 = L1_8280.Movement
  A0_8279:SetVolumeObjectMovementProperties(0, L1_8280)
end
L0_8273.SetMovementProperties = L1_8274
L0_8273 = VolumeObject
function L1_8274(A0_8281)
  local L1_8282
end
L0_8273.OnShutDown = L1_8274
L0_8273 = VolumeObject
function L1_8274(A0_8283)
  A0_8283:LoadVolumeObject(0, A0_8283.Properties.file_VolumeObjectFile)
  A0_8283:SetMovementProperties()
end
L0_8273.Create = L1_8274
L0_8273 = VolumeObject
function L1_8274(A0_8284)
  A0_8284:FreeSlot(0)
end
L0_8273.Delete = L1_8274
L0_8273 = VolumeObject
function L1_8274(A0_8285)
  if not A0_8285:IsSlotValid(0) then
    A0_8285:Create()
  end
end
L0_8273.OnReset = L1_8274
L0_8273 = VolumeObject
function L1_8274(A0_8286)
  local L1_8287
  L1_8287 = A0_8286.Properties
  if L1_8287.file_VolumeObjectFile ~= A0_8286._VolumeObjectFile then
    A0_8286._VolumeObjectFile = L1_8287.file_VolumeObjectFile
    A0_8286:Create()
  else
    A0_8286:SetMovementProperties()
  end
end
L0_8273.OnPropertyChange = L1_8274
L0_8273 = VolumeObject
function L1_8274(A0_8288, A1_8289)
  A1_8289.bHasObject = A0_8288:IsSlotValid(0)
  if A1_8289.bHasObject then
  end
end
L0_8273.OnSave = L1_8274
L0_8273 = VolumeObject
function L1_8274(A0_8290, A1_8291)
  if A1_8291.bHasObject and not A0_8290:IsSlotValid(0) then
    A0_8290:Create()
  elseif not A1_8291.bHasObject and A0_8290:IsSlotValid(0) then
    A0_8290:Delete()
  end
end
L0_8273.OnLoad = L1_8274
L0_8273 = VolumeObject
function L1_8274(A0_8292)
  A0_8292:Delete()
end
L0_8273.Event_Hide = L1_8274
L0_8273 = VolumeObject
function L1_8274(A0_8293)
  A0_8293:Create()
end
L0_8273.Event_Show = L1_8274
L0_8273 = VolumeObject
L1_8274 = {}
L2_8275 = {}
L3_8276 = {
  VolumeObject.Event_Hide,
  "bool"
}
L2_8275.Hide = L3_8276
L3_8276 = {
  VolumeObject.Event_Show,
  "bool"
}
L2_8275.Show = L3_8276
L1_8274.Inputs = L2_8275
L2_8275 = {}
L2_8275.Hide = "bool"
L2_8275.Show = "bool"
L1_8274.Outputs = L2_8275
L0_8273.FlowEvents = L1_8274
