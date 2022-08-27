local L0_7768, L1_7769, L2_7770, L3_7771
L0_7768 = {}
L1_7769 = {}
L1_7769.bActive = 1
L1_7769.Strength = 10
L1_7769.Radius = 10
L1_7769.bSpline = 0
L0_7768.Properties = L1_7769
L1_7769 = {}
L0_7768.Server = L1_7769
L1_7769 = {}
L0_7768.Client = L1_7769
L1_7769 = {}
L2_7770 = {}
L1_7769.Area = L2_7770
L0_7768._PhysTableCyl = L1_7769
L1_7769 = {}
L2_7770 = {}
L1_7769.Area = L2_7770
L0_7768._PhysTableSph = L1_7769
L1_7769 = {}
L2_7770 = {}
L3_7771 = {}
L2_7770.points = L3_7771
L1_7769.Area = L2_7770
L0_7768._PhysTableSpl = L1_7769
L1_7769 = {}
L0_7768._Points = L1_7769
L1_7769 = {}
L0_7768._Caps = L1_7769
L1_7769 = {}
L1_7769.Icon = "GravitySphere.bmp"
L1_7769.ShowBounds = 1
L0_7768.Editor = L1_7769
GravityValve = L0_7768
L0_7768 = GravityValve
function L1_7769(A0_7772, A1_7773)
  local L2_7774
  L2_7774 = A1_7773.bActive
  A0_7772.bActive = L2_7774
  L2_7774 = A1_7773._Points
  A0_7772._Points = L2_7774
  L2_7774 = A1_7773._Caps
  A0_7772._Caps = L2_7774
end
L0_7768.OnLoad = L1_7769
L0_7768 = GravityValve
function L1_7769(A0_7775, A1_7776)
  local L2_7777
  L2_7777 = A0_7775.bActive
  A1_7776.bActive = L2_7777
  L2_7777 = A0_7775._Points
  A1_7776._Points = L2_7777
  L2_7777 = A0_7775._Caps
  A1_7776._Caps = L2_7777
end
L0_7768.OnSave = L1_7769
L0_7768 = GravityValve
function L1_7769(A0_7778)
  A0_7778:SetActive(A0_7778.Properties.bActive)
end
L0_7768.OnSpawn = L1_7769
L0_7768 = GravityValve
function L1_7769(A0_7779)
  local L1_7780
  L1_7780 = A0_7779._Caps
  while table.getn(L1_7780) > 0 do
    System.RemoveEntity(L1_7780[1])
    table.remove(L1_7780, 1)
  end
end
L0_7768.OnDestroy = L1_7769
L0_7768 = GravityValve
function L1_7769(A0_7781)
  A0_7781:NeedSetup()
end
L0_7768.OnPropertyChange = L1_7769
L0_7768 = GravityValve
function L1_7769(A0_7782)
  A0_7782:NeedSetup()
end
L0_7768.OnReset = L1_7769
L0_7768 = GravityValve
function L1_7769(A0_7783)
  local L1_7784, L2_7785, L3_7786, L4_7787, L5_7788, L6_7789, L7_7790, L8_7791, L9_7792
  L1_7784 = 50
  L3_7786 = A0_7783
  L2_7785 = A0_7783.GetName
  L2_7785 = L2_7785(L3_7786)
  L3_7786 = "_p"
  L2_7785 = L2_7785 .. L3_7786
  L3_7786 = nil
  L4_7787 = 1
  L5_7788 = A0_7783._Points
  L5_7788[1] = A0_7783
  for L9_7792 = 1, L1_7784 do
    L3_7786 = L2_7785 .. tostring(L9_7792)
    if not System.GetEntityByName(L3_7786) then
      break
    end
    L5_7788[L9_7792 + 1] = System.GetEntityByName(L3_7786)
    L4_7787 = L9_7792 + 1
    Log("npoints " .. L4_7787)
  end
  while true do
    if L4_7787 < L6_7789 then
      L6_7789(L7_7790)
      L6_7789(L7_7790)
    end
  end
  for L9_7792 = 1, L7_7790(L8_7791) do
    Log(".. " .. L5_7788[L9_7792]:GetName())
  end
end
L0_7768.FillPoints = L1_7769
L0_7768 = GravityValve
function L1_7769(A0_7793, A1_7794, A2_7795, A3_7796, A4_7797)
  local L5_7798, L6_7799
  L5_7798 = A0_7793._PhysTableCyl
  L5_7798 = L5_7798.Area
  L6_7799 = DifferenceVectors
  L6_7799 = L6_7799(A2_7795, A1_7794)
  L5_7798.type = AREA_CYLINDER
  L5_7798.radius = A3_7796
  L5_7798.height = LengthVector(L6_7799) * 0.5
  L5_7798.center = ScaleVector(SumVectors(A2_7795, A1_7794), 0.5)
  L5_7798.axis = NormalizeVector(L6_7799)
  L5_7798.gravity = ScaleVector(L5_7798.axis, A4_7797)
  L5_7798.uniform = 1
  L5_7798.falloff = 0
  return L5_7798
end
L0_7768.CreateCylinderArea = L1_7769
L0_7768 = GravityValve
function L1_7769(A0_7800, A1_7801, A2_7802)
  local L3_7803
  L3_7803 = A0_7800._PhysTableSph
  L3_7803 = L3_7803.Area
  L3_7803.type = AREA_SPHERE
  L3_7803.radius = A1_7801
  L3_7803.uniform = 1
  L3_7803.falloff = 0
  L3_7803.gravity = ScaleVector(A2_7802, 8)
  return L3_7803
end
L0_7768.CreateSphereArea = L1_7769
L0_7768 = GravityValve
function L1_7769(A0_7804)
  A0_7804.bNeedSetup = 1
  A0_7804:Activate(1)
end
L0_7768.NeedSetup = L1_7769
L0_7768 = GravityValve
function L1_7769(A0_7805, A1_7806)
  A0_7805:NeedSetup()
end
L0_7768.OnChange = L1_7769
L0_7768 = GravityValve
function L1_7769(A0_7807)
  local L1_7808
  L1_7808 = A0_7807.bNeedSetup
  if L1_7808 then
    L1_7808 = A0_7807.bActive
    A0_7807:SetActive(0)
    A0_7807:SetActive(L1_7808)
    A0_7807.bNeedSetup = nil
    A0_7807:Activate(0)
  end
end
L0_7768.OnUpdate = L1_7769
L0_7768 = GravityValve
L0_7768 = L0_7768.Server
L1_7769 = GravityValve
L1_7769 = L1_7769.OnUpdate
L0_7768.OnUpdate = L1_7769
L0_7768 = GravityValve
L0_7768 = L0_7768.Client
L1_7769 = GravityValve
L1_7769 = L1_7769.OnUpdate
L0_7768.OnUpdate = L1_7769
L0_7768 = GravityValve
function L1_7769(A0_7809, A1_7810)
  local L2_7811, L3_7812, L4_7813, L5_7814, L6_7815
  L2_7811 = A0_7809.bActive
  if A1_7810 == L2_7811 then
    return
  end
  L3_7812 = A0_7809
  L2_7811 = A0_7809.FillPoints
  L2_7811(L3_7812)
  L2_7811, L3_7812 = nil, nil
  L4_7813 = A0_7809._Points
  L5_7814 = A0_7809._Caps
  L3_7812 = L6_7815
  if A1_7810 == 1 then
    if L6_7815 == 1 then
      for _FORV_11_ = 1, L3_7812 do
        A0_7809._PhysTableSpl.Area.points[_FORV_11_] = {
          x = 0,
          y = 0,
          z = 0
        }
        L4_7813[_FORV_11_]:GetWorldPos(A0_7809._PhysTableSpl.Area.points[_FORV_11_])
      end
      L6_7815.type = _FOR_
      L6_7815.radius = A0_7809.Properties.Radius
      L6_7815.falloff = 0
      L6_7815.gravity = {
        x = 0,
        y = 0,
        z = A0_7809.Properties.Strength
      }
      L6_7815.damping = 2
      A0_7809:Physicalize(0, PE_AREA, A0_7809._PhysTableSpl)
      A0_7809:SetPhysicParams(PHYSICPARAM_FOREIGNDATA, {foreignData = ZEROG_AREA_ID})
    else
      L6_7815.class = "GravityStreamCap"
      L6_7815.orientation = {
        x = 1,
        y = 0,
        z = 0
      }
      for _FORV_10_ = 2, L3_7812 do
        A0_7809:CreateCylinderArea(L4_7813[_FORV_10_ - 1]:GetPos(), L4_7813[_FORV_10_]:GetPos(), A0_7809.Properties.Radius, A0_7809.Properties.Strength)
        L4_7813[_FORV_10_]:Physicalize(0, PE_AREA, A0_7809._PhysTableCyl)
        L4_7813[_FORV_10_]:SetPhysicParams(PHYSICPARAM_FOREIGNDATA, {foreignData = ZEROG_AREA_ID})
        if _FORV_10_ > 2 then
          L6_7815.position = L4_7813[_FORV_10_ - 1]:GetPos()
          table.insert(L5_7814, System.SpawnEntity(L6_7815).id)
          A0_7809:CreateSphereArea(A0_7809.Properties.Radius, A0_7809._PhysTableCyl.Area.gravity)
          System.SpawnEntity(L6_7815):Physicalize(0, PE_AREA, A0_7809._PhysTableSph)
          System.SpawnEntity(L6_7815):SetPhysicParams(PHYSICPARAM_FOREIGNDATA, {foreignData = ZEROG_AREA_ID})
        end
      end
    end
  elseif A1_7810 == 0 then
    if L6_7815 then
      L6_7815(A0_7809)
      for _FORV_9_ = 2, L3_7812 do
        L4_7813[_FORV_9_]:DestroyPhysics()
      end
      L6_7815(_FOR_)
    end
  end
  A0_7809.bActive = A1_7810
end
L0_7768.SetActive = L1_7769
L0_7768 = GravityValve
function L1_7769(A0_7816)
  A0_7816:SetActive(1)
end
L0_7768.Event_Enable = L1_7769
L0_7768 = GravityValve
function L1_7769(A0_7817)
  A0_7817:SetActive(0)
end
L0_7768.Event_Disable = L1_7769
L0_7768 = GravityValve
L1_7769 = {}
L2_7770 = {}
L3_7771 = {
  GravityValve.Event_Disable,
  "bool"
}
L2_7770.Disable = L3_7771
L3_7771 = {
  GravityValve.Event_Enable,
  "bool"
}
L2_7770.Enable = L3_7771
L1_7769.Inputs = L2_7770
L2_7770 = {}
L2_7770.Disable = "bool"
L2_7770.Enable = "bool"
L1_7769.Outputs = L2_7770
L0_7768.FlowEvents = L1_7769
