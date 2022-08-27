Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkTrackingCamera = {
  Properties = {
    object_Model = "",
    fAreaRadius = 1,
    nTargetReevaluationInterval = 1000,
    yawJointName = "",
    bDisallowGrenades = true,
    fRadiansPerSec = 3.1,
    Sound = {audioTrigger_StartRotating = "", audioTrigger_StopRotating = ""},
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
    Disrupt = {
      disruptionProfile_Profile = "10739735956140212131",
      particleeffect_SparkVFX = "",
      audioTrigger_SparkSFX = ""
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
    Icon = "Hazard.bmp",
    IconOnTop = 1,
    IsScalable = false
  },
  PropertiesInstance = {bVerbose = 0, bStartsEnabled = 1}
}
GetArkEntityUtils(ArkTrackingCamera)
SetupCollisionFiltering(ArkTrackingCamera)
function ArkTrackingCamera.Init(A0_4629, A1_4630)
end
function ArkTrackingCamera.SetFromProperties(A0_4631)
  local L1_4632
end
function ArkTrackingCamera.OnReset(A0_4633, A1_4634)
end
function ArkTrackingCamera.OnSpawn(A0_4635)
  local L1_4636
end
function ArkTrackingCamera.Event_Enable(A0_4637)
  Ark.EnableTrackingCamera(A0_4637.id, true)
end
function ArkTrackingCamera.Event_Disable(A0_4638)
  Ark.EnableTrackingCamera(A0_4638.id, false)
end
ArkTrackingCamera.FlowEvents = {
  Inputs = {
    Enable = {
      ArkTrackingCamera.Event_Enable,
      "bool"
    },
    Disable = {
      ArkTrackingCamera.Event_Disable,
      "bool"
    }
  },
  Outputs = {
    Out = "bool",
    Enabled = "bool",
    Disabled = "bool"
  }
}
