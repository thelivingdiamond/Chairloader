local L0_6606, L1_6607
L0_6606 = {}
L1_6607 = {}
L1_6607.Icon = "Camera.bmp"
L0_6606.Editor = L1_6607
CameraSource = L0_6606
L0_6606 = CameraSource
function L1_6607(A0_6608)
  A0_6608:CreateCameraProxy()
  A0_6608:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
end
L0_6606.OnInit = L1_6607
