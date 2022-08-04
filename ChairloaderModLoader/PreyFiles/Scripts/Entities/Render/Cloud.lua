local L0_8025, L1_8026, L2_8027, L3_8028
L0_8025 = {}
L0_8025.type = "Cloud"
L0_8025.ENTITY_DETAIL_ID = 1
L1_8026 = {}
L1_8026.file_CloudFile = "Libs/Clouds/Default.xml"
L1_8026.fScale = 1
L2_8027 = {}
L2_8027.bAutoMove = 0
L3_8028 = {}
L3_8028.x = 0
L3_8028.y = 0
L3_8028.z = 0
L2_8027.vector_Speed = L3_8028
L3_8028 = {}
L3_8028.x = 2000
L3_8028.y = 2000
L3_8028.z = 2000
L2_8027.vector_SpaceLoopBox = L3_8028
L2_8027.fFadeDistance = 0
L1_8026.Movement = L2_8027
L0_8025.Properties = L1_8026
L1_8026 = {}
L1_8026.Model = "Editor/Objects/Particles.cgf"
L1_8026.Icon = "Clouds.bmp"
L0_8025.Editor = L1_8026
Cloud = L0_8025
L0_8025 = Cloud
function L1_8026(A0_8029)
  A0_8029:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
end
L0_8025.OnSpawn = L1_8026
L0_8025 = Cloud
function L1_8026(A0_8030)
  A0_8030:NetPresent(0)
  A0_8030:CreateCloud()
end
L0_8025.OnInit = L1_8026
L0_8025 = Cloud
function L1_8026(A0_8031)
  local L1_8032
  L1_8032 = A0_8031.Properties
  L1_8032 = L1_8032.Movement
  A0_8031:SetCloudMovementProperties(0, L1_8032)
end
L0_8025.SetMovementProperties = L1_8026
L0_8025 = Cloud
function L1_8026(A0_8033)
  local L1_8034
end
L0_8025.OnShutDown = L1_8026
L0_8025 = Cloud
function L1_8026(A0_8035)
  A0_8035:LoadCloud(0, A0_8035.Properties.file_CloudFile)
  A0_8035:SetMovementProperties()
end
L0_8025.CreateCloud = L1_8026
L0_8025 = Cloud
function L1_8026(A0_8036)
  A0_8036:FreeSlot(0)
end
L0_8025.DeleteCloud = L1_8026
L0_8025 = Cloud
function L1_8026(A0_8037)
  if not A0_8037:IsSlotValid(0) then
    A0_8037:CreateCloud()
  end
end
L0_8025.OnReset = L1_8026
L0_8025 = Cloud
function L1_8026(A0_8038)
  local L1_8039
  L1_8039 = A0_8038.Properties
  if L1_8039.file_CloudFile ~= A0_8038._CloudFile then
    A0_8038._CloudFile = L1_8039.file_CloudFile
    A0_8038:CreateCloud()
  else
    A0_8038:SetMovementProperties()
  end
end
L0_8025.OnPropertyChange = L1_8026
L0_8025 = Cloud
function L1_8026(A0_8040)
  A0_8040:FreeSlot(0)
end
L0_8025.DeleteCloud = L1_8026
L0_8025 = Cloud
function L1_8026(A0_8041, A1_8042)
  A1_8042.bHasCloud = A0_8041:IsSlotValid(0)
  if A1_8042.bHasCloud then
  end
end
L0_8025.OnSave = L1_8026
L0_8025 = Cloud
function L1_8026(A0_8043, A1_8044)
  if A1_8044.bHasCloud and not A0_8043:IsSlotValid(0) then
    A0_8043:CreateCloud()
  elseif not A1_8044.bHasCloud and A0_8043:IsSlotValid(0) then
    A0_8043:DeleteCloud()
  end
end
L0_8025.OnLoad = L1_8026
L0_8025 = Cloud
function L1_8026(A0_8045)
  A0_8045:DeleteCloud()
end
L0_8025.Event_Hide = L1_8026
L0_8025 = Cloud
function L1_8026(A0_8046)
  A0_8046:CreateCloud()
end
L0_8025.Event_Show = L1_8026
L0_8025 = Cloud
L1_8026 = {}
L2_8027 = {}
L3_8028 = {
  Cloud.Event_Hide,
  "bool"
}
L2_8027.Hide = L3_8028
L3_8028 = {
  Cloud.Event_Show,
  "bool"
}
L2_8027.Show = L3_8028
L1_8026.Inputs = L2_8027
L2_8027 = {}
L2_8027.Hide = "bool"
L2_8027.Show = "bool"
L1_8026.Outputs = L2_8027
L0_8025.FlowEvents = L1_8026
