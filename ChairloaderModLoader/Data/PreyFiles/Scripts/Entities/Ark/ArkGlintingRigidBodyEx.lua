Script.ReloadScript("Scripts/Entities/Physics/RigidBodyEx.lua")
ArkGlintingRigidBodyEx = {
  Properties = {
    glintconfig_GlintConfig = "16934642289625103724"
  }
}
MakeDerivedEntity(ArkGlintingRigidBodyEx, RigidBodyEx)
function ArkGlintingRigidBodyEx.Init(A0_3976, A1_3977)
  Ark.SetGlintConfig(A0_3976.id, A0_3976.Properties.glintconfig_GlintConfig)
  if A1_3977 then
    Ark.SetShouldGlint(A0_3976.id, true)
  end
end
function ArkGlintingRigidBodyEx.GetUsable(A0_3978)
  if A0_3978:GetPhysicalStats().mass > 0 and A0_3978.Properties.bIsCarryable == 1 then
    ({}).Use, ({}).ActionType = {}, "Carry"
  end
  return {}
end
function ArkGlintingRigidBodyEx.OnStartGame(A0_3979)
  if System.IsEditor() then
    A0_3979:Init(true)
  end
end
function ArkGlintingRigidBodyEx.OnStartLevel(A0_3980)
  if not System.IsEditor() then
    A0_3980:Init(true)
  end
end
function ArkGlintingRigidBodyEx.OnDestroy(A0_3981)
  Ark.SetShouldGlint(A0_3981.id, false)
end
function ArkGlintingRigidBodyEx.OnReset(A0_3982)
  RigidBodyEx.OnReset(A0_3982)
  Ark.SetShouldGlint(A0_3982.id, false)
end
function ArkGlintingRigidBodyEx.OnPostLoad(A0_3983)
  Ark.SetShouldGlint(A0_3983.id, true)
end
ArkGlintingRigidBodyEx.Server.Default.OnStartLevel = ArkGlintingRigidBodyEx.OnStartLevel
ArkGlintingRigidBodyEx.Server.Default.OnStartGame = ArkGlintingRigidBodyEx.OnStartGame
ArkGlintingRigidBodyEx.Server.Activated.OnStartLevel = ArkGlintingRigidBodyEx.OnStartLevel
ArkGlintingRigidBodyEx.Server.Activated.OnStartGame = ArkGlintingRigidBodyEx.OnStartGame
