Script.ReloadScript("Scripts/Entities/Ark/Pickups/ArkConsumable.lua")
ArkOxygenBottle = {
  Properties = {
    AppliedOnConsume = {nOxygenRestored = 500}
  }
}
ArkMakeDerivedEntityOverride(ArkOxygenBottle, ArkConsumable, true)
function ArkOxygenBottle.Consume(A0_3216, A1_3217, A2_3218)
  A0_3216:Log("ArkOxygenBottle:Consume()")
  g_localActor.arkPlayer:GiveOxygen(A0_3216.Properties.AppliedOnConsume.nOxygenRestored)
  ArkConsumable.Consume(A0_3216, A1_3217, A2_3218)
end
