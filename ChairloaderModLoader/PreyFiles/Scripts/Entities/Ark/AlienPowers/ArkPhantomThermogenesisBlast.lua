Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkPhantomThermogenesisBlast = {
  Properties = {
    object_Model = "",
    bUsable = 0,
    Physics = {
      bPhysicalize = 0,
      bRigidBody = 0,
      bPushableByPlayers = 0,
      bPushableByAI = 0,
      Density = -1,
      Mass = -1
    },
    signalpackage_SignalPackageId = "10641886185795227403",
    fMinimumSignalPercent = 0.5,
    TelegraphEffect = {audioTrigger_Telegraph = "", fBaseParticleRadius = 1},
    ExplosionEffect = {
      audioTrigger_Explosion = "",
      fExplosionEffectLifetime = 5,
      fBaseParticleRadius = 3,
      fExplosionDamageDelay = 0.7,
      fExplosionImpulse = 550
    }
  },
  Editor = {Icon = "", IconOnTop = 1}
}
