local L0_6662, L1_6663, L2_6664, L3_6665
L0_6662 = {}
L1_6663 = {}
L1_6663.material_Material = ""
L1_6663.fSnapDistance = 0
L1_6663.fSize = 1
L1_6663.nLifeTime = 180
L1_6663.bPlaced = 0
L1_6663.bPlaceTransparent = 0
L0_6662.Properties = L1_6663
L1_6663 = {}
L1_6663.Icon = "Decal.bmp"
L0_6662.Editor = L1_6663
DecalPlacer = L0_6662
L0_6662 = DecalPlacer
function L1_6663(A0_6666)
  A0_6666:OnReset()
end
L0_6662.OnPropertyChange = L1_6663
L0_6662 = DecalPlacer
function L1_6663(A0_6667)
  if tonumber(A0_6667.Properties.bPlaced) ~= 0 then
    A0_6667:Event_SpawnDecal()
  else
    A0_6667:Event_DestroyDecal()
  end
end
L0_6662.OnReset = L1_6663
L0_6662 = DecalPlacer
function L1_6663(A0_6668)
  A0_6668.hit = {}
  A0_6668.m_decalId = -1
  A0_6668:OnReset()
end
L0_6662.OnInit = L1_6663
L0_6662 = DecalPlacer
function L1_6663(A0_6669)
  local L1_6670, L2_6671, L3_6672, L4_6673, L5_6674, L6_6675, L7_6676, L8_6677, L9_6678, L10_6679, L11_6680, L12_6681
  L1_6670 = A0_6669.m_decalId
  if L1_6670 >= 0 then
    L1_6670 = Particle
    L1_6670 = L1_6670.DestroyDecal
    L2_6671 = A0_6669.m_decalId
    L1_6670(L2_6671)
    A0_6669.m_decalId = -1
  end
  L1_6670 = A0_6669.Properties
  L1_6670 = L1_6670.material_Material
  L2_6671 = A0_6669.Properties
  L2_6671 = L2_6671.fSize
  L3_6672 = A0_6669.Properties
  L3_6672 = L3_6672.nLifeTime
  L4_6673 = A0_6669.Properties
  L4_6673 = L4_6673.fSnapDistance
  L6_6675 = A0_6669
  L5_6674 = A0_6669.GetLocalAngles
  L5_6674 = L5_6674(L6_6675)
  L5_6674 = L5_6674.z
  L7_6676 = A0_6669
  L6_6675 = A0_6669.GetDirectionVector
  L8_6677 = 2
  L6_6675 = L6_6675(L7_6676, L8_6677)
  L7_6676 = A0_6669.Properties
  L7_6676 = L7_6676.bPlaceTransparent
  L8_6677, L9_6678 = nil, nil
  L10_6679 = false
  if L4_6673 > 0 then
    L11_6680 = g_Vectors
    L11_6680 = L11_6680.temp_v3
    L12_6681 = L6_6675.x
    L12_6681 = -L12_6681
    L12_6681 = L12_6681 * L4_6673
    L11_6680.x = L12_6681
    L12_6681 = L6_6675.y
    L12_6681 = -L12_6681
    L12_6681 = L12_6681 * L4_6673
    L11_6680.y = L12_6681
    L12_6681 = L6_6675.z
    L12_6681 = -L12_6681
    L12_6681 = L12_6681 * L4_6673
    L11_6680.z = L12_6681
    L12_6681 = A0_6669.hit
    if 0 < Physics.RayWorldIntersection(A0_6669:GetWorldPos(g_Vectors.temp_v2), L11_6680, 1, ent_all, nil, nil, L12_6681) then
      A0_6669.m_decalId = Particle.CreateMatDecal(L12_6681[1].pos, L12_6681[1].normal, L2_6671, L3_6672, L1_6670, L5_6674, L6_6675, L12_6681[1].entity and L12_6681[1].entity.id, L12_6681[1].renderNode, nil, nil, nil, L7_6676)
      L10_6679 = true
    end
  end
  if not L10_6679 then
    L8_6677 = L6_6675
    L12_6681 = A0_6669
    L11_6680 = A0_6669.GetWorldPos
    L11_6680 = L11_6680(L12_6681, g_Vectors.temp_v2)
    L9_6678 = L11_6680
    L11_6680 = Particle
    L11_6680 = L11_6680.CreateMatDecal
    L12_6681 = L9_6678
    L11_6680 = L11_6680(L12_6681, L8_6677, L2_6671, L3_6672, L1_6670, L5_6674, nil, nil, nil, nil, nil, nil, L7_6676)
    A0_6669.m_decalId = L11_6680
  end
  L11_6680 = BroadcastEvent
  L12_6681 = A0_6669
  L11_6680(L12_6681, "SpawnDecal")
end
L0_6662.Event_SpawnDecal = L1_6663
L0_6662 = DecalPlacer
function L1_6663(A0_6682)
  if A0_6682.m_decalId >= 0 then
    Particle.DestroyDecal(A0_6682.m_decalId)
    A0_6682.m_decalId = -1
  end
  BroadcastEvent(A0_6682, "DestroyDecal")
end
L0_6662.Event_DestroyDecal = L1_6663
L0_6662 = DecalPlacer
function L1_6663(A0_6683, A1_6684, A2_6685)
  A0_6683.Properties.material_Material = A2_6685
  A0_6683:ActivateOutput("Material", A2_6685)
end
L0_6662.Event_Material = L1_6663
L0_6662 = DecalPlacer
L1_6663 = {}
L2_6664 = {}
L3_6665 = {
  DecalPlacer.Event_SpawnDecal,
  "bool"
}
L2_6664.SpawnDecal = L3_6665
L3_6665 = {
  DecalPlacer.Event_DestroyDecal,
  "bool"
}
L2_6664.DestroyDecal = L3_6665
L3_6665 = {
  DecalPlacer.Event_Material,
  "string"
}
L2_6664.Material = L3_6665
L1_6663.Inputs = L2_6664
L2_6664 = {}
L2_6664.SpawnDecal = "bool"
L2_6664.DestroyDecal = "bool"
L2_6664.Material = "string"
L1_6663.Outputs = L2_6664
L0_6662.FlowEvents = L1_6663
