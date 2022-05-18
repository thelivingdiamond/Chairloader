Script.ReloadScript("Scripts/Entities/Others/RigidBody.lua")
DestroyedVehicle = {
  type = "DestroyedVehicle",
  Properties = {
    bUsable = 1,
    Physics = {Mass = 2000}
  },
  PropertiesInstance = {bProvideAICover = 1},
  Editor = {IsScalable = false}
}
MakeDerivedEntity(DestroyedVehicle, RigidBody)
AddHeavyObjectProperty(DestroyedVehicle)
MakeAICoverEntity(DestroyedVehicle)
SetupCollisionFiltering(DestroyedVehicle)
function DestroyedVehicle.IsUsable(A0_9127)
  local L1_9128
  L1_9128 = A0_9127.Properties
  L1_9128 = L1_9128.bUsable
  if L1_9128 ~= 0 then
    L1_9128 = 1
    return L1_9128
  end
  L1_9128 = 0
  return L1_9128
end
function DestroyedVehicle.OnReset(A0_9129)
  RigidBody.OnReset(A0_9129)
  ApplyCollisionFiltering(A0_9129, GetCollisionFiltering(A0_9129))
end
