Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkClock = {
  Properties = {
    object_Model = "",
    anim_Animation = "",
    Physics = {
      bPhysicalize = 1,
      bRigidBody = 0,
      bPushableByPlayers = 0,
      bPushableByAI = 0,
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
    Icon = "clock.bmp",
    IconOnTop = 1,
    IsScalable = false
  }
}
GetArkEntityUtils(ArkClock)
SetupCollisionFiltering(ArkClock)
function ArkClock.Init(A0_3600, A1_3601)
end
function ArkClock.SetFromProperties(A0_3602)
  local L1_3603
end
function ArkClock.OnSpawn(A0_3604)
  local L1_3605
end
function ArkClock.OnReset(A0_3606)
  local L1_3607
end
