Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkSwitch = {
  Properties = {
    object_Model = "",
    textDisplayName = "No Display Name Set",
    textDisplayNameLocked = "No Locked Display Name Set",
    textMessageTurnOn = "No Turn On Message Set",
    textMessageTurnOff = "No Turn Off Message Set",
    bDisallowGrenades = true,
    bRemoteManipulatable = 1,
    Sound = {
      audioTrigger_On = "",
      audioTrigger_Off = "",
      audioTrigger_Locked = ""
    },
    Animation = {anim_On = "", anim_Off = ""},
    Physics = {
      bPhysicalize = 1,
      bArticulated = 1,
      bPushableByPlayers = 1,
      bPushableByAI = 1,
      Density = -1,
      Mass = -1
    },
    Silhouette = {
      color_RGB = {
        x = 1,
        y = 1,
        z = 1
      },
      fAlpha = 0.25
    }
  },
  States = {"On", "Off"},
  PropertiesInstance = {
    bStartsOn = 0,
    bUsable = 1,
    bLocked = 0,
    bVerbose = 0,
    bPlayerCanLock = 0,
    bBreaksGloo = true
  },
  Editor = {
    IconOnTop = true,
    Icon = "switch.bmp",
    ShowBounds = 0,
    IsScalable = false
  }
}
GetArkEntityUtils(ArkSwitch)
SetupCollisionFiltering(ArkSwitch)
ArkMakeSaveable(ArkSwitch)
ArkSwitchInstanceVars = {
  m_bIsAnimating = false,
  m_savedState = false,
  m_bScriptedUsable = 1,
  m_bUsable = 1,
  m_bInit = false,
  m_bVerbose = false,
  m_bLocked = false,
  m_referenceTable = false,
  m_bNeedsUsableBroadcast = false,
  m_usableMessage = "",
  m_audioIds = {}
}
function CreateArkSwitch(A0_4531)
  mergef(A0_4531, ArkSwitchInstanceVars, 1)
  A0_4531.m_referenceTable = ArkSwitchInstanceVars
end
function ArkSwitch.Init(A0_4532)
  if not A0_4532.m_bInit then
    A0_4532.m_bInit = true
    A0_4532:Activate(1)
    A0_4532:GotoState("")
    A0_4532.m_skipAnim = true
    if A0_4532.PropertiesInstance.bStartsOn == 1 then
      A0_4532:GotoState("On")
    else
      A0_4532:GotoState("Off")
    end
    if A0_4532.m_bLocked then
      A0_4532:SetDisplayName(A0_4532.Properties.textDisplayNameLocked)
    else
      A0_4532:SetDisplayName(A0_4532.Properties.textDisplayName)
    end
  end
end
function ArkSwitch.SetFromProperties(A0_4533)
  A0_4533:SetupModelAndPhysics()
  GetAudioIds(A0_4533.Properties.Sound, A0_4533.m_audioIds)
  A0_4533.m_bVerbose = A0_4533.PropertiesInstance.bVerbose == 1
  A0_4533.m_bScriptedUsable = A0_4533.PropertiesInstance.bUsable == 1
  A0_4533.m_bUsable = A0_4533.PropertiesInstance.bUsable == 1
  A0_4533.m_bLocked = A0_4533.PropertiesInstance.bLocked == 1
  A0_4533.m_bNeedsUsableBroadcast = false
end
function ArkSwitch.ResetUsability(A0_4534)
  A0_4534.m_bUsable = A0_4534.m_bScriptedUsable
  if A0_4534.m_bNeedsUsableBroadcast then
    A0_4534.m_bNeedsUsableBroadcast = false
    if A0_4534.m_bUsable then
      BroadcastEvent(A0_4534, "Enabled")
    else
      BroadcastEvent(A0_4534, "Disabled")
    end
  end
end
function ArkSwitch.GetUsable(A0_4535)
  local L1_4536, L2_4537, L3_4538
  L1_4536 = {}
  L2_4537 = {}
  L3_4538 = A0_4535.m_bUsable
  if L3_4538 then
    L3_4538 = A0_4535.m_bLocked
    if not L3_4538 then
      L2_4537.ActionType = "ScriptDefined"
    else
      L2_4537.ActionType = "ScriptDefined"
    end
    L3_4538 = A0_4535.m_usableMessage
    L2_4537.DisplayText = L3_4538
    L3_4538 = {}
    if A0_4535.PropertiesInstance.bPlayerCanLock == 1 and A0_4535:GetState() == "Off" and A0_4535.m_bLocked then
      L3_4538.ActionType = "ScriptDefined"
      L3_4538.DisplayText = "Unlock"
    elseif A0_4535.PropertiesInstance.bPlayerCanLock == 1 and A0_4535:GetState() == "Off" and not A0_4535.m_bLocked then
      L3_4538.ActionType = "ScriptDefined"
      L3_4538.DisplayText = "Lock"
    end
    L1_4536.Special = L3_4538
    L1_4536.Use = L2_4537
  end
  return L1_4536
end
function ArkSwitch.OnSpecialUsed(A0_4539, A1_4540, A2_4541)
  if A0_4539.PropertiesInstance.bPlayerCanLock == 1 then
    if A0_4539.m_bLocked then
      A0_4539:Event_Unlock()
    else
      A0_4539:Event_Lock()
    end
  end
end
function ArkSwitch.GetRemoteManipulationInteraction(A0_4542)
  local L1_4543, L2_4544
  L1_4543 = {}
  L2_4544 = A0_4542.m_bUsable
  if L2_4544 then
    L2_4544 = A0_4542.Properties
    L2_4544 = L2_4544.bRemoteManipulatable
    if L2_4544 == 1 then
      L2_4544 = A0_4542.m_bLocked
      if not L2_4544 then
        L1_4543.ActionType = "ScriptDefined"
        L2_4544 = A0_4542.m_usableMessage
        L1_4543.DisplayText = L2_4544
      end
    end
  end
  return L1_4543
end
function ArkSwitch.AttemptUsabilityUpdate(A0_4545, A1_4546)
  if A0_4545:GetAnimationTime(0, 0) == 1 and A0_4545:GetNumQueuedAnimations(0, 0) == 1 then
    BroadcastEvent(A0_4545, A1_4546)
    A0_4545.m_bIsAnimating = false
    A0_4545:ResetUsability()
  elseif not A0_4545.PropertiesInstance.bBreaksGloo and Ark.HandleGooOverlappingEntity(A0_4545.id, A0_4545.PropertiesInstance.bBreaksGloo) then
    A0_4545:SetAnimationSpeed(0, 0, 0)
  elseif not Ark.HandleGooOverlappingEntity(A0_4545.id, A0_4545.PropertiesInstance.bBreaksGloo) then
    A0_4545:SetAnimationSpeed(0, 0, 1)
  end
end
function ArkSwitch.Animate(A0_4547, A1_4548, A2_4549)
  A0_4547:Log("anim = " .. A1_4548)
  if A0_4547.m_skipAnim then
    A0_4547:StopAnimation(0, 0)
    A0_4547:StartAnimation(0, A1_4548)
    A0_4547:SetAnimationTime(0, 0, 1)
    A0_4547.m_skipAnim = false
  else
    A0_4547:StartAnimation(0, A1_4548)
    A0_4547.m_bUsable = false
    if A2_4549 ~= nil then
      A0_4547:ExecuteAudioTrigger(A2_4549, A0_4547:GetDefaultAuxAudioProxyID())
    end
    A0_4547.m_bIsAnimating = true
  end
end
function ArkSwitch.SetLightBrightness(A0_4550, A1_4551)
  local L2_4552, L3_4553, L4_4554, L5_4555, L6_4556
  L2_4552 = A0_4550.CountLinks
  L2_4552 = L2_4552(L3_4553)
  for L6_4556 = 0, L2_4552 - 1 do
    if A0_4550:GetLink(L6_4556) and A0_4550:GetLink(L6_4556).SetLightScale then
      A0_4550:GetLink(L6_4556):SetLightScale(A1_4551)
    end
  end
end
function ArkSwitch.OnUsed(A0_4557)
  if A0_4557.PropertiesInstance.bBreaksGloo or not Ark.HandleGooOverlappingEntity(A0_4557.id, A0_4557.PropertiesInstance.bBreaksGloo) then
    if not A0_4557.m_bLocked then
      if A0_4557:GetState() == "On" then
        A0_4557:GotoState("Off")
      else
        A0_4557:GotoState("On")
      end
      Ark.AddInstigationEvent(A0_4557.id, g_localActor.id, 5)
    else
      A0_4557:ExecuteAudioTrigger(A0_4557.m_audioIds.audioTrigger_Locked, A0_4557:GetDefaultAuxAudioProxyID())
    end
    BroadcastEvent(A0_4557, "Used")
  end
end
function ArkSwitch.OnRemoteManipulation(A0_4558)
  if A0_4558.PropertiesInstance.bBreaksGloo or not Ark.HandleGooOverlappingEntity(A0_4558.id, A0_4558.PropertiesInstance.bBreaksGloo) then
    if A0_4558:GetState() == "On" then
      A0_4558:GotoState("Off")
    else
      A0_4558:GotoState("On")
    end
    BroadcastEvent(A0_4558, "Used")
  end
end
function ArkSwitch.OnPostLoad(A0_4559)
  A0_4559:Activate(1)
  A0_4559:GotoState("")
  A0_4559.m_skipAnim = true
  A0_4559:GotoState(A0_4559.m_savedState)
end
function ArkSwitch.OnPropertyChange(A0_4560)
  A0_4560:Log("OnPropertyChange")
  A0_4560:SetFromProperties()
  A0_4560:Init()
end
function ArkSwitch.OnReset(A0_4561)
  A0_4561.m_bInit = false
  A0_4561:SetFromProperties()
  A0_4561:Init()
  A0_4561:Log("OnReset")
end
function ArkSwitch.OnSpawn(A0_4562)
  CreateArkSwitch(A0_4562)
  A0_4562:SetFromProperties()
  A0_4562:Init()
  A0_4562:Log("OnSpawn")
end
function ArkSwitch.Event_On(A0_4563)
  if A0_4563.PropertiesInstance.bBreaksGloo or not Ark.HandleGooOverlappingEntity(A0_4563.id, A0_4563.PropertiesInstance.bBreaksGloo) then
    A0_4563:Log("Event_On")
    A0_4563:GotoState("On")
  end
end
function ArkSwitch.Event_Off(A0_4564)
  if A0_4564.PropertiesInstance.bBreaksGloo or not Ark.HandleGooOverlappingEntity(A0_4564.id, A0_4564.PropertiesInstance.bBreaksGloo) then
    A0_4564:Log("Event_Off")
    A0_4564:GotoState("Off")
  end
end
function ArkSwitch.Event_Lock(A0_4565)
  A0_4565:Log("Event_Lock")
  A0_4565.m_bLocked = true
  A0_4565:SetDisplayName(A0_4565.Properties.textDisplayNameLocked)
  BroadcastEvent(A0_4565, "Locked")
end
function ArkSwitch.Event_Unlock(A0_4566)
  A0_4566:Log("Event_Unlock")
  A0_4566.m_bLocked = false
  A0_4566:SetDisplayName(A0_4566.Properties.textDisplayName)
  BroadcastEvent(A0_4566, "Unlocked")
end
function ArkSwitch.Event_Enable(A0_4567)
  A0_4567:Log("Event_Enable")
  A0_4567.m_bScriptedUsable = true
  if not A0_4567.m_bIsAnimating then
    A0_4567.m_bUsable = true
    BroadcastEvent(A0_4567, "Enabled")
  else
    A0_4567.m_bNeedsUsableBroadcast = true
  end
end
function ArkSwitch.Event_Disable(A0_4568)
  A0_4568:Log("Event_Disable")
  A0_4568.m_bScriptedUsable = false
  if not A0_4568.m_bIsAnimating then
    A0_4568.m_bUsable = false
    BroadcastEvent(A0_4568, "Disabled")
  else
    A0_4568.m_bNeedsUsableBroadcast = true
  end
end
function ArkSwitch.Event_Hide(A0_4569)
  A0_4569:Hide(1)
  A0_4569:ActivateOutput("Hide", true)
end
function ArkSwitch.Event_UnHide(A0_4570)
  A0_4570:Hide(0)
  A0_4570:ActivateOutput("UnHide", true)
end
ArkSwitch.On = {
  OnStartLevel = function(A0_4571)
    A0_4571:OnStartLevel()
  end,
  OnBeginState = function(A0_4572)
    A0_4572:Log("On state begin")
    A0_4572:Activate(1)
    A0_4572:Animate(A0_4572.Properties.Animation.anim_On, A0_4572.m_audioIds.audioTrigger_On)
    A0_4572:SetLightBrightness(1)
    A0_4572.m_usableMessage = A0_4572.Properties.textMessageTurnOff
  end,
  OnUpdate = function(A0_4573)
    A0_4573:Log("On state OnUpdate")
    if A0_4573.m_bIsAnimating then
      A0_4573:AttemptUsabilityUpdate("On")
    else
      A0_4573:Activate(0)
    end
  end,
  OnEndState = function(A0_4574)
    A0_4574:Log("On state end")
  end
}
ArkSwitch.Off = {
  OnStartLevel = function(A0_4575)
    A0_4575:OnStartLevel()
  end,
  OnBeginState = function(A0_4576)
    A0_4576:Log("Off state begin")
    A0_4576:Activate(1)
    A0_4576:Animate(A0_4576.Properties.Animation.anim_Off, A0_4576.m_audioIds.audioTrigger_Off)
    A0_4576:SetLightBrightness(0)
    A0_4576.m_usableMessage = A0_4576.Properties.textMessageTurnOn
  end,
  OnUpdate = function(A0_4577)
    A0_4577:Log("Off state OnUpdate")
    if A0_4577.m_bIsAnimating then
      A0_4577:AttemptUsabilityUpdate("Off")
    else
      A0_4577:Activate(0)
    end
  end,
  OnEndState = function(A0_4578)
    A0_4578:Log("Off state end")
  end
}
ArkSwitch.FlowEvents = {
  Inputs = {
    Off = {
      ArkSwitch.Event_Off,
      "bool"
    },
    On = {
      ArkSwitch.Event_On,
      "bool"
    },
    Enable = {
      ArkSwitch.Event_Enable,
      "bool"
    },
    Disable = {
      ArkSwitch.Event_Disable,
      "bool"
    },
    Lock = {
      ArkSwitch.Event_Lock,
      "bool"
    },
    Unlock = {
      ArkSwitch.Event_Unlock,
      "bool"
    },
    Hide = {
      ArkSwitch.Event_Hide,
      "bool"
    },
    UnHide = {
      ArkSwitch.Event_UnHide,
      "bool"
    }
  },
  Outputs = {
    Off = "bool",
    On = "bool",
    Enabled = "bool",
    Disabled = "bool",
    Locked = "bool",
    Unlocked = "bool",
    Hide = "bool",
    UnHide = "bool",
    Used = "bool"
  }
}
