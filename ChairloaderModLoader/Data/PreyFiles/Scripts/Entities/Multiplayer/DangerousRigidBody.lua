Script.ReloadScript("Scripts/Entities/Physics/RigidBodyEx.lua")
DangerousRigidBody = {
  Properties = {
    bCurrentlyDealingDamage = 0,
    bDoesFriendlyFireDamage = 0,
    fDamageToDeal = 10000,
    fTimeBetweenHits = 0.5
  }
}
MakeDerivedEntity(DangerousRigidBody, RigidBodyEx)
function DangerousRigidBody.Event_MakeDangerous(A0_6342, A1_6343, A2_6344)
  Game.SetDangerousRigidBodyDangerStatus(A0_6342.id, true, A2_6344.id)
  A0_6342:ActivateOutput("IsDangerous", true)
end
function DangerousRigidBody.Event_MakeNotDangerous(A0_6345)
  Game.SetDangerousRigidBodyDangerStatus(A0_6345.id, false, 0)
  A0_6345:ActivateOutput("IsDangerous", false)
end
DangerousRigidBody.FlowEvents = {
  Inputs = {
    MakeDangerous = {
      DangerousRigidBody.Event_MakeDangerous,
      "entity"
    },
    MakeNotDangerous = {
      DangerousRigidBody.Event_MakeNotDangerous,
      "any"
    }
  },
  Outputs = {IsDangerous = "bool"}
}
mergef(DangerousRigidBody.FlowEvents, RigidBodyEx.FlowEvents, 1)
