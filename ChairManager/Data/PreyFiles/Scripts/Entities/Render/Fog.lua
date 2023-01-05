local L0_8066, L1_8067
L0_8066 = {}
L0_8066.type = "FogController"
L1_8067 = {}
L1_8067.GlobalDensityModifier = 1
L1_8067.AtmosphereHeightModifier = 0
L1_8067.FadeTime = 1
L0_8066.Properties = L1_8067
L1_8067 = {}
L1_8067.Icon = "Fog.bmp"
L0_8066.Editor = L1_8067
L0_8066.LastTime = 0
L0_8066.CurFadeAmount = 0
Fog = L0_8066
L0_8066 = Fog
function L1_8067(A0_8068, A1_8069)
  A0_8068:SetFog()
end
L0_8066.OnUpdate = L1_8067
L0_8066 = Fog
function L1_8067(A0_8070)
  A0_8070:OnReset()
end
L0_8066.OnInit = L1_8067
L0_8066 = Fog
function L1_8067(A0_8071)
  A0_8071:OnReset()
end
L0_8066.OnPropertyChange = L1_8067
L0_8066 = Fog
function L1_8067(A0_8072)
  A0_8072:KillTimer(0)
  A0_8072:KillTimer(1)
  A0_8072:ResetValues()
end
L0_8066.OnReset = L1_8067
L0_8066 = Fog
function L1_8067(A0_8073, A1_8074)
  local L2_8075
  L2_8075 = A0_8073.LastTime
  A1_8074.LastTime = L2_8075
  L2_8075 = A0_8073.CurFadeAmount
  A1_8074.CurFadeAmount = L2_8075
end
L0_8066.OnSave = L1_8067
L0_8066 = Fog
function L1_8067(A0_8076, A1_8077)
  local L2_8078
  L2_8078 = A1_8077.LastTime
  A0_8076.LastTime = L2_8078
  L2_8078 = A1_8077.CurFadeAmount
  A0_8076.CurFadeAmount = L2_8078
end
L0_8066.OnLoad = L1_8067
L0_8066 = Fog
function L1_8067(A0_8079)
  local L1_8080
  A0_8079.LastTime = 0
  A0_8079.CurFadeAmount = 0
end
L0_8066.ResetValues = L1_8067
L0_8066 = Fog
function L1_8067(A0_8081)
  local L1_8082, L2_8083, L3_8084
  L1_8082 = A0_8081.CurFadeAmount
  L2_8083 = A0_8081.Properties
  L2_8083 = L2_8083.GlobalDensityModifier
  L2_8083 = L2_8083 * L1_8082
  L3_8084 = A0_8081.Properties
  L3_8084 = L3_8084.AtmosphereHeightModifier
  L3_8084 = L3_8084 * L1_8082
  System.SetVolumetricFogModifiers(L2_8083, L3_8084)
end
L0_8066.SetFog = L1_8067
L0_8066 = Fog
function L1_8067(A0_8085, A1_8086, A2_8087)
  A0_8085.LastTime = _time
  A0_8085:KillTimer(1)
  A0_8085:SetTimer(0, 1)
  A0_8085:Activate(1)
end
L0_8066.OnEnterArea = L1_8067
L0_8066 = Fog
function L1_8067(A0_8088, A1_8089, A2_8090)
  A0_8088.LastTime = _time
  A0_8088:KillTimer(0)
  A0_8088:SetTimer(1, 1)
end
L0_8066.OnLeaveArea = L1_8067
L0_8066 = Fog
function L1_8067(A0_8091)
  local L1_8092
end
L0_8066.OnShutDown = L1_8067
L0_8066 = Fog
function L1_8067(A0_8093, A1_8094)
  local L2_8095
  L2_8095 = _time
  L2_8095 = L2_8095 - A0_8093.LastTime
  A0_8093.LastTime = _time
  if A1_8094 == 0 then
    A0_8093.CurFadeAmount = A0_8093.CurFadeAmount + L2_8095 / A0_8093.Properties.FadeTime
    if A0_8093.CurFadeAmount >= 1 then
      A0_8093.CurFadeAmount = 1
      A0_8093:KillTimer(0)
    else
      A0_8093:SetTimer(0, 1)
    end
  else
    A0_8093.CurFadeAmount = A0_8093.CurFadeAmount - L2_8095 / A0_8093.Properties.FadeTime
    if 0 >= A0_8093.CurFadeAmount then
      A0_8093.CurFadeAmount = 0
      A0_8093:KillTimer(1)
      A0_8093:Activate(0)
      A0_8093:SetFog()
    else
      A0_8093:SetTimer(1, 1)
    end
  end
end
L0_8066.OnTimer = L1_8067
