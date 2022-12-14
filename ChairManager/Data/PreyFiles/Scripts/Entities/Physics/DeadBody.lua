DeadBody = {
  type = "DeadBody",
  temp_ModelName = "",
  DeadBodyParams = {
    max_time_step = 0.025,
    sleep_speed = 0.025,
    damping = 0.3,
    freefall_damping = 0.1,
    lying_mode_ncolls = 4,
    lying_sleep_speed = 0.065,
    lying_damping = 1.5
  },
  PhysParams = {
    mass = 80,
    height = 1.8,
    eyeheight = 1.7,
    sphereheight = 1.2,
    radius = 0.45,
    stiffness_scale = 0,
    lod = 1,
    retain_joint_vel = 0
  },
  Properties = {
    soclasses_SmartObjectClass = "",
    bResting = 1,
    object_Model = "Objects/characters/Aliens/AlienGuts/AlienGuts_Phantom.cdf",
    lying_damping = 1.5,
    bCollidesWithPlayers = 0,
    bPushableByPlayers = 0,
    bPushableByAI = 0,
    Mass = 80,
    bNoFriendlyFire = 0,
    bIsMimicable = true,
    Buoyancy = {
      water_density = 1000,
      water_damping = 0,
      water_resistance = 1000
    },
    TacticalInfo = {bScannable = 0, LookupName = ""},
    Sound = {audioTrigger_Open = "", audioTrigger_Close = ""}
  },
  PropertiesInstance = {
    Stiffness = 0,
    bExtraStiff = 0,
    PoseAnim = "",
    nRestingOverride = -1,
    bBypassInventory = 0,
    character_Character = ""
  },
  Editor = {
    Icon = "DeadBody.bmp",
    IconOnTop = 1
  },
  containerListeners = {}
}
DeadBodyInstanceVars = {
  m_bSearched = false,
  m_bEmpty = false,
  m_usableMessage = ""
}
ArkMakeContainer(DeadBody)
function CreateDeadBody(A0_7563)
  mergef(A0_7563, DeadBodyInstanceVars, 1)
end
function DeadBody.GetUsable(A0_7564)
  local L2_7565
  L2_7565 = {}
  ;({}).ActionType = "ScriptDefined"
  L2_7565.Loot, ({}).DisplayText = {}, "@use_object"
  if ArkRoster.GetCharacterHasTrackingChip(A0_7564.PropertiesInstance.character_Character) then
    ArkRoster.DiscoverCharacter(A0_7564.PropertiesInstance.character_Character)
  end
  return L2_7565
end
function DeadBody.UpdateDisplayName(A0_7566)
  local L1_7567
  L1_7567 = A0_7566.PropertiesInstance
  L1_7567 = L1_7567.character_Character
  if L1_7567 ~= "" then
    L1_7567 = ArkRoster
    L1_7567 = L1_7567.GetCharacterName
    L1_7567 = L1_7567(A0_7566.PropertiesInstance.character_Character)
    A0_7566.m_usableMessage = L1_7567
  else
    L1_7567 = LogWarning
    L1_7567("No character name set, cannot set container name to character.")
    A0_7566.m_usableMessage = "Corpse"
  end
  L1_7567 = nil
  if A0_7566.m_bEmpty == true then
    L1_7567 = A0_7566.m_usableMessage .. " (Empty)"
  elseif A0_7566.m_bSearched == true then
    L1_7567 = A0_7566.m_usableMessage .. " (Searched)"
  else
    L1_7567 = A0_7566.m_usableMessage
  end
  A0_7566:SetDisplayName(L1_7567)
end
function DeadBody.OnLoad(A0_7568, A1_7569)
  local L2_7570
  L2_7570 = A1_7569.temp_ModelName
  A0_7568.temp_ModelName = L2_7570
  L2_7570 = A1_7569.PhysParams
  A0_7568.PhysParams = L2_7570
  L2_7570 = A1_7569.DeadBodyParams
  A0_7568.DeadBodyParams = L2_7570
  L2_7570 = A1_7569.m_bSearched
  A0_7568.m_bSearched = L2_7570
  L2_7570 = A1_7569.m_bEmpty
  A0_7568.m_bEmpty = L2_7570
end
function DeadBody.OnSave(A0_7571, A1_7572)
  local L2_7573
  L2_7573 = A0_7571.temp_ModelName
  A1_7572.temp_ModelName = L2_7573
  L2_7573 = A0_7571.PhysParams
  A1_7572.PhysParams = L2_7573
  L2_7573 = A0_7571.DeadBodyParams
  A1_7572.DeadBodyParams = L2_7573
  L2_7573 = A0_7571.m_bSearched
  A1_7572.m_bSearched = L2_7573
  L2_7573 = A0_7571.m_bEmpty
  A1_7572.m_bEmpty = L2_7573
end
function DeadBody.OnReset(A0_7574)
  A0_7574.bScannable = A0_7574.Properties.TacticalInfo.bScannable
  A0_7574.m_bSearched = false
  A0_7574.m_bEmpty = false
  if A0_7574.bScannable == 1 then
    Game.AddTacticalEntity(A0_7574.id, eTacticalEntity_Story)
  else
    Game.RemoveTacticalEntity(A0_7574.id, eTacticalEntity_Story)
  end
  A0_7574:LoadCharacter(0, A0_7574.Properties.object_Model)
  A0_7574:PhysicalizeThis()
  A0_7574:UpdateDisplayName()
end
function DeadBody.Server_OnInit(A0_7575)
  if not CryAction.IsServer() then
    DeadBody.OnPropertyChange(A0_7575)
  end
  CryAction.CreateGameObjectForEntity(A0_7575.id)
  A0_7575:InitInventory()
end
function DeadBody.OnLoot(A0_7576, A1_7577)
  if A0_7576.PropertiesInstance.bBypassInventory ~= 1 then
    A0_7576:OpenInventory()
    UIAction.StartAction("Ark_HUD_ExternalInventory", {
      A0_7576.Properties.Sound.audioTrigger_Open,
      A0_7576.Properties.Sound.audioTrigger_Close
    })
  end
  BroadcastEvent(A0_7576, "OnOpen")
end
function DeadBody.Client_OnInit(A0_7578)
  DeadBody.OnPropertyChange(A0_7578)
  A0_7578:SetUpdatePolicy(ENTITY_UPDATE_PHYSICS_VISIBLE)
end
function DeadBody.Server_OnDamageDead(A0_7579, A1_7580)
  if A1_7580.ipart then
    A0_7579:AddImpulse(A1_7580.ipart, A1_7580.pos, A1_7580.dir, A1_7580.impact_force_mul)
  else
    A0_7579:AddImpulse(-1, A1_7580.pos, A1_7580.dir, A1_7580.impact_force_mul)
  end
end
function DeadBody.OnSpawn(A0_7581)
  CreateDeadBody(A0_7581)
end
function DeadBody.OnHit(A0_7582)
  BroadcastEvent(A0_7582, "Hit")
end
function DeadBody.OnPropertyChange(A0_7583)
  A0_7583.PhysParams.mass = A0_7583.Properties.Mass
  if A0_7583.Properties.object_Model ~= A0_7583.temp_ModelName then
    A0_7583.temp_ModelName = A0_7583.Properties.object_Model
    A0_7583:LoadCharacter(0, A0_7583.Properties.object_Model)
  end
  A0_7583:PhysicalizeThis()
  A0_7583:UpdateDisplayName()
end
function DeadBody.PhysicalizeThis(A0_7584)
  local L1_7585, L2_7586, L3_7587, L4_7588
  L1_7585 = A0_7584.Properties
  L2_7586 = A0_7584.PhysParams
  L2_7586.retain_joint_vel = 0
  L2_7586 = A0_7584.PropertiesInstance
  L2_7586 = L2_7586.PoseAnim
  if L2_7586 ~= "" then
    L3_7587 = A0_7584
    L2_7586 = A0_7584.StartAnimation
    L4_7588 = 0
    L2_7586(L3_7587, L4_7588, A0_7584.PropertiesInstance.PoseAnim, 0, 0, 1, 1, 1, 0, 1)
    L2_7586 = A0_7584.PhysParams
    L2_7586.retain_joint_vel = 1
  end
  L2_7586 = L1_7585.bPushableByPlayers
  L3_7587 = L1_7585.bCollidesWithPlayers
  L4_7588 = status
  if L4_7588 == 1 then
    L2_7586 = 0
    L3_7587 = 0
  end
  L4_7588 = A0_7584.PhysParams
  L4_7588.mass = L1_7585.Mass
  L4_7588 = A0_7584.PhysParams
  L4_7588.stiffness_scale = A0_7584.PropertiesInstance.Stiffness * (1 - A0_7584.PropertiesInstance.bExtraStiff * 2)
  L4_7588 = A0_7584.Physicalize
  L4_7588(A0_7584, 0, PE_ARTICULATED, A0_7584.PhysParams)
  L4_7588 = A0_7584.SetPhysicParams
  L4_7588(A0_7584, PHYSICPARAM_SIMULATION, A0_7584.Properties)
  L4_7588 = A0_7584.SetPhysicParams
  L4_7588(A0_7584, PHYSICPARAM_BUOYANCY, A0_7584.Properties.Buoyancy)
  L4_7588 = L1_7585.lying_damping
  if L4_7588 then
    L4_7588 = A0_7584.DeadBodyParams
    L4_7588.lying_damping = L1_7585.lying_damping
  end
  L4_7588 = A0_7584.SetPhysicParams
  L4_7588(A0_7584, PHYSICPARAM_SIMULATION, A0_7584.DeadBodyParams)
  L4_7588 = A0_7584.SetPhysicParams
  L4_7588(A0_7584, PHYSICPARAM_ARTICULATED, A0_7584.DeadBodyParams)
  L4_7588 = {}
  L4_7588.flags_mask = geom_colltype_player
  L4_7588.flags = geom_colltype_player * L3_7587
  if status == 1 then
    L4_7588.flags_mask = geom_colltype_explosion + geom_colltype_ray + geom_colltype_foliage_proxy + geom_colltype_player
  end
  A0_7584:SetPhysicParams(PHYSICPARAM_PART_FLAGS, L4_7588)
  L4_7588.flags_mask = pef_pushable_by_players
  L4_7588.flags = pef_pushable_by_players * L2_7586
  A0_7584:SetPhysicParams(PHYSICPARAM_FLAGS, L4_7588)
  if A0_7584.PropertiesInstance.nRestingOverride == -1 then
    if L1_7585.bResting == 1 then
      A0_7584:AwakePhysics(0)
    else
      A0_7584:AwakePhysics(1)
    end
  elseif A0_7584.PropertiesInstance.nRestingOverride == 1 then
    A0_7584:AwakePhysics(0)
  elseif A0_7584.PropertiesInstance.nRestingOverride == 0 then
    A0_7584:AwakePhysics(1)
  end
  A0_7584:EnableProceduralFacialAnimation(false)
  A0_7584:PlayFacialAnimation("death_pose_0" .. random(1, 5), true)
end
function DeadBody.Event_Hide(A0_7589)
  A0_7589:Hide(1)
end
function DeadBody.Event_UnHide(A0_7590)
  A0_7590:Hide(0)
end
function DeadBody.Event_Awake(A0_7591)
  A0_7591:AwakePhysics(1)
end
function DeadBody.Event_Hit(A0_7592, A1_7593)
  BroadcastEvent(A0_7592, "Hit")
end
DeadBody.Server = {
  OnInit = DeadBody.Server_OnInit,
  OnStartGame = DeadBody.Server_OnStartGame,
  OnDamage = DeadBody.Server_OnDamageDead,
  OnHit = DeadBody.OnHit,
  OnUpdate = DeadBody.OnUpdate
}
DeadBody.Client = {
  OnInit = DeadBody.Client_OnInit,
  OnDamage = DeadBody.Client_OnDamage,
  OnUpdate = DeadBody.OnUpdate
}
function DeadBody.HasBeenScanned(A0_7594)
  A0_7594:ActivateOutput("Scanned", true)
end
DeadBody.FlowEvents = {
  Inputs = {
    Awake = {
      DeadBody.Event_Awake,
      "bool"
    },
    Hide = {
      DeadBody.Event_Hide,
      "bool"
    },
    UnHide = {
      DeadBody.Event_UnHide,
      "bool"
    }
  },
  Outputs = {
    OnOpen = "bool",
    Awake = "bool",
    Hit = "bool",
    Scanned = "bool"
  }
}
