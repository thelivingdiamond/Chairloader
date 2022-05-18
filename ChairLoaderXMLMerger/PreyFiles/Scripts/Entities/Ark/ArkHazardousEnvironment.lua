Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkHazardousEnvironment = {
  Properties = {
    Physics = {
      bPhysicalize = 0,
      bRigidBody = 0,
      bPushableByPlayers = 0,
      bPushableByAI = 0,
      Density = -1,
      Mass = -1
    }
  },
  Editor = {Icon = "hazard.bmp", IconOnTop = 1},
  iUpdateRate = 33,
  bVerbose = true
}
GetArkEntityUtils(ArkHazardousEnvironment)
function ArkHazardousEnvironment.Reset(A0_4055)
  A0_4055:SetIsZeroGMode(false)
  A0_4055:SetScriptUpdateRate(A0_4055.iUpdateRate)
  A0_4055:Activate(0)
end
function ArkHazardousEnvironment.SetIsZeroGMode(A0_4056, A1_4057)
  local L2_4058
  L2_4058 = 0
  if A1_4057 then
    L2_4058 = 1
  end
  System.SetCVar("pl_forcezerogmode", L2_4058)
  A0_4056.bIsZeroGMode = A1_4057
end
function ArkHazardousEnvironment.OnInit(A0_4059)
  A0_4059:Log("OnInit")
  A0_4059:Reset()
end
function ArkHazardousEnvironment.OnStartGame(A0_4060)
  A0_4060:Log("OnStartGame")
end
function ArkHazardousEnvironment.OnReset(A0_4061)
  A0_4061:Log("OnReset - Resetting...")
  A0_4061:Reset()
end
function ArkHazardousEnvironment.OnDestroy(A0_4062)
  A0_4062:Log("OnDestroy - Destroying...")
  A0_4062:Reset()
end
function ArkHazardousEnvironment.Event_GravityOn(A0_4063)
  A0_4063:SetIsZeroGMode(false)
  BroadcastEvent(A0_4063, "GravityUpdated")
end
function ArkHazardousEnvironment.Event_GravityOff(A0_4064)
  A0_4064:SetIsZeroGMode(true)
  BroadcastEvent(A0_4064, "GravityUpdated")
end
ArkHazardousEnvironment.FlowEvents = {
  Inputs = {
    GravityOn = {
      ArkHazardousEnvironment.Event_GravityOn,
      "bool"
    },
    GravityOff = {
      ArkHazardousEnvironment.Event_GravityOff,
      "bool"
    },
    AtmosphereOn = {
      ArkHazardousEnvironment.Event_AtmosphereOn,
      "bool"
    },
    AtmosphereOff = {
      ArkHazardousEnvironment.Event_AtmosphereOff,
      "bool"
    }
  },
  Outputs = {GravityUpdated = "bool", AtmosphereUpdated = "bool"}
}
