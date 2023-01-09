InteractiveObjectEx = {
  type = "InteractiveObjectEx",
  Properties = {
    Interaction = {
      object_Model = "Objects/prototype/ElevatorDoors/AnimatedElevatorDoors.cga",
      Interaction = "OpenElevatorDoor",
      InteractionRadius = 1.5,
      InteractionAngle = 70,
      bRemoveDecalsOnUse = 0,
      bStartInteractionOnExplosion = 0
    },
    Physics = {bRigidBody = 0}
  },
  Editor = {
    Icon = "animobject.bmp",
    IconOnTop = 1
  },
  userId = NULL_ENTITY
}
function InteractiveObjectEx.OnInit(A0_7994)
  A0_7994:OnReset()
end
function InteractiveObjectEx.OnPropertyChange(A0_7995)
  A0_7995:OnReset()
end
function InteractiveObjectEx.OnReset(A0_7996)
  local L1_7997
  L1_7997 = A0_7996.Properties
  L1_7997 = L1_7997.bUsable
  A0_7996.bUsable = L1_7997
end
function InteractiveObjectEx.OnSave(A0_7998, A1_7999)
  local L2_8000
  L2_8000 = A0_7998.bUsable
  A1_7999.bUsable = L2_8000
  L2_8000 = A0_7998.userId
  A1_7999.userId = L2_8000
end
function InteractiveObjectEx.OnLoad(A0_8001, A1_8002)
  local L2_8003
  L2_8003 = A1_8002.bUsable
  A0_8001.bUsable = L2_8003
  L2_8003 = A1_8002.userId
  A0_8001.userId = L2_8003
end
function InteractiveObjectEx.OnShutDown(A0_8004)
  local L1_8005
end
function InteractiveObjectEx.Event_Use(A0_8006)
  A0_8006.interactiveObject:Use(A0_8006.userId)
  A0_8006:ActivateOutput("Started", true)
end
function InteractiveObjectEx.Event_UserId(A0_8007, A1_8008, A2_8009)
  A0_8007.userId = A2_8009.id
end
function InteractiveObjectEx.Event_Hide(A0_8010)
  A0_8010:Hide(1)
  A0_8010:ActivateOutput("Hide", true)
end
function InteractiveObjectEx.Event_UnHide(A0_8011)
  A0_8011:Hide(0)
  A0_8011:ActivateOutput("UnHide", true)
end
function InteractiveObjectEx.Event_EnableUsable(A0_8012)
  A0_8012.bUsable = 1
  A0_8012:ActivateOutput("Enabled", true)
end
function InteractiveObjectEx.Event_DisableUsable(A0_8013)
  A0_8013.bUsable = 0
  A0_8013:ActivateOutput("Disabled", true)
end
function InteractiveObjectEx.Event_Reset(A0_8014)
  Game.ResetEntity(A0_8014.id)
  A0_8014:ActivateOutput("Reset", true)
end
InteractiveObjectEx.FlowEvents = {
  Inputs = {
    Use = {
      InteractiveObjectEx.Event_Use,
      "bool"
    },
    UserId = {
      InteractiveObjectEx.Event_UserId,
      "entity"
    },
    Hide = {
      InteractiveObjectEx.Event_Hide,
      "bool"
    },
    UnHide = {
      InteractiveObjectEx.Event_UnHide,
      "bool"
    },
    Enable = {
      InteractiveObjectEx.Event_EnableUsable,
      "bool"
    },
    Disable = {
      InteractiveObjectEx.Event_DisableUsable,
      "bool"
    },
    Reset = {
      InteractiveObjectEx.Event_Reset,
      "bool"
    }
  },
  Outputs = {
    Started = "bool",
    Finished = "bool",
    Aborted = "bool",
    Enabled = "bool",
    Disabled = "bool",
    Hide = "bool",
    UnHide = "bool",
    Reset = "bool",
    UsedBy = "entity"
  }
}
MakeUsable(InteractiveObjectEx)
function InteractiveObjectEx.IsUsable(A0_8015, A1_8016)
  if A0_8015.bUsable ~= 0 then
    return A0_8015.interactiveObject:CanUse(A1_8016.id)
  else
    return 0
  end
end
function InteractiveObjectEx.OnUsed(A0_8017, A1_8018, A2_8019)
  A0_8017.interactiveObject:Use(A1_8018.id)
  A0_8017:ActivateOutput("UsedBy", A1_8018.id)
  A0_8017:ActivateOutput("Started", true)
  BroadcastEvent(A0_8017, "Used")
end
function InteractiveObjectEx.StopUse(A0_8020, A1_8021, A2_8022)
  A0_8020.interactiveObject:StopUse(A1_8021)
  A0_8020:ActivateOutput("Finished", true)
end
function InteractiveObjectEx.AbortUse(A0_8023, A1_8024)
  A0_8023.interactiveObject:AbortUse()
  A0_8023:ActivateOutput("Aborted", true)
end
