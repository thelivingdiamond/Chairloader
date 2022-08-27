local L0_7899
L0_7899 = Script
L0_7899 = L0_7899.ReloadScript
L0_7899("Scripts/Entities/Physics/BasicEntity.lua")
L0_7899 = {}
L0_7899.Properties = {
  bUseSafeCarry = false,
  textDisplayName = "Name Not Set",
  bSerialize = 0,
  bDamagesPlayerOnCollisionSP = 0,
  ability_CarryRequirement = "",
  bHideDisplayName = 0,
  bGooCannotAttachInGravity = 0,
  ei_TransparencyMode = 0,
  carryDirection = {
    x = 0,
    y = 0,
    z = 0
  },
  carryHeightOffset = 0,
  carryForwardOffset = 0,
  vector_throwParticleOffset = {
    x = 0,
    y = 0,
    z = 0
  },
  vector_ThrowAngularImpulse = {
    x = -10,
    y = 0,
    z = 0
  },
  bIsMimicable = 1,
  bIsCarryable = 1,
  bInteractiveCollision = 0,
  Sound = {
    audioTrigger_Carry = "",
    audioTrigger_HoldCarryStart = "",
    audioTrigger_HoldCarryCancel = ""
  },
  AI = {bUsedAsDynamicObstacle = 1},
  Physics = {
    signalpackage_collisionDamagePackage = "",
    bRigidBodyActive = 1,
    bActivateOnDamage = 0,
    bResting = 1,
    bCanBreakOthers = 0,
    Simulation = {
      max_time_step = 0.02,
      sleep_speed = 0.04,
      damping = 0,
      bFixedDamping = 0,
      bUseSimpleSolver = 0
    },
    Buoyancy = {
      water_density = 1000,
      water_damping = 0,
      water_resistance = 1000
    },
    CGFPropsOverride = {
      Joint = {
        limit = "",
        twist = "",
        bend = "",
        push = "",
        pull = "",
        shift = ""
      },
      Constraint = {
        constraint_limit = "",
        constraint_minang = "",
        constraint_maxang = "",
        constraint_damping = "",
        constraint_collides = ""
      },
      Deformable = {
        stiffness = "",
        thickness = "",
        max_stretch = "",
        max_impulse = "",
        skin_dist = "",
        hardness = "",
        explosion_scale = ""
      },
      player_can_break = ""
    },
    ForeignData = {bMovingPlatform = 0}
  },
  MultiplayerOptions = {bNetworked = 0},
  RecycleData = {
    organic = 0,
    mineral = 0,
    synthetic = 0,
    exotic = 0
  },
  Silhouette = {
    color_RGB = {
      x = 1,
      y = 1,
      z = 1
    },
    fAlpha = 0.25
  }
}
L0_7899.PropertiesInstance = {bUsedAsDynamicObstacle = 1}
L0_7899.Editor = {
  Icon = "physicsobject.bmp",
  IconOnTop = 1,
  IsScalable = false
}
L0_7899.States = {"Default", "Activated"}
L0_7899.bRigidBodyActive = 1
L0_7899.signalListened = "3149325216915554009"
RigidBodyEx = L0_7899
L0_7899 = {}
L0_7899.bRigidBodyActive = 0
L0_7899.bActivateOnDamage = 0
L0_7899.bResting = 1
L0_7899.Simulation = {
  max_time_step = 0.02,
  sleep_speed = 0.04,
  damping = 0,
  bFixedDamping = 0,
  bUseSimpleSolver = 0
}
L0_7899.Buoyancy = {
  water_density = 1000,
  water_damping = 0,
  water_resistance = 1000
}
MakeDerivedEntity(RigidBodyEx, BasicEntity)
function RigidBodyEx.OnSpawn(A0_7900)
  if A0_7900.Properties.MultiplayerOptions.bNetworked == 0 then
    A0_7900:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
  end
  if A0_7900.Properties.Physics.bRigidBodyActive == 1 then
    A0_7900.bRigidBodyActive = 1
  end
  A0_7900:SetFromProperties()
  A0_7900:SetupHealthProperties()
  Ark.RegisterForSignal(A0_7900.id, A0_7900.signalListened)
  g_gameRules.game:MakeMovementVisibleToAI("RigidBodyEx")
end
function RigidBodyEx.OnSignalReceived(A0_7901)
  BroadcastEvent(A0_7901, "Hit")
end
function RigidBodyEx.SetFromProperties(A0_7902)
  local L1_7903, L2_7904
  L1_7903 = A0_7902.Properties
  L2_7904 = L1_7903.object_Model
  if L2_7904 == "" then
    return
  end
  L2_7904 = A0_7902.SetDisplayName
  L2_7904(A0_7902, A0_7902.Properties.textDisplayName)
  L2_7904 = A0_7902.LoadObject
  L2_7904(A0_7902, 0, L1_7903.object_Model)
  L2_7904 = A0_7902.CharacterUpdateOnRender
  L2_7904(A0_7902, 0, 1)
  L2_7904 = A0_7902.DrawSlot
  L2_7904(A0_7902, 0, 1)
  L2_7904 = L1_7903.Physics
  L2_7904 = L2_7904.bRigidBodyActive
  A0_7902.bRigidBodyActive = L2_7904
  L2_7904 = L1_7903.Physics
  L2_7904 = L2_7904.bPhysicalize
  if L2_7904 == 1 then
    L2_7904 = A0_7902.PhysicalizeThis
    L2_7904(A0_7902)
  else
    L2_7904 = {}
    A0_7902:Physicalize(0, PE_NONE, L2_7904)
  end
  L2_7904 = A0_7902.GotoState
  L2_7904(A0_7902, "Default")
  L2_7904 = A0_7902.Properties
  L2_7904 = L2_7904.bAutoGenAIHidePts
  if L2_7904 == 1 then
    L2_7904 = A0_7902.SetFlags
    L2_7904(A0_7902, ENTITY_FLAG_AI_HIDEABLE, 0)
  else
    L2_7904 = A0_7902.SetFlags
    L2_7904(A0_7902, ENTITY_FLAG_AI_HIDEABLE, 2)
  end
  L2_7904 = A0_7902.Properties
  L2_7904 = L2_7904.bCanTriggerAreas
  if L2_7904 == 1 then
    L2_7904 = A0_7902.SetFlags
    L2_7904(A0_7902, ENTITY_FLAG_TRIGGER_AREAS, 0)
  else
    L2_7904 = A0_7902.SetFlags
    L2_7904(A0_7902, ENTITY_FLAG_TRIGGER_AREAS, 2)
  end
  A0_7902.broken = 0
end
function RigidBodyEx.GetUsable(A0_7905)
  local L2_7906, L3_7907
  L2_7906 = {}
  L3_7907 = A0_7905.Properties
  L3_7907 = L3_7907.Physics
  L3_7907 = L3_7907.Mass
  if not (L3_7907 > 0) then
    L3_7907 = A0_7905.Properties
    L3_7907 = L3_7907.Physics
    L3_7907 = L3_7907.Density
  elseif L3_7907 > 0 then
    L3_7907 = A0_7905.Properties
    L3_7907 = L3_7907.Physics
    L3_7907 = L3_7907.bPhysicalize
    if L3_7907 == 1 then
      L3_7907 = A0_7905.Properties
      L3_7907 = L3_7907.bIsCarryable
      if L3_7907 == 1 then
        L3_7907 = {}
        L3_7907.ActionType = "Carry"
        if A0_7905.Properties.ability_CarryRequirement == "" then
          L3_7907.DisplayText = ""
        end
        L2_7906.Use = L3_7907
      end
    end
  end
  return L2_7906
end
function RigidBodyEx.GetRemoteManipulationInteraction(A0_7908)
  local L1_7909, L2_7910
  L1_7909 = {}
  L2_7910 = A0_7908.Properties
  L2_7910 = L2_7910.Physics
  L2_7910 = L2_7910.Mass
  if not (L2_7910 > 0) then
    L2_7910 = A0_7908.Properties
    L2_7910 = L2_7910.Physics
    L2_7910 = L2_7910.Density
  elseif L2_7910 > 0 then
    L2_7910 = A0_7908.Properties
    L2_7910 = L2_7910.Physics
    L2_7910 = L2_7910.bPhysicalize
    if L2_7910 == 1 then
      L2_7910 = A0_7908.Properties
      L2_7910 = L2_7910.bIsCarryable
      if L2_7910 == 1 then
        L1_7909.ActionType = "Carry"
      end
    end
  end
  L1_7909.CouldChange = false
  return L1_7909
end
function RigidBodyEx.PhysicalizeThis(A0_7911)
  local L1_7912
  L1_7912 = A0_7911.Properties
  L1_7912 = L1_7912.Physics
  if CryAction.IsImmersivenessEnabled() == 0 then
    L1_7912 = _UPVALUE0_
  end
  EntityCommon.PhysicalizeRigid(A0_7911, 0, L1_7912, A0_7911.bRigidBodyActive)
end
function RigidBodyEx.OnPropertyChange(A0_7913)
  A0_7913:SetFromProperties()
end
function RigidBodyEx.OnReset(A0_7914)
  A0_7914:ResetOnUsed()
  if A0_7914.Properties.Physics.bPhysicalize == 1 then
    if A0_7914:IsInState("Default") ~= 0 then
      A0_7914:AwakePhysics(1 - A0_7914.Properties.Physics.bResting)
    end
    A0_7914:GotoState("Default")
  end
  A0_7914:SetupHealthProperties()
  A0_7914.broken = 0
end
function RigidBodyEx.Event_Remove(A0_7915)
  A0_7915:DrawSlot(0, 0)
  A0_7915:DestroyPhysics()
  A0_7915:ActivateOutput("Remove", true)
end
function RigidBodyEx.Event_Hide(A0_7916)
  A0_7916:Hide(1)
  A0_7916:ActivateOutput("Hide", true)
end
function RigidBodyEx.Event_UnHide(A0_7917)
  A0_7917:Hide(0)
  A0_7917:ActivateOutput("UnHide", true)
end
function RigidBodyEx.Event_Ragdollize(A0_7918)
  A0_7918:RagDollize(0)
  A0_7918:ActivateOutput("Ragdollized", true)
end
function RigidBodyEx.OnPhysicsBreak(A0_7919, A1_7920, A2_7921, A3_7922)
  A0_7919:ActivateOutput("Break", A2_7921 + 1)
  A0_7919.broken = 1
end
function RigidBodyEx.OnDamage(A0_7923, A1_7924)
end
function RigidBodyEx.GetUsableMessage(A0_7925, A1_7926)
  return A0_7925.Properties.textDisplayName
end
function RigidBodyEx.Event_Activate(A0_7927, A1_7928)
  A0_7927:GotoState("Default")
  A0_7927:GotoState("Activated")
end
function RigidBodyEx.CommonSwitchToMaterial(A0_7929, A1_7930)
  if not A0_7929.sOriginalMaterial then
    A0_7929.sOriginalMaterial = A0_7929:GetMaterial()
  end
  if A0_7929.sOriginalMaterial then
    A0_7929:SetMaterial(A0_7929.sOriginalMaterial .. A1_7930)
  end
end
function RigidBodyEx.Event_SwitchToMaterialOriginal(A0_7931, A1_7932)
  A0_7931:CommonSwitchToMaterial("")
end
function RigidBodyEx.Event_SwitchToMaterial1(A0_7933, A1_7934)
  A0_7933:CommonSwitchToMaterial("1")
end
function RigidBodyEx.Event_SwitchToMaterial2(A0_7935, A1_7936)
  A0_7935:CommonSwitchToMaterial("2")
end
RigidBodyEx.Server.Default = {
  OnBeginState = function(A0_7937)
    if A0_7937.Properties.Physics.bRigidBody == 1 then
      if A0_7937.bRigidBodyActive ~= A0_7937.Properties.Physics.bRigidBodyActive then
        A0_7937.bRigidBodyActive = A0_7937.Properties.Physics.bRigidBodyActive
        A0_7937:PhysicalizeThis()
      else
        A0_7937:AwakePhysics(1 - A0_7937.Properties.Physics.bResting)
      end
    end
  end,
  OnDamage = RigidBodyEx.OnDamage,
  OnPhysicsBreak = RigidBodyEx.OnPhysicsBreak
}
RigidBodyEx.Server.Activated = {
  OnBeginState = function(A0_7938)
    if A0_7938.Properties.Physics.bRigidBody == 1 and A0_7938.bRigidBodyActive == 0 then
      A0_7938.bRigidBodyActive = 1
      A0_7938:PhysicalizeThis()
      A0_7938:AwakePhysics(1)
    end
  end,
  OnDamage = RigidBodyEx.OnDamage,
  OnPhysicsBreak = RigidBodyEx.OnPhysicsBreak
}
RigidBodyEx.FlowEvents = {
  Inputs = {
    Used = {
      RigidBodyEx.Event_Used,
      "bool"
    },
    EnableUsable = {
      RigidBodyEx.Event_EnableUsable,
      "bool"
    },
    DisableUsable = {
      RigidBodyEx.Event_DisableUsable,
      "bool"
    },
    Activate = {
      RigidBodyEx.Event_Activate,
      "bool"
    },
    Hide = {
      RigidBodyEx.Event_Hide,
      "bool"
    },
    UnHide = {
      RigidBodyEx.Event_UnHide,
      "bool"
    },
    Remove = {
      RigidBodyEx.Event_Remove,
      "bool"
    },
    Ragdollize = {
      RigidBodyEx.Event_Ragdollize,
      "bool"
    },
    SwitchToMaterial1 = {
      RigidBodyEx.Event_SwitchToMaterial1,
      "bool"
    },
    SwitchToMaterial2 = {
      RigidBodyEx.Event_SwitchToMaterial2,
      "bool"
    },
    SwitchToMaterialOriginal = {
      RigidBodyEx.Event_SwitchToMaterialOriginal,
      "bool"
    },
    ResetHealth = {
      RigidBodyEx.Event_ResetHealth,
      "any"
    },
    MakeVulnerable = {
      RigidBodyEx.Event_MakeVulnerable,
      "any"
    },
    MakeInvulnerable = {
      RigidBodyEx.Event_MakeInvulnerable,
      "any"
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
    Break = "int",
    Dead = "bool",
    Hit = "bool",
    Health = "float"
  }
}
