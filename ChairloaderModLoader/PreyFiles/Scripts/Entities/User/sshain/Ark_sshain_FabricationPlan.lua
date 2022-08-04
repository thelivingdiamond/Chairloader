local L0_8748, L1_8749, L2_8750
L0_8748 = {}
L1_8749 = {}
L1_8749.sFabricationPlan = "random"
L1_8749.object_Model = "GameSDK/Objects/User/sshain/pickups/Ark_sshain_pickup_fabplan.cgf"
L0_8748.Properties = L1_8749
L1_8749 = {}
L1_8749.Icon = "Seed.bmp"
L0_8748.Editor = L1_8749
L1_8749 = {}
L0_8748.m_fabPlan = L1_8749
L0_8748.m_usable = 1
L0_8748.m_useMessage = "Fabrication Plan"
Ark_sshain_FabricationPlan = L0_8748
L0_8748 = Ark_sshain_FabricationPlan
function L1_8749(A0_8751)
  A0_8751.m_fabPlan = A0_8751:GetFabricationPlanByName(A0_8751.Properties.sFabricationPlan)
  if A0_8751.m_fabPlan ~= nil then
    A0_8751.Properties.sFabricationPlan = A0_8751.m_fabPlan.itemName
    A0_8751.m_useMessage = A0_8751.Properties.sFabricationPlan .. " Fabrication Plan"
    A0_8751:LoadObject(0, A0_8751.Properties.object_Model)
    A0_8751:PhysicalizeThis()
  else
    LogWarning(A0_8751.class .. " has invalid FabricationPlan specified or FabricationPlan data not loaded.")
  end
end
L0_8748.Reset = L1_8749
L0_8748 = Ark_sshain_FabricationPlan
function L1_8749(A0_8752, A1_8753)
  local L2_8754, L3_8755
  L3_8755 = g_localActor
  L3_8755 = L3_8755.AllFabPlans
  if L3_8755 then
    L3_8755 = g_localActor
    L3_8755 = L3_8755.AllFabPlans
    if A1_8753 == "random" then
      L2_8754 = A0_8752:GetRandomPlan(L3_8755)
    else
      for _FORV_7_, _FORV_8_ in ipairs(L3_8755) do
        if A1_8753 == _FORV_8_.itemName then
        end
      end
    end
  end
  return L2_8754
end
L0_8748.GetFabricationPlanByName = L1_8749
L0_8748 = Ark_sshain_FabricationPlan
function L1_8749(A0_8756, A1_8757)
  local L2_8758
  L2_8758 = #A1_8757
  L2_8758 = L2_8758 or 0
  if L2_8758 ~= 0 then
    return A1_8757[math.random(1, L2_8758)]
  else
    return nil
  end
end
L0_8748.GetRandomPlan = L1_8749
L0_8748 = Ark_sshain_FabricationPlan
function L1_8749(A0_8759, A1_8760)
  local L2_8761
  A0_8759.m_usable = 1
  L2_8761 = A0_8759.m_usable
  return L2_8761
end
L0_8748.IsUsable = L1_8749
L0_8748 = Ark_sshain_FabricationPlan
function L1_8749(A0_8762, A1_8763)
  if A0_8762.m_usable == 1 then
    return A0_8762.m_useMessage
  else
    return "@use_object"
  end
end
L0_8748.GetUsableMessage = L1_8749
L0_8748 = Ark_sshain_FabricationPlan
function L1_8749(A0_8764)
  System.Log(A0_8764.class .. " OnInit")
end
L0_8748.OnInit = L1_8749
L0_8748 = Ark_sshain_FabricationPlan
function L1_8749(A0_8765)
  A0_8765:Reset()
end
L0_8748.OnPropertyChange = L1_8749
L0_8748 = Ark_sshain_FabricationPlan
function L1_8749(A0_8766)
  A0_8766:Reset()
end
L0_8748.OnReset = L1_8749
L0_8748 = Ark_sshain_FabricationPlan
function L1_8749(A0_8767, A1_8768, A2_8769)
  if A1_8768:AddFabricationPlan(A0_8767.m_fabPlan) == false then
  end
  BroadcastEvent(A0_8767, "Used")
  A0_8767:Hide(1)
end
L0_8748.OnUsed = L1_8749
L0_8748 = Ark_sshain_FabricationPlan
function L1_8749(A0_8770)
  local L1_8771
  L1_8771 = {}
  L1_8771.bRigidBody = 1
  L1_8771.bRigidBodyActive = 0
  L1_8771.bRigidBodyAfterDeath = 1
  L1_8771.bResting = 1
  L1_8771.Density = 999
  L1_8771.Mass = -1
  EntityCommon.PhysicalizeRigid(A0_8770, 0, L1_8771, 1)
end
L0_8748.PhysicalizeThis = L1_8749
L0_8748 = Ark_sshain_FabricationPlan
L1_8749 = {}
L2_8750 = {}
L1_8749.Inputs = L2_8750
L2_8750 = {}
L2_8750.Used = "bool"
L1_8749.Outputs = L2_8750
L0_8748.FlowEvents = L1_8749
