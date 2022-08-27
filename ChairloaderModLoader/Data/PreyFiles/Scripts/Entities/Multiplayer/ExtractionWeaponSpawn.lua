local L0_6409, L1_6410
L0_6409 = {}
L1_6410 = {}
L0_6409.Server = L1_6410
L1_6410 = {}
L0_6409.Client = L1_6410
L1_6410 = {}
L1_6410.fileModelOverride = ""
L1_6410.Radius = 6
L0_6409.Properties = L1_6410
L1_6410 = {}
L1_6410.Icon = "Item.bmp"
L1_6410.IconOnTop = 1
L0_6409.Editor = L1_6410
L0_6409.modelSlot = -1
L1_6410 = {}
L0_6409.spawnPointIds = L1_6410
L0_6409.inProximity = false
L0_6409.hasTick = true
L0_6409.open = false
ExtractionWeaponSpawn = L0_6409
L0_6409 = ExtractionWeaponSpawn
L0_6409.DEFAULT_FILE_MODEL = "objects/multiplayer/props/c3mp_gamemode_props/c3mp_powercell/c3mp_powercell.cdf"
L0_6409 = ExtractionWeaponSpawn
function L1_6410(A0_6411)
  local L1_6412, L2_6413, L3_6414
  L1_6412 = Log
  L2_6413 = "ExtractionWeaponSpawn:OnReset"
  L1_6412(L2_6413)
  L1_6412 = A0_6411.Properties
  L1_6412 = L1_6412.Radius
  L1_6412 = L1_6412 / 2
  L2_6413 = {}
  L3_6414 = -L1_6412
  L2_6413.x = L3_6414
  L3_6414 = -L1_6412
  L2_6413.y = L3_6414
  L3_6414 = -L1_6412
  L2_6413.z = L3_6414
  L3_6414 = {}
  L3_6414.x = L1_6412
  L3_6414.y = L1_6412
  L3_6414.z = L1_6412
  A0_6411:SetTriggerBBox(L2_6413, L3_6414)
  A0_6411:SetViewDistRatio(255)
  if System.IsEditor() then
    Log("In editor, activating")
    A0_6411:ActivateSite()
    A0_6411:AddSpawnPoints("spawn")
    A0_6411:AddSpawnPoints("spawnpoint")
    A0_6411:AddSpawnPoints("disruptor")
    Log("Entity=%s, found %d associated spawn points", EntityName(A0_6411), #A0_6411.spawnPointIds)
  end
end
L0_6409.OnReset = L1_6410
L0_6409 = ExtractionWeaponSpawn
function L1_6410(A0_6415, A1_6416)
  local L2_6417, L3_6418
  L2_6417 = 0
  L3_6418 = A0_6415.GetLinkTarget
  L3_6418 = L3_6418(A0_6415, A1_6416, L2_6417)
  while L3_6418 do
    InsertIntoTable(A0_6415.spawnPointIds, L3_6418.id)
    L2_6417 = L2_6417 + 1
    L3_6418 = A0_6415:GetLinkTarget(A1_6416, L2_6417)
  end
end
L0_6409.AddSpawnPoints = L1_6410
L0_6409 = ExtractionWeaponSpawn
function L1_6410(A0_6419)
  local L1_6420
  L1_6420 = A0_6419.DEFAULT_FILE_MODEL
  if A0_6419.Properties.fileModelOverride and A0_6419.Properties.fileModelOverride ~= "" then
    Log("Override file model provided, using model '%s'", A0_6419.Properties.fileModelOverride)
    L1_6420 = A0_6419.Properties.fileModelOverride
  end
  A0_6419.modelSlot = A0_6419:LoadObject(A0_6419.modelSlot, L1_6420)
  A0_6419:Physicalize(A0_6419.modelSlot, PE_STATIC, {mass = 0})
  A0_6419:SetViewDistRatio(255)
  A0_6419:SetFlags(ENTITY_FLAG_ON_RADAR, 0)
end
L0_6409.ActivateSite = L1_6410
L0_6409 = ExtractionWeaponSpawn
function L1_6410(A0_6421)
  A0_6421:DestroyPhysics()
  A0_6421:FreeSlot(A0_6421.modelSlot)
  A0_6421.modelSlot = -1
  A0_6421:SetViewDistRatio(255)
  A0_6421:SetFlags(ENTITY_FLAG_ON_RADAR, 2)
end
L0_6409.DeactivateSite = L1_6410
L0_6409 = ExtractionWeaponSpawn
function L1_6410(A0_6422, A1_6423)
  local L2_6424, L3_6425, L4_6426, L5_6427, L6_6428
  L5_6427 = A0_6422
  L5_6427 = A1_6423
  L2_6424(L3_6425, L4_6426, L5_6427)
  if L2_6424 then
    A0_6422.spawnPointIds = L2_6424
    L2_6424(L3_6425, L4_6426)
    L2_6424(L3_6425, L4_6426)
    L2_6424(L3_6425, L4_6426)
    L5_6427 = A0_6422
    L5_6427 = A0_6422.spawnPointIds
    L5_6427 = #L5_6427
    L2_6424(L3_6425, L4_6426, L5_6427)
    for L5_6427, L6_6428 in L2_6424(L3_6425) do
      g_gameRules.game:ClientSetTeam(A1_6423, L6_6428)
    end
  end
end
L0_6409.OnSetTeam = L1_6410
L0_6409 = ExtractionWeaponSpawn
L0_6409 = L0_6409.Server
function L1_6410(A0_6429)
  Log("ExtractionWeaponSpawn.Server.OnInit")
  if not A0_6429.bInitialized then
    A0_6429:OnReset()
    A0_6429.bInitialized = 1
    A0_6429:SetViewDistRatio(255)
  end
end
L0_6409.OnInit = L1_6410
L0_6409 = ExtractionWeaponSpawn
L0_6409 = L0_6409.Client
function L1_6410(A0_6430)
  Log("ExtractionWeaponSpawn.Client.OnInit")
  if not A0_6430.bInitialized then
    A0_6430:OnReset()
    A0_6430.bInitialized = 1
    A0_6430:SetViewDistRatio(255)
  end
end
L0_6409.OnInit = L1_6410
L0_6409 = ExtractionWeaponSpawn
function L1_6410(A0_6431)
  A0_6431:OnReset()
end
L0_6409.OnPropertyChange = L1_6410
L0_6409 = ExtractionWeaponSpawn
function L1_6410(A0_6432, A1_6433)
  if A0_6432.open ~= A1_6433 then
    A0_6432.open = A1_6433
    if A0_6432.open then
      A0_6432:StartAnimation(0, "machine_open", 0, 0, 1, 0)
    else
      A0_6432:StartAnimation(0, "machine_close", 0, 0, 1, 0)
    end
  end
end
L0_6409.SetOpen = L1_6410
L0_6409 = ExtractionWeaponSpawn
function L1_6410(A0_6434, A1_6435)
  A0_6434.inProximity = A1_6435
  A0_6434:SetOpen(not A0_6434.hasTick or A0_6434.inProximity)
end
L0_6409.InProximity = L1_6410
L0_6409 = ExtractionWeaponSpawn
function L1_6410(A0_6436, A1_6437)
  A0_6436.hasTick = A1_6437
  A0_6436:SetOpen(not A0_6436.hasTick or A0_6436.inProximity)
end
L0_6409.HasTick = L1_6410
