local L0_7470
L0_7470 = Script
L0_7470 = L0_7470.ReloadScript
L0_7470("scripts/Utils/EntityUtils.lua")
L0_7470 = {}
L0_7470.Properties = {
  soclasses_SmartObjectClass = "",
  bMissionCritical = 0,
  bCanTriggerAreas = 0,
  DmgFactorWhenCollidingAI = 1,
  object_Model = "",
  Physics = {
    bPhysicalize = 1,
    bRigidBody = 1,
    bPushableByPlayers = 1,
    bPushableByAI = 1,
    Density = -1,
    Mass = -1
  },
  MultiplayerOptions = {bNetworked = 0},
  bExcludeCover = 0,
  bIsMimicable = true
}
L0_7470.Client = {}
L0_7470.Server = {}
L0_7470._Flags = {}
L0_7470.Editor = {
  Icon = "physicsobject.bmp",
  IconOnTop = 1
}
BasicEntity = L0_7470
L0_7470 = {}
L0_7470.bPhysicalize = 1
L0_7470.bPushableByPlayers = 0
L0_7470.bPushableByAI = 0
L0_7470.Density = 0
L0_7470.Mass = 0
function BasicEntity.OnSpawn(A0_7471)
  if A0_7471.Properties.MultiplayerOptions.bNetworked == 0 then
    A0_7471:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
  end
  A0_7471.bRigidBodyActive = 1
  A0_7471:SetFromProperties()
end
function BasicEntity.SetFromProperties(A0_7472)
  local L1_7473
  L1_7473 = A0_7472.Properties
  if L1_7473.object_Model == "" then
    return
  end
  A0_7472.freezable = tonumber(L1_7473.bFreezable) ~= 0
  A0_7472:SetupModel()
  if L1_7473.bAutoGenAIHidePts == 1 then
    A0_7472:SetFlags(ENTITY_FLAG_AI_HIDEABLE, 0)
  else
    A0_7472:SetFlags(ENTITY_FLAG_AI_HIDEABLE, 2)
  end
  if A0_7472.Properties.bCanTriggerAreas == 1 then
    A0_7472:SetFlags(ENTITY_FLAG_TRIGGER_AREAS, 0)
  else
    A0_7472:SetFlags(ENTITY_FLAG_TRIGGER_AREAS, 2)
  end
end
function BasicEntity.SetupModel(A0_7474)
  local L1_7475
  L1_7475 = A0_7474.Properties
  A0_7474:LoadObject(0, L1_7475.object_Model)
  if L1_7475.Physics.bPhysicalize == 1 then
    A0_7474:PhysicalizeThis()
  end
end
function BasicEntity.IsRigidBody(A0_7476)
  local L1_7477
  L1_7477 = A0_7476.Properties
  if L1_7477.Mass == 0 or L1_7477.Density == 0 or L1_7477.bPhysicalize ~= 1 then
    return false
  end
  return true
end
function BasicEntity.PhysicalizeThis(A0_7478)
  local L1_7479
  L1_7479 = A0_7478.Properties
  L1_7479 = L1_7479.Physics
  if CryAction.IsImmersivenessEnabled() == 0 then
    L1_7479 = _UPVALUE0_
  end
  EntityCommon.PhysicalizeRigid(A0_7478, 0, L1_7479, A0_7478.bRigidBodyActive)
end
function BasicEntity.OnPropertyChange(A0_7480)
  if A0_7480.__usable and (A0_7480.__origUsable ~= A0_7480.Properties.bUsable or A0_7480.__origPickable ~= A0_7480.Properties.bPickable) then
    A0_7480.__usable = nil
  end
  A0_7480:SetFromProperties()
end
function BasicEntity.OnReset(A0_7481)
  A0_7481:ResetOnUsed()
  A0_7481:DrawSlot(0, 1)
  if A0_7481.Properties.Physics.bPhysicalize == 1 then
    A0_7481:PhysicalizeThis()
    A0_7481:AwakePhysics(0)
  end
end
function BasicEntity.Event_Remove(A0_7482)
  A0_7482:DrawSlot(0, 0)
  A0_7482:DestroyPhysics()
  A0_7482:ActivateOutput("Remove", true)
end
function BasicEntity.Event_Hide(A0_7483)
  A0_7483:Hide(1)
  A0_7483:ActivateOutput("Hide", true)
  if CurrentCinematicName then
    Log("%.3f %s %s : Event_Hide", _time, CurrentCinematicName, A0_7483:GetName())
  end
end
function BasicEntity.Event_UnHide(A0_7484)
  A0_7484:Hide(0)
  A0_7484:ActivateOutput("UnHide", true)
  if CurrentCinematicName then
    Log("%.3f %s %s : Event_UnHide", _time, CurrentCinematicName, A0_7484:GetName())
  end
end
function BasicEntity.Event_Ragdollize(A0_7485)
  A0_7485:RagDollize(0)
  A0_7485:ActivateOutput("Ragdollized", true)
  if A0_7485.Event_RagdollizeDerived then
    A0_7485:Event_RagdollizeDerived()
  end
end
function BasicEntity.Client.OnPhysicsBreak(A0_7486, A1_7487, A2_7488, A3_7489)
  A0_7486:ActivateOutput("Break", A2_7488 + 1)
end
function BasicEntity.IsUsable(A0_7490, A1_7491)
  if not A0_7490.__usable then
    A0_7490.__usable = A0_7490.Properties.bUsable
  end
  if System.IsMultiplayer() and System.IsMultiplayer() ~= 0 then
    return 0
  end
  return 2 or 0
end
BasicEntity.FlowEvents = {
  Inputs = {
    Used = {
      BasicEntity.Event_Used,
      "bool"
    },
    EnableUsable = {
      BasicEntity.Event_EnableUsable,
      "bool"
    },
    DisableUsable = {
      BasicEntity.Event_DisableUsable,
      "bool"
    },
    Hide = {
      BasicEntity.Event_Hide,
      "bool"
    },
    UnHide = {
      BasicEntity.Event_UnHide,
      "bool"
    },
    Remove = {
      BasicEntity.Event_Remove,
      "bool"
    },
    Ragdollize = {
      BasicEntity.Event_Ragdollize,
      "bool"
    }
  },
  Outputs = {
    Used = "bool",
    EnableUsable = "bool",
    DisableUsable = "bool",
    Activate = "bool",
    Hide = "bool",
    UnHide = "bool",
    Remove = "bool",
    Ragdollized = "bool",
    Break = "int"
  }
}
MakeUsable(BasicEntity)
MakePickable(BasicEntity)
MakeTargetableByAI(BasicEntity)
MakeKillable(BasicEntity)
AddHeavyObjectProperty(BasicEntity)
SetupCollisionFiltering(BasicEntity)
