Script.ReloadScript("scripts/Utils/EntityUtils.lua")
UIEntity = {
  Properties = {
    soclasses_SmartObjectClass = "",
    object_Model = "engine/engineassets/objects/default.cgf"
  },
  Client = {},
  Server = {},
  _Flags = {},
  Editor = {
    Icon = "physicsobject.bmp",
    IconOnTop = 1
  }
}
function UIEntity.OnSpawn(A0_7333)
  A0_7333:SetFromProperties()
end
function UIEntity.OnPreFreeze(A0_7334, A1_7335, A2_7336)
end
function UIEntity.CanShatter(A0_7337)
  local L1_7338
  L1_7338 = false
  return L1_7338
end
function UIEntity.SetFromProperties(A0_7339)
  local L1_7340
  L1_7340 = A0_7339.Properties
  if L1_7340.object_Model == "" then
    return
  end
  A0_7339.freezable = tonumber(L1_7340.bFreezable) ~= 0
end
function UIEntity.IsRigidBody(A0_7341)
  local L1_7342
  L1_7342 = false
  return L1_7342
end
function UIEntity.PhysicalizeThis(A0_7343)
  local L1_7344
end
function UIEntity.OnPropertyChange(A0_7345)
  A0_7345:SetFromProperties()
end
function UIEntity.OnReset(A0_7346)
  local L1_7347
end
function UIEntity.Client.OnPhysicsBreak(A0_7348, A1_7349, A2_7350, A3_7351)
end
function UIEntity.IsUsable(A0_7352, A1_7353)
  local L2_7354
  L2_7354 = 0
  return L2_7354
end
