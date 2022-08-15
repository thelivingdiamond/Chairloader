local L0_3023, L1_3024, L2_3025, L3_3026
L0_3023 = {}
L0_3023.spawnedEntity = nil
L1_3024 = {}
L1_3024.commrange = 30
L1_3024.bSpeciesHostility = 1
L1_3024.soclasses_SmartObjectClass = "Actor"
L1_3024.attackrange = 70
L1_3024.special = 0
L1_3024.damageScale = 1
L1_3024.aicharacter_character = "Coordinator"
L2_3025 = {}
L2_3025.stanceScale = 1.8
L2_3025.sightrange = 50
L2_3025.FOVSecondary = 160
L2_3025.FOVPrimary = 80
L2_3025.audioScale = 1
L1_3024.Perception = L2_3025
L1_3024.species = 2
L1_3024.bInvulnerable = 0
L2_3025 = {}
L2_3025.dmgMult = 1
L2_3025.dmgRatio = 1
L1_3024.Vulnerability = L2_3025
L1_3024.accuracy = 1
L1_3024.fileModel = ""
L1_3024.horizontal_fov = 160
L0_3023.Properties = L1_3024
L1_3024 = {}
L1_3024.aibehavior_behaviour = "CoordinatorIdle"
L1_3024.soclasses_SmartObjectClass = ""
L1_3024.groupid = 173
L0_3023.PropertiesInstance = L1_3024
SpawnCoordinator = L0_3023
L0_3023 = SpawnCoordinator
L0_3023 = L0_3023.Properties
L0_3023.SpawnedEntityName = ""
L0_3023 = SpawnCoordinator
function L1_3024(A0_3027, A1_3028, A2_3029)
  local L3_3030
  L3_3030 = {}
  L3_3030.class = "Coordinator"
  L3_3030.position = A0_3027:GetPos()
  L3_3030.orientation = A0_3027:GetDirectionVector(1)
  L3_3030.scale = A0_3027:GetScale()
  L3_3030.properties = A0_3027.Properties
  L3_3030.propertiesInstance = A0_3027.PropertiesInstance
  if A0_3027.Properties.SpawnedEntityName ~= "" then
    L3_3030.name = A0_3027.Properties.SpawnedEntityName
  else
    L3_3030.name = A0_3027:GetName()
  end
  if System.SpawnEntity(L3_3030) then
    A0_3027.spawnedEntity = System.SpawnEntity(L3_3030).id
    if not System.SpawnEntity(L3_3030).Events then
      System.SpawnEntity(L3_3030).Events = {}
    end
    if not System.SpawnEntity(L3_3030).Events.Dead then
      System.SpawnEntity(L3_3030).Events.Dead = {}
    end
    table.insert(System.SpawnEntity(L3_3030).Events.Dead, {
      A0_3027.id,
      "Dead"
    })
  end
  BroadcastEvent(A0_3027, "Spawned")
end
L0_3023.Event_Spawn = L1_3024
L0_3023 = SpawnCoordinator
function L1_3024(A0_3031)
  if A0_3031.spawnedEntity then
    System.RemoveEntity(A0_3031.spawnedEntity)
    A0_3031.spawnedEntity = nil
  end
end
L0_3023.OnReset = L1_3024
L0_3023 = SpawnCoordinator
function L1_3024(A0_3032)
  local L1_3033
  L1_3033 = A0_3032.spawnedEntity
  return L1_3033
end
L0_3023.GetFlowgraphForwardingEntity = L1_3024
L0_3023 = SpawnCoordinator
function L1_3024(A0_3034)
  BroadcastEvent(A0_3034, "Spawned")
end
L0_3023.Event_Spawned = L1_3024
L0_3023 = SpawnCoordinator
function L1_3024(A0_3035, A1_3036, A2_3037)
  if A1_3036 and A1_3036.id == A0_3035.spawnedEntity then
    BroadcastEvent(A0_3035, "Dead")
  end
end
L0_3023.Event_Dead = L1_3024
L0_3023 = SpawnCoordinator
function L1_3024(A0_3038, A1_3039, A2_3040)
  local L3_3041
  L3_3041 = A0_3038.spawnedEntity
  if L3_3041 then
    if A1_3039 then
      L3_3041 = A0_3038.spawnedEntity
    elseif L3_3041 ~= A1_3039.id then
      L3_3041 = System
      L3_3041 = L3_3041.GetEntity
      L3_3041 = L3_3041(A0_3038.spawnedEntity)
      if L3_3041 and L3_3041 ~= A1_3039 then
        A0_3038.Handle_Disable(L3_3041, A1_3039, A2_3040)
      end
    end
  end
end
L0_3023.Event_Disable = L1_3024
L0_3023 = SpawnCoordinator
function L1_3024(A0_3042, A1_3043, A2_3044)
  local L3_3045
  L3_3045 = A0_3042.spawnedEntity
  if L3_3045 then
    if A1_3043 then
      L3_3045 = A0_3042.spawnedEntity
    elseif L3_3045 ~= A1_3043.id then
      L3_3045 = System
      L3_3045 = L3_3045.GetEntity
      L3_3045 = L3_3045(A0_3042.spawnedEntity)
      if L3_3045 and L3_3045 ~= A1_3043 then
        A0_3042.Handle_Enable(L3_3045, A1_3043, A2_3044)
      end
    end
  end
end
L0_3023.Event_Enable = L1_3024
L0_3023 = SpawnCoordinator
function L1_3024(A0_3046, A1_3047, A2_3048)
  local L3_3049
  L3_3049 = A0_3046.spawnedEntity
  if L3_3049 then
    if A1_3047 then
      L3_3049 = A0_3046.spawnedEntity
    elseif L3_3049 ~= A1_3047.id then
      L3_3049 = System
      L3_3049 = L3_3049.GetEntity
      L3_3049 = L3_3049(A0_3046.spawnedEntity)
      if L3_3049 and L3_3049 ~= A1_3047 then
        A0_3046.Handle_Kill(L3_3049, A1_3047, A2_3048)
      end
    end
  end
end
L0_3023.Event_Kill = L1_3024
L0_3023 = SpawnCoordinator
L1_3024 = {}
L2_3025 = {}
L3_3026 = {
  SpawnCoordinator.Event_Spawn,
  "bool"
}
L2_3025.Spawn = L3_3026
L3_3026 = {
  SpawnCoordinator.Event_Disable,
  "bool"
}
L2_3025.Disable = L3_3026
L3_3026 = {
  SpawnCoordinator.Event_Enable,
  "bool"
}
L2_3025.Enable = L3_3026
L3_3026 = {
  SpawnCoordinator.Event_Kill,
  "bool"
}
L2_3025.Kill = L3_3026
L1_3024.Inputs = L2_3025
L2_3025 = {}
L2_3025.Spawned = "bool"
L2_3025.Dead = "bool"
L1_3024.Outputs = L2_3025
L0_3023.FlowEvents = L1_3024
L0_3023 = SpawnCoordinator
L1_3024 = Coordinator
L1_3024 = L1_3024.FlowEvents
L1_3024 = L1_3024.Inputs
L1_3024 = L1_3024.Disable
L1_3024 = L1_3024[1]
L0_3023.Handle_Disable = L1_3024
L0_3023 = SpawnCoordinator
L1_3024 = Coordinator
L1_3024 = L1_3024.FlowEvents
L1_3024 = L1_3024.Inputs
L1_3024 = L1_3024.Enable
L1_3024 = L1_3024[1]
L0_3023.Handle_Enable = L1_3024
L0_3023 = SpawnCoordinator
L1_3024 = Coordinator
L1_3024 = L1_3024.FlowEvents
L1_3024 = L1_3024.Inputs
L1_3024 = L1_3024.Kill
L1_3024 = L1_3024[1]
L0_3023.Handle_Kill = L1_3024
