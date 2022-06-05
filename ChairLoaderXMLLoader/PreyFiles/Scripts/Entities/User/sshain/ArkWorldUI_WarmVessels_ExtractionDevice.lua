Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkWorldUI_WarmVessels_ExtractionDevice = {
  Properties = {
    object_Model = "objects/user/ebeyhl/cylinder_window_01/canister_bait_a.cgf",
    UseMessage = "",
    bUsable = 1,
    Physics = {
      bPhysicalize = 1,
      bRigidBody = 1,
      bPushableByPlayers = 1,
      Density = -1,
      Mass = -1
    }
  },
  Editor = {
    Icon = "physicsobject.bmp",
    IconOnTop = 1
  },
  m_usable = 1,
  m_bVerbose = false
}
GetArkEntityUtils(ArkWorldUI_WarmVessels_ExtractionDevice)
function ArkWorldUI_WarmVessels_ExtractionDevice.IsUsable(A0_9051, A1_9052)
  local L2_9053
  L2_9053 = A0_9051.m_usable
  return L2_9053
end
function ArkWorldUI_WarmVessels_ExtractionDevice.GetUsableMessage(A0_9054, A1_9055)
  local L2_9056
  L2_9056 = "Insert Extraction Bait"
  return L2_9056
end
function ArkWorldUI_WarmVessels_ExtractionDevice.Event_Reset(A0_9057)
  local L1_9058
  A0_9057.m_usable = 1
end
function ArkWorldUI_WarmVessels_ExtractionDevice.OnStartGame(A0_9059)
  local L1_9060
  A0_9059.m_usable = 1
end
ArkWorldUI_WarmVessels_ExtractionDevice.FlowEvents = {
  Inputs = {
    Reset = {
      ArkWorldUI_WarmVessels_ExtractionDevice.Event_Reset,
      "bool"
    }
  },
  Outputs = {BaitLoaded = "bool"}
}
