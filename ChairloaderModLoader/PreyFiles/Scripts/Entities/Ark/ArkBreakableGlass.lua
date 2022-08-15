Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkBreakableGlass = {
  Properties = {
    object_Model = "",
    audioOcclusion = 1,
    audioOcclusionBroken = 0,
    Physics = {
      bPhysicalize = 1,
      bRigidBody = 0,
      bPushableByPlayers = 0,
      bPushableByAI = 0,
      bResting = 1,
      bRigidBodyActive = 0,
      Density = -1,
      Mass = -1
    }
  }
}
GetArkEntityUtils(ArkBreakableGlass)
SetupCollisionFiltering(ArkBreakableGlass)
function ArkBreakableGlass.SetFromProperties(A0_3512)
  A0_3512:SetupModelAndPhysics()
end
function ArkBreakableGlass.OnBreakable2d(A0_3513)
  A0_3513:ActivateOutput("Break", true)
end
function ArkBreakableGlass.OnReset(A0_3514, A1_3515)
  A0_3514:SetFromProperties()
end
function ArkBreakableGlass.OnSpawn(A0_3516)
  A0_3516:SetFromProperties()
end
ArkBreakableGlass.FlowEvents = {
  Outputs = {Break = "int"}
}
