local L0_4692, L1_4693, L2_4694
L0_4692 = {}
L1_4693 = {}
L1_4693.bIsThin = 0
L1_4693.bIsWindow = 0
L1_4693.bLedgeDoubleSide = 0
L1_4693.bLedgeFlipped = 0
L1_4693.fCornerMaxAngle = 130
L1_4693.fCornerEndAdjustAmount = 0.5
L2_4694 = {}
L2_4694.bEndCrouched = 0
L2_4694.bEndFalling = 0
L2_4694.bUsableByMarines = 1
L2_4694.esLedgeType = "Normal"
L1_4693.MainSide = L2_4694
L2_4694 = {}
L2_4694.bEndCrouched = 0
L2_4694.bEndFalling = 0
L2_4694.bUsableByMarines = 1
L2_4694.esLedgeType = "Normal"
L1_4693.OppositeSide = L2_4694
L0_4692.Properties = L1_4693
L1_4693 = {}
L0_4692.Client = L1_4693
L1_4693 = {}
L0_4692.Server = L1_4693
L1_4693 = {}
L1_4693.Icon = "ledge.bmp"
L1_4693.ShowBounds = 1
L0_4692.Editor = L1_4693
LedgeObjectStatic = L0_4692
L0_4692 = LedgeObjectStatic
function L1_4693(A0_4695)
  local L1_4696
end
L0_4692.OnPropertyChange = L1_4693
L0_4692 = LedgeObjectStatic
function L1_4693(A0_4697)
  local L1_4698
  L1_4698 = 1
  return L1_4698
end
L0_4692.IsShapeOnly = L1_4693
L0_4692 = LedgeObjectStatic
function L1_4693(A0_4699)
  local L1_4700
  L1_4700 = 0
  return L1_4700
end
L0_4692.IsClosed = L1_4693
L0_4692 = LedgeObjectStatic
function L1_4693(A0_4701)
  local L1_4702
  L1_4702 = 2
  return L1_4702
end
L0_4692.ShapeMinPoints = L1_4693
L0_4692 = LedgeObjectStatic
function L1_4693(A0_4703)
  local L1_4704
  L1_4704 = 33
  return L1_4704
end
L0_4692.ShapeMaxPoints = L1_4693
L0_4692 = LedgeObjectStatic
function L1_4693(A0_4705)
  local L1_4706
  L1_4706 = 0
  return L1_4706
end
L0_4692.ExportToGame = L1_4693
L0_4692 = LedgeObjectStatic
function L1_4693(A0_4707)
  A0_4707:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
  A0_4707:SetFlags(ENTITY_FLAG_NO_PROXIMITY, 0)
end
L0_4692.OnSpawn = L1_4693
