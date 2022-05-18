local L0_9523, L1_9524
L0_9523 = {}
L1_9524 = {}
L1_9524.x = 0
L1_9524.y = 0
L1_9524.z = 0
L0_9523.tempVec = L1_9524
L1_9524 = {}
L0_9523.Client = L1_9524
L1_9524 = {}
L0_9523.Server = L1_9524
L1_9524 = {}
L0_9523.spawns = L1_9524
SinglePlayer = L0_9523
L0_9523 = {}
usableEntityList = L0_9523
L0_9523 = g_dmgMult
if not L0_9523 then
  L0_9523 = 1
  g_dmgMult = L0_9523
end
L0_9523 = SinglePlayer
function L1_9524(A0_9525, A1_9526)
  AIReset()
end
L0_9523.OnReset = L1_9524
L0_9523 = SinglePlayer
function L1_9524(A0_9527, A1_9528)
  if A0_9527.game:IsDemoMode() ~= 0 then
    return
  end
  if A1_9528.inventory then
    A1_9528.inventory:Destroy()
  end
  if A1_9528.actor and A1_9528.actor:IsPlayer() then
    ItemSystem.GiveItemPack(A1_9528.id, "empty", false, true)
  end
end
L0_9523.EquipActor = L1_9524
L0_9523 = SinglePlayer
function L1_9524(A0_9529, A1_9530)
  if A1_9530 and A1_9530.OnShoot and not A1_9530:OnShoot() then
    return false
  end
  return true
end
L0_9523.OnShoot = L1_9524
L0_9523 = SinglePlayer
function L1_9524(A0_9531, A1_9532, A2_9533)
  local L3_9534, L4_9535
  if not A2_9533 then
    L3_9534 = 0
    return L3_9534
  end
  L3_9534 = System
  L3_9534 = L3_9534.GetEntity
  L4_9535 = A2_9533
  L3_9534 = L3_9534(L4_9535)
  L4_9535 = L3_9534.IsUsable
  if L4_9535 then
    L4_9535 = L3_9534.IsHidden
    L4_9535 = L4_9535(L3_9534)
    if L4_9535 then
      L4_9535 = 0
      return L4_9535
    end
    L4_9535 = System
    L4_9535 = L4_9535.GetEntity
    L4_9535 = L4_9535(A1_9532)
    if L4_9535 and L4_9535.actor and (L4_9535:IsDead() or L4_9535.actor:GetSpectatorMode() ~= 0) then
      return 0
    end
    return L3_9534:IsUsable(L4_9535)
  end
  L4_9535 = 0
  return L4_9535
end
L0_9523.IsUsable = L1_9524
L0_9523 = SinglePlayer
function L1_9524(A0_9536, A1_9537, A2_9538)
  if A2_9538 then
    for _FORV_7_, _FORV_8_ in ipairs(A2_9538) do
      if g_localActor.arkPlayer:IsMimickingObject() then
        usableEntityList[_FORV_7_] = 0
      elseif ArkPlayerItemAction.IsArkItem(_FORV_8_.id) then
        if ArkPlayerItemAction.CanUseItem(_FORV_8_.id) then
          usableEntityList[_FORV_7_] = 1
        else
          usableEntityList[_FORV_7_] = 0
        end
      elseif ArkPlayerEntityInteractionRules.CanPerformUseTest(_FORV_8_.id) then
        if ArkPlayerEntityInteractionRules.CanUseEntity(_FORV_8_.id) then
          usableEntityList[_FORV_7_] = _FORV_8_:IsUsable(A1_9537)
        else
          usableEntityList[_FORV_7_] = 0
        end
      else
        usableEntityList[_FORV_7_] = _FORV_8_:IsUsable(A1_9537)
      end
    end
  end
  return usableEntityList
end
L0_9523.AreUsable = L1_9524
L0_9523 = SinglePlayer
function L1_9524(A0_9539, A1_9540, A2_9541, A3_9542)
  if not A1_9540 then
    return
  end
  if A2_9541 and not System.GetEntity(A2_9541) then
    A2_9541 = nil
  end
  if System.GetEntity(A1_9540) and System.GetEntity(A1_9540).SetOnUseData then
    System.GetEntity(A1_9540):SetOnUseData(A2_9541 or NULL_ENTITY, A3_9542)
  end
  if A1_9540 ~= g_localActorId then
    return
  end
  if A0_9539.UsableMessage then
    HUD.SetInstructionObsolete(A0_9539.UsableMessage)
    A0_9539.UsableMessage = nil
  end
end
L0_9523.OnNewUsable = L1_9524
L0_9523 = SinglePlayer
function L1_9524(A0_9543, A1_9544, A2_9545, A3_9546, A4_9547)
  local L5_9548
  L5_9548 = g_localActorId
  if A1_9544 ~= L5_9548 then
    return
  end
  L5_9548 = ""
  if A2_9545 then
    obj = System.GetEntity(A2_9545)
    if obj then
      if obj.GetUsableMessage then
        L5_9548 = obj:GetUsableMessage(A4_9547)
      elseif obj:GetState() ~= "" and obj[obj:GetState()].GetUsableMessage then
        L5_9548 = obj[obj:GetState()].GetUsableMessage(obj, A4_9547)
      end
    end
  end
  if UIAction then
    UIAction.StartAction("DisplayUseText", {L5_9548})
  end
end
L0_9523.OnUsableMessage = L1_9524
L0_9523 = SinglePlayer
function L1_9524(A0_9549, A1_9550, A2_9551)
end
L0_9523.OnLongHover = L1_9524
L0_9523 = SinglePlayer
function L1_9524(A0_9552, A1_9553)
  if not System.IsEditor() then
    if not A1_9553.nextlevel then
      Game.PauseGame(true)
      Game.ShowMainMenu()
    end
    g_GameTokenPreviousLevel = GameToken.GetToken("Game.Global.Previous_Level")
  end
end
L0_9523.EndLevel = L1_9524
L0_9523 = SinglePlayer
function L1_9524(A0_9554, A1_9555, A2_9556, A3_9557, A4_9558, A5_9559, A6_9560, A7_9561, A8_9562, A9_9563, A10_9564, A11_9565, A12_9566, A13_9567, A14_9568, A15_9569, A16_9570)
  local L17_9571, L18_9572
  if not A5_9559 then
    L17_9571 = g_Vectors
    A5_9559 = L17_9571.up
  end
  A6_9560 = A6_9560 or 5.5
  A12_9566 = A12_9566 or A6_9560 / 2
  A14_9568 = A14_9568 or A6_9560
  A13_9567 = A13_9567 or A14_9568 / 2
  A7_9561 = A7_9561 or 0
  A8_9562 = A8_9562 or 200
  if A9_9563 == nil then
    L17_9571 = math
    L17_9571 = L17_9571.min
    L18_9572 = A6_9560
    L17_9571 = L17_9571(L18_9572, 5)
    A9_9563 = L17_9571
  end
  if A6_9560 == 0 then
    return
  end
  L17_9571 = NULL_ENTITY
  if A1_9555 ~= 0 and A1_9555 ~= nil then
    L17_9571 = A1_9555
  end
  L18_9572 = NULL_ENTITY
  if A2_9556 ~= 0 and A2_9556 ~= nil then
    L18_9572 = A2_9556
  end
  A0_9554.game:ServerExplosion(L17_9571, L18_9572, A3_9557, A4_9558, A5_9559, A6_9560, A7_9561, A8_9562, A9_9563, A10_9564, A11_9565, A15_9569, A12_9566, A13_9567, A14_9568, A16_9570)
end
L0_9523.CreateExplosion = L1_9524
L0_9523 = SinglePlayer
function L1_9524(A0_9573, A1_9574, A2_9575, A3_9576, A4_9577, A5_9578, A6_9579, A7_9580, A8_9581, A9_9582, A10_9583, A11_9584)
  local L12_9585, L13_9586
  A5_9578 = A5_9578 or 0
  L12_9585 = 0
  if A6_9579 then
    L13_9586 = A0_9573.game
    L13_9586 = L13_9586.GetHitMaterialId
    L13_9586 = L13_9586(L13_9586, A6_9579)
    L12_9585 = L13_9586
  end
  A7_9580 = A7_9580 or -1
  L13_9586 = 0
  if A8_9581 then
    L13_9586 = A0_9573.game:GetHitTypeId(A8_9581)
  else
    L13_9586 = A0_9573.game:GetHitTypeId("normal")
  end
  A0_9573.game:ServerHit(A1_9574, A2_9575, A3_9576, A4_9577, A5_9578, L12_9585, A7_9580, L13_9586, A9_9582, A10_9583, A11_9584)
end
L0_9523.CreateHit = L1_9524
L0_9523 = SinglePlayer
function L1_9524(A0_9587, A1_9588, A2_9589, A3_9590, A4_9591, A5_9592, A6_9593, A7_9594, A8_9595, A9_9596)
  local L10_9597, L11_9598
  L10_9597 = g_localActor
  if L10_9597 then
    L10_9597 = g_localActor
    L10_9597 = L10_9597.actor
    if L10_9597 then
      if A2_9589 then
        L11_9598 = A0_9587
        L10_9597 = A0_9587.ViewShake
        L10_9597(L11_9598, g_localActor, A2_9589, A3_9590, A4_9591, A5_9592, A6_9593, A7_9594, A8_9595, A9_9596)
        return
      end
      if A1_9588 then
        L10_9597 = A0_9587.tempVec
        L11_9598 = CopyVector
        L11_9598(L10_9597, A1_9588)
        L11_9598 = FastDifferenceVectors
        L11_9598(L10_9597, L10_9597, g_localActor:GetWorldPos())
        L11_9598 = LengthVector
        L11_9598 = L11_9598(L10_9597)
        A0_9587:ViewShake(g_localActor, L11_9598, A3_9590, A4_9591, A5_9592, A6_9593, A7_9594, A8_9595, A9_9596)
        return
      end
    end
  end
end
L0_9523.ClientViewShake = L1_9524
L0_9523 = SinglePlayer
function L1_9524(A0_9599, A1_9600, A2_9601, A3_9602, A4_9603, A5_9604, A6_9605, A7_9606, A8_9607, A9_9608)
  local L10_9609
  L10_9609 = A4_9603 - A2_9601
  A9_9608 = A9_9608 or 0
  if L10_9609 > 0 then
    A1_9600.actor:SetViewShake({
      x = 2 * g_Deg2Rad * (A5_9604 * math.min(1, L10_9609 / (A4_9603 - A3_9602))),
      y = 2 * g_Deg2Rad * (A5_9604 * math.min(1, L10_9609 / (A4_9603 - A3_9602))),
      z = 2 * g_Deg2Rad * (A5_9604 * math.min(1, L10_9609 / (A4_9603 - A3_9602)))
    }, {
      x = 0.02 * (A5_9604 * math.min(1, L10_9609 / (A4_9603 - A3_9602))),
      y = 0.02 * (A5_9604 * math.min(1, L10_9609 / (A4_9603 - A3_9602))),
      z = 0.02 * (A5_9604 * math.min(1, L10_9609 / (A4_9603 - A3_9602)))
    }, A6_9605 * 0.5 + A6_9605 * 0.5 * math.min(1, L10_9609 / (A4_9603 - A3_9602)), 0.05, A9_9608)
  end
end
L0_9523.ViewShake = L1_9524
L0_9523 = SinglePlayer
function L1_9524(A0_9610)
  local L1_9611
end
L0_9523.OnSpawn = L1_9524
L0_9523 = SinglePlayer
L0_9523 = L0_9523.Server
function L1_9524(A0_9612)
  local L1_9613
  L1_9613 = {}
  A0_9612.fallHit = L1_9613
  L1_9613 = {}
  A0_9612.explosionHit = L1_9613
  L1_9613 = {}
  A0_9612.collisionHit = L1_9613
end
L0_9523.OnInit = L1_9524
L0_9523 = SinglePlayer
L0_9523 = L0_9523.Client
function L1_9524(A0_9614)
  local L1_9615
end
L0_9523.OnInit = L1_9524
L0_9523 = SinglePlayer
L0_9523 = L0_9523.Server
function L1_9524(A0_9616, A1_9617)
  local L2_9618, L3_9619
  L2_9618 = {}
  L2_9618.name = "Dude"
  L2_9618.class = "ArkPlayer"
  L3_9619 = {}
  L3_9619.x = 0
  L3_9619.y = 0
  L3_9619.z = 0
  L2_9618.position = L3_9619
  L3_9619 = {}
  L3_9619.x = 0
  L3_9619.y = 0
  L3_9619.z = 0
  L2_9618.rotation = L3_9619
  L3_9619 = {}
  L3_9619.x = 1
  L3_9619.y = 1
  L3_9619.z = 1
  L2_9618.scale = L3_9619
  L3_9619 = Actor
  L3_9619 = L3_9619.CreateActor
  L3_9619 = L3_9619(A1_9617, L2_9618)
  player = L3_9619
  L3_9619 = player
  if not L3_9619 then
    L3_9619 = Log
    L3_9619("OnClientConnect: Failed to spawn the player!")
    return
  end
  L3_9619 = A0_9616.game
  L3_9619 = L3_9619.GetFirstSpawnLocation
  L3_9619 = L3_9619(L3_9619, 0)
  if L3_9619 and System.GetEntity(L3_9619) then
    player:SetWorldPos(System.GetEntity(L3_9619):GetWorldPos(g_Vectors.temp_v1))
    System.GetEntity(L3_9619):GetAngles(g_Vectors.temp_v1)
    g_Vectors.temp_v1.x = 0
    g_Vectors.temp_v1.y = 0
    player.actor:PlayerSetViewAngles(g_Vectors.temp_v1)
    System.GetEntity(L3_9619):Spawned(player)
    return
  end
  System.Log("$1warning: No spawn points; using default spawn location!")
end
L0_9523.OnClientConnect = L1_9524
L0_9523 = SinglePlayer
L0_9523 = L0_9523.Server
function L1_9524(A0_9620, A1_9621, A2_9622, A3_9623)
end
L0_9523.OnClientEnteredGame = L1_9524
L0_9523 = SinglePlayer
function L1_9524(A0_9624, A1_9625, A2_9626)
  local L3_9627
  L3_9627 = 0
  return L3_9627
end
L0_9523.GetDamageAbsorption = L1_9524
L0_9523 = SinglePlayer
function L1_9524(A0_9628, A1_9629, A2_9630)
  if A0_9628:IsStealthHealthHit(A1_9629.type) then
    return true
  elseif A1_9629.type == "silentMelee" then
    return true
  end
end
L0_9523.CanHitIgnoreInvulnerable = L1_9524
L0_9523 = SinglePlayer
function L1_9524(A0_9631, A1_9632)
  local L2_9633, L3_9634, L4_9635, L5_9636, L6_9637, L7_9638, L8_9639, L9_9640, L10_9641, L11_9642, L12_9643, L13_9644, L14_9645
  L2_9633 = A1_9632.target
  L3_9634 = A1_9632.shooter
  L4_9635 = A1_9632.shooterId
  L4_9635 = L4_9635 or NULL_ENTITY
  L5_9636 = A1_9632.weapon
  L6_9637 = L2_9633.actor
  L7_9638 = L6_9637
  L6_9637 = L6_9637.GetHealth
  L6_9637 = L6_9637(L7_9638)
  L7_9638 = L2_9633.IsInvulnerable
  if L7_9638 then
    L8_9639 = L2_9633
    L7_9638 = L2_9633.IsInvulnerable
    L7_9638 = L7_9638(L8_9639)
    if L7_9638 then
      L8_9639 = A0_9631
      L7_9638 = A0_9631.CanHitIgnoreInvulnerable
      L9_9640 = A1_9632
      L10_9641 = L2_9633
      L7_9638 = L7_9638(L8_9639, L9_9640, L10_9641)
      if not L7_9638 then
        L7_9638 = L6_9637 <= 0
        return L7_9638
      end
    end
  end
  L7_9638 = A0_9631.game
  L8_9639 = L7_9638
  L7_9638 = L7_9638.IsMultiplayer
  L7_9638 = L7_9638(L8_9639)
  L8_9639 = g_dmgMult
  L9_9640 = A1_9632.damage
  L8_9639 = L8_9639 * L9_9640
  L9_9640 = L3_9634 and L3_9634.actor
  L10_9641 = L2_9633 and L2_9633.actor
  if not L7_9638 then
    L11_9642 = not L9_9640 and L3_9634 and L3_9634.actor
    L12_9643 = not L10_9641 and L2_9633 and L2_9633.actor
    L13_9644 = 1
    if L10_9641 then
      L13_9644 = g_dmgMult
    end
    if L3_9634 then
      L14_9645 = L3_9634.actor
      if L14_9645 and L12_9643 then
        L14_9645 = AI
        L14_9645 = L14_9645.SetAlarmed
        L14_9645(L2_9633.id)
      end
    end
    L14_9645 = AI
    if L14_9645 then
      if L11_9642 and not L12_9643 then
        L14_9645 = AI
        L14_9645 = L14_9645.ProcessBalancedDamage
        L14_9645 = L14_9645(L4_9635, L2_9633.id, L13_9644 * A1_9632.damage, A1_9632.type)
        L8_9639 = L14_9645
        L14_9645 = A0_9631.GetDamageAbsorption
        L14_9645 = L14_9645(A0_9631, L2_9633, A1_9632)
        L14_9645 = 1 - L14_9645
        L8_9639 = L8_9639 * L14_9645
      elseif L11_9642 and L12_9643 then
        L14_9645 = AI
        L14_9645 = L14_9645.ProcessBalancedDamage
        L14_9645 = L14_9645(L4_9635, L2_9633.id, L13_9644 * A1_9632.damage, A1_9632.type)
        L8_9639 = L14_9645
        L14_9645 = A0_9631.GetDamageAbsorption
        L14_9645 = L14_9645(A0_9631, L2_9633, A1_9632)
        L14_9645 = 1 - L14_9645
        L8_9639 = L8_9639 * L14_9645
      else
        L14_9645 = A1_9632.damage
        L14_9645 = L13_9644 * L14_9645
        L8_9639 = L14_9645 * (1 - A0_9631:GetDamageAbsorption(L2_9633, A1_9632))
      end
    else
      L14_9645 = A1_9632.damage
      L14_9645 = L13_9644 * L14_9645
      L8_9639 = L14_9645 * (1 - A0_9631:GetDamageAbsorption(L2_9633, A1_9632))
    end
  end
  if L10_9641 then
    L11_9642 = A1_9632.damage
    if L11_9642 > 0 then
      L11_9642 = A1_9632.type
      if L11_9642 == "collision" then
        L11_9642 = A1_9632.velocity
        if L11_9642 then
          L11_9642 = A1_9632.velocity
          if L11_9642 > 0.5 then
            L8_9639 = 0
          end
        end
      end
    end
  end
  L11_9642 = L6_9637 - L8_9639
  if not L7_9638 then
    L12_9643 = A1_9632.type
    L12_9643 = L12_9643 ~= "fall" and L12_9643 ~= "punish" and L12_9643 ~= "vehicleDestruction"
  if L10_9641 and L12_9643 then
    L13_9644 = L2_9633.actor
    L14_9645 = L13_9644
    L13_9644 = L13_9644.GetLowHealthThreshold
    L13_9644 = L13_9644(L14_9645)
    if not (L6_9637 > L13_9644) or L11_9642 <= 0 then
    end
  end
  L13_9644 = A1_9632.type
  if L13_9644 ~= "event" then
    L13_9644 = L2_9633.GetForcedMinHealthThreshold
    if L13_9644 then
      L14_9645 = L2_9633
      L13_9644 = L2_9633.GetForcedMinHealthThreshold
      L13_9644 = L13_9644(L14_9645)
      if L11_9642 < L13_9644 then
        L11_9642 = L13_9644
      end
    end
  end
  L6_9637 = L11_9642
  if not L7_9638 then
    L13_9644 = L2_9633.id
    L14_9645 = g_localActorId
    if L13_9644 == L14_9645 and L6_9637 <= 0 then
      L13_9644 = A0_9631.game
      L14_9645 = L13_9644
      L13_9644 = L13_9644.DemiGodDeath
      L13_9644(L14_9645)
      L13_9644 = L2_9633.actor
      L14_9645 = L13_9644
      L13_9644 = L13_9644.IsGod
      L13_9644 = L13_9644(L14_9645)
      if L13_9644 and L13_9644 > 0 then
        L14_9645 = L2_9633.actor
        L14_9645 = L14_9645.SetHealth
        L14_9645(L14_9645, 0)
        L14_9645 = L2_9633.Properties
        L14_9645 = L14_9645.Damage
        L6_9637 = L14_9645.health
      end
    end
  end
  L13_9644 = L2_9633.actor
  L14_9645 = L13_9644
  L13_9644 = L13_9644.SetHealth
  L13_9644(L14_9645, L6_9637)
  L13_9644 = L2_9633.actor
  L14_9645 = L13_9644
  L13_9644 = L13_9644.GetHealth
  L13_9644 = L13_9644(L14_9645)
  L6_9637 = L13_9644
  if L5_9636 then
    L13_9644 = L5_9636.id
  else
    L13_9644 = L13_9644 or NULL_ENTITY
  end
  L14_9645 = A1_9632.projectileId
  L14_9645 = L14_9645 or NULL_ENTITY
  L2_9633.actor:DamageInfo(L4_9635, L2_9633.id, L13_9644, L14_9645, L8_9639, A1_9632.typeId, A1_9632.dir)
  if not L7_9638 and AI then
    if A1_9632.material_type then
      AI.DebugReportHitDamage(L2_9633.id, L4_9635, L8_9639, A1_9632.material_type)
    else
      AI.DebugReportHitDamage(L2_9633.id, L4_9635, L8_9639, "")
    end
  end
  return L6_9637 <= 0
end
L0_9523.ProcessActorDamage = L1_9524
L0_9523 = SinglePlayer
L0_9523 = L0_9523.Server
function L1_9524(A0_9646)
  CryAction.SendGameplayEvent(NULL_ENTITY, eGE_GameStarted)
  if g_GameTokenPreviousLevel then
    GameToken.SetToken("Game.Global.Previous_Level", g_GameTokenPreviousLevel)
    g_GameTokenPreviousLevel = nil
  end
end
L0_9523.OnStartLevel = L1_9524
L0_9523 = SinglePlayer
L0_9523 = L0_9523.Client
function L1_9524(A0_9647)
  local L1_9648
end
L0_9523.OnStartLevel = L1_9524
L0_9523 = SinglePlayer
L0_9523 = L0_9523.Client
function L1_9524(A0_9649, A1_9650)
  local L2_9651
  L2_9651 = A1_9650.target
  if L2_9651 and not A1_9650.backface and L2_9651.Client and L2_9651.Client.OnHit then
    L2_9651.Client.OnHit(L2_9651, A1_9650)
  end
end
L0_9523.OnHit = L1_9524
L0_9523 = SinglePlayer
function L1_9524(A0_9652)
  local L1_9653
end
L0_9523.PrecacheLevel = L1_9524
L0_9523 = SinglePlayer
function L1_9524(A0_9654, A1_9655)
  local L2_9656
  L2_9656 = A1_9655 == "stealthKill" or A1_9655 == "stealthKill_Maximum"
  return L2_9656
end
L0_9523.IsStealthHealthHit = L1_9524
