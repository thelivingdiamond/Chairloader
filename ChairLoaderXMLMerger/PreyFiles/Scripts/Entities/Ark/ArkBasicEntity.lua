Script.ReloadScript("scripts/ArkEntityUtils.lua")
Script.ReloadScript("scripts/Utils/EntityUtils.lua")
ArkBasicEntity = {
  Properties = {
    object_Model = "",
    bDisallowGrenades = true,
    UseMessage = "",
    bUsable = 1,
    Physics = {
      bPhysicalize = 1,
      bRigidBody = 0,
      bPushableByPlayers = 1,
      bPushableByAI = 0,
      Density = -1,
      Mass = -1
    }
  },
  Editor = {
    Icon = "physicsobject.bmp",
    IconOnTop = 1
  },
  m_bVerbose = false
}
GetArkEntityUtils(ArkBasicEntity)
function ArkBasicEntity.PhysicalizeThis(A0_3486)
  A0_3486:Log("PhysicalizeThis")
  EntityCommon.PhysicalizeRigid(A0_3486, 0, A0_3486.Properties.Physics, 0)
  ApplyCollisionFiltering(A0_3486, {collisionClass = collision_class_articulated})
end
