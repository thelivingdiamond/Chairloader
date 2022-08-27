Script.ReloadScript("Scripts/Entities/Physics/DestroyableObject.lua")
ArkLaserBeamSplitter = {
  Properties = {
    object_Model = "Objects/default/primitive_box.cgf",
    object_ModelDestroyed = "Objects/default/primitive_sphere.cgf",
    BeamSplitter = {
      PrimaryWeapon = "ArkBeamSplitterLaser",
      PrimaryWeaponJointName = "weaponjoint",
      bVerboseLogging = 0,
      fChargingTime = 0.75,
      fMaxGlowAmount = 5,
      fSplitDegreesPerSecond = 60
    }
  },
  Editor = {Icon = "mine.bmp", IconOnTop = 1},
  Client = {},
  Server = {},
  defaultMaterial = "Materials/ArkEffects/Temporary/beamsplitter",
  bVerbose = false
}
ArkMakeDerivedEntityOverride(ArkLaserBeamSplitter, DestroyableObject, true)
function ArkLaserBeamSplitter.Log(A0_4196, A1_4197)
  if A0_4196.bVerbose then
    System.Log(A1_4197)
  end
end
function ArkLaserBeamSplitter.Server.OnInit(A0_4198)
  A0_4198.bVerbose = A0_4198.Properties.BeamSplitter.bVerboseLogging == 1
  A0_4198:CommonInit()
  A0_4198:SetMaterial(A0_4198.defaultMaterial)
  A0_4198:Log("ArkLaserBeamSplitter Game Init!")
end
function ArkLaserBeamSplitter.Event_StartFiring(A0_4199, A1_4200)
  BroadcastEvent(A0_4199, "Started")
end
function ArkLaserBeamSplitter.Event_StopFiring(A0_4201, A1_4202)
  BroadcastEvent(A0_4201, "Stopped")
end
ArkLaserBeamSplitter.FlowEvents.Inputs.StartFiring = {
  ArkLaserBeamSplitter.Event_StartFiring,
  "bool"
}
ArkLaserBeamSplitter.FlowEvents.Inputs.StopFiring = {
  ArkLaserBeamSplitter.Event_StopFiring,
  "bool"
}
ArkLaserBeamSplitter.FlowEvents.Outputs.Destroyed = "bool"
ArkLaserBeamSplitter.FlowEvents.Outputs.Damaged = "bool"
ArkLaserBeamSplitter.FlowEvents.Outputs.Started = "bool"
ArkLaserBeamSplitter.FlowEvents.Outputs.Stopped = "bool"
