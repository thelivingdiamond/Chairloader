Switch = {
  Client = {},
  Server = {},
  Properties = {
    fileModel = "engine/engineassets/objects/default.cgf",
    Switch = "Props_Interactive.switches.small_switch",
    ModelSubObject = "",
    fileModelDestroyed = "",
    DestroyedSubObject = "",
    fHealth = 100,
    bDestroyable = 0,
    bUsable = 1,
    UseMessage = "Use Light Switch",
    bTurnedOn = 0,
    Physics = {
      bRigidBody = 0,
      bRigidBodyActive = 0,
      bRigidBodyAfterDeath = 1,
      bResting = 1,
      Density = -1,
      Mass = 1
    },
    Sound = {soundTurnOnSound = "", soundTurnOffSound = ""},
    SwitchPos = {
      bShowSwitch = 1,
      On = 35,
      Off = -35
    },
    SmartSwitch = {
      bUseSmartSwitch = 0,
      Entity = "",
      TurnedOnEvent = "",
      TurnedOffEvent = ""
    },
    Breakage = {
      fLifeTime = 20,
      fExplodeImpulse = 0,
      bSurfaceEffects = 1
    },
    Destruction = {
      bExplode = 0,
      Effect = "",
      EffectScale = 0,
      Radius = 0,
      Pressure = 0,
      Damage = 0,
      Decal = "",
      Direction = {
        x = 0,
        y = 0,
        z = -1
      }
    }
  },
  Editor = {Icon = "switch.bmp", IconOnTop = 1},
  States = {
    "TurnedOn",
    "TurnedOff",
    "Destroyed"
  },
  fCurrentSpeed = 0,
  fDesiredSpeed = 0,
  LastHit = {
    impulse = {
      x = 0,
      y = 0,
      z = 0
    },
    pos = {
      x = 0,
      y = 0,
      z = 0
    }
  },
  shooterId = nil
}
Net.Expose({
  Class = Switch,
  ClientMethods = {
    OnUsed_Internal = {
      RELIABLE_ORDERED,
      PRE_ATTACH,
      ENTITYID
    },
    Destroy = {RELIABLE_ORDERED, PRE_ATTACH}
  },
  ServerMethods = {
    SvRequestUse = {
      RELIABLE_ORDERED,
      PRE_ATTACH,
      ENTITYID
    }
  }
})
function Switch.OnPropertyChange(A0_7229)
  A0_7229:OnReset()
end
function Switch.OnSave(A0_7230, A1_7231)
  local L2_7232
  L2_7232 = A0_7230.switch
  A1_7231.switch = L2_7232
  L2_7232 = A0_7230.usable
  A1_7231.usable = L2_7232
end
function Switch.OnLoad(A0_7233, A1_7234)
  A0_7233.switch = A1_7234.switch
  A0_7233.usable = A1_7234.usable
  if A0_7233:GetState() ~= "Destroyed" then
    A0_7233:PhysicalizeThis(0)
    A0_7233:SetCurrentSlot(0)
  else
    A0_7233.Properties.Physics.bRigidBody = A0_7233.Properties.Physics.bRigidBodyAfterDeath
    A0_7233:PhysicalizeThis(1)
    A0_7233.Properties.Physics.bRigidBody = A0_7233.Properties.Physics.bRigidBody
    A0_7233:SetCurrentSlot(1)
  end
end
function Switch.OnReset(A0_7235)
  local L1_7236
  L1_7236 = A0_7235.Properties
  A0_7235.health = L1_7236.fHealth
  A0_7235.usable = A0_7235.Properties.bUsable
  if not EmptyString(L1_7236.fileModel) then
    A0_7235:LoadSubObject(0, L1_7236.fileModel, L1_7236.ModelSubObject)
  end
  if not EmptyString(L1_7236.fileModelDestroyed) then
    A0_7235:LoadSubObject(1, L1_7236.fileModelDestroyed, L1_7236.DestroyedSubObject)
  elseif not EmptyString(L1_7236.DestroyedSubObject) then
    A0_7235:LoadSubObject(1, L1_7236.fileModel, L1_7236.DestroyedSubObject)
  end
  A0_7235:SetCurrentSlot(0)
  A0_7235:PhysicalizeThis(0)
  if not EmptyString(A0_7235.Properties.Switch) then
    A0_7235:SpawnSwitch()
  end
  if A0_7235.Properties.bTurnedOn == 1 then
    A0_7235:GotoState("TurnedOn")
  else
    A0_7235:GotoState("TurnedOff")
  end
end
function Switch.PhysicalizeThis(A0_7237, A1_7238)
  local L2_7239
  L2_7239 = A0_7237.Properties
  L2_7239 = L2_7239.Physics
  EntityCommon.PhysicalizeRigid(A0_7237, A1_7238, L2_7239, 1)
end
function Switch.Client.OnHit(A0_7240, A1_7241, A2_7242)
  CopyVector(A0_7240.LastHit.pos, A1_7241.pos)
  CopyVector(A0_7240.LastHit.impulse, A1_7241.dir)
  A0_7240.LastHit.impulse.x = A0_7240.LastHit.impulse.x * A1_7241.damage
  A0_7240.LastHit.impulse.y = A0_7240.LastHit.impulse.y * A1_7241.damage
  A0_7240.LastHit.impulse.z = A0_7240.LastHit.impulse.z * A1_7241.damage
end
function Switch.Server.OnHit(A0_7243, A1_7244)
  A0_7243.shooterId = A1_7244.shooterId
  BroadcastEvent(A0_7243, "Hit")
  if A0_7243.Properties.bDestroyable == 1 then
    A0_7243.health = A0_7243.health - A1_7244.damage
    if A0_7243.health <= 0 then
      A0_7243.allClients:Destroy()
    end
  end
end
function Switch.Explode(A0_7245)
  local L1_7246, L2_7247, L3_7248
  L1_7246 = A0_7245.Properties
  L2_7247 = A0_7245.LastHit
  L2_7247 = L2_7247.pos
  L3_7248 = A0_7245.LastHit
  L3_7248 = L3_7248.impulse
  A0_7245:BreakToPieces(0, 0, L1_7246.Breakage.fExplodeImpulse, L2_7247, L3_7248, L1_7246.Breakage.fLifeTime, L1_7246.Breakage.bSurfaceEffects)
  if NumberToBool(A0_7245.Properties.Destruction.bExplode) then
    g_gameRules:CreateExplosion(A0_7245.shooterId, A0_7245.id, A0_7245.Properties.Destruction.Damage, A0_7245:GetWorldPos(), A0_7245.Properties.Destruction.Direction, A0_7245.Properties.Destruction.Radius, nil, A0_7245.Properties.Destruction.Pressure, A0_7245.Properties.Destruction.HoleSize, A0_7245.Properties.Destruction.Effect, A0_7245.Properties.Destruction.EffectScale)
  end
  A0_7245:SetCurrentSlot(1)
  if L1_7246.Physics.bRigidBodyAfterDeath == 1 then
    L1_7246.Physics.bRigidBody = 1
    A0_7245:PhysicalizeThis(1)
    L1_7246.Physics.bRigidBody = L1_7246.Physics.bRigidBody
  else
    A0_7245:PhysicalizeThis(1)
  end
  A0_7245:RemoveDecals()
  A0_7245:AwakePhysics(1)
  A0_7245:OnDestroy()
end
function Switch.SetCurrentSlot(A0_7249, A1_7250)
  if A1_7250 == 0 then
    A0_7249:DrawSlot(0, 1)
    A0_7249:DrawSlot(1, 0)
  else
    A0_7249:DrawSlot(0, 0)
    A0_7249:DrawSlot(1, 1)
  end
  A0_7249.currentSlot = A1_7250
end
function Switch.SetSwitch(A0_7251, A1_7252)
  local L2_7253, L3_7254, L4_7255
  L2_7253 = A0_7251.switch
  if L2_7253 == nil then
    return
  end
  L2_7253 = A0_7251.Properties
  L2_7253 = L2_7253.SwitchPos
  L3_7254 = L2_7253.bShowSwitch
  if L3_7254 == 0 then
    return
  end
  L3_7254 = A0_7251.Properties
  L3_7254 = L3_7254.SwitchPos
  L4_7255 = {}
  L4_7255.x = 0
  L4_7255.y = 0
  L4_7255.z = 0
  if A1_7252 == 1 then
    A0_7251.switch:GetAngles(L4_7255)
    L4_7255.y = L3_7254.On * g_Deg2Rad
  else
    A0_7251.switch:GetAngles(L4_7255)
    L4_7255.y = L3_7254.Off * g_Deg2Rad
  end
  A0_7251.switch:SetAngles(L4_7255)
end
function Switch.SpawnSwitch(A0_7256)
  local L1_7257, L2_7258, L3_7259
  L1_7257 = A0_7256.switch
  if L1_7257 then
    L1_7257 = Entity
    L1_7257 = L1_7257.DetachThis
    L2_7258 = A0_7256.switch
    L2_7258 = L2_7258.id
    L3_7259 = 0
    L1_7257(L2_7258, L3_7259)
    L1_7257 = System
    L1_7257 = L1_7257.RemoveEntity
    L2_7258 = A0_7256.switch
    L2_7258 = L2_7258.id
    L1_7257(L2_7258)
    A0_7256.switch = nil
  end
  L1_7257 = A0_7256.Properties
  L1_7257 = L1_7257.SwitchPos
  L2_7258 = L1_7257.bShowSwitch
  if L2_7258 == 0 then
    return
  end
  L2_7258 = A0_7256.switch
  if L2_7258 == nil then
    L2_7258 = A0_7256.Properties
    L2_7258 = L2_7258.Switch
    if L2_7258 == "" then
      L2_7258 = Log
      L3_7259 = "No switch found for switch object "
      L3_7259 = L3_7259 .. A0_7256:GetName()
      L2_7258(L3_7259)
    else
      L2_7258 = {}
      L2_7258.class = "BasicEntity"
      L3_7259 = Log
      L3_7259("self.Properties.Switch: " .. A0_7256.Properties.Switch)
      L3_7259 = A0_7256.Properties
      L3_7259 = L3_7259.Switch
      L2_7258.archetype = L3_7259
      L3_7259 = A0_7256.GetName
      L3_7259 = L3_7259(A0_7256)
      L3_7259 = L3_7259 .. "_switch"
      L2_7258.name = L3_7259
      L2_7258.flags = 0
      L3_7259 = A0_7256.GetPos
      L3_7259 = L3_7259(A0_7256)
      L2_7258.position = L3_7259
      L3_7259 = System
      L3_7259 = L3_7259.SpawnEntity
      L3_7259 = L3_7259(L2_7258)
      A0_7256.switch = L3_7259
      L3_7259 = A0_7256.AttachChild
      L3_7259(A0_7256, A0_7256.switch.id, 0)
      L3_7259 = A0_7256.switch
      L3_7259 = L3_7259.SetWorldPos
      L3_7259(L3_7259, A0_7256:GetPos())
      L3_7259 = {}
      L3_7259.x = 0
      L3_7259.y = 0
      L3_7259.z = 0
      if A0_7256.Properties.bTurnedOn == 1 then
        L3_7259.y = L1_7257.On * g_Deg2Rad
      else
        L3_7259.y = L1_7257.Off * g_Deg2Rad
      end
      A0_7256.switch:SetAngles(L3_7259)
    end
  else
    L2_7258 = A0_7256.Properties
    L2_7258 = L2_7258.bTurnedOn
    if L2_7258 == 1 then
      L2_7258 = A0_7256.switch
      L3_7259 = L2_7258
      L2_7258 = L2_7258.GetAngles
      L2_7258 = L2_7258(L3_7259)
      L3_7259 = L1_7257.On
      L3_7259 = L3_7259 * g_Deg2Rad
      if L2_7258 ~= L3_7259 then
        L2_7258 = {}
        L2_7258.x = 0
        L2_7258.y = 0
        L2_7258.z = 0
        L3_7259 = A0_7256.GetAngles
        L3_7259(A0_7256, L2_7258)
        L3_7259 = L1_7257.On
        L3_7259 = L3_7259 * g_Deg2Rad
        L2_7258.y = L3_7259
        L3_7259 = A0_7256.switch
        L3_7259 = L3_7259.SetAngles
        L3_7259(L3_7259, L2_7258)
      end
    else
      L2_7258 = A0_7256.switch
      L3_7259 = L2_7258
      L2_7258 = L2_7258.GetAngles
      L2_7258 = L2_7258(L3_7259)
      L3_7259 = L1_7257.Off
      L3_7259 = L3_7259 * g_Deg2Rad
      if L2_7258 ~= L3_7259 then
        L2_7258 = {}
        L2_7258.x = 0
        L2_7258.y = 0
        L2_7258.z = 0
        L3_7259 = A0_7256.GetAngles
        L3_7259(A0_7256, L2_7258)
        L3_7259 = L1_7257.Off
        L3_7259 = L3_7259 * g_Deg2Rad
        L2_7258.y = L3_7259
        L3_7259 = A0_7256.switch
        L3_7259 = L3_7259.SetAngles
        L3_7259(L3_7259, L2_7258)
      end
    end
  end
end
function Switch.OnDestroy(A0_7260)
  if A0_7260.switch then
    Entity.DetachThis(A0_7260.switch.id, 0)
    System.RemoveEntity(A0_7260.switch.id)
    A0_7260.switch = nil
  end
end
function Switch.Server.OnInit(A0_7261)
  if not A0_7261.bInitialized then
    A0_7261:OnReset()
    A0_7261.bInitialized = 1
    A0_7261.usable = A0_7261.Properties.bUsable
  end
end
function Switch.Client.OnInit(A0_7262)
  if not A0_7262.bInitialized then
    A0_7262:OnReset()
    A0_7262.bInitialized = 1
  end
end
function Switch.OnUsed(A0_7263, A1_7264, A2_7265)
  if not A0_7263.iUseCount then
    A0_7263.iUseCount = 0
  end
  A0_7263.iUseCount = A0_7263.iUseCount + 1
  System.Log("Used this many times: " .. tostring(A0_7263.iUseCount))
  A0_7263.server:SvRequestUse(A1_7264.id)
end
function Switch.Server.SvRequestUse(A0_7266, A1_7267)
  A0_7266.allClients:OnUsed_Internal(A1_7267)
end
function Switch.Client.OnUsed_Internal(A0_7268, A1_7269)
  A0_7268:ActivateOutput("UsedBy", A1_7269)
  if A0_7268:GetState() == "TurnedOn" then
    A0_7268:GotoState("TurnedOff")
  elseif A0_7268:GetState() == "TurnedOff" then
    A0_7268:GotoState("TurnedOn")
  elseif A0_7268:GetState() == "Destroyed" then
    return
  end
  BroadcastEvent(A0_7268, "Used")
end
function Switch.GetUsable(A0_7270)
  if A0_7270:GetState() ~= "Destroyed" and A0_7270.usable == 1 then
    ({}).ActionType = "ScriptDefined"
    ;({}).Use, ({}).DisplayText = {}, A0_7270.Properties.UseMessage
  end
  return {}
end
function Switch.PlaySound(A0_7271, A1_7272)
  local L2_7273
  if A1_7272 and A1_7272 ~= "" then
    L2_7273 = A0_7271.Properties
    L2_7273 = L2_7273.Sound
    L2_7273 = L2_7273["sound" .. A1_7272]
    if not L2_7273 or L2_7273 ~= "" then
    end
  else
  end
end
function Switch.CheckSmartSwitch(A0_7274, A1_7275)
  local L2_7276, L3_7277, L4_7278, L5_7279, L6_7280, L7_7281, L8_7282, L9_7283
  L2_7276 = A0_7274.Properties
  L2_7276 = L2_7276.SmartSwitch
  L3_7277 = L2_7276.bUseSmartSwitch
  if L3_7277 == 1 then
    L3_7277 = System
    L3_7277 = L3_7277.GetEntitiesInSphere
    L4_7278 = A0_7274.GetPos
    L4_7278 = L4_7278(L5_7279)
    L3_7277 = L3_7277(L4_7278, L5_7279)
    L4_7278 = {}
    for L8_7282, L9_7283 in L5_7279(L6_7280) do
      if L9_7283:GetName() == L2_7276.Entity then
        table.insert(L4_7278, L9_7283)
      end
    end
    L5_7279(L6_7280, L7_7281)
    if L5_7279 then
      if L6_7280 ~= "" then
        L8_7282 = type
        L9_7283 = L7_7281
        L8_7282 = L8_7282(L9_7283)
        if L8_7282 == "function" then
          L8_7282 = L7_7281
          L9_7283 = L5_7279
          L8_7282(L9_7283)
        else
          L8_7282 = System
          L8_7282 = L8_7282.Log
          L9_7283 = A0_7274.GetName
          L9_7283 = L9_7283(A0_7274)
          L9_7283 = L9_7283 .. " was trying to send an invalid event! Check entity properties!"
          L8_7282(L9_7283)
        end
      end
    end
  end
end
function Switch.Event_Destroyed(A0_7284)
  BroadcastEvent(A0_7284, "Destroyed")
  A0_7284:GotoState("Destroyed")
end
function Switch.Event_TurnedOn(A0_7285)
  BroadcastEvent(A0_7285, "TurnedOn")
  A0_7285:GotoState("TurnedOn")
end
function Switch.Event_TurnedOff(A0_7286)
  BroadcastEvent(A0_7286, "TurnedOff")
  A0_7286:GotoState("TurnedOff")
end
function Switch.Event_Switch(A0_7287)
  if A0_7287:GetState() ~= "Destroyed" then
    if A0_7287:GetState() == "TurnedOn" then
      A0_7287:GotoState("TurnedOff")
    elseif A0_7287:GetState() == "TurnedOff" then
      A0_7287:GotoState("TurnedOn")
    end
  end
end
function Switch.Event_Hit(A0_7288, A1_7289)
  BroadcastEvent(A0_7288, "Hit")
end
function Switch.Event_Enable(A0_7290, A1_7291)
  A0_7290.usable = 1
  BroadcastEvent(A0_7290, "Enable")
end
function Switch.Event_Disable(A0_7292, A1_7293)
  A0_7292.usable = 0
  BroadcastEvent(A0_7292, "Disable")
end
function Switch.Event_Hide(A0_7294, A1_7295)
  A0_7294:Hide(1)
  BroadcastEvent(A0_7294, "Hide")
end
function Switch.Event_Unhide(A0_7296, A1_7297)
  A0_7296:Hide(0)
  BroadcastEvent(A0_7296, "Unhide")
end
function Switch.Client.Destroy(A0_7298)
  A0_7298:GotoState("Destroyed")
end
Switch.Client.TurnedOn = {
  OnBeginState = function(A0_7299)
    A0_7299:SetSwitch(1)
    A0_7299:CheckSmartSwitch("TurnedOnEvent")
    BroadcastEvent(A0_7299, "TurnedOn")
  end,
  OnEndState = function(A0_7300)
    local L1_7301
  end
}
Switch.Client.TurnedOff = {
  OnBeginState = function(A0_7302)
    A0_7302:SetSwitch(0)
    A0_7302:CheckSmartSwitch("TurnedOffEvent")
    BroadcastEvent(A0_7302, "TurnedOff")
  end,
  OnEndState = function(A0_7303)
    local L1_7304
  end
}
Switch.Client.Destroyed = {
  OnBeginState = function(A0_7305)
    A0_7305:Explode()
    BroadcastEvent(A0_7305, "Destroyed")
  end,
  OnEndState = function(A0_7306)
    local L1_7307
  end
}
Switch.FlowEvents = {
  Inputs = {
    Switch = {
      Switch.Event_Switch
    },
    TurnedOn = {
      Switch.Event_TurnedOn
    },
    TurnedOff = {
      Switch.Event_TurnedOff
    },
    Hit = {
      Switch.Event_Hit,
      "bool"
    },
    Destroyed = {
      Switch.Event_Destroyed,
      "bool"
    },
    Disable = {
      Switch.Event_Disable,
      "bool"
    },
    Enable = {
      Switch.Event_Enable,
      "bool"
    },
    Hide = {
      Switch.Event_Hide,
      "bool"
    },
    Unhide = {
      Switch.Event_Unhide,
      "bool"
    }
  },
  Outputs = {
    Hit = "bool",
    TurnedOn = "bool",
    TurnedOff = "bool",
    Destroyed = "bool",
    Disable = "bool",
    Enable = "bool",
    Hide = "bool",
    Unhide = "bool",
    Used = "bool",
    UsedBy = "entity"
  }
}
