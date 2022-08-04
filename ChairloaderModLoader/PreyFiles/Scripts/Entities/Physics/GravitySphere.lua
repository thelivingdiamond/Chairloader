local L0_7737, L1_7738, L2_7739, L3_7740
L0_7737 = {}
L1_7738 = {}
L1_7738.bActive = 1
L1_7738.Radius = 10
L1_7738.bUniform = 1
L1_7738.bEllipsoidal = 1
L1_7738.FalloffInner = 0
L2_7739 = {}
L2_7739.x = 0
L2_7739.y = 0
L2_7739.z = 0
L1_7738.Gravity = L2_7739
L1_7738.Damping = 0
L0_7737.Properties = L1_7738
L1_7738 = {}
L2_7739 = {}
L1_7738.Area = L2_7739
L0_7737._PhysTable = L1_7738
L1_7738 = {}
L1_7738.Icon = "GravitySphere.bmp"
L1_7738.IconOnTop = 0
L0_7737.Editor = L1_7738
GravitySphere = L0_7737
L0_7737 = GravitySphere
function L1_7738(A0_7741, A1_7742)
  A0_7741.bActive = A1_7742.bActive
  A0_7741:PhysicalizeThis()
end
L0_7737.OnLoad = L1_7738
L0_7737 = GravitySphere
function L1_7738(A0_7743, A1_7744)
  A1_7744.bActive = A0_7743.bActive
end
L0_7737.OnSave = L1_7738
L0_7737 = GravitySphere
function L1_7738(A0_7745)
  A0_7745:OnReset()
end
L0_7737.OnInit = L1_7738
L0_7737 = GravitySphere
function L1_7738(A0_7746)
  A0_7746:DestroyPhysics()
  A0_7746.bActive = A0_7746.Properties.bActive
  if A0_7746.bActive ~= 0 then
    A0_7746:PhysicalizeThis()
  end
end
L0_7737.OnPropertyChange = L1_7738
L0_7737 = GravitySphere
function L1_7738(A0_7747)
  A0_7747.bActive = A0_7747.Properties.bActive
  A0_7747:PhysicalizeThis()
end
L0_7737.OnReset = L1_7738
L0_7737 = GravitySphere
function L1_7738(A0_7748)
  if A0_7748.bActive == 1 then
    if A0_7748.Properties.bEllipsoidal ~= 0 then
      A0_7748._PhysTable.Area.type = AREA_SPHERE
    else
      A0_7748._PhysTable.Area.type = AREA_BOX
      A0_7748._PhysTable.Area.box_min = {
        x = -A0_7748.Properties.Radius,
        y = -A0_7748.Properties.Radius,
        z = -A0_7748.Properties.Radius
      }
      A0_7748._PhysTable.Area.box_max = {
        x = A0_7748.Properties.Radius,
        y = A0_7748.Properties.Radius,
        z = A0_7748.Properties.Radius
      }
    end
    A0_7748._PhysTable.Area.radius = A0_7748.Properties.Radius
    A0_7748._PhysTable.Area.uniform = A0_7748.Properties.bUniform
    A0_7748._PhysTable.Area.falloffInner = A0_7748.Properties.FalloffInner
    A0_7748._PhysTable.Area.gravity = A0_7748.Properties.Gravity
    A0_7748._PhysTable.Area.damping = A0_7748.Properties.Damping
    A0_7748:Physicalize(0, PE_AREA, A0_7748._PhysTable)
    A0_7748:SetPhysicParams(PHYSICPARAM_FOREIGNDATA, {foreignData = ZEROG_AREA_ID})
  else
    A0_7748:DestroyPhysics()
  end
end
L0_7737.PhysicalizeThis = L1_7738
L0_7737 = GravitySphere
function L1_7738(A0_7749)
  if A0_7749.bActive ~= 1 then
    A0_7749.bActive = 1
    A0_7749:PhysicalizeThis()
    BroadcastEvent(A0_7749, "Activate")
  end
end
L0_7737.Event_Activate = L1_7738
L0_7737 = GravitySphere
function L1_7738(A0_7750)
  if A0_7750.bActive ~= 0 then
    A0_7750.bActive = 0
    A0_7750:PhysicalizeThis()
    BroadcastEvent(A0_7750, "Deactivate")
  end
end
L0_7737.Event_Deactivate = L1_7738
L0_7737 = GravitySphere
L1_7738 = {}
L2_7739 = {}
L3_7740 = {
  GravitySphere.Event_Deactivate,
  "bool"
}
L2_7739.Deactivate = L3_7740
L3_7740 = {
  GravitySphere.Event_Activate,
  "bool"
}
L2_7739.Activate = L3_7740
L1_7738.Inputs = L2_7739
L2_7739 = {}
L2_7739.Deactivate = "bool"
L2_7739.Activate = "bool"
L1_7738.Outputs = L2_7739
L0_7737.FlowEvents = L1_7738
