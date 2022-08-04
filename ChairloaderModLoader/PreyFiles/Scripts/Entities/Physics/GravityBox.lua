local L0_7705, L1_7706, L2_7707, L3_7708
L0_7705 = {}
L1_7706 = {}
L1_7706.bActive = 1
L2_7707 = {}
L2_7707.x = -10
L2_7707.y = -10
L2_7707.z = -10
L1_7706.BoxMin = L2_7707
L2_7707 = {}
L2_7707.x = 10
L2_7707.y = 10
L2_7707.z = 10
L1_7706.BoxMax = L2_7707
L1_7706.bUniform = 1
L2_7707 = {}
L2_7707.x = 0
L2_7707.y = 0
L2_7707.z = 0
L1_7706.Gravity = L2_7707
L1_7706.FalloffInner = 1
L2_7707 = {}
L2_7707.x = 0
L2_7707.y = 0
L2_7707.z = 0
L1_7706.vector_ImpulseActivate = L2_7707
L2_7707 = {}
L2_7707.x = 0
L2_7707.y = 0
L2_7707.z = 0
L1_7706.vector_ImpulseDeactivate = L2_7707
L1_7706.bAffectsParticleEmitterPosition = 0
L0_7705.Properties = L1_7706
L1_7706 = {}
L1_7706.Icon = "GravitySphere.bmp"
L0_7705.Editor = L1_7706
L1_7706 = {}
L2_7707 = {}
L1_7706.Area = L2_7707
L0_7705._PhysTable = L1_7706
GravityBox = L0_7705
L0_7705 = GravityBox
function L1_7706(A0_7709, A1_7710)
  A0_7709.bActive = A1_7710.bActive
  if A0_7709.bActive == 1 then
    A0_7709:PhysicalizeThis()
  else
    A0_7709:DestroyPhysics()
  end
end
L0_7705.OnLoad = L1_7706
L0_7705 = GravityBox
function L1_7706(A0_7711, A1_7712)
  A1_7712.bActive = A0_7711.bActive
end
L0_7705.OnSave = L1_7706
L0_7705 = GravityBox
function L1_7706(A0_7713)
  A0_7713.bActive = A0_7713.Properties.bActive
  if A0_7713.bActive == 1 then
    A0_7713:PhysicalizeThis()
  end
end
L0_7705.OnInit = L1_7706
L0_7705 = GravityBox
function L1_7706(A0_7714)
  if A0_7714.bActive ~= A0_7714.Properties.bActive then
    A0_7714.bActive = A0_7714.Properties.bActive
  end
  if A0_7714.bActive == 1 then
    A0_7714:PhysicalizeThis()
  else
    A0_7714:DestroyPhysics()
  end
end
L0_7705.OnPropertyChange = L1_7706
L0_7705 = GravityBox
function L1_7706(A0_7715)
  A0_7715:OnInit()
end
L0_7705.OnReset = L1_7706
L0_7705 = GravityBox
function L1_7706(A0_7716)
  local L1_7717, L2_7718
  L1_7717 = A0_7716.bActive
  if L1_7717 == 1 then
    L1_7717 = A0_7716.Properties
    L2_7718 = A0_7716._PhysTable
    L2_7718 = L2_7718.Area
    L2_7718.type = AREA_BOX
    L2_7718.box_min = L1_7717.BoxMin
    L2_7718.box_max = L1_7717.BoxMax
    L2_7718.uniform = L1_7717.bUniform
    L2_7718.falloffInner = L1_7717.FalloffInner
    L2_7718.gravity = L1_7717.Gravity
    A0_7716:Physicalize(0, PE_AREA, A0_7716._PhysTable)
    A0_7716:SetAreaAffectsParticleEmitterPosition(L1_7717.bAffectsParticleEmitterPosition)
  end
end
L0_7705.PhysicalizeThis = L1_7706
L0_7705 = GravityBox
function L1_7706(A0_7719)
  if A0_7719.bActive ~= 1 then
    A0_7719.bActive = 1
    A0_7719:PhysicalizeThis()
    Game.ImpulseEnvironment(A0_7719.id, A0_7719.Properties.vector_ImpulseActivate)
  end
end
L0_7705.Event_Activate = L1_7706
L0_7705 = GravityBox
function L1_7706(A0_7720)
  if A0_7720.bActive ~= 0 then
    Game.ImpulseEnvironment(A0_7720.id, A0_7720.Properties.vector_ImpulseDeactivate)
    A0_7720.bActive = 0
    A0_7720:DestroyPhysics()
  end
end
L0_7705.Event_Deactivate = L1_7706
L0_7705 = GravityBox
L1_7706 = {}
L2_7707 = {}
L3_7708 = {
  GravityBox.Event_Deactivate,
  "bool"
}
L2_7707.Deactivate = L3_7708
L3_7708 = {
  GravityBox.Event_Activate,
  "bool"
}
L2_7707.Activate = L3_7708
L1_7706.Inputs = L2_7707
L2_7707 = {}
L2_7707.Deactivate = "bool"
L2_7707.Activate = "bool"
L1_7706.Outputs = L2_7707
L0_7705.FlowEvents = L1_7706
