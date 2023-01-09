MineField = {
  type = "MineField",
  Properties = {
    TacticalInfo = {bScannable = 1, LookupName = ""}
  },
  Editor = {Icon = "mine.bmp"},
  Client = {},
  Server = {}
}
MakeUsable(MineField)
function MineField.OnSave(A0_5179, A1_5180)
  A1_5180.bUsable = A0_5179.bUsable
end
function MineField.OnLoad(A0_5181, A1_5182)
  A0_5181:OnReset()
  A0_5181.bUsable = A1_5182.bUsable
end
function MineField.Client.OnInit(A0_5183)
  A0_5183:OnReset()
end
function MineField.OnReset(A0_5184)
  local L1_5185
  L1_5185 = A0_5184.Properties
  L1_5185 = L1_5185.bUsable
  A0_5184.bUsable = L1_5185
end
function MineField.OnUsed(A0_5186, A1_5187, A2_5188)
end
function MineField.IsUsable(A0_5189, A1_5190)
  if A0_5189.bUsable == 1 then
    return 2
  end
  return 0
end
function MineField.OnPropertyChange(A0_5191)
  local L1_5192
end
function MineField.HasBeenScanned(A0_5193)
  Game.SendEventToGameObject(A0_5193.id, "OnScanned")
  A0_5193:ActivateOutput("Scanned", true)
end
function MineField.Event_SetScanned(A0_5194)
  A0_5194:HasBeenScanned()
end
function MineField.Event_Destroy(A0_5195)
  Game.SendEventToGameObject(A0_5195.id, "OnDestroy")
  A0_5195:ActivateOutput("Destroyed", true)
end
MineField.FlowEvents = {
  Inputs = {
    SetScanned = {
      MineField.Event_SetScanned,
      "bool"
    },
    SetDestroyed = {
      MineField.Event_Destroy,
      "bool"
    }
  },
  Outputs = {Scanned = "bool", Destroyed = "bool"}
}
