SpawnGroup = {
  Client = {},
  Server = {},
  Editor = {
    Icon = "spawngroup.bmp"
  },
  Properties = {
    objModelForSpawnGroup = "",
    teamName = "",
    bEnabled = 1,
    bDefault = 0
  }
}
SpawnGroup.NetSetup = {
  Class = SpawnGroup,
  ClientMethods = {},
  ServerMethods = {},
  ServerProperties = {}
}
function SpawnGroup.LoadModel(A0_6530)
  local L1_6531
  L1_6531 = A0_6530.Properties
  L1_6531 = L1_6531.objModelForSpawnGroup
  if string.len(L1_6531) > 0 then
    if string.lower(string.sub(L1_6531, -4)) == ".chr" or string.lower(string.sub(L1_6531, -4)) == ".cdf" or string.lower(string.sub(L1_6531, -4)) == ".cga" then
      A0_6530:LoadCharacter(0, L1_6531)
    else
      A0_6530:LoadObject(0, L1_6531)
    end
  end
  A0_6530:Physicalize(0, PE_STATIC, {mass = 0})
end
function SpawnGroup.OnSpawn(A0_6532)
  A0_6532:Activate(1)
  A0_6532:LoadModel()
end
function SpawnGroup.Server.OnInit(A0_6533)
  g_gameRules.game:SetTeam(g_gameRules.game:GetTeamId(A0_6533.Properties.teamName) or 0, A0_6533.id)
  A0_6533.default = tonumber(A0_6533.Properties.bDefault) ~= 0
end
function SpawnGroup.Server.OnStartGame(A0_6534)
  A0_6534:Enable(tonumber(A0_6534.Properties.bEnabled) ~= 0)
end
function SpawnGroup.OnPropertyChange(A0_6535)
  A0_6535:LoadModel()
end
function SpawnGroup.Server.OnShutDown(A0_6536)
  if g_gameRules then
    g_gameRules.game:RemoveSpawnGroup(A0_6536.id)
  end
end
function SpawnGroup.AddSpawnPoints(A0_6537, A1_6538)
  local L2_6539, L3_6540
  L2_6539 = 0
  L3_6540 = A0_6537.GetLinkTarget
  L3_6540 = L3_6540(A0_6537, A1_6538, L2_6539)
  while L3_6540 do
    g_gameRules.game:AddSpawnLocationToSpawnGroup(A0_6537.id, L3_6540.id)
    L3_6540:Enable(true)
    L2_6539 = L2_6539 + 1
    L3_6540 = A0_6537:GetLinkTarget(A1_6538, L2_6539)
  end
end
function SpawnGroup.RemoveSpawnPoints(A0_6541, A1_6542)
  local L2_6543, L3_6544
  L2_6543 = 0
  L3_6544 = A0_6541.GetLinkTarget
  L3_6544 = L3_6544(A0_6541, A1_6542, L2_6543)
  while L3_6544 do
    g_gameRules.game:RemoveSpawnLocationFromSpawnGroup(A0_6541.id, L3_6544.id)
    L3_6544:Enable(false)
    L2_6543 = L2_6543 + 1
    L3_6544 = A0_6541:GetLinkTarget(A1_6542, L2_6543)
  end
end
function SpawnGroup.Enable(A0_6545, A1_6546)
  local L2_6547
  L2_6547 = g_gameRules
  if not L2_6547 then
    return
  end
  if A1_6546 then
    L2_6547 = g_gameRules
    L2_6547 = L2_6547.game
    L2_6547 = L2_6547.AddSpawnGroup
    L2_6547(L2_6547, A0_6545.id)
    L2_6547 = g_gameRules
    L2_6547 = L2_6547.game
    L2_6547 = L2_6547.GetTeam
    L2_6547 = L2_6547(L2_6547, A0_6545.id)
    if A0_6545.default and L2_6547 ~= 0 then
      g_gameRules.game:SetTeamDefaultSpawnGroup(L2_6547, A0_6545.id)
    end
    A0_6545:AddSpawnPoints("spawn")
    A0_6545:AddSpawnPoints("spawnpoint")
    A0_6545:AddSpawnPoints("disruptor")
  else
    L2_6547 = g_gameRules
    L2_6547 = L2_6547.game
    L2_6547 = L2_6547.RemoveSpawnGroup
    L2_6547(L2_6547, A0_6545.id)
    L2_6547 = A0_6545.RemoveSpawnPoints
    L2_6547(A0_6545, "spawn")
    L2_6547 = A0_6545.RemoveSpawnPoints
    L2_6547(A0_6545, "spawnpoint")
    L2_6547 = A0_6545.RemoveSpawnPoints
    L2_6547(A0_6545, "disruptor")
  end
end
function SpawnGroup.IsEnabled(A0_6548)
  local L1_6549
  L1_6549 = A0_6548.enabled
  return L1_6549
end
function SpawnGroup.Event_Enable(A0_6550)
  A0_6550:Enable(true)
  if g_gameRules.SpawnGroupEnabled then
    g_gameRules:SpawnGroupEnabled(A0_6550.id, true)
  end
end
function SpawnGroup.Event_Disable(A0_6551)
  A0_6551:Enable(false)
  if g_gameRules.SpawnGroupEnabled then
    g_gameRules:SpawnGroupEnabled(A0_6551.id, false)
  end
end
SpawnGroup.FlowEvents = {
  Inputs = {
    Enable = {
      SpawnGroup.Event_Enable,
      "bool"
    },
    Disable = {
      SpawnGroup.Event_Disable,
      "bool"
    }
  }
}
Net.Expose(SpawnGroup.NetSetup)
