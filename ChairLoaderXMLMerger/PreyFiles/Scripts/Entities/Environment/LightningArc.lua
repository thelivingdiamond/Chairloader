local L0_5171, L1_5172, L2_5173, L3_5174
L0_5171 = {}
L1_5172 = {}
L1_5172.bCheckLOS = 1
L2_5173 = {}
L2_5173.fDelay = 2
L2_5173.fDelayVariation = 0.5
L1_5172.Timing = L2_5173
L2_5173 = {}
L2_5173.ArcPreset = "Default"
L2_5173.particleeffect_TargetHitVFX = ""
L2_5173.particleeffect_SourceVFX = ""
L1_5172.Render = L2_5173
L0_5171.Properties = L1_5172
L1_5172 = {}
L1_5172.Model = "Editor/Objects/Particles.cgf"
L1_5172.Icon = "Lightning.bmp"
L0_5171.Editor = L1_5172
LightningArc = L0_5171
L0_5171 = LightningArc
function L1_5172(A0_5175)
  A0_5175.lightningArc:ReadLuaParameters()
end
L0_5171.OnPropertyChange = L1_5172
L0_5171 = LightningArc
function L1_5172(A0_5176)
  A0_5176.lightningArc:TriggerSpark()
end
L0_5171.Event_Strike = L1_5172
L0_5171 = LightningArc
function L1_5172(A0_5177)
  A0_5177.lightningArc:Enable(true)
end
L0_5171.Event_Enable = L1_5172
L0_5171 = LightningArc
function L1_5172(A0_5178)
  A0_5178.lightningArc:Enable(false)
end
L0_5171.Event_Disable = L1_5172
L0_5171 = LightningArc
L1_5172 = {}
L2_5173 = {}
L3_5174 = {
  LightningArc.Event_Strike,
  "bool"
}
L2_5173.Strike = L3_5174
L3_5174 = {
  LightningArc.Event_Enable,
  "bool"
}
L2_5173.Enable = L3_5174
L3_5174 = {
  LightningArc.Event_Disable,
  "bool"
}
L2_5173.Disable = L3_5174
L1_5172.Inputs = L2_5173
L2_5173 = {}
L2_5173.StrikeTime = "float"
L2_5173.EntityId = "entity"
L1_5172.Outputs = L2_5173
L0_5171.FlowEvents = L1_5172
