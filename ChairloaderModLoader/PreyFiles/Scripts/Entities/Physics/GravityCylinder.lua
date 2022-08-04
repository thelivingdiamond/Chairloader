local L0_7721, L1_7722, L2_7723, L3_7724
L0_7721 = {}
L1_7722 = {}
L1_7722.bActive = 1
L1_7722.Radius = 2
L1_7722.Height = 1
L2_7723 = {}
L2_7723.x = 0
L2_7723.y = 0
L2_7723.z = 1
L1_7722.Axis = L2_7723
L2_7723 = {}
L2_7723.x = 0
L2_7723.y = 0
L2_7723.z = 0
L1_7722.Gravity = L2_7723
L2_7723 = {}
L2_7723.x = 0
L2_7723.y = 0
L2_7723.z = 0
L1_7722.vector_ImpulseActivate = L2_7723
L2_7723 = {}
L2_7723.x = 0
L2_7723.y = 0
L2_7723.z = 0
L1_7722.vector_ImpulseDeactivate = L2_7723
L0_7721.Properties = L1_7722
L1_7722 = {}
L1_7722.Icon = "GravitySphere.bmp"
L1_7722.ShowBounds = 1
L0_7721.Editor = L1_7722
L1_7722 = {}
L2_7723 = {}
L1_7722.Area = L2_7723
L0_7721._PhysTable = L1_7722
GravityCylinder = L0_7721
L0_7721 = GravityCylinder
function L1_7722(A0_7725, A1_7726)
  A0_7725.bActive = A1_7726.bActive
  if A0_7725.bActive == 1 then
    A0_7725:PhysicalizeThis()
  else
    A0_7725:DestroyPhysics()
  end
end
L0_7721.OnLoad = L1_7722
L0_7721 = GravityCylinder
function L1_7722(A0_7727, A1_7728)
  A1_7728.bActive = A0_7727.bActive
end
L0_7721.OnSave = L1_7722
L0_7721 = GravityCylinder
function L1_7722(A0_7729)
  A0_7729.bActive = A0_7729.Properties.bActive
  if A0_7729.bActive == 1 then
    A0_7729:PhysicalizeThis()
  end
end
L0_7721.OnInit = L1_7722
L0_7721 = GravityCylinder
function L1_7722(A0_7730)
  if A0_7730.bActive ~= A0_7730.Properties.bActive then
    A0_7730.bActive = A0_7730.Properties.bActive
  end
  if A0_7730.bActive == 1 then
    A0_7730:PhysicalizeThis()
  else
    A0_7730:DestroyPhysics()
  end
end
L0_7721.OnPropertyChange = L1_7722
L0_7721 = GravityCylinder
function L1_7722(A0_7731)
  A0_7731:OnInit()
end
L0_7721.OnReset = L1_7722
L0_7721 = GravityCylinder
function L1_7722(A0_7732)
  local L1_7733, L2_7734
  L1_7733 = A0_7732.bActive
  if L1_7733 == 1 then
    L1_7733 = A0_7732.Properties
    L2_7734 = A0_7732._PhysTable
    L2_7734 = L2_7734.Area
    L2_7734.type = AREA_CYLINDER
    L2_7734.radius = L1_7733.Radius
    L2_7734.height = L1_7733.Height
    L2_7734.axis = L1_7733.Axis
    L2_7734.gravity = L1_7733.Gravity
    L2_7734.center = A0_7732:GetPos()
    A0_7732:Physicalize(0, PE_AREA, A0_7732._PhysTable)
  end
end
L0_7721.PhysicalizeThis = L1_7722
L0_7721 = GravityCylinder
function L1_7722(A0_7735)
  if A0_7735.bActive ~= 1 then
    A0_7735.bActive = 1
    A0_7735:PhysicalizeThis()
    Game.ImpulseEnvironment(A0_7735.id, A0_7735.Properties.vector_ImpulseActivate)
  end
end
L0_7721.Event_Activate = L1_7722
L0_7721 = GravityCylinder
function L1_7722(A0_7736)
  if A0_7736.bActive ~= 0 then
    Game.ImpulseEnvironment(A0_7736.id, A0_7736.Properties.vector_ImpulseActivate)
    A0_7736.bActive = 0
    A0_7736:DestroyPhysics()
  end
end
L0_7721.Event_Deactivate = L1_7722
L0_7721 = GravityCylinder
L1_7722 = {}
L2_7723 = {}
L3_7724 = {
  GravityCylinder.Event_Deactivate,
  "bool"
}
L2_7723.Deactivate = L3_7724
L3_7724 = {
  GravityCylinder.Event_Activate,
  "bool"
}
L2_7723.Activate = L3_7724
L1_7722.Inputs = L2_7723
L2_7723 = {}
L2_7723.Deactivate = "bool"
L2_7723.Activate = "bool"
L1_7722.Outputs = L2_7723
L0_7721.FlowEvents = L1_7722
