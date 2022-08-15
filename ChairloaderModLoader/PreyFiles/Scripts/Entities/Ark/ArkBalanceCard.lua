local L0_3483, L1_3484
L0_3483 = {}
L1_3484 = {}
L1_3484.Icon = "Camera.bmp"
L0_3483.Editor = L1_3484
ArkBalanceCard = L0_3483
L0_3483 = ArkBalanceCard
function L1_3484(A0_3485)
  A0_3485:CreateCameraProxy()
  A0_3485:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
end
L0_3483.OnInit = L1_3484
