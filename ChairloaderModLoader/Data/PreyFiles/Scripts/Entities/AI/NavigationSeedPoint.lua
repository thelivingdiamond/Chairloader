local L0_2934, L1_2935
L0_2934 = {}
L0_2934.type = "NavigationSeedPoint"
L1_2935 = {}
L1_2935.Icon = "Seed.bmp"
L0_2934.Editor = L1_2935
NavigationSeedPoint = L0_2934
L0_2934 = NavigationSeedPoint
function L1_2935(A0_2936)
  CryAction.RegisterWithAI(A0_2936.id, AIOBJECT_NAV_SEED)
end
L0_2934.OnInit = L1_2935
