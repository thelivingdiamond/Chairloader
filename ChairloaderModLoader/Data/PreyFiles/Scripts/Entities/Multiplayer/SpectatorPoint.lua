local L0_6552, L1_6553
L0_6552 = {}
L1_6553 = {}
L0_6552.Client = L1_6553
L1_6553 = {}
L0_6552.Server = L1_6553
L1_6553 = {}
L1_6553.Icon = "spectator.bmp"
L1_6553.DisplayArrow = 1
L0_6552.Editor = L1_6553
L1_6553 = {}
L1_6553.bEnabled = 1
L0_6552.Properties = L1_6553
SpectatorPoint = L0_6552
L0_6552 = SpectatorPoint
L0_6552 = L0_6552.Server
function L1_6553(A0_6554)
  A0_6554:Enable(tonumber(A0_6554.Properties.bEnabled) ~= 0)
  A0_6554:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
end
L0_6552.OnInit = L1_6553
L0_6552 = SpectatorPoint
L0_6552 = L0_6552.Client
function L1_6553(A0_6555)
  if not CryAction.IsServer() then
    A0_6555:Enable(tonumber(A0_6555.Properties.bEnabled) ~= 0)
  end
  A0_6555:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
end
L0_6552.OnInit = L1_6553
L0_6552 = SpectatorPoint
function L1_6553(A0_6556, A1_6557)
  if A1_6557 then
    g_gameRules.game:AddSpectatorLocation(A0_6556.id)
  else
    g_gameRules.game:RemoveSpectatorLocation(A0_6556.id)
  end
  A0_6556.enabled = A1_6557
end
L0_6552.Enable = L1_6553
L0_6552 = SpectatorPoint
L0_6552 = L0_6552.Server
function L1_6553(A0_6558)
  if g_gameRules then
    g_gameRules.game:RemoveSpectatorLocation(A0_6558.id)
  end
end
L0_6552.OnShutDown = L1_6553
L0_6552 = SpectatorPoint
L0_6552 = L0_6552.Client
function L1_6553(A0_6559)
  if g_gameRules and not CryAction.IsServer() then
    g_gameRules.game:RemoveSpectatorLocation(A0_6559.id)
  end
end
L0_6552.OnShutDown = L1_6553
L0_6552 = SpectatorPoint
function L1_6553(A0_6560)
  local L1_6561
  L1_6561 = A0_6560.enabled
  return L1_6561
end
L0_6552.IsEnabled = L1_6553
