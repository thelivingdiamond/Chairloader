Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkEMPBlast = {
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
    signalpackage_SignalPackageId = "17591291352644797374",
    fMinimumDamagePercent = 0.5,
    TelegraphEffect = {
      particleeffect_Telegraph = "Characters.Aliens.Technopath.Cast.BodyCast",
      audioTrigger_Telegraph = "",
      fBaseParticleRadius = 1
    },
    ExplosionEffect = {
      particleeffect_Explosion = "Characters.Aliens.Technopath.EmpBlast.EmpExplosion",
      audioTrigger_Explosion = "",
      fExplosionEffectLifetime = 5,
      fBaseParticleRadius = 3,
      fExplosionDamageDelay = 0.45
    }
  },
  Editor = {Icon = "", IconOnTop = 1}
}
