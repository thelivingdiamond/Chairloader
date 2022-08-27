local L0_8941, L1_8942, L2_8943, L3_8944
L0_8941 = {}
L1_8942 = {}
L1_8942.fileModel = "Objects/User/jboyer/operator_test.cgf"
L1_8942.fMass = 100
L2_8943 = {}
L2_8943.health = 500
L1_8942.Damage = L2_8943
L2_8943 = {}
L3_8944 = {}
L3_8944.x = 1
L3_8944.y = 0
L3_8944.z = 0
L2_8943.clrTagDamage = L3_8944
L1_8942.Color = L2_8943
L0_8941.Properties = L1_8942
L1_8942 = {}
L1_8942.vfxDestroy = "explosions.grenade_air.explosion"
L1_8942.fDestroyEffectScale = 1
L1_8942.vfxDamage = "ArkAliens.Prototypes.DamageBlood"
L1_8942.fDamageEffectScale = 4
L0_8941.Effects = L1_8942
L1_8942 = {}
L1_8942.Icon = "animobject.bmp"
L1_8942.IconOnTop = 1
L0_8941.Editor = L1_8942
L1_8942 = {}
L0_8941.Server = L1_8942
L1_8942 = {}
L0_8941.eTarget = L1_8942
L1_8942 = {}
L1_8942.x = 0
L1_8942.y = 0
L1_8942.z = 0
L0_8941.vecDirToTarget = L1_8942
L1_8942 = {}
L1_8942.x = 0
L1_8942.y = 0
L1_8942.z = 0
L0_8941.vecStartingDir = L1_8942
L0_8941.fTagSize = 1.5
L0_8941.fTagVisibleTime = 0.88
L0_8941.fTagFadeTime = 0.33
L0_8941.fDuration = 1000
L0_8941.iUpdateRate = 33
L0_8941.iCurrentIncrement = 0
L0_8941.bVerbose = true
L0_8941.bHaveTarget = false
Ark_sshain_Operator = L0_8941
L0_8941 = Ark_sshain_Operator
function L1_8942(A0_8945, A1_8946)
  if A0_8945.bVerbose then
    System.Log(A1_8946)
  end
end
L0_8941.Log = L1_8942
L0_8941 = Ark_sshain_Operator
function L1_8942(A0_8947)
  A0_8947:SetScriptUpdateRate(A0_8947.iUpdateRate)
  A0_8947:ResetPhysics()
  A0_8947:Activate(0)
  A0_8947.bHaveTarget = false
  A0_8947.Properties.Damage.health = 500
  A0_8947:SetMaterial("Objects/User/jboyer/Operator02_Test_Mat")
  if A0_8947.Properties.fileModel ~= "" then
    A0_8947:LoadObject(0, A0_8947.Properties.fileModel)
  end
end
L0_8941.Reset = L1_8942
L0_8941 = Ark_sshain_Operator
function L1_8942(A0_8948, A1_8949)
end
L0_8941.TakeDamage = L1_8942
L0_8941 = Ark_sshain_Operator
function L1_8942(A0_8950)
  local L1_8951
end
L0_8941.Death = L1_8942
L0_8941 = Ark_sshain_Operator
function L1_8942(A0_8952)
  local L1_8953, L2_8954
  L1_8953 = A0_8952.iCurrentIncrement
  L2_8954 = A0_8952.fDuration
  if L1_8953 <= L2_8954 then
    L1_8953 = A0_8952.iCurrentIncrement
    L2_8954 = A0_8952.fDuration
    L1_8953 = L1_8953 / L2_8954
    L2_8954 = A0_8952.NLerpVectors
    L2_8954 = L2_8954(A0_8952, A0_8952.vecStartingDir, A0_8952.vecDirToTarget, L1_8953)
    A0_8952:SetDirectionVector(L2_8954)
    A0_8952.iCurrentIncrement = A0_8952.iCurrentIncrement + A0_8952.iUpdateRate
  else
    L2_8954 = A0_8952
    L1_8953 = A0_8952.Activate
    L1_8953(L2_8954, 0)
    A0_8952.iCurrentIncrement = 0
    L1_8953 = BroadcastEvent
    L2_8954 = A0_8952
    L1_8953(L2_8954, "Finished")
  end
end
L0_8941.UpdateFacingDir = L1_8942
L0_8941 = Ark_sshain_Operator
function L1_8942(A0_8955)
  local L1_8956, L2_8957, L3_8958, L4_8959, L5_8960
  L1_8956 = {}
  L2_8957 = {}
  L3_8958 = A0_8955.eTarget
  L4_8959 = L3_8958
  L3_8958 = L3_8958.GetCenterOfMassPos
  L3_8958 = L3_8958(L4_8959)
  L5_8960 = A0_8955
  L4_8959 = A0_8955.GetCenterOfMassPos
  L4_8959 = L4_8959(L5_8960)
  L5_8960 = DifferenceVectors
  L5_8960 = L5_8960(L3_8958, L4_8959)
  A0_8955.vecDirToTarget = NormalizeVector(L5_8960)
end
L0_8941.CalculateFacing = L1_8942
L0_8941 = Ark_sshain_Operator
function L1_8942(A0_8961, A1_8962, A2_8963, A3_8964)
  local L4_8965
  L4_8965 = {}
  L4_8965.x = Lerp(A1_8962.x, A2_8963.x, A3_8964)
  L4_8965.y = Lerp(A1_8962.y, A2_8963.y, A3_8964)
  L4_8965.z = Lerp(A1_8962.z, A2_8963.z, A3_8964)
  return NormalizeVector(L4_8965)
end
L0_8941.NLerpVectors = L1_8942
L0_8941 = Ark_sshain_Operator
function L1_8942(A0_8966, A1_8967)
  if not A1_8967 or A1_8967 ~= "" then
  end
end
L0_8941.PlaySound = L1_8942
L0_8941 = Ark_sshain_Operator
L0_8941 = L0_8941.Server
function L1_8942(A0_8968, A1_8969)
  if A0_8968.bHaveTarget then
    A0_8968:CalculateFacing()
    A0_8968:UpdateFacingDir()
  else
    A0_8968:Activate(0)
  end
end
L0_8941.OnUpdate = L1_8942
L0_8941 = Ark_sshain_Operator
function L1_8942(A0_8970, A1_8971)
  A0_8970:Log("Entity: OnSpawn - I'm alive!")
end
L0_8941.OnSpawn = L1_8942
L0_8941 = Ark_sshain_Operator
L0_8941 = L0_8941.Server
function L1_8942(A0_8972, A1_8973)
  A0_8972:Log("Entity: OnInit - Ready to go!")
  A0_8972:Reset()
end
L0_8941.OnInit = L1_8942
L0_8941 = Ark_sshain_Operator
function L1_8942(A0_8974)
  A0_8974:Reset()
end
L0_8941.OnPropertyChange = L1_8942
L0_8941 = Ark_sshain_Operator
function L1_8942(A0_8975, A1_8976, A2_8977)
  A0_8975:Log("Entity: OnReset - Resetting...")
  A0_8975:Reset()
end
L0_8941.OnReset = L1_8942
L0_8941 = Ark_sshain_Operator
L0_8941 = L0_8941.Server
function L1_8942(A0_8978, A1_8979)
  if A1_8979.type ~= "collision" then
    A0_8978:Log("Entity: OnHit - Ouch, " .. tostring(A1_8979.shooterId) .. " hit me with " .. A1_8979.damage .. " damage.")
    A0_8978:TakeDamage(A1_8979)
  end
end
L0_8941.OnHit = L1_8942
L0_8941 = Ark_sshain_Operator
L0_8941 = L0_8941.Server
function L1_8942(A0_8980, A1_8981)
end
L0_8941.OnCollision = L1_8942
L0_8941 = Ark_sshain_Operator
L0_8941 = L0_8941.Server
function L1_8942(A0_8982)
  local L1_8983
end
L0_8941.OnDamage = L1_8942
L0_8941 = Ark_sshain_Operator
L0_8941 = L0_8941.Server
function L1_8942(A0_8984)
  local L1_8985
end
L0_8941.OnMove = L1_8942
L0_8941 = Ark_sshain_Operator
function L1_8942(A0_8986, A1_8987)
  if A0_8986.bHaveTarget then
    A0_8986.vecStartingDir = A0_8986:GetDirectionVector()
    A0_8986.vecStartingTargetPos = A0_8986.eTarget:GetCenterOfMassPos()
    A0_8986:Activate(1)
  else
    A0_8986:Log("Warning: No facing target set!")
  end
  BroadcastEvent(A0_8986, "Started")
end
L0_8941.Event_Start = L1_8942
L0_8941 = Ark_sshain_Operator
function L1_8942(A0_8988, A1_8989)
  A0_8988:Activate(0)
  BroadcastEvent(A0_8988, "Stopped")
end
L0_8941.Event_Stop = L1_8942
L0_8941 = Ark_sshain_Operator
function L1_8942(A0_8990, A1_8991, A2_8992)
  local L3_8993
  L3_8993 = A2_8992 * 1000
  A0_8990.fDuration = L3_8993
end
L0_8941.Event_SetDuration = L1_8942
L0_8941 = Ark_sshain_Operator
function L1_8942(A0_8994, A1_8995, A2_8996)
  A0_8994.eTarget = A2_8996
  A0_8994.bHaveTarget = true
end
L0_8941.Event_EntityToFace = L1_8942
L0_8941 = Ark_sshain_Operator
L1_8942 = {}
L2_8943 = {}
L3_8944 = {
  Ark_sshain_Operator.Event_Start,
  "bool"
}
L2_8943.Start = L3_8944
L3_8944 = {
  Ark_sshain_Operator.Event_Stop,
  "bool"
}
L2_8943.Stop = L3_8944
L3_8944 = {
  Ark_sshain_Operator.Event_EntityToFace,
  "entity"
}
L2_8943.EntityToFace = L3_8944
L3_8944 = {
  Ark_sshain_Operator.Event_SetDuration,
  "float"
}
L2_8943.Duration = L3_8944
L1_8942.Inputs = L2_8943
L2_8943 = {}
L2_8943.Destroyed = "bool"
L2_8943.Damaged = "float"
L2_8943.Started = "bool"
L2_8943.Stopped = "bool"
L2_8943.Finished = "bool"
L1_8942.Outputs = L2_8943
L0_8941.FlowEvents = L1_8942
