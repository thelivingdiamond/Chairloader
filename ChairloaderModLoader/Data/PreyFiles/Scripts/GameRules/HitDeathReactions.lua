local L0_9488, L1_9489
L0_9488 = {}
HitDeathReactions = L0_9488
L0_9488 = HitDeathReactions
function L1_9489(A0_9490, A1_9491)
  return CryAction.LoadXML("Scripts/GameRules/HitDeathReactions_Defs.xml", A1_9491)
end
L0_9488.LoadXMLData = L1_9489
L0_9488 = HitDeathReactions
function L1_9489(A0_9492, A1_9493)
  A0_9492.entity:IgnoreNextDeathImpulse()
  A0_9492.binds:ExecuteDeathReaction(A1_9493)
end
L0_9488.DefaultKillReaction = L1_9489
L0_9488 = HitDeathReactions
function L1_9489(A0_9494, A1_9495)
  A0_9494.binds:ExecuteHitReaction(A1_9495)
end
L0_9488.DefaultHitReaction = L1_9489
L0_9488 = HitDeathReactions
function L1_9489(A0_9496, A1_9497, A2_9498, A3_9499)
  return (A0_9496.binds:IsValidReaction(A1_9497, A2_9498, A3_9499))
end
L0_9488.DefaultValidation = L1_9489
L0_9488 = HitDeathReactions
function L1_9489(A0_9500, A1_9501)
  A0_9500.entity:IgnoreNextDeathImpulse()
  A0_9500.binds:EndCurrentReaction()
end
L0_9488.ReactionDontApplyDeathImpulse = L1_9489
L0_9488 = HitDeathReactions
function L1_9489(A0_9502, A1_9503, A2_9504)
  return A2_9504.knocksDownLeg and A0_9502.binds:IsValidReaction(A1_9503, A2_9504)
end
L0_9488.FallAndPlay_Validation = L1_9489
L0_9488 = HitDeathReactions
function L1_9489(A0_9505)
  A0_9505.binds:EndCurrentReaction()
  BasicActor.ApplyDeathImpulse(A0_9505.entity, A0_9505.entity.hitDeathReactionsParams.HitDeathReactionsConfig and A0_9505.entity.hitDeathReactionsParams.HitDeathReactionsConfig.maxRagdolImpulse or -1)
end
L0_9488.DeathImpulse = L1_9489
L0_9488 = HitDeathReactions
function L1_9489(A0_9506, A1_9507)
  A0_9506.binds:ExecuteHitReaction(A1_9507)
  Script.SetTimer(500, function()
    _UPVALUE0_.entity:LeaveCover()
    AI.SetStance(_UPVALUE0_.entity.id, STANCE_STAND)
  end)
end
L0_9488.BackHitInCover_Reaction = L1_9489
L0_9488 = HitDeathReactions
function L1_9489(A0_9508, A1_9509, A2_9510)
  return (A0_9508.binds:IsValidReaction(A1_9509, A2_9510))
end
L0_9488.TestValidation = L1_9489
L0_9488 = HitDeathReactions
function L1_9489(A0_9511, A1_9512, A2_9513)
  local L3_9514, L4_9515
  L3_9514 = A0_9511.entity
  L3_9514 = L3_9514.lastHitEvent
  if L3_9514 ~= nil then
    L3_9514 = A0_9511.binds
    L4_9515 = L3_9514
    L3_9514 = L3_9514.IsValidReaction
    L3_9514 = L3_9514(L4_9515, A1_9512, A2_9513)
    L4_9515 = A0_9511.entity
    L4_9515 = L4_9515.lastHitEvent
    L4_9515 = L4_9515 == A1_9512.destructibleEvent
    return L3_9514 and L4_9515
  else
    L3_9514 = false
    return L3_9514
  end
end
L0_9488.Destructible_Validation = L1_9489
L0_9488 = HitDeathReactions
function L1_9489(A0_9516, A1_9517)
  A0_9516.entity:IgnoreNextDeathImpulse()
  if not A0_9516.binds:StartReactionAnim("deathReact_spiral_all_3p_01", true, 0.1) then
    Script.SetTimer(700, BasicActor.TurnRagdoll, A0_9516.entity, 1)
  end
end
L0_9488.TestKillReaction = L1_9489
L0_9488 = HitDeathReactions
function L1_9489(A0_9518, A1_9519)
  A0_9518.binds:ExecuteDeathReaction(A1_9519)
  if not A0_9518.binds:StartInteractiveAction(A1_9519.interactiveAction, 1000) then
    Script.SetTimer(3900, A0_9518.binds.EndCurrentReaction, A0_9518.binds)
  end
end
L0_9488.PlayerDeathTest = L1_9489
