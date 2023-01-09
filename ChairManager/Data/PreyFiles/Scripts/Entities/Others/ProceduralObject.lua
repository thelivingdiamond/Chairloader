local L0_7073, L1_7074, L2_7075
L0_7073 = {}
L0_7073.type = "ProceduralObject"
L1_7074 = {}
L1_7074.filePrefabLibrary = ""
L2_7075 = {}
L2_7075.sPrefabVariation = ""
L1_7074.ObjectVariation = L2_7075
L1_7074.nMaxSpawn = 0
L0_7073.Properties = L1_7074
L1_7074 = {}
L1_7074.Icon = "proceduralobject.bmp"
L1_7074.ShowBounds = 1
L0_7073.Editor = L1_7074
L0_7073.PrefabSourceName = ""
ProceduralObject = L0_7073
L0_7073 = ProceduralObject
function L1_7074(A0_7076)
  A0_7076:OnReset()
end
L0_7073.OnInit = L1_7074
L0_7073 = ProceduralObject
function L1_7074(A0_7077)
  A0_7077:OnReset()
end
L0_7073.OnPropertyChange = L1_7074
L0_7073 = ProceduralObject
function L1_7074(A0_7078, A1_7079)
  Game.DeletePrefab(A0_7078.id)
end
L0_7073.OnDestroy = L1_7074
L0_7073 = ProceduralObject
function L1_7074(A0_7080)
  Game.MovePrefab(A0_7080.id)
end
L0_7073.OnMove = L1_7074
L0_7073 = ProceduralObject
function L1_7074(A0_7081)
  if CryAction.IsClient() then
    A0_7081:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
  end
  if CryAction.IsServer() then
    A0_7081:SetFlags(ENTITY_FLAG_SERVER_ONLY, 0)
  end
end
L0_7073.OnSpawn = L1_7074
L0_7073 = ProceduralObject
function L1_7074(A0_7082, A1_7083)
  Game.DeletePrefab(A0_7082.id)
  if not EmptyString(A0_7082.Properties.filePrefabLibrary) then
    Game.LoadPrefabLibrary(A0_7082.Properties.filePrefabLibrary)
    if not EmptyString(A0_7082.Properties.ObjectVariation.sPrefabVariation) then
      Game.SpawnPrefab(A0_7082.id, A0_7082.Properties.filePrefabLibrary, A0_7082.Properties.ObjectVariation.sPrefabVariation, A1_7083, A0_7082.Properties.nMaxSpawn)
    end
  end
end
L0_7073.Spawn = L1_7074
L0_7073 = ProceduralObject
function L1_7074(A0_7084)
  Game.HidePrefab(A0_7084.id, true)
end
L0_7073.OnHidden = L1_7074
L0_7073 = ProceduralObject
function L1_7074(A0_7085)
  Game.HidePrefab(A0_7085.id, false)
end
L0_7073.OnUnHidden = L1_7074
L0_7073 = ProceduralObject
function L1_7074(A0_7086, A1_7087)
  if System.IsEditor() then
    if System.IsEditing() or 0 == 1 then
      Game.DeletePrefab(A0_7086.id)
      A0_7086:Spawn(0)
    end
  else
    Game.DeletePrefab(A0_7086.id)
  end
end
L0_7073.OnReset = L1_7074
