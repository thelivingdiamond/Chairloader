function CreateExplosive(A0_5538)
  local L1_5539, L2_5540
  L1_5539 = _G
  L1_5539 = L1_5539[A0_5538]
  if not L1_5539 then
    L1_5539 = {}
    function L2_5540(A0_5541, A1_5542)
      local L2_5543
      L2_5543 = true
      return L2_5543
    end
    L1_5539.CanDisarm = L2_5540
    L2_5540 = _G
    L2_5540[A0_5538] = L1_5539
  end
end
CreateExplosive("c4explosive")
