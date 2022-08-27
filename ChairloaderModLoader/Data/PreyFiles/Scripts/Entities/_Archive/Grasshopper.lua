local L0_889, L1_890
L0_889 = {}
L0_889.type = "GrasshopperController"
L1_890 = {}
L1_890.GrasshopperNumber = 29
L1_890.objCGF1 = "Objects/characters/animals/grasshopper/grasshopper.cgf"
L1_890.objCGF2 = ""
L1_890.objCGF3 = ""
L1_890.objCGF4 = ""
L0_889.Properties = L1_890
L1_890 = {}
L1_890.Model = "Objects/Editor/T.cgf"
L0_889.Editor = L1_890
L0_889.outsideGrasshopperNumber = 0
Grasshopper = L0_889
L0_889 = Grasshopper
function L1_890(A0_891)
  if strlen(A0_891.Properties.objCGF1) > 0 then
    A0_891:LoadObject(A0_891.Properties.objCGF1, 0, 1)
  end
  if 0 < strlen(A0_891.Properties.objCGF2) then
    A0_891:LoadObject(A0_891.Properties.objCGF2, 1, 1)
  end
  if 0 < strlen(A0_891.Properties.objCGF3) then
    A0_891:LoadObject(A0_891.Properties.objCGF3, 2, 1)
  end
  if 0 < strlen(A0_891.Properties.objCGF4) then
    A0_891:LoadObject(A0_891.Properties.objCGF4, 3, 1)
  end
end
L0_889.OnInit = L1_890
L0_889 = Grasshopper
function L1_890(A0_892, A1_893, A2_894, A3_895)
  System.SetGrasshopperCount(Lerp(A0_892.outsideGrasshopperNumber, A0_892.Properties.GrasshopperNumber, A3_895))
end
L0_889.OnProceedFadeArea = L1_890
L0_889 = Grasshopper
function L1_890(A0_896, A1_897, A2_898)
  A0_896.outsideGrasshopperNumber = System.GetGrasshopperCount()
  System.SetGrasshopperCGF(A0_896.id)
end
L0_889.OnEnterArea = L1_890
L0_889 = Grasshopper
function L1_890(A0_899, A1_900, A2_901)
  System.SetGrasshopperCount(A0_899.outsideGrasshopperNumber)
end
L0_889.OnLeaveArea = L1_890
L0_889 = Grasshopper
function L1_890(A0_902)
  local L1_903
end
L0_889.OnShutDown = L1_890
