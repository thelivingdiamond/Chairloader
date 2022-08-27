Script.ReloadScript("Scripts/Entities/AI/Grunt.lua")
SpawnGrunt = {
  spawnedEntity = nil,
  Properties = {
    commrange = 30,
    SpawnedEntityName = "",
    bSpeciesHostility = 1,
    soclasses_SmartObjectClass = "Actor",
    attackrange = 70,
    special = 0,
    aicharacter_character = "Cover",
    Perception = {
      stanceScale = 1.8,
      sightrange = 50,
      FOVSecondary = 160,
      FOVPrimary = 80,
      audioScale = 1
    },
    species = 1,
    bInvulnerable = 0,
    accuracy = 1,
    fileModel = ""
  },
  PropertiesInstance = {
    aibehavior_behaviour = "Job_StandIdle",
    soclasses_SmartObjectClass = "",
    groupid = 173
  }
}
SpawnGrunt.Properties.SpawnedEntityName = ""
function SpawnGrunt.Event_Spawn(A0_3050, A1_3051, A2_3052)
  local L3_3053
  L3_3053 = {}
  L3_3053.class = "Grunt"
  L3_3053.position = A0_3050:GetPos()
  L3_3053.orientation = A0_3050:GetDirectionVector(1)
  L3_3053.scale = A0_3050:GetScale()
  L3_3053.properties = A0_3050.Properties
  L3_3053.propertiesInstance = A0_3050.PropertiesInstance
  if A0_3050.Properties.SpawnedEntityName ~= "" then
    L3_3053.name = A0_3050.Properties.SpawnedEntityName
  else
    L3_3053.name = A0_3050:GetName()
  end
  if System.SpawnEntity(L3_3053) then
    A0_3050.spawnedEntity = System.SpawnEntity(L3_3053).id
    if not System.SpawnEntity(L3_3053).Events then
      System.SpawnEntity(L3_3053).Events = {}
    end
    if not System.SpawnEntity(L3_3053).Events.Dead then
      System.SpawnEntity(L3_3053).Events.Dead = {}
    end
    table.insert(System.SpawnEntity(L3_3053).Events.Dead, {
      A0_3050.id,
      "Dead"
    })
    if not System.SpawnEntity(L3_3053).Events.Spawned then
      System.SpawnEntity(L3_3053).Events.Spawned = {}
    end
    table.insert(System.SpawnEntity(L3_3053).Events.Spawned, {
      A0_3050.id,
      "Spawned"
    })
  end
  BroadcastEvent(A0_3050, "Spawned")
end
function SpawnGrunt.OnReset(A0_3054)
  if A0_3054.spawnedEntity then
    System.RemoveEntity(A0_3054.spawnedEntity)
    A0_3054.spawnedEntity = nil
  end
end
function SpawnGrunt.GetFlowgraphForwardingEntity(A0_3055)
  local L1_3056
  L1_3056 = A0_3055.spawnedEntity
  return L1_3056
end
function SpawnGrunt.Event_Spawned(A0_3057)
  BroadcastEvent(A0_3057, "Spawned")
end
function SpawnGrunt.Event_Dead(A0_3058, A1_3059, A2_3060)
  if A1_3059 and A1_3059.id == A0_3058.spawnedEntity then
    BroadcastEvent(A0_3058, "Dead")
  end
end
function SpawnGrunt.Event_Disable(A0_3061, A1_3062, A2_3063)
  local L3_3064
  L3_3064 = A0_3061.spawnedEntity
  if L3_3064 then
    if A1_3062 then
      L3_3064 = A0_3061.spawnedEntity
    elseif L3_3064 ~= A1_3062.id then
      L3_3064 = System
      L3_3064 = L3_3064.GetEntity
      L3_3064 = L3_3064(A0_3061.spawnedEntity)
      if L3_3064 and L3_3064 ~= A1_3062 then
        A0_3061.Handle_Disable(L3_3064, A1_3062, A2_3063)
      end
    end
  end
end
function SpawnGrunt.Event_Enable(A0_3065, A1_3066, A2_3067)
  local L3_3068
  L3_3068 = A0_3065.spawnedEntity
  if L3_3068 then
    if A1_3066 then
      L3_3068 = A0_3065.spawnedEntity
    elseif L3_3068 ~= A1_3066.id then
      L3_3068 = System
      L3_3068 = L3_3068.GetEntity
      L3_3068 = L3_3068(A0_3065.spawnedEntity)
      if L3_3068 and L3_3068 ~= A1_3066 then
        A0_3065.Handle_Enable(L3_3068, A1_3066, A2_3067)
      end
    end
  end
end
function SpawnGrunt.Event_Kill(A0_3069, A1_3070, A2_3071)
  local L3_3072
  L3_3072 = A0_3069.spawnedEntity
  if L3_3072 then
    if A1_3070 then
      L3_3072 = A0_3069.spawnedEntity
    elseif L3_3072 ~= A1_3070.id then
      L3_3072 = System
      L3_3072 = L3_3072.GetEntity
      L3_3072 = L3_3072(A0_3069.spawnedEntity)
      if L3_3072 and L3_3072 ~= A1_3070 then
        A0_3069.Handle_Kill(L3_3072, A1_3070, A2_3071)
      end
    end
  end
end
function SpawnGrunt.Event_Spawn(A0_3073, A1_3074, A2_3075)
  local L3_3076
  L3_3076 = A0_3073.spawnedEntity
  if L3_3076 then
    if A1_3074 then
      L3_3076 = A0_3073.spawnedEntity
    elseif L3_3076 ~= A1_3074.id then
      L3_3076 = System
      L3_3076 = L3_3076.GetEntity
      L3_3076 = L3_3076(A0_3073.spawnedEntity)
      if L3_3076 and L3_3076 ~= A1_3074 then
        A0_3073.Handle_Spawn(L3_3076, A1_3074, A2_3075)
      end
    end
  end
end
function SpawnGrunt.Event_Spawned(A0_3077, A1_3078, A2_3079)
  if A1_3078 and A1_3078.id == A0_3077.spawnedEntity then
    BroadcastEvent(A0_3077, "Spawned")
  end
end
SpawnGrunt.FlowEvents = {
  Inputs = {
    Spawn = {
      SpawnGrunt.Event_Spawn,
      "bool"
    },
    Disable = {
      SpawnGrunt.Event_Disable,
      "bool"
    },
    Enable = {
      SpawnGrunt.Event_Enable,
      "bool"
    },
    Hide = {
      SpawnGrunt.Event_Hide,
      "bool"
    },
    Kill = {
      SpawnGrunt.Event_Kill,
      "bool"
    },
    Spawn = {
      SpawnGrunt.Event_Spawn,
      "bool"
    }
  },
  Outputs = {
    Spawned = "bool",
    Dead = "bool",
    Spawned = "bool"
  }
}
SpawnGrunt.Handle_Disable = Grunt.FlowEvents.Inputs.Disable[1]
SpawnGrunt.Handle_Enable = Grunt.FlowEvents.Inputs.Enable[1]
SpawnGrunt.Handle_Kill = Grunt.FlowEvents.Inputs.Kill[1]
SpawnGrunt.Handle_Spawn = Grunt.FlowEvents.Inputs.Spawn[1]
