local L0_2996, L1_2997
L0_2996 = {}
L0_2996.type = "TagPoint"
L1_2997 = {}
L1_2997.Icon = "TagPoint.bmp"
L0_2996.Editor = L1_2997
TagPoint = L0_2996
L0_2996 = TagPoint
function L1_2997(A0_2998)
  A0_2998:SetFlags(ENTITY_FLAG_CLIENT_ONLY, 0)
end
L0_2996.OnSpawn = L1_2997
L0_2996 = TagPoint
function L1_2997(A0_2999)
  CryAction.RegisterWithAI(A0_2999.id, AIOBJECT_WAYPOINT)
end
L0_2996.OnInit = L1_2997
