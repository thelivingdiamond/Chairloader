Script.ReloadScript("scripts/Utils/EntityUtils.lua")
GeomEntity = {
  Client = {},
  Server = {},
  Editor = {
    Icon = "physicsobject.bmp",
    IconOnTop = 1
  },
  Properties = {
    bCollisionEnabled = 1,
    bCanTriggerAreas = 1,
    bDisallowGrenades = false,
    Disrupt = {
      disruptionProfile_Profile = "",
      particleeffect_SparkVFX = "",
      audioTrigger_SparkSFX = ""
    }
  }
}
SetupCollisionFiltering(GeomEntity)
function GeomEntity.Server.OnInit(A0_4708)
  A0_4708:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
  if A0_4708.Properties.bCanTriggerAreas == 1 then
    A0_4708:SetFlags(ENTITY_FLAG_TRIGGER_AREAS, 0)
  else
    A0_4708:SetFlags(ENTITY_FLAG_TRIGGER_AREAS, 2)
  end
end
function GeomEntity.Client.OnInit(A0_4709)
  A0_4709:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
  if A0_4709.Properties.bCanTriggerAreas == 1 then
    A0_4709:SetFlags(ENTITY_FLAG_TRIGGER_AREAS, 0)
  else
    A0_4709:SetFlags(ENTITY_FLAG_TRIGGER_AREAS, 2)
  end
end
function GeomEntity.Server.OnStartGame(A0_4710)
  A0_4710:UpdateCollision()
end
function GeomEntity.Client.OnPhysicsBreak(A0_4711, A1_4712, A2_4713, A3_4714)
  A0_4711:ActivateOutput("Break", A2_4713 + 1)
end
function GeomEntity.Event_Remove(A0_4715)
  A0_4715:DrawSlot(0, 0)
  A0_4715:DestroyPhysics()
  A0_4715:ActivateOutput("Remove", true)
end
function GeomEntity.Event_Hide(A0_4716)
  A0_4716:Hide(1)
  A0_4716:ActivateOutput("Hide", true)
end
function GeomEntity.Event_UnHide(A0_4717)
  A0_4717:Hide(0)
  A0_4717:ActivateOutput("UnHide", true)
end
function GeomEntity.OnPropertyChange(A0_4718)
  A0_4718:OnReset()
  A0_4718:UpdateCollision()
end
function GeomEntity.OnEditorSetGameMode(A0_4719, A1_4720)
  if A1_4720 ~= true then
    A0_4719:UpdateCollision()
  end
end
function GeomEntity.UpdateCollision(A0_4721)
  if not A0_4721:IsHidden() then
    A0_4721:EnablePhysics(A0_4721.Properties.bCollisionEnabled)
  end
  ApplyCollisionFiltering(A0_4721, GetCollisionFiltering(A0_4721))
end
GeomEntity.FlowEvents = {
  Inputs = {
    Hide = {
      GeomEntity.Event_Hide,
      "bool"
    },
    UnHide = {
      GeomEntity.Event_UnHide,
      "bool"
    },
    Remove = {
      GeomEntity.Event_Remove,
      "bool"
    }
  },
  Outputs = {
    Hide = "bool",
    UnHide = "bool",
    Remove = "bool",
    Break = "int"
  }
}
MakeTargetableByAI(GeomEntity)
MakeKillable(GeomEntity)
MakeRenderProxyOptions(GeomEntity)
