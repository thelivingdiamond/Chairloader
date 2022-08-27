local L0_9371, L1_9372, L2_9373, L3_9374, L4_9375, L5_9376, L6_9377, L7_9378
L0_9371(L1_9372)
L0_9371(L1_9372)
VEHICLE_SCRIPT_TIMER = L0_9371
AISOUND_TIMER = L0_9371
AISOUND_TIMEOUT = L0_9371
for L3_9374, L4_9375 in L0_9371(L1_9372) do
  L5_9376 = {}
  L6_9377 = {}
  L6_9377.bDisableEngine = 0
  L6_9377.Paint = ""
  L6_9377.Modification = ""
  L6_9377.soclasses_SmartObjectClass = ""
  L6_9377.bAutoGenAIHidePts = 0
  L6_9377.teamName = ""
  L6_9377.esNavigationType = "VehicleMedium"
  L6_9377.bSyncPhysics = 1
  L5_9376.Properties = L6_9377
  L6_9377 = {}
  L6_9377.bProvideAICover = 1
  L5_9376.PropertiesInstance = L6_9377
  L6_9377 = {}
  L6_9377.Icon = "Vehicle.bmp"
  L6_9377.IconOnTop = 1
  L5_9376.Editor = L6_9377
  L6_9377 = {}
  L5_9376.Client = L6_9377
  L6_9377 = {}
  L5_9376.Server = L6_9377
  L6_9377 = AddHeavyObjectProperty
  L7_9378 = L5_9376
  L6_9377(L7_9378)
  L6_9377 = MakeAICoverEntity
  L7_9378 = L5_9376
  L6_9377(L7_9378)
  L6_9377 = SetupCollisionFiltering
  L7_9378 = L5_9376
  L6_9377(L7_9378)
  L6_9377 = Vehicle
  L6_9377 = L6_9377.GetOptionalScript
  L7_9378 = L4_9375
  L6_9377 = L6_9377(L7_9378)
  if L6_9377 then
    L7_9378 = Script
    L7_9378 = L7_9378.ReloadScript
    L7_9378(L6_9377)
    L7_9378 = _G
    L7_9378 = L7_9378[L4_9375]
    if L7_9378 then
      L7_9378 = mergef
      L7_9378(L5_9376, _G[L4_9375], 1)
    end
  end
  function L7_9378(A0_9379)
    mergef(A0_9379, VehicleBase, 1)
    A0_9379:SpawnVehicleBase()
  end
  L5_9376.OnSpawn = L7_9378
  L7_9378 = L5_9376.Server
  function L7_9378.OnShutDown(A0_9380)
    if g_gameRules then
      g_gameRules.game:RemoveSpawnGroup(A0_9380.id)
    end
  end
  function L7_9378(A0_9381)
    local L1_9382
    L1_9382 = A0_9381.ResetVehicleBase
    L1_9382(A0_9381)
    L1_9382 = CryAction
    L1_9382 = L1_9382.IsServer
    L1_9382 = L1_9382()
    if L1_9382 then
      L1_9382 = g_gameRules
      if L1_9382 then
        L1_9382 = g_gameRules
        L1_9382 = L1_9382.game
        L1_9382 = L1_9382.GetTeamId
        L1_9382 = L1_9382(L1_9382, A0_9381.Properties.teamName)
        if L1_9382 and L1_9382 ~= 0 then
          g_gameRules.game:SetTeam(L1_9382, A0_9381.id)
        else
          g_gameRules.game:SetTeam(0, A0_9381.id)
        end
      end
    end
  end
  L5_9376.OnReset = L7_9378
  function L7_9378(A0_9383, A1_9384)
    if g_gameRules and g_gameRules.OnVehicleUnlocked then
      g_gameRules.OnVehicleUnlocked(g_gameRules, A0_9383.id, A1_9384)
    end
  end
  L5_9376.OnUnlocked = L7_9378
  function L7_9378(A0_9385)
    if A0_9385.OnVehicleDestroyedAI then
      A0_9385:OnVehicleDestroyedAI()
    end
    BroadcastEvent(A0_9385, "Destroy")
  end
  L5_9376.OnVehicleDestroyed = L7_9378
  function L7_9378(A0_9386)
    local L1_9387, L2_9388
    L1_9387 = A0_9386.Properties
    if L1_9387 then
      L1_9387 = A0_9386.Properties
      L2_9388 = {}
      L2_9388.nTimer = 30
      L2_9388.bUnique = 0
      L2_9388.bRespawn = 0
      L1_9387.Respawn = L2_9388
    end
  end
  MakeRespawnable = L7_9378
  L7_9378 = L5_9376.Client
  function L7_9378.OnTimer(A0_9389, A1_9390, A2_9391)
    if A1_9390 == AISOUND_TIMER and A0_9389.AISoundRadius and A0_9389:HasDriver() then
      A0_9389:SetTimer(AISOUND_TIMER, A2_9391)
      AI.SoundEvent(A0_9389:GetWorldPos(A0_9389.State.pos), A0_9389.AISoundRadius, AISOUND_MOVEMENT_LOUD, A0_9389.id)
    end
  end
  L7_9378 = L5_9376.Server
  function L7_9378.OnEnterArea(A0_9392, A1_9393, A2_9394)
    if A0_9392.OnEnterArea then
      A0_9392.OnEnterArea(A0_9392, A1_9393, A2_9394)
    end
  end
  L7_9378 = L5_9376.Server
  function L7_9378.OnLeaveArea(A0_9395, A1_9396, A2_9397)
    if A0_9395.OnLeaveArea then
      A0_9395.OnLeaveArea(A0_9395, A1_9396, A2_9397)
    end
  end
  function L7_9378(A0_9398, A1_9399)
    A0_9398:ActivateOutput("OnPassengerEnter", A1_9399)
  end
  L5_9376.OnPassengerEnter = L7_9378
  function L7_9378(A0_9400, A1_9401)
    A0_9400:ActivateOutput("OnPassengerExit", A1_9401)
  end
  L5_9376.OnPassengerExit = L7_9378
  function L7_9378(A0_9402)
    A0_9402:Hide(0)
    BroadcastEvent(A0_9402, "Enable")
  end
  L5_9376.Event_Enable = L7_9378
  function L7_9378(A0_9403)
    A0_9403:Hide(1)
    BroadcastEvent(A0_9403, "Disable")
  end
  L5_9376.Event_Disable = L7_9378
  function L7_9378(A0_9404)
    A0_9404.vehicle:DisableEngine(0)
    BroadcastEvent(A0_9404, "EnableEngine")
  end
  L5_9376.Event_EnableEngine = L7_9378
  function L7_9378(A0_9405)
    A0_9405.vehicle:DisableEngine(1)
    BroadcastEvent(A0_9405, "DisableEngine")
  end
  L5_9376.Event_DisableEngine = L7_9378
  function L7_9378(A0_9406)
    A0_9406.vehicle:EnableMovement(1)
    BroadcastEvent(A0_9406, "EnableMovement")
  end
  L5_9376.Event_EnableMovement = L7_9378
  function L7_9378(A0_9407)
    A0_9407.vehicle:EnableMovement(0)
    BroadcastEvent(A0_9407, "DisableMovement")
  end
  L5_9376.Event_DisableMovement = L7_9378
  L7_9378 = MakeRespawnable
  L7_9378(L5_9376)
  L7_9378 = L5_9376.Properties
  L7_9378 = L7_9378.Respawn
  L7_9378.bAbandon = 1
  L7_9378 = L5_9376.Properties
  L7_9378 = L7_9378.Respawn
  L7_9378.nAbandonTimer = 90
  L7_9378 = {}
  L7_9378.Inputs = {
    Enable = {
      L5_9376.Event_Enable,
      "bool"
    },
    Disable = {
      L5_9376.Event_Disable,
      "bool"
    },
    EnableEngine = {
      L5_9376.Event_EnableEngine,
      "bool"
    },
    DisableEngine = {
      L5_9376.Event_DisableEngine,
      "bool"
    },
    EnableMovement = {
      L5_9376.Event_EnableMovement,
      "bool"
    },
    DisableMovement = {
      L5_9376.Event_DisableMovement,
      "bool"
    }
  }
  L7_9378.Outputs = {
    Enable = "bool",
    Disable = "bool",
    EnableEngine = "bool",
    DisableEngine = "bool",
    EnableMovement = "bool",
    DisableMovement = "bool",
    Destroy = "bool",
    OnPassengerEnter = "entity",
    OnPassengerExit = "entity"
  }
  if not L5_9376.FlowEvents then
    L5_9376.FlowEvents = L7_9378
  else
    mergef(L5_9376.FlowEvents, L7_9378, 1)
  end
  _G[L4_9375] = L5_9376
  if _G[L4_9375].AIProperties then
    CreateVehicleAI(_G[L4_9375])
  end
  ExposeVehicleToNetwork(_G[L4_9375])
end
