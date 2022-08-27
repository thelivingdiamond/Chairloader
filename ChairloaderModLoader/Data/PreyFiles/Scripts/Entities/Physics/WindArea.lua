local L0_7973, L1_7974, L2_7975, L3_7976
L0_7973 = {}
L1_7974 = {}
L1_7974.bActive = 1
L2_7975 = {}
L2_7975.x = 10
L2_7975.y = 10
L2_7975.z = 10
L1_7974.Size = L2_7975
L1_7974.bEllipsoidal = 0
L1_7974.FalloffInner = 0
L2_7975 = {}
L2_7975.x = 0
L2_7975.y = 0
L2_7975.z = 0
L1_7974.Dir = L2_7975
L1_7974.Speed = 20
L1_7974.AirResistance = 1
L1_7974.AirDensity = 1
L0_7973.Properties = L1_7974
L1_7974 = {}
L1_7974.Icon = "Tornado.bmp"
L0_7973.Editor = L1_7974
L1_7974 = {}
L2_7975 = {}
L1_7974.Area = L2_7975
L0_7973._PhysTable = L1_7974
WindArea = L0_7973
L0_7973 = WindArea
function L1_7974(A0_7977, A1_7978)
  A0_7977.bActive = A1_7978.bActive
end
L0_7973.OnLoad = L1_7974
L0_7973 = WindArea
function L1_7974(A0_7979, A1_7980)
  A1_7980.bActive = A0_7979.bActive
end
L0_7973.OnSave = L1_7974
L0_7973 = WindArea
function L1_7974(A0_7981)
  A0_7981.bActive = A0_7981.Properties.bActive
  if A0_7981.bActive == 1 then
    A0_7981:PhysicalizeThis()
  end
end
L0_7973.OnInit = L1_7974
L0_7973 = WindArea
function L1_7974(A0_7982)
  A0_7982.bActive = A0_7982.Properties.bActive
  A0_7982:PhysicalizeThis()
end
L0_7973.OnPropertyChange = L1_7974
L0_7973 = WindArea
function L1_7974(A0_7983)
  local L1_7984
end
L0_7973.OnReset = L1_7974
L0_7973 = WindArea
function L1_7974(A0_7985)
  if A0_7985.bActive == 1 then
    if A0_7985.Properties.bEllipsoidal == 1 then
      A0_7985._PhysTable.Area.type = AREA_SPHERE
      A0_7985._PhysTable.Area.radius = LengthVector(A0_7985.Properties.Size) * 0.577
    else
      A0_7985._PhysTable.Area.type = AREA_BOX
    end
    A0_7985._PhysTable.Area.box_max = A0_7985.Properties.Size
    A0_7985._PhysTable.Area.box_min = {
      x = -A0_7985._PhysTable.Area.box_max.x,
      y = -A0_7985._PhysTable.Area.box_max.y,
      z = -A0_7985._PhysTable.Area.box_max.z
    }
    if A0_7985.Properties.bEllipsoidal == 1 or 1 > A0_7985.Properties.FalloffInner then
      A0_7985._PhysTable.Area.falloffInner = A0_7985.Properties.FalloffInner
    else
      A0_7985._PhysTable.Area.falloffInner = -1
    end
    if A0_7985.Properties.Dir.x == 0 and A0_7985.Properties.Dir.y == 0 and A0_7985.Properties.Dir.z == 0 then
      A0_7985._PhysTable.Area.uniform = 0
      A0_7985._PhysTable.Area.wind = {
        x = 0,
        y = 0,
        z = A0_7985.Properties.Speed
      }
    else
      A0_7985._PhysTable.Area.uniform = 2
      A0_7985._PhysTable.Area.wind = {
        x = A0_7985.Properties.Dir.x * A0_7985.Properties.Speed,
        y = A0_7985.Properties.Dir.y * A0_7985.Properties.Speed,
        z = A0_7985.Properties.Dir.z * A0_7985.Properties.Speed
      }
    end
    A0_7985._PhysTable.Area.water_damping = 0
    A0_7985._PhysTable.Area.resistance = A0_7985.Properties.AirResistance
    A0_7985._PhysTable.Area.density = A0_7985.Properties.AirDensity
    A0_7985:Physicalize(0, PE_AREA, A0_7985._PhysTable)
    A0_7985:AwakeEnvironment()
  else
    A0_7985:DestroyPhysics()
  end
end
L0_7973.PhysicalizeThis = L1_7974
L0_7973 = WindArea
function L1_7974(A0_7986)
  if A0_7986.bActive ~= 1 then
    A0_7986.bActive = 1
    A0_7986:PhysicalizeThis()
  end
end
L0_7973.Event_Activate = L1_7974
L0_7973 = WindArea
function L1_7974(A0_7987)
  if A0_7987.bActive ~= 0 then
    A0_7987.bActive = 0
    A0_7987:PhysicalizeThis()
  end
end
L0_7973.Event_Deactivate = L1_7974
L0_7973 = WindArea
function L1_7974(A0_7988, A1_7989, A2_7990)
  A0_7988.Properties.Speed = A2_7990
  A0_7988:OnPropertyChange()
end
L0_7973.Event_Speed = L1_7974
L0_7973 = WindArea
L1_7974 = {}
L2_7975 = {}
L3_7976 = {
  WindArea.Event_Deactivate,
  "bool"
}
L2_7975.Deactivate = L3_7976
L3_7976 = {
  WindArea.Event_Activate,
  "bool"
}
L2_7975.Activate = L3_7976
L3_7976 = {
  WindArea.Event_Speed,
  "float"
}
L2_7975.Speed = L3_7976
L1_7974.Inputs = L2_7975
L2_7975 = {}
L2_7975.Deactivate = "bool"
L2_7975.Activate = "bool"
L1_7974.Outputs = L2_7975
L0_7973.FlowEvents = L1_7974
