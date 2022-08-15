local L0_6201, L1_6202
L0_6201 = {}
L1_6202 = {}
L0_6201.Client = L1_6202
L1_6202 = {}
L0_6201.Server = L1_6202
L1_6202 = {}
L1_6202.fileModel = "objects/library/props/ctf/mpnots_flagbase01.cgf"
L1_6202.ModelSubObject = "main"
L1_6202.Radius = 2
L0_6201.Properties = L1_6202
L1_6202 = {}
L1_6202.Icon = "Item.bmp"
L1_6202.IconOnTop = 1
L0_6201.Editor = L1_6202
BTBBombBase = L0_6201
L0_6201 = BTBBombBase
L0_6201 = L0_6201.Server
function L1_6202(A0_6203)
  Log("BTBBombBase.Server.OnInit")
  if not A0_6203.bInitialized then
    A0_6203:OnReset()
    A0_6203.bInitialized = 1
  end
  A0_6203.inside = {}
end
L0_6201.OnInit = L1_6202
L0_6201 = BTBBombBase
L0_6201 = L0_6201.Client
function L1_6202(A0_6204)
  Log("BTBBombBase.Client.OnInit")
  if not A0_6204.bInitialized then
    A0_6204:OnReset()
    A0_6204.bInitialized = 1
  end
  A0_6204.inside = {}
end
L0_6201.OnInit = L1_6202
L0_6201 = BTBBombBase
function L1_6202(A0_6205)
  local L1_6206, L2_6207, L3_6208
  L1_6206 = Log
  L2_6207 = "BTBBombBase.OnReset"
  L1_6206(L2_6207)
  L2_6207 = A0_6205
  L1_6206 = A0_6205.LoadObject
  L3_6208 = 0
  L1_6206(L2_6207, L3_6208, A0_6205.Properties.fileModel)
  L1_6206 = A0_6205.Properties
  L1_6206 = L1_6206.Radius
  L1_6206 = L1_6206 / 2
  L2_6207 = {}
  L3_6208 = -L1_6206
  L2_6207.x = L3_6208
  L3_6208 = -L1_6206
  L2_6207.y = L3_6208
  L3_6208 = -L1_6206
  L2_6207.z = L3_6208
  L3_6208 = {}
  L3_6208.x = L1_6206
  L3_6208.y = L1_6206
  L3_6208.z = L1_6206
  A0_6205:SetTriggerBBox(L2_6207, L3_6208)
  A0_6205:Physicalize(0, PE_STATIC, {mass = 0})
  A0_6205:SetFlags(ENTITY_FLAG_ON_RADAR, 0)
end
L0_6201.OnReset = L1_6202
L0_6201 = BTBBombBase
L0_6201 = L0_6201.Server
function L1_6202(A0_6209)
  Log("HIT BASE!")
end
L0_6201.OnHit = L1_6202
