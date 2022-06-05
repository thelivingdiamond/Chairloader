Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkTelescope = {
  Properties = {
    object_Model = "Objects/Environment/Props/NeoDeco/Telescope_A/telescope_a.cgf",
    vector_CameraInterpolationOffset = {
      x = 0,
      y = -2.13,
      z = 1.35
    },
    vector_CameraInteropolationRotation = {
      x = -55,
      y = 0,
      z = 0
    },
    vector_CameraStablePositionOffset = {
      x = 0,
      y = 1.75,
      z = 2.2
    },
    vector_CameraStablePositionRotation = {
      x = 25,
      y = 0,
      z = 0
    },
    InteractionFOV = 30,
    vector_InteractionOffset = {
      x = 0,
      y = -2.13,
      z = 1.3
    },
    text_DisplayName = "@prop_telescope",
    Physics = {
      bPhysicalize = 1,
      bRigidBody = 0,
      bPushableByPlayers = 0,
      bPushableByAI = 0,
      bResting = 1,
      bRigidBodyActive = 1,
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
  Editor = {
    Icon = "Clouds.bmp",
    IconOnTop = 1,
    IsScalable = false
  },
  PropertiesInstance = {bVerbose = 0, bStartsEnabled = 1}
}
GetArkEntityUtils(ArkTelescope)
SetupCollisionFiltering(ArkTelescope)
function ArkTelescope.Init(A0_4579, A1_4580)
end
function ArkTelescope.SetFromProperties(A0_4581)
  local L1_4582
end
function ArkTelescope.OnReset(A0_4583, A1_4584)
end
function ArkTelescope.OnSpawn(A0_4585)
  local L1_4586
end
ArkTelescope.FlowEvents = {
  Outputs = {OnUsed = "bool"}
}
