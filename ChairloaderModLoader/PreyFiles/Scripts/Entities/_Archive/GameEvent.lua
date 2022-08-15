local L0_879, L1_880, L2_881
L0_879 = {}
L1_880 = {}
L1_880.nId = 0
L1_880.nAllowedDeaths = 3
L1_880.sUniqueName = ""
L1_880.bRespawnAtTagpoint = 0
L0_879.Properties = L1_880
L1_880 = {}
L1_880.Model = "Objects/Editor/Anchor.cgf"
L0_879.Editor = L1_880
GameEvent = L0_879
L0_879 = GameEvent
function L1_880(A0_882)
  local L1_883
end
L0_879.OnInit = L1_880
L0_879 = GameEvent
function L1_880(A0_884)
  local L1_885
end
L0_879.OnShutDown = L1_880
L0_879 = GameEvent
function L1_880(A0_886, A1_887)
  A0_886:EnableSave(nil)
  System.Log("Checkpoint " .. A0_886.Properties.nId .. " reached")
  A0_886.bSaveNow = nil
  A0_886:SetTimer(100)
end
L0_879.Event_Save = L1_880
L0_879 = GameEvent
function L1_880(A0_888)
  if _localplayer.timetodie then
    return
  end
  if A0_888.bSaveNow then
    A0_888.bSaveNow = nil
    if A0_888.Properties.bRespawnAtTagpoint == 1 and _localplayer.theVehicle == nil then
      _LastCheckPPos = new(A0_888:GetPos())
      _LastCheckPAngles = new(A0_888:GetAngles())
    else
      _LastCheckPPos = new(_localplayer:GetPos())
      _LastCheckPAngles = new(_localplayer:GetAngles(1))
    end
    A0_888:KillTimer()
    AI:Checkpoint()
    if A0_888.Properties.sUniqueName ~= "" then
      if ALLOWED_DEATHS and ALLOWED_DEATHS[A0_888.Properties.sUniqueName] then
        AI:SetAllowedDeathCount(ALLOWED_DEATHS[A0_888.Properties.sUniqueName].deaths)
      end
    else
      AI:SetAllowedDeathCount(A0_888.Properties.nAllowedDeaths)
    end
    Game:TouchCheckPoint(A0_888.Properties.nId, _LastCheckPPos, _LastCheckPAngles)
    if Game.OnAfterSave then
      Game:OnAfterSave()
    end
  else
    if Game.OnBeforeSave then
      Game:OnBeforeSave()
    end
    A0_888.bSaveNow = 1
    A0_888:SetTimer(1)
  end
end
L0_879.OnTimer = L1_880
L0_879 = GameEvent
L1_880 = {}
L2_881 = {}
L2_881.Save = {
  GameEvent.Event_Save,
  "bool"
}
L1_880.Inputs = L2_881
L2_881 = {}
L2_881.Save = "bool"
L1_880.Outputs = L2_881
L0_879.FlowEvents = L1_880
