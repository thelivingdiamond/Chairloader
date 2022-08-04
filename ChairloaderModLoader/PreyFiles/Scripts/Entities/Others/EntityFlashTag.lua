Script.ReloadScript("scripts/Utils/EntityUtils.lua")
EntityFlashTag = {
  Properties = {
    soclasses_SmartObjectClass = "",
    bAutoGenAIHidePts = 0,
    object_Model = "engine/engineassets/objects/default.cgf",
    fScale = 2
  },
  Client = {},
  Server = {},
  _Flags = {},
  Editor = {
    Icon = "physicsobject.bmp",
    IconOnTop = 1
  }
}
function EntityFlashTag.OnSpawn(A0_6709)
  A0_6709:SetFromProperties()
end
function EntityFlashTag.SetFromProperties(A0_6710)
  local L1_6711
  L1_6711 = A0_6710.Properties
  if L1_6711.object_Model == "" then
    return
  end
  A0_6710:LoadObject(0, L1_6711.object_Model)
  A0_6710:SetScale(L1_6711.fScale)
end
function EntityFlashTag.OnPropertyChange(A0_6712)
  A0_6712:SetFromProperties()
end
