local L0_9660
L0_9660 = Set
if L0_9660 then
  L0_9660 = Set
  L0_9660 = L0_9660.countTable
else
  L0_9660 = L0_9660 or {}
end
Set = {}
Set.countTable = L0_9660
setmetatable(Set.countTable, {__mode = "kv"})
function Set.New()
  local L1_9661
  L1_9661 = {}
  Set.countTable[L1_9661] = 0
  return L1_9661
end
function Set.SerializeValues(A0_9662)
  local L1_9663, L2_9664, L3_9665, L4_9666, L5_9667, L6_9668, L7_9669
  L1_9663 = {}
  for L5_9667, L6_9668 in L2_9664(L3_9665) do
    L7_9669 = {}
    table.insert(L7_9669, 1, L5_9667)
    table.insert(L7_9669, 2, L6_9668)
    table.insert(L1_9663, L7_9669)
  end
  return L1_9663
end
function Set.DeserializeValues(A0_9670)
  local L1_9671
  L1_9671 = Set
  L1_9671 = L1_9671.New
  L1_9671 = L1_9671()
  for _FORV_5_, _FORV_6_ in ipairs(A0_9670) do
    Set.Add(L1_9671, _FORV_6_[1], _FORV_6_[2])
  end
  return L1_9671
end
function Set.DeserializeEntities(A0_9672)
  local L1_9673, L2_9674, L3_9675, L4_9676, L5_9677, L6_9678
  L1_9673 = Set
  L1_9673 = L1_9673.New
  L1_9673 = L1_9673()
  for L5_9677, L6_9678 in L2_9674(L3_9675) do
    Set.Add(L1_9673, L6_9678)
  end
  return L1_9673
end
function Set.SerializeEntities(A0_9679)
  local L1_9680, L2_9681, L3_9682, L4_9683, L5_9684
  L1_9680 = {}
  for L5_9684, _FORV_6_ in L2_9681(L3_9682) do
    table.insert(L1_9680, L5_9684)
  end
  return L1_9680
end
function Set.DeserializeItems(A0_9685)
  local L1_9686, L2_9687, L3_9688, L4_9689, L5_9690, L6_9691
  L1_9686 = Set
  L1_9686 = L1_9686.New
  L1_9686 = L1_9686()
  for L5_9690, L6_9691 in L2_9687(L3_9688) do
    if L6_9691 then
      Set.Add(L1_9686, L6_9691)
    end
  end
  return L1_9686
end
function Set.SerializeItems(A0_9692)
  local L2_9693
  L2_9693 = {}
  for _FORV_6_, _FORV_7_ in pairs(A0_9692) do
    L2_9693[1] = _FORV_6_
  end
  return L2_9693
end
function Set.Check(A0_9694)
  if not Set.countTable[A0_9694] then
    if print then
      print(tostring(A0_9694) .. "is not registered as a Set")
    else
      System.Log(tostring(A0_9694) .. "is not registered as a Set")
    end
    System.ShowDebugger()
    Set.throwAnError.throwAnError = true
  end
end
function Set.Add(A0_9695, A1_9696, A2_9697)
  A2_9697 = A2_9697 or true
  Set.Check(A0_9695)
  if not A0_9695[A1_9696] then
    A0_9695[A1_9696] = A2_9697
    Set.countTable[A0_9695] = Set.countTable[A0_9695] + 1
    return true
  end
  return false
end
function Set.Remove(A0_9698, A1_9699)
  Set.Check(A0_9698)
  if A0_9698[A1_9699] then
    A0_9698[A1_9699] = nil
    Set.countTable[A0_9698] = Set.countTable[A0_9698] - 1
    return true
  end
  return false
end
function Set.Get(A0_9700, A1_9701)
  Set.Check(A0_9700)
  return A0_9700[A1_9701]
end
function Set.Set(A0_9702, A1_9703, A2_9704)
  A2_9704 = A2_9704 or true
  Set.Check(A0_9702)
  if not A0_9702[A1_9703] then
    A0_9702[A1_9703] = A2_9704
    Set.countTable[A0_9702] = Set.countTable[A0_9702] + 1
    return false
  else
    A0_9702[A1_9703] = A2_9704
    return true
  end
end
function Set.Size(A0_9705)
  Set.Check(A0_9705)
  return Set.countTable[A0_9705]
end
function Set.RemoveAll(A0_9706)
  Set.Check(A0_9706)
  for _FORV_4_, _FORV_5_ in pairs(A0_9706) do
    A0_9706[_FORV_4_] = nil
  end
  Set.countTable[A0_9706] = 0
end
function Set.Merge(A0_9707, A1_9708)
  local L2_9709, L3_9710, L4_9711, L5_9712, L6_9713, L7_9714
  L2_9709 = true
  L3_9710(L4_9711)
  L3_9710(L4_9711)
  for L6_9713, L7_9714 in L3_9710(L4_9711) do
    if not Set.Add(A0_9707, L6_9713, L7_9714) then
      L2_9709 = false
    end
  end
  return L2_9709
end
function Set.SanityCheck(A0_9715)
  local L1_9716, L2_9717, L3_9718, L4_9719, L5_9720, L6_9721, L7_9722, L8_9723, L9_9724
  L1_9716 = Set
  L1_9716 = L1_9716.Check
  L1_9716(L2_9717)
  L1_9716 = 0
  for L5_9720, L6_9721 in L2_9717(L3_9718) do
    L1_9716 = L1_9716 + 1
  end
  if L1_9716 ~= L2_9717 then
    L3_9718(L4_9719)
    return L3_9718
  end
  for L8_9723, L9_9724 in L5_9720(L6_9721) do
    if L3_9718 then
      if L3_9718 ~= type(L8_9723) then
        System.Log("[Set] Sanity check failed - Found indices of both types " .. L3_9718 .. " and " .. type(L8_9723))
        return false
      end
    else
    end
    if L4_9719 then
      if L4_9719 ~= type(L9_9724) then
        System.Log("[Set] Sanity check failed - Found values of both types " .. L4_9719 .. " and " .. type(L9_9724))
        return false
      end
    else
    end
  end
  return L5_9720
end
function Set.Test(A0_9725)
  local L1_9726, L2_9727
  L1_9726 = Set
  L1_9726 = L1_9726.New
  L1_9726 = L1_9726()
  L2_9727 = Set
  L2_9727 = L2_9727.New
  L2_9727 = L2_9727()
  if Set.Add(L1_9726, "key1", 1) == false then
    return false
  end
  if Set.Add(L1_9726, "key2") == false then
    return false
  end
  if Set.Add(L1_9726, "key3", 3) == false then
    return false
  end
  if Set.Add(L1_9726, "key1", 1) == true then
    return false
  end
  if Set.Remove(L1_9726, "key1") == false then
    return false
  end
  if Set.Get(L1_9726, "key2") == false then
    return false
  end
  if Set.Get(L1_9726, "key1") ~= nil then
    return false
  end
  if Set.Get(L1_9726, "key3") ~= 3 then
    return false
  end
  if Set.Size(L1_9726) ~= 2 then
    return false
  end
  Set.RemoveAll(L1_9726)
  if Set.Size(L1_9726) ~= 0 then
    return false
  end
  if Set.Add(L1_9726, "key1", 1) == false then
    return false
  end
  if Set.Set(L1_9726, "key1", 9) == false then
    return false
  end
  if Set.Set(L1_9726, "key0", 9) == true then
    return false
  end
  if Set.Add(L1_9726, "keyF", 3) == false then
    return false
  end
  if Set.Size(L1_9726) ~= 3 then
    return false
  end
  if Set.Add(L2_9727, "key3", 3) == false then
    return false
  end
  if Set.Add(L2_9727, "key4", 4) == false then
    return false
  end
  if Set.Add(L2_9727, "key5", 5) == false then
    return false
  end
  if Set.Add(L2_9727, "key3", 3) == true then
    return false
  end
  if Set.Set(L2_9727, "key9") == true then
    return false
  end
  if Set.Get(L2_9727, "key9") == nil then
    return false
  end
  if not Set.Merge(L1_9726, L2_9727) then
    return false
  end
  if Set.Size(L1_9726) ~= 7 then
    return false
  end
  if Set.Merge(L1_9726, L2_9727) then
    return false
  end
  if Set.Size(L1_9726) ~= 7 then
    return false
  end
  if A0_9725 then
    collectgarbage()
    for _FORV_7_, _FORV_8_ in pairs(Set.countTable) do
    end
    L2_9727 = nil
    collectgarbage()
    for _FORV_8_, _FORV_9_ in pairs(Set.countTable) do
    end
    if 0 + 1 - (0 + 1) ~= 1 then
      return false
    end
  end
  do return true end
  return true
end
if not Set.Test() then
  System.Log("Containers: ... Error - Failed Unit Test")
else
end
