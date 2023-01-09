Script.ReloadEntityScript("GravityValve")
GravityStream = {
  Editor = {
    Icon = "GravitySphere.bmp",
    IconOnTop = 1
  }
}
function GravityStream.OnLoad(A0_7751, A1_7752)
  A0_7751.oldPos = A1_7752.oldPos
end
function GravityStream.OnSave(A0_7753, A1_7754)
  A1_7754.oldPos = A0_7753.oldPos
end
function GravityStream.GetValve(A0_7755)
  local L1_7756, L2_7757, L3_7758, L4_7759, L5_7760, L6_7761
  L2_7757 = A0_7755
  L1_7756 = A0_7755.GetName
  L1_7756 = L1_7756(L2_7757)
  L2_7757 = string
  L2_7757 = L2_7757.find
  L3_7758 = L1_7756
  L4_7759 = "_[pP]"
  L5_7760 = 1
  L3_7758 = L2_7757(L3_7758, L4_7759, L5_7760)
  if not L2_7757 then
    L4_7759 = LogWarning
    L5_7760 = "Incorrectly formatted name - should be GravityValveName_p?; GravityValveName is the name of the associated valve, and ? is an integer indice."
    L4_7759(L5_7760)
    return
  end
  L4_7759 = tonumber
  L5_7760 = string
  L5_7760 = L5_7760.sub
  L6_7761 = L1_7756
  L6_7761 = L5_7760(L6_7761, L3_7758 + 1)
  L4_7759 = L4_7759(L5_7760, L6_7761, L5_7760(L6_7761, L3_7758 + 1))
  if not L4_7759 then
    return
  end
  L5_7760 = System
  L5_7760 = L5_7760.GetEntityByName
  L6_7761 = string
  L6_7761 = L6_7761.sub
  L6_7761 = L6_7761(L1_7756, 1, L2_7757 - 1)
  L5_7760 = L5_7760(L6_7761, L6_7761(L1_7756, 1, L2_7757 - 1))
  L6_7761 = L5_7760
  return L6_7761, L4_7759
end
function GravityStream.OnUpdate(A0_7762)
  local L1_7763, L2_7764, L3_7765, L4_7766
  L2_7764 = A0_7762
  L1_7763 = A0_7762.GetPos
  L1_7763 = L1_7763(L2_7764)
  L2_7764 = A0_7762.oldPos
  if L2_7764 then
    L2_7764 = LengthVector
    L3_7765 = DifferenceVectors
    L4_7766 = L1_7763
    L4_7766 = L3_7765(L4_7766, A0_7762.oldPos)
    L2_7764 = L2_7764(L3_7765, L4_7766, L3_7765(L4_7766, A0_7762.oldPos))
  elseif L2_7764 > 1.0E-4 then
    A0_7762.oldPos = L1_7763
    L3_7765 = A0_7762
    L2_7764 = A0_7762.GetValve
    L3_7765 = L2_7764(L3_7765)
    if L2_7764 then
      L4_7766 = L2_7764.OnChange
      L4_7766(L2_7764, L3_7765)
    end
    return
  end
  L3_7765 = A0_7762
  L2_7764 = A0_7762.GetName
  L2_7764 = L2_7764(L3_7765)
  L3_7765 = A0_7762._Name
  L3_7765 = not L3_7765
  if L3_7765 == L2_7764 then
    A0_7762._Name = L2_7764
    L4_7766 = A0_7762
    L3_7765 = A0_7762.GetValve
    L4_7766 = L3_7765(L4_7766)
    if L3_7765 then
      L3_7765:OnChange(L4_7766)
    end
  end
end
GravityStream.OnSpawn = GravityStream.OnUpdate
GravityStream.OnDestroy = GravityStream.OnUpdate
GravityStream.OnReset = GravityStream.OnUpdate
GravityStream.OnPropertyChange = GravityStream.OnUpdate
