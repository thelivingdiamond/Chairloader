local L0_6323, L1_6324, L2_6325
L0_6323 = {}
L1_6324 = {}
L0_6323.Server = L1_6324
L1_6324 = {}
L0_6323.Client = L1_6324
L1_6324 = {}
L1_6324.objModelSame = "engine/engineassets/objects/default.cgf"
L1_6324.objModelOther = "engine/engineassets/objects/default.cgf"
L1_6324.Team = 0
L1_6324.ActionSuffix = "flag"
L1_6324.ActionSuffixAG = "_flag"
L1_6324.PlayerTag = "flag"
L2_6325 = {}
L2_6325.mass = 20
L2_6325.density = 0
L2_6325.water_damping = 80
L2_6325.water_resistance = 190
L2_6325.water_density = 250
L1_6324.Physics = L2_6325
L0_6323.Properties = L1_6324
CTFFlag = L0_6323
L0_6323 = CTFFlag
function L1_6324(A0_6326, A1_6327, A2_6328)
  if string.len(A2_6328) > 0 then
    if string.lower(string.sub(A2_6328, -4)) == ".chr" or string.lower(string.sub(A2_6328, -4)) == ".cdf" or string.lower(string.sub(A2_6328, -4)) == ".cga" then
      A0_6326:LoadCharacter(A1_6327, A2_6328)
    else
      A0_6326:LoadObject(A1_6327, A2_6328)
    end
  end
end
L0_6323.LoadGeometry = L1_6324
L0_6323 = CTFFlag
function L1_6324(A0_6329)
  local L1_6330, L2_6331
  L1_6330 = g_gameRules
  L1_6330 = L1_6330.game
  L2_6331 = L1_6330
  L1_6330 = L1_6330.GetTeam
  L1_6330 = L1_6330(L2_6331, A0_6329.id)
  L2_6331 = 0
  if g_localActorId ~= nil then
    L2_6331 = g_gameRules.game:GetTeam(g_localActorId)
  end
  if L1_6330 == L2_6331 then
    A0_6329:LoadGeometry(0, A0_6329.Properties.objModelOther)
  else
    A0_6329:LoadGeometry(0, A0_6329.Properties.objModelSame)
  end
end
L0_6323.LoadCorrectGeometry = L1_6324
L0_6323 = CTFFlag
function L1_6324(A0_6332)
  CryAction.CreateGameObjectForEntity(A0_6332.id)
  CryAction.BindGameObjectToNetwork(A0_6332.id)
  CryAction.ForceGameObjectUpdate(A0_6332.id, true)
  A0_6332:RedirectAnimationToLayer0(0, true)
  A0_6332:Activate(1)
  A0_6332:SetPhysicParams(PHYSICPARAM_BUOYANCY, A0_6332.Properties.Physics)
  A0_6332:OnReset()
end
L0_6323.OnSpawn = L1_6324
L0_6323 = CTFFlag
function L1_6324(A0_6333)
  A0_6333:LoadCorrectGeometry()
  A0_6333:SetViewDistRatio(255)
end
L0_6323.OnReset = L1_6324
L0_6323 = CTFFlag
function L1_6324(A0_6334)
  A0_6334:OnReset()
end
L0_6323.OnInit = L1_6324
L0_6323 = CTFFlag
function L1_6324(A0_6335, A1_6336)
  A0_6335:LoadCorrectGeometry()
end
L0_6323.OnSetTeam = L1_6324
L0_6323 = CTFFlag
L0_6323 = L0_6323.Server
function L1_6324(A0_6337)
  if not A0_6337.bInitialized then
    A0_6337:OnReset()
    A0_6337.bInitialized = 1
  end
end
L0_6323.OnInit = L1_6324
L0_6323 = CTFFlag
L0_6323 = L0_6323.Client
function L1_6324(A0_6338)
  if not A0_6338.bInitialized then
    A0_6338:OnReset()
    A0_6338.bInitialized = 1
  end
end
L0_6323.OnInit = L1_6324
L0_6323 = CTFFlag
function L1_6324(A0_6339)
  A0_6339:OnReset()
end
L0_6323.OnPropertyChange = L1_6324
L0_6323 = CTFFlag
function L1_6324(A0_6340, A1_6341)
  if g_gameRules.game:GetTeam(A1_6341.id) ~= g_gameRules.game:GetTeam(A0_6340.id) then
    return 725725
  else
    return 0
  end
end
L0_6323.IsUsable = L1_6324
