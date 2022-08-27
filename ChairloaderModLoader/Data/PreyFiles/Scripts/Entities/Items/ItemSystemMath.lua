local L0_5627, L1_5628
function L0_5627(A0_5629, A1_5630, A2_5631)
  local L3_5632, L4_5633, L5_5634, L6_5635
  L3_5632 = vecSub
  L4_5633 = A2_5631
  L5_5634 = A1_5630
  L3_5632 = L3_5632(L4_5633, L5_5634)
  L4_5633 = vecLenSq
  L5_5634 = L3_5632
  L4_5633 = L4_5633(L5_5634)
  if L4_5633 > 0.001 then
    L5_5634 = A0_5629.x
    L6_5635 = A1_5630.x
    L5_5634 = L5_5634 - L6_5635
    L6_5635 = A2_5631.x
    L6_5635 = L6_5635 - A1_5630.x
    L5_5634 = L5_5634 * L6_5635
    L6_5635 = A0_5629.y
    L6_5635 = L6_5635 - A1_5630.y
    L6_5635 = L6_5635 * (A2_5631.y - A1_5630.y)
    L5_5634 = L5_5634 + L6_5635
    L6_5635 = A0_5629.z
    L6_5635 = L6_5635 - A1_5630.z
    L6_5635 = L6_5635 * (A2_5631.z - A1_5630.z)
    L5_5634 = L5_5634 + L6_5635
    L5_5634 = L5_5634 / L4_5633
    if L5_5634 > 0 and L5_5634 < 1 then
      L6_5635 = g_Vectors
      L6_5635 = L6_5635.temp_v2
      L6_5635.x = A1_5630.x + L5_5634 * (A2_5631.x - A1_5630.x)
      L6_5635.y = A1_5630.y + L5_5634 * (A2_5631.y - A1_5630.y)
      L6_5635.z = A1_5630.z + L5_5634 * (A2_5631.z - A1_5630.z)
      return vecLenSq(vecSub(A0_5629, L6_5635)), L6_5635
    end
  end
end
PointToLineDistanceSq = L0_5627
function L0_5627(A0_5636, A1_5637)
  local L2_5638
  L2_5638 = table
  L2_5638 = L2_5638.getn
  L2_5638 = L2_5638(A1_5637)
  for _FORV_8_ = 1, L2_5638 do
  end
  return not false
end
PointInPolygon = L0_5627
function L0_5627(A0_5639, A1_5640, A2_5641, A3_5642)
  local L4_5643, L5_5644, L6_5645, L7_5646
  L4_5643 = A2_5641.x
  L4_5643 = A0_5639 - L4_5643
  L5_5644 = A2_5641.y
  L5_5644 = A1_5640 - L5_5644
  L6_5645 = L4_5643 * L4_5643
  L7_5646 = L5_5644 * L5_5644
  L6_5645 = L6_5645 + L7_5646
  L7_5646 = A3_5642 * A3_5642
  if L6_5645 < L7_5646 then
    L6_5645 = true
    return L6_5645
  end
  L6_5645 = false
  return L6_5645
end
PointInCircle = L0_5627
function L0_5627(A0_5647, A1_5648)
  A1_5648 = A1_5648 or g_Vectors.v001
  return vecNormalize(vecCross(A0_5647, A1_5648))
end
vecFrontToRight = L0_5627
function L0_5627(A0_5649, A1_5650)
  local L2_5651
  if not A1_5650 then
    L2_5651 = g_Vectors
    A1_5650 = L2_5651.v001
  end
  L2_5651 = vecCopy
  L2_5651 = L2_5651(g_Vectors.temp_v1, vecNormalize(vecCross(A0_5649, A1_5650)))
  return vecNormalize(vecCross(L2_5651, A0_5649))
end
vecFrontToUp = L0_5627
function L0_5627(A0_5652)
  local L1_5653, L2_5654, L3_5655
  L1_5653 = A0_5652.x
  L2_5654 = A0_5652.y
  L3_5655 = math
  L3_5655 = L3_5655.sqrt
  L3_5655 = L3_5655(L1_5653 * L1_5653 + L2_5654 * L2_5654)
  g_Vectors.vecMathTemp2.y, g_Vectors.vecMathTemp2.x = math.atan2(A0_5652.z, L3_5655), math.atan2(-L1_5653 * 1, L2_5654 * 1)
  g_Vectors.vecMathTemp2.z = 0
  return g_Vectors.vecMathTemp2
end
vecToAngles = L0_5627
function L0_5627(A0_5656)
  local L1_5657
  L1_5657 = g_Vectors
  L1_5657 = L1_5657.vecMathTemp2
  L1_5657.x = -math.sin(A0_5656.x) * math.cos(A0_5656.y)
  L1_5657.z, L1_5657.y = math.sin(A0_5656.y), math.cos(A0_5656.x) * math.cos(A0_5656.y)
  return L1_5657
end
anglesToVec = L0_5627
function L0_5627(A0_5658)
  if not A0_5658 then
    return {
      x = 0,
      y = 0,
      z = 0
    }
  else
    return vecCopy({}, A0_5658)
  end
end
vecNew = L0_5627
function L0_5627(A0_5659, A1_5660, A2_5661, A3_5662)
  A0_5659.x = A1_5660
  A0_5659.y = A2_5661
  A0_5659.z = A3_5662
  return A0_5659
end
vecSet = L0_5627
function L0_5627(A0_5663, A1_5664)
  local L2_5665
  L2_5665 = A1_5664.x
  A0_5663.x = L2_5665
  L2_5665 = A1_5664.y
  A0_5663.y = L2_5665
  L2_5665 = A1_5664.z
  A0_5663.z = L2_5665
  return A0_5663
end
vecCopy = L0_5627
function L0_5627(A0_5666, A1_5667)
  local L2_5668, L3_5669, L4_5670, L5_5671, L6_5672
  L2_5668 = A0_5666.x
  L3_5669 = A1_5667.x
  L2_5668 = L2_5668 - L3_5669
  L3_5669 = A0_5666.y
  L4_5670 = A1_5667.y
  L3_5669 = L3_5669 - L4_5670
  L4_5670 = A0_5666.z
  L5_5671 = A1_5667.z
  L4_5670 = L4_5670 - L5_5671
  L5_5671 = L2_5668 * L2_5668
  L6_5672 = L3_5669 * L3_5669
  L5_5671 = L5_5671 + L6_5672
  L6_5672 = L4_5670 * L4_5670
  L5_5671 = L5_5671 + L6_5672
  return L5_5671
end
vecDistanceSq = L0_5627
function L0_5627(A0_5673, A1_5674)
  local L2_5675, L3_5676, L4_5677, L5_5678
  L2_5675 = A0_5673.x
  L3_5676 = A1_5674.x
  L2_5675 = L2_5675 - L3_5676
  L3_5676 = A0_5673.y
  L4_5677 = A1_5674.y
  L3_5676 = L3_5676 - L4_5677
  L4_5677 = L2_5675 * L2_5675
  L5_5678 = L3_5676 * L3_5676
  L4_5677 = L4_5677 + L5_5678
  return L4_5677
end
vec2DDistanceSq = L0_5627
function L0_5627(A0_5679, A1_5680)
  local L2_5681, L3_5682
  L2_5681 = g_Vectors
  L2_5681 = L2_5681.vecMathTemp1
  L3_5682 = A0_5679.x
  L3_5682 = L3_5682 * A1_5680
  L2_5681.x = L3_5682
  L3_5682 = A0_5679.y
  L3_5682 = L3_5682 * A1_5680
  L2_5681.y = L3_5682
  L3_5682 = A0_5679.z
  L3_5682 = L3_5682 * A1_5680
  L2_5681.z = L3_5682
  return L2_5681
end
vecScale = L0_5627
function L0_5627(A0_5683, A1_5684, A2_5685, A3_5686)
  local L4_5687, L5_5688
  if A3_5686 then
    L4_5687 = A3_5686
  else
    L5_5688 = math
    L5_5688 = L5_5688.acos
    L5_5688 = L5_5688(vecDot(A0_5683, A1_5684))
    L4_5687 = L5_5688
  end
  L5_5688 = math
  L5_5688 = L5_5688.sin
  L5_5688 = L5_5688(L4_5687)
  if math.abs(L5_5688) > 0.01 then
    g_Vectors.vecMathTemp1.x = 1 / L5_5688 * (A0_5683.x * math.sin((1 - A2_5685) * L4_5687) + A1_5684.x * math.sin(A2_5685 * L4_5687))
    g_Vectors.vecMathTemp1.y = 1 / L5_5688 * (A0_5683.y * math.sin((1 - A2_5685) * L4_5687) + A1_5684.y * math.sin(A2_5685 * L4_5687))
    g_Vectors.vecMathTemp1.z = 1 / L5_5688 * (A0_5683.z * math.sin((1 - A2_5685) * L4_5687) + A1_5684.z * math.sin(A2_5685 * L4_5687))
    return g_Vectors.vecMathTemp1
  else
    return vecLerp(A0_5683, A1_5684, A2_5685)
  end
end
vecSLerp = L0_5627
function L0_5627(A0_5689, A1_5690, A2_5691)
  local L3_5692, L4_5693, L5_5694, L6_5695
  L3_5692 = g_Vectors
  L3_5692 = L3_5692.vecMathTemp1
  L4_5693 = 1 - A2_5691
  L5_5694 = A0_5689.x
  L5_5694 = L5_5694 * L4_5693
  L6_5695 = A1_5690.x
  L6_5695 = L6_5695 * A2_5691
  L5_5694 = L5_5694 + L6_5695
  L3_5692.x = L5_5694
  L5_5694 = A0_5689.y
  L5_5694 = L5_5694 * L4_5693
  L6_5695 = A1_5690.y
  L6_5695 = L6_5695 * A2_5691
  L5_5694 = L5_5694 + L6_5695
  L3_5692.y = L5_5694
  L5_5694 = A0_5689.z
  L5_5694 = L5_5694 * L4_5693
  L6_5695 = A1_5690.z
  L6_5695 = L6_5695 * A2_5691
  L5_5694 = L5_5694 + L6_5695
  L3_5692.z = L5_5694
  return L3_5692
end
vecLerp = L0_5627
function L0_5627(A0_5696, A1_5697)
  local L2_5698, L3_5699, L4_5700
  L2_5698 = g_Vectors
  L2_5698 = L2_5698.vecMathTemp1
  L3_5699 = A0_5696.x
  L4_5700 = A1_5697.x
  L3_5699 = L3_5699 - L4_5700
  L2_5698.x = L3_5699
  L3_5699 = A0_5696.y
  L4_5700 = A1_5697.y
  L3_5699 = L3_5699 - L4_5700
  L2_5698.y = L3_5699
  L3_5699 = A0_5696.z
  L4_5700 = A1_5697.z
  L3_5699 = L3_5699 - L4_5700
  L2_5698.z = L3_5699
  return L2_5698
end
vecSub = L0_5627
function L0_5627(A0_5701, A1_5702)
  local L2_5703, L3_5704, L4_5705
  L2_5703 = g_Vectors
  L2_5703 = L2_5703.vecMathTemp1
  L3_5704 = A0_5701.x
  L4_5705 = A1_5702.x
  L3_5704 = L3_5704 + L4_5705
  L2_5703.x = L3_5704
  L3_5704 = A0_5701.y
  L4_5705 = A1_5702.y
  L3_5704 = L3_5704 + L4_5705
  L2_5703.y = L3_5704
  L3_5704 = A0_5701.z
  L4_5705 = A1_5702.z
  L3_5704 = L3_5704 + L4_5705
  L2_5703.z = L3_5704
  return L2_5703
end
vecAdd = L0_5627
function L0_5627(A0_5706)
  local L1_5707, L2_5708, L3_5709
  L1_5707 = A0_5706.x
  L2_5708 = A0_5706.x
  L1_5707 = L1_5707 * L2_5708
  L2_5708 = A0_5706.y
  L3_5709 = A0_5706.y
  L2_5708 = L2_5708 * L3_5709
  L1_5707 = L1_5707 + L2_5708
  L2_5708 = A0_5706.z
  L3_5709 = A0_5706.z
  L2_5708 = L2_5708 * L3_5709
  L1_5707 = L1_5707 + L2_5708
  return L1_5707
end
vecLenSq = L0_5627
function L0_5627(A0_5710)
  return math.sqrt(A0_5710.x * A0_5710.x + A0_5710.y * A0_5710.y + A0_5710.z * A0_5710.z)
end
vecLen = L0_5627
function L0_5627(A0_5711, A1_5712)
  local L2_5713, L3_5714, L4_5715
  L2_5713 = g_Vectors
  L2_5713 = L2_5713.vecMathTemp1
  L3_5714 = A0_5711.x
  L4_5715 = A1_5712.x
  L3_5714 = L3_5714 * L4_5715
  L2_5713.x = L3_5714
  L3_5714 = A0_5711.y
  L4_5715 = A1_5712.y
  L3_5714 = L3_5714 * L4_5715
  L2_5713.y = L3_5714
  L3_5714 = A0_5711.z
  L4_5715 = A1_5712.z
  L3_5714 = L3_5714 * L4_5715
  L2_5713.z = L3_5714
  return L2_5713
end
vecMul = L0_5627
function L0_5627(A0_5716)
  local L1_5717, L2_5718, L3_5719
  L1_5717 = math
  L1_5717 = L1_5717.sqrt
  L2_5718 = A0_5716.x
  L3_5719 = A0_5716.x
  L2_5718 = L2_5718 * L3_5719
  L3_5719 = A0_5716.y
  L3_5719 = L3_5719 * A0_5716.y
  L2_5718 = L2_5718 + L3_5719
  L3_5719 = A0_5716.z
  L3_5719 = L3_5719 * A0_5716.z
  L2_5718 = L2_5718 + L3_5719
  L1_5717 = L1_5717(L2_5718)
  if L1_5717 > 0 then
    L2_5718 = 1 / L1_5717
    L3_5719 = g_Vectors
    L3_5719 = L3_5719.vecMathTemp1
    L3_5719.x = A0_5716.x * L2_5718
    L3_5719.y = A0_5716.y * L2_5718
    L3_5719.z = A0_5716.z * L2_5718
    return L3_5719, L1_5717
  end
  L2_5718 = v
  L3_5719 = 0
  return L2_5718, L3_5719
end
vecNormalize = L0_5627
function L0_5627(A0_5720, A1_5721)
  local L2_5722, L3_5723, L4_5724
  L2_5722 = A0_5720.x
  L3_5723 = A1_5721.x
  L2_5722 = L2_5722 * L3_5723
  L3_5723 = A0_5720.y
  L4_5724 = A1_5721.y
  L3_5723 = L3_5723 * L4_5724
  L2_5722 = L2_5722 + L3_5723
  L3_5723 = A0_5720.z
  L4_5724 = A1_5721.z
  L3_5723 = L3_5723 * L4_5724
  L2_5722 = L2_5722 + L3_5723
  return L2_5722
end
vecDot = L0_5627
function L0_5627(A0_5725, A1_5726)
  local L2_5727, L3_5728, L4_5729, L5_5730
  L2_5727 = g_Vectors
  L2_5727 = L2_5727.vecMathTemp1
  L3_5728 = A0_5725.y
  L4_5729 = A1_5726.z
  L3_5728 = L3_5728 * L4_5729
  L4_5729 = A0_5725.z
  L5_5730 = A1_5726.y
  L4_5729 = L4_5729 * L5_5730
  L3_5728 = L3_5728 - L4_5729
  L2_5727.x = L3_5728
  L3_5728 = A0_5725.z
  L4_5729 = A1_5726.x
  L3_5728 = L3_5728 * L4_5729
  L4_5729 = A0_5725.x
  L5_5730 = A1_5726.z
  L4_5729 = L4_5729 * L5_5730
  L3_5728 = L3_5728 - L4_5729
  L2_5727.y = L3_5728
  L3_5728 = A0_5725.x
  L4_5729 = A1_5726.y
  L3_5728 = L3_5728 * L4_5729
  L4_5729 = A0_5725.y
  L5_5730 = A1_5726.x
  L4_5729 = L4_5729 * L5_5730
  L3_5728 = L3_5728 - L4_5729
  L2_5727.z = L3_5728
  return L2_5727
end
vecCross = L0_5627
function L0_5627(A0_5731, A1_5732)
  if A0_5731 then
    return A0_5731
  end
  return A1_5732
end
retDef = L0_5627
