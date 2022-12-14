local L0_8220, L1_8221, L2_8222, L3_8223
L0_8220 = {}
L0_8220.type = "PrismObject"
L0_8220.ENTITY_DETAIL_ID = 1
L1_8221 = {}
L0_8220.Properties = L1_8221
L1_8221 = {}
L1_8221.Model = "Editor/Objects/Particles.cgf"
L1_8221.Icon = "Clouds.bmp"
L0_8220.Editor = L1_8221
PrismObject = L0_8220
L0_8220 = PrismObject
function L1_8221(A0_8224)
  A0_8224:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
end
L0_8220.OnSpawn = L1_8221
L0_8220 = PrismObject
function L1_8221(A0_8225)
  A0_8225:NetPresent(0)
  A0_8225:Create()
end
L0_8220.OnInit = L1_8221
L0_8220 = PrismObject
function L1_8221(A0_8226)
  local L1_8227
end
L0_8220.OnShutDown = L1_8221
L0_8220 = PrismObject
function L1_8221(A0_8228)
  local L1_8229
  L1_8229 = A0_8228.Properties
  A0_8228:LoadPrismObject(0)
end
L0_8220.Create = L1_8221
L0_8220 = PrismObject
function L1_8221(A0_8230)
  A0_8230:FreeSlot(0)
end
L0_8220.Delete = L1_8221
L0_8220 = PrismObject
function L1_8221(A0_8231)
  if not A0_8231:IsSlotValid(0) then
    A0_8231:Create()
  end
end
L0_8220.OnReset = L1_8221
L0_8220 = PrismObject
function L1_8221(A0_8232, A1_8233)
  A1_8233.bHasObject = A0_8232:IsSlotValid(0)
  if A1_8233.bHasObject then
  end
end
L0_8220.OnSave = L1_8221
L0_8220 = PrismObject
function L1_8221(A0_8234, A1_8235)
  if A1_8235.bHasObject and not A0_8234:IsSlotValid(0) then
    A0_8234:Create()
  elseif not A1_8235.bHasObject and A0_8234:IsSlotValid(0) then
    A0_8234:Delete()
  end
end
L0_8220.OnLoad = L1_8221
L0_8220 = PrismObject
function L1_8221(A0_8236)
  A0_8236:Delete()
end
L0_8220.Event_Hide = L1_8221
L0_8220 = PrismObject
function L1_8221(A0_8237)
  A0_8237:Create()
end
L0_8220.Event_Show = L1_8221
L0_8220 = PrismObject
L1_8221 = {}
L2_8222 = {}
L3_8223 = {
  PrismObject.Event_Hide,
  "bool"
}
L2_8222.Hide = L3_8223
L3_8223 = {
  PrismObject.Event_Show,
  "bool"
}
L2_8222.Show = L3_8223
L1_8221.Inputs = L2_8222
L2_8222 = {}
L2_8222.Hide = "bool"
L2_8222.Show = "bool"
L1_8221.Outputs = L2_8222
L0_8220.FlowEvents = L1_8221
