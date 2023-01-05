local L0_3080, L1_3081
L0_3080 = {}
L1_3081 = {}
L1_3081.objModel = ""
L1_3081.fileActionController = ""
L1_3081.fileAnimDatabase3P = ""
L0_3080.Properties = L1_3081
L1_3081 = {}
L1_3081.Icon = "user.bmp"
L1_3081.IconOnTop = 1
L0_3080.Editor = L1_3081
MannequinObject = L0_3080
L0_3080 = MannequinObject
function L1_3081(A0_3082)
  A0_3082:ProcessBroadcastEvent("OnPropertyChange")
end
L0_3080.OnPropertyChange = L1_3081
