local L0_7070, L1_7071
L0_7070 = {}
L1_7071 = {}
L1_7071.Icon = "PrecacheCamera.bmp"
L0_7070.Editor = L1_7071
PrecacheCamera = L0_7070
L0_7070 = PrecacheCamera
function L1_7071(A0_7072)
  A0_7072:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
end
L0_7070.OnSpawn = L1_7071
