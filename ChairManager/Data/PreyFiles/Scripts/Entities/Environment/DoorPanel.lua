DoorPanel = {
  type = "DoorPanel",
  Properties = {
    objModel = "Objects/props/cell_panel/cell_panel.cgf",
    objModelDestroyed = "Objects/props/cell_panel/cell_panel_broken.cgf",
    bDestroyable = 1,
    DestroyedExplosionType = "SmartMineExplosive",
    esDoorPanelState = "Idle",
    bUsableOnlyOnce = 0,
    VisibleFlashDistance = 50,
    ScanSuccessTimeDelay = 0.5,
    ScanFailureTimeDelay = 1.5,
    TacticalInfo = {bScannable = 0, LookupName = ""}
  },
  Editor = {Icon = "mine.bmp"},
  Client = {},
  Server = {}
}
MakeUsable(DoorPanel)
function DoorPanel.OnSave(A0_5141, A1_5142)
  A1_5142.bUsable = A0_5141.bUsable
end
function DoorPanel.OnLoad(A0_5143, A1_5144)
  A0_5143:OnReset()
  A0_5143.bUsable = A1_5144.bUsable
end
function DoorPanel.Client.OnInit(A0_5145)
  A0_5145:OnReset()
end
function DoorPanel.OnReset(A0_5146)
  local L1_5147
  L1_5147 = A0_5146.Properties
  L1_5147 = L1_5147.bUsable
  A0_5146.bUsable = L1_5147
end
function DoorPanel.OnUsed(A0_5148, A1_5149, A2_5150)
end
function DoorPanel.IsUsable(A0_5151, A1_5152)
  if A0_5151.bUsable == 1 then
    return 2
  end
  return 0
end
function DoorPanel.OnPropertyChange(A0_5153)
  local L1_5154
end
function DoorPanel.Server.OnHit(A0_5155, A1_5156)
  if A0_5155.Properties.bDestroyable == 1 and A1_5156.type ~= "collision" and A1_5156.damage > 0 then
    Game.SendEventToGameObject(A0_5155.id, "Destroyed")
  end
end
function DoorPanel.OnStateChange(A0_5157, A1_5158)
  A0_5157:ActivateOutput(A1_5158, true)
end
function DoorPanel.Event_EnableUsable(A0_5159)
  local L1_5160
  A0_5159.bUsable = 1
end
function DoorPanel.Event_DisableUsable(A0_5161)
  local L1_5162
  A0_5161.bUsable = 0
end
function DoorPanel.Event_Idle(A0_5163)
  Game.SendEventToGameObject(A0_5163.id, "Idle")
end
function DoorPanel.Event_Scanning(A0_5164)
  A0_5164:OnCustomActionStart()
end
function DoorPanel.Event_ScanSuccess(A0_5165)
  A0_5165:OnCustomActionSucceed()
end
function DoorPanel.Event_ScanComplete(A0_5166)
  if A0_5166.Properties.bUsableOnlyOnce == 1 then
    A0_5166.bUsable = 0
  end
  Game.SendEventToGameObject(A0_5166.id, "ScanComplete")
end
function DoorPanel.Event_ScanFailure(A0_5167)
  Game.SendEventToGameObject(A0_5167.id, "ScanFailure")
end
function DoorPanel.Event_Destroyed(A0_5168)
  if A0_5168.Properties.bDestroyable == 1 then
    Game.SendEventToGameObject(A0_5168.id, "Destroyed")
  end
end
function DoorPanel.Event_Hide(A0_5169)
  A0_5169:Hide(1)
end
function DoorPanel.Event_Unhide(A0_5170)
  A0_5170:Hide(0)
end
DoorPanel.FlowEvents = {
  Inputs = {
    Idle = {
      DoorPanel.Event_Idle,
      "bool"
    },
    Scanning = {
      DoorPanel.Event_Scanning,
      "bool"
    },
    ScanSuccess = {
      DoorPanel.Event_ScanSuccess,
      "bool"
    },
    ScanComplete = {
      DoorPanel.Event_ScanComplete,
      "bool"
    },
    ScanFailure = {
      DoorPanel.Event_ScanFailure,
      "bool"
    },
    Destroyed = {
      DoorPanel.Event_Destroyed,
      "bool"
    },
    Hide = {
      DoorPanel.Event_Hide,
      "bool"
    },
    Unhide = {
      DoorPanel.Event_Unhide,
      "bool"
    }
  },
  Outputs = {
    Idle = "bool",
    Scanning = "bool",
    ScanSuccess = "bool",
    ScanComplete = "bool",
    ScanFailure = "bool",
    Destroyed = "bool"
  }
}
