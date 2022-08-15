Script.ReloadScript("Scripts/Entities/Physics/BasicEntity.lua")
Ark_sshain_Fabricator = {
  Properties = {
    object_Model = "GameSDK/Objects/ArkEffects/Temporary/proxy_fabricator.cga",
    file_XmlDef = "GameSDK/Scripts/Entities/User/sshain/Ark_sshain_FabPlans_Def.xml",
    file_XmlData = "GameSDK/Scripts/Entities/User/sshain/Ark_sshain_FabPlans_Data.xml",
    bUsable = true,
    bVerbose = true
  },
  Colors = {
    clrColor = {
      x = 1,
      y = 1,
      z = 0
    }
  },
  Sound = {
    sndCraft = "Sounds/environment:city:atrium_elevator_start"
  },
  States = {
    "InUse",
    "Busy",
    "Standby",
    "Destroyed"
  },
  Editor = {Icon = "Prefab.bmp"},
  m_file_SpawnVFX = "ArkGameplay.Fabricator.CraftingFinish",
  m_uiElementName = "DanielleFabricator",
  m_subMatIndex = 2,
  m_useMessage = "Use Fabricator",
  m_idleDelay = 5000,
  m_craftingDelay = 1500,
  m_itemClearDelay = 1000,
  m_usable = 1,
  m_timerId = 0,
  m_instanceId = -1,
  m_m_bVerbose = true,
  m_fInteractDist = 1.5,
  m_fItemClearDist = 1.5,
  m_planIndex = 1,
  m_fabPlans = {},
  m_vecItemSpawnPos = {},
  m_vecInteractPos = {}
}
MakeDerivedEntityOverride(Ark_sshain_Fabricator, BasicEntity)
function Ark_sshain_Fabricator.Log(A0_8772, A1_8773)
  A1_8773 = "ArkFabricator" .. tostring(A0_8772.m_instanceId) .. ": " .. A1_8773
  if A0_8772.m_bVerbose then
    System.Log(A1_8773)
  end
end
function Ark_sshain_Fabricator.Reset(A0_8774)
  local L1_8775
  L1_8775 = A0_8774.__super
  L1_8775 = L1_8775.SetFromProperties
  L1_8775(A0_8774)
  L1_8775 = A0_8774.__super
  L1_8775 = L1_8775.OnReset
  L1_8775(A0_8774)
  L1_8775 = A0_8774.Log
  L1_8775(A0_8774, "Fabricator: Reset")
  L1_8775 = A0_8774.GetRawId
  L1_8775 = L1_8775(A0_8774)
  A0_8774.m_instanceId = L1_8775
  L1_8775 = A0_8774.id
  Ark.AttachWorldUIInstanceToEntity(L1_8775, A0_8774.m_instanceId, A0_8774:GetMaterial(0), A0_8774.m_uiElementName, A0_8774.m_subMatIndex)
  UIAction.UnregisterElementListener(A0_8774, "OnButtonPress")
  UIAction.RegisterElementListener(A0_8774, A0_8774.m_uiElementName, A0_8774.m_instanceId, "fabricatorBtnPress", "OnButtonPress")
  A0_8774:PhysicalizeThis()
  if A0_8774.Properties.bUsable then
    A0_8774.m_usable = 1
  else
    A0_8774.m_usable = 0
  end
  if A0_8774.m_idleDelay < A0_8774.m_craftingDelay then
    A0_8774:Log("Fabricator Warning: Idle delay must be longer than crafting delay.")
    A0_8774.m_idleDelay = A0_8774.m_craftingDelay + 100
  end
  A0_8774.m_vecItemSpawnPos = A0_8774:GetBonePos(A0_8774:GetBoneNameFromTable(1))
  A0_8774.m_vecInteractPos = A0_8774:GetBonePos(A0_8774:GetBoneNameFromTable(2))
  A0_8774.m_fabPlans = {}
  A0_8774.m_planIndex = 1
  A0_8774.m_bVerbose = A0_8774.Properties.bVerbose
  if A0_8774.m_bVerbose then
    A0_8774:Log("Clearing crafting data for testing...")
    g_localActor:ClearAllArkInventory()
  end
  A0_8774:GotoState("Standby")
end
function Ark_sshain_Fabricator.Fabricate(A0_8776)
  local L1_8777
  L1_8777 = A0_8776.m_planIndex
  if L1_8777 ~= nil then
    L1_8777 = A0_8776.m_fabPlans
    L1_8777 = L1_8777[A0_8776.m_planIndex]
    if L1_8777 ~= nil then
      L1_8777 = A0_8776.m_fabPlans
      L1_8777 = L1_8777[A0_8776.m_planIndex]
      if A0_8776:PlayerHasPlanIngredients(L1_8777) then
        Script.KillTimer(A0_8776.m_timerId)
        A0_8776.m_timerId = Script.SetTimer(A0_8776.m_craftingDelay, function()
          _UPVALUE0_:SpawnItem(_UPVALUE1_)
        end)
        A0_8776:DebitPlanIngredients(L1_8777)
        A0_8776:GotoState("Busy")
      end
    end
  end
end
function Ark_sshain_Fabricator.GetPlayerItemQuantity(A0_8778, A1_8779)
  local L3_8780
  L3_8780 = 0
  for _FORV_6_, _FORV_7_ in ipairs(g_localActor:GetItems()) do
    if _FORV_7_ == A1_8779 then
      L3_8780 = L3_8780 + 1
    end
  end
  return L3_8780
end
function Ark_sshain_Fabricator.PlayerHasPlanIngredients(A0_8781, A1_8782)
  local L2_8783, L3_8784, L4_8785, L5_8786, L6_8787
  L2_8783 = g_localActor
  L3_8784 = L2_8783
  L2_8783 = L2_8783.GetIngredients
  L2_8783 = L2_8783(L3_8784)
  L3_8784 = L2_8783.organic
  L4_8785 = A1_8782.organic
  L3_8784 = L3_8784 >= L4_8785
  L4_8785 = L2_8783.mineral
  L5_8786 = A1_8782.mineral
  L4_8785 = L4_8785 >= L5_8786
  L5_8786 = L2_8783.synthetic
  L6_8787 = A1_8782.synthetic
  L5_8786 = L5_8786 >= L6_8787
  L6_8787 = L2_8783.exotic
  L6_8787 = L6_8787 >= A1_8782.exotic
  return L3_8784 and L4_8785 and L5_8786 and L6_8787
end
function Ark_sshain_Fabricator.GetPlayerFabPlans(A0_8788)
  return g_localActor:GetFabricationPlans()
end
function Ark_sshain_Fabricator.GetPlayerIngredientsAsArray(A0_8789)
  return {
    g_localActor:GetIngredients().organic,
    g_localActor:GetIngredients().mineral,
    g_localActor:GetIngredients().synthetic,
    g_localActor:GetIngredients().exotic
  }
end
function Ark_sshain_Fabricator.DebitPlanIngredients(A0_8790, A1_8791)
  g_localActor:RemoveIngredients(A1_8791)
end
function Ark_sshain_Fabricator.SpawnItem(A0_8792, A1_8793)
  local L2_8794, L3_8795
  L2_8794 = Particle
  L2_8794 = L2_8794.SpawnEffect
  L3_8795 = A0_8792.m_file_SpawnVFX
  L2_8794(L3_8795, A0_8792.m_vecItemSpawnPos, g_Vectors.v001)
  L2_8794 = {}
  L2_8794.class = A1_8793
  L3_8795 = A0_8792.m_vecItemSpawnPos
  L2_8794.position = L3_8795
  L2_8794.name = A1_8793
  L3_8795 = System
  L3_8795 = L3_8795.SpawnEntity
  L3_8795 = L3_8795(L2_8794)
  A0_8792:SetDisplayMode("ItemReady")
  A0_8792:StartItemClearTimer(L3_8795)
end
function Ark_sshain_Fabricator.StartItemClearTimer(A0_8796, A1_8797)
  A0_8796.m_timerId = Script.SetTimer(A0_8796.m_itemClearDelay, function()
    _UPVALUE0_:IsItemPresent(_UPVALUE1_)
  end)
end
function Ark_sshain_Fabricator.StartIdleTimer(A0_8798)
  A0_8798.m_timerId = Script.SetTimer(A0_8798.m_idleDelay, function()
    _UPVALUE0_:ReturnToStandby()
  end)
end
function Ark_sshain_Fabricator.IsItemPresent(A0_8799, A1_8800)
  if A1_8800 then
    A0_8799:Log("ItemId.bWasPickedUp: " .. tostring(A1_8800.bWasPickedUp))
  end
  if DistanceVectors(A1_8800:GetWorldPos(), A0_8799.m_vecItemSpawnPos) < A0_8799.m_fItemClearDist and not A1_8800.bWasPickedUp then
    A0_8799:StartItemClearTimer(A1_8800)
  else
    A0_8799:SetDisplayMode("ItemPickedUp")
    A0_8799:GotoState("InUse")
  end
end
function Ark_sshain_Fabricator.ReturnToStandby(A0_8801)
  if A0_8801.m_usable == 2 then
    if A0_8801:CheckDistanceToPlayer() > A0_8801.m_fInteractDist then
      A0_8801:GotoState("Standby")
    else
      A0_8801:StartIdleTimer()
    end
  end
end
function Ark_sshain_Fabricator.UpdateDisplayData(A0_8802)
  local L1_8803, L2_8804, L3_8805, L4_8806, L5_8807, L6_8808, L7_8809, L8_8810
  L1_8803 = A0_8802.GetPlayerIngredientsAsArray
  L1_8803 = L1_8803(L2_8804)
  L5_8807 = "ingredientsArray"
  L6_8808 = L1_8803
  L2_8804(L3_8805, L4_8806, L5_8807, L6_8808)
  A0_8802.m_fabPlans = L2_8804
  if L2_8804 > 0 then
    for L5_8807, L6_8808 in L2_8804(L3_8805) do
      L7_8809 = "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut"
      L8_8810 = false
      UIAction.CallFunction(A0_8802.m_uiElementName, A0_8802.m_instanceId, "fabricatorRecipeParams", L5_8807, L6_8808.itemName, L7_8809, L6_8808.organic, L6_8808.mineral, L6_8808.synthetic, L6_8808.exotic, A0_8802:GetPlayerItemQuantity(L6_8808.itemName), A0_8802:PlayerHasPlanIngredients(L6_8808), L8_8810)
    end
  else
    L5_8807 = "fabricatorRecipeParams"
    L6_8808 = 1
    L7_8809 = "ERROR: SEE DESCRIPTION"
    L8_8810 = "You currently have no fabrication plans for use with this Fabricator. Please come back when you have a fabrication plan."
    L2_8804(L3_8805, L4_8806, L5_8807, L6_8808, L7_8809, L8_8810, 0, 0, 0, 0, 0, false, false)
  end
end
function Ark_sshain_Fabricator.UpdateView(A0_8811)
  if #A0_8811:GetPlayerFabPlans() > 0 then
    UIAction.CallFunction(A0_8811.m_uiElementName, A0_8811.m_instanceId, "fabricatorHL", A0_8811.m_planIndex - 1)
  end
end
function Ark_sshain_Fabricator.SetDisplayMode(A0_8812, A1_8813, A2_8814)
  local L3_8815
  L3_8815 = "fabricator"
  L3_8815 = L3_8815 .. A1_8813
  if A2_8814 == nil then
    UIAction.CallFunction(A0_8812.m_uiElementName, A0_8812.m_instanceId, L3_8815)
  else
    UIAction.CallFunction(A0_8812.m_uiElementName, A0_8812.m_instanceId, L3_8815, A2_8814)
  end
end
function Ark_sshain_Fabricator.CheckDistanceToPlayer(A0_8816)
  local L1_8817, L2_8818
  L1_8817 = DistanceVectors
  L2_8818 = A0_8816.m_vecInteractPos
  L1_8817 = L1_8817(L2_8818, g_localActor:GetWorldPos())
  return L1_8817
end
function Ark_sshain_Fabricator.PlaySound(A0_8819, A1_8820)
  if not _sSound or A1_8820 ~= "" then
  end
end
function Ark_sshain_Fabricator.IsUsable(A0_8821, A1_8822)
  local L2_8823
  L2_8823 = 0
  if A0_8821.m_usable == 1 and A0_8821:CheckDistanceToPlayer() <= A0_8821.m_fInteractDist then
    L2_8823 = 1
  end
  return L2_8823
end
function Ark_sshain_Fabricator.GetUsableMessage(A0_8824, A1_8825)
  if A0_8824.m_usable == 1 then
    return A0_8824.m_useMessage
  else
    return "@use_object"
  end
end
function Ark_sshain_Fabricator.PhysicalizeThis(A0_8826)
  if A0_8826.Properties.object_Model ~= "" then
    A0_8826:LoadObject(0, A0_8826.Properties.object_Model)
  end
  BasicEntity.PhysicalizeThis(A0_8826)
end
function Ark_sshain_Fabricator.OnInit(A0_8827)
  A0_8827:Reset()
end
function Ark_sshain_Fabricator.OnUsed(A0_8828, A1_8829, A2_8830)
  A0_8828:GotoState("InUse")
  BroadcastEvent(A0_8828, "Used")
end
function Ark_sshain_Fabricator.OnButtonPress(A0_8831, A1_8832, A2_8833, A3_8834, A4_8835)
  local L5_8836
  L5_8836 = A4_8835[0]
  A0_8831:Log("Button pressed:" .. L5_8836)
  if L5_8836 == "Next" then
    A0_8831.m_planIndex = A0_8831.m_planIndex + 1
  elseif L5_8836 == "Prev" then
    A0_8831.m_planIndex = A0_8831.m_planIndex - 1
  elseif L5_8836 == "Create" then
    if A0_8831.m_usable == 2 then
      A0_8831:Fabricate()
    end
  elseif L5_8836 == "Start" then
    A0_8831:GotoState("InUse")
    BroadcastEvent(A0_8831, "Used")
  end
  if A0_8831.m_planIndex > #A0_8831.m_fabPlans then
    A0_8831.m_planIndex = 1
  elseif A0_8831.m_planIndex < 1 then
    A0_8831.m_planIndex = #A0_8831.m_fabPlans
  end
  A0_8831:UpdateView()
end
function Ark_sshain_Fabricator.OnPropertyChange(A0_8837)
  A0_8837:Reset()
end
function Ark_sshain_Fabricator.OnReset(A0_8838)
  A0_8838:Reset()
end
function Ark_sshain_Fabricator.Event_UserCommand(A0_8839, A1_8840, A2_8841)
  if A0_8839:CheckDistanceToPlayer() <= A0_8839.m_fInteractDist then
    if A2_8841 == "g" then
      A0_8839.m_planIndex = A0_8839.m_planIndex + 1
    elseif A2_8841 == "t" then
      A0_8839.m_planIndex = A0_8839.m_planIndex - 1
    elseif A2_8841 == "e" and A0_8839.m_usable == 2 then
      A0_8839:Fabricate()
    end
    if A0_8839.m_planIndex > #A0_8839.m_fabPlans then
      A0_8839.m_planIndex = 1
    elseif A0_8839.m_planIndex < 1 then
      A0_8839.m_planIndex = #A0_8839.m_fabPlans
    end
    A0_8839:UpdateView()
  end
end
Ark_sshain_Fabricator.Server.InUse = {
  OnBeginState = function(A0_8842)
    A0_8842:UpdateDisplayData()
    A0_8842:SetDisplayMode("Open")
    A0_8842:UpdateView()
    A0_8842.m_usable = 2
    A0_8842:StartIdleTimer()
    BroadcastEvent(A0_8842, "InUse")
    A0_8842:Log("In use state begin")
  end,
  OnEndState = function(A0_8843)
    A0_8843:Log("In use state end")
  end
}
Ark_sshain_Fabricator.Server.Busy = {
  OnBeginState = function(A0_8844)
    A0_8844:SetDisplayMode("BusyStart", A0_8844.m_craftingDelay * 0.001)
    A0_8844.m_usable = 0
    BroadcastEvent(A0_8844, "Busy")
    A0_8844:Log("Busy state begin")
  end,
  OnEndState = function(A0_8845)
    A0_8845:Log("Busy state end")
  end
}
Ark_sshain_Fabricator.Server.Standby = {
  OnBeginState = function(A0_8846)
    local L1_8847, L2_8848, L3_8849, L4_8850, L5_8851
    L1_8847(L2_8848, L3_8849)
    A0_8846.m_usable = 1
    L1_8847(L2_8848, L3_8849)
    L1_8847(L2_8848, L3_8849)
    L1_8847(L2_8848, L3_8849)
    L1_8847(L2_8848, L3_8849)
    L5_8851 = L2_8848(L3_8849)
    for L4_8850, L5_8851 in L1_8847(L2_8848, L3_8849, L4_8850, L5_8851, L2_8848(L3_8849)) do
      System.Log(tostring(L4_8850) .. " " .. L5_8851)
    end
  end,
  OnEndState = function(A0_8852)
    A0_8852:Log("standby state end")
  end
}
Ark_sshain_Fabricator.Server.Destroyed = {
  OnBeginState = function(A0_8853)
    A0_8853.m_usable = 0
    BroadcastEvent(A0_8853, "Destroyed")
  end,
  OnEndState = function(A0_8854)
    local L1_8855
  end
}
Ark_sshain_Fabricator.FlowEvents.Inputs.ButtonPress = {
  Ark_sshain_Fabricator.Event_OnButtonPress,
  "string"
}
Ark_sshain_Fabricator.FlowEvents.Inputs.UserCommand = {
  Ark_sshain_Fabricator.Event_UserCommand,
  "string"
}
Ark_sshain_Fabricator.FlowEvents.Outputs.CurrentPlan = "string"
Ark_sshain_Fabricator.FlowEvents.Outputs.UserHelp = "string"
Ark_sshain_Fabricator.FlowEvents.Outputs.InUse = "bool"
Ark_sshain_Fabricator.FlowEvents.Outputs.Busy = "bool"
Ark_sshain_Fabricator.FlowEvents.Outputs.Standby = "bool"
Ark_sshain_Fabricator.FlowEvents.Outputs.Destroyed = "bool"
