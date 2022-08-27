local L0_6385, L1_6386
L0_6385 = {}
L1_6386 = {}
L0_6385.Client = L1_6386
L1_6386 = {}
L0_6385.Server = L1_6386
L1_6386 = {}
L1_6386.fileModelOverride = ""
L1_6386.Radius = 2
L1_6386.OpenRange = 6
L0_6385.Properties = L1_6386
L1_6386 = {}
L1_6386.Icon = "Item.bmp"
L1_6386.IconOnTop = 1
L0_6385.Editor = L1_6386
L0_6385.modelSlot = -1
L1_6386 = {}
L0_6385.spawnPointIds = L1_6386
L0_6385.open = false
ExtractionPoint = L0_6385
L0_6385 = ExtractionPoint
L0_6385.DEFAULT_FILE_MODEL = "objects/multiplayer/props/c3mp_gamemode_props/c3mp_powercell/c3mp_powercell.cdf"
L0_6385 = ExtractionPoint
L0_6385 = L0_6385.Server
function L1_6386(A0_6387)
  Log("ExtractionPoint.Server.OnInit")
  if not A0_6387.bInitialized then
    A0_6387:OnReset()
    A0_6387.bInitialized = 1
    A0_6387:SetViewDistRatio(255)
  end
  A0_6387.inside = {}
end
L0_6385.OnInit = L1_6386
L0_6385 = ExtractionPoint
L0_6385 = L0_6385.Client
function L1_6386(A0_6388)
  Log("ExtractionPoint.Client.OnInit")
  if not A0_6388.bInitialized then
    A0_6388:OnReset()
    A0_6388.bInitialized = 1
    A0_6388:SetViewDistRatio(255)
  end
  A0_6388.inside = {}
end
L0_6385.OnInit = L1_6386
L0_6385 = ExtractionPoint
function L1_6386(A0_6389)
  local L1_6390, L2_6391, L3_6392
  L1_6390 = Log
  L2_6391 = "ExtractionPoint.OnReset"
  L1_6390(L2_6391)
  L1_6390 = A0_6389.Properties
  L1_6390 = L1_6390.Radius
  L1_6390 = L1_6390 / 2
  L2_6391 = {}
  L3_6392 = -L1_6390
  L2_6391.x = L3_6392
  L3_6392 = -L1_6390
  L2_6391.y = L3_6392
  L3_6392 = -L1_6390
  L2_6391.z = L3_6392
  L3_6392 = {}
  L3_6392.x = L1_6390
  L3_6392.y = L1_6390
  L3_6392.z = L1_6390
  A0_6389:SetTriggerBBox(L2_6391, L3_6392)
  A0_6389:SetViewDistRatio(255)
  if System.IsEditor() then
    Log("In editor, activating")
    A0_6389:ActivateSite()
    A0_6389:AddSpawnPoints("spawn")
    A0_6389:AddSpawnPoints("spawnpoint")
    A0_6389:AddSpawnPoints("disruptor")
    Log("Entity=%s, found %d associated spawn points", EntityName(A0_6389), #A0_6389.spawnPointIds)
  end
end
L0_6385.OnReset = L1_6386
L0_6385 = ExtractionPoint
function L1_6386(A0_6393, A1_6394)
  local L2_6395, L3_6396
  L2_6395 = 0
  L3_6396 = A0_6393.GetLinkTarget
  L3_6396 = L3_6396(A0_6393, A1_6394, L2_6395)
  while L3_6396 do
    InsertIntoTable(A0_6393.spawnPointIds, L3_6396.id)
    L2_6395 = L2_6395 + 1
    L3_6396 = A0_6393:GetLinkTarget(A1_6394, L2_6395)
  end
end
L0_6385.AddSpawnPoints = L1_6386
L0_6385 = ExtractionPoint
function L1_6386(A0_6397)
  local L1_6398
  L1_6398 = A0_6397.DEFAULT_FILE_MODEL
  if A0_6397.Properties.fileModelOverride and A0_6397.Properties.fileModelOverride ~= "" then
    Log("Override file model provided, using model '%s'", A0_6397.Properties.fileModelOverride)
    L1_6398 = A0_6397.Properties.fileModelOverride
  end
  A0_6397.modelSlot = A0_6397:LoadObject(A0_6397.modelSlot, L1_6398)
  A0_6397:Physicalize(A0_6397.modelSlot, PE_STATIC, {mass = 0})
  A0_6397:SetViewDistRatio(255)
  A0_6397:SetFlags(ENTITY_FLAG_ON_RADAR, 0)
end
L0_6385.ActivateSite = L1_6386
L0_6385 = ExtractionPoint
function L1_6386(A0_6399)
  A0_6399:DestroyPhysics()
  A0_6399:FreeSlot(A0_6399.modelSlot)
  A0_6399.modelSlot = -1
  A0_6399:SetViewDistRatio(255)
  A0_6399:SetFlags(ENTITY_FLAG_ON_RADAR, 2)
end
L0_6385.DeactivateSite = L1_6386
L0_6385 = ExtractionPoint
function L1_6386(A0_6400, A1_6401)
  local L2_6402, L3_6403, L4_6404, L5_6405, L6_6406
  L5_6405 = A0_6400
  L5_6405 = A1_6401
  L2_6402(L3_6403, L4_6404, L5_6405)
  if L2_6402 then
    A0_6400.spawnPointIds = L2_6402
    L2_6402(L3_6403, L4_6404)
    L2_6402(L3_6403, L4_6404)
    L2_6402(L3_6403, L4_6404)
    L5_6405 = A0_6400
    L5_6405 = A0_6400.spawnPointIds
    L5_6405 = #L5_6405
    L2_6402(L3_6403, L4_6404, L5_6405)
    for L5_6405, L6_6406 in L2_6402(L3_6403) do
      g_gameRules.game:ClientSetTeam(A1_6401, L6_6406)
    end
  end
end
L0_6385.OnSetTeam = L1_6386
L0_6385 = ExtractionPoint
function L1_6386(A0_6407, A1_6408)
  if A0_6407.open ~= A1_6408 then
    A0_6407.open = A1_6408
    if A0_6407.open then
      A0_6407:StartAnimation(0, "tick_device_open", 0, 0, 1, 0)
    else
      A0_6407:StartAnimation(0, "tick_device_close", 0, 0, 1, 0)
    end
  end
end
L0_6385.SetOpen = L1_6386
