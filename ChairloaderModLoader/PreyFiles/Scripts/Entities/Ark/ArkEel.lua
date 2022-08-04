Script.ReloadScript("scripts/ArkEntityUtils.lua")
ArkEel = {
  Properties = {
    object_Model = "Objects/characters/animals/Eel/Eel.cdf",
    Physics = {
      bPhysicalize = 1,
      bRigidBody = 1,
      signalpackage_collisionDamagePackage = "3149325216948552760",
      bPushableByPlayers = 1,
      bPushableByAI = 1,
      bResting = 1,
      bArticulated = 1,
      bRigidBodyActive = 1,
      Density = -1,
      Mass = 5
    },
    RecycleData = {
      organic = 50,
      mineral = 0,
      synthetic = 0,
      exotic = 0
    }
  },
  PropertiesInstance = {bForceWakeOnGameStart = 0},
  Editor = {
    IconOnTop = false,
    Icon = "Fish.bmp",
    ShowBounds = 0,
    IsScalable = false
  }
}
GetArkEntityUtils(ArkEel)
SetupCollisionFiltering(ArkEel)
function ArkEel.SetFromProperties(A0_3700)
  A0_3700:LoadCharacter(0, A0_3700.Properties.object_Model)
  A0_3700:PhysicalizeThis()
  A0_3700:RagDollize(0)
  if A0_3700.PropertiesInstance.bForceWakeOnGameStart ~= 0 then
    A0_3700:AddImpulse(0, g_Vectors.v000, g_Vectors.up, 0.25, 1, g_Vectors.up, 0.25, 1)
  end
end
function ArkEel.OnStartGame(A0_3701)
  A0_3701:SetFromProperties()
end
function ArkEel.OnPostLoad(A0_3702)
  A0_3702:SetFromProperties()
end
