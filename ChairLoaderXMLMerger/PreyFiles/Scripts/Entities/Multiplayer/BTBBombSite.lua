local L0_6210, L1_6211, L2_6212, L3_6213
L0_6210 = {}
L1_6211 = {}
L0_6210.Client = L1_6211
L1_6211 = {}
L0_6210.Server = L1_6211
L1_6211 = {}
L1_6211.fileModel = "objects/library/props/ctf/mpnots_flagbase01.cgf"
L1_6211.ModelSubObject = "main"
L1_6211.Radius = 2
L1_6211.teamName = ""
L2_6212 = {}
L2_6212.Effect = "explosions.rocket.soil"
L2_6212.EffectScale = 0.2
L2_6212.Radius = 2
L2_6212.Pressure = 250
L2_6212.Damage = 500
L2_6212.Decal = "textures/decal/explo_decal.dds"
L2_6212.DecalScale = 1
L3_6213 = {}
L3_6213.x = 0
L3_6213.y = 0
L3_6213.z = -1
L2_6212.Direction = L3_6213
L1_6211.Explosion = L2_6212
L0_6210.Properties = L1_6211
L1_6211 = {}
L1_6211.Icon = "Item.bmp"
L1_6211.IconOnTop = 1
L0_6210.Editor = L1_6211
BTBBombSite = L0_6210
L0_6210 = BTBBombSite
L0_6210 = L0_6210.Server
function L1_6211(A0_6214)
  Log("BTBBombSite.Server.OnInit")
  if not A0_6214.bInitialized then
    A0_6214:OnReset()
    A0_6214.bInitialized = 1
  end
  A0_6214.inside = {}
end
L0_6210.OnInit = L1_6211
L0_6210 = BTBBombSite
L0_6210 = L0_6210.Client
function L1_6211(A0_6215)
  Log("BTBBombSite.Client.OnInit")
  if not A0_6215.bInitialized then
    A0_6215:OnReset()
    A0_6215.bInitialized = 1
  end
  A0_6215.inside = {}
end
L0_6210.OnInit = L1_6211
L0_6210 = BTBBombSite
function L1_6211(A0_6216)
  local L1_6217, L2_6218, L3_6219, L4_6220
  L1_6217 = Log
  L2_6218 = "BTBBombSite.OnReset"
  L1_6217(L2_6218)
  L2_6218 = A0_6216
  L1_6217 = A0_6216.LoadObject
  L3_6219 = 0
  L4_6220 = A0_6216.Properties
  L4_6220 = L4_6220.fileModel
  L1_6217(L2_6218, L3_6219, L4_6220)
  L1_6217 = A0_6216.Properties
  L1_6217 = L1_6217.Radius
  L1_6217 = L1_6217 / 2
  L2_6218 = {}
  L3_6219 = -L1_6217
  L2_6218.x = L3_6219
  L3_6219 = -L1_6217
  L2_6218.y = L3_6219
  L3_6219 = -L1_6217
  L2_6218.z = L3_6219
  L3_6219 = {}
  L3_6219.x = L1_6217
  L3_6219.y = L1_6217
  L3_6219.z = L1_6217
  L4_6220 = A0_6216.SetTriggerBBox
  L4_6220(A0_6216, L2_6218, L3_6219)
  L4_6220 = A0_6216.Physicalize
  L4_6220(A0_6216, 0, PE_STATIC, {mass = 0})
  L4_6220 = A0_6216.SetFlags
  L4_6220(A0_6216, ENTITY_FLAG_ON_RADAR, 0)
  L4_6220 = CryAction
  L4_6220 = L4_6220.IsServer
  L4_6220 = L4_6220()
  if L4_6220 then
    L4_6220 = A0_6216.Properties
    L4_6220 = L4_6220.teamName
    if L4_6220 ~= "" then
      L4_6220 = g_gameRules
      L4_6220 = L4_6220.game
      L4_6220 = L4_6220.GetTeamId
      L4_6220 = L4_6220(L4_6220, A0_6216.Properties.teamName)
      if L4_6220 > 0 then
        g_gameRules.game:SetTeam(L4_6220, A0_6216.id)
      end
    end
  end
end
L0_6210.OnReset = L1_6211
L0_6210 = BTBBombSite
L0_6210 = L0_6210.Server
function L1_6211(A0_6221, A1_6222, A2_6223)
  Log("BTBBombSite.Server.OnEnterArea entity:%s, this areas team:%s", EntityName(A1_6222.id), A0_6221.Properties.teamName)
  for _FORV_7_, _FORV_8_ in ipairs(A0_6221.inside) do
    if _FORV_8_ == A1_6222.id then
      Log("Entity already inserted")
      break
    end
  end
  if not true then
    table.insert(A0_6221.inside, A1_6222.id)
    Log("Entity added")
  end
  if g_gameRules.Server.EntityEnterBombSiteArea ~= nil then
    g_gameRules.Server.EntityEnterBombSiteArea(g_gameRules, A1_6222, A0_6221)
  end
end
L0_6210.OnEnterArea = L1_6211
L0_6210 = BTBBombSite
L0_6210 = L0_6210.Client
function L1_6211(A0_6224, A1_6225, A2_6226)
  Log("BTBBombSite.Client.OnEnterArea entity:%s, this areas team:%s", EntityName(A1_6225.id), A0_6224.Properties.teamName)
  if g_gameRules.Client.EntityEnterBombSiteArea ~= nil then
    g_gameRules.Client.EntityEnterBombSiteArea(g_gameRules, A1_6225, A0_6224)
  end
end
L0_6210.OnEnterArea = L1_6211
L0_6210 = BTBBombSite
L0_6210 = L0_6210.Client
function L1_6211(A0_6227, A1_6228, A2_6229)
  Log("BTBBombSite.Client.OnLeaveArea entity:%s, this areas team:%s", EntityName(A1_6228.id), A0_6227.Properties.teamName)
  if g_gameRules.Client.EntityLeaveBombSiteArea ~= nil then
    g_gameRules.Client.EntityLeaveBombSiteArea(g_gameRules, A1_6228, A0_6227)
  end
end
L0_6210.OnLeaveArea = L1_6211
L0_6210 = BTBBombSite
L0_6210 = L0_6210.Server
function L1_6211(A0_6230, A1_6231, A2_6232)
  local L3_6233, L4_6234, L5_6235, L6_6236
  L6_6236 = A1_6231.id
  L6_6236 = A0_6230.Properties
  L6_6236 = L6_6236.teamName
  L3_6233(L4_6234, L5_6235, L6_6236)
  for L6_6236, _FORV_7_ in L3_6233(L4_6234) do
    if _FORV_7_ == A1_6231.id then
      table.remove(A0_6230.inside, L6_6236)
      Log("Entity removed")
      break
    end
  end
  if L3_6233 ~= nil then
    L6_6236 = A0_6230
    L3_6233(L4_6234, L5_6235, L6_6236)
  end
end
L0_6210.OnLeaveArea = L1_6211
L0_6210 = BTBBombSite
function L1_6211(A0_6237, A1_6238)
  for _FORV_5_, _FORV_6_ in ipairs(A0_6237.inside) do
    if _FORV_6_ == A1_6238 then
      return true
    end
  end
  return false
end
L0_6210.EntityInsideArea = L1_6211
L0_6210 = BTBBombSite
function L1_6211(A0_6239)
  local L1_6240, L2_6241
  L1_6240 = A0_6239.Properties
  L1_6240 = L1_6240.Explosion
  L2_6241 = L1_6240.Radius
  g_gameRules:CreateExplosion(A0_6239.id, A0_6239.id, L1_6240.Damage, A0_6239:GetWorldPos(), L1_6240.Direction, L2_6241, nil, L1_6240.Pressure, L1_6240.HoleSize, L1_6240.Effect, L1_6240.EffectScale)
end
L0_6210.Explode = L1_6211
