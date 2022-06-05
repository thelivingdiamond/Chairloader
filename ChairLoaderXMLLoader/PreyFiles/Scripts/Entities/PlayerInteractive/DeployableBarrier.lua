Script.ReloadScript("Scripts/Entities/Others/InteractiveEntity.lua")
Script.ReloadScript("Scripts/Entities/PlayerInteractive/InteractiveObjectEx.lua")
DeployableBarrier = {
  type = "DeployableBarrier",
  Properties = {
    bUsable = 1,
    Interaction = {
      object_Model = "Objects/props/military_infrastructure/mil_barrier/mil_barrier_2m_lp_hole.cga",
      Interaction = "barrier2m_hole",
      InteractionRadius = 1.5,
      InteractionAngle = 70
    },
    Physics = {bRigidBody = 1}
  },
  Editor = {
    Icon = "animobject.bmp",
    IconOnTop = 1
  }
}
function DeployableBarrier.StopUse(A0_7991, A1_7992, A2_7993)
  InteractiveObjectEx.StopUse(A0_7991, A1_7992, A2_7993)
  AI.AddCoverEntity(A0_7991.id)
end
mergef(DeployableBarrier, InteractiveObjectEx, 1)
DeployableBarrier.FlowEvents = {
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
    }
  },
  Outputs = {
    Started = "bool",
    Finished = "bool",
    Enabled = "bool",
    Disabled = "bool",
    Hide = "bool",
    UnHide = "bool"
  }
}
