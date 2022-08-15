local L0_7174, L1_7175, L2_7176, L3_7177
L0_7174 = {}
L1_7175 = {}
L0_7174.Client = L1_7175
L1_7175 = {}
L0_7174.Server = L1_7175
L1_7175 = {}
L1_7175.Model = "Editor/Objects/spawnpointhelper.cgf"
L1_7175.Icon = "SpawnPoint.bmp"
L1_7175.DisplayArrow = 1
L0_7174.Editor = L1_7175
L1_7175 = {}
L1_7175.teamName = ""
L1_7175.groupName = ""
L1_7175.bEnabled = 1
L1_7175.bInitialSpawn = 0
L1_7175.bDoVisTest = 1
L1_7175.destinationName = ""
L1_7175.bForceHiddenInProbes = 1
L0_7174.Properties = L1_7175
SpawnPoint = L0_7174
L0_7174 = SpawnPoint
L0_7174 = L0_7174.Server
function L1_7175(A0_7178)
  if System.IsMultiplayer() then
    g_gameRules.game:AddSpawnLocation(A0_7178.id, A0_7178.Properties.bInitialSpawn, A0_7178.Properties.bDoVisTest, A0_7178.Properties.groupName)
  end
  A0_7178:Enable(tonumber(A0_7178.Properties.bEnabled) ~= 0)
  A0_7178:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
  g_gameRules.game:ClientSetTeam(g_gameRules.game:GetTeamId(A0_7178.Properties.teamName) or 0, A0_7178.id)
  if System.IsEditor() then
    A0_7178:LoadObject(0, A0_7178.Editor.Model)
  end
end
L0_7174.OnInit = L1_7175
L0_7174 = SpawnPoint
function L1_7175(A0_7179, A1_7180)
  if A1_7180 then
    A0_7179:DrawSlot(0, 0)
  else
    A0_7179:DrawSlot(0, 1)
  end
end
L0_7174.OnEditorSetGameMode = L1_7175
L0_7174 = SpawnPoint
L0_7174 = L0_7174.Client
function L1_7175(A0_7181)
  A0_7181:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
  if not CryAction.IsServer() then
    g_gameRules.game:AddSpawnLocation(A0_7181.id, A0_7181.Properties.bInitialSpawn, A0_7181.Properties.bDoVisTest, A0_7181.Properties.groupName)
    g_gameRules.game:ClientSetTeam(g_gameRules.game:GetTeamId(A0_7181.Properties.teamName) or 0, A0_7181.id)
    A0_7181:Enable(tonumber(A0_7181.Properties.bEnabled) ~= 0)
  end
end
L0_7174.OnInit = L1_7175
L0_7174 = SpawnPoint
function L1_7175(A0_7182, A1_7183)
  if System.IsMultiplayer() then
    if A1_7183 then
      g_gameRules.game:EnableSpawnLocation(A0_7182.id, A0_7182.Properties.bInitialSpawn, A0_7182.Properties.groupName)
    else
      g_gameRules.game:DisableSpawnLocation(A0_7182.id, A0_7182.Properties.bInitialSpawn)
    end
  elseif A1_7183 then
    g_gameRules.game:AddSpawnLocation(A0_7182.id, A0_7182.Properties.bInitialSpawn, A0_7182.Properties.bDoVisTest, A0_7182.Properties.groupName)
  else
    g_gameRules.game:RemoveSpawnLocation(A0_7182.id, A0_7182.Properties.bInitialSpawn)
  end
  A0_7182.enabled = A1_7183
end
L0_7174.Enable = L1_7175
L0_7174 = SpawnPoint
function L1_7175(A0_7184)
  A0_7184:Enable(tonumber(A0_7184.Properties.bEnabled) ~= 0)
end
L0_7174.OnPropertyChange = L1_7175
L0_7174 = SpawnPoint
L0_7174 = L0_7174.Server
function L1_7175(A0_7185)
  if g_gameRules then
    g_gameRules.game:RemoveSpawnLocation(A0_7185.id, A0_7185.Properties.bInitialSpawn)
  end
end
L0_7174.OnShutDown = L1_7175
L0_7174 = SpawnPoint
L0_7174 = L0_7174.Client
function L1_7175(A0_7186)
  if g_gameRules and not CryAction.IsServer() then
    g_gameRules.game:RemoveSpawnLocation(A0_7186.id, A0_7186.Properties.bInitialSpawn)
  end
end
L0_7174.OnShutDown = L1_7175
L0_7174 = SpawnPoint
function L1_7175(A0_7187, A1_7188)
  A0_7187:ActivateOutput("Spawn", A1_7188.id)
end
L0_7174.Spawned = L1_7175
L0_7174 = SpawnPoint
function L1_7175(A0_7189)
  local L1_7190
  L1_7190 = A0_7189.enabled
  return L1_7190
end
L0_7174.IsEnabled = L1_7175
L0_7174 = SpawnPoint
function L1_7175(A0_7191)
  local L1_7192
  L1_7192 = g_localActor
  if L1_7192 == nil then
    return
  end
  L1_7192 = g_localActor
  A0_7191:GetWorldPos(g_Vectors.temp_v1)
  A0_7191:GetAngles(g_Vectors.temp_v2)
  g_Vectors.temp_v2.x = 0
  g_Vectors.temp_v2.y = 0
  L1_7192.arkPlayer:Spawn(g_Vectors.temp_v1, g_Vectors.temp_v2)
  A0_7191:ActivateOutput("Spawn", L1_7192.id)
end
L0_7174.Event_Spawn = L1_7175
L0_7174 = SpawnPoint
function L1_7175(A0_7193)
  A0_7193:Enable(true)
  BroadcastEvent(A0_7193, "Enabled")
end
L0_7174.Event_Enable = L1_7175
L0_7174 = SpawnPoint
function L1_7175(A0_7194)
  A0_7194:Enable(false)
  BroadcastEvent(A0_7194, "Disabled")
end
L0_7174.Event_Disable = L1_7175
L0_7174 = SpawnPoint
L1_7175 = {}
L2_7176 = {}
L3_7177 = {
  SpawnPoint.Event_Spawn,
  "bool"
}
L2_7176.Spawn = L3_7177
L3_7177 = {
  SpawnPoint.Event_Enable,
  "bool"
}
L2_7176.Enable = L3_7177
L3_7177 = {
  SpawnPoint.Event_Disable,
  "bool"
}
L2_7176.Disable = L3_7177
L1_7175.Inputs = L2_7176
L2_7176 = {}
L2_7176.Spawn = "entity"
L2_7176.Enabled = "bool"
L2_7176.Disabled = "bool"
L1_7175.Outputs = L2_7176
L0_7174.FlowEvents = L1_7175
