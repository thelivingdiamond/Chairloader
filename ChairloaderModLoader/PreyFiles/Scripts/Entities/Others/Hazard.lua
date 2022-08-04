Hazard = {
  Client = {},
  Server = {},
  type = "Trigger",
  Properties = {
    bEnabled = 1,
    Damage = {
      fDamage = 50,
      eiHazardType = 0,
      bOnlyPlayer = 1
    }
  },
  Editor = {
    Icon = "hazard.bmp",
    Model = "Editor/Objects/T.cgf",
    ShowBounds = 1
  },
  States = {
    "Activated",
    "Deactivated",
    "Turning"
  }
}
Net.Expose({
  Class = Hazard,
  ClientMethods = {
    AddScreenEffect = {
      RELIABLE_UNORDERED,
      PRE_ATTACH,
      ENTITYID
    },
    RemoveScreenEffect = {
      RELIABLE_UNORDERED,
      PRE_ATTACH,
      ENTITYID
    },
    DoFX = {RELIABLE_UNORDERED, PRE_ATTACH},
    InitFX = {RELIABLE_UNORDERED, PRE_ATTACH}
  },
  ServerMethods = {},
  ServerProperties = {}
})
CHECK_TIMER = 0
FX_TIMER = 1
function Hazard.OnReset(A0_6773)
  local L1_6774
  L1_6774 = {}
  A0_6773.ents = L1_6774
  L1_6774 = A0_6773.Properties
  A0_6773:InitFX()
  if L1_6774.bEnabled == 1 then
    Game.AddTacticalEntity(A0_6773.id, eTacticalEntity_Hazard)
    A0_6773:GotoState("Activated")
  else
    Game.RemoveTacticalEntity(A0_6773.id, eTacticalEntity_Hazard)
    A0_6773:GotoState("Deactivated")
  end
  A0_6773:RegisterForAreaEvents(A0_6773.Properties.bEnabled)
end
function Hazard.OnSave(A0_6775, A1_6776)
  local L2_6777
  L2_6777 = A0_6775.ents
  A1_6776.ents = L2_6777
  L2_6777 = A0_6775.fx
  A1_6776.fx = L2_6777
end
function Hazard.OnLoad(A0_6778, A1_6779)
  local L2_6780
  L2_6780 = A1_6779.ents
  A0_6778.ents = L2_6780
  L2_6780 = A1_6779.fx
  A0_6778.fx = L2_6780
end
function Hazard.OnPropertyChange(A0_6781)
  A0_6781:OnReset()
end
function Hazard.Client.OnInit(A0_6782)
  A0_6782:OnReset()
end
function Hazard.Server.OnInit(A0_6783)
  A0_6783:OnReset()
end
function Hazard.Client.InitFX(A0_6784)
  A0_6784:InitFX()
end
function Hazard.Client.AddScreenEffect(A0_6785, A1_6786)
  local L2_6787
  L2_6787 = System
  L2_6787 = L2_6787.GetEntity
  L2_6787 = L2_6787(A1_6786)
  if L2_6787 then
    A0_6785:AddScreenEffect(L2_6787)
  end
end
function Hazard.Client.RemoveScreenEffect(A0_6788, A1_6789)
  local L2_6790
  L2_6790 = System
  L2_6790 = L2_6790.GetEntity
  L2_6790 = L2_6790(A1_6789)
  if L2_6790 then
    A0_6788:RemoveScreenEffect(L2_6790)
  end
end
function Hazard.Client.DoFX(A0_6791)
  A0_6791:DoFX()
end
function Hazard.InitFX(A0_6792)
  local L1_6793
  L1_6793 = {none}
  L1_6793.fire = {
    active = 0,
    desired = 0,
    current = 0
  }
  L1_6793.frost = {
    active = 0,
    desired = 0,
    current = 0
  }
  L1_6793.electricity = {
    active = 0,
    desired = 0,
    current = 0
  }
  A0_6792.fx = L1_6793
  L1_6793 = A0_6792.Properties
  L1_6793 = L1_6793.Damage
  L1_6793 = L1_6793.eiHazardType
  A0_6792.dmg = ""
  if L1_6793 == 0 then
    A0_6792.dmg = "none"
  elseif L1_6793 == 1 then
    A0_6792.dmg = "fire"
  elseif L1_6793 == 2 then
    A0_6792.dmg = "frost"
  elseif L1_6793 == 3 then
    A0_6792.dmg = "electricity"
  else
    return
  end
end
function Hazard.HandleEntity(A0_6794, A1_6795)
  local L2_6796, L3_6797, L4_6798, L5_6799
  L2_6796 = A0_6794.Properties
  L2_6796 = L2_6796.Damage
  L3_6797 = {}
  L3_6797.x = 0
  L3_6797.y = 0
  L3_6797.z = 0
  L4_6798 = nil
  if A1_6795 ~= nil then
    L5_6799 = A1_6795.actor
    if L5_6799 ~= nil then
      L5_6799 = A0_6794.Properties
      L5_6799 = L5_6799.Damage
      L5_6799 = L5_6799.bOnlyPlayer
      if L5_6799 == 1 then
        L5_6799 = A1_6795.actor
        L5_6799 = L5_6799.IsPlayer
        L5_6799 = L5_6799(L5_6799)
        if not L5_6799 then
          return
        end
      end
      L5_6799 = A0_6794.Properties
      L5_6799 = L5_6799.Damage
      L5_6799 = L5_6799.fDamage
      if L5_6799 > 0 then
        g_gameRules:CreateHit(A1_6795.id, A0_6794.id, A0_6794.id, L5_6799, nil, nil, nil, "fire")
      end
    end
  end
end
function Hazard.HandleEntities(A0_6800)
  local L1_6801, L2_6802, L3_6803, L4_6804, L5_6805
  for L4_6804, L5_6805 in L1_6801(L2_6802) do
    A0_6800:HandleEntity(L5_6805)
  end
end
function Hazard.AddScreenEffect(A0_6806, A1_6807)
  if A1_6807 and A1_6807.actor and A1_6807.actor:IsPlayer() then
    if A0_6806.Properties.Damage.eiHazardType == 1 then
      if A0_6806.fx.fire.active ~= 1 then
        A0_6806.fx.fire.active = 1
        A0_6806.fx.fire.desired = 1
        A0_6806.fx.fire.current = 0
        System.SetScreenFx("FilterBlurring_Type", 0)
        System.SetScreenFx("FilterBlurring_Amount", 0)
        A0_6806:SetTimer(FX_TIMER, 25)
      end
    elseif A0_6806.Properties.Damage.eiHazardType == 2 then
      if A0_6806.fx.frost.active ~= 1 then
        A0_6806.fx.frost.active = 1
        A0_6806.fx.frost.desired = 1
        A0_6806.fx.frost.current = 0
        System.SetScreenFx("ScreenFrost_Active", 1)
        System.SetScreenFx("ScreenFrost_CenterAmount", 1)
        System.SetScreenFx("ScreenFrost_Amount", 0)
        A0_6806:SetTimer(FX_TIMER, 25)
      end
    elseif A0_6806.Properties.Damage.eiHazardType == 3 and A0_6806.fx.electricity.active ~= 1 then
      A0_6806.fx.electricity.active = 1
      A0_6806.fx.electricity.desired = 2
      A0_6806.fx.electricity.current = 0
      System.SetScreenFx("AlienInterference_Active", 1)
      System.SetScreenFx("AlienInterference_Amount", 1)
      A0_6806:SetTimer(FX_TIMER, 25)
    end
  end
end
function Hazard.RemoveScreenEffect(A0_6808, A1_6809)
  if A1_6809 and A1_6809.actor and A1_6809.actor:IsPlayer() and A0_6808.fx[A0_6808.dmg] and A0_6808.fx[A0_6808.dmg].active == 1 then
    A0_6808.fx[A0_6808.dmg].active = 0
    A0_6808.fx[A0_6808.dmg].desired = 0
    A0_6808:SetTimer(FX_TIMER, 25)
  end
end
function Hazard.DoFX(A0_6810)
  local L1_6811
  L1_6811 = A0_6810.dmg
  if L1_6811 ~= "none" then
    if A0_6810.fx[L1_6811].current < 0.01 and A0_6810.fx[L1_6811].desired == 0 then
      A0_6810.fx[L1_6811].current = 0
      if L1_6811 == "frost" then
        System.SetScreenFx("ScreenFrost_Amount", A0_6810.fx[L1_6811].current)
        System.SetScreenFx("ScreenFrost_Active", 0)
      elseif L1_6811 == "fire" then
        System.SetScreenFx("FilterBlurring_Amount", 0)
      elseif L1_6811 == "fire" then
        System.SetScreenFx("AlienInterference_Amount", 0)
        System.SetScreenFx("AlienInterference_Active", 0)
      end
    elseif A0_6810.fx[L1_6811].current < A0_6810.fx[L1_6811].desired then
      if L1_6811 == "frost" then
        A0_6810.fx[L1_6811].current = A0_6810.fx[L1_6811].current + 0.01
        System.SetScreenFx("ScreenFrost_Amount", A0_6810.fx[L1_6811].current)
      elseif L1_6811 == "fire" then
        A0_6810.fx[L1_6811].current = A0_6810.fx[L1_6811].current + 0.01
        System.SetScreenFx("FilterBlurring_Amount", A0_6810.fx[L1_6811].current)
      elseif L1_6811 == "electricity" then
        A0_6810.fx[L1_6811].current = A0_6810.fx[L1_6811].current + 0.1
        System.SetScreenFx("AlienInterference_Amount", A0_6810.fx[L1_6811].current)
      end
      A0_6810:SetTimer(FX_TIMER, 25)
    elseif A0_6810.fx[L1_6811].current > A0_6810.fx[L1_6811].desired then
      if L1_6811 == "frost" then
        A0_6810.fx[L1_6811].current = A0_6810.fx[L1_6811].current - 0.01
        System.SetScreenFx("ScreenFrost_Amount", A0_6810.fx[L1_6811].current)
      elseif L1_6811 == "fire" then
        A0_6810.fx[L1_6811].current = A0_6810.fx[L1_6811].current - 0.03
        System.SetScreenFx("FilterBlurring_Amount", A0_6810.fx[L1_6811].current)
      elseif L1_6811 == "electricity" then
        A0_6810.fx[L1_6811].current = A0_6810.fx[L1_6811].current - 0.1
        System.SetScreenFx("AlienInterference_Amount", A0_6810.fx[L1_6811].current)
      end
      A0_6810:SetTimer(FX_TIMER, 25)
    end
  end
end
function Hazard.Event_Activated(A0_6812)
  Game.AddTacticalEntity(A0_6812.id, eTacticalEntity_Hazard)
  A0_6812:GotoState("Activated")
  A0_6812:ActivateOutput("Activated", true)
  A0_6812:RegisterForAreaEvents(1)
end
function Hazard.Event_Deactivated(A0_6813)
  Game.RemoveTacticalEntity(A0_6813.id, eTacticalEntity_Hazard)
  A0_6813:GotoState("Deactivated")
  A0_6813:ActivateOutput("Deactivated", true)
  A0_6813:RegisterForAreaEvents(0)
end
function Hazard.IsEntityAlreadyInTable(A0_6814, A1_6815)
  for _FORV_5_, _FORV_6_ in pairs(A0_6814.ents) do
    if _FORV_6_.id == A1_6815.id then
      return true
    end
  end
  return false
end
Hazard.Server.Activated = {
  OnBeginState = function(A0_6816)
    if table.getn(A0_6816.ents) > 0 then
      A0_6816:SetTimer(CHECK_TIMER, 1000)
      for _FORV_4_, _FORV_5_ in pairs(A0_6816.ents) do
        if _FORV_5_.actor and _FORV_5_.actor:IsPlayer() then
          A0_6816.onClient:AddScreenEffect(_FORV_5_.actor:GetChannel(), _FORV_5_.id)
        end
      end
    end
  end,
  OnEnterArea = function(A0_6817, A1_6818, A2_6819)
    if not A0_6817:IsEntityAlreadyInTable(A1_6818) then
      A0_6817:ActivateOutput("Enter", true)
      table.insert(A0_6817.ents, A1_6818)
      A0_6817:SetTimer(CHECK_TIMER, 1000)
      A0_6817:HandleEntity(A1_6818)
      if A1_6818.actor and A1_6818.actor:IsPlayer() then
        A0_6817.onClient:AddScreenEffect(A1_6818.actor:GetChannel(), A1_6818.id)
      end
    end
  end,
  OnLeaveArea = function(A0_6820, A1_6821, A2_6822)
    local L3_6823, L4_6824, L5_6825, L6_6826
    for L6_6826, _FORV_7_ in L3_6823(L4_6824) do
      if _FORV_7_ == A1_6821 then
        A0_6820:ActivateOutput("Leave", true)
        table.remove(A0_6820.ents, L6_6826)
        if _FORV_7_.actor and _FORV_7_.actor:IsPlayer() then
          A0_6820.onClient:RemoveScreenEffect(_FORV_7_.actor:GetChannel(), _FORV_7_.id)
        end
        break
      end
    end
  end,
  OnTimer = function(A0_6827, A1_6828, A2_6829)
    if A1_6828 == CHECK_TIMER and A0_6827.ents and table.getn(A0_6827.ents) > 0 then
      A0_6827:HandleEntities()
      A0_6827:SetTimer(CHECK_TIMER, 1000)
    end
  end,
  OnEndState = function(A0_6830)
    local L1_6831
  end
}
Hazard.Client.Activated = {
  OnTimer = function(A0_6832, A1_6833, A2_6834)
    if A1_6833 == FX_TIMER then
      A0_6832:DoFX()
    end
  end
}
Hazard.Client.Deactivated = {
  OnTimer = function(A0_6835, A1_6836, A2_6837)
    if A1_6836 == FX_TIMER then
      A0_6835:DoFX()
    end
  end
}
Hazard.Server.Deactivated = {
  OnBeginState = function(A0_6838)
    for _FORV_4_, _FORV_5_ in pairs(A0_6838.ents) do
      if _FORV_5_.actor and _FORV_5_.actor:IsPlayer() then
        A0_6838.onClient:RemoveScreenEffect(_FORV_5_.actor:GetChannel(), _FORV_5_.id)
      end
    end
  end,
  OnEnterArea = function(A0_6839, A1_6840, A2_6841)
    if not A0_6839:IsEntityAlreadyInTable(A1_6840) then
      table.insert(A0_6839.ents, A1_6840)
    end
  end,
  OnLeaveArea = function(A0_6842, A1_6843, A2_6844)
    local L3_6845, L4_6846, L5_6847, L6_6848, L7_6849
    for L6_6848, L7_6849 in L3_6845(L4_6846) do
      if L7_6849 == A1_6843 then
        table.remove(A0_6842.ents, L6_6848)
        A0_6842:RemoveScreenEffect(L7_6849)
        break
      end
    end
  end
}
Hazard.FlowEvents = {
  Inputs = {
    Activated = {
      Hazard.Event_Activated,
      "bool"
    },
    Deactivated = {
      Hazard.Event_Deactivated,
      "bool"
    }
  },
  Outputs = {
    Activated = "bool",
    Deactivated = "bool",
    Enter = "bool",
    Leave = "bool"
  }
}
