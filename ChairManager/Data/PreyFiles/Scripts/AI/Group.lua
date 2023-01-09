local L0_416, L1_417
L0_416 = {}
L0_416.defendPressureThreshold = 0.75
function L1_417(A0_418, A1_419)
  local L2_420
  L2_420 = A0_418.AreaSearchCoordId
  A1_419.AreaSearchCoordId = L2_420
  L2_420 = A0_418.investigateMemberDeathID
  A1_419.investigateMemberDeathID = L2_420
end
L0_416.OnSaveAI = L1_417
function L1_417(A0_421, A1_422)
  local L2_423
  L2_423 = A1_422.AreaSearchCoordId
  A0_421.AreaSearchCoordId = L2_423
  L2_423 = A1_422.investigateMemberDeathID
  A0_421.investigateMemberDeathID = L2_423
end
L0_416.OnLoadAI = L1_417
AIGroup = L0_416
