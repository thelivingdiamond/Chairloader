local L0_6565, L1_6566
L0_6565 = {}
L1_6566 = {}
L0_6565.Server = L1_6566
L1_6566 = {}
L0_6565.Client = L1_6566
L1_6566 = {}
L1_6566.Icon = "Item.bmp"
L1_6566.IconOnTop = 1
L1_6566.ShowBounds = 1
L0_6565.Editor = L1_6566
VTOLSpawnPoint = L0_6565
L0_6565 = VTOLSpawnPoint
L0_6565 = L0_6565.Server
function L1_6566(A0_6567)
  A0_6567:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
end
L0_6565.OnInit = L1_6566
L0_6565 = VTOLSpawnPoint
L0_6565 = L0_6565.Client
function L1_6566(A0_6568)
  A0_6568:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
end
L0_6565.OnInit = L1_6566
