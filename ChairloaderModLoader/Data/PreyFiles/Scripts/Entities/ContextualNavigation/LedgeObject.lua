Script.ReloadScript("Scripts/Entities/ContextualNavigation/LedgeObjectStatic.lua")
LedgeObject = {
  Properties = {
    bEnabled = 1,
    bIsThin = 0,
    bIsWindow = 0,
    bLedgeDoubleSide = 0,
    bLedgeFlipped = 0,
    fCornerMaxAngle = 130,
    fCornerEndAdjustAmount = 0.5,
    MainSide = {
      bEndCrouched = 0,
      bEndFalling = 0,
      bUsableByMarines = 1,
      esLedgeType = "Normal"
    },
    OppositeSide = {
      bEndCrouched = 0,
      bEndFalling = 0,
      bUsableByMarines = 1,
      esLedgeType = "Normal"
    }
  },
  Client = {},
  Server = {},
  Editor = {Icon = "ledge.bmp", ShowBounds = 1}
}
function LedgeObject.OnPropertyChange(A0_4681)
  local L1_4682
end
function LedgeObject.IsShapeOnly(A0_4683)
  return LedgeObjectStatic.IsShapeOnly(A0_4683)
end
function LedgeObject.IsClosed(A0_4684)
  return LedgeObjectStatic.IsClosed(A0_4684)
end
function LedgeObject.ShapeMinPoints(A0_4685)
  return LedgeObjectStatic.ShapeMinPoints(A0_4685)
end
function LedgeObject.ShapeMaxPoints(A0_4686)
  return LedgeObjectStatic.ShapeMaxPoints(A0_4686)
end
function LedgeObject.OnSpawn(A0_4687)
  A0_4687:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
  A0_4687:SetFlags(ENTITY_FLAG_NO_PROXIMITY, 0)
end
function LedgeObject.Event_Enable(A0_4688)
  Game.SendEventToGameObject(A0_4688.id, "enable")
  BroadcastEvent(A0_4688, "Enable")
end
function LedgeObject.Event_Disable(A0_4689)
  Game.SendEventToGameObject(A0_4689.id, "disable")
  BroadcastEvent(A0_4689, "Disable")
end
function LedgeObject.StartUse(A0_4690, A1_4691)
  A0_4690:ActivateOutput("StartUse", A1_4691)
end
LedgeObject.FlowEvents = {
  Inputs = {
    Disable = {
      LedgeObject.Event_Disable,
      "bool"
    },
    Enable = {
      LedgeObject.Event_Enable,
      "bool"
    }
  },
  Outputs = {
    Disable = "bool",
    Enable = "bool",
    StartUse = "entity"
  }
}
