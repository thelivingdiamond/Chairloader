Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkNozzle = {
  Properties = {
    object_Model = "",
    UseMessage = "",
    bUsable = 0,
    Physics = {
      bPhysicalize = 1,
      bRigidBody = 1,
      bPushableByPlayers = 1,
      bPushableByAI = 1,
      Density = -1,
      Mass = -1
    }
  },
  Editor = {
    Icon = "physicsobject.bmp",
    IconOnTop = 1
  },
  m_bVerbose = false,
  signalListened = "3149325216915549017"
}
GetArkEntityUtils(ArkNozzle)
SetupCollisionFiltering(ArkNozzle)
function ArkNozzle.OnSpawn(A0_4391)
  Ark.RegisterForSignal(A0_4391.id, A0_4391.signalListened)
end
function ArkNozzle.OnSignalReceived(A0_4392)
  BroadcastEvent(A0_4392, "Gooed")
end
ArkNozzle.FlowEvents = {
  Inputs = {},
  Outputs = {Gooed = "bool"}
}
