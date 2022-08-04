Script.ReloadScript("Scripts/Entities/AI/Civilian.lua")
SpawnCivilian = {
  spawnedEntity = nil,
  Properties = {
    fileModel = "",
    attackrange = 0,
    commrange = 30,
    special = 0,
    aicharacter_character = "Hostage",
    Perception = {
      stanceScale = 1.8,
      sightrange = 50,
      FOVSecondary = 160,
      FOVPrimary = 80,
      audioScale = 1
    },
    species = 10,
    bInvulnerable = 0,
    bSpeciesHostility = 0,
    accuracy = 1,
    soclasses_SmartObjectClass = "Actor"
  },
  PropertiesInstance = {
    aibehavior_behaviour = "Job_StandIdle",
    soclasses_SmartObjectClass = "",
    groupid = 173
  }
}
SpawnCivilian.Properties.SpawnedEntityName = ""
function SpawnCivilian.Event_Spawn(A0_3000, A1_3001, A2_3002)
  local L3_3003
  L3_3003 = {}
  L3_3003.class = "Civilian"
  L3_3003.position = A0_3000:GetPos()
  L3_3003.orientation = A0_3000:GetDirectionVector(1)
  L3_3003.scale = A0_3000:GetScale()
  L3_3003.properties = A0_3000.Properties
  L3_3003.propertiesInstance = A0_3000.PropertiesInstance
  if A0_3000.Properties.SpawnedEntityName ~= "" then
    L3_3003.name = A0_3000.Properties.SpawnedEntityName
  else
    L3_3003.name = A0_3000:GetName()
  end
  if System.SpawnEntity(L3_3003) then
    A0_3000.spawnedEntity = System.SpawnEntity(L3_3003).id
    if not System.SpawnEntity(L3_3003).Events then
      System.SpawnEntity(L3_3003).Events = {}
    end
    if not System.SpawnEntity(L3_3003).Events.Dead then
      System.SpawnEntity(L3_3003).Events.Dead = {}
    end
    table.insert(System.SpawnEntity(L3_3003).Events.Dead, {
      A0_3000.id,
      "Dead"
    })
  end
  BroadcastEvent(A0_3000, "Spawned")
end
function SpawnCivilian.OnReset(A0_3004)
  if A0_3004.spawnedEntity then
    System.RemoveEntity(A0_3004.spawnedEntity)
    A0_3004.spawnedEntity = nil
  end
end
function SpawnCivilian.GetFlowgraphForwardingEntity(A0_3005)
  local L1_3006
  L1_3006 = A0_3005.spawnedEntity
  return L1_3006
end
function SpawnCivilian.Event_Spawned(A0_3007)
  BroadcastEvent(A0_3007, "Spawned")
end
function SpawnCivilian.Event_Dead(A0_3008, A1_3009, A2_3010)
  if A1_3009 and A1_3009.id == A0_3008.spawnedEntity then
    BroadcastEvent(A0_3008, "Dead")
  end
end
function SpawnCivilian.Event_Disable(A0_3011, A1_3012, A2_3013)
  local L3_3014
  L3_3014 = A0_3011.spawnedEntity
  if L3_3014 then
    if A1_3012 then
      L3_3014 = A0_3011.spawnedEntity
    elseif L3_3014 ~= A1_3012.id then
      L3_3014 = System
      L3_3014 = L3_3014.GetEntity
      L3_3014 = L3_3014(A0_3011.spawnedEntity)
      if L3_3014 and L3_3014 ~= A1_3012 then
        A0_3011.Handle_Disable(L3_3014, A1_3012, A2_3013)
      end
    end
  end
end
function SpawnCivilian.Event_Enable(A0_3015, A1_3016, A2_3017)
  local L3_3018
  L3_3018 = A0_3015.spawnedEntity
  if L3_3018 then
    if A1_3016 then
      L3_3018 = A0_3015.spawnedEntity
    elseif L3_3018 ~= A1_3016.id then
      L3_3018 = System
      L3_3018 = L3_3018.GetEntity
      L3_3018 = L3_3018(A0_3015.spawnedEntity)
      if L3_3018 and L3_3018 ~= A1_3016 then
        A0_3015.Handle_Enable(L3_3018, A1_3016, A2_3017)
      end
    end
  end
end
function SpawnCivilian.Event_Kill(A0_3019, A1_3020, A2_3021)
  local L3_3022
  L3_3022 = A0_3019.spawnedEntity
  if L3_3022 then
    if A1_3020 then
      L3_3022 = A0_3019.spawnedEntity
    elseif L3_3022 ~= A1_3020.id then
      L3_3022 = System
      L3_3022 = L3_3022.GetEntity
      L3_3022 = L3_3022(A0_3019.spawnedEntity)
      if L3_3022 and L3_3022 ~= A1_3020 then
        A0_3019.Handle_Kill(L3_3022, A1_3020, A2_3021)
      end
    end
  end
end
SpawnCivilian.FlowEvents = {
  Inputs = {
    Spawn = {
      SpawnCivilian.Event_Spawn,
      "bool"
    },
    Disable = {
      SpawnCivilian.Event_Disable,
      "bool"
    },
    Enable = {
      SpawnCivilian.Event_Enable,
      "bool"
    },
    Kill = {
      SpawnCivilian.Event_Kill,
      "bool"
    }
  },
  Outputs = {Spawned = "bool", Dead = "bool"}
}
SpawnCivilian.Handle_Disable = Civilian.FlowEvents.Inputs.Disable[1]
SpawnCivilian.Handle_Enable = Civilian.FlowEvents.Inputs.Enable[1]
SpawnCivilian.Handle_Kill = Civilian.FlowEvents.Inputs.Kill[1]
