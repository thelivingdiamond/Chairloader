Item = {
  Properties = {
    bPickable = 1,
    eiPhysicsType = 0,
    bMounted = 0,
    bUsable = 0,
    bSpecialSelect = 0,
    HitPoints = 0,
    soclasses_SmartObjectClass = "",
    initialSetup = ""
  },
  Client = {},
  Server = {},
  Editor = {Icon = "Item.bmp", IconOnTop = 1}
}
function Item.OnPropertyChange(A0_5571)
  A0_5571.item:Reset()
  if A0_5571.OnReset then
    A0_5571:OnReset()
  end
end
function Item.OnSave(A0_5572, A1_5573)
  local L2_5574
  L2_5574 = A0_5572.flowUser
  if L2_5574 then
    L2_5574 = A0_5572.flowUser
    L2_5574 = L2_5574.id
    A1_5573.flowUserID = L2_5574
  end
end
function Item.OnLoad(A0_5575, A1_5576)
  if A1_5576.flowUserID then
    A0_5575.flowUser = System.GetEntity(A1_5576.flowUserID)
  end
end
function Item.IsUsable(A0_5577, A1_5578)
  if A0_5577.item:CanPickUp(A1_5578.id) then
    return 725725
  elseif A0_5577.item:CanUse(A1_5578.id) then
    return 1
  else
    return 0
  end
end
function Item.GetUsableMessage(A0_5579)
  if A0_5579.item:IsMounted() then
    return "@use_mounted"
  else
    return A0_5579.item:GetUsableText()
  end
end
function Item.OnUsed(A0_5580, A1_5581)
  if A1_5581 then
    A0_5580:ActivateOutput("Used", A1_5581.id)
  end
  g_localActor:AddItem(A0_5580.id)
  A0_5580.m_bWasPickedUp = true
  return A0_5580.item:OnUsed(A1_5581.id)
end
function Item.OnFreeze(A0_5582, A1_5583, A2_5584, A3_5585)
  if not g_gameRules.game:IsMultiplayer() or g_gameRules.game:GetTeam(A1_5583) ~= g_gameRules.game:GetTeam(A0_5582.id) then
    return true
  end
  return false
end
function Item.Server.OnHit(A0_5586, A1_5587)
  if A0_5586.Properties.HitPoints and 0 < A0_5586.Properties.HitPoints then
    if A1_5587.type == "repair" then
      A0_5586.item:OnHit(A1_5587)
    elseif (not (tonumber(A0_5586.Properties.bExplosionOnly or 0) ~= 0) or A1_5587.explosion) and (not g_gameRules.game:IsMultiplayer() or g_gameRules.game:GetTeam(A1_5587.shooterId) ~= g_gameRules.game:GetTeam(A0_5586.id)) then
      A0_5586.item:OnHit(A1_5587)
      if not A0_5586.item:IsDestroyed() then
        if 0 < A1_5587.damage and g_gameRules.Server.OnTurretHit then
          g_gameRules.Server.OnTurretHit(g_gameRules, A0_5586, A1_5587)
        end
        if A0_5586.item:IsDestroyed() and A0_5586.FlowEvents and A0_5586.FlowEvents.Outputs.Destroyed then
          A0_5586:ActivateOutput("Destroyed", 1)
        end
      end
    end
  end
end
function Item.Server.OnShattered(A0_5588, A1_5589)
  g_gameRules.Server.OnTurretHit(g_gameRules, A0_5588, A1_5589)
end
function Item.Event_Hide(A0_5590)
  A0_5590:Hide(1)
  A0_5590:ActivateOutput("Hide", true)
end
function Item.Event_UnHide(A0_5591)
  A0_5591:Hide(0)
  A0_5591:ActivateOutput("UnHide", true)
end
function Item.Event_UserId(A0_5592, A1_5593, A2_5594)
  A0_5592.flowUser = A2_5594
end
function Item.Event_Use(A0_5595)
  A0_5595:OnUsed(A0_5595.flowUser)
end
Item.FlowEvents = {
  Inputs = {
    Hide = {
      Item.Event_Hide,
      "bool"
    },
    UnHide = {
      Item.Event_UnHide,
      "bool"
    },
    Use = {
      Item.Event_Use,
      "bool"
    },
    UserId = {
      Item.Event_UserId,
      "entity"
    }
  },
  Outputs = {
    Hide = "bool",
    UnHide = "bool",
    Used = "entity"
  }
}
function MakeRespawnable(A0_5596)
  local L1_5597, L2_5598
  L1_5597 = A0_5596.Properties
  if L1_5597 then
    L1_5597 = A0_5596.Properties
    L2_5598 = {}
    L2_5598.nTimer = 30
    L2_5598.bUnique = 0
    L2_5598.bRespawn = 0
    L1_5597.Respawn = L2_5598
  end
end
function CreateItemTable(A0_5599)
  if not _G[A0_5599] then
    _G[A0_5599] = new(Item)
  end
  MakeRespawnable(_G[A0_5599])
end
CreateItemTable("HMG")
HMG.Properties.bMounted = 1
HMG.Properties.bUsable = 1
HMG.Properties.bPickable = 0
HMG.Properties.MountedLimits = {
  pitchMin = -22,
  pitchMax = 60,
  yaw = 70
}
function HMG.OnReset(A0_5600)
  A0_5600.item:SetMountedAngleLimits(A0_5600.Properties.MountedLimits.pitchMin, A0_5600.Properties.MountedLimits.pitchMax, A0_5600.Properties.MountedLimits.yaw)
  A0_5600.inUse = false
end
function HMG.OnSpawn(A0_5601)
  A0_5601:OnReset()
end
function HMG.OnUsed(A0_5602, A1_5603)
  if A1_5603.actor:IsPlayer() then
    return Item.OnUsed(A0_5602, A1_5603)
  end
end
function HMG.OnAIUsed(A0_5604, A1_5605, A2_5606)
  if A1_5605.OnUseMountedWeaponRequest then
    A1_5605:OnUseMountedWeaponRequest(A0_5604.id)
    return
  end
  g_SignalData.id = A0_5604.id
  g_SignalData.iValue = A2_5606
  AI.Signal(SIGNALFILTER_SENDER, 0, "PrepareForMountedWeaponUse", A1_5605.id, g_SignalData)
end
CreateItemTable("VehicleHMG")
VehicleHMG.Properties.bMounted = 1
VehicleHMG.Properties.bUsable = 1
VehicleHMG.Properties.bPickable = 0
function VehicleHMG.IsUsable(A0_5607, A1_5608)
  if A0_5607.item:CanUseVehicle(A1_5608.id) == true then
    return 1
  end
  return (A0_5607.item:CanUseVehicle(A1_5608.id))
end
CreateItemTable("VTOLHMG")
VTOLHMG.Properties.bMounted = 1
VTOLHMG.Properties.bUsable = 1
VTOLHMG.Properties.bPickable = 0
function VTOLHMG.IsUsable(A0_5609, A1_5610)
  if A0_5609.item:CanUseVehicle(A1_5610.id) == true then
    return 1
  end
  return (A0_5609.item:CanUseVehicle(A1_5610.id))
end
CreateItemTable("AGL")
AGL.Properties.bMounted = 1
AGL.Properties.bUsable = 1
AGL.Properties.bPickable = 0
AGL.Properties.MountedLimits = {
  pitchMin = -22,
  pitchMax = 60,
  yaw = 70
}
CreateItemTable("swarmer")
swarmer.Properties.bPickable = 1
swarmer.Properties.bUsable = 1
CreateItemTable("Heavy_minigun")
Heavy_minigun.Properties.bPickable = 1
Heavy_minigun.Properties.bUsable = 1
CreateItemTable("Heavy_mortar")
Heavy_mortar.Properties.bPickable = 1
Heavy_mortar.Properties.bUsable = 1
CreateItemTable("Grunt_PlasmaRifle")
Grunt_PlasmaRifle.Properties.bPickable = 1
Grunt_PlasmaRifle.Properties.bUsable = 1
CreateItemTable("plasma_thrower")
plasma_thrower.Properties.bPickable = 1
plasma_thrower.Properties.bUsable = 1
CreateItemTable("LightningGun")
LightningGun.Properties.bPickable = 1
LightningGun.Properties.bUsable = 1
CreateItemTable("UseableTurret")
UseableTurret.Properties.bMounted = 1
UseableTurret.Properties.bUsable = 1
UseableTurret.Properties.MountedLimits = {
  pitchMin = -22,
  pitchMax = 60,
  yaw = 70
}
CreateItemTable("Cinematic_VTolMG")
Cinematic_VTolMG.Properties.bPickable = 0
Cinematic_VTolMG.Properties.bUsable = 0
function Cinematic_VTolMG.Event_Primary(A0_5611)
  Game.SendEventToGameObject(A0_5611.id, "primary")
end
function Cinematic_VTolMG.Event_Secondary(A0_5612)
  Game.SendEventToGameObject(A0_5612.id, "secondary")
end
function Cinematic_VTolMG.Event_Deactivate(A0_5613)
  Game.SendEventToGameObject(A0_5613.id, "deactivate")
end
Cinematic_VTolMG.FlowEvents = {
  Inputs = {
    Primary = {
      Cinematic_VTolMG.Event_Primary,
      "bool"
    },
    Secondary = {
      Cinematic_VTolMG.Event_Secondary,
      "bool"
    },
    Deactivate = {
      Cinematic_VTolMG.Event_Deactivate,
      "bool"
    }
  },
  Outputs = {}
}
function CreateTurret(A0_5614)
  CreateItemTable(A0_5614)
  _G[A0_5614].Properties.teamName = ""
  _G[A0_5614].Properties.GunTurret = {
    bSurveillance = 1,
    bVehiclesOnly = 0,
    bEnabled = 1,
    bSearching = 0,
    bSearchOnly = 0,
    MGRange = 50,
    RocketRange = 50,
    TACDetectRange = 300,
    TurnSpeed = 1.5,
    SearchSpeed = 0.5,
    UpdateTargetTime = 2,
    AbandonTargetTime = 0.5,
    TACCheckTime = 0.2,
    YawRange = 360,
    MinPitch = -45,
    MaxPitch = 45,
    AimTolerance = 20,
    Prediction = 1,
    BurstTime = 0,
    BurstPause = 0,
    SweepTime = 0,
    LightFOV = 0,
    ExplosiveDamageMultiplier = 1,
    bFindCloaked = 1,
    bExplosionOnly = 0
  }
  _G[A0_5614].Server.OnInit = function(A0_5615)
    A0_5615:OnReset()
  end
  _G[A0_5614].OnReset = function(A0_5616)
    local L1_5617
    L1_5617 = g_gameRules
    L1_5617 = L1_5617.game
    L1_5617 = L1_5617.GetTeamId
    L1_5617 = L1_5617(L1_5617, A0_5616.Properties.teamName)
    L1_5617 = L1_5617 or 0
    g_gameRules.game:SetTeam(L1_5617, A0_5616.id)
  end
  _G[A0_5614].Properties.objModel = ""
  _G[A0_5614].Properties.objBarrel = ""
  _G[A0_5614].Properties.objBase = ""
  _G[A0_5614].Properties.objDestroyed = ""
  _G[A0_5614].Properties.bUsable = nil
  _G[A0_5614].Properties.bPickable = nil
  _G[A0_5614].Event_EnableTurret = function(A0_5618)
    A0_5618.Properties.GunTurret.bEnabled = 1
    A0_5618:ActivateOutput("TurretEnabled", 1)
  end
  _G[A0_5614].Event_DisableTurret = function(A0_5619)
    A0_5619.Properties.GunTurret.bEnabled = 0
    A0_5619:ActivateOutput("TurretDisabled", true)
  end
  _G[A0_5614].FlowEvents.Inputs.EnableTurret = {
    _G[A0_5614].Event_EnableTurret,
    "bool"
  }
  _G[A0_5614].FlowEvents.Inputs.DisableTurret = {
    _G[A0_5614].Event_DisableTurret,
    "bool"
  }
  _G[A0_5614].FlowEvents.Outputs.TurretEnabled = "bool"
  _G[A0_5614].FlowEvents.Outputs.TurretDisabled = "bool"
  _G[A0_5614].FlowEvents.Outputs.Destroyed = "bool"
  return _G[A0_5614]
end
CreateTurret("WarriorMOARTurret")
CreateTurret("AutoTurret").Properties.bExplosionOnly = 1
CreateTurret("AutoTurretAA").Properties.bExplosionOnly = 1
AutoTurret.Properties.bPickable = 0
CreateItemTable("RippableTurretGun")
RippableTurretGun.Properties.bMounted = 1
RippableTurretGun.Properties.bUsable = 1
RippableTurretGun.Properties.MountedLimits = {
  pitchMin = -22,
  pitchMax = 60,
  yaw = 70
}
function RippableTurretGun.OnReset(A0_5620)
  A0_5620.item:SetMountedAngleLimits(A0_5620.Properties.MountedLimits.pitchMin, A0_5620.Properties.MountedLimits.pitchMax, A0_5620.Properties.MountedLimits.yaw)
end
function RippableTurretGun.OnSpawn(A0_5621)
  A0_5621:OnReset()
end
function RippableTurretGun.OnUsed(A0_5622, A1_5623)
  if A1_5623.actor:IsPlayer() then
    Item.OnUsed(A0_5622, A1_5623)
  else
    g_SignalData.id = A0_5622.id
    AI.Signal(SIGNALFILTER_SENDER, 0, "UseMountedWeapon", A1_5623.id, g_SignalData)
  end
end
function RippableTurretGun.OnAIUsed(A0_5624, A1_5625, A2_5626)
  g_SignalData.id = A0_5624.id
  g_SignalData.iValue = A2_5626
  AI.Signal(SIGNALFILTER_SENDER, 0, "PrepareForMountedWeaponUse", A1_5625.id, g_SignalData)
end
