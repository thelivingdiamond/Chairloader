Script.ReloadScript("SCRIPTS/Entities/AI/Shared/AIBase.lua")
ArkPhantomVoltaic_x = {
  Properties = {useSpecialMovementTransitions = 1, specialMovementTransitionsLibOverride = "ArkBeta"},
  AIMovementAbility = {
    walkSpeed = 2,
    runSpeed = 2.5,
    sprintSpeed = 2.5,
    maneuverSpeed = 2,
    maxAccel = 2.6,
    maxDecel = 1.13,
    directionalScaleRefSpeedMin = 1.13,
    directionalScaleRefSpeedMax = 2.6,
    directionalScaleTurn = 0.5,
    directionalScaleStrafe = 0.5,
    directionalScaleSlope = 0.083333,
    AIMovementSpeeds = {
      Relaxed = {
        Slow = {
          2,
          0,
          2
        },
        Walk = {
          2,
          0,
          2
        },
        Run = {
          2,
          0,
          2
        },
        Sprint = {
          2,
          0,
          2
        }
      },
      Alerted = {
        Slow = {
          2.5,
          0,
          2.5
        },
        Walk = {
          2.5,
          0,
          2.5
        },
        Run = {
          2.5,
          0,
          2.5
        },
        Sprint = {
          2.5,
          0,
          2.5
        }
      },
      Combat = {
        Slow = {
          2.5,
          0,
          2.5
        },
        Walk = {
          2.5,
          0,
          2.5
        },
        Run = {
          2.5,
          0,
          2.5
        },
        Sprint = {
          2.5,
          0,
          2.5
        }
      }
    }
  }
}
mergef(ArkPhantomVoltaic_x, AIBase, 1)
function ArkPhantomVoltaic_x.IsInvulnerable(A0_1967)
  local L1_1968
  L1_1968 = A0_1967.PropertiesInstance
  L1_1968 = L1_1968.bIsInvulnerable
  L1_1968 = L1_1968 == true
  return L1_1968
end
function ArkPhantomVoltaic_x.OnDeathCustom(A0_1969, A1_1970)
  if A0_1969.UpdateDisplayName then
    A0_1969:UpdateDisplayName()
  end
  ArkNpc.OnDeathCustom(A0_1969, A1_1970)
end
function ArkPhantomVoltaic_x.OnLureSignal(A0_1971, A1_1972, A2_1973, A3_1974)
  A0_1971.arknpc:OnLured(A1_1972)
end
function ArkPhantomVoltaic_x.OnSpawn(A0_1975, A1_1976)
  BasicActor.OnSpawn(A0_1975, A1_1976)
  A0_1975:Activate(1)
end
function ArkPhantomVoltaic_x.OnUpdate(A0_1977, A1_1978)
end
function ArkPhantomVoltaic_x.Server.OnStartGame(A0_1979)
  if not A0_1979.arknpc:IsDead() then
    A0_1979.arknpc:AttachGameEffect(4)
    A0_1979.arknpc:AttachGameEffect(6)
  end
end
function ArkPhantomVoltaic_x.OnNpcKilled(A0_1980)
  A0_1980.arknpc:DetachGameEffect(4)
  A0_1980.arknpc:DetachGameEffect(6)
  A0_1980:SetupInventoryOnDeath()
  A0_1980.Properties.loottables_HumanLootTable:gsub("([^,]+)", function(A0_1981)
    local L2_1982
    L2_1982 = _UPVALUE0_
    L2_1982[#_UPVALUE0_ + 1] = A0_1981
  end)
  if #{} > 0 then
    Ark.SpawnLootFromTable(({})[math.random(#{})], A0_1980.id)
  end
end
