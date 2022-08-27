Script.ReloadScript("Scripts/Entities/AI/Shared/BasicAITable.lua")
Script.ReloadScript("Scripts/Entities/AI/Shared/BasicAIEvent.lua")
Script.ReloadScript("Scripts/ArkEntityUtils.lua")
BasicAI = {
  ai = 1,
  IsAIControlled = function()
    local L0_2437, L1_2438
    L0_2437 = true
    return L0_2437
  end,
  Properties = {
    signalmodifier_SignalModifier = "18446744073709551615",
    fileSignalReceiverConfig = "ark/ai/AiSignalReceiverConfigs/NpcBaseSignalReceiverConfig.xml"
  },
  Server = {},
  Client = {},
  Editor = {Icon = "User.bmp", IconOnTop = 1}
}
function BasicAI.OnPropertyChange(A0_2439)
  local L1_2440
  L1_2440 = System
  L1_2440 = L1_2440.IsEditor
  L1_2440 = L1_2440()
  A0_2439:RegisterAI(L1_2440)
  A0_2439:OnReset()
end
function BasicAI.OnLoadAI(A0_2441, A1_2442)
  local L2_2443, L3_2444, L4_2445, L5_2446, L6_2447, L7_2448, L8_2449, L9_2450, L10_2451, L11_2452, L12_2453, L13_2454, L14_2455, L15_2456
  L2_2443 = {}
  A0_2441.AI = L2_2443
  L2_2443 = A1_2442.AI
  if L2_2443 then
    L2_2443 = A1_2442.AI
    A0_2441.AI = L2_2443
  end
  L2_2443 = A1_2442.Events
  if L2_2443 then
    L2_2443 = {}
    A0_2441.Events = L2_2443
    L2_2443 = A0_2441.Events
    for L6_2447, L7_2448 in L3_2444(L4_2445) do
      L8_2449 = A1_2442.Events
      L8_2449 = L8_2449[L6_2447]
      if not L9_2450 then
        L2_2443[L6_2447] = L9_2450
      end
      for L12_2453, L13_2454 in L9_2450(L10_2451) do
        L14_2455 = L13_2454[1]
        L15_2456 = L13_2454[2]
        table.insert(L2_2443[L6_2447], {L14_2455, L15_2456})
      end
    end
  else
    A0_2441.Events = nil
  end
  L2_2443 = A1_2442.spawnedEntity
  if L2_2443 then
    L2_2443 = A1_2442.spawnedEntity
    A0_2441.spawnedEntity = L2_2443
  else
    A0_2441.spawnedEntity = nil
  end
  L2_2443 = A1_2442.lastSpawnedEntity
  if L2_2443 then
    L2_2443 = A1_2442.lastSpawnedEntity
    A0_2441.lastSpawnedEntity = L2_2443
  else
    A0_2441.lastSpawnedEntity = nil
  end
  L2_2443 = A1_2442.InitialPosition
  if L2_2443 then
    L2_2443 = A1_2442.InitialPosition
    A0_2441.InitialPosition = L2_2443
  else
    A0_2441.InitialPosition = nil
  end
  L2_2443 = A0_2441.OnLoadCustom
  if L2_2443 then
    L2_2443 = A0_2441.OnLoadCustom
    L2_2443(L3_2444, L4_2445)
  end
end
function BasicAI.OnSaveAI(A0_2457, A1_2458)
  local L2_2459, L3_2460, L4_2461, L5_2462, L6_2463, L7_2464, L8_2465, L9_2466, L10_2467, L11_2468, L12_2469, L13_2470, L14_2471
  L2_2459 = A0_2457.Events
  if L2_2459 then
    L2_2459 = {}
    A1_2458.Events = L2_2459
    L2_2459 = A1_2458.Events
    for L6_2463, L7_2464 in L3_2460(L4_2461) do
      if not L8_2465 then
        L2_2459[L6_2463] = L8_2465
      end
      for L11_2468, L12_2469 in L8_2465(L9_2466) do
        L13_2470 = L12_2469[1]
        L14_2471 = L12_2469[2]
        table.insert(L2_2459[L6_2463], {L13_2470, L14_2471})
      end
    end
  end
  L2_2459 = A0_2457.spawnedEntity
  if L2_2459 then
    L2_2459 = A0_2457.spawnedEntity
    A1_2458.spawnedEntity = L2_2459
  end
  L2_2459 = A0_2457.lastSpawnedEntity
  if L2_2459 then
    L2_2459 = A0_2457.lastSpawnedEntity
    A1_2458.lastSpawnedEntity = L2_2459
  end
  L2_2459 = A0_2457.InitialPosition
  if L2_2459 then
    L2_2459 = A0_2457.InitialPosition
    A1_2458.InitialPosition = L2_2459
  end
  L2_2459 = A0_2457.OnSaveCustom
  if L2_2459 then
    L2_2459 = A0_2457.OnSaveCustom
    L2_2459(L3_2460, L4_2461)
  end
end
function BasicAI.RegisterAI(A0_2472, A1_2473)
  if (not A1_2473 or A1_2473 == false) and CryAction.HasAI(A0_2472.id) then
    return
  end
  if A0_2472 ~= g_localActor then
    if A0_2472.AIType == nil then
      CryAction.RegisterWithAI(A0_2472.id, AIOBJECT_ACTOR, A0_2472.Properties, A0_2472.PropertiesInstance, A0_2472.AIMovementAbility, A0_2472.melee)
    else
      CryAction.RegisterWithAI(A0_2472.id, A0_2472.AIType, A0_2472.Properties, A0_2472.PropertiesInstance, A0_2472.AIMovementAbility, A0_2472.melee)
    end
    A0_2472._enabled = true
    if A0_2472:IsHidden() then
      AI.LogEvent(A0_2472:GetName() .. ": The entity is hidden during init -> disable AI.")
      A0_2472:TriggerEvent(AIEVENT_DISABLE)
      A0_2472._enabled = false
    end
  end
end
function BasicAI.ResetAIParameters(A0_2474, A1_2475, A2_2476)
  if not A1_2475 or A2_2476 then
    AI.ResetParameters(A0_2474.id, A2_2476, A0_2474.Properties, A0_2474.PropertiesInstance, A0_2474.AIMovementAbility, A0_2474.melee)
    A0_2474._enabled = true
    if A0_2474:IsHidden() then
      AI.LogEvent(A0_2474:GetName() .. ": The entity is hidden during init -> disable AI.")
      A0_2474:TriggerEvent(AIEVENT_DISABLE)
      A0_2474._enabled = false
    end
  end
end
function BasicAI.OnReset(A0_2477, A1_2478, A2_2479)
  if A0_2477.OnPreReset ~= nil then
    A0_2477:OnPreReset(A1_2478, A2_2479)
  end
  if A0_2477.ResetOnUsed then
    A0_2477:ResetOnUsed()
  end
  A0_2477:NetPresent(1)
  A0_2477.UpdateTime = 0.05
  A0_2477:SetScriptUpdateRate(A0_2477.UpdateTime)
  A0_2477.useAction = AIUSEOP_NONE
  A0_2477.groupid = A0_2477.PropertiesInstance.groupid
  BasicActor.Reset(A0_2477, A1_2478, A2_2479)
  if A1_2478 and A0_2477.Properties.signalmodifier_SignalModifier ~= nil then
    Ark.AttachInboundSignalModifier(A0_2477.id, A0_2477.Properties.signalmodifier_SignalModifier)
  end
  if A0_2477.OnEnabled then
    A0_2477:OnEnabled()
  end
  A0_2477:SetColliderMode(A0_2477.Properties.eiColliderMode)
  A0_2477.InitialPosition = A0_2477:GetPos()
  A0_2477:CheckShaderParamCallbacks()
  if A0_2477.OnResetCustom then
    A0_2477:OnResetCustom(A1_2478, A2_2479)
  end
end
function BasicAI.OnSpawn(A0_2480, A1_2481)
  A0_2480:RegisterAI(not A1_2481)
end
function BasicAI.OnBeingReused(A0_2482)
  A0_2482:Event_Disabled(A0_2482)
end
function BasicAI.GetReturnToPoolWeight(A0_2483, A1_2484)
  if not A0_2483:IsDead() and not A1_2484 then
    return 0
  end
  if A0_2483:IsDead() then
  end
  return 0 + 1000 + A0_2483:GetDistance(g_localActor.id)
end
function BasicAI.OnGetPoolSignature(A0_2485, A1_2486)
  local L2_2487
  L2_2487 = A0_2485.AIType
  if L2_2487 then
    L2_2487 = A0_2485.AIType
    A1_2486.AIType = L2_2487
  end
end
function BasicAI.Server.OnInit(A0_2488, A1_2489)
  A0_2488:OnReset(true, A1_2489)
end
function BasicAI.Server.OnInitClient(A0_2490, A1_2491)
  if A0_2490._enabled then
    A0_2490.onClient:ClAIEnable(A1_2491)
  else
    A0_2490.onClient:ClAIDisable(A1_2491)
  end
end
function BasicAI.Client.ClAIEnable(A0_2492)
  if not CryAction.IsServer() then
    A0_2492:Hide(0)
    A0_2492:Event_Enabled(A0_2492)
  end
end
function BasicAI.Client.ClAIDisable(A0_2493)
  if not CryAction.IsServer() then
    A0_2493:Hide(1)
    A0_2493:TriggerEvent(AIEVENT_DISABLE)
  end
end
function BasicAI.Client.OnShutDown(A0_2494)
  BasicActor.ShutDown(A0_2494)
end
function BasicAI.OnDeath(A0_2495)
  GameAI.UnregisterWithAllModules(A0_2495.id)
  if A0_2495.Event_Dead then
    A0_2495:Event_Dead(A0_2495)
  end
end
function BasicAI.Expose(A0_2496)
  Net.Expose({
    Class = A0_2496,
    ClientMethods = {
      ClAIEnable = {RELIABLE_ORDERED, PRE_ATTACH},
      ClAIDisable = {RELIABLE_ORDERED, PRE_ATTACH}
    },
    ServerMethods = {},
    ServerProperties = {}
  })
end
function BasicAI.Client.OnPreparedFromPool(A0_2497)
  local L1_2498
end
function BasicAI.IsInvulnerable(A0_2499)
  local L1_2500
  L1_2500 = false
  return L1_2500
end
function CreateAI(A0_2501)
  local L1_2502
  L1_2502 = {}
  mergef(L1_2502, A0_2501, 1)
  mergef(L1_2502, BasicAI, 1)
  mergef(L1_2502, BasicAIEvent, 1)
  mergef(L1_2502, BasicAITable, 1)
  MakeSpawnable(L1_2502)
  return L1_2502
end
function CreateAISubclass(A0_2503, A1_2504)
  local L2_2505
  L2_2505 = {}
  mergef(L2_2505, A0_2503, 1)
  mergef(L2_2505, A1_2504, 1)
  mergef(L2_2505, BasicAI, 1)
  mergef(L2_2505, BasicAIEvent, 1)
  mergef(L2_2505, BasicAITable, 1)
  MakeSpawnable(L2_2505)
  return L2_2505
end
