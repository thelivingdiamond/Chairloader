local L0_5331, L1_5332, L2_5333, L3_5334
L0_5331 = {}
L0_5331.type = "TowerSearchLight"
L1_5332 = {}
L1_5332.bEnabled = 1
L1_5332.bCanDetectStealth = 0
L1_5332.bAlwaysSeePlayer = 0
L1_5332.visionFOV = 5
L1_5332.visionRange = 1000
L1_5332.hearingRange = 200
L1_5332.alertAIGroupId = -1
L1_5332.burstDispersion = 10
L1_5332.timeBetweenShootsInABurst = 0.5
L1_5332.offsetDistPrediction = 10
L1_5332.minPlayerSpeedForOffsetDistPrediction = 0.3
L1_5332.maxDistancePrediction = 0
L1_5332.preshootTime = 2
L1_5332.weapon = "TowerRocketLauncher"
L1_5332.objLaserBeamModel = "engine/engineassets/objects/default.cgf"
L1_5332.audioBackground = "TowerSearchLight_Background"
L1_5332.audioShoot = "TowerSearchLight_Shoot"
L1_5332.audioPreshoot = "TowerSearchLight_Preshoot"
L1_5332.laserBeamThicknessScale = 20
L1_5332.visionPersistenceTime = 0
L2_5333 = {}
L3_5334 = {}
L3_5334.linkName = ""
L3_5334.distFromTarget = 0
L3_5334.rotationZ = 0
L2_5333.attachment1 = L3_5334
L3_5334 = {}
L3_5334.linkName = ""
L3_5334.distFromTarget = 0
L3_5334.rotationZ = 0
L2_5333.attachment2 = L3_5334
L3_5334 = {}
L3_5334.linkName = ""
L3_5334.distFromTarget = 0
L3_5334.rotationZ = 0
L2_5333.attachment3 = L3_5334
L3_5334 = {}
L3_5334.linkName = ""
L3_5334.distFromTarget = 0
L3_5334.rotationZ = 0
L2_5333.attachment4 = L3_5334
L1_5332.attachments = L2_5333
L2_5333 = {}
L3_5334 = {}
L3_5334.bEnabled = 1
L3_5334.vOffset = {
  x = 0,
  y = 0,
  z = 0
}
L2_5333.spot1 = L3_5334
L3_5334 = {}
L3_5334.bEnabled = 0
L3_5334.vOffset = {
  x = 0,
  y = 0,
  z = 0
}
L2_5333.spot2 = L3_5334
L3_5334 = {}
L3_5334.bEnabled = 0
L3_5334.vOffset = {
  x = 0,
  y = 0,
  z = 0
}
L2_5333.spot3 = L3_5334
L1_5332.weaponSpots = L2_5333
L2_5333 = {}
L3_5334 = {}
L3_5334.timeToFirstBurst = 1.5
L3_5334.timeToFirstBurstIfStealth = 1.5
L3_5334.numWarningBursts = 0
L3_5334.timeBetweenWarningBursts = 5
L3_5334.errorAddedToWarningBursts = 10
L3_5334.timeBetweenBursts = 5
L3_5334.followDelay = 1
L3_5334.trackSpeed = 3
L3_5334.detectionSoundSequenceCoolDownTime = 20
L3_5334.audioDetection1 = {
  audio = "TowerSearchLight_Detection1",
  delay = 0
}
L3_5334.audioDetection2 = {
  audio = "TowerSearchLight_Detection2",
  delay = 1
}
L3_5334.audioDetection3 = {
  audio = "TowerSearchLight_Detection3",
  delay = 1.5
}
L2_5333.enemyInView = L3_5334
L3_5334 = {}
L3_5334.maxDistSearch = 6
L3_5334.timeSearching = 10
L3_5334.searchSpeed = 3
L3_5334.timeToFirstBurst = 1000
L3_5334.timeBetweenBursts = 10
L3_5334.minErrorShoot = 5
L3_5334.maxErrorShoot = 15
L2_5333.enemyLost = L3_5334
L1_5332.behaviour = L2_5333
L0_5331.Properties = L1_5332
L1_5332 = {}
L1_5332.Icon = "mine.bmp"
L0_5331.Editor = L1_5332
L1_5332 = {}
L0_5331.Client = L1_5332
L1_5332 = {}
L0_5331.Server = L1_5332
TowerSearchLight = L0_5331
L0_5331 = TowerSearchLight
function L1_5332(A0_5335)
  A0_5335.TowerSearchLight:OnPropertyChange()
end
L0_5331.OnPropertyChange = L1_5332
L0_5331 = TowerSearchLight
function L1_5332(A0_5336, A1_5337, A2_5338)
  A0_5336.TowerSearchLight:SetEntityIdleMovement(A2_5338.id)
end
L0_5331.Event_SetEntityIdleMovement = L1_5332
L0_5331 = TowerSearchLight
function L1_5332(A0_5339, A1_5340, A2_5341)
  A0_5339.TowerSearchLight:SetAlertAIGroupID(A2_5341)
end
L0_5331.Event_SetAlertAIGroupId = L1_5332
L0_5331 = TowerSearchLight
function L1_5332(A0_5342)
  A0_5342.TowerSearchLight:Enable()
end
L0_5331.Event_Enable = L1_5332
L0_5331 = TowerSearchLight
function L1_5332(A0_5343)
  A0_5343.TowerSearchLight:Disable()
end
L0_5331.Event_Disable = L1_5332
L0_5331 = TowerSearchLight
function L1_5332(A0_5344)
  A0_5344.TowerSearchLight:Sleep()
end
L0_5331.Event_Sleep = L1_5332
L0_5331 = TowerSearchLight
function L1_5332(A0_5345)
  A0_5345.TowerSearchLight:Wakeup()
end
L0_5331.Event_Wakeup = L1_5332
L0_5331 = TowerSearchLight
function L1_5332(A0_5346)
  A0_5346.TowerSearchLight:DisableWeaponSpot(0)
end
L0_5331.Event_DisableWeaponSpot1 = L1_5332
L0_5331 = TowerSearchLight
function L1_5332(A0_5347)
  A0_5347.TowerSearchLight:DisableWeaponSpot(1)
end
L0_5331.Event_DisableWeaponSpot2 = L1_5332
L0_5331 = TowerSearchLight
function L1_5332(A0_5348)
  A0_5348.TowerSearchLight:DisableWeaponSpot(2)
end
L0_5331.Event_DisableWeaponSpot3 = L1_5332
L0_5331 = TowerSearchLight
L1_5332 = {}
L2_5333 = {}
L3_5334 = {
  TowerSearchLight.Event_SetAlertAIGroupId,
  "int"
}
L2_5333.SetAlertAIGroupId = L3_5334
L3_5334 = {
  TowerSearchLight.Event_SetEntityIdleMovement,
  "entity"
}
L2_5333.SetEntityIdleMovement = L3_5334
L3_5334 = {
  TowerSearchLight.Event_Enable,
  "any"
}
L2_5333.Enable = L3_5334
L3_5334 = {
  TowerSearchLight.Event_Disable,
  "any"
}
L2_5333.Disable = L3_5334
L3_5334 = {
  TowerSearchLight.Event_Sleep,
  "any"
}
L2_5333.Sleep = L3_5334
L3_5334 = {
  TowerSearchLight.Event_Wakeup,
  "any"
}
L2_5333.Wakeup = L3_5334
L3_5334 = {
  TowerSearchLight.Event_DisableWeaponSpot1,
  "any"
}
L2_5333.DisableWeaponSpot1 = L3_5334
L3_5334 = {
  TowerSearchLight.Event_DisableWeaponSpot2,
  "any"
}
L2_5333.DisableWeaponSpot2 = L3_5334
L3_5334 = {
  TowerSearchLight.Event_DisableWeaponSpot3,
  "any"
}
L2_5333.DisableWeaponSpot3 = L3_5334
L1_5332.Inputs = L2_5333
L2_5333 = {}
L2_5333.PlayerDetected = "bool"
L2_5333.SoundHeard = "bool"
L2_5333.PlayerLost = "bool"
L2_5333.Preshoot = "bool"
L2_5333.Shoot = "bool"
L2_5333.Burst = "bool"
L1_5332.Outputs = L2_5333
L0_5331.FlowEvents = L1_5332
