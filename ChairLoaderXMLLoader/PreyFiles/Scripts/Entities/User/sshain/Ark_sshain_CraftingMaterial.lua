local L0_8730, L1_8731, L2_8732
L0_8730 = {}
L1_8731 = {}
L1_8731.nMinValue = 3
L1_8731.nMaxValue = 20
L1_8731.nIngredientType = 0
L0_8730.Properties = L1_8731
L1_8731 = {}
L1_8731.Icon = "Seed.bmp"
L0_8730.Editor = L1_8731
L0_8730.m_usable = 1
L0_8730.m_useMessage = ""
L0_8730.m_modelPath = "GameSDK/Objects/User/sshain/pickups/Ark_sshain_pickup_"
L0_8730.m_ingredientType = "organic"
L0_8730.m_value = 1
Ark_sshain_CraftingMaterial = L0_8730
L0_8730 = Ark_sshain_CraftingMaterial
function L1_8731(A0_8733)
  local L1_8734
  L1_8734 = {
    "organic",
    "mineral",
    "synthetic",
    "exotic"
  }
  if A0_8733.Properties.nIngredientType ~= 0 then
  end
  A0_8733.m_ingredientType = L1_8734[A0_8733.Properties.nIngredientType]
  A0_8733.m_value = math.random(A0_8733.Properties.nMinValue, A0_8733.Properties.nMaxValue)
  A0_8733.Properties.object_Model = A0_8733.m_modelPath .. A0_8733.m_ingredientType .. ".cgf"
  A0_8733.m_useMessage = tostring(A0_8733.m_value) .. " " .. A0_8733.m_ingredientType .. " ingredients"
  A0_8733:LoadObject(0, A0_8733.Properties.object_Model)
end
L0_8730.Reset = L1_8731
L0_8730 = Ark_sshain_CraftingMaterial
function L1_8731(A0_8735, A1_8736)
  local L2_8737
  A0_8735.m_usable = 1
  L2_8737 = A0_8735.m_usable
  return L2_8737
end
L0_8730.IsUsable = L1_8731
L0_8730 = Ark_sshain_CraftingMaterial
function L1_8731(A0_8738, A1_8739)
  if A0_8738.m_usable == 1 then
    return A0_8738.m_useMessage
  else
    return "@use_object"
  end
end
L0_8730.GetUsableMessage = L1_8731
L0_8730 = Ark_sshain_CraftingMaterial
function L1_8731(A0_8740)
  A0_8740:Reset()
  A0_8740:PhysicalizeThis()
end
L0_8730.OnInit = L1_8731
L0_8730 = Ark_sshain_CraftingMaterial
function L1_8731(A0_8741)
  A0_8741:Reset()
end
L0_8730.OnPropertyChange = L1_8731
L0_8730 = Ark_sshain_CraftingMaterial
function L1_8731(A0_8742)
  A0_8742:Reset()
end
L0_8730.OnReset = L1_8731
L0_8730 = Ark_sshain_CraftingMaterial
function L1_8731(A0_8743, A1_8744, A2_8745)
  A1_8744:AddIngredient(A0_8743.m_ingredientType, A0_8743.m_value)
  BroadcastEvent(A0_8743, "Used")
  A0_8743:Hide(1)
end
L0_8730.OnUsed = L1_8731
L0_8730 = Ark_sshain_CraftingMaterial
function L1_8731(A0_8746)
  local L1_8747
  L1_8747 = {}
  L1_8747.bRigidBody = 1
  L1_8747.bRigidBodyActive = 0
  L1_8747.bRigidBodyAfterDeath = 1
  L1_8747.bResting = 1
  L1_8747.Density = 999
  L1_8747.Mass = -1
  EntityCommon.PhysicalizeRigid(A0_8746, 0, L1_8747, 1)
end
L0_8730.PhysicalizeThis = L1_8731
L0_8730 = Ark_sshain_CraftingMaterial
L1_8731 = {}
L2_8732 = {}
L1_8731.Inputs = L2_8732
L2_8732 = {}
L2_8732.Used = "bool"
L1_8731.Outputs = L2_8732
L0_8730.FlowEvents = L1_8731
