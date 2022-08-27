local L0_3638, L1_3639, L2_3640, L3_3641
L0_3638 = {}
L1_3639 = {}
L2_3640 = {}
L2_3640.distractor_ArkDistractor = ""
L1_3639.ArkDistractor = L2_3640
L0_3638.Properties = L1_3639
L1_3639 = {}
L2_3640 = {}
L2_3640.fDistractionRadius = -1
L2_3640.fTryDistractionCD = -1
L2_3640.fChanceToDistract = -1
L2_3640.fOnUseWaitTime = -1
L2_3640.fOnUseCooldown = -1
L3_3641 = {}
L3_3641.fStandAngle = -1
L3_3641.fMinStandDistance = -1
L3_3641.fMaxStandDistance = -1
L2_3640.POS = L3_3641
L3_3641 = {}
L3_3641.fStartRelativePosX = -1
L3_3641.fStartRelativePosY = -1
L3_3641.fStartRelativePosZ = -1
L2_3640.LOS = L3_3641
L1_3639.ArkDistractorOverride = L2_3640
L0_3638.PropertiesInstance = L1_3639
L1_3639 = {}
L1_3639.Icon = "DistractorPoint.bmp"
L1_3639.IconOnTop = 1
L0_3638.Editor = L1_3639
ArkDistractor = L0_3638
L0_3638 = ArkDistractor
function L1_3639(A0_3642)
  BroadcastEvent(A0_3642, "EnableDis")
end
L0_3638.Event_Enable = L1_3639
L0_3638 = ArkDistractor
function L1_3639(A0_3643)
  BroadcastEvent(A0_3643, "DisableDis")
end
L0_3638.Event_Disable = L1_3639
L0_3638 = ArkDistractor
L1_3639 = {}
L2_3640 = {}
L3_3641 = {
  ArkDistractor.Event_Enable,
  "bool"
}
L2_3640.Enable = L3_3641
L3_3641 = {
  ArkDistractor.Event_Disable,
  "bool"
}
L2_3640.Disable = L3_3641
L1_3639.Inputs = L2_3640
L2_3640 = {}
L1_3639.Outputs = L2_3640
L0_3638.FlowEvents = L1_3639
