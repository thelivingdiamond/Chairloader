Script.ReloadScript("Scripts/Entities/actor/player.lua")
DamageTestEnt = new(Player)
DamageTestEnt.totalDamage = 0
DamageTestEnt.lastHitTime = 0
DamageTestEnt.firstHitTime = 0
DamageTestEnt.numHits = 0
DamageTestEnt.isActive = false
DamageTestEnt.watchText = ""
DamageTestEnt.watchTextDead = ""
DamageTestEnt.isDead = false
DamageTestEnt.Properties.fileHitDeathReactionsParamsDataFile = "Libs/HitDeathReactionsData/HitDeathReactions_MP.xml"
DamageTestEnt.Properties.Damage.fileBodyDamage = "Libs/BodyDamage/BodyDamage_MP.xml"
DamageTestEnt.Properties.Damage.fileBodyDamageParts = "Libs/BodyDamage/BodyParts_HumanMaleShared.xml"
DamageTestEnt.Properties.Damage.fileBodyDestructibility = "Libs/BodyDamage/BodyDestructibility_Default.xml"
function DamageTestEnt.Server.OnHit(A0_2920, A1_2921)
  local L2_2922, L3_2923, L4_2924, L5_2925, L6_2926, L7_2927, L8_2928, L9_2929, L10_2930, L11_2931
  L2_2922 = A1_2921.damage
  L3_2923 = A1_2921.target
  L4_2924 = L3_2923
  L3_2923 = L3_2923.GetPos
  L3_2923 = L3_2923(L4_2924)
  L4_2924 = A1_2921.shooter
  L5_2925 = L4_2924
  L4_2924 = L4_2924.GetPos
  L4_2924 = L4_2924(L5_2925)
  L5_2925 = DistanceVectors
  L6_2926 = L3_2923
  L7_2927 = L4_2924
  L5_2925 = L5_2925(L6_2926, L7_2927)
  L6_2926 = 0
  L7_2927 = 0
  L8_2928 = g_gameRules
  L8_2928 = L8_2928.game
  L9_2929 = L8_2928
  L8_2928 = L8_2928.GetServerTime
  L8_2928 = L8_2928(L9_2929)
  L9_2929 = A0_2920.isActive
  if L9_2929 == false then
    A0_2920.totalDamage = L2_2922
    A0_2920.firstHitTime = L8_2928
    A0_2920.lastHitTime = L8_2928
    A0_2920.isActive = true
    A0_2920.numHits = 1
  else
    L9_2929 = A0_2920.totalDamage
    L9_2929 = L9_2929 + L2_2922
    A0_2920.totalDamage = L9_2929
    A0_2920.lastHitTime = L8_2928
    L9_2929 = A0_2920.lastHitTime
    L10_2930 = A0_2920.firstHitTime
    L9_2929 = L9_2929 - L10_2930
    L7_2927 = L9_2929 * 0.001
    L9_2929 = A0_2920.totalDamage
    L6_2926 = L9_2929 / L7_2927
    L9_2929 = A0_2920.numHits
    L9_2929 = L9_2929 + 1
    A0_2920.numHits = L9_2929
  end
  L9_2929 = A1_2921.partId
  L10_2930 = A0_2920.actor
  L11_2931 = L10_2930
  L10_2930 = L10_2930.GetExtraHitLocationInfo
  L10_2930 = L10_2930(L11_2931, 0, A1_2921.partId)
  if L10_2930 then
    L11_2931 = L10_2930.boneName
    if L11_2931 then
      L9_2929 = L10_2930.boneName
    else
      L11_2931 = L10_2930.attachmentName
      if L11_2931 then
        L9_2929 = L10_2930.attachmentName
      end
    end
  end
  L11_2931 = nil
  if A1_2921.weapon then
    L11_2931 = A1_2921.weapon.class
  else
    L11_2931 = EntityName(A1_2921.weaponId) .. " (" .. A1_2921.type .. ")"
  end
  A0_2920.watchText = EntityName(A0_2920) .. " (" .. L9_2929 .. ") : " .. L11_2931 .. ": " .. L2_2922 .. " damage at " .. L5_2925 .. "m away, (total=" .. A0_2920.totalDamage .. ", time=" .. L7_2927 .. ", dps=" .. L6_2926 .. ", numHits=" .. A0_2920.numHits .. ")"
  Log(A0_2920.watchText)
  if A0_2920.isDead == false and A0_2920.totalDamage > 120 then
    A0_2920.watchTextDead = "Dead at time=" .. L7_2927 .. ", numHits=" .. A0_2920.numHits
    A0_2920.isDead = true
    Log(A0_2920.watchTextDead)
  end
end
function DamageTestEnt.Server.OnUpdate(A0_2932, A1_2933)
  A0_2932.actor:PostPhysicalize()
  if A0_2932.isActive == true then
    if g_gameRules.game:GetServerTime() - A0_2932.lastHitTime < 10000 then
      g_gameRules.game:Watch(A0_2932.watchText)
      if A0_2932.isDead == true then
        g_gameRules.game:Watch(A0_2932.watchTextDead)
      end
    else
      A0_2932.isActive = false
      A0_2932.isDead = false
    end
  end
end
CreateActor(DamageTestEnt)
DamageTestEnt:Expose()
