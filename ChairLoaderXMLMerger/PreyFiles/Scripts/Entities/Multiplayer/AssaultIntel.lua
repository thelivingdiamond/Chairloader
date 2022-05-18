AssaultIntel = {
  Client = {},
  Server = {},
  Properties = {
    fileModelOverride = "",
    ControlRadius = 3,
    ControlHeight = 3,
    ControlOffsetZ = 0,
    teamName = "",
    DebugDraw = 0
  },
  Editor = {Icon = "Item.bmp", IconOnTop = 1},
  previousUploadProgress = -20,
  previousTeam = 0
}
AssaultIntel.DEFAULT_FILE_MODEL = "objects/multiplayer/props/cw2_assault_mod_monitor/cw2_assault_mod_monitor.cgf"
Net.Expose({
  Class = AssaultIntel,
  ClientMethods = {},
  ServerMethods = {},
  ServerProperties = {UploadProgress = FLOAT, UploadInProgress = BOOL}
})
function AssaultIntel.Server.OnInit(A0_6080)
  if not A0_6080.bInitialized then
    A0_6080:OnReset()
    A0_6080.bInitialized = 1
    A0_6080:SetViewDistRatio(255)
  end
  A0_6080.inside = {}
  A0_6080.synched.UploadProgress = 0
  A0_6080.synched.UploadInProgress = false
end
function AssaultIntel.Client.OnInit(A0_6081)
  A0_6081.ClAlarmActive = false
  A0_6081.ClAlarmSoundID = nil
  if not A0_6081.bInitialized then
    A0_6081:OnReset()
    A0_6081.bInitialized = 1
    A0_6081:SetViewDistRatio(255)
  end
  A0_6081.inside = {}
end
function AssaultIntel.Client.WarningAlarm(A0_6082, A1_6083)
  if A1_6083 then
    A0_6082.ClAlarmActive = true
    if not A0_6082.ClAlarmSoundID then
      A0_6082.ClAlarmSoundID = Sound.Play("Sounds/crysiswar2:interface:multiplayer/mp_alarm_ambience_loop", A0_6082:GetWorldPos(), SOUND_DEFAULT_3D, SOUND_SEMANTIC_MECHANIC_ENTITY)
    end
  else
    A0_6082.ClAlarmActive = false
    if A0_6082.ClAlarmSoundID then
      Sound.StopSound(A0_6082.ClAlarmSoundID)
      A0_6082.ClAlarmSoundID = nil
    end
  end
end
function AssaultIntel.Client.OnUpdate(A0_6084, A1_6085)
  if g_localActorId and g_gameRules then
    if A0_6084.synched.UploadInProgress == true and A0_6084.ClAlarmActive == false then
      A0_6084.Client.WarningAlarm(A0_6084, true)
    elseif A0_6084.synched.UploadInProgress == false and A0_6084.ClAlarmActive == true then
      A0_6084.Client.WarningAlarm(A0_6084, false)
    end
  end
end
function AssaultIntel.OnReset(A0_6086)
  local L1_6087, L2_6088, L3_6089, L4_6090, L5_6091, L6_6092
  L1_6087 = A0_6086.DEFAULT_FILE_MODEL
  L2_6088 = A0_6086.Properties
  L2_6088 = L2_6088.fileModelOverride
  if L2_6088 then
    L2_6088 = A0_6086.Properties
    L2_6088 = L2_6088.fileModelOverride
    if L2_6088 ~= "" then
      L2_6088 = A0_6086.Properties
      L1_6087 = L2_6088.fileModelOverride
    end
  end
  L3_6089 = A0_6086
  L2_6088 = A0_6086.LoadObject
  L4_6090 = 0
  L5_6091 = L1_6087
  L2_6088(L3_6089, L4_6090, L5_6091)
  L3_6089 = A0_6086
  L2_6088 = A0_6086.Physicalize
  L4_6090 = 0
  L5_6091 = PE_STATIC
  L6_6092 = {}
  L6_6092.mass = 0
  L2_6088(L3_6089, L4_6090, L5_6091, L6_6092)
  L2_6088 = A0_6086.Properties
  L2_6088 = L2_6088.ControlRadius
  L3_6089 = A0_6086.Properties
  L3_6089 = L3_6089.ControlOffsetZ
  L4_6090 = A0_6086.Properties
  L4_6090 = L4_6090.ControlHeight
  L5_6091 = {}
  L6_6092 = -L2_6088
  L5_6091.x = L6_6092
  L6_6092 = -L2_6088
  L5_6091.y = L6_6092
  L5_6091.z = L3_6089
  L6_6092 = {}
  L6_6092.x = L2_6088
  L6_6092.y = L2_6088
  L6_6092.z = L4_6090 + L3_6089
  A0_6086:SetTriggerBBox(L5_6091, L6_6092)
  A0_6086:SetViewDistRatio(255)
  A0_6086:SetFlags(ENTITY_FLAG_ON_RADAR, 0)
  if A0_6086.isClient and A0_6086.ClAlarmActive == true then
    A0_6086.Client.WarningAlarm(A0_6086, false)
  end
  if System.IsEditor() then
    if A0_6086.Properties.DebugDraw ~= 0 then
      A0_6086:Activate(1)
    else
      A0_6086:Activate(0)
    end
  end
end
function AssaultIntel.OnPropertyChange(A0_6093)
  A0_6093:OnReset()
end
function AssaultIntel.Client.OnEnterArea(A0_6094, A1_6095, A2_6096)
  for _FORV_7_, _FORV_8_ in ipairs(A0_6094.inside) do
    if _FORV_8_ == A1_6095.id then
      break
    end
  end
  if not true then
    table.insert(A0_6094.inside, A1_6095.id)
  end
end
function AssaultIntel.Client.OnLeaveArea(A0_6097, A1_6098, A2_6099)
  local L3_6100, L4_6101, L5_6102, L6_6103
  for L6_6103, _FORV_7_ in L3_6100(L4_6101) do
    if _FORV_7_ == A1_6098.id then
      table.remove(A0_6097.inside, L6_6103)
      break
    end
  end
end
function AssaultIntel.EntityInsideArea(A0_6104, A1_6105)
  for _FORV_5_, _FORV_6_ in ipairs(A0_6104.inside) do
    if _FORV_6_ == A1_6105 then
      return true
    end
  end
  return false
end
function AssaultIntel.Server.OnEnterArea(A0_6106, A1_6107, A2_6108)
  if A1_6107 and A1_6107.actor and A1_6107.actor:IsPlayer() then
    for _FORV_7_, _FORV_8_ in ipairs(A0_6106.inside) do
      if _FORV_8_ == A1_6107.id then
        break
      end
    end
    if not true then
      table.insert(A0_6106.inside, A1_6107.id)
    end
    if g_gameRules.Server.EntityEnterIntelPoint ~= nil then
      g_gameRules.Server.EntityEnterIntelPoint(g_gameRules, A0_6106, A1_6107)
    end
  end
end
function AssaultIntel.Server.OnLeaveArea(A0_6109, A1_6110, A2_6111)
  local L3_6112, L4_6113, L5_6114, L6_6115
  if A1_6110 then
    if L3_6112 then
      if L3_6112 then
        for L6_6115, _FORV_7_ in L3_6112(L4_6113) do
          if _FORV_7_ == A1_6110.id then
            table.remove(A0_6109.inside, L6_6115)
            break
          end
        end
        if L3_6112 ~= nil then
          L6_6115 = A1_6110
          L3_6112(L4_6113, L5_6114, L6_6115)
        end
      end
    end
  end
end
function AssaultIntel.Server.OnUpdate(A0_6116, A1_6117)
  local L2_6118, L3_6119, L4_6120
  L2_6118 = A0_6116.Properties
  L2_6118 = L2_6118.DebugDraw
  if L2_6118 ~= 0 then
    L3_6119 = A0_6116
    L2_6118 = A0_6116.GetWorldPos
    L2_6118 = L2_6118(L3_6119)
    L3_6119 = A0_6116.Properties
    L3_6119 = L3_6119.ControlRadius
    L4_6120 = A0_6116.Properties
    L4_6120 = L4_6120.ControlHeight
    L2_6118.z = L2_6118.z + L4_6120 * 0.5 + A0_6116.Properties.ControlOffsetZ
    Game.DebugDrawCylinder(L2_6118.x, L2_6118.y, L2_6118.z, L3_6119, L4_6120, 60, 60, 255, 100)
  end
end
